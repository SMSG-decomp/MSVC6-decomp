void __cdecl browse_restart_region_after_pch(void)

{
  int iVar1;
  fe_line_map_row *pfVar2;
  long lVar3;
  void *local_4;
  
  if (g_emitter_region_mode == 2) {
    iVar1 = (*g_idb->vtbl->idb_browse_region)(g_idb,0,&local_4);
    if (iVar1 == 0) {
      diag_fatal(0x49,".\\nbrowser.c",0x80c);
    }
    if (g_line_map_cached_row.position == g_token_position) {
      pfVar2 = &g_line_map_cached_row;
    }
    else {
      pfVar2 = pp_line_map_find_entry(&g_line_map,g_token_position);
    }
    if ((uint)*(ushort *)((int)local_4 + 2) != (pfVar2->line - pfVar2->position) + g_token_position)
    {
      if (g_line_map_cached_row.position == g_token_position) {
        pfVar2 = &g_line_map_cached_row;
      }
      else {
        pfVar2 = pp_line_map_find_entry(&g_line_map,g_token_position);
      }
      *(short *)((int)local_4 + 6) =
           ((short)pfVar2->line - (short)pfVar2->position) + (short)g_token_position;
      (*g_il_emitter_browse->vtbl->flush)();
      lVar3 = ftell(g_browse_sbr_file);
      *(long *)((int)local_4 + 8) = lVar3;
      browse_add_record(0x16,(c1_symbol *)0x0);
    }
  }
  return;
}

