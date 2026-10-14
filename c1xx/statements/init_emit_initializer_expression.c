byte __cdecl init_emit_initializer_expression(c1_node *node,c1_conversion *conv)

{
  c1_node *node_00;
  
  if (node->op == '\x06') {
    conv->target_symbol = node->left;
    conv->target_kind = 3;
  }
  else {
    conv->target_symbol = (c1_symbol *)0x0;
    conv->target_kind = 6;
  }
  node_00 = conv_apply_conversion(conv,node);
  if ((g_brace_init_active != 0) || (PTR_104d2c58 != (c1_symbol *)0x0)) {
    node_00 = expr_full_expression_guarded(node_00,2);
  }
  stmt_emit_expression(node_00);
  return 1;
}

