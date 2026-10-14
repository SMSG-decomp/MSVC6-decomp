c1_u8 __cdecl lex_check_end_of_file_2(void *parameter_table)

{
  c1_token_source_frame **ppcVar1;
  _func_193 **pp_Var2;
  c1xx_token_cursor *cursor;
  arena *a;
  int iVar3;
  byte bVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  c1xx_token_stream *pcVar8;
  c1xx_token *pcVar9;
  c1_u8 *token;
  uint *puVar10;
  uint *puVar11;
  c1xx_token_stream *local_8;
  
  uVar5 = (g_compile_flags_cc & 0x100000) >> 0x14;
  iVar6 = uVar5 << 2;
  a = g_arenas + uVar5 * 4;
  g_compile_flags_cc = g_compile_flags_cc | 0x200000;
  piVar7 = arena_alloc(a,8);
  if (piVar7 == (int *)0x0) {
    piVar7 = (int *)0x0;
  }
  else {
    *piVar7 = g_token_arena_index;
    piVar7[1] = (int)g_token_arena_stack;
  }
  g_token_arena_index = iVar6;
  g_token_arena_stack = piVar7;
  pcVar8 = arena_alloc(a,0x38);
  if (pcVar8 == (c1xx_token_stream *)0x0) {
    pcVar8 = (c1xx_token_stream *)0x0;
  }
  else {
    pcVar8 = token_stream_init(pcVar8,iVar6,0);
  }
  token_source_push((c1_token_reader *)&g_token_record_position,pcVar8,iVar6,0,(void *)0x0,
                    &g_token_position);
  pcVar9 = parse_record_tokens_to_delimiter(g_token_save_frame->stream,0x341,'\0');
  if (g_token_save_frame == (c1_token_source_frame *)0x0) {
    local_8 = (c1xx_token_stream *)g_token_save_frame;
  }
  else {
    ppcVar1 = &g_token_save_frame->prev;
    local_8 = g_token_save_frame->stream;
    g_token_record_position = g_token_save_frame->position;
    pp_Var2 = &g_token_save_frame->on_pop;
    g_token_save_frame = *ppcVar1;
    if (*pp_Var2 != (_func_193 *)0x0) {
      (**pp_Var2)();
    }
  }
  pcVar8 = (c1xx_token_stream *)0x0;
  bVar4 = 0;
  switch(pcVar9->code) {
  case '4':
    bVar4 = 1;
  case '6':
  case 'u':
    pcVar8 = arena_alloc(a,0x38);
    if (pcVar8 == (c1xx_token_stream *)0x0) {
      pcVar8 = (c1xx_token_stream *)0x0;
    }
    else {
      pcVar8 = token_stream_init(pcVar8,iVar6,0);
    }
    token_source_push((c1_token_reader *)&g_token_record_position,pcVar8,iVar6,0,(void *)0x0,
                      &g_token_position);
    parse_record_tokens_to_delimiter
              (g_token_save_frame->stream,(-(uint)bVar4 & 0xfffffffe) + 0x42,'\x01');
    if (g_token_save_frame == (c1_token_source_frame *)0x0) {
      pcVar8 = (c1xx_token_stream *)0x0;
    }
    else {
      ppcVar1 = &g_token_save_frame->prev;
      pcVar8 = g_token_save_frame->stream;
      g_token_record_position = g_token_save_frame->position;
      pp_Var2 = &g_token_save_frame->on_pop;
      g_token_save_frame = *ppcVar1;
      if (*pp_Var2 != (_func_193 *)0x0) {
        (**pp_Var2)();
      }
    }
    break;
  default:
    return '\0';
  case 'm':
    diag_fatal_simple(4);
  case '\x7f':
    token_next((c1_token_reader *)&g_token_position);
  }
  g_token_arena_index = *g_token_arena_stack;
  g_token_arena_stack = (int *)g_token_arena_stack[1];
  g_tmpl_definition_tokens = local_8;
  g_tmpl_definition_tail_tokens = pcVar8;
  piVar7 = arena_alloc(g_arenas + 4,8);
  if (piVar7 == (int *)0x0) {
    piVar7 = (int *)0x0;
  }
  else {
    *piVar7 = g_token_arena_index;
    piVar7[1] = (int)g_token_arena_stack;
  }
  g_token_arena_index = 4;
  g_token_arena_stack = piVar7;
  pcVar8 = arena_alloc(g_arenas + 4,0x38);
  iVar6 = g_token_position;
  if (pcVar8 == (c1xx_token_stream *)0x0) {
    pcVar8 = (c1xx_token_stream *)0x0;
  }
  else {
    cursor = &pcVar8->first;
    pcVar8->start_position = g_token_position;
    pcVar8->position = iVar6;
    token_buffer_init(cursor,4);
    pcVar8->arena = 4;
    pcVar8->vtbl = (c1xx_token_stream_vtbl *)&PTR_token_stream_next_raw_104bc55c;
    (pcVar8->read).chunk = cursor->chunk;
    (pcVar8->read).index = (pcVar8->first).index;
    (pcVar8->read).arena = (pcVar8->first).arena;
    iVar6 = (pcVar8->first).index;
    (pcVar8->write).chunk = cursor->chunk;
    iVar3 = (pcVar8->first).arena;
    (pcVar8->write).index = iVar6;
    (pcVar8->write).arena = iVar3;
    pcVar8->flags = pcVar8->flags & 0xfe;
  }
  (*pcVar8->vtbl->append)(pcVar8,(int)g_token_template_decl);
  g_yylval = (uint)local_8;
  token = arena_or_pool_alloc(0x30,g_token_arena_index);
  if (token == (c1_u8 *)0x0) {
    token = (c1_u8 *)0x0;
  }
  else {
    *token = 0xf3;
    puVar10 = &g_yylval;
    puVar11 = (uint *)(token + 8);
    for (iVar6 = 10; iVar6 != 0; iVar6 = iVar6 + -1) {
      *puVar11 = *puVar10;
      puVar10 = puVar10 + 1;
      puVar11 = puVar11 + 1;
    }
  }
  (*pcVar8->vtbl->append)(pcVar8,(int)token);
  token_list_clear_saved_state((int *)&local_8->first);
  (*pcVar8->vtbl->append)(pcVar8,(int)g_token_end_parse);
  g_token_arena_index = *g_token_arena_stack;
  g_token_arena_stack = (int *)g_token_arena_stack[1];
  token_source_push((c1_token_reader *)&g_token_position,pcVar8,4,1,(void *)0x0,&g_token_position);
  pcVar8 = g_token_source->stream;
  if ((pcVar8->flags & 2) == 0) {
    pcVar8->flags = pcVar8->flags | 2;
    (*pcVar8->vtbl->append)(pcVar8,g_token_end_of_stream);
  }
  g_compile_flags_cc = g_compile_flags_cc | 0x20;
  return '\x01';
}

