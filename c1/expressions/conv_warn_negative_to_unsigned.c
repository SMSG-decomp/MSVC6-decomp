c1_node * __cdecl
conv_warn_negative_to_unsigned
          (uint op,int is_unsigned,c1_node *right,c1_node *left,char long_operand,char op_char,
          uint left_size,uint op_saved,uint right_size,c1_node *node,c1_type *result_type,uint size)

{
  c1_u16 cVar1;
  void *pvVar2;
  uint uVar3;
  c1_node *pcVar4;
  int iVar5;
  c1_type *pcVar6;
  byte count;
  void *pvVar7;
  int iVar8;
  short sVar9;
  bool bVar10;
  uint64_t uVar11;
  void *in_stack_00000028;
  
  if (((op_char != '1') && (op_char != 'M')) && (op_char != '[')) {
    diag_warning(2,0x134);
    op = op_saved;
  }
  sVar9 = (short)is_unsigned;
  if (left_size < 5) {
    if (sVar9 == 0) {
      pvVar7 = (void *)((int)left->left >> 0x1f);
    }
    else {
      pvVar7 = (void *)0x0;
    }
    left->left = left->left;
    left->right = pvVar7;
  }
  if (right_size < 5) {
    if (sVar9 == 0) {
      pvVar7 = (void *)((int)right->left >> 0x1f);
    }
    else {
      pvVar7 = (void *)0x0;
    }
    right->left = right->left;
    right->right = pvVar7;
  }
  switch(op) {
  case 0x31:
    uVar11 = CONCAT44((uint)right->right & (uint)left->right,(uint)right->left & (uint)left->left);
    break;
  case 0x32:
    if (left->left != (void *)0x0 || left->right != (void *)0x0) {
      bVar10 = right->left == (void *)0x0 && right->right == (void *)0x0;
LAB_1060d341:
      if (!bVar10) goto LAB_1060d343;
    }
    goto LAB_1060d369;
  default:
    return node;
  case 0x39:
    pvVar7 = right->left;
    pvVar2 = right->right;
    if (pvVar7 == (void *)0x0 && pvVar2 == (void *)0x0) {
      right->kind = '@';
      return right;
    }
    if (sVar9 == 0) {
      uVar11 = _alldiv((uint32_t)left->left,(uint32_t)left->right,(uint32_t)pvVar7,(uint32_t)pvVar2)
      ;
    }
    else {
      uVar11 = _aulldiv((uint32_t)left->left,(uint32_t)left->right,(uint32_t)pvVar7,(uint32_t)pvVar2
                       );
    }
    break;
  case 0x3b:
    if ((left->left != right->left) || (left->right != right->right)) goto LAB_1060d369;
    iVar8 = 1;
    goto LAB_1060d36b;
  case 0x3e:
    if (sVar9 == 0) {
      if ((int)right->right <= (int)left->right) {
        if ((int)right->right < (int)left->right) goto LAB_1060d343;
        if (right->left < left->left) {
          iVar8 = 1;
          goto LAB_1060d36b;
        }
      }
    }
    else if ((right->right <= left->right) &&
            ((left->right != right->right || (right->left < left->left)))) {
      iVar8 = 1;
      goto LAB_1060d36b;
    }
    goto LAB_1060d369;
  case 0x3f:
    if (sVar9 == 0) {
      if (((int)left->right < (int)right->right) ||
         (((int)left->right <= (int)right->right && (left->left < right->left)))) {
LAB_106328d2:
        iVar8 = 0;
      }
      else {
        iVar8 = 1;
      }
    }
    else {
      if ((left->right < right->right) ||
         ((left->right == right->right && (left->left < right->left)))) goto LAB_106328d2;
      iVar8 = 1;
    }
    is_unsigned = 0;
    uVar11 = (uint64_t)iVar8;
    result_type = g_type_int;
    break;
  case 0x43:
    uVar11 = _allshl((byte)right->left,(uint)left->left,(uint)left->right);
    result_type = node->type;
    break;
  case 0x44:
    if (sVar9 == 0) {
      if (((int)left->right <= (int)right->right) &&
         (((int)left->right < (int)right->right || (left->left < right->left)))) {
        iVar8 = 1;
        goto LAB_1060d36b;
      }
    }
    else if ((left->right <= right->right) &&
            ((left->right < right->right || (left->left < right->left)))) goto LAB_1063289e;
LAB_1060d369:
    iVar8 = 0;
    goto LAB_1060d36b;
  case 0x45:
    if (sVar9 == 0) {
      if (((int)right->right < (int)left->right) ||
         (((int)right->right <= (int)left->right && (right->left < left->left)))) {
LAB_1060d0be:
        iVar8 = 0;
      }
      else {
        iVar8 = 1;
      }
    }
    else {
      if ((right->right < left->right) ||
         ((right->right <= left->right && (right->left < left->left)))) goto LAB_1060d0be;
      iVar8 = 1;
    }
    uVar11 = (uint64_t)iVar8;
    result_type = g_type_int;
    is_unsigned = 0;
    break;
  case 0x46:
    in_stack_00000028 = right->right;
    pvVar7 = left->left;
    pvVar2 = right->left;
    uVar11 = CONCAT44((int)left->right + (-(uint)(pvVar7 < pvVar2) - (int)in_stack_00000028),
                      (int)pvVar7 - (int)pvVar2);
    uVar3 = fold_check_subtract_overflow
                      ((uint)pvVar7,(int)left->right,(uint)pvVar2,(int)in_stack_00000028,(int)sVar9,
                       size);
    goto LAB_1060d248;
  case 0x48:
    pvVar7 = right->left;
    pvVar2 = right->right;
    if (pvVar7 == (void *)0x0 && pvVar2 == (void *)0x0) {
      right->kind = '@';
      return right;
    }
    if (sVar9 == 0) {
      uVar11 = _allrem((uint32_t)left->left,(int32_t)left->right,(uint32_t)pvVar7,(int32_t)pvVar2);
    }
    else {
      uVar11 = _aullrem((uint32_t)left->left,(uint32_t)left->right,(uint32_t)pvVar7,(uint32_t)pvVar2
                       );
    }
    break;
  case 0x4a:
    pvVar7 = right->left;
    in_stack_00000028 = right->right;
    uVar11 = _allmul((uint)pvVar7,(int)in_stack_00000028,(uint)left->left,(int)left->right);
    uVar3 = fold_check_multiply_overflow
                      ((uint)left->left,(int)left->right,(uint)pvVar7,(int)in_stack_00000028,
                       (int)sVar9,size);
    goto LAB_1060d248;
  case 0x4c:
    if (left->left == right->left) {
      bVar10 = left->right == right->right;
      goto LAB_1060d341;
    }
LAB_1060d343:
    iVar8 = 1;
    goto LAB_1060d36b;
  case 0x4d:
    uVar11 = CONCAT44((uint)right->right | (uint)left->right,(uint)right->left | (uint)left->left);
    break;
  case 0x4f:
    if ((left->left == (void *)0x0 && left->right == (void *)0x0) &&
       (right->left == (void *)0x0 && right->right == (void *)0x0)) goto LAB_1060d369;
LAB_1063289e:
    iVar8 = 1;
LAB_1060d36b:
    uVar11 = (uint64_t)iVar8;
    result_type = g_type_int;
    is_unsigned = 0;
    break;
  case 0x51:
  case 0x53:
    pvVar7 = right->left;
    in_stack_00000028 = right->right;
    pvVar2 = left->left;
    uVar11 = CONCAT44((int)in_stack_00000028 + (int)left->right +
                      (uint)CARRY4((uint)pvVar7,(uint)pvVar2),(int)pvVar7 + (int)pvVar2);
    uVar3 = fold_add_overflows((uint)pvVar2,(int)left->right,(uint)pvVar7,(int)in_stack_00000028,
                               (int)sVar9,size);
LAB_1060d248:
    if (uVar3 != 0) {
      pcVar4 = fold_integer_overflow_fragment
                         (is_unsigned,(int)(uVar11 >> 0x20),(uint)uVar11,long_operand,op_char,node,
                          result_type,size);
      return pcVar4;
    }
    break;
  case 0x58:
    count = (byte)right->left;
    if (sVar9 == 0) {
      uVar11 = _allshr(count,(int)left->right,(uint)left->left);
      result_type = node->type;
    }
    else {
      uVar11 = _aullshr(count,(uint)left->right,(uint)left->left);
      result_type = node->type;
    }
    break;
  case 0x5b:
    uVar11 = CONCAT44((uint)right->right ^ (uint)left->right,(uint)right->left ^ (uint)left->left);
  }
  uVar3 = (uint)uVar11;
  if (((op_char == 'Q') || (op_char == 'F')) && (cVar1 = node->type->code, (char)cVar1 < '\0')) {
    pcVar4 = fold_binary_constant_expression_fragment
                       (CONCAT22((short)((uint)node->type >> 0x10),cVar1),is_unsigned,
                        (int)(uVar11 >> 0x20),uVar3,left,long_operand,result_type,size);
    return pcVar4;
  }
  if (result_type != (c1_type *)0x0) {
    size = type_size_scalar(result_type);
  }
  sVar9 = (short)is_unsigned;
  if (size == 8) {
    pcVar6 = g_type_uint64;
    if (sVar9 == 0) {
      pcVar6 = g_type_int64;
    }
  }
  else {
    if (sVar9 == 0) {
      iVar8 = (int)uVar3 >> 0x1f;
    }
    else {
      iVar8 = 0;
    }
    if (result_type == (c1_type *)0x0) {
      if (long_operand == '\0') {
LAB_1060d2f4:
        pcVar6 = g_type_unsigned_int;
        if (sVar9 == 0) {
          pcVar6 = g_type_int;
        }
        g_constant_value = uVar3;
        g_constant_value_high = iVar8;
        pcVar4 = tree_new_constant(pcVar6,&g_constant_value,g_expr_arena_index);
        return pcVar4;
      }
    }
    else {
      iVar5 = type_size_scalar(result_type);
      if ((iVar5 != 4) || ((result_type->code & 0x1f) == 0x14)) goto LAB_1060d2f4;
    }
    pcVar6 = g_type_unsigned_long;
    uVar11 = CONCAT44(iVar8,uVar3);
    if (sVar9 == 0) {
      pcVar6 = g_type_long;
      uVar11 = CONCAT44(iVar8,uVar3);
    }
  }
  g_constant_value_high = (int)(uVar11 >> 0x20);
  g_constant_value = (uint)uVar11;
  pcVar4 = tree_new_constant(pcVar6,&g_constant_value,g_expr_arena_index);
  return pcVar4;
}

