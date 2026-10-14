int __cdecl fpu_store_double(c2_float_const *k,double *out)

{
  int iVar1;
  float10 extraout_ST0;
  
  iVar1 = fpu_compare_abs((float10)g_fpu_limit_double,*(float10 *)k);
  *out = (double)extraout_ST0;
  return iVar1;
}

