c1_node * __cdecl init_element_lvalue(c1_type *type)

{
  int iVar1;
  c1_node *pcVar2;
  c1_node *left;
  
  iVar1 = sym_has_scalar_type(g_init_symbol);
  if (iVar1 == 0) {
    pcVar2 = tree_new_int_constant(g_init_offset);
    left = tree_new_symbol_ref(g_init_symbol);
    pcVar2 = tree_new_node('P',left,pcVar2,type);
    return pcVar2;
  }
  pcVar2 = tree_new_symbol_ref(g_init_symbol);
  return pcVar2;
}

