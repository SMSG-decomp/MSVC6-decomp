c1_node * __cdecl fold_unary_constant(c1_node *operand,c1_node *node)

{
  ushort uVar1;
  c1_type *type;
  uint lo;
  int iVar2;
  void *pvVar3;
  c1_node *pcVar4;
  byte bVar5;
  uint hi;
  longlong lVar6;
  ulonglong uVar7;
  
  diag_warning(2,0x92);
  if ((operand->kind & 7) != 3) {
    return node;
  }
  type = operand->type;
  uVar1 = type->code;
  if (((byte)uVar1 >> 5 & 1) == 0) {
    lo = -(int)operand->left;
    hi = -((int)operand->right + (uint)(operand->left != (void *)0x0));
    uVar7 = CONCAT44(hi,lo);
    if ((uVar1 & 0x2000) == 0) {
      if ((((g_ms_extensions == '\0') && ((uVar1 & 0xfff) == 0x11)) && ((uVar1 & 0x1000) == 0)) &&
         (g_opt_J_unsigned_char != '\0')) {
        pcVar4 = fold_truncate_to_type_width(lo,hi,type,operand,node);
        return pcVar4;
      }
      bVar5 = ('\b' - (&g_type_rank_table)[uVar1 & 0xf]) * '\b';
      lVar6 = _allshl(bVar5,lo,hi);
      uVar7 = _allshr(bVar5,(int)((ulonglong)lVar6 >> 0x20),(uint)lVar6);
    }
    uVar1 = type->code;
    if ((-1 < (char)uVar1) &&
       (((uVar1 & 0x2000) != 0 ||
        ((((g_ms_extensions == '\0' && ((uVar1 & 0xfff) == 0x11)) &&
          (((uVar1 & 0x1000) == 0 && (g_opt_J_unsigned_char != '\0')))) ||
         ((-1 < (longlong)uVar7 && (uVar7 != 0)))))))) {
      bVar5 = ('\b' - (&g_type_rank_table)[uVar1 & 0xf]) * '\b';
      lVar6 = _allshl(bVar5,(uint)uVar7,(uint)(uVar7 >> 0x20));
      uVar7 = _aullshr(bVar5,(uint)((ulonglong)lVar6 >> 0x20),(uint)lVar6);
    }
    operand->type = node->type;
    operand->left = (void *)(int)uVar7;
    operand->right = (void *)(int)(uVar7 >> 0x20);
    return operand;
  }
  iVar2 = float_fold_subtract_constants(&g_float_zero,operand->left,(float_const *)&stack0x00000010)
  ;
  if (iVar2 != 0) {
    diag_warning(2,0x38);
  }
  pvVar3 = record3_new_from((int *)&stack0x00000010,g_expr_arena_index);
  operand->left = pvVar3;
  return operand;
}

