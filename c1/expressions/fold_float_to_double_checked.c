int __cdecl fold_float_to_double_checked(float10 *in,double *out)

{
  int iVar1;
  float10 extraout_ST0;
  
  iVar1 = fpu_compare_abs();
  if (iVar1 == 0) {
    *out = (double)extraout_ST0;
  }
  return iVar1;
}

