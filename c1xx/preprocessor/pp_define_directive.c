void pp_define_directive(void)

{
  uint length;
  
  length = pp_define_body();
  if (g_ms_extensions != '\0') {
    pp_define_finish(g_define_text_ptr,length,g_define_formal_count);
    return;
  }
  pp_define_finish(g_macro_text_buffer,
                   (uint)(g_define_text_ptr + (length - (int)g_macro_text_buffer)),
                   g_define_formal_count);
  return;
}

