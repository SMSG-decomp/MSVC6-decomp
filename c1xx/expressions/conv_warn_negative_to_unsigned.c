c1_node * __thiscall conv_warn_negative_to_unsigned(void *this,undefined4 ebx,c1_node *node)

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
  c1_node *unaff_EBP;
  ulonglong uVar10;
  char in_stack_00000013;
  uint in_stack_00000014;
  char in_stack_00000018;
  uint in_stack_0000001c;
  void *in_stack_00000020;
  uint in_stack_00000028;
  c1_node *in_stack_00000070;
  c1_type *in_stack_00000074;
  short in_stack_00000078;
  
  if (((in_stack_00000018 != '1') && (in_stack_00000018 != 'M')) && (in_stack_00000018 != '[')) {
    diag_warning(2,0x134);
    this = in_stack_00000020;
  }
  if (in_stack_0000001c < 5) {
    if ((short)ebx == 0) {
      pvVar8 = (void *)((int)unaff_EBP->left >> 0x1f);
    }
    else {
      pvVar8 = (void *)0x0;
    }
    unaff_EBP->left = unaff_EBP->left;
    unaff_EBP->right = pvVar8;
  }
  if (in_stack_00000028 < 5) {
    if ((short)ebx == 0) {
      pvVar8 = (void *)((int)node->left >> 0x1f);
    }
    else {
      pvVar8 = (void *)0x0;
    }
    node->left = node->left;
    node->right = pvVar8;
  }
  switch(this) {
  case (void *)0x31:
    uVar10 = CONCAT44((uint)node->right & (uint)unaff_EBP->right,
                      (uint)node->left & (uint)unaff_EBP->left);
    break;
  case (void *)0x32:
    if ((unaff_EBP->left == (void *)0x0 && unaff_EBP->right == (void *)0x0) ||
       (node->left == (void *)0x0 && node->right == (void *)0x0)) goto LAB_1046a3ea;
    iVar3 = 1;
    goto LAB_1046a1e1;
  default:
    return in_stack_00000070;
  case (void *)0x39:
    pvVar8 = node->left;
    pvVar1 = node->right;
    if (pvVar8 == (void *)0x0 && pvVar1 == (void *)0x0) {
      node->kind = '@';
      return node;
    }
    if ((short)ebx == 0) {
      uVar10 = _alldiv((uint)unaff_EBP->left,(int)unaff_EBP->right,(uint)pvVar8,(int)pvVar1);
    }
    else {
      uVar10 = _aulldiv((uint)unaff_EBP->left,(uint)unaff_EBP->right,(uint)pvVar8,(uint)pvVar1);
    }
    break;
  case (void *)0x3b:
    if ((unaff_EBP->left != node->left) || (unaff_EBP->right != node->right)) goto LAB_1046a3ea;
    iVar3 = 1;
    goto LAB_1046a1e1;
  case (void *)0x3e:
    if ((short)ebx == 0) {
      if (((int)unaff_EBP->right < (int)node->right) ||
         (((int)unaff_EBP->right <= (int)node->right && (unaff_EBP->left <= node->left))))
      goto LAB_1046a1b3;
      iVar3 = 1;
    }
    else if ((unaff_EBP->right < node->right) ||
            ((unaff_EBP->right == node->right && (unaff_EBP->left <= node->left)))) {
LAB_1046a1b3:
      iVar3 = 0;
    }
    else {
      iVar3 = 1;
    }
    goto LAB_1046a17f;
  case (void *)0x3f:
    if ((short)ebx == 0) {
      if (((int)unaff_EBP->right < (int)node->right) ||
         (((int)unaff_EBP->right <= (int)node->right && (unaff_EBP->left < node->left))))
      goto LAB_1046a275;
      iVar3 = 1;
    }
    else if ((unaff_EBP->right < node->right) ||
            ((unaff_EBP->right == node->right && (unaff_EBP->left < node->left)))) {
LAB_1046a275:
      iVar3 = 0;
    }
    else {
      iVar3 = 1;
    }
    ebx._0_2_ = 0;
    uVar10 = (ulonglong)iVar3;
    in_stack_00000074 = g_type_int;
    break;
  case (void *)0x43:
    uVar10 = _allshl((byte)node->left,(uint)unaff_EBP->left,(uint)unaff_EBP->right);
    in_stack_00000074 = in_stack_00000070->type;
    break;
  case (void *)0x44:
    if ((short)ebx == 0) {
      if (((int)node->right < (int)unaff_EBP->right) ||
         (((int)node->right <= (int)unaff_EBP->right && (node->left <= unaff_EBP->left))))
      goto LAB_1046a1b3;
      iVar3 = 1;
    }
    else {
      if ((node->right < unaff_EBP->right) ||
         ((node->right <= unaff_EBP->right && (node->left <= unaff_EBP->left)))) goto LAB_1046a1b3;
      iVar3 = 1;
    }
LAB_1046a17f:
    uVar10 = (ulonglong)iVar3;
    in_stack_00000074 = g_type_int;
    ebx._0_2_ = 0;
    break;
  case (void *)0x45:
    if ((short)ebx == 0) {
      if (((int)node->right < (int)unaff_EBP->right) ||
         (((int)node->right <= (int)unaff_EBP->right && (node->left < unaff_EBP->left))))
      goto LAB_1046a3ea;
      iVar3 = 1;
    }
    else {
      if ((node->right < unaff_EBP->right) ||
         ((node->right <= unaff_EBP->right && (node->left < unaff_EBP->left)))) goto LAB_1046a3ea;
      iVar3 = 1;
    }
    goto LAB_1046a1e1;
  case (void *)0x46:
    pvVar8 = unaff_EBP->left;
    pvVar1 = node->left;
    uVar10 = CONCAT44((int)unaff_EBP->right + (-(uint)(pvVar8 < pvVar1) - (int)node->right),
                      (int)pvVar8 - (int)pvVar1);
    uVar5 = fold_check_subtract_overflow
                      ((uint)pvVar8,(int)unaff_EBP->right,(uint)pvVar1,(int)node->right,
                       (int)in_stack_00000078,in_stack_00000014);
    goto LAB_104152cc;
  case (void *)0x48:
    pvVar8 = node->left;
    pvVar1 = node->right;
    if (pvVar8 == (void *)0x0 && pvVar1 == (void *)0x0) {
      node->kind = '@';
      return node;
    }
    if ((short)ebx == 0) {
      uVar10 = _allrem((uint)unaff_EBP->left,(int)unaff_EBP->right,(uint)pvVar8,(int)pvVar1);
    }
    else {
      uVar10 = _aullrem((uint)unaff_EBP->left,(uint)unaff_EBP->right,(uint)pvVar8,(uint)pvVar1);
    }
    break;
  case (void *)0x4a:
    pvVar8 = unaff_EBP->left;
    pvVar1 = node->left;
    a_hi = node->right;
    uVar10 = _allmul((uint)pvVar1,(int)a_hi,(uint)pvVar8,(int)unaff_EBP->right);
    uVar5 = fold_check_multiply_overflow
                      ((uint)pvVar8,(int)unaff_EBP->right,(uint)pvVar1,(int)a_hi,
                       (int)in_stack_00000078,in_stack_00000014);
LAB_104152cc:
    ebx._0_2_ = in_stack_00000078;
    if (uVar5 != 0) {
LAB_1046a2d7:
      diag_warning(2,0x133,in_stack_00000020);
      ebx._0_2_ = in_stack_00000078;
    }
    break;
  case (void *)0x4c:
    if ((unaff_EBP->left == node->left) && (unaff_EBP->right == node->right)) goto LAB_1046a3ea;
LAB_1046a393:
    iVar3 = 1;
    goto LAB_1046a1e1;
  case (void *)0x4d:
    uVar10 = CONCAT44((uint)node->right | (uint)unaff_EBP->right,
                      (uint)node->left | (uint)unaff_EBP->left);
    break;
  case (void *)0x4f:
    if ((unaff_EBP->left != (void *)0x0 || unaff_EBP->right != (void *)0x0) ||
       (node->left != (void *)0x0 || node->right != (void *)0x0)) goto LAB_1046a393;
LAB_1046a3ea:
    iVar3 = 0;
LAB_1046a1e1:
    uVar10 = (ulonglong)iVar3;
    in_stack_00000074 = g_type_int;
    ebx._0_2_ = 0;
    break;
  case (void *)0x51:
  case (void *)0x53:
    pvVar8 = node->left;
    pvVar1 = unaff_EBP->left;
    uVar10 = CONCAT44((int)node->right + (int)unaff_EBP->right +
                      (uint)CARRY4((uint)pvVar8,(uint)pvVar1),(int)pvVar8 + (int)pvVar1);
    iVar3 = fold_add_overflows((uint)pvVar1,(int)unaff_EBP->right,(uint)pvVar8,(int)node->right,
                               (int)(short)ebx,in_stack_00000014);
    ebx._0_2_ = in_stack_00000078;
    if (iVar3 == 0) break;
    goto LAB_1046a2d7;
  case (void *)0x58:
    count = (byte)node->left;
    if ((short)ebx == 0) {
      uVar10 = _allshr(count,(int)unaff_EBP->right,(uint)unaff_EBP->left);
      in_stack_00000074 = in_stack_00000070->type;
    }
    else {
      uVar10 = _aullshr(count,(uint)unaff_EBP->right,(uint)unaff_EBP->left);
      in_stack_00000074 = in_stack_00000070->type;
    }
    break;
  case (void *)0x5b:
    uVar10 = CONCAT44((uint)node->right ^ (uint)unaff_EBP->right,
                      (uint)node->left ^ (uint)unaff_EBP->left);
  }
  iVar3 = (int)uVar10;
  if ((((in_stack_00000018 == 'Q') || (in_stack_00000018 == 'F')) &&
      (uVar2 = in_stack_00000070->type->code, (char)uVar2 < '\0')) &&
     ((uVar2 = uVar2 & 0x8f, uVar2 == 0x86 || (uVar2 == 0x82)))) {
    unaff_EBP->left = (void *)(int)uVar10;
    unaff_EBP->right = (void *)(int)(uVar10 >> 0x20);
    return unaff_EBP;
  }
  if (in_stack_00000074 != (c1_type *)0x0) {
    in_stack_00000014 = type_size_scalar(in_stack_00000074);
  }
  if (in_stack_00000014 == 8) {
    pcVar7 = g_type_uint64;
    if ((short)ebx == 0) {
      g_constant_value = iVar3;
      g_constant_value_high = (int)(uVar10 >> 0x20);
      pcVar4 = fold_binary_constants_tail(g_type_int64);
      return pcVar4;
    }
  }
  else {
    if ((short)ebx == 0) {
      iVar9 = iVar3 >> 0x1f;
    }
    else {
      iVar9 = 0;
    }
    if (in_stack_00000074 == (c1_type *)0x0) {
      if (in_stack_00000013 == '\0') {
LAB_10415264:
        pcVar7 = g_type_unsigned_int;
        if ((short)ebx == 0) {
          pcVar7 = g_type_int;
        }
        g_constant_value = iVar3;
        g_constant_value_high = iVar9;
        pcVar4 = tree_new_constant(pcVar7,&g_constant_value,g_expr_arena_index);
        return pcVar4;
      }
    }
    else {
      iVar6 = type_size_scalar(in_stack_00000074);
      if ((iVar6 != 4) || ((in_stack_00000074->code & 0x1f) == 0x14)) goto LAB_10415264;
    }
    pcVar7 = g_type_unsigned_long;
    uVar10 = CONCAT44(iVar9,iVar3);
    if ((short)ebx == 0) {
      pcVar7 = g_type_long;
      uVar10 = CONCAT44(iVar9,iVar3);
    }
  }
  g_constant_value_high = (int)(uVar10 >> 0x20);
  g_constant_value = (int)uVar10;
  pcVar4 = tree_new_constant(pcVar7,&g_constant_value,g_expr_arena_index);
  return pcVar4;
}

