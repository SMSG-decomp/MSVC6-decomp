void __cdecl stmt_switch_head(c1_node *node)

{
  byte bVar1;
  c1_type *pcVar2;
  c1_node *pcVar3;
  int iVar4;
  uint uVar5;
  
  stmt_new_loop_label(&g_loop_top_label_stack,0x11);
  stmt_new_loop_label(&g_break_label_stack,0x12);
  stmt_new_loop_label((c1_label_cell **)&g_switch_case_stack,0x13);
  g_switch_case_stack->cases = (c1_case_record *)0x0;
  stmt_new_loop_label(&g_default_label_stack,0x14);
  g_default_label_stack->label = (c1_node *)0x0;
  if (node == (c1_node *)0x0) {
    g_loop_top_label_stack->label->type = g_type_int;
    return;
  }
  bVar1 = node->kind & 7;
  if (bVar1 == 1) {
    if (node->op != '<') goto switchD_1061eab9_caseD_33;
    uVar5 = 0x3c;
LAB_10636f18:
    diag_warning(1,0x90,uVar5);
  }
  else {
    if (bVar1 != 2) goto switchD_1061eab9_caseD_33;
    bVar1 = node->op;
    uVar5 = (uint)bVar1;
    switch(uVar5) {
    case 0x32:
    case 0x3b:
    case 0x4f:
      if (bVar1 == 0x32) {
        iVar4 = 0x31;
      }
      else {
        iVar4 = (-(uint)(bVar1 != 0x4f) & 0xffffffe7) + 0x4d;
      }
      diag_warning(1,0x91,uVar5,iVar4);
      break;
    case 0x3e:
    case 0x3f:
    case 0x44:
    case 0x45:
    case 0x4c:
      goto LAB_10636f18;
    }
  }
switchD_1061eab9_caseD_33:
  if ((node->type->code & 0x110) == 0) {
    diag_error(0x32);
    pcVar3 = g_loop_top_label_stack->label;
    pcVar2 = g_type_int;
  }
  else {
    node = (c1_node *)expr_apply_implicit_conversion(node);
    pcVar3 = g_loop_top_label_stack->label;
    pcVar2 = node->type;
  }
  pcVar3->type = pcVar2;
  pcVar3 = tree_new_unary(0x85,node->type,node);
  PTR_106692dc = g_loop_top_label_stack->label->left;
  il_emit_pragma_or_segment_record(0x24);
  il_emit_expression_tree(pcVar3);
  return;
}

