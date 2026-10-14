byte lex_skip_mbcs_trail_byte(void)

{
  byte bVar1;
  
  g_compile_flags_c8 = g_compile_flags_c8 | 0x1000;
  bVar1 = *g_input_ptr;
  while ((g_input_ptr = g_input_ptr + 1, bVar1 == 0 && (g_macro_rescan_level < 1))) {
    lex_buffer_refill();
    bVar1 = *g_input_ptr;
  }
  g_compile_flags_c8 = g_compile_flags_c8 & 0xffffefff;
  return bVar1;
}

