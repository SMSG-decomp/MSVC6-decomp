byte lex_getc(void)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  
  pbVar3 = g_input_ptr + 1;
  if (*g_input_ptr != 0) {
    bVar1 = *g_input_ptr;
    g_input_ptr = pbVar3;
    if (g_char_class[bVar1] == '\0') {
      bVar1 = lex_next_significant_char(bVar1);
    }
    return bVar1;
  }
  g_input_ptr = pbVar3;
  iVar2 = lex_buffer_refill();
  if (iVar2 == 0x20) {
    g_input_ptr = g_input_ptr + 1;
    return 0;
  }
  bVar1 = *g_input_ptr;
  g_input_ptr = g_input_ptr + 1;
  return bVar1;
}

