void __cdecl class_build_vbase_dtor_body(c1_symbol *cls)

{
  c1_node *obj;
  c1_node *node;
  
  obj = expr_this_pointer((c1_symbol *)0x0);
  node = expr_build_destructor_call(cls,obj,1,1,0);
  stmt_emit_expression(node);
  access_set_special_member_context('\x01');
  class_build_vbase_destructor_calls(cls,obj);
  access_set_special_member_context('\0');
  return;
}

