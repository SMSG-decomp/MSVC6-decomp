void stmt_block_begin(void)

{
  (*g_il_emitter->vtbl->begin_block)();
  if (g_block_depth < 0xf9) {
    g_il_block_level = g_block_depth + '\x01';
    g_block_scope_number = g_block_scope_number + 1;
    g_block_depth = g_il_block_level;
    if (g_ilstore_status != 4) {
      if (((byte)g_compile_flags_c4 & 0x20) == 0) {
        hash_scope_new_block(g_current_scope);
      }
      if (g_opt_Zg == '\0') {
        il_emit_tuple(0x53,(c1_node *)0x0);
      }
    }
    return;
  }
  diag_fatal_simple(0x3d);
}

