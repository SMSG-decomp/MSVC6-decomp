char __cdecl lex_push_next_forced_include(void)

{
  c1_token_source_frame **ppcVar1;
  _func_193 **pp_Var2;
  int iVar3;
  c1xx_token_stream *pcVar4;
  c1_u8 *token;
  int *piVar5;
  
  while ((g_forced_include_files != (ushort *)0x0 &&
         ((int)(short)g_forced_include_index < (int)(uint)*g_forced_include_files))) {
    g_forced_include_current =
         *(byte **)(*(int *)(g_forced_include_files + 4) + (short)g_forced_include_index * 4);
    g_forced_include_index._0_2_ = (short)g_forced_include_index + 1;
    iVar3 = pp_include_open_file_2(g_forced_include_current,'\0');
    piVar5 = (int *)g_arenas[4].cur;
    if (-1 < iVar3) {
      if (g_opt_E_preprocess == 0) {
        g_arenas[4].cur = g_arenas[4].cur + 8;
        if (g_arenas[4].end < g_arenas[4].cur) {
          arena_grow(g_arenas + 4);
        }
        if (piVar5 == (int *)0x0) {
          piVar5 = (int *)0x0;
        }
        else {
          *piVar5 = g_token_arena_index;
          *(int **)((int)piVar5 + 4) = g_token_arena_stack;
        }
        g_token_arena_index = 4;
        g_token_arena_stack = piVar5;
        pcVar4 = arena_alloc(g_arenas + 4,0x38);
        if (pcVar4 == (c1xx_token_stream *)0x0) {
          pcVar4 = (c1xx_token_stream *)0x0;
        }
        else {
          pcVar4 = token_stream_init(pcVar4,4,1);
        }
        token_source_push((c1_token_reader *)&g_token_record_position,pcVar4,4,0,(void *)0x0,
                          &g_token_position);
        token = pp_include_directive_token(0);
        (*g_token_save_frame->stream->vtbl->append)(g_token_save_frame->stream,(int)token);
        (*g_token_save_frame->stream->vtbl->append)
                  (g_token_save_frame->stream,g_token_end_of_stream);
        pcVar4 = (c1xx_token_stream *)0x0;
        if (g_token_save_frame != (c1_token_source_frame *)0x0) {
          ppcVar1 = &g_token_save_frame->prev;
          pcVar4 = g_token_save_frame->stream;
          g_token_record_position = g_token_save_frame->position;
          pp_Var2 = &g_token_save_frame->on_pop;
          g_token_save_frame = *ppcVar1;
          if (*pp_Var2 != (_func_193 *)0x0) {
            (**pp_Var2)();
          }
        }
        token_source_push((c1_token_reader *)&g_token_position,pcVar4,4,1,(void *)0x0,
                          &g_token_position);
        g_token_arena_index = *g_token_arena_stack;
        g_token_arena_stack = (int *)g_token_arena_stack[1];
      }
      return '\x01';
    }
  }
  return '\0';
}

