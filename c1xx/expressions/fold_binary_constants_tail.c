c1_node * __cdecl fold_binary_constants_tail(c1_type *type)

{
  c1_node *pcVar1;
  
  pcVar1 = tree_new_constant(type,&g_constant_value,g_expr_arena_index);
  return pcVar1;
}

