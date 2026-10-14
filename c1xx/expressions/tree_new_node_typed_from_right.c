c1_node * __cdecl tree_new_node_typed_from_right(c1_u8 op,c1_symbol *sym)

{
  c1_node *pcVar1;
  
  pcVar1 = tree_new_node_typed(op,sym,sym->type);
  return pcVar1;
}

