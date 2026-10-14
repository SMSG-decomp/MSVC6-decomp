void __cdecl func_body_begin_fragment_3(void)

{
  int handle;
  void *return_address;
  
  if (g_pending_function_word == 1) {
    diag_warning(1,0x1a);
  }
  if (g_function_context_word == 1) {
    g_function_context_word = 5;
  }
  if ((g_function_context_word == 3) || (g_function_context_word == 5)) {
    if (g_opt_Zg != '\0') {
      handle = format_buffer_acquire();
      format_buffer_free(handle);
      zg_write_function_prototype(g_current_function,g_pp_output_stream);
      format_buffer_leave();
    }
  }
  else if (g_opt_Zg != '\0') {
    func_body_begin_fragment_2(g_current_function->type);
    return;
  }
  if (((g_opt_Zi != '\0') && (g_opt_Zg == '\0')) && (g_ilstore_status != 4)) {
    il_emit_pragma_or_segment_record(0x11);
  }
  g_compile_flags_c4 = g_compile_flags_c4 | 0x20000;
  return;
}

