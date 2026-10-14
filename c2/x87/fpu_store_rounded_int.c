int __cdecl fpu_store_rounded_int(c2_float_const *k,int *out)

{
  int iVar1;
  float10 truncated;
  float10 extraout_ST0;
  
  truncated = fpu_round_st0(*(float10 *)k);
  iVar1 = fpu_compare_abs((float10)g_fpu_limit_int32,truncated);
  *out = (int)ROUND(extraout_ST0);
  return iVar1;
}

