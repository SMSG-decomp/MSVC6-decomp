void __cdecl lex_mark_mbcs_lead_bytes(void)

{
  code *pcVar1;
  uint uVar2;
  
  _setmbcp(-4);
  pcVar1 = _mbctype_exref;
  uVar2 = 0;
  do {
    if (((byte)pcVar1[(uVar2 & 0xff) + 1] & 4) != 0) {
      g_char_flags[uVar2] = g_char_flags[uVar2] | 0x80;
      g_char_class[uVar2] = '#';
    }
    uVar2 = uVar2 + 1;
  } while ((int)uVar2 < 0x100);
  return;
}

