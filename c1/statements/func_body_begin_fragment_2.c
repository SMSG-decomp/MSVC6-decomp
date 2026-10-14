void __cdecl func_body_begin_fragment_2(c1_type *type)

{
  int handle;
  
  handle = format_buffer_acquire();
  format_buffer_free(handle);
  zg_write_function_prototype(g_current_function,g_pp_output_stream);
  format_buffer_leave();
  g_current_function->type = type;
  if (((g_opt_Zi != '\0') && (g_opt_Zg == '\0')) && (g_ilstore_status != 4)) {
    il_emit_pragma_or_segment_record(0x11);
  }
  g_compile_flags_c4 = g_compile_flags_c4 | 0x20000;
  return;
}

