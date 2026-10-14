uint __cdecl il_symbol_key(byte *sym)

{
  uint uVar1;
  
  if (g_c9il_mode != '\0') {
    return *(uint *)(sym + 0x1c) & 0xffffff;
  }
  if ((*(uint *)(sym + 0x18) & 0xfffffff8) == 0) {
    uVar1 = il_symbol_key_assign((c1_symbol *)sym);
    return uVar1;
  }
  return *(uint *)(sym + 0x18) >> 3;
}

