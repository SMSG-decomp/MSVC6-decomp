void __cdecl func_parse_definition_or_skip(c1_symbol *sym,char skip_local_member_check)

{
  c1xx_token_cursor *cursor;
  arena *a;
  int *piVar1;
  c1xx_token_stream_vtbl *pcVar2;
  void *pvVar3;
  byte bVar4;
  c1xx_token *pcVar5;
  byte *pbVar6;
  c1_u8 *pcVar7;
  c1_line_map_row *pcVar8;
  int iVar9;
  c1xx_token_stream *pcVar10;
  uint uVar11;
  c1_class_instance_cell *pcVar12;
  int *piVar13;
  c1_u32 stop_set;
  short n;
  int iStack_8;
  c1xx_token *local_4;
  
  if ((sym->flags3 & 4) != 0) {
    g_compile_flags_c8 = g_compile_flags_c8 & 0xfeffffff;
    pcVar5 = parse_lookahead_token();
    if (pcVar5 == (c1xx_token *)0x0) {
      pbVar6 = token_next((c1_token_reader *)&g_token_position);
      yyparse_set_lookahead(pbVar6);
    }
    pcVar5 = parse_lookahead_token();
    if ((pcVar5->code != '6') && (pcVar5->code != 'u')) {
      return;
    }
    diag_error(0x14d,sym);
    lex_skip_to_closing_brace(pcVar5->code == '6');
    token_next((c1_token_reader *)&g_token_position);
    yyparse_set_lookahead(g_token_lbrace);
    return;
  }
  if ((g_compile_flags_c8 & 0x1000000) != 0) {
    if (((g_compile_flags_cc & 0x100000) == 0) && ((g_compile_flags_cc & 8) == 0)) {
      deferred_body_list_add(&g_deferred_member_bodies,sym);
    }
    g_compile_flags_c8 = g_compile_flags_c8 & 0xfeffffff;
  }
  if ((g_compile_flags_cc & 0x200000) != 0) {
    return;
  }
  if ((g_compile_flags_cc & 0x40) != 0) {
    return;
  }
  pcVar5 = parse_lookahead_token();
  if (pcVar5 == (c1xx_token *)0x0) {
    pbVar6 = token_next((c1_token_reader *)&g_token_position);
    yyparse_set_lookahead(pbVar6);
  }
  pcVar5 = parse_lookahead_token();
  bVar4 = pcVar5->code;
  local_4 = pcVar5;
  switch((uint)bVar4) {
  case 0x34:
    return;
  default:
    diag_error(0x3b,0x4c,(uint)bVar4);
    func_parse_definition_or_skip_return();
    return;
  case 0x36:
  case 0x75:
    break;
  case 0x37:
  case 0x7f:
    if (g_current_function == (c1_symbol *)0x0) {
      return;
    }
    if (g_class_depth < 0) {
      return;
    }
    if ((sym->flags21 & 4) != 0) {
      return;
    }
    if (skip_local_member_check != '\0') {
      return;
    }
    if ((*(byte *)((int)&sym->tail + 8) & 4) != 0) {
      return;
    }
    diag_error(599,sym);
    return;
  }
  if ((g_compile_flags_cc & 0x100000) != 0) {
    lex_skip_to_closing_brace(bVar4 == 0x36);
    token_next((c1_token_reader *)&g_token_position);
    sym->flags2 = sym->flags2 | 4;
    yyparse_set_lookahead(g_token_lbrace);
    return;
  }
  if (g_current_function == (c1_symbol *)0x0) {
    bVar4 = sym->flags21 | 1;
  }
  else {
    if (g_class_depth < 0) {
      diag_error(0x259,sym);
      goto LAB_104399dc;
    }
    bVar4 = sym->flags21 & 0xfe;
  }
  sym->flags21 = bVar4;
LAB_104399dc:
  browse_define_symbol_as_defined(sym);
  (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)pcVar5);
  pcVar10 = (c1xx_token_stream *)g_arenas[0].cur;
  if ((g_compile_flags_cc & 8) == 0) {
    uVar11 = (~g_compile_flags_c8 | 0xbfffffff) >> 0x1e;
    piVar13 = (int *)g_arenas[uVar11].cur;
    a = g_arenas + uVar11;
    piVar1 = (int *)g_arenas[uVar11].end;
    a->cur = (c1_u8 *)(piVar13 + 2);
    if (piVar1 < piVar13 + 2) {
      arena_grow(a);
    }
    if (piVar13 == (int *)0x0) {
      piVar13 = (int *)0x0;
    }
    else {
      *piVar13 = g_token_arena_index;
      piVar13[1] = (int)g_token_arena_stack;
    }
    g_token_arena_index = uVar11;
    g_token_arena_stack = piVar13;
    if (g_token_stream_queues[uVar11].top == (c1_token_source_frame *)0x0) {
      pcVar10 = arena_alloc(a,0x38);
      if (pcVar10 == (c1xx_token_stream *)0x0) {
        pcVar10 = (c1xx_token_stream *)0x0;
      }
      else {
        pcVar10 = token_stream_init(pcVar10,uVar11,0);
      }
      token_source_push(g_token_stream_queues + uVar11,pcVar10,uVar11,0,(void *)0x0,
                        &g_token_position);
    }
    pcVar10 = (g_token_stream_queues[uVar11].top)->stream;
  }
  else {
    g_arenas[0].cur = g_arenas[0].cur + 0x38;
    uVar11 = 0;
    if (g_arenas[0].end < g_arenas[0].cur) {
      arena_grow(g_arenas);
    }
    iVar9 = g_token_position;
    if (pcVar10 == (c1xx_token_stream *)0x0) {
      pcVar10 = (c1xx_token_stream *)0x0;
      piVar13 = (int *)g_arenas[0].cur;
    }
    else {
      cursor = (c1xx_token_cursor *)((int)pcVar10 + 0xc);
      *(int *)((int)pcVar10 + 4) = g_token_position;
      *(int *)((int)pcVar10 + 8) = iVar9;
      token_buffer_init(cursor,0);
      *(c1_u8 *)((int)pcVar10 + 0x30) = '\0';
      *(c1_u8 *)((int)pcVar10 + 0x31) = '\0';
      *(c1_u8 *)((int)pcVar10 + 0x32) = '\0';
      *(c1_u8 *)((int)pcVar10 + 0x33) = '\0';
      *(undefined ***)pcVar10 = &PTR_token_stream_next_raw_104bc55c;
      *(c1_token_chunk **)((int)pcVar10 + 0x18) = cursor->chunk;
      *(undefined4 *)((int)pcVar10 + 0x1c) = *(undefined4 *)((int)pcVar10 + 0x10);
      *(undefined4 *)((int)pcVar10 + 0x20) = *(undefined4 *)((int)pcVar10 + 0x14);
      *(c1_token_chunk **)((int)pcVar10 + 0x24) = cursor->chunk;
      *(undefined4 *)((int)pcVar10 + 0x28) = *(undefined4 *)((int)pcVar10 + 0x10);
      *(undefined4 *)((int)pcVar10 + 0x2c) = *(undefined4 *)((int)pcVar10 + 0x14);
      *(byte *)((int)pcVar10 + 0x34) = *(byte *)((int)pcVar10 + 0x34) & 0xfe;
      piVar13 = (int *)g_arenas[0].cur;
    }
    g_arenas[0].cur = (c1_u8 *)(piVar13 + 2);
    if (g_arenas[0].end < g_arenas[0].cur) {
      arena_grow(g_arenas);
    }
    if (piVar13 == (int *)0x0) {
      piVar13 = (int *)0x0;
    }
    else {
      *piVar13 = g_token_arena_index;
      piVar13[1] = (int)g_token_arena_stack;
    }
    g_token_arena_index = 0;
    g_token_arena_stack = piVar13;
  }
  pcVar2 = pcVar10->vtbl;
  pcVar7 = token_new_position_marker(uVar11);
  (*pcVar2->append)(pcVar10,(int)pcVar7);
  token_stream_put_function_header(sym,pcVar10,uVar11);
  if ((sym->flags21 & 4) != 0) {
    sym->scope_index = (((g_class_def_stack[g_class_depth].cls)->detail).cls)->scope_index;
  }
  bVar4 = sym->kind & 0x1f;
  if ((bVar4 != 7) && (bVar4 != 8)) {
    diag_error(0x3f,sym);
  }
  stop_set = 0x242;
  if (((sym->flags1 & 0x10) != 0x10) || (local_4->code != '6')) {
    stop_set = 0x2c2;
  }
  if ((g_token_source->stream->flags & 1) != 0) {
    if (g_line_map_cached_row.position == g_token_position) {
      pcVar8 = &g_line_map_cached_row;
    }
    else {
      pcVar8 = pp_line_map_find_entry(&g_line_map,g_token_position);
    }
    iVar9 = (*g_idb->vtbl->idb_function_body_begin)
                      (g_idb,CONCAT22((short)((uint)g_macro_expansion_depth >> 0x10),
                                      (short)pcVar8->line - (short)pcVar8->position) +
                             g_token_position,g_macro_expansion_depth);
    if (iVar9 == 0) {
      diag_fatal(0x49,".\\funcs.c",0xaeb);
    }
  }
  pcVar5 = parse_record_tokens_to_delimiter(pcVar10,stop_set,'\x01');
  iStack_8 = 0;
  if ((g_token_source->stream->flags & 1) != 0) {
    if (g_line_map_cached_row.position == g_token_position) {
      pcVar8 = &g_line_map_cached_row;
    }
    else {
      pcVar8 = pp_line_map_find_entry(&g_line_map,g_token_position);
    }
    uVar11 = (*g_idb->vtbl->idb_function_body_end)
                       (g_idb,CONCAT22((short)((uint)g_macro_expansion_depth >> 0x10),
                                       (short)pcVar8->line - (short)pcVar8->position) +
                              g_token_position,g_macro_expansion_depth,&iStack_8);
    if (uVar11 == 0) {
      diag_fatal(0x49,".\\funcs.c",0xaf3);
    }
  }
  if ((g_minimal_rebuild != '\0') && (iStack_8 != 0)) {
    pbVar6 = mre_member_name_text(sym->name,(int)g_class_def_stack[g_class_depth].cls);
    iVar9 = (*g_idb->vtbl->idb_tracker_note)
                      ((((g_class_def_stack[g_class_depth].cls)->detail).cls)->gm_name_index,pbVar6)
    ;
    if (iVar9 == 0) {
      diag_fatal(0x49,".\\funcs.c",0xafc);
    }
  }
  if (pcVar5->code != 0x7b) {
    if ((g_compile_flags_c8 & 0x40000000) == 0) {
      n = 0x3c9;
    }
    else {
      n = 0x3c2;
    }
    diag_error(n,(uint)pcVar5->code);
  }
  if ((g_compile_flags_c8 & 0x40000000) != 0) {
    (*pcVar10->vtbl->append)(pcVar10,(int)g_token_end_parse);
  }
  pcVar7 = g_arenas[0].cur;
  g_token_arena_index = *g_token_arena_stack;
  g_token_arena_stack = (int *)g_token_arena_stack[1];
  if ((g_compile_flags_cc & 8) != 0) {
    for (pcVar12 = *g_class_template_instances; pcVar12 != (c1_class_instance_cell *)0x0;
        pcVar12 = pcVar12->next) {
      if (pcVar12->instance == g_class_def_stack[g_class_depth].cls) goto LAB_10439d96;
    }
    pcVar12 = (c1_class_instance_cell *)0x0;
LAB_10439d96:
    g_arenas[0].cur = g_arenas[0].cur + 0xc;
    if (g_arenas[0].end < g_arenas[0].cur) {
      arena_grow(g_arenas);
    }
    if (pcVar7 == (c1_u8 *)0x0) {
      pcVar7 = (c1_u8 *)0x0;
    }
    else {
      pvVar3 = pcVar12->bodies;
      *(c1_symbol **)pcVar7 = sym;
      *(c1xx_token_stream **)(pcVar7 + 4) = pcVar10;
      *(void **)(pcVar7 + 8) = pvVar3;
    }
    pcVar12->bodies = pcVar7;
  }
  yyparse_set_lookahead(g_token_lbrace);
  return;
}

