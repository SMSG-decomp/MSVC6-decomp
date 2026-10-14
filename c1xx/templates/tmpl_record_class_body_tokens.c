void * tmpl_record_class_body_tokens(void)

{
  c1xx_token_stream *pcVar1;
  int *piVar2;
  
  piVar2 = (int *)g_arenas[0].cur;
  g_arenas[0].cur = g_arenas[0].cur + 8;
  if (g_arenas[0].end < g_arenas[0].cur) {
    arena_grow(g_arenas);
  }
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)0x0;
  }
  else {
    *piVar2 = g_token_arena_index;
    *(int **)((int)piVar2 + 4) = g_token_arena_stack;
  }
  g_token_arena_index = 0;
  g_token_arena_stack = piVar2;
  pcVar1 = arena_alloc(g_arenas,0x38);
  if (pcVar1 == (c1xx_token_stream *)0x0) {
    pcVar1 = (c1xx_token_stream *)0x0;
  }
  else {
    pcVar1 = token_stream_init(pcVar1,0,0);
  }
  token_source_push((c1_token_reader *)&g_token_record_position,pcVar1,0,0,(void *)0x0,
                    &g_token_position);
  parse_record_tokens_to_delimiter(g_token_save_frame->stream,2,'\x01');
  (*g_token_save_frame->stream->vtbl->append)(g_token_save_frame->stream,(int)g_token_semicolon);
  g_compile_flags_c8 = g_compile_flags_c8 | 0x80000000;
  g_token_arena_index = *g_token_arena_stack;
  g_token_arena_stack = (int *)g_token_arena_stack[1];
  return g_token_semicolon;
}

