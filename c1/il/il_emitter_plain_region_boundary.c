void il_emitter_plain_region_boundary(void)

{
  fe_line_map_row *pfVar1;
  int iVar2;
  
  if ((g_include_depth == 0) && (g_emitter_region_mode != 0)) {
    if (g_line_map_cached_row.position == g_token_position) {
      pfVar1 = &g_line_map_cached_row;
    }
    else {
      pfVar1 = pp_line_map_find_entry(&g_line_map,g_token_position);
    }
    iVar2 = (*g_idb->vtbl->idb_browse_set_lines)
                      (g_idb,g_region_start_line,
                       ((short)pfVar1->line - (short)pfVar1->position) + (short)g_token_position);
    if (iVar2 == 0) {
      diag_fatal(0x49,".\\nbrowser.c",0x6e6);
    }
  }
  return;
}

