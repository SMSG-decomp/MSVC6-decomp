c1_node * __cdecl expr_check_binary_operand_types(c1_node *node)

{
  byte op;
  char cVar1;
  c1_u16 cVar2;
  c1_u16 cVar3;
  ushort uVar4;
  c1_node *left;
  char *pcVar5;
  uint uVar6;
  ushort uVar7;
  c1_node *pcVar8;
  c1_type *pcVar9;
  byte bVar10;
  ushort uVar11;
  bool bVar12;
  int operand;
  
  pcVar8 = node->left;
  left = node->right;
  op = node->op;
  uVar6 = (uint)op;
  switch(uVar6) {
  case 0x31:
  case 0x33:
  case 0x42:
  case 0x43:
  case 0x48:
  case 0x49:
  case 0x4d:
  case 0x4e:
  case 0x57:
  case 0x58:
  case 0x5b:
  case 0x5c:
    bVar12 = (pcVar8->type->code & 0x110) == 0;
    if (bVar12) {
      diag_error_C2296_or_C2297(op,1,pcVar8->type);
    }
    pcVar9 = left->type;
    if ((pcVar9->code & 0x110) == 0) goto LAB_1063bb6b;
    break;
  case 0x32:
  case 0x4f:
    pcVar9 = pcVar8->type;
    if (((((pcVar9->code & 0x130) == 0) && (uVar7 = pcVar9->code & 0x8f, uVar7 != 0x83)) &&
        (uVar7 != 0x82)) && (uVar7 != 0x86)) {
      pcVar8 = expr_check_binary_operand_types_fragment(left,pcVar9);
      return pcVar8;
    }
    pcVar9 = left->type;
    if ((((pcVar9->code & 0x130) != 0) || (uVar7 = pcVar9->code & 0x8f, uVar7 == 0x83)) ||
       ((uVar7 == 0x82 || (uVar7 == 0x86)))) {
      return node;
    }
LAB_1063bb6b:
    operand = 2;
    goto LAB_1063bb6d;
  case 0x34:
  case 0x74:
    if ((left->type->code & 0x8f) == 0x83) {
      pcVar9 = conv_array_to_pointer_type(left);
      left->type = pcVar9;
    }
    goto LAB_1060db9e;
  default:
    goto switchD_1060d932_caseD_35;
  case 0x39:
  case 0x4a:
    bVar12 = (pcVar8->type->code & 0x130) == 0;
    if (bVar12) {
      diag_error_C2296_or_C2297(op,1,pcVar8->type);
    }
    if ((left->type->code & 0x130) == 0) {
      diag_error_C2296_or_C2297(op,2,left->type);
      return (c1_node *)0x0;
    }
    break;
  case 0x3a:
  case 0x4b:
    bVar12 = (pcVar8->type->code & 0x30) == 0;
    if (bVar12) {
      diag_error_C2296_or_C2297(op,1,pcVar8->type);
    }
    if ((left->type->code & 0x30) != 0) {
      if (bVar12) {
        return (c1_node *)0x0;
      }
      expr_check_operand_conversion_unless_null(op,pcVar8,left);
      return node;
    }
    diag_error_C2296_or_C2297(op,2,left->type);
    return (c1_node *)0x0;
  case 0x3b:
  case 0x3e:
  case 0x3f:
  case 0x44:
  case 0x45:
  case 0x4c:
    if (((pcVar8->kind & 7) != 3) && ((left->kind & 7) != 3)) {
      cVar2 = pcVar8->type->code;
      if (((byte)cVar2 >> 4 & 1) != 0) {
        cVar3 = left->type->code;
        if ((((byte)cVar3 >> 4 & 1) != 0) &&
           (((~(byte)(cVar3 >> 0xd) ^ ~(byte)(cVar2 >> 0xd)) & 1) != 0)) {
          if ((pcVar8->op == 'd') && (pcVar8->type == g_type_int)) {
            pcVar5 = *(char **)((int)pcVar8->left + 4);
            cVar1 = *pcVar5;
            while (cVar1 < '\0') {
              pcVar5 = *(char **)(pcVar5 + 4);
              cVar1 = *pcVar5;
            }
            if ((pcVar5[1] & 0x20U) != 0) goto LAB_1060db9e;
          }
          if ((left->op == 'd') && (left->type == g_type_int)) {
            pcVar5 = *(char **)((int)left->left + 4);
            cVar1 = *pcVar5;
            while (cVar1 < '\0') {
              pcVar5 = *(char **)(pcVar5 + 4);
              cVar1 = *pcVar5;
            }
            if ((pcVar5[1] & 0x20U) == 0) {
              pcVar8 = expr_warn_signed_unsigned_compare(left,pcVar8,node);
              return pcVar8;
            }
          }
          else {
            diag_warning(3,0x12,uVar6);
          }
        }
      }
    }
LAB_1060db9e:
    expr_check_operand_conversion_unless_null(op,pcVar8,left);
    return node;
  case 0x47:
  case 0x52:
    uVar7 = left->type->code;
    if ((uVar7 & 0x130) == 0) {
      diag_error_C2296_or_C2297(op,2,left->type);
      return (c1_node *)0x0;
    }
    pcVar9 = pcVar8->type;
    uVar4 = pcVar9->code;
    if ((uVar4 & 0x100) == 0) {
      if ((uVar4 & 0x30) == 0) {
        if (((char)pcVar9->code < '\0') &&
           ((uVar11 = pcVar9->code & 0x8f, uVar11 == 0x86 || (uVar11 == 0x82)))) {
          if ((uVar7 & 0x110) != 0) {
            g_constant_value = type_size_checked(pcVar9);
            g_constant_value_high = 0;
            pcVar8 = tree_new_constant(g_type_long,(c1_u32 *)&g_constant_value,g_expr_arena_index);
            pcVar8 = expr_build_binary('J',left,pcVar8);
            node->right = pcVar8;
            return node;
          }
          diag_error(0x72,uVar6);
          return (c1_node *)0x0;
        }
        if (((byte)uVar4 & 0x8f) != 0x86) {
          bVar10 = (byte)pcVar9->code;
          if (-1 < (char)bVar10) {
            return node;
          }
          if ((bVar10 & 0x8f) != 0x84) {
            return node;
          }
        }
        diag_error_C2296_or_C2297(op,1,pcVar9);
        return (c1_node *)0x0;
      }
      goto LAB_1060db9e;
    }
    operand = 1;
LAB_1063bb6d:
    diag_error_C2296_or_C2297(op,operand,pcVar9);
    goto switchD_1060d932_caseD_35;
  }
  if (!bVar12) {
    return node;
  }
switchD_1060d932_caseD_35:
  return (c1_node *)0x0;
}

