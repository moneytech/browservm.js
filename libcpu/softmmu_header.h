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

#if DATA_SIZE == 8
#define SUFFIX q
#define USUFFIX q
#define DATA_TYPE uint64_t
#elif DATA_SIZE == 4
#define SUFFIX l
#define USUFFIX l
#define DATA_TYPE uint32_t
#elif DATA_SIZE == 2
#define SUFFIX w
#define USUFFIX uw
#define DATA_TYPE uint16_t
#define DATA_STYPE int16_t
#elif DATA_SIZE == 1
#define SUFFIX b
#define USUFFIX ub
#define DATA_TYPE uint8_t
#define DATA_STYPE int8_t
#else
#error unsupported data size
#endif

#if ACCESS_TYPE < (NB_MMU_MODES)

#define CPU_MMU_INDEX ACCESS_TYPE
#define MMUSUFFIX _mmu

#elif ACCESS_TYPE == (NB_MMU_MODES)

#define CPU_MMU_INDEX (cpu_mmu_index(env))
#define MMUSUFFIX _mmu

#elif ACCESS_TYPE == (NB_MMU_MODES + 1)

#define CPU_MMU_INDEX (cpu_mmu_index(env))
#define MMUSUFFIX _cmmu

#else
#error invalid ACCESS_TYPE
#endif

#if DATA_SIZE == 8
#define RES_TYPE uint64_t
#else
#define RES_TYPE uint32_t
#endif

#if ACCESS_TYPE == (NB_MMU_MODES + 1)
#define ADDR_READ addr_code
#define SE_NO_TRACE
#else
#define ADDR_READ addr_read
#endif

#define ADDR_MAX ((target_ulong) -1)


#define SMHINLINE inline
#define INSTR_BEFORE_MEMORY_ACCESS(...)
#define INSTR_AFTER_MEMORY_ACCESS(...)
#define INSTR_FORK_AND_CONCRETIZE(val, max) (val)
#define INSTR_FORK_AND_CONCRETIZE_ADDR(val, max) (val)

#define SE_RAM_OBJECT_BITS TARGET_PAGE_BITS
#define SE_RAM_OBJECT_DIFF 0





#define CPU_PREFIX cpu_
#define HELPER_PREFIX helper_

/* generic load/store macros */

static SMHINLINE RES_TYPE glue(glue(glue(CPU_PREFIX, ld), USUFFIX), MEMSUFFIX)(CPUArchState *env, target_ulong ptr) {
    target_ulong object_index, page_index;
    RES_TYPE res;
    target_ulong addr;
    target_ulong tlb_addr;
    uintptr_t physaddr;
    int mmu_idx;
    CPUTLBEntry *tlb_entry;


    addr = ptr;
    page_index = (addr >> TARGET_PAGE_BITS) & (CPU_TLB_SIZE - 1);
    object_index = 0;


    mmu_idx = CPU_MMU_INDEX;
    tlb_entry = &env->tlb_table[mmu_idx][page_index];
    tlb_addr = tlb_entry->ADDR_READ & ~TLB_MEM_TRACE;
    if (unlikely(tlb_addr != (addr & (TARGET_PAGE_MASK | (DATA_SIZE - 1))))) {
        res = glue(glue(glue(HELPER_PREFIX, ld), SUFFIX), MMUSUFFIX)(env, addr, mmu_idx, NULL);
    } else {
        // When we get here, the address is aligned with the size of the access,
        // which by definition means that it will fall inside the small page, without overflowing.


        physaddr = addr + env->tlb_table[mmu_idx][page_index].addend;
        res = glue(glue(ld, USUFFIX), _p)((uint8_t *) physaddr);


        INSTR_AFTER_MEMORY_ACCESS(addr, res, 0);
    }
    return res;
}

#if DATA_SIZE <= 2
static SMHINLINE int glue(glue(glue(CPU_PREFIX, lds), SUFFIX), MEMSUFFIX)(CPUArchState *env, target_ulong ptr) {
    int res;
    target_ulong object_index, page_index;
    target_ulong addr, tlb_addr;
    uintptr_t physaddr;
    int mmu_idx;
    CPUTLBEntry *tlb_entry;


    addr = ptr;
    page_index = (addr >> TARGET_PAGE_BITS) & (CPU_TLB_SIZE - 1);
    object_index = 0;


    mmu_idx = CPU_MMU_INDEX;
    tlb_entry = &env->tlb_table[mmu_idx][page_index];
    tlb_addr = tlb_entry->ADDR_READ & ~TLB_MEM_TRACE;
    if (unlikely(tlb_addr != (addr & (TARGET_PAGE_MASK | (DATA_SIZE - 1))))) {
        res = (DATA_STYPE) glue(glue(glue(HELPER_PREFIX, ld), SUFFIX), MMUSUFFIX)(env, addr, mmu_idx, NULL);
    } else {
        physaddr = addr + tlb_entry->addend;
        res = glue(glue(lds, SUFFIX), _p)((uint8_t *) physaddr);
        INSTR_AFTER_MEMORY_ACCESS(addr, res, 0);
    }
    return res;
}
#endif

#if ACCESS_TYPE != (NB_MMU_MODES + 1)

/* generic store macro */

static SMHINLINE void glue(glue(glue(CPU_PREFIX, st), SUFFIX), MEMSUFFIX)(CPUArchState *env, target_ulong ptr,
                                                                          RES_TYPE v) {
    target_ulong object_index, page_index;
    target_ulong addr, tlb_addr;
    uintptr_t physaddr;
    int mmu_idx;
    CPUTLBEntry *tlb_entry;


    addr = ptr;
    page_index = (addr >> TARGET_PAGE_BITS) & (CPU_TLB_SIZE - 1);
    object_index = 0;

    mmu_idx = CPU_MMU_INDEX;
    tlb_entry = &env->tlb_table[mmu_idx][page_index];
    tlb_addr = tlb_entry->addr_write & ~TLB_MEM_TRACE;
    if (unlikely(tlb_addr != (addr & (TARGET_PAGE_MASK | (DATA_SIZE - 1))))) {
        glue(glue(glue(HELPER_PREFIX, st), SUFFIX), MMUSUFFIX)(env, addr, v, mmu_idx, NULL);
    } else {
        physaddr = addr + env->tlb_table[mmu_idx][page_index].addend;
        glue(glue(st, SUFFIX), _p)((uint8_t *) physaddr, v);
        INSTR_AFTER_MEMORY_ACCESS(addr, v, MEM_TRACE_FLAG_WRITE);
    }
}

#endif /* ACCESS_TYPE != (NB_MMU_MODES + 1) */



#if ACCESS_TYPE != (NB_MMU_MODES + 1)

#if DATA_SIZE == 8
static SMHINLINE float64 glue(glue(CPU_PREFIX, ldfq), MEMSUFFIX)(CPUArchState *env, target_ulong ptr) {
    union {
        float64 d;
        uint64_t i;
    } u;
    u.i = glue(glue(CPU_PREFIX, ldq), MEMSUFFIX)(env, ptr);
    return u.d;
}

static SMHINLINE void glue(glue(CPU_PREFIX, stfq), MEMSUFFIX)(CPUArchState *env, target_ulong ptr, float64 v) {
    union {
        float64 d;
        uint64_t i;
    } u;
    u.d = v;
    glue(glue(CPU_PREFIX, stq), MEMSUFFIX)(env, ptr, u.i);
}
#endif /* DATA_SIZE == 8 */

#if DATA_SIZE == 4
static SMHINLINE float32 glue(glue(CPU_PREFIX, ldfl), MEMSUFFIX)(CPUArchState *env, target_ulong ptr) {
    union {
        float32 f;
        uint32_t i;
    } u;
    u.i = glue(glue(CPU_PREFIX, ldl), MEMSUFFIX)(env, ptr);
    return u.f;
}

static SMHINLINE void glue(glue(CPU_PREFIX, stfl), MEMSUFFIX)(CPUArchState *env, target_ulong ptr, float32 v) {
    union {
        float32 f;
        uint32_t i;
    } u;
    u.f = v;
    glue(glue(CPU_PREFIX, stl), MEMSUFFIX)(env, ptr, u.i);
}
#endif /* DATA_SIZE == 4 */

#endif /* ACCESS_TYPE != (NB_MMU_MODES + 1) */

#undef SE_RAM_OBJECT_BITS
#undef SE_RAM_OBJECT_DIFF
#undef INSTR_FORK_AND_CONCRETIZE
#undef INSTR_AFTER_MEMORY_ACCESS
#undef INSTR_BEFORE_MEMORY_ACCESS
#undef ADDR_MAX
#undef RES_TYPE
#undef DATA_TYPE
#undef DATA_STYPE
#undef SUFFIX
#undef USUFFIX
#undef DATA_SIZE
#undef CPU_MMU_INDEX
#undef MMUSUFFIX
#undef ADDR_READ
#undef CPU_PREFIX
#undef HELPER_PREFIX
