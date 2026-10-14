int __cdecl float_fold_multiply_constants(float_const *a,float_const *b,float_const *out)

{
  float10 fVar1;
  float10 fVar2;
  ushort uVar3;
  int iVar4;
  
  fVar1 = *(float10 *)a;
  fVar2 = *(float10 *)b;
  uVar3 = a->size | b->size;
  if ((uVar3 & 2) == 0) {
    if ((uVar3 & 8) == 0) {
      out->size = 4;
    }
    else {
      out->size = 8;
    }
  }
  else {
    out->size = 10;
  }
  iVar4 = fpu_store_constant_rounded(fVar2 * fVar1,(float10 *)out);
  return iVar4;
}

