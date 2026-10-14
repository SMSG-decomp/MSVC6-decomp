void __cdecl stmt_define_label(int name)

{
  c1_symbol *label;
  c1_node *labelref;
  
  label = (c1_symbol *)label_find_in_function(name);
  if (label == (c1_symbol *)0x0) {
    label = (c1_symbol *)label_new_user(name);
    label->flags4 = label->flags4 | 0x20;
    label_register(label);
  }
  else if ((label->flags2 & 4) != 0) {
    diag_error(0x2d,name);
  }
  label->position = g_token_position;
  stmt_label_definition_flow_state(label);
  labelref = tree_new_node_typed('\x06',label,(c1_type *)0x0);
  label_emit_definition(labelref);
  return;
}

