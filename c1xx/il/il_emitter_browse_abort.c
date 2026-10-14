void __thiscall il_emitter_browse_abort(c1xx_il_emitter_browse *this)

{
  FILE *saved_out_file;
  
  saved_out_file = g_browse_out_file;
  browse_add_record(0xe,(int *)0x0);
  browse_flush_queue();
  g_browse_out_file = saved_out_file;
  return;
}

