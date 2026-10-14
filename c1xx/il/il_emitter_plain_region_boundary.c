void __cdecl il_emitter_plain_region_boundary(void)

{
  c1_line_map_row *pcVar1;
  int iVar2;
  
  if ((g_include_depth == 0) && (g_emitter_region_mode != 0)) {
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
    iVar2 = (*g_idb->vtbl->idb_browse_set_lines)
                      (g_idb,g_region_start_line,(short)((pcVar1->line - pcVar1->position) + iVar2))
    ;
    if (iVar2 == 0) {
      diag_fatal(0x49,".\\nbrowser.c",0x6e6);
    }
  }
  return;
}

