c1_u8 * __cdecl pp_pragma_directive(void)

{
  c1_token_source_frame **ppcVar1;
  _func_240 **pp_Var2;
  uchar *puVar3;
  c1_token *pcVar4;
  int iVar5;
  c1_saved_token_stream *pcVar6;
  fe_arena *a;
  uchar *puVar7;
  c1_u8 *pcVar8;
  uint *puVar9;
  uint *puVar10;
  
  if (g_opt_E_preprocess != 0) {
    pcVar8 = pp_output_pragma();
    return pcVar8;
  }
  if (g_opt_Zg != '\0') {
    lex_skip_whitespace();
    return g_token_newline;
  }
  pcVar4 = token_next(&g_token_position);
  if (pcVar4->code != '-') {
    (*g_token_source->stream->vtbl->unget)(g_token_source->stream,pcVar4);
    pcVar4 = pragma_warn_expected_token('\x06');
    if (pcVar4 != (c1_token *)0x0) {
      iVar5 = pragma_lookup_name(((pcVar4->value).name)->text);
      if (iVar5 != 0x24) {
        pcVar6 = arena_alloc(g_arenas + 1,0x38);
        if (pcVar6 == (c1_saved_token_stream *)0x0) {
          pcVar6 = (c1_saved_token_stream *)0x0;
        }
        else {
          pcVar6 = token_stream_init(pcVar6,1,0);
        }
        token_source_push(&g_token_record_position,(int)pcVar6,1,0,0,&g_token_position);
        pcVar4 = (c1_token *)g_arenas[1].cur;
        g_arenas[1].cur = g_arenas[1].cur + 0x20;
        if (g_arenas[1].end < g_arenas[1].cur) {
          arena_grow(g_arenas + 1);
        }
        if (pcVar4 == (c1_token *)0x0) {
          pcVar4 = (c1_token *)0x0;
        }
        else {
          pcVar4->code = (uchar)iVar5;
          *(uchar *)((int)pcVar4 + 8) = (uchar)iVar5;
        }
        (*g_token_save_frame->stream->vtbl->append)(g_token_save_frame->stream,pcVar4);
        g_compile_flags_c4 = (uint)(iVar5 == 0x1d) << 0xd | g_compile_flags_c4 & 0xffffdfff;
        do {
          pcVar4 = token_next(&g_token_position);
          (*g_token_save_frame->stream->vtbl->append)(g_token_save_frame->stream,pcVar4);
        } while (pcVar4->code != '-');
        g_compile_flags_c4 = g_compile_flags_c4 & 0xffffdfff;
        pcVar6 = (c1_saved_token_stream *)0x0;
        if (g_token_save_frame != (c1_token_source_frame *)0x0) {
          ppcVar1 = &g_token_save_frame->prev;
          pcVar6 = g_token_save_frame->stream;
          g_token_record_position = g_token_save_frame->position;
          pp_Var2 = &g_token_save_frame->on_pop;
          g_token_save_frame = *ppcVar1;
          if (*pp_Var2 != (_func_240 *)0x0) {
            (**pp_Var2)();
          }
        }
        g_yylval = (uint)pcVar6;
        if (g_token_arena_index == 0) {
          if (g_pool_default.left < 0x20) {
            pool_reserve(&g_pool_default,0x20);
          }
          g_pool_default.left = g_pool_default.left - 0x20;
          puVar7 = g_pool_default.cur;
          g_pool_default.cur = g_pool_default.cur + 0x20;
        }
        else {
          a = g_arenas + g_token_arena_index;
          puVar7 = a->cur;
          puVar3 = g_arenas[g_token_arena_index].end;
          a->cur = puVar7 + 0x20;
          if (puVar3 < puVar7 + 0x20) {
            arena_grow(a);
          }
        }
        if (puVar7 == (c1_u8 *)0x0) {
          return (c1_u8 *)0x0;
        }
        *puVar7 = 0xf4;
        puVar9 = &g_yylval;
        puVar10 = (uint *)(puVar7 + 8);
        for (iVar5 = 6; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar10 = *puVar9;
          puVar9 = puVar9 + 1;
          puVar10 = puVar10 + 1;
        }
        return puVar7;
      }
      pragma_include_alias();
    }
    pragma_expect_dash_token();
  }
  return g_token_newline;
}

