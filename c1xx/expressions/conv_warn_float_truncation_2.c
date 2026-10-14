void __cdecl conv_warn_float_truncation_2(byte op,c1_node *node,c1_type *target)

{
  int iVar1;
  uint value_0;
  uint value_1;
  uint value_2;
  uint *value_src;
  
  if ((byte)(&g_type_rank_table)[(byte)target->code & 0xf] <
      (byte)(&g_type_rank_table)[(byte)node->type->code & 0xf]) {
    value_src = node->left;
    value_0 = *value_src;
    value_1 = value_src[1];
    value_2 = value_src[2];
    iVar1 = fold_float_round_to_width
                      ((int)&value_0,(int)(char)(&g_type_rank_table)[(byte)target->code & 0xf]);
    if (iVar1 != 0) {
      diag_warning(2,0x38);
      return;
    }
    iVar1 = float_const_compare_mask(6,&value_0,node->left);
    if (iVar1 != 0) {
      diag_warning(2,0x131,op,node->type,target);
    }
  }
  return;
}

