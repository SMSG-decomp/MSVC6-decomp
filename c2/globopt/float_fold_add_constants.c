int __cdecl float_fold_add_constants(c2_float_const *a,c2_float_const *b,c2_float_const *out)

{
  float10 fVar1;
  float10 fVar2;
  ushort uVar3;
  int iVar4;
  
  fVar1 = *(float10 *)a;
  fVar2 = *(float10 *)b;
  uVar3 = a->size_tag | b->size_tag;
  if ((uVar3 & 2) == 0) {
    if ((uVar3 & 8) == 0) {
      out->size_tag = 4;
    }
    else {
      out->size_tag = 8;
    }
  }
  else {
    out->size_tag = 10;
  }
  iVar4 = fpu_store_constant_rounded(out,fVar2 + fVar1);
  return iVar4;
}

