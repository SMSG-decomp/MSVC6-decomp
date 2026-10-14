void token_buffers_init(void)

{
  g_macro_arg_buffer = virtual_reserve_commit_or_fatal(0x500000,0x4000);
  g_macro_arg_buffer_limit = (int)g_macro_arg_buffer + 0x3ffb;
  g_macro_text_buffer = virtual_reserve_commit_or_fatal(0x500000,0x4000);
  g_macro_text_buffer_limit = g_macro_text_buffer + 0x3ffb;
  return;
}

