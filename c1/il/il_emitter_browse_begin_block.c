void il_emitter_browse_begin_block(void)

{
  g_browse_block_depth = g_browse_block_depth + 1;
  browse_add_record(8,(c1_symbol *)0x0);
  return;
}

