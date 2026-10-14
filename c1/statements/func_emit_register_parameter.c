void __cdecl func_emit_register_parameter(c1_symbol *sym)

{
  c1_node *node;
  
  node = tree_new_symbol_ref(sym);
  il_emit_tuple(0x2a,node);
  list_push_in_arena((int *)&g_pending_destructor_list,2);
  g_pending_destructor_list->value = sym;
  list_push_in_arena((int *)&g_pending_destructor_list,2);
  g_pending_destructor_list->value = (void *)0x1;
  return;
}

