/// Copyright (C) 2003  Fabrice Bellard
/// Copyright (C) 2010  Dependable Systems Laboratory, EPFL
/// Copyright (C) 2016  Cyberhaven
/// Copyrights of all contributions belong to their respective owners.
///
/// This library is free software; you can redistribute it and/or
/// modify it under the terms of the GNU Library General Public
/// License as published by the Free Software Foundation; either
/// version 2 of the License, or (at your option) any later version.
///
/// This library is distributed in the hope that it will be useful,
/// but WITHOUT ANY WARRANTY; without even the implied warranty of
/// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
/// Library General Public License for more details.
///
/// You should have received a copy of the GNU Library General Public
/// License along with this library; if not, see <http://www.gnu.org/licenses/>.

#include <cpu/config.h>
#include <cpu/memory.h>
#include <inttypes.h>
#include <tcg/utils/osdep.h>
#include "qemu-common.h"

#include "exec-phys.h"
#include "exec-ram.h"
#include "exec-tlb.h"
#include "exec.h"

/* statistics */
int g_tlb_flush_count;

static inline void tlb_flush_jmp_cache(CPUArchState *env, target_ulong addr) {
    unsigned int i;

    /* Discard jump cache entries for any tb which might potentially
       overlap the flushed page.  */
    i = tb_jmp_cache_hash_page(addr - TARGET_PAGE_SIZE);
    memset(&env->tb_jmp_cache[i], 0, TB_JMP_PAGE_SIZE * sizeof(TranslationBlock *));

    i = tb_jmp_cache_hash_page(addr);
    memset(&env->tb_jmp_cache[i], 0, TB_JMP_PAGE_SIZE * sizeof(TranslationBlock *));
}

static const CPUTLBEntry s_cputlb_empty_entry = {
    .addr_read = -1,
    .addr_write = -1,
    .addr_code = -1,
    .addend = -1,

};

/* NOTE:
 * If flush_global is true (the usual case), flush all tlb entries.
 * If flush_global is false, flush (at least) all tlb entries not
 * marked global.
 *
 * Since QEMU doesn't currently implement a global/not-global flag
 * for tlb entries, at the moment tlb_flush() will also flush all
 * tlb entries in the flush_global == false case. This is OK because
 * CPU architectures generally permit an implementation to drop
 * entries from the TLB at any time, so flushing more entries than
 * required is only an efficiency issue, not a correctness issue.
 */



void tlb_flush(CPUArchState *env, int flush_global) {
    int i;



#if defined(DEBUG_TLB)
    printf("tlb_flush:\n");
#endif
    /* must reset current TB so that interrupts cannot modify the
       links while we are modifying them */
    env->current_tb = NULL;

    int mmu_idx;
    for (mmu_idx = 0; mmu_idx < NB_MMU_MODES; mmu_idx++) {
        env->tlb_table[mmu_idx] = &env->_tlb_table[mmu_idx][0];
        for (i = 0; i < CPU_TLB_SIZE; i++) {
            env->tlb_table[mmu_idx][i] = s_cputlb_empty_entry;
        }
        env->tlb_mask[mmu_idx] = (CPU_TLB_SIZE - 1) << CPU_TLB_ENTRY_BITS;
    }



    memset(env->tb_jmp_cache, 0, TB_JMP_CACHE_SIZE * sizeof(void *));

    env->tlb_flush_addr = -1;
    env->tlb_flush_mask = 0;
    g_tlb_flush_count++;
}

void tlb_flush_page(CPUArchState *env, target_ulong addr) {
    int i;
    int mmu_idx;

#if defined(DEBUG_TLB)
    printf("tlb_flush_page: " TARGET_FMT_lx "\n", addr);
#endif
    /* Check if we need to flush due to large pages.  */
    if ((addr & env->tlb_flush_mask) == env->tlb_flush_addr) {
#if defined(DEBUG_TLB)
        printf("tlb_flush_page: forced full flush (" TARGET_FMT_lx "/" TARGET_FMT_lx ")\n", env->tlb_flush_addr,
               env->tlb_flush_mask);
#endif
        tlb_flush(env, 1);
        return;
    }
    /* must reset current TB so that interrupts cannot modify the
       links while we are modifying them */
    env->current_tb = NULL;

    addr &= TARGET_PAGE_MASK;
    i = (addr >> TARGET_PAGE_BITS) & (CPU_TLB_SIZE - 1);
    for (mmu_idx = 0; mmu_idx < NB_MMU_MODES; mmu_idx++) {
        // tlb_flush_entry(&env->tlb_table[mmu_idx][i], addr);
        CPUTLBEntry *tlb_entry = &env->tlb_table[mmu_idx][i];
        if (addr == (tlb_entry->addr_read & (TARGET_PAGE_MASK | TLB_INVALID_MASK)) ||
            addr == (tlb_entry->addr_write & (TARGET_PAGE_MASK | TLB_INVALID_MASK)) ||
            addr == (tlb_entry->addr_code & (TARGET_PAGE_MASK | TLB_INVALID_MASK))) {

            *tlb_entry = s_cputlb_empty_entry;
        }
    }

    tlb_flush_jmp_cache(env, addr);
}

/* update the TLBs so that writes to code in the virtual page 'addr'
   can be detected */
void tlb_protect_code(ram_addr_t ram_addr) {
    cpu_physical_memory_reset_dirty(ram_addr, ram_addr + TARGET_PAGE_SIZE, CODE_DIRTY_FLAG);
}

/* update the TLB so that writes in physical page 'phys_addr' are no longer
   tested for self modifying code */
void tlb_unprotect_code_phys(CPUArchState *env, ram_addr_t ram_addr, target_ulong vaddr) {
    cpu_physical_memory_set_dirty_flags(ram_addr, CODE_DIRTY_FLAG);
}



/* Our TLB does not support large pages, so remember the area covered by
   large pages and trigger a full TLB flush if these are invalidated.  */
static void tlb_add_large_page(CPUArchState *env, target_ulong vaddr, target_ulong size) {
    target_ulong mask = ~(size - 1);

    if (env->tlb_flush_addr == (target_ulong) -1) {
        env->tlb_flush_addr = vaddr & mask;
        env->tlb_flush_mask = mask;
        return;
    }
    /* Extend the existing region to include the new page.
       This is a compromise between unnecessary flushes and the cost
       of maintaining a full variable size TLB.  */
    mask &= env->tlb_flush_mask;
    while (((env->tlb_flush_addr ^ vaddr) & mask) != 0) {
        mask <<= 1;
    }
    env->tlb_flush_addr &= mask;
    env->tlb_flush_mask = mask;
}

/* Add a new TLB entry. At most one entry for a given virtual address
   is permitted. Only a single TARGET_PAGE_SIZE region is mapped, the
   supplied size is only used by tlb_flush_page.  */
void tlb_set_page(CPUArchState *env, target_ulong vaddr, target_phys_addr_t paddr, int prot, int mmu_idx,
                  target_ulong size) {
    unsigned int index;
    target_ulong address;
    target_ulong code_address;
    unsigned long addend;
    CPUTLBEntry *te;
    CPUWatchpoint *wp;
    target_phys_addr_t iotlb;

    assert(size >= TARGET_PAGE_SIZE);
    if (size != TARGET_PAGE_SIZE) {
        tlb_add_large_page(env, vaddr, size);
    }

    const MemoryDesc *sreg = mem_desc_find(paddr);

#if defined(DEBUG_TLB)
    printf("tlb_set_page: vaddr=" TARGET_FMT_lx " paddr=0x" TARGET_FMT_plx " prot=%x idx=%d pd=0x%08lx\n", vaddr, paddr,
           prot, mmu_idx, pd);
#endif

    address = vaddr;

    if (sreg) {
        // RAM
        addend = mem_desc_addend(sreg, paddr);
        iotlb = (sreg->ram_addr & TARGET_PAGE_MASK) + mem_desc_get_offset(sreg, paddr);
        iotlb |= phys_section_notdirty;
    } else {
        // Everything else (MMIO)
        address |= TLB_MMIO;
        addend = 0;
        iotlb = paddr;
    }

    code_address = address;
    /* Make accesses to pages with watchpoints go via the
       watchpoint trap routines.  */
    QTAILQ_FOREACH (wp, &env->watchpoints, entry) {
        if (vaddr == (wp->vaddr & TARGET_PAGE_MASK)) {
            /* Avoid trapping reads of pages with a write breakpoint. */
            if ((prot & PAGE_WRITE) || (wp->flags & BP_MEM_READ)) {
                iotlb = phys_section_watch + paddr;
                address |= TLB_MMIO;
                break;
            }
        }
    }

    index = (vaddr >> TARGET_PAGE_BITS) & (CPU_TLB_SIZE - 1);
    env->iotlb[mmu_idx][index] = iotlb - vaddr;

    te = &env->tlb_table[mmu_idx][index];
    te->addend = addend - vaddr;
    if (prot & PAGE_READ) {
        te->addr_read = address;
    } else {
        te->addr_read = -1;
    }

    if (prot & PAGE_EXEC) {
        te->addr_code = code_address;
    } else {
        te->addr_code = -1;
    }

    if (prot & PAGE_WRITE) {
        if (sreg) {
            // RAM
            int dirty = cpu_physical_memory_is_dirty(sreg->ram_addr + mem_desc_get_offset(sreg, paddr));
            if (!dirty) {
                te->addr_write = address | TLB_NOTDIRTY;
            } else {
                te->addr_write = address;
            }
        } else {
            // MMIO
            te->addr_write = address | TLB_MMIO;
        }
    } else {
        te->addr_write = -1;
    }

}
