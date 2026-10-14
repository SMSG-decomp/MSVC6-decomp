c1_node * __cdecl fold_binary_constant_expression(c1_node *node,c1_node *left,c1_node *right)

{
  c1_u8 op;
  ushort uVar1;
  ushort uVar2;
  c1_u16 cVar3;
  c1_type *type;
  void *pvVar4;
  uint *puVar5;
  c1_node *pcVar6;
  c1_u8 is_unsigned;
  undefined1 uVar7;
  c1_node *pcVar8;
  int iVar9;
  c1_type *pcVar10;
  c1_node *pcVar11;
  char *pcVar12;
  uint uVar13;
  c1_u8 is_unsigned_2;
  void *pvVar14;
  short sVar15;
  int iVar16;
  ushort uVar17;
  bool bVar18;
  uint64_t uVar19;
  float_const *pfVar20;
  char long_operand;
  float_const local_44;
  float_const local_38;
  char local_2c [44];
  
  pcVar6 = right;
  pcVar11 = left;
  long_operand = '\0';
  if (node == (c1_node *)0x0) {
    return (c1_node *)0x0;
  }
  op = node->op;
  if ((left->kind & 7) != 3) {
    return node;
  }
  pcVar10 = left->type;
  type = right->type;
  if ((right->kind & 7) != 3) {
    if ((op != '2') && (op != 'O')) {
      return node;
    }
    uVar1 = pcVar10->code;
    if (((byte)uVar1 >> 5 & 1) == 0) {
      uVar13 = (uint)(left->left != (void *)0x0 || left->right != (void *)0x0);
      iVar16 = 0;
      if (((uVar1 & 0x2000) == 0) &&
         ((((g_ms_extensions != '\0' || ((uVar1 & 0xfff) != 0x11)) || ((uVar1 & 0x1000) != 0)) ||
          (g_opt_J_unsigned_char == '\0')))) {
        bVar18 = false;
      }
      else {
        bVar18 = true;
      }
    }
    else {
      puVar5 = left->left;
      local_38.mantissa_lo = *puVar5;
      local_38.mantissa_hi = puVar5[1];
      local_38._8_4_ = puVar5[2];
      uVar13 = float_const_compare_mask(6,(float10 *)&local_38,(float10 *)&g_float_zero);
      iVar16 = (int)uVar13 >> 0x1f;
      bVar18 = false;
    }
    if ((uVar13 != 0 || iVar16 != 0) == (op == '2')) {
      return node;
    }
    pcVar10 = g_type_unsigned_int;
    uVar19 = CONCAT44(iVar16,uVar13);
    if (!bVar18) {
      pcVar10 = g_type_int;
      uVar19 = CONCAT44(iVar16,uVar13);
    }
    goto LAB_1060d452;
  }
  uVar1 = pcVar10->code;
  is_unsigned = (byte)uVar1 >> 5 & 1;
  if ((is_unsigned != '\0') || (((byte)type->code >> 5 & 1) != 0)) {
    if (is_unsigned == '\0') {
      if (((uVar1 & 0x2000) == 0) &&
         (((g_ms_extensions != '\0' || ((uVar1 & 0xfff) != 0x11)) ||
          (((uVar1 & 0x1000) != 0 || (g_opt_J_unsigned_char == '\0')))))) {
        iVar16 = 0;
      }
      else {
        iVar16 = 1;
      }
      pfVar20 = &local_38;
      pcVar12 = int64_to_string((int *)&left->left,local_2c,10,iVar16);
      uVar13 = float_const_from_string(pcVar12,pfVar20);
      if ((char)uVar13 != '\0') {
        diag_warning(2,0x38);
      }
    }
    else {
      puVar5 = left->left;
      local_38.mantissa_lo = *puVar5;
      local_38.mantissa_hi = puVar5[1];
      local_38._8_4_ = puVar5[2];
    }
    uVar1 = type->code;
    if (((byte)uVar1 >> 5 & 1) == 0) {
      if (((uVar1 & 0x2000) == 0) &&
         ((((g_ms_extensions != '\0' || ((uVar1 & 0xfff) != 0x11)) || ((uVar1 & 0x1000) != 0)) ||
          (g_opt_J_unsigned_char == '\0')))) {
        iVar16 = 0;
      }
      else {
        iVar16 = 1;
      }
      pfVar20 = &local_44;
      pcVar12 = int64_to_string((int *)&right->left,local_2c,10,iVar16);
      uVar13 = float_const_from_string(pcVar12,pfVar20);
      if ((char)uVar13 != '\0') {
        diag_warning(2,0x38);
      }
    }
    else {
      puVar5 = right->left;
      local_44.mantissa_lo = *puVar5;
      local_44.mantissa_hi = puVar5[1];
      local_44._8_4_ = puVar5[2];
    }
    pcVar11 = fold_float_constant(node,&local_38,&local_44);
    return pcVar11;
  }
  left = (c1_node *)0x0;
  pcVar8 = (c1_node *)type_size_scalar(pcVar10);
  local_44.mantissa_lo = type_size_scalar(type);
  uVar1 = pcVar10->code;
  if ((char)(byte)uVar1 < '\0') {
LAB_10632813:
    iVar16 = 1;
    right = (c1_node *)type_size_scalar(node->type);
  }
  else {
    uVar2 = type->code;
    if ((char)(byte)uVar2 < '\0') goto LAB_10632813;
    right = pcVar8;
    if (pcVar8 == (c1_node *)local_44.mantissa_lo) {
      if (pcVar8 == (c1_node *)0x1) {
        iVar16 = 0;
        right = (c1_node *)0x4;
      }
      else {
        if ((((uVar1 & 0x2000) == 0) &&
            (((((g_ms_extensions != '\0' || ((uVar1 & 0xfff) != 0x11)) || ((uVar1 & 0x1000) != 0))
              || (g_opt_J_unsigned_char == '\0')) && ((uVar2 & 0x2000) == 0)))) &&
           (((g_ms_extensions != '\0' || ((uVar2 & 0xfff) != 0x11)) ||
            (((uVar2 & 0x1000) != 0 || (g_opt_J_unsigned_char == '\0')))))) {
          iVar16 = 0;
        }
        else {
          iVar16 = 1;
        }
        if ((c1_node *)0x3 < pcVar8) goto LAB_1060ce57;
        right = (c1_node *)0x4;
      }
LAB_1060ce60:
      if ((((byte)uVar1 & 0x1f) == 0x14) || (((byte)uVar2 & 0x1f) == 0x14)) {
        long_operand = '\x01';
      }
      else {
        long_operand = '\0';
      }
    }
    else {
      uVar17 = (ushort)((uint)pcVar8 >> 0x10);
      if (local_44.mantissa_lo < pcVar8) {
        if (((uVar1 & 0x2000) == 0) &&
           (((g_ms_extensions != '\0' || ((uVar1 & 0xfff) != 0x11)) ||
            (((uVar1 & 0x1000) != 0 || (g_opt_J_unsigned_char == '\0')))))) {
          iVar16 = (uint)uVar17 << 0x10;
        }
        else {
          iVar16 = CONCAT31((int3)(((uint)uVar17 << 0x10) >> 8),1);
        }
      }
      else {
        if (((uVar2 & 0x2000) == 0) &&
           (((g_ms_extensions != '\0' || ((uVar2 & 0xfff) != 0x11)) ||
            (((uVar2 & 0x1000) != 0 || (g_opt_J_unsigned_char == '\0')))))) {
          uVar7 = 0;
        }
        else {
          uVar7 = 1;
        }
        iVar16 = CONCAT31((int3)(((uint)uVar17 << 0x10) >> 8),uVar7);
        right = (c1_node *)local_44.mantissa_lo;
      }
LAB_1060ce57:
      if (right == (c1_node *)0x4) goto LAB_1060ce60;
    }
  }
  sVar15 = (short)iVar16;
  switch(op) {
  case '2':
  case 'C':
  case 'O':
  case 'X':
    if (pcVar8 < (c1_node *)0x5) {
      pvVar14 = pcVar11->left;
      if (sVar15 == 0) {
        pcVar11->left = pvVar14;
        pcVar11->right = (void *)((int)pvVar14 >> 0x1f);
      }
      else {
        pcVar11->left = pvVar14;
        pcVar11->right = (void *)0x0;
      }
      goto LAB_1060cf94;
    }
    break;
  default:
    if (((((sVar15 != 0) && (-1 < (char)pcVar11->type->code)) && (-1 < (char)pcVar6->type->code)) &&
        (((((~(byte)(pcVar10->code >> 0xd) & 1) != 0 && ((int)pcVar11->right < 1)) &&
          ((int)pcVar11->right < 0)) ||
         ((((~(byte)(type->code >> 0xd) & 1) != 0 && ((int)pcVar6->right < 1)) &&
          ((int)pcVar6->right < 0)))))) && (((op != '1' && (op != 'M')) && (op != '[')))) {
      diag_warning(2,0x134);
    }
LAB_1060cf94:
    if (pcVar8 < (c1_node *)0x5) {
      if (sVar15 == 0) {
        pvVar14 = (void *)((int)pcVar11->left >> 0x1f);
      }
      else {
        pvVar14 = (void *)0x0;
      }
      pcVar11->left = pcVar11->left;
      pcVar11->right = pvVar14;
    }
  }
  if (local_44.mantissa_lo < (c1_node *)0x5) {
    if (sVar15 == 0) {
      pvVar14 = (void *)((int)pcVar6->left >> 0x1f);
    }
    else {
      pvVar14 = (void *)0x0;
    }
    pcVar6->left = pcVar6->left;
    pcVar6->right = pvVar14;
  }
  switch(op) {
  case '1':
    uVar19 = CONCAT44((uint)pcVar6->right & (uint)pcVar11->right,
                      (uint)pcVar6->left & (uint)pcVar11->left);
    break;
  case '2':
    if (pcVar11->left != (void *)0x0 || pcVar11->right != (void *)0x0) {
      bVar18 = pcVar6->left == (void *)0x0 && pcVar6->right == (void *)0x0;
LAB_1060d341:
      if (!bVar18) goto LAB_1060d343;
    }
    goto LAB_1060d369;
  default:
    return node;
  case '9':
    pvVar14 = pcVar6->left;
    pvVar4 = pcVar6->right;
    if (pvVar14 == (void *)0x0 && pvVar4 == (void *)0x0) {
      pcVar6->kind = '@';
      return pcVar6;
    }
    if (sVar15 == 0) {
      uVar19 = _alldiv((uint32_t)pcVar11->left,(uint32_t)pcVar11->right,(uint32_t)pvVar14,
                       (uint32_t)pvVar4);
    }
    else {
      uVar19 = _aulldiv((uint32_t)pcVar11->left,(uint32_t)pcVar11->right,(uint32_t)pvVar14,
                        (uint32_t)pvVar4);
    }
    break;
  case ';':
    if ((pcVar11->left != pcVar6->left) || (pcVar11->right != pcVar6->right)) goto LAB_1060d369;
    iVar16 = 1;
    goto LAB_1060d36b;
  case '>':
    if (sVar15 == 0) {
      if ((int)pcVar6->right <= (int)pcVar11->right) {
        if ((int)pcVar6->right < (int)pcVar11->right) goto LAB_1060d343;
        if (pcVar6->left < pcVar11->left) {
          iVar16 = 1;
          goto LAB_1060d36b;
        }
      }
    }
    else if ((pcVar6->right <= pcVar11->right) &&
            ((pcVar11->right != pcVar6->right || (pcVar6->left < pcVar11->left)))) {
      iVar16 = 1;
      goto LAB_1060d36b;
    }
    goto LAB_1060d369;
  case '?':
    if (sVar15 == 0) {
      if (((int)pcVar11->right < (int)pcVar6->right) ||
         (((int)pcVar11->right <= (int)pcVar6->right && (pcVar11->left < pcVar6->left)))) {
LAB_106328d2:
        iVar9 = 0;
      }
      else {
        iVar9 = 1;
      }
    }
    else {
      if ((pcVar11->right < pcVar6->right) ||
         ((pcVar11->right == pcVar6->right && (pcVar11->left < pcVar6->left)))) goto LAB_106328d2;
      iVar9 = 1;
    }
    iVar16 = 0;
    uVar19 = (uint64_t)iVar9;
    left = (c1_node *)g_type_int;
    break;
  case 'C':
    uVar19 = _allshl((byte)pcVar6->left,(uint)pcVar11->left,(uint)pcVar11->right);
    left = (c1_node *)node->type;
    break;
  case 'D':
    if (sVar15 == 0) {
      if (((int)pcVar11->right <= (int)pcVar6->right) &&
         (((int)pcVar11->right < (int)pcVar6->right || (pcVar11->left < pcVar6->left)))) {
        iVar16 = 1;
        goto LAB_1060d36b;
      }
    }
    else if ((pcVar11->right <= pcVar6->right) &&
            ((pcVar11->right < pcVar6->right || (pcVar11->left < pcVar6->left)))) goto LAB_1063289e;
LAB_1060d369:
    iVar16 = 0;
    goto LAB_1060d36b;
  case 'E':
    if (sVar15 == 0) {
      if (((int)pcVar6->right < (int)pcVar11->right) ||
         (((int)pcVar6->right <= (int)pcVar11->right && (pcVar6->left < pcVar11->left)))) {
LAB_1060d0be:
        iVar16 = 0;
      }
      else {
        iVar16 = 1;
      }
    }
    else {
      if ((pcVar6->right < pcVar11->right) ||
         ((pcVar6->right <= pcVar11->right && (pcVar6->left < pcVar11->left)))) goto LAB_1060d0be;
      iVar16 = 1;
    }
    uVar19 = (uint64_t)iVar16;
    left = (c1_node *)g_type_int;
    iVar16 = 0;
    break;
  case 'F':
    local_44.mantissa_hi = (uint)pcVar6->right;
    pcVar8 = pcVar11->left;
    local_44.mantissa_lo = (uint)pcVar6->left;
    uVar19 = CONCAT44((int)pcVar11->right +
                      (-(uint)(pcVar8 < local_44.mantissa_lo) - local_44.mantissa_hi),
                      (int)pcVar8 - local_44.mantissa_lo);
    uVar13 = fold_check_subtract_overflow
                       ((uint)pcVar8,(int)pcVar11->right,local_44.mantissa_lo,local_44.mantissa_hi,
                        (int)sVar15,(uint)right);
    goto LAB_1060d248;
  case 'H':
    pvVar14 = pcVar6->left;
    pvVar4 = pcVar6->right;
    if (pvVar14 == (void *)0x0 && pvVar4 == (void *)0x0) {
      pcVar6->kind = '@';
      return pcVar6;
    }
    if (sVar15 == 0) {
      uVar19 = _allrem((uint32_t)pcVar11->left,(int32_t)pcVar11->right,(uint32_t)pvVar14,
                       (int32_t)pvVar4);
    }
    else {
      uVar19 = _aullrem((uint32_t)pcVar11->left,(uint32_t)pcVar11->right,(uint32_t)pvVar14,
                        (uint32_t)pvVar4);
    }
    break;
  case 'J':
    local_44.mantissa_lo = (uint)pcVar6->left;
    local_44.mantissa_hi = (uint)pcVar6->right;
    uVar19 = _allmul(local_44.mantissa_lo,local_44.mantissa_hi,(uint)pcVar11->left,
                     (int)pcVar11->right);
    uVar13 = fold_check_multiply_overflow
                       ((uint)pcVar11->left,(int)pcVar11->right,local_44.mantissa_lo,
                        local_44.mantissa_hi,(int)sVar15,(uint)right);
    goto LAB_1060d248;
  case 'L':
    if (pcVar11->left == pcVar6->left) {
      bVar18 = pcVar11->right == pcVar6->right;
      goto LAB_1060d341;
    }
LAB_1060d343:
    iVar16 = 1;
    goto LAB_1060d36b;
  case 'M':
    uVar19 = CONCAT44((uint)pcVar6->right | (uint)pcVar11->right,
                      (uint)pcVar6->left | (uint)pcVar11->left);
    break;
  case 'O':
    if ((pcVar11->left == (void *)0x0 && pcVar11->right == (void *)0x0) &&
       (pcVar6->left == (void *)0x0 && pcVar6->right == (void *)0x0)) goto LAB_1060d369;
LAB_1063289e:
    iVar16 = 1;
LAB_1060d36b:
    uVar19 = (uint64_t)iVar16;
    left = (c1_node *)g_type_int;
    iVar16 = 0;
    break;
  case 'Q':
  case 'S':
    local_44.mantissa_lo = (uint)pcVar6->left;
    local_44.mantissa_hi = (uint)pcVar6->right;
    pvVar14 = pcVar11->left;
    uVar19 = CONCAT44(local_44.mantissa_hi + (int)pcVar11->right +
                      (uint)CARRY4(local_44.mantissa_lo,(uint)pvVar14),
                      &((c1_node *)local_44.mantissa_lo)->op + (int)pvVar14);
    uVar13 = fold_add_overflows((uint)pvVar14,(int)pcVar11->right,local_44.mantissa_lo,
                                local_44.mantissa_hi,(int)sVar15,(uint)right);
LAB_1060d248:
    if (uVar13 != 0) {
      pcVar11 = fold_integer_overflow_fragment
                          (iVar16,(int)(uVar19 >> 0x20),(uint)uVar19,long_operand,op,node,
                           (c1_type *)0x0,(int)right);
      return pcVar11;
    }
    break;
  case 'X':
    is_unsigned_2 = (c1_u8)pcVar6->left;
    if (sVar15 == 0) {
      uVar19 = _allshr(is_unsigned_2,(int)pcVar11->right,(uint)pcVar11->left);
      left = (c1_node *)node->type;
    }
    else {
      uVar19 = _aullshr(is_unsigned_2,(uint)pcVar11->right,(uint)pcVar11->left);
      left = (c1_node *)node->type;
    }
    break;
  case '[':
    uVar19 = CONCAT44((uint)pcVar6->right ^ (uint)pcVar11->right,
                      (uint)pcVar6->left ^ (uint)pcVar11->left);
  }
  uVar13 = (uint)uVar19;
  if (((op == 'Q') || (op == 'F')) && (cVar3 = node->type->code, (char)cVar3 < '\0')) {
    pcVar11 = fold_binary_constant_expression_fragment
                        (CONCAT22((short)((uint)node->type >> 0x10),cVar3),iVar16,
                         (int)(uVar19 >> 0x20),uVar13,pcVar11,long_operand,(c1_type *)left,
                         (int)right);
    return pcVar11;
  }
  if (left != (c1_node *)0x0) {
    right = (c1_node *)type_size_scalar((c1_type *)left);
  }
  sVar15 = (short)iVar16;
  if (right == (c1_node *)0x8) {
    pcVar10 = g_type_uint64;
    if (sVar15 == 0) {
      pcVar10 = g_type_int64;
    }
  }
  else {
    if (sVar15 == 0) {
      iVar16 = (int)uVar13 >> 0x1f;
    }
    else {
      iVar16 = 0;
    }
    if (left == (c1_node *)0x0) {
      if (long_operand == '\0') {
LAB_1060d2f4:
        pcVar10 = g_type_unsigned_int;
        if (sVar15 == 0) {
          pcVar10 = g_type_int;
        }
        g_constant_value = uVar13;
        g_constant_value_high = iVar16;
        pcVar11 = tree_new_constant(pcVar10,&g_constant_value,g_expr_arena_index);
        return pcVar11;
      }
    }
    else {
      iVar9 = type_size_scalar((c1_type *)left);
      if ((iVar9 != 4) || ((left->op & 0x1f) == 0x14)) goto LAB_1060d2f4;
    }
    pcVar10 = g_type_unsigned_long;
    uVar19 = CONCAT44(iVar16,uVar13);
    if (sVar15 == 0) {
      pcVar10 = g_type_long;
      uVar19 = CONCAT44(iVar16,uVar13);
    }
  }
LAB_1060d452:
  g_constant_value_high = (int)(uVar19 >> 0x20);
  g_constant_value = (uint)uVar19;
  pcVar11 = tree_new_constant(pcVar10,&g_constant_value,g_expr_arena_index);
  return pcVar11;
}

