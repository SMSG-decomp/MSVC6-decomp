void __cdecl eh_register_local_destructor(c1_symbol *sym)

{
  c1_node *n;
  
  n = tree_new_symbol_ref(sym,'\0');
  il_emit_tuple(0x2a,n);
  list_push_in_arena((int *)&g_pending_destructor_list,4);
  g_pending_destructor_list->value = (int)sym;
  list_push_in_arena((int *)&g_pending_destructor_list,4);
  g_pending_destructor_list->value = 1;
  return;
}

