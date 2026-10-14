ushort __cdecl pdb_numeric_leaf(ushort *out,uint lo,int hi)

{
  ushort uVar1;
  
  if ((hi < 1) && (hi < 0)) {
    uVar1 = debug_cv_signed_numeric_leaf(out,lo,hi);
    return uVar1;
  }
  uVar1 = debug_cv_unsigned_numeric_leaf(out,lo,hi);
  return uVar1;
}

