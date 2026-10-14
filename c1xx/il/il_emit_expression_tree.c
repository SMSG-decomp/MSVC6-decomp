void __cdecl il_emit_expression_tree(c1_node *node)

{
  char cVar1;
  node *pnVar2;
  void *pvVar3;
  uint uVar4;
  c1_type *pcVar5;
  byte bVar6;
  ushort uVar7;
  c1_node *pcVar8;
  c1_node *pcVar9;
  c1_node *pcVar10;
  int iVar11;
  c1_sym_link *pcVar12;
  c1_u32 *pcVar13;
  c1_type *pcVar14;
  
  pcVar10 = node;
joined_r0x10428eaf:
  if (g_error_count != 0) {
    return;
  }
LAB_10428eb7:
  if (pcVar10 == (c1_node *)0x0) {
    return;
  }
  if ((g_token_op_flags[pcVar10->op] & 0x80) == 0) goto switchD_10428f13_caseD_8;
  switch((uint)pcVar10->op) {
  case 7:
    pcVar10 = expr_string_literal(pcVar10);
    il_emit_tuple(g_tree_op_to_il_op[pcVar10->op],pcVar10);
    return;
  case 0x3d:
    pcVar10 = fold_static_const_member(pcVar10);
    break;
  case 0x5d:
    if (pcVar10->right == (void *)0x0) {
      pcVar8 = tree_new_unary('\x17',g_type_unsigned_int,(c1_node *)0x0);
      pcVar10->right = pcVar8;
    }
    break;
  case 100:
    if (((byte)pcVar10->type->code >> 6 & 1) != 0) goto LAB_10428f44;
    uVar7 = pcVar10->type->code & 0x8f;
    if ((uVar7 != 0x8a) && (uVar7 != 0x8e)) break;
    pcVar10 = pcVar10->left;
    goto LAB_10428eb7;
  case 0x6c:
    pcVar8 = pcVar10->left;
    pcVar13 = (c1_u32 *)0x0;
    pcVar9 = pcVar8;
    if (pcVar8->op == 0x99) {
      pcVar9 = pcVar8->left;
    }
    pvVar3 = pcVar9->left;
    uVar4 = *(uint *)((int)pvVar3 + 0x18);
    il_emit_expression_tree(pcVar8);
    *(uint *)((int)pvVar3 + 0x18) =
         (*(uint *)((int)pvVar3 + 0x18) ^ uVar4 & 3) & 3 ^ *(uint *)((int)pvVar3 + 0x18);
    il_emit_tuple(g_tree_op_to_il_op[pcVar10->op],pcVar10);
    if (((*(byte *)((int)pvVar3 + 1) & 4) != 0) && ((*(byte *)((int)pvVar3 + 0x34) & 1) != 0)) {
      if (g_function_parameter_scope == (c1_sym_list *)0x0) {
        pcVar12 = (c1_sym_link *)0x0;
      }
      else {
        pcVar12 = g_function_parameter_scope->head;
      }
      if (pcVar12 != (c1_sym_link *)0x0) {
        pcVar13 = &pcVar12[-1].position;
        bVar6 = *(byte *)((int)&pcVar12[-1].position + 2);
        node._0_1_ = bVar6 >> 3 & 1;
        *(byte *)((int)&pcVar12[-1].position + 2) = bVar6 | 8;
      }
    }
    if (g_function_parameter_scope == (c1_sym_list *)0x0) {
      pcVar14 = (c1_type *)0x0;
    }
    else {
      pcVar14 = (c1_type *)g_function_parameter_scope->tail;
    }
    goto joined_r0x10429172;
  case 0x70:
  case 0x9d:
    goto switchD_10428f13_caseD_70;
  case 0x77:
    iVar11 = expr_fold_string_intrinsic(pcVar10);
    if (iVar11 != 0) {
      return;
    }
switchD_10428f13_caseD_70:
    il_emit_expression_tree(pcVar10->left);
    il_emit_tuple(g_tree_op_to_il_op[pcVar10->op],pcVar10);
    for (pnVar2 = pcVar10->right; pnVar2 != (node *)0x0; pnVar2 = pnVar2->right) {
      il_emit_expression_tree(pnVar2->left);
      il_emit_tuple(0x55,pnVar2);
    }
    il_emit_tuple(0x4c,(node *)0x0);
    return;
  case 0x84:
    il_emit_expression_tree(pcVar10->left);
    il_emit_tuple(g_tree_op_to_il_op[pcVar10->op],pcVar10);
    for (pnVar2 = pcVar10->right; pnVar2 != (node *)0x0; pnVar2 = *(node **)pnVar2) {
      pcVar14 = pcVar10->type;
      cVar1 = (char)pcVar14->code;
      pcVar5 = pcVar14;
      while (cVar1 < '\0') {
        pcVar5 = pcVar5->base;
        cVar1 = (char)pcVar5->code;
      }
      cVar1 = (char)pcVar14->code;
      while (cVar1 < '\0') {
        pcVar14 = pcVar14->base;
        cVar1 = (char)pcVar14->code;
      }
      pcVar8 = tree_new_three_fields_flagged
                         ((uint)pnVar2->link,pnVar2->unk0c,
                          (int)(char)(&g_type_rank_table)[(byte)pcVar5->code & 0xf]);
      pcVar9 = tree_new_three_fields_flagged
                         ((uint)pnVar2->link,pnVar2->unk0c,
                          (int)(char)(&g_type_rank_table)[(byte)pcVar14->code & 0xf]);
      il_emit_tuple(g_tree_op_to_il_op[pcVar9->op],pcVar8);
      il_emit_tuple(0x3d,pnVar2);
    }
    il_emit_tuple(0x4c,(node *)0x0);
    return;
  case 0xc1:
    *(byte *)((int)&g_current_function->tail + 10) =
         *(byte *)((int)&g_current_function->tail + 10) | 8;
    *(byte *)((int)&g_current_function->tail + 10) =
         (g_opt_eh & 1) << 1 | *(byte *)((int)&g_current_function->tail + 10) & 0xfd;
    il_emit_expression_tree(*(c1_node **)((int)pcVar10->right + 0x10));
    il_emit_expression_tree(*(c1_node **)((int)pcVar10->right + 0x14));
    iVar11 = eh_state_of_entry(*(int *)((int)pcVar10->left + 0x10));
    uVar7 = *(ushort *)((int)pcVar10->left + 0x16);
    goto LAB_10429237;
  case 0xc2:
  case 0xc3:
    iVar11 = eh_state_of_entry((int)pcVar10->left);
    uVar7 = *(ushort *)((int)&pcVar10->right + 2);
LAB_10429237:
    switch(iVar11) {
    case 4:
    case 9:
      uVar7 = uVar7 | 2;
      break;
    case 5:
      uVar7 = uVar7 | 8;
    case 1:
    case 2:
    case 3:
    case 7:
      uVar7 = uVar7 | 1;
      break;
    case 6:
      uVar7 = uVar7 | 3;
      break;
    case 8:
      uVar7 = uVar7 | 4;
    }
    if (g_opt_eh == 0) {
      uVar7 = uVar7 | 0x10;
    }
    *(ushort *)((int)&pcVar10->right + 2) = uVar7;
    goto LAB_10428ee8;
  }
switchD_10428f13_caseD_8:
  bVar6 = pcVar10->kind;
  if ((bVar6 & 7) == 0) {
    if ((bVar6 & 0x40) != 0) {
      diag_error(0x7c);
      return;
    }
  }
  else if ((bVar6 & 7) == 1) {
    il_emit_expression_tree(pcVar10->left);
  }
  else if ((bVar6 & 7) == 2) {
    il_emit_expression_tree(pcVar10->left);
    il_emit_expression_tree(pcVar10->right);
  }
LAB_10428ee8:
  il_emit_tuple(g_tree_op_to_il_op[pcVar10->op],pcVar10);
  return;
joined_r0x10429172:
  if (pcVar14 == (c1_type *)0x0) {
LAB_104291a4:
    if (pcVar13 != (c1_u32 *)0x0) {
      if ((byte)node == 0) {
        bVar6 = *(byte *)((int)pcVar13 + 2) & 0xf7;
      }
      else {
        bVar6 = *(byte *)((int)pcVar13 + 2) | 8;
      }
      *(byte *)((int)pcVar13 + 2) = bVar6;
    }
    il_emit_tuple(0x4c,(node *)0x0);
    return;
  }
  if (((((c1_sym_link *)(pcVar14 + -1))->position & 0x80000) == 0) &&
     ((bVar6 = (byte)((c1_sym_link *)(pcVar14 + -1))->position & 0x1f, bVar6 == 0xb ||
      (bVar6 == 0xc)))) {
    pcVar10 = tree_new_symbol_ref((c1_symbol *)&((c1_sym_link *)(pcVar14 + -1))->position,'\0');
    il_emit_tuple(0x2d,pcVar10);
  }
  if (pcVar14 == (c1_type *)0x0) goto LAB_104291a4;
  pcVar14 = (((c1_sym_link *)(pcVar14 + 1))->type).type;
  goto joined_r0x10429172;
LAB_10428f44:
  pcVar8 = tree_new_int_constant(0);
  pcVar8->type = g_type_void;
  pcVar10 = tree_new_node('7',pcVar10->left,pcVar8,g_type_void);
  goto joined_r0x10428eaf;
}

