int __cdecl pp_include_pop_file(void)

{
  uint position;
  fe_input_file *pfVar1;
  int *piVar2;
  int iVar3;
  fe_line_map_row *pfVar4;
  fe_input_file **ppfVar5;
  char *pcVar6;
  long lVar7;
  int iVar8;
  int line;
  c1_emitter_suspend *suspend;
  
  iVar8 = 0;
  if (g_include_depth == -1) {
    return 0;
  }
  if (g_include_depth < 1) {
    iVar3 = (*g_idb->vtbl->idb_begin_source_file)(g_idb);
    if (iVar3 == 0) {
      line = 0x46c;
      goto LAB_106287cf;
    }
  }
  else {
    piVar2 = include_line_map_find(&g_lex_position,g_token_position);
    iVar3 = (*g_idb->vtbl->idb_include_leave)
                      (g_idb,((short)piVar2[1] - (short)*piVar2) + (short)g_token_position);
    if (iVar3 == 0) {
      line = 0x468;
LAB_106287cf:
      diag_fatal(0x49,".\\p0io.c",line);
    }
  }
  (*g_source_tracker->vtbl->source_tracker_pop)(g_source_tracker,(int)g_source_tracker_iface);
  suspend = g_emitter_suspend;
  if ((g_input_file->flags & 2) == 0) {
    iVar8 = 1000;
    iVar3 = g_emitter_suspend->depth + -1;
    g_emitter_suspend->depth = iVar3;
    if (iVar3 == 0) {
      g_il_emitter = suspend->saved;
      suspend->active = '\x01';
    }
  }
  if ((g_input_file->handle != -2) && (-1 < g_input_file->handle)) {
    _close(g_source_handle);
  }
  if (g_input_file->cond_depth != g_pp_cond_depth) {
    pcVar6 = pp_position_file_name(&g_token_position);
    diag_fatal(0x46,pcVar6);
  }
  if (((iVar8 != 1000) && (0 < g_include_depth)) &&
     (g_input_file->pack != g_pack_stack->top->packing)) {
    iVar8 = 1;
  }
  if (((g_minimal_rebuild != '\0') || (g_opt_FD != '\0')) &&
     (*(int *)((int)*g_pdb_file_stack + 8) != 0)) {
    pdb_source_file_pop(g_pdb_file_stack);
  }
  iVar3 = g_token_position;
  g_input_ptr = g_input_file->saved_input;
  piVar2 = &g_input_file->position;
  position = *piVar2;
  if (g_line_map_cached_row.position == position) {
    pfVar4 = &g_line_map_cached_row;
  }
  else {
    pfVar4 = pp_line_map_find_entry(&g_line_map,position);
  }
  g_lex_position = g_lex_position + 1;
  vector_push_triple((int *)&g_line_map,g_lex_position,(pfVar4->line - pfVar4->position) + *piVar2,
                     (int)pfVar4->file);
  pfVar1 = g_input_file;
  g_token_position = g_lex_position;
  ppfVar5 = &g_input_file->next;
  g_input_file = *ppfVar5;
  *ppfVar5 = g_input_file_free_list;
  g_include_depth = g_include_depth + -1;
  g_input_file_free_list = pfVar1;
  if (g_include_depth < 0) {
    if (g_line_map_cached_row.position == iVar3) {
      pfVar4 = &g_line_map_cached_row;
    }
    else {
      pfVar4 = pp_line_map_find_entry(&g_line_map,iVar3);
    }
    g_lex_position = g_lex_position + 1;
    vector_push_triple((int *)&g_line_map,g_lex_position,(pfVar4->line - pfVar4->position) + iVar3,
                       (int)pfVar4->file);
    g_token_position = g_lex_position;
    return 0;
  }
  g_source_handle = g_input_file->handle;
  if (g_source_handle == -1) {
    lVar7 = g_input_file->block_offset;
    pcVar6 = g_input_file->file->name->text;
    iVar3 = file_open_read_retry(pcVar6);
    g_input_file->handle = iVar3;
    g_source_handle = g_input_file->handle;
    if (g_source_handle == -1) {
      diag_fatal_file_errno(0x53,(-(uint)(g_include_depth != 0) & 2) + 0x155,pcVar6);
    }
    lVar7 = _lseek(g_input_file->handle,lVar7,0);
    if (lVar7 == -1) {
      diag_fatal_file_errno(0x54,(-(uint)(g_include_depth != 0) & 2) + 0x155,pcVar6);
    }
  }
  if (g_opt_EP_no_line == '\0') {
    pp_emit_line_directive();
  }
  if (iVar8 == 1000) {
    return 1000;
  }
  return ((-(uint)(iVar8 != 0) & 0xfffffffe) + 1) * (g_include_depth + 1);
}

