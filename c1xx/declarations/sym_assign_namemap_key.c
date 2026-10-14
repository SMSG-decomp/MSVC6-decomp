uint __fastcall sym_assign_namemap_key(int *file_rec)

{
  uint uVar1;
  
  uVar1 = sym_namemap_key(*(uint *)(*file_rec + 4));
  file_rec[2] = file_rec[2] & 7U | uVar1 * 8;
  return uVar1 & 0x1fffffff;
}

