uint32_t __cdecl fpu_store_rounded_int_flags(c2_float_const *k,uint16_t *out)

{
  uint uVar1;
  float10 truncated;
  float10 extraout_ST0;
  int64_t rounded;
  
  truncated = fpu_round_st0(*(float10 *)k);
  uVar1 = fpu_compare_abs((float10)g_fpu_limit_uint32,truncated);
  uVar1 = uVar1 | g_fpu_scratch;
  rounded._0_2_ = (uint16_t)(longlong)ROUND(extraout_ST0);
  rounded._2_2_ = (uint16_t)((ulonglong)(longlong)ROUND(extraout_ST0) >> 0x10);
  *out = (uint16_t)rounded;
  out[1] = rounded._2_2_;
  return uVar1;
}

