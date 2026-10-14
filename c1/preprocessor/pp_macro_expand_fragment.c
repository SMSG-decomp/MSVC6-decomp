int __cdecl pp_macro_expand_fragment(uchar *text_cursor,int expanded)

{
  c1_u8 cVar1;
  fe_macro *macro;
  bool bVar2;
  char cVar3;
  byte bVar4;
  uchar *text;
  int iVar5;
  int iVar6;
  uint uVar7;
  char *pcVar8;
  byte *pbVar9;
  byte *pbVar10;
  char *pcVar11;
  char *pcVar12;
  uint in_stack_0000001c;
  
  if (g_last_name == g_name_defined) {
    pp_if_parse_defined((int)g_last_name);
    text_cursor = g_macro_text_cursor;
  }
LAB_106058f2:
  do {
    if (g_macro_rescan_level == 0) {
      return expanded;
    }
    if (g_macro_text_buffer_limit <= text_cursor) {
      pp_define_check_size
                ((uint)text_cursor,(int)g_macro_text_buffer,(int *)&g_macro_text_buffer_limit);
      text_cursor = g_macro_text_cursor;
    }
    bVar4 = *g_input_ptr;
    in_stack_0000001c = CONCAT31(in_stack_0000001c._1_3_,bVar4);
    pbVar10 = g_input_ptr + 1;
    switch(g_char_class[bVar4]) {
    case '\0':
      g_input_ptr = pbVar10;
      uVar7 = lex_buffer_refill();
      text_cursor = g_macro_text_cursor;
      pbVar10 = g_input_ptr;
      if ((uVar7 & 0x50) != 0) goto switchD_1060593e_caseD_2;
      break;
    case '\x01':
      pbVar9 = g_input_ptr + 2;
      cVar1 = g_char_class[*pbVar10];
      while (cVar1 == '\x01') {
        bVar4 = *pbVar9;
        pbVar9 = pbVar9 + 1;
        cVar1 = g_char_class[bVar4];
      }
      g_input_ptr = pbVar9 + -1;
      *text_cursor = 0x20;
      text_cursor = g_macro_text_cursor + 1;
      g_macro_text_cursor = text_cursor;
      break;
    default:
switchD_1060593e_caseD_2:
      g_input_ptr = pbVar10;
      *text_cursor = bVar4;
      text_cursor = g_macro_text_cursor + 1;
      g_macro_text_cursor = text_cursor;
      break;
    case '\x06':
    case '\a':
    case '&':
      g_macro_expansion_text_start = text_cursor;
      g_input_ptr = pbVar10;
      cVar3 = pp_macro_scan_identifier(in_stack_0000001c);
      if ((cVar3 == '\0') || (macro = g_last_name->macro, macro == (fe_macro *)0x0))
      goto LAB_1060571f;
      cVar3 = pp_macro_is_being_expanded(macro);
      if (cVar3 != '\0') {
        iVar5 = -1;
        pcVar11 = g_last_name->text;
        do {
          if (iVar5 == 0) break;
          iVar5 = iVar5 + -1;
          cVar3 = *pcVar11;
          pcVar11 = pcVar11 + 1;
        } while (cVar3 != '\0');
        *g_macro_text_cursor = '\x04';
        g_macro_text_cursor = g_macro_text_cursor + 1;
        *g_macro_text_cursor = ~(byte)iVar5 - 1;
        g_macro_text_cursor = g_macro_text_cursor + 1;
        goto LAB_1060571f;
      }
      g_macro_arg_start = g_macro_arg_cursor;
      g_macro_arg_count = 0;
      cVar3 = macro->def->kind;
      iVar5 = (int)cVar3;
      if (cVar3 < -3) {
        if (g_browse_file != (char *)0x0) {
          (*g_il_emitter->vtbl->reference_macro)(macro);
        }
        pp_macro_check_nesting(macro);
        g_macro_expansion_frames[g_macro_expansion_depth].active = 1;
        switch(iVar5) {
        case -9:
          iVar5 = (*g_idb->vtbl->idb_note_predefined_macro)(g_idb);
          if (iVar5 == 0) {
            diag_fatal(0x49,".\\p0macros.c",0x3e6);
          }
          if (g_opt_Brepro == 0) {
            uVar7 = pp_current_file_mtime();
            pcVar8 = pp_format_date_time_strings(uVar7);
            pcVar11 = pcVar8;
            pcVar12 = g_pp_timestamp_text;
            for (iVar5 = 6; iVar5 != 0; iVar5 = iVar5 + -1) {
              *(undefined4 *)pcVar12 = *(undefined4 *)pcVar11;
              pcVar11 = pcVar11 + 4;
              pcVar12 = pcVar12 + 4;
            }
            *pcVar12 = *pcVar11;
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
          iVar5 = (*g_idb->vtbl->idb_note_predefined_macro)(g_idb);
          pbVar10 = (byte *)g_pp_time_text;
          if (iVar5 == 0) {
            diag_fatal(0x49,".\\p0macros.c",0x3d4);
          }
          goto LAB_10629661;
        case -6:
          iVar5 = (*g_idb->vtbl->idb_note_predefined_macro)(g_idb);
          pbVar10 = (byte *)g_pp_date_text;
          if (iVar5 == 0) {
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
        iVar5 = pp_macro_expansion_end();
        text_cursor = g_macro_text_cursor;
joined_r0x106056e2:
        g_macro_text_cursor = text_cursor;
        if (iVar5 != 0) {
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
      }
      else if (iVar5 == 0) {
        expanded = 1;
        if (g_browse_file != (char *)0x0) {
          (*g_il_emitter->vtbl->reference_macro)(macro);
        }
        if (macro->def->text[0] == '\0') {
          g_macro_text_cursor = g_macro_expansion_text_start;
          text_cursor = g_macro_expansion_text_start;
        }
        else {
          pp_macro_check_nesting(macro);
          pp_macro_begin_replacement();
          text_cursor = g_macro_text_cursor;
        }
      }
      else {
        if (iVar5 == -1) {
          iVar5 = 0;
        }
        iVar6 = pp_skip_blanks_in_macro_text();
        text_cursor = g_macro_text_cursor;
        pbVar10 = g_input_ptr;
        while (g_macro_text_cursor = text_cursor, g_input_ptr = pbVar10, iVar6 != 0) {
          if (*pbVar10 != 0x2f) {
LAB_1060579c:
            if (*g_input_ptr != 0x28) {
              pp_macro_check_nesting(macro);
              pp_macro_begin_replacement();
              g_macro_expansion_text_start = g_macro_text_cursor;
              pp_macro_text_append_string((uchar *)macro->name->text);
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
              iVar5 = pp_macro_expansion_end();
              text_cursor = g_macro_text_cursor;
              goto joined_r0x106056e2;
            }
            g_input_ptr = g_input_ptr + 1;
            g_compile_flags_c4 = g_compile_flags_c4 | 0x1000;
            expanded = 1;
            pp_macro_collect_argument_text(macro,iVar5);
            g_compile_flags_c4 = g_compile_flags_c4 & 0xffffefff;
            text_cursor = g_macro_text_cursor;
            if (g_browse_file != (char *)0x0) {
              (*g_il_emitter->vtbl->reference_macro)(macro);
              text_cursor = g_macro_text_cursor;
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
          text_cursor = g_macro_text_cursor;
          pbVar10 = g_input_ptr;
        }
      }
      break;
    case '\t':
      if (g_char_class[*pbVar10] == '\x1d') {
        bVar4 = 0x2e;
        goto switchD_1060593e_caseD_1d;
      }
      g_input_ptr = pbVar10;
      *text_cursor = 0x2e;
      text_cursor = g_macro_text_cursor + 1;
      g_macro_text_cursor = text_cursor;
      break;
    case '\x15':
    case '\x16':
      g_input_ptr = pbVar10;
      text_cursor = pp_copy_quoted_text(text_cursor,(uint *)&g_macro_text_buffer_limit,bVar4);
      g_macro_text_cursor = text_cursor;
      break;
    case '\x1d':
switchD_1060593e_caseD_1d:
      do {
        g_input_ptr = pbVar10;
        *text_cursor = bVar4;
        g_macro_text_cursor = g_macro_text_cursor + 1;
        if (g_macro_text_buffer_limit <= g_macro_text_cursor) {
          pp_define_check_size
                    ((uint)g_macro_text_cursor,(int)g_macro_text_buffer,
                     (int *)&g_macro_text_buffer_limit);
        }
        bVar4 = *g_input_ptr;
        pbVar10 = g_input_ptr + 1;
        in_stack_0000001c = CONCAT31(in_stack_0000001c._1_3_,bVar4);
        text_cursor = g_macro_text_cursor;
      } while (((g_char_flags[bVar4] & 4) != 0) ||
              (((bVar4 == 0x2b || (bVar4 == 0x2d)) &&
               ((*g_macro_text_cursor == 'e' || (*g_macro_text_cursor == 'E'))))));
      break;
    case '\'':
      g_input_ptr = pbVar10;
      pbVar10 = (byte *)pp_macro_argument_text();
      pp_macro_stringize(0x22,pbVar10);
      text_cursor = g_macro_text_cursor;
      break;
    case '(':
      g_input_ptr = pbVar10;
      pbVar10 = (byte *)pp_macro_argument_text();
      pp_macro_stringize(0x27,pbVar10);
      text_cursor = g_macro_text_cursor;
    }
  } while( true );
LAB_1060571f:
  text_cursor = g_macro_text_cursor;
  if ((g_compile_flags_c4 & 0x4000) != 0) {
    iVar5 = pp_macro_expand_fragment(g_macro_text_cursor,expanded);
    return iVar5;
  }
  goto LAB_106058f2;
}

