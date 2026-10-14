void __fastcall il_emitter_browse_begin_region(c1xx_il_emitter_browse *il_emitter_browse)

{
  long lVar1;
  
  if (g_emitter_region_mode != 2) {
    il_emitter_browse->region_offset = -1;
    return;
  }
  (*il_emitter_browse->vtbl->flush)();
  lVar1 = ftell((FILE *)g_browse_sbr_file);
  il_emitter_browse->region_offset = lVar1;
  browse_add_record(0x16,(int *)0x0);
  browse_next_region_id();
  g_browse_last_line = _g_region_start_line & 0xffff;
  return;
}

