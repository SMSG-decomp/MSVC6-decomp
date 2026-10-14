void __cdecl class_build_scalar_deleting_dtor_body(c1_symbol *cls)

{
  c1_node *node;
  
  node = expr_this_pointer((c1_symbol *)0x0);
  class_build_destroy_and_delete(cls);
  func_flow_state_note_8();
  stmt_emit_return_value(node,2);
  return;
}

