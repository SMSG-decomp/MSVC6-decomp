int __cdecl fold_float_to_int32_checked(float10 *in,int *out)

{
  int iVar1;
  float10 extraout_ST0;
  
  fpu_round_st0();
  iVar1 = fpu_compare_abs();
  if (iVar1 == 0) {
    *out = (int)ROUND(extraout_ST0);
  }
  return iVar1;
}

