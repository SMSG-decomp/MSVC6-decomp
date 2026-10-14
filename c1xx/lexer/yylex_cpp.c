byte * __cdecl yylex_cpp(void)

{
  ushort uVar1;
  c1xx_token *pcVar2;
  byte *pbVar3;
  int have_input;
  uint uVar4;
  c1_type *pcVar5;
  c1xx_token *pcVar6;
  int iVar7;
  int iVar8;
  byte bVar9;
  byte bVar10;
  uint *yylval_words_3;
  uint *yylval_words_2;
  uint *yylval_words;
  uint *yylval_words_4;
  uint uVar11;
  uint *puVar12;
  void **ppvVar13;
  uint local_2c;
  c1_type local_28;
  uint local_18 [6];
  undefined2 int_flags;
  undefined2 int_code;
  
  pcVar2 = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
  bVar10 = pcVar2->code;
  uVar11 = (uint)bVar10;
  uVar4 = (uint)g_token_class[uVar11];
  if (0xe6 < uVar4) {
switchD_104059a8_caseD_1:
    return &pcVar2->code;
  }
  do {
    iVar8 = g_paren_depth;
    switch((&switchD_104059a8::switchdataD_104064f0)[uVar4]) {
    case 0:
    case 0x6d:
      if (g_eof_terminal_returned == '\0') {
        g_eof_terminal_returned = '\x01';
        return &g_token_end_of_file->code;
      }
      if ((g_compile_flags_c4 & 0x20) != 0) {
        func_definition_end('\x01');
      }
      if (g_template_work_queue != (c1_tmpl_work_queue *)0x0) {
        g_template_work_queue->armed = '\x01';
      }
      have_input._0_1_ = lex_fetch_pending_input();
      if ((char)have_input == '\0') {
        pch_check_after_options();
        return &g_token_end_of_input->code;
      }
      break;
    default:
      goto switchD_104059a8_caseD_1;
    case 6:
    case 0x96:
      goto switchD_104059a8_caseD_6;
    case 0xf:
      if ((g_compile_flags_c4 & 2) != 0) {
        return &pcVar2->code;
      }
      pbVar3 = (byte *)lex_lookahead_decl_specifiers((char *)pcVar2);
      return pbVar3;
    case 0x1a:
    case 0x1b:
    case 0x1c:
    case 0x1d:
switchD_104059a8_caseD_1a:
      if ((g_compile_flags_c4 & 2) == 0) goto switchD_104059a8_caseD_20;
      diag_error(0x206,uVar11);
      break;
    case 0x1f:
    case 0x21:
    case 0xba:
      goto switchD_104059a8_caseD_1f;
    case 0x20:
switchD_104059a8_caseD_20:
      pbVar3 = (byte *)lex_peek_token((uint *)&g_token_position);
      if (g_token_class[*pbVar3] == 0xab) {
        return &pcVar2->code;
      }
      goto switchD_104059a8_caseD_1f;
    case 0x24:
      bVar10 = g_paren_level_flags[g_paren_depth];
      if ((((bVar10 & 2) != 0) && ((g_compile_flags_c4 & 0x8000000) != 0)) &&
         (pcVar2->type_symbol != (c1_symbol *)0x0)) {
        g_yylval = (uint)pcVar2->type_symbol->name;
        if (g_token_arena_index == 0) {
          pbVar3 = pool_alloc_raw(&g_pool_default,0x30);
        }
        else {
          pbVar3 = arena_alloc(g_arenas + g_token_arena_index,0x30);
        }
        if (pbVar3 != (byte *)0x0) {
          *pbVar3 = 6;
          yylval_words_3 = &g_yylval;
          puVar12 = (uint *)(pbVar3 + 8);
          for (iVar8 = 10; iVar8 != 0; iVar8 = iVar8 + -1) {
            *puVar12 = *yylval_words_3;
            yylval_words_3 = yylval_words_3 + 1;
            puVar12 = puVar12 + 1;
          }
          return pbVar3;
        }
        return (byte *)0x0;
      }
      if ((g_compile_flags_c4 & 0x10000000) != 0) {
        g_compile_flags_c4 = g_compile_flags_c4 | 1;
        return &pcVar2->code;
      }
      g_compile_flags_c4 = g_compile_flags_c4 | 1;
      g_paren_level_flags[g_paren_depth] = bVar10 | 2;
      if ((bVar10 & 0x80) == 0) {
        return &pcVar2->code;
      }
      g_paren_level_flags[iVar8] = bVar10 & 0x7e | 3;
      return &pcVar2->code;
    case 0x28:
      if ((g_compile_flags_c4 & 4) != 0) {
        return &pcVar2->code;
      }
      pbVar3 = (byte *)lex_lookahead_decl_specifiers((char *)pcVar2);
      return pbVar3;
    case 0x2c:
      if ((g_compile_flags_c4 & 0x10000000) == 0) {
        bVar10 = g_paren_level_flags[g_paren_depth];
        g_paren_level_flags[g_paren_depth] = bVar10 | 2;
        if ((bVar10 & 0x80) != 0) {
          g_paren_level_flags[iVar8] = bVar10 & 0x7e | 3;
        }
      }
      g_compile_flags_c4 = g_compile_flags_c4 | 0x80000000;
      return &pcVar2->code;
    case 0x59:
      g_compile_flags_c4 = g_compile_flags_c4 | 1;
    case 0x31:
    case 0x3c:
    case 0x46:
    case 0x4a:
    case 0x51:
    case 0x65:
    case 0x73:
    case 0x78:
    case 0x8c:
    case 0x8d:
    case 0x8e:
    case 0x8f:
    case 0x90:
    case 0x98:
    case 0xac:
    case 0xd9:
switchD_104059a8_caseD_31:
      uVar4 = g_compile_flags_c4 & 0x10000000;
LAB_10405cd7:
      iVar8 = g_paren_depth;
      if (uVar4 != 0) {
        return &pcVar2->code;
      }
      bVar10 = g_paren_level_flags[g_paren_depth];
      g_paren_level_flags[g_paren_depth] = bVar10 | 2;
      if ((bVar10 & 0x80) == 0) {
        return &pcVar2->code;
      }
      g_paren_level_flags[iVar8] = bVar10 & 0x7e | 3;
      return &pcVar2->code;
    case 0x75:
    case 0x7b:
    case 0x7f:
      if (g_paren_depth == 0) {
        return &pcVar2->code;
      }
      bVar9 = 1;
      local_2c = 1;
      if (g_paren_depth < 1) {
        return &pcVar2->code;
      }
      do {
        if (bVar9 != 1) goto LAB_10459a9c;
        if (((g_current_function != (c1_symbol *)0x0) && (bVar10 == 0x7f)) && (iVar8 == 1)) {
          return &pcVar2->code;
        }
        if ((g_paren_level_flags[iVar8] & 0x10) == 0) {
          if ((g_paren_level_flags[iVar8] & 0x40) == 0) {
            bVar9 = 0x7e;
            goto LAB_10459a86;
          }
          if ((iVar8 == 1) && (bVar10 != 0x7f)) {
            bVar9 = 0x7f;
            goto LAB_10459a86;
          }
        }
        else {
          bVar9 = 0xbf;
LAB_10459a86:
          local_2c = (uint)bVar9;
        }
        iVar8 = iVar8 + -1;
      } while (0 < iVar8);
      if (bVar9 == 1) {
        return &pcVar2->code;
      }
LAB_10459a9c:
      diag_error(0x8f,local_2c,uVar11);
      (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)pcVar2);
      (*g_token_source->stream->vtbl->unget)
                (g_token_source->stream,(char *)(&g_token_static_records)[local_2c]);
      break;
    case 0x76:
      if ((g_compile_flags_c4 & 0x10000000) == 0) {
        iVar8 = g_paren_depth + 1;
        if (0x3b < iVar8) {
          g_paren_depth = iVar8;
          diag_fatal_simple(0xd);
        }
        iVar7 = g_paren_depth + 1;
        g_paren_depth = iVar8;
        g_pending_access_check[iVar8] = (c1_symbol *)0x0;
        g_paren_level_flags[iVar7] = 0;
      }
      g_compile_flags_c4 = g_compile_flags_c4 & 0xfffffffe;
      return &pcVar2->code;
    case 0x7c:
      if ((g_paren_level_flags[g_paren_depth] & 0x10) == 0) {
        return &pcVar2->code;
      }
      if (pcVar2->code != 0x3e) {
        return &pcVar2->code;
      }
      return &g_token_template_close->code;
    case 0x7d:
      uVar4 = g_compile_flags_c4 & 0x10000000;
      if (uVar4 == 0) {
        bVar10 = g_paren_level_flags[g_paren_depth];
        g_paren_level_flags[g_paren_depth] = bVar10 | 2;
        if ((bVar10 & 0x80) != 0) {
          g_paren_level_flags[iVar8] = bVar10 & 0x7e | 3;
        }
      }
      if (uVar4 != 0) {
        return &pcVar2->code;
      }
      g_paren_level_flags[iVar8] = g_paren_level_flags[iVar8] | 1;
      return &pcVar2->code;
    case 0x7e:
      uVar4 = g_compile_flags_c4 & 0xfffffffe;
      if (g_paren_depth != 0) {
        g_compile_flags_c4 = uVar4;
        return &pcVar2->code;
      }
      if ((g_compile_flags_c4 & 0x10000000) != 0) {
        g_compile_flags_c4 = uVar4;
        return &pcVar2->code;
      }
      g_compile_flags_c4 = uVar4;
      diag_error(0x3b,0x4c,(uint)pcVar2->code);
      break;
    case 0x81:
      uVar4 = g_compile_flags_c4 & 0x10000000;
      if (uVar4 == 0) {
        g_sizeof_depth = g_sizeof_depth + 1;
      }
      goto LAB_10405cd7;
    case 0x95:
      if ((g_compile_flags_c4 & 0x40) != 0) {
        return &pcVar2->code;
      }
      (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)pcVar2);
      pcVar2 = (c1xx_token *)lex_compose_qualified_name((char *)0x0,0);
      if (pcVar2->code == 0x96) {
switchD_104059a8_caseD_6:
        g_compile_flags_c4 = g_compile_flags_c4 | 0x400;
        pcVar2 = lex_classify_type_name(pcVar2);
        g_compile_flags_c4 = g_compile_flags_c4 & 0xfffffbff;
        if (pcVar2->code == '\x1e') {
          pbVar3 = (byte *)lex_lookahead_decl_specifiers((char *)pcVar2);
          return pbVar3;
        }
LAB_10405b5e:
        iVar8 = g_paren_depth;
        if ((g_compile_flags_c4 & 0x10000000) != 0) {
          return &pcVar2->code;
        }
        bVar10 = g_paren_level_flags[g_paren_depth];
        g_paren_level_flags[g_paren_depth] = bVar10 | 2;
        if ((bVar10 & 0x80) != 0) {
          g_paren_level_flags[iVar8] = bVar10 & 0x7e | 3;
          return &pcVar2->code;
        }
        return &pcVar2->code;
      }
      goto switchD_104059a8_caseD_31;
    case 0x97:
      pcVar2 = (c1xx_token *)lex_operator_function_id();
      goto LAB_10405b5e;
    case 0xa4:
      (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)pcVar2);
      if ((((g_paren_depth != 0) &&
           (bVar10 = *(byte *)((int)&g_function_tuple_count + g_paren_depth + 3), (bVar10 & 1) == 0)
           ) && ((g_paren_depth < 1 || ((bVar10 & 4) == 0)))) &&
         (((g_compile_flags_c4 & 0x20000) != 0 && ((g_compile_flags_c4 & 0x20) == 0)))) {
        pbVar3 = parse_classify_candidate_token('\0');
        return pbVar3;
      }
      pbVar3 = parse_classify_candidate_token('\x01');
      return pbVar3;
    case 0xa5:
      bVar10 = g_paren_level_flags[g_paren_depth];
      if ((bVar10 & 2) != 0) {
        return &pcVar2->code;
      }
      local_18[0]._0_1_ = (byte)local_18[0] & 0xf8;
      puVar12 = local_18;
      for (iVar7 = 6; iVar7 != 0; iVar7 = iVar7 + -1) {
        *puVar12 = 0;
        puVar12 = puVar12 + 1;
      }
      if (((g_compile_flags_c4 & 0x10000000) == 0) &&
         (g_paren_level_flags[g_paren_depth] = bVar10 | 2, (bVar10 & 0x80) != 0)) {
        g_paren_level_flags[iVar8] = bVar10 & 0x7e | 3;
      }
      local_18[0]._0_1_ = (byte)local_18[0] ^ (byte)local_18[0] & 7 | 0x30;
      uVar1 = *(ushort *)&pcVar2->value;
      pcVar5 = g_type_int;
      if ((g_type_int->flags & uVar1) != uVar1) {
        int_code = g_type_int->code;
        int_flags = g_type_int->flags;
        local_28.base = g_type_int->base;
        local_28.flags = int_flags | uVar1;
        local_28.code = int_code;
        local_28.extra = g_type_int->extra;
        local_28.debug_index = g_type_int->debug_index;
        pcVar5 = type_intern(&local_28);
      }
      yylval_words_2 = local_18;
      puVar12 = &g_yylval;
      g_yylval_spec_type = pcVar5;
      for (iVar8 = 6; iVar8 != 0; iVar8 = iVar8 + -1) {
        *puVar12 = *yylval_words_2;
        yylval_words_2 = yylval_words_2 + 1;
        puVar12 = puVar12 + 1;
      }
      if (g_token_arena_index == 0) {
        pbVar3 = pool_alloc_raw(&g_pool_default,0x30);
      }
      else {
        pbVar3 = arena_alloc(g_arenas + g_token_arena_index,0x30);
      }
      if (pbVar3 != (byte *)0x0) {
        *pbVar3 = 0x24;
        yylval_words = &g_yylval;
        puVar12 = (uint *)(pbVar3 + 8);
        for (iVar8 = 10; iVar8 != 0; iVar8 = iVar8 + -1) {
          *puVar12 = *yylval_words;
          yylval_words = yylval_words + 1;
          puVar12 = puVar12 + 1;
        }
        return pbVar3;
      }
      return (byte *)0x0;
    case 0xab:
      bVar10 = g_current_scope->current->kind;
      if ((bVar10 != 0) && (bVar10 < 0xf9)) {
        pbVar3 = (byte *)tmpl_check_declaration_scope();
        return pbVar3;
      }
      pbVar3 = token_next((c1_token_reader *)&g_token_position);
      if (*pbVar3 != 0x44) {
        (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)pbVar3);
        g_compile_flags_cc = g_compile_flags_cc | 0x10000000;
        return &pcVar2->code;
      }
      pbVar3 = token_next((c1_token_reader *)&g_token_position);
      if (*pbVar3 != 0x3e) {
        (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)pbVar3);
        return &g_token_template_open->code;
      }
switchD_104059a8_caseD_1f:
      pbVar3 = (byte *)lex_lookahead_decl_specifiers((char *)pcVar2);
      return pbVar3;
    case 0xdb:
      g_compile_flags_c4 = g_compile_flags_c4 | 1;
      return &pcVar2->code;
    case 0xe2:
    case 0xe3:
      g_yylval = (uint)g_type_bool;
      _g_yylval_word2 = g_tree_op_to_il_op[pcVar2->code];
      _g_yylval_word3 = 0;
      if (g_token_arena_index == 0) {
        pcVar6 = (c1xx_token *)pool_alloc_raw(&g_pool_default,0x30);
      }
      else {
        pcVar6 = arena_alloc(g_arenas + g_token_arena_index,0x30);
      }
      pcVar2 = (c1xx_token *)0x0;
      if (pcVar6 != (c1xx_token *)0x0) {
        pcVar6->code = 0x65;
        yylval_words_4 = &g_yylval;
        ppvVar13 = &pcVar6->value;
        for (iVar8 = 10; pcVar2 = pcVar6, iVar8 != 0; iVar8 = iVar8 + -1) {
          *ppvVar13 = (void *)*yylval_words_4;
          yylval_words_4 = yylval_words_4 + 1;
          ppvVar13 = ppvVar13 + 1;
        }
      }
      goto switchD_104059a8_caseD_31;
    case 0xe6:
      if ((((g_compile_flags_c8 & 0x52000000) != 0) || ((g_compile_flags_cc & 0x300000) != 0)) ||
         ((g_compile_flags_cc & 8) != 0)) goto switchD_104059a8_caseD_1a;
      diag_error(899);
    }
    pcVar2 = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
    bVar10 = pcVar2->code;
    uVar11 = (uint)bVar10;
    uVar4 = (uint)g_token_class[uVar11];
    if (0xe6 < uVar4) {
      return &pcVar2->code;
    }
  } while( true );
}

