c1_u8 * __fastcall lex_source_next_token(c1xx_lex_source_stream *stream)

{
  c1xx_token_cursor *cursor;
  _func_193 **pp_Var1;
  char *pcVar2;
  c1_u8 cVar3;
  char cVar4;
  byte *pbVar5;
  c1_u8 *pcVar6;
  fe_name *pfVar7;
  int iVar8;
  byte bVar9;
  uint *token_rec;
  uint *token_rec_2;
  c1_arena *pcVar10;
  c1_u8 *pcVar11;
  uint uVar12;
  int iVar13;
  byte *pbVar14;
  uint *puVar15;
  char *pcVar16;
  uint *puVar17;
  byte bStack_c;
  uint *buffer;
  
  iVar13 = stream->pushed_count;
  if (iVar13 != 0) {
    stream->pushed_count = iVar13 + -1;
    return &stream->pushed[iVar13 + -1]->code;
  }
  do {
    pbVar14 = g_input_ptr;
    bVar9 = *g_input_ptr;
    g_input_ptr = g_input_ptr + 1;
    uVar12 = (uint)bVar9;
    switch(g_char_class[uVar12]) {
    case '\0':
      if (bVar9 == 0x5c) {
        if (g_opt_E_preprocess == 0) {
          iVar13 = lex_line_splice();
          if (iVar13 == 0) {
            diag_error(0x11);
          }
        }
        else {
          fputc(0x5c,g_pp_output_stream);
          bVar9 = *g_input_ptr;
          g_input_ptr = g_input_ptr + 1;
          if (g_char_class[bVar9] == '\0') {
            bVar9 = lex_next_significant_char(bVar9);
          }
          fputc((uint)bVar9,g_pp_output_stream);
        }
      }
      else if (bVar9 == 0x3f) {
        uVar12 = lex_trigraph();
        if ((uVar12 & 0x40) != 0) {
          return &g_token_question->code;
        }
      }
      else {
        if (g_source_exhausted != '\0') {
          g_input_ptr = pbVar14;
          return &g_token_end_of_input->code;
        }
        if (g_macro_expansion_depth == 0) {
          iVar13 = file_read_or_fatal();
          if (iVar13 != 0) {
            if (g_opt_E_preprocess == 0) {
              if (((g_include_depth != 0) || (g_pch_directive_mode != 2)) ||
                 (iVar13 = pch_read_options(), iVar13 != 1)) {
                uVar12 = pp_include_pop_file();
                if (uVar12 == 0) {
                  if ((g_compile_flags_c4 & 0x8000) != 0) {
                    return g_token_directive_end;
                  }
                  g_source_exhausted = '\x01';
                  g_input_ptr = g_end_of_input_sentinel;
                  (**(code **)(*g_source_tracker + 0xc))();
                }
                else if (uVar12 == 1000) break;
                iVar13 = g_token_arena_index;
                token_rec = arena_alloc(g_arenas + g_token_arena_index,0x38);
                iVar8 = g_token_position;
                if (token_rec == (uint *)0x0) {
                  token_rec = (uint *)0x0;
                }
                else {
                  cursor = (c1xx_token_cursor *)(token_rec + 3);
                  token_rec[1] = g_token_position;
                  token_rec[2] = iVar8;
                  token_buffer_init(cursor,iVar13);
                  token_rec[0xc] = iVar13;
                  *token_rec = (uint)&PTR_token_stream_next_raw_104bc55c;
                  token_rec[6] = (uint)cursor->chunk;
                  token_rec[7] = token_rec[4];
                  token_rec[8] = token_rec[5];
                  token_rec[9] = (uint)cursor->chunk;
                  token_rec[10] = token_rec[4];
                  token_rec[0xb] = token_rec[5];
                  *(byte *)(token_rec + 0xd) = (byte)token_rec[0xd] & 0xfe;
                }
                token_source_push((c1_token_reader *)&g_token_record_position,
                                  (c1xx_token_stream *)token_rec,iVar13,0,(void *)0x0,
                                  &g_token_position);
                g_yylval_word1 = (int)uVar12 >> 0x1f;
                g_yylval = uVar12;
                if (g_token_arena_index == 0) {
                  if (g_pool_default_left < 0x30) {
                    pool_reserve((c1xx_pool *)&g_pool_default,0x30);
                  }
                  g_pool_default_left = g_pool_default_left - 0x30;
                  pcVar11 = g_pool_default;
                  g_pool_default = g_pool_default + 0x30;
                }
                else {
                  pcVar11 = arena_alloc(g_arenas + g_token_arena_index,0x30);
                }
                if (pcVar11 == (c1_u8 *)0x0) {
                  pcVar11 = (c1_u8 *)0x0;
                }
                else {
                  *pcVar11 = '<';
                  puVar15 = &g_yylval;
                  puVar17 = (uint *)(pcVar11 + 8);
                  for (iVar13 = 10; iVar13 != 0; iVar13 = iVar13 + -1) {
                    *puVar17 = *puVar15;
                    puVar15 = puVar15 + 1;
                    puVar17 = puVar17 + 1;
                  }
                }
                (*g_token_save_frame->stream->vtbl->append)(g_token_save_frame->stream,(int)pcVar11)
                ;
                pcVar11 = token_new_position_marker(g_token_arena_index);
                (*g_token_save_frame->stream->vtbl->append)(g_token_save_frame->stream,(int)pcVar11)
                ;
                (*g_token_save_frame->stream->vtbl->append)
                          (g_token_save_frame->stream,(int)g_token_directive_end);
                (*g_token_save_frame->stream->vtbl->append)
                          (g_token_save_frame->stream,g_token_end_of_stream);
                token_rec_2 = (uint *)0x0;
                if (g_token_save_frame != (c1_token_source_frame *)0x0) {
                  buffer = (uint *)&g_token_save_frame->prev;
                  token_rec_2 = (uint *)g_token_save_frame->stream;
                  g_token_record_position = g_token_save_frame->position;
                  pp_Var1 = &g_token_save_frame->on_pop;
                  g_token_save_frame = (c1_token_source_frame *)*buffer;
                  if (*pp_Var1 != (_func_193 *)0x0) {
                    (**pp_Var1)();
                  }
                }
                g_yylval = (uint)token_rec_2;
                if (g_token_arena_index == 0) {
                  if (g_pool_default_left < 0x30) {
                    pool_reserve((c1xx_pool *)&g_pool_default,0x30);
                  }
                  g_pool_default_left = g_pool_default_left - 0x30;
                  pbVar14 = g_pool_default;
                  g_pool_default = g_pool_default + 0x30;
                }
                else {
                  pcVar10 = g_arenas + g_token_arena_index;
                  pbVar14 = pcVar10->cur;
                  pbVar5 = g_arenas[g_token_arena_index].end;
                  pcVar10->cur = pbVar14 + 0x30;
                  if (pbVar5 < pbVar14 + 0x30) {
                    arena_grow(pcVar10);
                  }
                }
                if (pbVar14 == (byte *)0x0) {
                  pbVar14 = (byte *)0x0;
                }
                else {
                  *pbVar14 = 0xf4;
                  puVar15 = &g_yylval;
                  puVar17 = (uint *)(pbVar14 + 8);
                  for (iVar13 = 10; iVar13 != 0; iVar13 = iVar13 + -1) {
                    *puVar17 = *puVar15;
                    puVar15 = puVar15 + 1;
                    puVar17 = puVar17 + 1;
                  }
                }
                if ((g_compile_flags_c8 & 0x4000000) != 0) {
                  pragma_process_saved_tokens(pbVar14);
                  pcVar11 = token_new_position_marker(0);
                  return pcVar11;
                }
                return pbVar14;
              }
            }
            else {
              iVar13 = pp_include_pop_file();
              if (iVar13 == 0) {
                return &g_token_end_of_input->code;
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
      pbVar14 = g_input_ptr;
      if (g_opt_E_preprocess == 0) {
        do {
          g_input_ptr = pbVar14;
          pbVar14 = g_input_ptr + 1;
        } while (g_char_class[*g_input_ptr] == '\x01');
      }
      else {
        do {
          g_input_ptr = pbVar14;
          if (bVar9 != 0xd) {
            fputc(uVar12,g_pp_output_stream);
          }
          bVar9 = *g_input_ptr;
          uVar12 = (uint)bVar9;
          pbVar14 = g_input_ptr + 1;
        } while (g_char_class[uVar12] == '\x01');
      }
      break;
    default:
      if (g_opt_E_preprocess == 0) {
        diag_error(0x12,uVar12);
      }
      else {
        fputc(uVar12,g_pp_output_stream);
      }
      break;
    case '\x03':
      bVar9 = lex_get_char();
      if (bVar9 == 0x2f) {
        g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
        pp_output_copy_comment();
        g_compile_flags_c4 = g_compile_flags_c4 & 0xfffff7ff;
      }
      else {
        g_input_ptr = g_input_ptr + -1;
        bVar9 = lex_get_char();
        if (bVar9 != 0x2a) {
          cVar3 = g_char_class[g_input_ptr[-1]];
          goto joined_r0x10402216;
        }
        g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
        pp_block_comment_dispatch();
        g_compile_flags_c4 = g_compile_flags_c4 & 0xfffff7ff;
      }
      break;
    case '\x04':
      return g_token_lparen;
    case '\x05':
      if ((g_compile_flags_c4 & 0x8000) != 0) {
        g_input_ptr = pbVar14;
        return g_token_directive_end;
      }
      pbVar14 = lex_scan_line_start();
      if (pbVar14 != (byte *)0x0) {
        return pbVar14;
      }
      break;
    case '\a':
      while( true ) {
        pbVar14 = g_input_ptr + 1;
        cVar3 = g_char_class[*g_input_ptr];
        if (cVar3 != '\0') break;
        if ((g_macro_expansion_depth != 0) || (*g_input_ptr != 0)) goto switchD_10401d49_caseD_6;
        g_input_ptr = pbVar14;
        lex_buffer_refill();
      }
      if (cVar3 == '\x15') {
        bVar9 = 1;
        g_input_ptr = pbVar14;
        goto LAB_104020da;
      }
      if (cVar3 == '\x16') {
        bStack_c = 1;
        g_input_ptr = pbVar14;
        goto LAB_1040206e;
      }
    case '\x06':
switchD_10401d49_caseD_6:
      iVar13 = lex_scan_identifier(bVar9);
      if (((iVar13 != 0) || (g_last_name->macro == (fe_macro *)0x0)) ||
         (iVar13 = pp_macro_invoke(g_last_name->macro), iVar13 == 0)) {
        if (g_opt_E_preprocess != 0) {
          pcVar16 = g_last_name->text;
          cVar4 = *pcVar16;
          while (cVar4 != '\0') {
            fputc((int)cVar4,g_pp_output_stream);
            pcVar2 = pcVar16 + 1;
            pcVar16 = pcVar16 + 1;
            cVar4 = *pcVar2;
          }
          return &g_token_internal->code;
        }
        if ((g_last_name->flags & 0x10000) == 0) {
          if (g_token_arena_index == 0) {
            if (g_pool_default_left < 0x30) {
              pool_reserve((c1xx_pool *)&g_pool_default,0x30);
            }
            g_pool_default_left = g_pool_default_left - 0x30;
            pcVar11 = g_pool_default;
            g_pool_default = g_pool_default + 0x30;
          }
          else {
            pcVar10 = g_arenas + g_token_arena_index;
            pcVar11 = pcVar10->cur;
            pcVar6 = g_arenas[g_token_arena_index].end;
            pcVar10->cur = pcVar11 + 0x30;
            if (pcVar6 < pcVar11 + 0x30) {
              arena_grow(pcVar10);
            }
          }
          pfVar7 = g_last_name;
          if (pcVar11 == (c1_u8 *)0x0) {
            return (byte *)0x0;
          }
          *pcVar11 = '\x06';
          *(fe_name **)(pcVar11 + 8) = pfVar7;
          *(int *)(pcVar11 + 0xc) = g_token_position;
          return pcVar11;
        }
        return (c1_u8 *)(&g_token_static_records)[g_last_name->token_kind];
      }
      break;
    case '\b':
      bVar9 = *g_input_ptr;
      g_input_ptr = pbVar14 + 2;
      cVar3 = g_char_class[bVar9];
      goto joined_r0x10402345;
    case '\t':
      bVar9 = *g_input_ptr;
      g_input_ptr = pbVar14 + 2;
      bVar9 = g_char_class[bVar9];
      goto joined_r0x1040228b;
    case '\n':
      bVar9 = *g_input_ptr;
      g_input_ptr = pbVar14 + 2;
      cVar3 = g_char_class[bVar9];
      goto joined_r0x10402829;
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
      bVar9 = *g_input_ptr;
      g_input_ptr = pbVar14 + 2;
      cVar3 = g_char_class[bVar9];
      goto joined_r0x1040279b;
    case '\r':
      bVar9 = *g_input_ptr;
      g_input_ptr = pbVar14 + 2;
      cVar3 = g_char_class[bVar9];
      goto joined_r0x104027e2;
    case '\x0e':
      bVar9 = *g_input_ptr;
      g_input_ptr = pbVar14 + 2;
      cVar3 = g_char_class[bVar9];
      goto joined_r0x1045a3e7;
    case '\x0f':
      goto switchD_10401d49_caseD_f;
    case '\x10':
      bVar9 = *g_input_ptr;
      g_input_ptr = pbVar14 + 2;
      cVar3 = g_char_class[bVar9];
      goto joined_r0x1040267a;
    case '\x11':
      bVar9 = *g_input_ptr;
      g_input_ptr = pbVar14 + 2;
      cVar3 = g_char_class[bVar9];
      goto joined_r0x10402621;
    case '\x12':
      bVar9 = *g_input_ptr;
      g_input_ptr = pbVar14 + 2;
      bVar9 = g_char_class[bVar9];
      goto joined_r0x1040258b;
    case '\x13':
      bVar9 = *g_input_ptr;
      g_input_ptr = pbVar14 + 2;
      cVar3 = g_char_class[bVar9];
      goto joined_r0x104023ad;
    case '\x14':
      bVar9 = *g_input_ptr;
      g_input_ptr = pbVar14 + 2;
      cVar3 = g_char_class[bVar9];
      goto joined_r0x10402437;
    case '\x15':
      bVar9 = 0;
LAB_104020da:
      if (g_opt_E_preprocess == 0) {
        lex_scan_string_literal_body(bVar9,'\'');
        pcVar11 = lex_scan_character_constant
                            ((uint)bVar9,(ushort *)g_yylval,(short)g_yylval_word1 - 1);
        return pcVar11;
      }
      pp_output_copy_literal(0x27,bVar9);
      break;
    case '\x16':
      bStack_c = 0;
LAB_1040206e:
      if (g_opt_E_preprocess == 0) {
        lex_scan_string_literal_body(bStack_c,'\"');
        if (g_token_arena_index == 0) {
          if (g_pool_default_left < 0x30) {
            pool_reserve((c1xx_pool *)&g_pool_default,0x30);
          }
          g_pool_default_left = g_pool_default_left - 0x30;
          pcVar11 = g_pool_default;
          g_pool_default = g_pool_default + 0x30;
        }
        else {
          pcVar10 = g_arenas + g_token_arena_index;
          pcVar11 = pcVar10->cur;
          pcVar6 = g_arenas[g_token_arena_index].end;
          pcVar10->cur = pcVar11 + 0x30;
          if (pcVar6 < pcVar11 + 0x30) {
            arena_grow(pcVar10);
          }
        }
        if (pcVar11 == (c1_u8 *)0x0) {
          return (byte *)0x0;
        }
        *pcVar11 = '\a';
        puVar15 = &g_yylval;
        puVar17 = (uint *)(pcVar11 + 8);
        for (iVar13 = 10; iVar13 != 0; iVar13 = iVar13 + -1) {
          *puVar17 = *puVar15;
          puVar15 = puVar15 + 1;
          puVar17 = puVar17 + 1;
        }
        return pcVar11;
      }
      pp_output_copy_literal(0x22,bStack_c);
      break;
    case '\x17':
      return &g_token_tilde->code;
    case '\x18':
      return g_token_rbrace;
    case '\x19':
      return g_token_rbracket;
    case '\x1a':
      bVar9 = *g_input_ptr;
      g_input_ptr = pbVar14 + 2;
      cVar3 = g_char_class[bVar9];
      goto joined_r0x1040274b;
    case '\x1b':
      return g_token_comma;
    case '\x1c':
      return g_token_rparen;
    case '\x1d':
      if (((g_compile_flags_c4 & 0x200000) != 0) && ((g_compile_flags_c4 & 0x8000) == 0)) {
        pcVar11 = lex_scan_integer_literal(bVar9,1);
        return pcVar11;
      }
      pcVar11 = lex_scan_integer_literal(bVar9,0);
      return pcVar11;
    case '\x1e':
      return g_token_lbrace;
    case '\x1f':
      return g_token_lbracket;
    case ' ':
      return g_token_semicolon;
    case ')':
      g_input_ptr = pbVar14 + 2;
    }
  } while( true );
joined_r0x1040274b:
  if (cVar3 != '\0') {
    if (cVar3 == '\x14') {
      return &g_token_colon_greater->code;
    }
    if (cVar3 == '\x1a') {
      return g_token_colon_colon;
    }
LAB_1040275f:
    g_input_ptr = g_input_ptr + -1;
    return g_token_colon;
  }
  uVar12 = lex_buffer_refill();
  if ((uVar12 & 0xffffff8f) == 0) {
    if ((uVar12 & 0x20) != 0) {
      g_input_ptr = g_input_ptr + 1;
    }
    goto LAB_1040275f;
  }
  bVar9 = *g_input_ptr;
  g_input_ptr = g_input_ptr + 1;
  cVar3 = g_char_class[bVar9];
  goto joined_r0x1040274b;
joined_r0x10402437:
  if (cVar3 != '\0') goto LAB_10402439;
  uVar12 = lex_buffer_refill();
  if ((uVar12 & 0xffffff8f) == 0) {
    if ((uVar12 & 0x20) != 0) {
      g_input_ptr = g_input_ptr + 1;
    }
    goto LAB_1040246c;
  }
  bVar9 = *g_input_ptr;
  g_input_ptr = g_input_ptr + 1;
  cVar3 = g_char_class[bVar9];
  goto joined_r0x10402437;
LAB_10402439:
  if (cVar3 == '\r') {
    g_input_ptr = g_input_ptr;
    return g_token_greater_equal;
  }
  if (cVar3 != '\x14') {
LAB_1040246c:
    g_input_ptr = g_input_ptr + -1;
    return g_token_greater;
  }
  cVar3 = g_char_class[*g_input_ptr];
  do {
    g_input_ptr = g_input_ptr + 1;
    if (cVar3 != '\0') {
      if (cVar3 == '\r') {
        return &g_token_shr_assign->code;
      }
LAB_104024aa:
      g_input_ptr = g_input_ptr + -1;
      return &g_token_shr->code;
    }
    uVar12 = lex_buffer_refill();
    if ((uVar12 & 0xffffff8f) == 0) {
      if ((uVar12 & 0x20) != 0) {
        g_input_ptr = g_input_ptr + 1;
      }
      goto LAB_104024aa;
    }
    cVar3 = g_char_class[*g_input_ptr];
  } while( true );
joined_r0x104023ad:
  if (cVar3 != '\0') goto LAB_104023b3;
  uVar12 = lex_buffer_refill();
  if ((uVar12 & 0xffffff8f) == 0) {
    if ((uVar12 & 0x20) != 0) {
      g_input_ptr = g_input_ptr + 1;
    }
    goto LAB_10402408;
  }
  bVar9 = *g_input_ptr;
  g_input_ptr = g_input_ptr + 1;
  cVar3 = g_char_class[bVar9];
  goto joined_r0x104023ad;
LAB_104023b3:
  if (cVar3 == '\r') {
    g_input_ptr = g_input_ptr;
    return &g_token_less_equal->code;
  }
  if (cVar3 != '\x13') {
LAB_10402408:
    g_input_ptr = g_input_ptr + -1;
    return &g_token_less->code;
  }
  cVar3 = g_char_class[*g_input_ptr];
  do {
    g_input_ptr = g_input_ptr + 1;
    if (cVar3 != '\0') {
      if (cVar3 == '\r') {
        return &g_token_shl_assign->code;
      }
LAB_104023e3:
      g_input_ptr = g_input_ptr + -1;
      return &g_token_shl->code;
    }
    uVar12 = lex_buffer_refill();
    if ((uVar12 & 0xffffff8f) == 0) {
      if ((uVar12 & 0x20) != 0) {
        g_input_ptr = g_input_ptr + 1;
      }
      goto LAB_104023e3;
    }
    cVar3 = g_char_class[*g_input_ptr];
  } while( true );
joined_r0x1040258b:
  if (bVar9 < 0x15) {
    switch((&switchD_10402595::switchdataD_10406208)[bVar9]) {
    case 0:
      goto switchD_10402595_caseD_0;
    default:
      break;
    case 0xd:
      g_input_ptr = g_input_ptr;
      return &g_token_sub_assign->code;
    case 0x12:
      g_input_ptr = g_input_ptr;
      return g_token_minus_minus;
    case 0x14:
      cVar3 = g_char_class[*g_input_ptr];
      goto joined_r0x104025b1;
    }
  }
  goto switchD_10402595_caseD_1;
joined_r0x104025b1:
  g_input_ptr = (byte *)((int)g_input_ptr + 1);
  if (cVar3 != '\0') {
    if (cVar3 == '\b') {
      return &g_token_arrow_star->code;
    }
LAB_104025c0:
    g_input_ptr = g_input_ptr + -1;
    return &g_token_arrow->code;
  }
  uVar12 = lex_buffer_refill();
  if ((uVar12 & 0xffffff8f) == 0) {
    if ((uVar12 & 0x20) != 0) {
      g_input_ptr = g_input_ptr + 1;
    }
    goto LAB_104025c0;
  }
  cVar3 = g_char_class[*g_input_ptr];
  goto joined_r0x104025b1;
switchD_10402595_caseD_0:
  uVar12 = lex_buffer_refill();
  if ((uVar12 & 0xffffff8f) == 0) {
    if ((uVar12 & 0x20) != 0) {
      g_input_ptr = g_input_ptr + 1;
    }
    goto switchD_10402595_caseD_1;
  }
  bVar9 = *g_input_ptr;
  g_input_ptr = g_input_ptr + 1;
  bVar9 = g_char_class[bVar9];
  goto joined_r0x1040258b;
joined_r0x10402621:
  if (cVar3 != '\0') {
    if (cVar3 == '\r') {
      return &g_token_add_assign->code;
    }
    if (cVar3 == '\x11') {
      return &g_token_plus_plus->code;
    }
LAB_10402631:
    g_input_ptr = g_input_ptr + -1;
    return g_token_plus;
  }
  uVar12 = lex_buffer_refill();
  if ((uVar12 & 0xffffff8f) == 0) {
    if ((uVar12 & 0x20) != 0) {
      g_input_ptr = g_input_ptr + 1;
    }
    goto LAB_10402631;
  }
  bVar9 = *g_input_ptr;
  g_input_ptr = g_input_ptr + 1;
  cVar3 = g_char_class[bVar9];
  goto joined_r0x10402621;
joined_r0x1040267a:
  if (cVar3 != '\0') {
    if (cVar3 == '\r') {
      return &g_token_and_assign->code;
    }
    if (cVar3 == '\x10') {
      return &g_token_logical_and->code;
    }
LAB_10402686:
    g_input_ptr = g_input_ptr + -1;
    return &g_token_ampersand->code;
  }
  uVar12 = lex_buffer_refill();
  if ((uVar12 & 0xffffff8f) == 0) {
    if ((uVar12 & 0x20) != 0) {
      g_input_ptr = g_input_ptr + 1;
    }
    goto LAB_10402686;
  }
  bVar9 = *g_input_ptr;
  g_input_ptr = g_input_ptr + 1;
  cVar3 = g_char_class[bVar9];
  goto joined_r0x1040267a;
joined_r0x1045a3e7:
  if (cVar3 != '\0') {
    if (cVar3 == '\r') {
      return &g_token_xor_assign->code;
    }
LAB_1045a42e:
    g_input_ptr = g_input_ptr + -1;
    return &g_token_caret->code;
  }
  uVar12 = lex_buffer_refill();
  if ((uVar12 & 0xffffff8f) == 0) {
    if ((uVar12 & 0x20) != 0) {
      g_input_ptr = g_input_ptr + 1;
    }
    goto LAB_1045a42e;
  }
  bVar9 = *g_input_ptr;
  g_input_ptr = g_input_ptr + 1;
  cVar3 = g_char_class[bVar9];
  goto joined_r0x1045a3e7;
joined_r0x104027e2:
  if (cVar3 != '\0') {
    if (cVar3 == '\r') {
      return &g_token_equal_equal->code;
    }
LAB_104027ed:
    g_input_ptr = g_input_ptr + -1;
    return g_token_assign;
  }
  uVar12 = lex_buffer_refill();
  if ((uVar12 & 0xffffff8f) == 0) {
    if ((uVar12 & 0x20) != 0) {
      g_input_ptr = g_input_ptr + 1;
    }
    goto LAB_104027ed;
  }
  bVar9 = *g_input_ptr;
  g_input_ptr = g_input_ptr + 1;
  cVar3 = g_char_class[bVar9];
  goto joined_r0x104027e2;
joined_r0x1040279b:
  if (cVar3 != '\0') {
    if (cVar3 == '\r') {
      return &g_token_mod_assign->code;
    }
LAB_104027a6:
    g_input_ptr = g_input_ptr + -1;
    return &g_token_percent->code;
  }
  uVar12 = lex_buffer_refill();
  if ((uVar12 & 0xffffff8f) == 0) {
    if ((uVar12 & 0x20) != 0) {
      g_input_ptr = g_input_ptr + 1;
    }
    goto LAB_104027a6;
  }
  bVar9 = *g_input_ptr;
  g_input_ptr = g_input_ptr + 1;
  cVar3 = g_char_class[bVar9];
  goto joined_r0x1040279b;
joined_r0x10402829:
  if (cVar3 != '\0') {
    if (cVar3 == '\r') {
      return &g_token_not_equal->code;
    }
LAB_10402834:
    g_input_ptr = g_input_ptr + -1;
    return &g_token_exclaim->code;
  }
  uVar12 = lex_buffer_refill();
  if ((uVar12 & 0xffffff8f) == 0) {
    if ((uVar12 & 0x20) != 0) {
      g_input_ptr = g_input_ptr + 1;
    }
    goto LAB_10402834;
  }
  bVar9 = *g_input_ptr;
  g_input_ptr = g_input_ptr + 1;
  cVar3 = g_char_class[bVar9];
  goto joined_r0x10402829;
joined_r0x1040228b:
  if (0x1d < bVar9) {
switchD_10402295_caseD_1:
    g_input_ptr = g_input_ptr + -1;
    return g_token_dot;
  }
  switch((&switchD_10402295::switchdataD_104061d4)[bVar9]) {
  case 0:
    uVar12 = lex_buffer_refill();
    if ((uVar12 & 0xffffff8f) == 0) {
      if ((uVar12 & 0x20) != 0) {
        g_input_ptr = g_input_ptr + 1;
      }
      goto switchD_10402295_caseD_1;
    }
    bVar9 = *g_input_ptr;
    g_input_ptr = g_input_ptr + 1;
    bVar9 = g_char_class[bVar9];
    break;
  default:
    goto switchD_10402295_caseD_1;
  case 8:
    g_input_ptr = g_input_ptr;
    return &g_token_dot_star->code;
  case 9:
    bVar9 = *g_input_ptr;
    g_input_ptr = g_input_ptr + 1;
    if (g_char_class[bVar9] == '\0') {
      bVar9 = lex_next_significant_char(bVar9);
    }
    if (bVar9 == 0x2e) {
      if (g_token_arena_index == 0) {
        if (g_pool_default_left < 0x30) {
          pool_reserve((c1xx_pool *)&g_pool_default,0x30);
        }
        g_pool_default_left = g_pool_default_left - 0x30;
        pcVar11 = g_pool_default;
        g_pool_default = g_pool_default + 0x30;
      }
      else {
        pcVar10 = g_arenas + g_token_arena_index;
        pcVar11 = pcVar10->cur;
        pcVar6 = g_arenas[g_token_arena_index].end;
        pcVar10->cur = pcVar11 + 0x30;
        if (pcVar6 < pcVar11 + 0x30) {
          arena_grow(pcVar10);
        }
      }
      if (pcVar11 == (c1_u8 *)0x0) {
        return (byte *)0x0;
      }
      *pcVar11 = 'j';
      puVar15 = &g_yylval;
      puVar17 = (uint *)(pcVar11 + 8);
      for (iVar13 = 10; iVar13 != 0; iVar13 = iVar13 + -1) {
        *puVar17 = *puVar15;
        puVar15 = puVar15 + 1;
        puVar17 = puVar17 + 1;
      }
      return pcVar11;
    }
    pbVar14 = g_input_ptr + -2;
    g_input_ptr = g_input_ptr + -1;
    *pbVar14 = 0x2e;
    goto switchD_10402295_caseD_1;
  case 0x1d:
    g_number_digit_buffer[0] = '.';
    g_number_digit_buffer[1] = g_input_ptr[-1];
    if (((g_compile_flags_c4 & 0x4000) == 0) &&
       ((g_opt_E_preprocess != 0 || ((g_compile_flags_c4 & 0x800000) != 0)))) {
      uVar12 = lex_scan_pp_number_text(g_number_digit_buffer + 2);
      if (g_opt_E_preprocess != 0) {
        fwrite(g_number_digit_buffer,uVar12 + 1,1,g_pp_output_stream);
      }
      return &g_token_internal->code;
    }
    pcVar11 = lex_scan_floating_literal(g_number_digit_buffer + 2);
    return pcVar11;
  }
  goto joined_r0x1040228b;
joined_r0x10402345:
  if (cVar3 != '\0') {
    if (cVar3 == '\x03') {
      if (g_opt_E_preprocess == 0) {
        diag_warning(1,0x8a);
      }
    }
    else if (cVar3 == '\r') {
      return &g_token_mul_assign->code;
    }
LAB_10402355:
    g_input_ptr = g_input_ptr + -1;
    return g_token_star;
  }
  uVar12 = lex_buffer_refill();
  if ((uVar12 & 0xffffff8f) == 0) {
    if ((uVar12 & 0x20) != 0) {
      g_input_ptr = g_input_ptr + 1;
    }
    goto LAB_10402355;
  }
  bVar9 = *g_input_ptr;
  g_input_ptr = g_input_ptr + 1;
  cVar3 = g_char_class[bVar9];
  goto joined_r0x10402345;
joined_r0x10402216:
  if (cVar3 != '\0') {
    if (cVar3 == '\r') {
      return &g_token_div_assign->code;
    }
LAB_10402221:
    g_input_ptr = g_input_ptr + -1;
    return &g_token_slash->code;
  }
  uVar12 = lex_buffer_refill();
  if ((uVar12 & 0xffffff8f) == 0) {
    if ((uVar12 & 0x20) != 0) {
      g_input_ptr = g_input_ptr + 1;
    }
    goto LAB_10402221;
  }
  bVar9 = *g_input_ptr;
  g_input_ptr = g_input_ptr + 1;
  cVar3 = g_char_class[bVar9];
  goto joined_r0x10402216;
switchD_10402595_caseD_1:
  g_input_ptr = g_input_ptr + -1;
  return &g_token_minus->code;
  while (uVar12 = lex_buffer_refill(), (uVar12 & 0xffffff8f) != 0) {
switchD_10401d49_caseD_f:
    bVar9 = *g_input_ptr;
    g_input_ptr = g_input_ptr + 1;
    cVar3 = g_char_class[bVar9];
    if (cVar3 != '\0') {
      if (cVar3 == '\r') {
        return &g_token_or_assign->code;
      }
      if (cVar3 == '\x0f') {
        return &g_token_logical_or->code;
      }
      goto LAB_1040271c;
    }
  }
  if ((uVar12 & 0x20) != 0) {
    g_input_ptr = g_input_ptr + 1;
  }
LAB_1040271c:
  g_input_ptr = g_input_ptr + -1;
  return &g_token_bar->code;
}

