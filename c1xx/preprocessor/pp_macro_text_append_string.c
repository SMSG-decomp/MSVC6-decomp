void __cdecl pp_macro_text_append_string(uchar *text)

{
  uchar uVar1;
  
  if (text != (uchar *)0x0) {
    uVar1 = *text;
    while (uVar1 != '\0') {
      if (g_macro_text_buffer_limit <= g_macro_text_cursor) {
        pp_define_check_size
                  ((uint)g_macro_text_cursor,(int)g_macro_text_buffer,
                   (int *)&g_macro_text_buffer_limit);
      }
      *g_macro_text_cursor = *text;
      g_macro_text_cursor = g_macro_text_cursor + 1;
      text = text + 1;
      uVar1 = *text;
    }
  }
  return;
}

