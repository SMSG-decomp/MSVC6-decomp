c1_u8 * __cdecl pp_line_directive(void)

{
  c1_token_source_frame **ppcVar1;
  _func_240 **pp_Var2;
  char cVar3;
  byte bVar4;
  c1_type *pcVar5;
  int iVar6;
  c1_u32 cVar7;
  byte *file;
  uchar *puVar8;
  c1_token *pcVar9;
  int *piVar10;
  byte *pbVar11;
  c1_saved_token_stream *pcVar12;
  c1_token *pcVar13;
  fe_arena *a;
  uint uVar14;
  byte *pbVar15;
  int iVar16;
  uint *puVar17;
  uchar *puVar18;
  c1_yystype *pcVar19;
  uint *puVar20;
  bool bVar21;
  
  iVar16 = g_opt_E_preprocess;
  g_opt_E_preprocess = 0;
  pcVar9 = token_next(&g_token_position);
  if (pcVar9->code == 0x65) {
    pcVar5 = (pcVar9->value).constant.type;
    cVar3 = (char)pcVar5->code;
    while (cVar3 < '\0') {
      pcVar5 = pcVar5->base;
      cVar3 = (char)pcVar5->code;
    }
    if ((pcVar5->code & 0x10) != 0) {
      iVar6 = (pcVar9->value).constant.hi;
      uVar14 = (pcVar9->value).constant.lo;
      if (((iVar6 < 0) || ((iVar6 < 1 && (uVar14 == 0)))) ||
         ((-1 < iVar6 && ((0 < iVar6 || (0x7fff < uVar14)))))) {
        diag_warning((-(uint)(g_ms_extensions != '\0') & 3) + 1,0x70);
      }
      cVar7 = (pcVar9->value).constant.lo;
      pcVar9 = token_next(&g_token_position);
      uVar14 = (uint)pcVar9->code;
      g_opt_E_preprocess = iVar16;
      if (uVar14 != 1) {
        if (uVar14 == 7) {
          if (((pcVar9->value).string.flags & 1) == 0) {
            file = (byte *)(pcVar9->value).string.text;
            pbVar11 = (byte *)pp_position_file_name(&g_token_position);
            pbVar15 = file;
            do {
              bVar4 = *pbVar15;
              bVar21 = bVar4 < *pbVar11;
              if (bVar4 != *pbVar11) {
LAB_1062d7ca:
                iVar16 = (1 - (uint)bVar21) - (uint)(bVar21 != 0);
                goto LAB_1062d759;
              }
              if (bVar4 == 0) break;
              bVar4 = pbVar15[1];
              bVar21 = bVar4 < pbVar11[1];
              if (bVar4 != pbVar11[1]) goto LAB_1062d7ca;
              pbVar15 = pbVar15 + 2;
              pbVar11 = pbVar11 + 2;
            } while (bVar4 != 0);
            iVar16 = 0;
LAB_1062d759:
            if (iVar16 != 0) {
              piVar10 = file_record_lookup_or_new(g_current_scope,(char *)file,0);
              if (piVar10 != (int *)0x0) goto LAB_1062d76f;
              goto LAB_1062d70d;
            }
          }
          else {
            diag_error(2);
          }
        }
        else if (uVar14 != 0x2d) {
          diag_error(0x82,uVar14);
          goto LAB_1062d6dd;
        }
        pcVar9 = (c1_token *)0x0;
      }
LAB_1062d70d:
      piVar10 = include_line_map_find(&g_lex_position,g_token_position);
      piVar10 = (int *)piVar10[2];
LAB_1062d76f:
      g_lex_position = g_lex_position + 1;
      vector_push_triple((int *)&g_line_map,g_lex_position,cVar7 - 1,(int)piVar10);
      g_token_position = g_lex_position;
      if (g_opt_E_preprocess == 0) {
        pcVar12 = arena_alloc(g_arenas,0x38);
        if (pcVar12 == (c1_saved_token_stream *)0x0) {
          pcVar12 = (c1_saved_token_stream *)0x0;
        }
        else {
          pcVar12 = token_stream_init(pcVar12,0,0);
        }
        token_source_push(&g_token_record_position,(int)pcVar12,0,0,0,&g_token_position);
        if (g_token_arena_index == 0) {
          pcVar13 = (c1_token *)pool_alloc_raw(&g_pool_default,0x20);
        }
        else {
          pcVar13 = arena_alloc(g_arenas + g_token_arena_index,0x20);
        }
        if (pcVar13 == (c1_token *)0x0) {
          pcVar13 = (c1_token *)0x0;
        }
        else {
          pcVar13->code = ':';
          puVar17 = &g_yylval;
          pcVar19 = &pcVar13->value;
          for (iVar16 = 6; iVar16 != 0; iVar16 = iVar16 + -1) {
            pcVar19->words[0] = *puVar17;
            puVar17 = puVar17 + 1;
            pcVar19 = (c1_yystype *)((int)pcVar19 + 4);
          }
        }
        (*g_token_save_frame->stream->vtbl->append)(g_token_save_frame->stream,pcVar13);
        pcVar13 = token_new_position_marker(0);
        (*g_token_save_frame->stream->vtbl->append)(g_token_save_frame->stream,pcVar13);
        if (pcVar9 != (c1_token *)0x0) {
          (*g_token_save_frame->stream->vtbl->append)(g_token_save_frame->stream,pcVar9);
        }
        (*g_token_save_frame->stream->vtbl->append)
                  (g_token_save_frame->stream,g_token_directive_end);
        pcVar12 = (c1_saved_token_stream *)0x0;
        if (g_token_save_frame != (c1_token_source_frame *)0x0) {
          ppcVar1 = &g_token_save_frame->prev;
          pcVar12 = g_token_save_frame->stream;
          g_token_record_position = g_token_save_frame->position;
          pp_Var2 = &g_token_save_frame->on_pop;
          g_token_save_frame = *ppcVar1;
          if (*pp_Var2 != (_func_240 *)0x0) {
            (**pp_Var2)();
          }
        }
        g_yylval = (uint)pcVar12;
        if (g_token_arena_index == 0) {
          if (g_pool_default.left < 0x20) {
            pool_reserve(&g_pool_default,0x20);
          }
          g_pool_default.left = g_pool_default.left - 0x20;
          puVar18 = g_pool_default.cur;
          g_pool_default.cur = g_pool_default.cur + 0x20;
        }
        else {
          a = g_arenas + g_token_arena_index;
          puVar18 = a->cur;
          puVar8 = g_arenas[g_token_arena_index].end;
          a->cur = puVar18 + 0x20;
          if (puVar8 < puVar18 + 0x20) {
            arena_grow(a);
          }
        }
        if (puVar18 == (uchar *)0x0) {
          puVar18 = (uchar *)0x0;
        }
        else {
          *puVar18 = 0xf4;
          puVar17 = &g_yylval;
          puVar20 = (uint *)(puVar18 + 8);
          for (iVar16 = 6; iVar16 != 0; iVar16 = iVar16 + -1) {
            *puVar20 = *puVar17;
            puVar17 = puVar17 + 1;
            puVar20 = puVar20 + 1;
          }
        }
      }
      else {
        pp_emit_line_directive();
        puVar18 = g_token_newline;
      }
      pp_warn_extra_tokens("#line");
      g_context_arena_index = 3;
      g_expr_arena_index = 3;
      return puVar18;
    }
  }
  diag_error(5,g_token_spelling[pcVar9->code]);
  g_opt_E_preprocess = iVar16;
LAB_1062d6dd:
  lex_skip_whitespace();
  g_context_arena_index = 3;
  g_expr_arena_index = 3;
  return g_token_newline;
}

