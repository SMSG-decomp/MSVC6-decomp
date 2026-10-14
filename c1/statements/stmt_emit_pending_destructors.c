void stmt_emit_pending_destructors(void)

{
  c1_node *node;
  
  if (g_opt_Zg == '\0') {
    while ((g_pending_destructor_list != (c1_list_cell *)0x0 &&
           (g_block_depth == *(c1_u8 *)&g_pending_destructor_list->value))) {
      list_pop_head((int *)&g_pending_destructor_list);
      node = tree_new_symbol_ref(g_pending_destructor_list->value);
      il_emit_tuple(0x2b,node);
      list_pop_head((int *)&g_pending_destructor_list);
    }
  }
  return;
}

