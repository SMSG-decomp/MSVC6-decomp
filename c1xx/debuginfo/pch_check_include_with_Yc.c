void __cdecl pch_check_include_with_Yc(void)

{
  if (g_create_pch_header_name == (char *)0x0) {
    pch_set_name(g_opt_source_file);
    pch_write();
  }
  else if ((uint)(1 < g_warnings_as_errors) + g_error_count == 0) {
    diag_error(0x359,g_create_pch_header_name);
  }
  if (g_browse_file != (char *)0x0) {
    (*g_il_emitter->vtbl->end_module_if)(0);
  }
  g_opt_Binl = 1;
  g_il_emitter = il_emitter_get_default();
  g_compile_flags_c8 = g_compile_flags_c8 | 0x80;
  return;
}

