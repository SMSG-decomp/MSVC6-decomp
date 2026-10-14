c1_node * __thiscall conv_build_integral_conversion(c1_conversion *conv,c1_node *dest)

{
  c1_u8 cVar1;
  ushort uVar2;
  c1_type *pcVar3;
  char *pcVar4;
  bool bVar5;
  bool bVar6;
  char cVar7;
  byte bVar8;
  c1_node *pcVar9;
  c1_symbol *pcVar10;
  int iVar11;
  uint uVar12;
  
  pcVar9 = fold_static_const_member(conv->expr);
  if ((pcVar9->kind & 7) == 3) {
    conv->expr = pcVar9;
    pcVar9 = conv_build_integral_constant(conv,dest);
    return pcVar9;
  }
  cVar7 = conv_constant_warnings_enabled(conv);
  if (cVar7 == '\0') goto LAB_1042d5c8;
  pcVar3 = conv->target;
  uVar12 = (uint)conv->source->code;
  pcVar10 = (pcVar3->extra).cls;
  bVar8 = (&g_type_rank_table)[(byte)pcVar3->code & 0xf];
  if (((byte)(&g_type_rank_table)[uVar12 & 0xf] <= bVar8) && ((int)pcVar10 < 1)) goto LAB_1042d5c8;
  bVar5 = false;
  bVar6 = false;
  if ((conv->expr->op == '=') && (pcVar4 = conv->expr->left, *pcVar4 == '5')) {
    bVar6 = true;
    iVar11 = *(int *)(*(int *)(*(int *)(pcVar4 + 0x14) + 0x14) + 0x10);
  }
  else {
    iVar11 = (int)(char)(&g_type_rank_table)[uVar12 & 0xf] << 3;
  }
  if ((int)pcVar10 < 1) {
    if (iVar11 <= (char)bVar8 * 8) goto LAB_1042d6ab;
LAB_1042d614:
    if (bVar6) {
      if (pcVar10 == (c1_symbol *)0x0) {
        pcVar10 = (c1_symbol *)((int)(char)bVar8 << 3);
      }
      diag_warning(4,0xfe,(uint)conv->op,conv->source,iVar11,pcVar3,pcVar10);
      goto LAB_1042d6ab;
    }
  }
  else {
    if ((((int)pcVar10 < iVar11) && (bVar6)) && ((uVar12 & 0xfff) != 0x10)) goto LAB_1042d614;
LAB_1042d6ab:
    bVar5 = true;
  }
  if (((conv->source->code & 0x1f) == 0x13) &&
     ((cVar1 = conv->expr->op, cVar1 == 'p' || (cVar1 == '=')))) {
    if (bVar5) goto LAB_1042d5c8;
    bVar8 = diag_warning(3,0xf2,(uint)conv->op,conv->source,conv->target);
    if (bVar8 != 0) {
      pcVar9 = conv_apply_standard_conversion(conv,dest);
      return pcVar9;
    }
  }
  else if (bVar5) goto LAB_1042d5c8;
  uVar2 = conv->source->code;
  if ((((byte)uVar2 & 0x1f) == 0x13) || (iVar11 = 3, (uVar2 & 0x100) != 0)) {
    iVar11 = 4;
  }
  diag_warning(iVar11,0xf4,(uint)conv->op,conv->source,conv->target);
LAB_1042d5c8:
  pcVar9 = conv_apply_standard_conversion(conv,dest);
  return pcVar9;
}

