c1_u8 * __cdecl pp_line_directive(void)

{
  c1_token_source_frame **ppcVar1;
  _func_193 **pp_Var2;
  byte bVar3;
  byte *pbVar4;
  int iVar5;
  byte *pbVar6;
  c1_line_map_row *pcVar7;
  byte *pbVar8;
  fe_file_record *c;
  c1xx_token_stream *pcVar9;
  byte *marker_tok;
  byte *marker_tok_2;
  c1_arena *a;
  uint uVar10;
  byte *pbVar11;
  int iVar12;
  uint *puVar13;
  uint *dst_2;
  uint *dst;
  byte *marker_tok_3;
  bool bVar14;
  
  iVar12 = g_opt_E_preprocess;
  g_opt_E_preprocess = 0;
  pbVar6 = token_next((c1_token_reader *)&g_token_position);
  if (*pbVar6 == 0x65) {
    pbVar4 = *(byte **)(pbVar6 + 8);
    bVar3 = *pbVar4;
    while ((char)bVar3 < '\0') {
      pbVar4 = *(byte **)(pbVar4 + 4);
      bVar3 = *pbVar4;
    }
    if ((*pbVar4 & 0x10) != 0) {
      iVar5 = *(int *)(pbVar6 + 0x14);
      if (((iVar5 < 0) || ((iVar5 < 1 && (*(uint *)(pbVar6 + 0x10) == 0)))) ||
         ((-1 < iVar5 && ((0 < iVar5 || (0x7fff < *(uint *)(pbVar6 + 0x10))))))) {
        diag_warning((-(uint)(g_ms_extensions != '\0') & 3) + 1,0x70);
      }
      iVar5 = *(int *)(pbVar6 + 0x10);
      pbVar6 = token_next((c1_token_reader *)&g_token_position);
      uVar10 = (uint)*pbVar6;
      g_opt_E_preprocess = iVar12;
      if (uVar10 != 1) {
        if (uVar10 == 7) {
          if ((pbVar6[0xe] & 1) == 0) {
            pbVar4 = *(byte **)(pbVar6 + 8);
            pbVar8 = (byte *)pp_position_file_name(&g_token_position);
            pbVar11 = pbVar4;
            do {
              bVar3 = *pbVar11;
              bVar14 = bVar3 < *pbVar8;
              if (bVar3 != *pbVar8) {
LAB_104621d7:
                iVar12 = (1 - (uint)bVar14) - (uint)(bVar14 != 0);
                goto LAB_104621ba;
              }
              if (bVar3 == 0) break;
              bVar3 = pbVar11[1];
              bVar14 = bVar3 < pbVar8[1];
              if (bVar3 != pbVar8[1]) goto LAB_104621d7;
              pbVar11 = pbVar11 + 2;
              pbVar8 = pbVar8 + 2;
            } while (bVar3 != 0);
            iVar12 = 0;
LAB_104621ba:
            if (iVar12 == 0) {
              pbVar6 = (byte *)0x0;
            }
            else {
              c = file_record_lookup_or_new(g_current_scope,(char *)pbVar4,0);
              if (c != (fe_file_record *)0x0) goto LAB_104620c4;
            }
            goto LAB_104620b1;
          }
          diag_error(2);
        }
        else if (uVar10 != 0x2d) {
          diag_error(0x82,uVar10);
          lex_skip_whitespace();
          goto joined_r0x104623c1;
        }
        pbVar6 = (byte *)0x0;
      }
LAB_104620b1:
      pcVar7 = include_line_map_find((c1_line_map_state *)&g_lex_position,g_token_position);
      c = pcVar7->file;
LAB_104620c4:
      g_lex_position = g_lex_position + 1;
      vector_push_triple((int *)&g_line_map,g_lex_position,iVar5 + -1,(int)c);
      g_token_position = g_lex_position;
      if (g_opt_E_preprocess == 0) {
        pcVar9 = arena_alloc(g_arenas,0x38);
        if (pcVar9 == (c1xx_token_stream *)0x0) {
          pcVar9 = (c1xx_token_stream *)0x0;
        }
        else {
          pcVar9 = token_stream_init(pcVar9,0,0);
        }
        token_source_push((c1_token_reader *)&g_token_record_position,pcVar9,0,0,(void *)0x0,
                          &g_token_position);
        if (g_token_arena_index == 0) {
          marker_tok = pool_alloc_raw(&g_pool_default,0x30);
        }
        else {
          marker_tok = arena_alloc(g_arenas + g_token_arena_index,0x30);
        }
        if (marker_tok == (byte *)0x0) {
          marker_tok = (byte *)0x0;
        }
        else {
          *marker_tok = 0x3a;
          puVar13 = &g_yylval;
          dst_2 = (uint *)(marker_tok + 8);
          for (iVar12 = 10; iVar12 != 0; iVar12 = iVar12 + -1) {
            *dst_2 = *puVar13;
            puVar13 = puVar13 + 1;
            dst_2 = dst_2 + 1;
          }
        }
        (*g_token_save_frame->stream->vtbl->append)(g_token_save_frame->stream,(int)marker_tok);
        marker_tok_2 = token_new_position_marker(0);
        (*g_token_save_frame->stream->vtbl->append)(g_token_save_frame->stream,(int)marker_tok_2);
        if (pbVar6 != (byte *)0x0) {
          (*g_token_save_frame->stream->vtbl->append)(g_token_save_frame->stream,(int)pbVar6);
        }
        (*g_token_save_frame->stream->vtbl->append)
                  (g_token_save_frame->stream,(int)g_token_directive_end);
        if (g_token_save_frame == (c1_token_source_frame *)0x0) {
          pcVar9 = (c1xx_token_stream *)0x0;
        }
        else {
          ppcVar1 = &g_token_save_frame->prev;
          pcVar9 = g_token_save_frame->stream;
          g_token_record_position = g_token_save_frame->position;
          pp_Var2 = &g_token_save_frame->on_pop;
          g_token_save_frame = *ppcVar1;
          if (*pp_Var2 != (_func_193 *)0x0) {
            (**pp_Var2)();
          }
        }
        g_yylval = (uint)pcVar9;
        if (g_token_arena_index == 0) {
          if (g_pool_default_left < 0x30) {
            pool_reserve((c1xx_pool *)&g_pool_default,0x30);
          }
          g_pool_default_left = g_pool_default_left - 0x30;
          marker_tok_3 = g_pool_default;
          g_pool_default = g_pool_default + 0x30;
        }
        else {
          a = g_arenas + g_token_arena_index;
          marker_tok_3 = a->cur;
          pbVar6 = g_arenas[g_token_arena_index].end;
          a->cur = marker_tok_3 + 0x30;
          if (pbVar6 < marker_tok_3 + 0x30) {
            arena_grow(a);
          }
        }
        if (marker_tok_3 == (byte *)0x0) {
          marker_tok_3 = (byte *)0x0;
        }
        else {
          *marker_tok_3 = 0xf4;
          puVar13 = &g_yylval;
          dst = (uint *)(marker_tok_3 + 8);
          for (iVar12 = 10; iVar12 != 0; iVar12 = iVar12 + -1) {
            *dst = *puVar13;
            puVar13 = puVar13 + 1;
            dst = dst + 1;
          }
        }
      }
      else {
        pp_emit_line_directive();
        marker_tok_3 = g_token_newline;
      }
      pp_warn_extra_tokens("#line");
      if ((((g_compile_flags_c8 & 0x32000000) == 0) &&
          (((((g_compile_flags_c8 & 0x40000000) == 0 || (((byte)g_compile_flags_cc & 8) != 0)) ||
            ((g_compile_flags_c4 & 0x200) != 0)) && (((byte)g_compile_flags_cc & 0x10) == 0)))) &&
         (((g_compile_flags_c8 & 0x4000000) == 0 || ((g_compile_flags_c4 & 0x8000) != 0)))) {
        g_context_arena_index = 5;
        g_expr_arena_index = 5;
        if (((byte)g_compile_flags_cc & 1) != 0) {
          g_context_arena_index = 4;
          g_expr_arena_index = 4;
          return marker_tok_3;
        }
      }
      else {
        g_context_arena_index = 0;
        g_expr_arena_index = 0;
      }
      return marker_tok_3;
    }
  }
  diag_error(5,g_token_spelling[*pbVar6]);
  g_opt_E_preprocess = iVar12;
  lex_skip_whitespace();
joined_r0x104623c1:
  if ((((g_compile_flags_c8 & 0x32000000) == 0) &&
      ((((g_compile_flags_c8 & 0x40000000) == 0 || (((byte)g_compile_flags_cc & 8) != 0)) ||
       ((g_compile_flags_c4 & 0x200) != 0)))) && (((byte)g_compile_flags_cc & 0x10) == 0)) {
    if (((g_compile_flags_c8 & 0x4000000) == 0) || ((g_compile_flags_c4 & 0x8000) != 0)) {
      if (((byte)g_compile_flags_cc & 1) == 0) {
        g_expr_arena_index = 5;
        g_context_arena_index = 5;
        return g_token_newline;
      }
      g_context_arena_index = 4;
      g_expr_arena_index = 4;
      g_current_scope = g_current_scope;
      g_token_directive_end = g_token_directive_end;
      g_compile_flags_c4 = g_compile_flags_c4;
      g_compile_flags_c8 = g_compile_flags_c8;
      g_compile_flags_cc._0_1_ = (byte)g_compile_flags_cc;
      g_lex_position = g_lex_position;
      g_ms_extensions = g_ms_extensions;
      g_token_arena_index = g_token_arena_index;
      g_yylval = g_yylval;
      g_token_position = g_token_position;
      g_token_record_position = g_token_record_position;
      g_token_save_frame = g_token_save_frame;
      g_pool_default = g_pool_default;
      g_pool_default_left = g_pool_default_left;
      g_opt_E_preprocess = g_opt_E_preprocess;
      return g_token_newline;
    }
  }
  g_context_arena_index = 0;
  g_expr_arena_index = 0;
  return g_token_newline;
}

