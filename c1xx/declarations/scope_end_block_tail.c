void __cdecl scope_end_block_tail(int scope)

{
  c1_node *n;
  
  if ((g_opt_Zg == '\0') && (g_ilstore_status != 4)) {
    if (((byte)g_compile_flags_c4 & 0x20) == 0) {
      scope_link_closed_block(g_current_scope,(c1xx_scope *)scope);
    }
    n = tree_new_int_constant((uint)g_block_depth);
    il_emit_tuple(0x54,n);
  }
  g_block_depth = g_block_depth + 0xff;
  g_il_block_level = g_block_depth;
  return;
}

