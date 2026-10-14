c1_u8 * __cdecl pp_directive(int if_value,int pch_mode_two,char include_angle,int if_value_high)

{
  c1_token_cursor *buffer;
  c1_token_source_frame **ppcVar1;
  _func_240 **pp_Var2;
  c1_u8 cVar3;
  int iVar4;
  int iVar5;
  c1_token *pcVar6;
  uchar *puVar7;
  byte bVar8;
  byte bVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  c1_u8 *pcVar14;
  byte *pbVar15;
  c1_saved_token_stream *stream;
  c1_token *pcVar16;
  c1_saved_token_stream *pcVar17;
  fe_arena *pfVar18;
  ushort uVar19;
  short sVar20;
  char *pcVar21;
  uint *puVar22;
  c1_yystype *pcVar23;
  uint *puVar24;
  bool bVar25;
  longlong lVar26;
  undefined4 in_stack_00000018;
  
  sVar20 = (short)if_value;
  pp_skip_line_comments();
  iVar12 = pch_record_or_match_directive();
  iVar13 = g_opt_E_preprocess;
  if (iVar12 == 1) {
    g_context_arena_index = 3;
    g_expr_arena_index = 3;
    return g_token_newline;
  }
  if (g_pch_directive_mode != pch_mode_two) {
    g_compile_flags_c4 = g_compile_flags_c4 | 0x4000;
    g_opt_E_preprocess = 0;
    lVar26 = pp_if_evaluate_expression();
    if_value_high = (int)((ulonglong)lVar26 >> 0x20);
    g_compile_flags_c4 = g_compile_flags_c4 & 0xffffbfff;
    sVar20 = (short)lVar26;
    g_opt_E_preprocess = iVar13;
    pp_warn_extra_tokens("#if/#elif");
  }
  iVar13 = pch_record_or_replay_if_value((int)sVar20);
  lVar26 = (longlong)iVar13;
LAB_10608de3:
  if ((lVar26 != 0) || (iVar13 = pp_check_expected_endif(5), iVar13 == 3)) {
    iVar13 = (*g_idb->vtbl->idb_conditional_enter)(g_idb);
    if (iVar13 == 0) {
      diag_fatal(0x49,".\\p0prepro.c",0x2f9);
    }
    uVar11 = pp_cond_stack_push();
    g_pp_cond_states[uVar11] = (-(uint)(lVar26 == 0) & 2) + 1;
    if (g_opt_EP_no_line != '\0') {
      g_expr_arena_index = 3;
      g_context_arena_index = 3;
      return g_token_newline;
    }
    bVar25 = lVar26 == 0;
LAB_10608fe8:
    if (!bVar25) {
      g_expr_arena_index = 3;
      g_context_arena_index = 3;
      return g_token_newline;
    }
    pp_emit_line_directive();
    g_context_arena_index = 3;
    g_expr_arena_index = 3;
    return g_token_newline;
  }
  if (g_opt_EP_no_line == '\0') {
    pp_emit_line_directive();
  }
  if (iVar13 != 2) {
    g_expr_arena_index = 3;
    g_context_arena_index = 3;
    return g_token_newline;
  }
  do {
    uVar19 = 0;
    bVar8 = pp_directive_lookup_name("if");
    iVar12 = g_opt_E_preprocess;
    iVar13 = g_token_arena_index;
    switch(bVar8) {
    case 0:
      goto switchD_10608c16_caseD_10608d89;
    case 1:
      if (g_pp_cond_depth < 0) {
        g_pp_cond_depth = g_pp_cond_depth + -1;
        diag_fatal_simple(0x12);
      }
      g_pp_cond_depth = g_pp_cond_depth + -1;
      iVar13 = (*g_idb->vtbl->idb_conditional_leave)(g_idb);
      if (iVar13 == 0) {
        diag_fatal(0x49,".\\p0prepro.c",0x32e);
      }
      iVar13 = pp_check_expected_endif(5);
      while (iVar13 != 4) {
        iVar13 = pp_check_expected_endif(5);
      }
LAB_10608fe1:
      bVar25 = g_opt_EP_no_line == '\0';
      goto LAB_10608fe8;
    case 2:
      if ((g_pp_cond_depth < 0) ||
         (iVar13 = g_pp_cond_depth + -1, puVar22 = g_pp_cond_states + g_pp_cond_depth,
         g_pp_cond_depth = iVar13, *puVar22 != 1)) {
        diag_fatal_simple(0x13);
      }
      iVar13 = (*g_idb->vtbl->idb_conditional_leave)(g_idb);
      if (iVar13 == 0) {
        diag_fatal(0x49,".\\p0prepro.c",0x34e);
      }
      pp_warn_extra_tokens("#else");
      pp_check_expected_endif(6);
      goto LAB_10608fe1;
    case 3:
      iVar13 = (*g_idb->vtbl->idb_conditional_leave)(g_idb);
      if (iVar13 == 0) {
        diag_fatal(0x49,".\\p0prepro.c",0x360);
      }
      iVar13 = g_pp_cond_depth + -1;
      if (-1 < g_pp_cond_depth) {
        g_pp_cond_depth = iVar13;
        if (g_opt_EP_no_line == '\0') {
          pp_emit_line_directive();
        }
        if (g_ms_extensions != '\0') {
          lex_skip_whitespace();
          g_context_arena_index = 3;
          g_expr_arena_index = 3;
          return g_token_newline;
        }
        pp_warn_extra_tokens("#endif");
        g_context_arena_index = 3;
        g_expr_arena_index = 3;
        return g_token_newline;
      }
      g_pp_cond_depth = iVar13;
      diag_fatal_simple(0x14);
    case 4:
    case 5:
      if ((g_include_depth == 0) && (g_pch_directive_mode != 0)) {
        pp_skip_line_comments();
        iVar13 = pch_record_or_match_directive();
        if (iVar13 == 1) {
          g_expr_arena_index = 3;
          g_context_arena_index = 3;
          return g_token_newline;
        }
        if (g_pch_directive_mode != 2) {
          do {
            bVar9 = *g_input_ptr;
            g_input_ptr = g_input_ptr + 1;
            in_stack_00000018 = CONCAT31(in_stack_00000018._1_3_,bVar9);
          } while (g_char_class[bVar9] == '\x01');
          if ((g_char_flags[bVar9] & 0x20) == 0) {
            bVar9 = lex_skip_comment(bVar9);
          }
          if ((g_char_flags[bVar9] & 1) == 0) {
            diag_fatal_simple(0x10);
          }
          lex_scan_identifier(bVar9);
          bVar25 = g_last_name->macro != (fe_macro *)0x0;
          uVar19 = (ushort)bVar25;
          pcVar21 = "#ifdef";
          if (bVar8 != 4) {
            pcVar21 = "#ifndef";
          }
          pp_warn_extra_tokens(pcVar21);
          if (bVar8 == 5) {
            uVar19 = (ushort)!bVar25;
            if_value_high = 0;
          }
        }
        uVar11 = pch_record_or_replay_if_value((int)(short)uVar19);
      }
      else {
        do {
          bVar9 = *g_input_ptr;
          g_input_ptr = g_input_ptr + 1;
        } while (g_char_class[bVar9] == '\x01');
        include_angle = bVar9;
        if ((g_char_flags[bVar9] & 0x20) == 0) {
          bVar9 = lex_skip_comment(bVar9);
        }
        if ((g_char_flags[bVar9] & 1) == 0) {
          diag_fatal_simple(0x10);
        }
        lex_scan_identifier(bVar9);
        uVar11 = (uint)(g_last_name->macro != (fe_macro *)0x0);
        pcVar21 = "#ifdef";
        if (bVar8 != 4) {
          pcVar21 = "#ifndef";
        }
        pp_warn_extra_tokens(pcVar21);
        if (bVar8 == 5) {
          if (uVar11 == 0) {
            uVar11 = 1;
          }
          else {
            uVar11 = 0;
          }
        }
      }
      if ((uVar11 != 0) || (iVar13 = pp_check_expected_endif(5), iVar13 == 3)) {
        iVar13 = (*g_idb->vtbl->idb_conditional_enter)(g_idb);
        if (iVar13 != 0) {
          uVar10 = pp_cond_stack_push();
          g_pp_cond_states[uVar10] = (-(uint)(uVar11 == 0) & 2) + 1;
          g_context_arena_index = 3;
          g_expr_arena_index = 3;
          return g_token_newline;
        }
        diag_fatal(0x49,".\\p0prepro.c",0x29f);
      }
      if (iVar13 != 2) {
        g_expr_arena_index = 3;
        g_context_arena_index = 3;
        return g_token_newline;
      }
      break;
    case 6:
      pp_define_parse('\x01');
      g_context_arena_index = 3;
      g_expr_arena_index = 3;
      return g_token_newline;
    case 7:
      pbVar15 = (byte *)pp_include_parse_filename('\x01',&include_angle);
      if (pbVar15 == (byte *)0x0) {
        g_expr_arena_index = 3;
        g_context_arena_index = 3;
        return g_token_newline;
      }
      pcVar14 = pp_include_directive_open(pbVar15,include_angle);
      return pcVar14;
    case 8:
      if ((g_include_depth == 0) && (g_pch_directive_mode != 0)) {
        pcVar14 = pp_scan_directive_fragment();
        return pcVar14;
      }
      pcVar14 = pp_pragma_directive();
      return pcVar14;
    case 9:
      do {
        bVar8 = *g_input_ptr;
        g_input_ptr = g_input_ptr + 1;
      } while (g_char_class[bVar8] == '\x01');
      include_angle = bVar8;
      if ((g_char_flags[bVar8] & 0x20) == 0) {
        bVar8 = lex_skip_comment(bVar8);
      }
      if ((g_char_flags[bVar8] & 1) != 0) {
        lex_scan_identifier(bVar8);
        pp_undef_directive();
        pp_warn_extra_tokens("#undef");
        g_context_arena_index = 3;
        g_expr_arena_index = 3;
        return g_token_newline;
      }
      diag_warning(1,6);
      pp_warn_extra_tokens("#undef");
      g_context_arena_index = 3;
      g_expr_arena_index = 3;
      return g_token_newline;
    case 10:
      if ((g_include_depth == 0) && (g_pch_directive_mode != 0)) {
        return &g_token_line_for_pch->code;
      }
      pcVar14 = pp_line_directive();
      return pcVar14;
    case 0xb:
    case 0xf:
      diag_fatal(0x15,"if");
    case 0xc:
      pcVar21 = g_number_digit_buffer;
      goto LAB_1062d332;
    case 0xd:
      g_opt_E_preprocess = 0;
      stream = arena_alloc(g_arenas + g_token_arena_index,0x38);
      iVar4 = g_token_position;
      if (stream == (c1_saved_token_stream *)0x0) {
        stream = (c1_saved_token_stream *)0x0;
      }
      else {
        buffer = &stream->start;
        stream->position = g_token_position;
        stream->position_end = iVar4;
        token_buffer_init(buffer,iVar13);
        stream->arena = iVar13;
        stream->vtbl = (c1_token_stream_vtbl *)&PTR_token_stream_next_raw_1065240c;
        (stream->read).block = buffer->block;
        (stream->read).index = (stream->start).index;
        (stream->read).arena = (stream->start).arena;
        iVar4 = (stream->start).index;
        (stream->write).block = buffer->block;
        iVar5 = (stream->start).arena;
        (stream->write).index = iVar4;
        (stream->write).arena = iVar5;
        stream->flags = stream->flags & 0xfe;
      }
      token_source_push(&g_token_record_position,(int)stream,iVar13,0,0,&g_token_position);
      if (g_token_arena_index == 0) {
        if (g_pool_default.left < 0x20) {
          pool_reserve(&g_pool_default,0x20);
        }
        g_pool_default.left = g_pool_default.left - 0x20;
        pcVar16 = (c1_token *)g_pool_default.cur;
        g_pool_default.cur = g_pool_default.cur + 0x20;
      }
      else {
        pfVar18 = g_arenas + g_token_arena_index;
        pcVar16 = (c1_token *)pfVar18->cur;
        pcVar6 = (c1_token *)g_arenas[g_token_arena_index].end;
        pfVar18->cur = &pcVar16[1].code;
        if (pcVar6 < pcVar16 + 1) {
          arena_grow(pfVar18);
        }
      }
      if (pcVar16 == (c1_token *)0x0) {
        pcVar16 = (c1_token *)0x0;
      }
      else {
        pcVar16->code = ',';
        puVar22 = &g_yylval;
        pcVar23 = &pcVar16->value;
        for (iVar13 = 6; iVar13 != 0; iVar13 = iVar13 + -1) {
          pcVar23->words[0] = *puVar22;
          puVar22 = puVar22 + 1;
          pcVar23 = (c1_yystype *)((int)pcVar23 + 4);
        }
      }
      (*g_token_save_frame->stream->vtbl->append)(g_token_save_frame->stream,pcVar16);
      do {
        pcVar16 = token_next(&g_token_position);
        (*g_token_save_frame->stream->vtbl->append)(g_token_save_frame->stream,pcVar16);
      } while (pcVar16->code != '-');
      pcVar17 = (c1_saved_token_stream *)0x0;
      if (g_token_save_frame != (c1_token_source_frame *)0x0) {
        ppcVar1 = &g_token_save_frame->prev;
        pcVar17 = g_token_save_frame->stream;
        g_token_record_position = g_token_save_frame->position;
        pp_Var2 = &g_token_save_frame->on_pop;
        g_token_save_frame = *ppcVar1;
        if (*pp_Var2 != (_func_240 *)0x0) {
          (**pp_Var2)();
        }
      }
      g_context_arena_index = 3;
      g_expr_arena_index = 3;
      if (iVar12 != 0) {
        g_expr_arena_index = 3;
        g_context_arena_index = 3;
        g_yylval = (uint)pcVar17;
        g_opt_E_preprocess = iVar12;
        return g_token_newline;
      }
      g_yylval = (uint)pcVar17;
      if (g_token_arena_index == 0) {
        g_opt_E_preprocess = iVar12;
        if (g_pool_default.left < 0x20) {
          pool_reserve(&g_pool_default,0x20);
        }
        g_pool_default.left = g_pool_default.left - 0x20;
        pcVar14 = g_pool_default.cur;
        g_pool_default.cur = g_pool_default.cur + 0x20;
      }
      else {
        pfVar18 = g_arenas + g_token_arena_index;
        pcVar14 = pfVar18->cur;
        puVar7 = g_arenas[g_token_arena_index].end;
        g_opt_E_preprocess = iVar12;
        pfVar18->cur = pcVar14 + 0x20;
        if (puVar7 < pcVar14 + 0x20) {
          arena_grow(pfVar18);
        }
      }
      if (pcVar14 != (c1_u8 *)0x0) {
        *pcVar14 = 0xf4;
        puVar22 = &g_yylval;
        puVar24 = (uint *)(pcVar14 + 8);
        for (iVar13 = 6; iVar13 != 0; iVar13 = iVar13 + -1) {
          *puVar24 = *puVar22;
          puVar22 = puVar22 + 1;
          puVar24 = puVar24 + 1;
        }
        return pcVar14;
      }
      return (c1_u8 *)0x0;
    case 0xe:
      diag_error(0x305);
      lex_skip_whitespace();
      g_context_arena_index = 3;
      g_expr_arena_index = 3;
      return g_token_newline;
    default:
      g_expr_arena_index = 3;
      g_context_arena_index = 3;
      return g_token_newline;
    }
  } while( true );
LAB_1062d332:
  do {
    bVar8 = *g_input_ptr;
    pbVar15 = g_input_ptr + 1;
    cVar3 = g_char_class[bVar8];
    if (cVar3 == '\0') break;
    if (cVar3 == '\x05') {
      *pcVar21 = 0;
      diag_fatal(0xbd,g_number_digit_buffer);
    }
    g_input_ptr = pbVar15;
    if (cVar3 != '#') goto LAB_1062d378;
    *pcVar21 = bVar8;
    lex_skip_mbcs_trail_byte();
    pcVar21[1] = bVar8;
    pcVar21 = pcVar21 + 2;
  } while( true );
  g_input_ptr = pbVar15;
  uVar11 = lex_buffer_refill();
  if ((uVar11 & 0xffffffaf) == 0) {
LAB_1062d378:
    *pcVar21 = bVar8;
    pcVar21 = pcVar21 + 1;
  }
  goto LAB_1062d332;
switchD_10608c16_caseD_10608d89:
  if ((g_include_depth == 0) && (g_pch_directive_mode != 0)) {
    pcVar14 = pp_directive(0,2,include_angle,if_value_high);
    return pcVar14;
  }
  g_compile_flags_c4 = g_compile_flags_c4 | 0x4000;
  g_opt_E_preprocess = 0;
  lVar26 = pp_if_evaluate_expression();
  g_compile_flags_c4 = g_compile_flags_c4 & 0xffffbfff;
  g_opt_E_preprocess = iVar12;
  pp_warn_extra_tokens("#if/#elif");
  goto LAB_10608de3;
}

