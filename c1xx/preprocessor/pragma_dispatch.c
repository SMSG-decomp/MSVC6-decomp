int __cdecl pragma_dispatch(void)

{
  c1xx_pragma_optimize_letter *pcVar1;
  c1_u8 cVar2;
  byte bVar3;
  int *piVar4;
  c1_u8 *pcVar5;
  int iVar6;
  c1xx_token *tok;
  c1xx_token *tok_2;
  char *pcVar7;
  byte *pbVar8;
  c1xx_token *tok_3;
  fe_file_record *c;
  c1xx_token *pcVar9;
  byte *pbVar10;
  c1xx_token *tok_4;
  byte *pbVar11;
  fe_name *seg_class;
  byte *pbVar12;
  uchar *puVar13;
  c1_u8 *pcVar14;
  void *pvVar15;
  c1xx_pragma_optimize_letter *pcVar16;
  c1xx_token_stream *token_stream;
  int *piVar17;
  c1xx_token_stream_vtbl *pcVar18;
  char cVar19;
  void **seg_name;
  byte bVar20;
  void **seg_name_2;
  void *a;
  bool bVar21;
  int iVar22;
  uint uVar23;
  char cStack_c;
  uint warn_arg2;
  uint warn_arg2_2;
  
  iVar6 = (*g_idb->vtbl->idb_note_pragma_begin)(g_idb);
  if (iVar6 == 0) {
    diag_fatal(0x49,".\\p0pragma.c",0x441);
  }
  tok = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
  cVar2 = tok->code;
  while (cVar2 == 0xf2) {
    tok = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
    cVar2 = tok->code;
  }
  uVar23 = (uint)tok->code;
  if (0xff < uVar23) {
switchD_10430797_caseD_11:
    iVar6 = 0x44;
    goto LAB_1045f1a6;
  }
  switch(uVar23) {
  case 0:
  case 2:
  case 8:
  case 9:
  case 10:
  case 0xb:
  case 0xc:
  case 0xd:
  case 0xe:
  case 0xf:
  case 0x10:
  case 0x17:
    iVar6 = 0x44;
    iVar22 = 4;
    goto LAB_1045f05d;
  case 1:
    iVar6 = (*g_idb->vtbl->idb_note_pragma)(g_idb,1);
    if (iVar6 == 0) {
      diag_fatal(0x49,".\\p0pragma.c",0x5ba);
    }
    tok = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
    switch(tok->code) {
    case '-':
      (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)tok);
      g_pragma_check_stack = g_opt_stack_probes;
      return 0;
    default:
      iVar6 = 0x4d;
      break;
    case 'F':
      g_pragma_check_stack = 0;
      return 0;
    case 'Q':
      g_pragma_check_stack = 1;
      return 0;
    case 'v':
      (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)tok);
      pcVar9 = pragma_parse_identifier(1);
      if (pcVar9 == (c1xx_token *)0x0) {
        g_pragma_check_stack = g_opt_stack_probes;
        return 0;
      }
      g_pragma_check_stack = *(byte *)&pcVar9->value & 1;
      return 0;
    }
    goto LAB_1045f1a6;
  case 3:
    iVar6 = (*g_idb->vtbl->idb_note_pragma)(g_idb,3);
    if (iVar6 == 0) {
      diag_fatal(0x49,".\\p0pragma.c",0x54d);
    }
    pragma_pack_parse();
    return 0;
  case 4:
    if (g_block_depth != '\0') {
      diag_error(0x9c);
    }
    puVar13 = pragma_warn_expected_token('v');
    if (puVar13 != (uchar *)0x0) {
      pragma_parse_list(pragma_intrinsic_one);
      pragma_warn_expected_token('~');
      return 0;
    }
    break;
  case 5:
    if (g_block_depth != '\0') {
      diag_error(0x9c);
    }
    puVar13 = pragma_warn_expected_token('v');
    if (puVar13 != (uchar *)0x0) {
      pragma_parse_list(pragma_function_one);
      pragma_warn_expected_token('~');
      return 0;
    }
    break;
  case 6:
    if (g_block_depth != '\0') {
      diag_error(0x9c);
    }
    puVar13 = pragma_warn_expected_token('v');
    if (puVar13 == (uchar *)0x0) {
      return 0;
    }
    pbVar11 = token_next((c1_token_reader *)&g_token_position);
    bVar20 = *pbVar11;
    if (bVar20 == 7) {
      (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)pbVar11);
      tok = (c1xx_token *)pragma_string_argument();
      if (*(char *)tok->value == '\0') {
        iVar6 = 0x26a;
        goto LAB_1045f1a6;
      }
      pvVar15 = name_intern(tok->value);
    }
    else {
      if (bVar20 != 6) {
        diag_warning(1,0x50,(uint)bVar20);
        pragma_skip_to_dash(pbVar11);
        return 0;
      }
      pvVar15 = *(void **)(pbVar11 + 8);
    }
    g_alloc_text_segment = segment_lookup_or_declare(pvVar15,g_name_unnamed,'\0');
    puVar13 = pragma_warn_expected_token('7');
    if (puVar13 != (uchar *)0x0) {
      g_compile_flags_c4 = g_compile_flags_c4 | 0x10000;
      pragma_parse_list(pragma_alloc_text_name);
      pragma_warn_expected_token('~');
      return 0;
    }
    break;
  case 7:
    diag_warning(1,0x8f);
    pbVar11 = token_next((c1_token_reader *)&g_token_position);
    pragma_skip_to_dash(pbVar11);
    return 0;
  default:
    goto switchD_10430797_caseD_11;
  case 0x12:
    iVar6 = (*g_idb->vtbl->idb_note_pragma_output)(g_idb,0x12);
    if (iVar6 == 0) {
      diag_fatal(0x49,".\\p0pragma.c",0x5e8);
    }
    puVar13 = pragma_warn_expected_token('v');
    if (((puVar13 != (uchar *)0x0) && (pcVar14 = pragma_string_argument(), pcVar14 != (c1_u8 *)0x0))
       && (puVar13 = pragma_warn_expected_token('~'), puVar13 != (uchar *)0x0)) {
      diag_write_stderr(*(char **)(pcVar14 + 8));
      diag_write_stderr("\n");
      return 0;
    }
    break;
  case 0x13:
    iVar6 = (*g_idb->vtbl->idb_note_pragma_output)(g_idb,0x13);
    if (iVar6 == 0) {
      diag_fatal(0x49,".\\p0pragma.c",0x609);
    }
    puVar13 = pragma_warn_expected_token('v');
    if (puVar13 == (uchar *)0x0) {
      return 0;
    }
    pbVar11 = pragma_warn_expected_token('\x06');
    if (pbVar11 == (byte *)0x0) {
      return 0;
    }
    pcVar7 = "compiler";
    pbVar12 = *(byte **)(*(int *)(pbVar11 + 8) + 4);
    g_comment_record_text = (char *)0x0;
    pbVar8 = pbVar12;
    do {
      bVar20 = *pbVar8;
      bVar21 = bVar20 < (byte)*pcVar7;
      if (bVar20 != *pcVar7) {
LAB_104309f7:
        iVar6 = (1 - (uint)bVar21) - (uint)(bVar21 != 0);
        goto LAB_104309fc;
      }
      if (bVar20 == 0) break;
      bVar20 = pbVar8[1];
      bVar21 = bVar20 < (byte)pcVar7[1];
      if (bVar20 != pcVar7[1]) goto LAB_104309f7;
      pbVar8 = pbVar8 + 2;
      pcVar7 = pcVar7 + 2;
    } while (bVar20 != 0);
    iVar6 = 0;
LAB_104309fc:
    if (iVar6 == 0) {
      g_comment_record_kind = 1;
      g_comment_record_text = "";
    }
    else {
      pcVar7 = "lib";
      pbVar8 = pbVar12;
      do {
        bVar20 = *pbVar8;
        bVar21 = bVar20 < (byte)*pcVar7;
        if (bVar20 != *pcVar7) {
LAB_10430ac4:
          iVar6 = (1 - (uint)bVar21) - (uint)(bVar21 != 0);
          goto LAB_10430a39;
        }
        if (bVar20 == 0) break;
        bVar20 = pbVar8[1];
        bVar21 = bVar20 < (byte)pcVar7[1];
        if (bVar20 != pcVar7[1]) goto LAB_10430ac4;
        pbVar8 = pbVar8 + 2;
        pcVar7 = pcVar7 + 2;
      } while (bVar20 != 0);
      iVar6 = 0;
LAB_10430a39:
      if (iVar6 == 0) {
        g_comment_record_kind = 4;
      }
      else {
        pcVar7 = "exestr";
        pbVar8 = pbVar12;
        do {
          bVar20 = *pbVar8;
          bVar21 = bVar20 < (byte)*pcVar7;
          if (bVar20 != *pcVar7) {
LAB_10430ae3:
            iVar6 = (1 - (uint)bVar21) - (uint)(bVar21 != 0);
            goto LAB_10430ae8;
          }
          if (bVar20 == 0) break;
          bVar20 = pbVar8[1];
          bVar21 = bVar20 < (byte)pcVar7[1];
          if (bVar20 != pcVar7[1]) goto LAB_10430ae3;
          pbVar8 = pbVar8 + 2;
          pcVar7 = pcVar7 + 2;
        } while (bVar20 != 0);
        iVar6 = 0;
LAB_10430ae8:
        if (iVar6 == 0) {
          g_comment_record_kind = 3;
        }
        else {
          pcVar7 = "user";
          pbVar8 = pbVar12;
          do {
            bVar20 = *pbVar8;
            bVar21 = bVar20 < (byte)*pcVar7;
            if (bVar20 != *pcVar7) {
LAB_10430b05:
              iVar6 = (1 - (uint)bVar21) - (uint)(bVar21 != 0);
              goto LAB_10430b0a;
            }
            if (bVar20 == 0) break;
            bVar20 = pbVar8[1];
            bVar21 = bVar20 < (byte)pcVar7[1];
            if (bVar20 != pcVar7[1]) goto LAB_10430b05;
            pbVar8 = pbVar8 + 2;
            pcVar7 = pcVar7 + 2;
          } while (bVar20 != 0);
          iVar6 = 0;
LAB_10430b0a:
          if (iVar6 == 0) {
            g_comment_record_kind = 6;
          }
          else {
            pcVar7 = "nolib";
            pbVar8 = pbVar12;
            do {
              bVar20 = *pbVar8;
              bVar21 = bVar20 < (byte)*pcVar7;
              if (bVar20 != *pcVar7) {
LAB_10430b27:
                iVar6 = (1 - (uint)bVar21) - (uint)(bVar21 != 0);
                goto LAB_10430b2c;
              }
              if (bVar20 == 0) break;
              bVar20 = pbVar8[1];
              bVar21 = bVar20 < (byte)pcVar7[1];
              if (bVar20 != pcVar7[1]) goto LAB_10430b27;
              pbVar8 = pbVar8 + 2;
              pcVar7 = pcVar7 + 2;
            } while (bVar20 != 0);
            iVar6 = 0;
LAB_10430b2c:
            if (iVar6 == 0) {
              g_comment_record_kind = 9;
            }
            else {
              pcVar7 = "linker";
              do {
                bVar20 = *pbVar12;
                bVar21 = bVar20 < (byte)*pcVar7;
                if (bVar20 != *pcVar7) {
LAB_1045f4fb:
                  iVar6 = (1 - (uint)bVar21) - (uint)(bVar21 != 0);
                  goto LAB_10430b69;
                }
                if (bVar20 == 0) break;
                bVar20 = pbVar12[1];
                bVar21 = bVar20 < (byte)pcVar7[1];
                if (bVar20 != pcVar7[1]) goto LAB_1045f4fb;
                pbVar12 = pbVar12 + 2;
                pcVar7 = pcVar7 + 2;
              } while (bVar20 != 0);
              iVar6 = 0;
LAB_10430b69:
              if (iVar6 != 0) {
LAB_1045f505:
                pbVar12 = *(byte **)(pbVar11 + 8);
                iVar6 = 0x6d;
                goto LAB_1045f50b;
              }
              g_comment_record_kind = 10;
            }
          }
        }
      }
    }
    pbVar11 = token_next((c1_token_reader *)&g_token_position);
    if ((g_comment_record_text == (char *)0x0) && (*pbVar11 == 0x37)) {
      pcVar14 = pragma_string_argument();
      if (pcVar14 == (c1_u8 *)0x0) {
        return 0;
      }
      g_comment_record_text = *(char **)(pcVar14 + 8);
      pbVar11 = token_next((c1_token_reader *)&g_token_position);
    }
    (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)pbVar11);
    puVar13 = pragma_warn_expected_token('~');
    if (puVar13 == (uchar *)0x0) {
      return 0;
    }
    goto LAB_10430aa8;
  case 0x14:
    (*g_idb->vtbl->idb_note_pragma)(g_idb,0x14);
    puVar13 = pragma_warn_expected_token('v');
    if (puVar13 == (uchar *)0x0) {
      return 0;
    }
    pbVar11 = pragma_warn_expected_token('\x06');
    if (pbVar11 == (byte *)0x0) {
      return 0;
    }
    pbVar12 = *(byte **)(pbVar11 + 8);
    pcVar7 = "_TEXT";
    pbVar8 = *(byte **)(pbVar12 + 4);
    pbVar10 = pbVar8;
    do {
      bVar20 = *pbVar10;
      bVar21 = bVar20 < (byte)*pcVar7;
      if (bVar20 != *pcVar7) {
LAB_1045fa93:
        iVar6 = (1 - (uint)bVar21) - (uint)(bVar21 != 0);
        goto LAB_1045fa58;
      }
      if (bVar20 == 0) break;
      bVar20 = pbVar10[1];
      bVar21 = bVar20 < (byte)pcVar7[1];
      if (bVar20 != pcVar7[1]) goto LAB_1045fa93;
      pbVar10 = pbVar10 + 2;
      pcVar7 = pcVar7 + 2;
    } while (bVar20 != 0);
    iVar6 = 0;
LAB_1045fa58:
    if (iVar6 == 0) {
      seg_name_2 = &g_code_seg_name;
      cStack_c = '\0';
    }
    else {
      pcVar7 = "_DATA";
      pbVar10 = pbVar8;
      do {
        bVar20 = *pbVar10;
        bVar21 = bVar20 < (byte)*pcVar7;
        if (bVar20 != *pcVar7) {
LAB_1045fad3:
          iVar6 = (1 - (uint)bVar21) - (uint)(bVar21 != 0);
          goto LAB_1045fac3;
        }
        if (bVar20 == 0) break;
        bVar20 = pbVar10[1];
        bVar21 = bVar20 < (byte)pcVar7[1];
        if (bVar20 != pcVar7[1]) goto LAB_1045fad3;
        pbVar10 = pbVar10 + 2;
        pcVar7 = pcVar7 + 2;
      } while (bVar20 != 0);
      iVar6 = 0;
LAB_1045fac3:
      if (iVar6 == 0) {
        seg_name_2 = &g_data_seg_name;
        cStack_c = '\x01';
      }
      else {
        pcVar7 = "_BSS";
        pbVar10 = pbVar8;
        do {
          bVar20 = *pbVar10;
          bVar21 = bVar20 < (byte)*pcVar7;
          if (bVar20 != *pcVar7) {
LAB_1045fb16:
            iVar6 = (1 - (uint)bVar21) - (uint)(bVar21 != 0);
            goto LAB_1045fb03;
          }
          if (bVar20 == 0) break;
          bVar20 = pbVar10[1];
          bVar21 = bVar20 < (byte)pcVar7[1];
          if (bVar20 != pcVar7[1]) goto LAB_1045fb16;
          pbVar10 = pbVar10 + 2;
          pcVar7 = pcVar7 + 2;
        } while (bVar20 != 0);
        iVar6 = 0;
LAB_1045fb03:
        if (iVar6 == 0) {
          seg_name_2 = &g_bss_seg_name;
          cStack_c = '\x03';
        }
        else {
          pcVar7 = "CONST";
          do {
            bVar20 = *pbVar8;
            bVar21 = bVar20 < (byte)*pcVar7;
            if (bVar20 != *pcVar7) {
LAB_1045fb5d:
              iVar6 = (1 - (uint)bVar21) - (uint)(bVar21 != 0);
              goto LAB_1045fb46;
            }
            if (bVar20 == 0) break;
            bVar20 = pbVar8[1];
            bVar21 = bVar20 < (byte)pcVar7[1];
            if (bVar20 != pcVar7[1]) goto LAB_1045fb5d;
            pbVar8 = pbVar8 + 2;
            pcVar7 = pcVar7 + 2;
          } while (bVar20 != 0);
          iVar6 = 0;
LAB_1045fb46:
          if (iVar6 != 0) goto LAB_1045f785;
          seg_name_2 = &g_const_seg_name;
          cStack_c = '\x04';
        }
      }
    }
    pbVar11 = token_next((c1_token_reader *)&g_token_position);
    if (*pbVar11 == 0x37) {
      puVar13 = pragma_warn_expected_token('\x06');
      if (puVar13 == (uchar *)0x0) {
        return 0;
      }
      pvVar15 = segment_lookup_or_declare(*(void **)(puVar13 + 8),g_name_unnamed,cStack_c);
      *seg_name_2 = pvVar15;
      pragma_warn_expected_token('~');
      return 0;
    }
    if (*pbVar11 == 0x7e) {
      *seg_name_2 = (void *)0x0;
      return 0;
    }
    goto LAB_1045f94c;
  case 0x15:
    if (g_block_depth != '\0') {
      diag_error(0x9c);
      return 0;
    }
    puVar13 = pragma_warn_expected_token('v');
    if ((puVar13 != (uchar *)0x0) && (pcVar14 = pragma_string_argument(), pcVar14 != (c1_u8 *)0x0))
    {
      g_pragma_optimize_list = *(char **)(pcVar14 + 8);
      puVar13 = pragma_warn_expected_token('7');
      if ((puVar13 != (uchar *)0x0) && (pcVar14 = pragma_check_on_off(), pcVar14 != (c1_u8 *)0x0)) {
        g_pragma_optimize_on = *(int *)(pcVar14 + 8);
        puVar13 = pragma_warn_expected_token('~');
        if (puVar13 != (uchar *)0x0) {
          if (g_pragma_optimize_on == 0) {
            if (*g_pragma_optimize_list == '\0') {
              uVar23 = il_function_option_word();
              opt_unpack_optimize_flags(uVar23 & ~g_pragma_optimize_off_mask);
              return 0;
            }
            do {
              pcVar16 = g_pragma_optimize_letters;
              pcVar7 = g_pragma_optimize_list;
              do {
                if (*pcVar7 == pcVar16->letter) {
                  *pcVar16->flag = pcVar16->on_value == '\0';
                  pcVar7 = g_pragma_optimize_list;
                }
                pcVar1 = pcVar16 + 1;
                pcVar16 = pcVar16 + 1;
              } while (pcVar1->letter != '\0');
              g_pragma_optimize_list = pcVar7 + 1;
            } while (*g_pragma_optimize_list != '\0');
            return 0;
          }
          if (*g_pragma_optimize_list == '\0') {
            uVar23 = il_function_option_word();
            opt_unpack_optimize_flags
                      (uVar23 & ~g_pragma_optimize_on_mask |
                       g_command_line_option_word & g_pragma_optimize_on_mask);
            return 0;
          }
          do {
            pcVar16 = g_pragma_optimize_letters;
            pcVar7 = g_pragma_optimize_list;
            do {
              if (*pcVar7 == pcVar16->letter) {
                *pcVar16->flag = pcVar16->on_value;
                pcVar7 = g_pragma_optimize_list;
              }
              pcVar1 = pcVar16 + 1;
              pcVar16 = pcVar16 + 1;
            } while (pcVar1->letter != '\0');
            g_pragma_optimize_list = pcVar7 + 1;
          } while (*g_pragma_optimize_list != '\0');
          return 0;
        }
      }
    }
    break;
  case 0x16:
    if (g_block_depth != '\0') {
      if (g_incremental != '\0') {
        diag_error(0x133);
        cVar19 = '\x01';
        cStack_c = '\x01';
        seg_name = &g_data_seg_name;
        goto LAB_1045f7c0;
      }
      diag_warning(1,0xb1,"data_seg");
    }
    cVar19 = '\x01';
    seg_name = &g_data_seg_name;
    cStack_c = '\x01';
    goto LAB_1045f7c0;
  case 0x18:
    cVar19 = '\0';
    seg_name = &g_code_seg_name;
    cStack_c = '\0';
    goto LAB_1045f7c0;
  case 0x19:
    iVar6 = (*g_idb->vtbl->idb_note_pragma)(g_idb,0x19);
    if (iVar6 == 0) {
      diag_fatal(0x49,".\\p0pragma.c",0x8c6);
    }
    pcVar9 = pragma_parse_identifier(0x65);
    if (pcVar9 == (c1xx_token *)0x0) {
      g_pragma_inline_depth = 8;
    }
    else {
      g_pragma_inline_depth = (ushort)pcVar9->value2;
    }
    if (g_inline_level != 0) {
      il_emit_pragma_or_segment_record(0x20);
      return 0;
    }
    break;
  case 0x1a:
    iVar6 = (*g_idb->vtbl->idb_note_pragma)(g_idb,0x1a);
    if (iVar6 == 0) {
      diag_fatal(0x49,".\\p0pragma.c",0x8b9);
    }
    pcVar9 = pragma_parse_identifier(1);
    if (pcVar9 == (c1xx_token *)0x0) {
      g_pragma_inline_recursion = 0;
    }
    else {
      g_pragma_inline_recursion = *(ushort *)&pcVar9->value;
    }
    if (g_inline_level != 0) {
      il_emit_pragma_or_segment_record(0x20);
      return 0;
    }
    break;
  case 0x1b:
    if (g_block_depth != '\0') {
      diag_error(0x9c);
      return 0;
    }
    pcVar9 = pragma_parse_identifier(1);
    if (pcVar9 == (c1xx_token *)0x0) {
      g_pragma_auto_inline = 1;
      g_function_auto_inline = 1;
      return 0;
    }
    g_pragma_auto_inline = (uint)pcVar9->value & 1;
    g_function_auto_inline = g_pragma_auto_inline;
    return 0;
  case 0x1c:
    iVar6 = (*g_idb->vtbl->idb_note_pragma)(g_idb,0x1c);
    if (iVar6 == 0) {
      diag_fatal(0x49,".\\p0pragma.c",0x812);
    }
    puVar13 = pragma_warn_expected_token('v');
    if (puVar13 == (uchar *)0x0) {
      return 0;
    }
    do {
      pbVar11 = token_next((c1_token_reader *)&g_token_position);
      bVar20 = *pbVar11;
      if (bVar20 == 6) {
        pcVar7 = "disable";
        pbVar12 = *(byte **)(*(int *)(pbVar11 + 8) + 4);
        pbVar8 = pbVar12;
        do {
          bVar20 = *pbVar8;
          bVar21 = bVar20 < (byte)*pcVar7;
          if (bVar20 != *pcVar7) {
LAB_10460007:
            iVar6 = (1 - (uint)bVar21) - (uint)(bVar21 != 0);
            goto LAB_10430bfc;
          }
          if (bVar20 == 0) break;
          bVar20 = pbVar8[1];
          bVar21 = bVar20 < (byte)pcVar7[1];
          if (bVar20 != pcVar7[1]) goto LAB_10460007;
          pbVar8 = pbVar8 + 2;
          pcVar7 = pcVar7 + 2;
        } while (bVar20 != 0);
        iVar6 = 0;
LAB_10430bfc:
        if (iVar6 == 0) {
          bVar20 = 0xd;
        }
        else {
          pcVar7 = "error";
          pbVar8 = pbVar12;
          do {
            bVar20 = *pbVar8;
            bVar21 = bVar20 < (byte)*pcVar7;
            if (bVar20 != *pcVar7) {
LAB_1046004c:
              iVar6 = (1 - (uint)bVar21) - (uint)(bVar21 != 0);
              goto LAB_1046003e;
            }
            if (bVar20 == 0) break;
            bVar20 = pbVar8[1];
            bVar21 = bVar20 < (byte)pcVar7[1];
            if (bVar20 != pcVar7[1]) goto LAB_1046004c;
            pbVar8 = pbVar8 + 2;
            pcVar7 = pcVar7 + 2;
          } while (bVar20 != 0);
          iVar6 = 0;
LAB_1046003e:
          if (iVar6 == 0) {
            bVar20 = 0xe;
          }
          else {
            pcVar7 = "once";
            do {
              bVar20 = *pbVar12;
              bVar21 = bVar20 < (byte)*pcVar7;
              if (bVar20 != *pcVar7) {
LAB_1046008e:
                iVar6 = (1 - (uint)bVar21) - (uint)(bVar21 != 0);
                goto LAB_10460080;
              }
              if (bVar20 == 0) break;
              bVar20 = pbVar12[1];
              bVar21 = bVar20 < (byte)pcVar7[1];
              if (bVar20 != pcVar7[1]) goto LAB_1046008e;
              pbVar12 = pbVar12 + 2;
              pcVar7 = pcVar7 + 2;
            } while (bVar20 != 0);
            iVar6 = 0;
LAB_10460080:
            if (iVar6 != 0) {
              pcVar7 = "push";
              pbVar12 = *(byte **)(*(int *)(pbVar11 + 8) + 4);
              pbVar8 = pbVar12;
              goto LAB_104600b6;
            }
            bVar20 = 5;
          }
        }
      }
      else if (bVar20 == 0x65) {
        switch(*(undefined4 *)(pbVar11 + 0x10)) {
        case 1:
          bVar20 = 1;
          break;
        case 2:
          bVar20 = 2;
          break;
        case 3:
          bVar20 = 3;
          break;
        case 4:
          bVar20 = 4;
          break;
        default:
          diag_warning(1,0x268,*(undefined4 *)(pbVar11 + 0x10),1,4);
          pragma_skip_to_dash(pbVar11);
          return 0;
        }
      }
      else {
        if (bVar20 != 0x67) goto LAB_104601fb;
        bVar20 = 0;
      }
      puVar13 = pragma_warn_expected_token('6');
      if (puVar13 == (uchar *)0x0) {
        return 0;
      }
      pbVar11 = token_next((c1_token_reader *)&g_token_position);
      bVar3 = *pbVar11;
      while (bVar3 == 0x65) {
        pragma_warning_check_number(*(uint *)(pbVar11 + 0x10),bVar20);
        pbVar11 = token_next((c1_token_reader *)&g_token_position);
        bVar3 = *pbVar11;
      }
      if (*pbVar11 == 0x7e) {
        iVar6 = pragma_dispatch_return_zero_tail();
        return iVar6;
      }
    } while (*pbVar11 == 0x7f);
    token_stream = g_token_source->stream;
    goto LAB_1045fe84;
  case 0x1d:
    g_compile_flags_c4 = g_compile_flags_c4 | 0x8000;
    pragma_hdrstop(&g_pch_file_name);
    g_compile_flags_c4 = g_compile_flags_c4 & 0xffff7fff;
    return (int)g_token_pragma_hdrstop;
  case 0x1e:
    iVar6 = (*g_idb->vtbl->idb_note_pragma)(g_idb,0x1e);
    if (iVar6 == 0) {
      diag_fatal(0x49,".\\p0pragma.c",0x648);
    }
    if ((g_crt_initializer_segment != (void *)0x0) || (g_init_seg_kind != 1)) {
      diag_error(0x164);
    }
    puVar13 = pragma_warn_expected_token('v');
    if (puVar13 == (uchar *)0x0) {
      return 0;
    }
    pbVar11 = token_next((c1_token_reader *)&g_token_position);
    if (*pbVar11 == 6) {
      pbVar12 = *(byte **)(pbVar11 + 8);
      pcVar7 = "compiler";
      pbVar8 = *(byte **)(pbVar12 + 4);
      pbVar10 = pbVar8;
      do {
        bVar20 = *pbVar10;
        bVar21 = bVar20 < (byte)*pcVar7;
        if (bVar20 != *pcVar7) {
LAB_1045f6ce:
          iVar6 = (1 - (uint)bVar21) - (uint)(bVar21 != 0);
          goto LAB_1045f6a0;
        }
        if (bVar20 == 0) break;
        bVar20 = pbVar10[1];
        bVar21 = bVar20 < (byte)pcVar7[1];
        if (bVar20 != pcVar7[1]) goto LAB_1045f6ce;
        pbVar10 = pbVar10 + 2;
        pcVar7 = pcVar7 + 2;
      } while (bVar20 != 0);
      iVar6 = 0;
LAB_1045f6a0:
      if (iVar6 == 0) {
        diag_warning(1,0x4a);
        g_init_seg_kind = 3;
        pragma_warn_expected_token('~');
        return 0;
      }
      pcVar7 = "lib";
      pbVar10 = pbVar8;
      do {
        bVar20 = *pbVar10;
        bVar21 = bVar20 < (byte)*pcVar7;
        if (bVar20 != *pcVar7) {
LAB_1045f72c:
          iVar6 = (1 - (uint)bVar21) - (uint)(bVar21 != 0);
          goto LAB_1045f6fe;
        }
        if (bVar20 == 0) break;
        bVar20 = pbVar10[1];
        bVar21 = bVar20 < (byte)pcVar7[1];
        if (bVar20 != pcVar7[1]) goto LAB_1045f72c;
        pbVar10 = pbVar10 + 2;
        pcVar7 = pcVar7 + 2;
      } while (bVar20 != 0);
      iVar6 = 0;
LAB_1045f6fe:
      if (iVar6 == 0) {
        diag_warning(3,0x49);
        g_init_seg_kind = 2;
        pragma_warn_expected_token('~');
        return 0;
      }
      pcVar7 = "user";
      do {
        bVar20 = *pbVar8;
        bVar21 = bVar20 < (byte)*pcVar7;
        if (bVar20 != *pcVar7) {
LAB_1045f77e:
          iVar6 = (1 - (uint)bVar21) - (uint)(bVar21 != 0);
          goto LAB_1045f75c;
        }
        if (bVar20 == 0) break;
        bVar20 = pbVar8[1];
        bVar21 = bVar20 < (byte)pcVar7[1];
        if (bVar20 != pcVar7[1]) goto LAB_1045f77e;
        pbVar8 = pbVar8 + 2;
        pcVar7 = pcVar7 + 2;
      } while (bVar20 != 0);
      iVar6 = 0;
LAB_1045f75c:
      if (iVar6 == 0) {
        g_init_seg_kind = 1;
        pragma_warn_expected_token('~');
        return 0;
      }
LAB_1045f785:
      iVar6 = 0x6d;
LAB_1045f50b:
      diag_warning(1,iVar6,pbVar12);
      pragma_skip_to_dash(pbVar11);
      return 0;
    }
    if (*pbVar11 != 7) {
      (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)pbVar11);
      pragma_warn_expected_token('\x06');
      return 0;
    }
    diag_warning(1,0x4b);
    (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)pbVar11);
    tok = (c1xx_token *)pragma_string_argument();
    if (*(char *)tok->value != '\0') {
      g_init_seg_kind = 5;
      g_init_seg_name = name_intern(tok->value);
      pbVar11 = token_next((c1_token_reader *)&g_token_position);
      if (*pbVar11 == 0x37) {
        puVar13 = pragma_warn_expected_token('\x06');
        if (puVar13 == (uchar *)0x0) {
          return 0;
        }
        pragma_init_seg_set_atexit(*(int *)(puVar13 + 8));
        pragma_warn_expected_token('~');
        return 0;
      }
      token_stream = g_token_source->stream;
      pcVar18 = token_stream->vtbl;
      if (*pbVar11 != 0x7e) {
        (*pcVar18->unget)(token_stream,(char *)pbVar11);
        pragma_warn_expected_token('7');
        return 0;
      }
      goto LAB_1045fe87;
    }
    iVar6 = 0x26a;
    goto LAB_1045f1a6;
  case 0x1f:
    iVar6 = (*g_idb->vtbl->idb_note_pragma)(g_idb,0x1f);
    if (iVar6 == 0) {
      diag_fatal(0x49,".\\p0pragma.c",0x7d1);
    }
    pcVar9 = pragma_parse_identifier(1);
    if (pcVar9 == (c1xx_token *)0x0) {
      g_pragma_vtordisp = g_opt_vd;
      return 0;
    }
    g_pragma_vtordisp = *(byte *)&pcVar9->value & 1;
    return 0;
  case 0x20:
    iVar6 = (*g_idb->vtbl->idb_note_pragma)(g_idb,0x20);
    if (iVar6 == 0) {
      diag_fatal(0x49,".\\p0pragma.c",0x5d8);
    }
    pcVar9 = pragma_parse_argument(7);
    if (pcVar9 != (c1xx_token *)0x0) {
      pcVar7 = setlocale(0,pcVar9->value);
      if (pcVar7 == (char *)0x0) {
        diag_error(0xaf,pcVar9->value);
      }
      lex_clear_lead_byte_classes();
      lex_mark_mbcs_lead_bytes();
      return 0;
    }
    break;
  case 0x21:
    iVar6 = (*g_idb->vtbl->idb_note_pragma)(g_idb,0x21);
    if (iVar6 == 0) {
      diag_fatal(0x49,".\\p0pragma.c",0x7e1);
    }
    puVar13 = pragma_warn_expected_token('v');
    if (puVar13 == (uchar *)0x0) {
      return 0;
    }
    do {
      pbVar11 = pragma_warn_expected_token('\x06');
      if (pbVar11 == (byte *)0x0) {
        return 0;
      }
      pcVar7 = "best_case";
      pbVar12 = *(byte **)(*(int *)(pbVar11 + 8) + 4);
      pbVar8 = pbVar12;
      do {
        bVar20 = *pbVar8;
        bVar21 = bVar20 < (byte)*pcVar7;
        if (bVar20 != *pcVar7) {
LAB_1045fe9e:
          iVar6 = (1 - (uint)bVar21) - (uint)(bVar21 != 0);
          goto LAB_1045fe60;
        }
        if (bVar20 == 0) break;
        bVar20 = pbVar8[1];
        bVar21 = bVar20 < (byte)pcVar7[1];
        if (bVar20 != pcVar7[1]) goto LAB_1045fe9e;
        pbVar8 = pbVar8 + 2;
        pcVar7 = pcVar7 + 2;
      } while (bVar20 != 0);
      iVar6 = 0;
LAB_1045fe60:
      if (iVar6 == 0) {
        class_set_member_pointer_representation('\0');
      }
      else {
        pcVar7 = "full_generality";
        pbVar8 = pbVar12;
        do {
          bVar20 = *pbVar8;
          bVar21 = bVar20 < (byte)*pcVar7;
          if (bVar20 != *pcVar7) {
LAB_1045fedf:
            iVar6 = (1 - (uint)bVar21) - (uint)(bVar21 != 0);
            goto LAB_1045fed2;
          }
          if (bVar20 == 0) break;
          bVar20 = pbVar8[1];
          bVar21 = bVar20 < (byte)pcVar7[1];
          if (bVar20 != pcVar7[1]) goto LAB_1045fedf;
          pbVar8 = pbVar8 + 2;
          pcVar7 = pcVar7 + 2;
        } while (bVar20 != 0);
        iVar6 = 0;
LAB_1045fed2:
        if (iVar6 == 0) {
          class_set_member_pointer_representation('\x01');
        }
        else {
          pcVar7 = "single_inheritance";
          pbVar8 = pbVar12;
          do {
            bVar20 = *pbVar8;
            bVar21 = bVar20 < (byte)*pcVar7;
            if (bVar20 != *pcVar7) {
LAB_1045ff23:
              iVar6 = (1 - (uint)bVar21) - (uint)(bVar21 != 0);
              goto LAB_1045ff13;
            }
            if (bVar20 == 0) break;
            bVar20 = pbVar8[1];
            bVar21 = bVar20 < (byte)pcVar7[1];
            if (bVar20 != pcVar7[1]) goto LAB_1045ff23;
            pbVar8 = pbVar8 + 2;
            pcVar7 = pcVar7 + 2;
          } while (bVar20 != 0);
          iVar6 = 0;
LAB_1045ff13:
          if (iVar6 == 0) {
            iVar6 = 1;
          }
          else {
            pcVar7 = "multiple_inheritance";
            pbVar8 = pbVar12;
            do {
              bVar20 = *pbVar8;
              bVar21 = bVar20 < (byte)*pcVar7;
              if (bVar20 != *pcVar7) {
LAB_1045ff5f:
                iVar6 = (1 - (uint)bVar21) - (uint)(bVar21 != 0);
                goto LAB_1045ff57;
              }
              if (bVar20 == 0) break;
              bVar20 = pbVar8[1];
              bVar21 = bVar20 < (byte)pcVar7[1];
              if (bVar20 != pcVar7[1]) goto LAB_1045ff5f;
              pbVar8 = pbVar8 + 2;
              pcVar7 = pcVar7 + 2;
            } while (bVar20 != 0);
            iVar6 = 0;
LAB_1045ff57:
            if (iVar6 == 0) {
              iVar6 = 2;
            }
            else {
              pcVar7 = "virtual_inheritance";
              do {
                bVar20 = *pbVar12;
                bVar21 = bVar20 < (byte)*pcVar7;
                if (bVar20 != *pcVar7) {
LAB_1045ffa2:
                  iVar6 = (1 - (uint)bVar21) - (uint)(bVar21 != 0);
                  goto LAB_1045ff93;
                }
                if (bVar20 == 0) break;
                bVar20 = pbVar12[1];
                bVar21 = bVar20 < (byte)pcVar7[1];
                if (bVar20 != pcVar7[1]) goto LAB_1045ffa2;
                pbVar12 = pbVar12 + 2;
                pcVar7 = pcVar7 + 2;
              } while (bVar20 != 0);
              iVar6 = 0;
LAB_1045ff93:
              if (iVar6 != 0) goto LAB_1045f505;
              iVar6 = 3;
            }
          }
          class_set_member_pointer_inheritance(iVar6);
        }
      }
      pbVar11 = token_next((c1_token_reader *)&g_token_position);
    } while (*pbVar11 == 0x37);
    token_stream = g_token_source->stream;
LAB_1045fe84:
    pcVar18 = token_stream->vtbl;
LAB_1045fe87:
    (*pcVar18->unget)(token_stream,(char *)pbVar11);
    pragma_warn_expected_token('~');
    return 0;
  case 0x22:
    if (g_block_depth == '\0') {
      pcVar9 = pragma_parse_identifier(1);
      if (pcVar9 == (c1xx_token *)0x0) {
        g_string_pooling = g_opt_Gf;
      }
      else {
        g_string_pooling = *(byte *)&pcVar9->value & 1;
      }
      g_string_pooling_readonly_state =
           (pcVar9 != (c1xx_token *)0x0) - 1U & g_string_pooling_readonly;
      return 0;
    }
    diag_error(0x9c);
    return 0;
  case 0x25:
    pragma_once();
    return 0;
  case 0x2b:
    pbVar11 = token_next((c1_token_reader *)&g_token_position);
    if (*pbVar11 == 0x2d) {
      (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)pbVar11);
      return 0;
    }
    if (*pbVar11 != 0x76) {
      (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)pbVar11);
      pragma_warn_expected_token('v');
      return 0;
    }
    pbVar11 = token_next((c1_token_reader *)&g_token_position);
    if (*pbVar11 != 6) {
      if (*pbVar11 == 0x7e) {
        return 0;
      }
      (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)pbVar11);
      pragma_warn_expected_token('\x06');
      return 0;
    }
    pcVar7 = "browser";
    pbVar12 = *(byte **)(*(int *)(pbVar11 + 8) + 4);
    pbVar8 = pbVar12;
    do {
      bVar20 = *pbVar8;
      bVar21 = bVar20 < (byte)*pcVar7;
      if (bVar20 != *pcVar7) {
LAB_10430d11:
        iVar6 = (1 - (uint)bVar21) - (uint)(bVar21 != 0);
        goto LAB_10430d16;
      }
      if (bVar20 == 0) break;
      bVar20 = pbVar8[1];
      bVar21 = bVar20 < (byte)pcVar7[1];
      if (bVar20 != pcVar7[1]) goto LAB_10430d11;
      pbVar8 = pbVar8 + 2;
      pcVar7 = pcVar7 + 2;
    } while (bVar20 != 0);
    iVar6 = 0;
LAB_10430d16:
    if (iVar6 == 0) {
      pragma_component();
      return 0;
    }
    pcVar7 = "minrebuild";
    pbVar8 = pbVar12;
    do {
      bVar20 = *pbVar8;
      bVar21 = bVar20 < (byte)*pcVar7;
      if (bVar20 != *pcVar7) {
LAB_10430d69:
        iVar6 = (1 - (uint)bVar21) - (uint)(bVar21 != 0);
        goto LAB_10430d47;
      }
      if (bVar20 == 0) break;
      bVar20 = pbVar8[1];
      bVar21 = bVar20 < (byte)pcVar7[1];
      if (bVar20 != pcVar7[1]) goto LAB_10430d69;
      pbVar8 = pbVar8 + 2;
      pcVar7 = pcVar7 + 2;
    } while (bVar20 != 0);
    iVar6 = 0;
LAB_10430d47:
    if (iVar6 == 0) {
      pragma_on_off_value();
      return 0;
    }
    pcVar7 = "mintypeinfo";
    pbVar8 = pbVar12;
    do {
      bVar20 = *pbVar8;
      bVar21 = bVar20 < (byte)*pcVar7;
      if (bVar20 != *pcVar7) {
LAB_10460338:
        iVar6 = (1 - (uint)bVar21) - (uint)(bVar21 != 0);
        goto LAB_10430da5;
      }
      if (bVar20 == 0) break;
      bVar20 = pbVar8[1];
      bVar21 = bVar20 < (byte)pcVar7[1];
      if (bVar20 != pcVar7[1]) goto LAB_10460338;
      pbVar8 = pbVar8 + 2;
      pcVar7 = pcVar7 + 2;
    } while (bVar20 != 0);
    iVar6 = 0;
LAB_10430da5:
    if (iVar6 == 0) {
      pragma_on_off_option();
      return 0;
    }
    iVar6 = 0xae;
    goto LAB_1045f50b;
  case 0x2c:
    g_comment_record_kind = 3;
    pcVar14 = pragma_string_argument();
    if (pcVar14 == (c1_u8 *)0x0) {
      return 0;
    }
    g_comment_record_text = *(char **)(pcVar14 + 8);
LAB_10430aa8:
    if (g_comment_record_text != (char *)0x0) {
      il_emit_pragma_or_segment_record(0xb);
      return 0;
    }
    break;
  case 0x2d:
    if (g_block_depth != '\0') {
      if (g_incremental != '\0') {
        diag_error(0x133);
        cVar19 = '\x03';
        cStack_c = '\x03';
        seg_name = &g_bss_seg_name;
        goto LAB_1045f7c0;
      }
      diag_warning(1,0xb1,"bss_seg");
    }
    cVar19 = '\x03';
    seg_name = &g_bss_seg_name;
    cStack_c = '\x03';
    goto LAB_1045f7c0;
  case 0x2e:
    if (g_block_depth != '\0') {
      if (g_incremental != '\0') {
        diag_error(0x133);
        cVar19 = '\x04';
        cStack_c = '\x04';
        seg_name = &g_const_seg_name;
        goto LAB_1045f7c0;
      }
      diag_warning(1,0xb1,"const_seg");
    }
    cVar19 = '\x04';
    seg_name = &g_const_seg_name;
    cStack_c = '\x04';
LAB_1045f7c0:
    (*g_idb->vtbl->idb_note_pragma)(g_idb,uVar23);
    puVar13 = pragma_warn_expected_token('v');
    if (puVar13 != (uchar *)0x0) {
      tok_4 = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
      if (tok_4->code != '\a') {
        if (tok_4->code == '~') {
          *seg_name = (void *)0x0;
          return 0;
        }
        (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)tok_4);
        pragma_string_argument();
        return 0;
      }
      (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)tok_4);
      tok = (c1xx_token *)pragma_string_argument();
      if (*(char *)tok->value == '\0') {
        iVar6 = 0x26a;
      }
      else {
        pvVar15 = name_intern(tok->value);
        pbVar11 = token_next((c1_token_reader *)&g_token_position);
        seg_class = g_name_unnamed;
        if (*pbVar11 != 0x37) {
          if (*pbVar11 != 0x7e) {
LAB_1045f94c:
            (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)pbVar11);
            pragma_warn_expected_token('7');
            return 0;
          }
          (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)pbVar11);
LAB_1045f982:
          pvVar15 = segment_lookup_or_declare(pvVar15,seg_class,cStack_c);
          *seg_name = pvVar15;
          if ((cVar19 == '\0') && ((g_compile_flags_c4 & 0x20) != 0)) {
            func_definition_end('\x01');
            func_body_begin_generated((c1_symbol *)0x0);
          }
          pragma_warn_expected_token('~');
          return 0;
        }
        tok = (c1xx_token *)pragma_string_argument();
        if (tok == (c1xx_token *)0x0) {
          return 0;
        }
        if (*(char *)tok->value != '\0') {
          seg_class = name_intern(tok->value);
          goto LAB_1045f982;
        }
        iVar6 = 0x26a;
      }
LAB_1045f1a6:
      iVar22 = 1;
LAB_1045f05d:
      diag_warning(iVar22,iVar6);
      pragma_skip_to_dash(&tok->code);
      iVar6 = pragma_dispatch_return_zero_tail();
      return iVar6;
    }
    break;
  case 0x30:
    if ((g_compile_flags_cc & 0x800000) == 0) {
      diag_warning(1,0xc3);
    }
    g_compile_flags_cc = g_compile_flags_cc & 0xff7fffff;
    return 0;
  case 0x38:
  case 0x39:
    puVar13 = pragma_warn_expected_token('v');
    if ((puVar13 != (uchar *)0x0) && (pcVar14 = pragma_string_argument(), pcVar14 != (c1_u8 *)0x0))
    {
      pcVar7 = *(char **)(pcVar14 + 8);
      puVar13 = pragma_warn_expected_token('~');
      if (puVar13 != (uchar *)0x0) {
        if (((pcVar7 == (char *)0x0) || (*pcVar7 == '\0')) ||
           (pvVar15 = name_intern(pcVar7), pvVar15 == (void *)0x0)) {
          diag_warning(1,600);
          return 0;
        }
        if (uVar23 == 0x38) {
          if (*(int *)((int)pvVar15 + 0xc) == 0) {
            diag_warning(1,0x259,pvVar15);
          }
          pcVar14 = g_arenas[0].cur;
          g_arenas[0].cur = g_arenas[0].cur + 0x10;
          if (g_arenas[0].end < g_arenas[0].cur) {
            arena_grow(g_arenas);
          }
          if (pcVar14 == (c1_u8 *)0x0) {
            pcVar14 = (c1_u8 *)0x0;
          }
          else {
            warn_arg2_2 = *(uint *)((int)pvVar15 + 0xc);
            *(void **)pcVar14 = pvVar15;
            *(uint *)(pcVar14 + 4) = warn_arg2_2;
            pcVar14[8] = '\0';
            pcVar14[9] = '\0';
            pcVar14[10] = '\0';
            pcVar14[0xb] = '\0';
            pcVar14[0xc] = '\0';
            pcVar14[0xd] = '\0';
            pcVar14[0xe] = '\0';
            pcVar14[0xf] = '\0';
          }
          pcVar5 = g_arenas[0].cur;
          if (g_push_macro_stack == (int *)0x0) {
            g_arenas[0].cur = g_arenas[0].cur + 4;
            if (g_arenas[0].end < g_arenas[0].cur) {
              arena_grow(g_arenas);
            }
            if (pcVar5 == (c1_u8 *)0x0) {
              g_push_macro_stack = (int *)0x0;
            }
            else {
              pcVar5[0] = '\0';
              pcVar5[1] = '\0';
              pcVar5[2] = '\0';
              pcVar5[3] = '\0';
              g_push_macro_stack = (int *)pcVar5;
            }
          }
          piVar17 = g_push_macro_stack;
          if (*g_push_macro_stack != 0) {
            *(int *)(pcVar14 + 8) = *g_push_macro_stack;
            *(c1_u8 **)(*piVar17 + 0xc) = pcVar14;
          }
          *piVar17 = (int)pcVar14;
          return 0;
        }
        if (g_push_macro_stack != (int *)0x0) {
          piVar17 = (int *)*g_push_macro_stack;
          if (piVar17 != (int *)0x0) {
            while ((void *)*piVar17 != pvVar15) {
              piVar17 = (int *)piVar17[2];
              if (piVar17 == (int *)0x0) {
                diag_warning(1,0x25a,pvVar15);
                return 0;
              }
            }
            if (piVar17 != (int *)0x0) {
              *(int *)((int)pvVar15 + 0xc) = piVar17[1];
              for (piVar4 = (int *)*g_push_macro_stack;
                  (piVar4 != (int *)0x0 && (piVar4 != piVar17)); piVar4 = (int *)piVar4[2]) {
              }
              if (piVar4[3] == 0) {
                *g_push_macro_stack = piVar4[2];
              }
              else {
                *(int *)(piVar4[3] + 8) = piVar4[2];
              }
              if (piVar4[2] == 0) {
                return 0;
              }
              *(int *)(piVar4[2] + 0xc) = piVar4[3];
              return 0;
            }
          }
          diag_warning(1,0x25a,pvVar15);
          return 0;
        }
        diag_warning(1,0x25a,pvVar15);
        return 0;
      }
    }
    break;
  case 0x3a:
    iVar6 = (*g_idb->vtbl->idb_note_pragma_output)(g_idb,0x3a);
    if (iVar6 == 0) {
      diag_fatal(0x49,".\\p0pragma.c",0x46e);
    }
    tok_3 = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
    if (tok_3->code == '\a') {
      iVar6 = (*g_idb->vtbl->idb_note_pragma)(g_idb,0x3a);
      if (iVar6 == 0) {
        diag_fatal(0x49,".\\p0pragma.c",0x483);
      }
      if (g_block_depth != '\0') {
        il_emit_pragma_or_segment_record(2);
      }
      if (g_browse_file != (char *)0x0) {
        (*g_il_emitter->vtbl->end_module)();
        (*g_il_emitter->vtbl->begin_module)();
        il_emit_pragma_or_segment_record(1);
        return 0;
      }
    }
    else {
      (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)tok_3);
    }
    il_emit_pragma_or_segment_record(1);
    return 0;
  case 0x3b:
    if (tok->value == (void *)0x0) {
      c = file_record_lookup_or_new(g_current_scope,(char *)g_forced_include_current,0);
      g_lex_position = g_lex_position + 1;
      vector_push_triple((int *)&g_line_map,g_lex_position,0,(int)c);
    }
    g_token_position = g_lex_position;
    il_emit_pragma_or_segment_record(2);
    il_emit_pragma_or_segment_record(1);
    if (g_browse_file != (char *)0x0) {
      (*g_il_emitter->vtbl->begin_module)();
      return 0;
    }
    break;
  case 0x3c:
    pvVar15 = tok->value;
    a = pvVar15;
    if ((int)pvVar15 < 0) {
      a = (void *)-(int)pvVar15;
    }
    if (((g_compile_flags_c4 & 0x20) != 0) && ((int)a < 1)) {
      func_definition_end('\x01');
    }
    if ((int)pvVar15 < 0) {
      pcVar7 = pp_position_file_name(&g_token_position);
      diag_warning(1,0x67,pcVar7);
    }
    tok_2 = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
    if (tok_2->code == 0xf2) {
      g_token_position = (int)tok_2->value;
      if (((g_compile_flags_c4 & 0x20000) != 0) && ((g_compile_flags_c4 & 0x20) == 0)) {
        il_emit_pragma_or_segment_record(0x24);
      }
      tok_2 = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
    }
    (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)tok_2);
    il_emit_pragma_or_segment_record(2);
    il_emit_pragma_or_segment_record(1);
    if ((0 < (int)a) && (g_browse_file != (char *)0x0)) {
      (*g_il_emitter->vtbl->end_module_if)((int)a);
    }
    if (((a == (void *)0x1) && (g_pch_create_header_seen != '\0')) && (g_pch_written == 0)) {
      pch_set_name(g_create_pch_header_name);
      return (int)g_token_pch_creation_point;
    }
    if (g_include_depth == 0) {
      if (g_pch_directive_mode != 1) {
        iVar6 = pragma_dispatch_return_zero_tail();
        return iVar6;
      }
      if (g_pch_include_count.count == 0) {
        return (int)g_token_pch_creation_point;
      }
    }
  }
  return 0;
  while( true ) {
    bVar20 = pbVar8[1];
    bVar21 = bVar20 < (byte)pcVar7[1];
    if (bVar20 != pcVar7[1]) goto LAB_1046012c;
    pbVar8 = pbVar8 + 2;
    pcVar7 = pcVar7 + 2;
    if (bVar20 == 0) break;
LAB_104600b6:
    bVar20 = *pbVar8;
    bVar21 = bVar20 < (byte)*pcVar7;
    if (bVar20 != *pcVar7) {
LAB_1046012c:
      iVar6 = (1 - (uint)bVar21) - (uint)(bVar21 != 0);
      goto LAB_104600dc;
    }
    if (bVar20 == 0) break;
  }
  iVar6 = 0;
LAB_104600dc:
  if (iVar6 == 0) {
    pragma_warning_push();
    pbVar11 = token_next((c1_token_reader *)&g_token_position);
    bVar20 = *pbVar11;
    if (bVar20 == 0x37) {
      pbVar11 = pragma_warn_expected_token('e');
      if (pbVar11 == (byte *)0x0) {
        return 0;
      }
      iVar6 = *(int *)(pbVar11 + 0x10);
      if ((0 < iVar6) && (iVar6 < 5)) {
        g_warning_state->level = iVar6;
        pragma_warn_expected_token('~');
        return 0;
      }
      uVar23 = 4;
      warn_arg2 = 1;
      iVar22 = 0x268;
    }
    else {
      if (bVar20 == 0x7e) {
        return 0;
      }
      uVar23 = (uint)bVar20;
      warn_arg2 = 0x7e;
      iVar6 = 0x37;
      iVar22 = 0xc4;
    }
    diag_warning(1,iVar22,iVar6,warn_arg2,uVar23);
    pragma_skip_to_dash(pbVar11);
    return 0;
  }
  pcVar7 = "pop";
  do {
    bVar20 = *pbVar12;
    bVar21 = bVar20 < (byte)*pcVar7;
    if (bVar20 != *pcVar7) {
LAB_10460181:
      iVar6 = (1 - (uint)bVar21) - (uint)(bVar21 != 0);
      goto LAB_10460160;
    }
    if (bVar20 == 0) break;
    bVar20 = pbVar12[1];
    bVar21 = bVar20 < (byte)pcVar7[1];
    if (bVar20 != pcVar7[1]) goto LAB_10460181;
    pbVar12 = pbVar12 + 2;
    pcVar7 = pcVar7 + 2;
  } while (bVar20 != 0);
  iVar6 = 0;
LAB_10460160:
  if (iVar6 == 0) {
    pragma_warning_pop();
    pragma_warn_expected_token('~');
    return 0;
  }
LAB_104601fb:
  diag_warning(1,0x267);
  pragma_skip_to_dash(pbVar11);
  return 0;
}

