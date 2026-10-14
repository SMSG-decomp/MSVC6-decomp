void pp_define_directive(void)

{
  byte *length;
  
  length = pp_define_body();
  if (g_ms_extensions != '\0') {
    pp_define_finish(g_define_text_ptr,(uint)length,g_define_formal_count);
    return;
  }
  pp_define_finish(g_macro_text_buffer,
                   (uint)(length + ((int)g_define_text_ptr - (int)g_macro_text_buffer)),
                   g_define_formal_count);
  return;
}

