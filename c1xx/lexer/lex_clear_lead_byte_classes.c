void __cdecl lex_clear_lead_byte_classes(void)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if (g_char_class[iVar1] == '#') {
      g_char_flags[iVar1] = g_char_flags[iVar1] & 0x7f;
      g_char_class[iVar1] = '!';
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x100);
  return;
}

