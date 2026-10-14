void __cdecl parse_scan_parenthesized_candidates(void)

{
  c1_token_source_frame **ppcVar1;
  _func_193 **pp_Var2;
  int iVar3;
  c1xx_token_stream *pcVar4;
  c1xx_token *token;
  int iVar5;
  int iVar6;
  
  iVar6 = 0;
  pcVar4 = arena_alloc(g_arenas + 5,0x38);
  if (pcVar4 == (c1xx_token_stream *)0x0) {
    pcVar4 = (c1xx_token_stream *)0x0;
  }
  else {
    pcVar4 = token_stream_copy(pcVar4,g_token_source->stream);
  }
  token_source_push((c1_token_reader *)&g_token_position,pcVar4,5,0,(void *)0x0,&g_token_position);
  do {
    token = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
    switch(token->code) {
    case 'v':
      iVar6 = iVar6 + 1;
      iVar5 = g_paren_depth + 1;
      if (0x3b < iVar5) {
        g_paren_depth = iVar5;
        diag_fatal_simple(0xd);
      }
      iVar3 = g_paren_depth + 1;
      g_paren_depth = iVar5;
      g_paren_level_flags[iVar3] = 0;
      break;
    case '~':
      iVar6 = iVar6 + -1;
      if (iVar6 < 0) {
        if (g_token_source == (c1_token_source_frame *)0x0) {
          return;
        }
        g_token_position = g_token_source->position;
        pp_Var2 = &g_token_source->on_pop;
        if (*pp_Var2 == (_func_193 *)0x0) {
          g_token_source = g_token_source->prev;
          return;
        }
        g_token_source = g_token_source->prev;
        (**pp_Var2)();
        return;
      }
      if (0 < g_paren_depth) {
        g_paren_depth = g_paren_depth + -1;
      }
      break;
    case 0xa4:
      if (iVar6 < 2) {
        tree_new_type_token_node(token,token->type_value);
      }
      else {
        g_compile_flags_c4 = g_compile_flags_c4 & 0xbfffffff;
        (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)token);
        parse_classify_candidate_token('\0');
      }
      break;
    case 0xf7:
      if (g_token_source != (c1_token_source_frame *)0x0) {
        ppcVar1 = &g_token_source->prev;
        g_token_position = g_token_source->position;
        pp_Var2 = &g_token_source->on_pop;
        g_token_source = *ppcVar1;
        if (*pp_Var2 != (_func_193 *)0x0) {
          (**pp_Var2)();
          return;
        }
      }
      return;
    }
  } while( true );
}

