int __cdecl pp_macro_expand(fe_macro *macro)

{
  c1_u8 cVar1;
  bool bVar2;
  char cVar3;
  byte bVar4;
  fe_line_map_row *pfVar5;
  uchar *text;
  int iVar6;
  uint uVar7;
  char *pcVar8;
  byte *pbVar9;
  byte *pbVar10;
  int iVar11;
  fe_macro *macro_00;
  char *pcVar12;
  int iVar13;
  char *pcVar14;
  
  iVar11 = 0;
  cVar3 = pp_macro_is_being_expanded(macro);
  if (cVar3 != '\0') {
    return 0;
  }
  g_macro_expansion_text_start = g_macro_text_cursor;
  g_macro_rescan_level = 0;
  if (g_line_map_cached_row.position == g_token_position) {
    pfVar5 = &g_line_map_cached_row;
  }
  else {
    pfVar5 = pp_line_map_find_entry(&g_line_map,g_token_position);
  }
  g_macro_invocation_line = (pfVar5->line - pfVar5->position) + g_token_position;
  macro_00 = macro;
LAB_10605744:
  g_macro_arg_start = g_macro_arg_cursor;
  g_macro_arg_count = 0;
  cVar3 = macro_00->def->kind;
  iVar13 = (int)cVar3;
  if (-4 < cVar3) {
    if (iVar13 == 0) {
      iVar11 = 1;
      if (g_browse_file != (char *)0x0) {
        (*g_il_emitter->vtbl->reference_macro)(macro_00);
      }
      if (macro_00->def->text[0] == '\0') {
        g_macro_text_cursor = g_macro_expansion_text_start;
      }
      else {
        pp_macro_check_nesting(macro_00);
        pp_macro_begin_replacement();
      }
    }
    else {
      if (iVar13 == -1) {
        iVar13 = 0;
      }
      iVar6 = pp_skip_blanks_in_macro_text();
      pbVar10 = g_input_ptr;
      while (g_input_ptr = pbVar10, iVar6 != 0) {
        if (*pbVar10 != 0x2f) {
LAB_1060579c:
          if (*g_input_ptr != 0x28) {
            pp_macro_check_nesting(macro_00);
            pp_macro_begin_replacement();
            g_macro_expansion_text_start = g_macro_text_cursor;
            pp_macro_text_append_string((uchar *)macro_00->name->text);
            if ((g_compile_flags_c4 & 0x400000) == 0) {
              if (g_macro_blanks_skipped != 0) {
                pp_macro_text_append_string((uchar *)(g_tree_op_to_il_op + 0xf9));
              }
            }
            else {
              g_compile_flags_c4 = g_compile_flags_c4 & 0xffbfffff;
              pp_macro_text_append_string((uchar *)"\n");
              g_lex_position = g_lex_position + -1;
              g_token_position = g_lex_position;
            }
            g_input_ptr = g_macro_expansion_text_start;
            iVar13 = pp_macro_expansion_end();
            goto joined_r0x106056e2;
          }
          g_input_ptr = g_input_ptr + 1;
          g_compile_flags_c4 = g_compile_flags_c4 | 0x1000;
          iVar11 = 1;
          pp_macro_collect_argument_text(macro_00,iVar13);
          g_compile_flags_c4 = g_compile_flags_c4 & 0xffffefff;
          if (g_browse_file != (char *)0x0) {
            (*g_il_emitter->vtbl->reference_macro)(macro_00);
          }
          break;
        }
        g_input_ptr = pbVar10 + 1;
        if ((g_ms_extensions == '\0') && (g_pch_option_block == 0)) {
          bVar4 = lex_get_char();
          if (bVar4 == 0x2f) {
            bVar4 = lex_get_char();
            if (bVar4 != 0x2a) {
              g_input_ptr = g_input_ptr + -1;
              diag_warning(4,1);
              g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
              pp_output_copy_comment();
              goto LAB_106297d5;
            }
            diag_warning(4,0xb3);
            if ((g_opt_C_keep_comments == 0) || ((g_compile_flags_c4 & 0x8000) != 0)) {
              g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
              pp_skip_block_comment();
              g_compile_flags_c4 = g_compile_flags_c4 & 0xfffff7ff;
              bVar2 = false;
            }
            else {
              g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
              pp_output_skip_comment();
              g_compile_flags_c4 = g_compile_flags_c4 & 0xfffff7ff;
              bVar2 = false;
            }
          }
          else {
            g_input_ptr = g_input_ptr + -1;
            bVar4 = lex_get_char();
            if (bVar4 == 0x2a) {
              g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
              pp_block_comment_dispatch();
              goto LAB_106297d5;
            }
            g_input_ptr = g_input_ptr + -1;
            bVar2 = false;
          }
        }
        else {
          bVar4 = *g_input_ptr;
          g_input_ptr = pbVar10 + 2;
          if (g_char_class[bVar4] == '\0') {
            bVar4 = lex_next_significant_char(bVar4);
          }
          if (bVar4 == 0x2f) {
            g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
            pp_output_copy_comment();
          }
          else {
            bVar4 = g_input_ptr[-1];
            if (g_char_class[bVar4] == '\0') {
              bVar4 = lex_next_significant_char(bVar4);
            }
            if (bVar4 != 0x2a) {
              g_input_ptr = g_input_ptr + -1;
              bVar2 = false;
              goto LAB_10629787;
            }
            if ((g_opt_C_keep_comments == 0) || ((g_compile_flags_c4 & 0x8000) != 0)) {
              g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
              pp_skip_block_comment();
            }
            else {
              g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
              pp_output_skip_comment();
            }
          }
LAB_106297d5:
          g_compile_flags_c4 = g_compile_flags_c4 & 0xfffff7ff;
          bVar2 = true;
        }
LAB_10629787:
        if (!bVar2) {
          g_input_ptr = g_input_ptr + -1;
          goto LAB_1060579c;
        }
        iVar6 = pp_skip_blanks_in_macro_text();
        pbVar10 = g_input_ptr;
      }
    }
    goto LAB_106058f2;
  }
  if (g_browse_file != (char *)0x0) {
    (*g_il_emitter->vtbl->reference_macro)(macro_00);
  }
  pp_macro_check_nesting(macro_00);
  g_macro_expansion_frames[g_macro_expansion_depth].active = 1;
  switch(iVar13) {
  case -9:
    iVar13 = (*g_idb->vtbl->idb_note_predefined_macro)(g_idb);
    if (iVar13 == 0) {
      diag_fatal(0x49,".\\p0macros.c",0x3e6);
    }
    if (g_opt_Brepro == 0) {
      uVar7 = pp_current_file_mtime();
      pcVar8 = pp_format_date_time_strings(uVar7);
      pcVar12 = pcVar8;
      pcVar14 = g_pp_timestamp_text;
      for (iVar13 = 6; iVar13 != 0; iVar13 = iVar13 + -1) {
        *(undefined4 *)pcVar14 = *(undefined4 *)pcVar12;
        pcVar12 = pcVar12 + 4;
        pcVar14 = pcVar14 + 4;
      }
      *pcVar14 = *pcVar12;
      g_pp_timestamp_text._11_4_ = *(undefined4 *)(pcVar8 + 0x10);
      g_pp_timestamp_text._15_4_ = *(undefined4 *)(pcVar8 + 0x14);
      g_pp_timestamp_text._19_4_ = *(undefined4 *)(pcVar8 + 10);
      g_pp_timestamp_text[0x17] = pcVar8[0xe];
      g_pp_timestamp_text[0x18] = '\0';
    }
    else {
      g_pp_timestamp_text[0] = '1';
      g_pp_timestamp_text[1] = '\0';
    }
    pbVar10 = (byte *)g_pp_timestamp_text;
    goto LAB_10629661;
  case -8:
    pp_macro_text_append_string("1");
    break;
  case -7:
    iVar13 = (*g_idb->vtbl->idb_note_predefined_macro)(g_idb);
    pbVar10 = (byte *)g_pp_time_text;
    if (iVar13 == 0) {
      diag_fatal(0x49,".\\p0macros.c",0x3d4);
    }
    goto LAB_10629661;
  case -6:
    iVar13 = (*g_idb->vtbl->idb_note_predefined_macro)(g_idb);
    pbVar10 = (byte *)g_pp_date_text;
    if (iVar13 == 0) {
      diag_fatal(0x49,".\\p0macros.c",0x3cf);
    }
LAB_10629661:
    pp_macro_stringize(0x22,pbVar10);
    break;
  case -5:
    if (g_opt_Brepro == 0) {
      pbVar10 = (byte *)pp_position_file_name(&g_token_position);
      g_macro_text_cursor = pp_quote_file_name(g_macro_text_cursor,pbVar10);
    }
    else {
      g_macro_text_cursor = pp_quote_file_name(g_macro_text_cursor,(byte *)"Brepro.c");
    }
    break;
  case -4:
    text = (uchar *)iccline_check_incremental();
    pp_macro_text_append_string(text);
  }
  iVar13 = pp_macro_expansion_end();
joined_r0x106056e2:
  if (iVar13 != 0) {
    g_pp_timestamp_text[0xb] = (char)g_pp_timestamp_text._11_4_;
    g_pp_timestamp_text[0xc] = SUB41(g_pp_timestamp_text._11_4_,1);
    g_pp_timestamp_text[0xd] = SUB41(g_pp_timestamp_text._11_4_,2);
    g_pp_timestamp_text[0xe] = SUB41(g_pp_timestamp_text._11_4_,3);
    g_pp_timestamp_text[0xf] = (char)g_pp_timestamp_text._15_4_;
    g_pp_timestamp_text[0x10] = SUB41(g_pp_timestamp_text._15_4_,1);
    g_pp_timestamp_text[0x11] = SUB41(g_pp_timestamp_text._15_4_,2);
    g_pp_timestamp_text[0x12] = SUB41(g_pp_timestamp_text._15_4_,3);
    g_pp_timestamp_text[0x13] = (char)g_pp_timestamp_text._19_4_;
    g_pp_timestamp_text[0x14] = SUB41(g_pp_timestamp_text._19_4_,1);
    g_pp_timestamp_text[0x15] = SUB41(g_pp_timestamp_text._19_4_,2);
    g_pp_timestamp_text[0x16] = SUB41(g_pp_timestamp_text._19_4_,3);
    return 1;
  }
LAB_106058f2:
  if (g_macro_rescan_level == 0) {
    return iVar11;
  }
  if (g_macro_text_buffer_limit <= g_macro_text_cursor) {
    pp_define_check_size
              ((uint)g_macro_text_cursor,(int)g_macro_text_buffer,(int *)&g_macro_text_buffer_limit)
    ;
  }
  bVar4 = *g_input_ptr;
  macro = (fe_macro *)CONCAT31(macro._1_3_,bVar4);
  pbVar10 = g_input_ptr + 1;
  switch(g_char_class[bVar4]) {
  case '\0':
    g_input_ptr = pbVar10;
    uVar7 = lex_buffer_refill();
    pbVar10 = g_input_ptr;
    if ((uVar7 & 0x50) == 0) goto LAB_106058f2;
  default:
    g_input_ptr = pbVar10;
    *g_macro_text_cursor = bVar4;
    g_macro_text_cursor = g_macro_text_cursor + 1;
    goto LAB_106058f2;
  case '\x01':
    pbVar9 = g_input_ptr + 2;
    cVar1 = g_char_class[*pbVar10];
    while (cVar1 == '\x01') {
      bVar4 = *pbVar9;
      pbVar9 = pbVar9 + 1;
      cVar1 = g_char_class[bVar4];
    }
    g_input_ptr = pbVar9 + -1;
    *g_macro_text_cursor = ' ';
    g_macro_text_cursor = g_macro_text_cursor + 1;
    goto LAB_106058f2;
  case '\x06':
  case '\a':
  case '&':
    goto switchD_1060593e_caseD_6;
  case '\t':
    if (g_char_class[*pbVar10] == '\x1d') {
      bVar4 = 0x2e;
      goto switchD_1060593e_caseD_1d;
    }
    g_input_ptr = pbVar10;
    *g_macro_text_cursor = '.';
    g_macro_text_cursor = g_macro_text_cursor + 1;
    goto LAB_106058f2;
  case '\x15':
  case '\x16':
    g_input_ptr = pbVar10;
    g_macro_text_cursor =
         pp_copy_quoted_text(g_macro_text_cursor,(uint *)&g_macro_text_buffer_limit,bVar4);
    goto LAB_106058f2;
  case '\x1d':
switchD_1060593e_caseD_1d:
    do {
      g_input_ptr = pbVar10;
      *g_macro_text_cursor = bVar4;
      g_macro_text_cursor = g_macro_text_cursor + 1;
      if (g_macro_text_buffer_limit <= g_macro_text_cursor) {
        pp_define_check_size
                  ((uint)g_macro_text_cursor,(int)g_macro_text_buffer,
                   (int *)&g_macro_text_buffer_limit);
      }
      bVar4 = *g_input_ptr;
      pbVar10 = g_input_ptr + 1;
      macro = (fe_macro *)CONCAT31(macro._1_3_,bVar4);
    } while (((g_char_flags[bVar4] & 4) != 0) ||
            (((bVar4 == 0x2b || (bVar4 == 0x2d)) &&
             ((*g_macro_text_cursor == 'e' || (*g_macro_text_cursor == 'E'))))));
    goto LAB_106058f2;
  case '\'':
    g_input_ptr = pbVar10;
    pbVar10 = (byte *)pp_macro_argument_text();
    pp_macro_stringize(0x22,pbVar10);
    goto LAB_106058f2;
  case '(':
    break;
  }
  g_input_ptr = pbVar10;
  pbVar10 = (byte *)pp_macro_argument_text();
  pp_macro_stringize(0x27,pbVar10);
  goto LAB_106058f2;
switchD_1060593e_caseD_6:
  g_macro_expansion_text_start = g_macro_text_cursor;
  g_input_ptr = pbVar10;
  cVar3 = pp_macro_scan_identifier((uint)macro);
  if ((cVar3 != '\0') && (macro_00 = g_last_name->macro, macro_00 != (fe_macro *)0x0)) {
    cVar3 = pp_macro_is_being_expanded(macro_00);
    if (cVar3 == '\0') goto LAB_10605744;
    iVar13 = -1;
    pcVar12 = g_last_name->text;
    do {
      if (iVar13 == 0) break;
      iVar13 = iVar13 + -1;
      cVar3 = *pcVar12;
      pcVar12 = pcVar12 + 1;
    } while (cVar3 != '\0');
    *g_macro_text_cursor = '\x04';
    g_macro_text_cursor = g_macro_text_cursor + 1;
    *g_macro_text_cursor = ~(byte)iVar13 - 1;
    g_macro_text_cursor = g_macro_text_cursor + 1;
  }
  if ((g_compile_flags_c4 & 0x4000) != 0) {
    iVar11 = pp_macro_expand_fragment(g_macro_text_cursor,iVar11);
    return iVar11;
  }
  goto LAB_106058f2;
}

