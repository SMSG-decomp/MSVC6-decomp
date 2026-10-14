void __cdecl pp_include_push_file(int *file_record,int mode,int handle,byte browse)

{
  int *piVar1;
  c1xx_emitter_suspend *pcVar2;
  char cVar3;
  int iVar4;
  char *pcVar5;
  c1_u8 *pcVar6;
  fe_input_file *pfVar7;
  byte bVar8;
  c1_mre_file *pcStack_104;
  char acStack_100 [256];
  
  pfVar7 = (fe_input_file *)g_arenas[1].cur;
  if (g_input_file_free_list == (fe_input_file *)0x0) {
    g_arenas[1].cur = g_arenas[1].cur + 0x2c;
    pcVar6 = g_arenas[1].cur;
    if (g_arenas[1].end < g_arenas[1].cur) {
      arena_grow(g_arenas + 1);
      pcVar6 = g_arenas[1].cur;
    }
    g_arenas[1].cur = pcVar6 + 0x7004;
    if (g_arenas[1].end < g_arenas[1].cur) {
      arena_grow(g_arenas + 1);
    }
    *(c1_u8 **)((int)pfVar7 + 0x10) = pcVar6 + 2;
  }
  else {
    pfVar7 = g_input_file_free_list;
    g_input_file_free_list = g_input_file_free_list->next;
  }
  pfVar7->next = g_input_file;
  g_input_file = pfVar7;
  if (0x400 < g_include_depth + 1) {
    diag_fatal(0xe,g_include_depth);
  }
  g_source_handle = handle;
  g_include_depth = g_include_depth + 1;
  pfVar7->cond_depth = g_pp_cond_depth;
  pfVar7->pack = g_pack_stack->top->packing;
  if (g_include_depth == 0) {
    g_main_input_file = g_input_file;
  }
  pfVar7->saved_input = g_input_ptr;
  pfVar7->position = g_token_position;
  pfVar7->handle = g_source_handle;
  bVar8 = pfVar7->flags;
  pfVar7->last_read = 0;
  pfVar7->block_offset = 0;
  pfVar7->flags = bVar8 & 0xfe;
  pfVar7->flags = ((byte)(g_compile_flags_cc >> 0x18) & 1) << 3 | bVar8 & 0xf6;
  g_input_file->flags = g_input_file->flags & 0xfb;
  pfVar7->flags = (browse & 1) << 1 | pfVar7->flags & 0xfd;
  pcVar2 = g_emitter_suspend;
  if (browse == 0) {
    if (g_emitter_suspend->depth == 0) {
      g_emitter_suspend->saved = g_il_emitter;
      g_il_emitter = il_emitter_get_default();
      pcVar2->enabled = '\0';
    }
    piVar1 = &pcVar2->depth;
    *piVar1 = *piVar1 + 1;
  }
  g_input_ptr = pfVar7->buffer;
  (**(code **)*g_source_tracker)(g_source_tracker,g_source_tracker_iface);
  pfVar7->file = (fe_file_record *)file_record;
  g_lex_position = g_lex_position + 1;
  vector_push_triple((int *)&g_line_map,g_lex_position,0,(int)file_record);
  g_token_position = g_lex_position;
  g_input_ptr[-1] = 10;
  g_input_ptr = g_input_ptr + 1;
  file_read_or_fatal();
  if (g_idb != (c1xx_idb *)0x0) {
    (**(code **)(*g_source_tracker_iface + 8))();
    iVar4 = (*g_idb->vtbl->idb_include_enter)(g_idb,*(char **)(*file_record + 4),browse == 0);
    if (iVar4 == 0) {
      diag_fatal(0x49,".\\p0io.c",0x151);
    }
    if ((g_minimal_rebuild != '\0') || (g_opt_FD != '\0')) {
      pcVar5 = pp_position_file_name(&g_token_position);
      _splitpath(pcVar5,(char *)0x0,(char *)0x0,(char *)0x0,acStack_100);
      if (acStack_100[0] != '\0') {
        iVar4 = -1;
        pcVar5 = acStack_100;
        do {
          if (iVar4 == 0) break;
          iVar4 = iVar4 + -1;
          cVar3 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar3 != '\0');
        if ((iVar4 == -6) && (iVar4 = strncmp(acStack_100,".tl",3), iVar4 == 0)) goto LAB_10432eb4;
      }
      bVar8 = mode != 2;
      pcVar5 = pp_position_file_name(&g_token_position);
      pdb_source_file_push(g_minimal_rebuild_tracker,pcVar5,handle,bVar8);
      if (g_minimal_rebuild != '\0') {
        pcStack_104 = (c1_mre_file *)0x0;
        cVar3 = pdb_file_stack_top_object(g_minimal_rebuild_tracker,&pcStack_104);
        if ((cVar3 != '\0') &&
           (iVar4 = (*g_idb->vtbl->idb_set_tracker)(g_idb,pcStack_104), iVar4 == 0)) {
          diag_fatal(0x49,".\\p0io.c",0x176);
        }
      }
    }
  }
LAB_10432eb4:
  if ((g_opt_EP_no_line == '\0') && (g_pp_output_stream != 0)) {
    pp_emit_line_directive();
  }
  g_input_ptr = g_input_ptr + -1;
  *g_input_ptr = 10;
  return;
}

