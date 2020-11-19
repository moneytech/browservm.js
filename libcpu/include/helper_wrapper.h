#ifndef WRAPPERS_H
#define WRAPPERS_H
inline uint64_t cc_compute_all_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	uint64_t res = helper_cc_compute_all((int)(arg1));
	return res;
}
inline uint64_t cc_compute_c_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	uint64_t res = helper_cc_compute_c((int)(arg1));
	return res;
}
inline uint64_t lock_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_lock();
	return 0;
}
inline uint64_t unlock_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_unlock();
	return 0;
}
inline uint64_t write_eflags_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_write_eflags((target_ulong)(arg1), (uint32_t)(arg2));
	return 0;
}
inline uint64_t read_eflags_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	uint64_t res = helper_read_eflags();
	return res;
}
inline uint64_t divb_AL_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_divb_AL((target_ulong)(arg1));
	return 0;
}
inline uint64_t idivb_AL_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_idivb_AL((target_ulong)(arg1));
	return 0;
}
uint64_t divw_AX_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_divw_AX((target_ulong)(arg1));
	return 0;
}
uint64_t idivw_AX_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_idivw_AX((target_ulong)(arg1));
	return 0;
}
uint64_t divl_EAX_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_divl_EAX((target_ulong)(arg1));
	return 0;
}
uint64_t idivl_EAX_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_idivl_EAX((target_ulong)(arg1));
	return 0;
}
inline uint64_t aam_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_aam((int)(arg1));
	return 0;
}
inline uint64_t aad_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_aad((int)(arg1));
	return 0;
}
inline uint64_t aaa_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_aaa();
	return 0;
}
inline uint64_t aas_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_aas();
	return 0;
}
inline uint64_t daa_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_daa();
	return 0;
}
inline uint64_t das_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_das();
	return 0;
}
inline uint64_t lsl_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	uint64_t res = helper_lsl((target_ulong)(arg1));
	return res;
}
inline uint64_t lar_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	uint64_t res = helper_lar((target_ulong)(arg1));
	return res;
}
inline uint64_t verr_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_verr((target_ulong)(arg1));
	return 0;
}
inline uint64_t verw_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_verw((target_ulong)(arg1));
	return 0;
}
inline uint64_t lldt_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_lldt((int)(arg1));
	return 0;
}
inline uint64_t ltr_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_ltr((int)(arg1));
	return 0;
}
inline uint64_t load_seg_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_load_seg((int)(arg1), (int)(arg2));
	return 0;
}
inline uint64_t ljmp_protected_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_ljmp_protected((int)(arg1), (target_ulong)(arg2), (int)(arg3));
	return 0;
}
inline uint64_t lcall_real_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_lcall_real((int)(arg1), (target_ulong)(arg2), (int)(arg3), (int)(arg4));
	return 0;
}
inline uint64_t lcall_protected_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_lcall_protected((int)(arg1), (target_ulong)(arg2), (int)(arg3), (int)(arg4));
	return 0;
}
inline uint64_t iret_real_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_iret_real((int)(arg1));
	return 0;
}
inline uint64_t iret_protected_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_iret_protected((int)(arg1), (int)(arg2));
	return 0;
}
inline uint64_t lret_protected_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_lret_protected((int)(arg1), (int)(arg2));
	return 0;
}
inline uint64_t read_crN_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	uint64_t res = helper_read_crN((int)(arg1));
	return res;
}
inline uint64_t write_crN_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_write_crN((int)(arg1), (target_ulong)(arg2));
	return 0;
}
inline uint64_t lmsw_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_lmsw((target_ulong)(arg1));
	return 0;
}
inline uint64_t clts_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_clts();
	return 0;
}
uint64_t movl_drN_T0_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_movl_drN_T0((int)(arg1), (target_ulong)(arg2));
	return 0;
}
inline uint64_t invlpg_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_invlpg((target_ulong)(arg1));
	return 0;
}
inline uint64_t enter_level_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_enter_level((int)(arg1), (int)(arg2), (target_ulong)(arg3));
	return 0;
}
uint64_t sysenter_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_sysenter();
	return 0;
}
uint64_t sysexit_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_sysexit((int)(arg1));
	return 0;
}
inline uint64_t hlt_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_hlt((int)(arg1));
	return 0;
}
inline uint64_t monitor_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_monitor((target_ulong)(arg1));
	return 0;
}
inline uint64_t mwait_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_mwait((int)(arg1));
	return 0;
}
inline uint64_t debug_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_debug();
	return 0;
}
inline uint64_t reset_rf_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_reset_rf();
	return 0;
}
inline uint64_t raise_interrupt_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_raise_interrupt((int)(arg1), (int)(arg2));
	return 0;
}
uint64_t raise_exception_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_raise_exception((int)(arg1));
	return 0;
}
inline uint64_t cli_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_cli();
	return 0;
}
inline uint64_t sti_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_sti();
	return 0;
}
inline uint64_t set_inhibit_irq_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_set_inhibit_irq();
	return 0;
}
inline uint64_t reset_inhibit_irq_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_reset_inhibit_irq();
	return 0;
}
inline uint64_t boundw_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_boundw((target_ulong)(arg1), (int)(arg2));
	return 0;
}
inline uint64_t boundl_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_boundl((target_ulong)(arg1), (int)(arg2));
	return 0;
}
inline uint64_t rsm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_rsm();
	return 0;
}
inline uint64_t into_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_into((int)(arg1));
	return 0;
}
uint64_t cmpxchg8b_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_cmpxchg8b((target_ulong)(arg1));
	return 0;
}
inline uint64_t single_step_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_single_step();
	return 0;
}
inline uint64_t cpuid_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_cpuid();
	return 0;
}
inline uint64_t rdtsc_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_rdtsc();
	return 0;
}
inline uint64_t rdtscp_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_rdtscp();
	return 0;
}
inline uint64_t rdpmc_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_rdpmc();
	return 0;
}
inline uint64_t rdmsr_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_rdmsr();
	return 0;
}
inline uint64_t wrmsr_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_wrmsr();
	return 0;
}
inline uint64_t check_iob_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_check_iob((uint32_t)(arg1));
	return 0;
}
inline uint64_t check_iow_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_check_iow((uint32_t)(arg1));
	return 0;
}
inline uint64_t check_iol_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_check_iol((uint32_t)(arg1));
	return 0;
}
inline uint64_t outb_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_outb((uint32_t)(arg1), (uint32_t)(arg2));
	return 0;
}
inline uint64_t inb_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	uint64_t res = helper_inb((uint32_t)(arg1));
	return res;
}
inline uint64_t outw_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_outw((uint32_t)(arg1), (uint32_t)(arg2));
	return 0;
}
inline uint64_t inw_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	uint64_t res = helper_inw((uint32_t)(arg1));
	return res;
}
inline uint64_t outl_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_outl((uint32_t)(arg1), (uint32_t)(arg2));
	return 0;
}
inline uint64_t inl_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	uint64_t res = helper_inl((uint32_t)(arg1));
	return res;
}
inline uint64_t svm_check_intercept_param_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_svm_check_intercept_param((uint32_t)(arg1), (uint64_t)(0 | (((long long)arg2) << 0) | (((long long)arg3) << 32)));
	return 0;
}
uint64_t vmexit_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_vmexit((uint32_t)(arg1), (uint64_t)(0 | (((long long)arg2) << 0) | (((long long)arg3) << 32)));
	return 0;
}
inline uint64_t svm_check_io_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_svm_check_io((uint32_t)(arg1), (uint32_t)(arg2), (uint32_t)(arg3));
	return 0;
}
inline uint64_t vmrun_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_vmrun((int)(arg1), (int)(arg2));
	return 0;
}
inline uint64_t vmmcall_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_vmmcall();
	return 0;
}
inline uint64_t vmload_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_vmload((int)(arg1));
	return 0;
}
inline uint64_t vmsave_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_vmsave((int)(arg1));
	return 0;
}
inline uint64_t stgi_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_stgi();
	return 0;
}
inline uint64_t clgi_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_clgi();
	return 0;
}
inline uint64_t skinit_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_skinit();
	return 0;
}
inline uint64_t invlpga_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_invlpga((int)(arg1));
	return 0;
}
uint64_t flds_FT0_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_flds_FT0((uint32_t)(arg1));
	return 0;
}
uint64_t fldl_FT0_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_fldl_FT0((uint64_t)(0 | (((long long)arg1) << 0) | (((long long)arg2) << 32)));
	return 0;
}
uint64_t fildl_FT0_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_fildl_FT0((int32_t)(arg1));
	return 0;
}
uint64_t flds_ST0_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_flds_ST0((uint32_t)(arg1));
	return 0;
}
uint64_t fldl_ST0_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_fldl_ST0((uint64_t)(0 | (((long long)arg1) << 0) | (((long long)arg2) << 32)));
	return 0;
}
uint64_t fildl_ST0_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_fildl_ST0((int32_t)(arg1));
	return 0;
}
uint64_t fildll_ST0_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_fildll_ST0((int64_t)(0 | (((long long)arg1) << 0) | (((long long)arg2) << 32)));
	return 0;
}
uint64_t fsts_ST0_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	uint64_t res = helper_fsts_ST0();
	return res;
}
uint64_t fstl_ST0_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	uint64_t res = helper_fstl_ST0();
	return res;
}
uint64_t fist_ST0_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	uint64_t res = helper_fist_ST0();
	return res;
}
uint64_t fistl_ST0_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	uint64_t res = helper_fistl_ST0();
	return res;
}
uint64_t fistll_ST0_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	uint64_t res = helper_fistll_ST0();
	return res;
}
uint64_t fistt_ST0_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	uint64_t res = helper_fistt_ST0();
	return res;
}
uint64_t fisttl_ST0_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	uint64_t res = helper_fisttl_ST0();
	return res;
}
uint64_t fisttll_ST0_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	uint64_t res = helper_fisttll_ST0();
	return res;
}
uint64_t fldt_ST0_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_fldt_ST0((target_ulong)(arg1));
	return 0;
}
uint64_t fstt_ST0_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_fstt_ST0((target_ulong)(arg1));
	return 0;
}
inline uint64_t fpush_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_fpush();
	return 0;
}
inline uint64_t fpop_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_fpop();
	return 0;
}
inline uint64_t fdecstp_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_fdecstp();
	return 0;
}
inline uint64_t fincstp_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_fincstp();
	return 0;
}
inline uint64_t ffree_STN_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_ffree_STN((int)(arg1));
	return 0;
}
uint64_t fmov_ST0_FT0_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_fmov_ST0_FT0();
	return 0;
}
uint64_t fmov_FT0_STN_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_fmov_FT0_STN((int)(arg1));
	return 0;
}
uint64_t fmov_ST0_STN_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_fmov_ST0_STN((int)(arg1));
	return 0;
}
uint64_t fmov_STN_ST0_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_fmov_STN_ST0((int)(arg1));
	return 0;
}
uint64_t fxchg_ST0_STN_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_fxchg_ST0_STN((int)(arg1));
	return 0;
}
uint64_t fcom_ST0_FT0_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_fcom_ST0_FT0();
	return 0;
}
uint64_t fucom_ST0_FT0_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_fucom_ST0_FT0();
	return 0;
}
uint64_t fcomi_ST0_FT0_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_fcomi_ST0_FT0();
	return 0;
}
uint64_t fucomi_ST0_FT0_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_fucomi_ST0_FT0();
	return 0;
}
uint64_t fadd_ST0_FT0_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_fadd_ST0_FT0();
	return 0;
}
uint64_t fmul_ST0_FT0_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_fmul_ST0_FT0();
	return 0;
}
uint64_t fsub_ST0_FT0_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_fsub_ST0_FT0();
	return 0;
}
uint64_t fsubr_ST0_FT0_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_fsubr_ST0_FT0();
	return 0;
}
uint64_t fdiv_ST0_FT0_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_fdiv_ST0_FT0();
	return 0;
}
uint64_t fdivr_ST0_FT0_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_fdivr_ST0_FT0();
	return 0;
}
uint64_t fadd_STN_ST0_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_fadd_STN_ST0((int)(arg1));
	return 0;
}
uint64_t fmul_STN_ST0_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_fmul_STN_ST0((int)(arg1));
	return 0;
}
uint64_t fsub_STN_ST0_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_fsub_STN_ST0((int)(arg1));
	return 0;
}
uint64_t fsubr_STN_ST0_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_fsubr_STN_ST0((int)(arg1));
	return 0;
}
uint64_t fdiv_STN_ST0_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_fdiv_STN_ST0((int)(arg1));
	return 0;
}
uint64_t fdivr_STN_ST0_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_fdivr_STN_ST0((int)(arg1));
	return 0;
}
uint64_t fchs_ST0_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_fchs_ST0();
	return 0;
}
uint64_t fabs_ST0_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_fabs_ST0();
	return 0;
}
uint64_t fxam_ST0_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_fxam_ST0();
	return 0;
}
uint64_t fld1_ST0_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_fld1_ST0();
	return 0;
}
uint64_t fldl2t_ST0_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_fldl2t_ST0();
	return 0;
}
uint64_t fldl2e_ST0_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_fldl2e_ST0();
	return 0;
}
uint64_t fldpi_ST0_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_fldpi_ST0();
	return 0;
}
uint64_t fldlg2_ST0_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_fldlg2_ST0();
	return 0;
}
uint64_t fldln2_ST0_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_fldln2_ST0();
	return 0;
}
uint64_t fldz_ST0_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_fldz_ST0();
	return 0;
}
uint64_t fldz_FT0_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_fldz_FT0();
	return 0;
}
inline uint64_t fnstsw_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	uint64_t res = helper_fnstsw();
	return res;
}
inline uint64_t fnstcw_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	uint64_t res = helper_fnstcw();
	return res;
}
inline uint64_t fldcw_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_fldcw((uint32_t)(arg1));
	return 0;
}
uint64_t fclex_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_fclex();
	return 0;
}
inline uint64_t fwait_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_fwait();
	return 0;
}
inline uint64_t fninit_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_fninit();
	return 0;
}
uint64_t fbld_ST0_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_fbld_ST0((target_ulong)(arg1));
	return 0;
}
uint64_t fbst_ST0_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_fbst_ST0((target_ulong)(arg1));
	return 0;
}
uint64_t f2xm1_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_f2xm1();
	return 0;
}
uint64_t fyl2x_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_fyl2x();
	return 0;
}
inline uint64_t fptan_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_fptan();
	return 0;
}
inline uint64_t fpatan_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_fpatan();
	return 0;
}
uint64_t fxtract_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_fxtract();
	return 0;
}
uint64_t fprem1_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_fprem1();
	return 0;
}
inline uint64_t fprem_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_fprem();
	return 0;
}
uint64_t fyl2xp1_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_fyl2xp1();
	return 0;
}
inline uint64_t fsqrt_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_fsqrt();
	return 0;
}
inline uint64_t fsincos_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_fsincos();
	return 0;
}
inline uint64_t frndint_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_frndint();
	return 0;
}
inline uint64_t fscale_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_fscale();
	return 0;
}
inline uint64_t fsin_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_fsin();
	return 0;
}
inline uint64_t fcos_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_fcos();
	return 0;
}
inline uint64_t fstenv_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_fstenv((target_ulong)(arg1), (int)(arg2));
	return 0;
}
inline uint64_t fldenv_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_fldenv((target_ulong)(arg1), (int)(arg2));
	return 0;
}
inline uint64_t fsave_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_fsave((target_ulong)(arg1), (int)(arg2));
	return 0;
}
inline uint64_t frstor_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_frstor((target_ulong)(arg1), (int)(arg2));
	return 0;
}
uint64_t fxsave_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_fxsave((target_ulong)(arg1), (int)(arg2));
	return 0;
}
uint64_t fxrstor_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_fxrstor((target_ulong)(arg1), (int)(arg2));
	return 0;
}
inline uint64_t bsf_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	uint64_t res = helper_bsf((target_ulong)(arg1));
	return res;
}
inline uint64_t bsr_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	uint64_t res = helper_bsr((target_ulong)(arg1));
	return res;
}
uint64_t lzcnt_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	uint64_t res = helper_lzcnt((target_ulong)(arg1), (int)(arg2));
	return res;
}
uint64_t ldmxcsr_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_ldmxcsr((uint32_t)(arg1));
	return 0;
}
uint64_t enter_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_enter_mmx();
	return 0;
}
inline uint64_t emms_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_emms();
	return 0;
}
inline uint64_t movq_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_movq((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t psrlw_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_psrlw_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t psraw_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_psraw_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t psllw_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_psllw_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t psrld_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_psrld_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t psrad_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_psrad_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pslld_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pslld_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t psrlq_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_psrlq_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t psllq_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_psllq_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t paddb_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_paddb_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t paddw_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_paddw_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t paddl_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_paddl_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t paddq_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_paddq_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t psubb_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_psubb_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t psubw_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_psubw_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t psubl_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_psubl_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t psubq_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_psubq_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t paddusb_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_paddusb_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t paddsb_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_paddsb_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t psubusb_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_psubusb_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t psubsb_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_psubsb_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t paddusw_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_paddusw_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t paddsw_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_paddsw_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t psubusw_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_psubusw_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t psubsw_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_psubsw_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pminub_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pminub_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pmaxub_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pmaxub_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pminsw_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pminsw_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pmaxsw_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pmaxsw_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pand_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pand_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pandn_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pandn_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t por_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_por_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pxor_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pxor_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pcmpgtb_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pcmpgtb_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pcmpgtw_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pcmpgtw_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pcmpgtl_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pcmpgtl_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pcmpeqb_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pcmpeqb_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pcmpeqw_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pcmpeqw_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pcmpeql_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pcmpeql_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pmullw_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pmullw_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pmulhrw_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pmulhrw_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pmulhuw_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pmulhuw_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pmulhw_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pmulhw_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pavgb_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pavgb_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pavgw_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pavgw_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pmuludq_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pmuludq_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pmaddwd_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pmaddwd_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t psadbw_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_psadbw_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t maskmov_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_maskmov_mmx((void *)(arg1), (void *)(arg2), (target_ulong)(arg3));
	return 0;
}
uint64_t movl_mm_T0_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_movl_mm_T0_mmx((void *)(arg1), (uint32_t)(arg2));
	return 0;
}
uint64_t pshufw_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pshufw_mmx((void *)(arg1), (void *)(arg2), (int)(arg3));
	return 0;
}
uint64_t pmovmskb_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	uint64_t res = helper_pmovmskb_mmx((void *)(arg1));
	return res;
}
uint64_t packsswb_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_packsswb_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t packuswb_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_packuswb_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t packssdw_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_packssdw_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t punpcklbw_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_punpcklbw_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t punpcklwd_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_punpcklwd_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t punpckldq_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_punpckldq_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t punpckhbw_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_punpckhbw_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t punpckhwd_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_punpckhwd_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t punpckhdq_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_punpckhdq_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pi2fd_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pi2fd((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pi2fw_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pi2fw((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pf2id_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pf2id((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pf2iw_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pf2iw((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t pfacc_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pfacc((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t pfadd_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pfadd((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t pfcmpeq_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pfcmpeq((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t pfcmpge_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pfcmpge((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t pfcmpgt_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pfcmpgt((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pfmax_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pfmax((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t pfmin_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pfmin((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t pfmul_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pfmul((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t pfnacc_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pfnacc((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t pfpnacc_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pfpnacc((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t pfrcp_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pfrcp((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t pfrsqrt_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pfrsqrt((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t pfsub_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pfsub((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t pfsubr_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pfsubr((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t pswapd_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pswapd((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t phaddw_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_phaddw_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t phaddd_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_phaddd_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t phaddsw_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_phaddsw_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t phsubw_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_phsubw_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t phsubd_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_phsubd_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t phsubsw_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_phsubsw_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pabsb_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pabsb_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pabsw_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pabsw_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pabsd_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pabsd_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pmaddubsw_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pmaddubsw_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pmulhrsw_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pmulhrsw_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pshufb_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pshufb_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t psignb_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_psignb_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t psignw_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_psignw_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t psignd_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_psignd_mmx((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t palignr_mmx_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_palignr_mmx((void *)(arg1), (void *)(arg2), (int32_t)(arg3));
	return 0;
}
uint64_t psrlw_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_psrlw_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t psraw_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_psraw_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t psllw_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_psllw_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t psrld_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_psrld_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t psrad_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_psrad_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pslld_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pslld_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t psrlq_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_psrlq_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t psllq_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_psllq_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t psrldq_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_psrldq_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pslldq_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pslldq_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t paddb_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_paddb_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t paddw_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_paddw_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t paddl_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_paddl_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t paddq_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_paddq_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t psubb_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_psubb_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t psubw_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_psubw_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t psubl_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_psubl_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t psubq_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_psubq_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t paddusb_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_paddusb_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t paddsb_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_paddsb_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t psubusb_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_psubusb_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t psubsb_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_psubsb_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t paddusw_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_paddusw_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t paddsw_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_paddsw_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t psubusw_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_psubusw_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t psubsw_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_psubsw_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pminub_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pminub_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pmaxub_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pmaxub_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pminsw_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pminsw_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pmaxsw_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pmaxsw_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pand_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pand_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pandn_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pandn_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t por_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_por_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pxor_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pxor_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pcmpgtb_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pcmpgtb_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pcmpgtw_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pcmpgtw_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pcmpgtl_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pcmpgtl_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pcmpeqb_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pcmpeqb_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pcmpeqw_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pcmpeqw_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pcmpeql_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pcmpeql_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pmullw_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pmullw_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pmulhuw_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pmulhuw_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pmulhw_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pmulhw_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pavgb_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pavgb_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pavgw_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pavgw_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pmuludq_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pmuludq_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pmaddwd_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pmaddwd_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t psadbw_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_psadbw_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t maskmov_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_maskmov_xmm((void *)(arg1), (void *)(arg2), (target_ulong)(arg3));
	return 0;
}
uint64_t movl_mm_T0_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_movl_mm_T0_xmm((void *)(arg1), (uint32_t)(arg2));
	return 0;
}
inline uint64_t shufps_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_shufps((void *)(arg1), (void *)(arg2), (int)(arg3));
	return 0;
}
inline uint64_t shufpd_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_shufpd((void *)(arg1), (void *)(arg2), (int)(arg3));
	return 0;
}
uint64_t pshufd_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pshufd_xmm((void *)(arg1), (void *)(arg2), (int)(arg3));
	return 0;
}
uint64_t pshuflw_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pshuflw_xmm((void *)(arg1), (void *)(arg2), (int)(arg3));
	return 0;
}
uint64_t pshufhw_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pshufhw_xmm((void *)(arg1), (void *)(arg2), (int)(arg3));
	return 0;
}
inline uint64_t addps_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_addps((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t addss_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_addss((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t addpd_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_addpd((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t addsd_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_addsd((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t subps_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_subps((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t subss_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_subss((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t subpd_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_subpd((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t subsd_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_subsd((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t mulps_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_mulps((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t mulss_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_mulss((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t mulpd_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_mulpd((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t mulsd_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_mulsd((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t divps_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_divps((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t divss_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_divss((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t divpd_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_divpd((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t divsd_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_divsd((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t minps_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_minps((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t minss_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_minss((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t minpd_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_minpd((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t minsd_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_minsd((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t maxps_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_maxps((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t maxss_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_maxss((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t maxpd_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_maxpd((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t maxsd_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_maxsd((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t sqrtps_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_sqrtps((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t sqrtss_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_sqrtss((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t sqrtpd_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_sqrtpd((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t sqrtsd_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_sqrtsd((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t cvtps2pd_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_cvtps2pd((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t cvtpd2ps_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_cvtpd2ps((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t cvtss2sd_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_cvtss2sd((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t cvtsd2ss_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_cvtsd2ss((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t cvtdq2ps_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_cvtdq2ps((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t cvtdq2pd_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_cvtdq2pd((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t cvtpi2ps_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_cvtpi2ps((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t cvtpi2pd_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_cvtpi2pd((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t cvtsi2ss_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_cvtsi2ss((void *)(arg1), (uint32_t)(arg2));
	return 0;
}
uint64_t cvtsi2sd_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_cvtsi2sd((void *)(arg1), (uint32_t)(arg2));
	return 0;
}
uint64_t cvtps2dq_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_cvtps2dq((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t cvtpd2dq_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_cvtpd2dq((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t cvtps2pi_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_cvtps2pi((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t cvtpd2pi_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_cvtpd2pi((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t cvtss2si_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	uint64_t res = helper_cvtss2si((void *)(arg1));
	return res;
}
uint64_t cvtsd2si_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	uint64_t res = helper_cvtsd2si((void *)(arg1));
	return res;
}
uint64_t cvttps2dq_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_cvttps2dq((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t cvttpd2dq_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_cvttpd2dq((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t cvttps2pi_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_cvttps2pi((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t cvttpd2pi_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_cvttpd2pi((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t cvttss2si_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	uint64_t res = helper_cvttss2si((void *)(arg1));
	return res;
}
uint64_t cvttsd2si_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	uint64_t res = helper_cvttsd2si((void *)(arg1));
	return res;
}
inline uint64_t rsqrtps_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_rsqrtps((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t rsqrtss_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_rsqrtss((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t rcpps_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_rcpps((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t rcpss_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_rcpss((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t extrq_r_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_extrq_r((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t extrq_i_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_extrq_i((void *)(arg1), (int)(arg2), (int)(arg3));
	return 0;
}
inline uint64_t insertq_r_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_insertq_r((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t insertq_i_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_insertq_i((void *)(arg1), (int)(arg2), (int)(arg3));
	return 0;
}
inline uint64_t haddps_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_haddps((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t haddpd_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_haddpd((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t hsubps_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_hsubps((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t hsubpd_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_hsubpd((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t addsubps_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_addsubps((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t addsubpd_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_addsubpd((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t cmpeqps_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_cmpeqps((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t cmpeqss_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_cmpeqss((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t cmpeqpd_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_cmpeqpd((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t cmpeqsd_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_cmpeqsd((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t cmpltps_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_cmpltps((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t cmpltss_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_cmpltss((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t cmpltpd_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_cmpltpd((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t cmpltsd_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_cmpltsd((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t cmpleps_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_cmpleps((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t cmpless_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_cmpless((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t cmplepd_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_cmplepd((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t cmplesd_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_cmplesd((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t cmpunordps_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_cmpunordps((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t cmpunordss_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_cmpunordss((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t cmpunordpd_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_cmpunordpd((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t cmpunordsd_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_cmpunordsd((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t cmpneqps_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_cmpneqps((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t cmpneqss_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_cmpneqss((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t cmpneqpd_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_cmpneqpd((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t cmpneqsd_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_cmpneqsd((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t cmpnltps_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_cmpnltps((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t cmpnltss_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_cmpnltss((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t cmpnltpd_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_cmpnltpd((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t cmpnltsd_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_cmpnltsd((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t cmpnleps_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_cmpnleps((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t cmpnless_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_cmpnless((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t cmpnlepd_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_cmpnlepd((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t cmpnlesd_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_cmpnlesd((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t cmpordps_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_cmpordps((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t cmpordss_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_cmpordss((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t cmpordpd_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_cmpordpd((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t cmpordsd_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_cmpordsd((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t ucomiss_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_ucomiss((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t comiss_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_comiss((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t ucomisd_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_ucomisd((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t comisd_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_comisd((void *)(arg1), (void *)(arg2));
	return 0;
}
inline uint64_t movmskps_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	uint64_t res = helper_movmskps((void *)(arg1));
	return res;
}
inline uint64_t movmskpd_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	uint64_t res = helper_movmskpd((void *)(arg1));
	return res;
}
uint64_t pmovmskb_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	uint64_t res = helper_pmovmskb_xmm((void *)(arg1));
	return res;
}
uint64_t packsswb_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_packsswb_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t packuswb_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_packuswb_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t packssdw_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_packssdw_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t punpcklbw_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_punpcklbw_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t punpcklwd_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_punpcklwd_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t punpckldq_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_punpckldq_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t punpckhbw_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_punpckhbw_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t punpckhwd_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_punpckhwd_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t punpckhdq_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_punpckhdq_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t punpcklqdq_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_punpcklqdq_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t punpckhqdq_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_punpckhqdq_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t phaddw_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_phaddw_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t phaddd_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_phaddd_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t phaddsw_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_phaddsw_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t phsubw_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_phsubw_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t phsubd_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_phsubd_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t phsubsw_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_phsubsw_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pabsb_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pabsb_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pabsw_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pabsw_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pabsd_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pabsd_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pmaddubsw_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pmaddubsw_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pmulhrsw_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pmulhrsw_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pshufb_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pshufb_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t psignb_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_psignb_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t psignw_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_psignw_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t psignd_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_psignd_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t palignr_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_palignr_xmm((void *)(arg1), (void *)(arg2), (int32_t)(arg3));
	return 0;
}
uint64_t pblendvb_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pblendvb_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t blendvps_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_blendvps_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t blendvpd_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_blendvpd_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t ptest_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_ptest_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pmovsxbw_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pmovsxbw_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pmovsxbd_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pmovsxbd_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pmovsxbq_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pmovsxbq_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pmovsxwd_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pmovsxwd_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pmovsxwq_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pmovsxwq_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pmovsxdq_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pmovsxdq_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pmovzxbw_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pmovzxbw_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pmovzxbd_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pmovzxbd_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pmovzxbq_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pmovzxbq_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pmovzxwd_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pmovzxwd_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pmovzxwq_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pmovzxwq_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pmovzxdq_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pmovzxdq_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pmuldq_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pmuldq_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pcmpeqq_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pcmpeqq_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t packusdw_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_packusdw_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pminsb_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pminsb_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pminsd_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pminsd_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pminuw_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pminuw_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pminud_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pminud_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pmaxsb_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pmaxsb_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pmaxsd_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pmaxsd_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pmaxuw_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pmaxuw_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pmaxud_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pmaxud_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pmulld_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pmulld_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t phminposuw_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_phminposuw_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t roundps_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_roundps_xmm((void *)(arg1), (void *)(arg2), (uint32_t)(arg3));
	return 0;
}
uint64_t roundpd_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_roundpd_xmm((void *)(arg1), (void *)(arg2), (uint32_t)(arg3));
	return 0;
}
uint64_t roundss_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_roundss_xmm((void *)(arg1), (void *)(arg2), (uint32_t)(arg3));
	return 0;
}
uint64_t roundsd_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_roundsd_xmm((void *)(arg1), (void *)(arg2), (uint32_t)(arg3));
	return 0;
}
uint64_t blendps_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_blendps_xmm((void *)(arg1), (void *)(arg2), (uint32_t)(arg3));
	return 0;
}
uint64_t blendpd_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_blendpd_xmm((void *)(arg1), (void *)(arg2), (uint32_t)(arg3));
	return 0;
}
uint64_t pblendw_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pblendw_xmm((void *)(arg1), (void *)(arg2), (uint32_t)(arg3));
	return 0;
}
uint64_t dpps_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_dpps_xmm((void *)(arg1), (void *)(arg2), (uint32_t)(arg3));
	return 0;
}
uint64_t dppd_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_dppd_xmm((void *)(arg1), (void *)(arg2), (uint32_t)(arg3));
	return 0;
}
uint64_t mpsadbw_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_mpsadbw_xmm((void *)(arg1), (void *)(arg2), (uint32_t)(arg3));
	return 0;
}
uint64_t pcmpgtq_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pcmpgtq_xmm((void *)(arg1), (void *)(arg2));
	return 0;
}
uint64_t pcmpestri_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pcmpestri_xmm((void *)(arg1), (void *)(arg2), (uint32_t)(arg3));
	return 0;
}
uint64_t pcmpestrm_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pcmpestrm_xmm((void *)(arg1), (void *)(arg2), (uint32_t)(arg3));
	return 0;
}
uint64_t pcmpistri_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pcmpistri_xmm((void *)(arg1), (void *)(arg2), (uint32_t)(arg3));
	return 0;
}
uint64_t pcmpistrm_xmm_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_pcmpistrm_xmm((void *)(arg1), (void *)(arg2), (uint32_t)(arg3));
	return 0;
}
uint64_t crc32_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	uint64_t res = helper_crc32((uint32_t)(arg1), (target_ulong)(arg2), (uint32_t)(arg3));
	return res;
}
inline uint64_t popcnt_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	uint64_t res = helper_popcnt((target_ulong)(arg1), (uint32_t)(arg2));
	return res;
}
inline uint64_t rclb_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	uint64_t res = helper_rclb((target_ulong)(arg1), (target_ulong)(arg2));
	return res;
}
inline uint64_t rclw_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	uint64_t res = helper_rclw((target_ulong)(arg1), (target_ulong)(arg2));
	return res;
}
inline uint64_t rcll_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	uint64_t res = helper_rcll((target_ulong)(arg1), (target_ulong)(arg2));
	return res;
}
inline uint64_t rcrb_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	uint64_t res = helper_rcrb((target_ulong)(arg1), (target_ulong)(arg2));
	return res;
}
inline uint64_t rcrw_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	uint64_t res = helper_rcrw((target_ulong)(arg1), (target_ulong)(arg2));
	return res;
}
inline uint64_t rcrl_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	uint64_t res = helper_rcrl((target_ulong)(arg1), (target_ulong)(arg2));
	return res;
}
inline uint64_t se_opcode_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_se_opcode((uint64_t)(0 | (((long long)arg1) << 0) | (((long long)arg2) << 32)));
	return 0;
}
inline uint64_t gvec_mov_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_mov((void *)(arg1), (void *)(arg2), (uint32_t)(arg3));
	return 0;
}
uint64_t gvec_dup8_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_dup8((void *)(arg1), (uint32_t)(arg2), (uint32_t)(arg3));
	return 0;
}
uint64_t gvec_dup16_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_dup16((void *)(arg1), (uint32_t)(arg2), (uint32_t)(arg3));
	return 0;
}
uint64_t gvec_dup32_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_dup32((void *)(arg1), (uint32_t)(arg2), (uint32_t)(arg3));
	return 0;
}
uint64_t gvec_dup64_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_dup64((void *)(arg1), (uint32_t)(arg2), (uint64_t)(0 | (((long long)arg3) << 0) | (((long long)arg4) << 32)));
	return 0;
}
uint64_t gvec_add8_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_add8((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_add16_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_add16((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_add32_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_add32((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_add64_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_add64((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_adds8_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_adds8((void *)(arg1), (void *)(arg2), (uint64_t)(0 | (((long long)arg3) << 0) | (((long long)arg4) << 32)), (uint32_t)(arg5));
	return 0;
}
uint64_t gvec_adds16_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_adds16((void *)(arg1), (void *)(arg2), (uint64_t)(0 | (((long long)arg3) << 0) | (((long long)arg4) << 32)), (uint32_t)(arg5));
	return 0;
}
uint64_t gvec_adds32_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_adds32((void *)(arg1), (void *)(arg2), (uint64_t)(0 | (((long long)arg3) << 0) | (((long long)arg4) << 32)), (uint32_t)(arg5));
	return 0;
}
uint64_t gvec_adds64_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_adds64((void *)(arg1), (void *)(arg2), (uint64_t)(0 | (((long long)arg3) << 0) | (((long long)arg4) << 32)), (uint32_t)(arg5));
	return 0;
}
uint64_t gvec_sub8_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_sub8((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_sub16_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_sub16((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_sub32_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_sub32((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_sub64_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_sub64((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_subs8_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_subs8((void *)(arg1), (void *)(arg2), (uint64_t)(0 | (((long long)arg3) << 0) | (((long long)arg4) << 32)), (uint32_t)(arg5));
	return 0;
}
uint64_t gvec_subs16_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_subs16((void *)(arg1), (void *)(arg2), (uint64_t)(0 | (((long long)arg3) << 0) | (((long long)arg4) << 32)), (uint32_t)(arg5));
	return 0;
}
uint64_t gvec_subs32_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_subs32((void *)(arg1), (void *)(arg2), (uint64_t)(0 | (((long long)arg3) << 0) | (((long long)arg4) << 32)), (uint32_t)(arg5));
	return 0;
}
uint64_t gvec_subs64_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_subs64((void *)(arg1), (void *)(arg2), (uint64_t)(0 | (((long long)arg3) << 0) | (((long long)arg4) << 32)), (uint32_t)(arg5));
	return 0;
}
uint64_t gvec_mul8_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_mul8((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_mul16_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_mul16((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_mul32_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_mul32((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_mul64_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_mul64((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_muls8_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_muls8((void *)(arg1), (void *)(arg2), (uint64_t)(0 | (((long long)arg3) << 0) | (((long long)arg4) << 32)), (uint32_t)(arg5));
	return 0;
}
uint64_t gvec_muls16_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_muls16((void *)(arg1), (void *)(arg2), (uint64_t)(0 | (((long long)arg3) << 0) | (((long long)arg4) << 32)), (uint32_t)(arg5));
	return 0;
}
uint64_t gvec_muls32_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_muls32((void *)(arg1), (void *)(arg2), (uint64_t)(0 | (((long long)arg3) << 0) | (((long long)arg4) << 32)), (uint32_t)(arg5));
	return 0;
}
uint64_t gvec_muls64_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_muls64((void *)(arg1), (void *)(arg2), (uint64_t)(0 | (((long long)arg3) << 0) | (((long long)arg4) << 32)), (uint32_t)(arg5));
	return 0;
}
uint64_t gvec_ssadd8_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_ssadd8((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_ssadd16_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_ssadd16((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_ssadd32_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_ssadd32((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_ssadd64_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_ssadd64((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_sssub8_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_sssub8((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_sssub16_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_sssub16((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_sssub32_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_sssub32((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_sssub64_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_sssub64((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_usadd8_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_usadd8((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_usadd16_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_usadd16((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_usadd32_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_usadd32((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_usadd64_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_usadd64((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_ussub8_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_ussub8((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_ussub16_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_ussub16((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_ussub32_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_ussub32((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_ussub64_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_ussub64((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_smin8_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_smin8((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_smin16_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_smin16((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_smin32_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_smin32((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_smin64_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_smin64((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_smax8_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_smax8((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_smax16_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_smax16((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_smax32_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_smax32((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_smax64_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_smax64((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_umin8_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_umin8((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_umin16_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_umin16((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_umin32_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_umin32((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_umin64_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_umin64((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_umax8_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_umax8((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_umax16_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_umax16((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_umax32_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_umax32((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_umax64_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_umax64((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_neg8_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_neg8((void *)(arg1), (void *)(arg2), (uint32_t)(arg3));
	return 0;
}
uint64_t gvec_neg16_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_neg16((void *)(arg1), (void *)(arg2), (uint32_t)(arg3));
	return 0;
}
uint64_t gvec_neg32_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_neg32((void *)(arg1), (void *)(arg2), (uint32_t)(arg3));
	return 0;
}
uint64_t gvec_neg64_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_neg64((void *)(arg1), (void *)(arg2), (uint32_t)(arg3));
	return 0;
}
inline uint64_t gvec_not_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_not((void *)(arg1), (void *)(arg2), (uint32_t)(arg3));
	return 0;
}
inline uint64_t gvec_and_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_and((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
inline uint64_t gvec_or_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_or((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_xor_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_xor((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
inline uint64_t gvec_andc_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_andc((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
inline uint64_t gvec_orc_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_orc((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
inline uint64_t gvec_nand_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_nand((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
inline uint64_t gvec_nor_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_nor((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
inline uint64_t gvec_eqv_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_eqv((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
inline uint64_t gvec_ands_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_ands((void *)(arg1), (void *)(arg2), (uint64_t)(0 | (((long long)arg3) << 0) | (((long long)arg4) << 32)), (uint32_t)(arg5));
	return 0;
}
uint64_t gvec_xors_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_xors((void *)(arg1), (void *)(arg2), (uint64_t)(0 | (((long long)arg3) << 0) | (((long long)arg4) << 32)), (uint32_t)(arg5));
	return 0;
}
inline uint64_t gvec_ors_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_ors((void *)(arg1), (void *)(arg2), (uint64_t)(0 | (((long long)arg3) << 0) | (((long long)arg4) << 32)), (uint32_t)(arg5));
	return 0;
}
uint64_t gvec_shl8i_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_shl8i((void *)(arg1), (void *)(arg2), (uint32_t)(arg3));
	return 0;
}
uint64_t gvec_shl16i_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_shl16i((void *)(arg1), (void *)(arg2), (uint32_t)(arg3));
	return 0;
}
uint64_t gvec_shl32i_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_shl32i((void *)(arg1), (void *)(arg2), (uint32_t)(arg3));
	return 0;
}
uint64_t gvec_shl64i_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_shl64i((void *)(arg1), (void *)(arg2), (uint32_t)(arg3));
	return 0;
}
uint64_t gvec_shr8i_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_shr8i((void *)(arg1), (void *)(arg2), (uint32_t)(arg3));
	return 0;
}
uint64_t gvec_shr16i_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_shr16i((void *)(arg1), (void *)(arg2), (uint32_t)(arg3));
	return 0;
}
uint64_t gvec_shr32i_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_shr32i((void *)(arg1), (void *)(arg2), (uint32_t)(arg3));
	return 0;
}
uint64_t gvec_shr64i_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_shr64i((void *)(arg1), (void *)(arg2), (uint32_t)(arg3));
	return 0;
}
uint64_t gvec_sar8i_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_sar8i((void *)(arg1), (void *)(arg2), (uint32_t)(arg3));
	return 0;
}
uint64_t gvec_sar16i_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_sar16i((void *)(arg1), (void *)(arg2), (uint32_t)(arg3));
	return 0;
}
uint64_t gvec_sar32i_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_sar32i((void *)(arg1), (void *)(arg2), (uint32_t)(arg3));
	return 0;
}
uint64_t gvec_sar64i_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_sar64i((void *)(arg1), (void *)(arg2), (uint32_t)(arg3));
	return 0;
}
uint64_t gvec_eq8_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_eq8((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_eq16_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_eq16((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_eq32_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_eq32((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_eq64_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_eq64((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_ne8_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_ne8((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_ne16_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_ne16((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_ne32_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_ne32((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_ne64_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_ne64((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_lt8_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_lt8((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_lt16_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_lt16((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_lt32_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_lt32((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_lt64_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_lt64((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_le8_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_le8((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_le16_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_le16((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_le32_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_le32((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_le64_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_le64((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_ltu8_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_ltu8((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_ltu16_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_ltu16((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_ltu32_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_ltu32((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_ltu64_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_ltu64((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_leu8_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_leu8((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_leu16_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_leu16((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_leu32_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_leu32((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t gvec_leu64_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	helper_gvec_leu64((void *)(arg1), (void *)(arg2), (void *)(arg3), (uint32_t)(arg4));
	return 0;
}
uint64_t div_i32_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	uint64_t res = helper_div_i32((int32_t)(arg1), (int32_t)(arg2));
	return res;
}
uint64_t rem_i32_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	uint64_t res = helper_rem_i32((int32_t)(arg1), (int32_t)(arg2));
	return res;
}
uint64_t divu_i32_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	uint64_t res = helper_divu_i32((uint32_t)(arg1), (uint32_t)(arg2));
	return res;
}
uint64_t remu_i32_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	uint64_t res = helper_remu_i32((uint32_t)(arg1), (uint32_t)(arg2));
	return res;
}
uint64_t div_i64_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	uint64_t res = helper_div_i64((int64_t)(0 | (((long long)arg1) << 0) | (((long long)arg2) << 32)), (int64_t)(0 | (((long long)arg3) << 0) | (((long long)arg4) << 32)));
	return res;
}
uint64_t rem_i64_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	uint64_t res = helper_rem_i64((int64_t)(0 | (((long long)arg1) << 0) | (((long long)arg2) << 32)), (int64_t)(0 | (((long long)arg3) << 0) | (((long long)arg4) << 32)));
	return res;
}
uint64_t divu_i64_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	uint64_t res = helper_divu_i64((uint64_t)(0 | (((long long)arg1) << 0) | (((long long)arg2) << 32)), (uint64_t)(0 | (((long long)arg3) << 0) | (((long long)arg4) << 32)));
	return res;
}
uint64_t remu_i64_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	uint64_t res = helper_remu_i64((uint64_t)(0 | (((long long)arg1) << 0) | (((long long)arg2) << 32)), (uint64_t)(0 | (((long long)arg3) << 0) | (((long long)arg4) << 32)));
	return res;
}
uint64_t shl_i64_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	uint64_t res = helper_shl_i64((uint64_t)(0 | (((long long)arg1) << 0) | (((long long)arg2) << 32)), (uint64_t)(0 | (((long long)arg3) << 0) | (((long long)arg4) << 32)));
	return res;
}
uint64_t shr_i64_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	uint64_t res = helper_shr_i64((uint64_t)(0 | (((long long)arg1) << 0) | (((long long)arg2) << 32)), (uint64_t)(0 | (((long long)arg3) << 0) | (((long long)arg4) << 32)));
	return res;
}
uint64_t sar_i64_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	uint64_t res = helper_sar_i64((int64_t)(0 | (((long long)arg1) << 0) | (((long long)arg2) << 32)), (int64_t)(0 | (((long long)arg3) << 0) | (((long long)arg4) << 32)));
	return res;
}
uint64_t mulsh_i64_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	uint64_t res = helper_mulsh_i64((int64_t)(0 | (((long long)arg1) << 0) | (((long long)arg2) << 32)), (int64_t)(0 | (((long long)arg3) << 0) | (((long long)arg4) << 32)));
	return res;
}
uint64_t muluh_i64_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	uint64_t res = helper_muluh_i64((uint64_t)(0 | (((long long)arg1) << 0) | (((long long)arg2) << 32)), (uint64_t)(0 | (((long long)arg3) << 0) | (((long long)arg4) << 32)));
	return res;
}
uint64_t clz_i32_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	uint64_t res = helper_clz_i32((uint32_t)(arg1), (uint32_t)(arg2));
	return res;
}
uint64_t ctz_i32_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	uint64_t res = helper_ctz_i32((uint32_t)(arg1), (uint32_t)(arg2));
	return res;
}
uint64_t clz_i64_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	uint64_t res = helper_clz_i64((uint64_t)(0 | (((long long)arg1) << 0) | (((long long)arg2) << 32)), (uint64_t)(0 | (((long long)arg3) << 0) | (((long long)arg4) << 32)));
	return res;
}
uint64_t ctz_i64_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	uint64_t res = helper_ctz_i64((uint64_t)(0 | (((long long)arg1) << 0) | (((long long)arg2) << 32)), (uint64_t)(0 | (((long long)arg3) << 0) | (((long long)arg4) << 32)));
	return res;
}
uint64_t clrsb_i32_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	uint64_t res = helper_clrsb_i32((uint32_t)(arg1));
	return res;
}
uint64_t clrsb_i64_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	uint64_t res = helper_clrsb_i64((uint64_t)(0 | (((long long)arg1) << 0) | (((long long)arg2) << 32)));
	return res;
}
uint64_t ctpop_i32_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	uint64_t res = helper_ctpop_i32((uint32_t)(arg1));
	return res;
}
uint64_t ctpop_i64_wrapper(tcg_target_ulong arg1, tcg_target_ulong arg2, tcg_target_ulong arg3, tcg_target_ulong arg4, tcg_target_ulong arg5, tcg_target_ulong arg6, tcg_target_ulong arg7, tcg_target_ulong arg8, tcg_target_ulong arg9, tcg_target_ulong arg10, tcg_target_ulong arg11, tcg_target_ulong arg12) {
	uint64_t res = helper_ctpop_i64((uint64_t)(0 | (((long long)arg1) << 0) | (((long long)arg2) << 32)));
	return res;
}
#endif
