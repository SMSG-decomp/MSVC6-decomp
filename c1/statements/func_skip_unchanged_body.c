char __cdecl func_skip_unchanged_body(int body_bytes,ushort position_delta)

{
  c1_token_source_frame **ppcVar1;
  _func_240 **pp_Var2;
  byte bVar3;
  int iVar4;
  c1_saved_token_stream *pcVar5;
  int *piVar6;
  
  iVar4 = lex_input_bytes_left();
  if (iVar4 < body_bytes) {
    for (; body_bytes != 0; body_bytes = body_bytes + -1) {
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
    g_input_ptr = g_input_ptr + body_bytes;
  }
  piVar6 = (int *)g_arenas[2].cur;
  g_lex_position = g_lex_position + (uint)position_delta;
  g_arenas[2].cur = g_arenas[2].cur + 8;
  g_token_position = g_lex_position;
  if (g_arenas[2].end < g_arenas[2].cur) {
    arena_grow(g_arenas + 2);
  }
  if (piVar6 == (int *)0x0) {
    piVar6 = (int *)0x0;
  }
  else {
    *piVar6 = g_token_arena_index;
    *(int **)((int)piVar6 + 4) = g_token_arena_stack;
  }
  g_token_arena_index = 2;
  g_token_arena_stack = piVar6;
  pcVar5 = arena_alloc(g_arenas + 2,0x38);
  if (pcVar5 == (c1_saved_token_stream *)0x0) {
    pcVar5 = (c1_saved_token_stream *)0x0;
  }
  else {
    pcVar5 = token_stream_init(pcVar5,2,1);
  }
  token_source_push(&g_token_record_position,(int)pcVar5,2,0,0,&g_token_position);
  (*g_token_save_frame->stream->vtbl->append)(g_token_save_frame->stream,g_token_rbrace);
  (*g_token_save_frame->stream->vtbl->append)(g_token_save_frame->stream,g_token_end_of_stream);
  pcVar5 = (c1_saved_token_stream *)0x0;
  if (g_token_save_frame != (c1_token_source_frame *)0x0) {
    ppcVar1 = &g_token_save_frame->prev;
    pcVar5 = g_token_save_frame->stream;
    g_token_record_position = g_token_save_frame->position;
    pp_Var2 = &g_token_save_frame->on_pop;
    g_token_save_frame = *ppcVar1;
    if (*pp_Var2 != (_func_240 *)0x0) {
      (**pp_Var2)();
    }
  }
  token_source_push(&g_token_position,(int)pcVar5,2,1,0,&g_token_position);
  g_token_arena_index = *g_token_arena_stack;
  g_token_arena_stack = (int *)g_token_arena_stack[1];
  return '\x01';
}

