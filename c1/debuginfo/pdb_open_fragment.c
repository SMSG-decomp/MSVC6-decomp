void pdb_open_fragment(void)

{
  char cVar1;
  int iVar2;
  fe_line_map_row *pfVar3;
  MREFile *pMStack00000004;
  
  pMStack00000004 = (MREFile *)0x0;
  cVar1 = pdb_file_stack_top_object(g_pdb_file_stack,&stack0x00000004);
  if (cVar1 != '\0') {
    iVar2 = (*g_idb->vtbl->idb_set_tracker)(g_idb,pMStack00000004);
    if (iVar2 == 0) {
      diag_fatal(0x49,".\\main.c",0x2a8);
    }
  }
  g_il_emitter = il_emitter_get_preferred();
  if ((g_use_pch == '\0') && (g_pch_automatic == '\0')) {
    iVar2 = (*g_idb->vtbl->idb_begin_unit)(g_idb,&g_ilstore_status);
    if (iVar2 == 0) {
      diag_fatal(0x49,".\\main.c",0x2b6);
    }
    if ((g_pch_creating == 0) && (g_ilstore_status == 1)) {
      cVar1 = (*g_il_emitter->vtbl->reopen)(g_il_emitter);
      if (cVar1 != '\0') goto LAB_10614f42;
    }
    (*g_il_emitter->vtbl->open)();
  }
  else {
    iVar2 = (*g_idb->vtbl->idb_begin_unit_no_check)(g_idb,&g_ilstore_status);
    if (iVar2 == 0) {
      diag_fatal(0x49,".\\main.c",0x2b2);
    }
  }
LAB_10614f42:
  if (g_use_pch == '\0') {
    il_emitter_begin_region_at_top_level(g_ilstore_status == 5);
    return;
  }
  if (g_line_map_cached_row.position == g_token_position) {
    pfVar3 = &g_line_map_cached_row;
  }
  else {
    pfVar3 = pp_line_map_find_entry(&g_line_map,g_token_position);
  }
  iVar2 = (pfVar3->line - pfVar3->position) + g_token_position;
  if (g_line_map_cached_row.position == g_token_position) {
    pfVar3 = &g_line_map_cached_row;
  }
  else {
    pfVar3 = pp_line_map_find_entry(&g_line_map,g_token_position);
  }
  g_lex_position = g_lex_position + 1;
  vector_push_triple((int *)&g_line_map,g_lex_position,0,(int)pfVar3->file);
  g_token_position = g_lex_position;
  il_emitter_begin_region_at_top_level(g_ilstore_status == 5);
  if (g_line_map_cached_row.position == g_token_position) {
    pfVar3 = &g_line_map_cached_row;
  }
  else {
    pfVar3 = pp_line_map_find_entry(&g_line_map,g_token_position);
  }
  g_lex_position = g_lex_position + 1;
  vector_push_triple((int *)&g_line_map,g_lex_position,iVar2,(int)pfVar3->file);
  g_token_position = g_lex_position;
  return;
}

