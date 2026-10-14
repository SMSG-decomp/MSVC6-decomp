void __cdecl browse_flush_queue(void)

{
  c1xx_browse_record *rec;
  
  rec = (c1xx_browse_record *)browse_ring_pop_front();
  while (rec != (c1xx_browse_record *)0x0) {
    browse_record_type(rec);
    rec = (c1xx_browse_record *)browse_ring_pop_front();
  }
  return;
}

