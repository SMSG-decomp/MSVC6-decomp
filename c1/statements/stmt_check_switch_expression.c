void __cdecl stmt_check_switch_expression(c1_node *node)

{
  c1_type *pcVar1;
  c1_node *pcVar2;
  
  diag_warning(1,0x91);
  if ((node->type->code & 0x110) == 0) {
    diag_error(0x32);
    pcVar2 = g_loop_top_label_stack->label;
    pcVar1 = g_type_int;
  }
  else {
    node = (c1_node *)expr_apply_implicit_conversion(node);
    pcVar2 = g_loop_top_label_stack->label;
    pcVar1 = node->type;
  }
  pcVar2->type = pcVar1;
  pcVar2 = tree_new_unary(0x85,node->type,node);
  PTR_106692dc = g_loop_top_label_stack->label->left;
  il_emit_pragma_or_segment_record(0x24);
  il_emit_expression_tree(pcVar2);
  return;
}

