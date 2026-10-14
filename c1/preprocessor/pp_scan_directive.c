c1_u8 * __cdecl pp_scan_directive(void)

{
  c1_token_cursor *buffer;
  c1_token_source_frame **ppcVar1;
  _func_240 **pp_Var2;
  c1_u8 cVar3;
  int iVar4;
  int iVar5;
  c1_token *pcVar6;
  uchar *puVar7;
  int iVar8;
  byte bVar9;
  byte bVar10;
  uint uVar11;
  c1_u8 *pcVar12;
  byte *pbVar13;
  uint uVar14;
  c1_saved_token_stream *stream;
  c1_token *pcVar15;
  c1_saved_token_stream *pcVar16;
  fe_arena *pfVar17;
  int iVar18;
  char *pcVar19;
  uint *puVar20;
  c1_yystype *pcVar21;
  uint *puVar22;
  bool bVar23;
  longlong lVar24;
  byte in_stack_fffffff4;
  uint local_8;
  int in_stack_fffffffc;
  
  pcVar19 = g_last_name->text;
  bVar9 = *g_input_ptr;
  uVar14 = (uint)bVar9;
  bVar10 = g_char_flags[uVar14];
  while (g_input_ptr = g_input_ptr + 1, (bVar10 & 1) == 0) {
    switch(g_char_class[uVar14]) {
    case '\0':
      uVar14 = lex_buffer_refill();
      uVar14 = uVar14 & 0xffffffaf;
      break;
    case '\x01':
      goto switchD_10608c71_caseD_1;
    default:
      diag_error(0x13,(uint)bVar9);
      lex_skip_whitespace();
      return g_token_newline;
    case '\x03':
      if ((g_ms_extensions == '\0') && (g_pch_option_block == 0)) {
        uVar14 = lex_skip_comment_in_directive();
      }
      else {
        bVar9 = lex_get_char();
        if (bVar9 == 0x2f) {
          g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
          pp_output_copy_comment();
        }
        else {
          g_input_ptr = g_input_ptr + -1;
          bVar9 = lex_get_char();
          if (bVar9 != 0x2a) {
            g_input_ptr = g_input_ptr + -1;
            uVar14 = 0;
            break;
          }
          g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
          pp_block_comment_dispatch();
        }
        g_compile_flags_c4 = g_compile_flags_c4 & 0xfffff7ff;
        uVar14 = 1;
      }
      break;
    case '\x05':
      g_input_ptr = g_input_ptr + -1;
      return g_token_newline;
    }
    if (uVar14 == 0) goto LAB_10608bdd;
switchD_10608c71_caseD_1:
    bVar9 = *g_input_ptr;
    uVar14 = (uint)bVar9;
    bVar10 = g_char_flags[uVar14];
  }
  lex_scan_identifier(bVar9);
  pcVar19 = g_last_name->text;
LAB_10608bdd:
  g_context_arena_index = 3;
  g_expr_arena_index = 3;
  bVar9 = pp_directive_lookup_name(pcVar19);
  iVar18 = g_token_arena_index;
  iVar8 = g_opt_E_preprocess;
  do {
    if (0xf < bVar9) {
      g_expr_arena_index = 3;
      g_context_arena_index = 3;
      g_token_arena_index = iVar18;
      g_opt_E_preprocess = iVar8;
      return g_token_newline;
    }
    g_token_arena_index = iVar18;
    g_opt_E_preprocess = iVar8;
    switch((&switchD_10608c16::switchdataD_106091b4)[bVar9]) {
    case (undefined *)0x10608c78:
      if ((g_include_depth == 0) && (g_pch_directive_mode != 0)) {
        pp_skip_line_comments();
        iVar18 = pch_record_or_match_directive();
        if (iVar18 == 1) {
          g_expr_arena_index = 3;
          g_context_arena_index = 3;
          return g_token_newline;
        }
        if (g_pch_directive_mode != 2) {
          do {
            bVar10 = *g_input_ptr;
            g_input_ptr = g_input_ptr + 1;
          } while (g_char_class[bVar10] == '\x01');
          if ((g_char_flags[bVar10] & 0x20) == 0) {
            bVar10 = lex_skip_comment(bVar10);
          }
          if ((g_char_flags[bVar10] & 1) == 0) {
            diag_fatal_simple(0x10);
          }
          lex_scan_identifier(bVar10);
          local_8 = (uint)(g_last_name->macro != (fe_macro *)0x0);
          pcVar19 = "#ifdef";
          if (bVar9 != 4) {
            pcVar19 = "#ifndef";
          }
          pp_warn_extra_tokens(pcVar19);
          if (bVar9 == 5) {
            local_8 = (uint)(local_8 == 0);
            in_stack_fffffffc = 0;
          }
        }
        uVar14 = pch_record_or_replay_if_value((int)(short)local_8);
      }
      else {
        do {
          in_stack_fffffff4 = *g_input_ptr;
          g_input_ptr = g_input_ptr + 1;
        } while (g_char_class[in_stack_fffffff4] == '\x01');
        bVar10 = in_stack_fffffff4;
        if ((g_char_flags[in_stack_fffffff4] & 0x20) == 0) {
          bVar10 = lex_skip_comment(in_stack_fffffff4);
        }
        if ((g_char_flags[bVar10] & 1) == 0) {
          diag_fatal_simple(0x10);
        }
        lex_scan_identifier(bVar10);
        uVar14 = (uint)(g_last_name->macro != (fe_macro *)0x0);
        pcVar19 = "#ifdef";
        if (bVar9 != 4) {
          pcVar19 = "#ifndef";
        }
        pp_warn_extra_tokens(pcVar19);
        if (bVar9 == 5) {
          if (uVar14 == 0) {
            uVar14 = 1;
          }
          else {
            uVar14 = 0;
          }
        }
      }
      if ((uVar14 != 0) || (iVar18 = pp_check_expected_endif(5), iVar18 == 3)) {
        iVar18 = (*g_idb->vtbl->idb_conditional_enter)(g_idb);
        if (iVar18 != 0) {
          uVar11 = pp_cond_stack_push();
          g_pp_cond_states[uVar11] = (-(uint)(uVar14 == 0) & 2) + 1;
          g_context_arena_index = 3;
          g_expr_arena_index = 3;
          return g_token_newline;
        }
        diag_fatal(0x49,".\\p0prepro.c",0x29f);
      }
      break;
    case (undefined *)0x10608d89:
      if ((g_include_depth == 0) && (g_pch_directive_mode != 0)) {
        pcVar12 = pp_directive(local_8,2,in_stack_fffffff4,in_stack_fffffffc);
        return pcVar12;
      }
      g_compile_flags_c4 = g_compile_flags_c4 | 0x4000;
      g_opt_E_preprocess = 0;
      lVar24 = pp_if_evaluate_expression();
      g_compile_flags_c4 = g_compile_flags_c4 & 0xffffbfff;
      g_opt_E_preprocess = iVar8;
      pp_warn_extra_tokens("#if/#elif");
      if ((lVar24 != 0) || (iVar18 = pp_check_expected_endif(5), iVar18 == 3)) {
        iVar18 = (*g_idb->vtbl->idb_conditional_enter)(g_idb);
        if (iVar18 == 0) {
          diag_fatal(0x49,".\\p0prepro.c",0x2f9);
        }
        uVar14 = pp_cond_stack_push();
        g_pp_cond_states[uVar14] = (-(uint)(lVar24 == 0) & 2) + 1;
        if (g_opt_EP_no_line != '\0') {
          g_expr_arena_index = 3;
          g_context_arena_index = 3;
          return g_token_newline;
        }
        bVar23 = lVar24 == 0;
        goto LAB_10608fe8;
      }
      if (g_opt_EP_no_line == '\0') {
        pp_emit_line_directive();
      }
      break;
    case (undefined *)0x10608e5e:
      pp_define_parse('\x01');
      g_context_arena_index = 3;
      g_expr_arena_index = 3;
      return g_token_newline;
    case (undefined *)0x10608e84:
      pbVar13 = (byte *)pp_include_parse_filename('\x01',&stack0xfffffff4);
      if (pbVar13 == (byte *)0x0) {
        g_expr_arena_index = 3;
        g_context_arena_index = 3;
        return g_token_newline;
      }
      pcVar12 = pp_include_directive_open(pbVar13,in_stack_fffffff4);
      return pcVar12;
    case (undefined *)0x10608f4c:
      if (g_pp_cond_depth < 0) {
        g_pp_cond_depth = g_pp_cond_depth + -1;
        diag_fatal_simple(0x12);
      }
      g_pp_cond_depth = g_pp_cond_depth + -1;
      iVar18 = (*g_idb->vtbl->idb_conditional_leave)(g_idb);
      if (iVar18 == 0) {
        diag_fatal(0x49,".\\p0prepro.c",0x32e);
      }
      iVar18 = pp_check_expected_endif(5);
      while (iVar18 != 4) {
        iVar18 = pp_check_expected_endif(5);
      }
LAB_10608fe1:
      bVar23 = g_opt_EP_no_line == '\0';
LAB_10608fe8:
      if (!bVar23) {
        g_expr_arena_index = 3;
        g_context_arena_index = 3;
        return g_token_newline;
      }
      pp_emit_line_directive();
      g_context_arena_index = 3;
      g_expr_arena_index = 3;
      return g_token_newline;
    case (undefined *)0x10608f94:
      if ((g_pp_cond_depth < 0) ||
         (iVar18 = g_pp_cond_depth + -1, puVar20 = g_pp_cond_states + g_pp_cond_depth,
         g_pp_cond_depth = iVar18, *puVar20 != 1)) {
        diag_fatal_simple(0x13);
      }
      iVar18 = (*g_idb->vtbl->idb_conditional_leave)(g_idb);
      if (iVar18 == 0) {
        diag_fatal(0x49,".\\p0prepro.c",0x34e);
      }
      pp_warn_extra_tokens("#else");
      pp_check_expected_endif(6);
      goto LAB_10608fe1;
    case (undefined *)0x10608ff3:
      iVar18 = (*g_idb->vtbl->idb_conditional_leave)(g_idb);
      if (iVar18 == 0) {
        diag_fatal(0x49,".\\p0prepro.c",0x360);
      }
      iVar18 = g_pp_cond_depth + -1;
      if (-1 < g_pp_cond_depth) {
        g_pp_cond_depth = iVar18;
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
      g_pp_cond_depth = iVar18;
      diag_fatal_simple(0x14);
    case (undefined *)0x10609059:
      if ((g_include_depth == 0) && (g_pch_directive_mode != 0)) {
        pcVar12 = pp_scan_directive_fragment();
        return pcVar12;
      }
      pcVar12 = pp_pragma_directive();
      return pcVar12;
    case (undefined *)0x1060907d:
      do {
        bVar9 = *g_input_ptr;
        g_input_ptr = g_input_ptr + 1;
      } while (g_char_class[bVar9] == '\x01');
      if ((g_char_flags[bVar9] & 0x20) == 0) {
        bVar9 = lex_skip_comment(bVar9);
      }
      if ((g_char_flags[bVar9] & 1) != 0) {
        lex_scan_identifier(bVar9);
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
    case (undefined *)0x1062d179:
      if ((g_include_depth == 0) && (g_pch_directive_mode != 0)) {
        return &g_token_line_for_pch->code;
      }
      pcVar12 = pp_line_directive();
      return pcVar12;
    case (undefined *)0x1062d1a5:
      diag_error(0x305);
      lex_skip_whitespace();
      g_context_arena_index = 3;
      g_expr_arena_index = 3;
      return g_token_newline;
    case (undefined *)0x1062d32d:
      pcVar19 = g_number_digit_buffer;
      goto LAB_1062d332;
    case (undefined *)0x1062d3c5:
      g_opt_E_preprocess = 0;
      stream = arena_alloc(g_arenas + iVar18,0x38);
      iVar4 = g_token_position;
      if (stream == (c1_saved_token_stream *)0x0) {
        stream = (c1_saved_token_stream *)0x0;
      }
      else {
        buffer = &stream->start;
        stream->position = g_token_position;
        stream->position_end = iVar4;
        token_buffer_init(buffer,iVar18);
        stream->arena = iVar18;
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
      token_source_push(&g_token_record_position,(int)stream,iVar18,0,0,&g_token_position);
      if (g_token_arena_index == 0) {
        if (g_pool_default.left < 0x20) {
          pool_reserve(&g_pool_default,0x20);
        }
        g_pool_default.left = g_pool_default.left - 0x20;
        pcVar15 = (c1_token *)g_pool_default.cur;
        g_pool_default.cur = g_pool_default.cur + 0x20;
      }
      else {
        pfVar17 = g_arenas + g_token_arena_index;
        pcVar15 = (c1_token *)pfVar17->cur;
        pcVar6 = (c1_token *)g_arenas[g_token_arena_index].end;
        pfVar17->cur = &pcVar15[1].code;
        if (pcVar6 < pcVar15 + 1) {
          arena_grow(pfVar17);
        }
      }
      if (pcVar15 == (c1_token *)0x0) {
        pcVar15 = (c1_token *)0x0;
      }
      else {
        pcVar15->code = ',';
        puVar20 = &g_yylval;
        pcVar21 = &pcVar15->value;
        for (iVar18 = 6; iVar18 != 0; iVar18 = iVar18 + -1) {
          pcVar21->words[0] = *puVar20;
          puVar20 = puVar20 + 1;
          pcVar21 = (c1_yystype *)((int)pcVar21 + 4);
        }
      }
      (*g_token_save_frame->stream->vtbl->append)(g_token_save_frame->stream,pcVar15);
      do {
        pcVar15 = token_next(&g_token_position);
        (*g_token_save_frame->stream->vtbl->append)(g_token_save_frame->stream,pcVar15);
      } while (pcVar15->code != '-');
      pcVar16 = (c1_saved_token_stream *)0x0;
      if (g_token_save_frame != (c1_token_source_frame *)0x0) {
        ppcVar1 = &g_token_save_frame->prev;
        pcVar16 = g_token_save_frame->stream;
        g_token_record_position = g_token_save_frame->position;
        pp_Var2 = &g_token_save_frame->on_pop;
        g_token_save_frame = *ppcVar1;
        if (*pp_Var2 != (_func_240 *)0x0) {
          (**pp_Var2)();
        }
      }
      g_context_arena_index = 3;
      g_expr_arena_index = 3;
      if (iVar8 != 0) {
        g_opt_E_preprocess = iVar8;
        g_yylval = (uint)pcVar16;
        g_context_arena_index = 3;
        g_expr_arena_index = 3;
        return g_token_newline;
      }
      g_yylval = (uint)pcVar16;
      if (g_token_arena_index == 0) {
        g_opt_E_preprocess = iVar8;
        if (g_pool_default.left < 0x20) {
          pool_reserve(&g_pool_default,0x20);
        }
        g_pool_default.left = g_pool_default.left - 0x20;
        pcVar12 = g_pool_default.cur;
        g_pool_default.cur = g_pool_default.cur + 0x20;
      }
      else {
        pfVar17 = g_arenas + g_token_arena_index;
        pcVar12 = pfVar17->cur;
        puVar7 = g_arenas[g_token_arena_index].end;
        g_opt_E_preprocess = iVar8;
        pfVar17->cur = pcVar12 + 0x20;
        if (puVar7 < pcVar12 + 0x20) {
          arena_grow(pfVar17);
        }
      }
      if (pcVar12 != (c1_u8 *)0x0) {
        *pcVar12 = 0xf4;
        puVar20 = &g_yylval;
        puVar22 = (uint *)(pcVar12 + 8);
        for (iVar18 = 6; iVar18 != 0; iVar18 = iVar18 + -1) {
          *puVar22 = *puVar20;
          puVar20 = puVar20 + 1;
          puVar22 = puVar22 + 1;
        }
        return pcVar12;
      }
      return (c1_u8 *)0x0;
    case (undefined *)0x1062d5ee:
      diag_fatal(0x15,pcVar19);
    }
    if (iVar18 != 2) {
      g_expr_arena_index = 3;
      g_context_arena_index = 3;
      return g_token_newline;
    }
    local_8 = 0;
    pcVar19 = "if";
    bVar9 = pp_directive_lookup_name("if");
    iVar18 = g_token_arena_index;
    iVar8 = g_opt_E_preprocess;
  } while( true );
LAB_1062d332:
  do {
    bVar9 = *g_input_ptr;
    pbVar13 = g_input_ptr + 1;
    cVar3 = g_char_class[bVar9];
    if (cVar3 == '\0') break;
    if (cVar3 == '\x05') {
      *pcVar19 = 0;
      diag_fatal(0xbd,g_number_digit_buffer);
    }
    g_input_ptr = pbVar13;
    if (cVar3 != '#') goto LAB_1062d378;
    *pcVar19 = bVar9;
    lex_skip_mbcs_trail_byte();
    pcVar19[1] = bVar9;
    pcVar19 = pcVar19 + 2;
  } while( true );
  g_input_ptr = pbVar13;
  uVar14 = lex_buffer_refill();
  if ((uVar14 & 0xffffffaf) == 0) {
LAB_1062d378:
    *pcVar19 = bVar9;
    pcVar19 = pcVar19 + 1;
  }
  goto LAB_1062d332;
}

