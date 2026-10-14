uint __fastcall sym_assign_namemap_key(int *entry)

{
  uint uVar1;
  
  uVar1 = sym_namemap_key(*(uint *)(*entry + 4));
  entry[2] = entry[2] & 7U | uVar1 * 8;
  return uVar1 & 0x1fffffff;
}

