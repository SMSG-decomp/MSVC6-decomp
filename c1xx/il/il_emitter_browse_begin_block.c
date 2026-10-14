void __thiscall il_emitter_browse_begin_block(c1xx_il_emitter_browse *this)

{
  g_browse_block_depth = g_browse_block_depth + 1;
  browse_add_record(8,(int *)0x0);
  return;
}

