int coff_check_incremental_options(void)

{
  byte bVar1;
  uint32_t uVar2;
  
  bVar1 = prevobj_read_byte();
  if ((bVar1 & 1) != g_opt_penter_hook) {
    return 0;
  }
  if ((bool)(bVar1 >> 1 & 1) != (g_opt_cpu_target == 4)) {
    return 0;
  }
  if ((bool)(bVar1 >> 2 & 1) != (g_opt_cpu_target == 5)) {
    return 0;
  }
  if ((bVar1 >> 3 & 1) != g_opt_function_level_linking) {
    return 0;
  }
  if ((bVar1 >> 4 & 1) != g_opt_cbstring) {
    return 0;
  }
  if ((bVar1 >> 5 & 1) != g_opt_bzalign) {
    return 0;
  }
  if ((bVar1 >> 6 & 1) != g_opt_blend) {
    return 0;
  }
  if ((uint)(bVar1 >> 7) != g_opt_line_numbers) {
    return 0;
  }
  uVar2 = prevobj_read_dword();
  return (uint)(uVar2 == g_opt_stack_probe_size);
}

