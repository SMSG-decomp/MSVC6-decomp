c1_node * __cdecl
fold_float_arithmetic_set_flag_fragment
          (byte left_code,byte right_code,c1_type *left_type,c1_node *right_const,
          c1_node *left_const,char long_result,c1_u8 op,uint left_size,c1_type *right_type,
          uint right_size,int right_hi,c1_node *node,c1_type *result_type)

{
  void *pvVar1;
  void *pvVar2;
  void *a_hi;
  ushort uVar3;
  int iVar4;
  c1_node *pcVar5;
  uint uVar6;
  int iVar7;
  c1_type *pcVar8;
  int iVar9;
  short sVar10;
  int is_unsigned;
  ulonglong uVar11;
  uint uStack00000014;
  uint uStack00000020;
  short sStack00000078;
  
  is_unsigned = 1;
  _sStack00000078 = 1;
  if (left_size < 4) {
    uStack00000014 = 4;
LAB_10415046:
    if (((left_code & 0x1f) == 0x14) || ((right_code & 0x1f) == 0x14)) {
      long_result = '\x01';
    }
    else {
      long_result = '\0';
    }
  }
  else {
    uStack00000014 = left_size;
    if (left_size == 4) goto LAB_10415046;
  }
  uStack00000020 = (uint)op;
  switch(uStack00000020) {
  case 0x32:
  case 0x43:
  case 0x4f:
  case 0x58:
    if (left_size < 5) {
      left_const->left = left_const->left;
      left_const->right = (void *)0x0;
      goto LAB_104150db;
    }
    break;
  default:
    if (((-1 < (char)left_const->type->code) && (-1 < (char)right_const->type->code)) &&
       ((((uVar3 = left_type->code, (uVar3 & 0x2000) == 0 &&
          ((((g_opt_J_unsigned_char == '\0' || (((byte)uVar3 & 0xf) != 1)) ||
            (((uVar3 & 0xfff) == 0x11 && ((uVar3 & 0x1000) != 0)))) &&
           (((int)left_const->right < 1 && ((int)left_const->right < 0)))))) ||
         ((uVar3 = right_type->code, (uVar3 & 0x2000) == 0 &&
          ((((g_opt_J_unsigned_char == '\0' || (((byte)uVar3 & 0xf) != 1)) ||
            (((uVar3 & 0xfff) == 0x11 && ((uVar3 & 0x1000) != 0)))) &&
           (((int)right_const->right < 1 && ((int)right_const->right < 0)))))))) &&
        ((op != '1' && ((op != 'M' && (op != '[')))))))) {
      diag_warning(2,0x134);
    }
LAB_104150db:
    if (left_size < 5) {
      left_const->left = left_const->left;
      left_const->right = (void *)0x0;
    }
  }
  if (right_size < 5) {
    right_const->left = right_const->left;
    right_const->right = (void *)0x0;
  }
  switch(uStack00000020) {
  case 0x31:
    uVar11 = CONCAT44((uint)right_const->right & (uint)left_const->right,
                      (uint)right_const->left & (uint)left_const->left);
    break;
  case 0x32:
    if ((left_const->left == (void *)0x0 && left_const->right == (void *)0x0) ||
       (right_const->left == (void *)0x0 && right_const->right == (void *)0x0)) goto LAB_1046a3ea;
    iVar4 = 1;
    goto LAB_1046a1e1;
  default:
    return node;
  case 0x39:
    if (right_const->left == (void *)0x0 && right_const->right == (void *)0x0) {
      right_const->kind = '@';
      return right_const;
    }
    uVar11 = _aulldiv((uint)left_const->left,(uint)left_const->right,(uint)right_const->left,
                      (uint)right_const->right);
    break;
  case 0x3b:
    if ((left_const->left == right_const->left) && (left_const->right == right_const->right)) {
      iVar4 = 1;
      goto LAB_1046a1e1;
    }
    goto LAB_1046a3ea;
  case 0x3e:
    if ((left_const->right < right_const->right) ||
       ((left_const->right == right_const->right && (left_const->left <= right_const->left)))) {
LAB_1046a1b3:
      iVar4 = 0;
    }
    else {
      iVar4 = 1;
    }
    goto LAB_1046a17f;
  case 0x3f:
    if ((left_const->right < right_const->right) ||
       ((left_const->right == right_const->right && (left_const->left < right_const->left)))) {
      iVar4 = 0;
    }
    else {
      iVar4 = 1;
    }
    uVar11 = (ulonglong)iVar4;
    result_type = g_type_int;
    is_unsigned = 0;
    break;
  case 0x43:
    uVar11 = _allshl((byte)right_const->left,(uint)left_const->left,(uint)left_const->right);
    result_type = node->type;
    break;
  case 0x44:
    if ((right_const->right < left_const->right) ||
       ((right_const->right <= left_const->right && (right_const->left <= left_const->left))))
    goto LAB_1046a1b3;
    iVar4 = 1;
LAB_1046a17f:
    uVar11 = (ulonglong)iVar4;
    result_type = g_type_int;
    is_unsigned = 0;
    break;
  case 0x45:
    if ((left_const->right <= right_const->right) &&
       ((left_const->right < right_const->right || (left_const->left <= right_const->left)))) {
      iVar4 = 1;
      goto LAB_1046a1e1;
    }
    goto LAB_1046a3ea;
  case 0x46:
    pvVar1 = left_const->left;
    pvVar2 = right_const->left;
    uVar11 = CONCAT44((int)left_const->right + (-(uint)(pvVar1 < pvVar2) - (int)right_const->right),
                      (int)pvVar1 - (int)pvVar2);
    uVar6 = fold_check_subtract_overflow
                      ((uint)pvVar1,(int)left_const->right,(uint)pvVar2,(int)right_const->right,
                       (int)sStack00000078,uStack00000014);
    goto LAB_104152cc;
  case 0x48:
    if (right_const->left == (void *)0x0 && right_const->right == (void *)0x0) {
      right_const->kind = '@';
      return right_const;
    }
    uVar11 = _aullrem((uint)left_const->left,(uint)left_const->right,(uint)right_const->left,
                      (uint)right_const->right);
    break;
  case 0x4a:
    pvVar1 = left_const->left;
    pvVar2 = right_const->left;
    a_hi = right_const->right;
    uVar11 = _allmul((uint)pvVar2,(int)a_hi,(uint)pvVar1,(int)left_const->right);
    uVar6 = fold_check_multiply_overflow
                      ((uint)pvVar1,(int)left_const->right,(uint)pvVar2,(int)a_hi,
                       (int)sStack00000078,uStack00000014);
LAB_104152cc:
    is_unsigned = _sStack00000078;
    if (uVar6 != 0) {
LAB_1046a2d7:
      diag_warning(2,0x133,uStack00000020);
      is_unsigned = _sStack00000078;
    }
    break;
  case 0x4c:
    if ((left_const->left != right_const->left) || (left_const->right != right_const->right)) {
LAB_1046a393:
      iVar4 = 1;
      goto LAB_1046a1e1;
    }
    goto LAB_1046a3ea;
  case 0x4d:
    uVar11 = CONCAT44((uint)right_const->right | (uint)left_const->right,
                      (uint)right_const->left | (uint)left_const->left);
    break;
  case 0x4f:
    if ((left_const->left != (void *)0x0 || left_const->right != (void *)0x0) ||
       (right_const->left != (void *)0x0 || right_const->right != (void *)0x0)) goto LAB_1046a393;
LAB_1046a3ea:
    iVar4 = 0;
LAB_1046a1e1:
    uVar11 = (ulonglong)iVar4;
    result_type = g_type_int;
    is_unsigned = 0;
    break;
  case 0x51:
  case 0x53:
    pvVar1 = right_const->left;
    pvVar2 = left_const->left;
    uVar11 = CONCAT44((int)right_const->right + (int)left_const->right +
                      (uint)CARRY4((uint)pvVar1,(uint)pvVar2),(int)pvVar1 + (int)pvVar2);
    iVar4 = fold_add_overflows((uint)pvVar2,(int)left_const->right,(uint)pvVar1,
                               (int)right_const->right,1,uStack00000014);
    is_unsigned = _sStack00000078;
    if (iVar4 == 0) break;
    goto LAB_1046a2d7;
  case 0x58:
    uVar11 = _aullshr((byte)right_const->left,(uint)left_const->right,(uint)left_const->left);
    result_type = node->type;
    break;
  case 0x5b:
    uVar11 = CONCAT44((uint)right_const->right ^ (uint)left_const->right,
                      (uint)right_const->left ^ (uint)left_const->left);
  }
  iVar4 = (int)uVar11;
  if ((((op == 'Q') || (op == 'F')) && (uVar3 = node->type->code, (char)uVar3 < '\0')) &&
     ((uVar3 = uVar3 & 0x8f, uVar3 == 0x86 || (uVar3 == 0x82)))) {
    left_const->left = (void *)(int)uVar11;
    left_const->right = (void *)(int)(uVar11 >> 0x20);
    return left_const;
  }
  uVar6 = uStack00000014;
  if (result_type != (c1_type *)0x0) {
    uVar6 = type_size_scalar(result_type);
  }
  sVar10 = (short)is_unsigned;
  if (uVar6 == 8) {
    pcVar8 = g_type_uint64;
    if (sVar10 == 0) {
      g_constant_value = iVar4;
      g_constant_value_high = (int)(uVar11 >> 0x20);
      pcVar5 = fold_binary_constants_tail(g_type_int64);
      return pcVar5;
    }
  }
  else {
    if (sVar10 == 0) {
      iVar9 = iVar4 >> 0x1f;
    }
    else {
      iVar9 = 0;
    }
    if (result_type == (c1_type *)0x0) {
      if (long_result == '\0') {
LAB_10415264:
        pcVar8 = g_type_unsigned_int;
        if (sVar10 == 0) {
          pcVar8 = g_type_int;
        }
        g_constant_value = iVar4;
        g_constant_value_high = iVar9;
        pcVar5 = tree_new_constant(pcVar8,&g_constant_value,g_expr_arena_index);
        return pcVar5;
      }
    }
    else {
      iVar7 = type_size_scalar(result_type);
      if ((iVar7 != 4) || ((result_type->code & 0x1f) == 0x14)) goto LAB_10415264;
    }
    pcVar8 = g_type_unsigned_long;
    uVar11 = CONCAT44(iVar9,iVar4);
    if (sVar10 == 0) {
      pcVar8 = g_type_long;
      uVar11 = CONCAT44(iVar9,iVar4);
    }
  }
  g_constant_value_high = (int)(uVar11 >> 0x20);
  g_constant_value = (int)uVar11;
  pcVar5 = tree_new_constant(pcVar8,&g_constant_value,g_expr_arena_index);
  return pcVar5;
}

