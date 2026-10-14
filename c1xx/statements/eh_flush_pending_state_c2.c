void __cdecl eh_flush_pending_state_c2(void)

{
  c1_node *tree;
  
  if (0 < g_eh_pending_unwind_count) {
    tree = tree_new_node_with_fields
                     (0xc2,(ushort)g_eh_pending_unwind_count,(void *)g_eh_pending_unwind_state,0);
    stmt_emit_merged_expression(tree);
    g_eh_pending_unwind_count = 0;
  }
  g_eh_unresolved_dtor_class = (c1_symbol *)0x0;
  g_eh_ctor_return_flushed = '\x01';
  return;
}

