void __cdecl conv_warn_float_truncation_2(byte op,c1_node *node,c1_type *target)

{
  uint *puVar1;
  int iVar2;
  float_const local_c;
  
  if ((byte)(&g_type_rank_table)[(byte)target->code & 0xf] <
      (byte)(&g_type_rank_table)[(byte)node->type->code & 0xf]) {
    puVar1 = node->left;
    local_c.mantissa_lo = *puVar1;
    local_c.mantissa_hi = puVar1[1];
    local_c._8_4_ = puVar1[2];
    iVar2 = fold_float_round_to_width
                      (&local_c,(int)(char)(&g_type_rank_table)[(byte)target->code & 0xf]);
    if (iVar2 != 0) {
      diag_warning(2,0x38);
      return;
    }
    iVar2 = float_const_compare_mask(6,(float10 *)&local_c,node->left);
    if (iVar2 != 0) {
      diag_warning(2,0x131,op,node->type,target);
    }
  }
  return;
}

