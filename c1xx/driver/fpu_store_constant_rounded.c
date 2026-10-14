int __cdecl fpu_store_constant_rounded(float10 value,float10 *out)

{
  double dVar1;
  int iVar2;
  uint uVar3;
  int extraout_EAX;
  int extraout_EAX_00;
  int extraout_EAX_01;
  float10 extraout_ST0;
  float10 fVar4;
  float10 value_00;
  float10 extraout_ST0_00;
  
  if (*(short *)((int)out + 10) == 4) {
    iVar2 = fpu_compare_abs((float10)CONCAT64(g_fpu_float_limit._4_6_,g_fpu_float_limit._0_4_),value
                           );
    uVar3 = opt_float_consistency_enabled();
    fVar4 = extraout_ST0_00;
    if (uVar3 != 0) {
      g_fpu_scratch = (float)extraout_ST0_00;
      fpu_store_st0_tbyte_esi((float10)g_fpu_scratch,out);
      return extraout_EAX_01;
    }
  }
  else {
    if (*(short *)((int)out + 10) == 10) {
      fpu_compare_abs(g_fpu_long_double_limit,value);
      fpu_store_st0_tbyte_esi(value_00,out);
      return extraout_EAX;
    }
    iVar2 = fpu_compare_abs(g_fpu_double_limit,value);
    uVar3 = opt_float_consistency_enabled();
    fVar4 = extraout_ST0;
    if (uVar3 != 0) {
      dVar1 = (double)extraout_ST0;
      g_fpu_scratch = SUB84(dVar1,0);
      g_fpu_float_limit._0_4_ = (undefined4)((ulonglong)dVar1 >> 0x20);
      fpu_store_st0_tbyte_esi((float10)dVar1,out);
      return extraout_EAX_00;
    }
  }
  *out = fVar4;
  return iVar2;
}

