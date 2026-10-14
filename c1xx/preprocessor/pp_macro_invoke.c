int __cdecl pp_macro_invoke(fe_macro *macro)

{
  c1_u8 cVar1;
  char cVar2;
  byte bVar3;
  c1_line_map_row *pcVar4;
  int iVar5;
  uint uVar6;
  uchar *text;
  char *pcVar7;
  byte *pbVar8;
  byte *pbVar9;
  int iVar10;
  fe_macro *macro_00;
  char *pcVar11;
  int iVar12;
  char *pcVar13;
  uint slash_next;
  uint after_slash;
  
  iVar10 = 0;
  cVar2 = pp_macro_is_being_expanded(macro);
  if (cVar2 != '\0') {
    return 0;
  }
  g_macro_expansion_text_start = g_macro_text_cursor;
  g_macro_rescan_level = 0;
  if (g_line_map_cached_row.position == g_token_position) {
    pcVar4 = &g_line_map_cached_row;
  }
  else {
    pcVar4 = pp_line_map_find_entry(&g_line_map,g_token_position);
  }
  g_macro_invocation_line = (pcVar4->line - pcVar4->position) + g_token_position;
  macro_00 = macro;
  do {
    g_macro_arg_count = 0;
    g_macro_arg_start = g_macro_arg_cursor;
    cVar2 = macro_00->def->kind;
    iVar12 = (int)cVar2;
    if (-4 < cVar2) {
      if (iVar12 != 0) {
        if (iVar12 == -1) {
          iVar12 = 0;
        }
        iVar5 = pp_skip_blanks_in_macro_text();
        if (iVar5 == 0) goto LAB_1040a014;
        while (*g_input_ptr == 0x2f) {
          bVar3 = g_input_ptr[1];
          slash_next = CONCAT31(slash_next._1_3_,bVar3);
          g_input_ptr = g_input_ptr + 2;
          if (g_char_class[bVar3] == '\0') {
            bVar3 = lex_next_significant_char(bVar3);
          }
          if (bVar3 == 0x2f) {
            g_compile_flags_c4 = g_compile_flags_c4 | 0x800;
            pp_output_copy_comment();
          }
          else {
            bVar3 = g_input_ptr[-1];
            after_slash = CONCAT31(after_slash._1_3_,bVar3);
            if (g_char_class[bVar3] == '\0') {
              bVar3 = lex_next_significant_char(bVar3);
            }
            if (bVar3 != 0x2a) {
              g_input_ptr = g_input_ptr + -2;
              break;
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
          g_compile_flags_c4 = g_compile_flags_c4 & 0xfffff7ff;
          iVar5 = pp_skip_blanks_in_macro_text();
          if (iVar5 == 0) {
            iVar10 = pp_macro_expand(iVar10,slash_next,after_slash,(uint)macro);
            return iVar10;
          }
        }
        if (*g_input_ptr == 0x28) {
          g_input_ptr = g_input_ptr + 1;
          g_compile_flags_c4 = g_compile_flags_c4 | 0x1000;
          iVar10 = 1;
          pp_macro_collect_arguments_text(macro_00,iVar12);
          g_compile_flags_c4 = g_compile_flags_c4 & 0xffffefff;
          if (g_browse_file != (char *)0x0) {
            (*g_il_emitter->vtbl->reference_macro)((int)macro_00);
            iVar10 = pp_macro_expand(1,slash_next,after_slash,(uint)macro);
            return iVar10;
          }
          goto LAB_1040a014;
        }
        pp_macro_check_nesting(macro_00);
        pp_macro_begin_replacement();
        g_macro_expansion_text_start = g_macro_text_cursor;
        pp_macro_text_append_string((uchar *)macro_00->name->text);
        if ((g_compile_flags_c4 & 0x400000) == 0) {
          if (g_macro_blanks_skipped != 0) {
            pp_macro_text_append_string(" ");
          }
        }
        else {
          g_compile_flags_c4 = g_compile_flags_c4 & 0xffbfffff;
          pp_macro_text_append_string((uchar *)"\n");
          g_lex_position = g_lex_position + -1;
          g_token_position = g_lex_position;
        }
        g_input_ptr = g_macro_expansion_text_start;
        iVar12 = pp_macro_expansion_end();
        goto joined_r0x10409ebc;
      }
      iVar10 = 1;
      if (g_browse_file != (char *)0x0) {
        (*g_il_emitter->vtbl->reference_macro)((int)macro_00);
      }
      if (macro_00->def->text[0] != '\0') {
        pp_macro_check_nesting(macro_00);
        pp_macro_begin_replacement();
        iVar10 = pp_macro_expand(1,slash_next,after_slash,(uint)macro);
        return iVar10;
      }
      g_macro_text_cursor = g_macro_expansion_text_start;
      goto LAB_1040a014;
    }
    if (g_browse_file != (char *)0x0) {
      (*g_il_emitter->vtbl->reference_macro)((int)macro_00);
    }
    pp_macro_check_nesting(macro_00);
    g_macro_expansion_frames[g_macro_expansion_depth].active = 1;
    switch(iVar12) {
    case -0xb:
    case -10:
    case -8:
      pp_macro_text_append_string("1");
      break;
    case -9:
      iVar12 = (*g_idb->vtbl->idb_note_predefined_macro)(g_idb);
      if (iVar12 == 0) {
        diag_fatal(0x49,".\\p0macros.c",0x3e6);
      }
      if (g_opt_Brepro == 0) {
        uVar6 = pp_current_file_mtime();
        pcVar7 = pp_format_date_time_strings(uVar6);
        pcVar11 = pcVar7;
        pcVar13 = g_pp_timestamp_text;
        for (iVar12 = 6; iVar12 != 0; iVar12 = iVar12 + -1) {
          *(undefined4 *)pcVar13 = *(undefined4 *)pcVar11;
          pcVar11 = pcVar11 + 4;
          pcVar13 = pcVar13 + 4;
        }
        *pcVar13 = *pcVar11;
        g_pp_timestamp_text._11_4_ = *(undefined4 *)(pcVar7 + 0x10);
        g_pp_timestamp_text._15_4_ = *(undefined4 *)(pcVar7 + 0x14);
        g_pp_timestamp_text._19_4_ = *(undefined4 *)(pcVar7 + 10);
        g_pp_timestamp_text[0x17] = pcVar7[0xe];
        g_pp_timestamp_text[0x18] = '\0';
      }
      else {
        g_pp_timestamp_text[0] = '1';
        g_pp_timestamp_text[1] = '\0';
      }
      pbVar9 = (byte *)g_pp_timestamp_text;
      goto LAB_1045cf3f;
    case -7:
      iVar12 = (*g_idb->vtbl->idb_note_predefined_macro)(g_idb);
      pbVar9 = (byte *)g_pp_time_text;
      if (iVar12 == 0) {
        diag_fatal(0x49,".\\p0macros.c",0x3d4);
      }
      goto LAB_1045cf3f;
    case -6:
      iVar12 = (*g_idb->vtbl->idb_note_predefined_macro)(g_idb);
      pbVar9 = (byte *)g_pp_date_text;
      if (iVar12 == 0) {
        diag_fatal(0x49,".\\p0macros.c",0x3cf);
      }
LAB_1045cf3f:
      pp_macro_stringize(0x22,pbVar9);
      break;
    case -5:
      if (g_opt_Brepro == 0) {
        pbVar9 = (byte *)pp_position_file_name(&g_token_position);
        g_macro_text_cursor = pp_quote_file_name(g_macro_text_cursor,pbVar9);
      }
      else {
        g_macro_text_cursor = pp_quote_file_name(g_macro_text_cursor,(byte *)"Brepro.cxx");
      }
      break;
    case -4:
      text = (uchar *)pp_expand_line_macro();
      pp_macro_text_append_string(text);
    }
    iVar12 = pp_macro_expansion_end();
joined_r0x10409ebc:
    if (iVar12 != 0) {
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
LAB_1040a014:
    if (g_macro_rescan_level == 0) {
      return iVar10;
    }
    if (g_macro_text_buffer_limit <= g_macro_text_cursor) {
      pp_define_check_size
                ((uint)g_macro_text_cursor,(int)g_macro_text_buffer,
                 (int *)&g_macro_text_buffer_limit);
    }
    bVar3 = *g_input_ptr;
    macro = (fe_macro *)CONCAT31(macro._1_3_,bVar3);
    pbVar9 = g_input_ptr + 1;
    switch(g_char_class[bVar3]) {
    case '\0':
      g_input_ptr = pbVar9;
      uVar6 = lex_buffer_refill();
      pbVar9 = g_input_ptr;
      if ((uVar6 & 0x50) == 0) goto LAB_1040a014;
    default:
      g_input_ptr = pbVar9;
      *g_macro_text_cursor = bVar3;
      g_macro_text_cursor = g_macro_text_cursor + 1;
      goto LAB_1040a014;
    case '\x01':
      pbVar8 = g_input_ptr + 2;
      cVar1 = g_char_class[*pbVar9];
      while (cVar1 == '\x01') {
        bVar3 = *pbVar8;
        pbVar8 = pbVar8 + 1;
        cVar1 = g_char_class[bVar3];
      }
      g_input_ptr = pbVar8 + -1;
      *g_macro_text_cursor = ' ';
      g_macro_text_cursor = g_macro_text_cursor + 1;
      goto LAB_1040a014;
    case '\x06':
    case '\a':
    case '&':
      g_macro_expansion_text_start = g_macro_text_cursor;
      g_input_ptr = pbVar9;
      cVar2 = pp_macro_scan_identifier((uint)macro);
      if ((cVar2 == '\0') || (macro_00 = g_last_name->macro, macro_00 == (fe_macro *)0x0)) {
        if ((g_compile_flags_c4 & 0x4000) != 0) {
          iVar10 = pp_macro_expand_defined_in_if
                             (g_macro_text_cursor,iVar10,slash_next,after_slash,(uint)macro);
          return iVar10;
        }
        goto LAB_1040a014;
      }
      cVar2 = pp_macro_is_being_expanded(macro_00);
      if (cVar2 != '\0') {
        iVar10 = pp_macro_mark_not_expandable(iVar10,slash_next,after_slash,(uint)macro);
        return iVar10;
      }
      break;
    case '\t':
      if (g_char_class[*pbVar9] == '\x1d') {
        bVar3 = 0x2e;
        goto switchD_1040a060_caseD_1d;
      }
      g_input_ptr = pbVar9;
      *g_macro_text_cursor = '.';
      g_macro_text_cursor = g_macro_text_cursor + 1;
      goto LAB_1040a014;
    case '\x15':
    case '\x16':
      g_input_ptr = pbVar9;
      g_macro_text_cursor =
           pp_copy_quoted_text(g_macro_text_cursor,(uint *)&g_macro_text_buffer_limit,bVar3);
      goto LAB_1040a014;
    case '\x1d':
switchD_1040a060_caseD_1d:
      do {
        g_input_ptr = pbVar9;
        *g_macro_text_cursor = bVar3;
        g_macro_text_cursor = g_macro_text_cursor + 1;
        if (g_macro_text_buffer_limit <= g_macro_text_cursor) {
          pp_define_check_size
                    ((uint)g_macro_text_cursor,(int)g_macro_text_buffer,
                     (int *)&g_macro_text_buffer_limit);
        }
        bVar3 = *g_input_ptr;
        pbVar9 = g_input_ptr + 1;
        macro = (fe_macro *)CONCAT31(macro._1_3_,bVar3);
      } while (((g_char_flags[bVar3] & 4) != 0) ||
              (((bVar3 == 0x2b || (bVar3 == 0x2d)) &&
               ((*g_macro_text_cursor == 'e' || (*g_macro_text_cursor == 'E'))))));
      goto LAB_1040a014;
    case '\'':
      goto switchD_1040a060_caseD_27;
    case '(':
      g_input_ptr = pbVar9;
      pbVar9 = (byte *)pp_macro_argument_text();
      pp_macro_stringize(0x27,pbVar9);
      iVar10 = pp_macro_expand(iVar10,slash_next,after_slash,(uint)macro);
      return iVar10;
    }
  } while( true );
switchD_1040a060_caseD_27:
  g_input_ptr = pbVar9;
  pbVar9 = (byte *)pp_macro_argument_text();
  pp_macro_stringize(0x22,pbVar9);
  goto LAB_1040a014;
}

