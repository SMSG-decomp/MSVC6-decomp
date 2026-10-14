void il_emitter_browse_end_block(void)

{
  if (0 < g_browse_block_depth) {
    g_browse_block_depth = g_browse_block_depth + -1;
    browse_add_record(9,(c1_symbol *)0x0);
    return;
  }
  g_browse_block_depth = 0;
  return;
}

