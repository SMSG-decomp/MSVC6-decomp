void __cdecl
conv_warn_float_truncation_1(uint op,c1_node *e,c1_type *target,c1xx_float_const *out,char warn)

{
  ushort uVar1;
  c1_type *pcVar2;
  int iVar3;
  uint uVar4;
  void *local_3c;
  void *local_38;
  c1xx_float_const local_34;
  char local_28 [40];
  
  pcVar2 = e->type;
  uVar1 = pcVar2->code;
  if (((uVar1 & 0x2000) == 0) &&
     ((((uVar1 & 0xfff) != 0x11 || ((uVar1 & 0x1000) != 0)) || (g_opt_J_unsigned_char == '\0')))) {
    iVar3 = 0;
  }
  else {
    iVar3 = 1;
  }
  int64_to_string((int *)&e->left,local_28,10,iVar3);
  uVar4 = float_const_from_string(local_28,&local_34);
  if (out != (c1xx_float_const *)0x0) {
    out->mantissa_lo = local_34.mantissa_lo;
    out->mantissa_hi = local_34.mantissa_hi;
    out->sign_exponent = local_34.sign_exponent;
    out->size = local_34.size;
  }
  if ((warn != '\0') &&
     ((byte)(&g_type_rank_table)[(byte)target->code & 0xf] <=
      (byte)(&g_type_rank_table)[(byte)pcVar2->code & 0xf])) {
    iVar3 = fold_float_round_to_width
                      ((int)&local_34,(int)(char)(&g_type_rank_table)[(byte)target->code & 0xf]);
    fold_float_to_int64_checked(&local_34,(c1_u32 *)&local_3c);
    if (iVar3 != 0 || (char)uVar4 != '\0') {
      diag_warning(2,0x38);
    }
    if ((e->left != local_3c) || (e->right != local_38)) {
      diag_warning(2,0x131,op & 0xff,pcVar2,target);
    }
  }
  return;
}

