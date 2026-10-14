void __cdecl
conv_warn_float_truncation_1
          (c1_u8 op,c1_node *node,c1_type *target,uint *out_value,char check_round_trip)

{
  ushort uVar1;
  c1_type *pcVar2;
  int iVar3;
  uint uVar4;
  void *local_3c;
  void *local_38;
  float_const local_34;
  char local_28 [40];
  
  pcVar2 = node->type;
  uVar1 = pcVar2->code;
  if (((uVar1 & 0x2000) == 0) &&
     ((((g_ms_extensions != '\0' || ((uVar1 & 0xfff) != 0x11)) || ((uVar1 & 0x1000) != 0)) ||
      (g_opt_J_unsigned_char == '\0')))) {
    iVar3 = 0;
  }
  else {
    iVar3 = 1;
  }
  int64_to_string((int *)&node->left,local_28,10,iVar3);
  uVar4 = float_const_from_string(local_28,&local_34);
  if (out_value != (uint *)0x0) {
    *out_value = local_34.mantissa_lo;
    out_value[1] = local_34.mantissa_hi;
    out_value[2] = local_34._8_4_;
  }
  if ((check_round_trip != '\0') &&
     ((byte)(&g_type_rank_table)[(byte)target->code & 0xf] <=
      (byte)(&g_type_rank_table)[(byte)pcVar2->code & 0xf])) {
    iVar3 = fold_float_round_to_width
                      (&local_34,(int)(char)(&g_type_rank_table)[(byte)target->code & 0xf]);
    fold_float_to_int64_checked((float10 *)&local_34,(longlong *)&local_3c);
    if (iVar3 != 0 || (char)uVar4 != '\0') {
      diag_warning(2,0x38);
    }
    if ((node->left != local_3c) || (node->right != local_38)) {
      diag_warning(2,0x131,op,pcVar2,target);
    }
  }
  return;
}

