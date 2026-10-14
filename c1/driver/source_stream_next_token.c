c1_token * __thiscall source_stream_next_token(c1_source_stream *stream)

{
  c1_token_cursor *buffer;
  c1_token_source_frame **ppcVar1;
  _func_240 **pp_Var2;
  char *pcVar3;
  c1_u8 cVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  c1_token *pcVar8;
  code *write_text;
  code *put_char;
  fe_name *pfVar9;
  byte bVar10;
  c1_saved_token_stream *saved_stream;
  c1_saved_token_stream *pcVar11;
  fe_arena *pfVar12;
  c1_token *pcVar13;
  uint uVar14;
  int iVar15;
  byte *pbVar16;
  uint *puVar17;
  char *pcVar18;
  c1_yystype *pcVar19;
  int in_stack_fffffff4;
  uint in_stack_fffffffc;
  
  put_char = fputc_exref;
  write_text = fwrite_exref;
  iVar15 = stream->unget_count;
  if (iVar15 != 0) {
    stream->unget_count = iVar15 + -1;
    return stream->unget[iVar15 + -1];
  }
  do {
    pbVar16 = g_input_ptr;
    bVar10 = *g_input_ptr;
    g_input_ptr = g_input_ptr + 1;
    in_stack_fffffffc = CONCAT31((int3)(in_stack_fffffffc >> 8),bVar10);
    uVar14 = (uint)bVar10;
    switch(g_char_class[uVar14]) {
    case '\0':
      if (bVar10 == 0x5c) {
        if (g_opt_E_preprocess == 0) {
          iVar15 = lex_line_splice();
          if (iVar15 == 0) {
            diag_error(0x11);
          }
        }
        else {
          fputc(0x5c,g_pp_output_stream);
          bVar10 = *g_input_ptr;
          g_input_ptr = g_input_ptr + 1;
          if (g_char_class[bVar10] == '\0') {
            bVar10 = lex_next_significant_char(bVar10);
          }
          fputc((uint)bVar10,g_pp_output_stream);
        }
      }
      else if (bVar10 == 0x3f) {
        uVar14 = lex_trigraph();
        if ((uVar14 & 0x40) != 0) {
          return g_token_question;
        }
      }
      else {
        if (g_lex_source_ended != '\0') {
          g_input_ptr = pbVar16;
          return g_token_end_marker;
        }
        if (g_macro_expansion_depth == 0) {
          iVar15 = file_read_or_fatal();
          if (iVar15 != 0) {
            if (g_opt_E_preprocess == 0) {
              if (((g_include_depth != 0) || (g_pch_directive_mode != 2)) ||
                 (iVar15 = pch_read_options(), iVar15 != 1)) {
                uVar14 = pp_include_pop_file();
                if (uVar14 == 0) {
                  if ((g_compile_flags_c4 & 0x8000) != 0) {
                    return g_token_directive_end;
                  }
                  g_lex_source_ended = '\x01';
                  g_input_ptr = &g_empty_source_text;
                  (*g_source_tracker->vtbl->source_tracker_mark)(g_source_tracker);
                }
                else if (uVar14 == 1000) break;
                iVar15 = g_token_arena_index;
                saved_stream = arena_alloc(g_arenas + g_token_arena_index,0x38);
                iVar6 = g_token_position;
                if (saved_stream == (c1_saved_token_stream *)0x0) {
                  saved_stream = (c1_saved_token_stream *)0x0;
                }
                else {
                  buffer = &saved_stream->start;
                  saved_stream->position = g_token_position;
                  saved_stream->position_end = iVar6;
                  token_buffer_init(buffer,iVar15);
                  saved_stream->arena = iVar15;
                  saved_stream->vtbl = (c1_token_stream_vtbl *)&PTR_token_stream_next_raw_1065240c;
                  (saved_stream->read).block = buffer->block;
                  (saved_stream->read).index = (saved_stream->start).index;
                  (saved_stream->read).arena = (saved_stream->start).arena;
                  iVar6 = (saved_stream->start).index;
                  (saved_stream->write).block = buffer->block;
                  iVar7 = (saved_stream->start).arena;
                  (saved_stream->write).index = iVar6;
                  (saved_stream->write).arena = iVar7;
                  saved_stream->flags = saved_stream->flags & 0xfe;
                }
                token_source_push(&g_token_record_position,(int)saved_stream,iVar15,0,0,
                                  &g_token_position);
                g_yylval_word1 = (int)uVar14 >> 0x1f;
                g_yylval = uVar14;
                if (g_token_arena_index == 0) {
                  if (g_pool_default.left < 0x20) {
                    pool_reserve(&g_pool_default,0x20);
                  }
                  g_pool_default.left = g_pool_default.left - 0x20;
                  pcVar13 = (c1_token *)g_pool_default.cur;
                  g_pool_default.cur = g_pool_default.cur + 0x20;
                }
                else {
                  pcVar13 = arena_alloc(g_arenas + g_token_arena_index,0x20);
                }
                if (pcVar13 == (c1_token *)0x0) {
                  pcVar13 = (c1_token *)0x0;
                }
                else {
                  pcVar13->code = '<';
                  puVar17 = &g_yylval;
                  pcVar19 = &pcVar13->value;
                  for (iVar15 = 6; iVar15 != 0; iVar15 = iVar15 + -1) {
                    pcVar19->words[0] = *puVar17;
                    puVar17 = puVar17 + 1;
                    pcVar19 = (c1_yystype *)((int)pcVar19 + 4);
                  }
                }
                (*g_token_save_frame->stream->vtbl->append)(g_token_save_frame->stream,pcVar13);
                pcVar13 = token_new_position_marker(g_token_arena_index);
                (*g_token_save_frame->stream->vtbl->append)(g_token_save_frame->stream,pcVar13);
                (*g_token_save_frame->stream->vtbl->append)
                          (g_token_save_frame->stream,g_token_directive_end);
                (*g_token_save_frame->stream->vtbl->append)
                          (g_token_save_frame->stream,g_token_end_of_stream);
                pcVar11 = (c1_saved_token_stream *)0x0;
                if (g_token_save_frame != (c1_token_source_frame *)0x0) {
                  ppcVar1 = &g_token_save_frame->prev;
                  pcVar11 = g_token_save_frame->stream;
                  g_token_record_position = g_token_save_frame->position;
                  pp_Var2 = &g_token_save_frame->on_pop;
                  g_token_save_frame = *ppcVar1;
                  if (*pp_Var2 != (_func_240 *)0x0) {
                    (**pp_Var2)();
                  }
                }
                g_yylval = (uint)pcVar11;
                if (g_token_arena_index == 0) {
                  if (g_pool_default.left < 0x20) {
                    pool_reserve(&g_pool_default,0x20);
                  }
                  g_pool_default.left = g_pool_default.left - 0x20;
                  pcVar13 = (c1_token *)g_pool_default.cur;
                  g_pool_default.cur = g_pool_default.cur + 0x20;
                }
                else {
                  pfVar12 = g_arenas + g_token_arena_index;
                  pcVar13 = (c1_token *)pfVar12->cur;
                  pcVar8 = (c1_token *)g_arenas[g_token_arena_index].end;
                  pfVar12->cur = &pcVar13[1].code;
                  if (pcVar8 < pcVar13 + 1) {
                    arena_grow(pfVar12);
                  }
                }
                if (pcVar13 == (c1_token *)0x0) {
                  return (c1_token *)0x0;
                }
                pcVar13->code = 0xf4;
                puVar17 = &g_yylval;
                pcVar19 = &pcVar13->value;
                for (iVar15 = 6; iVar15 != 0; iVar15 = iVar15 + -1) {
                  pcVar19->words[0] = *puVar17;
                  puVar17 = puVar17 + 1;
                  pcVar19 = (c1_yystype *)((int)pcVar19 + 4);
                }
                return pcVar13;
              }
            }
            else {
              iVar15 = pp_include_pop_file();
              if (iVar15 == 0) {
                return g_token_end_marker;
              }
            }
          }
        }
        else {
          lex_buffer_refill();
        }
      }
      break;
    case '\x01':
      pbVar16 = g_input_ptr;
      if (g_opt_E_preprocess == 0) {
        do {
          g_input_ptr = pbVar16;
          pbVar16 = g_input_ptr + 1;
        } while (g_char_class[*g_input_ptr] == '\x01');
      }
      else {
        do {
          g_input_ptr = pbVar16;
          if (bVar10 != 0xd) {
            fputc(uVar14,g_pp_output_stream);
          }
          bVar10 = *g_input_ptr;
          in_stack_fffffffc = CONCAT31((int3)(in_stack_fffffffc >> 8),bVar10);
          uVar14 = (uint)bVar10;
          pbVar16 = g_input_ptr + 1;
        } while (g_char_class[uVar14] == '\x01');
      }
      break;
    default:
      if (g_opt_E_preprocess == 0) {
        diag_error(0x12,uVar14);
      }
      else {
        fputc(uVar14,g_pp_output_stream);
      }
      break;
    case '\x03':
      if ((g_ms_extensions == '\0') && (g_pch_option_block == 0)) {
        iVar15 = lex_skip_comment_in_directive();
      }
      else {
        bVar10 = lex_get_char();
        if (bVar10 == 0x2f) {
          g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
          pp_output_copy_comment();
        }
        else {
          g_input_ptr = g_input_ptr + -1;
          bVar10 = lex_get_char();
          if (bVar10 != 0x2a) {
            g_input_ptr = g_input_ptr + -1;
            iVar15 = 0;
            goto LAB_10602d3d;
          }
          g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
          pp_block_comment_dispatch();
        }
        g_compile_flags_c4 = g_compile_flags_c4 & 0xfffff7ff;
        iVar15 = 1;
      }
LAB_10602d3d:
      if (iVar15 == 0) {
        cVar4 = g_char_class[*g_input_ptr];
        goto joined_r0x10602d5e;
      }
      break;
    case '\x04':
      return g_token_lparen;
    case '\x05':
      if ((g_compile_flags_c4 & 0x8000) != 0) {
        g_input_ptr = pbVar16;
        return g_token_directive_end;
      }
      pcVar13 = (c1_token *)lex_scan_new_line();
      if (pcVar13 != (c1_token *)0x0) {
        return pcVar13;
      }
      break;
    case '\a':
      pbVar16 = pbVar16 + 2;
      cVar4 = g_char_class[*g_input_ptr];
      if (cVar4 == '\0') {
        if ((g_macro_expansion_depth == 0) && (*g_input_ptr == 0)) {
          g_input_ptr = pbVar16;
          uVar14 = in_stack_fffffffc;
          lex_buffer_refill();
          pcVar13 = lex_scan_token_directive_fragment
                              (put_char,in_stack_fffffffc,write_text,(char)in_stack_fffffff4,uVar14)
          ;
          return pcVar13;
        }
      }
      else {
        if (cVar4 == '\x15') {
          in_stack_fffffff4 = 1;
          g_input_ptr = pbVar16;
          goto LAB_106030fc;
        }
        if (cVar4 == '\x16') {
          in_stack_fffffff4 = 1;
          g_input_ptr = pbVar16;
          goto LAB_10603090;
        }
      }
    case '\x06':
      iVar15 = lex_scan_identifier(bVar10);
      if (((iVar15 != 0) || (g_last_name->macro == (fe_macro *)0x0)) ||
         (iVar15 = pp_macro_expand(g_last_name->macro), iVar15 == 0)) {
        if (g_opt_E_preprocess != 0) {
          pcVar18 = g_last_name->text;
          cVar5 = *pcVar18;
          while (cVar5 != '\0') {
            fputc((int)cVar5,g_pp_output_stream);
            pcVar3 = pcVar18 + 1;
            pcVar18 = pcVar18 + 1;
            cVar5 = *pcVar3;
          }
          return g_token_internal;
        }
        if ((g_last_name->flags & 0x10000) == 0) {
          if (g_token_arena_index == 0) {
            if (g_pool_default.left < 0x20) {
              pool_reserve(&g_pool_default,0x20);
            }
            g_pool_default.left = g_pool_default.left - 0x20;
            pcVar13 = (c1_token *)g_pool_default.cur;
            g_pool_default.cur = g_pool_default.cur + 0x20;
          }
          else {
            pfVar12 = g_arenas + g_token_arena_index;
            pcVar13 = (c1_token *)pfVar12->cur;
            pcVar8 = (c1_token *)g_arenas[g_token_arena_index].end;
            pfVar12->cur = &pcVar13[1].code;
            if (pcVar8 < pcVar13 + 1) {
              arena_grow(pfVar12);
            }
          }
          pfVar9 = g_last_name;
          if (pcVar13 == (c1_token *)0x0) {
            return (c1_token *)0x0;
          }
          pcVar13->code = '\x06';
          (pcVar13->value).name = pfVar9;
          (pcVar13->value).words[1] = g_token_position;
          return pcVar13;
        }
        return (c1_token *)(&g_token_static_records)[g_last_name->token_kind];
      }
      break;
    case '\b':
      bVar10 = *g_input_ptr;
      g_input_ptr = pbVar16 + 2;
      cVar4 = g_char_class[bVar10];
      goto joined_r0x10603338;
    case '\t':
      bVar10 = *g_input_ptr;
      g_input_ptr = pbVar16 + 2;
      cVar4 = g_char_class[bVar10];
      goto joined_r0x1060326e;
    case '\n':
      bVar10 = *g_input_ptr;
      g_input_ptr = pbVar16 + 2;
      cVar4 = g_char_class[bVar10];
      goto joined_r0x10603817;
    case '\v':
      if (g_opt_E_preprocess == 0) {
        if (g_macro_expansion_depth == 0) {
          diag_error(0xe);
          lex_skip_whitespace();
        }
        else {
          diag_error(0x79);
        }
      }
      else {
        fwrite("#",1,1,g_pp_output_stream);
      }
      break;
    case '\f':
      bVar10 = *g_input_ptr;
      g_input_ptr = pbVar16 + 2;
      cVar4 = g_char_class[bVar10];
      goto joined_r0x1060375e;
    case '\r':
      bVar10 = *g_input_ptr;
      g_input_ptr = pbVar16 + 2;
      cVar4 = g_char_class[bVar10];
      goto joined_r0x106037a5;
    case '\x0e':
      bVar10 = *g_input_ptr;
      g_input_ptr = pbVar16 + 2;
      cVar4 = g_char_class[bVar10];
      goto joined_r0x10603717;
    case '\x0f':
      goto switchD_10602cf1_caseD_f;
    case '\x10':
      bVar10 = *g_input_ptr;
      g_input_ptr = pbVar16 + 2;
      cVar4 = g_char_class[bVar10];
      goto joined_r0x10603620;
    case '\x11':
      bVar10 = *g_input_ptr;
      g_input_ptr = pbVar16 + 2;
      cVar4 = g_char_class[bVar10];
      goto joined_r0x106035c7;
    case '\x12':
      bVar10 = *g_input_ptr;
      g_input_ptr = pbVar16 + 2;
      bVar10 = g_char_class[bVar10];
      goto joined_r0x10603560;
    case '\x13':
      bVar10 = *g_input_ptr;
      g_input_ptr = pbVar16 + 2;
      cVar4 = g_char_class[bVar10];
      goto joined_r0x10603388;
    case '\x14':
      bVar10 = *g_input_ptr;
      g_input_ptr = pbVar16 + 2;
      cVar4 = g_char_class[bVar10];
      goto joined_r0x1060341b;
    case '\x15':
      in_stack_fffffff4 = 0;
LAB_106030fc:
      if (g_opt_E_preprocess == 0) {
        lex_scan_string_literal_entry((c1_u8)in_stack_fffffff4,'\'');
        pcVar13 = (c1_token *)
                  lex_scan_character_constant
                            (in_stack_fffffff4,(ushort *)g_yylval,(short)g_yylval_word1 - 1);
        return pcVar13;
      }
      pp_output_copy_literal(0x27,(c1_u8)in_stack_fffffff4);
      break;
    case '\x16':
      in_stack_fffffff4 = 0;
LAB_10603090:
      if (g_opt_E_preprocess == 0) {
        lex_scan_string_literal_entry((c1_u8)in_stack_fffffff4,'\"');
        if (g_token_arena_index == 0) {
          if (g_pool_default.left < 0x20) {
            pool_reserve(&g_pool_default,0x20);
          }
          g_pool_default.left = g_pool_default.left - 0x20;
          pcVar13 = (c1_token *)g_pool_default.cur;
          g_pool_default.cur = g_pool_default.cur + 0x20;
        }
        else {
          pfVar12 = g_arenas + g_token_arena_index;
          pcVar13 = (c1_token *)pfVar12->cur;
          pcVar8 = (c1_token *)g_arenas[g_token_arena_index].end;
          pfVar12->cur = &pcVar13[1].code;
          if (pcVar8 < pcVar13 + 1) {
            arena_grow(pfVar12);
          }
        }
        if (pcVar13 == (c1_token *)0x0) {
          return (c1_token *)0x0;
        }
        pcVar13->code = '\a';
        puVar17 = &g_yylval;
        pcVar19 = &pcVar13->value;
        for (iVar15 = 6; iVar15 != 0; iVar15 = iVar15 + -1) {
          pcVar19->words[0] = *puVar17;
          puVar17 = puVar17 + 1;
          pcVar19 = (c1_yystype *)((int)pcVar19 + 4);
        }
        return pcVar13;
      }
      pp_output_copy_literal(0x22,(c1_u8)in_stack_fffffff4);
      break;
    case '\x17':
      return g_token_tilde;
    case '\x18':
      return g_token_rbrace;
    case '\x19':
      return g_token_rbracket;
    case '\x1a':
      bVar10 = *g_input_ptr;
      g_input_ptr = pbVar16 + 2;
      cVar4 = g_char_class[bVar10];
      goto joined_r0x106036d9;
    case '\x1b':
      return g_token_comma;
    case '\x1c':
      return g_token_rparen;
    case '\x1d':
      if (((g_compile_flags_c4 & 0x200000) != 0) && ((g_compile_flags_c4 & 0x8000) == 0)) {
        pcVar13 = lex_scan_number_token(bVar10,1);
        return pcVar13;
      }
      pcVar13 = lex_scan_number_token(bVar10,0);
      return pcVar13;
    case '\x1e':
      return g_token_lbrace;
    case '\x1f':
      return g_token_lbracket;
    case ' ':
      return g_token_semicolon;
    case ')':
      g_input_ptr = pbVar16 + 2;
    }
  } while( true );
joined_r0x106036d9:
  if (cVar4 != '\0') {
    if (cVar4 == '\x14') {
      return g_token_colon_greater;
    }
LAB_106036e8:
    g_input_ptr = g_input_ptr + -1;
    return g_token_colon;
  }
  uVar14 = lex_buffer_refill();
  if ((uVar14 & 0xffffff8f) == 0) {
    if ((uVar14 & 0x20) != 0) {
      g_input_ptr = g_input_ptr + 1;
    }
    goto LAB_106036e8;
  }
  bVar10 = *g_input_ptr;
  g_input_ptr = g_input_ptr + 1;
  cVar4 = g_char_class[bVar10];
  goto joined_r0x106036d9;
joined_r0x1060341b:
  if (cVar4 != '\0') goto LAB_10603421;
  uVar14 = lex_buffer_refill();
  if ((uVar14 & 0xffffff8f) == 0) {
    if ((uVar14 & 0x20) != 0) {
      g_input_ptr = g_input_ptr + 1;
    }
    goto LAB_10603438;
  }
  bVar10 = *g_input_ptr;
  g_input_ptr = g_input_ptr + 1;
  cVar4 = g_char_class[bVar10];
  goto joined_r0x1060341b;
LAB_10603421:
  if (cVar4 == '\r') {
    g_input_ptr = g_input_ptr;
    return g_token_greater_equal;
  }
  if (cVar4 != '\x14') {
LAB_10603438:
    g_input_ptr = g_input_ptr + -1;
    return g_token_greater;
  }
  cVar4 = g_char_class[*g_input_ptr];
  do {
    g_input_ptr = g_input_ptr + 1;
    if (cVar4 != '\0') {
      if (cVar4 == '\r') {
        return g_token_shift_right_assign;
      }
LAB_10603472:
      g_input_ptr = g_input_ptr + -1;
      return g_token_shift_right;
    }
    uVar14 = lex_buffer_refill();
    if ((uVar14 & 0xffffff8f) == 0) {
      if ((uVar14 & 0x20) != 0) {
        g_input_ptr = g_input_ptr + 1;
      }
      goto LAB_10603472;
    }
    cVar4 = g_char_class[*g_input_ptr];
  } while( true );
joined_r0x10603388:
  if (cVar4 != '\0') goto LAB_1060338e;
  uVar14 = lex_buffer_refill();
  if ((uVar14 & 0xffffff8f) == 0) {
    if ((uVar14 & 0x20) != 0) {
      g_input_ptr = g_input_ptr + 1;
      pcVar13 = lex_scan_token_fragment();
      return pcVar13;
    }
    goto code_r0x106033ec;
  }
  bVar10 = *g_input_ptr;
  g_input_ptr = g_input_ptr + 1;
  cVar4 = g_char_class[bVar10];
  goto joined_r0x10603388;
LAB_1060338e:
  if (cVar4 == '\r') {
    g_input_ptr = g_input_ptr;
    return g_token_less_equal;
  }
  if (cVar4 != '\x13') {
code_r0x106033ec:
    g_input_ptr = g_input_ptr + -1;
    return g_token_less;
  }
  cVar4 = g_char_class[*g_input_ptr];
  do {
    g_input_ptr = g_input_ptr + 1;
    if (cVar4 != '\0') {
      if (cVar4 == '\r') {
        return g_token_shift_left_assign;
      }
LAB_106033ba:
      g_input_ptr = g_input_ptr + -1;
      return g_token_shift_left;
    }
    uVar14 = lex_buffer_refill();
    if ((uVar14 & 0xffffff8f) == 0) {
      if ((uVar14 & 0x20) != 0) {
        g_input_ptr = g_input_ptr + 1;
      }
      goto LAB_106033ba;
    }
    cVar4 = g_char_class[*g_input_ptr];
  } while( true );
joined_r0x10603560:
  if (bVar10 < 0x15) {
    switch(bVar10) {
    case 0:
      goto lex_scan_token_fragment_4;
    default:
      break;
    case 0xd:
      return g_token_minus_assign;
    case 0x12:
      return g_token_minus_minus;
    case 0x14:
      return g_token_arrow;
    }
  }
  goto switchD_1060356a_caseD_1;
lex_scan_token_fragment_4:
  uVar14 = lex_buffer_refill();
  if ((uVar14 & 0xffffff8f) == 0) {
    if ((uVar14 & 0x20) != 0) {
      g_input_ptr = g_input_ptr + 1;
    }
    goto switchD_1060356a_caseD_1;
  }
  bVar10 = *g_input_ptr;
  g_input_ptr = g_input_ptr + 1;
  bVar10 = g_char_class[bVar10];
  goto joined_r0x10603560;
joined_r0x106035c7:
  if (cVar4 != '\0') {
    if (cVar4 == '\r') {
      return g_token_plus_assign;
    }
    if (cVar4 == '\x11') {
      return g_token_plus_plus;
    }
LAB_106035d7:
    g_input_ptr = g_input_ptr + -1;
    return g_token_plus;
  }
  uVar14 = lex_buffer_refill();
  if ((uVar14 & 0xffffff8f) == 0) {
    if ((uVar14 & 0x20) != 0) {
      g_input_ptr = g_input_ptr + 1;
    }
    goto LAB_106035d7;
  }
  bVar10 = *g_input_ptr;
  g_input_ptr = g_input_ptr + 1;
  cVar4 = g_char_class[bVar10];
  goto joined_r0x106035c7;
joined_r0x10603620:
  if (cVar4 != '\0') {
    if (cVar4 == '\r') {
      return g_token_amp_assign;
    }
    if (cVar4 == '\x10') {
      return g_token_and_and;
    }
code_r0x1060364a:
    g_input_ptr = g_input_ptr + -1;
    return g_token_amp;
  }
  uVar14 = lex_buffer_refill();
  if ((uVar14 & 0xffffff8f) == 0) {
    if ((uVar14 & 0x20) != 0) {
      g_input_ptr = g_input_ptr + 1;
      pcVar13 = lex_scan_token_fragment_2();
      return pcVar13;
    }
    goto code_r0x1060364a;
  }
  bVar10 = *g_input_ptr;
  g_input_ptr = g_input_ptr + 1;
  cVar4 = g_char_class[bVar10];
  goto joined_r0x10603620;
joined_r0x10603717:
  if (cVar4 != '\0') {
    if (cVar4 == '\r') {
      return g_token_caret_assign;
    }
LAB_10603722:
    g_input_ptr = g_input_ptr + -1;
    return g_token_caret;
  }
  uVar14 = lex_buffer_refill();
  if ((uVar14 & 0xffffff8f) == 0) {
    if ((uVar14 & 0x20) != 0) {
      g_input_ptr = g_input_ptr + 1;
    }
    goto LAB_10603722;
  }
  bVar10 = *g_input_ptr;
  g_input_ptr = g_input_ptr + 1;
  cVar4 = g_char_class[bVar10];
  goto joined_r0x10603717;
joined_r0x106037a5:
  if (cVar4 != '\0') {
    if (cVar4 == '\r') {
      return g_token_equal_equal;
    }
LAB_106037ac:
    g_input_ptr = g_input_ptr + -1;
    return g_token_assign;
  }
  uVar14 = lex_buffer_refill();
  if ((uVar14 & 0xffffff8f) == 0) {
    if ((uVar14 & 0x20) != 0) {
      g_input_ptr = g_input_ptr + 1;
    }
    goto LAB_106037ac;
  }
  bVar10 = *g_input_ptr;
  g_input_ptr = g_input_ptr + 1;
  cVar4 = g_char_class[bVar10];
  goto joined_r0x106037a5;
joined_r0x1060375e:
  if (cVar4 != '\0') {
    if (cVar4 == '\r') {
      return g_token_percent_assign;
    }
LAB_10603769:
    g_input_ptr = g_input_ptr + -1;
    return g_token_percent;
  }
  uVar14 = lex_buffer_refill();
  if ((uVar14 & 0xffffff8f) == 0) {
    if ((uVar14 & 0x20) != 0) {
      g_input_ptr = g_input_ptr + 1;
    }
    goto LAB_10603769;
  }
  bVar10 = *g_input_ptr;
  g_input_ptr = g_input_ptr + 1;
  cVar4 = g_char_class[bVar10];
  goto joined_r0x1060375e;
joined_r0x10603817:
  if (cVar4 != '\0') {
    if (cVar4 == '\r') {
      return g_token_not_equal;
    }
LAB_10603822:
    g_input_ptr = g_input_ptr + -1;
    return g_token_not;
  }
  uVar14 = lex_buffer_refill();
  if ((uVar14 & 0xffffff8f) == 0) {
    if ((uVar14 & 0x20) != 0) {
      g_input_ptr = g_input_ptr + 1;
    }
    goto LAB_10603822;
  }
  bVar10 = *g_input_ptr;
  g_input_ptr = g_input_ptr + 1;
  cVar4 = g_char_class[bVar10];
  goto joined_r0x10603817;
joined_r0x1060326e:
  if (cVar4 != '\0') {
    if (cVar4 == '\t') {
      bVar10 = *g_input_ptr;
      g_input_ptr = g_input_ptr + 1;
      if (g_char_class[bVar10] == '\0') {
        bVar10 = lex_next_significant_char(bVar10);
      }
      if (bVar10 == 0x2e) {
        if (g_token_arena_index == 0) {
          if (g_pool_default.left < 0x20) {
            pool_reserve(&g_pool_default,0x20);
          }
          g_pool_default.left = g_pool_default.left - 0x20;
          pcVar13 = (c1_token *)g_pool_default.cur;
          g_pool_default.cur = g_pool_default.cur + 0x20;
        }
        else {
          pfVar12 = g_arenas + g_token_arena_index;
          pcVar13 = (c1_token *)pfVar12->cur;
          pcVar8 = (c1_token *)g_arenas[g_token_arena_index].end;
          pfVar12->cur = &pcVar13[1].code;
          if (pcVar8 < pcVar13 + 1) {
            arena_grow(pfVar12);
          }
        }
        if (pcVar13 == (c1_token *)0x0) {
          return (c1_token *)0x0;
        }
        pcVar13->code = 'j';
        puVar17 = &g_yylval;
        pcVar19 = &pcVar13->value;
        for (iVar15 = 6; iVar15 != 0; iVar15 = iVar15 + -1) {
          pcVar19->words[0] = *puVar17;
          puVar17 = puVar17 + 1;
          pcVar19 = (c1_yystype *)((int)pcVar19 + 4);
        }
        return pcVar13;
      }
      pbVar16 = g_input_ptr + -2;
      g_input_ptr = g_input_ptr + -1;
      *pbVar16 = 0x2e;
    }
    else if (cVar4 == '\x1d') {
      g_number_digit_buffer[0] = '.';
      g_number_digit_buffer[1] = g_input_ptr[-1];
      if (((g_compile_flags_c4 & 0x4000) == 0) &&
         ((g_opt_E_preprocess != 0 || ((g_compile_flags_c4 & 0x800000) != 0)))) {
        iVar15 = lex_scan_pp_number_text((byte *)(g_number_digit_buffer + 2));
        if (g_opt_E_preprocess != 0) {
          fwrite(g_number_digit_buffer,iVar15 + 1,1,g_pp_output_stream);
        }
        return g_token_internal;
      }
      pcVar13 = lex_scan_number(g_number_digit_buffer + 2);
      return pcVar13;
    }
LAB_10603282:
    g_input_ptr = g_input_ptr + -1;
    return g_token_dot;
  }
  uVar14 = lex_buffer_refill();
  if ((uVar14 & 0xffffff8f) == 0) {
    if ((uVar14 & 0x20) != 0) {
      g_input_ptr = g_input_ptr + 1;
    }
    goto LAB_10603282;
  }
  bVar10 = *g_input_ptr;
  g_input_ptr = g_input_ptr + 1;
  cVar4 = g_char_class[bVar10];
  goto joined_r0x1060326e;
joined_r0x10603338:
  if (cVar4 != '\0') {
    if (cVar4 == '\x03') {
      if (g_opt_E_preprocess == 0) {
        diag_warning(1,0x8a);
      }
    }
    else if (cVar4 == '\r') {
      return g_token_star_assign;
    }
LAB_1060334c:
    g_input_ptr = g_input_ptr + -1;
    return g_token_star;
  }
  uVar14 = lex_buffer_refill();
  if ((uVar14 & 0xffffff8f) == 0) {
    if ((uVar14 & 0x20) != 0) {
      g_input_ptr = g_input_ptr + 1;
    }
    goto LAB_1060334c;
  }
  bVar10 = *g_input_ptr;
  g_input_ptr = g_input_ptr + 1;
  cVar4 = g_char_class[bVar10];
  goto joined_r0x10603338;
joined_r0x10602d5e:
  g_input_ptr = g_input_ptr + 1;
  if (cVar4 != '\0') {
    if (cVar4 == '\r') {
      return g_token_slash_assign;
    }
LAB_10602d6d:
    g_input_ptr = g_input_ptr + -1;
    return g_token_slash;
  }
  uVar14 = lex_buffer_refill();
  if ((uVar14 & 0xffffff8f) == 0) {
    if ((uVar14 & 0x20) != 0) {
      g_input_ptr = g_input_ptr + 1;
    }
    goto LAB_10602d6d;
  }
  cVar4 = g_char_class[*g_input_ptr];
  goto joined_r0x10602d5e;
switchD_1060356a_caseD_1:
  g_input_ptr = g_input_ptr + -1;
  return g_token_minus;
  while (uVar14 = lex_buffer_refill(), (uVar14 & 0xffffff8f) != 0) {
switchD_10602cf1_caseD_f:
    bVar10 = *g_input_ptr;
    g_input_ptr = g_input_ptr + 1;
    cVar4 = g_char_class[bVar10];
    if (cVar4 != '\0') {
      if (cVar4 == '\r') {
        return g_token_bar_assign;
      }
      if (cVar4 == '\x0f') {
        return g_token_bar_bar;
      }
      goto code_r0x106036aa;
    }
  }
  if ((uVar14 & 0x20) != 0) {
    g_input_ptr = g_input_ptr + 1;
    pcVar13 = lex_scan_token_fragment_3();
    return pcVar13;
  }
code_r0x106036aa:
  g_input_ptr = g_input_ptr + -1;
  return g_token_bar;
}

