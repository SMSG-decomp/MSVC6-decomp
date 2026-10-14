c1_node * __cdecl expr_array_to_pointer_tail(c1_symbol *sym,c1_node *node)

{
  c1_type *pcVar1;
  
  node->type = sym->type;
  pcVar1 = conv_array_to_pointer_type(node);
  node->type = pcVar1;
  return node;
}

