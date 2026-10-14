char __cdecl lex_skip_unchanged_function_body(int byte_count,uint position_delta)

{
  c1_token_source_frame **ppcVar1;
  _func_193 **pp_Var2;
  byte bVar3;
  int iVar4;
  c1xx_token_stream *pcVar5;
  int *piVar6;
  
  iVar4 = lex_input_bytes_left();
  if (iVar4 < byte_count) {
    for (; byte_count != 0; byte_count = byte_count + -1) {
      bVar3 = *g_input_ptr;
      g_input_ptr = g_input_ptr + 1;
      if (bVar3 == 0) {
        iVar4 = file_read_or_fatal();
        if (iVar4 != 0) {
          return '\0';
        }
        g_input_ptr = g_input_ptr + 1;
      }
    }
  }
  else {
    g_input_ptr = g_input_ptr + byte_count;
  }
  piVar6 = (int *)g_arenas[4].cur;
  g_lex_position = g_lex_position + (position_delta & 0xffff);
  g_arenas[4].cur = g_arenas[4].cur + 8;
  g_token_position = g_lex_position;
  if (g_arenas[4].end < g_arenas[4].cur) {
    arena_grow(g_arenas + 4);
  }
  if (piVar6 == (int *)0x0) {
    piVar6 = (int *)0x0;
  }
  else {
    *piVar6 = g_token_arena_index;
    *(int **)((int)piVar6 + 4) = g_token_arena_stack;
  }
  g_token_arena_index = 4;
  g_token_arena_stack = piVar6;
  pcVar5 = arena_alloc(g_arenas + 4,0x38);
  if (pcVar5 == (c1xx_token_stream *)0x0) {
    pcVar5 = (c1xx_token_stream *)0x0;
  }
  else {
    pcVar5 = token_stream_init(pcVar5,4,1);
  }
  token_source_push((c1_token_reader *)&g_token_record_position,pcVar5,4,0,(void *)0x0,
                    &g_token_position);
  (*g_token_save_frame->stream->vtbl->append)(g_token_save_frame->stream,(int)g_token_rbrace);
  (*g_token_save_frame->stream->vtbl->append)(g_token_save_frame->stream,g_token_end_of_stream);
  pcVar5 = (c1xx_token_stream *)0x0;
  if (g_token_save_frame != (c1_token_source_frame *)0x0) {
    ppcVar1 = &g_token_save_frame->prev;
    pcVar5 = g_token_save_frame->stream;
    g_token_record_position = g_token_save_frame->position;
    pp_Var2 = &g_token_save_frame->on_pop;
    g_token_save_frame = *ppcVar1;
    if (*pp_Var2 != (_func_193 *)0x0) {
      (**pp_Var2)();
    }
  }
  token_source_push((c1_token_reader *)&g_token_position,pcVar5,4,1,(void *)0x0,&g_token_position);
  g_token_arena_index = *g_token_arena_stack;
  g_token_arena_stack = (int *)g_token_arena_stack[1];
  return '\x01';
}

