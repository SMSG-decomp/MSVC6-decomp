int __cdecl fold_float_to_int32_checked(float10 *value,int *out)

{
  int iVar1;
  float10 value_00;
  float10 extraout_ST0;
  
  value_00 = fpu_round_st0(*value);
  iVar1 = fpu_compare_abs(g_fpu_int32_limit,value_00);
  if (iVar1 == 0) {
    *out = (int)ROUND(extraout_ST0);
  }
  return iVar1;
}

