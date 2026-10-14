void __cdecl lex_mark_mbcs_lead_bytes(void)

{
  uint uVar1;
  code *mbctype;
  
  _setmbcp(-4);
  mbctype = _mbctype_exref;
  uVar1 = 0;
  do {
    if (((byte)mbctype[(uVar1 & 0xff) + 1] & 4) != 0) {
      g_char_flags[uVar1] = g_char_flags[uVar1] | 0x80;
      g_char_class[uVar1] = '#';
    }
    uVar1 = uVar1 + 1;
  } while ((int)uVar1 < 0x100);
  return;
}

