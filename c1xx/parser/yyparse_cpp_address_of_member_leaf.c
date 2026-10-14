int __cdecl
yyparse_cpp_address_of_member_leaf
          (c1_node *leaf,c1_yy_value *value_base,c1_yy_value *value_top,c1_yy_parser *parser,
          int *state_sp,byte *saved_lookahead,int saved_rule)

{
  ushort *puVar1;
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
  c1_scope_body *pcVar12;
  char *token;
  c1_yy_value *pcVar13;
  c1_symbol *pcVar14;
  c1_yy_action_slot d;
  byte *pbVar15;
  c1_param_clause *pcVar16;
  c1xx_scope *scope;
  c1_sym_list *params;
  c1_arg_item *pcVar17;
  c1_arg_list *pcVar18;
  int *piVar19;
  c1_decl_modifier *pcVar20;
  void *pvVar21;
  c1_node *pcVar22;
  c1_line_map_row *pcVar23;
  c1xx_token_stream *stream;
  c1xx_token *pcVar24;
  uint *puVar25;
  c1_lookup_entry *cell;
  c1_u8 *pcVar26;
  c1_u32 cVar27;
  fe_name *pfVar28;
  c1_symbol *pcVar29;
  c1_declarator *d_00;
  c1_type *pcVar30;
  c1_declarator *pcVar31;
  c1_decl_record *pcVar32;
  int iVar33;
  int iVar34;
  c1_arena *a;
  uint uVar35;
  undefined4 extraout_ECX;
  short *psVar36;
  undefined2 uVar40;
  c1xx_idb_vtbl *pcVar37;
  c1_yy_value *pcVar38;
  c1_yy_value *pcVar39;
  c1_u32 *pcVar41;
  void **ppvVar42;
  undefined4 *puVar43;
  bool bVar44;
  longlong lVar45;
  c1_decl_modifier cVar46;
  c1_yy_action_slot in_stack_00000018;
  longlong in_stack_00000020;
  undefined4 in_stack_00000028;
  uint in_stack_00000034;
  c1_u32 in_stack_00000038;
  void *in_stack_0000003c;
  c1_u32 in_stack_00000040;
  void *in_stack_00000044;
  c1_u32 in_stack_00000048;
  void *in_stack_0000004c;
  c1_u16 in_stack_00000050;
  c1_u16 in_stack_00000052;
  c1_type *in_stack_00000054;
  c1_type_extra in_stack_00000058;
  c1_u32 in_stack_0000005c;
  byte in_stack_00000060;
  c1_type *in_stack_00000078;
  c1_symbol *in_stack_0000007c;
  c1_u32 acStack_24 [2];
  undefined1 uVar47;
  undefined1 uVar48;
  undefined1 uVar49;
  undefined1 uVar50;
  undefined2 uVar51;
  c1_symbol **ppcVar52;
  c1xx_decl_specifiers *pcVar53;
  c1_symbol *qualifier;
  c1_overload_set *pcVar54;
  uint uVar55;
  
  lVar45 = g_enum_value;
  if (leaf->right == (void *)0x0) goto LAB_10422fd4;
  cVar27 = expr_build_unary(0x31,leaf);
  value_base[1].words[0] = cVar27;
  lVar45 = g_enum_value;
switchD_10421905_caseD_1:
  iVar34 = g_yy_pgo[g_yy_r1[g_yy_rule]] + 1 + *state_sp;
  pcVar13 = value_base;
  g_enum_value = lVar45;
  if ((0xfdb < iVar34) ||
     (iVar33 = (int)g_yy_action[iVar34],
     (int)g_yy_chk[g_yy_action[iVar34]] != -(uint)g_yy_r1[g_yy_rule])) {
    iVar33 = (int)g_yy_action[g_yy_pgo[g_yy_r1[g_yy_rule]]];
  }
  while( true ) {
    state_sp = state_sp + 1;
    value_top = pcVar13 + 1;
    *state_sp = iVar33;
    sVar3 = g_yy_pact[iVar33];
    if (sVar3 < -999) break;
    if (g_yy_lookahead == (byte *)0x0) {
      g_yy_lookahead = yylex_cpp();
    }
    iVar34 = (int)sVar3 + (uint)g_token_class[*g_yy_lookahead];
    if (((iVar34 < 0) || (0xfdb < iVar34)) ||
       (iVar34 = (int)g_yy_action[iVar34],
       g_yy_chk[iVar34] != (ushort)g_token_class[*g_yy_lookahead])) break;
    if (parser->states + 0x3fb < state_sp) {
      yyerror_cpp("yacc stack overflow");
      g_yy_result = 1;
      iVar34 = parse_yacc_return_tail(saved_lookahead,saved_rule);
      return iVar34;
    }
    yy_copy_token_value(pcVar13 + 2,g_yy_lookahead);
    g_yy_lookahead = (byte *)0x0;
    pcVar13 = value_top;
    iVar33 = iVar34;
    if (0 < parser->errflag) {
      parser->errflag = parser->errflag + -1;
    }
  }
  iVar34 = (int)g_yy_def[iVar33];
  lVar45 = g_enum_value;
  if (iVar34 < 1) {
    if (iVar34 == -2) {
      if (g_yy_lookahead == (byte *)0x0) {
        g_yy_lookahead = yylex_cpp();
        lVar45 = g_enum_value;
      }
      psVar36 = g_yy_exca + g_yy_exca_index[iVar33];
      uVar2 = g_yy_exca[g_yy_exca_index[iVar33]];
      while ((uVar2 != g_token_class[*g_yy_lookahead] && (-1 < (short)uVar2))) {
        puVar1 = (ushort *)(psVar36 + 2);
        psVar36 = psVar36 + 2;
        uVar2 = *puVar1;
      }
      iVar34 = (int)psVar36[1];
      if (iVar34 < 0) {
        g_yy_result = 0;
        g_enum_value = lVar45;
        iVar34 = parse_yacc_return_tail(saved_lookahead,saved_rule);
        return iVar34;
      }
    }
    if (iVar34 == 0) {
      g_enum_value = lVar45;
      iVar34 = yyparse_cpp_error_entry
                         (0,value_top,state_sp,iVar33,parser,in_stack_00000018,saved_lookahead,
                          saved_rule);
      return iVar34;
    }
  }
  iVar33 = g_paren_depth;
  pcVar24 = (c1xx_token *)g_yy_lookahead;
  g_enum_value._4_4_ = (undefined4)((ulonglong)lVar45 >> 0x20);
  g_enum_value._0_4_ = (undefined4)lVar45;
  uVar55 = (uint)g_yy_r2[iVar34];
  state_sp = state_sp + -uVar55;
  value_base = value_top + -uVar55;
  uVar40 = (undefined2)(uVar55 * -5 >> 0x10);
  g_yy_rule = iVar34;
  g_enum_value = lVar45;
  switch(iVar34) {
  case 3:
    goto switchD_10421905_caseD_0;
  default:
    goto switchD_10421905_caseD_1;
  case 5:
    paren_depth_leave(pcVar13->words[0]);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 6:
    paren_depth_leave(0);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 8:
    if ((g_yy_lookahead == (byte *)0x0) || (*g_yy_lookahead != 0x76)) {
      pcVar53 = g_paren_level_declspecs + g_paren_depth;
      for (iVar34 = 9; iVar34 != 0; iVar34 = iVar34 + -1) {
        *(c1_u32 *)pcVar53->spec = pcVar13->words[0];
        pcVar53 = (c1xx_decl_specifiers *)(pcVar53->spec + 4);
        pcVar13 = (c1_yy_value *)(pcVar13->words + 1);
      }
      g_paren_level_flags[iVar33] = g_paren_level_flags[iVar33] | 1;
      lVar45 = g_enum_value;
    }
    else {
      pcVar41 = (c1_u32 *)(&g_paren_level_declspecs_prev_base + g_paren_depth * 0x24);
      iVar33 = 9;
      iVar34 = g_paren_depth;
LAB_10420c2b:
      for (; g_enum_value = lVar45, iVar33 != 0; iVar33 = iVar33 + -1) {
        *pcVar41 = pcVar13->words[0];
        pcVar13 = (c1_yy_value *)(pcVar13->words + 1);
        pcVar41 = pcVar41 + 1;
        lVar45 = g_enum_value;
      }
      pbVar15 = (byte *)((int)&g_function_tuple_count + iVar34 + 3);
      *pbVar15 = *pbVar15 | 1;
      lVar45 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 9:
    pcVar39 = pcVar13 + -1;
    g_declarator_paren_base = g_declarator_paren_base + -1;
    decl_check_conversion_return_type(pcVar13->declarator->decl,&pcVar39->spec);
    decl_finish_declarator(pcVar13->declarator->decl);
    pcVar38 = pcVar39;
    ppvVar42 = (void **)&pcVar13->node->unk0c;
    for (iVar34 = 6; iVar34 != 0; iVar34 = iVar34 + -1) {
      *ppvVar42 = (void *)pcVar38->words[0];
      pcVar38 = (c1_yy_value *)(pcVar38->words + 1);
      ppvVar42 = ppvVar42 + 1;
    }
    pcVar13->declarator->flags56 = pcVar13->declarator->flags56 | 0x20;
    if (g_class_depth < 0) {
      if ((g_compile_flags_c8 & 0x40) == 0) {
        g_last_declared_symbol =
             decl_declare_from_declarator(pcVar13->declarator,(byte *)pcVar39->words);
      }
      else {
        g_last_declared_symbol = pcVar13->declarator->sym;
      }
      bVar11 = g_current_scope->current->kind;
      if ((0xfa < bVar11) && (bVar11 != 0xfd)) {
        scope_pop_to_kind(g_current_scope,'\x01');
      }
      class_check_unnamed_class_member(&pcVar39->spec);
      lVar45 = g_enum_value;
    }
    else {
      pcVar13->declarator->kind = 2;
      in_stack_00000018.sym = (c1_symbol *)0x0;
      cVar9 = class_begin_member_list
                        (pcVar13->declarator,&pcVar39->spec,(c1_symbol **)&stack0x00000018);
      lVar45 = g_enum_value;
      if (((cVar9 == '\0') && (bVar11 = g_current_scope->current->kind, 0xfa < bVar11)) &&
         (bVar11 != 0xfd)) {
        scope_pop_to_kind(g_current_scope,'\x01');
        lVar45 = g_enum_value;
      }
      g_last_declared_symbol = in_stack_00000018.sym;
      if ((c1_declarator *)in_stack_00000018.sym == (c1_declarator *)0x0) {
        g_last_declared_symbol = pcVar13->declarator->sym;
      }
    }
    goto switchD_10421905_caseD_1;
  case 10:
    g_compile_flags_c4 = g_compile_flags_c4 | 0x1000000;
    g_compile_flags_c8 = g_compile_flags_c8 & 0xfffffffd;
    g_declarator_paren_base = g_declarator_paren_base + -1;
    if ((g_paren_level_flags[g_paren_depth] & 1) == 0) {
      pcVar53 = decl_specifiers_default((void *)0x0);
    }
    else {
      pcVar53 = g_paren_level_declspecs + g_paren_depth;
    }
    decl_check_conversion_return_type(pcVar13->declarator->decl,pcVar53);
    decl_finish_declarator(pcVar13->declarator->decl);
    if ((g_paren_level_flags[g_paren_depth] & 1) == 0) {
      pcVar53 = decl_specifiers_default((void *)0x0);
    }
    else {
      pcVar53 = g_paren_level_declspecs + g_paren_depth;
    }
    ppvVar42 = (void **)&pcVar13->node->unk0c;
    for (iVar34 = 6; iVar34 != 0; iVar34 = iVar34 + -1) {
      *ppvVar42 = *(void **)pcVar53->spec;
      pcVar53 = (c1xx_decl_specifiers *)(pcVar53->spec + 4);
      ppvVar42 = ppvVar42 + 1;
    }
    pcVar13->declarator->flags56 = pcVar13->declarator->flags56 | 0x20;
    if (g_class_depth < 0) {
      if ((g_compile_flags_c8 & 0x40) == 0) {
        if ((g_paren_level_flags[g_paren_depth] & 1) == 0) {
          pcVar53 = decl_specifiers_default((void *)0x0);
          g_last_declared_symbol = decl_declare_from_declarator(pcVar13->declarator,pcVar53->spec);
        }
        else {
          g_last_declared_symbol =
               decl_declare_from_declarator
                         (pcVar13->declarator,g_paren_level_declspecs[g_paren_depth].spec);
        }
      }
      else {
        g_last_declared_symbol = pcVar13->declarator->sym;
      }
      bVar11 = g_current_scope->current->kind;
      lVar45 = g_enum_value;
      if ((0xfa < bVar11) && (bVar11 != 0xfd)) {
        scope_pop_to_kind(g_current_scope,'\x01');
        lVar45 = g_enum_value;
      }
    }
    else {
      pcVar13->declarator->kind = 2;
      in_stack_00000018.sym = (c1_symbol *)0x0;
      if ((g_paren_level_flags[g_paren_depth] & 1) == 0) {
        pcVar53 = decl_specifiers_default((void *)0x0);
      }
      else {
        pcVar53 = g_paren_level_declspecs + g_paren_depth;
      }
      cVar9 = class_begin_member_list(pcVar13->declarator,pcVar53,(c1_symbol **)&stack0x00000018);
      lVar45 = g_enum_value;
      if (((cVar9 == '\0') && (bVar11 = g_current_scope->current->kind, 0xfa < bVar11)) &&
         (bVar11 != 0xfd)) {
        scope_pop_to_kind(g_current_scope,'\x01');
        lVar45 = g_enum_value;
      }
      g_last_declared_symbol = in_stack_00000018.sym;
      if ((c1_declarator *)in_stack_00000018.sym == (c1_declarator *)0x0) {
        g_last_declared_symbol = pcVar13->declarator->sym;
      }
    }
    goto switchD_10421905_caseD_1;
  case 0xb:
    g_compile_flags_c4 = g_compile_flags_c4 | 0x1000000;
    g_compile_flags_c8 = g_compile_flags_c8 & 0xfffffffd;
    bVar11 = g_current_scope->current->kind;
    if ((0xfa < bVar11) && (bVar11 != 0xfd)) {
      scope_pop_to_kind(g_current_scope,'\x01');
    }
    if ((g_paren_level_flags[g_paren_depth] & 1) == 0) {
      pcVar53 = decl_specifiers_default((void *)0x0);
    }
    else {
      pcVar53 = g_paren_level_declspecs + g_paren_depth;
    }
    decl_check_conversion_return_type(pcVar13->declarator->decl,pcVar53);
    decl_finish_declarator(pcVar13->declarator->decl);
    if ((g_paren_level_flags[g_paren_depth] & 1) == 0) {
      pcVar53 = decl_specifiers_default((void *)0x0);
    }
    else {
      pcVar53 = g_paren_level_declspecs + g_paren_depth;
    }
    ppvVar42 = (void **)&pcVar13->node->unk0c;
    for (iVar34 = 6; iVar34 != 0; iVar34 = iVar34 + -1) {
      *ppvVar42 = *(void **)pcVar53->spec;
      pcVar53 = (c1xx_decl_specifiers *)(pcVar53->spec + 4);
      ppvVar42 = ppvVar42 + 1;
    }
    if ((g_paren_level_flags[g_paren_depth] & 1) == 0) {
      pcVar53 = decl_specifiers_default((void *)0x0);
    }
    else {
      pcVar53 = g_paren_level_declspecs + g_paren_depth;
    }
    g_last_declared_symbol = func_begin_member_definition(pcVar13->declarator,pcVar53->spec);
    g_declarator_paren_base = g_declarator_paren_base + -1;
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfc;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xc:
    g_compile_flags_c4 = g_compile_flags_c4 & 0xfeffffff;
    g_compile_flags_c8 = g_compile_flags_c8 & 0xfffffffd;
    bVar11 = g_current_scope->current->kind;
    if ((0xfa < bVar11) && (bVar11 != 0xfd)) {
      scope_pop_to_kind(g_current_scope,'\x01');
    }
    pcVar39 = pcVar13 + -1;
    decl_check_conversion_return_type(pcVar13->declarator->decl,&pcVar39->spec);
    decl_finish_declarator(pcVar13->declarator->decl);
    pcVar38 = pcVar39;
    ppvVar42 = (void **)&pcVar13->node->unk0c;
    for (iVar34 = 6; iVar34 != 0; iVar34 = iVar34 + -1) {
      *ppvVar42 = (void *)pcVar38->words[0];
      pcVar38 = (c1_yy_value *)(pcVar38->words + 1);
      ppvVar42 = ppvVar42 + 1;
    }
    g_last_declared_symbol =
         func_begin_member_definition(pcVar13->declarator,(byte *)pcVar39->words);
    goto LAB_10420683;
  case 0xd:
  case 0x83:
    default_argument_store_and_advance_top(pcVar13->node);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xe:
    g_class_depth = g_class_depth + -1;
    class_begin_deferred_member_bodies();
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xf:
    class_reset_member_function_class();
    g_yy_lookahead = (byte *)lex_unget_token((c1xx_token *)g_yy_lookahead);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x10:
    parse_external_declaration_end();
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x11:
    pch_creation_point();
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x12:
    pp_line_after_pch_options();
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x13:
    iVar34 = g_error_count;
    if (g_error_count != 0) goto LAB_104235dc;
    goto switchD_10421905_caseD_1;
  case 0x14:
    pch_hdrstop();
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
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
    goto switchD_10421905_caseD_1;
  case 0x17:
    g_yy_result = parser->error_count;
    g_yy_rule = saved_rule;
    g_yy_lookahead = saved_lookahead;
    return parser->error_count;
  case 0x1b:
  case 0x1c:
    goto switchD_10421905_caseD_18;
  case 0x1e:
    g_compile_flags_c4 = g_compile_flags_c4 | 0x1000000;
    g_compile_flags_c8 = g_compile_flags_c8 & 0xfffffffd;
    if ((g_paren_level_flags[g_paren_depth] & 1) == 0) {
      pcVar53 = decl_specifiers_default((void *)0x0);
      lVar45 = g_enum_value;
    }
    else {
      pcVar53 = g_paren_level_declspecs + g_paren_depth;
    }
    g_enum_value = lVar45;
    decl_check_conversion_return_type(value_top->declarator->decl,pcVar53);
    decl_finish_declarator(value_top->declarator->decl);
    if ((g_paren_level_flags[g_paren_depth] & 1) == 0) {
      pcVar53 = decl_specifiers_default((void *)0x0);
    }
    else {
      pcVar53 = g_paren_level_declspecs + g_paren_depth;
    }
    ppvVar42 = (void **)&value_top->node->unk0c;
    for (iVar34 = 6; iVar34 != 0; iVar34 = iVar34 + -1) {
      *ppvVar42 = *(void **)pcVar53->spec;
      pcVar53 = (c1xx_decl_specifiers *)(pcVar53->spec + 4);
      ppvVar42 = ppvVar42 + 1;
    }
    if ((g_paren_level_flags[g_paren_depth] & 1) == 0) {
      pcVar53 = decl_specifiers_default((void *)0x0);
    }
    else {
      pcVar53 = g_paren_level_declspecs + g_paren_depth;
    }
    func_begin_member_definition(value_top->declarator,pcVar53->spec);
    g_declarator_paren_base = g_declarator_paren_base + -1;
    bVar11 = g_current_scope->current->kind;
    if ((0xfa < bVar11) && (bVar11 != 0xfd)) {
      scope_pop_to_kind(g_current_scope,'\x01');
    }
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfc;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1f:
    g_ctor_mem_initializers = value_top->node;
    func_begin_definition_frame();
    g_compile_flags_c8 = g_compile_flags_c8 & 0xffffffbf;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x20:
    funcs_check_incremental();
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x21:
    tmpl_parse_queued_definition(value_top->header);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x22:
    g_compile_flags_c4 = g_compile_flags_c4 & 0xfeffffff;
    g_compile_flags_c8 = g_compile_flags_c8 & 0xfffffffd;
    bVar11 = g_current_scope->current->kind;
    if ((0xfa < bVar11) && (bVar11 != 0xfd)) {
      scope_pop_to_kind(g_current_scope,'\x01');
    }
    decl_check_conversion_return_type(value_top->declarator->decl,&pcVar13->spec);
    decl_finish_declarator(value_top->declarator->decl);
    pcVar39 = pcVar13;
    ppvVar42 = (void **)&value_top->node->unk0c;
    for (iVar34 = 6; iVar34 != 0; iVar34 = iVar34 + -1) {
      *ppvVar42 = (void *)pcVar39->words[0];
      pcVar39 = (c1_yy_value *)(pcVar39->words + 1);
      ppvVar42 = ppvVar42 + 1;
    }
    if (g_block_depth == '\0') {
      pcVar29 = func_begin_member_definition(value_top->declarator,(byte *)pcVar13->words);
      value_base[1].sym = pcVar29;
    }
    else {
      cVar9 = '\0';
      pcVar29 = decl_declare_in_current_scope(value_top->declarator,&pcVar13->spec);
      func_parse_definition_or_skip(pcVar29,cVar9);
      g_yy_lookahead = g_token_end_parse;
    }
LAB_10420683:
    g_declarator_paren_base = g_declarator_paren_base + -1;
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfc;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x24:
    g_compile_flags_cc = g_compile_flags_cc | 2;
    func_begin_definition_state((int *)(value_top->str).text);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x25:
    pcVar29 = type_require_complete(value_top->sym);
    value_base[1].sym = pcVar29;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x26:
    pcVar29 = type_require_complete(value_top->sym);
    value_base[1].sym = pcVar29;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x27:
  case 0x39:
  case 0xf7:
  case 0x12d:
  case 0x168:
  case 0x174:
  case 0x182:
  case 0x1e8:
    break;
  case 0x28:
    g_compile_flags_c4 = g_compile_flags_c4 | 1;
    g_compile_flags_c8 = g_compile_flags_c8 | 0x100;
    goto switchD_10421905_caseD_1;
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
    value_base[1].ptr = (void *)value_top->words[0];
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x2a:
    pcVar22 = tree_append_expression_list_item((c1_node *)0x0,value_top->node);
    value_base[1].node = pcVar22;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x2b:
    pcVar22 = tree_append_expression_list_item(pcVar13[-1].node,value_top->node);
    value_base[1].node = pcVar22;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x2c:
    diag_error(0x276);
    pcVar22 = tree_append_expression_list_item(pcVar13[-1].node,value_top->node);
    value_base[1].node = pcVar22;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x2d:
  case 0x2f:
  case 0x31:
  case 0x33:
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] | 1;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x2e:
    cVar27 = pcVar13->words[0];
    pfVar28 = pcVar13[-3].name;
    uVar48 = (undefined1)cVar27;
    uVar50 = (undefined1)(cVar27 >> 8);
    uVar40 = (undefined2)(cVar27 >> 0x10);
    goto LAB_1042079c;
  case 0x30:
    cVar27 = pcVar13->words[0];
    uVar48 = (undefined1)cVar27;
    uVar50 = (undefined1)(cVar27 >> 8);
    uVar40 = (undefined2)(cVar27 >> 0x10);
    pfVar28 = (pcVar13[-3].declarator)->name;
LAB_1042079c:
    cVar9 = '\0';
    pcVar30 = (c1_type *)0x0;
    pcVar29 = sym_new_kind1_placeholder(pfVar28);
    pcVar22 = tree_new_symbol_ref(pcVar29,cVar9);
    pcVar22 = tree_new_node('v',pcVar22,(c1_node *)CONCAT22(uVar40,CONCAT11(uVar50,uVar48)),pcVar30)
    ;
    value_base[1].node = pcVar22;
    g_compile_flags_c4 = g_compile_flags_c4 | 1;
    goto LAB_104207ca;
  case 0x32:
  case 0x34:
    cVar27 = pcVar13->words[0];
    pcVar30 = (c1_type *)0x0;
    uVar48 = (undefined1)cVar27;
    uVar50 = (undefined1)(cVar27 >> 8);
    uVar40 = (undefined2)(cVar27 >> 0x10);
    pcVar22 = tree_new_symbol_ref(*pcVar13[-3].cell,'\0');
    pcVar22 = tree_new_node('v',pcVar22,(c1_node *)CONCAT22(uVar40,CONCAT11(uVar50,uVar48)),pcVar30)
    ;
    value_base[1].node = pcVar22;
    g_compile_flags_c4 = g_compile_flags_c4 | 1;
    goto LAB_104207ca;
  case 0x35:
    value_base[1].words[0] = 0;
    diag_error(0x15f);
    g_compile_flags_c4 = g_compile_flags_c4 | 1;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
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
    goto switchD_10421905_caseD_1;
  case 0x38:
    value_base[1].words[0] = pcVar13->words[0];
LAB_104207ca:
    lVar45 = g_enum_value;
    if (0 < g_paren_depth) {
      g_paren_depth = g_paren_depth + -1;
    }
    goto switchD_10421905_caseD_1;
  case 0x3b:
    pcVar22 = tree_append_list_item((c1_node *)0x0,value_top->node,2);
    value_base[1].node = pcVar22;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x3c:
    pcVar22 = tree_append_list_item(pcVar13[-1].node,value_top->node,2);
    value_base[1].node = pcVar22;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x3e:
    decl_pop_linkage_specification();
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x46:
    if (pcVar13->words[0] == 0) {
      g_compile_flags_c4 = g_compile_flags_c4 | 0x800000;
      g_compile_flags_c8 = g_compile_flags_c8 & 0xffffffbf;
    }
    else {
      g_ctor_mem_initializers = value_top->node;
      func_begin_definition_frame();
      g_compile_flags_c8 = g_compile_flags_c8 & 0xffffffbf;
      lVar45 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0x47:
    if (pcVar13[-2].words[0] == 0) {
      g_compile_flags_c4 = g_compile_flags_c4 & 0xff7fffff;
      g_compile_flags_cc = g_compile_flags_cc & 0xfffffffd;
    }
    else {
      funcs_check_incremental();
      g_compile_flags_cc = g_compile_flags_cc & 0xfffffffd;
      lVar45 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0x49:
    parse_yyerrok(parser);
    g_compile_flags_c4 = g_compile_flags_c4 & 0xff7fffff;
    g_compile_flags_c8 = g_compile_flags_c8 & 0xffffffbf;
    g_compile_flags_cc = g_compile_flags_cc & 0xfffffffd;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x4a:
    pcVar41 = (c1_u32 *)&stack0x00000100;
    for (iVar34 = 9; iVar34 != 0; iVar34 = iVar34 + -1) {
      *pcVar41 = pcVar13->words[0];
      pcVar41 = pcVar41 + 1;
      pcVar13 = (c1_yy_value *)(pcVar13->words + 1);
    }
    class_check_unnamed_class_member((c1xx_decl_specifiers *)&stack0x00000100);
    value_base[1].ptr = (void *)value_top->words[0];
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x4b:
    pcVar41 = (c1_u32 *)&stack0x000000b8;
    for (iVar34 = 9; iVar34 != 0; iVar34 = iVar34 + -1) {
      *pcVar41 = value_top->words[0];
      value_top = (c1_yy_value *)(value_top->words + 1);
      pcVar41 = pcVar41 + 1;
    }
    class_check_unnamed_class_member((c1xx_decl_specifiers *)&stack0x000000b8);
    decl_check_empty_declaration(&stack0x000000b8);
    value_base[1].words[0] = 0;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x4c:
    tmpl_finish_class_template_declaration(pcVar13 + -1,&pcVar13->spec);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x4d:
    tmpl_finish_nonclass_template_declaration(pcVar13 + -1,pcVar13->sym);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x4e:
    tmpl_finish_class_template_declaration(pcVar13,(c1xx_decl_specifiers *)0x0);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x4f:
    g_compile_flags_cc = g_compile_flags_cc & 0xefffffff;
    pcVar31 = arena_alloc(g_arenas + 5,0x58);
    if (pcVar31 == (c1_declarator *)0x0) {
      pcVar31 = (c1_declarator *)0x0;
    }
    else {
      pcVar31->position = g_token_position;
    }
    pcVar39 = pcVar13;
    pcVar26 = pcVar31->spec;
    for (iVar34 = 6; iVar34 != 0; iVar34 = iVar34 + -1) {
      *(c1_u32 *)pcVar26 = pcVar39->words[0];
      pcVar39 = (c1_yy_value *)(pcVar39->words + 1);
      pcVar26 = pcVar26 + 4;
    }
    tmpl_explicit_instantiation(pcVar31,'\x01',&pcVar13->spec);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x50:
    g_compile_flags_cc = g_compile_flags_cc & 0xefffffff;
    pcVar39 = pcVar13 + -1;
    decl_check_conversion_return_type(pcVar13->declarator->decl,&pcVar39->spec);
    decl_finish_declarator(pcVar13->declarator->decl);
    pcVar38 = pcVar39;
    ppvVar42 = (void **)&pcVar13->node->unk0c;
    for (iVar34 = 6; iVar34 != 0; iVar34 = iVar34 + -1) {
      *ppvVar42 = (void *)pcVar38->words[0];
      pcVar38 = (c1_yy_value *)(pcVar38->words + 1);
      ppvVar42 = ppvVar42 + 1;
    }
    tmpl_explicit_instantiation(pcVar13->declarator,'\x01',&pcVar39->spec);
    g_declarator_paren_base = g_declarator_paren_base + -1;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x51:
    g_compile_flags_cc = g_compile_flags_cc & 0xefffffff;
    diag_error(0x38d);
    tmpl_explicit_instantiation_without_specifiers(pcVar13->declarator,1);
    bVar11 = g_current_scope->current->kind;
    goto LAB_10465c69;
  case 0x52:
    g_compile_flags_cc = g_compile_flags_cc & 0xefffffff;
    pcVar31 = arena_alloc(g_arenas + 5,0x58);
    if (pcVar31 == (c1_declarator *)0x0) {
      pcVar31 = (c1_declarator *)0x0;
    }
    else {
      pcVar31->position = g_token_position;
    }
    pcVar39 = pcVar13;
    pcVar26 = pcVar31->spec;
    for (iVar34 = 6; iVar34 != 0; iVar34 = iVar34 + -1) {
      *(c1_u32 *)pcVar26 = pcVar39->words[0];
      pcVar39 = (c1_yy_value *)(pcVar39->words + 1);
      pcVar26 = pcVar26 + 4;
    }
    tmpl_explicit_instantiation(pcVar31,pcVar13[-2].spec.spec[0],&pcVar13->spec);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x53:
    pcVar39 = pcVar13 + -1;
    g_compile_flags_cc = g_compile_flags_cc & 0xefffffff;
    decl_check_conversion_return_type(pcVar13->declarator->decl,&pcVar39->spec);
    decl_finish_declarator(pcVar13->declarator->decl);
    pcVar38 = pcVar39;
    ppvVar42 = (void **)&pcVar13->node->unk0c;
    for (iVar34 = 6; iVar34 != 0; iVar34 = iVar34 + -1) {
      *ppvVar42 = (void *)pcVar38->words[0];
      pcVar38 = (c1_yy_value *)(pcVar38->words + 1);
      ppvVar42 = ppvVar42 + 1;
    }
    tmpl_explicit_instantiation(pcVar13->declarator,pcVar13[-3].spec.spec[0],&pcVar39->spec);
    bVar11 = g_current_scope->current->kind;
    if ((0xfa < bVar11) && (bVar11 != 0xfd)) {
      scope_pop_to_kind(g_current_scope,'\x01');
    }
    g_declarator_paren_base = g_declarator_paren_base + -1;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x54:
    g_compile_flags_cc = g_compile_flags_cc & 0xefffffff;
    in_stack_00000060 = in_stack_00000060 & 0xf8;
    in_stack_00000028 = CONCAT31(in_stack_00000028._1_3_,pcVar13[-2].spec.spec[0]);
    puVar43 = (undefined4 *)&stack0x00000060;
    for (iVar34 = 6; iVar34 != 0; iVar34 = iVar34 + -1) {
      *puVar43 = 0;
      puVar43 = puVar43 + 1;
    }
    pcVar31 = pcVar13->declarator;
    in_stack_0000007c = (c1_symbol *)0x0;
    in_stack_00000060 = in_stack_00000060 & 7 ^ in_stack_00000060 | 0x30;
    in_stack_00000078 = g_type_none;
    decl_check_conversion_return_type(pcVar31->decl,(c1xx_decl_specifiers *)&stack0x00000060);
    decl_finish_declarator(pcVar31->decl);
    tmpl_explicit_instantiation
              (pcVar31,(c1_u8)in_stack_00000028,(c1xx_decl_specifiers *)&stack0x00000060);
    bVar11 = g_current_scope->current->kind;
LAB_10465c69:
    if ((bVar11 < 0xfb) || (bVar11 == 0xfd)) goto LAB_104232fa;
    scope_pop_to_kind(g_current_scope,'\x01');
    g_declarator_paren_base = g_declarator_paren_base + -1;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x55:
    g_compile_flags_cc = g_compile_flags_cc & 0xefffffff;
    parse_yyerrok(parser);
    tmpl_finish_class_template_declaration((c1_yy_value *)0x0,(c1xx_decl_specifiers *)0x0);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x56:
    tmpl_check_nested_definition();
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x57:
    decl_pop_declarator_state(pcVar13->params);
    pvVar21 = tmpl_header_end(pcVar13->header->parameter_scope);
    value_base[1].ptr = pvVar21;
    pcVar18 = tmpl_header_take_parameter_list();
    *(c1_arg_list **)((int)value_base + 0x2c) = pcVar18;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x5d:
    g_declarator_paren_base = g_declarator_paren_base + -1;
    decl_check_conversion_return_type(value_top->declarator->decl,&pcVar13->spec);
    decl_finish_declarator(value_top->declarator->decl);
    pcVar39 = pcVar13;
    ppvVar42 = (void **)&value_top->node->unk0c;
    for (iVar34 = 6; iVar34 != 0; iVar34 = iVar34 + -1) {
      *ppvVar42 = (void *)pcVar39->words[0];
      pcVar39 = (c1_yy_value *)(pcVar39->words + 1);
      ppvVar42 = ppvVar42 + 1;
    }
    if (g_class_depth < 0) {
      if ((g_compile_flags_c8 & 0x40) == 0) {
        pcVar29 = decl_declare_from_declarator(value_top->declarator,(byte *)pcVar13->words);
      }
      else {
        pcVar29 = value_top->declarator->sym;
      }
      bVar11 = g_current_scope->current->kind;
      if ((0xfa < bVar11) && (bVar11 != 0xfd)) {
        scope_pop_to_kind(g_current_scope,'\x01');
      }
      class_check_unnamed_class_member(&pcVar13->spec);
      value_base[1].sym = pcVar29;
      lVar45 = g_enum_value;
    }
    else {
      value_top->declarator->kind = 2;
      cVar9 = class_begin_member_list(value_top->declarator,&pcVar13->spec,(c1_symbol **)0x0);
      if (((cVar9 == '\0') && (bVar11 = g_current_scope->current->kind, 0xfa < bVar11)) &&
         (bVar11 != 0xfd)) {
        scope_pop_to_kind(g_current_scope,'\x01');
      }
      value_base[1].words[0] = (c1_u32)value_top->declarator->sym;
      lVar45 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0x5e:
    g_compile_flags_c4 = g_compile_flags_c4 | 0x1000000;
    g_compile_flags_c8 = g_compile_flags_c8 & 0xfffffffd;
    g_declarator_paren_base = g_declarator_paren_base + -1;
    if ((g_paren_level_flags[g_paren_depth] & 1) == 0) {
      pcVar53 = decl_specifiers_default((void *)0x0);
      lVar45 = g_enum_value;
    }
    else {
      pcVar53 = g_paren_level_declspecs + g_paren_depth;
    }
    g_enum_value = lVar45;
    decl_check_conversion_return_type(value_top->declarator->decl,pcVar53);
    decl_finish_declarator(value_top->declarator->decl);
    if ((g_paren_level_flags[g_paren_depth] & 1) == 0) {
      pcVar53 = decl_specifiers_default((void *)0x0);
    }
    else {
      pcVar53 = g_paren_level_declspecs + g_paren_depth;
    }
    ppvVar42 = (void **)&value_top->node->unk0c;
    for (iVar34 = 6; iVar34 != 0; iVar34 = iVar34 + -1) {
      *ppvVar42 = *(void **)pcVar53->spec;
      pcVar53 = (c1xx_decl_specifiers *)(pcVar53->spec + 4);
      ppvVar42 = ppvVar42 + 1;
    }
    if (g_class_depth < 0) {
      if ((g_compile_flags_c8 & 0x40) == 0) {
        if ((g_paren_level_flags[g_paren_depth] & 1) == 0) {
          pcVar53 = decl_specifiers_default((void *)0x0);
          pcVar31 = (c1_declarator *)
                    decl_declare_from_declarator(value_top->declarator,pcVar53->spec);
        }
        else {
          pcVar31 = (c1_declarator *)
                    decl_declare_from_declarator
                              (value_top->declarator,g_paren_level_declspecs[g_paren_depth].spec);
        }
      }
      else {
        pcVar31 = (c1_declarator *)value_top->declarator->sym;
      }
      bVar11 = g_current_scope->current->kind;
      if (0xfa < bVar11) {
        iVar34 = yyparse_cpp_template_member_declaration_tail
                           (g_current_scope,bVar11,(c1_symbol *)pcVar31,value_base,parser,state_sp,
                            saved_lookahead,saved_rule);
        return iVar34;
      }
      goto LAB_10421939;
    }
    value_top->declarator->kind = 2;
    if ((g_paren_level_flags[g_paren_depth] & 1) == 0) {
      pcVar53 = decl_specifiers_default((void *)0x0);
    }
    else {
      pcVar53 = g_paren_level_declspecs + g_paren_depth;
    }
    cVar9 = class_begin_member_list(value_top->declarator,pcVar53,(c1_symbol **)0x0);
    if (((cVar9 == '\0') && (bVar11 = g_current_scope->current->kind, 0xfa < bVar11)) &&
       (bVar11 != 0xfd)) {
      scope_pop_to_kind(g_current_scope,'\x01');
    }
    value_base[1].words[0] = (c1_u32)value_top->declarator->sym;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x5f:
  case 0x60:
  case 0x6a:
    goto switchD_10421905_caseD_5c;
  case 0x61:
  case 0x62:
    pcVar12 = arena_alloc(g_arenas + 5,0x1c);
    if (pcVar12 == (c1_scope_body *)0x0) goto LAB_10465f34;
    cVar4 = g_current_scope->current->body;
    pcVar12[4] = (c1_scope_body)0x3;
    *(c1_u8 *)(pcVar12 + 5) = '\x01';
    *pcVar12 = cVar4;
    value_base[1].params = (c1_param_clause *)pcVar12;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 100:
    if ((g_token_source->stream->flags & 1) != 0) {
      pcVar23 = include_line_map_find((c1_line_map_state *)&g_lex_position,g_token_position);
      (*g_idb->vtbl->idb_scope_kind4_end)
                (g_idb,CONCAT22(uVar40,(short)pcVar23->line - (short)pcVar23->position) +
                       g_token_position,0);
    }
    if ((g_compile_flags_c8 & 0x10000000) == 0) {
      diag_error(0x3e);
    }
    pcVar17 = arena_alloc(g_arenas,0x14);
    if (pcVar17 == (c1_arg_item *)0x0) {
      pcVar17 = (c1_arg_item *)0x0;
    }
    else {
      cVar6 = (c1_arg_value)value_top->node->right;
      tmpl_list_item_construct(pcVar17,0,0);
      pcVar17->value = cVar6;
      pcVar17->vtbl = &PTR_pch_fixup_list_object_104c4c3c;
    }
    pcVar18 = g_paren_level_arg_lists[g_paren_depth];
    if (pcVar18 == (c1_arg_list *)0x0) {
      pcVar18 = arena_alloc(g_arenas,0xc);
      if (pcVar18 == (c1_arg_list *)0x0) {
        g_paren_level_arg_lists[g_paren_depth] = (c1_arg_list *)0x0;
      }
      else {
        pcVar18->first = pcVar17;
        pcVar18->last = pcVar17;
        pcVar18->flags = (pcVar17->kind >> 3 & 1 ^ pcVar18->flags) & 1 ^ pcVar18->flags;
        g_paren_level_arg_lists[g_paren_depth] = pcVar18;
      }
    }
    else {
      pcVar17->next = pcVar18->first;
      pcVar18->first->prev = pcVar17;
      pcVar18->first = pcVar17;
      if ((pcVar17->kind & 8) != 0) {
        pcVar18->flags = pcVar18->flags | 1;
      }
    }
    expr_count_evaluated_operator();
    uVar55 = g_compile_flags_c8 & 0xfeffffff;
    uVar35 = g_compile_flags_cc & 0xffffffef;
    lVar45 = g_enum_value;
    if (((g_compile_flags_c8 & 0x32000000) == 0) &&
       (((((g_compile_flags_c8 & 0x40000000) == 0 || ((g_compile_flags_cc & 8) != 0)) ||
         ((g_compile_flags_c4 & 0x200) != 0)) &&
        ((uVar8 = g_compile_flags_c8 & 0x4000000, g_compile_flags_c8 = uVar55,
         g_compile_flags_cc = uVar35, uVar8 == 0 || ((g_compile_flags_c4 & 0x8000) != 0))))))
    goto LAB_1046607d;
LAB_1046625d:
    g_compile_flags_cc = uVar35;
    g_compile_flags_c8 = uVar55;
    g_context_arena_index = 0;
    g_expr_arena_index = 0;
    goto switchD_10421905_caseD_5c;
  case 0x65:
    if ((g_token_source->stream->flags & 1) != 0) {
      pcVar23 = include_line_map_find((c1_line_map_state *)&g_lex_position,g_token_position);
      (*g_idb->vtbl->idb_scope_kind4_end)
                (g_idb,CONCAT22(uVar40,(short)pcVar23->line - (short)pcVar23->position) +
                       g_token_position,0);
    }
    a = g_arenas + g_expr_arena_index;
    pcVar22 = (c1_node *)a->cur;
    pcVar7 = (c1_node *)g_arenas[g_expr_arena_index].end;
    a->cur = &pcVar22[1].op;
    if (pcVar7 < pcVar22 + 1) {
      arena_grow(a);
    }
    pcVar22->kind = '\0';
    pcVar22->op = 0xc6;
    pcVar22->left = (void *)value_top->words[0];
    in_stack_00000054 = (c1_type *)0x0;
    in_stack_0000005c = 0;
    in_stack_00000050 = 0x80e;
    in_stack_00000052 = 0;
    in_stack_00000058.cls = (c1_symbol *)0x0;
    pcVar30 = type_intern((c1_type *)&stack0x00000050);
    pcVar22->type = pcVar30;
    pcVar22 = tree_append_list_item((c1_node *)0x0,pcVar22,2);
    pcVar17 = arena_alloc(g_arenas,0x14);
    if (pcVar17 == (c1_arg_item *)0x0) {
      pcVar17 = (c1_arg_item *)0x0;
    }
    else {
      tmpl_list_item_construct(pcVar17,1,0);
      pcVar17->vtbl = &PTR_pch_fixup_tree_list_object_104bcbcc;
      (pcVar17->value).expr = pcVar22;
    }
    pcVar18 = g_paren_level_arg_lists[g_paren_depth];
    if (pcVar18 == (c1_arg_list *)0x0) {
      pcVar18 = arena_alloc(g_arenas,0xc);
      if (pcVar18 == (c1_arg_list *)0x0) {
        g_paren_level_arg_lists[g_paren_depth] = (c1_arg_list *)0x0;
      }
      else {
        pcVar18->first = pcVar17;
        pcVar18->last = pcVar17;
        pcVar18->flags = (pcVar17->kind >> 3 & 1 ^ pcVar18->flags) & 1 ^ pcVar18->flags;
        g_paren_level_arg_lists[g_paren_depth] = pcVar18;
      }
    }
    else {
      pcVar17->next = pcVar18->first;
      pcVar18->first->prev = pcVar17;
      pcVar18->first = pcVar17;
      if ((pcVar17->kind & 8) != 0) {
        pcVar18->flags = pcVar18->flags | 1;
      }
    }
    expr_count_evaluated_operator();
    uVar55 = g_compile_flags_c8 & 0xfeffffff;
    uVar35 = g_compile_flags_cc & 0xffffffef;
    lVar45 = g_enum_value;
    if ((((g_compile_flags_c8 & 0x32000000) != 0) ||
        ((((g_compile_flags_c8 & 0x40000000) != 0 && ((g_compile_flags_cc & 8) == 0)) &&
         ((g_compile_flags_c4 & 0x200) == 0)))) ||
       ((uVar8 = g_compile_flags_c8 & 0x4000000, g_compile_flags_c8 = uVar55,
        g_compile_flags_cc = uVar35, uVar8 != 0 && ((g_compile_flags_c4 & 0x8000) == 0))))
    goto LAB_1046625d;
LAB_1046607d:
    g_context_arena_index = 5;
    g_expr_arena_index = 5;
    if ((g_compile_flags_cc & 1) != 0) {
      g_context_arena_index = 4;
      g_expr_arena_index = 4;
    }
    goto switchD_10421905_caseD_5c;
  case 0x68:
    g_compile_flags_c8 = g_compile_flags_c8 | 0x8000000;
    parse_default_argument_begin((c1_type *)0x0);
    func_flow_state_note_3e();
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x69:
    stream = token_reader_current_stream((c1_token_reader *)&g_token_position);
    cVar9 = token_stream_is_source_text(stream);
    lVar45 = g_enum_value;
    if (cVar9 != '\0') {
      pcVar37 = g_idb->vtbl;
      goto LAB_10422231;
    }
    goto switchD_10421905_caseD_1;
  case 0x6b:
  case 0x6d:
    pcVar26 = arena_alloc_n_aligned(0xc,0);
    if (pcVar26 == (c1_u8 *)0x0) goto LAB_10465f34;
    pvVar21 = tmpl_argument_list_init(pcVar26,value_top->ptr);
    value_base[1].ptr = pvVar21;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x6c:
    list_append_tail(pcVar13[-1].args,value_top->arg);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x6e:
    pcVar17 = tmpl_argument_from_expression(value_top->node);
    value_base[1].arg = pcVar17;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x6f:
    pcVar41 = acStack_24;
    for (iVar34 = 9; iVar34 != 0; iVar34 = iVar34 + -1) {
      *pcVar41 = pcVar13->words[0];
      pcVar41 = pcVar41 + 1;
      pcVar13 = (c1_yy_value *)(pcVar13->words + 1);
    }
    pcVar17 = decl_finish_declarator_record(value_top->declarator);
    value_base[1].arg = pcVar17;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x71:
    g_compile_flags_c8 = g_compile_flags_c8 & 0xffffffdf;
    goto switchD_10421905_caseD_1;
  case 0x72:
  case 0x15d:
  case 0x15e:
    goto switchD_10421905_caseD_6f;
  case 0x73:
    pcVar22 = value_top->node;
    pcVar13 = pcVar13 + -1;
    pcVar41 = (c1_u32 *)&stack0x00000124;
    for (iVar34 = 9; iVar34 != 0; iVar34 = iVar34 + -1) {
      *pcVar41 = pcVar13->words[0];
      pcVar13 = (c1_yy_value *)(pcVar13->words + 1);
      pcVar41 = pcVar41 + 1;
    }
    iVar34 = decl_parse_linkage_specification((c1xx_decl_specifiers *)&stack0x00000124,pcVar22);
    decl_push_linkage_specification(iVar34);
    if (g_yy_lookahead == (byte *)0x0) {
      iVar34 = parse_error_recovery_count();
      if (iVar34 == 0) {
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
    goto switchD_10421905_caseD_1;
  case 0x76:
    ns_end_definition(pcVar13[-1].words[0]);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x77:
    pbVar15 = ns_define_namespace((void *)0x0);
    value_base[1].str.text = pbVar15;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x78:
    pbVar15 = ns_define_namespace(pcVar13->ptr);
    value_base[1].str.text = pbVar15;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x79:
    scope_pop_to_kind_if_needed(g_current_scope,'\0');
    pvVar21 = qualname_resolved_symbol(pcVar13->declarator);
    cVar10 = '\0';
    uVar48 = 0;
    uVar50 = 0;
    uVar40 = 0;
    if (pvVar21 == (void *)0x0) {
      pcVar29 = value_word0(pcVar13->cell);
      ns_using_directive((c1_symbol *)0x0,(fe_name *)pcVar29,
                         CONCAT22(uVar40,CONCAT11(uVar50,uVar48)),cVar10);
      lVar45 = g_enum_value;
    }
    else {
      uVar47 = 0;
      uVar49 = 0;
      uVar51 = 0;
      pcVar29 = qualname_resolved_symbol(pcVar13->declarator);
      ns_using_directive(pcVar29,(fe_name *)CONCAT22(uVar51,CONCAT11(uVar49,uVar47)),
                         CONCAT22(uVar40,CONCAT11(uVar50,uVar48)),cVar10);
      lVar45 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0x7a:
    scope_pop_to_kind_if_needed(g_current_scope,'\0');
    pvVar21 = qualname_resolved_symbol(pcVar13->declarator);
    pcVar31 = (c1_declarator *)pcVar13->cell;
    if (pvVar21 == (void *)0x0) goto LAB_104668f9;
    pcVar29 = qualname_resolved_symbol(pcVar31);
    ns_using_declaration(pcVar29);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x7b:
    ns_using_declaration((pcVar13->spec).type_sym);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x7c:
    scope_pop_to_kind_if_needed(g_current_scope,'\0');
    ns_define_alias(pcVar13->declarator,pcVar13[-2].name);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x7d:
    diag_error(0x122);
    parse_paren_depth_pop();
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x7e:
    if (g_yy_lookahead != (byte *)0x0) {
      cVar10 = lex_token_code((c1xx_token *)g_yy_lookahead);
      if (cVar10 == 'v') {
        iVar33 = 9;
        iVar34 = g_paren_depth;
        pcVar13 = value_top;
        pcVar41 = (c1_u32 *)(&g_paren_level_declspecs_prev_base + g_paren_depth * 0x24);
        lVar45 = g_enum_value;
        goto LAB_10420c2b;
      }
    }
    iVar34 = g_paren_depth;
    pcVar53 = g_paren_level_declspecs + g_paren_depth;
    for (iVar33 = 9; iVar33 != 0; iVar33 = iVar33 + -1) {
      *(c1_u32 *)pcVar53->spec = value_top->words[0];
      value_top = (c1_yy_value *)(value_top->words + 1);
      pcVar53 = (c1xx_decl_specifiers *)(pcVar53->spec + 4);
    }
    g_paren_level_flags[iVar34] = g_paren_level_flags[iVar34] | 1;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x7f:
    if ((*(code **)((int)pcVar13 + 0x48) != (code *)0x0) && (*(int *)((int)pcVar13 + 0x44) != 0)) {
      (**(code **)((int)pcVar13 + 0x48))();
      lVar45 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0x80:
    bVar44 = g_yy_lookahead != (byte *)0x0;
    puVar25 = &g_yylval;
    for (iVar34 = 9; iVar34 != 0; iVar34 = iVar34 + -1) {
      *puVar25 = value_top->words[0];
      value_top = (c1_yy_value *)(value_top->words + 1);
      puVar25 = puVar25 + 1;
    }
    if (bVar44) {
      cVar10 = lex_token_code(pcVar24);
      pcVar24 = (c1xx_token *)g_yy_lookahead;
      lVar45 = g_enum_value;
      if (cVar10 == '\x7f') goto switchD_10421905_caseD_1;
    }
    g_yy_lookahead = (byte *)lex_unget_token(pcVar24);
    g_compile_flags_c4 = g_compile_flags_c4 | 0x80000000;
    pcVar29 = value_word0((c1_symbol **)&g_token_arena_index);
    pcVar26 = arena_or_pool_alloc(0x30,(int)pcVar29);
    if (pcVar26 == (c1_u8 *)0x0) {
      token = (char *)0x0;
    }
    else {
      token = token_init(pcVar26,'\"',&g_yylval);
    }
    pcVar24 = (c1xx_token *)lex_lookahead_decl_specifiers(token);
    g_compile_flags_c4 = g_compile_flags_c4 & 0x7fffffff;
    pcVar13 = token_value_address(pcVar24);
    pcVar39 = value_base + 1;
    lVar45 = g_enum_value;
    for (iVar34 = 9; iVar34 != 0; iVar34 = iVar34 + -1) {
      g_enum_value = lVar45;
      pcVar39->words[0] = pcVar13->words[0];
      pcVar13 = (c1_yy_value *)(pcVar13->words + 1);
      pcVar39 = (c1_yy_value *)(pcVar39->words + 1);
      lVar45 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0x85:
    iVar34 = browse_end_global_block();
    *(int *)((int)value_base + 0x40) = iVar34;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x86:
    pcVar30 = class_end_definition();
    *(c1_type **)((int)value_base + 0x40) = pcVar30;
    class_begin_deferred_member_bodies();
    lVar45 = g_enum_value;
    if (g_yy_lookahead == (byte *)0x0) {
      g_yy_lookahead = token_next((c1_token_reader *)&g_token_position);
      lVar45 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0x87:
    class_reset_member_function_class();
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x88:
    if ((code *)pcVar13->words[8] != (code *)0x0) {
      (*(code *)pcVar13->words[8])();
    }
    class_begin_definition((pcVar13->spec).type_sym,(pcVar13->spec).type);
    class_end_member_list();
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x8a:
    if (*(code **)((int)pcVar13 + 0x48) != (code *)0x0) {
      (**(code **)((int)pcVar13 + 0x48))();
    }
    class_begin_definition(*(c1_symbol **)((int)pcVar13 + 0x44),*(c1_type **)((int)pcVar13 + 0x40));
    g_compile_flags_c4 = g_compile_flags_c4 | 3;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x8b:
    if (g_yy_lookahead == (byte *)0x0) {
      g_yy_lookahead = token_next((c1_token_reader *)&g_token_position);
    }
    cVar10 = lex_token_code((c1xx_token *)g_yy_lookahead);
    if (cVar10 != 'u') {
      lex_token_code((c1xx_token *)g_yy_lookahead);
      diag_error(0x265);
      pcVar24 = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
      g_yy_lookahead = &parse_skip_tokens_to_one_of(pcVar24)->code;
      cVar10 = lex_token_code((c1xx_token *)g_yy_lookahead);
      if (cVar10 == '\x7f') {
        lex_unget_token((c1xx_token *)g_yy_lookahead);
        pcVar24 = token_static_for_code(0x7b);
        token_source_unget((c1_token_reader *)&g_token_position,pcVar24);
        g_yy_lookahead = &token_static_for_code(0x75)->code;
      }
    }
    g_compile_flags_c4 = g_compile_flags_c4 & 0xfffffffc;
    class_end_member_list();
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x8d:
  case 0x8e:
  case 0x1a5:
    g_compile_flags_c4 = g_compile_flags_c4 & 0xfffffffe;
    goto switchD_10421905_caseD_1;
  case 0x8f:
    if ((code *)pcVar13->words[8] != (code *)0x0) {
      (*(code *)pcVar13->words[8])();
    }
    pcVar29 = (c1_symbol *)sym_name((c1_symbol *)(pcVar13->spec).type);
    lVar45 = g_enum_value;
    if (g_pragma_mintypeinfo != '\0') {
      sym_detail_set_flag3f_bit3(pcVar29);
      lVar45 = g_enum_value;
    }
    if ((g_browse_file != (char *)0x0) && ((g_block_depth == '\0' || (g_opt_FR_browse != 0)))) {
      g_enum_value = lVar45;
      cVar10 = sym_flags3_bit0(pcVar29);
      lVar45 = g_enum_value;
      if (cVar10 == '\0') {
        (*g_il_emitter->vtbl->begin_block)();
        pcVar5 = g_il_emitter->vtbl;
        iVar34 = sym_name(pcVar29);
        iVar34 = (*pcVar5->mark_definition)(0,iVar34);
        if (iVar34 == 0) {
          (*g_il_emitter->vtbl->define_symbol)(g_il_emitter,pcVar29);
        }
        (*g_il_emitter->vtbl->set_owner)((int)pcVar29);
        lVar45 = g_enum_value;
      }
    }
    goto switchD_10421905_caseD_1;
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
    goto switchD_10421905_caseD_1;
  case 0x97:
  case 0x9e:
    class_check_base_defined
              ((pcVar13->spec).spec[0] & 3,(pcVar13->spec).spec[0] >> 2 & 0xffffff01,value_top->name
               ,0);
    g_compile_flags_c4 = g_compile_flags_c4 | 1;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x98:
    bVar11 = (pcVar13->spec).spec[0];
    pcVar29 = (c1_symbol *)sym_name(value_top->sym);
    class_check_base_class(bVar11 & 3,bVar11 >> 2 & 1,pcVar29);
    goto LAB_10420ed7;
  case 0x99:
    pcVar29 = value_word0(value_top->cell);
    access_check_member(pcVar29);
    bVar11 = (pcVar13->spec).spec[0];
    iVar34 = 0;
    pcVar29 = value_word0(value_top->cell);
    uVar47 = SUB41(pcVar29,0);
    uVar49 = (undefined1)((uint)pcVar29 >> 8);
    uVar51 = (undefined2)((uint)pcVar29 >> 0x10);
    uVar55 = CONCAT31((int3)((uint)extraout_ECX >> 8),bVar11 >> 2) & 0xffffff01;
    uVar48 = (undefined1)uVar55;
    uVar50 = (undefined1)(uVar55 >> 8);
    uVar40 = (undefined2)(uVar55 >> 0x10);
    goto LAB_10466526;
  case 0x9a:
  case 0xa1:
    parse_yyerrok(parser);
    uVar55 = 0x75;
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
    goto switchD_10421905_caseD_1;
  case 0x9f:
    pcVar29 = value_word0(value_top->cell);
    access_check_member(pcVar29);
    bVar11 = (pcVar13->spec).spec[0];
    iVar34 = 1;
    pcVar29 = value_word0(value_top->cell);
    uVar47 = SUB41(pcVar29,0);
    uVar49 = (undefined1)((uint)pcVar29 >> 8);
    uVar51 = (undefined2)((uint)pcVar29 >> 0x10);
    uVar55 = CONCAT31((int3)((uint)pcVar29 >> 8),bVar11 >> 2) & 0xffffff01;
    uVar48 = (undefined1)uVar55;
    uVar50 = (undefined1)(uVar55 >> 8);
    uVar40 = (undefined2)(uVar55 >> 0x10);
LAB_10466526:
    class_check_base_of_symbol
              (bVar11 & 3,CONCAT22(uVar40,CONCAT11(uVar50,uVar48)),
               (c1_symbol *)CONCAT22(uVar51,CONCAT11(uVar49,uVar47)),iVar34);
LAB_10420ed7:
    g_compile_flags_c4 = g_compile_flags_c4 | 1;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xa0:
    diag_error(0x348);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xa2:
    value_base[1].spec.spec[0] = value_base[1].spec.spec[0] & 0xe0;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xa3:
    bVar11 = value_base[1].spec.spec[0];
    if ((bVar11 & 3) == 0) {
      value_base[1].spec.spec[0] =
           ((byte)g_tree_op_to_il_op[(value_top->spec).spec[0]] ^ bVar11) & 3 ^ bVar11;
      lVar45 = g_enum_value;
    }
    else if ((bVar11 & 8) == 0) {
      diag_error(0x1f6);
      value_base[1].spec.spec[0] = value_base[1].spec.spec[0] | 8;
      lVar45 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
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
    goto switchD_10421905_caseD_1;
  case 0xa7:
  case 0xa8:
    diag_error(0x2f8);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xa9:
    lVar45 = enum_warn_value_wrapped(lVar45,value_top->ptr);
    acStack_24[1] = 0x10420f95;
    g_enum_value = lVar45;
    enum_declare(value_top->name,g_current_enum_type,(c1_u32)lVar45,(int)((ulonglong)lVar45 >> 0x20)
                );
    g_compile_flags_c4 = g_compile_flags_c4 | 1;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xaa:
    if ((g_compile_flags_cc & 0x100000) != 0) {
      pcVar24 = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
      pcVar24 = parse_skip_tokens_to_one_of(pcVar24);
      token_source_unget((c1_token_reader *)&g_token_position,pcVar24);
      g_yylval = (uint)g_type_int;
      _g_yylval_word2 = 1;
      _g_yylval_word3 = 0;
      pcVar29 = value_word0((c1_symbol **)&g_token_arena_index);
      pcVar26 = arena_or_pool_alloc(0x30,(int)pcVar29);
      if (pcVar26 == (c1_u8 *)0x0) goto LAB_10466f79;
      g_yy_lookahead = token_init(pcVar26,'e',&g_yylval);
      lVar45 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0xab:
    enum_declare(pcVar13[-2].name,g_current_enum_type,value_top->words[0],
                 *(int *)((int)pcVar13 + 0x2c));
    if (((g_prototype_scope_depth == 0) && ((g_compile_flags_c4 & 0x8000000) == 0)) &&
       ((g_paren_depth == 0 &&
        (((g_compile_flags_c8 & 0x40000000) == 0 && ((g_compile_flags_cc & 8) == 0)))))) {
      arena_reset(5);
    }
    g_compile_flags_c4 = g_compile_flags_c4 | 1;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
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
    goto switchD_10421905_caseD_1;
  case 0xaf:
    pcVar41 = (c1_u32 *)&stack0x000000dc;
    for (iVar34 = 9; iVar34 != 0; iVar34 = iVar34 + -1) {
      *pcVar41 = pcVar13->words[0];
      pcVar41 = pcVar41 + 1;
      pcVar13 = (c1_yy_value *)(pcVar13->words + 1);
    }
    pcVar31 = decl_declarator_alloc();
    if (pcVar31 == (c1_declarator *)0x0) {
      pcVar31 = (c1_declarator *)0x0;
    }
    else {
      pcVar31 = declarator_set_position(pcVar31);
    }
    decl_declarator_set_specifiers(pcVar31,(c1xx_decl_specifiers *)&stack0x000000dc);
    class_begin_member_list(pcVar31,(c1xx_decl_specifiers *)&stack0x000000dc,(c1_symbol **)0x0);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xb1:
    pcVar13 = pcVar13 + -1;
    pcVar41 = (c1_u32 *)&stack0x00000148;
    for (iVar34 = 9; iVar34 != 0; iVar34 = iVar34 + -1) {
      *pcVar41 = pcVar13->words[0];
      pcVar13 = (c1_yy_value *)(pcVar13->words + 1);
      pcVar41 = pcVar41 + 1;
    }
    class_check_unnamed_class_member((c1xx_decl_specifiers *)&stack0x00000148);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xb3:
    if ((((c1_symbol_tail *)pcVar13->declarator->unk2c)->fn).op_token == '\x01') {
      cVar9 = value_byte1_bit4((c1_symbol *)pcVar13->declarator);
      lVar45 = g_enum_value;
      if (cVar9 == '\0') {
        cVar9 = value_byte1_bit5(pcVar13->sym);
        lVar45 = g_enum_value;
        if ((cVar9 == '\0') &&
           ((((c1_symbol_tail *)pcVar13->declarator->unk2c)->fn).special_kind == '\0')) {
          sym_name((c1_symbol *)pcVar13->declarator);
          diag_warning(1);
          lVar45 = g_enum_value;
        }
      }
    }
    goto switchD_10421905_caseD_1;
  case 0xb4:
    class_set_current_access((c1_u8)g_tree_op_to_il_op[(pcVar13->spec).spec[0]]);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xb5:
    lex_token_code((c1xx_token *)g_yy_lookahead);
    diag_error(0x140);
    class_set_current_access((c1_u8)g_tree_op_to_il_op[(value_top->spec).spec[0]]);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xb7:
    diag_error(0x14e);
    lex_skip_to_closing_brace('\x01');
    goto LAB_10466782;
  case 0xb9:
    diag_error(0xee);
LAB_10466782:
    if ((g_compile_flags_c8 & 0x40000000) != 0) {
      pcVar24 = (c1xx_token *)lex_peek_token((uint *)&g_token_position);
      cVar10 = lex_token_code(pcVar24);
      if (cVar10 == 0xf7) {
        iVar34 = token_reader_top_kind((c1_token_reader *)&g_token_position);
joined_r0x1046681a:
        if (iVar34 == 0) {
          diag_fatal_simple(0xc9);
        }
      }
    }
LAB_1046681c:
    parse_yyerrok(parser);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xba:
    diag_error(0x14e);
    lex_skip_to_closing_brace('\0');
    if ((g_compile_flags_c8 & 0x40000000) != 0) {
      pcVar24 = (c1xx_token *)lex_peek_token((uint *)&g_token_position);
      cVar10 = lex_token_code(pcVar24);
      if (cVar10 != 0xf7) goto LAB_1046681c;
      iVar34 = token_reader_top_kind((c1_token_reader *)&g_token_position);
      goto joined_r0x1046681a;
    }
    goto LAB_1046681c;
  case 0xbe:
  case 0xcd:
    diag_warning(1,0xe4);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xbf:
    g_yy_lookahead = &parse_skip_tokens_to_one_of((c1xx_token *)g_yy_lookahead)->code;
    cVar10 = lex_token_code((c1xx_token *)g_yy_lookahead);
    if (cVar10 != '\x7f') {
      lex_unget_token((c1xx_token *)g_yy_lookahead);
      g_yy_lookahead = &token_static_for_code(0x7f)->code;
    }
    parse_yyerrok(parser);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
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
    goto switchD_10421905_caseD_1;
  case 0xc1:
    pcVar29 = decl_declarator_symbol(value_top->declarator);
    if (pcVar29 == (c1_symbol *)0x0) {
      declarator_set_kind(value_top->declarator,2);
      g_declarator_paren_base = g_declarator_paren_base + -1;
      pcVar53 = decl_specifiers_current();
      pcVar32 = decl_declarator_record(value_top->declarator);
      decl_check_conversion_return_type(pcVar32,pcVar53);
      pcVar32 = decl_declarator_record(value_top->declarator);
      decl_finish_declarator(pcVar32);
      pcVar53 = decl_specifiers_current();
      decl_declarator_set_specifiers(value_top->declarator,pcVar53);
      ppcVar52 = (c1_symbol **)0x0;
      pcVar53 = decl_specifiers_current();
      cVar9 = class_begin_member_list(value_top->declarator,pcVar53,ppcVar52);
      if (cVar9 == '\0') {
        scope_pop_to_kind_if_needed(g_current_scope,'\x01');
      }
      pcVar29 = decl_declarator_symbol(value_top->declarator);
      value_base[1].sym = pcVar29;
      lVar45 = g_enum_value;
    }
    else {
      pcVar29 = decl_declarator_symbol(value_top->declarator);
      value_base[1].sym = pcVar29;
      lVar45 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0xc2:
    pcVar22 = expr_resolve_address_of_overload(value_top->node);
    bVar11 = expr_is_zero_constant(pcVar22);
    if (bVar11 == 0) {
      diag_error(0x102);
    }
    declarator_set_flags56_bit1(pcVar13->declarator,'\x01');
    declarator_set_kind(pcVar13->declarator,2);
    g_declarator_paren_base = g_declarator_paren_base + -1;
    pcVar53 = decl_specifiers_current();
    pcVar32 = decl_declarator_record(pcVar13->declarator);
    decl_check_conversion_return_type(pcVar32,pcVar53);
    pcVar32 = decl_declarator_record(pcVar13->declarator);
    decl_finish_declarator(pcVar32);
    pcVar53 = decl_specifiers_current();
    decl_declarator_set_specifiers(pcVar13->declarator,pcVar53);
    ppcVar52 = (c1_symbol **)0x0;
    pcVar53 = decl_specifiers_current();
    cVar9 = class_begin_member_list(pcVar13->declarator,pcVar53,ppcVar52);
    if (cVar9 == '\0') {
      scope_pop_to_kind_if_needed(g_current_scope,'\x01');
    }
    pcVar29 = decl_declarator_symbol(pcVar13->declarator);
    value_base[1].sym = pcVar29;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xc4:
    declarator_set_kind(pcVar13[-1].declarator,1);
    iVar34 = *(int *)((int)pcVar13 + 0x2c);
    cVar27 = value_top->words[0];
    uVar48 = (undefined1)cVar27;
    uVar50 = (undefined1)(cVar27 >> 8);
    uVar40 = (undefined2)(cVar27 >> 0x10);
    pcVar29 = decl_declarator_symbol(pcVar13[-1].declarator);
    cVar10 = type_check_bitfield_width(pcVar29,CONCAT22(uVar40,CONCAT11(uVar50,uVar48)),iVar34);
    decl_set_bitfield_width(pcVar13[-1].declarator,cVar10);
    g_declarator_paren_base = g_declarator_paren_base + -1;
    pcVar53 = decl_specifiers_current();
    pcVar32 = decl_declarator_record(pcVar13[-1].declarator);
    decl_check_conversion_return_type(pcVar32,pcVar53);
    pcVar32 = decl_declarator_record(pcVar13[-1].declarator);
    decl_finish_declarator(pcVar32);
    pcVar53 = decl_specifiers_current();
    decl_declarator_set_specifiers(pcVar13[-1].declarator,pcVar53);
    ppcVar52 = (c1_symbol **)0x0;
    pcVar53 = decl_specifiers_current();
    cVar9 = class_begin_member_list(pcVar13[-1].declarator,pcVar53,ppcVar52);
    if (cVar9 == '\0') {
      scope_pop_to_kind_if_needed(g_current_scope,'\x01');
    }
    pcVar29 = decl_declarator_symbol(pcVar13[-1].declarator);
    value_base[1].sym = pcVar29;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xc5:
    pcVar31 = decl_declarator_alloc();
    if (pcVar31 == (c1_declarator *)0x0) {
      pcVar31 = (c1_declarator *)0x0;
    }
    else {
      pcVar31 = decl_declarator_init(pcVar31,g_name_alignment_member,1,(c1_overload_set *)0x0);
    }
    iVar34 = *(int *)((int)pcVar13 + 0x2c);
    cVar27 = value_top->words[0];
    uVar48 = (undefined1)cVar27;
    uVar50 = (undefined1)(cVar27 >> 8);
    uVar40 = (undefined2)(cVar27 >> 0x10);
    pcVar29 = decl_declarator_symbol(pcVar31);
    cVar10 = type_check_bitfield_width(pcVar29,CONCAT22(uVar40,CONCAT11(uVar50,uVar48)),iVar34);
    decl_set_bitfield_width(pcVar31,cVar10);
    declarator_set_flags54_bit5(pcVar31,'\x01');
    pcVar53 = decl_specifiers_current();
    pcVar32 = decl_declarator_record(pcVar31);
    decl_check_conversion_return_type(pcVar32,pcVar53);
    pcVar32 = decl_declarator_record(pcVar31);
    decl_finish_declarator(pcVar32);
    pcVar53 = decl_specifiers_current();
    decl_declarator_set_specifiers(pcVar31,pcVar53);
    ppcVar52 = (c1_symbol **)0x0;
    pcVar53 = decl_specifiers_current();
    class_begin_member_list(pcVar31,pcVar53,ppcVar52);
    pcVar29 = decl_declarator_symbol(pcVar31);
    value_base[1].sym = pcVar29;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xc6:
    scope_pop_to_kind_if_needed(g_current_scope,'\x01');
    pcVar29 = decl_declarator_symbol(value_top->declarator);
    value_base[1].sym = pcVar29;
    pvVar21 = qualname_resolved_symbol(value_top->declarator);
    pcVar31 = (c1_declarator *)value_top->cell;
    if (pvVar21 == (void *)0x0) {
LAB_104668f9:
      value_word0((c1_symbol **)pcVar31);
      diag_error(0x369);
      lVar45 = g_enum_value;
    }
    else {
      pbVar15 = qualname_resolved_symbol(pcVar31);
      ns_member_using_declaration(pbVar15);
      lVar45 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 199:
    ns_member_using_declaration(*(byte **)((int)pcVar13 + 0x44));
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xca:
    cVar10 = lex_token_code((c1xx_token *)g_yy_lookahead);
    lVar45 = g_enum_value;
    if (cVar10 == '6') {
      pcVar29 = value_word0(value_top->cell);
      iVar34 = class_is_innermost_being_defined((int)pcVar29);
      lVar45 = g_enum_value;
      if ((char)iVar34 != '\0') {
        declarator_set_kind(value_top->declarator,2);
        g_declarator_paren_base = g_declarator_paren_base + -1;
        pcVar53 = decl_specifiers_current();
        pcVar32 = decl_declarator_record(value_top->declarator);
        decl_check_conversion_return_type(pcVar32,pcVar53);
        pcVar32 = decl_declarator_record(value_top->declarator);
        decl_finish_declarator(pcVar32);
        pcVar53 = decl_specifiers_current();
        decl_declarator_set_specifiers(value_top->declarator,pcVar53);
        g_yy_lookahead = (byte *)lex_unget_token((c1xx_token *)g_yy_lookahead);
        ppcVar52 = (c1_symbol **)0x0;
        pcVar53 = decl_specifiers_current();
        cVar9 = class_begin_member_list(value_top->declarator,pcVar53,ppcVar52);
        lVar45 = g_enum_value;
        if (cVar9 == '\0') {
          scope_pop_to_kind_if_needed(g_current_scope,'\x01');
          lVar45 = g_enum_value;
        }
      }
    }
    goto switchD_10421905_caseD_1;
  case 0xce:
    g_declarator_paren_base = g_declarator_paren_base + -1;
    pcVar53 = decl_specifiers_current();
    pcVar32 = decl_declarator_record(value_top->declarator);
    decl_check_conversion_return_type(pcVar32,pcVar53);
    pcVar32 = decl_declarator_record(value_top->declarator);
    decl_finish_declarator(pcVar32);
    pcVar53 = decl_specifiers_current();
    decl_declarator_set_specifiers(value_top->declarator,pcVar53);
    if (((g_compile_flags_c8 & 0x40) == 0) && ((g_compile_flags_cc & 0x200000) == 0)) {
      pcVar53 = decl_specifiers_current();
      decl_declare_from_declarator(value_top->declarator,pcVar53->spec);
    }
    scope_pop_to_kind_if_needed(g_current_scope,'\x01');
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xcf:
    if (g_opt_Zg == '\0') {
      pcVar29 = decl_declarator_symbol(pcVar13->declarator);
      cVar9 = decl_check_function_style_initializer(pcVar29);
      if (cVar9 == '\0') {
        g_declarator_paren_base = g_declarator_paren_base + -1;
        decl_set_has_initializer(pcVar13->declarator,'\x01');
        pcVar53 = decl_specifiers_current();
        pcVar32 = decl_declarator_record(pcVar13->declarator);
        decl_check_conversion_return_type(pcVar32,pcVar53);
        pcVar32 = decl_declarator_record(pcVar13->declarator);
        decl_finish_declarator(pcVar32);
        pcVar53 = decl_specifiers_current();
        decl_declarator_set_specifiers(pcVar13->declarator,pcVar53);
        pcVar53 = decl_specifiers_current();
        pcVar29 = decl_declare_and_check(pcVar13->declarator,pcVar53->spec);
        decl_record_set_symbol(pcVar13->ptr,pcVar29);
        pcVar29 = decl_declarator_symbol(pcVar13->declarator);
        pcVar29 = (c1_symbol *)decl_begin_initialized_definition(pcVar29);
        decl_record_set_symbol(pcVar13->ptr,pcVar29);
        pcVar29 = decl_declarator_symbol(pcVar13->declarator);
        if (pcVar29 != (c1_symbol *)0x0) {
          pcVar29 = decl_declarator_symbol(pcVar13->declarator);
          init_set_target_symbol(pcVar29);
          pcVar22 = value_top->node;
          pcVar29 = decl_declarator_symbol(pcVar13->declarator);
          decl_finish_initialization(pcVar29,pcVar22);
          scope_pop_to_kind_if_needed(g_current_scope,'\x01');
          pcVar31 = pcVar13->declarator;
          goto LAB_10421651;
        }
      }
    }
    goto LAB_10422a54;
  case 0xd1:
    if ((g_opt_Zg != '\0') || (pcVar13[-1].words[0] == 0)) goto LAB_10422a54;
    pcVar22 = value_top->node;
    if ((pcVar22 != (c1_node *)0x0) && (pcVar22->op == 0xe8)) {
      pcVar22 = property_build_access('\x01',pcVar22,(c1_node *)0x0);
      value_top->node = pcVar22;
    }
    pcVar29 = decl_declarator_symbol(pcVar13[-1].declarator);
    init_set_target_symbol(pcVar29);
    g_compile_flags_c8 = g_compile_flags_c8 | 0x80000;
    g_compile_flags_cc = g_compile_flags_cc | 0x80000;
    pcVar22 = expr_resolve_address_of_overload(value_top->node);
    pcVar29 = decl_declarator_symbol(pcVar13[-1].declarator);
    decl_finish_initialization(pcVar29,pcVar22);
    g_compile_flags_cc = g_compile_flags_cc & 0xfff7ffff;
    g_compile_flags_c8 = g_compile_flags_c8 & 0xfff7ffff;
    scope_pop_to_kind_if_needed(g_current_scope,'\x01');
    pcVar31 = pcVar13[-1].declarator;
LAB_10421651:
    pcVar29 = decl_declarator_symbol(pcVar31);
    type_check_destructible_2(pcVar29);
    g_string_literal_cur = &g_string_literal_buffer;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xd2:
    if (g_opt_Zg == '\0') {
      cVar9 = '\0';
      pcVar29 = decl_declarator_symbol(value_top->declarator);
      init_begin(pcVar29,cVar9);
      g_compile_flags_cc = g_compile_flags_cc | 0x80000;
      g_brace_init_active = 1;
      lVar45 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0xd3:
    pcVar29 = decl_declarator_symbol(pcVar13[-4].declarator);
    init_finish(pcVar29);
    g_compile_flags_cc = g_compile_flags_cc & 0xfff7ffff;
    if (g_opt_Zg == '\0') {
      pcVar29 = decl_declarator_symbol(pcVar13[-4].declarator);
      type_check_destructible_2(pcVar29);
    }
    scope_pop_to_kind_if_needed(g_current_scope,'\x01');
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xd4:
    pcVar53 = decl_specifiers_current();
    pcVar32 = decl_declarator_record(pcVar13->declarator);
    decl_check_conversion_return_type(pcVar32,pcVar53);
    pcVar32 = decl_declarator_record(pcVar13->declarator);
    decl_finish_declarator(pcVar32);
    pcVar53 = decl_specifiers_current();
    decl_declarator_set_specifiers(pcVar13->declarator,pcVar53);
    g_declarator_paren_base = g_declarator_paren_base + -1;
    lVar45 = g_enum_value;
    if (g_opt_Zg == '\0') {
      decl_set_has_initializer(pcVar13->declarator,'\x01');
      pcVar53 = decl_specifiers_current();
      decl_declarator_set_specifiers(pcVar13->declarator,pcVar53);
      pcVar53 = decl_specifiers_current();
      pcVar29 = decl_declare_and_check(pcVar13->declarator,pcVar53->spec);
      decl_record_set_symbol(pcVar13->ptr,pcVar29);
      pcVar29 = decl_declarator_symbol(pcVar13->declarator);
      decl_begin_initialized_definition(pcVar29);
      g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] | 2;
      lVar45 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0xd5:
    decl_specifiers_current();
    diag_error(0x201);
    value_base[1].words[0] = 0;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xd8:
    if (g_opt_Zg == '\0') {
      iVar34 = 0;
      pcVar22 = expr_resolve_address_of_overload(value_top->node);
      init_process_initializer(pcVar22,iVar34);
    }
    g_string_literal_cur = &g_string_literal_buffer;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xd9:
    if (g_opt_Zg == '\0') {
      init_check_too_many_2();
      lVar45 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0xda:
    if (g_opt_Zg == '\0') {
      init_pop_brace_level();
      lVar45 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
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
      goto switchD_10421905_caseD_1;
    case '6':
    case 'u':
    case 0xa6:
      bVar44 = g_paren_depth == 0;
      goto LAB_10421837;
    case 'j':
    case '~':
      bVar44 = g_paren_depth != 0;
LAB_10421837:
      if (bVar44) goto switchD_10421905_caseD_1;
      break;
    case '\x7f':
      if ((g_paren_depth == 0) || ((g_paren_level_flags[g_paren_depth] & 8) == 0))
      goto switchD_10421905_caseD_1;
    }
    bVar11 = (-(g_paren_depth != 0) & 0xb8U) + 0x7f;
    in_stack_00000034 = CONCAT31(in_stack_00000034._1_3_,bVar11);
    parse_report_inserted_token(g_yy_lookahead,(uint)bVar11);
    lex_unget_token((c1xx_token *)g_yy_lookahead);
    g_yy_lookahead = &token_static_for_code(in_stack_00000034)->code;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xdc:
  case 0x11a:
    g_declarator_paren_base = g_declarator_paren_base + 1;
    goto switchD_10421905_caseD_1;
  case 0xdd:
    pvVar21 = value_top->ptr;
    piVar19 = decl_declarator_record(value_base[1].declarator);
    decl_append_function_layer(piVar19,pvVar21);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xde:
    pcVar31 = value_top->declarator;
    goto LAB_1042192a;
  case 0xe0:
    if (pcVar13->node == (c1_node *)0x0) {
      in_stack_00000020 = 0;
    }
    else {
      in_stack_00000020 = expr_eval_constant_expression(pcVar13->node);
      if (((g_class_depth < 0) || (g_ms_extensions == '\0')) && (in_stack_00000020 == 0)) {
        iVar34 = yyparse_cpp_zero_array_bound_error
                           (value_base,parser,state_sp,0,saved_lookahead,saved_rule);
        return iVar34;
      }
    }
    piVar19 = (int *)&stack0x00000020;
    pcVar32 = decl_declarator_record(value_base[1].declarator);
    decl_append_array_layer(pcVar32,piVar19);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xe1:
  case 0x125:
  case 0x175:
    value_base[1].words[0] = pcVar13->words[0];
    lVar45 = g_enum_value;
  case 0x17f:
    g_enum_value = lVar45;
    parse_paren_depth_pop();
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xe2:
    pcVar31 = value_top->declarator;
    pcVar32 = decl_declarator_record(pcVar31);
    type_check_based_form(pcVar32,&pcVar13->mods);
    value_base[1].node = (c1_node *)pcVar31;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xe4:
    pcVar31 = value_top->declarator;
    cVar9 = declarator_flags56_bit0(pcVar31);
    if (cVar9 != '\0') {
      pcVar53 = &g_conversion_type_specifiers;
      pcVar32 = decl_declarator_record(pcVar31);
      decl_record_set_conversion_type(pcVar32,pcVar53);
    }
    value_base[1].declarator = pcVar31;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xe5:
    pcVar31 = decl_declarator_alloc();
    if (pcVar31 == (c1_declarator *)0x0) {
LAB_10466a12:
      pcVar31 = (c1_declarator *)0x0;
    }
    else {
      pcVar31 = decl_declarator_init(pcVar31,value_top->name,0,(c1_overload_set *)0x0);
    }
    goto LAB_10421a04;
  case 0xe6:
    pcVar31 = decl_declarator_alloc();
    if (pcVar31 == (c1_declarator *)0x0) {
      pcVar31 = (c1_declarator *)0x0;
    }
    else {
      pcVar54 = (c1_overload_set *)0x0;
      uVar48 = 0;
      uVar50 = 0;
      uVar40 = 0;
      pcVar29 = value_word0(value_top->cell);
      pcVar31 = decl_declarator_init
                          (pcVar31,(fe_name *)pcVar29,CONCAT22(uVar40,CONCAT11(uVar50,uVar48)),
                           pcVar54);
    }
    pvVar21 = decl_declarator_record(value_top->declarator);
    if (pvVar21 == (void *)0x0) {
      pcVar29 = (c1_symbol *)sym_name(value_top->sym);
    }
    else {
      pcVar29 = (c1_symbol *)sym_name(value_top->sym);
    }
    iVar34 = sym_scope_index(pcVar29);
    if (iVar34 != 0) {
      pcVar29 = sym_scope_by_index(pcVar29,0x1c);
      decl_record_set_qualifying_class(pcVar31,pcVar29);
    }
    goto LAB_10421a04;
  case 0xe7:
    pcVar31 = decl_declarator_alloc();
    if (pcVar31 == (c1_declarator *)0x0) goto LAB_10466a12;
    pcVar54 = (c1_overload_set *)0x0;
    uVar48 = 0;
    uVar50 = 0;
    uVar40 = 0;
    pfVar28 = sym_name_of_ref(value_top->cell);
    pcVar31 = decl_declarator_init(pcVar31,pfVar28,CONCAT22(uVar40,CONCAT11(uVar50,uVar48)),pcVar54)
    ;
LAB_10421a04:
    cVar9 = class_name_is_current_class(pcVar31);
    if (cVar9 == '\0') {
LAB_10421a0f:
      value_base[1].declarator = pcVar31;
      lVar45 = g_enum_value;
    }
    else {
      decl_set_is_constructor(pcVar31,'\x01');
      value_base[1].declarator = pcVar31;
      lVar45 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0xe8:
  case 0x1b2:
    goto switchD_10421905_caseD_e5;
  case 0xe9:
    pcVar31 = decl_declarator_alloc();
    if (pcVar31 == (c1_declarator *)0x0) {
      pcVar31 = (c1_declarator *)0x0;
    }
    else {
      pcVar31 = decl_declarator_init(pcVar31,value_top->name,0,(c1_overload_set *)0x0);
    }
    cVar9 = class_name_is_current_class(pcVar31);
    if (cVar9 == '\0') {
      if (-1 < g_class_depth) goto LAB_10466aa7;
LAB_10466b25:
      value_word0((c1_symbol **)pcVar31);
LAB_10466b2d:
      diag_error(0x24c);
      value_base[1].declarator = pcVar31;
      lVar45 = g_enum_value;
    }
    else {
      decl_set_is_destructor(pcVar31,'\x01');
      value_base[1].declarator = pcVar31;
      lVar45 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0xea:
    pcVar29 = value_word0(value_top->cell);
    pcVar31 = decl_declarator_alloc();
    if (pcVar31 == (c1_declarator *)0x0) {
      pcVar31 = (c1_declarator *)0x0;
    }
    else {
      pcVar31 = decl_declarator_init(pcVar31,(fe_name *)pcVar29,0,(c1_overload_set *)0x0);
    }
    cVar9 = class_name_is_current_class(pcVar31);
    if (cVar9 == '\0') {
      if (g_class_depth < 0) goto LAB_10466b2d;
      goto LAB_10466aa7;
    }
    goto LAB_10421ad0;
  case 0xeb:
    pcVar31 = decl_declarator_alloc();
    if (pcVar31 == (c1_declarator *)0x0) {
      pcVar31 = (c1_declarator *)0x0;
    }
    else {
      pcVar54 = (c1_overload_set *)0x0;
      uVar48 = 0;
      uVar50 = 0;
      uVar40 = 0;
      pfVar28 = sym_name_of_ref(value_top->cell);
      pcVar31 = decl_declarator_init
                          (pcVar31,pfVar28,CONCAT22(uVar40,CONCAT11(uVar50,uVar48)),pcVar54);
    }
    cVar9 = class_name_is_current_class(pcVar31);
    if (cVar9 != '\0') goto LAB_10421ad0;
    if (g_class_depth < 0) goto LAB_10466b25;
LAB_10466aa7:
    diag_error(0x20b);
    pvVar21 = class_current_definition_name();
    decl_set_name(pcVar31,pvVar21);
LAB_10421ad0:
    decl_set_is_destructor(pcVar31,'\x01');
    value_base[1].declarator = pcVar31;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xec:
    pcVar31 = decl_declarator_alloc();
    if (pcVar31 == (c1_declarator *)0x0) {
      value_set_byte30((c1_declarator *)0x0,(value_top->spec).spec[0]);
      value_base[1].words[0] = 0;
      lVar45 = g_enum_value;
    }
    else {
      pcVar31 = decl_declarator_init
                          (pcVar31,*(fe_name **)((int)pcVar13 + 0x2c),0,(c1_overload_set *)0x0);
      value_set_byte30(pcVar31,(value_top->spec).spec[0]);
      value_base[1].declarator = pcVar31;
      lVar45 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0xed:
    pcVar53 = &g_conversion_type_specifiers;
    for (iVar34 = 9; iVar34 != 0; iVar34 = iVar34 + -1) {
      *(c1_u32 *)pcVar53->spec = value_top->words[0];
      value_top = (c1_yy_value *)(value_top->words + 1);
      pcVar53 = (c1xx_decl_specifiers *)(pcVar53->spec + 4);
    }
    pcVar31 = decl_declarator_alloc();
    if (pcVar31 == (c1_declarator *)0x0) {
      pcVar31 = (c1_declarator *)0x0;
    }
    else {
      pcVar54 = (c1_overload_set *)0x0;
      uVar48 = 0;
      uVar50 = 0;
      uVar40 = 0;
      pfVar28 = decl_conversion_function_name(g_conversion_type_specifiers.type);
      pcVar31 = decl_declarator_init
                          (pcVar31,pfVar28,CONCAT22(uVar40,CONCAT11(uVar50,uVar48)),pcVar54);
    }
    value_set_byte30(pcVar31,0x8f);
    declarator_set_flags56_bit0(pcVar31,'\x01');
    g_compile_flags_c4 = g_compile_flags_c4 & 0xfffffffb;
    value_base[1].declarator = pcVar31;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xee:
    if (value_top->cell == (c1_symbol **)0x0) {
      d.sym = (c1_symbol *)0x0;
      in_stack_00000018.sym = d.sym;
    }
    else {
      pcVar14 = value_word0(value_top->cell);
      pcVar29 = *(c1_symbol **)(*(int *)pcVar14->type + 8);
      pcVar31 = decl_declarator_alloc();
      if (pcVar31 == (c1_declarator *)0x0) {
        d.sym = (c1_symbol *)0x0;
      }
      else {
        uVar48 = 0;
        uVar50 = 0;
        uVar40 = 0;
        qualifier = pcVar14;
        pfVar28 = (fe_name *)sym_name(pcVar14);
        d.sym = (c1_symbol *)
                decl_declarator_init
                          (pcVar31,pfVar28,CONCAT22(uVar40,CONCAT11(uVar50,uVar48)),qualifier);
      }
      in_stack_00000018 = d;
      lookup_check_symbol_kinds_reversed(*(int **)pcVar14->type);
      bVar11 = pcVar14->flags1;
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
        d = in_stack_00000018;
        if ((pcVar29->kind & 0x1f) == 0x11) {
          pcVar29 = (c1_symbol *)ovl_first_function_of_set(pcVar29);
          d = in_stack_00000018;
        }
        g_conversion_type_specifiers.type = decl_declarator_record((c1_declarator *)pcVar29->type);
        puVar25 = decl_specifiers_of_symbol((uint *)&stack0x0000016c,pcVar29);
        pcVar53 = &g_conversion_type_specifiers;
        for (iVar34 = 6; iVar34 != 0; iVar34 = iVar34 + -1) {
          *(uint *)pcVar53->spec = *puVar25;
          puVar25 = puVar25 + 1;
          pcVar53 = (c1xx_decl_specifiers *)(pcVar53->spec + 4);
        }
        declarator_set_flags56_bit0(d.declarator,'\x01');
        in_stack_00000018 = d;
        lVar45 = g_enum_value;
      }
      bVar11 = pcVar29->kind & 0x1f;
      if ((((bVar11 == 0x10) || (bVar11 == 7)) ||
          ((bVar11 == 6 || (((bVar11 == 0x11 || (bVar11 == 8)) || (bVar11 == 0x1b)))))) ||
         ((bVar11 == 0x1a &&
          (((bVar11 = **(byte **)pcVar29->type & 0x1f, bVar11 == 0x10 || (bVar11 == 7)) ||
           (((bVar11 == 6 || ((bVar11 == 0x11 || (bVar11 == 8)))) || (bVar11 == 0x1b)))))))) {
        g_enum_value = lVar45;
        if (**(int **)pcVar14->type != 0) {
          pcVar14 = *(c1_symbol **)(**(int **)pcVar14->type + 8);
          if ((pcVar14->kind & 0x1f) == 0xf) {
            pcVar14 = scope_vector_get((short)pcVar14->key_ref);
          }
          if ((pcVar14->kind & 0x1f) == 4) {
            decl_record_set_qualifying_class(d.declarator,pcVar14);
            if ((g_compile_flags_cc & 0x200000) != 0) {
              declarator_set_kind(d.declarator,2);
            }
          }
        }
        bVar11 = pcVar29->kind & 0x1f;
        if (((bVar11 == 0x10) || (bVar11 == 0x11)) || (bVar11 == 0x1b)) {
          pbVar15 = ovl_first_function_of_set(pcVar29);
          value_set_byte30(d.declarator,pbVar15[0x2f]);
          value_base[1].declarator = (c1_declarator *)d;
          lVar45 = g_enum_value;
        }
        else {
          value_set_byte30(d.declarator,(pcVar29->tail).fn.op_token);
          value_base[1].declarator = (c1_declarator *)d;
          lVar45 = g_enum_value;
        }
        goto switchD_10421905_caseD_1;
      }
    }
    g_enum_value = lVar45;
    value_base[1].declarator = (c1_declarator *)d;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xef:
    if (pcVar13->cell == (c1_symbol **)0x0) {
LAB_10466c6d:
      pcVar31 = (c1_declarator *)0x0;
    }
    else {
      pcVar29 = value_word0(pcVar13->cell);
      pcVar53 = &g_conversion_type_specifiers;
      for (iVar34 = 9; iVar34 != 0; iVar34 = iVar34 + -1) {
        *(c1_u32 *)pcVar53->spec = value_top->words[0];
        value_top = (c1_yy_value *)(value_top->words + 1);
        pcVar53 = (c1xx_decl_specifiers *)(pcVar53->spec + 4);
      }
      decl_qualified_conversion_function_name(pcVar29,g_conversion_type_specifiers.type);
      if (pcVar29->type == (c1_type *)0x0) {
        pcVar31 = decl_declarator_alloc();
        if (pcVar31 == (c1_declarator *)0x0) goto LAB_10466c6d;
        pcVar54 = (c1_overload_set *)0x0;
        uVar48 = 0;
        uVar50 = 0;
        uVar40 = 0;
        pfVar28 = name_new_S();
        pcVar31 = decl_declarator_init
                            (pcVar31,pfVar28,CONCAT22(uVar40,CONCAT11(uVar50,uVar48)),pcVar54);
      }
      else {
        pcVar31 = decl_declarator_alloc();
        if (pcVar31 == (c1_declarator *)0x0) {
          pcVar31 = (c1_declarator *)0x0;
        }
        else {
          uVar48 = 0;
          uVar50 = 0;
          uVar40 = 0;
          pcVar14 = pcVar29;
          pfVar28 = (fe_name *)sym_name(pcVar29);
          pcVar31 = decl_declarator_init
                              (pcVar31,pfVar28,CONCAT22(uVar40,CONCAT11(uVar50,uVar48)),
                               (c1_overload_set *)pcVar14);
        }
        lookup_check_symbol_kinds_reversed(*(int **)pcVar29->type);
        if (**(int **)pcVar29->type != 0) {
          pcVar29 = *(c1_symbol **)(**(int **)pcVar29->type + 8);
          if ((pcVar29->kind & 0x1f) == 0xf) {
            pcVar29 = scope_vector_get((short)pcVar29->key_ref);
          }
          decl_record_set_qualifying_class(pcVar31,pcVar29);
        }
        value_set_byte30(pcVar31,0x8f);
        declarator_set_flags56_bit0(pcVar31,'\x01');
        if ((g_compile_flags_cc & 0x200000) != 0) {
          declarator_set_kind(pcVar31,2);
        }
      }
    }
    g_compile_flags_c4 = g_compile_flags_c4 & 0xfffffffb;
    value_base[1].declarator = pcVar31;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xf0:
    pcVar13 = value_base + 1;
    decl_conversion_function_declarator(&pcVar13->spec,(c1_decl_record *)0x0);
    (pcVar13->spec).spec[0] = (pcVar13->spec).spec[0] & 0x7f;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xf1:
    pcVar13 = value_base + 1;
    pcVar32 = decl_declarator_record(value_top->declarator);
    decl_conversion_function_declarator(&pcVar13->spec,pcVar32);
    (pcVar13->spec).spec[0] = (pcVar13->spec).spec[0] & 0x7f;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xf2:
    param_clause_set_cv_qualifiers(pcVar13[-1].params,&pcVar13->mods);
    param_clause_set_exception_spec(pcVar13[-1].params,value_top->words[0]);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xf3:
    pcVar26 = class_record_new_kind5();
    value_base[1].str.text = pcVar26;
    parse_paren_depth_pop();
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xf4:
    g_prototype_scope_depth = g_prototype_scope_depth + 1;
    g_block_depth = g_block_depth + '\x01';
    scope_new_block_record(g_current_scope,(c1_sym_list *)0x0);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xf5:
    pvVar21 = pcVar13[-1].ptr;
    value_base[1].ptr = pvVar21;
    if (pcVar13->sym != (c1_symbol *)0x0) {
      sym_list_append(pvVar21,pcVar13->sym);
    }
    g_prototype_scope_depth = g_prototype_scope_depth + -1;
    g_block_depth = g_block_depth + 0xff;
    parse_paren_depth_pop();
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xf6:
    if (((((g_block_depth == '\0') || (-1 < g_class_depth)) ||
         ((g_compile_flags_c8 & 0x10000000) != 0)) ||
        ((((g_compile_flags_c8 & 0x40000000) != 0 && ((g_compile_flags_cc & 8) == 0)) &&
         ((g_compile_flags_c4 & 0x200) == 0)))) || ((g_compile_flags_cc & 0x50) != 0)) {
      iVar34 = 0;
    }
    else {
      iVar34 = 4;
    }
    pcVar29 = sym_new_of_kind('\v',g_name_ellipsis,iVar34);
    sym_mark_ellipsis_parameter(pcVar29);
    pcVar30 = type_intern_basic_parts(0x80d,0,0);
    pcVar29->type = pcVar30;
    pcVar16 = (c1_param_clause *)arena5_alloc_1c();
    if (pcVar16 == (c1_param_clause *)0x0) {
      value_base[1].words[0] = 0;
      sym_list_append((void *)0x0,pcVar29);
      parse_paren_depth_pop();
      lVar45 = g_enum_value;
    }
    else {
      pcVar16 = optional_value_init(pcVar16,3,(c1_sym_list *)0x0,'\0');
      value_base[1].params = pcVar16;
      sym_list_append(pcVar16,pcVar29);
      parse_paren_depth_pop();
      lVar45 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0xf8:
    if (value_top->words[0] != 2) goto LAB_10467c9b;
    diag_warning(3,0x122);
    value_base[1].ptr = (void *)value_top->words[0];
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xf9:
    pcVar16 = (c1_param_clause *)arena5_alloc_1c();
    if (pcVar16 == (c1_param_clause *)0x0) goto LAB_10465f34;
    cVar9 = '\x01';
    scope = decl_declarator_record((c1_declarator *)g_current_scope);
    params = scope_symbol_list(scope);
    pcVar16 = optional_value_init(pcVar16,3,params,cVar9);
    value_base[1].params = pcVar16;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xfb:
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] | 8;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xfc:
    if ((value_top->words[0] != 0) && (g_paren_level_arg_lists[g_paren_depth] != (c1_arg_list *)0x0)
       ) {
      arena_set_expression_index(0);
      g_compile_flags_cc = g_compile_flags_cc | 0x10;
      pcVar22 = tree_append_list_item((c1_node *)0x0,(c1_node *)0x0,2);
      pcVar17 = (c1_arg_item *)arena_alloc_n_aligned(0x14,0);
      if (pcVar17 == (c1_arg_item *)0x0) {
        pcVar17 = (c1_arg_item *)0x0;
      }
      else {
        pcVar17 = arg_expression_item_init(pcVar17,pcVar22,'\0','\x01');
      }
      tmpl_argument_list_prepend(g_paren_level_arg_lists[g_paren_depth],pcVar17);
      goto LAB_10466d4e;
    }
    goto switchD_10421905_caseD_5c;
  case 0xfd:
    cVar10 = token_source_reads_source_file((c1_token_reader *)&g_token_position);
    if (cVar10 != '\0') {
      iVar34 = 0;
      pcVar37 = g_idb->vtbl;
      uVar55 = lex_line_number_of_position(&g_token_position);
      (*pcVar37->idb_scope_kind4_end)(g_idb,uVar55,iVar34);
    }
    if ((pcVar13->words[0] != 0) && (value_top->node != (c1_node *)0x0)) {
      pcVar22 = expr_resolve_address_of_overload(value_top->node);
      if ((g_compile_flags_c8 & 0x40000000) != 0) {
        pcVar22 = tree_copy_to_arena(pcVar22,0);
      }
      tree_attach_typed_link(pcVar22,pcVar13->sym->type);
      acStack_24[1] = 0x10421fe2;
      pcVar22 = conv_convert_expression(0xc6,pcVar13->sym->type,pcVar22,'\x02','\x04');
      value_top->node = pcVar22;
      iVar34 = 2;
      pcVar22 = (c1_node *)expr_finish_full_expression((int)pcVar22);
      pcVar22 = tree_append_list_item((c1_node *)0x0,pcVar22,iVar34);
      pcVar17 = (c1_arg_item *)arena_alloc_n_aligned(0x14,0);
      if (pcVar17 == (c1_arg_item *)0x0) {
        pcVar17 = (c1_arg_item *)0x0;
      }
      else {
        pcVar17 = arg_expression_item_init(pcVar17,pcVar22,'\0','\x01');
      }
      if (g_paren_level_arg_lists[g_paren_depth] == (c1_arg_list *)0x0) {
        pcVar26 = arena_alloc_n_aligned(0xc,0);
        if (pcVar26 == (c1_u8 *)0x0) {
          g_paren_level_arg_lists[g_paren_depth] = (c1_arg_list *)0x0;
        }
        else {
          pcVar18 = tmpl_argument_list_init(pcVar26,pcVar17);
          g_paren_level_arg_lists[g_paren_depth] = pcVar18;
        }
      }
      else {
        tmpl_argument_list_prepend(g_paren_level_arg_lists[g_paren_depth],pcVar17);
      }
    }
    goto joined_r0x10466e52;
  case 0xfe:
    cVar10 = token_source_reads_source_file((c1_token_reader *)&g_token_position);
    if (cVar10 != '\0') {
      iVar34 = 0;
      pcVar37 = g_idb->vtbl;
      uVar55 = lex_line_number_of_position(&g_token_position);
      (*pcVar37->idb_scope_kind4_end)(g_idb,uVar55,iVar34);
    }
    if ((g_compile_flags_c8 & 0x10000000) == 0) {
      diag_error(0x3e);
    }
    pcVar17 = (c1_arg_item *)arena_alloc_n_aligned(0x14,0);
    if (pcVar17 == (c1_arg_item *)0x0) {
      pcVar17 = (c1_arg_item *)0x0;
    }
    else {
      pcVar17 = pch_fixup_list_object_ctor(pcVar17,value_top->sym->type,'\0');
    }
    if (g_paren_level_arg_lists[g_paren_depth] == (c1_arg_list *)0x0) {
      pcVar26 = arena_alloc_n_aligned(0xc,0);
      if (pcVar26 == (c1_u8 *)0x0) {
        g_paren_level_arg_lists[g_paren_depth] = (c1_arg_list *)0x0;
      }
      else {
        pcVar18 = tmpl_argument_list_init(pcVar26,pcVar17);
        g_paren_level_arg_lists[g_paren_depth] = pcVar18;
      }
    }
    else {
      tmpl_argument_list_prepend(g_paren_level_arg_lists[g_paren_depth],pcVar17);
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
    goto switchD_10421905_caseD_1;
  case 0xff:
    cVar10 = token_source_reads_source_file((c1_token_reader *)&g_token_position);
    if (cVar10 != '\0') {
      iVar34 = 0;
      pcVar37 = g_idb->vtbl;
      uVar55 = lex_line_number_of_position(&g_token_position);
      (*pcVar37->idb_scope_kind4_end)(g_idb,uVar55,iVar34);
    }
    if ((g_compile_flags_cc & 0x100000) == 0) {
      pcVar22 = arena_alloc(g_arenas + g_expr_arena_index,0x18);
      pcVar22->kind = '\0';
      pcVar22->op = 0xc6;
      pcVar22->left = (void *)value_top->words[0];
      pcVar30 = type_intern_basic_parts(0x80e,0,0);
      value_set_field4(pcVar22,pcVar30);
      pcVar22 = tree_append_list_item((c1_node *)0x0,pcVar22,2);
      pcVar17 = (c1_arg_item *)arena_alloc_n_aligned(0x14,0);
      if (pcVar17 == (c1_arg_item *)0x0) {
        pcVar17 = (c1_arg_item *)0x0;
      }
      else {
        pcVar17 = arg_expression_item_init(pcVar17,pcVar22,'\0','\x01');
      }
      if (g_paren_level_arg_lists[g_paren_depth] == (c1_arg_list *)0x0) {
        pcVar26 = arena_alloc_n_aligned(0xc,0);
        if (pcVar26 == (c1_u8 *)0x0) {
          g_paren_level_arg_lists[g_paren_depth] = (c1_arg_list *)0x0;
        }
        else {
          pcVar18 = tmpl_argument_list_init(pcVar26,pcVar17);
          g_paren_level_arg_lists[g_paren_depth] = pcVar18;
        }
      }
      else {
        tmpl_argument_list_prepend(g_paren_level_arg_lists[g_paren_depth],pcVar17);
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
      iVar34 = 0;
      pcVar37 = g_idb->vtbl;
      uVar55 = lex_line_number_of_position(&g_token_position);
      (*pcVar37->idb_scope_kind4_end)(g_idb,uVar55,iVar34);
    }
    cVar10 = lex_token_code((c1xx_token *)g_yy_lookahead);
    if (cVar10 == 'u') {
      diag_error(0x117);
      pcVar24 = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
      parse_skip_tokens_to_one_of(pcVar24);
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
      parse_default_argument_begin(value_top->sym->type);
      func_flow_state_note_3e();
      lVar45 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0x102:
    cVar10 = token_source_reads_source_file((c1_token_reader *)&g_token_position);
    lVar45 = g_enum_value;
    if (cVar10 != '\0') {
      pcVar37 = g_idb->vtbl;
LAB_10422231:
      iVar34 = 0;
      uVar55 = lex_line_number_of_position(&g_token_position);
      (*pcVar37->idb_scope_kind3_to_4)(g_idb,uVar55,iVar34);
      lVar45 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0x104:
    scope_insert_through_object(g_current_scope,value_top->sym);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x105:
    value_base[1].words[0] = 0;
    if ((g_compile_flags_c8 & 0x30000000) == 0) {
      pcVar24 = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
      pcVar24 = parse_skip_tokens_to_one_of(pcVar24);
      g_yy_lookahead = &pcVar24->code;
LAB_10466f65:
      token_source_unget((c1_token_reader *)&g_token_position,pcVar24);
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
        pcVar24 = token_static_for_code(0x3e);
        goto LAB_10466f65;
      }
    }
    parse_yyerrok(parser);
LAB_10466f79:
    g_yy_lookahead = (byte *)0x0;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x106:
    pcVar41 = (c1_u32 *)&stack0x00000094;
    for (iVar34 = 9; iVar34 != 0; iVar34 = iVar34 + -1) {
      *pcVar41 = pcVar13->words[0];
      pcVar41 = pcVar41 + 1;
      pcVar13 = (c1_yy_value *)(pcVar13->words + 1);
    }
    decl_set_local_key_flag(value_top->declarator,'\x01');
    if (((g_compile_flags_c8 & 0x10000000) == 0) || (g_paren_depth != 1)) {
      cVar27 = 5;
    }
    else {
      cVar27 = 0xb;
    }
    declarator_set_kind(value_top->declarator,cVar27);
    pcVar53 = (c1xx_decl_specifiers *)&stack0x00000094;
    pcVar32 = decl_declarator_record(value_top->declarator);
    decl_check_conversion_return_type(pcVar32,pcVar53);
    pcVar32 = decl_declarator_record(value_top->declarator);
    decl_finish_declarator(pcVar32);
    decl_declarator_set_specifiers(value_top->declarator,(c1xx_decl_specifiers *)&stack0x00000094);
    decl_declare_in_current_scope(value_top->declarator,(c1xx_decl_specifiers *)&stack0x00000094);
    pcVar29 = decl_declarator_symbol(value_top->declarator);
    if ((g_compile_flags_c8 & 0x10000000) != 0) {
      pcVar30 = pcVar29->type;
      cVar9 = type_code_is_201(pcVar30);
      if (cVar9 == '\0') {
        cVar9 = type_code_is_202(pcVar30);
        if (cVar9 != '\0') {
          iVar34 = yyparse_cpp_class_template_parameter_error
                             (pcVar29,value_base,parser,state_sp,saved_lookahead,saved_rule);
          return iVar34;
        }
      }
      else if ((pcVar29->storage & 0x80) == 0) {
        diag_error(0x3e1);
        pcVar29->flags3 = pcVar29->flags3 | 4;
      }
    }
    g_declarator_paren_base = g_declarator_paren_base + -1;
    scope_pop_to_kind_if_needed(g_current_scope,'\x01');
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfc;
    value_base[1].sym = pcVar29;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x107:
    bVar44 = false;
    decl_set_local_key_flag(value_top->declarator,'\x01');
    if (((g_compile_flags_c8 & 0x10000000) == 0) || (g_paren_depth != 1)) {
      cVar27 = 6;
    }
    else {
      cVar27 = 0xb;
    }
    declarator_set_kind(value_top->declarator,cVar27);
    decl_set_name(value_top->declarator,g_name_formal);
    if ((((g_compile_flags_c8 & 0x10000000) != 0) && ((pcVar13->spec).type_sym != (c1_symbol *)0x0))
       && ((((pcVar13->spec).type_sym)->kind & 0x1f) == 4)) {
      pcVar30 = type_innermost_base((pcVar13->spec).type);
      if (((pcVar30->code & 0x20f) == 0x201) && (((pcVar13->spec).spec[0] & 0x80) == 0)) {
        iVar34 = sym_scope_index((pcVar13->spec).type_sym);
        if (iVar34 == 0) {
          bVar44 = true;
          pvVar21 = (void *)sym_name((pcVar13->spec).type_sym);
          if ((*(uint *)((int)pvVar21 + 8) & 0x2000000) != 0) {
            cell = lookup_name_in_context(g_current_scope,pvVar21,0x20);
            if (cell != (c1_lookup_entry *)0x0) {
              value_word0(&cell->sym);
            }
            diag_error(0x3af);
          }
          decl_set_name(value_top->declarator,pvVar21);
        }
      }
    }
    (pcVar13->spec).spec[0] = (pcVar13->spec).spec[0] & 0x7f;
    pcVar39 = pcVar13;
    pcVar32 = decl_declarator_record(value_top->declarator);
    decl_check_conversion_return_type(pcVar32,&pcVar39->spec);
    pcVar32 = decl_declarator_record(value_top->declarator);
    decl_finish_declarator(pcVar32);
    decl_declarator_set_specifiers(value_top->declarator,&pcVar13->spec);
    decl_process_declaration(value_top->declarator);
    pcVar29 = sym_new_from_declarator(value_top->declarator,0xffffffff);
    if (bVar44) {
      bVar11 = type_code_high_bit(pcVar29->type);
      if (bVar11 != 0) {
        sym_name(pcVar29);
        diag_error(0x395);
        pcVar29->flags3 = pcVar29->flags3 | 4;
      }
    }
    g_declarator_paren_base = g_declarator_paren_base + -1;
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfc;
    value_base[1].sym = pcVar29;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x108:
  case 0x10f:
    goto switchD_10421905_caseD_105;
  case 0x10b:
  case 0x112:
    qualified_type_merge(&value_base[1].mods,&value_top->mods,(c1_u32)g_yy_lookahead);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x10c:
    diag_warning(1,0xe6);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x10d:
    operator_id_set(&value_base[1].mods,(short)g_tree_op_to_il_op[(value_top->spec).spec[0]],
                    (void *)0x0);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x10e:
    value_base[1].words[0] = pcVar13->words[0];
    *(c1_u32 *)((int)value_base + 0x2c) = pcVar13->words[1];
    parse_paren_depth_pop();
    g_compile_flags_c4 = g_compile_flags_c4 & 0x7fffffff;
    lVar45 = g_enum_value;
    if ((g_compile_flags_c8 & 0x10) != 0) {
      g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfc;
      lVar45 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0x113:
    operator_id_set(&value_base[1].mods,(short)g_tree_op_to_il_op[(value_top->spec).spec[0]],
                    (void *)0x0);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x114:
    operator_id_set(&value_base[1].mods,(value_top->ptr_op).kind,(void *)0x0);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x115:
    bits = value_u16_at2(*(c1_type **)((int)pcVar13 + 0x40));
    pcVar30 = type_without_flags(*(c1_type **)((int)pcVar13 + 0x40),0x3e0);
    *(c1_type **)((int)pcVar13 + 0x40) = pcVar30;
    decl_warn_unexpected_specifiers_1(&value_top->spec);
    operator_id_set(&value_base[1].mods,bits,(void *)0x0);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x116:
    pcVar29 = type_parse_based_specifier(value_top->ptr);
    operator_id_set(&value_base[1].mods,0x18,pcVar29);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x117:
    pcVar22 = expr_check_this_usage();
    lVar45 = g_enum_value;
    if (pcVar22 == (c1_node *)0x0) {
switchD_10421905_caseD_105:
      g_enum_value = lVar45;
      pair_clear(&value_base[1].mods);
      lVar45 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0x118:
    operator_id_set(&value_base[1].mods,8,(void *)0x0);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x119:
    pair_clear(&value_base[1].mods);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_14f;
  case 0x11c:
    pcVar31 = decl_declarator_alloc();
    if (pcVar31 == (c1_declarator *)0x0) {
LAB_10465f34:
      value_base[1].words[0] = 0;
      lVar45 = g_enum_value;
    }
    else {
      pcVar31 = decl_declarator_init(pcVar31,g_name_abstract_declarator,4,(c1_overload_set *)0x0);
      value_base[1].declarator = pcVar31;
      lVar45 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0x11d:
    pcVar31 = decl_declarator_alloc();
    if (pcVar31 == (c1_declarator *)0x0) {
      pcVar32 = decl_declarator_record((c1_declarator *)0x0);
      type_check_based_form(pcVar32,&value_top->mods);
      value_base[1].words[0] = 0;
      lVar45 = g_enum_value;
    }
    else {
      pcVar31 = decl_declarator_init(pcVar31,g_name_abstract_declarator,4,(c1_overload_set *)0x0);
      pcVar32 = decl_declarator_record(pcVar31);
      type_check_based_form(pcVar32,&value_top->mods);
      value_base[1].declarator = pcVar31;
      lVar45 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0x11e:
    pcVar31 = decl_declarator_alloc();
    if (pcVar31 == (c1_declarator *)0x0) {
      pvVar21 = value_top->ptr;
      pcVar31 = (c1_declarator *)0x0;
    }
    else {
      pcVar31 = decl_declarator_init(pcVar31,g_name_abstract_declarator,4,(c1_overload_set *)0x0);
      pvVar21 = value_top->ptr;
    }
    goto LAB_10467272;
  case 0x11f:
    pcVar31 = decl_declarator_alloc();
    if (pcVar31 == (c1_declarator *)0x0) {
      pcVar31 = (c1_declarator *)0x0;
    }
    else {
      pcVar31 = decl_declarator_init(pcVar31,g_name_abstract_declarator,4,(c1_overload_set *)0x0);
    }
    pcVar32 = decl_declarator_record(pcVar31);
    type_check_based_form(pcVar32,&pcVar13->mods);
    pvVar21 = value_top->ptr;
LAB_10467272:
    piVar19 = decl_declarator_record(pcVar31);
    decl_append_function_layer(piVar19,pvVar21);
    goto LAB_10421a0f;
  case 0x120:
    pcVar32 = decl_declarator_record(value_top->declarator);
    decl_declarator_append_pointer_op(pcVar32,&pcVar13->ptr_op);
    lVar45 = g_enum_value;
switchD_10421905_caseD_e5:
    g_enum_value = lVar45;
    value_base[1].ptr = (void *)value_top->words[0];
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x122:
    pcVar22 = pcVar13->node;
    pvVar21 = decl_declarator_record(value_base[1].declarator);
    type_check_array_bound_constant_2(pvVar21,pcVar22);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x123:
    pvVar21 = value_top->ptr;
    piVar19 = decl_declarator_record(value_base[1].declarator);
    decl_append_function_layer(piVar19,pvVar21);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x126:
    pcVar31 = decl_declarator_alloc();
    if (pcVar31 == (c1_declarator *)0x0) {
      pcVar31 = (c1_declarator *)0x0;
      pcVar13 = value_top;
      lVar45 = g_enum_value;
    }
    else {
      pcVar31 = decl_declarator_init(pcVar31,(fe_name *)0x0,0,(c1_overload_set *)0x0);
      pcVar13 = value_top;
      lVar45 = g_enum_value;
    }
LAB_1042192a:
    g_enum_value = lVar45;
    pcVar32 = decl_declarator_record(pcVar31);
    decl_declarator_append_pointer_op(pcVar32,&pcVar13->ptr_op);
LAB_10421939:
    value_base[1].declarator = pcVar31;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x127:
  case 0x1e6:
    pcVar32 = decl_declarator_record(value_top->declarator);
    decl_declarator_append_pointer_op(pcVar32,&pcVar13->ptr_op);
    lVar45 = g_enum_value;
LAB_10467c9b:
    g_enum_value = lVar45;
    value_base[1].ptr = (void *)value_top->words[0];
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x128:
    in_stack_00000040 = pcVar13[-1].words[0];
    in_stack_00000044 = *(void **)((int)pcVar13 + -0x24);
    type_pair_record_init
              (&value_base[1].ptr_op,(c1_decl_modifier *)&stack0x00000040,&value_top->mods);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x129:
    pcVar20 = u16_value_init((c1_decl_modifier *)&stack0x0000008c,0);
    type_pair_record_init(&value_base[1].ptr_op,pcVar20,&value_top->mods);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x12a:
    in_stack_00000048 = pcVar13[-1].words[0];
    in_stack_0000004c = *(void **)((int)pcVar13 + -0x24);
    type_warn_qualifiers_on_reference
              (&value_base[1].ptr_op,(c1_decl_modifier *)&stack0x00000048,&value_top->mods);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 299:
    pcVar20 = u16_value_init((c1_decl_modifier *)&stack0x00000084,0);
    type_warn_qualifiers_on_reference(&value_base[1].ptr_op,pcVar20,&value_top->mods);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 300:
    in_stack_00000038 = pcVar13[-1].words[0];
    in_stack_0000003c = *(void **)((int)pcVar13 + -0x24);
    qualified_name_record_init
              (&value_base[1].ptr_op,pcVar13->qualified,(c1_decl_modifier *)&stack0x00000038,
               &value_top->mods);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x12e:
    if (((g_block_depth != '\0') && (g_class_depth < 0)) && ((g_compile_flags_c8 & 0x10000000) == 0)
       ) {
      if ((((g_compile_flags_c8 & 0x40000000) != 0) && ((g_compile_flags_cc & 8) == 0)) &&
         ((g_compile_flags_c4 & 0x200) == 0)) {
        iVar34 = yyparse_cpp_ellipsis_parameter_arena0
                           (value_base,parser,state_sp,saved_lookahead,saved_rule);
        return iVar34;
      }
      if ((g_compile_flags_cc & 0x50) == 0) {
        iVar34 = 4;
        goto LAB_104225ad;
      }
    }
    iVar34 = 0;
    goto LAB_104225ad;
  case 0x12f:
    if (((((g_block_depth == '\0') || (-1 < g_class_depth)) ||
         ((g_compile_flags_c8 & 0x10000000) != 0)) ||
        ((((g_compile_flags_c8 & 0x40000000) != 0 && ((g_compile_flags_cc & 8) == 0)) &&
         ((g_compile_flags_c4 & 0x200) == 0)))) || ((g_compile_flags_cc & 0x50) != 0)) {
      iVar34 = 0;
    }
    else {
      iVar34 = 4;
    }
LAB_104225ad:
    pcVar29 = sym_new_of_kind('\v',g_name_ellipsis,iVar34);
    value_base[1].sym = pcVar29;
    pcVar30 = type_intern_basic_parts(0x80d,0,0);
    (value_base[1].sym)->type = pcVar30;
    sym_mark_ellipsis_parameter(value_base[1].sym);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x130:
    if ((g_opt_Zg == '\0') && ((g_compile_flags_c4 & 0x800000) == 0)) {
      if ((value_top->spec).spec[0] != 0xaa) {
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
    goto switchD_10421905_caseD_1;
  case 0x131:
    if ((g_opt_Zg == '\0') && ((g_compile_flags_c4 & 0x800000) == 0)) {
      if (pcVar13[-1].spec.spec[0] != 0xaa) {
        scope_end_block();
        lVar45 = g_enum_value;
      }
    }
    else {
      g_compile_flags_c4 = g_compile_flags_c4 & 0xff7fffff;
    }
    goto switchD_10421905_caseD_1;
  case 0x135:
    g_compile_flags_c4 = g_compile_flags_c4 & 0xfffffffe;
    if (g_yy_lookahead == (byte *)0x0) {
      bVar11 = g_paren_level_flags[g_paren_depth];
      g_pending_access_check[g_paren_depth] = (c1_symbol *)0x0;
      g_paren_level_flags[iVar33] = bVar11 & 0xfc;
      lVar45 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0x136:
  case 0x165:
    value_base[1].spec.spec[0] = '\0';
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x137:
  case 0x176:
  case 0x1ed:
    value_base[1].spec.spec[0] = '\x01';
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x138:
    pcVar22 = pcVar13->node;
    if (pcVar22 != (c1_node *)0x0) {
      if (pcVar22->op == 0xe8) {
        pcVar22 = property_build_access('t',pcVar22,(c1_node *)0x0);
        pcVar13->node = pcVar22;
      }
      cVar9 = '\x01';
      pcVar22 = expr_resolve_address_of_overload(pcVar13->node);
      pcVar22 = expr_warn_no_effect(pcVar22,cVar9);
      pcVar13->node = pcVar22;
      pcVar22 = expr_full_expression_guarded(pcVar22,2);
      stmt_emit_expression(pcVar22);
    }
    iVar34 = parse_error_recovery_count();
    if (iVar34 != 0) goto LAB_10422a54;
    arena_reset(5);
    g_string_literal_cur = &g_string_literal_buffer;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x13b:
    func_end_compound_statement(pcVar13->node,'\0');
    label_emit_definition(pcVar13->node);
    stmt_if_then_end_flow_state(1);
    func_end_compound_statement((c1_node *)0x0,'\x01');
    lVar45 = g_enum_value;
    if ((value_top->spec).spec[0] != '\0') {
      diag_warning(3,0x186);
      lVar45 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0x13c:
    func_end_compound_statement(pcVar13->node,'\0');
    label_emit_definition(pcVar13->node);
    stmt_else_end_flow_state();
    func_end_compound_statement((c1_node *)0x0,'\x01');
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x13d:
    stmt_while_end_flow_state();
    stmt_loop_end();
    func_end_compound_statement((c1_node *)0x0,(pcVar13->spec).spec[0]);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x13e:
    if (g_ms_extensions != '\0') {
      func_end_compound_statement((c1_node *)0x0,(pcVar13->spec).spec[0]);
      stmt_for_end_flow_state();
    }
    stmt_loop_end();
    lVar45 = g_enum_value;
    if (g_ms_extensions == '\0') {
      stmt_for_end_flow_state();
      func_end_compound_statement((c1_node *)0x0,(pcVar13->spec).spec[0]);
      lVar45 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0x13f:
    func_flow_state_note_1f();
    stmt_do_head();
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfc;
    cVar10 = parse_begin_compound_value((c1_node *)0x0);
    (value_top->spec).spec[0] = cVar10;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x140:
    func_end_compound_statement((c1_node *)0x0,pcVar13[-3].spec.spec[0]);
    func_flow_state_note_22();
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] | 3;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x141:
    label_emit_definition(g_continue_label_stack->label);
    if (pcVar13[-1].node != (c1_node *)0x0) {
      pcVar22 = expr_resolve_address_of_overload(pcVar13[-1].node);
      pcVar13[-1].node = pcVar22;
      pcVar22 = stmt_check_controlling_expression(pcVar22,0);
      pcVar13[-1].node = pcVar22;
      stmt_emit_condition(pcVar22,g_loop_top_label_stack->label,1);
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
    iVar34 = parse_error_recovery_count();
    if (iVar34 == 0) {
      arena_reset(5);
    }
    g_string_literal_cur = &g_string_literal_buffer;
    stmt_do_end_flow_state();
    parse_paren_depth_pop();
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x142:
    il_emit_line_record_24();
    il_emit_tuple(0x3a,*(node **)((int)g_break_label_stack + 4));
    stmt_switch_end();
    stmt_warn_switch_without_cases();
    func_end_compound_statement((c1_node *)0x0,(pcVar13->spec).spec[0]);
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
    goto switchD_10421905_caseD_1;
  case 0x143:
    eh_check_leave();
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
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
    goto switchD_10421905_caseD_1;
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
    goto switchD_10421905_caseD_1;
  case 0x146:
    func_flow_state_note_8();
    stmt_emit_return_value((c1_node *)0x0,1);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x147:
    func_flow_state_note_8();
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x148:
    pcVar22 = pcVar13->node;
    if ((pcVar22 != (c1_node *)0x0) && (pcVar22->op == 0xe8)) {
      pcVar22 = property_build_access('\x01',pcVar22,(c1_node *)0x0);
      pcVar13->node = pcVar22;
    }
    pcVar22 = expr_resolve_address_of_overload(pcVar13->node);
    pcVar13->node = pcVar22;
    stmt_emit_return_value(pcVar22,2);
    iVar34 = parse_error_recovery_count();
    if (iVar34 != 0) goto LAB_10422a54;
    arena_reset(5);
    g_string_literal_cur = &g_string_literal_buffer;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x149:
    pcVar29 = (c1_symbol *)label_find_in_function(pcVar13->words[0]);
    if (pcVar29 == (c1_symbol *)0x0) {
      pcVar29 = (c1_symbol *)label_new_user(pcVar13->words[0]);
      label_register(pcVar29);
      stmt_goto_flow_state(pcVar29,0);
    }
    else {
      stmt_goto_flow_state(pcVar29,1);
    }
    pcVar22 = tree_new_symbol_ref(pcVar29,'\0');
    il_emit_tuple(0x3a,pcVar22);
    iVar34 = parse_error_recovery_count();
    if (iVar34 == 0) {
      arena_reset(5);
    }
LAB_10422a54:
    g_string_literal_cur = &g_string_literal_buffer;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x14a:
    il_emit_line_record_24();
    asm_block_emit();
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x14b:
    eh_except_end();
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x14c:
    eh_finally_begin();
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x14d:
    eh_finally_end();
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x14f:
    diag_error(0xb5);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x152:
    goto switchD_10421905_caseD_14f;
  case 0x153:
    parse_yyerrok(parser);
    g_yy_lookahead = (byte *)0x0;
    uVar55 = 0x7b;
LAB_1046653f:
    pcVar24 = token_static_for_code(uVar55);
    token_source_unget((c1_token_reader *)&g_token_position,pcVar24);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
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
    goto switchD_10421905_caseD_1;
  case 0x155:
    pending_top_mark();
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x156:
    eh_check_try_has_catch();
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x159:
    if (g_yy_lookahead == (byte *)0x0) {
      g_yy_lookahead = yylex_cpp();
      if (g_yy_lookahead == (byte *)0x0) {
        diag_fatal(1);
      }
    }
    cVar10 = lex_token_code((c1xx_token *)g_yy_lookahead);
    if (cVar10 == 'u') {
      lVar45 = g_enum_value;
      if ((value_top->spec).spec[0] != '\0') {
        g_yylval = CONCAT31(g_yylval._1_3_,0xaa);
        pcVar26 = arena_or_pool_alloc(0x30,4);
        if (pcVar26 == (c1_u8 *)0x0) goto LAB_104671eb;
        g_yy_lookahead = token_init(pcVar26,'u',&g_yylval);
        lVar45 = g_enum_value;
      }
    }
    else {
      diag_error(0x13f);
      lVar45 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0x15a:
    scope_end_and_flush_pending_top(pcVar13[-1].spec.spec[0]);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x15b:
    decl_pop_declarator_state(value_top->params);
    cVar10 = eh_check_catch_type_count(value_top->params);
    value_base[1].spec.spec[0] = cVar10;
    vtable_nop();
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x15c:
    diag_error(0x135);
    lVar45 = g_enum_value;
switchD_10421905_caseD_14f:
    g_enum_value = lVar45;
    parse_yyerrok(parser);
LAB_104671eb:
    g_yy_lookahead = (byte *)0x0;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x15f:
    parse_paren_depth_pop();
    value_base[1].words[0] = 1;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x160:
    parse_paren_depth_pop();
    value_base[1].words[0] = 2;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x161:
    eh_try_begin();
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x162:
    eh_try_block_end();
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x163:
    eh_except_filter_begin();
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x164:
    eh_except_emit_filter(pcVar13->node);
    eh_except_filter_end();
    parse_paren_depth_pop();
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x169:
    expr_warn_no_effect(value_top->node,'\0');
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x16a:
    pcVar31 = (c1_declarator *)0x0;
    g_pending_access_check[g_paren_depth] = (c1_symbol *)0x0;
    if (value_top->declarator != (c1_declarator *)0x0) {
      pcVar29 = decl_declarator_symbol(value_top->declarator);
      if (pcVar29 == (c1_symbol *)0x0) goto LAB_10467c7c;
      pcVar29 = decl_declarator_symbol(value_top->declarator);
      pvVar21 = (void *)sym_name(pcVar29);
      pcVar22 = expr_lookup_name_expression(pvVar21);
      value_base[1].node = pcVar22;
      lVar45 = g_enum_value;
      goto switchD_10421905_caseD_1;
    }
    goto LAB_10467c7c;
  case 0x16b:
    g_case_label = (c1_node *)0x0;
    goto switchD_10421905_caseD_1;
  case 0x16d:
    stmt_define_label(pcVar13->words[0]);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x16e:
    if ((pcVar13[-1].node == (c1_node *)0x0) || (g_switch_case_stack == (c1_switch_cases_cell *)0x0)
       ) {
      diag_error(0x2e);
      lVar45 = g_enum_value;
    }
    else {
      pcVar22 = expr_resolve_address_of_overload(pcVar13[-1].node);
      stmt_case_label(pcVar22);
      lVar45 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0x16f:
    if (g_default_label_stack == (c1xx_label_cell *)0x0) {
      diag_error(0x2f);
      lVar45 = g_enum_value;
    }
    else if (g_default_label_stack->label == (c1_node *)0x0) {
      if (g_case_label == (c1_node *)0x0) {
        pcVar22 = label_new(0x14);
        g_default_label_stack->label = pcVar22;
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
    goto switchD_10421905_caseD_1;
  case 0x170:
    parse_begin_compound_value(pcVar13->node);
    value_base[1].words[0] = pcVar13->words[0];
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x171:
    parse_begin_compound_value((c1_node *)0x0);
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] | 0x80;
    func_flow_state_note_11();
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x172:
    pcVar22 = label_new(0x1e);
    value_base[1].node = pcVar22;
    if (pcVar13->node != (c1_node *)0x0) {
      pcVar22 = expr_resolve_address_of_overload(pcVar13->node);
      pcVar13->node = pcVar22;
      pcVar22 = stmt_check_controlling_expression(pcVar22,0);
      pcVar13->node = pcVar22;
      stmt_emit_condition(pcVar22,value_base[1].node,0);
    }
    stmt_if_then_begin_flow_state();
    parse_paren_depth_pop();
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfe;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x173:
    func_end_compound_statement(pcVar13[-1].node,'\0');
    stmt_else_begin_flow_state();
    pcVar22 = label_new(0x1e);
    il_emit_tuple(0x3a,pcVar22);
    label_emit_definition(pcVar13[-1].node);
    il_emit_line_record_24();
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfe;
    acStack_24[1] = 0x10422c59;
    parse_begin_compound_value(pcVar22);
    value_base[1].node = pcVar22;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x177:
    value_base[1].spec.spec[0] = (value_top->spec).spec[0];
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x178:
    if (g_ms_extensions == '\0') {
      cVar10 = parse_begin_compound_value((c1_node *)0x0);
      (value_top->spec).spec[0] = cVar10;
    }
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] | 0x80;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x179:
    if (pcVar13->node != (c1_node *)0x0) {
      cVar9 = '\x01';
      pcVar22 = expr_resolve_address_of_overload(pcVar13->node);
      pcVar22 = expr_warn_no_effect(pcVar22,cVar9);
      pcVar13->node = pcVar22;
      pcVar22 = expr_full_expression_guarded(pcVar22,2);
      stmt_emit_expression(pcVar22);
    }
    iVar34 = parse_error_recovery_count();
    if (iVar34 == 0) {
      arena_reset(5);
    }
    g_string_literal_cur = &g_string_literal_buffer;
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] | 2;
    func_flow_state_note_25();
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x17a:
    pcVar22 = stmt_check_controlling_expression(pcVar13->node,0);
    pcVar13->node = pcVar22;
    func_flow_state_note_27();
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x17b:
    cVar9 = '\x01';
    pcVar22 = expr_resolve_address_of_overload(pcVar13[-1].node);
    pcVar22 = expr_warn_no_effect(pcVar22,cVar9);
    pcVar13[-1].node = pcVar22;
    stmt_for_head((c1_node *)0x0,pcVar13[-4].node,pcVar22);
    if ((pcVar13->spec).spec[0] != '\0') {
      diag_error(0x3b);
    }
    parse_paren_depth_pop();
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfc;
    func_flow_state_note_2a();
    lVar45 = g_enum_value;
    if (g_ms_extensions != '\0') {
      cVar10 = parse_begin_compound_value((c1_node *)0x0);
      pcVar13[-9].spec.spec[0] = cVar10;
      lVar45 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0x17c:
    cVar10 = parse_begin_compound_value((c1_node *)0x0);
    (value_top->spec).spec[0] = cVar10;
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] | 0x80;
    func_flow_state_note_19();
    stmt_while_head();
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x17d:
    cVar9 = '\0';
    pcVar22 = expr_resolve_address_of_overload(pcVar13->node);
    pcVar22 = expr_warn_no_effect(pcVar22,cVar9);
    pcVar13->node = pcVar22;
    pcVar22 = stmt_check_controlling_expression(pcVar22,0);
    pcVar13->node = pcVar22;
    stmt_emit_loop_test(pcVar22);
    parse_paren_depth_pop();
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfe;
    func_flow_state_note_1c();
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x17e:
    cVar10 = parse_begin_compound_value((c1_node *)0x0);
    (value_top->spec).spec[0] = cVar10;
    func_flow_state_note_31();
    lVar45 = g_enum_value;
  case 0x1b0:
    g_enum_value = lVar45;
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] | 3;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x180:
    pcVar22 = expr_resolve_address_of_overload(pcVar13[-2].node);
    stmt_switch_head((int)pcVar22);
    lVar45 = g_enum_value;
switchD_10421905_caseD_6f:
    g_enum_value = lVar45;
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfc;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x181:
    cVar9 = '\0';
    pcVar22 = expr_resolve_address_of_overload(value_top->node);
    pcVar22 = expr_warn_no_effect(pcVar22,cVar9);
    cVar46 = (c1_decl_modifier)expr_eval_constant_expression(pcVar22);
    value_base[1].mods = cVar46;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x183:
    cVar9 = '\0';
    pcVar22 = expr_resolve_address_of_overload(value_top->node);
    pcVar22 = expr_warn_no_effect(pcVar22,cVar9);
    value_base[1].node = pcVar22;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x184:
  case 0x19a:
    pcVar22 = expr_build_binary((pcVar13->spec).spec[0],pcVar13[-1].node,value_top->node);
    value_base[1].node = pcVar22;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x185:
    pcVar22 = expr_build_zero_pair();
    value_base[1].node = pcVar22;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x186:
    pcVar22 = expr_build_throw(value_top->node);
    value_base[1].node = pcVar22;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x187:
    if ((pcVar13[-1].declarator != (c1_declarator *)0x0) &&
       (pcVar22 = value_top->node, pcVar22 != (c1_node *)0x0)) {
      pcVar30 = decl_declarator_record(pcVar13[-1].declarator);
      pcVar22 = expr_resolve_function_address(pcVar30,pcVar22);
joined_r0x104676a9:
      if (pcVar22 == (c1_node *)0x0) {
        expr_report_function_operand('4',value_top->node);
      }
      goto LAB_10422ec5;
    }
    break;
  case 0x188:
    if ((pcVar13[-1].declarator != (c1_declarator *)0x0) &&
       (pcVar22 = value_top->node, pcVar22 != (c1_node *)0x0)) {
      pcVar30 = decl_declarator_record(pcVar13[-1].declarator);
      pcVar22 = expr_resolve_function_address(pcVar30,pcVar22);
      goto joined_r0x104676a9;
    }
    break;
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
    pcVar22 = value_top->node;
LAB_10422ec5:
    pcVar22 = expr_build_binary((pcVar13->spec).spec[0],pcVar13[-1].node,pcVar22);
    value_base[1].node = pcVar22;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x18a:
    pcVar22 = expr_build_conditional(pcVar13[-3].node,pcVar13[-1].node,value_top->node);
    value_base[1].node = pcVar22;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x18b:
  case 0x18d:
    if (pcVar13->words[0] != 0) {
      func_flow_state_note_3e();
      lVar45 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0x18c:
  case 0x18e:
    pcVar22 = expr_build_binary(pcVar13[-1].spec.spec[0],pcVar13[-2].node,value_top->node);
    value_base[1].node = pcVar22;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x199:
    pcVar22 = expr_check_based_operator(pcVar13[-1].node,value_top->node);
    value_base[1].node = pcVar22;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x19d:
    g_compile_flags_c8 = g_compile_flags_c8 | 1;
    pcVar22 = value_top->node;
    cVar27 = pcVar13->words[0];
    uVar48 = (undefined1)cVar27;
    uVar50 = (undefined1)(cVar27 >> 8);
    uVar40 = (undefined2)(cVar27 >> 0x10);
    cVar10 = 'd';
LAB_10422f46:
    g_enum_value = lVar45;
    pcVar22 = expr_build_cast(cVar10,(c1_symbol *)CONCAT22(uVar40,CONCAT11(uVar50,uVar48)),pcVar22);
    value_base[1].node = pcVar22;
    g_compile_flags_c8 = g_compile_flags_c8 & 0xfffffffe;
    tree_clear_value_link(value_base[1].node);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x19e:
    goto switchD_10421905_caseD_19b;
  case 0x19f:
    (pcVar13->spec).spec[0] = ((pcVar13->spec).spec[0] == '@') + 'T';
    pcVar22 = tree_new_int_constant(1);
    pcVar22 = expr_build_binary((pcVar13->spec).spec[0],value_top->node,pcVar22);
    value_base[1].node = pcVar22;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1a0:
    cVar27 = expr_build_unary(0x3d,value_top->node);
    value_base[1].words[0] = cVar27;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1a1:
    pcVar29 = value_top->sym;
    if (pcVar29 == (c1_symbol *)0x0) {
      value_base[1].words[0] = 0;
      lVar45 = g_enum_value;
    }
    else if ((pcVar29->kind == '=') && ((c1_symbol *)pcVar29->type != (c1_symbol *)0x0)) {
      pcVar22 = expr_address_of_member((c1_symbol *)pcVar29->type);
      value_base[1].node = pcVar22;
      lVar45 = g_enum_value;
    }
    else {
      if ((pcVar29->kind == 'S') && ((((c1_node *)pcVar29->type)->kind & 7) == 4)) {
        iVar34 = yyparse_cpp_address_of_member_leaf
                           ((c1_node *)pcVar29->type,value_base,value_top,parser,state_sp,
                            saved_lookahead,saved_rule);
        return iVar34;
      }
LAB_10422fd4:
      g_compile_flags_c8 = g_compile_flags_c8 | 4;
      g_enum_value = lVar45;
      cVar27 = expr_build_unary(0x31,value_top->node);
      value_base[1].words[0] = cVar27;
      g_compile_flags_c8 = g_compile_flags_c8 & 0xfffffffb;
      lVar45 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0x1a2:
    pcVar22 = (c1_node *)expr_build_unary(0x86,value_top->node);
    value_base[1].node = pcVar22;
    tree_clear_value_link(pcVar22);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1a3:
    cVar27 = expr_build_unary(0x5a,value_top->node);
    value_base[1].words[0] = cVar27;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1a4:
    cVar27 = expr_build_unary(0x3c,value_top->node);
    value_base[1].words[0] = cVar27;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1a6:
    cVar27 = expr_build_unary(0x59,value_top->node);
    value_base[1].words[0] = cVar27;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1a7:
    (*g_idb->vtbl->idb_note_sizeof)(g_idb);
    if (value_top->node == (c1_node *)0x0) {
      value_base[1].words[0] = 0;
      g_sizeof_depth = g_sizeof_depth + -1;
      lVar45 = g_enum_value;
    }
    else {
      pcVar22 = expr_build_sizeof(value_top->node);
      value_base[1].node = pcVar22;
      g_sizeof_depth = g_sizeof_depth + -1;
      lVar45 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0x1a8:
    (*g_idb->vtbl->idb_note_sizeof)(g_idb);
    pcVar22 = expr_sizeof_type(value_top->sym->type);
    value_base[1].node = pcVar22;
    g_sizeof_depth = g_sizeof_depth + -1;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1ad:
    cVar27 = expr_build_unary(0xf0,pcVar13->node);
    value_base[1].words[0] = cVar27;
    parse_paren_depth_pop();
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1af:
    g_member_access_op = '\x01';
    if ((pcVar13->node != (c1_node *)0x0) && (pcVar13->node->op == '7')) {
      diag_warning(4,0x2c5);
    }
    pcVar22 = expr_build_binary(pcVar13[-1].spec.spec[0],pcVar13[-2].node,pcVar13->node);
    value_base[1].node = pcVar22;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1b1:
    pcVar22 = pcVar13[-1].node;
    if ((pcVar22 != (c1_node *)0x0) && ((pcVar22->kind & 0x88) == 0)) {
      if ((g_compile_flags_c8 & 0x800000) != 0) {
        if (value_top->node != (c1_node *)0x0) {
          diag_error(0x209);
          pcVar22 = tree_new_zero_flagged();
        }
        value_base[1].node = pcVar22;
        g_compile_flags_c8 = g_compile_flags_c8 & 0xff7fffff;
        g_member_access_op = '\x01';
        lVar45 = g_enum_value;
        goto switchD_10421905_caseD_1;
      }
      pcVar22 = (c1_node *)expr_build_call(pcVar22,value_top->node);
    }
    value_base[1].node = pcVar22;
    lVar45 = g_enum_value;
switchD_10421905_caseD_19b:
    g_member_access_op = '\x01';
    goto switchD_10421905_caseD_1;
  case 0x1b4:
    g_member_access_op = '\x01';
    pcVar22 = tree_new_int_constant(1);
    pcVar22 = expr_build_binary((value_top->spec).spec[0],pcVar13->node,pcVar22);
    value_base[1].node = pcVar22;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1b5:
    g_member_access_op = '\x01';
    pcVar22 = class_check_operator_global_form
                        (CONCAT22((short)((uint)g_yy_lookahead >> 0x10),
                                  CONCAT11((char)((uint)g_yy_lookahead >> 8),(pcVar13->spec).spec[0]
                                          )),value_top->node);
    value_base[1].node = pcVar22;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1b6:
    if ((value_top->spec).spec[0] != 'D') {
      diag_error(0x2f8);
    }
    parse_paren_depth_push(1);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1b7:
    if ((value_top->spec).spec[0] != 0xbf) {
      iVar34 = yyparse_cpp_named_cast_expected_gt
                         ((value_top->spec).spec[0],value_base,parser,state_sp,saved_lookahead,
                          saved_rule);
      return iVar34;
    }
    goto LAB_104232f5;
  case 0x1b8:
    if (value_top->words[0] != 0) {
      g_compile_flags_c8 = g_compile_flags_c8 | 1;
      pcVar22 = value_top->node;
      pcVar29 = parse_type_id_declarator(pcVar13[-2].declarator,&pcVar13[-3].spec);
      uVar48 = SUB41(pcVar29,0);
      uVar50 = (undefined1)((uint)pcVar29 >> 8);
      uVar40 = (undefined2)((uint)pcVar29 >> 0x10);
      cVar10 = pcVar13[-6].spec.spec[0];
      lVar45 = g_enum_value;
      goto LAB_10422f46;
    }
    break;
  case 0x1b9:
    pcVar22 = expr_build_typeid_expression(pcVar13->node);
    value_base[1].node = pcVar22;
    parse_paren_depth_pop();
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1ba:
    pcVar29 = (c1_symbol *)decl_finish_declarator_then_type(pcVar13->ptr,(byte *)pcVar13[-1].words);
    goto LAB_104232f2;
  case 0x1bb:
    pcVar22 = expr_build_uuidof_expression(pcVar13->node);
    value_base[1].node = pcVar22;
    parse_paren_depth_pop();
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1bc:
    pcVar29 = decl_finish_declarator_uuidof(pcVar13->ptr,(byte *)pcVar13[-1].words);
    goto LAB_104232f2;
  case 0x1bd:
    parse_paren_depth_pop();
    value_base[1].words[0] = pcVar13->words[0];
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1be:
    value_base[1].words[0] = 0;
    parse_report_inserted_token(g_yy_lookahead,0x76);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1bf:
    pcVar22 = tree_new_constant(value_top->type,(void *)((int)pcVar13 + 0x30),g_expr_arena_index);
    value_base[1].node = pcVar22;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1c1:
    type_string_literal_array(value_top->node);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1c2:
    pcVar22 = expr_check_this_usage();
    value_base[1].node = pcVar22;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1c3:
    pcVar22 = expr_build_builtin_unary(0x76,pcVar13->node);
    value_base[1].node = pcVar22;
    tree_clear_value_link(pcVar22);
    parse_paren_depth_pop();
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1c5:
    PTR_104d2158 = expr_prepare_member_access_object
                             (g_current_scope,(value_top->spec).spec[0],pcVar13->node,'\0');
    g_member_access_op = (value_top->spec).spec[0];
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1c6:
    pcVar22 = expr_build_member_access(g_member_access_op,PTR_104d2158,value_top->node);
    value_base[1].node = pcVar22;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1c7:
    pcVar22 = expr_build_pseudo_destructor_call(g_member_access_op,PTR_104d2158,value_top->words[0])
    ;
    value_base[1].node = pcVar22;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1c8:
    pcVar29 = value_word0(value_top->cell);
    pcVar22 = expr_build_pseudo_destructor_call(g_member_access_op,PTR_104d2158,(int)pcVar29);
    value_base[1].node = pcVar22;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1c9:
    pfVar28 = sym_name_of_ref(value_top->cell);
    pcVar22 = expr_build_pseudo_destructor_call(g_member_access_op,PTR_104d2158,(int)pfVar28);
    value_base[1].node = pcVar22;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1ca:
    pcVar22 = expr_check_qualified_pseudo_destructor
                        (g_member_access_op,PTR_104d2158,&pcVar13[-2].spec,&value_top->spec);
    value_base[1].node = pcVar22;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1cb:
    pcVar22 = expr_lookup_name_expression(value_top->ptr);
    value_base[1].node = pcVar22;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1cc:
    pvVar21 = decl_declarator_record(value_top->declarator);
    if (pvVar21 == (void *)0x0) {
      pcVar29 = (c1_symbol *)sym_name(value_top->sym);
      pcVar22 = sym_is_data_or_function(pcVar29);
      value_base[1].node = pcVar22;
      lVar45 = g_enum_value;
    }
    else {
      pcVar29 = (c1_symbol *)sym_name(value_top->sym);
      pcVar22 = sym_is_data_or_function(pcVar29);
      if (pcVar22->right != (void *)0x0) {
        diag_fatal(1);
      }
      pvVar21 = value_fieldc(value_top->ptr);
      pcVar22->right = pvVar21;
      value_base[1].node = pcVar22;
      lVar45 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0x1cd:
    pcVar29 = value_word0(value_top->cell);
    pcVar22 = sym_is_data_or_function(pcVar29);
    value_base[1].node = pcVar22;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1ce:
    pcVar22 = expr_lookup_name_expression(*(void **)((int)pcVar13 + 0x2c));
    value_base[1].node = pcVar22;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1cf:
    pfVar28 = decl_conversion_function_name(*(c1_type **)((int)pcVar13 + 0x40));
    pcVar22 = expr_lookup_name_expression(pfVar28);
    value_base[1].node = pcVar22;
    g_compile_flags_c4 = g_compile_flags_c4 & 0xfffffffb;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1d0:
    pcVar29 = value_word0(value_top->cell);
    lVar45 = g_enum_value;
    if ((pcVar29->flags3 & 4) == 0) {
      pcVar29 = value_word0(value_top->cell);
      pcVar22 = sym_is_data_or_function(pcVar29);
      pvVar21 = decl_declarator_record(value_top->declarator);
      if (pvVar21 != (void *)0x0) {
        if (pcVar22->right != (void *)0x0) {
          diag_fatal(1);
        }
        pvVar21 = decl_declarator_record(value_top->declarator);
        pcVar22->right = pvVar21;
      }
      value_base[1].node = pcVar22;
      lVar45 = g_enum_value;
      goto switchD_10421905_caseD_1;
    }
    break;
  case 0x1d1:
    if (pcVar13->cell != (c1_symbol **)0x0) {
      pcVar30 = *(c1_type **)((int)pcVar13 + 0x40);
      pcVar29 = value_word0(pcVar13->cell);
      decl_qualified_conversion_function_name(pcVar29,pcVar30);
      pcVar29 = value_word0(pcVar13->cell);
      pcVar22 = sym_is_data_or_function(pcVar29);
      pvVar21 = decl_declarator_record(pcVar13->declarator);
      if (pvVar21 != (void *)0x0) {
        if (pcVar22->right != (void *)0x0) {
          diag_fatal(1);
        }
        pvVar21 = decl_declarator_record(pcVar13->declarator);
        pcVar22->right = pvVar21;
      }
      value_base[1].node = pcVar22;
    }
    g_compile_flags_c4 = g_compile_flags_c4 & 0xfffffffb;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1d3:
    pcVar29 = parse_type_id_declarator(pcVar13->declarator,&pcVar13[-1].spec);
LAB_104232f2:
    value_base[1].sym = pcVar29;
    lVar45 = g_enum_value;
LAB_104232f5:
    g_enum_value = lVar45;
    parse_paren_depth_pop();
LAB_104232fa:
    g_declarator_paren_base = g_declarator_paren_base + -1;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1d4:
    value_base[1].words[0] = pcVar13->words[0];
    parse_paren_depth_pop();
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1d5:
  case 0x1ea:
    value_base[1].words[0] = 0;
    parse_paren_depth_pop();
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1d6:
    pcVar22 = tree_append_list_item((c1_node *)0x0,value_top->node,0);
    value_base[1].node = pcVar22;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1d7:
    pcVar22 = tree_append_list_item(pcVar13[-1].node,value_top->node,0);
    value_base[1].node = pcVar22;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1d8:
    pcVar22 = arena_alloc(g_arenas + g_expr_arena_index,0x18);
    pcVar22->kind = '\x05';
    pcVar22->op = '\a';
    pcVar22->left = (void *)value_top->words[0];
    pcVar22->right = *(void **)((int)pcVar13 + 0x2c);
    value_base[1].node = pcVar22;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1d9:
    lex_concatenate_strings((c1_string_value *)(pcVar13->declarator->spec + 4),&value_top->str);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1da:
    parse_paren_depth_pop();
    g_compile_flags_c8 = g_compile_flags_c8 & 0xffffffef;
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] | 2;
    g_compile_flags_c4 = g_compile_flags_c4 & 0x7fffffff;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1db:
    pcVar32 = decl_declarator_record(pcVar13->declarator);
    pcVar22 = decl_record_new_array_bound(pcVar32);
    cVar27 = value_top->words[0];
    uVar48 = (undefined1)cVar27;
    uVar50 = (undefined1)(cVar27 >> 8);
    uVar40 = (undefined2)(cVar27 >> 0x10);
    pcVar29 = sym_new_from_declarator(pcVar13->declarator,0xffffffff);
    pcVar22 = expr_build_new_or_placeholder
                        (pcVar13[-1].spec.spec[0],0,pcVar29,CONCAT22(uVar40,CONCAT11(uVar50,uVar48))
                         ,(int)pcVar22);
    value_base[1].node = pcVar22;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1dc:
    pcVar32 = decl_declarator_record(pcVar13->declarator);
    pcVar22 = decl_record_new_array_bound(pcVar32);
    cVar27 = value_top->words[0];
    uVar48 = (undefined1)cVar27;
    uVar50 = (undefined1)(cVar27 >> 8);
    uVar40 = (undefined2)(cVar27 >> 0x10);
    pcVar29 = sym_new_from_declarator(pcVar13->declarator,0xffffffff);
    pcVar22 = expr_build_new_or_placeholder
                        (pcVar13[-1].spec.spec[0],0,pcVar29,CONCAT22(uVar40,CONCAT11(uVar50,uVar48))
                         ,(int)pcVar22);
    value_base[1].node = pcVar22;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1dd:
  case 0x1de:
    pcVar32 = decl_declarator_record(pcVar13->declarator);
    pcVar22 = decl_record_new_array_bound(pcVar32);
    cVar27 = value_top->words[0];
    uVar48 = (undefined1)cVar27;
    uVar50 = (undefined1)(cVar27 >> 8);
    uVar40 = (undefined2)(cVar27 >> 0x10);
    pcVar29 = sym_new_from_declarator(pcVar13->declarator,0xffffffff);
    pcVar22 = expr_build_new_or_placeholder
                        (pcVar13[-2].spec.spec[0],pcVar13[-1].words[0],pcVar29,
                         CONCAT22(uVar40,CONCAT11(uVar50,uVar48)),(int)pcVar22);
    value_base[1].node = pcVar22;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1df:
    g_compile_flags_c8 = g_compile_flags_c8 | 0x10;
    g_compile_flags_c4 = g_compile_flags_c4 | 0x80000000;
    goto switchD_10421905_caseD_1;
  case 0x1e0:
    g_compile_flags_c8 = g_compile_flags_c8 | 0x10;
    g_compile_flags_c4 = g_compile_flags_c4 | 0x80000000;
    parse_paren_depth_push(2);
    func_flow_state_note_43();
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1e1:
    decl_set_local_key_flag(value_top->declarator,'\x01');
    (pcVar13->spec).spec[0] = (pcVar13->spec).spec[0] & 0x7f;
    pcVar39 = pcVar13;
    pcVar32 = decl_declarator_record(value_top->declarator);
    decl_check_conversion_return_type(pcVar32,&pcVar39->spec);
    pcVar32 = decl_declarator_record(value_top->declarator);
    decl_allow_variable_array_bound(pcVar32);
    pcVar32 = decl_declarator_record(value_top->declarator);
    decl_finish_declarator(pcVar32);
    decl_declarator_set_specifiers(value_top->declarator,&pcVar13->spec);
    decl_process_declaration(value_top->declarator);
    pcVar30 = (c1_type *)sym_name(value_top->sym);
    iVar34 = type_chain_is_cv_qualified(pcVar30);
    if ((char)iVar34 == '\0') {
      pcVar30 = (c1_type *)sym_name(value_top->sym);
      cVar10 = type_is_void(pcVar30);
      if (cVar10 != '\0') {
        diag_error(0x1d5);
      }
    }
    else {
      sym_name(value_top->sym);
      diag_error(0x1d4);
    }
    g_declarator_paren_base = g_declarator_paren_base + -1;
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfe;
    value_base[1].ptr = (void *)value_top->words[0];
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1e2:
    pcVar31 = decl_declarator_alloc();
    if (pcVar31 == (c1_declarator *)0x0) {
      pcVar31 = (c1_declarator *)0x0;
    }
    else {
      pcVar31 = decl_declarator_init(pcVar31,g_name_new_target,4,(c1_overload_set *)0x0);
    }
    decl_set_local_key_flag(pcVar31,'\x01');
    pvVar21 = decl_declarator_record(value_top->declarator);
    d_00 = decl_declarator_record(pcVar31);
    decl_set_name(d_00,pvVar21);
    pcVar32 = decl_declarator_record(pcVar31);
    decl_finish_declarator(pcVar32);
    decl_process_declaration(pcVar31);
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfe;
    value_base[1].declarator = pcVar31;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1e3:
    pcVar31 = pcVar13->declarator;
    decl_set_local_key_flag(pcVar31,'\x01');
    declarator_set_kind(pcVar31,4);
    decl_set_name(pcVar31,g_name_new_target);
    pcVar39 = pcVar13 + -1;
    (pcVar39->spec).spec[0] = pcVar13[-1].spec.spec[0] & 0x7f;
    decl_declarator_set_specifiers(pcVar31,&pcVar39->spec);
    pcVar32 = decl_declarator_record(pcVar31);
    decl_check_conversion_return_type(pcVar32,&pcVar39->spec);
    pcVar32 = decl_declarator_record(pcVar31);
    decl_allow_variable_array_bound(pcVar32);
    pcVar32 = decl_declarator_record(pcVar31);
    decl_finish_declarator(pcVar32);
    decl_process_declaration(pcVar31);
    cVar10 = type_is_cv_qualified_stripped(pcVar31);
    if (cVar10 == '\0') {
      pcVar30 = (c1_type *)sym_name((c1_symbol *)pcVar31);
      cVar10 = type_is_void(pcVar30);
      if (cVar10 != '\0') {
        diag_error(0x1d5);
      }
    }
    else {
      sym_name((c1_symbol *)pcVar31);
      diag_error(0x1d4);
    }
    g_declarator_paren_base = g_declarator_paren_base + -1;
    parse_paren_depth_pop();
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfe;
    value_base[1].words[0] = (c1_u32)pcVar31;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1e4:
    pcVar31 = decl_declarator_alloc();
    if (pcVar31 == (c1_declarator *)0x0) {
      pcVar31 = (c1_declarator *)0x0;
    }
    else {
      pcVar31 = decl_declarator_init(pcVar31,g_name_new_target,4,(c1_overload_set *)0x0);
    }
    g_declarator_paren_base = g_declarator_paren_base + 1;
    if (g_yy_lookahead != (byte *)0x0) {
      cVar10 = lex_token_code((c1xx_token *)g_yy_lookahead);
      if (cVar10 == 'v') {
        g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] | 3;
      }
    }
    value_base[1].declarator = pcVar31;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1e5:
    pcVar31 = decl_declarator_alloc();
    if (pcVar31 == (c1_declarator *)0x0) {
      pcVar31 = (c1_declarator *)0x0;
    }
    else {
      pcVar31 = decl_declarator_init(pcVar31,g_name_new_target,4,(c1_overload_set *)0x0);
    }
    pcVar32 = decl_declarator_record(pcVar31);
    type_check_based_form(pcVar32,&value_top->mods);
    g_declarator_paren_base = g_declarator_paren_base + 1;
LAB_10467c7c:
    value_base[1].declarator = pcVar31;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1e7:
    if ((pcVar13->node != (c1_node *)0x0) && (pcVar13->node->op == '7')) {
      diag_warning(4,0x2c5);
    }
    pcVar22 = pcVar13->node;
    pvVar21 = decl_declarator_record(value_base[1].declarator);
    type_check_array_bound_constant_2(pvVar21,pcVar22);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1eb:
    pcVar22 = expr_build_delete((pcVar13->spec).spec[0],value_top->node,(c1_node *)0x0,'\0');
    value_base[1].node = pcVar22;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1ec:
    if ((pcVar13[-1].node != (c1_node *)0x0) && ((pcVar13[-1].node)->op == '7')) {
      diag_warning(4,0x2c5);
    }
    pcVar22 = expr_build_delete(pcVar13[-3].spec.spec[0],value_top->node,pcVar13[-1].node,'\x01');
    value_base[1].node = pcVar22;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  }
  g_enum_value = lVar45;
  value_base[1].words[0] = 0;
  lVar45 = g_enum_value;
  goto switchD_10421905_caseD_1;
switchD_10421905_caseD_0:
  iVar34 = parser->error_count;
LAB_104235dc:
  g_yy_result = iVar34;
  iVar34 = parse_yacc_return_tail(saved_lookahead,saved_rule);
  return iVar34;
}

