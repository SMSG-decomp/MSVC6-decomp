void incr_write_free_ranges(void)

{
  c2_coff_free_range *range;
  
  for (range = g_coff_free_ranges; range != (c2_coff_free_range *)0x0; range = range->next) {
    incr_stream_put_dword(range->start);
    incr_stream_put_dword(range->size);
  }
  incr_stream_put_dword(0);
  incr_stream_put_dword(0);
  return;
}

