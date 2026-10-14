void __cdecl stmt_block_end(void)

{
  c1_node *node;
  c1_scope_object *in_ECX;
  c1_scope_object *pcStack_4;
  
  if (g_block_depth != '\0') {
    (*g_il_emitter->vtbl->end_block)();
    if (g_block_depth == '\x02') {
      g_block_scope_number = 0;
    }
    pcStack_4 = in_ECX;
    if (((byte)g_compile_flags_c4 & 0x20) == 0) {
      if (g_ilstore_status == 4) {
        if (g_block_depth == '\x01') {
          scope_pop_child(g_current_scope);
        }
      }
      else {
        pcStack_4 = g_current_scope->current;
        if (g_block_depth != pcStack_4->level) {
          diag_fatal_simple(0x1fa);
        }
        scope_pop_child(g_current_scope);
        stmt_emit_pending_destructors();
      }
    }
    if ((g_opt_Zg == '\0') && (g_ilstore_status != 4)) {
      if (((byte)g_compile_flags_c4 & 0x20) == 0) {
        scope_link_closed_block(g_current_scope,(int)pcStack_4);
      }
      node = tree_new_int_constant((uint)g_block_depth);
      il_emit_tuple(0x54,node);
    }
    g_il_block_level = g_block_depth + 0xff;
    g_block_depth = g_il_block_level;
  }
  return;
}

