void __cdecl stmt_define_label(int name)

{
  c1_symbol *label;
  c1_node *node;
  
  label = label_find_in_function((void *)name);
  if (label == (c1_symbol *)0x0) {
    label = label_new_user(name);
    label->flags3 = label->flags3 | 0x20;
    label_register(label);
  }
  else if ((label->flags1 & 1) != 0) {
    diag_error(0x2d,name);
  }
  label->position = g_token_position;
  node = tree_new_node_typed('\x06',label,(c1_type *)0x0);
  label_emit_definition(node);
  return;
}

