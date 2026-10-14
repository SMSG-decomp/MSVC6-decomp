void __cdecl stmt_switch_end(void)

{
  void *pvVar1;
  c1_node *node;
  
  node = tree_new_binary(0x84,g_loop_top_label_stack->label,g_switch_case_stack->cases);
  node->type = g_loop_top_label_stack->label->type;
  pvVar1 = g_loop_top_label_stack->label->left;
  *(byte *)((int)pvVar1 + 2) = *(byte *)((int)pvVar1 + 2) | 4;
  *(c1_u8 *)((int)g_loop_top_label_stack->label->left + 0x28) = g_block_depth;
  if (g_default_label_stack->label == (c1_node *)0x0) {
    PTR_104de3b4 = *(c1_symbol **)(*(int *)((int)g_break_label_stack + 4) + 0x10);
  }
  else {
    PTR_104de3b4 = g_default_label_stack->label->left;
  }
  il_emit_expression_tree(node);
  label_emit_definition(*(c1_node **)((int)g_break_label_stack + 4));
  return;
}

