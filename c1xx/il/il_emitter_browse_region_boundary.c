void __fastcall il_emitter_browse_region_boundary(c1xx_il_emitter_browse *il_emitter_browse)

{
  c1_line_map_row *pcVar1;
  int iVar2;
  
  if (g_include_depth == 0) {
    (*il_emitter_browse->vtbl->flush)();
    if (g_use_instantiation_position == '\0') {
      if (g_line_map_cached_row.position == g_token_position) {
        pcVar1 = &g_line_map_cached_row;
        iVar2 = g_token_position;
      }
      else {
        pcVar1 = pp_line_map_find_entry(&g_line_map,g_token_position);
        iVar2 = g_token_position;
      }
    }
    else if (g_line_map_cached_row.position == g_region_source_position) {
      pcVar1 = &g_line_map_cached_row;
      iVar2 = g_region_source_position;
    }
    else {
      pcVar1 = pp_line_map_find_entry(&g_line_map,g_region_source_position);
      iVar2 = g_region_source_position;
    }
    iVar2 = (pcVar1->line - pcVar1->position) + iVar2;
    iVar2 = (*g_idb->vtbl->idb_browse_set_region)
                      (g_idb,CONCAT22((short)((uint)iVar2 >> 0x10),g_region_start_line),iVar2,
                       il_emitter_browse->region_offset);
    if (iVar2 == 0) {
      diag_fatal(0x49,".\\nbrowser.c",0x6db);
    }
  }
  return;
}

