c1_node * __cdecl fold_binary_constants(c1_node *node,c1_node *left,c1_node *right)

{
  byte op;
  ushort uVar1;
  void *a_hi;
  bool bVar2;
  byte bVar3;
  ushort uVar4;
  c1_node *pcVar5;
  c1_node *right_const;
  uint uVar6;
  uint right_size;
  int iVar7;
  c1_type *pcVar8;
  int iVar9;
  char *pcVar10;
  uint uVar11;
  byte bVar12;
  byte right_code;
  void *pvVar13;
  int iVar14;
  ulonglong uVar15;
  c1xx_float_const *pcVar16;
  char long_result;
  uint local_58;
  c1_type *t;
  void *pvVar17;
  int right_hi;
  uint left_float_0;
  uint left_float_1;
  uint left_float_2;
  char acStack_2c [44];
  uint *left_float_src;
  uint *left_float_src_2;
  
  long_result = '\0';
  if (node == (c1_node *)0x0) {
    return (c1_node *)0x0;
  }
  op = node->op;
  pcVar5 = fold_static_const_member(left);
  if ((pcVar5->kind & 7) != 3) {
    return node;
  }
  right_const = fold_static_const_member(right);
  pcVar8 = pcVar5->type;
  t = right_const->type;
  if ((right_const->kind & 7) != 3) {
    if ((op != 0x32) && (op != 0x4f)) {
      return node;
    }
    uVar4 = pcVar8->code;
    if (((byte)uVar4 >> 5 & 1) == 0) {
      uVar11 = (uint)(pcVar5->left != (void *)0x0 || pcVar5->right != (void *)0x0);
      iVar9 = 0;
      if (((uVar4 & 0x2000) == 0) &&
         ((((uVar4 & 0xfff) != 0x11 || ((uVar4 & 0x1000) != 0)) || (g_opt_J_unsigned_char == '\0')))
         ) {
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
    }
    else {
      left_float_src_2 = pcVar5->left;
      left_float_0 = *left_float_src_2;
      left_float_1 = left_float_src_2[1];
      left_float_2 = left_float_src_2[2];
      uVar11 = float_const_compare_mask(6,&left_float_0,&g_float_zero);
      iVar9 = (int)uVar11 >> 0x1f;
      bVar2 = false;
    }
    if ((uVar11 != 0 || iVar9 != 0) == (op == 0x32)) {
      return node;
    }
    pcVar8 = g_type_unsigned_int;
    uVar15 = CONCAT44(iVar9,uVar11);
    if (!bVar2) {
      g_constant_value = uVar11;
      g_constant_value_high = iVar9;
      pcVar5 = fold_binary_constants_tail(g_type_int);
      return pcVar5;
    }
    goto code_r0x1041540a;
  }
  uVar4 = pcVar8->code;
  bVar3 = (byte)uVar4 >> 5 & 1;
  if ((bVar3 != 0) || (((byte)t->code >> 5 & 1) != 0)) {
    if (bVar3 == 0) {
      if (((uVar4 & 0x2000) == 0) &&
         ((((uVar4 & 0xfff) != 0x11 || ((uVar4 & 0x1000) != 0)) || (g_opt_J_unsigned_char == '\0')))
         ) {
        iVar9 = 0;
      }
      else {
        iVar9 = 1;
      }
      pcVar16 = (c1xx_float_const *)&left_float_0;
      pcVar10 = int64_to_string((int *)&pcVar5->left,acStack_2c,10,iVar9);
      uVar11 = float_const_from_string(pcVar10,pcVar16);
      if ((char)uVar11 != '\0') {
        diag_warning(2,0x38);
      }
    }
    else {
      left_float_src = pcVar5->left;
      left_float_0 = *left_float_src;
      left_float_1 = left_float_src[1];
      left_float_2 = left_float_src[2];
    }
    uVar4 = t->code;
    if (((byte)uVar4 >> 5 & 1) == 0) {
      if (((uVar4 & 0x2000) == 0) &&
         ((((uVar4 & 0xfff) != 0x11 || ((uVar4 & 0x1000) != 0)) || (g_opt_J_unsigned_char == '\0')))
         ) {
        iVar9 = 0;
      }
      else {
        iVar9 = 1;
      }
      pcVar16 = (c1xx_float_const *)&stack0xffffffbc;
      pcVar10 = int64_to_string((int *)&right_const->left,acStack_2c,10,iVar9);
      uVar11 = float_const_from_string(pcVar10,pcVar16);
      if ((char)uVar11 != '\0') {
        diag_warning(2,0x38);
      }
    }
    pcVar5 = fold_float_constant(node,&left_float_0,&stack0xffffffbc);
    return pcVar5;
  }
  left = (c1_node *)0x0;
  uVar6 = type_size_scalar(pcVar8);
  uVar11 = uVar6;
  right_size = type_size_scalar(t);
  uVar4 = pcVar8->code;
  bVar3 = (byte)uVar4;
  if ((char)bVar3 < '\0') {
LAB_1046a094:
    right._0_2_ = 1;
    local_58 = type_size_scalar(node->type);
  }
  else {
    uVar1 = t->code;
    right_code = (byte)uVar1;
    if ((char)right_code < '\0') goto LAB_1046a094;
    local_58 = uVar11;
    if (uVar6 == right_size) {
      if (uVar6 == 1) {
        local_58 = 4;
        right._0_2_ = 0;
      }
      else {
        if ((uVar4 & 0x2000) == 0) {
          if ((((uVar4 & 0xfff) == 0x11) && ((uVar4 & 0x1000) == 0)) &&
             (g_opt_J_unsigned_char != '\0')) {
            pcVar5 = fold_float_arithmetic_set_flag_fragment
                               (bVar3,right_code,pcVar8,right_const,pcVar5,long_result,op,uVar11,t,
                                right_size,right_hi,node,(c1_type *)0x0);
            return pcVar5;
          }
          if ((uVar1 & 0x2000) != 0) goto code_r0x104150a0;
          if ((((uVar1 & 0xfff) == 0x11) && ((uVar1 & 0x1000) == 0)) &&
             (g_opt_J_unsigned_char != '\0')) {
            pcVar5 = fold_float_arithmetic_set_flag_fragment
                               (bVar3,right_code,pcVar8,right_const,pcVar5,long_result,op,uVar11,t,
                                right_size,right_hi,node,(c1_type *)0x0);
            return pcVar5;
          }
          right._0_2_ = 0;
        }
        else {
code_r0x104150a0:
          right._0_2_ = 1;
        }
        if (3 < uVar11) goto LAB_1041503d;
        local_58 = 4;
      }
LAB_10415046:
      if (((bVar3 & 0x1f) == 0x14) || ((right_code & 0x1f) == 0x14)) {
        long_result = '\x01';
      }
      else {
        long_result = '\0';
      }
    }
    else {
      if (right_size < uVar6) {
        if (((uVar4 & 0x2000) == 0) &&
           ((((uVar4 & 0xfff) != 0x11 || ((uVar4 & 0x1000) != 0)) || (g_opt_J_unsigned_char == '\0')
            ))) {
          right._0_2_ = 0;
        }
        else {
          right._0_2_ = 1;
        }
      }
      else {
        if (((uVar1 & 0x2000) == 0) &&
           ((((uVar1 & 0xfff) != 0x11 || ((uVar1 & 0x1000) != 0)) || (g_opt_J_unsigned_char == '\0')
            ))) {
          bVar12 = 0;
        }
        else {
          bVar12 = 1;
        }
        right._0_2_ = (ushort)bVar12;
        local_58 = right_size;
      }
LAB_1041503d:
      if (local_58 == 4) goto LAB_10415046;
    }
  }
  uVar6 = (uint)op;
  switch(uVar6) {
  case 0x32:
  case 0x43:
  case 0x4f:
  case 0x58:
    if (uVar11 < 5) {
      pvVar13 = pcVar5->left;
      if ((ushort)right == 0) {
        pcVar5->left = pvVar13;
        pcVar5->right = (void *)((int)pvVar13 >> 0x1f);
      }
      else {
        pcVar5->left = pvVar13;
        pcVar5->right = (void *)0x0;
      }
      goto LAB_104150db;
    }
    break;
  default:
    if ((((((ushort)right != 0) && (-1 < (char)pcVar5->type->code)) &&
         (-1 < (char)right_const->type->code)) &&
        (((uVar4 = pcVar8->code, (uVar4 & 0x2000) == 0 &&
          ((((g_opt_J_unsigned_char == '\0' || (((byte)uVar4 & 0xf) != 1)) ||
            (((uVar4 & 0xfff) == 0x11 && ((uVar4 & 0x1000) != 0)))) &&
           (((int)pcVar5->right < 1 && ((int)pcVar5->right < 0)))))) ||
         ((uVar4 = t->code, (uVar4 & 0x2000) == 0 &&
          ((((g_opt_J_unsigned_char == '\0' || (((byte)uVar4 & 0xf) != 1)) ||
            (((uVar4 & 0xfff) == 0x11 && ((uVar4 & 0x1000) != 0)))) &&
           (((int)right_const->right < 1 && ((int)right_const->right < 0)))))))))) &&
       ((op != 0x31 && ((op != 0x4d && (op != 0x5b)))))) {
      diag_warning(2,0x134);
    }
LAB_104150db:
    if (uVar11 < 5) {
      if ((ushort)right == 0) {
        pvVar13 = (void *)((int)pcVar5->left >> 0x1f);
      }
      else {
        pvVar13 = (void *)0x0;
      }
      pcVar5->left = pcVar5->left;
      pcVar5->right = pvVar13;
    }
  }
  if (right_size < 5) {
    if ((ushort)right == 0) {
      pvVar13 = (void *)((int)right_const->left >> 0x1f);
    }
    else {
      pvVar13 = (void *)0x0;
    }
    right_const->left = right_const->left;
    right_const->right = pvVar13;
  }
  switch(uVar6) {
  case 0x31:
    uVar15 = CONCAT44((uint)right_const->right & (uint)pcVar5->right,
                      (uint)right_const->left & (uint)pcVar5->left);
    break;
  case 0x32:
    if ((pcVar5->left == (void *)0x0 && pcVar5->right == (void *)0x0) ||
       (right_const->left == (void *)0x0 && right_const->right == (void *)0x0)) goto LAB_1046a3ea;
    iVar9 = 1;
    goto LAB_1046a1e1;
  default:
    return node;
  case 0x39:
    pvVar13 = right_const->left;
    pvVar17 = right_const->right;
    if (pvVar13 == (void *)0x0 && pvVar17 == (void *)0x0) {
      right_const->kind = '@';
      return right_const;
    }
    if ((ushort)right == 0) {
      uVar15 = _alldiv((uint)pcVar5->left,(int)pcVar5->right,(uint)pvVar13,(int)pvVar17);
    }
    else {
      uVar15 = _aulldiv((uint)pcVar5->left,(uint)pcVar5->right,(uint)pvVar13,(uint)pvVar17);
    }
    break;
  case 0x3b:
    if ((pcVar5->left != right_const->left) || (pcVar5->right != right_const->right))
    goto LAB_1046a3ea;
    iVar9 = 1;
    goto LAB_1046a1e1;
  case 0x3e:
    if ((ushort)right == 0) {
      if (((int)pcVar5->right < (int)right_const->right) ||
         (((int)pcVar5->right <= (int)right_const->right && (pcVar5->left <= right_const->left))))
      goto LAB_1046a1b3;
      iVar9 = 1;
    }
    else if ((pcVar5->right < right_const->right) ||
            ((pcVar5->right == right_const->right && (pcVar5->left <= right_const->left)))) {
LAB_1046a1b3:
      iVar9 = 0;
    }
    else {
      iVar9 = 1;
    }
    goto LAB_1046a17f;
  case 0x3f:
    if ((ushort)right == 0) {
      if (((int)pcVar5->right < (int)right_const->right) ||
         (((int)pcVar5->right <= (int)right_const->right && (pcVar5->left < right_const->left))))
      goto LAB_1046a275;
      iVar9 = 1;
    }
    else if ((pcVar5->right < right_const->right) ||
            ((pcVar5->right == right_const->right && (pcVar5->left < right_const->left)))) {
LAB_1046a275:
      iVar9 = 0;
    }
    else {
      iVar9 = 1;
    }
    right._0_2_ = 0;
    uVar15 = (ulonglong)iVar9;
    left = (c1_node *)g_type_int;
    break;
  case 0x43:
    uVar15 = _allshl((byte)right_const->left,(uint)pcVar5->left,(uint)pcVar5->right);
    left = (c1_node *)node->type;
    break;
  case 0x44:
    if ((ushort)right == 0) {
      if (((int)right_const->right < (int)pcVar5->right) ||
         (((int)right_const->right <= (int)pcVar5->right && (right_const->left <= pcVar5->left))))
      goto LAB_1046a1b3;
      iVar9 = 1;
    }
    else {
      if ((right_const->right < pcVar5->right) ||
         ((right_const->right <= pcVar5->right && (right_const->left <= pcVar5->left))))
      goto LAB_1046a1b3;
      iVar9 = 1;
    }
LAB_1046a17f:
    uVar15 = (ulonglong)iVar9;
    left = (c1_node *)g_type_int;
    right._0_2_ = 0;
    break;
  case 0x45:
    if ((ushort)right == 0) {
      if (((int)right_const->right < (int)pcVar5->right) ||
         (((int)right_const->right <= (int)pcVar5->right && (right_const->left < pcVar5->left))))
      goto LAB_1046a3ea;
      iVar9 = 1;
    }
    else {
      if ((right_const->right < pcVar5->right) ||
         ((right_const->right <= pcVar5->right && (right_const->left < pcVar5->left))))
      goto LAB_1046a3ea;
      iVar9 = 1;
    }
    goto LAB_1046a1e1;
  case 0x46:
    pvVar13 = pcVar5->left;
    pvVar17 = right_const->left;
    uVar15 = CONCAT44((int)pcVar5->right + (-(uint)(pvVar13 < pvVar17) - (int)right_const->right),
                      (int)pvVar13 - (int)pvVar17);
    uVar11 = fold_check_subtract_overflow
                       ((uint)pvVar13,(int)pcVar5->right,(uint)pvVar17,(int)right_const->right,
                        (int)(short)(ushort)right,local_58);
    goto LAB_104152cc;
  case 0x48:
    pvVar13 = right_const->left;
    pvVar17 = right_const->right;
    if (pvVar13 == (void *)0x0 && pvVar17 == (void *)0x0) {
      right_const->kind = '@';
      return right_const;
    }
    if ((ushort)right == 0) {
      uVar15 = _allrem((uint)pcVar5->left,(int)pcVar5->right,(uint)pvVar13,(int)pvVar17);
    }
    else {
      uVar15 = _aullrem((uint)pcVar5->left,(uint)pcVar5->right,(uint)pvVar13,(uint)pvVar17);
    }
    break;
  case 0x4a:
    pvVar13 = pcVar5->left;
    pvVar17 = right_const->left;
    a_hi = right_const->right;
    uVar15 = _allmul((uint)pvVar17,(int)a_hi,(uint)pvVar13,(int)pcVar5->right);
    uVar11 = fold_check_multiply_overflow
                       ((uint)pvVar13,(int)pcVar5->right,(uint)pvVar17,(int)a_hi,
                        (int)(short)(ushort)right,local_58);
LAB_104152cc:
    if (uVar11 != 0) {
LAB_1046a2d7:
      diag_warning(2,0x133,uVar6);
    }
    break;
  case 0x4c:
    if ((pcVar5->left == right_const->left) && (pcVar5->right == right_const->right))
    goto LAB_1046a3ea;
LAB_1046a393:
    iVar9 = 1;
    goto LAB_1046a1e1;
  case 0x4d:
    uVar15 = CONCAT44((uint)right_const->right | (uint)pcVar5->right,
                      (uint)right_const->left | (uint)pcVar5->left);
    break;
  case 0x4f:
    if ((pcVar5->left != (void *)0x0 || pcVar5->right != (void *)0x0) ||
       (right_const->left != (void *)0x0 || right_const->right != (void *)0x0)) goto LAB_1046a393;
LAB_1046a3ea:
    iVar9 = 0;
LAB_1046a1e1:
    uVar15 = (ulonglong)iVar9;
    left = (c1_node *)g_type_int;
    right._0_2_ = 0;
    break;
  case 0x51:
  case 0x53:
    pvVar13 = right_const->left;
    pvVar17 = pcVar5->left;
    uVar15 = CONCAT44((int)right_const->right + (int)pcVar5->right +
                      (uint)CARRY4((uint)pvVar13,(uint)pvVar17),(int)pvVar13 + (int)pvVar17);
    iVar9 = fold_add_overflows((uint)pvVar17,(int)pcVar5->right,(uint)pvVar13,
                               (int)right_const->right,(int)(short)(ushort)right,local_58);
    if (iVar9 == 0) break;
    goto LAB_1046a2d7;
  case 0x58:
    bVar3 = (byte)right_const->left;
    if ((ushort)right == 0) {
      uVar15 = _allshr(bVar3,(int)pcVar5->right,(uint)pcVar5->left);
      left = (c1_node *)node->type;
    }
    else {
      uVar15 = _aullshr(bVar3,(uint)pcVar5->right,(uint)pcVar5->left);
      left = (c1_node *)node->type;
    }
    break;
  case 0x5b:
    uVar15 = CONCAT44((uint)right_const->right ^ (uint)pcVar5->right,
                      (uint)right_const->left ^ (uint)pcVar5->left);
  }
  iVar9 = (int)uVar15;
  if ((((op == 0x51) || (op == 0x46)) && (uVar4 = node->type->code, (char)uVar4 < '\0')) &&
     ((uVar4 = uVar4 & 0x8f, uVar4 == 0x86 || (uVar4 == 0x82)))) {
    pcVar5->left = (void *)(int)uVar15;
    pcVar5->right = (void *)(int)(uVar15 >> 0x20);
    return pcVar5;
  }
  if (left != (c1_node *)0x0) {
    local_58 = type_size_scalar((c1_type *)left);
  }
  if (local_58 == 8) {
    pcVar8 = g_type_uint64;
    if ((ushort)right == 0) {
      g_constant_value = iVar9;
      g_constant_value_high = (int)(uVar15 >> 0x20);
      pcVar5 = fold_binary_constants_tail(g_type_int64);
      return pcVar5;
    }
  }
  else {
    if ((ushort)right == 0) {
      iVar14 = iVar9 >> 0x1f;
    }
    else {
      iVar14 = 0;
    }
    if (left == (c1_node *)0x0) {
      if (long_result == '\0') {
LAB_10415264:
        pcVar8 = g_type_unsigned_int;
        if ((ushort)right == 0) {
          pcVar8 = g_type_int;
        }
        g_constant_value = iVar9;
        g_constant_value_high = iVar14;
        pcVar5 = tree_new_constant(pcVar8,&g_constant_value,g_expr_arena_index);
        return pcVar5;
      }
    }
    else {
      iVar7 = type_size_scalar((c1_type *)left);
      if ((iVar7 != 4) || ((left->op & 0x1f) == 0x14)) goto LAB_10415264;
    }
    pcVar8 = g_type_unsigned_long;
    uVar15 = CONCAT44(iVar14,iVar9);
    if ((ushort)right == 0) {
      pcVar8 = g_type_long;
      uVar15 = CONCAT44(iVar14,iVar9);
    }
  }
code_r0x1041540a:
  g_constant_value_high = (int)(uVar15 >> 0x20);
  g_constant_value = (uint)uVar15;
  pcVar5 = tree_new_constant(pcVar8,&g_constant_value,g_expr_arena_index);
  return pcVar5;
}

