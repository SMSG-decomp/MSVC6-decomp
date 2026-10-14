uint __cdecl float_const_from_string(char *text,c1xx_float_const *out)

{
  char *pcVar1;
  char cVar2;
  c1xx_float_const *out_00;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  double local_14;
  _LDOUBLE local_c;
  
  pcVar3 = text;
  _atoldbl(&local_c,text);
  out_00 = out;
  out->mantissa_lo = local_c.ld._0_4_;
  out->mantissa_hi = local_c.ld._4_4_;
  pcVar3 = pcVar3 + 1;
  out->sign_exponent = local_c.ld._8_2_;
  cVar2 = *pcVar3;
  while (cVar2 != '\0') {
    pcVar1 = pcVar3 + 1;
    pcVar3 = pcVar3 + 1;
    cVar2 = *pcVar1;
  }
  if ((pcVar3[-1] & 0xdfU) == 0x4c) {
    iVar4 = fold_float_to_double_checked((byte *)out,&local_14);
    if (iVar4 == 0) {
      uVar5 = float_const_set_double(&local_14,out_00);
      out_00->size = 8;
      return uVar5 & 0xffffff00;
    }
    out_00->size = 8;
    return CONCAT31((int3)((uint)iVar4 >> 8),1);
  }
  if ((pcVar3[-1] & 0xdfU) == 0x46) {
    out->size = 4;
    iVar4 = fpu_store_float_if_in_range((float10 *)out,(float *)&text);
    if (iVar4 == 0) {
      uVar5 = fpu_store_float_constant((float *)&text,out_00);
      return uVar5 & 0xffffff00;
    }
    return CONCAT31((int3)((uint)iVar4 >> 8),1);
  }
  out->size = 8;
  iVar4 = fold_float_to_double_checked((byte *)out,&local_14);
  if (iVar4 != 0) {
    return CONCAT31((int3)((uint)iVar4 >> 8),1);
  }
  uVar5 = float_const_set_double(&local_14,out_00);
  return uVar5 & 0xffffff00;
}

