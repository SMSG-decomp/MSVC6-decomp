c1_node * __cdecl fold_float_constant_conversion(c1_u8 op,c1_type *type,c1_node *node)

{
  ushort uVar1;
  c1_type *pcVar2;
  c1_type type_copy;
  float_const value;
  float_const value_00;
  byte bVar3;
  c1_type *pcVar4;
  c1_node *pcVar5;
  int iVar6;
  void *pvVar7;
  ulonglong uVar8;
  undefined1 in_stack_ffffffbc;
  undefined1 in_stack_ffffffbd;
  c1_u16 in_stack_ffffffbe;
  c1_type *in_stack_ffffffc0;
  c1_type_x08 in_stack_ffffffc4;
  c1_u32 in_stack_ffffffc8;
  uint in_stack_ffffffcc;
  uint in_stack_ffffffd0;
  ushort in_stack_ffffffd4;
  ushort in_stack_ffffffd6;
  
  pcVar2 = g_type_int;
  pcVar4 = node->type;
  if (((pcVar4->code & 0x100) != 0) && ((type->code & 0x100) == 0)) {
    node->type = g_type_int;
    pcVar4 = pcVar2;
  }
  pcVar2 = node->type;
  bVar3 = (byte)pcVar2->code;
  if (((bVar3 >> 4 & 1) == 0) && (-1 < (char)bVar3)) {
    if (((bVar3 >> 5 & 1) != 0) && (((byte)type->code >> 4 & 1) != 0)) {
      iVar6 = fold_float_to_int64_checked(node->left,(longlong *)&stack0xffffffbc);
      if (iVar6 != 0) {
        diag_warning(2,0x38);
      }
      node->left = (void *)CONCAT22(in_stack_ffffffbe,CONCAT11(in_stack_ffffffbd,in_stack_ffffffbc))
      ;
      node->op = 'e';
      node->right = in_stack_ffffffc0;
    }
  }
  else {
    bVar3 = (byte)type->code;
    if (((bVar3 >> 4 & 1) == 0) && (-1 < (char)bVar3)) {
      value.mantissa_hi = in_stack_ffffffd0;
      value.mantissa_lo = in_stack_ffffffcc;
      value.sign_exponent = in_stack_ffffffd4;
      value.size = in_stack_ffffffd6;
      pcVar5 = fold_float_overflow_check
                         (bVar3,CONCAT22((short)((uint)pcVar4 >> 0x10),pcVar2->code),node,type,value
                         );
      return pcVar5;
    }
    uVar8 = conv_cast_constant(op,(int)node,type);
    node->left = (void *)(int)uVar8;
    node->right = (void *)(int)(uVar8 >> 0x20);
    if ((type->code & 0x2000) == 0) {
      if (g_ms_extensions == '\0') {
        type_copy.code._1_1_ = in_stack_ffffffbd;
        type_copy.code._0_1_ = in_stack_ffffffbc;
        type_copy.flags = in_stack_ffffffbe;
        type_copy.base = in_stack_ffffffc0;
        type_copy.extra.sym = in_stack_ffffffc4.sym;
        type_copy.debug_index = in_stack_ffffffc8;
        value_00.mantissa_hi = in_stack_ffffffd0;
        value_00.mantissa_lo = in_stack_ffffffcc;
        value_00.sign_exponent = in_stack_ffffffd4;
        value_00.size = in_stack_ffffffd6;
        pcVar5 = fold_float_constant_conversion_fragment
                           ('\0',CONCAT22((short)(uVar8 >> 0x10),type->code),g_opt_J_unsigned_char,
                            pcVar2,node,type,type_copy,value_00);
        return pcVar5;
      }
    }
    else {
      uVar1 = pcVar2->code;
      if (((uVar1 & 0x2000) == 0) &&
         ((((g_ms_extensions != '\0' || ((uVar1 & 0xfff) != 0x11)) || ((uVar1 & 0x1000) != 0)) ||
          (g_opt_J_unsigned_char == '\0')))) {
        pcVar4 = node->type;
        uVar1 = pcVar4->code;
        if (((uVar1 & 0x2000) == 0) &&
           (((g_ms_extensions != '\0' || ((uVar1 & 0xfff) != 0x11)) ||
            (((uVar1 & 0x1000) != 0 || (g_opt_J_unsigned_char == '\0')))))) {
          pcVar4 = type_intern((c1_type *)&stack0xffffffbc);
        }
        node->type = pcVar4;
      }
    }
  }
  if (((byte)type->code >> 5 & 1) != 0) {
    if (g_opt_Op != '\0') {
      iVar6 = type_size_scalar(type);
      fold_float_round_to_width((float_const *)&stack0xffffffcc,iVar6);
    }
    type_size_scalar(type);
    node->op = 'e';
    pvVar7 = record3_new_from((int *)&stack0xffffffcc,g_expr_arena_index);
    node->left = pvVar7;
  }
  node->type = type;
  return node;
}

