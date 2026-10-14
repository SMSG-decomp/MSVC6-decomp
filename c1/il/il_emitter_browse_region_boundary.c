void __fastcall il_emitter_browse_region_boundary(c1_il_emitter_browse *il_emitter_browse)

{
  fe_line_map_row *pfVar1;
  int iVar2;
  
  if (g_include_depth == 0) {
    (*il_emitter_browse->vtbl->flush)();
    if (g_line_map_cached_row.position == g_token_position) {
      pfVar1 = &g_line_map_cached_row;
    }
    else {
      pfVar1 = pp_line_map_find_entry(&g_line_map,g_token_position);
    }
    iVar2 = (*g_idb->vtbl->idb_browse_set_region)
                      (g_idb,CONCAT22((short)((uint)g_token_position >> 0x10),g_region_start_line),
                       CONCAT22((short)((uint)il_emitter_browse[2].vtbl >> 0x10),
                                (short)pfVar1->line - (short)pfVar1->position) + g_token_position,
                       (int)il_emitter_browse[2].vtbl);
    if (iVar2 == 0) {
      diag_fatal(0x49,".\\nbrowser.c",0x6db);
    }
  }
  return;
}

