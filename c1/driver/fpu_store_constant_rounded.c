int __cdecl fpu_store_constant_rounded(float10 value,float10 *out)

{
  int extraout_EAX;
  int iVar1;
  uint uVar2;
  int extraout_EAX_00;
  int extraout_EAX_01;
  float10 fVar3;
  float10 value_00;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  
  if (*(short *)((int)out + 10) == 4) {
    iVar1 = fpu_compare_abs();
    uVar2 = opt_float_consistency_enabled();
    fVar3 = extraout_ST0_00;
    if (uVar2 != 0) {
      g_fpu_scratch = (uint32_t)(float)extraout_ST0_00;
      fpu_store_st0_tbyte_esi((float10)(float)g_fpu_scratch,out);
      return extraout_EAX_01;
    }
  }
  else {
    if (*(short *)((int)out + 10) == 10) {
      fpu_compare_abs();
      fpu_store_st0_tbyte_esi(value_00,out);
      return extraout_EAX;
    }
    iVar1 = fpu_compare_abs();
    uVar2 = opt_float_consistency_enabled();
    fVar3 = extraout_ST0;
    if (uVar2 != 0) {
      _g_fpu_scratch = (double)extraout_ST0;
      fpu_store_st0_tbyte_esi((float10)_g_fpu_scratch,out);
      return extraout_EAX_00;
    }
  }
  *out = fVar3;
  return iVar1;
}

