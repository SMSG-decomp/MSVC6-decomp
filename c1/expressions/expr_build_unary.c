c1_node * __cdecl expr_build_unary(c1_u8 op,c1_node *operand)

{
  char *pcVar1;
  c1_type *type;
  ushort uVar2;
  c1_node *pcVar3;
  int iVar4;
  c1_type *pcVar5;
  uint lo;
  c1_node *operand_00;
  void *pvVar6;
  byte bVar7;
  ushort uVar8;
  uint hi;
  longlong lVar9;
  ulonglong uVar10;
  float_const local_c;
  
  if (operand == (c1_node *)0x0) {
    return (c1_node *)0x0;
  }
  pcVar5 = operand->type;
  pcVar3 = tree_new_unary(op,pcVar5,operand);
  iVar4 = expr_check_illegal_for_type(op,'\x01',(c1_node *)0x0,operand);
  if (iVar4 == 0) {
    return (c1_node *)0x0;
  }
  switch(op) {
  case '1':
    pcVar3 = expr_build_address_of(operand,0xc);
    return pcVar3;
  default:
    pcVar3 = fold_truncate_to_type_width
                       (local_c.mantissa_lo,local_c.mantissa_hi,pcVar5,operand,pcVar3);
    return pcVar3;
  case '<':
    uVar2 = pcVar5->code & 0x8f;
    if (((uVar2 != 0x83) && (uVar2 != 0x82)) && ((uVar2 != 0x86 && ((pcVar5->code & 0x130) == 0))))
    {
      diag_error(0xab,0x3c,pcVar5);
      return pcVar3;
    }
    pcVar3->type = g_type_int;
    if ((operand->kind & 7) != 3) {
      return pcVar3;
    }
    uVar2 = pcVar5->code;
    if (((uVar2 & 0x110) == 0) &&
       ((-1 < (char)uVar2 || (((uVar2 & 0x8f) != 0x86 && ((uVar2 & 0x8f) != 0x82)))))) {
      pcVar3 = tree_new_int_constant(0);
      pcVar3 = expr_build_binary(';',operand,pcVar3);
      return pcVar3;
    }
    if (operand->left == (void *)0x0 && operand->right == (void *)0x0) {
      pcVar3 = fold_truncate_to_type_width(1,0,operand->type,operand,pcVar3);
      return pcVar3;
    }
    pcVar3 = fold_truncate_to_type_width(0,0,operand->type,operand,pcVar3);
    return pcVar3;
  case '=':
    uVar2 = pcVar5->code;
    uVar8 = uVar2 & 0x8f;
    if ((uVar8 == 0x86) || ((bVar7 = (byte)uVar2, (char)bVar7 < '\0' && (uVar8 == 0x84)))) {
      if (uVar2 == 0x4086) {
        return operand;
      }
      pcVar5 = type_member_pointer_to_3(pcVar5,1);
      operand->type = pcVar5;
      return operand;
    }
    if (((char)bVar7 < '\0') && (uVar8 == 0x82)) {
      pcVar5 = expr_check_based_void_pointer(pcVar5);
      pcVar3->type = pcVar5;
      bVar7 = (byte)pcVar5->code;
      if ((char)bVar7 < '\0') {
        if ((*(byte *)(-(uint)((pcVar5->code & 0x80) != 0) & (uint)pcVar5) & 0x8f) == 0x83) {
          operand->kind = operand->kind | 0x20;
          pcVar5 = pcVar3->type;
          pcVar5 = type_intern_from_parts
                             (pcVar5,0x83,
                              *(ushort *)((-(uint)((pcVar5->code & 0x80) != 0) & (uint)pcVar5) + 2)
                              & 0x3e0 | *(byte *)(((uint)operand->type &
                                                  -(uint)((operand->type->code & 0x80) != 0)) + 2) &
                                        0x1f,
                              (c1_u32 *)((-(uint)((pcVar5->code & 0x80) != 0) & (uint)pcVar5) + 8));
          operand->type = pcVar5;
          return operand;
        }
        if ((pcVar5->code & 0x8f) != 0x82) {
          return pcVar3;
        }
        uVar2 = pcVar5->flags & 0x18;
        if ((uVar2 != 0x18) && (uVar2 != 8)) {
          return pcVar3;
        }
        pcVar3 = expr_based_pointer_fixup(pcVar3);
        return pcVar3;
      }
      if ((bVar7 >> 6 & 1) == 0) goto LAB_1060dced;
    }
    else {
      if (uVar8 == 0x83) {
        pcVar3 = tree_new_int_constant(0);
        pcVar3 = expr_build_binary('A',operand,pcVar3);
        return pcVar3;
      }
      if ((bVar7 & 0x83) == 0x81) {
        return operand;
      }
    }
    diag_error(100);
    pcVar3 = pcVar3->left;
LAB_1060dced:
    if (((((operand->kind & 7) == 4) && (operand->op == '\x06')) && ((pcVar3->kind & 7) == 1)) &&
       (pcVar3->op == '=')) {
      pcVar1 = pcVar3->left;
      if (((pcVar1[1] & 7U) == 4) && (*pcVar1 == '\x06')) {
        pcVar1[1] = pcVar1[1] & 0xdf;
      }
    }
    return pcVar3;
  case 'Y':
    if ((pcVar5->code & 0x110) == 0) {
      diag_error(0xab,0x59,pcVar5);
      return pcVar3;
    }
    operand_00 = (c1_node *)expr_apply_implicit_conversion(operand);
    pcVar3->type = operand_00->type;
    if ((operand_00->kind & 7) == 3) {
      pcVar3 = fold_truncate_to_type_width
                         (~(uint)operand_00->left,~(uint)operand_00->right,operand_00->type,
                          operand_00,pcVar3);
      return pcVar3;
    }
    return pcVar3;
  case 'Z':
    if ((operand->type->code & 0x130) == 0) {
      diag_error(0xab,0x5a,operand->type);
      return pcVar3;
    }
    operand = (c1_node *)expr_apply_implicit_conversion(operand);
    pcVar5 = operand->type;
    pcVar3->type = pcVar5;
    uVar2 = pcVar5->code;
    if ((uVar2 & 0x2000) == 0) {
      if ((((g_ms_extensions == '\0') && ((uVar2 & 0xfff) == 0x11)) && ((uVar2 & 0x1000) == 0)) &&
         (g_opt_J_unsigned_char != '\0')) {
        pcVar3 = fold_unary_constant(operand,pcVar3);
        return pcVar3;
      }
    }
    else {
      diag_warning(2,0x92);
    }
    if ((operand->kind & 7) != 3) {
      return pcVar3;
    }
    pcVar5 = operand->type;
    uVar2 = pcVar5->code;
    if (((byte)uVar2 >> 5 & 1) != 0) {
      iVar4 = float_fold_subtract_constants(&g_float_zero,operand->left,&local_c);
      if (iVar4 != 0) {
        diag_warning(2,0x38);
      }
      pvVar6 = record3_new_from((int *)&local_c,g_expr_arena_index);
      operand->left = pvVar6;
      return operand;
    }
    lo = -(int)operand->left;
    hi = -((int)operand->right + (uint)(operand->left != (void *)0x0));
    uVar10 = CONCAT44(hi,lo);
    if ((uVar2 & 0x2000) == 0) {
      if (((g_ms_extensions == '\0') && ((uVar2 & 0xfff) == 0x11)) &&
         (((uVar2 & 0x1000) == 0 && (g_opt_J_unsigned_char != '\0')))) {
        pcVar3 = fold_truncate_to_type_width(lo,hi,pcVar5,operand,pcVar3);
        return pcVar3;
      }
      bVar7 = ('\b' - (&g_type_rank_table)[uVar2 & 0xf]) * '\b';
      lVar9 = _allshl(bVar7,lo,hi);
      uVar10 = _allshr(bVar7,(int)((ulonglong)lVar9 >> 0x20),(uint)lVar9);
    }
    uVar2 = pcVar5->code;
    if ((-1 < (char)uVar2) &&
       (((uVar2 & 0x2000) != 0 ||
        ((((g_ms_extensions == '\0' && ((uVar2 & 0xfff) == 0x11)) &&
          (((uVar2 & 0x1000) == 0 && (g_opt_J_unsigned_char != '\0')))) ||
         ((-1 < (longlong)uVar10 && (uVar10 != 0)))))))) {
      bVar7 = ('\b' - (&g_type_rank_table)[uVar2 & 0xf]) * '\b';
      lVar9 = _allshl(bVar7,(uint)uVar10,(uint)(uVar10 >> 0x20));
      uVar10 = _aullshr(bVar7,(uint)((ulonglong)lVar9 >> 0x20),(uint)lVar9);
    }
    operand->type = pcVar3->type;
    operand->left = (void *)(int)uVar10;
    operand->right = (void *)(int)(uVar10 >> 0x20);
    break;
  case 'v':
    operand->flags = operand->flags | 2;
    if ((((byte)pcVar3->type->code >> 5 & 1) != 0) && ((operand->kind & 7) != 3)) {
      return pcVar3;
    }
    break;
  case 0x86:
    if ((pcVar5->code & 0x130) == 0) {
      diag_error(0xab,0x86,pcVar5);
    }
    operand = (c1_node *)expr_apply_implicit_conversion(operand);
    pcVar5 = operand->type;
    pcVar3->type = pcVar5;
    type = operand->type;
    if ((operand->kind & 7) == 3) {
      if (((byte)type->code >> 5 & 1) == 0) {
        pcVar3 = fold_truncate_to_type_width
                           ((uint)operand->left,(int)operand->right,type,operand,pcVar3);
        return pcVar3;
      }
    }
    else if (pcVar5 != type) {
      return pcVar3;
    }
    break;
  case 0xf0:
    pcVar3 = tree_new_unary(op,g_type_void,operand);
    return pcVar3;
  }
  return operand;
}

