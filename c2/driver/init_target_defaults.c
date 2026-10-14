void init_target_defaults(void)

{
  g_callee_saved_mask = 0x1d0;
  g_call_clobber_reg_mask = 0xe;
  if (3 < g_opt_cpu_target) {
    g_code_section_align = 0x10;
  }
  if (g_opt_cpu_target < 5) {
    g_opt_cpu_target = 5;
  }
  return;
}

