c1_node * __cdecl expr_check_binary_operand_types(c1_node *node)

{
  c1_u16 cVar1;
  ushort uVar2;
  c1_type *right_type;
  char *pcVar3;
  bool bVar4;
  uint op;
  char cVar5;
  c1_node *pcVar6;
  c1_type *pcVar7;
  char cVar8;
  byte bVar9;
  ushort uVar10;
  ushort uVar11;
  bool bVar12;
  c1_u8 op_00;
  c1_node *right_cell;
  c1_node *left_cell;
  uint op_cell;
  uint op_code;
  
  bVar4 = false;
  bVar12 = false;
  left_cell = node->left;
  right_cell = node->right;
  cVar1 = left_cell->type->code;
  if ((cVar1 == 0x80c) || (cVar1 == 0x80e)) {
    expr_resolve_function_operand
              (CONCAT31((int3)(CONCAT22((short)((uint)left_cell->type >> 0x10),cVar1) >> 8),node->op
                       ),&left_cell,right_cell);
  }
  cVar1 = right_cell->type->code;
  if ((cVar1 == 0x80c) || (cVar1 == 0x80e)) {
    expr_resolve_function_operand
              (CONCAT31((int3)((uint)left_cell >> 8),node->op),&right_cell,left_cell);
  }
  bVar9 = node->op;
  op_cell = CONCAT31(op_cell._1_3_,bVar9);
  op = op_cell;
  op_code = (uint)bVar9;
  switch(op_code) {
  case 0x31:
  case 0x43:
  case 0x48:
  case 0x4d:
  case 0x58:
  case 0x5b:
    pcVar7 = left_cell->type;
    if ((pcVar7->code & 0x110) == 0) {
LAB_10480f8b:
      diag_error_C2296_or_C2297(bVar9,1,pcVar7);
      bVar4 = true;
    }
    goto LAB_1042dc3b;
  case 0x32:
  case 0x4f:
    pcVar7 = left_cell->type;
    uVar10 = pcVar7->code & 0x8f;
    if ((uVar10 == 0x8a) || (uVar10 == 0x8e)) {
      left_cell = conv_convert_expression(bVar9,g_type_bool,left_cell,'\x02','\0');
      node->left = left_cell;
      bVar12 = bVar4;
    }
    else if (((((pcVar7->code & 0x130) == 0) && (uVar10 = pcVar7->code & 0x8f, uVar10 != 0x83)) &&
             (uVar10 != 0x82)) && (uVar10 != 0x86)) {
      diag_error_C2296_or_C2297(bVar9,1,pcVar7);
      bVar12 = true;
    }
    pcVar7 = right_cell->type;
    uVar10 = pcVar7->code & 0x8f;
    if ((uVar10 == 0x8a) || (uVar10 == 0x8e)) {
      pcVar6 = conv_convert_expression(bVar9,g_type_bool,right_cell,'\x02','\0');
      node->right = pcVar6;
    }
    else if ((((pcVar7->code & 0x130) == 0) && (uVar10 = pcVar7->code & 0x8f, uVar10 != 0x83)) &&
            ((uVar10 != 0x82 && (uVar10 != 0x86)))) {
      pcVar6 = expr_check_pointer_arithmetic_push_fragment(pcVar7,op);
      return pcVar6;
    }
    goto LAB_1042dc49;
  case 0x33:
  case 0x42:
  case 0x49:
  case 0x4e:
  case 0x57:
  case 0x5c:
    pcVar7 = left_cell->type;
    if (((byte)pcVar7->code >> 4 & 1) == 0) goto LAB_10480f8b;
LAB_1042dc3b:
    pcVar7 = right_cell->type;
    uVar10 = pcVar7->code & 0x110;
    bVar12 = bVar4;
LAB_1042dc43:
    if (uVar10 == 0) {
LAB_10480fa3:
      diag_error_C2296_or_C2297(bVar9,2,pcVar7);
    }
    else {
LAB_1042dc49:
      if (!bVar12) {
        return node;
      }
    }
    break;
  case 0x34:
    node = expr_convert_operands_to_common_type(node,left_cell,right_cell);
    if (node != (c1_node *)0x0) {
      left_cell = node->left;
      right_cell = node->right;
      goto switchD_1042dbd9_caseD_74;
    }
    break;
  case 0x39:
  case 0x4a:
    bVar12 = (left_cell->type->code & 0x130) == 0;
    if (bVar12) {
      diag_error_C2296_or_C2297(bVar9,1,left_cell->type);
    }
    pcVar7 = right_cell->type;
    uVar10 = pcVar7->code & 0x130;
    goto LAB_1042dc43;
  case 0x3a:
  case 0x4b:
    bVar12 = (left_cell->type->code & 0x30) == 0;
    if (bVar12) {
      diag_error_C2296_or_C2297(bVar9,1,left_cell->type);
    }
    pcVar7 = right_cell->type;
    if ((pcVar7->code & 0x30) != 0) {
      if (bVar12) {
        return (c1_node *)0x0;
      }
      expr_check_operand_conversion_unless_null(op,left_cell,right_cell);
      return node;
    }
    goto LAB_10480fa3;
  case 0x3b:
  case 0x4c:
    goto switchD_1042dbd9_caseD_3b;
  case 0x3e:
  case 0x3f:
  case 0x44:
  case 0x45:
    cVar5 = expr_check_member_pointer_operand(node);
    if (cVar5 != '\0') {
      return (c1_node *)0x0;
    }
switchD_1042dbd9_caseD_3b:
    if (((((left_cell->kind & 7) != 3) && ((right_cell->kind & 7) != 3)) &&
        (pcVar7 = left_cell->type, ((byte)pcVar7->code >> 4 & 1) != 0)) &&
       (right_type = right_cell->type, ((byte)right_type->code >> 4 & 1) != 0)) {
      uVar10 = pcVar7->code;
      if ((uVar10 & 0x2000) == 0) {
        if ((g_opt_J_unsigned_char != '\0') && (((byte)uVar10 & 0xf) == 1)) {
          if ((uVar10 & 0xfff) != 0x11) goto code_r0x1042dda6;
          if ((uVar10 & 0x1000) == 0) {
            pcVar6 = expr_check_pointer_arithmetic_zero_edx_fragment
                               (left_cell,g_opt_J_unsigned_char,right_cell,pcVar7,right_cell,
                                left_cell,op_cell,right_type,op_code,node);
            return pcVar6;
          }
        }
        cVar5 = '\x01';
      }
      else {
code_r0x1042dda6:
        cVar5 = '\0';
      }
      uVar10 = right_type->code;
      if ((uVar10 & 0x2000) == 0) {
        if ((g_opt_J_unsigned_char != '\0') && (((byte)uVar10 & 0xf) == 1)) {
          if ((uVar10 & 0xfff) != 0x11) goto code_r0x1042ddaa;
          if ((uVar10 & 0x1000) == 0) {
            pcVar6 = expr_check_binary_operand_types_signed_compare
                               (cVar5,left_cell,right_cell,pcVar7,right_cell,left_cell,op_cell,
                                right_type,op_code,node);
            return pcVar6;
          }
        }
        cVar8 = '\x01';
      }
      else {
code_r0x1042ddaa:
        cVar8 = '\0';
      }
      if (cVar8 != cVar5) {
        if ((left_cell->op == 'd') && (pcVar7 == g_type_int)) {
          pcVar3 = *(char **)((int)left_cell->left + 4);
          cVar5 = *pcVar3;
          while (cVar5 < '\0') {
            pcVar3 = *(char **)(pcVar3 + 4);
            cVar5 = *pcVar3;
          }
          if ((pcVar3[1] & 0x20U) != 0) goto LAB_1042dc9d;
        }
        if ((right_cell->op == 'd') && (right_type == g_type_int)) {
          pcVar3 = *(char **)((int)right_cell->left + 4);
          cVar5 = *pcVar3;
          while (cVar5 < '\0') {
            pcVar3 = *(char **)(pcVar3 + 4);
            cVar5 = *pcVar3;
          }
          if ((pcVar3[1] & 0x20U) == 0) {
            pcVar6 = expr_warn_signed_unsigned_compare(right_cell,left_cell,op_cell,op_code,node);
            return pcVar6;
          }
        }
        else {
          diag_warning(3,0x12,op_code);
        }
      }
    }
LAB_1042dc9d:
    pcVar6 = expr_convert_operands_to_common_type(node,left_cell,right_cell);
    if (pcVar6 != (c1_node *)0x0) {
      left_cell = pcVar6->left;
      right_cell = pcVar6->right;
      expr_check_operand_conversion_unless_null(op_cell,left_cell,right_cell);
      uVar10 = left_cell->type->code & 0x8f;
      if ((uVar10 != 0x8a) && (uVar10 != 0x8e)) {
        return pcVar6;
      }
      pcVar6 = expr_expand_member_pointer_compare(pcVar6);
      return pcVar6;
    }
    break;
  case 0x47:
  case 0x52:
    cVar5 = expr_check_member_pointer_operand(node);
    if (cVar5 == '\0') {
      uVar10 = right_cell->type->code;
      op_00 = (c1_u8)op_cell;
      if ((uVar10 & 0x130) == 0) {
        diag_error_C2296_or_C2297(op_00,2,right_cell->type);
        return (c1_node *)0x0;
      }
      pcVar7 = left_cell->type;
      uVar2 = pcVar7->code;
      if ((uVar2 & 0x100) != 0) {
        diag_error_C2296_or_C2297(op_00,1,pcVar7);
        return (c1_node *)0x0;
      }
      if ((uVar2 & 0x30) == 0) {
        if (((char)pcVar7->code < '\0') &&
           ((uVar11 = pcVar7->code & 0x8f, uVar11 == 0x86 || (uVar11 == 0x82)))) {
          if ((uVar10 & 0x110) != 0) {
            g_constant_value = type_size_checked(pcVar7);
            g_constant_value_high = 0;
            pcVar6 = tree_new_constant(g_type_long,&g_constant_value,g_expr_arena_index);
            pcVar6 = expr_build_builtin_binary('J',right_cell,pcVar6);
            node->right = pcVar6;
            return node;
          }
          diag_error(0x72,op_code);
          return (c1_node *)0x0;
        }
        if ((((byte)uVar2 & 0x8f) == 0x86) ||
           ((bVar9 = (byte)pcVar7->code, (char)bVar9 < '\0' && ((bVar9 & 0x8f) == 0x84)))) {
          diag_error_C2296_or_C2297(op_00,1,pcVar7);
          return (c1_node *)0x0;
        }
      }
      else {
        expr_check_operand_conversion_unless_null(op_cell,left_cell,right_cell);
      }
      return node;
    }
    break;
  case 0x74:
switchD_1042dbd9_caseD_74:
    expr_check_operand_conversion_unless_null(op,left_cell,right_cell);
    return node;
  }
  return (c1_node *)0x0;
}

