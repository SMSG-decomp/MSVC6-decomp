int __cdecl fold_float_store_result_3(float_const *a,float_const *b,float_const *out)

{
  ushort uVar1;
  int iVar2;
  float10 value;
  
  if (_adjust_fdiv == 0) {
    value = *(float10 *)a / *(float10 *)b;
  }
  else {
    value = (float10)_adj_fdiv_r();
  }
  uVar1 = a->size | b->size;
  if ((uVar1 & 2) == 0) {
    if ((uVar1 & 8) == 0) {
      out->size = 4;
    }
    else {
      out->size = 8;
    }
  }
  else {
    out->size = 10;
  }
  iVar2 = fpu_store_constant_rounded(value,(float10 *)out);
  return iVar2;
}

