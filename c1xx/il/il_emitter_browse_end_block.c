void __thiscall il_emitter_browse_end_block(c1xx_il_emitter_browse *this)

{
  if (0 < g_browse_block_depth) {
    g_browse_block_depth = g_browse_block_depth + -1;
    browse_add_record(9,(int *)0x0);
    return;
  }
  g_browse_block_depth = 0;
  return;
}

