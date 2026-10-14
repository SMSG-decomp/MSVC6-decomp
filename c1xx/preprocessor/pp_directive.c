c1_u8 * __cdecl pp_directive(void)

{
  c1xx_token_cursor *cursor;
  c1_token_source_frame **ppcVar1;
  _func_193 **pp_Var2;
  c1_u8 cVar3;
  c1_u8 *pcVar4;
  char *pcVar5;
  byte bVar6;
  byte bVar7;
  char cVar8;
  char *pcVar9;
  uint uVar10;
  int iVar11;
  c1_u8 *pcVar12;
  uint uVar13;
  uint *line_stream;
  byte *pbVar14;
  uint *line_stream_2;
  c1_arena *pcVar15;
  int iVar16;
  ushort uVar17;
  int cond_lo;
  uint *line_buf_2;
  uint *line_buf;
  uint *puVar18;
  bool bVar19;
  longlong lVar20;
  byte local_19;
  char *local_18;
  byte *local_14;
  c1_vector *local_10;
  int local_c;
  int cond_lo_default;
  uint cond_hi;
  
  pcVar9 = g_last_name->text;
  local_18 = (char *)CONCAT31(local_18._1_3_,*g_input_ptr);
  uVar13 = (uint)*g_input_ptr;
  bVar6 = g_char_flags[uVar13];
  pbVar14 = g_input_ptr;
  while (g_input_ptr = pbVar14 + 1, (bVar6 & 1) == 0) {
    switch(g_char_class[uVar13]) {
    case '\0':
      uVar13 = lex_buffer_refill();
      if ((uVar13 & 0xffffffaf) == 0) {
LAB_1046179e:
        if (((((g_compile_flags_c8 & 0x32000000) != 0) ||
             ((((g_compile_flags_c8 & 0x40000000) != 0 && (((byte)g_compile_flags_cc & 8) == 0)) &&
              ((g_compile_flags_c4 & 0x200) == 0)))) || (((byte)g_compile_flags_cc & 0x10) != 0)) ||
           (((g_compile_flags_c8 & 0x4000000) != 0 && ((g_compile_flags_c4 & 0x8000) == 0))))
        goto LAB_10461810;
        g_context_arena_index = 5;
        g_expr_arena_index = 5;
        if (((byte)g_compile_flags_cc & 1) != 0) {
          g_context_arena_index = 4;
          g_expr_arena_index = 4;
        }
        goto LAB_1040e979;
      }
      break;
    case '\x01':
      break;
    default:
      diag_error(0x13,(uint)local_18 & 0xff);
      lex_skip_whitespace();
      return g_token_newline;
    case '\x03':
      bVar6 = lex_get_char();
      if (bVar6 == 0x2f) {
        g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
        pp_output_copy_comment();
      }
      else {
        g_input_ptr = g_input_ptr + -1;
        bVar6 = lex_get_char();
        if (bVar6 != 0x2a) {
          g_input_ptr = g_input_ptr + -1;
          goto LAB_1046179e;
        }
        g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
        pp_block_comment_dispatch();
      }
      g_compile_flags_c4 = g_compile_flags_c4 & 0xfffff7ff;
      break;
    case '\x05':
      g_input_ptr = pbVar14;
      return g_token_newline;
    }
    local_18 = (char *)CONCAT31(local_18._1_3_,*g_input_ptr);
    uVar13 = (uint)*g_input_ptr;
    pbVar14 = g_input_ptr;
    bVar6 = g_char_flags[uVar13];
  }
  lex_scan_identifier((byte)local_18);
  pcVar9 = g_last_name->text;
  if ((((g_compile_flags_c8 & 0x32000000) == 0) &&
      ((((g_compile_flags_c8 & 0x40000000) == 0 || (((byte)g_compile_flags_cc & 8) != 0)) ||
       ((g_compile_flags_c4 & 0x200) != 0)))) &&
     ((((byte)g_compile_flags_cc & 0x10) == 0 &&
      (((g_compile_flags_c8 & 0x4000000) == 0 || ((g_compile_flags_c4 & 0x8000) != 0)))))) {
    g_context_arena_index = 5;
    g_expr_arena_index = 5;
    if (((byte)g_compile_flags_cc & 1) != 0) {
      g_context_arena_index = 4;
      g_expr_arena_index = 4;
    }
  }
  else {
LAB_10461810:
    g_context_arena_index = 0;
    g_expr_arena_index = 0;
  }
LAB_1040e979:
  bVar6 = pp_directive_lookup_name(pcVar9);
  local_14 = (byte *)CONCAT31(local_14._1_3_,bVar6);
  uVar13 = g_token_arena_index;
  iVar16 = g_opt_E_preprocess;
  pcVar5 = local_18;
joined_r0x1040e994:
  g_token_arena_index = uVar13;
  g_opt_E_preprocess = iVar16;
  if (bVar6 < 0x10) {
    uVar17 = (ushort)cond_lo_default;
    local_18._1_3_ = (undefined3)((uint)pcVar5 >> 8);
    local_18 = pcVar5;
    switch(bVar6) {
    case 0:
      if ((g_include_depth == 0) && (g_pch_directive_mode != 0)) {
        pp_capture_directive_text();
        iVar11 = pch_record_or_match_directive();
        iVar16 = g_opt_E_preprocess;
        if (iVar11 == 1) break;
        if (g_pch_directive_mode != 2) {
          g_compile_flags_c4 = g_compile_flags_c4 | 0x4000;
          g_opt_E_preprocess = 0;
          lVar20 = pp_if_evaluate_expression();
          cond_hi = (uint)((ulonglong)lVar20 >> 0x20);
          g_compile_flags_c4 = g_compile_flags_c4 & 0xffffbfff;
          uVar17 = (ushort)lVar20;
          g_opt_E_preprocess = iVar16;
          pp_warn_extra_tokens("#if/#elif");
        }
        iVar16 = pch_record_or_replay_if_value((int)(short)uVar17);
        lVar20 = (longlong)iVar16;
      }
      else {
        g_compile_flags_c4 = g_compile_flags_c4 | 0x4000;
        g_opt_E_preprocess = 0;
        lVar20 = pp_if_evaluate_expression();
        g_compile_flags_c4 = g_compile_flags_c4 & 0xffffbfff;
        g_opt_E_preprocess = iVar16;
        pp_warn_extra_tokens("#if/#elif");
      }
      if ((lVar20 == 0) && (iVar16 = pp_check_expected_endif(5), iVar16 != 3)) {
        if (g_opt_EP_no_line == '\0') {
          pp_emit_line_directive();
        }
        goto joined_r0x1040eb0d;
      }
      iVar16 = (*g_idb->vtbl->idb_conditional_enter)(g_idb);
      if (iVar16 == 0) {
        diag_fatal(0x49,".\\p0prepro.c",0x2f9);
      }
      uVar13 = pp_cond_stack_push();
      g_pp_cond_states[uVar13] = (-(uint)(lVar20 == 0) & 2) + 1;
      if (g_opt_EP_no_line == '\0') {
        bVar19 = lVar20 == 0;
        goto LAB_1040ed48;
      }
      break;
    case 1:
      if (g_pp_cond_depth < 0) {
        g_pp_cond_depth = g_pp_cond_depth + -1;
        diag_fatal_simple(0x12);
      }
      g_pp_cond_depth = g_pp_cond_depth + -1;
      iVar16 = (*g_idb->vtbl->idb_conditional_leave)(g_idb);
      if (iVar16 == 0) {
        diag_fatal(0x49,".\\p0prepro.c",0x32e);
      }
      iVar16 = pp_check_expected_endif(5);
      while (iVar16 != 4) {
        iVar16 = pp_check_expected_endif(5);
      }
LAB_1040ed41:
      bVar19 = g_opt_EP_no_line == '\0';
LAB_1040ed48:
      if (bVar19) {
        pp_emit_line_directive();
      }
      break;
    case 2:
      if ((g_pp_cond_depth < 0) ||
         (iVar16 = g_pp_cond_depth + -1, puVar18 = g_pp_cond_states + g_pp_cond_depth,
         g_pp_cond_depth = iVar16, *puVar18 != 1)) {
        diag_fatal_simple(0x13);
      }
      iVar16 = (*g_idb->vtbl->idb_conditional_leave)(g_idb);
      if (iVar16 == 0) {
        diag_fatal(0x49,".\\p0prepro.c",0x34e);
      }
      pp_warn_extra_tokens("#else");
      pp_check_expected_endif(6);
      goto LAB_1040ed41;
    case 3:
      iVar16 = (*g_idb->vtbl->idb_conditional_leave)(g_idb);
      if (iVar16 == 0) {
        diag_fatal(0x49,".\\p0prepro.c",0x360);
      }
      iVar16 = g_pp_cond_depth + -1;
      if (g_pp_cond_depth < 0) {
        g_pp_cond_depth = iVar16;
        diag_fatal_simple(0x14);
      }
      g_pp_cond_depth = iVar16;
      if (g_opt_EP_no_line == '\0') {
        pp_emit_line_directive();
      }
      if (g_ms_extensions == '\0') {
        pp_warn_extra_tokens("#endif");
      }
      else {
        lex_skip_whitespace();
      }
      break;
    default:
      if ((g_include_depth == 0) && (g_pch_directive_mode != 0)) {
        pp_capture_directive_text();
        iVar16 = pch_record_or_match_directive();
        if (iVar16 == 1) break;
        if (g_pch_directive_mode != 2) {
          do {
            bVar7 = *g_input_ptr;
            g_input_ptr = g_input_ptr + 1;
            local_10 = (c1_vector *)CONCAT31(local_10._1_3_,bVar7);
          } while (g_char_class[bVar7] == '\x01');
          if ((g_char_flags[bVar7] & 0x20) == 0) {
            bVar7 = lex_skip_comment(bVar7);
            local_18 = (char *)CONCAT31(local_18._1_3_,bVar7);
          }
          else {
            local_18 = (char *)CONCAT31(local_18._1_3_,bVar7);
          }
          if ((g_char_flags[(uint)local_18 & 0xff] & 1) == 0) {
            diag_fatal_simple(0x10);
          }
          lex_scan_identifier((byte)local_18);
          bVar19 = g_last_name->macro != (fe_macro *)0x0;
          uVar17 = (ushort)bVar19;
          pcVar9 = "#ifdef";
          if (bVar6 != 4) {
            pcVar9 = "#ifndef";
          }
          pp_warn_extra_tokens(pcVar9);
          if (bVar6 == 5) {
            cond_hi = 0;
            uVar17 = (ushort)!bVar19;
          }
        }
        uVar13 = pch_record_or_replay_if_value((int)(short)uVar17);
      }
      else {
        do {
          bVar7 = *g_input_ptr;
          g_input_ptr = g_input_ptr + 1;
          local_c = CONCAT31(local_c._1_3_,bVar7);
        } while (g_char_class[bVar7] == '\x01');
        if ((g_char_flags[bVar7] & 0x20) == 0) {
          bVar7 = lex_skip_comment(bVar7);
          local_18 = (char *)CONCAT31(local_18._1_3_,bVar7);
        }
        else {
          local_18 = (char *)CONCAT31(local_18._1_3_,bVar7);
        }
        if ((g_char_flags[(uint)local_18 & 0xff] & 1) == 0) {
          diag_fatal_simple(0x10);
        }
        lex_scan_identifier((byte)local_18);
        uVar13 = (uint)(g_last_name->macro != (fe_macro *)0x0);
        pcVar9 = "#ifdef";
        if (bVar6 != 4) {
          pcVar9 = "#ifndef";
        }
        pp_warn_extra_tokens(pcVar9);
        if (bVar6 == 5) {
          if (uVar13 == 0) {
            uVar13 = 1;
          }
          else {
            uVar13 = 0;
          }
        }
      }
      if ((uVar13 == 0) && (iVar16 = pp_check_expected_endif(5), iVar16 != 3)) {
joined_r0x1040eb0d:
        if (iVar16 == 2) goto LAB_1040eb13;
      }
      else {
        iVar16 = (*g_idb->vtbl->idb_conditional_enter)(g_idb);
        if (iVar16 == 0) {
          diag_fatal(0x49,".\\p0prepro.c",0x29f);
        }
        uVar10 = pp_cond_stack_push();
        g_pp_cond_states[uVar10] = (-(uint)(uVar13 == 0) & 2) + 1;
      }
      break;
    case 6:
      pp_define_parse(1);
      break;
    case 7:
      pbVar14 = (byte *)pp_include_parse_filename('\x01',(char *)&local_c);
      if (pbVar14 != (byte *)0x0) {
        pcVar12 = pp_include_open_and_push(pbVar14,(char)local_c);
        return pcVar12;
      }
      break;
    case 8:
      if ((g_include_depth == 0) && (g_pch_directive_mode != 0)) {
        pcVar12 = (c1_u8 *)pp_pragma_directive_pch();
        return pcVar12;
      }
      pcVar12 = pp_pragma_directive();
      return pcVar12;
    case 9:
      do {
        bVar6 = *g_input_ptr;
        g_input_ptr = g_input_ptr + 1;
        local_c = CONCAT31(local_c._1_3_,bVar6);
      } while (g_char_class[bVar6] == '\x01');
      if ((g_char_flags[bVar6] & 0x20) == 0) {
        bVar6 = lex_skip_comment(bVar6);
        local_18 = (char *)CONCAT31(local_18._1_3_,bVar6);
      }
      else {
        local_18 = (char *)CONCAT31(local_18._1_3_,bVar6);
      }
      if ((g_char_flags[(uint)local_18 & 0xff] & 1) == 0) {
        diag_warning(1,6);
        pp_warn_extra_tokens("#undef");
      }
      else {
        lex_scan_identifier((byte)local_18);
        pp_undef_directive();
        pp_warn_extra_tokens("#undef");
      }
      break;
    case 10:
      if ((g_include_depth == 0) && (g_pch_directive_mode != 0)) {
        return g_token_line_directive_for_pch;
      }
      pcVar12 = pp_line_directive();
      return pcVar12;
    case 0xb:
    case 0xf:
      diag_fatal(0x15,pcVar9);
    case 0xc:
      pcVar12 = g_number_digit_buffer;
      goto LAB_10461bab;
    case 0xd:
      g_opt_E_preprocess = 0;
      local_c = iVar16;
      line_stream = arena_alloc(g_arenas + uVar13,0x38);
      iVar16 = g_token_position;
      if (line_stream == (uint *)0x0) {
        line_stream = (uint *)0x0;
      }
      else {
        cursor = (c1xx_token_cursor *)(line_stream + 3);
        line_stream[1] = g_token_position;
        line_stream[2] = iVar16;
        token_buffer_init(cursor,uVar13);
        line_stream[0xc] = uVar13;
        *line_stream = (uint)&PTR_token_stream_next_raw_104bc55c;
        line_stream[6] = (uint)cursor->chunk;
        line_stream[7] = line_stream[4];
        line_stream[8] = line_stream[5];
        line_stream[9] = (uint)cursor->chunk;
        line_stream[10] = line_stream[4];
        line_stream[0xb] = line_stream[5];
        *(byte *)(line_stream + 0xd) = (byte)line_stream[0xd] & 0xfe;
      }
      token_source_push((c1_token_reader *)&g_token_record_position,(c1xx_token_stream *)line_stream
                        ,uVar13,0,(void *)0x0,&g_token_position);
      if (g_token_arena_index == 0) {
        if (g_pool_default_left < 0x30) {
          pool_reserve((c1xx_pool *)&g_pool_default,0x30);
        }
        g_pool_default_left = g_pool_default_left - 0x30;
        pcVar12 = g_pool_default;
        g_pool_default = g_pool_default + 0x30;
      }
      else {
        pcVar15 = g_arenas + g_token_arena_index;
        pcVar12 = pcVar15->cur;
        pcVar4 = g_arenas[g_token_arena_index].end;
        pcVar15->cur = pcVar12 + 0x30;
        if (pcVar4 < pcVar12 + 0x30) {
          arena_grow(pcVar15);
        }
      }
      if (pcVar12 == (c1_u8 *)0x0) {
        pcVar12 = (c1_u8 *)0x0;
      }
      else {
        *pcVar12 = ',';
        line_buf_2 = &g_yylval;
        puVar18 = (uint *)(pcVar12 + 8);
        for (iVar16 = 10; iVar16 != 0; iVar16 = iVar16 + -1) {
          *puVar18 = *line_buf_2;
          line_buf_2 = line_buf_2 + 1;
          puVar18 = puVar18 + 1;
        }
      }
      (*g_token_save_frame->stream->vtbl->append)(g_token_save_frame->stream,(int)pcVar12);
      do {
        pbVar14 = token_next((c1_token_reader *)&g_token_position);
        (*g_token_save_frame->stream->vtbl->append)(g_token_save_frame->stream,(int)pbVar14);
      } while (*pbVar14 != 0x2d);
      if (g_token_save_frame == (c1_token_source_frame *)0x0) {
        line_stream_2 = (uint *)0x0;
      }
      else {
        ppcVar1 = &g_token_save_frame->prev;
        line_stream_2 = (uint *)g_token_save_frame->stream;
        g_token_record_position = g_token_save_frame->position;
        pp_Var2 = &g_token_save_frame->on_pop;
        g_token_save_frame = *ppcVar1;
        if (*pp_Var2 != (_func_193 *)0x0) {
          (**pp_Var2)();
        }
      }
      if ((((g_compile_flags_c8 & 0x32000000) == 0) &&
          (((((g_compile_flags_c8 & 0x40000000) == 0 || (((byte)g_compile_flags_cc & 8) != 0)) ||
            ((g_compile_flags_c4 & 0x200) != 0)) && (((byte)g_compile_flags_cc & 0x10) == 0)))) &&
         (((g_compile_flags_c8 & 0x4000000) == 0 || ((g_compile_flags_c4 & 0x8000) != 0)))) {
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
      g_opt_E_preprocess = local_c;
      g_yylval = (uint)line_stream_2;
      if (local_c == 0) {
        if (g_token_arena_index == 0) {
          if (g_pool_default_left < 0x30) {
            pool_reserve((c1xx_pool *)&g_pool_default,0x30);
          }
          g_pool_default_left = g_pool_default_left - 0x30;
          pcVar12 = g_pool_default;
          g_pool_default = g_pool_default + 0x30;
        }
        else {
          pcVar15 = g_arenas + g_token_arena_index;
          pcVar12 = pcVar15->cur;
          pcVar4 = g_arenas[g_token_arena_index].end;
          pcVar15->cur = pcVar12 + 0x30;
          if (pcVar4 < pcVar12 + 0x30) {
            arena_grow(pcVar15);
          }
        }
        if (pcVar12 != (c1_u8 *)0x0) {
          *pcVar12 = 0xf4;
          line_buf = &g_yylval;
          puVar18 = (uint *)(pcVar12 + 8);
          for (iVar16 = 10; iVar16 != 0; iVar16 = iVar16 + -1) {
            *puVar18 = *line_buf;
            line_buf = line_buf + 1;
            puVar18 = puVar18 + 1;
          }
          return pcVar12;
        }
        return (c1_u8 *)0x0;
      }
      break;
    case 0xe:
      pcVar12 = pp_import_parse_line(&local_10,(char *)&local_c);
      if ((pcVar12 != (c1_u8 *)0x0) &&
         (cVar8 = pp_import_directive((char *)pcVar12,local_10,(char)local_c,(char **)&local_14,
                                      &local_18,&local_19), cVar8 != '\0')) {
        pcVar12 = pp_include_open_and_push(local_14,'\0');
        return pcVar12;
      }
    }
  }
  if (((((g_compile_flags_c8 & 0x32000000) == 0) &&
       ((((g_compile_flags_c8 & 0x40000000) == 0 || (((byte)g_compile_flags_cc & 8) != 0)) ||
        ((g_compile_flags_c4 & 0x200) != 0)))) && (((byte)g_compile_flags_cc & 0x10) == 0)) &&
     (((g_compile_flags_c8 & 0x4000000) == 0 || ((g_compile_flags_c4 & 0x8000) != 0)))) {
    if (((byte)g_compile_flags_cc & 1) == 0) {
      g_context_arena_index = 5;
      g_expr_arena_index = 5;
      return g_token_newline;
    }
    g_context_arena_index = 4;
    g_expr_arena_index = 4;
    return g_token_newline;
  }
  g_context_arena_index = 0;
  g_expr_arena_index = 0;
  return g_token_newline;
LAB_10461bab:
  do {
    bVar6 = *g_input_ptr;
    pbVar14 = g_input_ptr + 1;
    local_18 = (char *)CONCAT31(local_18._1_3_,bVar6);
    cVar3 = g_char_class[bVar6];
    if (cVar3 == '\0') break;
    if (cVar3 == '\x05') {
      *pcVar12 = 0;
      diag_fatal(0xbd,g_number_digit_buffer);
    }
    g_input_ptr = pbVar14;
    if (cVar3 != '#') goto LAB_10461bf1;
    *pcVar12 = bVar6;
    lex_skip_mbcs_trail_byte();
    pcVar12[1] = bVar6;
    pcVar12 = pcVar12 + 2;
  } while( true );
  g_input_ptr = pbVar14;
  uVar13 = lex_buffer_refill();
  if ((uVar13 & 0xffffffaf) == 0) {
LAB_10461bf1:
    *pcVar12 = bVar6;
    pcVar12 = pcVar12 + 1;
  }
  goto LAB_10461bab;
LAB_1040eb13:
  cond_lo = 0;
  pcVar9 = "if";
  bVar6 = pp_directive_lookup_name("if");
  local_14 = (byte *)CONCAT31(local_14._1_3_,bVar6);
  uVar13 = g_token_arena_index;
  iVar16 = g_opt_E_preprocess;
  pcVar5 = local_18;
  cond_lo_default = cond_lo;
  goto joined_r0x1040e994;
}

