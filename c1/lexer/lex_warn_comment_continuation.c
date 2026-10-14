void __cdecl lex_warn_comment_continuation(void)

{
  uint uVar1;
  byte bVar2;
  
  do {
    bVar2 = *g_input_ptr;
    g_input_ptr = g_input_ptr + 1;
    if (g_char_class[bVar2] == '\0') {
      bVar2 = lex_next_significant_char(bVar2);
    }
    uVar1 = (uint)bVar2;
  } while (g_char_class[uVar1] == '\x01');
  if (uVar1 == 0x2f) {
    bVar2 = *g_input_ptr;
    g_input_ptr = g_input_ptr + 1;
    if (g_char_class[bVar2] == '\0') {
      bVar2 = lex_next_significant_char(bVar2);
    }
    if (bVar2 == 0x2f) {
      return;
    }
    g_input_ptr = g_input_ptr + -1;
  }
  else if (uVar1 == 10) goto LAB_1062dd52;
  diag_warning(1,10);
LAB_1062dd52:
  g_input_ptr = g_input_ptr + -1;
  return;
}

