int __cdecl init_element_access(c1_node *node,c1_node *list)

{
  c1_node *pcVar1;
  c1_node *left;
  
  pcVar1 = init_chain_as_comma_list(list);
  expr_make_reusable(&list,&node);
  left = expr_build_builtin_unary(0x3d,node);
  node = expr_build_builtin_binary('4',left,pcVar1);
  node = expr_assignment_as_lvalue(node);
  pcVar1 = expr_build_null_guarded(list,node);
  return (int)pcVar1;
}

