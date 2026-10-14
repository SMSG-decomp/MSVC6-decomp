int __cdecl pragma_dispatch(void)

{
  c1_pragma_optimize_letter *pcVar1;
  c1_u8 cVar2;
  fe_macro *pfVar3;
  c1_pushed_macro *pcVar4;
  uchar *puVar5;
  c1_pushed_macro **ppcVar6;
  int iVar7;
  c1_token *pcVar8;
  c1_token *pcVar9;
  fe_name *section_name;
  void *pvVar10;
  byte *pbVar11;
  char *pcVar12;
  fe_name *alloc_text_seg_name;
  byte *pbVar13;
  byte *browser_cursor;
  byte *minrebuild_cursor;
  byte *mintypeinfo_cursor;
  int *c;
  fe_name *macro_name;
  c1_pragma_optimize_letter *pcVar14;
  void **ppvVar15;
  byte bVar16;
  void *section_class;
  c1_pushed_macro *pcVar17;
  c1_u32 cVar18;
  bool bVar19;
  int level;
  undefined4 uVar20;
  code *each;
  uint uVar21;
  char cStack_8;
  void *message_arg;
  
  iVar7 = (*g_idb->vtbl->idb_note_pragma_begin)(g_idb);
  if (iVar7 == 0) {
    diag_fatal(0x49,".\\p0pragma.c",0x441);
  }
  pcVar8 = token_next(&g_token_position);
  uVar21 = (uint)pcVar8->code;
  if (0x36 < pcVar8->code) {
    switch(uVar21) {
    case 0x38:
    case 0x39:
      pcVar8 = pragma_warn_expected_token('v');
      if (pcVar8 == (c1_token *)0x0) {
        return 0;
      }
      pcVar8 = pragma_string_argument();
      if (pcVar8 == (c1_token *)0x0) {
        return 0;
      }
      pcVar12 = (pcVar8->value).string.text;
      pcVar8 = pragma_warn_expected_token('~');
      if (pcVar8 == (c1_token *)0x0) {
        return 0;
      }
      if (((pcVar12 != (char *)0x0) && (*pcVar12 != '\0')) &&
         (macro_name = name_intern(pcVar12), macro_name != (fe_name *)0x0)) {
        if (uVar21 == 0x38) {
          if (macro_name->macro == (fe_macro *)0x0) {
            diag_warning(1,0x259,macro_name);
          }
          pcVar17 = (c1_pushed_macro *)g_arenas[0].cur;
          g_arenas[0].cur = g_arenas[0].cur + 0x10;
          if (g_arenas[0].end < g_arenas[0].cur) {
            arena_grow(g_arenas);
          }
          if (pcVar17 == (c1_pushed_macro *)0x0) {
            pcVar17 = (c1_pushed_macro *)0x0;
          }
          else {
            pfVar3 = macro_name->macro;
            pcVar17->name = macro_name;
            *(fe_macro **)((int)pcVar17 + 4) = pfVar3;
            *(uchar *)((int)pcVar17 + 8) = '\0';
            *(uchar *)((int)pcVar17 + 9) = '\0';
            *(uchar *)((int)pcVar17 + 10) = '\0';
            *(uchar *)((int)pcVar17 + 0xb) = '\0';
            *(uchar *)((int)pcVar17 + 0xc) = '\0';
            *(uchar *)((int)pcVar17 + 0xd) = '\0';
            *(uchar *)((int)pcVar17 + 0xe) = '\0';
            *(uchar *)((int)pcVar17 + 0xf) = '\0';
          }
          puVar5 = g_arenas[0].cur;
          if (g_pushed_macros == (c1_pushed_macro **)0x0) {
            g_arenas[0].cur = g_arenas[0].cur + 4;
            if (g_arenas[0].end < g_arenas[0].cur) {
              arena_grow(g_arenas);
            }
            if (puVar5 == (uchar *)0x0) {
              g_pushed_macros = (c1_pushed_macro **)0x0;
            }
            else {
              puVar5[0] = '\0';
              puVar5[1] = '\0';
              puVar5[2] = '\0';
              puVar5[3] = '\0';
              g_pushed_macros = (c1_pushed_macro **)puVar5;
            }
          }
          ppcVar6 = g_pushed_macros;
          if (*g_pushed_macros != (c1_pushed_macro *)0x0) {
            pcVar17->next = *g_pushed_macros;
            (*ppcVar6)->prev = pcVar17;
          }
          *ppcVar6 = pcVar17;
          return 0;
        }
        if (g_pushed_macros == (c1_pushed_macro **)0x0) {
          diag_warning(1,0x25a,macro_name);
          return 0;
        }
        pcVar17 = *g_pushed_macros;
        if (pcVar17 != (c1_pushed_macro *)0x0) {
          while (pcVar17->name != macro_name) {
            pcVar17 = pcVar17->next;
            if (pcVar17 == (c1_pushed_macro *)0x0) {
              diag_warning(1,0x25a,macro_name);
              return 0;
            }
          }
          if (pcVar17 != (c1_pushed_macro *)0x0) {
            macro_name->macro = pcVar17->definition;
            for (pcVar4 = *g_pushed_macros;
                (pcVar4 != (c1_pushed_macro *)0x0 && (pcVar4 != pcVar17)); pcVar4 = pcVar4->next) {
            }
            if (pcVar4->prev == (c1_pushed_macro *)0x0) {
              *g_pushed_macros = pcVar4->next;
            }
            else {
              pcVar4->prev->next = pcVar4->next;
            }
            if (pcVar4->next != (c1_pushed_macro *)0x0) {
              pcVar4->next->prev = pcVar4->prev;
              return 0;
            }
            return 0;
          }
        }
        diag_warning(1,0x25a,macro_name);
        return 0;
      }
      diag_warning(1,600);
      return 0;
    case 0x3a:
      iVar7 = (*g_idb->vtbl->idb_note_pragma_output)(g_idb,0x3a);
      if (iVar7 == 0) {
        diag_fatal(0x49,".\\p0pragma.c",0x46e);
      }
      pcVar8 = token_next(&g_token_position);
      if (pcVar8->code == '\a') {
        iVar7 = (*g_idb->vtbl->idb_note_pragma)(g_idb,0x3a);
        if (iVar7 == 0) {
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
        (*g_token_source->stream->vtbl->unget)(g_token_source->stream,pcVar8);
      }
      il_emit_pragma_or_segment_record(1);
      return 0;
    case 0x3b:
      if ((pcVar8->value).ptr == (void *)0x0) {
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
      return 0;
    case 0x3c:
      cVar18 = (pcVar8->value).words[0];
      if ((int)cVar18 < 0) {
        cVar18 = -cVar18;
        pcVar12 = pp_position_file_name(&g_token_position);
        diag_warning(1,0x67,pcVar12);
      }
      pcVar8 = token_next(&g_token_position);
      if (pcVar8->code == 0xf2) {
        g_token_position = (pcVar8->value).words[0];
        if (((g_compile_flags_c4 & 0x20000) != 0) && ((g_compile_flags_c4 & 0x20) == 0)) {
          il_emit_pragma_or_segment_record(0x24);
        }
        pcVar8 = token_next(&g_token_position);
      }
      (*g_token_source->stream->vtbl->unget)(g_token_source->stream,pcVar8);
      il_emit_pragma_or_segment_record(2);
      il_emit_pragma_or_segment_record(1);
      if ((0 < (int)cVar18) && (g_browse_file != (char *)0x0)) {
        (*g_il_emitter->vtbl->end_module_if)(cVar18);
      }
      if ((cVar18 == 1) && (g_pch_create_header_reached != '\0')) {
        iVar7 = pragma_dispatch_fragment();
        return iVar7;
      }
      if (g_include_depth != 0) {
        return 0;
      }
      if (g_pch_directive_mode != 1) {
        iVar7 = pragma_dispatch_return_zero_tail();
        return iVar7;
      }
      if (g_pch_include_count[0] == 0) {
        return (int)g_token_pch_creation_point;
      }
      return 0;
    }
switchD_10609ae4_caseD_3d:
    iVar7 = 0x44;
    goto LAB_1062ae04;
  }
  switch(uVar21) {
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
    iVar7 = 0x44;
    level = 4;
    goto LAB_1062acf3;
  case 1:
    iVar7 = (*g_idb->vtbl->idb_note_pragma)(g_idb,1);
    if (iVar7 == 0) {
      diag_fatal(0x49,".\\p0pragma.c",0x5ba);
    }
    pcVar8 = token_next(&g_token_position);
    switch(pcVar8->code) {
    case '-':
      (*g_token_source->stream->vtbl->unget)(g_token_source->stream,pcVar8);
      g_pragma_check_stack = g_opt_stack_probes;
      return 0;
    default:
      iVar7 = 0x4d;
      break;
    case 'F':
      g_pragma_check_stack = 0;
      return 0;
    case 'Q':
      g_pragma_check_stack = 1;
      return 0;
    case 'v':
      (*g_token_source->stream->vtbl->unget)(g_token_source->stream,pcVar8);
      pcVar8 = pragma_parse_identifier(1);
      if (pcVar8 != (c1_token *)0x0) {
        g_pragma_check_stack = (pcVar8->value).spec.words.storage & 1;
        return 0;
      }
      g_pragma_check_stack = g_opt_stack_probes;
      return 0;
    }
    goto LAB_1062ae04;
  case 3:
    iVar7 = (*g_idb->vtbl->idb_note_pragma)(g_idb,3);
    if (iVar7 != 0) {
      pragma_pack_parse();
      return 0;
    }
    diag_fatal(0x49,".\\p0pragma.c",0x54d);
  case 4:
    if (g_block_depth != '\0') {
      diag_error(0x9c);
    }
    pcVar8 = pragma_warn_expected_token('v');
    if (pcVar8 == (c1_token *)0x0) {
      return 0;
    }
    each = pragma_intrinsic_name;
    goto LAB_10609b89;
  case 5:
    if (g_block_depth != '\0') {
      diag_error(0x9c);
    }
    pcVar8 = pragma_warn_expected_token('v');
    if (pcVar8 == (c1_token *)0x0) {
      return 0;
    }
    each = pragma_function_name;
    goto LAB_10609b89;
  case 6:
    if (g_block_depth != '\0') {
      diag_error(0x9c);
    }
    pcVar8 = pragma_warn_expected_token('v');
    if (pcVar8 == (c1_token *)0x0) {
      return 0;
    }
    pcVar8 = token_next(&g_token_position);
    bVar16 = pcVar8->code;
    if (bVar16 == 7) {
      (*g_token_source->stream->vtbl->unget)(g_token_source->stream,pcVar8);
      pcVar8 = pragma_string_argument();
      pcVar12 = (pcVar8->value).string.text;
      if (*pcVar12 == '\0') {
        iVar7 = 0x26a;
        goto LAB_1062ae04;
      }
      alloc_text_seg_name = name_intern(pcVar12);
    }
    else {
      if (bVar16 != 6) {
        diag_warning(1,0x50,(uint)bVar16);
        pragma_skip_to_dash(pcVar8);
        return 0;
      }
      alloc_text_seg_name = (pcVar8->value).name;
    }
    g_alloc_text_segment = segment_lookup_or_declare(alloc_text_seg_name,g_name_unnamed,'\0');
    pcVar8 = pragma_warn_expected_token('7');
    if (pcVar8 == (c1_token *)0x0) {
      return 0;
    }
    each = pragma_alloc_text_name;
    g_compile_flags_c4 = g_compile_flags_c4 | 0x10000;
LAB_10609b89:
    pragma_parse_list(each);
    pragma_warn_expected_token('~');
    return 0;
  case 7:
    diag_warning(1,0x8f);
    pcVar8 = token_next(&g_token_position);
    pragma_skip_to_dash(pcVar8);
    return 0;
  default:
    goto switchD_10609ae4_caseD_3d;
  case 0x12:
    iVar7 = (*g_idb->vtbl->idb_note_pragma_output)(g_idb,0x12);
    if (iVar7 == 0) {
      diag_fatal(0x49,".\\p0pragma.c",0x5e8);
    }
    pcVar8 = pragma_warn_expected_token('v');
    if (((pcVar8 != (c1_token *)0x0) &&
        (pcVar8 = pragma_string_argument(), pcVar8 != (c1_token *)0x0)) &&
       (pcVar9 = pragma_warn_expected_token('~'), pcVar9 != (c1_token *)0x0)) {
      diag_write_stderr((pcVar8->value).string.text);
      diag_write_stderr("\n");
      return 0;
    }
    break;
  case 0x13:
    iVar7 = (*g_idb->vtbl->idb_note_pragma_output)(g_idb,0x13);
    if (iVar7 == 0) {
      diag_fatal(0x49,".\\p0pragma.c",0x609);
    }
    pcVar8 = pragma_warn_expected_token('v');
    if (pcVar8 == (c1_token *)0x0) {
      return 0;
    }
    pcVar8 = pragma_warn_expected_token('\x06');
    if (pcVar8 == (c1_token *)0x0) {
      return 0;
    }
    pcVar12 = "compiler";
    pbVar13 = (byte *)((pcVar8->value).name)->text;
    g_comment_record_text = (char *)0x0;
    pbVar11 = pbVar13;
    do {
      bVar16 = *pbVar11;
      bVar19 = bVar16 < (byte)*pcVar12;
      if (bVar16 != *pcVar12) {
LAB_10609c6a:
        iVar7 = (1 - (uint)bVar19) - (uint)(bVar19 != 0);
        goto LAB_10609c6f;
      }
      if (bVar16 == 0) break;
      bVar16 = pbVar11[1];
      bVar19 = bVar16 < (byte)pcVar12[1];
      if (bVar16 != pcVar12[1]) goto LAB_10609c6a;
      pbVar11 = pbVar11 + 2;
      pcVar12 = pcVar12 + 2;
    } while (bVar16 != 0);
    iVar7 = 0;
LAB_10609c6f:
    if (iVar7 == 0) {
      g_comment_record_kind = 1;
      g_comment_record_text = "";
    }
    else {
      pcVar12 = "lib";
      pbVar11 = pbVar13;
      do {
        bVar16 = *pbVar11;
        bVar19 = bVar16 < (byte)*pcVar12;
        if (bVar16 != *pcVar12) {
LAB_1062b09d:
          iVar7 = (1 - (uint)bVar19) - (uint)(bVar19 != 0);
          goto LAB_10609cac;
        }
        if (bVar16 == 0) break;
        bVar16 = pbVar11[1];
        bVar19 = bVar16 < (byte)pcVar12[1];
        if (bVar16 != pcVar12[1]) goto LAB_1062b09d;
        pbVar11 = pbVar11 + 2;
        pcVar12 = pcVar12 + 2;
      } while (bVar16 != 0);
      iVar7 = 0;
LAB_10609cac:
      if (iVar7 == 0) {
        g_comment_record_kind = 4;
      }
      else {
        pcVar12 = "exestr";
        pbVar11 = pbVar13;
        do {
          bVar16 = *pbVar11;
          bVar19 = bVar16 < (byte)*pcVar12;
          if (bVar16 != *pcVar12) {
LAB_1062b0e7:
            iVar7 = (1 - (uint)bVar19) - (uint)(bVar19 != 0);
            goto LAB_1062b0d4;
          }
          if (bVar16 == 0) break;
          bVar16 = pbVar11[1];
          bVar19 = bVar16 < (byte)pcVar12[1];
          if (bVar16 != pcVar12[1]) goto LAB_1062b0e7;
          pbVar11 = pbVar11 + 2;
          pcVar12 = pcVar12 + 2;
        } while (bVar16 != 0);
        iVar7 = 0;
LAB_1062b0d4:
        if (iVar7 == 0) {
          g_comment_record_kind = 3;
        }
        else {
          pcVar12 = "user";
          pbVar11 = pbVar13;
          do {
            bVar16 = *pbVar11;
            bVar19 = bVar16 < (byte)*pcVar12;
            if (bVar16 != *pcVar12) {
LAB_1062b12e:
              iVar7 = (1 - (uint)bVar19) - (uint)(bVar19 != 0);
              goto LAB_1062b11b;
            }
            if (bVar16 == 0) break;
            bVar16 = pbVar11[1];
            bVar19 = bVar16 < (byte)pcVar12[1];
            if (bVar16 != pcVar12[1]) goto LAB_1062b12e;
            pbVar11 = pbVar11 + 2;
            pcVar12 = pcVar12 + 2;
          } while (bVar16 != 0);
          iVar7 = 0;
LAB_1062b11b:
          if (iVar7 == 0) {
            g_comment_record_kind = 6;
          }
          else {
            pcVar12 = "nolib";
            pbVar11 = pbVar13;
            do {
              bVar16 = *pbVar11;
              bVar19 = bVar16 < (byte)*pcVar12;
              if (bVar16 != *pcVar12) {
LAB_1062b175:
                iVar7 = (1 - (uint)bVar19) - (uint)(bVar19 != 0);
                goto LAB_1062b162;
              }
              if (bVar16 == 0) break;
              bVar16 = pbVar11[1];
              bVar19 = bVar16 < (byte)pcVar12[1];
              if (bVar16 != pcVar12[1]) goto LAB_1062b175;
              pbVar11 = pbVar11 + 2;
              pcVar12 = pcVar12 + 2;
            } while (bVar16 != 0);
            iVar7 = 0;
LAB_1062b162:
            if (iVar7 == 0) {
              g_comment_record_kind = 9;
            }
            else {
              pcVar12 = "linker";
              do {
                bVar16 = *pbVar13;
                bVar19 = bVar16 < (byte)*pcVar12;
                if (bVar16 != *pcVar12) {
LAB_1062b1bc:
                  iVar7 = (1 - (uint)bVar19) - (uint)(bVar19 != 0);
                  goto LAB_1062b1a9;
                }
                if (bVar16 == 0) break;
                bVar16 = pbVar13[1];
                bVar19 = bVar16 < (byte)pcVar12[1];
                if (bVar16 != pcVar12[1]) goto LAB_1062b1bc;
                pbVar13 = pbVar13 + 2;
                pcVar12 = pcVar12 + 2;
              } while (bVar16 != 0);
              iVar7 = 0;
LAB_1062b1a9:
              if (iVar7 != 0) {
                message_arg = (pcVar8->value).ptr;
                goto LAB_1062b1c7;
              }
              g_comment_record_kind = 10;
            }
          }
        }
      }
    }
    pcVar8 = token_next(&g_token_position);
    if ((g_comment_record_text == (char *)0x0) && (pcVar8->code == '7')) {
      pcVar8 = pragma_string_argument();
      if (pcVar8 == (c1_token *)0x0) {
        return 0;
      }
      g_comment_record_text = (pcVar8->value).string.text;
      pcVar8 = token_next(&g_token_position);
    }
    (*g_token_source->stream->vtbl->unget)(g_token_source->stream,pcVar8);
    pcVar8 = pragma_warn_expected_token('~');
    if (pcVar8 == (c1_token *)0x0) {
      return 0;
    }
    goto LAB_10609d1b;
  case 0x14:
    (*g_idb->vtbl->idb_note_pragma)(g_idb,0x14);
    pcVar8 = pragma_warn_expected_token('v');
    if (pcVar8 == (c1_token *)0x0) {
      return 0;
    }
    pcVar8 = pragma_warn_expected_token('\x06');
    if (pcVar8 == (c1_token *)0x0) {
      return 0;
    }
    message_arg = (pcVar8->value).name;
    pcVar12 = "_TEXT";
    pbVar13 = (byte *)((fe_name *)message_arg)->text;
    pbVar11 = pbVar13;
    do {
      bVar16 = *pbVar11;
      bVar19 = bVar16 < (byte)*pcVar12;
      if (bVar16 != *pcVar12) {
LAB_1062b3d6:
        iVar7 = (1 - (uint)bVar19) - (uint)(bVar19 != 0);
        goto LAB_1062b39b;
      }
      if (bVar16 == 0) break;
      bVar16 = pbVar11[1];
      bVar19 = bVar16 < (byte)pcVar12[1];
      if (bVar16 != pcVar12[1]) goto LAB_1062b3d6;
      pbVar11 = pbVar11 + 2;
      pcVar12 = pcVar12 + 2;
    } while (bVar16 != 0);
    iVar7 = 0;
LAB_1062b39b:
    if (iVar7 == 0) {
      ppvVar15 = &g_code_seg_name;
      cStack_8 = '\0';
    }
    else {
      pcVar12 = "_DATA";
      pbVar11 = pbVar13;
      do {
        bVar16 = *pbVar11;
        bVar19 = bVar16 < (byte)*pcVar12;
        if (bVar16 != *pcVar12) {
LAB_1062b416:
          iVar7 = (1 - (uint)bVar19) - (uint)(bVar19 != 0);
          goto LAB_1062b406;
        }
        if (bVar16 == 0) break;
        bVar16 = pbVar11[1];
        bVar19 = bVar16 < (byte)pcVar12[1];
        if (bVar16 != pcVar12[1]) goto LAB_1062b416;
        pbVar11 = pbVar11 + 2;
        pcVar12 = pcVar12 + 2;
      } while (bVar16 != 0);
      iVar7 = 0;
LAB_1062b406:
      if (iVar7 == 0) {
        ppvVar15 = &g_data_seg_name;
        cStack_8 = '\x01';
      }
      else {
        pcVar12 = "_BSS";
        pbVar11 = pbVar13;
        do {
          bVar16 = *pbVar11;
          bVar19 = bVar16 < (byte)*pcVar12;
          if (bVar16 != *pcVar12) {
LAB_1062b459:
            iVar7 = (1 - (uint)bVar19) - (uint)(bVar19 != 0);
            goto LAB_1062b446;
          }
          if (bVar16 == 0) break;
          bVar16 = pbVar11[1];
          bVar19 = bVar16 < (byte)pcVar12[1];
          if (bVar16 != pcVar12[1]) goto LAB_1062b459;
          pbVar11 = pbVar11 + 2;
          pcVar12 = pcVar12 + 2;
        } while (bVar16 != 0);
        iVar7 = 0;
LAB_1062b446:
        if (iVar7 == 0) {
          ppvVar15 = &g_bss_seg_name;
          cStack_8 = '\x03';
        }
        else {
          pcVar12 = "CONST";
          do {
            bVar16 = *pbVar13;
            bVar19 = bVar16 < (byte)*pcVar12;
            if (bVar16 != *pcVar12) {
LAB_1062b49c:
              iVar7 = (1 - (uint)bVar19) - (uint)(bVar19 != 0);
              goto LAB_1062b489;
            }
            if (bVar16 == 0) break;
            bVar16 = pbVar13[1];
            bVar19 = bVar16 < (byte)pcVar12[1];
            if (bVar16 != pcVar12[1]) goto LAB_1062b49c;
            pbVar13 = pbVar13 + 2;
            pcVar12 = pcVar12 + 2;
          } while (bVar16 != 0);
          iVar7 = 0;
LAB_1062b489:
          if (iVar7 != 0) {
LAB_1062b1c7:
            iVar7 = 0x6d;
LAB_1062b1c9:
            diag_warning(1,iVar7,message_arg);
            pragma_skip_to_dash(pcVar8);
            return 0;
          }
          ppvVar15 = &g_const_seg_name;
          cStack_8 = '\x04';
        }
      }
    }
    pcVar8 = token_next(&g_token_position);
    if (pcVar8->code == '7') {
      pcVar8 = pragma_warn_expected_token('\x06');
      if (pcVar8 != (c1_token *)0x0) {
        pvVar10 = segment_lookup_or_declare((pcVar8->value).ptr,g_name_unnamed,cStack_8);
        *ppvVar15 = pvVar10;
        pragma_warn_expected_token('~');
        return 0;
      }
      return 0;
    }
    if (pcVar8->code == '~') {
      *ppvVar15 = (void *)0x0;
      return 0;
    }
    goto LAB_1062b2e6;
  case 0x15:
    if (g_block_depth != '\0') {
      diag_error(0x9c);
      return 0;
    }
    pcVar8 = pragma_warn_expected_token('v');
    if ((pcVar8 != (c1_token *)0x0) &&
       (pcVar8 = pragma_string_argument(), pcVar8 != (c1_token *)0x0)) {
      g_pragma_optimize_list = (pcVar8->value).string.text;
      pcVar8 = pragma_warn_expected_token('7');
      if ((pcVar8 != (c1_token *)0x0) && (pcVar8 = pragma_check_on_off(), pcVar8 != (c1_token *)0x0)
         ) {
        g_pragma_optimize_on = (pcVar8->value).words[0];
        pcVar8 = pragma_warn_expected_token('~');
        if (pcVar8 != (c1_token *)0x0) {
          if (g_pragma_optimize_on != 0) {
            if (*g_pragma_optimize_list == '\0') {
              uVar21 = il_function_option_word();
              opt_unpack_optimize_flags
                        (uVar21 & ~g_pragma_optimize_mask |
                         g_command_line_option_word & g_pragma_optimize_mask);
              return 0;
            }
            do {
              pcVar14 = g_pragma_optimize_letters;
              pcVar12 = g_pragma_optimize_list;
              do {
                if (*pcVar12 == pcVar14->letter) {
                  *pcVar14->flag = pcVar14->on_value;
                  pcVar12 = g_pragma_optimize_list;
                }
                pcVar1 = pcVar14 + 1;
                pcVar14 = pcVar14 + 1;
              } while (pcVar1->letter != '\0');
              g_pragma_optimize_list = pcVar12 + 1;
            } while (*g_pragma_optimize_list != '\0');
            return 0;
          }
          if (*g_pragma_optimize_list != '\0') {
            do {
              pcVar14 = g_pragma_optimize_letters;
              pcVar12 = g_pragma_optimize_list;
              do {
                if (*pcVar12 == pcVar14->letter) {
                  *pcVar14->flag = pcVar14->on_value == '\0';
                  pcVar12 = g_pragma_optimize_list;
                }
                pcVar1 = pcVar14 + 1;
                pcVar14 = pcVar14 + 1;
              } while (pcVar1->letter != '\0');
              g_pragma_optimize_list = pcVar12 + 1;
            } while (*g_pragma_optimize_list != '\0');
            return 0;
          }
          uVar21 = il_function_option_word();
          opt_unpack_optimize_flags(uVar21 & ~g_pragma_optimize_off_mask);
          return 0;
        }
      }
    }
    break;
  case 0x16:
    if (g_block_depth != '\0') {
      if (g_incremental != '\0') {
        diag_error(0x133);
        cStack_8 = '\x01';
        ppvVar15 = &g_data_seg_name;
        goto LAB_10609d4e;
      }
      diag_warning(1,0xb1,"data_seg");
    }
    cStack_8 = '\x01';
    ppvVar15 = &g_data_seg_name;
    goto LAB_10609d4e;
  case 0x18:
    cStack_8 = '\0';
    ppvVar15 = &g_code_seg_name;
    goto LAB_10609d4e;
  case 0x19:
    iVar7 = (*g_idb->vtbl->idb_note_pragma)(g_idb,0x19);
    if (iVar7 == 0) {
      diag_fatal(0x49,".\\p0pragma.c",0x8c6);
    }
    pcVar8 = pragma_parse_identifier(0x65);
    if (pcVar8 == (c1_token *)0x0) {
      g_pragma_inline_depth = 8;
    }
    else {
      g_pragma_inline_depth = *(ushort *)((int)&pcVar8->value + 8);
    }
    if (g_inline_level != 0) {
      il_emit_pragma_or_segment_record(0x20);
      return 0;
    }
    break;
  case 0x1a:
    iVar7 = (*g_idb->vtbl->idb_note_pragma)(g_idb,0x1a);
    if (iVar7 == 0) {
      diag_fatal(0x49,".\\p0pragma.c",0x8b9);
    }
    pcVar8 = pragma_parse_identifier(1);
    if (pcVar8 == (c1_token *)0x0) {
      g_pragma_inline_recursion = 0;
    }
    else {
      g_pragma_inline_recursion = (pcVar8->value).half;
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
    pcVar8 = pragma_parse_identifier(1);
    if (pcVar8 != (c1_token *)0x0) {
      g_pragma_auto_inline = (pcVar8->value).words[0] & 1;
      g_function_auto_inline = g_pragma_auto_inline;
      return 0;
    }
    g_pragma_auto_inline = 1;
    g_function_auto_inline = 1;
    return 0;
  case 0x1c:
    iVar7 = (*g_idb->vtbl->idb_note_pragma)(g_idb,0x1c);
    if (iVar7 == 0) {
      diag_fatal(0x49,".\\p0pragma.c",0x812);
    }
    pcVar8 = pragma_warn_expected_token('v');
    if (pcVar8 != (c1_token *)0x0) {
      do {
        pcVar8 = token_next(&g_token_position);
        cVar2 = pcVar8->code;
        if (cVar2 == '\x06') {
          pcVar12 = "disable";
          pbVar13 = (byte *)((pcVar8->value).name)->text;
          pbVar11 = pbVar13;
          do {
            bVar16 = *pbVar11;
            bVar19 = bVar16 < (byte)*pcVar12;
            if (bVar16 != *pcVar12) {
LAB_1062b5a1:
              iVar7 = (1 - (uint)bVar19) - (uint)(bVar19 != 0);
              goto LAB_1060a033;
            }
            if (bVar16 == 0) break;
            bVar16 = pbVar11[1];
            bVar19 = bVar16 < (byte)pcVar12[1];
            if (bVar16 != pcVar12[1]) goto LAB_1062b5a1;
            pbVar11 = pbVar11 + 2;
            pcVar12 = pcVar12 + 2;
          } while (bVar16 != 0);
          iVar7 = 0;
LAB_1060a033:
          if (iVar7 == 0) {
            bVar16 = 0xd;
          }
          else {
            pcVar12 = "error";
            pbVar11 = pbVar13;
            do {
              bVar16 = *pbVar11;
              bVar19 = bVar16 < (byte)*pcVar12;
              if (bVar16 != *pcVar12) {
LAB_1062b5e6:
                iVar7 = (1 - (uint)bVar19) - (uint)(bVar19 != 0);
                goto LAB_1062b5d8;
              }
              if (bVar16 == 0) break;
              bVar16 = pbVar11[1];
              bVar19 = bVar16 < (byte)pcVar12[1];
              if (bVar16 != pcVar12[1]) goto LAB_1062b5e6;
              pbVar11 = pbVar11 + 2;
              pcVar12 = pcVar12 + 2;
            } while (bVar16 != 0);
            iVar7 = 0;
LAB_1062b5d8:
            if (iVar7 == 0) {
              bVar16 = 0xe;
            }
            else {
              pcVar12 = "once";
              do {
                bVar16 = *pbVar13;
                bVar19 = bVar16 < (byte)*pcVar12;
                if (bVar16 != *pcVar12) {
LAB_1062b628:
                  iVar7 = (1 - (uint)bVar19) - (uint)(bVar19 != 0);
                  goto LAB_1062b61a;
                }
                if (bVar16 == 0) break;
                bVar16 = pbVar13[1];
                bVar19 = bVar16 < (byte)pcVar12[1];
                if (bVar16 != pcVar12[1]) goto LAB_1062b628;
                pbVar13 = pbVar13 + 2;
                pcVar12 = pcVar12 + 2;
              } while (bVar16 != 0);
              iVar7 = 0;
LAB_1062b61a:
              if (iVar7 != 0) {
                pcVar12 = "push";
                pbVar13 = (byte *)((pcVar8->value).name)->text;
                pbVar11 = pbVar13;
                goto LAB_1062b665;
              }
              bVar16 = 5;
            }
          }
        }
        else if (cVar2 == 'e') {
          switch((pcVar8->value).words[2]) {
          case 1:
            bVar16 = 1;
            break;
          case 2:
            bVar16 = 2;
            break;
          case 3:
            bVar16 = 3;
            break;
          case 4:
            bVar16 = 4;
            break;
          default:
            diag_warning(1,0x268,(pcVar8->value).words[2],1,4);
            pragma_skip_to_dash(pcVar8);
            return 0;
          }
        }
        else {
          if (cVar2 != 'g') goto LAB_1062b7aa;
          bVar16 = 0;
        }
        pcVar8 = pragma_warn_expected_token('6');
        if (pcVar8 == (c1_token *)0x0) {
          return 0;
        }
        pcVar8 = token_next(&g_token_position);
        cVar2 = pcVar8->code;
        while (cVar2 == 'e') {
          pragma_warning_check_number((pcVar8->value).words[2],bVar16);
          pcVar8 = token_next(&g_token_position);
          cVar2 = pcVar8->code;
        }
        if (pcVar8->code == '~') {
          iVar7 = pragma_dispatch_return_zero_tail();
          return iVar7;
        }
        if (pcVar8->code != '\x7f') {
          (*g_token_source->stream->vtbl->unget)(g_token_source->stream,pcVar8);
          pragma_warn_expected_token('~');
          return 0;
        }
      } while( true );
    }
    break;
  case 0x1d:
    g_compile_flags_c4 = g_compile_flags_c4 | 0x8000;
    pragma_hdrstop(&g_pch_file_name);
    g_compile_flags_c4 = g_compile_flags_c4 & 0xffff7fff;
    return (int)g_token_pragma_hdrstop;
  case 0x1e:
  case 0x1f:
  case 0x21:
    iVar7 = 0x9d;
    goto LAB_1062ae04;
  case 0x20:
    iVar7 = (*g_idb->vtbl->idb_note_pragma)(g_idb,0x20);
    if (iVar7 == 0) {
      diag_fatal(0x49,".\\p0pragma.c",0x5d8);
    }
    pcVar8 = pragma_parse_argument(7);
    if (pcVar8 != (c1_token *)0x0) {
      pcVar12 = setlocale(0,(pcVar8->value).string.text);
      if (pcVar12 == (char *)0x0) {
        diag_error(0xaf,(pcVar8->value).ptr);
      }
      lex_clear_lead_byte_classes();
      lex_mark_mbcs_lead_bytes();
      return 0;
    }
    break;
  case 0x22:
    if (g_block_depth != '\0') {
      diag_error(0x9c);
      return 0;
    }
    pcVar8 = pragma_parse_identifier(1);
    if (pcVar8 == (c1_token *)0x0) {
      g_string_pooling = g_opt_Gf;
    }
    else {
      g_string_pooling = (pcVar8->value).spec.words.storage & 1;
    }
    g_string_pooling_readonly_active = (pcVar8 != (c1_token *)0x0) - 1U & g_string_pooling_readonly;
    return 0;
  case 0x25:
    pragma_once();
    return 0;
  case 0x2b:
    pcVar8 = token_next(&g_token_position);
    if (pcVar8->code == '-') {
      (*g_token_source->stream->vtbl->unget)(g_token_source->stream,pcVar8);
      return 0;
    }
    if (pcVar8->code != 'v') {
      (*g_token_source->stream->vtbl->unget)(g_token_source->stream,pcVar8);
      pragma_warn_expected_token('v');
      return 0;
    }
    pcVar8 = token_next(&g_token_position);
    if (pcVar8->code != '\x06') {
      if (pcVar8->code != '~') {
        (*g_token_source->stream->vtbl->unget)(g_token_source->stream,pcVar8);
        pragma_warn_expected_token('\x06');
        return 0;
      }
      return 0;
    }
    pcVar12 = "browser";
    message_arg = ((pcVar8->value).name)->text;
    browser_cursor = message_arg;
    do {
      bVar16 = *browser_cursor;
      bVar19 = bVar16 < (byte)*pcVar12;
      if (bVar16 != *pcVar12) {
LAB_1062b993:
        iVar7 = (1 - (uint)bVar19) - (uint)(bVar19 != 0);
        goto LAB_1062b980;
      }
      if (bVar16 == 0) break;
      bVar16 = browser_cursor[1];
      bVar19 = bVar16 < (byte)pcVar12[1];
      if (bVar16 != pcVar12[1]) goto LAB_1062b993;
      browser_cursor = browser_cursor + 2;
      pcVar12 = pcVar12 + 2;
    } while (bVar16 != 0);
    iVar7 = 0;
LAB_1062b980:
    if (iVar7 == 0) {
      pragma_component();
      return 0;
    }
    pcVar12 = "minrebuild";
    minrebuild_cursor = message_arg;
    do {
      bVar16 = *minrebuild_cursor;
      bVar19 = bVar16 < (byte)*pcVar12;
      if (bVar16 != *pcVar12) {
LAB_1062b9da:
        iVar7 = (1 - (uint)bVar19) - (uint)(bVar19 != 0);
        goto LAB_1062b9c7;
      }
      if (bVar16 == 0) break;
      bVar16 = minrebuild_cursor[1];
      bVar19 = bVar16 < (byte)pcVar12[1];
      if (bVar16 != pcVar12[1]) goto LAB_1062b9da;
      minrebuild_cursor = minrebuild_cursor + 2;
      pcVar12 = pcVar12 + 2;
    } while (bVar16 != 0);
    iVar7 = 0;
LAB_1062b9c7:
    if (iVar7 == 0) {
      pragma_component_minrebuild();
      return 0;
    }
    pcVar12 = "mintypeinfo";
    mintypeinfo_cursor = message_arg;
    do {
      bVar16 = *mintypeinfo_cursor;
      bVar19 = bVar16 < (byte)*pcVar12;
      if (bVar16 != *pcVar12) {
LAB_1062ba21:
        iVar7 = (1 - (uint)bVar19) - (uint)(bVar19 != 0);
        goto LAB_1062ba0e;
      }
      if (bVar16 == 0) break;
      bVar16 = mintypeinfo_cursor[1];
      bVar19 = bVar16 < (byte)pcVar12[1];
      if (bVar16 != pcVar12[1]) goto LAB_1062ba21;
      mintypeinfo_cursor = mintypeinfo_cursor + 2;
      pcVar12 = pcVar12 + 2;
    } while (bVar16 != 0);
    iVar7 = 0;
LAB_1062ba0e:
    if (iVar7 == 0) {
      pragma_component_mintypeinfo();
      return 0;
    }
    iVar7 = 0xae;
    goto LAB_1062b1c9;
  case 0x2c:
    g_comment_record_kind = 3;
    pcVar8 = pragma_string_argument();
    if (pcVar8 == (c1_token *)0x0) {
      return 0;
    }
    g_comment_record_text = (pcVar8->value).string.text;
LAB_10609d1b:
    if (g_comment_record_text != (char *)0x0) {
      il_emit_pragma_or_segment_record(0xb);
      return 0;
    }
    break;
  case 0x2d:
    if (g_block_depth != '\0') {
      if (g_incremental != '\0') {
        diag_error(0x133);
        cStack_8 = '\x03';
        ppvVar15 = &g_bss_seg_name;
        goto LAB_10609d4e;
      }
      diag_warning(1,0xb1,"bss_seg");
    }
    cStack_8 = '\x03';
    ppvVar15 = &g_bss_seg_name;
    goto LAB_10609d4e;
  case 0x2e:
    if (g_block_depth != '\0') {
      if (g_incremental != '\0') {
        diag_error(0x133);
        cStack_8 = '\x04';
        ppvVar15 = &g_const_seg_name;
        goto LAB_10609d4e;
      }
      diag_warning(1,0xb1,"const_seg");
    }
    cStack_8 = '\x04';
    ppvVar15 = &g_const_seg_name;
LAB_10609d4e:
    (*g_idb->vtbl->idb_note_pragma)(g_idb,uVar21);
    pcVar8 = pragma_warn_expected_token('v');
    if (pcVar8 != (c1_token *)0x0) {
      pcVar8 = token_next(&g_token_position);
      if (pcVar8->code != '\a') {
        if (pcVar8->code == '~') {
          *ppvVar15 = (void *)0x0;
          return 0;
        }
        (*g_token_source->stream->vtbl->unget)(g_token_source->stream,pcVar8);
        pragma_string_argument();
        return 0;
      }
      (*g_token_source->stream->vtbl->unget)(g_token_source->stream,pcVar8);
      pcVar8 = pragma_string_argument();
      pcVar12 = (pcVar8->value).string.text;
      if (*pcVar12 == '\0') {
        iVar7 = 0x26a;
      }
      else {
        section_name = name_intern(pcVar12);
        pcVar8 = token_next(&g_token_position);
        section_class = g_name_unnamed;
        if (pcVar8->code != '7') {
          if (pcVar8->code != '~') {
LAB_1062b2e6:
            (*g_token_source->stream->vtbl->unget)(g_token_source->stream,pcVar8);
            pragma_warn_expected_token('7');
            return 0;
          }
          (*g_token_source->stream->vtbl->unget)(g_token_source->stream,pcVar8);
LAB_10609ddf:
          pvVar10 = segment_lookup_or_declare(section_name,section_class,cStack_8);
          *ppvVar15 = pvVar10;
          pragma_warn_expected_token('~');
          return 0;
        }
        pcVar8 = pragma_string_argument();
        if (pcVar8 == (c1_token *)0x0) {
          return 0;
        }
        pcVar12 = (pcVar8->value).string.text;
        if (*pcVar12 != '\0') {
          section_class = name_intern(pcVar12);
          goto LAB_10609ddf;
        }
        iVar7 = 0x26a;
      }
LAB_1062ae04:
      level = 1;
LAB_1062acf3:
      diag_warning(level,iVar7);
      pragma_skip_to_dash(pcVar8);
      iVar7 = pragma_dispatch_return_zero_tail();
      return iVar7;
    }
  }
  return 0;
  while( true ) {
    bVar16 = pbVar11[1];
    bVar19 = bVar16 < (byte)pcVar12[1];
    if (bVar16 != pcVar12[1]) goto LAB_1062b6db;
    pbVar11 = pbVar11 + 2;
    pcVar12 = pcVar12 + 2;
    if (bVar16 == 0) break;
LAB_1062b665:
    bVar16 = *pbVar11;
    bVar19 = bVar16 < (byte)*pcVar12;
    if (bVar16 != *pcVar12) {
LAB_1062b6db:
      iVar7 = (1 - (uint)bVar19) - (uint)(bVar19 != 0);
      goto LAB_1062b68b;
    }
    if (bVar16 == 0) break;
  }
  iVar7 = 0;
LAB_1062b68b:
  if (iVar7 == 0) {
    pragma_warning_push();
    pcVar8 = token_next(&g_token_position);
    bVar16 = pcVar8->code;
    if (bVar16 == 0x37) {
      pcVar8 = pragma_warn_expected_token('e');
      if (pcVar8 == (c1_token *)0x0) {
        return 0;
      }
      cVar18 = (pcVar8->value).words[2];
      if ((0 < (int)cVar18) && ((int)cVar18 < 5)) {
        g_warning_state->level = cVar18;
        pragma_warn_expected_token('~');
        return 0;
      }
      uVar21 = 4;
      uVar20 = 1;
      iVar7 = 0x268;
    }
    else {
      if (bVar16 == 0x7e) {
        return 0;
      }
      uVar21 = (uint)bVar16;
      uVar20 = 0x7e;
      cVar18 = 0x37;
      iVar7 = 0xc4;
    }
    diag_warning(1,iVar7,cVar18,uVar20,uVar21);
    pragma_skip_to_dash(pcVar8);
    return 0;
  }
  pcVar12 = "pop";
  do {
    bVar16 = *pbVar13;
    bVar19 = bVar16 < (byte)*pcVar12;
    if (bVar16 != *pcVar12) {
LAB_1062b730:
      iVar7 = (1 - (uint)bVar19) - (uint)(bVar19 != 0);
      goto LAB_1062b70f;
    }
    if (bVar16 == 0) break;
    bVar16 = pbVar13[1];
    bVar19 = bVar16 < (byte)pcVar12[1];
    if (bVar16 != pcVar12[1]) goto LAB_1062b730;
    pbVar13 = pbVar13 + 2;
    pcVar12 = pcVar12 + 2;
  } while (bVar16 != 0);
  iVar7 = 0;
LAB_1062b70f:
  if (iVar7 == 0) {
    pragma_warning_pop();
    pragma_warn_expected_token('~');
    return 0;
  }
LAB_1062b7aa:
  diag_warning(1,0x267);
  pragma_skip_to_dash(pcVar8);
  return 0;
}

