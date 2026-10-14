c1_u8 * __cdecl pp_pragma_directive(void)

{
  _func_193 **pp_Var1;
  c1_u8 *pcVar2;
  byte *pbVar3;
  uchar *puVar4;
  int iVar5;
  c1xx_token_stream *pcVar6;
  c1_arena *a;
  uint *frame;
  c1_u8 *pcVar7;
  uint *puVar8;
  uint *callback;
  
  if (g_opt_E_preprocess != 0) {
    pcVar7 = (c1_u8 *)pp_pragma_directive_to_output();
    return pcVar7;
  }
  if (g_opt_Zg != '\0') {
    lex_skip_whitespace();
    return g_token_newline;
  }
  pbVar3 = token_next((c1_token_reader *)&g_token_position);
  if (*pbVar3 != 0x2d) {
    (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)pbVar3);
    puVar4 = pragma_warn_expected_token('\x06');
    if (puVar4 != (uchar *)0x0) {
      iVar5 = pragma_lookup_name(*(char **)(*(int *)(puVar4 + 8) + 4));
      if (iVar5 != 0x24) {
        if (iVar5 == 0x2f) {
          pragma_start_map_region();
          return g_token_newline;
        }
        if (iVar5 == 0x31) {
          pcVar7 = (c1_u8 *)pragma_implementation_key();
          return pcVar7;
        }
        pcVar6 = arena_alloc(g_arenas + 1,0x38);
        if (pcVar6 == (c1xx_token_stream *)0x0) {
          pcVar6 = (c1xx_token_stream *)0x0;
        }
        else {
          pcVar6 = token_stream_init(pcVar6,1,0);
        }
        token_source_push((c1_token_reader *)&g_token_record_position,pcVar6,1,0,(void *)0x0,
                          &g_token_position);
        pcVar7 = g_arenas[1].cur;
        g_arenas[1].cur = g_arenas[1].cur + 0x30;
        if (g_arenas[1].end < g_arenas[1].cur) {
          arena_grow(g_arenas + 1);
        }
        if (pcVar7 == (c1_u8 *)0x0) {
          pcVar7 = (c1_u8 *)0x0;
        }
        else {
          *pcVar7 = (c1_u8)iVar5;
          pcVar7[8] = (c1_u8)iVar5;
        }
        (*g_token_save_frame->stream->vtbl->append)(g_token_save_frame->stream,(int)pcVar7);
        g_compile_flags_c4 = (uint)(iVar5 == 0x1d) << 0xd | g_compile_flags_c4 & 0xffffdfff;
        do {
          pbVar3 = token_next((c1_token_reader *)&g_token_position);
          (*g_token_save_frame->stream->vtbl->append)(g_token_save_frame->stream,(int)pbVar3);
        } while (*pbVar3 != 0x2d);
        g_compile_flags_c4 = g_compile_flags_c4 & 0xffffdfff;
        pcVar6 = (c1xx_token_stream *)0x0;
        if (g_token_save_frame != (c1_token_source_frame *)0x0) {
          callback = (uint *)&g_token_save_frame->prev;
          pcVar6 = g_token_save_frame->stream;
          g_token_record_position = g_token_save_frame->position;
          pp_Var1 = &g_token_save_frame->on_pop;
          g_token_save_frame = (c1_token_source_frame *)*callback;
          if (*pp_Var1 != (_func_193 *)0x0) {
            (**pp_Var1)();
          }
        }
        g_yylval = (uint)pcVar6;
        if (g_token_arena_index == 0) {
          if (g_pool_default_left < 0x30) {
            pool_reserve((c1xx_pool *)&g_pool_default,0x30);
          }
          g_pool_default_left = g_pool_default_left - 0x30;
          pcVar7 = g_pool_default;
          g_pool_default = g_pool_default + 0x30;
        }
        else {
          a = g_arenas + g_token_arena_index;
          pcVar7 = a->cur;
          pcVar2 = g_arenas[g_token_arena_index].end;
          a->cur = pcVar7 + 0x30;
          if (pcVar2 < pcVar7 + 0x30) {
            arena_grow(a);
          }
        }
        if (pcVar7 == (c1_u8 *)0x0) {
          return (c1_u8 *)0x0;
        }
        *pcVar7 = 0xf4;
        frame = &g_yylval;
        puVar8 = (uint *)(pcVar7 + 8);
        for (iVar5 = 10; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar8 = *frame;
          frame = frame + 1;
          puVar8 = puVar8 + 1;
        }
        return pcVar7;
      }
      pragma_include_alias();
    }
    pragma_expect_dash_token();
  }
  return g_token_newline;
}

