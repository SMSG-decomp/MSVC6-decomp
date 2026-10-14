void __thiscall il_emitter_browse_end_module(c1xx_il_emitter_browse *this)

{
  c1xx_browse_record *rec;
  
  browse_add_record(10,(int *)0x0);
  rec = (c1xx_browse_record *)browse_ring_pop_front();
  while (rec != (c1xx_browse_record *)0x0) {
    browse_record_type(rec);
    rec = (c1xx_browse_record *)browse_ring_pop_front();
  }
  return;
}

