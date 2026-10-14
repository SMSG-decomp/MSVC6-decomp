void token_buffers_free(void)

{
  if (g_token_buffers_freed == 0) {
    g_token_buffers_freed = 1;
    VirtualFree(g_macro_arg_buffer,0x500000,0x4000);
    VirtualFree(g_macro_arg_buffer,0,0x8000);
    VirtualFree(g_macro_text_buffer,0x500000,0x4000);
    VirtualFree(g_macro_text_buffer,0,0x8000);
  }
  return;
}

