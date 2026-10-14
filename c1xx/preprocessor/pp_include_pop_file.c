int __cdecl pp_include_pop_file(void)

{
  uint position;
  fe_input_file *pfVar1;
  c1xx_emitter_suspend *pcVar2;
  c1_line_map_row *pcVar3;
  int iVar4;
  fe_input_file **ppfVar5;
  char *pcVar6;
  long lVar7;
  int iVar8;
  int *piVar9;
  int fatal_line;
  
  iVar8 = 0;
  if ((g_include_depth == 0) &&
     (pcVar6 = (char *)include_path_try_next((int *)&g_map_region_queue), *pcVar6 != '\x01')) {
    (*g_token_source->stream->vtbl->unget)(g_token_source->stream,pcVar6);
    return 1000;
  }
  if (g_include_depth == -1) {
    return 0;
  }
  if (g_include_depth < 1) {
    iVar4 = (*g_idb->vtbl->idb_begin_source_file)(g_idb);
    if (iVar4 == 0) {
      fatal_line = 0x46c;
      goto LAB_1045c0ea;
    }
  }
  else {
    pcVar3 = include_line_map_find((c1_line_map_state *)&g_lex_position,g_token_position);
    iVar4 = (*g_idb->vtbl->idb_include_leave)
                      (g_idb,((short)pcVar3->line - (short)pcVar3->position) +
                             (short)g_token_position);
    if (iVar4 == 0) {
      fatal_line = 0x468;
LAB_1045c0ea:
      diag_fatal(0x49,".\\p0io.c",fatal_line);
    }
  }
  (**(code **)(*g_source_tracker + 4))(g_source_tracker_iface);
  pcVar2 = g_emitter_suspend;
  if ((g_input_file->flags & 2) == 0) {
    iVar8 = 1000;
    iVar4 = g_emitter_suspend->depth + -1;
    g_emitter_suspend->depth = iVar4;
    if (iVar4 == 0) {
      g_il_emitter = pcVar2->saved;
      pcVar2->enabled = '\x01';
    }
  }
  if (g_input_file->handle == -2) {
    if ((g_compile_flags_c8 & 0x20000) != 0) {
      g_compile_flags_c8 = g_compile_flags_c8 & 0xfffdffff;
    }
  }
  else if (-1 < g_input_file->handle) {
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
     (g_minimal_rebuild_tracker->current->prev != (c1_source_file_record *)0x0)) {
    pdb_source_file_pop(g_minimal_rebuild_tracker);
  }
  iVar4 = g_token_position;
  g_input_ptr = g_input_file->saved_input;
  piVar9 = &g_input_file->position;
  position = *piVar9;
  if (g_line_map_cached_row.position == position) {
    pcVar3 = &g_line_map_cached_row;
  }
  else {
    pcVar3 = pp_line_map_find_entry(&g_line_map,position);
  }
  g_lex_position = g_lex_position + 1;
  vector_push_triple((int *)&g_line_map,g_lex_position,(pcVar3->line - pcVar3->position) + *piVar9,
                     (int)pcVar3->file);
  pfVar1 = g_input_file;
  g_token_position = g_lex_position;
  ppfVar5 = &g_input_file->next;
  g_input_file = *ppfVar5;
  *ppfVar5 = g_input_file_free_list;
  g_include_depth = g_include_depth + -1;
  g_input_file_free_list = pfVar1;
  if (g_include_depth < 0) {
    if (g_line_map_cached_row.position == iVar4) {
      pcVar3 = &g_line_map_cached_row;
    }
    else {
      pcVar3 = pp_line_map_find_entry(&g_line_map,iVar4);
    }
    g_lex_position = g_lex_position + 1;
    vector_push_triple((int *)&g_line_map,g_lex_position,(pcVar3->line - pcVar3->position) + iVar4,
                       (int)pcVar3->file);
    g_token_position = g_lex_position;
    return 0;
  }
  g_source_handle = g_input_file->handle;
  if (g_source_handle == -1) {
    lVar7 = g_input_file->block_offset;
    pcVar6 = g_input_file->file->name->text;
    iVar4 = file_open_read_retry(pcVar6);
    g_input_file->handle = iVar4;
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

