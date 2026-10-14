c1_node * __cdecl init_emit_runtime_assignment(c1_node *object,c1_node *value)

{
  c1_node *pcVar1;
  
  pcVar1 = tree_new_rvalue(object);
  pcVar1 = expr_build_binary('t',pcVar1,value);
  stmt_emit_expression(pcVar1);
  return (c1_node *)0x1;
}

