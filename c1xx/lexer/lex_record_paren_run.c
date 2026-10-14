void __cdecl lex_record_paren_run(char *token)

{
  c1_token_source_frame **ppcVar1;
  _func_193 **pp_Var2;
  uint uVar3;
  int *piVar4;
  c1xx_token_stream *pcVar5;
  c1_u8 *token_copy;
  uint *dst;
  int iVar6;
  byte from_source;
  
  g_compile_flags_c4 = g_compile_flags_c4 & 0xfffffff7 | 0x10000000;
  from_source = g_token_source->stream->flags & 1;
  if (((g_compile_flags_c8 & 0x10000000) == 0) && (((byte)g_compile_flags_cc & 8) == 0)) {
    piVar4 = arena_alloc(g_arenas + 2,8);
    if (piVar4 == (int *)0x0) {
      piVar4 = (int *)0x0;
    }
    else {
      *piVar4 = g_token_arena_index;
      piVar4[1] = (int)g_token_arena_stack;
    }
    g_token_arena_index = 2;
    g_context_arena_index = 2;
    g_expr_arena_index = 2;
    g_token_arena_stack = piVar4;
    pcVar5 = arena_alloc(g_arenas + 2,0x38);
    if (pcVar5 == (c1xx_token_stream *)0x0) {
      pcVar5 = (c1xx_token_stream *)0x0;
      iVar6 = 2;
    }
    else {
      pcVar5 = token_stream_init(pcVar5,2,from_source);
      iVar6 = 2;
    }
  }
  else {
    piVar4 = arena_alloc(g_arenas,8);
    if (piVar4 == (int *)0x0) {
      piVar4 = (int *)0x0;
    }
    else {
      *piVar4 = g_token_arena_index;
      piVar4[1] = (int)g_token_arena_stack;
    }
    g_token_arena_index = 0;
    g_context_arena_index = 0;
    g_expr_arena_index = 0;
    g_token_arena_stack = piVar4;
    pcVar5 = arena_alloc(g_arenas,0x38);
    if (pcVar5 == (c1xx_token_stream *)0x0) {
      pcVar5 = (c1xx_token_stream *)0x0;
    }
    else {
      pcVar5 = token_stream_init(pcVar5,0,from_source);
    }
    iVar6 = 0;
  }
  token_source_push((c1_token_reader *)&g_token_record_position,pcVar5,iVar6,0,(void *)0x0,
                    &g_token_position);
  if (token == (char *)0x0) {
    iVar6 = 0;
  }
  else {
    if (g_token_arena_index == 0) {
      token_copy = pool_alloc_raw(&g_pool_default,0x30);
    }
    else {
      token_copy = arena_alloc(g_arenas + g_token_arena_index,0x30);
    }
    if ((uint *)token_copy == (uint *)0x0) {
      token_copy = (c1_u8 *)0x0;
    }
    else {
      dst = (uint *)token_copy;
      for (iVar6 = 0xc; iVar6 != 0; iVar6 = iVar6 + -1) {
        *dst = *(uint *)token;
        token = (char *)((int)token + 4);
        dst = dst + 1;
      }
    }
    (*g_token_save_frame->stream->vtbl->append)(g_token_save_frame->stream,(int)token_copy);
    (*g_token_save_frame->stream->vtbl->append)(g_token_save_frame->stream,g_token_lparen);
    iVar6 = 1;
  }
  lex_record_balanced_tokens(iVar6);
  (*g_token_save_frame->stream->vtbl->append)(g_token_save_frame->stream,g_token_end_of_stream);
  if (g_token_save_frame == (c1_token_source_frame *)0x0) {
    pcVar5 = (c1xx_token_stream *)0x0;
  }
  else {
    ppcVar1 = &g_token_save_frame->prev;
    pcVar5 = g_token_save_frame->stream;
    g_token_record_position = g_token_save_frame->position;
    pp_Var2 = &g_token_save_frame->on_pop;
    g_token_save_frame = *ppcVar1;
    if (*pp_Var2 != (_func_193 *)0x0) {
      (**pp_Var2)();
    }
  }
  token_source_push((c1_token_reader *)&g_token_position,pcVar5,2,1,lex_record_paren_run_on_pop,
                    &g_token_position);
  uVar3 = g_compile_flags_c4;
  g_compile_flags_c4 = g_compile_flags_c4 & 0xefffffff;
  if (((((g_compile_flags_c8 & 0x32000000) == 0) &&
       ((((g_compile_flags_c8 & 0x40000000) == 0 || (((byte)g_compile_flags_cc & 8) != 0)) ||
        ((uVar3 & 0x200) != 0)))) && (((byte)g_compile_flags_cc & 0x10) == 0)) &&
     (((g_compile_flags_c8 & 0x4000000) == 0 || ((uVar3 & 0x8000) != 0)))) {
    g_context_arena_index = 5;
    g_expr_arena_index = 5;
    if (((byte)g_compile_flags_cc & 1) != 0) {
      g_context_arena_index = 4;
      g_expr_arena_index = 4;
    }
  }
  else {
    g_context_arena_index = 0;
    g_expr_arena_index = 0;
  }
  g_token_arena_index = *g_token_arena_stack;
  g_token_arena_stack = (int *)g_token_arena_stack[1];
  return;
}

