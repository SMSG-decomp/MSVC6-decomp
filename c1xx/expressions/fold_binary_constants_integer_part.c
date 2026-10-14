c1_node * __cdecl
fold_binary_constants_integer_part
          (uint op_index,int is_unsigned,c1_node *left_const,c1_node *right_const,char long_result,
          uint size,c1_u8 op,uint left_size,uint op_word,uint right_size,int right_hi,c1_node *node,
          c1_type *result_type,int is_unsigned_copy)

{
  void *pvVar1;
  void *a_hi;
  ushort uVar2;
  int iVar3;
  c1_node *pcVar4;
  uint uVar5;
  int iVar6;
  c1_type *pcVar7;
  byte count;
  void *pvVar8;
  int iVar9;
  short sVar10;
  ulonglong uVar11;
  
  sVar10 = (short)is_unsigned;
  if (left_size < 5) {
    pvVar8 = left_const->left;
    if (sVar10 == 0) {
      left_const->left = pvVar8;
      left_const->right = (void *)((int)pvVar8 >> 0x1f);
    }
    else {
      left_const->left = pvVar8;
      left_const->right = (void *)0x0;
    }
    if (left_size < 5) {
      if (sVar10 == 0) {
        pvVar8 = (void *)((int)left_const->left >> 0x1f);
      }
      else {
        pvVar8 = (void *)0x0;
      }
      left_const->left = left_const->left;
      left_const->right = pvVar8;
    }
  }
  if (right_size < 5) {
    if (sVar10 == 0) {
      pvVar8 = (void *)((int)right_const->left >> 0x1f);
    }
    else {
      pvVar8 = (void *)0x0;
    }
    right_const->left = right_const->left;
    right_const->right = pvVar8;
  }
  switch(op_index) {
  case 0x31:
    uVar11 = CONCAT44((uint)right_const->right & (uint)left_const->right,
                      (uint)right_const->left & (uint)left_const->left);
    is_unsigned_copy._0_2_ = sVar10;
    break;
  case 0x32:
    if ((left_const->left == (void *)0x0 && left_const->right == (void *)0x0) ||
       (right_const->left == (void *)0x0 && right_const->right == (void *)0x0)) goto LAB_1046a3ea;
    iVar3 = 1;
    goto LAB_1046a1e1;
  default:
    return node;
  case 0x39:
    pvVar8 = right_const->left;
    pvVar1 = right_const->right;
    if (pvVar8 == (void *)0x0 && pvVar1 == (void *)0x0) {
      right_const->kind = '@';
      return right_const;
    }
    if (sVar10 == 0) {
      uVar11 = _alldiv((uint)left_const->left,(int)left_const->right,(uint)pvVar8,(int)pvVar1);
      is_unsigned_copy._0_2_ = sVar10;
    }
    else {
      uVar11 = _aulldiv((uint)left_const->left,(uint)left_const->right,(uint)pvVar8,(uint)pvVar1);
      is_unsigned_copy._0_2_ = sVar10;
    }
    break;
  case 0x3b:
    if ((left_const->left != right_const->left) || (left_const->right != right_const->right))
    goto LAB_1046a3ea;
    iVar3 = 1;
    goto LAB_1046a1e1;
  case 0x3e:
    if (sVar10 == 0) {
      if (((int)left_const->right < (int)right_const->right) ||
         (((int)left_const->right <= (int)right_const->right &&
          (left_const->left <= right_const->left)))) goto LAB_1046a1b3;
      iVar3 = 1;
    }
    else if ((left_const->right < right_const->right) ||
            ((left_const->right == right_const->right && (left_const->left <= right_const->left))))
    {
LAB_1046a1b3:
      iVar3 = 0;
    }
    else {
      iVar3 = 1;
    }
    goto LAB_1046a17f;
  case 0x3f:
    if (sVar10 == 0) {
      if (((int)left_const->right < (int)right_const->right) ||
         (((int)left_const->right <= (int)right_const->right &&
          (left_const->left < right_const->left)))) goto LAB_1046a275;
      iVar3 = 1;
    }
    else if ((left_const->right < right_const->right) ||
            ((left_const->right == right_const->right && (left_const->left < right_const->left)))) {
LAB_1046a275:
      iVar3 = 0;
    }
    else {
      iVar3 = 1;
    }
    uVar11 = (ulonglong)iVar3;
    result_type = g_type_int;
    is_unsigned_copy._0_2_ = 0;
    break;
  case 0x43:
    uVar11 = _allshl((byte)right_const->left,(uint)left_const->left,(uint)left_const->right);
    result_type = node->type;
    is_unsigned_copy._0_2_ = sVar10;
    break;
  case 0x44:
    if (sVar10 == 0) {
      if (((int)right_const->right < (int)left_const->right) ||
         (((int)right_const->right <= (int)left_const->right &&
          (right_const->left <= left_const->left)))) goto LAB_1046a1b3;
      iVar3 = 1;
    }
    else {
      if ((right_const->right < left_const->right) ||
         ((right_const->right <= left_const->right && (right_const->left <= left_const->left))))
      goto LAB_1046a1b3;
      iVar3 = 1;
    }
LAB_1046a17f:
    uVar11 = (ulonglong)iVar3;
    result_type = g_type_int;
    is_unsigned_copy._0_2_ = 0;
    break;
  case 0x45:
    if (sVar10 == 0) {
      if (((int)right_const->right < (int)left_const->right) ||
         (((int)right_const->right <= (int)left_const->right &&
          (right_const->left < left_const->left)))) goto LAB_1046a3ea;
      iVar3 = 1;
    }
    else {
      if ((right_const->right < left_const->right) ||
         ((right_const->right <= left_const->right && (right_const->left < left_const->left))))
      goto LAB_1046a3ea;
      iVar3 = 1;
    }
    goto LAB_1046a1e1;
  case 0x46:
    pvVar8 = left_const->left;
    pvVar1 = right_const->left;
    uVar11 = CONCAT44((int)left_const->right + (-(uint)(pvVar8 < pvVar1) - (int)right_const->right),
                      (int)pvVar8 - (int)pvVar1);
    uVar5 = fold_check_subtract_overflow
                      ((uint)pvVar8,(int)left_const->right,(uint)pvVar1,(int)right_const->right,
                       (int)(short)is_unsigned_copy,size);
    goto LAB_104152cc;
  case 0x48:
    pvVar8 = right_const->left;
    pvVar1 = right_const->right;
    if (pvVar8 == (void *)0x0 && pvVar1 == (void *)0x0) {
      right_const->kind = '@';
      return right_const;
    }
    if (sVar10 == 0) {
      uVar11 = _allrem((uint)left_const->left,(int)left_const->right,(uint)pvVar8,(int)pvVar1);
      is_unsigned_copy._0_2_ = sVar10;
    }
    else {
      uVar11 = _aullrem((uint)left_const->left,(uint)left_const->right,(uint)pvVar8,(uint)pvVar1);
      is_unsigned_copy._0_2_ = sVar10;
    }
    break;
  case 0x4a:
    pvVar8 = left_const->left;
    pvVar1 = right_const->left;
    a_hi = right_const->right;
    uVar11 = _allmul((uint)pvVar1,(int)a_hi,(uint)pvVar8,(int)left_const->right);
    uVar5 = fold_check_multiply_overflow
                      ((uint)pvVar8,(int)left_const->right,(uint)pvVar1,(int)a_hi,
                       (int)(short)is_unsigned_copy,size);
LAB_104152cc:
    if (uVar5 != 0) {
LAB_1046a2d7:
      diag_warning(2,0x133,op_word);
    }
    break;
  case 0x4c:
    if ((left_const->left == right_const->left) && (left_const->right == right_const->right))
    goto LAB_1046a3ea;
LAB_1046a393:
    iVar3 = 1;
    goto LAB_1046a1e1;
  case 0x4d:
    uVar11 = CONCAT44((uint)right_const->right | (uint)left_const->right,
                      (uint)right_const->left | (uint)left_const->left);
    is_unsigned_copy._0_2_ = sVar10;
    break;
  case 0x4f:
    if ((left_const->left != (void *)0x0 || left_const->right != (void *)0x0) ||
       (right_const->left != (void *)0x0 || right_const->right != (void *)0x0)) goto LAB_1046a393;
LAB_1046a3ea:
    iVar3 = 0;
LAB_1046a1e1:
    uVar11 = (ulonglong)iVar3;
    result_type = g_type_int;
    is_unsigned_copy._0_2_ = 0;
    break;
  case 0x51:
  case 0x53:
    pvVar8 = right_const->left;
    pvVar1 = left_const->left;
    uVar11 = CONCAT44((int)right_const->right + (int)left_const->right +
                      (uint)CARRY4((uint)pvVar8,(uint)pvVar1),(int)pvVar8 + (int)pvVar1);
    iVar3 = fold_add_overflows((uint)pvVar1,(int)left_const->right,(uint)pvVar8,
                               (int)right_const->right,(int)sVar10,size);
    if (iVar3 == 0) break;
    goto LAB_1046a2d7;
  case 0x58:
    count = (byte)right_const->left;
    if (sVar10 == 0) {
      uVar11 = _allshr(count,(int)left_const->right,(uint)left_const->left);
      result_type = node->type;
      is_unsigned_copy._0_2_ = sVar10;
    }
    else {
      uVar11 = _aullshr(count,(uint)left_const->right,(uint)left_const->left);
      result_type = node->type;
      is_unsigned_copy._0_2_ = sVar10;
    }
    break;
  case 0x5b:
    uVar11 = CONCAT44((uint)right_const->right ^ (uint)left_const->right,
                      (uint)right_const->left ^ (uint)left_const->left);
    is_unsigned_copy._0_2_ = sVar10;
  }
  iVar3 = (int)uVar11;
  if ((((op == 'Q') || (op == 'F')) && (uVar2 = node->type->code, (char)uVar2 < '\0')) &&
     ((uVar2 = uVar2 & 0x8f, uVar2 == 0x86 || (uVar2 == 0x82)))) {
    left_const->left = (void *)(int)uVar11;
    left_const->right = (void *)(int)(uVar11 >> 0x20);
    return left_const;
  }
  if (result_type != (c1_type *)0x0) {
    size = type_size_scalar(result_type);
  }
  if (size == 8) {
    pcVar7 = g_type_uint64;
    if ((short)is_unsigned_copy == 0) {
      g_constant_value = iVar3;
      g_constant_value_high = (int)(uVar11 >> 0x20);
      pcVar4 = fold_binary_constants_tail(g_type_int64);
      return pcVar4;
    }
  }
  else {
    if ((short)is_unsigned_copy == 0) {
      iVar9 = iVar3 >> 0x1f;
    }
    else {
      iVar9 = 0;
    }
    if (result_type == (c1_type *)0x0) {
      if (long_result == '\0') {
LAB_10415264:
        pcVar7 = g_type_unsigned_int;
        if ((short)is_unsigned_copy == 0) {
          pcVar7 = g_type_int;
        }
        g_constant_value = iVar3;
        g_constant_value_high = iVar9;
        pcVar4 = tree_new_constant(pcVar7,&g_constant_value,g_expr_arena_index);
        return pcVar4;
      }
    }
    else {
      iVar6 = type_size_scalar(result_type);
      if ((iVar6 != 4) || ((result_type->code & 0x1f) == 0x14)) goto LAB_10415264;
    }
    pcVar7 = g_type_unsigned_long;
    uVar11 = CONCAT44(iVar9,iVar3);
    if ((short)is_unsigned_copy == 0) {
      pcVar7 = g_type_long;
      uVar11 = CONCAT44(iVar9,iVar3);
    }
  }
  g_constant_value_high = (int)(uVar11 >> 0x20);
  g_constant_value = (int)uVar11;
  pcVar4 = tree_new_constant(pcVar7,&g_constant_value,g_expr_arena_index);
  return pcVar4;
}

