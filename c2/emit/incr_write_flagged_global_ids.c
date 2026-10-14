void incr_write_flagged_global_ids(void)

{
  c2_fe_symbol *prev;
  
  for (prev = scope_iter_next(&g_global_scope,(c2_fe_symbol *)0x0); prev != (c2_fe_symbol *)0x0;
      prev = scope_iter_next(&g_global_scope,prev)) {
    if ((prev->attrs & 0x10000) != 0) {
      incr_stream_put_dword(prev->id);
    }
  }
  incr_stream_put_dword(0);
  return;
}

