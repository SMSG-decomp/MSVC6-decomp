void __cdecl stmt_emit_pending_destructors(void)

{
  c1_node *n;
  
  if (g_opt_Zg == '\0') {
    while ((g_pending_destructor_list != (c1_value_cell *)0x0 &&
           (g_block_depth == (c1_u8)g_pending_destructor_list->value))) {
      list_pop_head((int *)&g_pending_destructor_list);
      n = tree_new_symbol_ref((c1_symbol *)g_pending_destructor_list->value,'\0');
      il_emit_tuple(0x2b,n);
      list_pop_head((int *)&g_pending_destructor_list);
    }
  }
  return;
}

