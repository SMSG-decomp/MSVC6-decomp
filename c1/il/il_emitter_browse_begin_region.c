void __fastcall il_emitter_browse_begin_region(c1_il_emitter_browse *il_emitter_browse)

{
  c1_il_emitter_browse_vtbl *pcVar1;
  
  if (g_emitter_region_mode != 2) {
    il_emitter_browse[2].vtbl = (c1_il_emitter_browse_vtbl *)0xffffffff;
    return;
  }
  (*il_emitter_browse->vtbl->flush)();
  pcVar1 = (c1_il_emitter_browse_vtbl *)ftell(g_browse_sbr_file);
  il_emitter_browse[2].vtbl = pcVar1;
  browse_add_record(0x16,(c1_symbol *)0x0);
  browse_next_region_id();
  g_browse_last_line = _g_region_start_line & 0xffff;
  return;
}

