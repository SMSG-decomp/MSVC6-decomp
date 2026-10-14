void __cdecl pch_check_after_options(void)

{
  if ((g_pch_create != '\0') && (g_pch_written == 0)) {
    pch_check_include_with_Yc();
    return;
  }
  if (g_pch_directive_mode != 0) {
    pch_read_options();
  }
  if (g_browse_file != (char *)0x0) {
    (*g_il_emitter->vtbl->end_module_if)(0);
  }
  g_opt_Binl = 1;
  g_il_emitter = il_emitter_get_default();
  g_compile_flags_c8 = g_compile_flags_c8 | 0x80;
  return;
}

