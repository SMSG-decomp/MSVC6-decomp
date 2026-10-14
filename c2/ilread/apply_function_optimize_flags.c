void __fastcall apply_function_optimize_flags(uint32_t options)

{
  g_no_missing_return_warning = options >> 8 & 1;
  g_opt_assume_no_alias = options >> 0x19 & 1;
  g_opt_favor_speed = options >> 0x17 & 1;
  g_force_stack_probe = options >> 0x1f;
  g_opt_float_consistency = options >> 0x12 & 1;
  g_opt_omit_frame_pointer = options >> 0xb & 1;
  g_opt_assume_no_alias_across_calls = options >> 0x18 & 1;
  g_opt_global = options >> 0x15 & 1;
  if (g_opt_dlp != 0) {
    g_opt_omit_frame_pointer = 0;
    g_opt_assume_no_alias = 0;
    g_opt_assume_no_alias_across_calls = 0;
  }
  g_opt_force_schedule = options >> 9 & 1;
  g_opt_vb_float_checks = options >> 10 & 1;
  if (g_opt_runtime_checks != 0) {
    g_opt_omit_frame_pointer = 0;
    g_opt_global = 0;
  }
  if (g_opt_edit_and_continue == 0) {
    if (g_opt_global != 0) {
      g_loop_inversion_enabled = 1;
      goto LAB_10731f4a;
    }
  }
  else {
    g_opt_omit_frame_pointer = 0;
    g_opt_global = 0;
  }
  g_opt_assume_no_alias = 0;
LAB_10731f4a:
  g_assume_no_alias_across_calls = (uint)(g_opt_assume_no_alias_across_calls == 0);
  if (g_opt_assume_no_alias_across_calls != 0) {
    g_opt_assume_no_alias = 1;
  }
  if ((g_opt_no_eh_opt != 0) && ((g_cur_func_sym->fn_flags & 0x100) != 0)) {
    g_opt_global = 0;
    g_loop_inversion_enabled = 0;
  }
  return;
}

