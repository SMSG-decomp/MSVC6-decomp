int __cdecl fold_float_to_double_checked(byte *value,double *out)

{
  int iVar1;
  float10 extraout_ST0;
  
  iVar1 = fpu_compare_abs(g_fpu_double_limit,*(float10 *)value);
  if (iVar1 == 0) {
    *out = (double)extraout_ST0;
  }
  return iVar1;
}

