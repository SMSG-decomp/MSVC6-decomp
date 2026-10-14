uint __fastcall il_symbol_key_2(int sym_keys)

{
  uint uVar1;
  
  if (g_c9il_mode != '\0') {
    return *(uint *)(sym_keys + 0xc) & 0xffffff;
  }
  if ((*(uint *)(sym_keys + 8) & 0xfffffff8) != 0) {
    return *(uint *)(sym_keys + 8) >> 3;
  }
  uVar1 = sym_assign_namemap_key((int *)sym_keys);
  return uVar1;
}

