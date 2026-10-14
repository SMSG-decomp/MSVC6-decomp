int __thiscall yyparse_cpp(c1_yy_parser *parser)

{
  ushort *puVar1;
  c1_yy_value *value_base;
  ushort uVar2;
  short sVar3;
  c1_scope_body cVar4;
  c1xx_il_emitter_vtbl *pcVar5;
  c1_arg_value cVar6;
  c1_node *pcVar7;
  uint uVar8;
  char cVar9;
  c1_u8 cVar10;
  byte bVar11;
  c1_u16 bits;
  int iVar12;
  c1_scope_body *pcVar13;
  char *token;
  c1_yy_value *pcVar14;
  c1_symbol *pcVar15;
  c1_yy_action_slot d;
  byte *pbVar16;
  c1_param_clause *pcVar17;
  c1xx_scope *scope;
  c1_sym_list *params;
  c1_arg_item *pcVar18;
  c1_arg_list *pcVar19;
  int *piVar20;
  c1_decl_modifier *pcVar21;
  int iVar22;
  void *pvVar23;
  c1_node *pcVar24;
  c1_line_map_row *pcVar25;
  c1xx_token_stream *stream;
  c1xx_token *pcVar26;
  uint *puVar27;
  c1_lookup_entry *cell;
  c1_u8 *pcVar28;
  c1_u32 cVar29;
  fe_name *pfVar30;
  c1_symbol *pcVar31;
  c1_declarator *d_00;
  c1_type *pcVar32;
  c1_declarator *pcVar33;
  c1_decl_record *pcVar34;
  int iVar35;
  c1_arena *a;
  uint uVar36;
  undefined4 extraout_ECX;
  short *psVar37;
  undefined2 uVar41;
  c1xx_idb_vtbl *pcVar38;
  c1_yy_value *pcVar39;
  c1_yy_value *pcVar40;
  c1_u32 *pcVar42;
  void **ppvVar43;
  bool bVar44;
  longlong lVar45;
  longlong lVar46;
  c1_decl_modifier cVar47;
  c1_u32 acStackY_1a8 [2];
  undefined1 uVar48;
  undefined1 uVar49;
  undefined1 uVar50;
  undefined1 uVar51;
  undefined2 uVar52;
  c1_symbol **ppcVar53;
  c1xx_decl_specifiers *pcVar54;
  c1_symbol *qualifier;
  c1_overload_set *pcVar55;
  uint uVar56;
  c1_yy_action_slot in_stack_fffffe94;
  int *state_sp;
  byte *saved_lookahead;
  uint uStack_150;
  c1_decl_modifier local_14c;
  c1_decl_modifier local_144;
  c1_decl_modifier cStack_13c;
  c1_type cStack_134;
  c1xx_decl_specifiers cStack_124;
  c1_decl_modifier local_100;
  c1_decl_modifier local_f8;
  c1xx_decl_specifiers local_f0;
  c1xx_decl_specifiers local_cc;
  c1xx_decl_specifiers local_a8;
  c1xx_decl_specifiers local_84;
  c1xx_decl_specifiers local_60;
  c1xx_decl_specifiers local_3c;
  uint auStack_18 [6];
  
  saved_lookahead = g_yy_lookahead;
  state_sp = (int *)((int)parser->values + 0x9ffc);
  g_yy_lookahead = (byte *)0x0;
  pcVar14 = (c1_yy_value *)(parser[-1].states + 0x3fc);
  iVar22 = 0;
  iVar12 = g_yy_rule;
LAB_1042188d:
  do {
    piVar20 = state_sp + 1;
    pcVar40 = pcVar14 + 1;
    *piVar20 = iVar22;
    sVar3 = g_yy_pact[iVar22];
    state_sp = piVar20;
    if (-1000 < sVar3) {
      if (g_yy_lookahead == (byte *)0x0) {
        g_yy_lookahead = yylex_cpp();
      }
      iVar35 = (int)sVar3 + (uint)g_token_class[*g_yy_lookahead];
      if (((-1 < iVar35) && (iVar35 < 0xfdc)) &&
         (iVar35 = (int)g_yy_action[iVar35],
         g_yy_chk[iVar35] == (ushort)g_token_class[*g_yy_lookahead])) {
        if (parser->states + 0x3fb < piVar20) {
          yyerror_cpp("yacc stack overflow");
          g_yy_result = 1;
          iVar12 = parse_yacc_return_tail(saved_lookahead,iVar12);
          return iVar12;
        }
        yy_copy_token_value(pcVar14 + 2,g_yy_lookahead);
        g_yy_lookahead = (byte *)0x0;
        pcVar14 = pcVar40;
        iVar22 = iVar35;
        if (0 < parser->errflag) {
          parser->errflag = parser->errflag + -1;
        }
        goto LAB_1042188d;
      }
    }
    iVar35 = (int)g_yy_def[iVar22];
    lVar45 = g_enum_value;
    if (iVar35 < 1) {
      if (iVar35 == -2) {
        piVar20 = state_sp;
        if (g_yy_lookahead == (byte *)0x0) {
          g_yy_lookahead = yylex_cpp();
          piVar20 = state_sp;
          lVar45 = g_enum_value;
        }
        psVar37 = g_yy_exca + g_yy_exca_index[iVar22];
        uVar2 = g_yy_exca[g_yy_exca_index[iVar22]];
        while ((uVar2 != g_token_class[*g_yy_lookahead] && (-1 < (short)uVar2))) {
          puVar1 = (ushort *)(psVar37 + 2);
          psVar37 = psVar37 + 2;
          uVar2 = *puVar1;
        }
        iVar35 = (int)psVar37[1];
        state_sp = piVar20;
        if (iVar35 < 0) {
          g_yy_result = 0;
          g_enum_value = lVar45;
          iVar12 = parse_yacc_return_tail(saved_lookahead,iVar12);
          return iVar12;
        }
      }
      if (iVar35 == 0) {
        g_enum_value = lVar45;
        iVar12 = yyparse_cpp_error_entry
                           (0,pcVar40,piVar20,iVar22,parser,in_stack_fffffe94,saved_lookahead,iVar12
                           );
        return iVar12;
      }
    }
    iVar22 = g_paren_depth;
    pcVar26 = (c1xx_token *)g_yy_lookahead;
    g_enum_value._4_4_ = (undefined4)((ulonglong)lVar45 >> 0x20);
    g_enum_value._0_4_ = (undefined4)lVar45;
    uVar56 = (uint)g_yy_r2[iVar35];
    state_sp = state_sp + -uVar56;
    value_base = pcVar40 + -uVar56;
    uVar41 = (undefined2)(uVar56 * -5 >> 0x10);
    g_yy_rule = iVar35;
    g_enum_value = lVar45;
    switch(iVar35) {
    case 3:
      iVar22 = parser->error_count;
LAB_104235dc:
      g_yy_result = iVar22;
      iVar12 = parse_yacc_return_tail(saved_lookahead,iVar12);
      return iVar12;
    case 5:
      paren_depth_leave(pcVar14->words[0]);
      lVar45 = g_enum_value;
      break;
    case 6:
      paren_depth_leave(0);
      lVar45 = g_enum_value;
      break;
    case 8:
      if ((g_yy_lookahead == (byte *)0x0) || (*g_yy_lookahead != 0x76)) {
        pcVar54 = g_paren_level_declspecs + g_paren_depth;
        for (iVar35 = 9; iVar35 != 0; iVar35 = iVar35 + -1) {
          *(c1_u32 *)pcVar54->spec = pcVar14->words[0];
          pcVar54 = (c1xx_decl_specifiers *)(pcVar54->spec + 4);
          pcVar14 = (c1_yy_value *)(pcVar14->words + 1);
        }
        g_paren_level_flags[iVar22] = g_paren_level_flags[iVar22] | 1;
        lVar45 = g_enum_value;
      }
      else {
        pcVar42 = (c1_u32 *)(&g_paren_level_declspecs_prev_base + g_paren_depth * 0x24);
        iVar35 = 9;
LAB_10420c2b:
        for (; g_enum_value = lVar45, iVar35 != 0; iVar35 = iVar35 + -1) {
          *pcVar42 = pcVar14->words[0];
          pcVar14 = (c1_yy_value *)(pcVar14->words + 1);
          pcVar42 = pcVar42 + 1;
          lVar45 = g_enum_value;
        }
        pbVar16 = (byte *)((int)&g_function_tuple_count + iVar22 + 3);
        *pbVar16 = *pbVar16 | 1;
        lVar45 = g_enum_value;
      }
      break;
    case 9:
      pcVar40 = pcVar14 + -1;
      g_declarator_paren_base = g_declarator_paren_base + -1;
      decl_check_conversion_return_type(pcVar14->declarator->decl,&pcVar40->spec);
      decl_finish_declarator(pcVar14->declarator->decl);
      pcVar39 = pcVar40;
      ppvVar43 = (void **)&pcVar14->node->unk0c;
      for (iVar22 = 6; iVar22 != 0; iVar22 = iVar22 + -1) {
        *ppvVar43 = (void *)pcVar39->words[0];
        pcVar39 = (c1_yy_value *)(pcVar39->words + 1);
        ppvVar43 = ppvVar43 + 1;
      }
      pcVar14->declarator->flags56 = pcVar14->declarator->flags56 | 0x20;
      if (g_class_depth < 0) {
        if ((g_compile_flags_c8 & 0x40) == 0) {
          g_last_declared_symbol =
               decl_declare_from_declarator(pcVar14->declarator,(byte *)pcVar40->words);
        }
        else {
          g_last_declared_symbol = pcVar14->declarator->sym;
        }
        bVar11 = g_current_scope->current->kind;
        if ((0xfa < bVar11) && (bVar11 != 0xfd)) {
          scope_pop_to_kind(g_current_scope,'\x01');
        }
        class_check_unnamed_class_member(&pcVar40->spec);
        lVar45 = g_enum_value;
      }
      else {
        pcVar14->declarator->kind = 2;
        in_stack_fffffe94.sym = (c1_symbol *)0x0;
        cVar9 = class_begin_member_list
                          (pcVar14->declarator,&pcVar40->spec,(c1_symbol **)&stack0xfffffe94);
        lVar45 = g_enum_value;
        if (((cVar9 == '\0') && (bVar11 = g_current_scope->current->kind, 0xfa < bVar11)) &&
           (bVar11 != 0xfd)) {
          scope_pop_to_kind(g_current_scope,'\x01');
          lVar45 = g_enum_value;
        }
        g_last_declared_symbol = in_stack_fffffe94.sym;
        if ((c1_declarator *)in_stack_fffffe94.sym == (c1_declarator *)0x0) {
          g_last_declared_symbol = pcVar14->declarator->sym;
        }
      }
      break;
    case 10:
      g_compile_flags_c4 = g_compile_flags_c4 | 0x1000000;
      g_compile_flags_c8 = g_compile_flags_c8 & 0xfffffffd;
      g_declarator_paren_base = g_declarator_paren_base + -1;
      if ((g_paren_level_flags[g_paren_depth] & 1) == 0) {
        pcVar54 = decl_specifiers_default((void *)0x0);
      }
      else {
        pcVar54 = g_paren_level_declspecs + g_paren_depth;
      }
      decl_check_conversion_return_type(pcVar14->declarator->decl,pcVar54);
      decl_finish_declarator(pcVar14->declarator->decl);
      if ((g_paren_level_flags[g_paren_depth] & 1) == 0) {
        pcVar54 = decl_specifiers_default((void *)0x0);
      }
      else {
        pcVar54 = g_paren_level_declspecs + g_paren_depth;
      }
      ppvVar43 = (void **)&pcVar14->node->unk0c;
      for (iVar22 = 6; iVar22 != 0; iVar22 = iVar22 + -1) {
        *ppvVar43 = *(void **)pcVar54->spec;
        pcVar54 = (c1xx_decl_specifiers *)(pcVar54->spec + 4);
        ppvVar43 = ppvVar43 + 1;
      }
      pcVar14->declarator->flags56 = pcVar14->declarator->flags56 | 0x20;
      if (g_class_depth < 0) {
        if ((g_compile_flags_c8 & 0x40) == 0) {
          if ((g_paren_level_flags[g_paren_depth] & 1) == 0) {
            pcVar54 = decl_specifiers_default((void *)0x0);
            g_last_declared_symbol = decl_declare_from_declarator(pcVar14->declarator,pcVar54->spec)
            ;
          }
          else {
            g_last_declared_symbol =
                 decl_declare_from_declarator
                           (pcVar14->declarator,g_paren_level_declspecs[g_paren_depth].spec);
          }
        }
        else {
          g_last_declared_symbol = pcVar14->declarator->sym;
        }
        bVar11 = g_current_scope->current->kind;
        lVar45 = g_enum_value;
        if ((0xfa < bVar11) && (bVar11 != 0xfd)) {
          scope_pop_to_kind(g_current_scope,'\x01');
          lVar45 = g_enum_value;
        }
      }
      else {
        pcVar14->declarator->kind = 2;
        in_stack_fffffe94.sym = (c1_symbol *)0x0;
        if ((g_paren_level_flags[g_paren_depth] & 1) == 0) {
          pcVar54 = decl_specifiers_default((void *)0x0);
        }
        else {
          pcVar54 = g_paren_level_declspecs + g_paren_depth;
        }
        cVar9 = class_begin_member_list(pcVar14->declarator,pcVar54,(c1_symbol **)&stack0xfffffe94);
        lVar45 = g_enum_value;
        if (((cVar9 == '\0') && (bVar11 = g_current_scope->current->kind, 0xfa < bVar11)) &&
           (bVar11 != 0xfd)) {
          scope_pop_to_kind(g_current_scope,'\x01');
          lVar45 = g_enum_value;
        }
        g_last_declared_symbol = in_stack_fffffe94.sym;
        if ((c1_declarator *)in_stack_fffffe94.sym == (c1_declarator *)0x0) {
          g_last_declared_symbol = pcVar14->declarator->sym;
        }
      }
      break;
    case 0xb:
      g_compile_flags_c4 = g_compile_flags_c4 | 0x1000000;
      g_compile_flags_c8 = g_compile_flags_c8 & 0xfffffffd;
      bVar11 = g_current_scope->current->kind;
      if ((0xfa < bVar11) && (bVar11 != 0xfd)) {
        scope_pop_to_kind(g_current_scope,'\x01');
      }
      if ((g_paren_level_flags[g_paren_depth] & 1) == 0) {
        pcVar54 = decl_specifiers_default((void *)0x0);
      }
      else {
        pcVar54 = g_paren_level_declspecs + g_paren_depth;
      }
      decl_check_conversion_return_type(pcVar14->declarator->decl,pcVar54);
      decl_finish_declarator(pcVar14->declarator->decl);
      if ((g_paren_level_flags[g_paren_depth] & 1) == 0) {
        pcVar54 = decl_specifiers_default((void *)0x0);
      }
      else {
        pcVar54 = g_paren_level_declspecs + g_paren_depth;
      }
      ppvVar43 = (void **)&pcVar14->node->unk0c;
      for (iVar22 = 6; iVar22 != 0; iVar22 = iVar22 + -1) {
        *ppvVar43 = *(void **)pcVar54->spec;
        pcVar54 = (c1xx_decl_specifiers *)(pcVar54->spec + 4);
        ppvVar43 = ppvVar43 + 1;
      }
      if ((g_paren_level_flags[g_paren_depth] & 1) == 0) {
        pcVar54 = decl_specifiers_default((void *)0x0);
      }
      else {
        pcVar54 = g_paren_level_declspecs + g_paren_depth;
      }
      g_last_declared_symbol = func_begin_member_definition(pcVar14->declarator,pcVar54->spec);
      g_declarator_paren_base = g_declarator_paren_base + -1;
      g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfc;
      lVar45 = g_enum_value;
      break;
    case 0xc:
      g_compile_flags_c4 = g_compile_flags_c4 & 0xfeffffff;
      g_compile_flags_c8 = g_compile_flags_c8 & 0xfffffffd;
      bVar11 = g_current_scope->current->kind;
      if ((0xfa < bVar11) && (bVar11 != 0xfd)) {
        scope_pop_to_kind(g_current_scope,'\x01');
      }
      pcVar40 = pcVar14 + -1;
      decl_check_conversion_return_type(pcVar14->declarator->decl,&pcVar40->spec);
      decl_finish_declarator(pcVar14->declarator->decl);
      pcVar39 = pcVar40;
      ppvVar43 = (void **)&pcVar14->node->unk0c;
      for (iVar22 = 6; iVar22 != 0; iVar22 = iVar22 + -1) {
        *ppvVar43 = (void *)pcVar39->words[0];
        pcVar39 = (c1_yy_value *)(pcVar39->words + 1);
        ppvVar43 = ppvVar43 + 1;
      }
      g_last_declared_symbol =
           func_begin_member_definition(pcVar14->declarator,(byte *)pcVar40->words);
      goto LAB_10420683;
    case 0xd:
    case 0x83:
      default_argument_store_and_advance_top(pcVar14->node);
      lVar45 = g_enum_value;
      break;
    case 0xe:
      g_class_depth = g_class_depth + -1;
      class_begin_deferred_member_bodies();
      lVar45 = g_enum_value;
      break;
    case 0xf:
      class_reset_member_function_class();
      g_yy_lookahead = (byte *)lex_unget_token((c1xx_token *)g_yy_lookahead);
      lVar45 = g_enum_value;
      break;
    case 0x10:
      parse_external_declaration_end();
      lVar45 = g_enum_value;
      break;
    case 0x11:
      pch_creation_point();
      lVar45 = g_enum_value;
      break;
    case 0x12:
      pp_line_after_pch_options();
      lVar45 = g_enum_value;
      break;
    case 0x13:
      iVar22 = g_error_count;
      if (g_error_count != 0) goto LAB_104235dc;
      break;
    case 0x14:
      pch_hdrstop();
      lVar45 = g_enum_value;
      break;
    case 0x15:
      if ((g_compile_flags_c8 & 0x40) == 0) {
        diag_error(0x1bf);
        lex_skip_to_closing_brace('\0');
        parse_yyerrok(parser);
        lVar45 = g_enum_value;
      }
      else {
        g_compile_flags_c8 = g_compile_flags_c8 & 0xffffffbf;
        lex_skip_to_closing_brace('\0');
        parse_yyerrok(parser);
        lVar45 = g_enum_value;
      }
      break;
    case 0x17:
      g_yy_result = parser->error_count;
      g_yy_rule = iVar12;
      g_yy_lookahead = saved_lookahead;
      return parser->error_count;
    case 0x1b:
    case 0x1c:
      goto switchD_10421905_caseD_18;
    case 0x1e:
      g_compile_flags_c4 = g_compile_flags_c4 | 0x1000000;
      g_compile_flags_c8 = g_compile_flags_c8 & 0xfffffffd;
      if ((g_paren_level_flags[g_paren_depth] & 1) == 0) {
        pcVar54 = decl_specifiers_default((void *)0x0);
        lVar45 = g_enum_value;
      }
      else {
        pcVar54 = g_paren_level_declspecs + g_paren_depth;
      }
      g_enum_value = lVar45;
      decl_check_conversion_return_type(pcVar40->declarator->decl,pcVar54);
      decl_finish_declarator(pcVar40->declarator->decl);
      if ((g_paren_level_flags[g_paren_depth] & 1) == 0) {
        pcVar54 = decl_specifiers_default((void *)0x0);
      }
      else {
        pcVar54 = g_paren_level_declspecs + g_paren_depth;
      }
      ppvVar43 = (void **)&pcVar40->node->unk0c;
      for (iVar22 = 6; iVar22 != 0; iVar22 = iVar22 + -1) {
        *ppvVar43 = *(void **)pcVar54->spec;
        pcVar54 = (c1xx_decl_specifiers *)(pcVar54->spec + 4);
        ppvVar43 = ppvVar43 + 1;
      }
      if ((g_paren_level_flags[g_paren_depth] & 1) == 0) {
        pcVar54 = decl_specifiers_default((void *)0x0);
      }
      else {
        pcVar54 = g_paren_level_declspecs + g_paren_depth;
      }
      func_begin_member_definition(pcVar40->declarator,pcVar54->spec);
      g_declarator_paren_base = g_declarator_paren_base + -1;
      bVar11 = g_current_scope->current->kind;
      if ((0xfa < bVar11) && (bVar11 != 0xfd)) {
        scope_pop_to_kind(g_current_scope,'\x01');
      }
      g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfc;
      lVar45 = g_enum_value;
      break;
    case 0x1f:
      g_ctor_mem_initializers = pcVar40->node;
      func_begin_definition_frame();
      g_compile_flags_c8 = g_compile_flags_c8 & 0xffffffbf;
      lVar45 = g_enum_value;
      break;
    case 0x20:
      funcs_check_incremental();
      lVar45 = g_enum_value;
      break;
    case 0x21:
      tmpl_parse_queued_definition(pcVar40->header);
      lVar45 = g_enum_value;
      break;
    case 0x22:
      g_compile_flags_c4 = g_compile_flags_c4 & 0xfeffffff;
      g_compile_flags_c8 = g_compile_flags_c8 & 0xfffffffd;
      bVar11 = g_current_scope->current->kind;
      if ((0xfa < bVar11) && (bVar11 != 0xfd)) {
        scope_pop_to_kind(g_current_scope,'\x01');
      }
      decl_check_conversion_return_type(pcVar40->declarator->decl,&pcVar14->spec);
      decl_finish_declarator(pcVar40->declarator->decl);
      pcVar39 = pcVar14;
      ppvVar43 = (void **)&pcVar40->node->unk0c;
      for (iVar22 = 6; iVar22 != 0; iVar22 = iVar22 + -1) {
        *ppvVar43 = (void *)pcVar39->words[0];
        pcVar39 = (c1_yy_value *)(pcVar39->words + 1);
        ppvVar43 = ppvVar43 + 1;
      }
      if (g_block_depth == '\0') {
        pcVar31 = func_begin_member_definition(pcVar40->declarator,(byte *)pcVar14->words);
        value_base[1].sym = pcVar31;
      }
      else {
        cVar9 = '\0';
        pcVar31 = decl_declare_in_current_scope(pcVar40->declarator,&pcVar14->spec);
        func_parse_definition_or_skip(pcVar31,cVar9);
        g_yy_lookahead = g_token_end_parse;
      }
LAB_10420683:
      g_declarator_paren_base = g_declarator_paren_base + -1;
      g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfc;
      lVar45 = g_enum_value;
      break;
    case 0x24:
      g_compile_flags_cc = g_compile_flags_cc | 2;
      func_begin_definition_state((int *)(pcVar40->str).text);
      lVar45 = g_enum_value;
      break;
    case 0x25:
      pcVar31 = type_require_complete(pcVar40->sym);
      value_base[1].sym = pcVar31;
      lVar45 = g_enum_value;
      break;
    case 0x26:
      pcVar31 = type_require_complete(pcVar40->sym);
      value_base[1].sym = pcVar31;
      lVar45 = g_enum_value;
      break;
    case 0x27:
    case 0x39:
    case 0xf7:
    case 0x12d:
    case 0x168:
    case 0x174:
    case 0x182:
    case 0x1e8:
      goto switchD_10421905_caseD_24;
    case 0x28:
      g_compile_flags_c4 = g_compile_flags_c4 | 1;
      g_compile_flags_c8 = g_compile_flags_c8 | 0x100;
      break;
    case 0x29:
      if (g_yy_lookahead == (byte *)0x0) {
        g_yy_lookahead = token_next((c1_token_reader *)&g_token_position);
      }
      if (*g_yy_lookahead != 0x75) {
        diag_error(0x264);
        lex_unget_token((c1xx_token *)g_yy_lookahead);
        g_yy_lookahead = g_token_lbrace;
      }
      g_compile_flags_c4 = g_compile_flags_c4 & 0xfffffffe;
      g_compile_flags_c8 = g_compile_flags_c8 & 0xfffffeff;
      value_base[1].ptr = (void *)pcVar40->words[0];
      lVar45 = g_enum_value;
      break;
    case 0x2a:
      pcVar24 = tree_append_expression_list_item((c1_node *)0x0,pcVar40->node);
      value_base[1].node = pcVar24;
      lVar45 = g_enum_value;
      break;
    case 0x2b:
      pcVar24 = tree_append_expression_list_item(pcVar14[-1].node,pcVar40->node);
      value_base[1].node = pcVar24;
      lVar45 = g_enum_value;
      break;
    case 0x2c:
      diag_error(0x276);
      pcVar24 = tree_append_expression_list_item(pcVar14[-1].node,pcVar40->node);
      value_base[1].node = pcVar24;
      lVar45 = g_enum_value;
      break;
    case 0x2d:
    case 0x2f:
    case 0x31:
    case 0x33:
      g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] | 1;
      lVar45 = g_enum_value;
      break;
    case 0x2e:
      cVar29 = pcVar14->words[0];
      pfVar30 = pcVar14[-3].name;
      uVar49 = (undefined1)cVar29;
      uVar51 = (undefined1)(cVar29 >> 8);
      uVar41 = (undefined2)(cVar29 >> 0x10);
      goto LAB_1042079c;
    case 0x30:
      cVar29 = pcVar14->words[0];
      uVar49 = (undefined1)cVar29;
      uVar51 = (undefined1)(cVar29 >> 8);
      uVar41 = (undefined2)(cVar29 >> 0x10);
      pfVar30 = (pcVar14[-3].declarator)->name;
LAB_1042079c:
      cVar9 = '\0';
      pcVar32 = (c1_type *)0x0;
      pcVar31 = sym_new_kind1_placeholder(pfVar30);
      pcVar24 = tree_new_symbol_ref(pcVar31,cVar9);
      pcVar24 = tree_new_node('v',pcVar24,(c1_node *)CONCAT22(uVar41,CONCAT11(uVar51,uVar49)),
                              pcVar32);
      value_base[1].node = pcVar24;
      g_compile_flags_c4 = g_compile_flags_c4 | 1;
      goto LAB_104207ca;
    case 0x32:
    case 0x34:
      cVar29 = pcVar14->words[0];
      pcVar32 = (c1_type *)0x0;
      uVar49 = (undefined1)cVar29;
      uVar51 = (undefined1)(cVar29 >> 8);
      uVar41 = (undefined2)(cVar29 >> 0x10);
      pcVar24 = tree_new_symbol_ref(*pcVar14[-3].cell,'\0');
      pcVar24 = tree_new_node('v',pcVar24,(c1_node *)CONCAT22(uVar41,CONCAT11(uVar51,uVar49)),
                              pcVar32);
      value_base[1].node = pcVar24;
      g_compile_flags_c4 = g_compile_flags_c4 | 1;
      goto LAB_104207ca;
    case 0x35:
      value_base[1].words[0] = 0;
      diag_error(0x15f);
      g_compile_flags_c4 = g_compile_flags_c4 | 1;
      lVar45 = g_enum_value;
      break;
    case 0x36:
      value_base[1].words[0] = 0;
      diag_error(0x15f);
      g_compile_flags_c4 = g_compile_flags_c4 | 1;
      goto LAB_104207ca;
    case 0x37:
      value_base[1].words[0] = 0;
      parse_yyerrok(parser);
      parse_skip_tokens_to_one_of((c1xx_token *)g_yy_lookahead);
      lVar45 = g_enum_value;
      break;
    case 0x38:
      value_base[1].words[0] = pcVar14->words[0];
LAB_104207ca:
      lVar45 = g_enum_value;
      if (0 < g_paren_depth) {
        g_paren_depth = g_paren_depth + -1;
      }
      break;
    case 0x3b:
      pcVar24 = tree_append_list_item((c1_node *)0x0,pcVar40->node,2);
      value_base[1].node = pcVar24;
      lVar45 = g_enum_value;
      break;
    case 0x3c:
      pcVar24 = tree_append_list_item(pcVar14[-1].node,pcVar40->node,2);
      value_base[1].node = pcVar24;
      lVar45 = g_enum_value;
      break;
    case 0x3e:
      decl_pop_linkage_specification();
      lVar45 = g_enum_value;
      break;
    case 0x46:
      if (pcVar14->words[0] == 0) {
        g_compile_flags_c4 = g_compile_flags_c4 | 0x800000;
        g_compile_flags_c8 = g_compile_flags_c8 & 0xffffffbf;
      }
      else {
        g_ctor_mem_initializers = pcVar40->node;
        func_begin_definition_frame();
        g_compile_flags_c8 = g_compile_flags_c8 & 0xffffffbf;
        lVar45 = g_enum_value;
      }
      break;
    case 0x47:
      if (pcVar14[-2].words[0] == 0) {
        g_compile_flags_c4 = g_compile_flags_c4 & 0xff7fffff;
        g_compile_flags_cc = g_compile_flags_cc & 0xfffffffd;
      }
      else {
        funcs_check_incremental();
        g_compile_flags_cc = g_compile_flags_cc & 0xfffffffd;
        lVar45 = g_enum_value;
      }
      break;
    case 0x49:
      parse_yyerrok(parser);
      g_compile_flags_c4 = g_compile_flags_c4 & 0xff7fffff;
      g_compile_flags_c8 = g_compile_flags_c8 & 0xffffffbf;
      g_compile_flags_cc = g_compile_flags_cc & 0xfffffffd;
      lVar45 = g_enum_value;
      break;
    case 0x4a:
      pcVar54 = &local_84;
      for (iVar22 = 9; iVar22 != 0; iVar22 = iVar22 + -1) {
        *(c1_u32 *)pcVar54->spec = pcVar14->words[0];
        pcVar54 = (c1xx_decl_specifiers *)(pcVar54->spec + 4);
        pcVar14 = (c1_yy_value *)(pcVar14->words + 1);
      }
      class_check_unnamed_class_member(&local_84);
      value_base[1].ptr = (void *)pcVar40->words[0];
      lVar45 = g_enum_value;
      break;
    case 0x4b:
      pcVar54 = &local_cc;
      for (iVar22 = 9; iVar22 != 0; iVar22 = iVar22 + -1) {
        *(c1_u32 *)pcVar54->spec = pcVar40->words[0];
        pcVar40 = (c1_yy_value *)(pcVar40->words + 1);
        pcVar54 = (c1xx_decl_specifiers *)(pcVar54->spec + 4);
      }
      class_check_unnamed_class_member(&local_cc);
      decl_check_empty_declaration(local_cc.spec);
      value_base[1].words[0] = 0;
      lVar45 = g_enum_value;
      break;
    case 0x4c:
      tmpl_finish_class_template_declaration(pcVar14 + -1,&pcVar14->spec);
      lVar45 = g_enum_value;
      break;
    case 0x4d:
      tmpl_finish_nonclass_template_declaration(pcVar14 + -1,pcVar14->sym);
      lVar45 = g_enum_value;
      break;
    case 0x4e:
      tmpl_finish_class_template_declaration(pcVar14,(c1xx_decl_specifiers *)0x0);
      lVar45 = g_enum_value;
      break;
    case 0x4f:
      g_compile_flags_cc = g_compile_flags_cc & 0xefffffff;
      pcVar33 = arena_alloc(g_arenas + 5,0x58);
      if (pcVar33 == (c1_declarator *)0x0) {
        pcVar33 = (c1_declarator *)0x0;
      }
      else {
        pcVar33->position = g_token_position;
      }
      pcVar40 = pcVar14;
      pcVar28 = pcVar33->spec;
      for (iVar22 = 6; iVar22 != 0; iVar22 = iVar22 + -1) {
        *(c1_u32 *)pcVar28 = pcVar40->words[0];
        pcVar40 = (c1_yy_value *)(pcVar40->words + 1);
        pcVar28 = pcVar28 + 4;
      }
      tmpl_explicit_instantiation(pcVar33,'\x01',&pcVar14->spec);
      lVar45 = g_enum_value;
      break;
    case 0x50:
      g_compile_flags_cc = g_compile_flags_cc & 0xefffffff;
      pcVar40 = pcVar14 + -1;
      decl_check_conversion_return_type(pcVar14->declarator->decl,&pcVar40->spec);
      decl_finish_declarator(pcVar14->declarator->decl);
      pcVar39 = pcVar40;
      ppvVar43 = (void **)&pcVar14->node->unk0c;
      for (iVar22 = 6; iVar22 != 0; iVar22 = iVar22 + -1) {
        *ppvVar43 = (void *)pcVar39->words[0];
        pcVar39 = (c1_yy_value *)(pcVar39->words + 1);
        ppvVar43 = ppvVar43 + 1;
      }
      tmpl_explicit_instantiation(pcVar14->declarator,'\x01',&pcVar40->spec);
      g_declarator_paren_base = g_declarator_paren_base + -1;
      lVar45 = g_enum_value;
      break;
    case 0x51:
      g_compile_flags_cc = g_compile_flags_cc & 0xefffffff;
      diag_error(0x38d);
      tmpl_explicit_instantiation_without_specifiers(pcVar14->declarator,1);
      bVar11 = g_current_scope->current->kind;
      goto LAB_10465c69;
    case 0x52:
      g_compile_flags_cc = g_compile_flags_cc & 0xefffffff;
      pcVar33 = arena_alloc(g_arenas + 5,0x58);
      if (pcVar33 == (c1_declarator *)0x0) {
        pcVar33 = (c1_declarator *)0x0;
      }
      else {
        pcVar33->position = g_token_position;
      }
      pcVar40 = pcVar14;
      pcVar28 = pcVar33->spec;
      for (iVar22 = 6; iVar22 != 0; iVar22 = iVar22 + -1) {
        *(c1_u32 *)pcVar28 = pcVar40->words[0];
        pcVar40 = (c1_yy_value *)(pcVar40->words + 1);
        pcVar28 = pcVar28 + 4;
      }
      tmpl_explicit_instantiation(pcVar33,pcVar14[-2].spec.spec[0],&pcVar14->spec);
      lVar45 = g_enum_value;
      break;
    case 0x53:
      pcVar40 = pcVar14 + -1;
      g_compile_flags_cc = g_compile_flags_cc & 0xefffffff;
      decl_check_conversion_return_type(pcVar14->declarator->decl,&pcVar40->spec);
      decl_finish_declarator(pcVar14->declarator->decl);
      pcVar39 = pcVar40;
      ppvVar43 = (void **)&pcVar14->node->unk0c;
      for (iVar22 = 6; iVar22 != 0; iVar22 = iVar22 + -1) {
        *ppvVar43 = (void *)pcVar39->words[0];
        pcVar39 = (c1_yy_value *)(pcVar39->words + 1);
        ppvVar43 = ppvVar43 + 1;
      }
      tmpl_explicit_instantiation(pcVar14->declarator,pcVar14[-3].spec.spec[0],&pcVar40->spec);
      bVar11 = g_current_scope->current->kind;
      if ((0xfa < bVar11) && (bVar11 != 0xfd)) {
        scope_pop_to_kind(g_current_scope,'\x01');
      }
      g_declarator_paren_base = g_declarator_paren_base + -1;
      lVar45 = g_enum_value;
      break;
    case 0x54:
      g_compile_flags_cc = g_compile_flags_cc & 0xefffffff;
      cStack_124.spec[0] = cStack_124.spec[0] & 0xf8;
      cVar10 = pcVar14[-2].spec.spec[0];
      pcVar54 = &cStack_124;
      for (iVar22 = 6; iVar22 != 0; iVar22 = iVar22 + -1) {
        pcVar54->spec[0] = '\0';
        pcVar54->spec[1] = '\0';
        pcVar54->spec[2] = '\0';
        pcVar54->spec[3] = '\0';
        pcVar54 = (c1xx_decl_specifiers *)(pcVar54->spec + 4);
      }
      pcVar33 = pcVar14->declarator;
      cStack_124.type_sym = (c1_symbol *)0x0;
      cStack_124.spec[0] = cStack_124.spec[0] & 7 ^ cStack_124.spec[0] | 0x30;
      cStack_124.type = g_type_none;
      decl_check_conversion_return_type(pcVar33->decl,&cStack_124);
      decl_finish_declarator(pcVar33->decl);
      tmpl_explicit_instantiation(pcVar33,cVar10,&cStack_124);
      bVar11 = g_current_scope->current->kind;
LAB_10465c69:
      if ((0xfa < bVar11) && (bVar11 != 0xfd)) {
        scope_pop_to_kind(g_current_scope,'\x01');
        g_declarator_paren_base = g_declarator_paren_base + -1;
        lVar45 = g_enum_value;
        break;
      }
      goto LAB_104232fa;
    case 0x55:
      g_compile_flags_cc = g_compile_flags_cc & 0xefffffff;
      parse_yyerrok(parser);
      tmpl_finish_class_template_declaration((c1_yy_value *)0x0,(c1xx_decl_specifiers *)0x0);
      lVar45 = g_enum_value;
      break;
    case 0x56:
      tmpl_check_nested_definition();
      lVar45 = g_enum_value;
      break;
    case 0x57:
      decl_pop_declarator_state(pcVar14->params);
      pvVar23 = tmpl_header_end(pcVar14->header->parameter_scope);
      value_base[1].ptr = pvVar23;
      pcVar19 = tmpl_header_take_parameter_list();
      *(c1_arg_list **)((int)value_base + 0x2c) = pcVar19;
      lVar45 = g_enum_value;
      break;
    case 0x5d:
      g_declarator_paren_base = g_declarator_paren_base + -1;
      decl_check_conversion_return_type(pcVar40->declarator->decl,&pcVar14->spec);
      decl_finish_declarator(pcVar40->declarator->decl);
      pcVar39 = pcVar14;
      ppvVar43 = (void **)&pcVar40->node->unk0c;
      for (iVar22 = 6; iVar22 != 0; iVar22 = iVar22 + -1) {
        *ppvVar43 = (void *)pcVar39->words[0];
        pcVar39 = (c1_yy_value *)(pcVar39->words + 1);
        ppvVar43 = ppvVar43 + 1;
      }
      if (g_class_depth < 0) {
        if ((g_compile_flags_c8 & 0x40) == 0) {
          pcVar31 = decl_declare_from_declarator(pcVar40->declarator,(byte *)pcVar14->words);
        }
        else {
          pcVar31 = pcVar40->declarator->sym;
        }
        bVar11 = g_current_scope->current->kind;
        if ((0xfa < bVar11) && (bVar11 != 0xfd)) {
          scope_pop_to_kind(g_current_scope,'\x01');
        }
        class_check_unnamed_class_member(&pcVar14->spec);
        value_base[1].sym = pcVar31;
        lVar45 = g_enum_value;
      }
      else {
        pcVar40->declarator->kind = 2;
        cVar9 = class_begin_member_list(pcVar40->declarator,&pcVar14->spec,(c1_symbol **)0x0);
        if (((cVar9 == '\0') && (bVar11 = g_current_scope->current->kind, 0xfa < bVar11)) &&
           (bVar11 != 0xfd)) {
          scope_pop_to_kind(g_current_scope,'\x01');
        }
        value_base[1].words[0] = (c1_u32)pcVar40->declarator->sym;
        lVar45 = g_enum_value;
      }
      break;
    case 0x5e:
      g_compile_flags_c4 = g_compile_flags_c4 | 0x1000000;
      g_compile_flags_c8 = g_compile_flags_c8 & 0xfffffffd;
      g_declarator_paren_base = g_declarator_paren_base + -1;
      if ((g_paren_level_flags[g_paren_depth] & 1) == 0) {
        pcVar54 = decl_specifiers_default((void *)0x0);
        lVar45 = g_enum_value;
      }
      else {
        pcVar54 = g_paren_level_declspecs + g_paren_depth;
      }
      g_enum_value = lVar45;
      decl_check_conversion_return_type(pcVar40->declarator->decl,pcVar54);
      decl_finish_declarator(pcVar40->declarator->decl);
      if ((g_paren_level_flags[g_paren_depth] & 1) == 0) {
        pcVar54 = decl_specifiers_default((void *)0x0);
      }
      else {
        pcVar54 = g_paren_level_declspecs + g_paren_depth;
      }
      ppvVar43 = (void **)&pcVar40->node->unk0c;
      for (iVar22 = 6; iVar22 != 0; iVar22 = iVar22 + -1) {
        *ppvVar43 = *(void **)pcVar54->spec;
        pcVar54 = (c1xx_decl_specifiers *)(pcVar54->spec + 4);
        ppvVar43 = ppvVar43 + 1;
      }
      if (-1 < g_class_depth) {
        pcVar40->declarator->kind = 2;
        if ((g_paren_level_flags[g_paren_depth] & 1) == 0) {
          pcVar54 = decl_specifiers_default((void *)0x0);
        }
        else {
          pcVar54 = g_paren_level_declspecs + g_paren_depth;
        }
        cVar9 = class_begin_member_list(pcVar40->declarator,pcVar54,(c1_symbol **)0x0);
        if (((cVar9 == '\0') && (bVar11 = g_current_scope->current->kind, 0xfa < bVar11)) &&
           (bVar11 != 0xfd)) {
          scope_pop_to_kind(g_current_scope,'\x01');
        }
        value_base[1].words[0] = (c1_u32)pcVar40->declarator->sym;
        lVar45 = g_enum_value;
        break;
      }
      if ((g_compile_flags_c8 & 0x40) == 0) {
        if ((g_paren_level_flags[g_paren_depth] & 1) == 0) {
          pcVar54 = decl_specifiers_default((void *)0x0);
          pcVar33 = (c1_declarator *)decl_declare_from_declarator(pcVar40->declarator,pcVar54->spec)
          ;
        }
        else {
          pcVar33 = (c1_declarator *)
                    decl_declare_from_declarator
                              (pcVar40->declarator,g_paren_level_declspecs[g_paren_depth].spec);
        }
      }
      else {
        pcVar33 = (c1_declarator *)pcVar40->declarator->sym;
      }
      bVar11 = g_current_scope->current->kind;
      if (0xfa < bVar11) {
        iVar12 = yyparse_cpp_template_member_declaration_tail
                           (g_current_scope,bVar11,(c1_symbol *)pcVar33,value_base,parser,state_sp,
                            saved_lookahead,iVar12);
        return iVar12;
      }
      goto LAB_10421939;
    case 0x5f:
    case 0x60:
    case 0x6a:
      goto switchD_10421905_caseD_5c;
    case 0x61:
    case 0x62:
      pcVar13 = arena_alloc(g_arenas + 5,0x1c);
      if (pcVar13 == (c1_scope_body *)0x0) {
LAB_10465f34:
        value_base[1].words[0] = 0;
        lVar45 = g_enum_value;
      }
      else {
        cVar4 = g_current_scope->current->body;
        pcVar13[4] = (c1_scope_body)0x3;
        *(c1_u8 *)(pcVar13 + 5) = '\x01';
        *pcVar13 = cVar4;
        value_base[1].params = (c1_param_clause *)pcVar13;
        lVar45 = g_enum_value;
      }
      break;
    case 100:
      if ((g_token_source->stream->flags & 1) != 0) {
        pcVar25 = include_line_map_find((c1_line_map_state *)&g_lex_position,g_token_position);
        (*g_idb->vtbl->idb_scope_kind4_end)
                  (g_idb,CONCAT22(uVar41,(short)pcVar25->line - (short)pcVar25->position) +
                         g_token_position,0);
      }
      if ((g_compile_flags_c8 & 0x10000000) == 0) {
        diag_error(0x3e);
      }
      pcVar18 = arena_alloc(g_arenas,0x14);
      if (pcVar18 == (c1_arg_item *)0x0) {
        pcVar18 = (c1_arg_item *)0x0;
      }
      else {
        cVar6 = (c1_arg_value)pcVar40->node->right;
        tmpl_list_item_construct(pcVar18,0,0);
        pcVar18->value = cVar6;
        pcVar18->vtbl = &PTR_pch_fixup_list_object_104c4c3c;
      }
      pcVar19 = g_paren_level_arg_lists[g_paren_depth];
      if (pcVar19 == (c1_arg_list *)0x0) {
        pcVar19 = arena_alloc(g_arenas,0xc);
        if (pcVar19 == (c1_arg_list *)0x0) {
          g_paren_level_arg_lists[g_paren_depth] = (c1_arg_list *)0x0;
        }
        else {
          pcVar19->first = pcVar18;
          pcVar19->last = pcVar18;
          pcVar19->flags = (pcVar18->kind >> 3 & 1 ^ pcVar19->flags) & 1 ^ pcVar19->flags;
          g_paren_level_arg_lists[g_paren_depth] = pcVar19;
        }
      }
      else {
        pcVar18->next = pcVar19->first;
        pcVar19->first->prev = pcVar18;
        pcVar19->first = pcVar18;
        if ((pcVar18->kind & 8) != 0) {
          pcVar19->flags = pcVar19->flags | 1;
        }
      }
      expr_count_evaluated_operator();
      uVar56 = g_compile_flags_c8 & 0xfeffffff;
      uVar36 = g_compile_flags_cc & 0xffffffef;
      lVar45 = g_enum_value;
      if (((g_compile_flags_c8 & 0x32000000) != 0) ||
         (((((g_compile_flags_c8 & 0x40000000) != 0 && ((g_compile_flags_cc & 8) == 0)) &&
           ((g_compile_flags_c4 & 0x200) == 0)) ||
          ((uVar8 = g_compile_flags_c8 & 0x4000000, g_compile_flags_c8 = uVar56,
           g_compile_flags_cc = uVar36, uVar8 != 0 && ((g_compile_flags_c4 & 0x8000) == 0))))))
      goto LAB_1046625d;
LAB_1046607d:
      g_context_arena_index = 5;
      g_expr_arena_index = 5;
      if ((g_compile_flags_cc & 1) != 0) {
        g_context_arena_index = 4;
        g_expr_arena_index = 4;
      }
      goto switchD_10421905_caseD_5c;
    case 0x65:
      if ((g_token_source->stream->flags & 1) != 0) {
        pcVar25 = include_line_map_find((c1_line_map_state *)&g_lex_position,g_token_position);
        (*g_idb->vtbl->idb_scope_kind4_end)
                  (g_idb,CONCAT22(uVar41,(short)pcVar25->line - (short)pcVar25->position) +
                         g_token_position,0);
      }
      a = g_arenas + g_expr_arena_index;
      pcVar24 = (c1_node *)a->cur;
      pcVar7 = (c1_node *)g_arenas[g_expr_arena_index].end;
      a->cur = &pcVar24[1].op;
      if (pcVar7 < pcVar24 + 1) {
        arena_grow(a);
      }
      pcVar24->kind = '\0';
      pcVar24->op = 0xc6;
      pcVar24->left = (void *)pcVar40->words[0];
      cStack_134.base = (c1_type *)0x0;
      cStack_134.debug_index = 0;
      cStack_134.code = 0x80e;
      cStack_134.flags = 0;
      cStack_134.extra.cls = (c1_symbol *)0x0;
      pcVar32 = type_intern(&cStack_134);
      pcVar24->type = pcVar32;
      pcVar24 = tree_append_list_item((c1_node *)0x0,pcVar24,2);
      pcVar18 = arena_alloc(g_arenas,0x14);
      if (pcVar18 == (c1_arg_item *)0x0) {
        pcVar18 = (c1_arg_item *)0x0;
      }
      else {
        tmpl_list_item_construct(pcVar18,1,0);
        pcVar18->vtbl = &PTR_pch_fixup_tree_list_object_104bcbcc;
        (pcVar18->value).expr = pcVar24;
      }
      pcVar19 = g_paren_level_arg_lists[g_paren_depth];
      if (pcVar19 == (c1_arg_list *)0x0) {
        pcVar19 = arena_alloc(g_arenas,0xc);
        if (pcVar19 == (c1_arg_list *)0x0) {
          g_paren_level_arg_lists[g_paren_depth] = (c1_arg_list *)0x0;
        }
        else {
          pcVar19->first = pcVar18;
          pcVar19->last = pcVar18;
          pcVar19->flags = (pcVar18->kind >> 3 & 1 ^ pcVar19->flags) & 1 ^ pcVar19->flags;
          g_paren_level_arg_lists[g_paren_depth] = pcVar19;
        }
      }
      else {
        pcVar18->next = pcVar19->first;
        pcVar19->first->prev = pcVar18;
        pcVar19->first = pcVar18;
        if ((pcVar18->kind & 8) != 0) {
          pcVar19->flags = pcVar19->flags | 1;
        }
      }
      expr_count_evaluated_operator();
      uVar56 = g_compile_flags_c8 & 0xfeffffff;
      uVar36 = g_compile_flags_cc & 0xffffffef;
      lVar45 = g_enum_value;
      if ((((g_compile_flags_c8 & 0x32000000) == 0) &&
          ((((g_compile_flags_c8 & 0x40000000) == 0 || ((g_compile_flags_cc & 8) != 0)) ||
           ((g_compile_flags_c4 & 0x200) != 0)))) &&
         ((uVar8 = g_compile_flags_c8 & 0x4000000, g_compile_flags_c8 = uVar56,
          g_compile_flags_cc = uVar36, uVar8 == 0 || ((g_compile_flags_c4 & 0x8000) != 0))))
      goto LAB_1046607d;
LAB_1046625d:
      g_compile_flags_cc = uVar36;
      g_compile_flags_c8 = uVar56;
      g_context_arena_index = 0;
      g_expr_arena_index = 0;
      goto switchD_10421905_caseD_5c;
    case 0x68:
      g_compile_flags_c8 = g_compile_flags_c8 | 0x8000000;
      parse_default_argument_begin((c1_type *)0x0);
      func_flow_state_note_3e();
      lVar45 = g_enum_value;
      break;
    case 0x69:
      stream = token_reader_current_stream((c1_token_reader *)&g_token_position);
      cVar9 = token_stream_is_source_text(stream);
      lVar45 = g_enum_value;
      if (cVar9 != '\0') {
        pcVar38 = g_idb->vtbl;
LAB_10422231:
        iVar22 = 0;
        uVar56 = lex_line_number_of_position(&g_token_position);
        (*pcVar38->idb_scope_kind3_to_4)(g_idb,uVar56,iVar22);
        lVar45 = g_enum_value;
      }
      break;
    case 0x6b:
    case 0x6d:
      pcVar28 = arena_alloc_n_aligned(0xc,0);
      if (pcVar28 == (c1_u8 *)0x0) goto LAB_10465f34;
      pvVar23 = tmpl_argument_list_init(pcVar28,pcVar40->ptr);
      value_base[1].ptr = pvVar23;
      lVar45 = g_enum_value;
      break;
    case 0x6c:
      list_append_tail(pcVar14[-1].args,pcVar40->arg);
      lVar45 = g_enum_value;
      break;
    case 0x6e:
      pcVar18 = tmpl_argument_from_expression(pcVar40->node);
      value_base[1].arg = pcVar18;
      lVar45 = g_enum_value;
      break;
    case 0x6f:
      pcVar42 = acStackY_1a8;
      for (iVar22 = 9; iVar22 != 0; iVar22 = iVar22 + -1) {
        *pcVar42 = pcVar14->words[0];
        pcVar42 = pcVar42 + 1;
        pcVar14 = (c1_yy_value *)(pcVar14->words + 1);
      }
      pcVar18 = decl_finish_declarator_record(pcVar40->declarator);
      value_base[1].arg = pcVar18;
      lVar45 = g_enum_value;
      break;
    case 0x71:
      g_compile_flags_c8 = g_compile_flags_c8 & 0xffffffdf;
      break;
    case 0x72:
    case 0x15d:
    case 0x15e:
      goto switchD_10421905_caseD_6f;
    case 0x73:
      pcVar24 = pcVar40->node;
      pcVar14 = pcVar14 + -1;
      pcVar54 = &local_60;
      for (iVar22 = 9; iVar22 != 0; iVar22 = iVar22 + -1) {
        *(c1_u32 *)pcVar54->spec = pcVar14->words[0];
        pcVar14 = (c1_yy_value *)(pcVar14->words + 1);
        pcVar54 = (c1xx_decl_specifiers *)(pcVar54->spec + 4);
      }
      iVar22 = decl_parse_linkage_specification(&local_60,pcVar24);
      decl_push_linkage_specification(iVar22);
      if (g_yy_lookahead == (byte *)0x0) {
        iVar22 = parse_error_recovery_count();
        if (iVar22 == 0) {
          arena_reset(5);
        }
      }
      g_string_literal_cur = &g_string_literal_buffer;
      g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfc;
      lVar45 = g_enum_value;
      if (g_yy_lookahead != (byte *)0x0) {
        cVar10 = lex_token_code((c1xx_token *)g_yy_lookahead);
        lVar45 = g_enum_value;
        if (cVar10 != 'u') {
          g_compile_flags_c8 = g_compile_flags_c8 | 0x20;
        }
      }
      break;
    case 0x76:
      ns_end_definition(pcVar14[-1].words[0]);
      lVar45 = g_enum_value;
      break;
    case 0x77:
      pbVar16 = ns_define_namespace((void *)0x0);
      value_base[1].str.text = pbVar16;
      lVar45 = g_enum_value;
      break;
    case 0x78:
      pbVar16 = ns_define_namespace(pcVar14->ptr);
      value_base[1].str.text = pbVar16;
      lVar45 = g_enum_value;
      break;
    case 0x79:
      scope_pop_to_kind_if_needed(g_current_scope,'\0');
      pvVar23 = qualname_resolved_symbol(pcVar14->declarator);
      cVar10 = '\0';
      uVar49 = 0;
      uVar51 = 0;
      uVar41 = 0;
      if (pvVar23 == (void *)0x0) {
        pcVar31 = value_word0(pcVar14->cell);
        ns_using_directive((c1_symbol *)0x0,(fe_name *)pcVar31,
                           CONCAT22(uVar41,CONCAT11(uVar51,uVar49)),cVar10);
        lVar45 = g_enum_value;
      }
      else {
        uVar48 = 0;
        uVar50 = 0;
        uVar52 = 0;
        pcVar31 = qualname_resolved_symbol(pcVar14->declarator);
        ns_using_directive(pcVar31,(fe_name *)CONCAT22(uVar52,CONCAT11(uVar50,uVar48)),
                           CONCAT22(uVar41,CONCAT11(uVar51,uVar49)),cVar10);
        lVar45 = g_enum_value;
      }
      break;
    case 0x7a:
      scope_pop_to_kind_if_needed(g_current_scope,'\0');
      pvVar23 = qualname_resolved_symbol(pcVar14->declarator);
      pcVar33 = (c1_declarator *)pcVar14->cell;
      if (pvVar23 == (void *)0x0) {
LAB_104668f9:
        value_word0((c1_symbol **)pcVar33);
        diag_error(0x369);
        lVar45 = g_enum_value;
      }
      else {
        pcVar31 = qualname_resolved_symbol(pcVar33);
        ns_using_declaration(pcVar31);
        lVar45 = g_enum_value;
      }
      break;
    case 0x7b:
      ns_using_declaration((pcVar14->spec).type_sym);
      lVar45 = g_enum_value;
      break;
    case 0x7c:
      scope_pop_to_kind_if_needed(g_current_scope,'\0');
      ns_define_alias(pcVar14->declarator,pcVar14[-2].name);
      lVar45 = g_enum_value;
      break;
    case 0x7d:
      diag_error(0x122);
      parse_paren_depth_pop();
      lVar45 = g_enum_value;
      break;
    case 0x7e:
      if (g_yy_lookahead != (byte *)0x0) {
        cVar10 = lex_token_code((c1xx_token *)g_yy_lookahead);
        if (cVar10 == 'v') {
          iVar35 = 9;
          iVar22 = g_paren_depth;
          pcVar14 = pcVar40;
          pcVar42 = (c1_u32 *)(&g_paren_level_declspecs_prev_base + g_paren_depth * 0x24);
          lVar45 = g_enum_value;
          goto LAB_10420c2b;
        }
      }
      iVar22 = g_paren_depth;
      pcVar54 = g_paren_level_declspecs + g_paren_depth;
      for (iVar35 = 9; iVar35 != 0; iVar35 = iVar35 + -1) {
        *(c1_u32 *)pcVar54->spec = pcVar40->words[0];
        pcVar40 = (c1_yy_value *)(pcVar40->words + 1);
        pcVar54 = (c1xx_decl_specifiers *)(pcVar54->spec + 4);
      }
      g_paren_level_flags[iVar22] = g_paren_level_flags[iVar22] | 1;
      lVar45 = g_enum_value;
      break;
    case 0x7f:
      if ((*(code **)((int)pcVar14 + 0x48) != (code *)0x0) && (*(int *)((int)pcVar14 + 0x44) != 0))
      {
        (**(code **)((int)pcVar14 + 0x48))();
        lVar45 = g_enum_value;
      }
      break;
    case 0x80:
      bVar44 = g_yy_lookahead != (byte *)0x0;
      puVar27 = &g_yylval;
      for (iVar22 = 9; iVar22 != 0; iVar22 = iVar22 + -1) {
        *puVar27 = pcVar40->words[0];
        pcVar40 = (c1_yy_value *)(pcVar40->words + 1);
        puVar27 = puVar27 + 1;
      }
      if (bVar44) {
        cVar10 = lex_token_code(pcVar26);
        pcVar26 = (c1xx_token *)g_yy_lookahead;
        lVar45 = g_enum_value;
        if (cVar10 == '\x7f') break;
      }
      g_yy_lookahead = (byte *)lex_unget_token(pcVar26);
      g_compile_flags_c4 = g_compile_flags_c4 | 0x80000000;
      pcVar31 = value_word0((c1_symbol **)&g_token_arena_index);
      pcVar28 = arena_or_pool_alloc(0x30,(int)pcVar31);
      if (pcVar28 == (c1_u8 *)0x0) {
        token = (char *)0x0;
      }
      else {
        token = token_init(pcVar28,'\"',&g_yylval);
      }
      pcVar26 = (c1xx_token *)lex_lookahead_decl_specifiers(token);
      g_compile_flags_c4 = g_compile_flags_c4 & 0x7fffffff;
      pcVar14 = token_value_address(pcVar26);
      pcVar40 = value_base + 1;
      lVar45 = g_enum_value;
      for (iVar22 = 9; iVar22 != 0; iVar22 = iVar22 + -1) {
        g_enum_value = lVar45;
        pcVar40->words[0] = pcVar14->words[0];
        pcVar14 = (c1_yy_value *)(pcVar14->words + 1);
        pcVar40 = (c1_yy_value *)(pcVar40->words + 1);
        lVar45 = g_enum_value;
      }
      break;
    case 0x85:
      iVar22 = browse_end_global_block();
      *(int *)((int)value_base + 0x40) = iVar22;
      lVar45 = g_enum_value;
      break;
    case 0x86:
      pcVar32 = class_end_definition();
      *(c1_type **)((int)value_base + 0x40) = pcVar32;
      class_begin_deferred_member_bodies();
      lVar45 = g_enum_value;
      if (g_yy_lookahead == (byte *)0x0) {
        g_yy_lookahead = token_next((c1_token_reader *)&g_token_position);
        lVar45 = g_enum_value;
      }
      break;
    case 0x87:
      class_reset_member_function_class();
      lVar45 = g_enum_value;
      break;
    case 0x88:
      if ((code *)pcVar14->words[8] != (code *)0x0) {
        (*(code *)pcVar14->words[8])();
      }
      class_begin_definition((pcVar14->spec).type_sym,(pcVar14->spec).type);
      class_end_member_list();
      lVar45 = g_enum_value;
      break;
    case 0x8a:
      if (*(code **)((int)pcVar14 + 0x48) != (code *)0x0) {
        (**(code **)((int)pcVar14 + 0x48))();
      }
      class_begin_definition
                (*(c1_symbol **)((int)pcVar14 + 0x44),*(c1_type **)((int)pcVar14 + 0x40));
      g_compile_flags_c4 = g_compile_flags_c4 | 3;
      lVar45 = g_enum_value;
      break;
    case 0x8b:
      if (g_yy_lookahead == (byte *)0x0) {
        g_yy_lookahead = token_next((c1_token_reader *)&g_token_position);
      }
      cVar10 = lex_token_code((c1xx_token *)g_yy_lookahead);
      if (cVar10 != 'u') {
        lex_token_code((c1xx_token *)g_yy_lookahead);
        diag_error(0x265);
        pcVar26 = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
        g_yy_lookahead = &parse_skip_tokens_to_one_of(pcVar26)->code;
        cVar10 = lex_token_code((c1xx_token *)g_yy_lookahead);
        if (cVar10 == '\x7f') {
          lex_unget_token((c1xx_token *)g_yy_lookahead);
          pcVar26 = token_static_for_code(0x7b);
          token_source_unget((c1_token_reader *)&g_token_position,pcVar26);
          g_yy_lookahead = &token_static_for_code(0x75)->code;
        }
      }
      g_compile_flags_c4 = g_compile_flags_c4 & 0xfffffffc;
      class_end_member_list();
      lVar45 = g_enum_value;
      break;
    case 0x8d:
    case 0x8e:
    case 0x1a5:
      g_compile_flags_c4 = g_compile_flags_c4 & 0xfffffffe;
      break;
    case 0x8f:
      if ((code *)pcVar14->words[8] != (code *)0x0) {
        (*(code *)pcVar14->words[8])();
      }
      pcVar31 = (c1_symbol *)sym_name((c1_symbol *)(pcVar14->spec).type);
      lVar45 = g_enum_value;
      if (g_pragma_mintypeinfo != '\0') {
        sym_detail_set_flag3f_bit3(pcVar31);
        lVar45 = g_enum_value;
      }
      if ((g_browse_file != (char *)0x0) && ((g_block_depth == '\0' || (g_opt_FR_browse != 0)))) {
        g_enum_value = lVar45;
        cVar10 = sym_flags3_bit0(pcVar31);
        lVar45 = g_enum_value;
        if (cVar10 == '\0') {
          (*g_il_emitter->vtbl->begin_block)();
          pcVar5 = g_il_emitter->vtbl;
          iVar22 = sym_name(pcVar31);
          iVar22 = (*pcVar5->mark_definition)(0,iVar22);
          if (iVar22 == 0) {
            (*g_il_emitter->vtbl->define_symbol)(g_il_emitter,pcVar31);
          }
          (*g_il_emitter->vtbl->set_owner)((int)pcVar31);
          lVar45 = g_enum_value;
        }
      }
      break;
    case 0x96:
      if (g_yy_lookahead == (byte *)0x0) {
        g_yy_lookahead = token_next((c1_token_reader *)&g_token_position);
      }
      cVar10 = lex_token_code((c1xx_token *)g_yy_lookahead);
      lVar45 = g_enum_value;
      if (cVar10 != '7') {
        cVar10 = lex_token_code((c1xx_token *)g_yy_lookahead);
        lVar45 = g_enum_value;
        if (cVar10 != 'u') {
          parse_report_inserted_token(g_yy_lookahead,0x37);
          lex_unget_token((c1xx_token *)g_yy_lookahead);
          g_yy_lookahead = &token_static_for_code(0x37)->code;
          lVar45 = g_enum_value;
        }
      }
      break;
    case 0x97:
    case 0x9e:
      class_check_base_defined
                ((pcVar14->spec).spec[0] & 3,(pcVar14->spec).spec[0] >> 2 & 0xffffff01,pcVar40->name
                 ,0);
      g_compile_flags_c4 = g_compile_flags_c4 | 1;
      lVar45 = g_enum_value;
      break;
    case 0x98:
      bVar11 = (pcVar14->spec).spec[0];
      pcVar31 = (c1_symbol *)sym_name(pcVar40->sym);
      class_check_base_class(bVar11 & 3,bVar11 >> 2 & 1,pcVar31);
      goto LAB_10420ed7;
    case 0x99:
      pcVar31 = value_word0(pcVar40->cell);
      access_check_member(pcVar31);
      bVar11 = (pcVar14->spec).spec[0];
      iVar22 = 0;
      pcVar31 = value_word0(pcVar40->cell);
      uVar48 = SUB41(pcVar31,0);
      uVar50 = (undefined1)((uint)pcVar31 >> 8);
      uVar52 = (undefined2)((uint)pcVar31 >> 0x10);
      uVar56 = CONCAT31((int3)((uint)extraout_ECX >> 8),bVar11 >> 2) & 0xffffff01;
      uVar49 = (undefined1)uVar56;
      uVar51 = (undefined1)(uVar56 >> 8);
      uVar41 = (undefined2)(uVar56 >> 0x10);
      goto LAB_10466526;
    case 0x9a:
    case 0xa1:
      parse_yyerrok(parser);
      uVar56 = 0x75;
      goto LAB_1046653f;
    case 0x9d:
      if (g_yy_lookahead == (byte *)0x0) {
        g_yy_lookahead = token_next((c1_token_reader *)&g_token_position);
      }
      cVar10 = lex_token_code((c1xx_token *)g_yy_lookahead);
      lVar45 = g_enum_value;
      if (cVar10 != '7') {
        cVar10 = lex_token_code((c1xx_token *)g_yy_lookahead);
        lVar45 = g_enum_value;
        if (cVar10 != 'u') {
          cVar10 = lex_token_code((c1xx_token *)g_yy_lookahead);
          lVar45 = g_enum_value;
          if (cVar10 != '6') {
            parse_report_inserted_token(g_yy_lookahead,0x37);
            lex_unget_token((c1xx_token *)g_yy_lookahead);
            g_yy_lookahead = &token_static_for_code(0x37)->code;
            lVar45 = g_enum_value;
          }
        }
      }
      break;
    case 0x9f:
      pcVar31 = value_word0(pcVar40->cell);
      access_check_member(pcVar31);
      bVar11 = (pcVar14->spec).spec[0];
      iVar22 = 1;
      pcVar31 = value_word0(pcVar40->cell);
      uVar48 = SUB41(pcVar31,0);
      uVar50 = (undefined1)((uint)pcVar31 >> 8);
      uVar52 = (undefined2)((uint)pcVar31 >> 0x10);
      uVar56 = CONCAT31((int3)((uint)pcVar31 >> 8),bVar11 >> 2) & 0xffffff01;
      uVar49 = (undefined1)uVar56;
      uVar51 = (undefined1)(uVar56 >> 8);
      uVar41 = (undefined2)(uVar56 >> 0x10);
LAB_10466526:
      class_check_base_of_symbol
                (bVar11 & 3,CONCAT22(uVar41,CONCAT11(uVar51,uVar49)),
                 (c1_symbol *)CONCAT22(uVar52,CONCAT11(uVar50,uVar48)),iVar22);
LAB_10420ed7:
      g_compile_flags_c4 = g_compile_flags_c4 | 1;
      lVar45 = g_enum_value;
      break;
    case 0xa0:
      diag_error(0x348);
      lVar45 = g_enum_value;
      break;
    case 0xa2:
      value_base[1].spec.spec[0] = value_base[1].spec.spec[0] & 0xe0;
      lVar45 = g_enum_value;
      break;
    case 0xa3:
      bVar11 = value_base[1].spec.spec[0];
      if ((bVar11 & 3) == 0) {
        value_base[1].spec.spec[0] =
             ((byte)g_tree_op_to_il_op[(pcVar40->spec).spec[0]] ^ bVar11) & 3 ^ bVar11;
        lVar45 = g_enum_value;
      }
      else if ((bVar11 & 8) == 0) {
        diag_error(0x1f6);
        value_base[1].spec.spec[0] = value_base[1].spec.spec[0] | 8;
        lVar45 = g_enum_value;
      }
      break;
    case 0xa4:
      bVar11 = value_base[1].spec.spec[0];
      if ((bVar11 & 4) == 0) {
        value_base[1].spec.spec[0] = bVar11 | 4;
        lVar45 = g_enum_value;
      }
      else if ((bVar11 & 0x10) == 0) {
        diag_error(0x1fb);
        value_base[1].spec.spec[0] = value_base[1].spec.spec[0] | 0x10;
        lVar45 = g_enum_value;
      }
      break;
    case 0xa7:
    case 0xa8:
      diag_error(0x2f8);
      lVar45 = g_enum_value;
      break;
    case 0xa9:
      lVar45 = enum_warn_value_wrapped(lVar45,pcVar40->ptr);
      acStackY_1a8[1] = 0x10420f95;
      g_enum_value = lVar45;
      enum_declare(pcVar40->name,g_current_enum_type,(c1_u32)lVar45,(int)((ulonglong)lVar45 >> 0x20)
                  );
      g_compile_flags_c4 = g_compile_flags_c4 | 1;
      lVar45 = g_enum_value;
      break;
    case 0xaa:
      if ((g_compile_flags_cc & 0x100000) != 0) {
        pcVar26 = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
        pcVar26 = parse_skip_tokens_to_one_of(pcVar26);
        token_source_unget((c1_token_reader *)&g_token_position,pcVar26);
        g_yylval = (uint)g_type_int;
        _g_yylval_word2 = 1;
        _g_yylval_word3 = 0;
        pcVar31 = value_word0((c1_symbol **)&g_token_arena_index);
        pcVar28 = arena_or_pool_alloc(0x30,(int)pcVar31);
        if (pcVar28 == (c1_u8 *)0x0) goto LAB_10466f79;
        g_yy_lookahead = token_init(pcVar28,'e',&g_yylval);
        lVar45 = g_enum_value;
      }
      break;
    case 0xab:
      enum_declare(pcVar14[-2].name,g_current_enum_type,pcVar40->words[0],
                   *(int *)((int)pcVar14 + 0x2c));
      if (((g_prototype_scope_depth == 0) && ((g_compile_flags_c4 & 0x8000000) == 0)) &&
         ((g_paren_depth == 0 &&
          (((g_compile_flags_c8 & 0x40000000) == 0 && ((g_compile_flags_cc & 8) == 0)))))) {
        arena_reset(5);
      }
      g_compile_flags_c4 = g_compile_flags_c4 | 1;
      lVar45 = g_enum_value;
      break;
    case 0xac:
    case 0xad:
      if ((((g_prototype_scope_depth == 0) && ((g_compile_flags_c4 & 0x8000000) == 0)) &&
          (g_paren_depth == 0)) &&
         (((g_compile_flags_c8 & 0x40000000) == 0 && ((g_compile_flags_cc & 8) == 0)))) {
        arena_reset(5);
        lVar45 = g_enum_value;
      }
      g_string_literal_cur = &g_string_literal_buffer;
    case 0x16c:
      g_compile_flags_c4 = g_compile_flags_c4 & 0xfffffffe;
      g_enum_value = lVar45;
      g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfc;
      lVar45 = g_enum_value;
      break;
    case 0xaf:
      pcVar54 = &local_a8;
      for (iVar22 = 9; iVar22 != 0; iVar22 = iVar22 + -1) {
        *(c1_u32 *)pcVar54->spec = pcVar14->words[0];
        pcVar54 = (c1xx_decl_specifiers *)(pcVar54->spec + 4);
        pcVar14 = (c1_yy_value *)(pcVar14->words + 1);
      }
      pcVar33 = decl_declarator_alloc();
      if (pcVar33 == (c1_declarator *)0x0) {
        pcVar33 = (c1_declarator *)0x0;
      }
      else {
        pcVar33 = declarator_set_position(pcVar33);
      }
      decl_declarator_set_specifiers(pcVar33,&local_a8);
      class_begin_member_list(pcVar33,&local_a8,(c1_symbol **)0x0);
      lVar45 = g_enum_value;
      break;
    case 0xb1:
      pcVar14 = pcVar14 + -1;
      pcVar54 = &local_3c;
      for (iVar22 = 9; iVar22 != 0; iVar22 = iVar22 + -1) {
        *(c1_u32 *)pcVar54->spec = pcVar14->words[0];
        pcVar14 = (c1_yy_value *)(pcVar14->words + 1);
        pcVar54 = (c1xx_decl_specifiers *)(pcVar54->spec + 4);
      }
      class_check_unnamed_class_member(&local_3c);
      lVar45 = g_enum_value;
      break;
    case 0xb3:
      if ((((c1_symbol_tail *)pcVar14->declarator->unk2c)->fn).op_token == '\x01') {
        cVar9 = value_byte1_bit4((c1_symbol *)pcVar14->declarator);
        lVar45 = g_enum_value;
        if (cVar9 == '\0') {
          cVar9 = value_byte1_bit5(pcVar14->sym);
          lVar45 = g_enum_value;
          if ((cVar9 == '\0') &&
             ((((c1_symbol_tail *)pcVar14->declarator->unk2c)->fn).special_kind == '\0')) {
            sym_name((c1_symbol *)pcVar14->declarator);
            diag_warning(1);
            lVar45 = g_enum_value;
          }
        }
      }
      break;
    case 0xb4:
      class_set_current_access((c1_u8)g_tree_op_to_il_op[(pcVar14->spec).spec[0]]);
      lVar45 = g_enum_value;
      break;
    case 0xb5:
      lex_token_code((c1xx_token *)g_yy_lookahead);
      diag_error(0x140);
      class_set_current_access((c1_u8)g_tree_op_to_il_op[(pcVar40->spec).spec[0]]);
      lVar45 = g_enum_value;
      break;
    case 0xb7:
      diag_error(0x14e);
      lex_skip_to_closing_brace('\x01');
      goto LAB_10466782;
    case 0xb9:
      diag_error(0xee);
LAB_10466782:
      if ((g_compile_flags_c8 & 0x40000000) != 0) {
        pcVar26 = (c1xx_token *)lex_peek_token((uint *)&g_token_position);
        cVar10 = lex_token_code(pcVar26);
        if (cVar10 == 0xf7) {
          iVar22 = token_reader_top_kind((c1_token_reader *)&g_token_position);
joined_r0x1046681a:
          if (iVar22 == 0) {
            diag_fatal_simple(0xc9);
          }
        }
      }
LAB_1046681c:
      parse_yyerrok(parser);
      lVar45 = g_enum_value;
      break;
    case 0xba:
      diag_error(0x14e);
      lex_skip_to_closing_brace('\0');
      if ((g_compile_flags_c8 & 0x40000000) != 0) {
        pcVar26 = (c1xx_token *)lex_peek_token((uint *)&g_token_position);
        cVar10 = lex_token_code(pcVar26);
        if (cVar10 != 0xf7) goto LAB_1046681c;
        iVar22 = token_reader_top_kind((c1_token_reader *)&g_token_position);
        goto joined_r0x1046681a;
      }
      goto LAB_1046681c;
    case 0xbe:
    case 0xcd:
      diag_warning(1,0xe4);
      lVar45 = g_enum_value;
      break;
    case 0xbf:
      g_yy_lookahead = &parse_skip_tokens_to_one_of((c1xx_token *)g_yy_lookahead)->code;
      cVar10 = lex_token_code((c1xx_token *)g_yy_lookahead);
      if (cVar10 != '\x7f') {
        lex_unget_token((c1xx_token *)g_yy_lookahead);
        g_yy_lookahead = &token_static_for_code(0x7f)->code;
      }
      parse_yyerrok(parser);
      lVar45 = g_enum_value;
      break;
    case 0xc0:
      g_yy_lookahead = &parse_skip_tokens_to_one_of((c1xx_token *)g_yy_lookahead)->code;
      cVar10 = lex_token_code((c1xx_token *)g_yy_lookahead);
      lVar45 = g_enum_value;
      if (cVar10 != '\x7f') {
        lex_unget_token((c1xx_token *)g_yy_lookahead);
        g_yy_lookahead = &token_static_for_code(0x7f)->code;
        lVar45 = g_enum_value;
      }
switchD_10421905_caseD_18:
      g_enum_value = lVar45;
      parse_yyerrok(parser);
      lVar45 = g_enum_value;
      break;
    case 0xc1:
      pcVar31 = decl_declarator_symbol(pcVar40->declarator);
      if (pcVar31 == (c1_symbol *)0x0) {
        declarator_set_kind(pcVar40->declarator,2);
        g_declarator_paren_base = g_declarator_paren_base + -1;
        pcVar54 = decl_specifiers_current();
        pcVar34 = decl_declarator_record(pcVar40->declarator);
        decl_check_conversion_return_type(pcVar34,pcVar54);
        pcVar34 = decl_declarator_record(pcVar40->declarator);
        decl_finish_declarator(pcVar34);
        pcVar54 = decl_specifiers_current();
        decl_declarator_set_specifiers(pcVar40->declarator,pcVar54);
        ppcVar53 = (c1_symbol **)0x0;
        pcVar54 = decl_specifiers_current();
        cVar9 = class_begin_member_list(pcVar40->declarator,pcVar54,ppcVar53);
        if (cVar9 == '\0') {
          scope_pop_to_kind_if_needed(g_current_scope,'\x01');
        }
        pcVar31 = decl_declarator_symbol(pcVar40->declarator);
        value_base[1].sym = pcVar31;
        lVar45 = g_enum_value;
      }
      else {
        pcVar31 = decl_declarator_symbol(pcVar40->declarator);
        value_base[1].sym = pcVar31;
        lVar45 = g_enum_value;
      }
      break;
    case 0xc2:
      pcVar24 = expr_resolve_address_of_overload(pcVar40->node);
      bVar11 = expr_is_zero_constant(pcVar24);
      if (bVar11 == 0) {
        diag_error(0x102);
      }
      declarator_set_flags56_bit1(pcVar14->declarator,'\x01');
      declarator_set_kind(pcVar14->declarator,2);
      g_declarator_paren_base = g_declarator_paren_base + -1;
      pcVar54 = decl_specifiers_current();
      pcVar34 = decl_declarator_record(pcVar14->declarator);
      decl_check_conversion_return_type(pcVar34,pcVar54);
      pcVar34 = decl_declarator_record(pcVar14->declarator);
      decl_finish_declarator(pcVar34);
      pcVar54 = decl_specifiers_current();
      decl_declarator_set_specifiers(pcVar14->declarator,pcVar54);
      ppcVar53 = (c1_symbol **)0x0;
      pcVar54 = decl_specifiers_current();
      cVar9 = class_begin_member_list(pcVar14->declarator,pcVar54,ppcVar53);
      if (cVar9 == '\0') {
        scope_pop_to_kind_if_needed(g_current_scope,'\x01');
      }
      pcVar31 = decl_declarator_symbol(pcVar14->declarator);
      value_base[1].sym = pcVar31;
      lVar45 = g_enum_value;
      break;
    case 0xc4:
      declarator_set_kind(pcVar14[-1].declarator,1);
      iVar22 = *(int *)((int)pcVar14 + 0x2c);
      cVar29 = pcVar40->words[0];
      uVar49 = (undefined1)cVar29;
      uVar51 = (undefined1)(cVar29 >> 8);
      uVar41 = (undefined2)(cVar29 >> 0x10);
      pcVar31 = decl_declarator_symbol(pcVar14[-1].declarator);
      cVar10 = type_check_bitfield_width(pcVar31,CONCAT22(uVar41,CONCAT11(uVar51,uVar49)),iVar22);
      decl_set_bitfield_width(pcVar14[-1].declarator,cVar10);
      g_declarator_paren_base = g_declarator_paren_base + -1;
      pcVar54 = decl_specifiers_current();
      pcVar34 = decl_declarator_record(pcVar14[-1].declarator);
      decl_check_conversion_return_type(pcVar34,pcVar54);
      pcVar34 = decl_declarator_record(pcVar14[-1].declarator);
      decl_finish_declarator(pcVar34);
      pcVar54 = decl_specifiers_current();
      decl_declarator_set_specifiers(pcVar14[-1].declarator,pcVar54);
      ppcVar53 = (c1_symbol **)0x0;
      pcVar54 = decl_specifiers_current();
      cVar9 = class_begin_member_list(pcVar14[-1].declarator,pcVar54,ppcVar53);
      if (cVar9 == '\0') {
        scope_pop_to_kind_if_needed(g_current_scope,'\x01');
      }
      pcVar31 = decl_declarator_symbol(pcVar14[-1].declarator);
      value_base[1].sym = pcVar31;
      lVar45 = g_enum_value;
      break;
    case 0xc5:
      pcVar33 = decl_declarator_alloc();
      if (pcVar33 == (c1_declarator *)0x0) {
        pcVar33 = (c1_declarator *)0x0;
      }
      else {
        pcVar33 = decl_declarator_init(pcVar33,g_name_alignment_member,1,(c1_overload_set *)0x0);
      }
      iVar22 = *(int *)((int)pcVar14 + 0x2c);
      cVar29 = pcVar40->words[0];
      uVar49 = (undefined1)cVar29;
      uVar51 = (undefined1)(cVar29 >> 8);
      uVar41 = (undefined2)(cVar29 >> 0x10);
      pcVar31 = decl_declarator_symbol(pcVar33);
      cVar10 = type_check_bitfield_width(pcVar31,CONCAT22(uVar41,CONCAT11(uVar51,uVar49)),iVar22);
      decl_set_bitfield_width(pcVar33,cVar10);
      declarator_set_flags54_bit5(pcVar33,'\x01');
      pcVar54 = decl_specifiers_current();
      pcVar34 = decl_declarator_record(pcVar33);
      decl_check_conversion_return_type(pcVar34,pcVar54);
      pcVar34 = decl_declarator_record(pcVar33);
      decl_finish_declarator(pcVar34);
      pcVar54 = decl_specifiers_current();
      decl_declarator_set_specifiers(pcVar33,pcVar54);
      ppcVar53 = (c1_symbol **)0x0;
      pcVar54 = decl_specifiers_current();
      class_begin_member_list(pcVar33,pcVar54,ppcVar53);
      pcVar31 = decl_declarator_symbol(pcVar33);
      value_base[1].sym = pcVar31;
      lVar45 = g_enum_value;
      break;
    case 0xc6:
      scope_pop_to_kind_if_needed(g_current_scope,'\x01');
      pcVar31 = decl_declarator_symbol(pcVar40->declarator);
      value_base[1].sym = pcVar31;
      pvVar23 = qualname_resolved_symbol(pcVar40->declarator);
      pcVar33 = (c1_declarator *)pcVar40->cell;
      if (pvVar23 == (void *)0x0) goto LAB_104668f9;
      pbVar16 = qualname_resolved_symbol(pcVar33);
      ns_member_using_declaration(pbVar16);
      lVar45 = g_enum_value;
      break;
    case 199:
      ns_member_using_declaration(*(byte **)((int)pcVar14 + 0x44));
      lVar45 = g_enum_value;
      break;
    case 0xca:
      cVar10 = lex_token_code((c1xx_token *)g_yy_lookahead);
      lVar45 = g_enum_value;
      if (cVar10 == '6') {
        pcVar31 = value_word0(pcVar40->cell);
        iVar22 = class_is_innermost_being_defined((int)pcVar31);
        lVar45 = g_enum_value;
        if ((char)iVar22 != '\0') {
          declarator_set_kind(pcVar40->declarator,2);
          g_declarator_paren_base = g_declarator_paren_base + -1;
          pcVar54 = decl_specifiers_current();
          pcVar34 = decl_declarator_record(pcVar40->declarator);
          decl_check_conversion_return_type(pcVar34,pcVar54);
          pcVar34 = decl_declarator_record(pcVar40->declarator);
          decl_finish_declarator(pcVar34);
          pcVar54 = decl_specifiers_current();
          decl_declarator_set_specifiers(pcVar40->declarator,pcVar54);
          g_yy_lookahead = (byte *)lex_unget_token((c1xx_token *)g_yy_lookahead);
          ppcVar53 = (c1_symbol **)0x0;
          pcVar54 = decl_specifiers_current();
          cVar9 = class_begin_member_list(pcVar40->declarator,pcVar54,ppcVar53);
          lVar45 = g_enum_value;
          if (cVar9 == '\0') {
            scope_pop_to_kind_if_needed(g_current_scope,'\x01');
            lVar45 = g_enum_value;
          }
        }
      }
      break;
    case 0xce:
      g_declarator_paren_base = g_declarator_paren_base + -1;
      pcVar54 = decl_specifiers_current();
      pcVar34 = decl_declarator_record(pcVar40->declarator);
      decl_check_conversion_return_type(pcVar34,pcVar54);
      pcVar34 = decl_declarator_record(pcVar40->declarator);
      decl_finish_declarator(pcVar34);
      pcVar54 = decl_specifiers_current();
      decl_declarator_set_specifiers(pcVar40->declarator,pcVar54);
      if (((g_compile_flags_c8 & 0x40) == 0) && ((g_compile_flags_cc & 0x200000) == 0)) {
        pcVar54 = decl_specifiers_current();
        decl_declare_from_declarator(pcVar40->declarator,pcVar54->spec);
      }
      scope_pop_to_kind_if_needed(g_current_scope,'\x01');
      lVar45 = g_enum_value;
      break;
    case 0xcf:
      if (g_opt_Zg == '\0') {
        pcVar31 = decl_declarator_symbol(pcVar14->declarator);
        cVar9 = decl_check_function_style_initializer(pcVar31);
        if (cVar9 == '\0') {
          g_declarator_paren_base = g_declarator_paren_base + -1;
          decl_set_has_initializer(pcVar14->declarator,'\x01');
          pcVar54 = decl_specifiers_current();
          pcVar34 = decl_declarator_record(pcVar14->declarator);
          decl_check_conversion_return_type(pcVar34,pcVar54);
          pcVar34 = decl_declarator_record(pcVar14->declarator);
          decl_finish_declarator(pcVar34);
          pcVar54 = decl_specifiers_current();
          decl_declarator_set_specifiers(pcVar14->declarator,pcVar54);
          pcVar54 = decl_specifiers_current();
          pcVar31 = decl_declare_and_check(pcVar14->declarator,pcVar54->spec);
          decl_record_set_symbol(pcVar14->ptr,pcVar31);
          pcVar31 = decl_declarator_symbol(pcVar14->declarator);
          pcVar31 = (c1_symbol *)decl_begin_initialized_definition(pcVar31);
          decl_record_set_symbol(pcVar14->ptr,pcVar31);
          pcVar31 = decl_declarator_symbol(pcVar14->declarator);
          if (pcVar31 != (c1_symbol *)0x0) {
            pcVar31 = decl_declarator_symbol(pcVar14->declarator);
            init_set_target_symbol(pcVar31);
            pcVar24 = pcVar40->node;
            pcVar31 = decl_declarator_symbol(pcVar14->declarator);
            decl_finish_initialization(pcVar31,pcVar24);
            scope_pop_to_kind_if_needed(g_current_scope,'\x01');
            pcVar33 = pcVar14->declarator;
            goto LAB_10421651;
          }
        }
      }
      goto LAB_10422a54;
    case 0xd1:
      if ((g_opt_Zg != '\0') || (pcVar14[-1].words[0] == 0)) goto LAB_10422a54;
      pcVar24 = pcVar40->node;
      if ((pcVar24 != (c1_node *)0x0) && (pcVar24->op == 0xe8)) {
        pcVar24 = property_build_access('\x01',pcVar24,(c1_node *)0x0);
        pcVar40->node = pcVar24;
      }
      pcVar31 = decl_declarator_symbol(pcVar14[-1].declarator);
      init_set_target_symbol(pcVar31);
      g_compile_flags_c8 = g_compile_flags_c8 | 0x80000;
      g_compile_flags_cc = g_compile_flags_cc | 0x80000;
      pcVar24 = expr_resolve_address_of_overload(pcVar40->node);
      pcVar31 = decl_declarator_symbol(pcVar14[-1].declarator);
      decl_finish_initialization(pcVar31,pcVar24);
      g_compile_flags_cc = g_compile_flags_cc & 0xfff7ffff;
      g_compile_flags_c8 = g_compile_flags_c8 & 0xfff7ffff;
      scope_pop_to_kind_if_needed(g_current_scope,'\x01');
      pcVar33 = pcVar14[-1].declarator;
LAB_10421651:
      pcVar31 = decl_declarator_symbol(pcVar33);
      type_check_destructible_2(pcVar31);
      g_string_literal_cur = &g_string_literal_buffer;
      lVar45 = g_enum_value;
      break;
    case 0xd2:
      if (g_opt_Zg == '\0') {
        cVar9 = '\0';
        pcVar31 = decl_declarator_symbol(pcVar40->declarator);
        init_begin(pcVar31,cVar9);
        g_compile_flags_cc = g_compile_flags_cc | 0x80000;
        g_brace_init_active = 1;
        lVar45 = g_enum_value;
      }
      break;
    case 0xd3:
      pcVar31 = decl_declarator_symbol(pcVar14[-4].declarator);
      init_finish(pcVar31);
      g_compile_flags_cc = g_compile_flags_cc & 0xfff7ffff;
      if (g_opt_Zg == '\0') {
        pcVar31 = decl_declarator_symbol(pcVar14[-4].declarator);
        type_check_destructible_2(pcVar31);
      }
      scope_pop_to_kind_if_needed(g_current_scope,'\x01');
      lVar45 = g_enum_value;
      break;
    case 0xd4:
      pcVar54 = decl_specifiers_current();
      pcVar34 = decl_declarator_record(pcVar14->declarator);
      decl_check_conversion_return_type(pcVar34,pcVar54);
      pcVar34 = decl_declarator_record(pcVar14->declarator);
      decl_finish_declarator(pcVar34);
      pcVar54 = decl_specifiers_current();
      decl_declarator_set_specifiers(pcVar14->declarator,pcVar54);
      g_declarator_paren_base = g_declarator_paren_base + -1;
      lVar45 = g_enum_value;
      if (g_opt_Zg == '\0') {
        decl_set_has_initializer(pcVar14->declarator,'\x01');
        pcVar54 = decl_specifiers_current();
        decl_declarator_set_specifiers(pcVar14->declarator,pcVar54);
        pcVar54 = decl_specifiers_current();
        pcVar31 = decl_declare_and_check(pcVar14->declarator,pcVar54->spec);
        decl_record_set_symbol(pcVar14->ptr,pcVar31);
        pcVar31 = decl_declarator_symbol(pcVar14->declarator);
        decl_begin_initialized_definition(pcVar31);
        g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] | 2;
        lVar45 = g_enum_value;
      }
      break;
    case 0xd5:
      decl_specifiers_current();
      diag_error(0x201);
      value_base[1].words[0] = 0;
      lVar45 = g_enum_value;
      break;
    case 0xd8:
      if (g_opt_Zg == '\0') {
        iVar22 = 0;
        pcVar24 = expr_resolve_address_of_overload(pcVar40->node);
        init_process_initializer(pcVar24,iVar22);
      }
      g_string_literal_cur = &g_string_literal_buffer;
      lVar45 = g_enum_value;
      break;
    case 0xd9:
      if (g_opt_Zg == '\0') {
        init_check_too_many_2();
        lVar45 = g_enum_value;
      }
      break;
    case 0xda:
      if (g_opt_Zg == '\0') {
        init_pop_brace_level();
        lVar45 = g_enum_value;
      }
      break;
    case 0xdb:
      if (g_yy_lookahead == (byte *)0x0) {
        g_yy_lookahead = token_next((c1_token_reader *)&g_token_position);
      }
      cVar10 = lex_token_code((c1xx_token *)g_yy_lookahead);
      lVar45 = g_enum_value;
      switch(cVar10) {
      case '4':
      case '7':
      case '>':
      case 0xbf:
        break;
      default:
        goto switchD_1042181a_caseD_35;
      case '6':
      case 'u':
      case 0xa6:
        bVar44 = g_paren_depth == 0;
        goto LAB_10421837;
      case 'j':
      case '~':
        bVar44 = g_paren_depth != 0;
LAB_10421837:
        if (!bVar44) {
switchD_1042181a_caseD_35:
          bVar11 = (-(g_paren_depth != 0) & 0xb8U) + 0x7f;
          uStack_150 = CONCAT31(uStack_150._1_3_,bVar11);
          parse_report_inserted_token(g_yy_lookahead,(uint)bVar11);
          lex_unget_token((c1xx_token *)g_yy_lookahead);
          g_yy_lookahead = &token_static_for_code(uStack_150)->code;
          lVar45 = g_enum_value;
        }
        break;
      case '\x7f':
        if ((g_paren_depth != 0) && ((g_paren_level_flags[g_paren_depth] & 8) != 0))
        goto switchD_1042181a_caseD_35;
      }
      break;
    case 0xdc:
    case 0x11a:
      g_declarator_paren_base = g_declarator_paren_base + 1;
      break;
    case 0xdd:
      pvVar23 = pcVar40->ptr;
      piVar20 = decl_declarator_record(value_base[1].declarator);
      decl_append_function_layer(piVar20,pvVar23);
      lVar45 = g_enum_value;
      break;
    case 0xde:
      pcVar33 = pcVar40->declarator;
      goto LAB_1042192a;
    case 0xe0:
      if (pcVar14->node != (c1_node *)0x0) {
        lVar46 = expr_eval_constant_expression(pcVar14->node);
        if (((g_class_depth < 0) || (lVar45 = g_enum_value, g_ms_extensions == '\0')) &&
           (lVar45 = g_enum_value, lVar46 == 0)) {
          iVar12 = yyparse_cpp_zero_array_bound_error
                             (value_base,parser,state_sp,0,saved_lookahead,iVar12);
          return iVar12;
        }
      }
      piVar20 = (int *)&stack0xfffffe9c;
      g_enum_value = lVar45;
      pcVar34 = decl_declarator_record(value_base[1].declarator);
      decl_append_array_layer(pcVar34,piVar20);
      lVar45 = g_enum_value;
      break;
    case 0xe1:
    case 0x125:
    case 0x175:
      value_base[1].words[0] = pcVar14->words[0];
      lVar45 = g_enum_value;
    case 0x17f:
      g_enum_value = lVar45;
      parse_paren_depth_pop();
      lVar45 = g_enum_value;
      break;
    case 0xe2:
      pcVar33 = pcVar40->declarator;
      pcVar34 = decl_declarator_record(pcVar33);
      type_check_based_form(pcVar34,&pcVar14->mods);
      value_base[1].declarator = pcVar33;
      lVar45 = g_enum_value;
      break;
    case 0xe4:
      pcVar33 = pcVar40->declarator;
      cVar9 = declarator_flags56_bit0(pcVar33);
      if (cVar9 != '\0') {
        pcVar54 = &g_conversion_type_specifiers;
        pcVar34 = decl_declarator_record(pcVar33);
        decl_record_set_conversion_type(pcVar34,pcVar54);
      }
      value_base[1].declarator = pcVar33;
      lVar45 = g_enum_value;
      break;
    case 0xe5:
      pcVar33 = decl_declarator_alloc();
      if (pcVar33 == (c1_declarator *)0x0) {
LAB_10466a12:
        pcVar33 = (c1_declarator *)0x0;
      }
      else {
        pcVar33 = decl_declarator_init(pcVar33,pcVar40->name,0,(c1_overload_set *)0x0);
      }
      goto LAB_10421a04;
    case 0xe6:
      pcVar33 = decl_declarator_alloc();
      if (pcVar33 == (c1_declarator *)0x0) {
        pcVar33 = (c1_declarator *)0x0;
      }
      else {
        pcVar55 = (c1_overload_set *)0x0;
        uVar49 = 0;
        uVar51 = 0;
        uVar41 = 0;
        pcVar31 = value_word0(pcVar40->cell);
        pcVar33 = decl_declarator_init
                            (pcVar33,(fe_name *)pcVar31,CONCAT22(uVar41,CONCAT11(uVar51,uVar49)),
                             pcVar55);
      }
      pvVar23 = decl_declarator_record(pcVar40->declarator);
      if (pvVar23 == (void *)0x0) {
        pcVar31 = (c1_symbol *)sym_name(pcVar40->sym);
      }
      else {
        pcVar31 = (c1_symbol *)sym_name(pcVar40->sym);
      }
      iVar22 = sym_scope_index(pcVar31);
      if (iVar22 != 0) {
        pcVar31 = sym_scope_by_index(pcVar31,0x1c);
        decl_record_set_qualifying_class(pcVar33,pcVar31);
      }
      goto LAB_10421a04;
    case 0xe7:
      pcVar33 = decl_declarator_alloc();
      if (pcVar33 == (c1_declarator *)0x0) goto LAB_10466a12;
      pcVar55 = (c1_overload_set *)0x0;
      uVar49 = 0;
      uVar51 = 0;
      uVar41 = 0;
      pfVar30 = sym_name_of_ref(pcVar40->cell);
      pcVar33 = decl_declarator_init
                          (pcVar33,pfVar30,CONCAT22(uVar41,CONCAT11(uVar51,uVar49)),pcVar55);
LAB_10421a04:
      cVar9 = class_name_is_current_class(pcVar33);
      if (cVar9 == '\0') {
LAB_10421a0f:
        value_base[1].declarator = pcVar33;
        lVar45 = g_enum_value;
      }
      else {
        decl_set_is_constructor(pcVar33,'\x01');
        value_base[1].declarator = pcVar33;
        lVar45 = g_enum_value;
      }
      break;
    case 0xe8:
    case 0x1b2:
      goto switchD_10421905_caseD_e5;
    case 0xe9:
      pcVar33 = decl_declarator_alloc();
      if (pcVar33 == (c1_declarator *)0x0) {
        pcVar33 = (c1_declarator *)0x0;
      }
      else {
        pcVar33 = decl_declarator_init(pcVar33,pcVar40->name,0,(c1_overload_set *)0x0);
      }
      cVar9 = class_name_is_current_class(pcVar33);
      if (cVar9 == '\0') {
joined_r0x10466b1f:
        if (g_class_depth < 0) {
          value_word0((c1_symbol **)pcVar33);
          goto LAB_10466b2d;
        }
LAB_10466aa7:
        diag_error(0x20b);
        pvVar23 = class_current_definition_name();
        decl_set_name(pcVar33,pvVar23);
        goto LAB_10421ad0;
      }
      decl_set_is_destructor(pcVar33,'\x01');
      value_base[1].declarator = pcVar33;
      lVar45 = g_enum_value;
      break;
    case 0xea:
      pcVar31 = value_word0(pcVar40->cell);
      pcVar33 = decl_declarator_alloc();
      if (pcVar33 == (c1_declarator *)0x0) {
        pcVar33 = (c1_declarator *)0x0;
      }
      else {
        pcVar33 = decl_declarator_init(pcVar33,(fe_name *)pcVar31,0,(c1_overload_set *)0x0);
      }
      cVar9 = class_name_is_current_class(pcVar33);
      if (cVar9 != '\0') goto LAB_10421ad0;
      if (-1 < g_class_depth) goto LAB_10466aa7;
LAB_10466b2d:
      diag_error(0x24c);
      value_base[1].declarator = pcVar33;
      lVar45 = g_enum_value;
      break;
    case 0xeb:
      pcVar33 = decl_declarator_alloc();
      if (pcVar33 == (c1_declarator *)0x0) {
        pcVar33 = (c1_declarator *)0x0;
      }
      else {
        pcVar55 = (c1_overload_set *)0x0;
        uVar49 = 0;
        uVar51 = 0;
        uVar41 = 0;
        pfVar30 = sym_name_of_ref(pcVar40->cell);
        pcVar33 = decl_declarator_init
                            (pcVar33,pfVar30,CONCAT22(uVar41,CONCAT11(uVar51,uVar49)),pcVar55);
      }
      cVar9 = class_name_is_current_class(pcVar33);
      if (cVar9 == '\0') goto joined_r0x10466b1f;
LAB_10421ad0:
      decl_set_is_destructor(pcVar33,'\x01');
      value_base[1].declarator = pcVar33;
      lVar45 = g_enum_value;
      break;
    case 0xec:
      pcVar33 = decl_declarator_alloc();
      if (pcVar33 == (c1_declarator *)0x0) {
        value_set_byte30((c1_declarator *)0x0,(pcVar40->spec).spec[0]);
        value_base[1].words[0] = 0;
        lVar45 = g_enum_value;
      }
      else {
        pcVar33 = decl_declarator_init
                            (pcVar33,*(fe_name **)((int)pcVar14 + 0x2c),0,(c1_overload_set *)0x0);
        value_set_byte30(pcVar33,(pcVar40->spec).spec[0]);
        value_base[1].declarator = pcVar33;
        lVar45 = g_enum_value;
      }
      break;
    case 0xed:
      pcVar54 = &g_conversion_type_specifiers;
      for (iVar22 = 9; iVar22 != 0; iVar22 = iVar22 + -1) {
        *(c1_u32 *)pcVar54->spec = pcVar40->words[0];
        pcVar40 = (c1_yy_value *)(pcVar40->words + 1);
        pcVar54 = (c1xx_decl_specifiers *)(pcVar54->spec + 4);
      }
      pcVar33 = decl_declarator_alloc();
      if (pcVar33 == (c1_declarator *)0x0) {
        pcVar33 = (c1_declarator *)0x0;
      }
      else {
        pcVar55 = (c1_overload_set *)0x0;
        uVar49 = 0;
        uVar51 = 0;
        uVar41 = 0;
        pfVar30 = decl_conversion_function_name(g_conversion_type_specifiers.type);
        pcVar33 = decl_declarator_init
                            (pcVar33,pfVar30,CONCAT22(uVar41,CONCAT11(uVar51,uVar49)),pcVar55);
      }
      value_set_byte30(pcVar33,0x8f);
      declarator_set_flags56_bit0(pcVar33,'\x01');
      g_compile_flags_c4 = g_compile_flags_c4 & 0xfffffffb;
      value_base[1].declarator = pcVar33;
      lVar45 = g_enum_value;
      break;
    case 0xee:
      if (pcVar40->cell == (c1_symbol **)0x0) {
        d.sym = (c1_symbol *)0x0;
        in_stack_fffffe94.sym = d.sym;
      }
      else {
        pcVar15 = value_word0(pcVar40->cell);
        pcVar31 = *(c1_symbol **)(*(int *)pcVar15->type + 8);
        pcVar33 = decl_declarator_alloc();
        if (pcVar33 == (c1_declarator *)0x0) {
          d.sym = (c1_symbol *)0x0;
        }
        else {
          uVar49 = 0;
          uVar51 = 0;
          uVar41 = 0;
          qualifier = pcVar15;
          pfVar30 = (fe_name *)sym_name(pcVar15);
          d.sym = (c1_symbol *)
                  decl_declarator_init
                            (pcVar33,pfVar30,CONCAT22(uVar41,CONCAT11(uVar51,uVar49)),qualifier);
        }
        in_stack_fffffe94 = d;
        lookup_check_symbol_kinds_reversed(*(int **)pcVar15->type);
        bVar11 = pcVar15->flags1;
        if ((bVar11 & 0x40) == 0) {
          if ((bVar11 & 0x10) == 0) {
            lVar45 = g_enum_value;
            if ((bVar11 & 0x20) != 0) {
              decl_set_is_destructor(d.declarator,'\x01');
              lVar45 = g_enum_value;
            }
          }
          else {
            decl_set_is_constructor(d.declarator,'\x01');
            lVar45 = g_enum_value;
          }
        }
        else {
          d = in_stack_fffffe94;
          if ((pcVar31->kind & 0x1f) == 0x11) {
            pcVar31 = (c1_symbol *)ovl_first_function_of_set(pcVar31);
            d = in_stack_fffffe94;
          }
          g_conversion_type_specifiers.type = decl_declarator_record((c1_declarator *)pcVar31->type)
          ;
          puVar27 = decl_specifiers_of_symbol(auStack_18,pcVar31);
          pcVar54 = &g_conversion_type_specifiers;
          for (iVar22 = 6; iVar22 != 0; iVar22 = iVar22 + -1) {
            *(uint *)pcVar54->spec = *puVar27;
            puVar27 = puVar27 + 1;
            pcVar54 = (c1xx_decl_specifiers *)(pcVar54->spec + 4);
          }
          declarator_set_flags56_bit0(d.declarator,'\x01');
          in_stack_fffffe94 = d;
          lVar45 = g_enum_value;
        }
        bVar11 = pcVar31->kind & 0x1f;
        if ((((bVar11 == 0x10) || (bVar11 == 7)) ||
            ((bVar11 == 6 || (((bVar11 == 0x11 || (bVar11 == 8)) || (bVar11 == 0x1b)))))) ||
           ((bVar11 == 0x1a &&
            (((bVar11 = **(byte **)pcVar31->type & 0x1f, bVar11 == 0x10 || (bVar11 == 7)) ||
             (((bVar11 == 6 || ((bVar11 == 0x11 || (bVar11 == 8)))) || (bVar11 == 0x1b)))))))) {
          g_enum_value = lVar45;
          if (**(int **)pcVar15->type != 0) {
            pcVar15 = *(c1_symbol **)(**(int **)pcVar15->type + 8);
            if ((pcVar15->kind & 0x1f) == 0xf) {
              pcVar15 = scope_vector_get((short)pcVar15->key_ref);
            }
            if ((pcVar15->kind & 0x1f) == 4) {
              decl_record_set_qualifying_class(d.declarator,pcVar15);
              if ((g_compile_flags_cc & 0x200000) != 0) {
                declarator_set_kind(d.declarator,2);
              }
            }
          }
          bVar11 = pcVar31->kind & 0x1f;
          if (((bVar11 == 0x10) || (bVar11 == 0x11)) || (bVar11 == 0x1b)) {
            pbVar16 = ovl_first_function_of_set(pcVar31);
            value_set_byte30(d.declarator,pbVar16[0x2f]);
            value_base[1].declarator = (c1_declarator *)d;
            lVar45 = g_enum_value;
          }
          else {
            value_set_byte30(d.declarator,(pcVar31->tail).fn.op_token);
            value_base[1].declarator = (c1_declarator *)d;
            lVar45 = g_enum_value;
          }
          break;
        }
      }
      g_enum_value = lVar45;
      value_base[1].declarator = (c1_declarator *)d;
      lVar45 = g_enum_value;
      break;
    case 0xef:
      if (pcVar14->cell == (c1_symbol **)0x0) {
LAB_10466c6d:
        pcVar33 = (c1_declarator *)0x0;
      }
      else {
        pcVar31 = value_word0(pcVar14->cell);
        pcVar54 = &g_conversion_type_specifiers;
        for (iVar22 = 9; iVar22 != 0; iVar22 = iVar22 + -1) {
          *(c1_u32 *)pcVar54->spec = pcVar40->words[0];
          pcVar40 = (c1_yy_value *)(pcVar40->words + 1);
          pcVar54 = (c1xx_decl_specifiers *)(pcVar54->spec + 4);
        }
        decl_qualified_conversion_function_name(pcVar31,g_conversion_type_specifiers.type);
        if (pcVar31->type == (c1_type *)0x0) {
          pcVar33 = decl_declarator_alloc();
          if (pcVar33 == (c1_declarator *)0x0) goto LAB_10466c6d;
          pcVar55 = (c1_overload_set *)0x0;
          uVar49 = 0;
          uVar51 = 0;
          uVar41 = 0;
          pfVar30 = name_new_S();
          pcVar33 = decl_declarator_init
                              (pcVar33,pfVar30,CONCAT22(uVar41,CONCAT11(uVar51,uVar49)),pcVar55);
        }
        else {
          pcVar33 = decl_declarator_alloc();
          if (pcVar33 == (c1_declarator *)0x0) {
            pcVar33 = (c1_declarator *)0x0;
          }
          else {
            uVar49 = 0;
            uVar51 = 0;
            uVar41 = 0;
            pcVar15 = pcVar31;
            pfVar30 = (fe_name *)sym_name(pcVar31);
            pcVar33 = decl_declarator_init
                                (pcVar33,pfVar30,CONCAT22(uVar41,CONCAT11(uVar51,uVar49)),
                                 (c1_overload_set *)pcVar15);
          }
          lookup_check_symbol_kinds_reversed(*(int **)pcVar31->type);
          if (**(int **)pcVar31->type != 0) {
            pcVar31 = *(c1_symbol **)(**(int **)pcVar31->type + 8);
            if ((pcVar31->kind & 0x1f) == 0xf) {
              pcVar31 = scope_vector_get((short)pcVar31->key_ref);
            }
            decl_record_set_qualifying_class(pcVar33,pcVar31);
          }
          value_set_byte30(pcVar33,0x8f);
          declarator_set_flags56_bit0(pcVar33,'\x01');
          if ((g_compile_flags_cc & 0x200000) != 0) {
            declarator_set_kind(pcVar33,2);
          }
        }
      }
      g_compile_flags_c4 = g_compile_flags_c4 & 0xfffffffb;
      value_base[1].declarator = pcVar33;
      lVar45 = g_enum_value;
      break;
    case 0xf0:
      pcVar14 = value_base + 1;
      decl_conversion_function_declarator(&pcVar14->spec,(c1_decl_record *)0x0);
      (pcVar14->spec).spec[0] = (pcVar14->spec).spec[0] & 0x7f;
      lVar45 = g_enum_value;
      break;
    case 0xf1:
      pcVar14 = value_base + 1;
      pcVar34 = decl_declarator_record(pcVar40->declarator);
      decl_conversion_function_declarator(&pcVar14->spec,pcVar34);
      (pcVar14->spec).spec[0] = (pcVar14->spec).spec[0] & 0x7f;
      lVar45 = g_enum_value;
      break;
    case 0xf2:
      param_clause_set_cv_qualifiers(pcVar14[-1].params,&pcVar14->mods);
      param_clause_set_exception_spec(pcVar14[-1].params,pcVar40->words[0]);
      lVar45 = g_enum_value;
      break;
    case 0xf3:
      pcVar28 = class_record_new_kind5();
      value_base[1].str.text = pcVar28;
      parse_paren_depth_pop();
      lVar45 = g_enum_value;
      break;
    case 0xf4:
      g_prototype_scope_depth = g_prototype_scope_depth + 1;
      g_block_depth = g_block_depth + '\x01';
      scope_new_block_record(g_current_scope,(c1_sym_list *)0x0);
      lVar45 = g_enum_value;
      break;
    case 0xf5:
      pvVar23 = pcVar14[-1].ptr;
      value_base[1].ptr = pvVar23;
      if (pcVar14->sym != (c1_symbol *)0x0) {
        sym_list_append(pvVar23,pcVar14->sym);
      }
      g_prototype_scope_depth = g_prototype_scope_depth + -1;
      g_block_depth = g_block_depth + 0xff;
      parse_paren_depth_pop();
      lVar45 = g_enum_value;
      break;
    case 0xf6:
      if (((((g_block_depth == '\0') || (-1 < g_class_depth)) ||
           ((g_compile_flags_c8 & 0x10000000) != 0)) ||
          ((((g_compile_flags_c8 & 0x40000000) != 0 && ((g_compile_flags_cc & 8) == 0)) &&
           ((g_compile_flags_c4 & 0x200) == 0)))) || ((g_compile_flags_cc & 0x50) != 0)) {
        iVar22 = 0;
      }
      else {
        iVar22 = 4;
      }
      pcVar31 = sym_new_of_kind('\v',g_name_ellipsis,iVar22);
      sym_mark_ellipsis_parameter(pcVar31);
      pcVar32 = type_intern_basic_parts(0x80d,0,0);
      pcVar31->type = pcVar32;
      pcVar17 = (c1_param_clause *)arena5_alloc_1c();
      if (pcVar17 == (c1_param_clause *)0x0) {
        value_base[1].words[0] = 0;
        sym_list_append((void *)0x0,pcVar31);
        parse_paren_depth_pop();
        lVar45 = g_enum_value;
      }
      else {
        pcVar17 = optional_value_init(pcVar17,3,(c1_sym_list *)0x0,'\0');
        value_base[1].params = pcVar17;
        sym_list_append(pcVar17,pcVar31);
        parse_paren_depth_pop();
        lVar45 = g_enum_value;
      }
      break;
    case 0xf8:
      if (pcVar40->words[0] != 2) goto LAB_10467c9b;
      diag_warning(3,0x122);
      value_base[1].ptr = (void *)pcVar40->words[0];
      lVar45 = g_enum_value;
      break;
    case 0xf9:
      pcVar17 = (c1_param_clause *)arena5_alloc_1c();
      if (pcVar17 == (c1_param_clause *)0x0) goto LAB_10465f34;
      cVar9 = '\x01';
      scope = decl_declarator_record((c1_declarator *)g_current_scope);
      params = scope_symbol_list(scope);
      pcVar17 = optional_value_init(pcVar17,3,params,cVar9);
      value_base[1].params = pcVar17;
      lVar45 = g_enum_value;
      break;
    case 0xfb:
      g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] | 8;
      lVar45 = g_enum_value;
      break;
    case 0xfc:
      if ((pcVar40->words[0] != 0) && (g_paren_level_arg_lists[g_paren_depth] != (c1_arg_list *)0x0)
         ) {
        arena_set_expression_index(0);
        g_compile_flags_cc = g_compile_flags_cc | 0x10;
        pcVar24 = tree_append_list_item((c1_node *)0x0,(c1_node *)0x0,2);
        pcVar18 = (c1_arg_item *)arena_alloc_n_aligned(0x14,0);
        if (pcVar18 == (c1_arg_item *)0x0) {
          pcVar18 = (c1_arg_item *)0x0;
        }
        else {
          pcVar18 = arg_expression_item_init(pcVar18,pcVar24,'\0','\x01');
        }
        tmpl_argument_list_prepend(g_paren_level_arg_lists[g_paren_depth],pcVar18);
        goto LAB_10466d4e;
      }
      goto switchD_10421905_caseD_5c;
    case 0xfd:
      cVar10 = token_source_reads_source_file((c1_token_reader *)&g_token_position);
      if (cVar10 != '\0') {
        iVar22 = 0;
        pcVar38 = g_idb->vtbl;
        uVar56 = lex_line_number_of_position(&g_token_position);
        (*pcVar38->idb_scope_kind4_end)(g_idb,uVar56,iVar22);
      }
      if ((pcVar14->words[0] != 0) && (pcVar40->node != (c1_node *)0x0)) {
        pcVar24 = expr_resolve_address_of_overload(pcVar40->node);
        if ((g_compile_flags_c8 & 0x40000000) != 0) {
          pcVar24 = tree_copy_to_arena(pcVar24,0);
        }
        tree_attach_typed_link(pcVar24,pcVar14->sym->type);
        acStackY_1a8[1] = 0x10421fe2;
        pcVar24 = conv_convert_expression(0xc6,pcVar14->sym->type,pcVar24,'\x02','\x04');
        pcVar40->node = pcVar24;
        iVar22 = 2;
        pcVar24 = (c1_node *)expr_finish_full_expression((int)pcVar24);
        pcVar24 = tree_append_list_item((c1_node *)0x0,pcVar24,iVar22);
        pcVar18 = (c1_arg_item *)arena_alloc_n_aligned(0x14,0);
        if (pcVar18 == (c1_arg_item *)0x0) {
          pcVar18 = (c1_arg_item *)0x0;
        }
        else {
          pcVar18 = arg_expression_item_init(pcVar18,pcVar24,'\0','\x01');
        }
        if (g_paren_level_arg_lists[g_paren_depth] == (c1_arg_list *)0x0) {
          pcVar28 = arena_alloc_n_aligned(0xc,0);
          if (pcVar28 == (c1_u8 *)0x0) {
            g_paren_level_arg_lists[g_paren_depth] = (c1_arg_list *)0x0;
          }
          else {
            pcVar19 = tmpl_argument_list_init(pcVar28,pcVar18);
            g_paren_level_arg_lists[g_paren_depth] = pcVar19;
          }
        }
        else {
          tmpl_argument_list_prepend(g_paren_level_arg_lists[g_paren_depth],pcVar18);
        }
      }
      goto joined_r0x10466e52;
    case 0xfe:
      cVar10 = token_source_reads_source_file((c1_token_reader *)&g_token_position);
      if (cVar10 != '\0') {
        iVar22 = 0;
        pcVar38 = g_idb->vtbl;
        uVar56 = lex_line_number_of_position(&g_token_position);
        (*pcVar38->idb_scope_kind4_end)(g_idb,uVar56,iVar22);
      }
      if ((g_compile_flags_c8 & 0x10000000) == 0) {
        diag_error(0x3e);
      }
      pcVar18 = (c1_arg_item *)arena_alloc_n_aligned(0x14,0);
      if (pcVar18 == (c1_arg_item *)0x0) {
        pcVar18 = (c1_arg_item *)0x0;
      }
      else {
        pcVar18 = pch_fixup_list_object_ctor(pcVar18,pcVar40->sym->type,'\0');
      }
      if (g_paren_level_arg_lists[g_paren_depth] == (c1_arg_list *)0x0) {
        pcVar28 = arena_alloc_n_aligned(0xc,0);
        if (pcVar28 == (c1_u8 *)0x0) {
          g_paren_level_arg_lists[g_paren_depth] = (c1_arg_list *)0x0;
        }
        else {
          pcVar19 = tmpl_argument_list_init(pcVar28,pcVar18);
          g_paren_level_arg_lists[g_paren_depth] = pcVar19;
        }
      }
      else {
        tmpl_argument_list_prepend(g_paren_level_arg_lists[g_paren_depth],pcVar18);
      }
      expr_count_evaluated_operator();
joined_r0x10466e52:
      g_compile_flags_cc = g_compile_flags_cc & 0xffffffef;
      if ((g_compile_flags_c8 & 0x10000000) != 0) {
LAB_10466e58:
        g_compile_flags_c8 = g_compile_flags_c8 & 0xfeffffff;
      }
LAB_10422076:
      arena_select_for_expressions();
      lVar45 = g_enum_value;
switchD_10421905_caseD_5c:
      g_enum_value = lVar45;
      g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfd;
      lVar45 = g_enum_value;
      break;
    case 0xff:
      cVar10 = token_source_reads_source_file((c1_token_reader *)&g_token_position);
      if (cVar10 != '\0') {
        iVar22 = 0;
        pcVar38 = g_idb->vtbl;
        uVar56 = lex_line_number_of_position(&g_token_position);
        (*pcVar38->idb_scope_kind4_end)(g_idb,uVar56,iVar22);
      }
      if ((g_compile_flags_cc & 0x100000) == 0) {
        pcVar24 = arena_alloc(g_arenas + g_expr_arena_index,0x18);
        pcVar24->kind = '\0';
        pcVar24->op = 0xc6;
        pcVar24->left = (void *)pcVar40->words[0];
        pcVar32 = type_intern_basic_parts(0x80e,0,0);
        value_set_field4(pcVar24,pcVar32);
        pcVar24 = tree_append_list_item((c1_node *)0x0,pcVar24,2);
        pcVar18 = (c1_arg_item *)arena_alloc_n_aligned(0x14,0);
        if (pcVar18 == (c1_arg_item *)0x0) {
          pcVar18 = (c1_arg_item *)0x0;
        }
        else {
          pcVar18 = arg_expression_item_init(pcVar18,pcVar24,'\0','\x01');
        }
        if (g_paren_level_arg_lists[g_paren_depth] == (c1_arg_list *)0x0) {
          pcVar28 = arena_alloc_n_aligned(0xc,0);
          if (pcVar28 == (c1_u8 *)0x0) {
            g_paren_level_arg_lists[g_paren_depth] = (c1_arg_list *)0x0;
          }
          else {
            pcVar19 = tmpl_argument_list_init(pcVar28,pcVar18);
            g_paren_level_arg_lists[g_paren_depth] = pcVar19;
          }
        }
        else {
          tmpl_argument_list_prepend(g_paren_level_arg_lists[g_paren_depth],pcVar18);
        }
        if ((g_compile_flags_c8 & 0x10000000) != 0) goto LAB_104221a8;
      }
      else {
LAB_104221a8:
        g_compile_flags_c8 = g_compile_flags_c8 & 0xfeffffff;
      }
      expr_count_evaluated_operator();
      func_flow_state_pop_unless_sizeof();
      g_compile_flags_cc = g_compile_flags_cc & 0xffffffef;
      goto LAB_10422076;
    case 0x100:
      cVar10 = token_source_reads_source_file((c1_token_reader *)&g_token_position);
      if (cVar10 != '\0') {
        iVar22 = 0;
        pcVar38 = g_idb->vtbl;
        uVar56 = lex_line_number_of_position(&g_token_position);
        (*pcVar38->idb_scope_kind4_end)(g_idb,uVar56,iVar22);
      }
      cVar10 = lex_token_code((c1xx_token *)g_yy_lookahead);
      if (cVar10 == 'u') {
        diag_error(0x117);
        pcVar26 = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
        parse_skip_tokens_to_one_of(pcVar26);
        g_yy_lookahead = (byte *)0x0;
      }
      else {
        g_yy_lookahead = &parse_skip_tokens_to_one_of((c1xx_token *)g_yy_lookahead)->code;
      }
      parse_yyerrok(parser);
LAB_10466d4e:
      g_compile_flags_cc = g_compile_flags_cc & 0xffffffef;
      if ((g_compile_flags_c8 & 0x10000000) == 0) goto LAB_10422076;
      goto LAB_10466e58;
    case 0x101:
      if ((g_class_depth < 0) && ((g_compile_flags_c8 & 0x10000000) == 0)) {
        g_compile_flags_cc = g_compile_flags_cc | 0x10;
        arena_set_expression_index(0);
        func_flow_state_note_3e();
        lVar45 = g_enum_value;
      }
      else {
        g_compile_flags_c8 = g_compile_flags_c8 | 0x8000000;
        parse_default_argument_begin(pcVar40->sym->type);
        func_flow_state_note_3e();
        lVar45 = g_enum_value;
      }
      break;
    case 0x102:
      cVar10 = token_source_reads_source_file((c1_token_reader *)&g_token_position);
      lVar45 = g_enum_value;
      if (cVar10 != '\0') {
        pcVar38 = g_idb->vtbl;
        goto LAB_10422231;
      }
      break;
    case 0x104:
      scope_insert_through_object(g_current_scope,pcVar40->sym);
      lVar45 = g_enum_value;
      break;
    case 0x105:
      value_base[1].words[0] = 0;
      if ((g_compile_flags_c8 & 0x30000000) == 0) {
        pcVar26 = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
        pcVar26 = parse_skip_tokens_to_one_of(pcVar26);
        g_yy_lookahead = &pcVar26->code;
LAB_10466f65:
        token_source_unget((c1_token_reader *)&g_token_position,pcVar26);
      }
      else {
        if (g_yy_lookahead == (byte *)0x0) {
LAB_10466f97:
          g_yy_lookahead = token_next((c1_token_reader *)&g_token_position);
        }
        else {
          cVar10 = lex_token_code((c1xx_token *)g_yy_lookahead);
          if (cVar10 != '>') goto LAB_10466f97;
        }
        g_yy_lookahead = &parse_skip_tokens_to_one_of((c1xx_token *)g_yy_lookahead)->code;
        token_source_unget((c1_token_reader *)&g_token_position,(c1xx_token *)g_yy_lookahead);
        cVar10 = lex_token_code((c1xx_token *)g_yy_lookahead);
        if (cVar10 == '\x7f') {
          pcVar26 = token_static_for_code(0x3e);
          goto LAB_10466f65;
        }
      }
      parse_yyerrok(parser);
LAB_10466f79:
      g_yy_lookahead = (byte *)0x0;
      lVar45 = g_enum_value;
      break;
    case 0x106:
      pcVar54 = &local_f0;
      for (iVar22 = 9; iVar22 != 0; iVar22 = iVar22 + -1) {
        *(c1_u32 *)pcVar54->spec = pcVar14->words[0];
        pcVar54 = (c1xx_decl_specifiers *)(pcVar54->spec + 4);
        pcVar14 = (c1_yy_value *)(pcVar14->words + 1);
      }
      decl_set_local_key_flag(pcVar40->declarator,'\x01');
      if (((g_compile_flags_c8 & 0x10000000) == 0) || (g_paren_depth != 1)) {
        cVar29 = 5;
      }
      else {
        cVar29 = 0xb;
      }
      declarator_set_kind(pcVar40->declarator,cVar29);
      pcVar54 = &local_f0;
      pcVar34 = decl_declarator_record(pcVar40->declarator);
      decl_check_conversion_return_type(pcVar34,pcVar54);
      pcVar34 = decl_declarator_record(pcVar40->declarator);
      decl_finish_declarator(pcVar34);
      decl_declarator_set_specifiers(pcVar40->declarator,&local_f0);
      decl_declare_in_current_scope(pcVar40->declarator,&local_f0);
      pcVar31 = decl_declarator_symbol(pcVar40->declarator);
      if ((g_compile_flags_c8 & 0x10000000) != 0) {
        pcVar32 = pcVar31->type;
        cVar9 = type_code_is_201(pcVar32);
        if (cVar9 == '\0') {
          cVar9 = type_code_is_202(pcVar32);
          if (cVar9 != '\0') {
            iVar12 = yyparse_cpp_class_template_parameter_error
                               (pcVar31,value_base,parser,state_sp,saved_lookahead,iVar12);
            return iVar12;
          }
        }
        else if ((pcVar31->storage & 0x80) == 0) {
          diag_error(0x3e1);
          pcVar31->flags3 = pcVar31->flags3 | 4;
        }
      }
      g_declarator_paren_base = g_declarator_paren_base + -1;
      scope_pop_to_kind_if_needed(g_current_scope,'\x01');
      g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfc;
      value_base[1].sym = pcVar31;
      lVar45 = g_enum_value;
      break;
    case 0x107:
      bVar44 = false;
      decl_set_local_key_flag(pcVar40->declarator,'\x01');
      if (((g_compile_flags_c8 & 0x10000000) == 0) || (g_paren_depth != 1)) {
        cVar29 = 6;
      }
      else {
        cVar29 = 0xb;
      }
      declarator_set_kind(pcVar40->declarator,cVar29);
      decl_set_name(pcVar40->declarator,g_name_formal);
      if ((((g_compile_flags_c8 & 0x10000000) != 0) &&
          ((pcVar14->spec).type_sym != (c1_symbol *)0x0)) &&
         ((((pcVar14->spec).type_sym)->kind & 0x1f) == 4)) {
        pcVar32 = type_innermost_base((pcVar14->spec).type);
        if (((pcVar32->code & 0x20f) == 0x201) && (((pcVar14->spec).spec[0] & 0x80) == 0)) {
          iVar22 = sym_scope_index((pcVar14->spec).type_sym);
          if (iVar22 == 0) {
            bVar44 = true;
            pvVar23 = (void *)sym_name((pcVar14->spec).type_sym);
            if ((*(uint *)((int)pvVar23 + 8) & 0x2000000) != 0) {
              cell = lookup_name_in_context(g_current_scope,pvVar23,0x20);
              if (cell != (c1_lookup_entry *)0x0) {
                value_word0(&cell->sym);
              }
              diag_error(0x3af);
            }
            decl_set_name(pcVar40->declarator,pvVar23);
          }
        }
      }
      (pcVar14->spec).spec[0] = (pcVar14->spec).spec[0] & 0x7f;
      pcVar39 = pcVar14;
      pcVar34 = decl_declarator_record(pcVar40->declarator);
      decl_check_conversion_return_type(pcVar34,&pcVar39->spec);
      pcVar34 = decl_declarator_record(pcVar40->declarator);
      decl_finish_declarator(pcVar34);
      decl_declarator_set_specifiers(pcVar40->declarator,&pcVar14->spec);
      decl_process_declaration(pcVar40->declarator);
      pcVar31 = sym_new_from_declarator(pcVar40->declarator,0xffffffff);
      if (bVar44) {
        bVar11 = type_code_high_bit(pcVar31->type);
        if (bVar11 != 0) {
          sym_name(pcVar31);
          diag_error(0x395);
          pcVar31->flags3 = pcVar31->flags3 | 4;
        }
      }
      g_declarator_paren_base = g_declarator_paren_base + -1;
      g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfc;
      value_base[1].sym = pcVar31;
      lVar45 = g_enum_value;
      break;
    case 0x108:
    case 0x10f:
switchD_10421905_caseD_105:
      g_enum_value = lVar45;
      pair_clear(&value_base[1].mods);
      lVar45 = g_enum_value;
      break;
    case 0x10b:
    case 0x112:
      qualified_type_merge(&value_base[1].mods,&pcVar40->mods,(c1_u32)g_yy_lookahead);
      lVar45 = g_enum_value;
      break;
    case 0x10c:
      diag_warning(1,0xe6);
      lVar45 = g_enum_value;
      break;
    case 0x10d:
      operator_id_set(&value_base[1].mods,(short)g_tree_op_to_il_op[(pcVar40->spec).spec[0]],
                      (void *)0x0);
      lVar45 = g_enum_value;
      break;
    case 0x10e:
      value_base[1].words[0] = pcVar14->words[0];
      *(c1_u32 *)((int)value_base + 0x2c) = pcVar14->words[1];
      parse_paren_depth_pop();
      g_compile_flags_c4 = g_compile_flags_c4 & 0x7fffffff;
      lVar45 = g_enum_value;
      if ((g_compile_flags_c8 & 0x10) != 0) {
        g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfc;
        lVar45 = g_enum_value;
      }
      break;
    case 0x113:
      operator_id_set(&value_base[1].mods,(short)g_tree_op_to_il_op[(pcVar40->spec).spec[0]],
                      (void *)0x0);
      lVar45 = g_enum_value;
      break;
    case 0x114:
      operator_id_set(&value_base[1].mods,(pcVar40->ptr_op).kind,(void *)0x0);
      lVar45 = g_enum_value;
      break;
    case 0x115:
      bits = value_u16_at2(*(c1_type **)((int)pcVar14 + 0x40));
      pcVar32 = type_without_flags(*(c1_type **)((int)pcVar14 + 0x40),0x3e0);
      *(c1_type **)((int)pcVar14 + 0x40) = pcVar32;
      decl_warn_unexpected_specifiers_1(&pcVar40->spec);
      operator_id_set(&value_base[1].mods,bits,(void *)0x0);
      lVar45 = g_enum_value;
      break;
    case 0x116:
      pcVar31 = type_parse_based_specifier(pcVar40->ptr);
      operator_id_set(&value_base[1].mods,0x18,pcVar31);
      lVar45 = g_enum_value;
      break;
    case 0x117:
      pcVar24 = expr_check_this_usage();
      lVar45 = g_enum_value;
      if (pcVar24 == (c1_node *)0x0) goto switchD_10421905_caseD_105;
      break;
    case 0x118:
      operator_id_set(&value_base[1].mods,8,(void *)0x0);
      lVar45 = g_enum_value;
      break;
    case 0x119:
      pair_clear(&value_base[1].mods);
      lVar45 = g_enum_value;
      goto switchD_10421905_caseD_14f;
    case 0x11c:
      pcVar33 = decl_declarator_alloc();
      if (pcVar33 == (c1_declarator *)0x0) goto LAB_10465f34;
      pcVar33 = decl_declarator_init(pcVar33,g_name_abstract_declarator,4,(c1_overload_set *)0x0);
      value_base[1].declarator = pcVar33;
      lVar45 = g_enum_value;
      break;
    case 0x11d:
      pcVar33 = decl_declarator_alloc();
      if (pcVar33 == (c1_declarator *)0x0) {
        pcVar34 = decl_declarator_record((c1_declarator *)0x0);
        type_check_based_form(pcVar34,&pcVar40->mods);
        value_base[1].words[0] = 0;
        lVar45 = g_enum_value;
      }
      else {
        pcVar33 = decl_declarator_init(pcVar33,g_name_abstract_declarator,4,(c1_overload_set *)0x0);
        pcVar34 = decl_declarator_record(pcVar33);
        type_check_based_form(pcVar34,&pcVar40->mods);
        value_base[1].declarator = pcVar33;
        lVar45 = g_enum_value;
      }
      break;
    case 0x11e:
      pcVar33 = decl_declarator_alloc();
      if (pcVar33 == (c1_declarator *)0x0) {
        pvVar23 = pcVar40->ptr;
        pcVar33 = (c1_declarator *)0x0;
      }
      else {
        pcVar33 = decl_declarator_init(pcVar33,g_name_abstract_declarator,4,(c1_overload_set *)0x0);
        pvVar23 = pcVar40->ptr;
      }
      goto LAB_10467272;
    case 0x11f:
      pcVar33 = decl_declarator_alloc();
      if (pcVar33 == (c1_declarator *)0x0) {
        pcVar33 = (c1_declarator *)0x0;
      }
      else {
        pcVar33 = decl_declarator_init(pcVar33,g_name_abstract_declarator,4,(c1_overload_set *)0x0);
      }
      pcVar34 = decl_declarator_record(pcVar33);
      type_check_based_form(pcVar34,&pcVar14->mods);
      pvVar23 = pcVar40->ptr;
LAB_10467272:
      piVar20 = decl_declarator_record(pcVar33);
      decl_append_function_layer(piVar20,pvVar23);
      goto LAB_10421a0f;
    case 0x120:
      pcVar34 = decl_declarator_record(pcVar40->declarator);
      decl_declarator_append_pointer_op(pcVar34,&pcVar14->ptr_op);
      lVar45 = g_enum_value;
switchD_10421905_caseD_e5:
      g_enum_value = lVar45;
      value_base[1].ptr = (void *)pcVar40->words[0];
      lVar45 = g_enum_value;
      break;
    case 0x122:
      pcVar24 = pcVar14->node;
      pvVar23 = decl_declarator_record(value_base[1].declarator);
      type_check_array_bound_constant_2(pvVar23,pcVar24);
      lVar45 = g_enum_value;
      break;
    case 0x123:
      pvVar23 = pcVar40->ptr;
      piVar20 = decl_declarator_record(value_base[1].declarator);
      decl_append_function_layer(piVar20,pvVar23);
      lVar45 = g_enum_value;
      break;
    case 0x126:
      pcVar33 = decl_declarator_alloc();
      if (pcVar33 == (c1_declarator *)0x0) {
        pcVar33 = (c1_declarator *)0x0;
        pcVar14 = pcVar40;
        lVar45 = g_enum_value;
      }
      else {
        pcVar33 = decl_declarator_init(pcVar33,(fe_name *)0x0,0,(c1_overload_set *)0x0);
        pcVar14 = pcVar40;
        lVar45 = g_enum_value;
      }
LAB_1042192a:
      g_enum_value = lVar45;
      pcVar34 = decl_declarator_record(pcVar33);
      decl_declarator_append_pointer_op(pcVar34,&pcVar14->ptr_op);
LAB_10421939:
      value_base[1].declarator = pcVar33;
      lVar45 = g_enum_value;
      break;
    case 0x127:
    case 0x1e6:
      pcVar34 = decl_declarator_record(pcVar40->declarator);
      decl_declarator_append_pointer_op(pcVar34,&pcVar14->ptr_op);
      lVar45 = g_enum_value;
LAB_10467c9b:
      g_enum_value = lVar45;
      value_base[1].ptr = (void *)pcVar40->words[0];
      lVar45 = g_enum_value;
      break;
    case 0x128:
      local_144.bits = pcVar14[-1].words[0];
      local_144.based = *(void **)((int)pcVar14 + -0x24);
      type_pair_record_init(&value_base[1].ptr_op,&local_144,&pcVar40->mods);
      lVar45 = g_enum_value;
      break;
    case 0x129:
      pcVar21 = u16_value_init(&local_f8,0);
      type_pair_record_init(&value_base[1].ptr_op,pcVar21,&pcVar40->mods);
      lVar45 = g_enum_value;
      break;
    case 0x12a:
      cStack_13c.bits = pcVar14[-1].words[0];
      cStack_13c.based = *(void **)((int)pcVar14 + -0x24);
      type_warn_qualifiers_on_reference(&value_base[1].ptr_op,&cStack_13c,&pcVar40->mods);
      lVar45 = g_enum_value;
      break;
    case 299:
      pcVar21 = u16_value_init(&local_100,0);
      type_warn_qualifiers_on_reference(&value_base[1].ptr_op,pcVar21,&pcVar40->mods);
      lVar45 = g_enum_value;
      break;
    case 300:
      local_14c.bits = pcVar14[-1].words[0];
      local_14c.based = *(void **)((int)pcVar14 + -0x24);
      qualified_name_record_init(&value_base[1].ptr_op,pcVar14->qualified,&local_14c,&pcVar40->mods)
      ;
      lVar45 = g_enum_value;
      break;
    case 0x12e:
      if (((g_block_depth != '\0') && (g_class_depth < 0)) &&
         ((g_compile_flags_c8 & 0x10000000) == 0)) {
        if ((((g_compile_flags_c8 & 0x40000000) != 0) && ((g_compile_flags_cc & 8) == 0)) &&
           ((g_compile_flags_c4 & 0x200) == 0)) {
          iVar12 = yyparse_cpp_ellipsis_parameter_arena0
                             (value_base,parser,state_sp,saved_lookahead,iVar12);
          return iVar12;
        }
        if ((g_compile_flags_cc & 0x50) == 0) {
          iVar22 = 4;
          goto LAB_104225ad;
        }
      }
      iVar22 = 0;
      goto LAB_104225ad;
    case 0x12f:
      if (((((g_block_depth == '\0') || (-1 < g_class_depth)) ||
           ((g_compile_flags_c8 & 0x10000000) != 0)) ||
          ((((g_compile_flags_c8 & 0x40000000) != 0 && ((g_compile_flags_cc & 8) == 0)) &&
           ((g_compile_flags_c4 & 0x200) == 0)))) || ((g_compile_flags_cc & 0x50) != 0)) {
        iVar22 = 0;
      }
      else {
        iVar22 = 4;
      }
LAB_104225ad:
      pcVar31 = sym_new_of_kind('\v',g_name_ellipsis,iVar22);
      value_base[1].sym = pcVar31;
      pcVar32 = type_intern_basic_parts(0x80d,0,0);
      (value_base[1].sym)->type = pcVar32;
      sym_mark_ellipsis_parameter(value_base[1].sym);
      lVar45 = g_enum_value;
      break;
    case 0x130:
      if ((g_opt_Zg == '\0') && ((g_compile_flags_c4 & 0x800000) == 0)) {
        if ((pcVar40->spec).spec[0] != 0xaa) {
          func_begin_compound_statement();
        }
        g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfc;
        il_emit_line_record_24();
        lVar45 = g_enum_value;
      }
      else {
        lex_skip_to_closing_brace('\0');
        lVar45 = g_enum_value;
      }
      break;
    case 0x131:
      if ((g_opt_Zg == '\0') && ((g_compile_flags_c4 & 0x800000) == 0)) {
        if (pcVar14[-1].spec.spec[0] != 0xaa) {
          scope_end_block();
          lVar45 = g_enum_value;
        }
      }
      else {
        g_compile_flags_c4 = g_compile_flags_c4 & 0xff7fffff;
      }
      break;
    case 0x135:
      g_compile_flags_c4 = g_compile_flags_c4 & 0xfffffffe;
      if (g_yy_lookahead == (byte *)0x0) {
        bVar11 = g_paren_level_flags[g_paren_depth];
        g_pending_access_check[g_paren_depth] = (c1_symbol *)0x0;
        g_paren_level_flags[iVar22] = bVar11 & 0xfc;
        lVar45 = g_enum_value;
      }
      break;
    case 0x136:
    case 0x165:
      value_base[1].spec.spec[0] = '\0';
      lVar45 = g_enum_value;
      break;
    case 0x137:
    case 0x176:
    case 0x1ed:
      value_base[1].spec.spec[0] = '\x01';
      lVar45 = g_enum_value;
      break;
    case 0x138:
      pcVar24 = pcVar14->node;
      if (pcVar24 != (c1_node *)0x0) {
        if (pcVar24->op == 0xe8) {
          pcVar24 = property_build_access('t',pcVar24,(c1_node *)0x0);
          pcVar14->node = pcVar24;
        }
        cVar9 = '\x01';
        pcVar24 = expr_resolve_address_of_overload(pcVar14->node);
        pcVar24 = expr_warn_no_effect(pcVar24,cVar9);
        pcVar14->node = pcVar24;
        pcVar24 = expr_full_expression_guarded(pcVar24,2);
        stmt_emit_expression(pcVar24);
      }
      iVar22 = parse_error_recovery_count();
      if (iVar22 != 0) goto LAB_10422a54;
      arena_reset(5);
      g_string_literal_cur = &g_string_literal_buffer;
      lVar45 = g_enum_value;
      break;
    case 0x13b:
      func_end_compound_statement(pcVar14->node,'\0');
      label_emit_definition(pcVar14->node);
      stmt_if_then_end_flow_state(1);
      func_end_compound_statement((c1_node *)0x0,'\x01');
      lVar45 = g_enum_value;
      if ((pcVar40->spec).spec[0] != '\0') {
        diag_warning(3,0x186);
        lVar45 = g_enum_value;
      }
      break;
    case 0x13c:
      func_end_compound_statement(pcVar14->node,'\0');
      label_emit_definition(pcVar14->node);
      stmt_else_end_flow_state();
      func_end_compound_statement((c1_node *)0x0,'\x01');
      lVar45 = g_enum_value;
      break;
    case 0x13d:
      stmt_while_end_flow_state();
      stmt_loop_end();
      func_end_compound_statement((c1_node *)0x0,(pcVar14->spec).spec[0]);
      lVar45 = g_enum_value;
      break;
    case 0x13e:
      if (g_ms_extensions != '\0') {
        func_end_compound_statement((c1_node *)0x0,(pcVar14->spec).spec[0]);
        stmt_for_end_flow_state();
      }
      stmt_loop_end();
      lVar45 = g_enum_value;
      if (g_ms_extensions == '\0') {
        stmt_for_end_flow_state();
        func_end_compound_statement((c1_node *)0x0,(pcVar14->spec).spec[0]);
        lVar45 = g_enum_value;
      }
      break;
    case 0x13f:
      func_flow_state_note_1f();
      stmt_do_head();
      g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfc;
      cVar10 = parse_begin_compound_value((c1_node *)0x0);
      (pcVar40->spec).spec[0] = cVar10;
      lVar45 = g_enum_value;
      break;
    case 0x140:
      func_end_compound_statement((c1_node *)0x0,pcVar14[-3].spec.spec[0]);
      func_flow_state_note_22();
      g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] | 3;
      lVar45 = g_enum_value;
      break;
    case 0x141:
      label_emit_definition(g_continue_label_stack->label);
      if (pcVar14[-1].node != (c1_node *)0x0) {
        pcVar24 = expr_resolve_address_of_overload(pcVar14[-1].node);
        pcVar14[-1].node = pcVar24;
        pcVar24 = stmt_check_controlling_expression(pcVar24,0);
        pcVar14[-1].node = pcVar24;
        stmt_emit_condition(pcVar24,g_loop_top_label_stack->label,1);
      }
      il_emit_line_record_24();
      label_emit_definition(*(c1_node **)((int)g_break_label_stack + 4));
      g_loop_top_label_stack = g_loop_top_label_stack->next;
      g_continue_label_stack = g_continue_label_stack->next;
      g_break_label_stack = *(void **)g_break_label_stack;
      g_loop_label_count = g_loop_label_count + -3;
      if (g_loop_label_count == 0) {
        arena_reset(6);
      }
      iVar22 = parse_error_recovery_count();
      if (iVar22 == 0) {
        arena_reset(5);
      }
      g_string_literal_cur = &g_string_literal_buffer;
      stmt_do_end_flow_state();
      parse_paren_depth_pop();
      lVar45 = g_enum_value;
      break;
    case 0x142:
      il_emit_line_record_24();
      il_emit_tuple(0x3a,*(node **)((int)g_break_label_stack + 4));
      stmt_switch_end();
      stmt_warn_switch_without_cases();
      func_end_compound_statement((c1_node *)0x0,(pcVar14->spec).spec[0]);
      g_loop_top_label_stack = g_loop_top_label_stack->next;
      g_break_label_stack = *(void **)g_break_label_stack;
      g_switch_case_stack = g_switch_case_stack->next;
      g_default_label_stack = g_default_label_stack->next;
      g_loop_label_count = g_loop_label_count + -4;
      lVar45 = g_enum_value;
      if (g_loop_label_count == 0) {
        arena_reset(6);
        lVar45 = g_enum_value;
      }
      break;
    case 0x143:
      eh_check_leave();
      lVar45 = g_enum_value;
      break;
    case 0x144:
      if (g_break_label_stack == (void *)0x0) {
        diag_error(0x2b);
        lVar45 = g_enum_value;
      }
      else {
        stmt_jump_flow_state();
        il_emit_tuple(0x3a,*(node **)((int)g_break_label_stack + 4));
        lVar45 = g_enum_value;
      }
      break;
    case 0x145:
      if (g_continue_label_stack == (c1xx_label_cell *)0x0) {
        diag_error(0x2c);
        lVar45 = g_enum_value;
      }
      else {
        stmt_jump_flow_state_2();
        il_emit_tuple(0x3a,g_continue_label_stack->label);
        lVar45 = g_enum_value;
      }
      break;
    case 0x146:
      func_flow_state_note_8();
      stmt_emit_return_value((c1_node *)0x0,1);
      lVar45 = g_enum_value;
      break;
    case 0x147:
      func_flow_state_note_8();
      lVar45 = g_enum_value;
      break;
    case 0x148:
      pcVar24 = pcVar14->node;
      if ((pcVar24 != (c1_node *)0x0) && (pcVar24->op == 0xe8)) {
        pcVar24 = property_build_access('\x01',pcVar24,(c1_node *)0x0);
        pcVar14->node = pcVar24;
      }
      pcVar24 = expr_resolve_address_of_overload(pcVar14->node);
      pcVar14->node = pcVar24;
      stmt_emit_return_value(pcVar24,2);
      iVar22 = parse_error_recovery_count();
      if (iVar22 != 0) goto LAB_10422a54;
      arena_reset(5);
      g_string_literal_cur = &g_string_literal_buffer;
      lVar45 = g_enum_value;
      break;
    case 0x149:
      pcVar31 = (c1_symbol *)label_find_in_function(pcVar14->words[0]);
      if (pcVar31 == (c1_symbol *)0x0) {
        pcVar31 = (c1_symbol *)label_new_user(pcVar14->words[0]);
        label_register(pcVar31);
        stmt_goto_flow_state(pcVar31,0);
      }
      else {
        stmt_goto_flow_state(pcVar31,1);
      }
      pcVar24 = tree_new_symbol_ref(pcVar31,'\0');
      il_emit_tuple(0x3a,pcVar24);
      iVar22 = parse_error_recovery_count();
      if (iVar22 == 0) {
        arena_reset(5);
      }
LAB_10422a54:
      g_string_literal_cur = &g_string_literal_buffer;
      lVar45 = g_enum_value;
      break;
    case 0x14a:
      il_emit_line_record_24();
      asm_block_emit();
      lVar45 = g_enum_value;
      break;
    case 0x14b:
      eh_except_end();
      lVar45 = g_enum_value;
      break;
    case 0x14c:
      eh_finally_begin();
      lVar45 = g_enum_value;
      break;
    case 0x14d:
      eh_finally_end();
      lVar45 = g_enum_value;
      break;
    case 0x14f:
      diag_error(0xb5);
      lVar45 = g_enum_value;
      break;
    case 0x152:
      goto switchD_10421905_caseD_14f;
    case 0x153:
      parse_yyerrok(parser);
      g_yy_lookahead = (byte *)0x0;
      uVar56 = 0x7b;
LAB_1046653f:
      pcVar26 = token_static_for_code(uVar56);
      token_source_unget((c1_token_reader *)&g_token_position,pcVar26);
      lVar45 = g_enum_value;
      break;
    case 0x154:
      if (g_yy_lookahead == (byte *)0x0) {
        g_yy_lookahead = yylex_cpp();
        if (g_yy_lookahead == (byte *)0x0) {
          diag_fatal(1);
        }
      }
      cVar10 = lex_token_code((c1xx_token *)g_yy_lookahead);
      if (cVar10 != 'u') {
        diag_error(0x13f);
      }
      eh_check_handling_enabled();
      lVar45 = g_enum_value;
      break;
    case 0x155:
      pending_top_mark();
      lVar45 = g_enum_value;
      break;
    case 0x156:
      eh_check_try_has_catch();
      lVar45 = g_enum_value;
      break;
    case 0x159:
      if (g_yy_lookahead == (byte *)0x0) {
        g_yy_lookahead = yylex_cpp();
        if (g_yy_lookahead == (byte *)0x0) {
          diag_fatal(1);
        }
      }
      cVar10 = lex_token_code((c1xx_token *)g_yy_lookahead);
      if (cVar10 != 'u') {
        diag_error(0x13f);
        lVar45 = g_enum_value;
        break;
      }
      lVar45 = g_enum_value;
      if ((pcVar40->spec).spec[0] == '\0') break;
      g_yylval = CONCAT31(g_yylval._1_3_,0xaa);
      pcVar28 = arena_or_pool_alloc(0x30,4);
      if (pcVar28 != (c1_u8 *)0x0) {
        g_yy_lookahead = token_init(pcVar28,'u',&g_yylval);
        lVar45 = g_enum_value;
        break;
      }
      goto LAB_104671eb;
    case 0x15a:
      scope_end_and_flush_pending_top(pcVar14[-1].spec.spec[0]);
      lVar45 = g_enum_value;
      break;
    case 0x15b:
      decl_pop_declarator_state(pcVar40->params);
      cVar10 = eh_check_catch_type_count(pcVar40->params);
      value_base[1].spec.spec[0] = cVar10;
      vtable_nop();
      lVar45 = g_enum_value;
      break;
    case 0x15c:
      diag_error(0x135);
      lVar45 = g_enum_value;
switchD_10421905_caseD_14f:
      g_enum_value = lVar45;
      parse_yyerrok(parser);
LAB_104671eb:
      g_yy_lookahead = (byte *)0x0;
      lVar45 = g_enum_value;
      break;
    case 0x15f:
      parse_paren_depth_pop();
      value_base[1].words[0] = 1;
      lVar45 = g_enum_value;
      break;
    case 0x160:
      parse_paren_depth_pop();
      value_base[1].words[0] = 2;
      lVar45 = g_enum_value;
      break;
    case 0x161:
      eh_try_begin();
      lVar45 = g_enum_value;
      break;
    case 0x162:
      eh_try_block_end();
      lVar45 = g_enum_value;
      break;
    case 0x163:
      eh_except_filter_begin();
      lVar45 = g_enum_value;
      break;
    case 0x164:
      eh_except_emit_filter(pcVar14->node);
      eh_except_filter_end();
      parse_paren_depth_pop();
      lVar45 = g_enum_value;
      break;
    case 0x169:
      expr_warn_no_effect(pcVar40->node,'\0');
      lVar45 = g_enum_value;
      break;
    case 0x16a:
      pcVar33 = (c1_declarator *)0x0;
      g_pending_access_check[g_paren_depth] = (c1_symbol *)0x0;
      if (pcVar40->declarator != (c1_declarator *)0x0) {
        pcVar31 = decl_declarator_symbol(pcVar40->declarator);
        if (pcVar31 != (c1_symbol *)0x0) {
          pcVar31 = decl_declarator_symbol(pcVar40->declarator);
          pvVar23 = (void *)sym_name(pcVar31);
          pcVar24 = expr_lookup_name_expression(pvVar23);
          value_base[1].node = pcVar24;
          lVar45 = g_enum_value;
          break;
        }
      }
      goto LAB_10467c7c;
    case 0x16b:
      g_case_label = (c1_node *)0x0;
      break;
    case 0x16d:
      stmt_define_label(pcVar14->words[0]);
      lVar45 = g_enum_value;
      break;
    case 0x16e:
      if ((pcVar14[-1].node == (c1_node *)0x0) ||
         (g_switch_case_stack == (c1_switch_cases_cell *)0x0)) {
        diag_error(0x2e);
        lVar45 = g_enum_value;
      }
      else {
        pcVar24 = expr_resolve_address_of_overload(pcVar14[-1].node);
        stmt_case_label(pcVar24);
        lVar45 = g_enum_value;
      }
      break;
    case 0x16f:
      if (g_default_label_stack == (c1xx_label_cell *)0x0) {
        diag_error(0x2f);
        lVar45 = g_enum_value;
      }
      else if (g_default_label_stack->label == (c1_node *)0x0) {
        if (g_case_label == (c1_node *)0x0) {
          pcVar24 = label_new(0x14);
          g_default_label_stack->label = pcVar24;
          g_case_label = g_default_label_stack->label;
          label_emit_definition(g_default_label_stack->label);
          stmt_default_label_flow_state();
          lVar45 = g_enum_value;
        }
        else {
          g_default_label_stack->label = g_case_label;
          stmt_default_label_flow_state();
          lVar45 = g_enum_value;
        }
      }
      else {
        diag_error(0x30);
        lVar45 = g_enum_value;
      }
      break;
    case 0x170:
      parse_begin_compound_value(pcVar14->node);
      value_base[1].words[0] = pcVar14->words[0];
      lVar45 = g_enum_value;
      break;
    case 0x171:
      parse_begin_compound_value((c1_node *)0x0);
      g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] | 0x80;
      func_flow_state_note_11();
      lVar45 = g_enum_value;
      break;
    case 0x172:
      pcVar24 = label_new(0x1e);
      value_base[1].node = pcVar24;
      if (pcVar14->node != (c1_node *)0x0) {
        pcVar24 = expr_resolve_address_of_overload(pcVar14->node);
        pcVar14->node = pcVar24;
        pcVar24 = stmt_check_controlling_expression(pcVar24,0);
        pcVar14->node = pcVar24;
        stmt_emit_condition(pcVar24,value_base[1].node,0);
      }
      stmt_if_then_begin_flow_state();
      parse_paren_depth_pop();
      g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfe;
      lVar45 = g_enum_value;
      break;
    case 0x173:
      func_end_compound_statement(pcVar14[-1].node,'\0');
      stmt_else_begin_flow_state();
      pcVar24 = label_new(0x1e);
      il_emit_tuple(0x3a,pcVar24);
      label_emit_definition(pcVar14[-1].node);
      il_emit_line_record_24();
      g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfe;
      acStackY_1a8[1] = 0x10422c59;
      parse_begin_compound_value(pcVar24);
      value_base[1].node = pcVar24;
      lVar45 = g_enum_value;
      break;
    case 0x177:
      value_base[1].spec.spec[0] = (pcVar40->spec).spec[0];
      lVar45 = g_enum_value;
      break;
    case 0x178:
      if (g_ms_extensions == '\0') {
        cVar10 = parse_begin_compound_value((c1_node *)0x0);
        (pcVar40->spec).spec[0] = cVar10;
      }
      g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] | 0x80;
      lVar45 = g_enum_value;
      break;
    case 0x179:
      if (pcVar14->node != (c1_node *)0x0) {
        cVar9 = '\x01';
        pcVar24 = expr_resolve_address_of_overload(pcVar14->node);
        pcVar24 = expr_warn_no_effect(pcVar24,cVar9);
        pcVar14->node = pcVar24;
        pcVar24 = expr_full_expression_guarded(pcVar24,2);
        stmt_emit_expression(pcVar24);
      }
      iVar22 = parse_error_recovery_count();
      if (iVar22 == 0) {
        arena_reset(5);
      }
      g_string_literal_cur = &g_string_literal_buffer;
      g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] | 2;
      func_flow_state_note_25();
      lVar45 = g_enum_value;
      break;
    case 0x17a:
      pcVar24 = stmt_check_controlling_expression(pcVar14->node,0);
      pcVar14->node = pcVar24;
      func_flow_state_note_27();
      lVar45 = g_enum_value;
      break;
    case 0x17b:
      cVar9 = '\x01';
      pcVar24 = expr_resolve_address_of_overload(pcVar14[-1].node);
      pcVar24 = expr_warn_no_effect(pcVar24,cVar9);
      pcVar14[-1].node = pcVar24;
      stmt_for_head((c1_node *)0x0,pcVar14[-4].node,pcVar24);
      if ((pcVar14->spec).spec[0] != '\0') {
        diag_error(0x3b);
      }
      parse_paren_depth_pop();
      g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfc;
      func_flow_state_note_2a();
      lVar45 = g_enum_value;
      if (g_ms_extensions != '\0') {
        cVar10 = parse_begin_compound_value((c1_node *)0x0);
        pcVar14[-9].spec.spec[0] = cVar10;
        lVar45 = g_enum_value;
      }
      break;
    case 0x17c:
      cVar10 = parse_begin_compound_value((c1_node *)0x0);
      (pcVar40->spec).spec[0] = cVar10;
      g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] | 0x80;
      func_flow_state_note_19();
      stmt_while_head();
      lVar45 = g_enum_value;
      break;
    case 0x17d:
      cVar9 = '\0';
      pcVar24 = expr_resolve_address_of_overload(pcVar14->node);
      pcVar24 = expr_warn_no_effect(pcVar24,cVar9);
      pcVar14->node = pcVar24;
      pcVar24 = stmt_check_controlling_expression(pcVar24,0);
      pcVar14->node = pcVar24;
      stmt_emit_loop_test(pcVar24);
      parse_paren_depth_pop();
      g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfe;
      func_flow_state_note_1c();
      lVar45 = g_enum_value;
      break;
    case 0x17e:
      cVar10 = parse_begin_compound_value((c1_node *)0x0);
      (pcVar40->spec).spec[0] = cVar10;
      func_flow_state_note_31();
      lVar45 = g_enum_value;
    case 0x1b0:
      g_enum_value = lVar45;
      g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] | 3;
      lVar45 = g_enum_value;
      break;
    case 0x180:
      pcVar24 = expr_resolve_address_of_overload(pcVar14[-2].node);
      stmt_switch_head((int)pcVar24);
      lVar45 = g_enum_value;
switchD_10421905_caseD_6f:
      g_enum_value = lVar45;
      g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfc;
      lVar45 = g_enum_value;
      break;
    case 0x181:
      cVar9 = '\0';
      pcVar24 = expr_resolve_address_of_overload(pcVar40->node);
      pcVar24 = expr_warn_no_effect(pcVar24,cVar9);
      cVar47 = (c1_decl_modifier)expr_eval_constant_expression(pcVar24);
      value_base[1].mods = cVar47;
      lVar45 = g_enum_value;
      break;
    case 0x183:
      cVar9 = '\0';
      pcVar24 = expr_resolve_address_of_overload(pcVar40->node);
      pcVar24 = expr_warn_no_effect(pcVar24,cVar9);
      value_base[1].node = pcVar24;
      lVar45 = g_enum_value;
      break;
    case 0x184:
    case 0x19a:
      pcVar24 = expr_build_binary((pcVar14->spec).spec[0],pcVar14[-1].node,pcVar40->node);
      value_base[1].node = pcVar24;
      lVar45 = g_enum_value;
      break;
    case 0x185:
      pcVar24 = expr_build_zero_pair();
      value_base[1].node = pcVar24;
      lVar45 = g_enum_value;
      break;
    case 0x186:
      pcVar24 = expr_build_throw(pcVar40->node);
      value_base[1].node = pcVar24;
      lVar45 = g_enum_value;
      break;
    case 0x187:
      if ((pcVar14[-1].declarator != (c1_declarator *)0x0) &&
         (pcVar24 = pcVar40->node, pcVar24 != (c1_node *)0x0)) {
        pcVar32 = decl_declarator_record(pcVar14[-1].declarator);
        pcVar24 = expr_resolve_function_address(pcVar32,pcVar24);
joined_r0x104676a9:
        if (pcVar24 == (c1_node *)0x0) {
          expr_report_function_operand('4',pcVar40->node);
        }
        goto LAB_10422ec5;
      }
      goto switchD_10421905_caseD_24;
    case 0x188:
      if ((pcVar14[-1].declarator != (c1_declarator *)0x0) &&
         (pcVar24 = pcVar40->node, pcVar24 != (c1_node *)0x0)) {
        pcVar32 = decl_declarator_record(pcVar14[-1].declarator);
        pcVar24 = expr_resolve_function_address(pcVar32,pcVar24);
        goto joined_r0x104676a9;
      }
      goto switchD_10421905_caseD_24;
    case 0x189:
    case 399:
    case 400:
    case 0x191:
    case 0x192:
    case 0x193:
    case 0x194:
    case 0x195:
    case 0x196:
    case 0x197:
    case 0x198:
      pcVar24 = pcVar40->node;
LAB_10422ec5:
      pcVar24 = expr_build_binary((pcVar14->spec).spec[0],pcVar14[-1].node,pcVar24);
      value_base[1].node = pcVar24;
      lVar45 = g_enum_value;
      break;
    case 0x18a:
      pcVar24 = expr_build_conditional(pcVar14[-3].node,pcVar14[-1].node,pcVar40->node);
      value_base[1].node = pcVar24;
      lVar45 = g_enum_value;
      break;
    case 0x18b:
    case 0x18d:
      if (pcVar14->words[0] != 0) {
        func_flow_state_note_3e();
        lVar45 = g_enum_value;
      }
      break;
    case 0x18c:
    case 0x18e:
      pcVar24 = expr_build_binary(pcVar14[-1].spec.spec[0],pcVar14[-2].node,pcVar40->node);
      value_base[1].node = pcVar24;
      lVar45 = g_enum_value;
      break;
    case 0x199:
      pcVar24 = expr_check_based_operator(pcVar14[-1].node,pcVar40->node);
      value_base[1].node = pcVar24;
      lVar45 = g_enum_value;
      break;
    case 0x19d:
      g_compile_flags_c8 = g_compile_flags_c8 | 1;
      pcVar24 = pcVar40->node;
      cVar29 = pcVar14->words[0];
      uVar49 = (undefined1)cVar29;
      uVar51 = (undefined1)(cVar29 >> 8);
      uVar41 = (undefined2)(cVar29 >> 0x10);
      cVar10 = 'd';
LAB_10422f46:
      g_enum_value = lVar45;
      pcVar24 = expr_build_cast(cVar10,(c1_symbol *)CONCAT22(uVar41,CONCAT11(uVar51,uVar49)),pcVar24
                               );
      value_base[1].node = pcVar24;
      g_compile_flags_c8 = g_compile_flags_c8 & 0xfffffffe;
      tree_clear_value_link(value_base[1].node);
      lVar45 = g_enum_value;
      break;
    case 0x19e:
      goto switchD_10421905_caseD_19b;
    case 0x19f:
      (pcVar14->spec).spec[0] = ((pcVar14->spec).spec[0] == '@') + 'T';
      pcVar24 = tree_new_int_constant(1);
      pcVar24 = expr_build_binary((pcVar14->spec).spec[0],pcVar40->node,pcVar24);
      value_base[1].node = pcVar24;
      lVar45 = g_enum_value;
      break;
    case 0x1a0:
      cVar29 = expr_build_unary(0x3d,pcVar40->node);
      value_base[1].words[0] = cVar29;
      lVar45 = g_enum_value;
      break;
    case 0x1a1:
      pcVar31 = pcVar40->sym;
      if (pcVar31 == (c1_symbol *)0x0) {
        value_base[1].words[0] = 0;
        lVar45 = g_enum_value;
      }
      else if ((pcVar31->kind == '=') && ((c1_symbol *)pcVar31->type != (c1_symbol *)0x0)) {
        pcVar24 = expr_address_of_member((c1_symbol *)pcVar31->type);
        value_base[1].node = pcVar24;
        lVar45 = g_enum_value;
      }
      else {
        if ((pcVar31->kind == 'S') && ((((c1_node *)pcVar31->type)->kind & 7) == 4)) {
          iVar12 = yyparse_cpp_address_of_member_leaf
                             ((c1_node *)pcVar31->type,value_base,pcVar40,parser,state_sp,
                              saved_lookahead,iVar12);
          return iVar12;
        }
        g_compile_flags_c8 = g_compile_flags_c8 | 4;
        cVar29 = expr_build_unary(0x31,pcVar40->node);
        value_base[1].words[0] = cVar29;
        g_compile_flags_c8 = g_compile_flags_c8 & 0xfffffffb;
        lVar45 = g_enum_value;
      }
      break;
    case 0x1a2:
      pcVar24 = (c1_node *)expr_build_unary(0x86,pcVar40->node);
      value_base[1].node = pcVar24;
      tree_clear_value_link(pcVar24);
      lVar45 = g_enum_value;
      break;
    case 0x1a3:
      cVar29 = expr_build_unary(0x5a,pcVar40->node);
      value_base[1].words[0] = cVar29;
      lVar45 = g_enum_value;
      break;
    case 0x1a4:
      cVar29 = expr_build_unary(0x3c,pcVar40->node);
      value_base[1].words[0] = cVar29;
      lVar45 = g_enum_value;
      break;
    case 0x1a6:
      cVar29 = expr_build_unary(0x59,pcVar40->node);
      value_base[1].words[0] = cVar29;
      lVar45 = g_enum_value;
      break;
    case 0x1a7:
      (*g_idb->vtbl->idb_note_sizeof)(g_idb);
      if (pcVar40->node == (c1_node *)0x0) {
        value_base[1].words[0] = 0;
        g_sizeof_depth = g_sizeof_depth + -1;
        lVar45 = g_enum_value;
      }
      else {
        pcVar24 = expr_build_sizeof(pcVar40->node);
        value_base[1].node = pcVar24;
        g_sizeof_depth = g_sizeof_depth + -1;
        lVar45 = g_enum_value;
      }
      break;
    case 0x1a8:
      (*g_idb->vtbl->idb_note_sizeof)(g_idb);
      pcVar24 = expr_sizeof_type(pcVar40->sym->type);
      value_base[1].node = pcVar24;
      g_sizeof_depth = g_sizeof_depth + -1;
      lVar45 = g_enum_value;
      break;
    case 0x1ad:
      cVar29 = expr_build_unary(0xf0,pcVar14->node);
      value_base[1].words[0] = cVar29;
      parse_paren_depth_pop();
      lVar45 = g_enum_value;
      break;
    case 0x1af:
      g_member_access_op = '\x01';
      if ((pcVar14->node != (c1_node *)0x0) && (pcVar14->node->op == '7')) {
        diag_warning(4,0x2c5);
      }
      pcVar24 = expr_build_binary(pcVar14[-1].spec.spec[0],pcVar14[-2].node,pcVar14->node);
      value_base[1].node = pcVar24;
      lVar45 = g_enum_value;
      break;
    case 0x1b1:
      pcVar24 = pcVar14[-1].node;
      if ((pcVar24 != (c1_node *)0x0) && ((pcVar24->kind & 0x88) == 0)) {
        if ((g_compile_flags_c8 & 0x800000) != 0) {
          if (pcVar40->node != (c1_node *)0x0) {
            diag_error(0x209);
            pcVar24 = tree_new_zero_flagged();
          }
          value_base[1].node = pcVar24;
          g_compile_flags_c8 = g_compile_flags_c8 & 0xff7fffff;
          g_member_access_op = '\x01';
          lVar45 = g_enum_value;
          break;
        }
        pcVar24 = (c1_node *)expr_build_call(pcVar24,pcVar40->node);
      }
      value_base[1].node = pcVar24;
      lVar45 = g_enum_value;
switchD_10421905_caseD_19b:
      g_member_access_op = '\x01';
      break;
    case 0x1b4:
      g_member_access_op = '\x01';
      pcVar24 = tree_new_int_constant(1);
      pcVar24 = expr_build_binary((pcVar40->spec).spec[0],pcVar14->node,pcVar24);
      value_base[1].node = pcVar24;
      lVar45 = g_enum_value;
      break;
    case 0x1b5:
      g_member_access_op = '\x01';
      pcVar24 = class_check_operator_global_form
                          (CONCAT22((short)((uint)g_yy_lookahead >> 0x10),
                                    CONCAT11((char)((uint)g_yy_lookahead >> 8),
                                             (pcVar14->spec).spec[0])),pcVar40->node);
      value_base[1].node = pcVar24;
      lVar45 = g_enum_value;
      break;
    case 0x1b6:
      if ((pcVar40->spec).spec[0] != 'D') {
        diag_error(0x2f8);
      }
      parse_paren_depth_push(1);
      lVar45 = g_enum_value;
      break;
    case 0x1b7:
      if ((pcVar40->spec).spec[0] != 0xbf) {
        iVar12 = yyparse_cpp_named_cast_expected_gt
                           ((pcVar40->spec).spec[0],value_base,parser,state_sp,saved_lookahead,
                            iVar12);
        return iVar12;
      }
      goto LAB_104232f5;
    case 0x1b8:
      if (pcVar40->words[0] != 0) {
        g_compile_flags_c8 = g_compile_flags_c8 | 1;
        pcVar24 = pcVar40->node;
        pcVar31 = parse_type_id_declarator(pcVar14[-2].declarator,&pcVar14[-3].spec);
        uVar49 = SUB41(pcVar31,0);
        uVar51 = (undefined1)((uint)pcVar31 >> 8);
        uVar41 = (undefined2)((uint)pcVar31 >> 0x10);
        cVar10 = pcVar14[-6].spec.spec[0];
        lVar45 = g_enum_value;
        goto LAB_10422f46;
      }
switchD_10421905_caseD_24:
      g_enum_value = lVar45;
      value_base[1].words[0] = 0;
      lVar45 = g_enum_value;
      break;
    case 0x1b9:
      pcVar24 = expr_build_typeid_expression(pcVar14->node);
      value_base[1].node = pcVar24;
      parse_paren_depth_pop();
      lVar45 = g_enum_value;
      break;
    case 0x1ba:
      pcVar31 = (c1_symbol *)
                decl_finish_declarator_then_type(pcVar14->ptr,(byte *)pcVar14[-1].words);
      goto LAB_104232f2;
    case 0x1bb:
      pcVar24 = expr_build_uuidof_expression(pcVar14->node);
      value_base[1].node = pcVar24;
      parse_paren_depth_pop();
      lVar45 = g_enum_value;
      break;
    case 0x1bc:
      pcVar31 = decl_finish_declarator_uuidof(pcVar14->ptr,(byte *)pcVar14[-1].words);
      goto LAB_104232f2;
    case 0x1bd:
      parse_paren_depth_pop();
      value_base[1].words[0] = pcVar14->words[0];
      lVar45 = g_enum_value;
      break;
    case 0x1be:
      value_base[1].words[0] = 0;
      parse_report_inserted_token(g_yy_lookahead,0x76);
      lVar45 = g_enum_value;
      break;
    case 0x1bf:
      pcVar24 = tree_new_constant(pcVar40->type,(void *)((int)pcVar14 + 0x30),g_expr_arena_index);
      value_base[1].node = pcVar24;
      lVar45 = g_enum_value;
      break;
    case 0x1c1:
      type_string_literal_array(pcVar40->node);
      lVar45 = g_enum_value;
      break;
    case 0x1c2:
      pcVar24 = expr_check_this_usage();
      value_base[1].node = pcVar24;
      lVar45 = g_enum_value;
      break;
    case 0x1c3:
      pcVar24 = expr_build_builtin_unary(0x76,pcVar14->node);
      value_base[1].node = pcVar24;
      tree_clear_value_link(pcVar24);
      parse_paren_depth_pop();
      lVar45 = g_enum_value;
      break;
    case 0x1c5:
      PTR_104d2158 = expr_prepare_member_access_object
                               (g_current_scope,(pcVar40->spec).spec[0],pcVar14->node,'\0');
      g_member_access_op = (pcVar40->spec).spec[0];
      lVar45 = g_enum_value;
      break;
    case 0x1c6:
      pcVar24 = expr_build_member_access(g_member_access_op,PTR_104d2158,pcVar40->node);
      value_base[1].node = pcVar24;
      lVar45 = g_enum_value;
      break;
    case 0x1c7:
      pcVar24 = expr_build_pseudo_destructor_call(g_member_access_op,PTR_104d2158,pcVar40->words[0])
      ;
      value_base[1].node = pcVar24;
      lVar45 = g_enum_value;
      break;
    case 0x1c8:
      pcVar31 = value_word0(pcVar40->cell);
      pcVar24 = expr_build_pseudo_destructor_call(g_member_access_op,PTR_104d2158,(int)pcVar31);
      value_base[1].node = pcVar24;
      lVar45 = g_enum_value;
      break;
    case 0x1c9:
      pfVar30 = sym_name_of_ref(pcVar40->cell);
      pcVar24 = expr_build_pseudo_destructor_call(g_member_access_op,PTR_104d2158,(int)pfVar30);
      value_base[1].node = pcVar24;
      lVar45 = g_enum_value;
      break;
    case 0x1ca:
      pcVar24 = expr_check_qualified_pseudo_destructor
                          (g_member_access_op,PTR_104d2158,&pcVar14[-2].spec,&pcVar40->spec);
      value_base[1].node = pcVar24;
      lVar45 = g_enum_value;
      break;
    case 0x1cb:
      pcVar24 = expr_lookup_name_expression(pcVar40->ptr);
      value_base[1].node = pcVar24;
      lVar45 = g_enum_value;
      break;
    case 0x1cc:
      pvVar23 = decl_declarator_record(pcVar40->declarator);
      if (pvVar23 == (void *)0x0) {
        pcVar31 = (c1_symbol *)sym_name(pcVar40->sym);
        pcVar24 = sym_is_data_or_function(pcVar31);
        value_base[1].node = pcVar24;
        lVar45 = g_enum_value;
      }
      else {
        pcVar31 = (c1_symbol *)sym_name(pcVar40->sym);
        pcVar24 = sym_is_data_or_function(pcVar31);
        if (pcVar24->right != (void *)0x0) {
          diag_fatal(1);
        }
        pvVar23 = value_fieldc(pcVar40->ptr);
        pcVar24->right = pvVar23;
        value_base[1].node = pcVar24;
        lVar45 = g_enum_value;
      }
      break;
    case 0x1cd:
      pcVar31 = value_word0(pcVar40->cell);
      pcVar24 = sym_is_data_or_function(pcVar31);
      value_base[1].node = pcVar24;
      lVar45 = g_enum_value;
      break;
    case 0x1ce:
      pcVar24 = expr_lookup_name_expression(*(void **)((int)pcVar14 + 0x2c));
      value_base[1].node = pcVar24;
      lVar45 = g_enum_value;
      break;
    case 0x1cf:
      pfVar30 = decl_conversion_function_name(*(c1_type **)((int)pcVar14 + 0x40));
      pcVar24 = expr_lookup_name_expression(pfVar30);
      value_base[1].node = pcVar24;
      g_compile_flags_c4 = g_compile_flags_c4 & 0xfffffffb;
      lVar45 = g_enum_value;
      break;
    case 0x1d0:
      pcVar31 = value_word0(pcVar40->cell);
      lVar45 = g_enum_value;
      if ((pcVar31->flags3 & 4) != 0) goto switchD_10421905_caseD_24;
      pcVar31 = value_word0(pcVar40->cell);
      pcVar24 = sym_is_data_or_function(pcVar31);
      pvVar23 = decl_declarator_record(pcVar40->declarator);
      if (pvVar23 != (void *)0x0) {
        if (pcVar24->right != (void *)0x0) {
          diag_fatal(1);
        }
        pvVar23 = decl_declarator_record(pcVar40->declarator);
        pcVar24->right = pvVar23;
      }
      value_base[1].node = pcVar24;
      lVar45 = g_enum_value;
      break;
    case 0x1d1:
      if (pcVar14->cell != (c1_symbol **)0x0) {
        pcVar32 = *(c1_type **)((int)pcVar14 + 0x40);
        pcVar31 = value_word0(pcVar14->cell);
        decl_qualified_conversion_function_name(pcVar31,pcVar32);
        pcVar31 = value_word0(pcVar14->cell);
        pcVar24 = sym_is_data_or_function(pcVar31);
        pvVar23 = decl_declarator_record(pcVar14->declarator);
        if (pvVar23 != (void *)0x0) {
          if (pcVar24->right != (void *)0x0) {
            diag_fatal(1);
          }
          pvVar23 = decl_declarator_record(pcVar14->declarator);
          pcVar24->right = pvVar23;
        }
        value_base[1].node = pcVar24;
      }
      g_compile_flags_c4 = g_compile_flags_c4 & 0xfffffffb;
      lVar45 = g_enum_value;
      break;
    case 0x1d3:
      pcVar31 = parse_type_id_declarator(pcVar14->declarator,&pcVar14[-1].spec);
LAB_104232f2:
      value_base[1].sym = pcVar31;
      lVar45 = g_enum_value;
LAB_104232f5:
      g_enum_value = lVar45;
      parse_paren_depth_pop();
LAB_104232fa:
      g_declarator_paren_base = g_declarator_paren_base + -1;
      lVar45 = g_enum_value;
      break;
    case 0x1d4:
      value_base[1].words[0] = pcVar14->words[0];
      parse_paren_depth_pop();
      lVar45 = g_enum_value;
      break;
    case 0x1d5:
    case 0x1ea:
      value_base[1].words[0] = 0;
      parse_paren_depth_pop();
      lVar45 = g_enum_value;
      break;
    case 0x1d6:
      pcVar24 = tree_append_list_item((c1_node *)0x0,pcVar40->node,0);
      value_base[1].node = pcVar24;
      lVar45 = g_enum_value;
      break;
    case 0x1d7:
      pcVar24 = tree_append_list_item(pcVar14[-1].node,pcVar40->node,0);
      value_base[1].node = pcVar24;
      lVar45 = g_enum_value;
      break;
    case 0x1d8:
      pcVar24 = arena_alloc(g_arenas + g_expr_arena_index,0x18);
      pcVar24->kind = '\x05';
      pcVar24->op = '\a';
      pcVar24->left = (void *)pcVar40->words[0];
      pcVar24->right = *(void **)((int)pcVar14 + 0x2c);
      value_base[1].node = pcVar24;
      lVar45 = g_enum_value;
      break;
    case 0x1d9:
      lex_concatenate_strings((c1_string_value *)(pcVar14->declarator->spec + 4),&pcVar40->str);
      lVar45 = g_enum_value;
      break;
    case 0x1da:
      parse_paren_depth_pop();
      g_compile_flags_c8 = g_compile_flags_c8 & 0xffffffef;
      g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] | 2;
      g_compile_flags_c4 = g_compile_flags_c4 & 0x7fffffff;
      lVar45 = g_enum_value;
      break;
    case 0x1db:
      pcVar34 = decl_declarator_record(pcVar14->declarator);
      pcVar24 = decl_record_new_array_bound(pcVar34);
      cVar29 = pcVar40->words[0];
      uVar49 = (undefined1)cVar29;
      uVar51 = (undefined1)(cVar29 >> 8);
      uVar41 = (undefined2)(cVar29 >> 0x10);
      pcVar31 = sym_new_from_declarator(pcVar14->declarator,0xffffffff);
      pcVar24 = expr_build_new_or_placeholder
                          (pcVar14[-1].spec.spec[0],0,pcVar31,
                           CONCAT22(uVar41,CONCAT11(uVar51,uVar49)),(int)pcVar24);
      value_base[1].node = pcVar24;
      lVar45 = g_enum_value;
      break;
    case 0x1dc:
      pcVar34 = decl_declarator_record(pcVar14->declarator);
      pcVar24 = decl_record_new_array_bound(pcVar34);
      cVar29 = pcVar40->words[0];
      uVar49 = (undefined1)cVar29;
      uVar51 = (undefined1)(cVar29 >> 8);
      uVar41 = (undefined2)(cVar29 >> 0x10);
      pcVar31 = sym_new_from_declarator(pcVar14->declarator,0xffffffff);
      pcVar24 = expr_build_new_or_placeholder
                          (pcVar14[-1].spec.spec[0],0,pcVar31,
                           CONCAT22(uVar41,CONCAT11(uVar51,uVar49)),(int)pcVar24);
      value_base[1].node = pcVar24;
      lVar45 = g_enum_value;
      break;
    case 0x1dd:
    case 0x1de:
      pcVar34 = decl_declarator_record(pcVar14->declarator);
      pcVar24 = decl_record_new_array_bound(pcVar34);
      cVar29 = pcVar40->words[0];
      uVar49 = (undefined1)cVar29;
      uVar51 = (undefined1)(cVar29 >> 8);
      uVar41 = (undefined2)(cVar29 >> 0x10);
      pcVar31 = sym_new_from_declarator(pcVar14->declarator,0xffffffff);
      pcVar24 = expr_build_new_or_placeholder
                          (pcVar14[-2].spec.spec[0],pcVar14[-1].words[0],pcVar31,
                           CONCAT22(uVar41,CONCAT11(uVar51,uVar49)),(int)pcVar24);
      value_base[1].node = pcVar24;
      lVar45 = g_enum_value;
      break;
    case 0x1df:
      g_compile_flags_c8 = g_compile_flags_c8 | 0x10;
      g_compile_flags_c4 = g_compile_flags_c4 | 0x80000000;
      break;
    case 0x1e0:
      g_compile_flags_c8 = g_compile_flags_c8 | 0x10;
      g_compile_flags_c4 = g_compile_flags_c4 | 0x80000000;
      parse_paren_depth_push(2);
      func_flow_state_note_43();
      lVar45 = g_enum_value;
      break;
    case 0x1e1:
      decl_set_local_key_flag(pcVar40->declarator,'\x01');
      (pcVar14->spec).spec[0] = (pcVar14->spec).spec[0] & 0x7f;
      pcVar39 = pcVar14;
      pcVar34 = decl_declarator_record(pcVar40->declarator);
      decl_check_conversion_return_type(pcVar34,&pcVar39->spec);
      pcVar34 = decl_declarator_record(pcVar40->declarator);
      decl_allow_variable_array_bound(pcVar34);
      pcVar34 = decl_declarator_record(pcVar40->declarator);
      decl_finish_declarator(pcVar34);
      decl_declarator_set_specifiers(pcVar40->declarator,&pcVar14->spec);
      decl_process_declaration(pcVar40->declarator);
      pcVar32 = (c1_type *)sym_name(pcVar40->sym);
      iVar22 = type_chain_is_cv_qualified(pcVar32);
      if ((char)iVar22 == '\0') {
        pcVar32 = (c1_type *)sym_name(pcVar40->sym);
        cVar10 = type_is_void(pcVar32);
        if (cVar10 != '\0') {
          diag_error(0x1d5);
        }
      }
      else {
        sym_name(pcVar40->sym);
        diag_error(0x1d4);
      }
      g_declarator_paren_base = g_declarator_paren_base + -1;
      g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfe;
      value_base[1].ptr = (void *)pcVar40->words[0];
      lVar45 = g_enum_value;
      break;
    case 0x1e2:
      pcVar33 = decl_declarator_alloc();
      if (pcVar33 == (c1_declarator *)0x0) {
        pcVar33 = (c1_declarator *)0x0;
      }
      else {
        pcVar33 = decl_declarator_init(pcVar33,g_name_new_target,4,(c1_overload_set *)0x0);
      }
      decl_set_local_key_flag(pcVar33,'\x01');
      pvVar23 = decl_declarator_record(pcVar40->declarator);
      d_00 = decl_declarator_record(pcVar33);
      decl_set_name(d_00,pvVar23);
      pcVar34 = decl_declarator_record(pcVar33);
      decl_finish_declarator(pcVar34);
      decl_process_declaration(pcVar33);
      g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfe;
      value_base[1].declarator = pcVar33;
      lVar45 = g_enum_value;
      break;
    case 0x1e3:
      pcVar33 = pcVar14->declarator;
      decl_set_local_key_flag(pcVar33,'\x01');
      declarator_set_kind(pcVar33,4);
      decl_set_name(pcVar33,g_name_new_target);
      pcVar40 = pcVar14 + -1;
      (pcVar40->spec).spec[0] = pcVar14[-1].spec.spec[0] & 0x7f;
      decl_declarator_set_specifiers(pcVar33,&pcVar40->spec);
      pcVar34 = decl_declarator_record(pcVar33);
      decl_check_conversion_return_type(pcVar34,&pcVar40->spec);
      pcVar34 = decl_declarator_record(pcVar33);
      decl_allow_variable_array_bound(pcVar34);
      pcVar34 = decl_declarator_record(pcVar33);
      decl_finish_declarator(pcVar34);
      decl_process_declaration(pcVar33);
      cVar10 = type_is_cv_qualified_stripped(pcVar33);
      if (cVar10 == '\0') {
        pcVar32 = (c1_type *)sym_name((c1_symbol *)pcVar33);
        cVar10 = type_is_void(pcVar32);
        if (cVar10 != '\0') {
          diag_error(0x1d5);
        }
      }
      else {
        sym_name((c1_symbol *)pcVar33);
        diag_error(0x1d4);
      }
      g_declarator_paren_base = g_declarator_paren_base + -1;
      parse_paren_depth_pop();
      g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfe;
      value_base[1].words[0] = (c1_u32)pcVar33;
      lVar45 = g_enum_value;
      break;
    case 0x1e4:
      pcVar33 = decl_declarator_alloc();
      if (pcVar33 == (c1_declarator *)0x0) {
        pcVar33 = (c1_declarator *)0x0;
      }
      else {
        pcVar33 = decl_declarator_init(pcVar33,g_name_new_target,4,(c1_overload_set *)0x0);
      }
      g_declarator_paren_base = g_declarator_paren_base + 1;
      if (g_yy_lookahead != (byte *)0x0) {
        cVar10 = lex_token_code((c1xx_token *)g_yy_lookahead);
        if (cVar10 == 'v') {
          g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] | 3;
        }
      }
      value_base[1].declarator = pcVar33;
      lVar45 = g_enum_value;
      break;
    case 0x1e5:
      pcVar33 = decl_declarator_alloc();
      if (pcVar33 == (c1_declarator *)0x0) {
        pcVar33 = (c1_declarator *)0x0;
      }
      else {
        pcVar33 = decl_declarator_init(pcVar33,g_name_new_target,4,(c1_overload_set *)0x0);
      }
      pcVar34 = decl_declarator_record(pcVar33);
      type_check_based_form(pcVar34,&pcVar40->mods);
      g_declarator_paren_base = g_declarator_paren_base + 1;
LAB_10467c7c:
      value_base[1].declarator = pcVar33;
      lVar45 = g_enum_value;
      break;
    case 0x1e7:
      if ((pcVar14->node != (c1_node *)0x0) && (pcVar14->node->op == '7')) {
        diag_warning(4,0x2c5);
      }
      pcVar24 = pcVar14->node;
      pvVar23 = decl_declarator_record(value_base[1].declarator);
      type_check_array_bound_constant_2(pvVar23,pcVar24);
      lVar45 = g_enum_value;
      break;
    case 0x1eb:
      pcVar24 = expr_build_delete((pcVar14->spec).spec[0],pcVar40->node,(c1_node *)0x0,'\0');
      value_base[1].node = pcVar24;
      lVar45 = g_enum_value;
      break;
    case 0x1ec:
      if ((pcVar14[-1].node != (c1_node *)0x0) && ((pcVar14[-1].node)->op == '7')) {
        diag_warning(4,0x2c5);
      }
      pcVar24 = expr_build_delete(pcVar14[-3].spec.spec[0],pcVar40->node,pcVar14[-1].node,'\x01');
      value_base[1].node = pcVar24;
      lVar45 = g_enum_value;
    }
    iVar35 = g_yy_pgo[g_yy_r1[g_yy_rule]] + 1 + *state_sp;
    pcVar14 = value_base;
    g_enum_value = lVar45;
    if ((0xfdb < iVar35) ||
       (iVar22 = (int)g_yy_action[iVar35],
       (int)g_yy_chk[g_yy_action[iVar35]] != -(uint)g_yy_r1[g_yy_rule])) {
      iVar22 = (int)g_yy_action[g_yy_pgo[g_yy_r1[g_yy_rule]]];
    }
  } while( true );
}

