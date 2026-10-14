c1_node * __cdecl expr_build_builtin_binary(c1_u8 op,c1_node *left,c1_node *right)

{
  c1_type **ppcVar1;
  c1_u8 cVar2;
  c1_u16 cVar3;
  void *pvVar4;
  char cVar5;
  byte bVar6;
  byte bVar7;
  ushort uVar8;
  ushort uVar9;
  c1_node *pcVar10;
  int iVar11;
  uint uVar12;
  c1_type *pcVar13;
  c1_node *pcVar14;
  ushort uVar15;
  uint uVar16;
  c1_type *pcVar17;
  longlong lVar18;
  c1_node *pcVar19;
  byte local_9;
  
  pcVar19 = right;
  pcVar14 = left;
  if ((right->op == 0xe8) &&
     (right = property_build_access(op,right,(c1_node *)0x0), right == (c1_node *)0x0)) {
    return (c1_node *)0x0;
  }
  if (left->op == 0xe8) {
    switch(op) {
    case '3':
    case '4':
    case '8':
    case ':':
    case '@':
    case 'A':
    case 'B':
    case 'G':
    case 'I':
    case 'K':
    case 'N':
    case 'R':
    case 'T':
    case 'U':
    case 'W':
    case '\\':
      pcVar14 = property_build_access(op,left,right);
      return pcVar14;
    }
    left = property_build_access(op,left,(c1_node *)0x0);
    if (left == (c1_node *)0x0) {
      return (c1_node *)0x0;
    }
  }
  cVar3 = left->type->code;
  if ((cVar3 == 0x80c) || (pcVar10 = left, cVar3 == 0x80e)) {
    switch(g_token_class[op]) {
    case '2':
    case 'O':
      diag_warning(1,0x227);
      break;
    case '4':
    case 'a':
    case 't':
      left = expr_resolve_address_of_overload(left);
      if ((left->kind & 8) == 0) {
        diag_error(0x293,(uint)op);
        return (c1_node *)0x0;
      }
      return (c1_node *)0x0;
    }
    pcVar10 = expr_resolve_function_address(right->type,left);
    if (pcVar10 == (c1_node *)0x0) {
      cVar3 = right->type->code;
      if ((cVar3 == 0x80c) || (cVar3 == 0x80e)) {
        expr_report_function_operand(op,left);
      }
      return (c1_node *)0x0;
    }
  }
  left = pcVar10;
  uVar12 = (uint)op;
  cVar2 = g_token_class[uVar12];
  if (((cVar2 != '4') && (cVar2 != 'a')) && (cVar2 != 't')) {
    left = fold_static_const_member(left);
  }
  cVar3 = right->type->code;
  if ((cVar3 == 0x80c) || (pcVar10 = right, cVar3 == 0x80e)) {
    if ((g_token_class[uVar12] == '2') || (g_token_class[uVar12] == 'O')) {
      diag_warning(1,0x227);
    }
    pcVar10 = expr_resolve_function_address(left->type,right);
    if ((pcVar10 == (c1_node *)0x0) || ((pcVar10->kind & 8) != 0)) {
      expr_report_function_operand(op,right);
      return (c1_node *)0x0;
    }
  }
  right = pcVar10;
  local_9 = 0;
  if (((left->type->code & 0xfff) == 0x10) || ((right->type->code & 0xfff) == 0x10)) {
    local_9 = expr_warn_bool_mix(left,right,op);
  }
  switch(g_token_class[uVar12]) {
  case '2':
  case '4':
  case '6':
  case '7':
  case 'O':
  case 'T':
  case 'U':
  case 'V':
  case 's':
  case 't':
  case 0x83:
  case 0x94:
    break;
  default:
    switch(uVar12) {
    case 0x31:
      goto switchD_104142aa_caseD_31;
    default:
      goto switchD_104142aa_caseD_32;
    case 0x48:
    case 0x4d:
    case 0x5b:
      goto switchD_104142aa_caseD_48;
    case 0x56:
      left = (c1_node *)expr_apply_implicit_conversion(left);
      right = (c1_node *)expr_apply_implicit_conversion(right);
      break;
    }
  case 'A':
switchD_10414213_caseD_41:
    right = (c1_node *)expr_apply_implicit_conversion(right);
    break;
  case 'a':
    switch(uVar12) {
    case 0x33:
    case 0x49:
    case 0x4e:
    case 0x5c:
      if (((byte)left->type->code >> 5 & 1) == 0) {
        cVar5 = type_compare(right->type,left->type,0);
        if ((cVar5 == '\0') || ((right->type->code & 0xfff) != 0x10))
        goto switchD_10414243_caseD_34;
      }
      else {
        right = (c1_node *)expr_apply_implicit_conversion(right);
      }
      break;
    default:
switchD_10414243_caseD_34:
      right = (c1_node *)conv_apply_integral_promotion(left->type,right);
    }
  }
switchD_10414213_caseD_32:
  pcVar10 = tree_new_node(op,left,right,(c1_type *)0x0);
  pcVar10->flags = (pcVar10->flags ^ local_9) & 1 ^ pcVar10->flags;
  iVar11 = expr_check_illegal_for_type(op,2,left,right);
  if (iVar11 == 0) {
    return (c1_node *)0x0;
  }
  switch(uVar12) {
  case 0x31:
  case 0x4d:
  case 0x5b:
    if ((((g_op_flags_table[pcVar14->op] & 8) != 0) && ((pcVar14->flags & 2) == 0)) ||
       (((g_op_flags_table[pcVar19->op] & 8) != 0 && ((pcVar19->flags & 2) == 0)))) {
      diag_warning(3,0x22a,uVar12);
    }
  case 0x39:
  case 0x48:
  case 0x4a:
    pcVar13 = conv_usual_arithmetic(op,left->type,right->type);
    pcVar10->type = pcVar13;
LAB_1041483f:
    pcVar14 = left;
    pcVar19 = right;
    pcVar10 = expr_check_binary_operand_types(pcVar10);
    pcVar14 = fold_binary_constants(pcVar10,pcVar14,pcVar19);
    return pcVar14;
  case 0x33:
  case 0x3a:
  case 0x42:
  case 0x47:
  case 0x49:
  case 0x4b:
  case 0x4e:
  case 0x52:
  case 0x57:
  case 0x5c:
    if ((left->type->code & 0xfff) == 0x10) {
      pcVar14 = expr_build_bool_increment(op,left,right);
      return pcVar14;
    }
  case 0x34:
  case 0x74:
    pcVar10 = expr_check_binary_operand_types(pcVar10);
    if (pcVar10 == (c1_node *)0x0) {
      return (c1_node *)0x0;
    }
    pcVar10->type = left->type;
    pcVar14 = expr_lvalue_address(left,(uint)(op != 't'));
    pcVar10->left = pcVar14;
    if (pcVar14 == (c1_node *)0x0) {
      diag_error(0x6a,uVar12);
      return pcVar10;
    }
    uVar9 = pcVar10->type->flags & 0x18;
    if ((uVar9 == 0x18) || (uVar9 == 8)) {
      if ((op == 't') || (op == '4')) {
        pcVar14 = type_based_pointer_from_node(pcVar10->type,pcVar10->right);
        pcVar10->right = pcVar14;
      }
      pcVar10 = expr_based_pointer_fixup(pcVar10);
    }
    break;
  case 0x37:
  case 0x56:
    bVar7 = (right->flags ^ pcVar10->flags) & 1 ^ pcVar10->flags;
    pcVar10->flags = bVar7;
    pcVar10->flags = (right->flags ^ bVar7) & 4 ^ bVar7;
    pcVar10->type = right->type;
    if ((right->kind & 0x80) != 0) {
      pcVar10->kind = pcVar10->kind | 0x80;
    }
    if ((pcVar10->type->code & 0x8f) == 0x83) {
      pcVar13 = conv_array_to_pointer_type(pcVar10);
      pcVar10->type = pcVar13;
      return pcVar10;
    }
    break;
  case 0x38:
  case 0x40:
  case 0x54:
  case 0x55:
    pcVar13 = left->type;
    if ((pcVar13->code & 0xfff) == 0x10) {
      pcVar14 = expr_build_bool_increment(op,left,(c1_node *)0x0);
      return pcVar14;
    }
    pcVar10->type = pcVar13;
    if (((char)pcVar13->code < '\0') &&
       (cVar5 = expr_check_operand_type_illegal(op,pcVar13), cVar5 != '\0')) {
      pcVar14 = expr_build_subscript_and_lvalue_ops_return_null();
      return pcVar14;
    }
    if ((left->type->code & 0x100) != 0) {
      diag_error(0x7e,uVar12);
    }
    left = expr_lvalue_address(left,1);
    if (left == (c1_node *)0x0) {
      diag_error(0x69,uVar12);
      return pcVar10;
    }
    pcVar10->left = left;
    pcVar13 = pcVar10->type;
    if (-1 < (char)pcVar13->code) {
      pcVar14 = fold_float_conversion(op,pcVar13,pcVar10->right);
      pcVar10->right = pcVar14;
      return pcVar10;
    }
    uVar9 = pcVar13->code & 0x8f;
    if (uVar9 == 0x82) {
      uVar12 = type_size_checked(pcVar13);
      g_constant_value_high = 0;
      g_constant_value = uVar12;
      lVar18 = _allshl(0x1f,0xffffffff,0xffffffff);
      uVar16 = ~(uint)((ulonglong)lVar18 >> 0x20);
      if (((int)uVar16 < 1) && ((0x7fffffff < uVar16 || (~(uint)lVar18 < uVar12)))) {
        pcVar14 = tree_new_constant(g_type_long,&g_constant_value,g_expr_arena_index);
        pcVar10->right = pcVar14;
      }
      else {
        pcVar14 = tree_new_constant(g_type_int,&g_constant_value,g_expr_arena_index);
        pcVar10->right = pcVar14;
      }
    }
    else if ((uVar9 == 0x86) ||
            ((bVar7 = (byte)pcVar13->code, (char)bVar7 < '\0' && ((bVar7 & 0x8f) == 0x84)))) {
      diag_error(0xab,uVar12,pcVar13);
    }
    if ((*(byte *)(((uint)pcVar10->type & -(uint)((pcVar10->type->code & 0x80) != 0)) + 2) & 8) != 0
       ) {
      pcVar14 = expr_based_pointer_fixup(pcVar10);
      return pcVar14;
    }
    break;
  case 0x3b:
  case 0x3e:
  case 0x3f:
  case 0x44:
  case 0x45:
  case 0x4c:
    if (((left->kind & 7) == 5) || ((right->kind & 7) == 5)) {
      diag_warning(4,0x82,uVar12);
    }
  case 0x32:
  case 0x4f:
    pcVar14 = expr_check_binary_operand_types(pcVar10);
    if (pcVar14 == (c1_node *)0x0) {
      return (c1_node *)0x0;
    }
    pcVar14->type = g_type_bool;
    pcVar14 = fold_binary_constants(pcVar14,left,right);
    pcVar14->flags = pcVar14->flags | 1;
    return pcVar14;
  case 0x41:
    if ((left->type->code & 0x8f) == 0x83) {
      pcVar13 = conv_array_to_pointer_type(left);
      left->type = pcVar13;
    }
    if ((right->type->code & 0x8f) == 0x83) {
      pcVar13 = conv_array_to_pointer_type(right);
      right->type = pcVar13;
    }
    pcVar13 = conv_usual_arithmetic(op,left->type,(c1_type *)0x0);
    pcVar10->type = pcVar13;
    pcVar13 = left->type;
    pcVar17 = right->type;
    uVar9 = pcVar13->code & 0x8f;
    if ((uVar9 != 0x82) && (uVar9 != 0x83)) {
      uVar9 = pcVar17->code & 0x8f;
      if ((uVar9 != 0x82) && (uVar9 != 0x83)) {
        diag_error(0x6d);
        return pcVar10;
      }
      pcVar10->left = right;
      pcVar10->right = left;
      right = left;
      pcVar14 = pcVar10->left;
      pcVar10->type = pcVar14->type;
      pcVar13 = pcVar14->type;
      pcVar17 = left->type;
      left = pcVar14;
    }
    if ((pcVar13->flags & 0x18) == 8) {
      diag_error(0xd6);
      return pcVar10;
    }
    if ((char)pcVar17->code < '\0') {
      diag_error(0x6b);
      return pcVar10;
    }
    if ((pcVar17->code & 0x110) == 0) {
      diag_error(0x6c);
      return pcVar10;
    }
    g_constant_value = type_size_checked(pcVar13);
    g_constant_value_high = 0;
    pcVar14 = tree_new_constant(g_type_long,&g_constant_value,g_expr_arena_index);
    right = expr_build_builtin_binary('J',right,pcVar14);
    pcVar10->right = right;
    right = fold_static_const_member(right);
    if ((((right->kind & 7) == 3) && (left->op == 'A')) &&
       ((*(byte *)((int)left->right + 1) & 7) == 3)) {
      pcVar10->left = left->left;
      uVar12 = *(uint *)((int)left->right + 0x10);
      pvVar4 = right->left;
      iVar11 = *(int *)((int)left->right + 0x14);
      right->left = (void *)((int)pvVar4 + uVar12);
      right->right = (void *)((int)right->right + (uint)CARRY4((uint)pvVar4,uVar12) + iVar11);
    }
    pcVar13 = pcVar13->base;
    pcVar10->type = pcVar13;
    if ((pcVar13->code & 0x8f) != 0x83) {
      pcVar14 = tree_new_rvalue(pcVar10);
      return pcVar14;
    }
    break;
  case 0x43:
  case 0x58:
    if ((((g_op_flags_table[pcVar14->op] & 4) != 0) && ((pcVar14->flags & 2) == 0)) ||
       (((g_op_flags_table[pcVar19->op] & 4) != 0 && ((pcVar19->flags & 2) == 0)))) {
      diag_warning(3,0x22a,uVar12);
    }
    pcVar10->left = left;
    pcVar10->type = left->type;
    goto LAB_1041483f;
  case 0x46:
    if ((left->type->code & 0x8f) == 0x83) {
      pcVar13 = conv_array_to_pointer_type(left);
      left->type = pcVar13;
    }
    if ((right->type->code & 0x8f) == 0x83) {
      pcVar13 = conv_array_to_pointer_type(right);
      right->type = pcVar13;
    }
    pcVar13 = conv_usual_arithmetic(op,left->type,right->type);
    pcVar10->type = pcVar13;
    cVar5 = expr_check_member_pointer_operand(pcVar10);
    if (cVar5 != '\0') {
      return (c1_node *)0x0;
    }
    pcVar13 = left->type;
    pcVar17 = right->type;
    uVar9 = pcVar13->code & 0x8f;
    if ((uVar9 != 0x82) && (uVar9 != 0x83)) {
      if ((uVar9 != 0x86) && ((bVar7 = (byte)pcVar13->code, -1 < (char)bVar7 || (uVar9 != 0x84)))) {
        bVar6 = (byte)pcVar17->code;
        if ((char)bVar6 < '\0') {
          diag_error(0x71);
          return (c1_node *)0x0;
        }
        if (((bVar7 >> 6 & 1) != 0) || ((bVar6 >> 6 & 1) != 0)) {
          diag_error(0xba,uVar12);
        }
        pcVar14 = fold_binary_constants(pcVar10,left,right);
        return pcVar14;
      }
      diag_error_C2296_or_C2297(op,1,pcVar13);
      return (c1_node *)0x0;
    }
    uVar12 = type_size_checked(pcVar13);
    uVar9 = pcVar17->code;
    uVar8 = uVar9 & 0x8f;
    if ((uVar8 != 0x82) && (uVar8 != 0x83)) {
      if ((uVar9 & 0x110) != 0) {
        g_constant_value_high = (int)uVar12 >> 0x1f;
        g_constant_value = uVar12;
        pcVar14 = tree_new_constant(g_type_long,&g_constant_value,g_expr_arena_index);
        pcVar14 = expr_build_builtin_binary('J',right,pcVar14);
        pcVar10->right = pcVar14;
        return pcVar10;
      }
      if ((uVar8 != 0x86) && ((-1 < (char)uVar9 || (uVar8 != 0x84)))) {
        diag_error(0x70);
        return pcVar10;
      }
      diag_error_C2296_or_C2297(op,2,pcVar17);
      return (c1_node *)0x0;
    }
    if ((((char)pcVar13->code < '\0') &&
        ((((uVar15 = pcVar13->code & 0x8f, uVar15 == 0x86 || (uVar15 == 0x82)) &&
          ((pcVar13->base->code & 0x200) != 0)) && ((char)uVar9 < '\0')))) &&
       (((uVar8 == 0x86 || (uVar8 == 0x82)) && ((pcVar17->base->code & 0x200) != 0)))) {
      pcVar10 = expr_convert_operands_to_common_type(pcVar10,left,right);
      if (pcVar10 == (c1_node *)0x0) {
        return (c1_node *)0x0;
      }
      left = pcVar10->left;
      right = pcVar10->right;
      uVar12 = type_size_checked(left->type);
    }
    expr_check_operand_conversion_unless_null(0x46,left,right);
    pcVar10->type = g_type_int;
    pcVar10 = fold_binary_constants(pcVar10,left,right);
    if (uVar12 != 1) {
      if ((uVar12 & uVar12 - 1) != 0) {
        pcVar14 = tree_new_int_constant(uVar12);
        pcVar14 = expr_build_builtin_binary('9',pcVar10,pcVar14);
        return pcVar14;
      }
      iVar11 = 1;
      for (uVar12 = uVar12 >> 2; uVar12 != 0; uVar12 = uVar12 >> 1) {
        iVar11 = iVar11 + 1;
      }
      pcVar10->flags = pcVar10->flags | 2;
      pcVar14 = tree_new_int_constant(iVar11);
      pcVar14 = expr_build_builtin_binary('X',pcVar10,pcVar14);
      return pcVar14;
    }
    break;
  case 0x51:
    if ((left->type->code & 0x8f) == 0x83) {
      pcVar13 = conv_array_to_pointer_type(left);
      left->type = pcVar13;
    }
    if ((right->type->code & 0x8f) == 0x83) {
      pcVar13 = conv_array_to_pointer_type(right);
      right->type = pcVar13;
    }
    pcVar13 = conv_usual_arithmetic(op,left->type,right->type);
    pcVar10->type = pcVar13;
    cVar5 = expr_check_member_pointer_operand(pcVar10);
    pcVar14 = left;
    if (cVar5 != '\0') {
      return (c1_node *)0x0;
    }
    pcVar13 = left->type;
    uVar9 = pcVar13->code & 0x8f;
    if (((uVar9 != 0x83) && (uVar9 != 0x82)) && (uVar9 != 0x86)) {
      uVar9 = right->type->code;
      uVar8 = uVar9 & 0x8f;
      if (((uVar8 != 0x83) && (uVar8 != 0x82)) && (uVar8 != 0x86)) {
        if ((((byte)pcVar13->code >> 6 & 1) != 0) || (((byte)uVar9 >> 6 & 1) != 0)) {
          diag_error(0xba,uVar12);
        }
        pcVar14 = fold_binary_constants(pcVar10,left,right);
        return pcVar14;
      }
      pcVar10->left = right;
      pcVar10->right = left;
      right = left;
      pcVar19 = pcVar10->left;
      pcVar10->type = pcVar19->type;
      ppcVar1 = &left->type;
      left = pcVar19;
      pcVar14 = expr_build_builtin_binary_pointer_add(pcVar19->type,1,*ppcVar1,pcVar10,op,pcVar14);
      return pcVar14;
    }
    uVar9 = pcVar13->code & 0x8f;
    if ((uVar9 == 0x86) || (((char)pcVar13->code < '\0' && (uVar9 == 0x84)))) {
      diag_error_C2296_or_C2297(op,1,pcVar13);
      return (c1_node *)0x0;
    }
    uVar9 = right->type->code;
    if ((uVar9 & 0x110) != 0) {
      g_constant_value = type_size_checked(pcVar13);
      g_constant_value_high = 0;
      pcVar14 = tree_new_constant(g_type_long,&g_constant_value,g_expr_arena_index);
      pcVar14 = expr_build_builtin_binary('J',right,pcVar14);
      pcVar10->right = pcVar14;
      return pcVar10;
    }
    if (-1 < (char)uVar9) {
      diag_error(0x6f);
      return (c1_node *)0x0;
    }
    diag_error(0x6e);
    return (c1_node *)0x0;
  case 0x92:
  case 0x93:
    pcVar13 = left->type;
    cVar5 = (char)pcVar13->code;
    pcVar17 = pcVar13;
    while (cVar5 < '\0') {
      pcVar17 = pcVar17->base;
      cVar5 = (char)pcVar17->code;
    }
    if ((pcVar17->code & 0x200) != 0) {
      if (op == 0x92) {
        cVar5 = (char)pcVar13->code;
      }
      else {
        if (op != 0x93) goto LAB_104806d7;
        if ((pcVar13->code & 0x8f) != 0x82) goto LAB_10480723;
        cVar5 = (char)pcVar13->base->code;
      }
      if (-1 < cVar5) {
LAB_104806d7:
        uVar9 = right->type->code & 0x8f;
        if ((uVar9 != 0x8a) && (uVar9 != 0x8e)) {
          diag_error_C2296_or_C2297(op,2,right->type);
          return (c1_node *)0x0;
        }
        pcVar14 = expr_build_member_pointer_dereference(pcVar10);
        return pcVar14;
      }
    }
LAB_10480723:
    diag_error_C2296_or_C2297(op,1,pcVar13);
    return (c1_node *)0x0;
  }
  return pcVar10;
switchD_104142aa_caseD_31:
  if (((left->flags & 1) != 0) || ((right->flags & 1) != 0)) {
    local_9 = 1;
  }
switchD_104142aa_caseD_48:
  if (((byte)left->type->code >> 5 & 1) != 0) goto switchD_10414213_caseD_41;
  if (((byte)right->type->code >> 5 & 1) == 0) {
switchD_104142aa_caseD_32:
    conv_apply_integral_promotion_2(&left,&right);
  }
  else {
    left = (c1_node *)expr_apply_implicit_conversion(left);
  }
  goto switchD_10414213_caseD_32;
}

