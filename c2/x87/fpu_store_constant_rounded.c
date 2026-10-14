int fpu_store_constant_rounded(c2_float_const *k,float10 value)

{
  int iVar1;
  int extraout_EAX;
  int extraout_EAX_00;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  
  iVar1 = 0;
  if (k->size_tag == 4) {
    iVar1 = fpu_compare_abs((float10)g_fpu_limit_float,value);
    value = extraout_ST0_00;
    if (g_opt_float_consistency != 0) {
      g_fpu_scratch = (uint32_t)(float)extraout_ST0_00;
      fpu_store_st0_tbyte_esi(k,(float10)(float)g_fpu_scratch);
      return extraout_EAX_00;
    }
  }
  else if (k->size_tag != 10) {
    iVar1 = fpu_compare_abs((float10)g_fpu_limit_double,value);
    value = extraout_ST0;
    if (g_opt_float_consistency != 0) {
      _g_fpu_scratch = (double)extraout_ST0;
      fpu_store_st0_tbyte_esi(k,(float10)_g_fpu_scratch);
      return extraout_EAX;
    }
  }
  *(float10 *)k = value;
  return iVar1;
}

