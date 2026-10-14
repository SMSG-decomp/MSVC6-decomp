int __cdecl fpu_store_float(c2_float_const *k,float *out)

{
  int iVar1;
  float10 extraout_ST0;
  
  iVar1 = fpu_compare_abs((float10)g_fpu_limit_float,*(float10 *)k);
  *out = (float)extraout_ST0;
  return iVar1;
}

