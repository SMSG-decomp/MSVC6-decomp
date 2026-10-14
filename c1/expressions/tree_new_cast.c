c1_node * __cdecl tree_new_cast(c1_type *type,c1_node *operand)

{
  c1_node *pcVar1;
  
  pcVar1 = tree_new_unary('d',type,operand);
  return pcVar1;
}

