void __cdecl pp_include_push_file(int *file_record,int mode,int handle,byte pch_part)

{
  int *piVar1;
  int iVar2;
  uchar *puVar3;
  char *name;
  fe_input_file *pfVar4;
  c1_u8 by_handle;
  c1_emitter_suspend *suspend;
  
  pfVar4 = (fe_input_file *)g_arenas[1].cur;
  if (g_input_file_free_list == (fe_input_file *)0x0) {
    g_arenas[1].cur = g_arenas[1].cur + 0x2c;
    puVar3 = g_arenas[1].cur;
    if (g_arenas[1].end < g_arenas[1].cur) {
      arena_grow(g_arenas + 1);
      puVar3 = g_arenas[1].cur;
    }
    g_arenas[1].cur = puVar3 + 0x7004;
    if (g_arenas[1].end < g_arenas[1].cur) {
      arena_grow(g_arenas + 1);
    }
    *(uchar **)((int)pfVar4 + 0x10) = puVar3 + 2;
  }
  else {
    pfVar4 = g_input_file_free_list;
    g_input_file_free_list = g_input_file_free_list->next;
  }
  pfVar4->next = g_input_file;
  g_input_file = pfVar4;
  if (g_include_depth + 1 < 0x401) {
    g_source_handle = handle;
    g_include_depth = g_include_depth + 1;
    pfVar4->cond_depth = g_pp_cond_depth;
    pfVar4->pack = g_pack_stack->top->packing;
    if (g_include_depth == 0) {
      g_primary_input_file = g_input_file;
    }
    pfVar4->saved_input = g_input_ptr;
    pfVar4->position = g_token_position;
    pfVar4->handle = g_source_handle;
    pfVar4->last_read = 0;
    pfVar4->block_offset = 0;
    pfVar4->flags = pfVar4->flags & 0xfe;
    g_input_file->flags = g_input_file->flags & 0xfb;
    pfVar4->flags = (pch_part & 1) << 1 | pfVar4->flags & 0xfd;
    suspend = g_emitter_suspend;
    if (pch_part == 0) {
      if (g_emitter_suspend->depth == 0) {
        g_emitter_suspend->saved = g_il_emitter;
        g_il_emitter = il_emitter_get_default();
        suspend->active = '\0';
      }
      piVar1 = &suspend->depth;
      *piVar1 = *piVar1 + 1;
    }
    g_input_ptr = pfVar4->buffer;
    (*g_source_tracker->vtbl->source_tracker_push)(g_source_tracker,(int)g_source_tracker_iface);
    pfVar4->file = (fe_file_record *)file_record;
    g_lex_position = g_lex_position + 1;
    vector_push_triple((int *)&g_line_map,g_lex_position,0,(int)file_record);
    g_token_position = g_lex_position;
    g_input_ptr[-1] = 10;
    g_input_ptr = g_input_ptr + 1;
    file_read_or_fatal();
    if (g_idb != (c1_idb_state *)0x0) {
      (*g_source_tracker_iface->vtbl->reset)(g_source_tracker_iface);
      iVar2 = (*g_idb->vtbl->idb_include_enter)(g_idb,*(char **)(*file_record + 4),pch_part == 0);
      if (iVar2 == 0) {
        diag_fatal(0x49,".\\p0io.c",0x151);
      }
      if ((g_minimal_rebuild != '\0') || (g_opt_FD != '\0')) {
        by_handle = mode != 2;
        name = pp_position_file_name(&g_token_position);
        pdb_file_stack_push(g_pdb_file_stack,name,handle,by_handle);
        if (g_minimal_rebuild != '\0') {
          pp_include_push_file_fragment();
          return;
        }
      }
    }
    if ((g_opt_EP_no_line == '\0') && (g_pp_output_stream != 0)) {
      pp_emit_line_directive();
    }
    g_input_ptr = g_input_ptr + -1;
    *g_input_ptr = 10;
    return;
  }
  diag_fatal(0xe,g_include_depth);
}

