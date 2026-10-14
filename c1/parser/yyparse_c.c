int __fastcall yyparse_c(c1_yyparse_state *parser)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  c1_token *pcVar4;
  c1_declaration *pcVar5;
  c1_symbol *pcVar6;
  uchar *puVar7;
  c1_u32 cVar8;
  c1_u32 cVar9;
  short *psVar10;
  c1_scope_object *pcVar11;
  c1_u8 cVar12;
  c1_u8 cVar13;
  undefined4 uVar14;
  undefined3 uVar15;
  uchar *puVar16;
  c1_u8 cVar17;
  c1_u16 cVar18;
  int iVar19;
  c1_token *pcVar20;
  fe_arena *pfVar21;
  void *result_3;
  c1_scope_entries cVar22;
  c1_type *pcVar23;
  int iVar24;
  void *result_2;
  c1_node *pcVar25;
  void *result;
  c1_yystype *pcVar26;
  c1_type_declarator *pcVar27;
  ushort uVar28;
  undefined2 uVar29;
  c1_yyparse_state *pcVar30;
  int iVar31;
  uint uVar32;
  c1_yy_token_insertion *pcVar33;
  uint uVar34;
  uint uVar35;
  ushort *puVar36;
  void *pvVar37;
  short sVar38;
  c1_yystype *pcVar39;
  uint *puVar40;
  c1_declaration *decl;
  c1_yystype *pcVar41;
  c1_decl_specifiers *pcVar42;
  uint *level_spec_dst;
  c1_node *pcVar43;
  bool bVar44;
  longlong value;
  ulonglong uVar45;
  undefined1 uVar46;
  undefined1 uVar47;
  undefined1 uVar48;
  undefined1 uVar49;
  undefined2 uVar50;
  ushort local_54 [2];
  uint mods_position;
  ushort local_4c [2];
  uint mods_position_2;
  uint type_name_word;
  c1_type cStack_38;
  c1_type local_28;
  c1_yystype local_18;
  short rule;
  c1_declaration *decl_2;
  c1_declaration *decl_3;
  c1_declaration *decl_4;
  void *result_4;
  
  pcVar30 = (c1_yyparse_state *)(parser->ssp + 1);
  parser->ssp = (short *)pcVar30;
  if (parser + 1 < pcVar30) {
    iVar19 = yy_stack_overflow();
    return iVar19;
  }
  do {
    *(short *)&pcVar30->lookahead = parser->state;
    pcVar26 = parser->vsp;
    parser->vsp = pcVar26 + 1;
    pcVar39 = &g_yyval;
    pcVar26 = pcVar26 + 1;
    for (iVar19 = 6; iVar19 != 0; iVar19 = iVar19 + -1) {
      pcVar26->words[0] = (c1_u32)pcVar39->ptr;
      pcVar39 = (c1_yystype *)(&pcVar39->ptr + 1);
      pcVar26 = (c1_yystype *)&(pcVar26->string).length;
    }
LAB_10615c08:
    sVar38 = g_yy_pact[parser->state];
    if (-1000 < sVar38) {
      if (parser->lookahead == (c1_token *)0x0) {
        pcVar20 = yylex_c();
        parser->lookahead = pcVar20;
      }
      pcVar20 = parser->lookahead;
      if (pcVar20 == (c1_token *)0x0) {
        uVar28 = 0xffff;
      }
      else {
        uVar28 = (ushort)(byte)(&g_token_class)[pcVar20->code];
      }
      sVar38 = sVar38 + uVar28;
      if ((sVar38 < 0) || (0x52d < sVar38)) goto LAB_10615c30;
      if (pcVar20 == (c1_token *)0x0) {
        uVar32 = 0xffffffff;
      }
      else {
        uVar32 = (uint)(byte)(&g_token_class)[pcVar20->code];
      }
      sVar38 = g_yy_action[sVar38];
      uVar35 = (uint)g_yy_chk[sVar38];
      if (uVar35 != uVar32) goto LAB_10615c30;
      pcVar26 = &parser->lookahead->value;
      pcVar39 = &g_yyval;
      for (iVar19 = 6; iVar19 != 0; iVar19 = iVar19 + -1) {
        pcVar39->ptr = pcVar26->ptr;
        pcVar26 = (c1_yystype *)(&pcVar26->ptr + 1);
        pcVar39 = (c1_yystype *)(&pcVar39->ptr + 1);
      }
      parser->state = sVar38;
      parser->lookahead = (c1_token *)0x0;
      uVar45 = CONCAT44(uVar35,g_yyval.ptr);
      if (0 < parser->errflag) {
        parser->errflag = parser->errflag + -1;
        uVar45 = CONCAT44(uVar35,g_yyval.ptr);
      }
      goto switchD_10615cfc_caseD_2;
    }
LAB_10615c30:
    rule = g_yy_def[parser->state];
    if (rule == -2) {
      if (parser->lookahead == (c1_token *)0x0) {
        pcVar20 = yylex_c();
        parser->lookahead = pcVar20;
      }
      puVar36 = (ushort *)(g_yy_exca + g_yy_exidx[parser->state]);
      while( true ) {
        if (parser->lookahead == (c1_token *)0x0) {
          uVar28 = 0xffff;
        }
        else {
          uVar28 = (ushort)(byte)(&g_token_class)[parser->lookahead->code];
        }
        if ((*puVar36 == uVar28) || ((short)*puVar36 < 0)) break;
        puVar36 = puVar36 + 2;
      }
      rule = puVar36[1];
      if (rule < 0) {
        return 0;
      }
    }
    if (rule != 0) {
switchD_1063069f_default:
      pcVar26 = parser->vsp;
      parser->ssp = parser->ssp + -(uint)g_yy_r2[rule];
      bVar2 = g_yy_r2[rule];
      parser->vsp = pcVar26 + -(uint)bVar2;
      bVar3 = g_yy_r1[rule];
      pcVar39 = pcVar26 + -(uint)bVar2 + 1;
      pcVar41 = &g_yyval;
      for (iVar19 = 6; iVar19 != 0; iVar19 = iVar19 + -1) {
        pcVar41->words[0] = (c1_u32)pcVar39->ptr;
        pcVar39 = (c1_yystype *)&(pcVar39->string).length;
        pcVar41 = (c1_yystype *)(&pcVar41->ptr + 1);
      }
      iVar19 = (int)(short)(ushort)bVar3;
      sVar38 = *parser->ssp + g_yy_pgo[iVar19] + 1;
      if ((0x52d < sVar38) ||
         (sVar38 = g_yy_action[sVar38], parser->state = sVar38, (int)g_yy_chk[sVar38] != -iVar19)) {
        parser->state = g_yy_action[g_yy_pgo[iVar19]];
      }
      decl = (c1_declaration *)g_arenas[3].cur;
      iVar31 = g_paren_depth;
      iVar19 = g_token_arena_index;
      pvVar37 = g_name_ellipsis;
      uVar15 = g_yyval.value._1_3_;
      puVar7 = g_arenas[3].cur;
      uVar45 = (ulonglong)CONCAT24(rule,g_yyval.ptr);
      iVar24 = g_nested_declaration_depth;
      switch(rule) {
      case 1:
        goto switchD_10615cfc_caseD_0;
      case 2:
        if (g_ms_extensions == '\0') {
          diag_error(0xb7);
        }
        else {
          diag_warning(4,0xce,0xce);
        }
switchD_10615cfc_caseD_0:
        uVar45 = (ulonglong)g_yyval.words[0];
        if (g_error_count != 0) {
          return g_error_count;
        }
        break;
      case 5:
        tu_external_declaration_end();
        uVar45 = (ulonglong)g_yyval.words[0];
        break;
      case 6:
        pch_hdrstop();
        uVar45 = (ulonglong)g_yyval.words[0];
        break;
      case 7:
        pch_creation_point();
        uVar45 = (ulonglong)g_yyval.words[0];
        break;
      case 8:
        pp_line_after_pch_options();
        uVar45 = (ulonglong)g_yyval.words[0];
        break;
      case 9:
        g_compile_flags_c8 = g_compile_flags_c8 & 0xffffffbf;
        uVar45 = (ulonglong)CONCAT24(rule,g_yyval.ptr);
        if (pcVar26[-1].ptr != (void *)0x0) {
          func_body_begin();
          uVar45 = (ulonglong)g_yyval.words[0];
        }
        break;
      case 10:
        if (pcVar26[-3].ptr != (void *)0x0) {
          func_definition_end();
        }
        g_compile_flags_c8 = g_compile_flags_c8 & 0xfffffdff;
        uVar45 = (ulonglong)g_yyval.words[0];
        break;
      case 0xb:
        uVar45 = (ulonglong)CONCAT24(rule,g_yyval.ptr);
        if ((g_compile_flags_c4 & 0x1000000) != 0) {
          diag_warning(4,0xda,0xda);
          uVar45 = (ulonglong)g_yyval.words[0];
        }
        break;
      case 0xc:
        uVar45 = (ulonglong)CONCAT24(rule,g_yyval.ptr);
        if (g_ms_extensions == '\0') {
          iVar19 = yyparse_c_external_declaration_fragment(parser);
          return iVar19;
        }
        break;
      case 0xd:
        uVar45 = (ulonglong)CONCAT24(rule,g_yyval.ptr);
        if ((g_compile_flags_c4 & 0x1000000) == 0) goto switchD_10615cfc_caseD_84;
        break;
      case 0xe:
        yy_errok(parser);
        goto LAB_10630829;
      case 0xf:
        parse_skip_to_closing_brace();
        stmt_block_end();
        func_definition_end();
        yy_errok(parser);
        parser->lookahead = (c1_token *)0x0;
LAB_10630829:
        g_paren_depth = 0;
        g_compile_flags_c4 = g_compile_flags_c4 & 0xff7fffff;
        uVar45 = (ulonglong)g_yyval.words[0];
        break;
      case 0x11:
        diag_error(0x1c1);
        parse_skip_to_closing_brace();
        if (g_input_ptr != (byte *)0x0) {
          g_input_ptr = g_input_ptr + 1;
        }
        yy_errok(parser);
        parser->lookahead = (c1_token *)0x0;
        uVar45 = (ulonglong)g_yyval.words[0];
        break;
      case 0x12:
        g_compile_flags_c4 = g_compile_flags_c4 & 0xfeffffff;
        pcVar39 = pcVar26 + -1;
        g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfc;
        pcVar25 = pcVar26->node;
        pcVar25->unk0c = (c1_u32)pcVar39->ptr;
        pcVar25->left = *(void **)((int)pcVar26 + -0x14);
        pcVar25->right = *(void **)((int)pcVar26 + -0x10);
        decl_apply_specifiers(pcVar26->decl->declarator,&pcVar39->spec);
        decl_finish_declarator(pcVar26->decl->declarator);
        pcVar20 = parser->lookahead;
        if (pcVar20 == (c1_token *)0x0) {
          pcVar20 = yylex_c();
LAB_1063089d:
          parser->lookahead = pcVar20;
        }
        else if (pcVar20->code == '\x06') {
          pcVar20 = decl_specifier_from_tag(pcVar20);
          goto LAB_1063089d;
        }
        pcVar20 = parser->lookahead;
        switch(pcVar20->code) {
        case '\x06':
          pcVar6 = pcVar26->decl->sym;
          if (pcVar6 == (c1_symbol *)0x0) {
            diag_error(0x3d,(char)(pcVar20->value).words[0]);
            parser->lookahead = g_token_semicolon;
            uVar45 = (ulonglong)g_yyval.words[0];
            goto switchD_10615cfc_caseD_2;
          }
          pcVar27 = pcVar26->decl->declarator;
          bVar2 = pcVar27->flags30;
          if ((bVar2 & 8) == 0) {
            uVar46 = SUB41(pcVar6,0);
            if ((bVar2 & 0x10) == 0) {
              uVar48 = (undefined1)(pcVar20->value).words[0];
              uVar47 = 0x1a;
            }
            else {
              uVar48 = (undefined1)(pcVar20->value).words[0];
              uVar47 = 0x19;
            }
LAB_1063094c:
            diag_error(CONCAT11(1,uVar47),uVar46,uVar48);
          }
          else {
            if (*(int *)((int)pcVar27->params + 4) == 2) {
              uVar48 = (undefined1)(pcVar20->value).words[0];
              uVar46 = 0x49;
              uVar47 = 0xf5;
              goto LAB_1063094c;
            }
            diag_error(0x118,(char)(pcVar20->value).words[0]);
          }
          pcVar20 = parse_skip_to_token_in_set(parser->lookahead,0x7f,0x75,1);
          parser->lookahead = pcVar20;
          if (pcVar20->code == 'u') {
            parse_skip_to_closing_brace();
            g_input_ptr = g_input_ptr + 1;
            parser->lookahead = g_token_semicolon;
          }
          break;
        default:
          parse_report_missing_token(pcVar20,0x75);
          (*g_token_source->stream->vtbl->unget)(g_token_source->stream,parser->lookahead);
          parser->lookahead = g_token_semicolon;
          break;
        case '\"':
        case '$':
          result_4 = pcVar26->decl->sym;
          if (((result_4 == (void *)0x0) ||
              (pvVar37 = pcVar26->decl->declarator->params, pvVar37 == (void *)0x0)) ||
             (*(int *)((int)pvVar37 + 4) == 2)) goto switchD_10615ec3_caseD_75;
          diag_error(0x1bc,(char)result_4);
          (*g_token_source->stream->vtbl->unget)(g_token_source->stream,parser->lookahead);
          parser->lookahead = g_token_semicolon;
          break;
        case 'u':
switchD_10615ec3_caseD_75:
          func_definition_begin(pcVar26->ptr,(int *)&pcVar39->value);
          uVar45 = CONCAT44(pcVar26->decl->sym,pcVar26->decl->sym);
          goto switchD_10615cfc_caseD_2;
        }
        g_compile_flags_c8 = g_compile_flags_c8 | 0x200;
        uVar45 = 0;
        break;
      case 0x14:
        g_compile_flags_c8 = g_compile_flags_c8 | 0x40;
        uVar45 = (ulonglong)CONCAT24(rule,g_yyval.ptr);
        break;
      case 0x15:
      case 0x83:
        goto switchD_10615cfc_caseD_14;
      case 0x1b:
        diag_error(0x92,0x37,(char)pcVar26->words[0]);
        yy_errok(parser);
        parser->lookahead = (c1_token *)0x0;
        uVar45 = (ulonglong)g_yyval.words[0];
        break;
      case 0x1c:
        pcVar5 = pcVar26->decl;
        pcVar42 = g_decl_specifiers_by_level + g_paren_depth;
        cVar17 = (pcVar42->words).inlining;
        cVar12 = (pcVar42->words).declspec;
        cVar13 = (pcVar42->words).allocate;
        (pcVar5->spec).storage = (pcVar42->words).storage;
        (pcVar5->spec).inlining = cVar17;
        (pcVar5->spec).declspec = cVar12;
        (pcVar5->spec).allocate = cVar13;
        (pcVar5->spec).segment = g_decl_specifiers_by_level[iVar31].words.segment;
        pcVar42 = g_decl_specifiers_by_level + iVar31;
        cVar17 = (pcVar42->words).pad09[0];
        cVar12 = (pcVar42->words).pad09[1];
        cVar13 = (pcVar42->words).pad09[2];
        (pcVar5->spec).flags8 = (pcVar42->words).flags8;
        (pcVar5->spec).pad09[0] = cVar17;
        (pcVar5->spec).pad09[1] = cVar12;
        (pcVar5->spec).pad09[2] = cVar13;
        decl_apply_specifiers(pcVar26->decl->declarator,g_decl_specifiers_by_level + g_paren_depth);
        decl_finish_declarator(pcVar26->decl->declarator);
        decl_check_old_style_formal(pcVar26->decl,g_decl_specifiers_by_level + g_paren_depth);
        uVar45 = (ulonglong)g_yyval.words[0];
        break;
      case 0x1d:
        g_yyval.spec.type = g_type_int;
        g_yyval.spec.words.segment = (void *)0x0;
        g_yyval.words[2] = 0;
        g_compile_flags_c4 = g_compile_flags_c4 | 0x1000000;
        g_yyval.words[0] = 0x12;
        pcVar26 = &g_yyval;
        pcVar42 = g_decl_specifiers_by_level + g_paren_depth;
        for (iVar19 = 6; iVar19 != 0; iVar19 = iVar19 + -1) {
          *(void **)&pcVar42->words = pcVar26->ptr;
          pcVar26 = (c1_yystype *)(&pcVar26->ptr + 1);
          pcVar42 = (c1_decl_specifiers *)&(pcVar42->words).segment;
        }
        g_paren_level_flags[iVar31] = g_paren_level_flags[iVar31] & 0xfc;
        uVar45 = (ulonglong)g_yyval.words[0];
        break;
      case 0x1f:
        if ((parser->lookahead == (c1_token *)0x0) || (parser->lookahead->code != 'v')) {
          pcVar42 = g_decl_specifiers_by_level + g_paren_depth;
          for (iVar19 = 6; iVar19 != 0; iVar19 = iVar19 + -1) {
            *(void **)&pcVar42->words = pcVar26->ptr;
            pcVar26 = (c1_yystype *)&(pcVar26->string).length;
            pcVar42 = (c1_decl_specifiers *)&(pcVar42->words).segment;
          }
          g_paren_level_flags[iVar31] = g_paren_level_flags[iVar31] | 1;
          uVar45 = (ulonglong)g_yyval.words[0];
        }
        else {
          level_spec_dst = (uint *)(&g_decl_specifiers_by_level_base + g_paren_depth * 0x18);
          for (iVar19 = 6; iVar19 != 0; iVar19 = iVar19 + -1) {
            *level_spec_dst = (uint)pcVar26->ptr;
            pcVar26 = (c1_yystype *)&(pcVar26->string).length;
            level_spec_dst = level_spec_dst + 1;
          }
          pbVar1 = (byte *)((int)&g_function_tuple_count + iVar31 + 3);
          *pbVar1 = *pbVar1 | 1;
          uVar45 = (ulonglong)CONCAT24(rule,g_yyval.ptr);
        }
        break;
      case 0x20:
        uVar45 = (ulonglong)CONCAT24(rule,g_yyval.ptr);
        if (((pcVar26->spec).tag_insert != (_func_241 *)0x0) &&
           (uVar45 = (ulonglong)CONCAT24(rule,g_yyval.ptr),
           (pcVar26->spec).named.sym != (c1_symbol *)0x0)) {
          (*(pcVar26->spec).tag_insert)((pcVar26->spec).named.sym);
          uVar45 = (ulonglong)g_yyval.words[0];
        }
        break;
      case 0x21:
        g_compile_flags_c4 = g_compile_flags_c4 | 0x80000000;
        bVar44 = g_token_arena_index == 0;
        pcVar26 = &g_yyval;
        puVar40 = &g_yylval;
        for (iVar31 = 6; iVar31 != 0; iVar31 = iVar31 + -1) {
          *puVar40 = (uint)pcVar26->ptr;
          pcVar26 = (c1_yystype *)(&pcVar26->ptr + 1);
          puVar40 = puVar40 + 1;
        }
        if (bVar44) {
          pcVar20 = (c1_token *)pool_alloc_raw(&g_pool_default,0x20);
        }
        else {
          pfVar21 = g_arenas + iVar19;
          pcVar20 = (c1_token *)pfVar21->cur;
          pcVar4 = (c1_token *)g_arenas[iVar19].end;
          pfVar21->cur = &pcVar20[1].code;
          if (pcVar4 < pcVar20 + 1) {
            arena_grow(pfVar21);
          }
        }
        if (pcVar20 == (c1_token *)0x0) {
          pcVar20 = (c1_token *)0x0;
        }
        else {
          pcVar20->code = '\"';
          puVar40 = &g_yylval;
          pcVar26 = &pcVar20->value;
          for (iVar19 = 6; iVar19 != 0; iVar19 = iVar19 + -1) {
            pcVar26->words[0] = *puVar40;
            puVar40 = puVar40 + 1;
            pcVar26 = (c1_yystype *)((int)pcVar26 + 4);
          }
        }
        pcVar20 = decl_specifier_from_tag(pcVar20);
        g_compile_flags_c4 = g_compile_flags_c4 & 0x7fffffff;
        pcVar26 = &pcVar20->value;
        pcVar39 = &g_yyval;
        for (iVar19 = 6; uVar45 = (ulonglong)g_yyval.words[0], iVar19 != 0; iVar19 = iVar19 + -1) {
          pcVar39->words[0] = (c1_u32)pcVar26->ptr;
          pcVar26 = (c1_yystype *)((int)pcVar26 + 4);
          pcVar39 = (c1_yystype *)(&pcVar39->ptr + 1);
        }
        break;
      case 0x22:
        g_yyval.spec.type = esu_finish_struct_specifier();
        uVar45 = (ulonglong)g_yyval.words[0];
        break;
      case 0x23:
        g_yyval.spec.type = decl_check_empty_enumeration();
        uVar45 = (ulonglong)g_yyval.words[0];
        break;
      case 0x24:
        if ((pcVar26->spec).tag_insert != (_func_241 *)0x0) {
          (*(pcVar26->spec).tag_insert)((pcVar26->spec).named.sym);
        }
        esu_struct_body_begin((pcVar26->spec).named.tag,(pcVar26->spec).type);
        uVar45 = (ulonglong)g_yyval.words[0];
        break;
      case 0x28:
        uVar45 = (ulonglong)CONCAT24(rule,g_yyval.ptr);
        if ((&pcVar26->spec)[-1].tag_insert != (_func_241 *)0x0) {
          (*(&pcVar26->spec)[-1].tag_insert)((&pcVar26->spec)[-1].named.sym);
          uVar45 = (ulonglong)g_yyval.words[0];
        }
        break;
      case 0x2b:
        value = enum_warn_value_wrapped
                          (CONCAT26((short)((uint)g_enum_last_value_high >> 0x10),
                                    CONCAT15((char)((uint)g_enum_last_value_high >> 8),
                                             CONCAT14((char)g_enum_last_value_high,g_enum_last_value
                                                     ))),pcVar26->ptr);
        g_enum_last_value_high = (int)((ulonglong)value >> 0x20);
        g_enum_last_value = (uint)value;
        decl_declare_enumerator(pcVar26->ptr,g_current_enum_type,value);
        uVar45 = (ulonglong)g_yyval.words[0];
        break;
      case 0x2c:
        decl_declare_enumerator
                  (pcVar26[-2].ptr,g_current_enum_type,
                   CONCAT26((short)(pcVar26->words[1] >> 0x10),
                            CONCAT15((char)(pcVar26->words[1] >> 8),(int5)pcVar26->value)));
        uVar45 = (ulonglong)g_yyval.words[0];
        if (g_nested_declaration_depth == 0) {
          arena_reset_ptr(g_arenas + 3);
          uVar45 = (ulonglong)g_yyval.words[0];
        }
        break;
      case 0x2f:
        if (g_nested_declaration_depth == 0) {
          arena_reset_ptr(g_arenas + 3);
        }
        g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfc;
        uVar45 = (ulonglong)g_yyval.words[0];
        break;
      case 0x30:
        g_arenas[3].cur = g_arenas[3].cur + 0x30;
        if (g_arenas[3].end < g_arenas[3].cur) {
          arena_grow(g_arenas + 3);
        }
        if (decl == (c1_declaration *)0x0) {
          decl = (c1_declaration *)0x0;
        }
        else {
          *(int *)((int)decl + 0x18) = g_token_position;
        }
        iVar19 = g_paren_depth;
        pcVar42 = g_decl_specifiers_by_level + g_paren_depth;
        cVar17 = (pcVar42->words).inlining;
        cVar12 = (pcVar42->words).declspec;
        cVar13 = (pcVar42->words).allocate;
        (decl->spec).storage = (pcVar42->words).storage;
        (decl->spec).inlining = cVar17;
        (decl->spec).declspec = cVar12;
        (decl->spec).allocate = cVar13;
        (decl->spec).segment = g_decl_specifiers_by_level[iVar19].words.segment;
        pcVar42 = g_decl_specifiers_by_level + iVar19;
        cVar17 = (pcVar42->words).pad09[0];
        cVar12 = (pcVar42->words).pad09[1];
        cVar13 = (pcVar42->words).pad09[2];
        (decl->spec).flags8 = (pcVar42->words).flags8;
        (decl->spec).pad09[0] = cVar17;
        (decl->spec).pad09[1] = cVar12;
        (decl->spec).pad09[2] = cVar13;
        class_check_member_declaration(decl,g_decl_specifiers_by_level + g_paren_depth);
        uVar45 = (ulonglong)g_yyval.words[0];
        break;
      case 0x32:
        pcVar5 = pcVar26->decl;
        pcVar42 = g_decl_specifiers_by_level + g_paren_depth;
        cVar17 = (pcVar42->words).inlining;
        cVar12 = (pcVar42->words).declspec;
        cVar13 = (pcVar42->words).allocate;
        (pcVar5->spec).storage = (pcVar42->words).storage;
        (pcVar5->spec).inlining = cVar17;
        (pcVar5->spec).declspec = cVar12;
        (pcVar5->spec).allocate = cVar13;
        (pcVar5->spec).segment = g_decl_specifiers_by_level[iVar31].words.segment;
        pcVar42 = g_decl_specifiers_by_level + iVar31;
        cVar17 = (pcVar42->words).pad09[0];
        cVar12 = (pcVar42->words).pad09[1];
        cVar13 = (pcVar42->words).pad09[2];
        (pcVar5->spec).flags8 = (pcVar42->words).flags8;
        (pcVar5->spec).pad09[0] = cVar17;
        (pcVar5->spec).pad09[1] = cVar12;
        (pcVar5->spec).pad09[2] = cVar13;
        decl_apply_specifiers(pcVar26->decl->declarator,g_decl_specifiers_by_level + g_paren_depth);
        decl_finish_declarator(pcVar26->decl->declarator);
        class_check_member_declaration(pcVar26->decl,g_decl_specifiers_by_level + g_paren_depth);
        uVar45 = (ulonglong)g_yyval.words[0];
        break;
      case 0x33:
        pcVar5 = pcVar26->decl;
        pcVar42 = g_decl_specifiers_by_level + g_paren_depth;
        cVar17 = (pcVar42->words).inlining;
        cVar12 = (pcVar42->words).declspec;
        cVar13 = (pcVar42->words).allocate;
        (pcVar5->spec).storage = (pcVar42->words).storage;
        (pcVar5->spec).inlining = cVar17;
        (pcVar5->spec).declspec = cVar12;
        (pcVar5->spec).allocate = cVar13;
        (pcVar5->spec).segment = g_decl_specifiers_by_level[iVar31].words.segment;
        pcVar42 = g_decl_specifiers_by_level + iVar31;
        cVar17 = (pcVar42->words).pad09[0];
        cVar12 = (pcVar42->words).pad09[1];
        cVar13 = (pcVar42->words).pad09[2];
        (pcVar5->spec).flags8 = (pcVar42->words).flags8;
        (pcVar5->spec).pad09[0] = cVar17;
        (pcVar5->spec).pad09[1] = cVar12;
        (pcVar5->spec).pad09[2] = cVar13;
        decl_apply_specifiers(pcVar26->decl->declarator,g_decl_specifiers_by_level + g_paren_depth);
        decl_finish_declarator(pcVar26->decl->declarator);
        class_check_member_declaration(pcVar26->decl,g_decl_specifiers_by_level + g_paren_depth);
        uVar45 = (ulonglong)g_yyval.words[0];
        break;
      case 0x34:
        diag_warning(1,0xe4,0xe4);
        iVar19 = g_paren_depth;
        decl_4 = pcVar26->decl;
        pcVar42 = g_decl_specifiers_by_level + g_paren_depth;
        cVar17 = (pcVar42->words).inlining;
        cVar12 = (pcVar42->words).declspec;
        cVar13 = (pcVar42->words).allocate;
        (decl_4->spec).storage = (pcVar42->words).storage;
        (decl_4->spec).inlining = cVar17;
        (decl_4->spec).declspec = cVar12;
        (decl_4->spec).allocate = cVar13;
        (decl_4->spec).segment = g_decl_specifiers_by_level[iVar19].words.segment;
        pcVar42 = g_decl_specifiers_by_level + iVar19;
        cVar17 = (pcVar42->words).pad09[0];
        cVar12 = (pcVar42->words).pad09[1];
        cVar13 = (pcVar42->words).pad09[2];
        (decl_4->spec).flags8 = (pcVar42->words).flags8;
        (decl_4->spec).pad09[0] = cVar17;
        (decl_4->spec).pad09[1] = cVar12;
        (decl_4->spec).pad09[2] = cVar13;
        decl_apply_specifiers(pcVar26->decl->declarator,g_decl_specifiers_by_level + g_paren_depth);
        decl_finish_declarator(pcVar26->decl->declarator);
        class_check_member_declaration(pcVar26->decl,g_decl_specifiers_by_level + g_paren_depth);
        uVar45 = (ulonglong)g_yyval.words[0];
        break;
      case 0x35:
        pcVar20 = parse_skip_to_token_in_set(parser->lookahead,0x7f,0x7b,1);
        parser->lookahead = pcVar20;
        if (pcVar20->code != '\x7f') {
          (*g_token_source->stream->vtbl->unget)(g_token_source->stream,pcVar20);
          parser->lookahead = g_token_semicolon;
        }
        yy_errok(parser);
        uVar45 = (ulonglong)g_yyval.words[0];
        break;
      case 0x36:
        pcVar20 = parse_skip_to_token_in_set(parser->lookahead,0x7f,0x7b,1);
        parser->lookahead = pcVar20;
        if (pcVar20->code != '\x7f') {
          (*g_token_source->stream->vtbl->unget)(g_token_source->stream,pcVar20);
          parser->lookahead = g_token_semicolon;
        }
      case 0x86:
      case 0xa4:
        yy_errok(parser);
        uVar45 = (ulonglong)g_yyval.words[0];
        break;
      case 0x37:
        (g_yyval.decl)->context = 2;
        uVar45 = (ulonglong)CONCAT24(rule,g_yyval.ptr);
        break;
      case 0x38:
        (g_yyval.decl)->context = 1;
        cVar17 = type_check_bitfield_width((g_yyval.decl)->sym,pcVar26->words[0],pcVar26->words[1]);
        (g_yyval.decl)->width = cVar17;
        uVar45 = (ulonglong)g_yyval.words[0];
        break;
      case 0x39:
        g_arenas[3].cur = g_arenas[3].cur + 0x30;
        if (g_arenas[3].end < g_arenas[3].cur) {
          arena_grow(g_arenas + 3);
        }
        pvVar37 = g_name_alignment_member;
        if (decl == (c1_declaration *)0x0) goto LAB_10630bdb;
LAB_1061652a:
        decl->name = pvVar37;
        puVar7[0x24] = '\0';
        puVar7[0x25] = '\0';
        puVar7[0x26] = '\0';
        puVar7[0x27] = '\0';
        pcVar27 = arena_alloc(g_arenas + 3,0x38);
        if (pcVar27 == (c1_type_declarator *)0x0) {
          puVar7[4] = '\0';
          iVar19 = g_token_position;
          puVar7[5] = '\0';
          puVar7[6] = '\0';
          puVar7[7] = '\0';
          *(int *)((int)decl + 0x18) = g_token_position;
          uVar45 = CONCAT44(iVar19,decl);
        }
        else {
          pcVar27 = decl_new_declarator(pcVar27,decl->name);
          *(c1_type_declarator **)((int)decl + 4) = pcVar27;
          iVar19 = g_token_position;
          *(int *)((int)decl + 0x18) = g_token_position;
          uVar45 = CONCAT44(iVar19,decl);
        }
        break;
      case 0x3d:
        diag_warning(1,0xe4,0xe4);
        uVar45 = (ulonglong)g_yyval.words[0];
        break;
      case 0x3e:
        decl_3 = pcVar26->decl;
        pcVar42 = g_decl_specifiers_by_level + g_paren_depth;
        cVar17 = (pcVar42->words).inlining;
        cVar12 = (pcVar42->words).declspec;
        cVar13 = (pcVar42->words).allocate;
        (decl_3->spec).storage = (pcVar42->words).storage;
        (decl_3->spec).inlining = cVar17;
        (decl_3->spec).declspec = cVar12;
        (decl_3->spec).allocate = cVar13;
        (decl_3->spec).segment = g_decl_specifiers_by_level[iVar31].words.segment;
        pcVar42 = g_decl_specifiers_by_level + iVar31;
        cVar17 = (pcVar42->words).pad09[0];
        cVar12 = (pcVar42->words).pad09[1];
        cVar13 = (pcVar42->words).pad09[2];
        (decl_3->spec).flags8 = (pcVar42->words).flags8;
        (decl_3->spec).pad09[0] = cVar17;
        (decl_3->spec).pad09[1] = cVar12;
        (decl_3->spec).pad09[2] = cVar13;
        decl_apply_specifiers(pcVar26->decl->declarator,g_decl_specifiers_by_level + g_paren_depth);
        decl_finish_declarator(pcVar26->decl->declarator);
        decl_declare_function_or_variable(pcVar26->decl,g_decl_specifiers_by_level + g_paren_depth);
        uVar45 = (ulonglong)g_yyval.words[0];
        break;
      case 0x3f:
        if (g_opt_Zg == '\0') {
          decl_finish_initialization(pcVar26[-1].sym,pcVar26->node);
          iVar24 = g_nested_declaration_depth;
        }
        goto LAB_10616b59;
      case 0x40:
        uVar45 = (ulonglong)CONCAT24(rule,g_yyval.ptr);
        if (g_opt_Zg == '\0') {
          init_begin(pcVar26->sym);
          uVar45 = (ulonglong)g_yyval.words[0];
        }
        break;
      case 0x41:
        init_finish(pcVar26[-5].sym);
        uVar45 = (ulonglong)g_yyval.words[0];
        break;
      case 0x42:
        decl_2 = pcVar26[-1].decl;
        pcVar42 = g_decl_specifiers_by_level + g_paren_depth;
        cVar17 = (pcVar42->words).inlining;
        cVar12 = (pcVar42->words).declspec;
        cVar13 = (pcVar42->words).allocate;
        (decl_2->spec).storage = (pcVar42->words).storage;
        (decl_2->spec).inlining = cVar17;
        (decl_2->spec).declspec = cVar12;
        (decl_2->spec).allocate = cVar13;
        (decl_2->spec).segment = g_decl_specifiers_by_level[iVar31].words.segment;
        pcVar42 = g_decl_specifiers_by_level + iVar31;
        cVar17 = (pcVar42->words).pad09[0];
        cVar12 = (pcVar42->words).pad09[1];
        cVar13 = (pcVar42->words).pad09[2];
        (decl_2->spec).flags8 = (pcVar42->words).flags8;
        (decl_2->spec).pad09[0] = cVar17;
        (decl_2->spec).pad09[1] = cVar12;
        (decl_2->spec).pad09[2] = cVar13;
        decl_apply_specifiers
                  ((pcVar26[-1].decl)->declarator,g_decl_specifiers_by_level + g_paren_depth);
        decl_finish_declarator((pcVar26[-1].decl)->declarator);
        (pcVar26[-1].decl)->flags2c = (pcVar26[-1].decl)->flags2c | 4;
        result_3 = decl_declare_function_or_variable
                             (pcVar26[-1].decl,g_decl_specifiers_by_level + g_paren_depth);
        result = (void *)decl_begin_initialized_definition(result_3);
        goto LAB_10617265;
      case 0x43:
        g_yyval.ptr = (void *)0x0;
        decl_report_bad_specifier(0x201,(byte *)(g_decl_specifiers_by_level + g_paren_depth));
        uVar45 = (ulonglong)g_yyval.words[0];
        break;
      case 0x46:
        if (g_opt_Zg == '\0') {
          init_process_initializer(pcVar26->node);
          iVar24 = g_nested_declaration_depth;
        }
        goto LAB_10616b59;
      case 0x47:
        uVar45 = (ulonglong)CONCAT24(rule,g_yyval.ptr);
        if (g_opt_Zg == '\0') {
          init_nested_brace_begin();
          uVar45 = (ulonglong)g_yyval.words[0];
        }
        break;
      case 0x48:
        uVar45 = (ulonglong)CONCAT24(rule,g_yyval.ptr);
        if (g_opt_Zg == '\0') {
          init_pop_brace_level();
          uVar45 = (ulonglong)g_yyval.words[0];
        }
        break;
      case 0x49:
        g_arenas[3].cur = g_arenas[3].cur + 0x30;
        if (g_arenas[3].end < g_arenas[3].cur) {
          arena_grow(g_arenas + 3);
        }
        if (decl != (c1_declaration *)0x0) {
          pvVar37 = pcVar26->ptr;
          goto LAB_1061652a;
        }
LAB_10630bdb:
        uVar45 = 0;
        break;
      case 0x4a:
        g_arenas[3].cur = g_arenas[3].cur + 0x30;
        if (g_arenas[3].end < g_arenas[3].cur) {
          arena_grow(g_arenas + 3);
        }
        if (decl == (c1_declaration *)0x0) {
          type_check_based_form(pcRam00000004,(uint *)&pcVar26[-1].half);
          uVar45 = 0;
        }
        else {
          decl->name = pcVar26->ptr;
          puVar7[0x24] = '\0';
          puVar7[0x25] = '\0';
          puVar7[0x26] = '\0';
          puVar7[0x27] = '\0';
          pcVar27 = arena_alloc(g_arenas + 3,0x38);
          if (pcVar27 == (c1_type_declarator *)0x0) {
            puVar7[4] = '\0';
            puVar7[5] = '\0';
            puVar7[6] = '\0';
            puVar7[7] = '\0';
            *(int *)((int)decl + 0x18) = g_token_position;
            type_check_based_form(*(c1_type_declarator **)((int)decl + 4),(uint *)&pcVar26[-1].half)
            ;
            uVar45 = ZEXT48(decl);
          }
          else {
            pcVar27 = decl_new_declarator(pcVar27,decl->name);
            *(c1_type_declarator **)((int)decl + 4) = pcVar27;
            *(int *)((int)decl + 0x18) = g_token_position;
            type_check_based_form(*(c1_type_declarator **)((int)decl + 4),(uint *)&pcVar26[-1].half)
            ;
            uVar45 = ZEXT48(decl);
          }
        }
        break;
      case 0x4b:
        local_54[0] = 0;
        mods_position = 0;
        decl_add_pointer_modifier(pcVar26->decl->declarator,local_54,&pcVar26[-1].half);
        result = pcVar26->ptr;
        goto LAB_10617265;
      case 0x4c:
        decl_add_pointer_modifier(pcVar26->decl->declarator,&pcVar26[-3].half,&pcVar26[-1].half);
        uVar45 = (ulonglong)pcVar26->words[0];
        break;
      case 0x4d:
        decl_append_array_layer((g_yyval.decl)->declarator,(int *)&pcVar26[-1].value);
        uVar45 = (ulonglong)g_yyval.words[0];
        break;
      case 0x4e:
        decl_append_function_layer((g_yyval.decl)->declarator,(int *)(pcVar26->string).text);
        uVar45 = (ulonglong)g_yyval.words[0];
        break;
      case 0x50:
        g_yyval.ptr = pcVar26[-1].ptr;
        goto LAB_10617103;
      case 0x51:
      case 0x5a:
        g_block_depth = g_block_depth + '\x01';
        g_prototype_scope_depth = g_prototype_scope_depth + 1;
        g_nested_declaration_depth = g_nested_declaration_depth + 1;
        block_scope_new(g_current_scope,(void *)0x0);
        uVar45 = (ulonglong)g_yyval.words[0];
        break;
      case 0x52:
        g_yyval.ptr = pcVar26[-2].string.text;
        if (pcVar26[-1].sym != (c1_symbol *)0x0) {
          decl_parameter_list_end((int *)g_yyval.string.text,pcVar26[-1].sym);
        }
        g_block_depth = g_block_depth + 0xff;
        g_prototype_scope_depth = g_prototype_scope_depth + -1;
        g_nested_declaration_depth = g_nested_declaration_depth + -1;
        goto switchD_10615cfc_caseD_90;
      case 0x53:
        g_arenas[3].cur = g_arenas[3].cur + 0xc;
        if (g_arenas[3].end < g_arenas[3].cur) {
          arena_grow(g_arenas + 3);
        }
        if (decl == (c1_declaration *)0x0) goto switchD_10615cfc_caseD_7b;
        cVar22 = g_current_scope->current->entries;
        puVar7[4] = '\x01';
        puVar7[5] = '\0';
        puVar7[6] = '\0';
        puVar7[7] = '\0';
        *(uchar *)((int)decl + 8) = '\x01';
        *(c1_scope_entries *)decl = cVar22;
        uVar45 = ZEXT48(decl);
        break;
      case 0x54:
        g_arenas[3].cur = g_arenas[3].cur + 0xc;
        if (g_arenas[3].end < g_arenas[3].cur) {
          arena_grow(g_arenas + 3);
        }
        if (decl == (c1_declaration *)0x0) goto switchD_10615cfc_caseD_7b;
        cVar22 = g_current_scope->current->entries;
LAB_1061672c:
        puVar7[4] = '\x06';
        puVar7[5] = '\0';
        puVar7[6] = '\0';
        puVar7[7] = '\0';
        *(uchar *)((int)decl + 8) = '\x01';
        *(c1_scope_entries *)decl = cVar22;
        uVar45 = ZEXT48(decl);
        break;
      case 0x56:
        result = decl_old_style_parameter_name(pcVar26->ptr);
        goto LAB_10617265;
      case 0x58:
      case 0x60:
        (*g_current_scope->current->vtbl->insert)(g_current_scope->current,g_yyval.sym);
        uVar45 = (ulonglong)g_yyval.words[0];
        break;
      case 0x59:
      case 0x61:
        g_yyval.ptr = (void *)0x0;
        yy_errok(parser);
        parser->lookahead = (c1_token *)0x0;
        uVar45 = (ulonglong)g_yyval.words[0];
        break;
      case 0x5b:
        g_yyval.ptr = pcVar26[-2].string.text;
        if (pcVar26[-1].sym != (c1_symbol *)0x0) {
          decl_parameter_list_end((int *)g_yyval.string.text,pcVar26[-1].sym);
        }
        g_block_depth = g_block_depth + 0xff;
        g_prototype_scope_depth = g_prototype_scope_depth + -1;
        g_nested_declaration_depth = g_nested_declaration_depth + -1;
        goto LAB_10617103;
      case 0x5c:
        g_arenas[3].cur = g_arenas[3].cur + 0xc;
        if (g_arenas[3].end < g_arenas[3].cur) {
          arena_grow(g_arenas + 3);
        }
        if (decl == (c1_declaration *)0x0) goto switchD_10615cfc_caseD_7b;
        pcVar11 = g_current_scope->current;
        cVar22 = pcVar11->entries;
        puVar7[4] = '\x01';
        puVar7[5] = '\0';
        puVar7[6] = '\0';
        puVar7[7] = '\0';
        *(uchar *)((int)decl + 8) = '\x01';
        *(c1_scope_entries *)decl = cVar22;
        uVar45 = CONCAT44(pcVar11,decl);
        break;
      case 0x5d:
        g_arenas[3].cur = g_arenas[3].cur + 0xc;
        if (g_arenas[3].end < g_arenas[3].cur) {
          arena_grow(g_arenas + 3);
        }
        if (decl != (c1_declaration *)0x0) {
          cVar22 = g_current_scope->current->entries;
          goto LAB_1061672c;
        }
      case 0x7c:
      case 0xb1:
      case 0xb8:
switchD_10615cfc_caseD_7b:
        uVar45 = 0;
        break;
      case 0x62:
        pcVar39 = pcVar26 + -1;
        pcVar26->decl->context = 5;
        pcVar25 = pcVar26->node;
        pcVar25->unk0c = (c1_u32)pcVar39->ptr;
        pcVar25->left = *(void **)((int)pcVar26 + -0x14);
        pcVar25->right = *(void **)((int)pcVar26 + -0x10);
        decl_apply_specifiers(pcVar26->decl->declarator,&pcVar39->spec);
        decl_finish_declarator(pcVar26->decl->declarator);
        decl_declare_declarator(pcVar26->decl,&pcVar39->spec);
        g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfc;
        result = sym_new_from_declarator(pcVar26->decl,-1);
        goto LAB_10617265;
      case 99:
        pcVar26->decl->context = 6;
        pcVar25 = pcVar26->node;
        pcVar25->unk0c = (c1_u32)pcVar26[-1].ptr;
        pcVar25->left = *(void **)((int)pcVar26 + -0x14);
        pcVar25->right = *(void **)((int)pcVar26 + -0x10);
        pcVar26->decl->name = g_name_formal;
        decl_apply_specifiers(pcVar26->decl->declarator,&pcVar26[-1].spec);
        decl_finish_declarator(pcVar26->decl->declarator);
        decl_abstract_declarator(pcVar26->decl);
        g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfc;
        result = sym_new_from_declarator(pcVar26->decl,-1);
        goto LAB_10617265;
      case 0x65:
        cVar18 = type_merge_qualifiers(g_yyval.half,pcVar26->half);
        g_yyval.half = cVar18;
        uVar45 = (ulonglong)g_yyval.words[0];
        if (g_yyval.spec.words.segment == (void *)0x0) {
          g_yyval.spec.words.segment = (void *)pcVar26->words[1];
          uVar45 = (ulonglong)g_yyval.words[0];
        }
        break;
      case 0x66:
        diag_warning(1,0xe6,0xe6);
        uVar45 = (ulonglong)g_yyval.words[0];
        break;
      case 0x67:
        sVar38 = (short)g_tree_op_to_il_op[(pcVar26->spec).words.storage];
        goto LAB_10616900;
      case 0x68:
        g_yyval.ptr = pcVar26[-1].ptr;
        g_yyval.spec.words.segment = (&pcVar26->spec)[-1].words.segment;
        goto LAB_10617103;
      case 0x69:
        g_yyval.spec.words.segment = (void *)0x0;
        uVar45 = 0;
        break;
      case 0x6b:
        sVar38 = (short)g_tree_op_to_il_op[(pcVar26->spec).words.storage];
LAB_10616900:
        if (sVar38 == 0x18) {
          sVar38 = 0;
        }
        g_yyval.spec.words.segment = (void *)0x0;
        g_yyval.words[0] = CONCAT22(g_yyval.value._2_2_,sVar38);
        uVar45 = CONCAT44(0,g_yyval.words[0]);
        break;
      case 0x6c:
        uVar28 = (ushort)g_tree_op_to_il_op[(pcVar26->spec).words.storage];
        if (uVar28 == 0x18) {
          uVar28 = 0;
        }
        g_yyval.half = g_yyval.half | uVar28;
        uVar45 = (ulonglong)CONCAT24(rule,g_yyval.ptr);
        break;
      case 0x6d:
        g_yyval.words[1] = decl_check_based_argument(pcVar26->words[0]);
        uVar29 = 0x18;
        if (g_yyval.spec.words.segment == (void *)0x0) {
          uVar29 = 0;
        }
        g_yyval.words[0] = CONCAT22(g_yyval.value._2_2_,uVar29);
        uVar45 = CONCAT44(0,g_yyval.words[0]);
        break;
      case 0x6e:
        g_yyval.spec.words.segment = (void *)0x0;
        g_yyval.words[0] = CONCAT22(g_yyval.value._2_2_,8);
        uVar45 = (ulonglong)CONCAT24(rule,g_yyval.ptr);
        break;
      case 0x6f:
        g_yyval.ptr = (void *)0x0;
        g_yyval.spec.words.segment = (void *)0x0;
        yy_errok(parser);
        parser->lookahead = (c1_token *)0x0;
        uVar45 = (ulonglong)g_yyval.words[0];
        break;
      case 0x72:
        g_arenas[3].cur = g_arenas[3].cur + 0x30;
        if (g_arenas[3].end < g_arenas[3].cur) {
          arena_grow(g_arenas + 3);
        }
        pvVar37 = g_name_abstract_declarator;
        if (decl == (c1_declaration *)0x0) goto switchD_10615cfc_caseD_7b;
        puVar7[0x24] = '\x04';
        puVar7[0x25] = '\0';
        puVar7[0x26] = '\0';
        puVar7[0x27] = '\0';
        decl->name = pvVar37;
        puVar7 = g_arenas[3].cur;
        g_arenas[3].cur = g_arenas[3].cur + 0x38;
        if (g_arenas[3].end < g_arenas[3].cur) {
          arena_grow(g_arenas + 3);
        }
        if (puVar7 == (uchar *)0x0) {
          pcVar27 = (c1_type_declarator *)0x0;
        }
        else {
          pcVar27 = decl_new_declarator((c1_type_declarator *)puVar7,decl->name);
        }
        *(c1_type_declarator **)((int)decl + 4) = pcVar27;
        *(int *)((int)decl + 0x18) = g_token_position;
        uVar45 = ZEXT48(decl);
        break;
      case 0x73:
        g_arenas[3].cur = g_arenas[3].cur + 0x30;
        if (g_arenas[3].end < g_arenas[3].cur) {
          arena_grow(g_arenas + 3);
        }
        pvVar37 = g_name_abstract_declarator;
        if (decl == (c1_declaration *)0x0) {
          type_check_based_form(pcRam00000004,(uint *)&pcVar26->half);
          uVar45 = 0;
        }
        else {
          puVar7[0x24] = '\x04';
          puVar7[0x25] = '\0';
          puVar7[0x26] = '\0';
          puVar7[0x27] = '\0';
          decl->name = pvVar37;
          puVar16 = g_arenas[3].cur;
          g_arenas[3].cur = g_arenas[3].cur + 0x38;
          if (g_arenas[3].end < g_arenas[3].cur) {
            arena_grow(g_arenas + 3);
          }
          if (puVar16 == (uchar *)0x0) {
            puVar7[4] = '\0';
            puVar7[5] = '\0';
            puVar7[6] = '\0';
            puVar7[7] = '\0';
            *(int *)((int)decl + 0x18) = g_token_position;
            type_check_based_form(*(c1_type_declarator **)((int)decl + 4),(uint *)&pcVar26->half);
            uVar45 = ZEXT48(decl);
          }
          else {
            pcVar27 = decl_new_declarator((c1_type_declarator *)puVar16,decl->name);
            *(c1_type_declarator **)((int)decl + 4) = pcVar27;
            *(int *)((int)decl + 0x18) = g_token_position;
            type_check_based_form(*(c1_type_declarator **)((int)decl + 4),(uint *)&pcVar26->half);
            uVar45 = ZEXT48(decl);
          }
        }
        break;
      case 0x74:
        g_arenas[3].cur = g_arenas[3].cur + 0x30;
        if (g_arenas[3].end < g_arenas[3].cur) {
          arena_grow(g_arenas + 3);
        }
        pvVar37 = g_name_abstract_declarator;
        if (decl == (c1_declaration *)0x0) {
          decl_append_function_layer(pcRam00000004,(int *)(pcVar26->string).text);
          uVar45 = 0;
        }
        else {
          puVar7[0x24] = '\x04';
          puVar7[0x25] = '\0';
          puVar7[0x26] = '\0';
          puVar7[0x27] = '\0';
          decl->name = pvVar37;
          puVar16 = g_arenas[3].cur;
          g_arenas[3].cur = g_arenas[3].cur + 0x38;
          if (g_arenas[3].end < g_arenas[3].cur) {
            arena_grow(g_arenas + 3);
          }
          if (puVar16 == (uchar *)0x0) {
            puVar7[4] = '\0';
            puVar7[5] = '\0';
            puVar7[6] = '\0';
            puVar7[7] = '\0';
            *(int *)((int)decl + 0x18) = g_token_position;
            decl_append_function_layer
                      (*(c1_type_declarator **)((int)decl + 4),(int *)(pcVar26->string).text);
            uVar45 = ZEXT48(decl);
          }
          else {
            pcVar27 = decl_new_declarator((c1_type_declarator *)puVar16,decl->name);
            *(c1_type_declarator **)((int)decl + 4) = pcVar27;
            *(int *)((int)decl + 0x18) = g_token_position;
            decl_append_function_layer
                      (*(c1_type_declarator **)((int)decl + 4),(int *)(pcVar26->string).text);
            uVar45 = ZEXT48(decl);
          }
        }
        break;
      case 0x75:
        g_arenas[3].cur = g_arenas[3].cur + 0x30;
        if (g_arenas[3].end < g_arenas[3].cur) {
          arena_grow(g_arenas + 3);
        }
        pvVar37 = g_name_abstract_declarator;
        if (decl == (c1_declaration *)0x0) {
          decl = (c1_declaration *)0x0;
        }
        else {
          puVar7[0x24] = '\x04';
          puVar7[0x25] = '\0';
          puVar7[0x26] = '\0';
          puVar7[0x27] = '\0';
          decl->name = pvVar37;
          puVar16 = g_arenas[3].cur;
          g_arenas[3].cur = g_arenas[3].cur + 0x38;
          if (g_arenas[3].end < g_arenas[3].cur) {
            arena_grow(g_arenas + 3);
          }
          if (puVar16 == (uchar *)0x0) {
            puVar7[4] = '\0';
            puVar7[5] = '\0';
            puVar7[6] = '\0';
            puVar7[7] = '\0';
            *(int *)((int)decl + 0x18) = g_token_position;
          }
          else {
            pcVar27 = decl_new_declarator((c1_type_declarator *)puVar16,decl->name);
            *(c1_type_declarator **)((int)decl + 4) = pcVar27;
            *(int *)((int)decl + 0x18) = g_token_position;
          }
        }
        type_check_based_form(decl->declarator,(uint *)&pcVar26[-1].half);
        decl_append_function_layer(decl->declarator,(int *)(pcVar26->string).text);
        uVar45 = ZEXT48(decl);
        break;
      case 0x76:
        g_yyval.ptr = pcVar26->decl;
        local_4c[0] = 0;
        mods_position_2 = 0;
        decl_add_pointer_modifier((g_yyval.decl)->declarator,local_4c,&pcVar26[-1].half);
        uVar45 = (ulonglong)g_yyval.words[0];
        break;
      case 0x77:
        g_yyval.ptr = pcVar26->decl;
        decl_add_pointer_modifier((g_yyval.decl)->declarator,&pcVar26[-3].half,&pcVar26[-1].half);
        uVar45 = (ulonglong)g_yyval.words[0];
        break;
      case 0x78:
        decl_append_array_layer((g_yyval.decl)->declarator,(int *)&pcVar26[-1].value);
        uVar45 = (ulonglong)g_yyval.words[0];
        break;
      case 0x79:
        decl_append_function_layer((g_yyval.decl)->declarator,(int *)(pcVar26->string).text);
        uVar45 = (ulonglong)g_yyval.words[0];
        break;
      case 0x7b:
        g_yyval.ptr = pcVar26[-1].ptr;
        goto LAB_10617103;
      case 0x7d:
        diag_error(0x3b,0x4c,0x37);
        pvVar37 = g_name_ellipsis;
        uVar32 = -(uint)(g_block_depth != '\0') & 2;
        if ((uVar32 == 0) &&
           (puVar40 = g_symbol_free_lists[g_symbol_size_class_table[0xb]], puVar40 != (uint *)0x0))
        {
          g_symbol_free_lists[g_symbol_size_class_table[0xb]] = (uint *)puVar40[1];
          *puVar40 = 0;
          pcVar25 = (c1_node *)(puVar40 + -2);
          puVar40[1] = 0;
          uVar35 = g_symbol_size_table[0xb];
          pcVar43 = pcVar25;
          for (uVar34 = g_symbol_size_table[0xb] >> 2; uVar34 != 0; uVar34 = uVar34 - 1) {
            pcVar43->op = '\0';
            pcVar43->kind = '\0';
            pcVar43->flags = '\0';
            pcVar43->pad03 = '\0';
            pcVar43 = (c1_node *)&pcVar43->type;
          }
          for (uVar35 = uVar35 & 3; uVar35 != 0; uVar35 = uVar35 - 1) {
            pcVar43->op = '\0';
            pcVar43 = (c1_node *)&pcVar43->kind;
          }
          *puVar40 = (uint)pvVar37;
          pcVar25->op = pcVar25->op & 0xeb | 0xb;
          if (pcVar25 == (c1_node *)0x0) goto LAB_10631096;
        }
        else {
LAB_10631096:
          pfVar21 = g_arenas + uVar32;
          uVar35 = g_symbol_size_table[0xb] + 3;
          pcVar25 = (c1_node *)pfVar21->cur;
          puVar7 = g_arenas[uVar32].end;
          pfVar21->cur = &pcVar25->op + (uVar35 & 0xfffffffc);
          if (puVar7 < &pcVar25->op + (uVar35 & 0xfffffffc)) {
            arena_grow(pfVar21);
          }
          if (pcVar25 == (c1_node *)0x0) {
            pcVar25 = (c1_node *)0x0;
          }
          else {
            pcVar25->op = pcVar25->op & 0xeb | 0xb;
            if (&pcVar25->link != (c1_node **)0x0) {
              decl_parameter_list_set((int *)&pcVar25->link,(int)pvVar37,(int)pcVar25);
            }
          }
        }
        cStack_38.base = (c1_type *)0x0;
        cStack_38.debug_index = 0;
        cStack_38.code = 0x80d;
        cStack_38.flags = 0;
        cStack_38.extra.sym = (c1_symbol *)0x0;
        pcVar23 = &cStack_38;
        g_yyval.node = pcVar25;
        goto LAB_10616ac3;
      case 0x7e:
        uVar32 = -(uint)(g_block_depth != '\0') & 2;
        if ((uVar32 == 0) &&
           (puVar40 = g_symbol_free_lists[g_symbol_size_class_table[0xb]], puVar40 != (uint *)0x0))
        {
          pcVar25 = (c1_node *)(puVar40 + -2);
          g_symbol_free_lists[g_symbol_size_class_table[0xb]] = (uint *)puVar40[1];
          *puVar40 = 0;
          puVar40[1] = 0;
          uVar35 = g_symbol_size_table[0xb];
          pcVar43 = pcVar25;
          for (uVar34 = g_symbol_size_table[0xb] >> 2; uVar34 != 0; uVar34 = uVar34 - 1) {
            pcVar43->op = '\0';
            pcVar43->kind = '\0';
            pcVar43->flags = '\0';
            pcVar43->pad03 = '\0';
            pcVar43 = (c1_node *)&pcVar43->type;
          }
          for (uVar35 = uVar35 & 3; uVar35 != 0; uVar35 = uVar35 - 1) {
            pcVar43->op = '\0';
            pcVar43 = (c1_node *)&pcVar43->kind;
          }
          *puVar40 = (uint)pvVar37;
          pcVar25->op = pcVar25->op & 0xeb | 0xb;
          if (pcVar25 == (c1_node *)0x0) goto LAB_10616a58;
        }
        else {
LAB_10616a58:
          pfVar21 = g_arenas + uVar32;
          uVar35 = g_symbol_size_table[0xb] + 3;
          pcVar25 = (c1_node *)pfVar21->cur;
          puVar7 = g_arenas[uVar32].end;
          pfVar21->cur = &pcVar25->op + (uVar35 & 0xfffffffc);
          if (puVar7 < &pcVar25->op + (uVar35 & 0xfffffffc)) {
            arena_grow(pfVar21);
          }
          if (pcVar25 == (c1_node *)0x0) {
            pcVar25 = (c1_node *)0x0;
          }
          else {
            pcVar25->op = pcVar25->op & 0xeb | 0xb;
            if (&pcVar25->link != (c1_node **)0x0) {
              decl_parameter_list_set((int *)&pcVar25->link,(int)pvVar37,(int)pcVar25);
            }
          }
        }
        local_28.base = (c1_type *)0x0;
        local_28.debug_index = 0;
        local_28.code = 0x80d;
        local_28.flags = 0;
        local_28.extra.sym = (c1_symbol *)0x0;
        pcVar23 = &local_28;
        g_yyval.node = pcVar25;
LAB_10616ac3:
        pcVar23 = type_intern(pcVar23);
        uVar14 = g_yyval.ptr;
        (g_yyval.sym)->type = pcVar23;
        (g_yyval.node)->kind = (g_yyval.node)->kind | 2;
        uVar45 = CONCAT44(uVar14,g_yyval.ptr);
        break;
      case 0x7f:
        if ((g_opt_Zg == '\0') && ((g_compile_flags_c4 & 0x800000) == 0)) {
          stmt_block_begin();
          g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfc;
          uVar45 = (ulonglong)g_yyval.words[0];
        }
        else {
          g_compile_flags_c4 = g_compile_flags_c4 | 0x800000;
          parse_skip_to_closing_brace();
          uVar45 = (ulonglong)g_yyval.words[0];
        }
        break;
      case 0x80:
        if ((g_opt_Zg == '\0') && ((g_compile_flags_c4 & 0x800000) == 0)) {
          stmt_block_end();
          uVar45 = (ulonglong)g_yyval.words[0];
        }
        else {
          g_compile_flags_c4 = g_compile_flags_c4 & 0xff7fffff;
          uVar45 = (ulonglong)CONCAT24(rule,g_yyval.ptr);
        }
        break;
      case 0x85:
switchD_10615cfc_caseD_84:
        decl_check_empty_declaration((c1_u8 *)&pcVar26[-1].half);
        uVar45 = (ulonglong)g_yyval.words[0];
        break;
      case 0x8a:
        pcVar25 = expr_warn_no_effect(pcVar26[-1].node,'\x01');
        pcVar26[-1].node = pcVar25;
        stmt_emit_expression(pcVar25);
        goto LAB_10616b54;
      case 0x8c:
        label_emit_definition(pcVar26[-1].node);
        uVar45 = (ulonglong)g_yyval.words[0];
        break;
      case 0x8d:
        label_emit_definition(pcVar26[-1].node);
        uVar45 = (ulonglong)g_yyval.words[0];
        break;
      case 0x8e:
        pcVar25 = expr_warn_no_effect(pcVar26[-1].node,'\0');
        pcVar26[-1].node = pcVar25;
        stmt_loop_begin((c1_node *)0x0,(int)pcVar25,(c1_node *)0x0);
        goto LAB_10617103;
      case 0x8f:
      case 0x92:
        stmt_loop_end();
        uVar45 = (ulonglong)g_yyval.words[0];
        break;
      case 0x90:
        pcVar25 = expr_warn_no_effect(pcVar26[-4].node,'\x01');
        pcVar26[-4].node = pcVar25;
        pcVar25 = expr_warn_no_effect(pcVar26[-2].node,'\0');
        pcVar26[-2].node = pcVar25;
        pcVar25 = expr_warn_no_effect(pcVar26->node,'\x01');
        pcVar26->node = pcVar25;
        stmt_loop_begin(pcVar26[-4].node,pcVar26[-2].words[0],pcVar25);
        uVar45 = (ulonglong)g_yyval.words[0];
        break;
      case 0x91:
        goto switchD_10615cfc_caseD_90;
      case 0x93:
        stmt_do_head();
        uVar45 = (ulonglong)g_yyval.words[0];
        break;
      case 0x94:
        pcVar25 = expr_warn_no_effect(pcVar26[-2].node,'\0');
        pcVar26[-2].node = pcVar25;
        label_emit_definition(g_continue_label_stack->label);
        if (pcVar26[-2].node != (c1_node *)0x0) {
          stmt_check_controlling_expression(pcVar26[-2].node,g_loop_top_label_stack->label,1);
        }
        il_emit_pragma_or_segment_record(0x24);
        label_emit_definition(g_break_label_stack->label);
        g_loop_top_label_stack = g_loop_top_label_stack->next;
        g_continue_label_stack = g_continue_label_stack->next;
        g_break_label_stack = g_break_label_stack->next;
        g_loop_label_count = g_loop_label_count + -3;
        if (g_loop_label_count == 0) {
          arena_reset_ptr(g_arenas + 4);
        }
        iVar19 = yy_error_flag();
        if (iVar19 == 0) {
          arena_reset_ptr(g_arenas + 3);
        }
        g_string_literal_cur = &g_string_literal_buffer;
        goto switchD_10615cfc_caseD_90;
      case 0x95:
        pcVar25 = expr_warn_no_effect(pcVar26[-1].node,'\0');
        pcVar26[-1].node = pcVar25;
        goto LAB_10617103;
      case 0x96:
        stmt_switch_head(pcVar26[-3].node);
        g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfc;
        uVar45 = (ulonglong)g_yyval.words[0];
        break;
      case 0x97:
        il_emit_pragma_or_segment_record(0x24);
        il_emit_tuple(0x3a,g_break_label_stack->label);
        stmt_switch_end();
        g_loop_top_label_stack = g_loop_top_label_stack->next;
        g_break_label_stack = g_break_label_stack->next;
        g_switch_case_stack = g_switch_case_stack->next;
        g_default_label_stack = g_default_label_stack->next;
        g_loop_label_count = g_loop_label_count + -4;
        uVar45 = CONCAT44(g_default_label_stack,g_yyval.ptr);
        if (g_loop_label_count == 0) {
          arena_reset_ptr(g_arenas + 4);
          uVar45 = (ulonglong)g_yyval.words[0];
        }
        break;
      case 0x98:
        eh_check_leave();
        uVar45 = (ulonglong)g_yyval.words[0];
        break;
      case 0x99:
        if (g_break_label_stack == (c1_label_cell *)0x0) {
          diag_error(0x2b);
          uVar45 = (ulonglong)g_yyval.words[0];
        }
        else {
          il_emit_tuple(0x3a,g_break_label_stack->label);
          uVar45 = (ulonglong)g_yyval.words[0];
        }
        break;
      case 0x9a:
        if (g_continue_label_stack == (c1_label_cell *)0x0) {
          diag_error(0x2c);
          uVar45 = (ulonglong)g_yyval.words[0];
        }
        else {
          il_emit_tuple(0x3a,g_continue_label_stack->label);
          uVar45 = (ulonglong)g_yyval.words[0];
        }
        break;
      case 0x9b:
        stmt_return((c1_node *)0x0,1);
        uVar45 = (ulonglong)g_yyval.words[0];
        break;
      case 0x9c:
        pcVar25 = expr_warn_no_effect(pcVar26[-1].node,'\0');
        pcVar26[-1].node = pcVar25;
        stmt_return(pcVar25,1);
        goto LAB_10616b54;
      case 0x9d:
        result_2 = label_find_in_function(pcVar26[-1].ptr);
        if (result_2 == (void *)0x0) {
          result_2 = label_new_user(pcVar26[-1].words[0]);
          label_register(result_2);
        }
        pcVar25 = tree_new_symbol_ref(result_2);
        il_emit_tuple(0x3a,pcVar25);
LAB_10616b54:
        iVar24 = yy_error_flag();
LAB_10616b59:
        if (iVar24 == 0) {
          arena_reset_ptr(g_arenas + 3);
        }
        g_string_literal_cur = &g_string_literal_buffer;
        uVar45 = (ulonglong)g_yyval.words[0];
        break;
      case 0x9e:
        asm_statement();
        uVar45 = (ulonglong)g_yyval.words[0];
        break;
      case 0x9f:
        eh_except_end();
        uVar45 = (ulonglong)g_yyval.words[0];
        break;
      case 0xa0:
        eh_finally_begin();
        uVar45 = (ulonglong)g_yyval.words[0];
        break;
      case 0xa1:
        eh_finally_end();
        uVar45 = (ulonglong)g_yyval.words[0];
        break;
      case 0xa3:
        diag_error(0xb5);
        uVar45 = (ulonglong)g_yyval.words[0];
        break;
      case 0xa5:
        eh_try_begin();
        uVar45 = (ulonglong)g_yyval.words[0];
        break;
      case 0xa6:
        eh_try_block_end();
        uVar45 = (ulonglong)g_yyval.words[0];
        break;
      case 0xa7:
        eh_except_filter_begin();
        uVar45 = (ulonglong)g_yyval.words[0];
        break;
      case 0xa8:
        eh_except_emit_filter(pcVar26[-1].node);
        eh_except_filter_end();
        goto switchD_10615cfc_caseD_90;
      case 0xa9:
        g_case_run_label = (c1_node *)0x0;
        uVar45 = (ulonglong)CONCAT24(rule,g_yyval.ptr);
        break;
      case 0xab:
        stmt_define_label(pcVar26[-1].words[0]);
        uVar45 = (ulonglong)g_yyval.words[0];
        break;
      case 0xac:
        if ((pcVar26[-2].node == (c1_node *)0x0) ||
           (g_switch_case_stack == (c1_case_list_cell *)0x0)) {
          diag_error(0x2e);
          uVar45 = (ulonglong)g_yyval.words[0];
        }
        else {
          stmt_case_label(pcVar26[-2].node);
          uVar45 = (ulonglong)g_yyval.words[0];
        }
        break;
      case 0xad:
        if (g_default_label_stack == (c1_label_cell *)0x0) {
          diag_error(0x2f);
          uVar45 = (ulonglong)g_yyval.words[0];
        }
        else if (g_default_label_stack->label == (c1_node *)0x0) {
          if (g_case_run_label == (c1_node *)0x0) {
            pcVar25 = label_new(0x14);
            g_default_label_stack->label = pcVar25;
            g_case_run_label = g_default_label_stack->label;
            label_emit_definition(g_default_label_stack->label);
            uVar45 = (ulonglong)g_yyval.words[0];
          }
          else {
            g_default_label_stack->label = g_case_run_label;
            uVar45 = (ulonglong)CONCAT24(rule,g_yyval.ptr);
          }
        }
        else {
          diag_error(0x30);
          uVar45 = (ulonglong)g_yyval.words[0];
        }
        break;
      case 0xaf:
        g_yyval.node = label_new(0x1e);
        pcVar25 = expr_warn_no_effect(pcVar26[-1].node,'\0');
        pcVar26[-1].node = pcVar25;
        if (pcVar25 != (c1_node *)0x0) {
          stmt_check_controlling_expression(pcVar25,g_yyval.node,0);
        }
switchD_10615cfc_caseD_90:
        if (0 < g_paren_depth) {
          g_paren_depth = g_paren_depth + -1;
        }
        g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfc;
        uVar45 = (ulonglong)g_yyval.words[0];
        break;
      case 0xb0:
        g_yyval.node = label_new(0x1e);
        il_emit_tuple(0x3a,g_yyval.node);
        label_emit_definition(pcVar26[-2].node);
        il_emit_pragma_or_segment_record(0x24);
switchD_10615cfc_caseD_14:
        g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfc;
        uVar45 = (ulonglong)g_yyval.words[0];
        break;
      case 0xb2:
      case 0xe6:
        g_yyval.ptr = pcVar26[-1].ptr;
        goto LAB_10617103;
      case 0xb3:
        g_yyval.words[0] = CONCAT31(uVar15,1);
        uVar45 = (ulonglong)CONCAT24(rule,g_yyval.ptr);
        break;
      case 0xb4:
        g_yyval.words[0] = CONCAT31(uVar15,(pcVar26->spec).words.storage);
        uVar45 = CONCAT44(0,g_yyval.words[0]);
        break;
      case 0xb5:
        g_yyval.spec.words.segment = (void *)0x0;
        uVar45 = 0;
        break;
      case 0xb6:
        if (((g_class_depth < 0) ||
            (uVar45 = (ulonglong)CONCAT24(rule,g_yyval.ptr), g_ms_extensions == '\0')) &&
           (uVar45 = (ulonglong)CONCAT24(rule,g_yyval.ptr),
           pcVar26->ptr == (void *)0x0 && pcVar26->words[1] == 0)) {
          iVar19 = yyparse_c_actions_array_bound(parser);
          return iVar19;
        }
        break;
      case 0xb7:
        uVar45 = expr_eval_constant_expression(pcVar26->node);
        g_yyval.words[1] = (c1_u32)(uVar45 >> 0x20);
        break;
      case 0xba:
      case 0xbb:
      case 0xbc:
      case 0xbd:
      case 0xbe:
      case 0xbf:
      case 0xc0:
      case 0xc1:
      case 0xc2:
      case 0xc3:
      case 0xc4:
      case 0xc5:
      case 0xc6:
      case 199:
      case 200:
        result = expr_build_binary(pcVar26[-1].spec.words.storage,pcVar26[-2].node,pcVar26->node);
        goto LAB_10617265;
      case 0xc9:
        pcVar25 = expr_build_binary(pcVar26[-1].spec.words.storage,pcVar26[-2].node,pcVar26->node);
        result = expr_build_binary(pcVar26[-3].spec.words.storage,pcVar26[-4].node,pcVar25);
        goto LAB_10617265;
      case 0xcb:
        g_constant_value = 1;
        g_constant_value_high = 0;
        pcVar25 = tree_new_constant(g_type_int,&g_constant_value,g_expr_arena_index);
        result = expr_build_binary((pcVar26->spec).words.storage,pcVar26[-1].node,pcVar25);
        goto LAB_10617265;
      case 0xcc:
        result = expr_build_unary(0x86,pcVar26->node);
        goto LAB_10617265;
      case 0xcd:
        result = expr_build_unary('Z',pcVar26->node);
        goto LAB_10617265;
      case 0xce:
        result = expr_build_unary('Y',pcVar26->node);
        goto LAB_10617265;
      case 0xcf:
        result = expr_build_unary('<',pcVar26->node);
        goto LAB_10617265;
      case 0xd0:
        g_constant_value = 1;
        g_constant_value_high = 0;
        pcVar26[-1].spec.words.storage = (pcVar26[-1].spec.words.storage == '@') + 'T';
        pcVar25 = tree_new_constant(g_type_int,&g_constant_value,g_expr_arena_index);
        result = expr_build_binary(pcVar26[-1].spec.words.storage,pcVar26->node,pcVar25);
        goto LAB_10617265;
      case 0xd1:
        g_yyval.node = expr_build_unary('v',pcVar26[-1].node);
        goto LAB_10617103;
      case 0xd2:
        result = expr_build_unary('=',pcVar26->node);
        goto LAB_10617265;
      case 0xd3:
        result = expr_build_unary('1',pcVar26->node);
        goto LAB_10617265;
      case 0xd4:
        if (pcVar26->node == (c1_node *)0x0) {
          g_sizeof_depth = g_sizeof_depth + -1;
          uVar45 = 0;
        }
        else {
          pcVar25 = expr_build_sizeof(pcVar26->node);
          g_sizeof_depth = g_sizeof_depth + -1;
          uVar45 = ZEXT48(pcVar25);
        }
        break;
      case 0xd5:
        pcVar25 = expr_sizeof_type(pcVar26->sym->type);
        g_sizeof_depth = g_sizeof_depth + -1;
        uVar45 = ZEXT48(pcVar25);
        break;
      case 0xd8:
        result = expr_build_cast_expression('d',pcVar26[-1].words[0],pcVar26->node);
        goto LAB_10617265;
      case 0xd9:
        if ((pcVar26[-1].node)->op == '7') {
          diag_warning(4,0x2c5,0xc5);
        }
        result = expr_build_binary(pcVar26[-2].spec.words.storage,pcVar26[-3].node,pcVar26[-1].node)
        ;
        goto LAB_10617265;
      case 0xda:
        g_yyval.node = expr_build_call(g_yyval.node);
        goto LAB_10617103;
      case 0xdb:
        if (g_yyval.ptr != (void *)0x0) {
          (g_yyval.node)->right = pcVar26[-1].ptr;
        }
        g_yyval.node = expr_build_call(g_yyval.node);
        goto LAB_10617103;
      case 0xdc:
        g_current_scope->unk209 = '\x01';
        uVar45 = (ulonglong)CONCAT24(rule,g_yyval.ptr);
        break;
      case 0xdd:
        g_yyval.node = expr_build_member_access
                                 (pcVar26[-2].spec.words.storage,pcVar26[-3].node,pcVar26->words[0])
        ;
        g_current_scope->unk209 = '\0';
        uVar45 = (ulonglong)g_yyval.words[0];
        break;
      case 0xde:
        result = expr_check_based_operator(pcVar26[-2].node,pcVar26->node);
        goto LAB_10617265;
      case 0xdf:
        result = expr_identifier(pcVar26->words[0]);
        goto LAB_10617265;
      case 0xe0:
        result = tree_new_constant((pcVar26->constant).type,pcVar26->words + 2,g_expr_arena_index);
        goto LAB_10617265;
      case 0xe1:
        type_string_literal_array(pcVar26->node);
        uVar45 = (ulonglong)g_yyval.words[0];
        break;
      case 0xe2:
        g_yyval.node = expr_build_unary(0xf0,pcVar26[-1].node);
LAB_10617103:
        uVar45 = (ulonglong)g_yyval.words[0];
        if (0 < g_paren_depth) {
          g_paren_depth = g_paren_depth + -1;
          uVar45 = (ulonglong)g_yyval.words[0];
        }
        break;
      case 0xe3:
        pfVar21 = g_arenas + g_expr_arena_index;
        pcVar6 = (c1_symbol *)pfVar21->cur;
        puVar7 = g_arenas[g_expr_arena_index].end;
        pfVar21->cur = (uchar *)&pcVar6->key_ref;
        if (puVar7 < &pcVar6->key_ref) {
          arena_grow(pfVar21);
        }
        g_yyval.sym = pcVar6;
        pcVar6->flags1 = '\x05';
        pcVar6->kind = '\a';
        pcVar6->position = (c1_u32)pcVar26->ptr;
        pcVar23 = (c1_type *)pcVar26->words[1];
        pcVar6->type = pcVar23;
        uVar45 = CONCAT44(pcVar23,g_yyval.ptr);
        break;
      case 0xe4:
        lex_concatenate_strings((c1_string_value *)&(pcVar26[-1].node)->left,pcVar26);
        uVar45 = (ulonglong)g_yyval.words[0];
        break;
      case 0xe5:
        g_nested_declaration_depth = g_nested_declaration_depth + 1;
        uVar45 = (ulonglong)CONCAT24(rule,g_yyval.ptr);
        break;
      case 0xe7:
        type_name_word = 0;
        pcVar25 = pcVar26->node;
        pcVar25->unk0c = 0;
        pcVar25->left = (void *)0x0;
        pcVar25->right = (void *)0x0;
        decl_apply_specifiers(pcVar26->decl->declarator,&pcVar26[-1].spec);
        decl_finish_declarator(pcVar26->decl->declarator);
        decl_abstract_declarator(pcVar26->decl);
        g_nested_declaration_depth = g_nested_declaration_depth + -1;
        g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfc;
        result = sym_new_from_declarator(pcVar26->decl,-1);
        goto LAB_10617265;
      case 0xe8:
        result = expr_declare_undefined_function(pcVar26[-1].words[0]);
        goto LAB_10617265;
      case 0xe9:
        result = expr_call_begin(pcVar26[-1].node);
        goto LAB_10617265;
      case 0xea:
        cVar8 = pcVar26->words[0];
        uVar48 = (undefined1)cVar8;
        uVar49 = (undefined1)(cVar8 >> 8);
        uVar50 = (undefined2)(cVar8 >> 0x10);
        uVar46 = 0;
        uVar47 = 0;
        uVar29 = 0;
        goto LAB_106173c1;
      case 0xeb:
        cVar8 = pcVar26->words[0];
        cVar9 = pcVar26[-2].words[0];
        uVar48 = (undefined1)cVar8;
        uVar49 = (undefined1)(cVar8 >> 8);
        uVar50 = (undefined2)(cVar8 >> 0x10);
        uVar46 = (undefined1)cVar9;
        uVar47 = (undefined1)(cVar9 >> 8);
        uVar29 = (undefined2)(cVar9 >> 0x10);
LAB_106173c1:
        result = tree_append_list_item
                           ((c1_node *)CONCAT22(uVar29,CONCAT11(uVar47,uVar46)),
                            (c1_node *)CONCAT22(uVar50,CONCAT11(uVar49,uVar48)),0);
LAB_10617265:
        uVar45 = ZEXT48(result);
      }
      goto switchD_10615cfc_caseD_2;
    }
    switch(parser->errflag) {
    case 0:
      sVar38 = 0;
      iVar19 = 0;
      pcVar33 = g_yy_token_insertions;
      break;
    case 1:
    case 2:
      goto switchD_1063069f_caseD_1;
    case 3:
      goto switchD_1063069f_caseD_3;
    default:
      goto switchD_1063069f_default;
    }
    do {
      if (parser->state <= sVar38) break;
      sVar38 = pcVar33[1].state;
      pcVar33 = pcVar33 + 1;
      iVar19 = iVar19 + 3;
    } while (sVar38 != -1000);
    if (parser->state == (&g_yy_token_insertions[0].state)[iVar19]) {
      iVar31 = (int)(&g_yy_token_insertions[0].token)[iVar19];
      if (iVar31 < 0) {
        parser->errflag = parser->errflag + 1;
        iVar31 = -iVar31;
      }
      if (parser->errflag < 2) {
        parse_report_missing_token(parser->lookahead,iVar31);
      }
      pcVar26 = yyparse_c_value_for_token(&local_18,iVar31);
      sVar38 = (&g_yy_token_insertions[0].next_state)[iVar19];
      pcVar39 = &g_yyval;
      for (iVar19 = 6; iVar19 != 0; iVar19 = iVar19 + -1) {
        pcVar39->words[0] = (c1_u32)pcVar26->ptr;
        pcVar26 = (c1_yystype *)&(pcVar26->string).length;
        pcVar39 = (c1_yystype *)(&pcVar39->ptr + 1);
      }
      parser->state = sVar38;
      uVar45 = (ulonglong)g_yyval.words[0];
    }
    else {
      yyerror_c("syntax error");
      parser->nerrs = parser->nerrs + 1;
switchD_1063069f_caseD_1:
      parser->errflag = 3;
      while( true ) {
        psVar10 = parser->ssp;
        if (psVar10 < parser->ss) {
          return 1;
        }
        sVar38 = g_yy_pact[*psVar10] + 0x100;
        if (((-1 < sVar38) && (sVar38 < 0x52e)) && (g_yy_chk[g_yy_action[sVar38]] == 0x100)) break;
        parser->ssp = psVar10 + -1;
        parser->vsp = parser->vsp + -1;
      }
      parser->state = g_yy_action[sVar38];
      uVar45 = (ulonglong)g_yyval.words[0];
    }
switchD_10615cfc_caseD_2:
    g_yyval.words[0] = (c1_u32)uVar45;
    pcVar30 = (c1_yyparse_state *)(parser->ssp + 1);
    parser->ssp = (short *)pcVar30;
    if (parser + 1 < pcVar30) {
      yyerror_c("yacc stack overflow");
      return 1;
    }
  } while( true );
switchD_1063069f_caseD_3:
  if ((parser->lookahead != (c1_token *)0x0) && ((&g_token_class)[parser->lookahead->code] == '\0'))
  {
    return 1;
  }
  parser->lookahead = (c1_token *)0x0;
  goto LAB_10615c08;
}

