c1_type * __cdecl tree_new_scope_chain_list(int sym)

{
  int key;
  c1_type *pcVar1;
  
  if (*(short *)(sym + 6) != 0) {
    pcVar1 = tree_new_scope_chain_list((int)g_scope_vector->entries[*(short *)(sym + 6)]);
    key._0_2_ = pcVar1->code;
    key._2_2_ = pcVar1->flags;
    pcVar1 = (c1_type *)tree_new_list_cell((c1_keyed_list *)0x0,key,(c1_symbol *)sym);
    return pcVar1;
  }
  pcVar1 = (c1_type *)tree_new_list_cell((c1_keyed_list *)0x0,0,(c1_symbol *)sym);
  return pcVar1;
}

