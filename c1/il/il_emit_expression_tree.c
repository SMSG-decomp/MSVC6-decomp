void __cdecl il_emit_expression_tree(c1_node *node)

{
  char cVar1;
  c1_type *pcVar2;
  void *pvVar3;
  uint uVar4;
  c1_type *pcVar5;
  byte bVar6;
  int iVar7;
  c1_node *node_00;
  c1_node *pcVar8;
  c1_node *pcVar9;
  int *piVar10;
  
  if (g_error_count == 0) {
    while (node != (c1_node *)0x0) {
      if (((&g_token_attributes)[node->op] & 0x80) == 0) goto switchD_10618b51_caseD_8;
      switch((uint)node->op) {
      case 7:
        pcVar9 = expr_string_literal(node);
        il_emit_tuple(g_tree_op_to_il_op[pcVar9->op],pcVar9);
        return;
      case 0x5d:
        if (node->right == (void *)0x0) {
          pcVar9 = tree_new_unary('\x17',g_type_unsigned_int,(c1_node *)0x0);
          node->right = pcVar9;
        }
      default:
switchD_10618b51_caseD_8:
        bVar6 = node->kind;
        if ((bVar6 & 7) == 0) {
          if ((bVar6 & 0x40) != 0) {
            diag_error(0x7c);
            return;
          }
        }
        else if ((bVar6 & 7) == 1) {
          il_emit_expression_tree(node->left);
        }
        else if ((bVar6 & 7) == 2) {
          il_emit_expression_tree(node->left);
          il_emit_expression_tree(node->right);
        }
        il_emit_tuple(g_tree_op_to_il_op[node->op],node);
        return;
      case 100:
        if (((byte)node->type->code >> 6 & 1) == 0) goto switchD_10618b51_caseD_8;
        pcVar9 = tree_new_int_constant(0);
        pcVar9->type = g_type_void;
        node = tree_new_node('7',node->left,pcVar9,g_type_void);
        if (g_error_count != 0) {
          return;
        }
        break;
      case 0x6c:
        pvVar3 = node->left->left;
        uVar4 = *(uint *)((int)pvVar3 + 0x18);
        il_emit_expression_tree(node->left);
        *(uint *)((int)pvVar3 + 0x18) =
             (*(uint *)((int)pvVar3 + 0x18) ^ uVar4 & 3) & 3 ^ *(uint *)((int)pvVar3 + 0x18);
        il_emit_tuple(g_tree_op_to_il_op[node->op],node);
        if (g_function_parameter_scope == (c1_scope_symbol_list *)0x0) {
          piVar10 = (int *)0x0;
        }
        else {
          piVar10 = g_function_parameter_scope->last;
        }
        goto joined_r0x10618d31;
      case 0x70:
        goto switchD_10618b51_caseD_70;
      case 0x77:
        iVar7 = expr_fold_string_intrinsic(node);
        if (iVar7 != 0) {
          return;
        }
        goto switchD_10618b51_caseD_70;
      case 0x84:
        il_emit_expression_tree(node->left);
        il_emit_tuple(g_tree_op_to_il_op[node->op],node);
        for (pcVar9 = node->right; pcVar9 != (c1_node *)0x0; pcVar9 = *(c1_node **)pcVar9) {
          pcVar2 = node->type;
          cVar1 = (char)pcVar2->code;
          pcVar5 = pcVar2;
          while (cVar1 < '\0') {
            pcVar5 = pcVar5->base;
            cVar1 = (char)pcVar5->code;
          }
          cVar1 = (char)pcVar2->code;
          while (cVar1 < '\0') {
            pcVar2 = pcVar2->base;
            cVar1 = (char)pcVar2->code;
          }
          node_00 = tree_new_three_fields_flagged
                              ((c1_u32)pcVar9->link,pcVar9->unk0c,
                               (int)(char)(&g_type_rank_table)[(byte)pcVar5->code & 0xf]);
          pcVar8 = tree_new_three_fields_flagged
                             ((c1_u32)pcVar9->link,pcVar9->unk0c,
                              (int)(char)(&g_type_rank_table)[(byte)pcVar2->code & 0xf]);
          il_emit_tuple(g_tree_op_to_il_op[pcVar8->op],node_00);
          il_emit_tuple(0x3d,pcVar9);
        }
        il_emit_tuple(0x4c,(c1_node *)0x0);
        return;
      }
    }
  }
  return;
joined_r0x10618d31:
  if (piVar10 == (int *)0x0) {
LAB_10618d69:
    il_emit_tuple(0x4c,(c1_node *)0x0);
    return;
  }
  if (((*(byte *)((int)piVar10 + -7) & 2) == 0) &&
     ((bVar6 = ((c1_symbol *)(piVar10 + -2))->kind & 0x1f, bVar6 == 0xb || (bVar6 == 0xc)))) {
    pcVar9 = tree_new_symbol_ref((c1_symbol *)(piVar10 + -2));
    il_emit_tuple(0x2d,pcVar9);
  }
  if (piVar10 == (int *)0x0) goto LAB_10618d69;
  piVar10 = (int *)piVar10[7];
  goto joined_r0x10618d31;
switchD_10618b51_caseD_70:
  il_emit_expression_tree(node->left);
  il_emit_tuple(g_tree_op_to_il_op[node->op],node);
  for (pcVar9 = node->right; pcVar9 != (c1_node *)0x0; pcVar9 = pcVar9->right) {
    il_emit_expression_tree(pcVar9->left);
    il_emit_tuple(0x55,pcVar9);
  }
  il_emit_tuple(0x4c,(c1_node *)0x0);
  return;
}

