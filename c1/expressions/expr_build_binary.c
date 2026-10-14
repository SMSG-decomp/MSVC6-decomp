c1_node * __cdecl expr_build_binary(c1_u8 op,c1_node *left,c1_node *right)

{
  undefined2 uVar1;
  bool bVar2;
  byte bVar3;
  byte bVar4;
  ushort uVar5;
  ushort uVar6;
  c1_node *pcVar7;
  int iVar8;
  uint uVar9;
  c1_type *pcVar10;
  c1_node *pcVar11;
  c1_node *pcVar12;
  uint uVar13;
  c1_type *pcVar14;
  longlong lVar15;
  c1_type local_10;
  
  pcVar12 = right;
  pcVar11 = left;
  if (left == (c1_node *)0x0) {
    return (c1_node *)0x0;
  }
  if (right == (c1_node *)0x0) {
    return (c1_node *)0x0;
  }
  uVar9 = (uint)op;
  switch((&g_token_class)[uVar9]) {
  case 0x32:
  case 0x34:
  case 0x37:
  case 0x4f:
  case 0x54:
  case 0x55:
  case 0x73:
  case 0x74:
  case 0x83:
    break;
  default:
    switch(uVar9) {
    case 0x31:
    case 0x48:
    case 0x4d:
    case 0x5b:
      if (((byte)left->type->code >> 5 & 1) != 0) goto switchD_1060c228_caseD_41;
      if (((byte)right->type->code >> 5 & 1) == 0) goto switchD_1060c28a_caseD_32;
      left = (c1_node *)expr_apply_implicit_conversion(left);
      break;
    default:
switchD_1060c28a_caseD_32:
      conv_balance_binary_operands(&left,&right);
      break;
    case 0x56:
      left = (c1_node *)expr_apply_implicit_conversion(left);
      right = (c1_node *)expr_apply_implicit_conversion(right);
    }
    break;
  case 0x41:
switchD_1060c228_caseD_41:
    right = (c1_node *)expr_apply_implicit_conversion(right);
    break;
  case 0x61:
    switch(uVar9) {
    case 0x33:
    case 0x49:
    case 0x4e:
    case 0x5c:
      if (((byte)left->type->code >> 5 & 1) == 0) {
        right = (c1_node *)conv_promote_operand(left->type,right);
      }
      else {
        right = (c1_node *)expr_apply_implicit_conversion(right);
      }
      break;
    default:
      right = (c1_node *)conv_promote_operand(left->type,right);
    }
  }
  pcVar7 = tree_new_node(op,left,right,(c1_type *)0x0);
  iVar8 = expr_check_illegal_for_type(op,'\x02',left,right);
  if (iVar8 == 0) {
    return (c1_node *)0x0;
  }
  switch(uVar9) {
  case 0x31:
  case 0x4d:
  case 0x5b:
    if ((((g_op_flags_table[pcVar11->op] & 8) != 0) && ((pcVar11->flags & 2) == 0)) ||
       (((g_op_flags_table[pcVar12->op] & 8) != 0 && ((pcVar12->flags & 2) == 0)))) {
      diag_warning(3,0x22a,uVar9);
    }
  case 0x39:
  case 0x48:
  case 0x4a:
    pcVar10 = conv_usual_arithmetic(op,left->type,right->type);
    pcVar7->type = pcVar10;
    break;
  case 0x33:
  case 0x34:
  case 0x3a:
  case 0x42:
  case 0x47:
  case 0x49:
  case 0x4b:
  case 0x4e:
  case 0x52:
  case 0x57:
  case 0x5c:
  case 0x74:
    pcVar11 = expr_check_binary_operand_types(pcVar7);
    if (pcVar11 == (c1_node *)0x0) {
      return (c1_node *)0x0;
    }
    pcVar11->type = left->type;
    pcVar12 = expr_warn_cast_on_lvalue(left,(uint)(op != 't'));
    pcVar11->left = pcVar12;
    if (pcVar12 != (c1_node *)0x0) {
      uVar6 = pcVar11->type->flags & 0x18;
      if ((uVar6 != 0x18) && (uVar6 != 8)) {
        return pcVar11;
      }
      if ((op == 't') || (op == '4')) {
        pcVar12 = type_based_pointer_from_node(pcVar11->type,pcVar11->right);
        pcVar11->right = pcVar12;
      }
      pcVar11 = expr_based_pointer_fixup(pcVar11);
      return pcVar11;
    }
    diag_error(0x6a,uVar9);
    return pcVar11;
  default:
    return pcVar7;
  case 0x36:
    if ((left->type->code & 0x8f) == 0x83) {
      pcVar10 = conv_array_to_pointer_type(left);
      left->type = pcVar10;
    }
    if ((right->type->code & 0x8f) == 0x83) {
      pcVar10 = conv_array_to_pointer_type(right);
      right->type = pcVar10;
    }
    pcVar10 = conv_usual_arithmetic(op,left->type,right->type);
    pcVar7->type = pcVar10;
    uVar6 = left->type->flags | right->type->flags;
    if (pcVar10->flags != uVar6) {
      uVar1 = pcVar10->code;
      local_10.base = pcVar10->base;
      local_10.extra = pcVar10->extra;
      local_10.debug_index = pcVar10->debug_index;
      local_10.flags = uVar6;
      local_10.code = uVar1;
      pcVar10 = type_intern(&local_10);
    }
    pcVar7->type = pcVar10;
    expr_check_operand_conversion_unless_null(op,left,right);
    uVar6 = pcVar7->type->code;
    if (((char)uVar6 < '\0') && ((uVar6 = uVar6 & 0x8f, uVar6 == 0x86 || (uVar6 == 0x82)))) {
      bVar4 = left->kind & 0x80;
      if ((bVar4 != 0) && ((right->kind & 0x80) != 0)) {
        pcVar11 = expr_build_binary_fragment_2(0x80,pcVar7);
        return pcVar11;
      }
      if (bVar4 != 0) {
        pcVar7->type = right->type;
        return pcVar7;
      }
      if ((right->kind & 0x80) != 0) {
        pcVar7->type = left->type;
      }
    }
    return pcVar7;
  case 0x38:
  case 0x40:
  case 0x54:
  case 0x55:
    pcVar7->type = left->type;
    left = expr_warn_cast_on_lvalue(left,1);
    if (left == (c1_node *)0x0) {
      diag_error(0x69,uVar9);
      return pcVar7;
    }
    pcVar7->left = left;
    pcVar10 = pcVar7->type;
    if (-1 < (char)pcVar10->code) {
      pcVar11 = fold_float_constant_conversion(op,pcVar10,pcVar7->right);
      pcVar7->right = pcVar11;
      return pcVar7;
    }
    uVar6 = pcVar10->code & 0x8f;
    if (uVar6 == 0x82) {
      uVar9 = type_size_checked(pcVar10);
      g_constant_value_high = 0;
      g_constant_value = uVar9;
      lVar15 = _allshl(0x1f,0xffffffff,0xffffffff);
      uVar13 = ~(uint)((ulonglong)lVar15 >> 0x20);
      if (((int)uVar13 < 1) && ((0x7fffffff < uVar13 || (~(uint)lVar15 < uVar9)))) {
        pcVar11 = tree_new_constant(g_type_long,&g_constant_value,g_expr_arena_index);
        pcVar7->right = pcVar11;
      }
      else {
        pcVar11 = tree_new_constant(g_type_int,&g_constant_value,g_expr_arena_index);
        pcVar7->right = pcVar11;
      }
    }
    else if ((uVar6 == 0x86) ||
            ((bVar4 = (byte)pcVar10->code, (char)bVar4 < '\0' && ((bVar4 & 0x8f) == 0x84)))) {
      diag_error(0xab,uVar9,pcVar10);
    }
    if ((*(byte *)(((uint)pcVar7->type & -(uint)((pcVar7->type->code & 0x80) != 0)) + 2) & 8) != 0)
    {
      pcVar11 = expr_based_pointer_fixup(pcVar7);
      return pcVar11;
    }
    return pcVar7;
  case 0x3b:
  case 0x3e:
  case 0x3f:
  case 0x44:
  case 0x45:
  case 0x4c:
    if (((left->kind & 7) == 5) || ((right->kind & 7) == 5)) {
      diag_warning(4,0x82,uVar9);
    }
  case 0x32:
  case 0x4f:
    pcVar11 = expr_check_binary_operand_types(pcVar7);
    if (pcVar11 != (c1_node *)0x0) {
      pcVar11->type = g_type_int;
      pcVar11 = fold_binary_constant_expression(pcVar11,left,right);
      return pcVar11;
    }
    return (c1_node *)0x0;
  case 0x41:
    if ((left->type->code & 0x8f) == 0x83) {
      pcVar10 = conv_array_to_pointer_type(left);
      left->type = pcVar10;
    }
    if ((right->type->code & 0x8f) == 0x83) {
      pcVar10 = conv_array_to_pointer_type(right);
      right->type = pcVar10;
    }
    pcVar10 = conv_usual_arithmetic(op,left->type,(c1_type *)0x0);
    pcVar7->type = pcVar10;
    pcVar10 = left->type;
    pcVar14 = right->type;
    uVar6 = pcVar10->code & 0x8f;
    if ((uVar6 != 0x82) && (uVar6 != 0x83)) {
      uVar6 = pcVar14->code & 0x8f;
      if ((uVar6 != 0x82) && (uVar6 != 0x83)) {
        diag_error(0x6d);
        return pcVar7;
      }
      pcVar7->left = right;
      pcVar7->right = left;
      right = left;
      pcVar11 = pcVar7->left;
      pcVar7->type = pcVar11->type;
      pcVar10 = pcVar11->type;
      pcVar14 = left->type;
      left = pcVar11;
    }
    if ((pcVar10->flags & 0x18) == 8) {
      diag_error(0xd6);
      return pcVar7;
    }
    if (-1 < (char)pcVar14->code) {
      if ((pcVar14->code & 0x110) == 0) {
        diag_error(0x6c);
        return pcVar7;
      }
      g_constant_value = type_size_checked(pcVar10);
      g_constant_value_high = 0;
      pcVar11 = tree_new_constant(g_type_long,&g_constant_value,g_expr_arena_index);
      right = expr_build_binary('J',right,pcVar11);
      pcVar7->right = right;
      if ((((right->kind & 7) == 3) && (left->op == 'A')) &&
         ((*(byte *)((int)left->right + 1) & 7) == 3)) {
        pcVar11 = expr_build_binary_fragment(left,pcVar10,pcVar7,left,right);
        return pcVar11;
      }
      pcVar10 = pcVar10->base;
      pcVar7->type = pcVar10;
      if ((pcVar10->code & 0x8f) != 0x83) {
        pcVar7 = tree_new_rvalue(pcVar7);
      }
      return pcVar7;
    }
    diag_error(0x6b);
    return pcVar7;
  case 0x43:
  case 0x58:
    if (((g_op_flags_table[pcVar11->op] & 4) != 0) && ((pcVar11->flags & 2) == 0)) {
      pcVar11 = expr_warn_operator_precedence(pcVar7,left,right);
      return pcVar11;
    }
    if (((g_op_flags_table[pcVar12->op] & 4) != 0) && ((pcVar12->flags & 2) == 0)) {
      pcVar11 = expr_warn_operator_precedence(pcVar7,left,right);
      return pcVar11;
    }
    pcVar7->left = left;
    pcVar7->type = left->type;
    break;
  case 0x46:
    if ((left->type->code & 0x8f) == 0x83) {
      pcVar10 = conv_array_to_pointer_type(left);
      left->type = pcVar10;
    }
    if ((right->type->code & 0x8f) == 0x83) {
      pcVar10 = conv_array_to_pointer_type(right);
      right->type = pcVar10;
    }
    pcVar10 = conv_usual_arithmetic(op,left->type,right->type);
    pcVar7->type = pcVar10;
    pcVar10 = left->type;
    pcVar14 = right->type;
    uVar6 = pcVar10->code & 0x8f;
    if ((uVar6 == 0x82) || (uVar6 == 0x83)) {
      uVar9 = type_size_checked(pcVar10);
      uVar6 = pcVar14->code;
      uVar5 = uVar6 & 0x8f;
      if ((uVar5 == 0x82) || (uVar5 == 0x83)) {
        expr_check_operand_conversion_unless_null('F',left,right);
        pcVar7->type = g_type_int;
        pcVar11 = fold_binary_constant_expression(pcVar7,left,right);
        if (uVar9 == 1) {
          return pcVar11;
        }
        if ((uVar9 & uVar9 - 1) != 0) {
          pcVar12 = tree_new_int_constant(uVar9);
          pcVar11 = expr_build_binary('9',pcVar11,pcVar12);
          return pcVar11;
        }
        iVar8 = 1;
        for (uVar9 = uVar9 >> 2; uVar9 != 0; uVar9 = uVar9 >> 1) {
          iVar8 = iVar8 + 1;
        }
        pcVar11->flags = pcVar11->flags | 2;
        pcVar12 = tree_new_int_constant(iVar8);
        pcVar11 = expr_build_binary('X',pcVar11,pcVar12);
        return pcVar11;
      }
      if ((uVar6 & 0x110) != 0) {
        g_constant_value_high = (int)uVar9 >> 0x1f;
        g_constant_value = uVar9;
        pcVar11 = tree_new_constant(g_type_long,&g_constant_value,g_expr_arena_index);
        pcVar11 = expr_build_binary('J',right,pcVar11);
        pcVar7->right = pcVar11;
        return pcVar7;
      }
      if ((uVar5 != 0x86) && ((-1 < (char)uVar6 || (uVar5 != 0x84)))) {
        diag_error(0x70);
        return pcVar7;
      }
      diag_error_C2296_or_C2297(op,2,pcVar14);
      return (c1_node *)0x0;
    }
    if ((uVar6 != 0x86) && ((bVar4 = (byte)pcVar10->code, -1 < (char)bVar4 || (uVar6 != 0x84)))) {
      bVar3 = (byte)pcVar14->code;
      if ((char)bVar3 < '\0') {
        diag_error(0x71);
        return (c1_node *)0x0;
      }
      if (((bVar4 >> 6 & 1) != 0) || ((bVar3 >> 6 & 1) != 0)) {
        diag_error(0xba,uVar9);
      }
      pcVar11 = fold_binary_constant_expression(pcVar7,left,right);
      return pcVar11;
    }
    goto LAB_1063b4db;
  case 0x51:
    bVar2 = false;
    if ((left->type->code & 0x8f) == 0x83) {
      pcVar10 = conv_array_to_pointer_type(left);
      left->type = pcVar10;
    }
    if ((right->type->code & 0x8f) == 0x83) {
      pcVar10 = conv_array_to_pointer_type(right);
      right->type = pcVar10;
    }
    pcVar10 = conv_usual_arithmetic(op,left->type,right->type);
    pcVar7->type = pcVar10;
    pcVar10 = left->type;
    pcVar14 = right->type;
    uVar6 = pcVar10->code & 0x8f;
    if (((uVar6 != 0x83) && (uVar6 != 0x82)) && (uVar6 != 0x86)) {
      uVar6 = pcVar14->code & 0x8f;
      if (((uVar6 != 0x83) && (uVar6 != 0x82)) && (uVar6 != 0x86)) {
        if ((((byte)pcVar10->code >> 6 & 1) != 0) || (((byte)pcVar14->code >> 6 & 1) != 0)) {
          diag_error(0xba,uVar9);
        }
        pcVar11 = fold_binary_constant_expression(pcVar7,left,right);
        return pcVar11;
      }
      pcVar7->left = right;
      pcVar7->right = left;
      right = left;
      pcVar11 = pcVar7->left;
      bVar2 = true;
      pcVar7->type = pcVar11->type;
      pcVar10 = pcVar11->type;
      pcVar14 = left->type;
      left = pcVar11;
    }
    uVar6 = pcVar10->code & 0x8f;
    if ((uVar6 != 0x86) && ((-1 < (char)pcVar10->code || (uVar6 != 0x84)))) {
      if ((pcVar14->code & 0x110) != 0) {
        g_constant_value = type_size_checked(pcVar10);
        g_constant_value_high = 0;
        pcVar11 = tree_new_constant(g_type_long,&g_constant_value,g_expr_arena_index);
        pcVar11 = expr_build_binary('J',right,pcVar11);
        pcVar7->right = pcVar11;
        return pcVar7;
      }
      if (-1 < (char)pcVar14->code) {
        diag_error(0x6f);
        return (c1_node *)0x0;
      }
      diag_error(0x6e);
      return (c1_node *)0x0;
    }
    if (bVar2) {
      diag_error_C2296_or_C2297(op,2,pcVar10);
      return (c1_node *)0x0;
    }
LAB_1063b4db:
    diag_error_C2296_or_C2297(op,1,pcVar10);
    return (c1_node *)0x0;
  case 0x56:
    uVar6 = left->type->code & 0x8f;
    if ((((uVar6 != 0x83) && (uVar6 != 0x82)) && (uVar6 != 0x86)) &&
       ((left->type->code & 0x130) == 0)) {
      diag_error(0x9b);
      return (c1_node *)0x0;
    }
    if ((left->kind & 7) == 3) {
      if (left->left == (void *)0x0 && left->right == (void *)0x0) {
        pcVar11 = right->right;
      }
      else {
        pcVar11 = right->left;
      }
      pcVar7 = conv_convert_to_type('\x01',right->type,pcVar11);
    }
  case 0x37:
    pcVar7->kind = pcVar7->kind | 0x20;
    pcVar7->type = right->type;
    if ((right->kind & 0x80) != 0) {
      pcVar7->kind = pcVar7->kind | 0x80;
    }
    if ((pcVar7->type->code & 0x8f) != 0x83) {
      return pcVar7;
    }
    pcVar10 = conv_array_to_pointer_type(pcVar7);
    pcVar7->type = pcVar10;
    return pcVar7;
  }
  pcVar11 = left;
  pcVar12 = right;
  pcVar7 = expr_check_binary_operand_types(pcVar7);
  pcVar11 = fold_binary_constant_expression(pcVar7,pcVar11,pcVar12);
  return pcVar11;
}

