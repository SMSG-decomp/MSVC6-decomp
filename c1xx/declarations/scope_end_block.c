void __cdecl scope_end_block(void)

{
  c1_node *n;
  c1xx_scope *in_ECX;
  c1xx_scope *closed_block;
  
  if (g_block_depth != '\0') {
    (*g_il_emitter->vtbl->end_block)();
    if (g_ilstore_status == 4) {
      if (g_block_depth == '\x02') {
        g_block_number = 0;
      }
    }
    else if ((1 < g_block_depth) && (func_flow_state_pop(), g_block_depth == '\x02')) {
      if ((g_function_return_type != (c1_type *)0x0) && ((g_compile_flags_c8 & 0x800) == 0)) {
        stmt_emit_return_value((c1_node *)0x0,0);
      }
      g_block_number = 0;
      if (((g_current_function->flags1 & 0x10) == 0x10) ||
         ((g_current_function->flags1 & 0x20) == 0x20)) {
        stmt_check_missing_return_value();
      }
      else {
        eh_check_try_with_unwinding();
      }
    }
    if (((byte)g_compile_flags_c4 & 0x20) == 0) {
      if (g_ilstore_status == 4) {
        if (g_block_depth == '\x01') {
          scope_pop_child(g_current_scope);
          scope_end_block_tail((int)in_ECX);
          return;
        }
      }
      else {
        in_ECX = g_current_scope->current;
        if (g_block_depth != in_ECX->kind) {
          diag_fatal_simple(0x1fa);
        }
        scope_pop_child(g_current_scope);
        stmt_emit_pending_destructors();
      }
    }
    if ((g_opt_Zg == '\0') && (g_ilstore_status != 4)) {
      if (((byte)g_compile_flags_c4 & 0x20) == 0) {
        scope_link_closed_block(g_current_scope,in_ECX);
      }
      n = tree_new_int_constant((uint)g_block_depth);
      il_emit_tuple(0x54,n);
    }
    g_il_block_level = g_block_depth + 0xff;
    g_block_depth = g_il_block_level;
  }
  return;
}

