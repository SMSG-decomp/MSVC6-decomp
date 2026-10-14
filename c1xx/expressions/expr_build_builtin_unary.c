c1_node * __cdecl expr_build_builtin_unary(uint op,c1_node *operand)

{
  c1_u8 cVar1;
  c1_u16 cVar2;
  char *pcVar3;
  byte bVar4;
  char cVar5;
  ushort uVar6;
  c1_node *pcVar7;
  int iVar8;
  uint uVar9;
  c1_symbol *pcVar10;
  c1_symbol *pcVar11;
  c1_type *pcVar12;
  c1_node *pcVar13;
  void *pvVar14;
  ushort uVar15;
  c1_u8 op_00;
  uint hi;
  longlong lVar16;
  ulonglong uVar17;
  c1_type local_10;
  
  if (operand == (c1_node *)0x0) {
    return (c1_node *)0x0;
  }
  cVar2 = operand->type->code;
  op_00 = (c1_u8)op;
  if ((cVar2 == 0x80c) || (cVar2 == 0x80e)) {
    if (op_00 == 'v') {
      return operand;
    }
    cVar1 = operand->op;
    if (cVar1 == '1') {
      diag_error(0xab,op & 0xff,operand->type);
      return operand;
    }
    if ((((cVar1 == 'P') || (cVar1 == 'S')) || (cVar1 == 0x92)) || (cVar1 == 0x93)) {
      if (((op_00 != '1') || (pcVar3 = operand->right, pcVar3 == (char *)0x0)) ||
         ((*pcVar3 != '\x06' ||
          (pcVar11 = *(c1_symbol **)(pcVar3 + 0x10), pcVar11 == (c1_symbol *)0x0)))) {
LAB_10480a37:
        if ((operand->op != 0x92) && (operand->op != 0x93)) {
          diag_error(0x114,0x4c,op & 0xff);
          return (c1_node *)0x0;
        }
        diag_error(0x12a,op & 0xff);
        return (c1_node *)0x0;
      }
      if ((pcVar11->kind & 0x1f) == 0x12) {
        pcVar11 = *(c1_symbol **)(*(int *)pcVar11->type + 8);
      }
      cVar5 = ovl_names_single_function(pcVar11,'\x01');
      if ((cVar5 == '\0') ||
         (pcVar11 = sym_first_function_of_overload_set(pcVar11,'\x01'), (pcVar11->storage & 7) != 3)
         ) goto LAB_10480a37;
      if (((byte)g_compile_flags_c8 & 4) != 0) {
        return operand;
      }
      *(c1_symbol **)((int)operand->right + 0x10) = pcVar11;
      *(c1_type **)((int)operand->right + 4) = pcVar11->type;
      operand->type = pcVar11->type;
    }
    else {
      pcVar11 = operand->left;
      pcVar10 = pcVar11;
      if ((pcVar11->kind & 0x1f) == 0x12) {
        pcVar10 = *(c1_symbol **)(*(int *)pcVar11->type + 8);
      }
      bVar4 = pcVar10->kind & 0x1f;
      if (bVar4 == 3) {
        if (op_00 == '1') {
          pcVar7 = expr_address_of_member(pcVar11);
          return pcVar7;
        }
        diag_error(0xab,op & 0xff,pcVar10->type);
        return (c1_node *)0x0;
      }
      if (bVar4 == 2) {
        diag_error(0x87,pcVar10);
        return (c1_node *)0x0;
      }
      if (((pcVar10->flags1 & 0x10) == 0x10) || ((pcVar10->flags1 & 0x20) == 0x20)) {
        diag_error(0x115,pcVar10);
        return (c1_node *)0x0;
      }
      cVar5 = ovl_names_single_function(pcVar10,'\x01');
      if (cVar5 == '\0') {
        if (op_00 == '1') {
          local_10.base = (c1_type *)0x0;
          local_10.debug_index = 0;
          local_10.code = 0x80c;
          local_10.flags = 0;
          local_10.extra.cls = (c1_symbol *)0x0;
          pcVar12 = type_intern(&local_10);
          pcVar7 = tree_new_unary('1',pcVar12,operand);
          return pcVar7;
        }
        diag_error(0xf4,pcVar10);
        return (c1_node *)0x0;
      }
      bVar4 = pcVar10->kind & 0x1f;
      if (((bVar4 == 0x11) || (bVar4 == 8)) && (op_00 == '1')) {
        pcVar10 = sym_first_function_of_overload_set(pcVar10,'\x01');
        *(c1_symbol **)(*(int *)pcVar11->type + 8) = pcVar10;
        pcVar7 = expr_address_of_member(pcVar11);
        return pcVar7;
      }
      pcVar11 = sym_first_function_of_overload_set(pcVar10,'\x01');
      operand->left = pcVar11;
      operand->type = pcVar11->type;
      operand->type = pcVar11->type;
    }
  }
  pcVar12 = operand->type;
  pcVar7 = tree_new_unary(op_00,pcVar12,operand);
  iVar8 = expr_check_illegal_for_type(op_00,1,(c1_node *)0x0,operand);
  if (iVar8 == 0) {
    return (c1_node *)0x0;
  }
  uVar9 = op & 0xff;
  switch(uVar9) {
  case 0x31:
    pcVar7 = expr_build_address_of(operand,0xc);
    return pcVar7;
  default:
    pcVar7 = type_fold_integer_constant_fragment
                       (pcVar12,local_10._0_4_,(int)local_10.base,operand,pcVar7);
    return pcVar7;
  case 0x3c:
    uVar6 = pcVar12->code & 0x8f;
    if (((uVar6 != 0x83) && (uVar6 != 0x82)) &&
       ((uVar6 != 0x86 && ((((pcVar12->code & 0x130) == 0 && (uVar6 != 0x8a)) && (uVar6 != 0x8e)))))
       ) {
      diag_error(0xab,0x3c,pcVar12);
      return pcVar7;
    }
    pcVar7->type = g_type_bool;
    pcVar7->flags = pcVar7->flags | 1;
    pcVar13 = fold_static_const_member(operand);
    if ((pcVar13->kind & 7) != 3) {
      return pcVar7;
    }
    uVar6 = pcVar12->code;
    if (((uVar6 & 0x110) == 0) &&
       ((-1 < (char)uVar6 || (((uVar6 & 0x8f) != 0x86 && ((uVar6 & 0x8f) != 0x82)))))) {
      pcVar7 = tree_new_int_constant(0);
      pcVar7 = expr_build_builtin_binary(';',pcVar13,pcVar7);
      pcVar7->flags = pcVar7->flags | 1;
      return pcVar7;
    }
    if (pcVar13->left == (void *)0x0 && pcVar13->right == (void *)0x0) {
      pcVar7 = type_fold_integer_constant_fragment(pcVar13->type,1,0,pcVar13,pcVar7);
      return pcVar7;
    }
    pcVar7 = type_fold_integer_constant_fragment(pcVar13->type,0,0,pcVar13,pcVar7);
    return pcVar7;
  case 0x3d:
  case 0xa0:
    cVar5 = expr_check_operand_type_illegal(op_00,pcVar12);
    if (cVar5 != '\0') {
      return pcVar7->left;
    }
    uVar6 = pcVar12->code;
    uVar15 = uVar6 & 0x8f;
    if ((uVar15 == 0x86) || ((bVar4 = (byte)uVar6, (char)bVar4 < '\0' && (uVar15 == 0x84)))) {
      if (uVar6 == 0x4086) {
        return operand;
      }
      pcVar12 = type_member_pointer_to_3(pcVar12,1);
      operand->type = pcVar12;
      return operand;
    }
    if (((char)bVar4 < '\0') && ((uVar15 == 0x82 || (((char)bVar4 < '\0' && (uVar15 == 0x80)))))) {
      pcVar12 = expr_check_based_void_pointer(pcVar12);
      pcVar7->type = pcVar12;
      bVar4 = (byte)pcVar12->code;
      if ((char)bVar4 < '\0') {
        if ((*(byte *)(-(uint)((pcVar12->code & 0x80) != 0) & (uint)pcVar12) & 0x8f) == 0x83) {
          operand->kind = operand->kind | 0x20;
          pcVar12 = pcVar7->type;
          pcVar12 = type_intern_from_parts
                              (pcVar12,0x83,
                               *(ushort *)
                                ((-(uint)((pcVar12->code & 0x80) != 0) & (uint)pcVar12) + 2) & 0x3e0
                               | *(byte *)(((uint)operand->type &
                                           -(uint)((operand->type->code & 0x80) != 0)) + 2) & 0x1f,
                               (c1_u32 *)
                               ((-(uint)((pcVar12->code & 0x80) != 0) & (uint)pcVar12) + 8));
          operand->type = pcVar12;
          return operand;
        }
        if ((pcVar12->code & 0x8f) != 0x82) {
          return pcVar7;
        }
        uVar6 = pcVar12->flags & 0x18;
        if ((uVar6 != 0x18) && (uVar6 != 8)) {
          return pcVar7;
        }
        pcVar7 = expr_based_pointer_fixup(pcVar7);
        return pcVar7;
      }
      if ((bVar4 >> 6 & 1) == 0) goto LAB_104117b3;
    }
    else {
      if (uVar15 == 0x83) {
        pcVar7 = tree_new_int_constant(0);
        pcVar7 = expr_build_builtin_binary('A',operand,pcVar7);
        return pcVar7;
      }
      if ((bVar4 & 0x83) == 0x81) {
        return operand;
      }
    }
    diag_error(100);
    pcVar7 = pcVar7->left;
LAB_104117b3:
    if (((((operand->kind & 7) == 4) && (operand->op == '\x06')) && ((pcVar7->kind & 7) == 1)) &&
       (pcVar7->op == '=')) {
      pcVar3 = pcVar7->left;
      if (((pcVar3[1] & 7U) == 4) && (*pcVar3 == '\x06')) {
        pcVar3[1] = pcVar3[1] & 0xdf;
      }
    }
    return pcVar7;
  case 0x59:
    if ((pcVar12->code & 0x110) == 0) {
      diag_error(0xab,0x59,pcVar12);
      return pcVar7;
    }
    if ((pcVar12->code & 0xfff) == 0x10) {
      diag_warning(1,0x324,uVar9);
    }
    pcVar13 = (c1_node *)expr_apply_implicit_conversion(operand);
    pcVar7->type = pcVar13->type;
    pcVar13 = fold_static_const_member(pcVar13);
    if ((pcVar13->kind & 7) == 3) {
      pcVar13->flags = pcVar13->flags & 0xfe;
      pcVar7 = type_fold_integer_constant_fragment
                         (pcVar13->type,~(uint)pcVar13->left,~(uint)pcVar13->right,pcVar13,pcVar7);
      return pcVar7;
    }
    return pcVar7;
  case 0x5a:
    uVar6 = operand->type->code;
    if ((uVar6 & 0x130) == 0) {
      diag_error(0xab,0x5a,operand->type);
      return pcVar7;
    }
    if (((uVar6 & 0xfff) == 0x10) && ((g_op_flags_table[operand->op] & 1) == 0)) {
      diag_warning(1,0x324,uVar9);
    }
    pcVar13 = (c1_node *)expr_apply_implicit_conversion(operand);
    pcVar12 = pcVar13->type;
    pcVar7->type = pcVar12;
    uVar6 = pcVar12->code;
    if (((uVar6 & 0x2000) != 0) ||
       ((((uVar6 & 0xfff) == 0x11 && ((uVar6 & 0x1000) == 0)) && (g_opt_J_unsigned_char != '\0'))))
    {
      diag_warning(2,0x92);
    }
    operand = fold_static_const_member(pcVar13);
    if ((operand->kind & 7) != 3) {
      return pcVar7;
    }
    operand->flags = operand->flags & 0xfe;
    pcVar12 = operand->type;
    uVar6 = pcVar12->code;
    if (((byte)uVar6 >> 5 & 1) != 0) {
      iVar8 = float_fold_subtract_constants
                        (&g_float_zero,operand->left,(c1xx_float_const *)&local_10);
      if (iVar8 != 0) {
        diag_warning(2,0x38);
      }
      pvVar14 = record3_new_from((int *)&local_10,g_expr_arena_index);
      operand->left = pvVar14;
      return operand;
    }
    uVar9 = -(int)operand->left;
    hi = -((int)operand->right + (uint)(operand->left != (void *)0x0));
    uVar17 = CONCAT44(hi,uVar9);
    if ((uVar6 & 0x2000) == 0) {
      if ((((uVar6 & 0xfff) == 0x11) && ((uVar6 & 0x1000) == 0)) && (g_opt_J_unsigned_char != '\0'))
      {
        pcVar7 = type_fold_integer_constant_fragment(pcVar12,uVar9,hi,operand,pcVar7);
        return pcVar7;
      }
      bVar4 = ('\b' - (&g_type_rank_table)[uVar6 & 0xf]) * '\b';
      lVar16 = _allshl(bVar4,uVar9,hi);
      uVar17 = _allshr(bVar4,(int)((ulonglong)lVar16 >> 0x20),(uint)lVar16);
    }
    uVar6 = pcVar12->code;
    if ((-1 < (char)uVar6) &&
       (((uVar6 & 0x2000) != 0 ||
        (((((uVar6 & 0xfff) == 0x11 && ((uVar6 & 0x1000) == 0)) && (g_opt_J_unsigned_char != '\0'))
         || ((-1 < (longlong)uVar17 && (uVar17 != 0)))))))) {
      bVar4 = ('\b' - (&g_type_rank_table)[uVar6 & 0xf]) * '\b';
      lVar16 = _allshl(bVar4,(uint)uVar17,(uint)(uVar17 >> 0x20));
      uVar17 = _aullshr(bVar4,(uint)((ulonglong)lVar16 >> 0x20),(uint)lVar16);
    }
    if (((byte)g_compile_flags_cc & 8) != 0) {
      operand = tree_copy_to_arena(operand,5);
    }
    operand->type = pcVar7->type;
    operand->left = (void *)(int)uVar17;
    operand->right = (void *)(int)(uVar17 >> 0x20);
    break;
  case 0x76:
    operand->flags = operand->flags | 2;
    if ((((byte)pcVar7->type->code >> 5 & 1) != 0) &&
       (operand = fold_static_const_member(operand), (operand->kind & 7) != 3)) {
      return pcVar7;
    }
    break;
  case 0x86:
    uVar6 = pcVar12->code;
    if (((-1 < (char)uVar6) || (((uVar6 & 0x8f) != 0x86 && ((uVar6 & 0x8f) != 0x82)))) &&
       ((uVar6 & 0x130) == 0)) {
      diag_error(0xab,0x86,pcVar12);
    }
    pcVar13 = (c1_node *)expr_apply_implicit_conversion(operand);
    pcVar7->type = pcVar13->type;
    operand = fold_static_const_member(pcVar13);
    pcVar12 = operand->type;
    if ((operand->kind & 7) == 3) {
      if (((byte)pcVar12->code >> 5 & 1) == 0) {
        pcVar7 = type_fold_integer_constant_fragment
                           (pcVar12,(uint)operand->left,(int)operand->right,operand,pcVar7);
        return pcVar7;
      }
    }
    else if (pcVar7->type != pcVar12) {
      return pcVar7;
    }
    break;
  case 0xf0:
    pcVar7 = tree_new_unary(op_00,g_type_void,operand);
    return pcVar7;
  }
  return operand;
}

