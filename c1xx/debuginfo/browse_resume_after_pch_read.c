void __fastcall browse_resume_after_pch_read(c1xx_il_emitter *il_emitter)

{
  int iVar1;
  long lVar2;
  c1_line_map_row *pcVar3;
  c1_u16 cVar4;
  uint uVar5;
  c1_idb_browse_entry *local_4;
  
  if (g_emitter_region_mode == 2) {
    local_4 = (c1_idb_browse_entry *)il_emitter;
    iVar1 = (*g_idb->vtbl->idb_browse_region)(g_idb,0,&local_4);
    if (iVar1 == 0) {
      diag_fatal(0x49,".\\nbrowser.c",0x80c);
    }
    if (g_use_instantiation_position == '\0') {
      if (g_line_map_cached_row.position == g_token_position) {
        pcVar3 = &g_line_map_cached_row;
      }
      else {
        pcVar3 = pp_line_map_find_entry(&g_line_map,g_token_position);
      }
      uVar5 = (pcVar3->line - pcVar3->position) + g_token_position;
    }
    else if (g_line_map_cached_row.position == g_region_source_position) {
      uVar5 = (g_line_map_cached_row.line - g_line_map_cached_row.position) +
              g_region_source_position;
    }
    else {
      pcVar3 = pp_line_map_find_entry(&g_line_map,g_region_source_position);
      uVar5 = (pcVar3->line - pcVar3->position) + g_region_source_position;
    }
    if (local_4->old_last_line != uVar5) {
      if (g_use_instantiation_position == '\0') {
        if (g_line_map_cached_row.position == g_token_position) {
          pcVar3 = &g_line_map_cached_row;
        }
        else {
          pcVar3 = pp_line_map_find_entry(&g_line_map,g_token_position);
        }
        cVar4 = ((short)pcVar3->line - (short)pcVar3->position) + (short)g_token_position;
      }
      else if (g_line_map_cached_row.position == g_region_source_position) {
        cVar4 = ((short)g_line_map_cached_row.line - (short)g_line_map_cached_row.position) +
                (short)g_region_source_position;
      }
      else {
        pcVar3 = pp_line_map_find_entry(&g_line_map,g_region_source_position);
        cVar4 = ((short)pcVar3->line - (short)pcVar3->position) + (short)g_region_source_position;
      }
      local_4->last_line = cVar4;
      (*g_il_emitter_browse->vtbl->flush)();
      lVar2 = ftell((FILE *)g_browse_sbr_file);
      local_4->sbr_offset = lVar2;
      browse_add_record(0x16,(int *)0x0);
    }
  }
  return;
}

