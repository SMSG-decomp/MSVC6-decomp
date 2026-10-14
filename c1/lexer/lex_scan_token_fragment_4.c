c1_token * __cdecl lex_scan_token_fragment_4(void)

{
  byte bVar1;
  uint uVar2;
  
code_r0x10627bb6:
  uVar2 = lex_buffer_refill();
  if ((uVar2 & 0xffffff8f) != 0) {
    bVar1 = *g_input_ptr;
    g_input_ptr = g_input_ptr + 1;
    switch(g_char_class[bVar1]) {
    case '\0':
      goto code_r0x10627bb6;
    default:
switchD_1060356a_caseD_1:
      g_input_ptr = g_input_ptr + -1;
      return g_token_minus;
    case '\r':
      return g_token_minus_assign;
    case '\x12':
      return g_token_minus_minus;
    case '\x14':
      return g_token_arrow;
    }
  }
  if ((uVar2 & 0x20) != 0) {
    g_input_ptr = g_input_ptr + 1;
  }
  goto switchD_1060356a_caseD_1;
}

