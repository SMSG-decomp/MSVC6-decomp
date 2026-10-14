int __cdecl
yyparse_cpp_zero_array_bound_error
          (c1_yy_value *value_base,c1_yy_parser *parser,int *state_sp,longlong bound,
          byte *saved_lookahead,int saved_rule)

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
  c1_decl_record *pcVar14;
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
  void *pvVar22;
  c1_node *pcVar23;
  c1_line_map_row *pcVar24;
  c1xx_token_stream *stream;
  c1xx_token *pcVar25;
  uint *puVar26;
  c1_lookup_entry *cell;
  c1_u8 *pcVar27;
  c1_u32 cVar28;
  fe_name *pfVar29;
  c1_symbol *pcVar30;
  c1_declarator *d_00;
  c1_type *pcVar31;
  c1_declarator *pcVar32;
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
  longlong *bound_00;
  c1xx_decl_specifiers *pcVar53;
  c1_symbol *qualifier;
  c1_overload_set *pcVar54;
  uint uVar55;
  
  if (((g_compile_flags_cc & 0x100000) == 0) && ((g_compile_flags_cc & 0x20) == 0)) {
    diag_error(0x1d2);
  }
LAB_10421952:
  bound_00 = &bound;
  pcVar14 = decl_declarator_record(value_base[1].declarator);
  decl_append_array_layer(pcVar14,(int *)bound_00);
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
    pcVar39 = pcVar13 + 1;
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
    pcVar13 = pcVar39;
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
                         (0,pcVar39,state_sp,iVar33,parser,in_stack_00000018,saved_lookahead,
                          saved_rule);
      return iVar34;
    }
  }
  iVar33 = g_paren_depth;
  pcVar25 = (c1xx_token *)g_yy_lookahead;
  g_enum_value._4_4_ = (undefined4)((ulonglong)lVar45 >> 0x20);
  g_enum_value._0_4_ = (undefined4)lVar45;
  uVar55 = (uint)g_yy_r2[iVar34];
  state_sp = state_sp + -uVar55;
  value_base = pcVar39 + -uVar55;
  uVar40 = (undefined2)(uVar55 * -5 >> 0x10);
  g_yy_rule = iVar34;
  g_enum_value = lVar45;
  switch(iVar34) {
  case 3:
    iVar34 = parser->error_count;
    goto LAB_104235dc;
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
      pbVar16 = (byte *)((int)&g_function_tuple_count + iVar34 + 3);
      *pbVar16 = *pbVar16 | 1;
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
    if (g_error_count != 0) {
LAB_104235dc:
      g_yy_result = iVar34;
      iVar34 = parse_yacc_return_tail(saved_lookahead,saved_rule);
      return iVar34;
    }
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
    decl_check_conversion_return_type(pcVar39->declarator->decl,pcVar53);
    decl_finish_declarator(pcVar39->declarator->decl);
    if ((g_paren_level_flags[g_paren_depth] & 1) == 0) {
      pcVar53 = decl_specifiers_default((void *)0x0);
    }
    else {
      pcVar53 = g_paren_level_declspecs + g_paren_depth;
    }
    ppvVar42 = (void **)&pcVar39->node->unk0c;
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
    func_begin_member_definition(pcVar39->declarator,pcVar53->spec);
    g_declarator_paren_base = g_declarator_paren_base + -1;
    bVar11 = g_current_scope->current->kind;
    if ((0xfa < bVar11) && (bVar11 != 0xfd)) {
      scope_pop_to_kind(g_current_scope,'\x01');
    }
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfc;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1f:
    g_ctor_mem_initializers = pcVar39->node;
    func_begin_definition_frame();
    g_compile_flags_c8 = g_compile_flags_c8 & 0xffffffbf;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x20:
    funcs_check_incremental();
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x21:
    tmpl_parse_queued_definition(pcVar39->header);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x22:
    g_compile_flags_c4 = g_compile_flags_c4 & 0xfeffffff;
    g_compile_flags_c8 = g_compile_flags_c8 & 0xfffffffd;
    bVar11 = g_current_scope->current->kind;
    if ((0xfa < bVar11) && (bVar11 != 0xfd)) {
      scope_pop_to_kind(g_current_scope,'\x01');
    }
    decl_check_conversion_return_type(pcVar39->declarator->decl,&pcVar13->spec);
    decl_finish_declarator(pcVar39->declarator->decl);
    pcVar38 = pcVar13;
    ppvVar42 = (void **)&pcVar39->node->unk0c;
    for (iVar34 = 6; iVar34 != 0; iVar34 = iVar34 + -1) {
      *ppvVar42 = (void *)pcVar38->words[0];
      pcVar38 = (c1_yy_value *)(pcVar38->words + 1);
      ppvVar42 = ppvVar42 + 1;
    }
    if (g_block_depth == '\0') {
      pcVar30 = func_begin_member_definition(pcVar39->declarator,(byte *)pcVar13->words);
      value_base[1].sym = pcVar30;
    }
    else {
      cVar9 = '\0';
      pcVar30 = decl_declare_in_current_scope(pcVar39->declarator,&pcVar13->spec);
      func_parse_definition_or_skip(pcVar30,cVar9);
      g_yy_lookahead = g_token_end_parse;
    }
LAB_10420683:
    g_declarator_paren_base = g_declarator_paren_base + -1;
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfc;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x24:
    g_compile_flags_cc = g_compile_flags_cc | 2;
    func_begin_definition_state((int *)(pcVar39->str).text);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x25:
    pcVar30 = type_require_complete(pcVar39->sym);
    value_base[1].sym = pcVar30;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x26:
    pcVar30 = type_require_complete(pcVar39->sym);
    value_base[1].sym = pcVar30;
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
    value_base[1].ptr = (void *)pcVar39->words[0];
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x2a:
    pcVar23 = tree_append_expression_list_item((c1_node *)0x0,pcVar39->node);
    value_base[1].node = pcVar23;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x2b:
    pcVar23 = tree_append_expression_list_item(pcVar13[-1].node,pcVar39->node);
    value_base[1].node = pcVar23;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x2c:
    diag_error(0x276);
    pcVar23 = tree_append_expression_list_item(pcVar13[-1].node,pcVar39->node);
    value_base[1].node = pcVar23;
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
    cVar28 = pcVar13->words[0];
    pfVar29 = pcVar13[-3].name;
    uVar48 = (undefined1)cVar28;
    uVar50 = (undefined1)(cVar28 >> 8);
    uVar40 = (undefined2)(cVar28 >> 0x10);
    goto LAB_1042079c;
  case 0x30:
    cVar28 = pcVar13->words[0];
    uVar48 = (undefined1)cVar28;
    uVar50 = (undefined1)(cVar28 >> 8);
    uVar40 = (undefined2)(cVar28 >> 0x10);
    pfVar29 = (pcVar13[-3].declarator)->name;
LAB_1042079c:
    cVar9 = '\0';
    pcVar31 = (c1_type *)0x0;
    pcVar30 = sym_new_kind1_placeholder(pfVar29);
    pcVar23 = tree_new_symbol_ref(pcVar30,cVar9);
    pcVar23 = tree_new_node('v',pcVar23,(c1_node *)CONCAT22(uVar40,CONCAT11(uVar50,uVar48)),pcVar31)
    ;
    value_base[1].node = pcVar23;
    g_compile_flags_c4 = g_compile_flags_c4 | 1;
    goto LAB_104207ca;
  case 0x32:
  case 0x34:
    cVar28 = pcVar13->words[0];
    pcVar31 = (c1_type *)0x0;
    uVar48 = (undefined1)cVar28;
    uVar50 = (undefined1)(cVar28 >> 8);
    uVar40 = (undefined2)(cVar28 >> 0x10);
    pcVar23 = tree_new_symbol_ref(*pcVar13[-3].cell,'\0');
    pcVar23 = tree_new_node('v',pcVar23,(c1_node *)CONCAT22(uVar40,CONCAT11(uVar50,uVar48)),pcVar31)
    ;
    value_base[1].node = pcVar23;
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
    pcVar23 = tree_append_list_item((c1_node *)0x0,pcVar39->node,2);
    value_base[1].node = pcVar23;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x3c:
    pcVar23 = tree_append_list_item(pcVar13[-1].node,pcVar39->node,2);
    value_base[1].node = pcVar23;
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
      g_ctor_mem_initializers = pcVar39->node;
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
    value_base[1].ptr = (void *)pcVar39->words[0];
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x4b:
    pcVar41 = (c1_u32 *)&stack0x000000b8;
    for (iVar34 = 9; iVar34 != 0; iVar34 = iVar34 + -1) {
      *pcVar41 = pcVar39->words[0];
      pcVar39 = (c1_yy_value *)(pcVar39->words + 1);
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
    pcVar32 = arena_alloc(g_arenas + 5,0x58);
    if (pcVar32 == (c1_declarator *)0x0) {
      pcVar32 = (c1_declarator *)0x0;
    }
    else {
      pcVar32->position = g_token_position;
    }
    pcVar39 = pcVar13;
    pcVar27 = pcVar32->spec;
    for (iVar34 = 6; iVar34 != 0; iVar34 = iVar34 + -1) {
      *(c1_u32 *)pcVar27 = pcVar39->words[0];
      pcVar39 = (c1_yy_value *)(pcVar39->words + 1);
      pcVar27 = pcVar27 + 4;
    }
    tmpl_explicit_instantiation(pcVar32,'\x01',&pcVar13->spec);
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
    pcVar32 = arena_alloc(g_arenas + 5,0x58);
    if (pcVar32 == (c1_declarator *)0x0) {
      pcVar32 = (c1_declarator *)0x0;
    }
    else {
      pcVar32->position = g_token_position;
    }
    pcVar39 = pcVar13;
    pcVar27 = pcVar32->spec;
    for (iVar34 = 6; iVar34 != 0; iVar34 = iVar34 + -1) {
      *(c1_u32 *)pcVar27 = pcVar39->words[0];
      pcVar39 = (c1_yy_value *)(pcVar39->words + 1);
      pcVar27 = pcVar27 + 4;
    }
    tmpl_explicit_instantiation(pcVar32,pcVar13[-2].spec.spec[0],&pcVar13->spec);
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
    pcVar32 = pcVar13->declarator;
    in_stack_0000007c = (c1_symbol *)0x0;
    in_stack_00000060 = in_stack_00000060 & 7 ^ in_stack_00000060 | 0x30;
    in_stack_00000078 = g_type_none;
    decl_check_conversion_return_type(pcVar32->decl,(c1xx_decl_specifiers *)&stack0x00000060);
    decl_finish_declarator(pcVar32->decl);
    tmpl_explicit_instantiation
              (pcVar32,(c1_u8)in_stack_00000028,(c1xx_decl_specifiers *)&stack0x00000060);
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
    pvVar22 = tmpl_header_end(pcVar13->header->parameter_scope);
    value_base[1].ptr = pvVar22;
    pcVar19 = tmpl_header_take_parameter_list();
    *(c1_arg_list **)((int)value_base + 0x2c) = pcVar19;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x5d:
    g_declarator_paren_base = g_declarator_paren_base + -1;
    decl_check_conversion_return_type(pcVar39->declarator->decl,&pcVar13->spec);
    decl_finish_declarator(pcVar39->declarator->decl);
    pcVar38 = pcVar13;
    ppvVar42 = (void **)&pcVar39->node->unk0c;
    for (iVar34 = 6; iVar34 != 0; iVar34 = iVar34 + -1) {
      *ppvVar42 = (void *)pcVar38->words[0];
      pcVar38 = (c1_yy_value *)(pcVar38->words + 1);
      ppvVar42 = ppvVar42 + 1;
    }
    if (g_class_depth < 0) {
      if ((g_compile_flags_c8 & 0x40) == 0) {
        pcVar30 = decl_declare_from_declarator(pcVar39->declarator,(byte *)pcVar13->words);
      }
      else {
        pcVar30 = pcVar39->declarator->sym;
      }
      bVar11 = g_current_scope->current->kind;
      if ((0xfa < bVar11) && (bVar11 != 0xfd)) {
        scope_pop_to_kind(g_current_scope,'\x01');
      }
      class_check_unnamed_class_member(&pcVar13->spec);
      value_base[1].sym = pcVar30;
      lVar45 = g_enum_value;
    }
    else {
      pcVar39->declarator->kind = 2;
      cVar9 = class_begin_member_list(pcVar39->declarator,&pcVar13->spec,(c1_symbol **)0x0);
      if (((cVar9 == '\0') && (bVar11 = g_current_scope->current->kind, 0xfa < bVar11)) &&
         (bVar11 != 0xfd)) {
        scope_pop_to_kind(g_current_scope,'\x01');
      }
      value_base[1].words[0] = (c1_u32)pcVar39->declarator->sym;
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
    decl_check_conversion_return_type(pcVar39->declarator->decl,pcVar53);
    decl_finish_declarator(pcVar39->declarator->decl);
    if ((g_paren_level_flags[g_paren_depth] & 1) == 0) {
      pcVar53 = decl_specifiers_default((void *)0x0);
    }
    else {
      pcVar53 = g_paren_level_declspecs + g_paren_depth;
    }
    ppvVar42 = (void **)&pcVar39->node->unk0c;
    for (iVar34 = 6; iVar34 != 0; iVar34 = iVar34 + -1) {
      *ppvVar42 = *(void **)pcVar53->spec;
      pcVar53 = (c1xx_decl_specifiers *)(pcVar53->spec + 4);
      ppvVar42 = ppvVar42 + 1;
    }
    if (g_class_depth < 0) {
      if ((g_compile_flags_c8 & 0x40) == 0) {
        if ((g_paren_level_flags[g_paren_depth] & 1) == 0) {
          pcVar53 = decl_specifiers_default((void *)0x0);
          pcVar32 = (c1_declarator *)decl_declare_from_declarator(pcVar39->declarator,pcVar53->spec)
          ;
        }
        else {
          pcVar32 = (c1_declarator *)
                    decl_declare_from_declarator
                              (pcVar39->declarator,g_paren_level_declspecs[g_paren_depth].spec);
        }
      }
      else {
        pcVar32 = (c1_declarator *)pcVar39->declarator->sym;
      }
      bVar11 = g_current_scope->current->kind;
      if (0xfa < bVar11) {
        iVar34 = yyparse_cpp_template_member_declaration_tail
                           (g_current_scope,bVar11,(c1_symbol *)pcVar32,value_base,parser,state_sp,
                            saved_lookahead,saved_rule);
        return iVar34;
      }
      goto LAB_10421939;
    }
    pcVar39->declarator->kind = 2;
    if ((g_paren_level_flags[g_paren_depth] & 1) == 0) {
      pcVar53 = decl_specifiers_default((void *)0x0);
    }
    else {
      pcVar53 = g_paren_level_declspecs + g_paren_depth;
    }
    cVar9 = class_begin_member_list(pcVar39->declarator,pcVar53,(c1_symbol **)0x0);
    if (((cVar9 == '\0') && (bVar11 = g_current_scope->current->kind, 0xfa < bVar11)) &&
       (bVar11 != 0xfd)) {
      scope_pop_to_kind(g_current_scope,'\x01');
    }
    value_base[1].words[0] = (c1_u32)pcVar39->declarator->sym;
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
      pcVar24 = include_line_map_find((c1_line_map_state *)&g_lex_position,g_token_position);
      (*g_idb->vtbl->idb_scope_kind4_end)
                (g_idb,CONCAT22(uVar40,(short)pcVar24->line - (short)pcVar24->position) +
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
      cVar6 = (c1_arg_value)pcVar39->node->right;
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
      pcVar24 = include_line_map_find((c1_line_map_state *)&g_lex_position,g_token_position);
      (*g_idb->vtbl->idb_scope_kind4_end)
                (g_idb,CONCAT22(uVar40,(short)pcVar24->line - (short)pcVar24->position) +
                       g_token_position,0);
    }
    a = g_arenas + g_expr_arena_index;
    pcVar23 = (c1_node *)a->cur;
    pcVar7 = (c1_node *)g_arenas[g_expr_arena_index].end;
    a->cur = &pcVar23[1].op;
    if (pcVar7 < pcVar23 + 1) {
      arena_grow(a);
    }
    pcVar23->kind = '\0';
    pcVar23->op = 0xc6;
    pcVar23->left = (void *)pcVar39->words[0];
    in_stack_00000054 = (c1_type *)0x0;
    in_stack_0000005c = 0;
    in_stack_00000050 = 0x80e;
    in_stack_00000052 = 0;
    in_stack_00000058.cls = (c1_symbol *)0x0;
    pcVar31 = type_intern((c1_type *)&stack0x00000050);
    pcVar23->type = pcVar31;
    pcVar23 = tree_append_list_item((c1_node *)0x0,pcVar23,2);
    pcVar18 = arena_alloc(g_arenas,0x14);
    if (pcVar18 == (c1_arg_item *)0x0) {
      pcVar18 = (c1_arg_item *)0x0;
    }
    else {
      tmpl_list_item_construct(pcVar18,1,0);
      pcVar18->vtbl = &PTR_pch_fixup_tree_list_object_104bcbcc;
      (pcVar18->value).expr = pcVar23;
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
    pcVar27 = arena_alloc_n_aligned(0xc,0);
    if (pcVar27 == (c1_u8 *)0x0) goto LAB_10465f34;
    pvVar22 = tmpl_argument_list_init(pcVar27,pcVar39->ptr);
    value_base[1].ptr = pvVar22;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x6c:
    list_append_tail(pcVar13[-1].args,pcVar39->arg);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x6e:
    pcVar18 = tmpl_argument_from_expression(pcVar39->node);
    value_base[1].arg = pcVar18;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x6f:
    pcVar41 = acStack_24;
    for (iVar34 = 9; iVar34 != 0; iVar34 = iVar34 + -1) {
      *pcVar41 = pcVar13->words[0];
      pcVar41 = pcVar41 + 1;
      pcVar13 = (c1_yy_value *)(pcVar13->words + 1);
    }
    pcVar18 = decl_finish_declarator_record(pcVar39->declarator);
    value_base[1].arg = pcVar18;
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
    pcVar23 = pcVar39->node;
    pcVar13 = pcVar13 + -1;
    pcVar41 = (c1_u32 *)&stack0x00000124;
    for (iVar34 = 9; iVar34 != 0; iVar34 = iVar34 + -1) {
      *pcVar41 = pcVar13->words[0];
      pcVar13 = (c1_yy_value *)(pcVar13->words + 1);
      pcVar41 = pcVar41 + 1;
    }
    iVar34 = decl_parse_linkage_specification((c1xx_decl_specifiers *)&stack0x00000124,pcVar23);
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
    pbVar16 = ns_define_namespace((void *)0x0);
    value_base[1].str.text = pbVar16;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x78:
    pbVar16 = ns_define_namespace(pcVar13->ptr);
    value_base[1].str.text = pbVar16;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x79:
    scope_pop_to_kind_if_needed(g_current_scope,'\0');
    pvVar22 = qualname_resolved_symbol(pcVar13->declarator);
    cVar10 = '\0';
    uVar48 = 0;
    uVar50 = 0;
    uVar40 = 0;
    if (pvVar22 == (void *)0x0) {
      pcVar30 = value_word0(pcVar13->cell);
      ns_using_directive((c1_symbol *)0x0,(fe_name *)pcVar30,
                         CONCAT22(uVar40,CONCAT11(uVar50,uVar48)),cVar10);
      lVar45 = g_enum_value;
    }
    else {
      uVar47 = 0;
      uVar49 = 0;
      uVar51 = 0;
      pcVar30 = qualname_resolved_symbol(pcVar13->declarator);
      ns_using_directive(pcVar30,(fe_name *)CONCAT22(uVar51,CONCAT11(uVar49,uVar47)),
                         CONCAT22(uVar40,CONCAT11(uVar50,uVar48)),cVar10);
      lVar45 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0x7a:
    scope_pop_to_kind_if_needed(g_current_scope,'\0');
    pvVar22 = qualname_resolved_symbol(pcVar13->declarator);
    pcVar32 = (c1_declarator *)pcVar13->cell;
    if (pvVar22 == (void *)0x0) goto LAB_104668f9;
    pcVar30 = qualname_resolved_symbol(pcVar32);
    ns_using_declaration(pcVar30);
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
        pcVar13 = pcVar39;
        pcVar41 = (c1_u32 *)(&g_paren_level_declspecs_prev_base + g_paren_depth * 0x24);
        lVar45 = g_enum_value;
        goto LAB_10420c2b;
      }
    }
    iVar34 = g_paren_depth;
    pcVar53 = g_paren_level_declspecs + g_paren_depth;
    for (iVar33 = 9; iVar33 != 0; iVar33 = iVar33 + -1) {
      *(c1_u32 *)pcVar53->spec = pcVar39->words[0];
      pcVar39 = (c1_yy_value *)(pcVar39->words + 1);
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
    puVar26 = &g_yylval;
    for (iVar34 = 9; iVar34 != 0; iVar34 = iVar34 + -1) {
      *puVar26 = pcVar39->words[0];
      pcVar39 = (c1_yy_value *)(pcVar39->words + 1);
      puVar26 = puVar26 + 1;
    }
    if (bVar44) {
      cVar10 = lex_token_code(pcVar25);
      pcVar25 = (c1xx_token *)g_yy_lookahead;
      lVar45 = g_enum_value;
      if (cVar10 == '\x7f') goto switchD_10421905_caseD_1;
    }
    g_yy_lookahead = (byte *)lex_unget_token(pcVar25);
    g_compile_flags_c4 = g_compile_flags_c4 | 0x80000000;
    pcVar30 = value_word0((c1_symbol **)&g_token_arena_index);
    pcVar27 = arena_or_pool_alloc(0x30,(int)pcVar30);
    if (pcVar27 == (c1_u8 *)0x0) {
      token = (char *)0x0;
    }
    else {
      token = token_init(pcVar27,'\"',&g_yylval);
    }
    pcVar25 = (c1xx_token *)lex_lookahead_decl_specifiers(token);
    g_compile_flags_c4 = g_compile_flags_c4 & 0x7fffffff;
    pcVar13 = token_value_address(pcVar25);
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
    pcVar31 = class_end_definition();
    *(c1_type **)((int)value_base + 0x40) = pcVar31;
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
      pcVar25 = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
      g_yy_lookahead = &parse_skip_tokens_to_one_of(pcVar25)->code;
      cVar10 = lex_token_code((c1xx_token *)g_yy_lookahead);
      if (cVar10 == '\x7f') {
        lex_unget_token((c1xx_token *)g_yy_lookahead);
        pcVar25 = token_static_for_code(0x7b);
        token_source_unget((c1_token_reader *)&g_token_position,pcVar25);
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
    pcVar30 = (c1_symbol *)sym_name((c1_symbol *)(pcVar13->spec).type);
    lVar45 = g_enum_value;
    if (g_pragma_mintypeinfo != '\0') {
      sym_detail_set_flag3f_bit3(pcVar30);
      lVar45 = g_enum_value;
    }
    if ((g_browse_file != (char *)0x0) && ((g_block_depth == '\0' || (g_opt_FR_browse != 0)))) {
      g_enum_value = lVar45;
      cVar10 = sym_flags3_bit0(pcVar30);
      lVar45 = g_enum_value;
      if (cVar10 == '\0') {
        (*g_il_emitter->vtbl->begin_block)();
        pcVar5 = g_il_emitter->vtbl;
        iVar34 = sym_name(pcVar30);
        iVar34 = (*pcVar5->mark_definition)(0,iVar34);
        if (iVar34 == 0) {
          (*g_il_emitter->vtbl->define_symbol)(g_il_emitter,pcVar30);
        }
        (*g_il_emitter->vtbl->set_owner)((int)pcVar30);
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
              ((pcVar13->spec).spec[0] & 3,(pcVar13->spec).spec[0] >> 2 & 0xffffff01,pcVar39->name,0
              );
    g_compile_flags_c4 = g_compile_flags_c4 | 1;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x98:
    bVar11 = (pcVar13->spec).spec[0];
    pcVar30 = (c1_symbol *)sym_name(pcVar39->sym);
    class_check_base_class(bVar11 & 3,bVar11 >> 2 & 1,pcVar30);
    goto LAB_10420ed7;
  case 0x99:
    pcVar30 = value_word0(pcVar39->cell);
    access_check_member(pcVar30);
    bVar11 = (pcVar13->spec).spec[0];
    iVar34 = 0;
    pcVar30 = value_word0(pcVar39->cell);
    uVar47 = SUB41(pcVar30,0);
    uVar49 = (undefined1)((uint)pcVar30 >> 8);
    uVar51 = (undefined2)((uint)pcVar30 >> 0x10);
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
    pcVar30 = value_word0(pcVar39->cell);
    access_check_member(pcVar30);
    bVar11 = (pcVar13->spec).spec[0];
    iVar34 = 1;
    pcVar30 = value_word0(pcVar39->cell);
    uVar47 = SUB41(pcVar30,0);
    uVar49 = (undefined1)((uint)pcVar30 >> 8);
    uVar51 = (undefined2)((uint)pcVar30 >> 0x10);
    uVar55 = CONCAT31((int3)((uint)pcVar30 >> 8),bVar11 >> 2) & 0xffffff01;
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
           ((byte)g_tree_op_to_il_op[(pcVar39->spec).spec[0]] ^ bVar11) & 3 ^ bVar11;
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
    lVar45 = enum_warn_value_wrapped(lVar45,pcVar39->ptr);
    acStack_24[1] = 0x10420f95;
    g_enum_value = lVar45;
    enum_declare(pcVar39->name,g_current_enum_type,(c1_u32)lVar45,(int)((ulonglong)lVar45 >> 0x20));
    g_compile_flags_c4 = g_compile_flags_c4 | 1;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xaa:
    if ((g_compile_flags_cc & 0x100000) != 0) {
      pcVar25 = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
      pcVar25 = parse_skip_tokens_to_one_of(pcVar25);
      token_source_unget((c1_token_reader *)&g_token_position,pcVar25);
      g_yylval = (uint)g_type_int;
      _g_yylval_word2 = 1;
      _g_yylval_word3 = 0;
      pcVar30 = value_word0((c1_symbol **)&g_token_arena_index);
      pcVar27 = arena_or_pool_alloc(0x30,(int)pcVar30);
      if (pcVar27 == (c1_u8 *)0x0) goto LAB_10466f79;
      g_yy_lookahead = token_init(pcVar27,'e',&g_yylval);
      lVar45 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0xab:
    enum_declare(pcVar13[-2].name,g_current_enum_type,pcVar39->words[0],
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
    pcVar32 = decl_declarator_alloc();
    if (pcVar32 == (c1_declarator *)0x0) {
      pcVar32 = (c1_declarator *)0x0;
    }
    else {
      pcVar32 = declarator_set_position(pcVar32);
    }
    decl_declarator_set_specifiers(pcVar32,(c1xx_decl_specifiers *)&stack0x000000dc);
    class_begin_member_list(pcVar32,(c1xx_decl_specifiers *)&stack0x000000dc,(c1_symbol **)0x0);
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
    class_set_current_access((c1_u8)g_tree_op_to_il_op[(pcVar39->spec).spec[0]]);
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
      pcVar25 = (c1xx_token *)lex_peek_token((uint *)&g_token_position);
      cVar10 = lex_token_code(pcVar25);
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
      pcVar25 = (c1xx_token *)lex_peek_token((uint *)&g_token_position);
      cVar10 = lex_token_code(pcVar25);
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
    pcVar30 = decl_declarator_symbol(pcVar39->declarator);
    if (pcVar30 == (c1_symbol *)0x0) {
      declarator_set_kind(pcVar39->declarator,2);
      g_declarator_paren_base = g_declarator_paren_base + -1;
      pcVar53 = decl_specifiers_current();
      pcVar14 = decl_declarator_record(pcVar39->declarator);
      decl_check_conversion_return_type(pcVar14,pcVar53);
      pcVar14 = decl_declarator_record(pcVar39->declarator);
      decl_finish_declarator(pcVar14);
      pcVar53 = decl_specifiers_current();
      decl_declarator_set_specifiers(pcVar39->declarator,pcVar53);
      ppcVar52 = (c1_symbol **)0x0;
      pcVar53 = decl_specifiers_current();
      cVar9 = class_begin_member_list(pcVar39->declarator,pcVar53,ppcVar52);
      if (cVar9 == '\0') {
        scope_pop_to_kind_if_needed(g_current_scope,'\x01');
      }
      pcVar30 = decl_declarator_symbol(pcVar39->declarator);
      value_base[1].sym = pcVar30;
      lVar45 = g_enum_value;
    }
    else {
      pcVar30 = decl_declarator_symbol(pcVar39->declarator);
      value_base[1].sym = pcVar30;
      lVar45 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0xc2:
    pcVar23 = expr_resolve_address_of_overload(pcVar39->node);
    bVar11 = expr_is_zero_constant(pcVar23);
    if (bVar11 == 0) {
      diag_error(0x102);
    }
    declarator_set_flags56_bit1(pcVar13->declarator,'\x01');
    declarator_set_kind(pcVar13->declarator,2);
    g_declarator_paren_base = g_declarator_paren_base + -1;
    pcVar53 = decl_specifiers_current();
    pcVar14 = decl_declarator_record(pcVar13->declarator);
    decl_check_conversion_return_type(pcVar14,pcVar53);
    pcVar14 = decl_declarator_record(pcVar13->declarator);
    decl_finish_declarator(pcVar14);
    pcVar53 = decl_specifiers_current();
    decl_declarator_set_specifiers(pcVar13->declarator,pcVar53);
    ppcVar52 = (c1_symbol **)0x0;
    pcVar53 = decl_specifiers_current();
    cVar9 = class_begin_member_list(pcVar13->declarator,pcVar53,ppcVar52);
    if (cVar9 == '\0') {
      scope_pop_to_kind_if_needed(g_current_scope,'\x01');
    }
    pcVar30 = decl_declarator_symbol(pcVar13->declarator);
    value_base[1].sym = pcVar30;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xc4:
    declarator_set_kind(pcVar13[-1].declarator,1);
    iVar34 = *(int *)((int)pcVar13 + 0x2c);
    cVar28 = pcVar39->words[0];
    uVar48 = (undefined1)cVar28;
    uVar50 = (undefined1)(cVar28 >> 8);
    uVar40 = (undefined2)(cVar28 >> 0x10);
    pcVar30 = decl_declarator_symbol(pcVar13[-1].declarator);
    cVar10 = type_check_bitfield_width(pcVar30,CONCAT22(uVar40,CONCAT11(uVar50,uVar48)),iVar34);
    decl_set_bitfield_width(pcVar13[-1].declarator,cVar10);
    g_declarator_paren_base = g_declarator_paren_base + -1;
    pcVar53 = decl_specifiers_current();
    pcVar14 = decl_declarator_record(pcVar13[-1].declarator);
    decl_check_conversion_return_type(pcVar14,pcVar53);
    pcVar14 = decl_declarator_record(pcVar13[-1].declarator);
    decl_finish_declarator(pcVar14);
    pcVar53 = decl_specifiers_current();
    decl_declarator_set_specifiers(pcVar13[-1].declarator,pcVar53);
    ppcVar52 = (c1_symbol **)0x0;
    pcVar53 = decl_specifiers_current();
    cVar9 = class_begin_member_list(pcVar13[-1].declarator,pcVar53,ppcVar52);
    if (cVar9 == '\0') {
      scope_pop_to_kind_if_needed(g_current_scope,'\x01');
    }
    pcVar30 = decl_declarator_symbol(pcVar13[-1].declarator);
    value_base[1].sym = pcVar30;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xc5:
    pcVar32 = decl_declarator_alloc();
    if (pcVar32 == (c1_declarator *)0x0) {
      pcVar32 = (c1_declarator *)0x0;
    }
    else {
      pcVar32 = decl_declarator_init(pcVar32,g_name_alignment_member,1,(c1_overload_set *)0x0);
    }
    iVar34 = *(int *)((int)pcVar13 + 0x2c);
    cVar28 = pcVar39->words[0];
    uVar48 = (undefined1)cVar28;
    uVar50 = (undefined1)(cVar28 >> 8);
    uVar40 = (undefined2)(cVar28 >> 0x10);
    pcVar30 = decl_declarator_symbol(pcVar32);
    cVar10 = type_check_bitfield_width(pcVar30,CONCAT22(uVar40,CONCAT11(uVar50,uVar48)),iVar34);
    decl_set_bitfield_width(pcVar32,cVar10);
    declarator_set_flags54_bit5(pcVar32,'\x01');
    pcVar53 = decl_specifiers_current();
    pcVar14 = decl_declarator_record(pcVar32);
    decl_check_conversion_return_type(pcVar14,pcVar53);
    pcVar14 = decl_declarator_record(pcVar32);
    decl_finish_declarator(pcVar14);
    pcVar53 = decl_specifiers_current();
    decl_declarator_set_specifiers(pcVar32,pcVar53);
    ppcVar52 = (c1_symbol **)0x0;
    pcVar53 = decl_specifiers_current();
    class_begin_member_list(pcVar32,pcVar53,ppcVar52);
    pcVar30 = decl_declarator_symbol(pcVar32);
    value_base[1].sym = pcVar30;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xc6:
    scope_pop_to_kind_if_needed(g_current_scope,'\x01');
    pcVar30 = decl_declarator_symbol(pcVar39->declarator);
    value_base[1].sym = pcVar30;
    pvVar22 = qualname_resolved_symbol(pcVar39->declarator);
    pcVar32 = (c1_declarator *)pcVar39->cell;
    if (pvVar22 == (void *)0x0) {
LAB_104668f9:
      value_word0((c1_symbol **)pcVar32);
      diag_error(0x369);
      lVar45 = g_enum_value;
    }
    else {
      pbVar16 = qualname_resolved_symbol(pcVar32);
      ns_member_using_declaration(pbVar16);
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
      pcVar30 = value_word0(pcVar39->cell);
      iVar34 = class_is_innermost_being_defined((int)pcVar30);
      lVar45 = g_enum_value;
      if ((char)iVar34 != '\0') {
        declarator_set_kind(pcVar39->declarator,2);
        g_declarator_paren_base = g_declarator_paren_base + -1;
        pcVar53 = decl_specifiers_current();
        pcVar14 = decl_declarator_record(pcVar39->declarator);
        decl_check_conversion_return_type(pcVar14,pcVar53);
        pcVar14 = decl_declarator_record(pcVar39->declarator);
        decl_finish_declarator(pcVar14);
        pcVar53 = decl_specifiers_current();
        decl_declarator_set_specifiers(pcVar39->declarator,pcVar53);
        g_yy_lookahead = (byte *)lex_unget_token((c1xx_token *)g_yy_lookahead);
        ppcVar52 = (c1_symbol **)0x0;
        pcVar53 = decl_specifiers_current();
        cVar9 = class_begin_member_list(pcVar39->declarator,pcVar53,ppcVar52);
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
    pcVar14 = decl_declarator_record(pcVar39->declarator);
    decl_check_conversion_return_type(pcVar14,pcVar53);
    pcVar14 = decl_declarator_record(pcVar39->declarator);
    decl_finish_declarator(pcVar14);
    pcVar53 = decl_specifiers_current();
    decl_declarator_set_specifiers(pcVar39->declarator,pcVar53);
    if (((g_compile_flags_c8 & 0x40) == 0) && ((g_compile_flags_cc & 0x200000) == 0)) {
      pcVar53 = decl_specifiers_current();
      decl_declare_from_declarator(pcVar39->declarator,pcVar53->spec);
    }
    scope_pop_to_kind_if_needed(g_current_scope,'\x01');
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xcf:
    if (g_opt_Zg == '\0') {
      pcVar30 = decl_declarator_symbol(pcVar13->declarator);
      cVar9 = decl_check_function_style_initializer(pcVar30);
      if (cVar9 == '\0') {
        g_declarator_paren_base = g_declarator_paren_base + -1;
        decl_set_has_initializer(pcVar13->declarator,'\x01');
        pcVar53 = decl_specifiers_current();
        pcVar14 = decl_declarator_record(pcVar13->declarator);
        decl_check_conversion_return_type(pcVar14,pcVar53);
        pcVar14 = decl_declarator_record(pcVar13->declarator);
        decl_finish_declarator(pcVar14);
        pcVar53 = decl_specifiers_current();
        decl_declarator_set_specifiers(pcVar13->declarator,pcVar53);
        pcVar53 = decl_specifiers_current();
        pcVar30 = decl_declare_and_check(pcVar13->declarator,pcVar53->spec);
        decl_record_set_symbol(pcVar13->ptr,pcVar30);
        pcVar30 = decl_declarator_symbol(pcVar13->declarator);
        pcVar30 = (c1_symbol *)decl_begin_initialized_definition(pcVar30);
        decl_record_set_symbol(pcVar13->ptr,pcVar30);
        pcVar30 = decl_declarator_symbol(pcVar13->declarator);
        if (pcVar30 != (c1_symbol *)0x0) {
          pcVar30 = decl_declarator_symbol(pcVar13->declarator);
          init_set_target_symbol(pcVar30);
          pcVar23 = pcVar39->node;
          pcVar30 = decl_declarator_symbol(pcVar13->declarator);
          decl_finish_initialization(pcVar30,pcVar23);
          scope_pop_to_kind_if_needed(g_current_scope,'\x01');
          pcVar32 = pcVar13->declarator;
          goto LAB_10421651;
        }
      }
    }
    goto LAB_10422a54;
  case 0xd1:
    if ((g_opt_Zg != '\0') || (pcVar13[-1].words[0] == 0)) goto LAB_10422a54;
    pcVar23 = pcVar39->node;
    if ((pcVar23 != (c1_node *)0x0) && (pcVar23->op == 0xe8)) {
      pcVar23 = property_build_access('\x01',pcVar23,(c1_node *)0x0);
      pcVar39->node = pcVar23;
    }
    pcVar30 = decl_declarator_symbol(pcVar13[-1].declarator);
    init_set_target_symbol(pcVar30);
    g_compile_flags_c8 = g_compile_flags_c8 | 0x80000;
    g_compile_flags_cc = g_compile_flags_cc | 0x80000;
    pcVar23 = expr_resolve_address_of_overload(pcVar39->node);
    pcVar30 = decl_declarator_symbol(pcVar13[-1].declarator);
    decl_finish_initialization(pcVar30,pcVar23);
    g_compile_flags_cc = g_compile_flags_cc & 0xfff7ffff;
    g_compile_flags_c8 = g_compile_flags_c8 & 0xfff7ffff;
    scope_pop_to_kind_if_needed(g_current_scope,'\x01');
    pcVar32 = pcVar13[-1].declarator;
LAB_10421651:
    pcVar30 = decl_declarator_symbol(pcVar32);
    type_check_destructible_2(pcVar30);
    g_string_literal_cur = &g_string_literal_buffer;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xd2:
    if (g_opt_Zg == '\0') {
      cVar9 = '\0';
      pcVar30 = decl_declarator_symbol(pcVar39->declarator);
      init_begin(pcVar30,cVar9);
      g_compile_flags_cc = g_compile_flags_cc | 0x80000;
      g_brace_init_active = 1;
      lVar45 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0xd3:
    pcVar30 = decl_declarator_symbol(pcVar13[-4].declarator);
    init_finish(pcVar30);
    g_compile_flags_cc = g_compile_flags_cc & 0xfff7ffff;
    if (g_opt_Zg == '\0') {
      pcVar30 = decl_declarator_symbol(pcVar13[-4].declarator);
      type_check_destructible_2(pcVar30);
    }
    scope_pop_to_kind_if_needed(g_current_scope,'\x01');
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xd4:
    pcVar53 = decl_specifiers_current();
    pcVar14 = decl_declarator_record(pcVar13->declarator);
    decl_check_conversion_return_type(pcVar14,pcVar53);
    pcVar14 = decl_declarator_record(pcVar13->declarator);
    decl_finish_declarator(pcVar14);
    pcVar53 = decl_specifiers_current();
    decl_declarator_set_specifiers(pcVar13->declarator,pcVar53);
    g_declarator_paren_base = g_declarator_paren_base + -1;
    lVar45 = g_enum_value;
    if (g_opt_Zg == '\0') {
      decl_set_has_initializer(pcVar13->declarator,'\x01');
      pcVar53 = decl_specifiers_current();
      decl_declarator_set_specifiers(pcVar13->declarator,pcVar53);
      pcVar53 = decl_specifiers_current();
      pcVar30 = decl_declare_and_check(pcVar13->declarator,pcVar53->spec);
      decl_record_set_symbol(pcVar13->ptr,pcVar30);
      pcVar30 = decl_declarator_symbol(pcVar13->declarator);
      decl_begin_initialized_definition(pcVar30);
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
      pcVar23 = expr_resolve_address_of_overload(pcVar39->node);
      init_process_initializer(pcVar23,iVar34);
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
    uVar55 = in_stack_00000034;
    parse_report_inserted_token(g_yy_lookahead,(uint)bVar11);
    lex_unget_token((c1xx_token *)g_yy_lookahead);
    g_yy_lookahead = &token_static_for_code(uVar55)->code;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xdc:
  case 0x11a:
    g_declarator_paren_base = g_declarator_paren_base + 1;
    goto switchD_10421905_caseD_1;
  case 0xdd:
    pvVar22 = pcVar39->ptr;
    piVar20 = decl_declarator_record(value_base[1].declarator);
    decl_append_function_layer(piVar20,pvVar22);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xde:
    pcVar32 = pcVar39->declarator;
    goto LAB_1042192a;
  case 0xe0:
    goto switchD_10421905_caseD_dd;
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
    pcVar32 = pcVar39->declarator;
    pcVar14 = decl_declarator_record(pcVar32);
    type_check_based_form(pcVar14,&pcVar13->mods);
    value_base[1].declarator = pcVar32;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xe4:
    pcVar32 = pcVar39->declarator;
    cVar9 = declarator_flags56_bit0(pcVar32);
    if (cVar9 != '\0') {
      pcVar53 = &g_conversion_type_specifiers;
      pcVar14 = decl_declarator_record(pcVar32);
      decl_record_set_conversion_type(pcVar14,pcVar53);
    }
    value_base[1].declarator = pcVar32;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xe5:
    pcVar32 = decl_declarator_alloc();
    if (pcVar32 == (c1_declarator *)0x0) {
LAB_10466a12:
      pcVar32 = (c1_declarator *)0x0;
    }
    else {
      pcVar32 = decl_declarator_init(pcVar32,pcVar39->name,0,(c1_overload_set *)0x0);
    }
    goto LAB_10421a04;
  case 0xe6:
    pcVar32 = decl_declarator_alloc();
    if (pcVar32 == (c1_declarator *)0x0) {
      pcVar32 = (c1_declarator *)0x0;
    }
    else {
      pcVar54 = (c1_overload_set *)0x0;
      uVar48 = 0;
      uVar50 = 0;
      uVar40 = 0;
      pcVar30 = value_word0(pcVar39->cell);
      pcVar32 = decl_declarator_init
                          (pcVar32,(fe_name *)pcVar30,CONCAT22(uVar40,CONCAT11(uVar50,uVar48)),
                           pcVar54);
    }
    pvVar22 = decl_declarator_record(pcVar39->declarator);
    if (pvVar22 == (void *)0x0) {
      pcVar30 = (c1_symbol *)sym_name(pcVar39->sym);
    }
    else {
      pcVar30 = (c1_symbol *)sym_name(pcVar39->sym);
    }
    iVar34 = sym_scope_index(pcVar30);
    if (iVar34 != 0) {
      pcVar30 = sym_scope_by_index(pcVar30,0x1c);
      decl_record_set_qualifying_class(pcVar32,pcVar30);
    }
    goto LAB_10421a04;
  case 0xe7:
    pcVar32 = decl_declarator_alloc();
    if (pcVar32 == (c1_declarator *)0x0) goto LAB_10466a12;
    pcVar54 = (c1_overload_set *)0x0;
    uVar48 = 0;
    uVar50 = 0;
    uVar40 = 0;
    pfVar29 = sym_name_of_ref(pcVar39->cell);
    pcVar32 = decl_declarator_init(pcVar32,pfVar29,CONCAT22(uVar40,CONCAT11(uVar50,uVar48)),pcVar54)
    ;
LAB_10421a04:
    cVar9 = class_name_is_current_class(pcVar32);
    if (cVar9 == '\0') {
LAB_10421a0f:
      value_base[1].declarator = pcVar32;
      lVar45 = g_enum_value;
    }
    else {
      decl_set_is_constructor(pcVar32,'\x01');
      value_base[1].declarator = pcVar32;
      lVar45 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0xe8:
  case 0x1b2:
    goto switchD_10421905_caseD_e5;
  case 0xe9:
    pcVar32 = decl_declarator_alloc();
    if (pcVar32 == (c1_declarator *)0x0) {
      pcVar32 = (c1_declarator *)0x0;
    }
    else {
      pcVar32 = decl_declarator_init(pcVar32,pcVar39->name,0,(c1_overload_set *)0x0);
    }
    cVar9 = class_name_is_current_class(pcVar32);
    if (cVar9 == '\0') {
      if (-1 < g_class_depth) goto LAB_10466aa7;
LAB_10466b25:
      value_word0((c1_symbol **)pcVar32);
LAB_10466b2d:
      diag_error(0x24c);
      value_base[1].declarator = pcVar32;
      lVar45 = g_enum_value;
    }
    else {
      decl_set_is_destructor(pcVar32,'\x01');
      value_base[1].declarator = pcVar32;
      lVar45 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0xea:
    pcVar30 = value_word0(pcVar39->cell);
    pcVar32 = decl_declarator_alloc();
    if (pcVar32 == (c1_declarator *)0x0) {
      pcVar32 = (c1_declarator *)0x0;
    }
    else {
      pcVar32 = decl_declarator_init(pcVar32,(fe_name *)pcVar30,0,(c1_overload_set *)0x0);
    }
    cVar9 = class_name_is_current_class(pcVar32);
    if (cVar9 == '\0') {
      if (g_class_depth < 0) goto LAB_10466b2d;
      goto LAB_10466aa7;
    }
    goto LAB_10421ad0;
  case 0xeb:
    pcVar32 = decl_declarator_alloc();
    if (pcVar32 == (c1_declarator *)0x0) {
      pcVar32 = (c1_declarator *)0x0;
    }
    else {
      pcVar54 = (c1_overload_set *)0x0;
      uVar48 = 0;
      uVar50 = 0;
      uVar40 = 0;
      pfVar29 = sym_name_of_ref(pcVar39->cell);
      pcVar32 = decl_declarator_init
                          (pcVar32,pfVar29,CONCAT22(uVar40,CONCAT11(uVar50,uVar48)),pcVar54);
    }
    cVar9 = class_name_is_current_class(pcVar32);
    if (cVar9 != '\0') goto LAB_10421ad0;
    if (g_class_depth < 0) goto LAB_10466b25;
LAB_10466aa7:
    diag_error(0x20b);
    pvVar22 = class_current_definition_name();
    decl_set_name(pcVar32,pvVar22);
LAB_10421ad0:
    decl_set_is_destructor(pcVar32,'\x01');
    value_base[1].declarator = pcVar32;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xec:
    pcVar32 = decl_declarator_alloc();
    if (pcVar32 == (c1_declarator *)0x0) {
      value_set_byte30((c1_declarator *)0x0,(pcVar39->spec).spec[0]);
      value_base[1].words[0] = 0;
      lVar45 = g_enum_value;
    }
    else {
      pcVar32 = decl_declarator_init
                          (pcVar32,*(fe_name **)((int)pcVar13 + 0x2c),0,(c1_overload_set *)0x0);
      value_set_byte30(pcVar32,(pcVar39->spec).spec[0]);
      value_base[1].declarator = pcVar32;
      lVar45 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0xed:
    pcVar53 = &g_conversion_type_specifiers;
    for (iVar34 = 9; iVar34 != 0; iVar34 = iVar34 + -1) {
      *(c1_u32 *)pcVar53->spec = pcVar39->words[0];
      pcVar39 = (c1_yy_value *)(pcVar39->words + 1);
      pcVar53 = (c1xx_decl_specifiers *)(pcVar53->spec + 4);
    }
    pcVar32 = decl_declarator_alloc();
    if (pcVar32 == (c1_declarator *)0x0) {
      pcVar32 = (c1_declarator *)0x0;
    }
    else {
      pcVar54 = (c1_overload_set *)0x0;
      uVar48 = 0;
      uVar50 = 0;
      uVar40 = 0;
      pfVar29 = decl_conversion_function_name(g_conversion_type_specifiers.type);
      pcVar32 = decl_declarator_init
                          (pcVar32,pfVar29,CONCAT22(uVar40,CONCAT11(uVar50,uVar48)),pcVar54);
    }
    value_set_byte30(pcVar32,0x8f);
    declarator_set_flags56_bit0(pcVar32,'\x01');
    g_compile_flags_c4 = g_compile_flags_c4 & 0xfffffffb;
    value_base[1].declarator = pcVar32;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xee:
    if (pcVar39->cell == (c1_symbol **)0x0) {
      d.sym = (c1_symbol *)0x0;
      in_stack_00000018.sym = d.sym;
    }
    else {
      pcVar15 = value_word0(pcVar39->cell);
      pcVar30 = *(c1_symbol **)(*(int *)pcVar15->type + 8);
      pcVar32 = decl_declarator_alloc();
      if (pcVar32 == (c1_declarator *)0x0) {
        d.sym = (c1_symbol *)0x0;
      }
      else {
        uVar48 = 0;
        uVar50 = 0;
        uVar40 = 0;
        qualifier = pcVar15;
        pfVar29 = (fe_name *)sym_name(pcVar15);
        d.sym = (c1_symbol *)
                decl_declarator_init
                          (pcVar32,pfVar29,CONCAT22(uVar40,CONCAT11(uVar50,uVar48)),qualifier);
      }
      in_stack_00000018 = d;
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
        d = in_stack_00000018;
        if ((pcVar30->kind & 0x1f) == 0x11) {
          pcVar30 = (c1_symbol *)ovl_first_function_of_set(pcVar30);
          d = in_stack_00000018;
        }
        g_conversion_type_specifiers.type = decl_declarator_record((c1_declarator *)pcVar30->type);
        puVar26 = decl_specifiers_of_symbol((uint *)&stack0x0000016c,pcVar30);
        pcVar53 = &g_conversion_type_specifiers;
        for (iVar34 = 6; iVar34 != 0; iVar34 = iVar34 + -1) {
          *(uint *)pcVar53->spec = *puVar26;
          puVar26 = puVar26 + 1;
          pcVar53 = (c1xx_decl_specifiers *)(pcVar53->spec + 4);
        }
        declarator_set_flags56_bit0(d.declarator,'\x01');
        in_stack_00000018 = d;
        lVar45 = g_enum_value;
      }
      bVar11 = pcVar30->kind & 0x1f;
      if ((((bVar11 == 0x10) || (bVar11 == 7)) ||
          ((bVar11 == 6 || (((bVar11 == 0x11 || (bVar11 == 8)) || (bVar11 == 0x1b)))))) ||
         ((bVar11 == 0x1a &&
          (((bVar11 = **(byte **)pcVar30->type & 0x1f, bVar11 == 0x10 || (bVar11 == 7)) ||
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
        bVar11 = pcVar30->kind & 0x1f;
        if (((bVar11 == 0x10) || (bVar11 == 0x11)) || (bVar11 == 0x1b)) {
          pbVar16 = ovl_first_function_of_set(pcVar30);
          value_set_byte30(d.declarator,pbVar16[0x2f]);
          value_base[1].declarator = (c1_declarator *)d;
          lVar45 = g_enum_value;
        }
        else {
          value_set_byte30(d.declarator,(pcVar30->tail).fn.op_token);
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
      pcVar32 = (c1_declarator *)0x0;
    }
    else {
      pcVar30 = value_word0(pcVar13->cell);
      pcVar53 = &g_conversion_type_specifiers;
      for (iVar34 = 9; iVar34 != 0; iVar34 = iVar34 + -1) {
        *(c1_u32 *)pcVar53->spec = pcVar39->words[0];
        pcVar39 = (c1_yy_value *)(pcVar39->words + 1);
        pcVar53 = (c1xx_decl_specifiers *)(pcVar53->spec + 4);
      }
      decl_qualified_conversion_function_name(pcVar30,g_conversion_type_specifiers.type);
      if (pcVar30->type == (c1_type *)0x0) {
        pcVar32 = decl_declarator_alloc();
        if (pcVar32 == (c1_declarator *)0x0) goto LAB_10466c6d;
        pcVar54 = (c1_overload_set *)0x0;
        uVar48 = 0;
        uVar50 = 0;
        uVar40 = 0;
        pfVar29 = name_new_S();
        pcVar32 = decl_declarator_init
                            (pcVar32,pfVar29,CONCAT22(uVar40,CONCAT11(uVar50,uVar48)),pcVar54);
      }
      else {
        pcVar32 = decl_declarator_alloc();
        if (pcVar32 == (c1_declarator *)0x0) {
          pcVar32 = (c1_declarator *)0x0;
        }
        else {
          uVar48 = 0;
          uVar50 = 0;
          uVar40 = 0;
          pcVar15 = pcVar30;
          pfVar29 = (fe_name *)sym_name(pcVar30);
          pcVar32 = decl_declarator_init
                              (pcVar32,pfVar29,CONCAT22(uVar40,CONCAT11(uVar50,uVar48)),
                               (c1_overload_set *)pcVar15);
        }
        lookup_check_symbol_kinds_reversed(*(int **)pcVar30->type);
        if (**(int **)pcVar30->type != 0) {
          pcVar30 = *(c1_symbol **)(**(int **)pcVar30->type + 8);
          if ((pcVar30->kind & 0x1f) == 0xf) {
            pcVar30 = scope_vector_get((short)pcVar30->key_ref);
          }
          decl_record_set_qualifying_class(pcVar32,pcVar30);
        }
        value_set_byte30(pcVar32,0x8f);
        declarator_set_flags56_bit0(pcVar32,'\x01');
        if ((g_compile_flags_cc & 0x200000) != 0) {
          declarator_set_kind(pcVar32,2);
        }
      }
    }
    g_compile_flags_c4 = g_compile_flags_c4 & 0xfffffffb;
    value_base[1].declarator = pcVar32;
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
    pcVar14 = decl_declarator_record(pcVar39->declarator);
    decl_conversion_function_declarator(&pcVar13->spec,pcVar14);
    (pcVar13->spec).spec[0] = (pcVar13->spec).spec[0] & 0x7f;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xf2:
    param_clause_set_cv_qualifiers(pcVar13[-1].params,&pcVar13->mods);
    param_clause_set_exception_spec(pcVar13[-1].params,pcVar39->words[0]);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xf3:
    pcVar27 = class_record_new_kind5();
    value_base[1].str.text = pcVar27;
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
    pvVar22 = pcVar13[-1].ptr;
    value_base[1].ptr = pvVar22;
    if (pcVar13->sym != (c1_symbol *)0x0) {
      sym_list_append(pvVar22,pcVar13->sym);
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
    pcVar30 = sym_new_of_kind('\v',g_name_ellipsis,iVar34);
    sym_mark_ellipsis_parameter(pcVar30);
    pcVar31 = type_intern_basic_parts(0x80d,0,0);
    pcVar30->type = pcVar31;
    pcVar17 = (c1_param_clause *)arena5_alloc_1c();
    if (pcVar17 == (c1_param_clause *)0x0) {
      value_base[1].words[0] = 0;
      sym_list_append((void *)0x0,pcVar30);
      parse_paren_depth_pop();
      lVar45 = g_enum_value;
    }
    else {
      pcVar17 = optional_value_init(pcVar17,3,(c1_sym_list *)0x0,'\0');
      value_base[1].params = pcVar17;
      sym_list_append(pcVar17,pcVar30);
      parse_paren_depth_pop();
      lVar45 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0xf8:
    if (pcVar39->words[0] != 2) goto LAB_10467c9b;
    diag_warning(3,0x122);
    value_base[1].ptr = (void *)pcVar39->words[0];
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xf9:
    pcVar17 = (c1_param_clause *)arena5_alloc_1c();
    if (pcVar17 == (c1_param_clause *)0x0) goto LAB_10465f34;
    cVar9 = '\x01';
    scope = decl_declarator_record((c1_declarator *)g_current_scope);
    params = scope_symbol_list(scope);
    pcVar17 = optional_value_init(pcVar17,3,params,cVar9);
    value_base[1].params = pcVar17;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xfb:
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] | 8;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xfc:
    if ((pcVar39->words[0] != 0) && (g_paren_level_arg_lists[g_paren_depth] != (c1_arg_list *)0x0))
    {
      arena_set_expression_index(0);
      g_compile_flags_cc = g_compile_flags_cc | 0x10;
      pcVar23 = tree_append_list_item((c1_node *)0x0,(c1_node *)0x0,2);
      pcVar18 = (c1_arg_item *)arena_alloc_n_aligned(0x14,0);
      if (pcVar18 == (c1_arg_item *)0x0) {
        pcVar18 = (c1_arg_item *)0x0;
      }
      else {
        pcVar18 = arg_expression_item_init(pcVar18,pcVar23,'\0','\x01');
      }
      tmpl_argument_list_prepend(g_paren_level_arg_lists[g_paren_depth],pcVar18);
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
    if ((pcVar13->words[0] != 0) && (pcVar39->node != (c1_node *)0x0)) {
      pcVar23 = expr_resolve_address_of_overload(pcVar39->node);
      if ((g_compile_flags_c8 & 0x40000000) != 0) {
        pcVar23 = tree_copy_to_arena(pcVar23,0);
      }
      tree_attach_typed_link(pcVar23,pcVar13->sym->type);
      acStack_24[1] = 0x10421fe2;
      pcVar23 = conv_convert_expression(0xc6,pcVar13->sym->type,pcVar23,'\x02','\x04');
      pcVar39->node = pcVar23;
      iVar34 = 2;
      pcVar23 = (c1_node *)expr_finish_full_expression((int)pcVar23);
      pcVar23 = tree_append_list_item((c1_node *)0x0,pcVar23,iVar34);
      pcVar18 = (c1_arg_item *)arena_alloc_n_aligned(0x14,0);
      if (pcVar18 == (c1_arg_item *)0x0) {
        pcVar18 = (c1_arg_item *)0x0;
      }
      else {
        pcVar18 = arg_expression_item_init(pcVar18,pcVar23,'\0','\x01');
      }
      if (g_paren_level_arg_lists[g_paren_depth] == (c1_arg_list *)0x0) {
        pcVar27 = arena_alloc_n_aligned(0xc,0);
        if (pcVar27 == (c1_u8 *)0x0) {
          g_paren_level_arg_lists[g_paren_depth] = (c1_arg_list *)0x0;
        }
        else {
          pcVar19 = tmpl_argument_list_init(pcVar27,pcVar18);
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
      iVar34 = 0;
      pcVar37 = g_idb->vtbl;
      uVar55 = lex_line_number_of_position(&g_token_position);
      (*pcVar37->idb_scope_kind4_end)(g_idb,uVar55,iVar34);
    }
    if ((g_compile_flags_c8 & 0x10000000) == 0) {
      diag_error(0x3e);
    }
    pcVar18 = (c1_arg_item *)arena_alloc_n_aligned(0x14,0);
    if (pcVar18 == (c1_arg_item *)0x0) {
      pcVar18 = (c1_arg_item *)0x0;
    }
    else {
      pcVar18 = pch_fixup_list_object_ctor(pcVar18,pcVar39->sym->type,'\0');
    }
    if (g_paren_level_arg_lists[g_paren_depth] == (c1_arg_list *)0x0) {
      pcVar27 = arena_alloc_n_aligned(0xc,0);
      if (pcVar27 == (c1_u8 *)0x0) {
        g_paren_level_arg_lists[g_paren_depth] = (c1_arg_list *)0x0;
      }
      else {
        pcVar19 = tmpl_argument_list_init(pcVar27,pcVar18);
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
      pcVar23 = arena_alloc(g_arenas + g_expr_arena_index,0x18);
      pcVar23->kind = '\0';
      pcVar23->op = 0xc6;
      pcVar23->left = (void *)pcVar39->words[0];
      pcVar31 = type_intern_basic_parts(0x80e,0,0);
      value_set_field4(pcVar23,pcVar31);
      pcVar23 = tree_append_list_item((c1_node *)0x0,pcVar23,2);
      pcVar18 = (c1_arg_item *)arena_alloc_n_aligned(0x14,0);
      if (pcVar18 == (c1_arg_item *)0x0) {
        pcVar18 = (c1_arg_item *)0x0;
      }
      else {
        pcVar18 = arg_expression_item_init(pcVar18,pcVar23,'\0','\x01');
      }
      if (g_paren_level_arg_lists[g_paren_depth] == (c1_arg_list *)0x0) {
        pcVar27 = arena_alloc_n_aligned(0xc,0);
        if (pcVar27 == (c1_u8 *)0x0) {
          g_paren_level_arg_lists[g_paren_depth] = (c1_arg_list *)0x0;
        }
        else {
          pcVar19 = tmpl_argument_list_init(pcVar27,pcVar18);
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
      iVar34 = 0;
      pcVar37 = g_idb->vtbl;
      uVar55 = lex_line_number_of_position(&g_token_position);
      (*pcVar37->idb_scope_kind4_end)(g_idb,uVar55,iVar34);
    }
    cVar10 = lex_token_code((c1xx_token *)g_yy_lookahead);
    if (cVar10 == 'u') {
      diag_error(0x117);
      pcVar25 = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
      parse_skip_tokens_to_one_of(pcVar25);
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
      parse_default_argument_begin(pcVar39->sym->type);
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
    scope_insert_through_object(g_current_scope,pcVar39->sym);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x105:
    value_base[1].words[0] = 0;
    if ((g_compile_flags_c8 & 0x30000000) == 0) {
      pcVar25 = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
      pcVar25 = parse_skip_tokens_to_one_of(pcVar25);
      g_yy_lookahead = &pcVar25->code;
LAB_10466f65:
      token_source_unget((c1_token_reader *)&g_token_position,pcVar25);
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
        pcVar25 = token_static_for_code(0x3e);
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
    decl_set_local_key_flag(pcVar39->declarator,'\x01');
    if (((g_compile_flags_c8 & 0x10000000) == 0) || (g_paren_depth != 1)) {
      cVar28 = 5;
    }
    else {
      cVar28 = 0xb;
    }
    declarator_set_kind(pcVar39->declarator,cVar28);
    pcVar53 = (c1xx_decl_specifiers *)&stack0x00000094;
    pcVar14 = decl_declarator_record(pcVar39->declarator);
    decl_check_conversion_return_type(pcVar14,pcVar53);
    pcVar14 = decl_declarator_record(pcVar39->declarator);
    decl_finish_declarator(pcVar14);
    decl_declarator_set_specifiers(pcVar39->declarator,(c1xx_decl_specifiers *)&stack0x00000094);
    decl_declare_in_current_scope(pcVar39->declarator,(c1xx_decl_specifiers *)&stack0x00000094);
    pcVar30 = decl_declarator_symbol(pcVar39->declarator);
    if ((g_compile_flags_c8 & 0x10000000) != 0) {
      pcVar31 = pcVar30->type;
      cVar9 = type_code_is_201(pcVar31);
      if (cVar9 == '\0') {
        cVar9 = type_code_is_202(pcVar31);
        if (cVar9 != '\0') {
          iVar34 = yyparse_cpp_class_template_parameter_error
                             (pcVar30,value_base,parser,state_sp,saved_lookahead,saved_rule);
          return iVar34;
        }
      }
      else if ((pcVar30->storage & 0x80) == 0) {
        diag_error(0x3e1);
        pcVar30->flags3 = pcVar30->flags3 | 4;
      }
    }
    g_declarator_paren_base = g_declarator_paren_base + -1;
    scope_pop_to_kind_if_needed(g_current_scope,'\x01');
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfc;
    value_base[1].sym = pcVar30;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x107:
    bVar44 = false;
    decl_set_local_key_flag(pcVar39->declarator,'\x01');
    if (((g_compile_flags_c8 & 0x10000000) == 0) || (g_paren_depth != 1)) {
      cVar28 = 6;
    }
    else {
      cVar28 = 0xb;
    }
    declarator_set_kind(pcVar39->declarator,cVar28);
    decl_set_name(pcVar39->declarator,g_name_formal);
    if ((((g_compile_flags_c8 & 0x10000000) != 0) && ((pcVar13->spec).type_sym != (c1_symbol *)0x0))
       && ((((pcVar13->spec).type_sym)->kind & 0x1f) == 4)) {
      pcVar31 = type_innermost_base((pcVar13->spec).type);
      if (((pcVar31->code & 0x20f) == 0x201) && (((pcVar13->spec).spec[0] & 0x80) == 0)) {
        iVar34 = sym_scope_index((pcVar13->spec).type_sym);
        if (iVar34 == 0) {
          bVar44 = true;
          pvVar22 = (void *)sym_name((pcVar13->spec).type_sym);
          if ((*(uint *)((int)pvVar22 + 8) & 0x2000000) != 0) {
            cell = lookup_name_in_context(g_current_scope,pvVar22,0x20);
            if (cell != (c1_lookup_entry *)0x0) {
              value_word0(&cell->sym);
            }
            diag_error(0x3af);
          }
          decl_set_name(pcVar39->declarator,pvVar22);
        }
      }
    }
    (pcVar13->spec).spec[0] = (pcVar13->spec).spec[0] & 0x7f;
    pcVar38 = pcVar13;
    pcVar14 = decl_declarator_record(pcVar39->declarator);
    decl_check_conversion_return_type(pcVar14,&pcVar38->spec);
    pcVar14 = decl_declarator_record(pcVar39->declarator);
    decl_finish_declarator(pcVar14);
    decl_declarator_set_specifiers(pcVar39->declarator,&pcVar13->spec);
    decl_process_declaration(pcVar39->declarator);
    pcVar30 = sym_new_from_declarator(pcVar39->declarator,0xffffffff);
    if (bVar44) {
      bVar11 = type_code_high_bit(pcVar30->type);
      if (bVar11 != 0) {
        sym_name(pcVar30);
        diag_error(0x395);
        pcVar30->flags3 = pcVar30->flags3 | 4;
      }
    }
    g_declarator_paren_base = g_declarator_paren_base + -1;
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfc;
    value_base[1].sym = pcVar30;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x108:
  case 0x10f:
    goto switchD_10421905_caseD_105;
  case 0x10b:
  case 0x112:
    qualified_type_merge(&value_base[1].mods,&pcVar39->mods,(c1_u32)g_yy_lookahead);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x10c:
    diag_warning(1,0xe6);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x10d:
    operator_id_set(&value_base[1].mods,(short)g_tree_op_to_il_op[(pcVar39->spec).spec[0]],
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
    operator_id_set(&value_base[1].mods,(short)g_tree_op_to_il_op[(pcVar39->spec).spec[0]],
                    (void *)0x0);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x114:
    operator_id_set(&value_base[1].mods,(pcVar39->ptr_op).kind,(void *)0x0);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x115:
    bits = value_u16_at2(*(c1_type **)((int)pcVar13 + 0x40));
    pcVar31 = type_without_flags(*(c1_type **)((int)pcVar13 + 0x40),0x3e0);
    *(c1_type **)((int)pcVar13 + 0x40) = pcVar31;
    decl_warn_unexpected_specifiers_1(&pcVar39->spec);
    operator_id_set(&value_base[1].mods,bits,(void *)0x0);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x116:
    pcVar30 = type_parse_based_specifier(pcVar39->ptr);
    operator_id_set(&value_base[1].mods,0x18,pcVar30);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x117:
    pcVar23 = expr_check_this_usage();
    lVar45 = g_enum_value;
    if (pcVar23 == (c1_node *)0x0) {
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
    pcVar32 = decl_declarator_alloc();
    if (pcVar32 == (c1_declarator *)0x0) {
LAB_10465f34:
      value_base[1].words[0] = 0;
      lVar45 = g_enum_value;
    }
    else {
      pcVar32 = decl_declarator_init(pcVar32,g_name_abstract_declarator,4,(c1_overload_set *)0x0);
      value_base[1].declarator = pcVar32;
      lVar45 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0x11d:
    pcVar32 = decl_declarator_alloc();
    if (pcVar32 == (c1_declarator *)0x0) {
      pcVar14 = decl_declarator_record((c1_declarator *)0x0);
      type_check_based_form(pcVar14,&pcVar39->mods);
      value_base[1].words[0] = 0;
      lVar45 = g_enum_value;
    }
    else {
      pcVar32 = decl_declarator_init(pcVar32,g_name_abstract_declarator,4,(c1_overload_set *)0x0);
      pcVar14 = decl_declarator_record(pcVar32);
      type_check_based_form(pcVar14,&pcVar39->mods);
      value_base[1].declarator = pcVar32;
      lVar45 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0x11e:
    pcVar32 = decl_declarator_alloc();
    if (pcVar32 == (c1_declarator *)0x0) {
      pvVar22 = pcVar39->ptr;
      pcVar32 = (c1_declarator *)0x0;
    }
    else {
      pcVar32 = decl_declarator_init(pcVar32,g_name_abstract_declarator,4,(c1_overload_set *)0x0);
      pvVar22 = pcVar39->ptr;
    }
    goto LAB_10467272;
  case 0x11f:
    pcVar32 = decl_declarator_alloc();
    if (pcVar32 == (c1_declarator *)0x0) {
      pcVar32 = (c1_declarator *)0x0;
    }
    else {
      pcVar32 = decl_declarator_init(pcVar32,g_name_abstract_declarator,4,(c1_overload_set *)0x0);
    }
    pcVar14 = decl_declarator_record(pcVar32);
    type_check_based_form(pcVar14,&pcVar13->mods);
    pvVar22 = pcVar39->ptr;
LAB_10467272:
    piVar20 = decl_declarator_record(pcVar32);
    decl_append_function_layer(piVar20,pvVar22);
    goto LAB_10421a0f;
  case 0x120:
    pcVar14 = decl_declarator_record(pcVar39->declarator);
    decl_declarator_append_pointer_op(pcVar14,&pcVar13->ptr_op);
    lVar45 = g_enum_value;
switchD_10421905_caseD_e5:
    g_enum_value = lVar45;
    value_base[1].ptr = (void *)pcVar39->words[0];
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x122:
    pcVar23 = pcVar13->node;
    pvVar22 = decl_declarator_record(value_base[1].declarator);
    type_check_array_bound_constant_2(pvVar22,pcVar23);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x123:
    pvVar22 = pcVar39->ptr;
    piVar20 = decl_declarator_record(value_base[1].declarator);
    decl_append_function_layer(piVar20,pvVar22);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x126:
    pcVar32 = decl_declarator_alloc();
    if (pcVar32 == (c1_declarator *)0x0) {
      pcVar32 = (c1_declarator *)0x0;
      pcVar13 = pcVar39;
      lVar45 = g_enum_value;
    }
    else {
      pcVar32 = decl_declarator_init(pcVar32,(fe_name *)0x0,0,(c1_overload_set *)0x0);
      pcVar13 = pcVar39;
      lVar45 = g_enum_value;
    }
LAB_1042192a:
    g_enum_value = lVar45;
    pcVar14 = decl_declarator_record(pcVar32);
    decl_declarator_append_pointer_op(pcVar14,&pcVar13->ptr_op);
LAB_10421939:
    value_base[1].declarator = pcVar32;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x127:
  case 0x1e6:
    pcVar14 = decl_declarator_record(pcVar39->declarator);
    decl_declarator_append_pointer_op(pcVar14,&pcVar13->ptr_op);
    lVar45 = g_enum_value;
LAB_10467c9b:
    g_enum_value = lVar45;
    value_base[1].ptr = (void *)pcVar39->words[0];
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x128:
    in_stack_00000040 = pcVar13[-1].words[0];
    in_stack_00000044 = *(void **)((int)pcVar13 + -0x24);
    type_pair_record_init(&value_base[1].ptr_op,(c1_decl_modifier *)&stack0x00000040,&pcVar39->mods)
    ;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x129:
    pcVar21 = u16_value_init((c1_decl_modifier *)&stack0x0000008c,0);
    type_pair_record_init(&value_base[1].ptr_op,pcVar21,&pcVar39->mods);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x12a:
    in_stack_00000048 = pcVar13[-1].words[0];
    in_stack_0000004c = *(void **)((int)pcVar13 + -0x24);
    type_warn_qualifiers_on_reference
              (&value_base[1].ptr_op,(c1_decl_modifier *)&stack0x00000048,&pcVar39->mods);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 299:
    pcVar21 = u16_value_init((c1_decl_modifier *)&stack0x00000084,0);
    type_warn_qualifiers_on_reference(&value_base[1].ptr_op,pcVar21,&pcVar39->mods);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 300:
    in_stack_00000038 = pcVar13[-1].words[0];
    in_stack_0000003c = *(void **)((int)pcVar13 + -0x24);
    qualified_name_record_init
              (&value_base[1].ptr_op,pcVar13->qualified,(c1_decl_modifier *)&stack0x00000038,
               &pcVar39->mods);
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
    pcVar30 = sym_new_of_kind('\v',g_name_ellipsis,iVar34);
    value_base[1].sym = pcVar30;
    pcVar31 = type_intern_basic_parts(0x80d,0,0);
    (value_base[1].sym)->type = pcVar31;
    sym_mark_ellipsis_parameter(value_base[1].sym);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x130:
    if ((g_opt_Zg == '\0') && ((g_compile_flags_c4 & 0x800000) == 0)) {
      if ((pcVar39->spec).spec[0] != 0xaa) {
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
    pcVar23 = pcVar13->node;
    if (pcVar23 != (c1_node *)0x0) {
      if (pcVar23->op == 0xe8) {
        pcVar23 = property_build_access('t',pcVar23,(c1_node *)0x0);
        pcVar13->node = pcVar23;
      }
      cVar9 = '\x01';
      pcVar23 = expr_resolve_address_of_overload(pcVar13->node);
      pcVar23 = expr_warn_no_effect(pcVar23,cVar9);
      pcVar13->node = pcVar23;
      pcVar23 = expr_full_expression_guarded(pcVar23,2);
      stmt_emit_expression(pcVar23);
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
    if ((pcVar39->spec).spec[0] != '\0') {
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
    (pcVar39->spec).spec[0] = cVar10;
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
      pcVar23 = expr_resolve_address_of_overload(pcVar13[-1].node);
      pcVar13[-1].node = pcVar23;
      pcVar23 = stmt_check_controlling_expression(pcVar23,0);
      pcVar13[-1].node = pcVar23;
      stmt_emit_condition(pcVar23,g_loop_top_label_stack->label,1);
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
    pcVar23 = pcVar13->node;
    if ((pcVar23 != (c1_node *)0x0) && (pcVar23->op == 0xe8)) {
      pcVar23 = property_build_access('\x01',pcVar23,(c1_node *)0x0);
      pcVar13->node = pcVar23;
    }
    pcVar23 = expr_resolve_address_of_overload(pcVar13->node);
    pcVar13->node = pcVar23;
    stmt_emit_return_value(pcVar23,2);
    iVar34 = parse_error_recovery_count();
    if (iVar34 != 0) goto LAB_10422a54;
    arena_reset(5);
    g_string_literal_cur = &g_string_literal_buffer;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x149:
    pcVar30 = (c1_symbol *)label_find_in_function(pcVar13->words[0]);
    if (pcVar30 == (c1_symbol *)0x0) {
      pcVar30 = (c1_symbol *)label_new_user(pcVar13->words[0]);
      label_register(pcVar30);
      stmt_goto_flow_state(pcVar30,0);
    }
    else {
      stmt_goto_flow_state(pcVar30,1);
    }
    pcVar23 = tree_new_symbol_ref(pcVar30,'\0');
    il_emit_tuple(0x3a,pcVar23);
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
    pcVar25 = token_static_for_code(uVar55);
    token_source_unget((c1_token_reader *)&g_token_position,pcVar25);
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
      if ((pcVar39->spec).spec[0] != '\0') {
        g_yylval = CONCAT31(g_yylval._1_3_,0xaa);
        pcVar27 = arena_or_pool_alloc(0x30,4);
        if (pcVar27 == (c1_u8 *)0x0) goto LAB_104671eb;
        g_yy_lookahead = token_init(pcVar27,'u',&g_yylval);
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
    decl_pop_declarator_state(pcVar39->params);
    cVar10 = eh_check_catch_type_count(pcVar39->params);
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
    expr_warn_no_effect(pcVar39->node,'\0');
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x16a:
    pcVar32 = (c1_declarator *)0x0;
    g_pending_access_check[g_paren_depth] = (c1_symbol *)0x0;
    if (pcVar39->declarator != (c1_declarator *)0x0) {
      pcVar30 = decl_declarator_symbol(pcVar39->declarator);
      if (pcVar30 == (c1_symbol *)0x0) goto LAB_10467c7c;
      pcVar30 = decl_declarator_symbol(pcVar39->declarator);
      pvVar22 = (void *)sym_name(pcVar30);
      pcVar23 = expr_lookup_name_expression(pvVar22);
      value_base[1].node = pcVar23;
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
      pcVar23 = expr_resolve_address_of_overload(pcVar13[-1].node);
      stmt_case_label(pcVar23);
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
        pcVar23 = label_new(0x14);
        g_default_label_stack->label = pcVar23;
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
    pcVar23 = label_new(0x1e);
    value_base[1].node = pcVar23;
    if (pcVar13->node != (c1_node *)0x0) {
      pcVar23 = expr_resolve_address_of_overload(pcVar13->node);
      pcVar13->node = pcVar23;
      pcVar23 = stmt_check_controlling_expression(pcVar23,0);
      pcVar13->node = pcVar23;
      stmt_emit_condition(pcVar23,value_base[1].node,0);
    }
    stmt_if_then_begin_flow_state();
    parse_paren_depth_pop();
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfe;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x173:
    func_end_compound_statement(pcVar13[-1].node,'\0');
    stmt_else_begin_flow_state();
    pcVar23 = label_new(0x1e);
    il_emit_tuple(0x3a,pcVar23);
    label_emit_definition(pcVar13[-1].node);
    il_emit_line_record_24();
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfe;
    acStack_24[1] = 0x10422c59;
    parse_begin_compound_value(pcVar23);
    value_base[1].node = pcVar23;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x177:
    value_base[1].spec.spec[0] = (pcVar39->spec).spec[0];
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x178:
    if (g_ms_extensions == '\0') {
      cVar10 = parse_begin_compound_value((c1_node *)0x0);
      (pcVar39->spec).spec[0] = cVar10;
    }
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] | 0x80;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x179:
    if (pcVar13->node != (c1_node *)0x0) {
      cVar9 = '\x01';
      pcVar23 = expr_resolve_address_of_overload(pcVar13->node);
      pcVar23 = expr_warn_no_effect(pcVar23,cVar9);
      pcVar13->node = pcVar23;
      pcVar23 = expr_full_expression_guarded(pcVar23,2);
      stmt_emit_expression(pcVar23);
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
    pcVar23 = stmt_check_controlling_expression(pcVar13->node,0);
    pcVar13->node = pcVar23;
    func_flow_state_note_27();
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x17b:
    cVar9 = '\x01';
    pcVar23 = expr_resolve_address_of_overload(pcVar13[-1].node);
    pcVar23 = expr_warn_no_effect(pcVar23,cVar9);
    pcVar13[-1].node = pcVar23;
    stmt_for_head((c1_node *)0x0,pcVar13[-4].node,pcVar23);
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
    (pcVar39->spec).spec[0] = cVar10;
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] | 0x80;
    func_flow_state_note_19();
    stmt_while_head();
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x17d:
    cVar9 = '\0';
    pcVar23 = expr_resolve_address_of_overload(pcVar13->node);
    pcVar23 = expr_warn_no_effect(pcVar23,cVar9);
    pcVar13->node = pcVar23;
    pcVar23 = stmt_check_controlling_expression(pcVar23,0);
    pcVar13->node = pcVar23;
    stmt_emit_loop_test(pcVar23);
    parse_paren_depth_pop();
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfe;
    func_flow_state_note_1c();
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x17e:
    cVar10 = parse_begin_compound_value((c1_node *)0x0);
    (pcVar39->spec).spec[0] = cVar10;
    func_flow_state_note_31();
    lVar45 = g_enum_value;
  case 0x1b0:
    g_enum_value = lVar45;
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] | 3;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x180:
    pcVar23 = expr_resolve_address_of_overload(pcVar13[-2].node);
    stmt_switch_head((int)pcVar23);
    lVar45 = g_enum_value;
switchD_10421905_caseD_6f:
    g_enum_value = lVar45;
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfc;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x181:
    cVar9 = '\0';
    pcVar23 = expr_resolve_address_of_overload(pcVar39->node);
    pcVar23 = expr_warn_no_effect(pcVar23,cVar9);
    cVar46 = (c1_decl_modifier)expr_eval_constant_expression(pcVar23);
    value_base[1].mods = cVar46;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x183:
    cVar9 = '\0';
    pcVar23 = expr_resolve_address_of_overload(pcVar39->node);
    pcVar23 = expr_warn_no_effect(pcVar23,cVar9);
    value_base[1].node = pcVar23;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x184:
  case 0x19a:
    pcVar23 = expr_build_binary((pcVar13->spec).spec[0],pcVar13[-1].node,pcVar39->node);
    value_base[1].node = pcVar23;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x185:
    pcVar23 = expr_build_zero_pair();
    value_base[1].node = pcVar23;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x186:
    pcVar23 = expr_build_throw(pcVar39->node);
    value_base[1].node = pcVar23;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x187:
    if ((pcVar13[-1].declarator != (c1_declarator *)0x0) &&
       (pcVar23 = pcVar39->node, pcVar23 != (c1_node *)0x0)) {
      pcVar31 = decl_declarator_record(pcVar13[-1].declarator);
      pcVar23 = expr_resolve_function_address(pcVar31,pcVar23);
joined_r0x104676a9:
      if (pcVar23 == (c1_node *)0x0) {
        expr_report_function_operand('4',pcVar39->node);
      }
      goto LAB_10422ec5;
    }
    break;
  case 0x188:
    if ((pcVar13[-1].declarator != (c1_declarator *)0x0) &&
       (pcVar23 = pcVar39->node, pcVar23 != (c1_node *)0x0)) {
      pcVar31 = decl_declarator_record(pcVar13[-1].declarator);
      pcVar23 = expr_resolve_function_address(pcVar31,pcVar23);
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
    pcVar23 = pcVar39->node;
LAB_10422ec5:
    pcVar23 = expr_build_binary((pcVar13->spec).spec[0],pcVar13[-1].node,pcVar23);
    value_base[1].node = pcVar23;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x18a:
    pcVar23 = expr_build_conditional(pcVar13[-3].node,pcVar13[-1].node,pcVar39->node);
    value_base[1].node = pcVar23;
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
    pcVar23 = expr_build_binary(pcVar13[-1].spec.spec[0],pcVar13[-2].node,pcVar39->node);
    value_base[1].node = pcVar23;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x199:
    pcVar23 = expr_check_based_operator(pcVar13[-1].node,pcVar39->node);
    value_base[1].node = pcVar23;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x19d:
    g_compile_flags_c8 = g_compile_flags_c8 | 1;
    pcVar23 = pcVar39->node;
    cVar28 = pcVar13->words[0];
    uVar48 = (undefined1)cVar28;
    uVar50 = (undefined1)(cVar28 >> 8);
    uVar40 = (undefined2)(cVar28 >> 0x10);
    cVar10 = 'd';
LAB_10422f46:
    g_enum_value = lVar45;
    pcVar23 = expr_build_cast(cVar10,(c1_symbol *)CONCAT22(uVar40,CONCAT11(uVar50,uVar48)),pcVar23);
    value_base[1].node = pcVar23;
    g_compile_flags_c8 = g_compile_flags_c8 & 0xfffffffe;
    tree_clear_value_link(value_base[1].node);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x19e:
    goto switchD_10421905_caseD_19b;
  case 0x19f:
    (pcVar13->spec).spec[0] = ((pcVar13->spec).spec[0] == '@') + 'T';
    pcVar23 = tree_new_int_constant(1);
    pcVar23 = expr_build_binary((pcVar13->spec).spec[0],pcVar39->node,pcVar23);
    value_base[1].node = pcVar23;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1a0:
    cVar28 = expr_build_unary(0x3d,pcVar39->node);
    value_base[1].words[0] = cVar28;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1a1:
    pcVar30 = pcVar39->sym;
    if (pcVar30 == (c1_symbol *)0x0) {
      value_base[1].words[0] = 0;
      lVar45 = g_enum_value;
    }
    else if ((pcVar30->kind == '=') && ((c1_symbol *)pcVar30->type != (c1_symbol *)0x0)) {
      pcVar23 = expr_address_of_member((c1_symbol *)pcVar30->type);
      value_base[1].node = pcVar23;
      lVar45 = g_enum_value;
    }
    else {
      if ((pcVar30->kind == 'S') && ((((c1_node *)pcVar30->type)->kind & 7) == 4)) {
        iVar34 = yyparse_cpp_address_of_member_leaf
                           ((c1_node *)pcVar30->type,value_base,pcVar39,parser,state_sp,
                            saved_lookahead,saved_rule);
        return iVar34;
      }
      g_compile_flags_c8 = g_compile_flags_c8 | 4;
      cVar28 = expr_build_unary(0x31,pcVar39->node);
      value_base[1].words[0] = cVar28;
      g_compile_flags_c8 = g_compile_flags_c8 & 0xfffffffb;
      lVar45 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0x1a2:
    pcVar23 = (c1_node *)expr_build_unary(0x86,pcVar39->node);
    value_base[1].node = pcVar23;
    tree_clear_value_link(pcVar23);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1a3:
    cVar28 = expr_build_unary(0x5a,pcVar39->node);
    value_base[1].words[0] = cVar28;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1a4:
    cVar28 = expr_build_unary(0x3c,pcVar39->node);
    value_base[1].words[0] = cVar28;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1a6:
    cVar28 = expr_build_unary(0x59,pcVar39->node);
    value_base[1].words[0] = cVar28;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1a7:
    (*g_idb->vtbl->idb_note_sizeof)(g_idb);
    if (pcVar39->node == (c1_node *)0x0) {
      value_base[1].words[0] = 0;
      g_sizeof_depth = g_sizeof_depth + -1;
      lVar45 = g_enum_value;
    }
    else {
      pcVar23 = expr_build_sizeof(pcVar39->node);
      value_base[1].node = pcVar23;
      g_sizeof_depth = g_sizeof_depth + -1;
      lVar45 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0x1a8:
    (*g_idb->vtbl->idb_note_sizeof)(g_idb);
    pcVar23 = expr_sizeof_type(pcVar39->sym->type);
    value_base[1].node = pcVar23;
    g_sizeof_depth = g_sizeof_depth + -1;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1ad:
    cVar28 = expr_build_unary(0xf0,pcVar13->node);
    value_base[1].words[0] = cVar28;
    parse_paren_depth_pop();
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1af:
    g_member_access_op = '\x01';
    if ((pcVar13->node != (c1_node *)0x0) && (pcVar13->node->op == '7')) {
      diag_warning(4,0x2c5);
    }
    pcVar23 = expr_build_binary(pcVar13[-1].spec.spec[0],pcVar13[-2].node,pcVar13->node);
    value_base[1].node = pcVar23;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1b1:
    pcVar23 = pcVar13[-1].node;
    if ((pcVar23 != (c1_node *)0x0) && ((pcVar23->kind & 0x88) == 0)) {
      if ((g_compile_flags_c8 & 0x800000) != 0) {
        if (pcVar39->node != (c1_node *)0x0) {
          diag_error(0x209);
          pcVar23 = tree_new_zero_flagged();
        }
        value_base[1].node = pcVar23;
        g_compile_flags_c8 = g_compile_flags_c8 & 0xff7fffff;
        g_member_access_op = '\x01';
        lVar45 = g_enum_value;
        goto switchD_10421905_caseD_1;
      }
      pcVar23 = (c1_node *)expr_build_call(pcVar23,pcVar39->node);
    }
    value_base[1].node = pcVar23;
    lVar45 = g_enum_value;
switchD_10421905_caseD_19b:
    g_member_access_op = '\x01';
    goto switchD_10421905_caseD_1;
  case 0x1b4:
    g_member_access_op = '\x01';
    pcVar23 = tree_new_int_constant(1);
    pcVar23 = expr_build_binary((pcVar39->spec).spec[0],pcVar13->node,pcVar23);
    value_base[1].node = pcVar23;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1b5:
    g_member_access_op = '\x01';
    pcVar23 = class_check_operator_global_form
                        (CONCAT22((short)((uint)g_yy_lookahead >> 0x10),
                                  CONCAT11((char)((uint)g_yy_lookahead >> 8),(pcVar13->spec).spec[0]
                                          )),pcVar39->node);
    value_base[1].node = pcVar23;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1b6:
    if ((pcVar39->spec).spec[0] != 'D') {
      diag_error(0x2f8);
    }
    parse_paren_depth_push(1);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1b7:
    if ((pcVar39->spec).spec[0] != 0xbf) {
      iVar34 = yyparse_cpp_named_cast_expected_gt
                         ((pcVar39->spec).spec[0],value_base,parser,state_sp,saved_lookahead,
                          saved_rule);
      return iVar34;
    }
    goto LAB_104232f5;
  case 0x1b8:
    if (pcVar39->words[0] != 0) {
      g_compile_flags_c8 = g_compile_flags_c8 | 1;
      pcVar23 = pcVar39->node;
      pcVar30 = parse_type_id_declarator(pcVar13[-2].declarator,&pcVar13[-3].spec);
      uVar48 = SUB41(pcVar30,0);
      uVar50 = (undefined1)((uint)pcVar30 >> 8);
      uVar40 = (undefined2)((uint)pcVar30 >> 0x10);
      cVar10 = pcVar13[-6].spec.spec[0];
      lVar45 = g_enum_value;
      goto LAB_10422f46;
    }
    break;
  case 0x1b9:
    pcVar23 = expr_build_typeid_expression(pcVar13->node);
    value_base[1].node = pcVar23;
    parse_paren_depth_pop();
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1ba:
    pcVar30 = (c1_symbol *)decl_finish_declarator_then_type(pcVar13->ptr,(byte *)pcVar13[-1].words);
    goto LAB_104232f2;
  case 0x1bb:
    pcVar23 = expr_build_uuidof_expression(pcVar13->node);
    value_base[1].node = pcVar23;
    parse_paren_depth_pop();
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1bc:
    pcVar30 = decl_finish_declarator_uuidof(pcVar13->ptr,(byte *)pcVar13[-1].words);
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
    pcVar23 = tree_new_constant(pcVar39->type,(void *)((int)pcVar13 + 0x30),g_expr_arena_index);
    value_base[1].node = pcVar23;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1c1:
    type_string_literal_array(pcVar39->node);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1c2:
    pcVar23 = expr_check_this_usage();
    value_base[1].node = pcVar23;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1c3:
    pcVar23 = expr_build_builtin_unary(0x76,pcVar13->node);
    value_base[1].node = pcVar23;
    tree_clear_value_link(pcVar23);
    parse_paren_depth_pop();
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1c5:
    PTR_104d2158 = expr_prepare_member_access_object
                             (g_current_scope,(pcVar39->spec).spec[0],pcVar13->node,'\0');
    g_member_access_op = (pcVar39->spec).spec[0];
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1c6:
    pcVar23 = expr_build_member_access(g_member_access_op,PTR_104d2158,pcVar39->node);
    value_base[1].node = pcVar23;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1c7:
    pcVar23 = expr_build_pseudo_destructor_call(g_member_access_op,PTR_104d2158,pcVar39->words[0]);
    value_base[1].node = pcVar23;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1c8:
    pcVar30 = value_word0(pcVar39->cell);
    pcVar23 = expr_build_pseudo_destructor_call(g_member_access_op,PTR_104d2158,(int)pcVar30);
    value_base[1].node = pcVar23;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1c9:
    pfVar29 = sym_name_of_ref(pcVar39->cell);
    pcVar23 = expr_build_pseudo_destructor_call(g_member_access_op,PTR_104d2158,(int)pfVar29);
    value_base[1].node = pcVar23;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1ca:
    pcVar23 = expr_check_qualified_pseudo_destructor
                        (g_member_access_op,PTR_104d2158,&pcVar13[-2].spec,&pcVar39->spec);
    value_base[1].node = pcVar23;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1cb:
    pcVar23 = expr_lookup_name_expression(pcVar39->ptr);
    value_base[1].node = pcVar23;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1cc:
    pvVar22 = decl_declarator_record(pcVar39->declarator);
    if (pvVar22 == (void *)0x0) {
      pcVar30 = (c1_symbol *)sym_name(pcVar39->sym);
      pcVar23 = sym_is_data_or_function(pcVar30);
      value_base[1].node = pcVar23;
      lVar45 = g_enum_value;
    }
    else {
      pcVar30 = (c1_symbol *)sym_name(pcVar39->sym);
      pcVar23 = sym_is_data_or_function(pcVar30);
      if (pcVar23->right != (void *)0x0) {
        diag_fatal(1);
      }
      pvVar22 = value_fieldc(pcVar39->ptr);
      pcVar23->right = pvVar22;
      value_base[1].node = pcVar23;
      lVar45 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0x1cd:
    pcVar30 = value_word0(pcVar39->cell);
    pcVar23 = sym_is_data_or_function(pcVar30);
    value_base[1].node = pcVar23;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1ce:
    pcVar23 = expr_lookup_name_expression(*(void **)((int)pcVar13 + 0x2c));
    value_base[1].node = pcVar23;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1cf:
    pfVar29 = decl_conversion_function_name(*(c1_type **)((int)pcVar13 + 0x40));
    pcVar23 = expr_lookup_name_expression(pfVar29);
    value_base[1].node = pcVar23;
    g_compile_flags_c4 = g_compile_flags_c4 & 0xfffffffb;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1d0:
    pcVar30 = value_word0(pcVar39->cell);
    lVar45 = g_enum_value;
    if ((pcVar30->flags3 & 4) == 0) {
      pcVar30 = value_word0(pcVar39->cell);
      pcVar23 = sym_is_data_or_function(pcVar30);
      pvVar22 = decl_declarator_record(pcVar39->declarator);
      if (pvVar22 != (void *)0x0) {
        if (pcVar23->right != (void *)0x0) {
          diag_fatal(1);
        }
        pvVar22 = decl_declarator_record(pcVar39->declarator);
        pcVar23->right = pvVar22;
      }
      value_base[1].node = pcVar23;
      lVar45 = g_enum_value;
      goto switchD_10421905_caseD_1;
    }
    break;
  case 0x1d1:
    if (pcVar13->cell != (c1_symbol **)0x0) {
      pcVar31 = *(c1_type **)((int)pcVar13 + 0x40);
      pcVar30 = value_word0(pcVar13->cell);
      decl_qualified_conversion_function_name(pcVar30,pcVar31);
      pcVar30 = value_word0(pcVar13->cell);
      pcVar23 = sym_is_data_or_function(pcVar30);
      pvVar22 = decl_declarator_record(pcVar13->declarator);
      if (pvVar22 != (void *)0x0) {
        if (pcVar23->right != (void *)0x0) {
          diag_fatal(1);
        }
        pvVar22 = decl_declarator_record(pcVar13->declarator);
        pcVar23->right = pvVar22;
      }
      value_base[1].node = pcVar23;
    }
    g_compile_flags_c4 = g_compile_flags_c4 & 0xfffffffb;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1d3:
    pcVar30 = parse_type_id_declarator(pcVar13->declarator,&pcVar13[-1].spec);
LAB_104232f2:
    value_base[1].sym = pcVar30;
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
    pcVar23 = tree_append_list_item((c1_node *)0x0,pcVar39->node,0);
    value_base[1].node = pcVar23;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1d7:
    pcVar23 = tree_append_list_item(pcVar13[-1].node,pcVar39->node,0);
    value_base[1].node = pcVar23;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1d8:
    pcVar23 = arena_alloc(g_arenas + g_expr_arena_index,0x18);
    pcVar23->kind = '\x05';
    pcVar23->op = '\a';
    pcVar23->left = (void *)pcVar39->words[0];
    pcVar23->right = *(void **)((int)pcVar13 + 0x2c);
    value_base[1].node = pcVar23;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1d9:
    lex_concatenate_strings((c1_string_value *)(pcVar13->declarator->spec + 4),&pcVar39->str);
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
    pcVar14 = decl_declarator_record(pcVar13->declarator);
    pcVar23 = decl_record_new_array_bound(pcVar14);
    cVar28 = pcVar39->words[0];
    uVar48 = (undefined1)cVar28;
    uVar50 = (undefined1)(cVar28 >> 8);
    uVar40 = (undefined2)(cVar28 >> 0x10);
    pcVar30 = sym_new_from_declarator(pcVar13->declarator,0xffffffff);
    pcVar23 = expr_build_new_or_placeholder
                        (pcVar13[-1].spec.spec[0],0,pcVar30,CONCAT22(uVar40,CONCAT11(uVar50,uVar48))
                         ,(int)pcVar23);
    value_base[1].node = pcVar23;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1dc:
    pcVar14 = decl_declarator_record(pcVar13->declarator);
    pcVar23 = decl_record_new_array_bound(pcVar14);
    cVar28 = pcVar39->words[0];
    uVar48 = (undefined1)cVar28;
    uVar50 = (undefined1)(cVar28 >> 8);
    uVar40 = (undefined2)(cVar28 >> 0x10);
    pcVar30 = sym_new_from_declarator(pcVar13->declarator,0xffffffff);
    pcVar23 = expr_build_new_or_placeholder
                        (pcVar13[-1].spec.spec[0],0,pcVar30,CONCAT22(uVar40,CONCAT11(uVar50,uVar48))
                         ,(int)pcVar23);
    value_base[1].node = pcVar23;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1dd:
  case 0x1de:
    pcVar14 = decl_declarator_record(pcVar13->declarator);
    pcVar23 = decl_record_new_array_bound(pcVar14);
    cVar28 = pcVar39->words[0];
    uVar48 = (undefined1)cVar28;
    uVar50 = (undefined1)(cVar28 >> 8);
    uVar40 = (undefined2)(cVar28 >> 0x10);
    pcVar30 = sym_new_from_declarator(pcVar13->declarator,0xffffffff);
    pcVar23 = expr_build_new_or_placeholder
                        (pcVar13[-2].spec.spec[0],pcVar13[-1].words[0],pcVar30,
                         CONCAT22(uVar40,CONCAT11(uVar50,uVar48)),(int)pcVar23);
    value_base[1].node = pcVar23;
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
    decl_set_local_key_flag(pcVar39->declarator,'\x01');
    (pcVar13->spec).spec[0] = (pcVar13->spec).spec[0] & 0x7f;
    pcVar38 = pcVar13;
    pcVar14 = decl_declarator_record(pcVar39->declarator);
    decl_check_conversion_return_type(pcVar14,&pcVar38->spec);
    pcVar14 = decl_declarator_record(pcVar39->declarator);
    decl_allow_variable_array_bound(pcVar14);
    pcVar14 = decl_declarator_record(pcVar39->declarator);
    decl_finish_declarator(pcVar14);
    decl_declarator_set_specifiers(pcVar39->declarator,&pcVar13->spec);
    decl_process_declaration(pcVar39->declarator);
    pcVar31 = (c1_type *)sym_name(pcVar39->sym);
    iVar34 = type_chain_is_cv_qualified(pcVar31);
    if ((char)iVar34 == '\0') {
      pcVar31 = (c1_type *)sym_name(pcVar39->sym);
      cVar10 = type_is_void(pcVar31);
      if (cVar10 != '\0') {
        diag_error(0x1d5);
      }
    }
    else {
      sym_name(pcVar39->sym);
      diag_error(0x1d4);
    }
    g_declarator_paren_base = g_declarator_paren_base + -1;
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfe;
    value_base[1].ptr = (void *)pcVar39->words[0];
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1e2:
    pcVar32 = decl_declarator_alloc();
    if (pcVar32 == (c1_declarator *)0x0) {
      pcVar32 = (c1_declarator *)0x0;
    }
    else {
      pcVar32 = decl_declarator_init(pcVar32,g_name_new_target,4,(c1_overload_set *)0x0);
    }
    decl_set_local_key_flag(pcVar32,'\x01');
    pvVar22 = decl_declarator_record(pcVar39->declarator);
    d_00 = decl_declarator_record(pcVar32);
    decl_set_name(d_00,pvVar22);
    pcVar14 = decl_declarator_record(pcVar32);
    decl_finish_declarator(pcVar14);
    decl_process_declaration(pcVar32);
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfe;
    value_base[1].declarator = pcVar32;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1e3:
    pcVar32 = pcVar13->declarator;
    decl_set_local_key_flag(pcVar32,'\x01');
    declarator_set_kind(pcVar32,4);
    decl_set_name(pcVar32,g_name_new_target);
    pcVar39 = pcVar13 + -1;
    (pcVar39->spec).spec[0] = pcVar13[-1].spec.spec[0] & 0x7f;
    decl_declarator_set_specifiers(pcVar32,&pcVar39->spec);
    pcVar14 = decl_declarator_record(pcVar32);
    decl_check_conversion_return_type(pcVar14,&pcVar39->spec);
    pcVar14 = decl_declarator_record(pcVar32);
    decl_allow_variable_array_bound(pcVar14);
    pcVar14 = decl_declarator_record(pcVar32);
    decl_finish_declarator(pcVar14);
    decl_process_declaration(pcVar32);
    cVar10 = type_is_cv_qualified_stripped(pcVar32);
    if (cVar10 == '\0') {
      pcVar31 = (c1_type *)sym_name((c1_symbol *)pcVar32);
      cVar10 = type_is_void(pcVar31);
      if (cVar10 != '\0') {
        diag_error(0x1d5);
      }
    }
    else {
      sym_name((c1_symbol *)pcVar32);
      diag_error(0x1d4);
    }
    g_declarator_paren_base = g_declarator_paren_base + -1;
    parse_paren_depth_pop();
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfe;
    value_base[1].words[0] = (c1_u32)pcVar32;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1e4:
    pcVar32 = decl_declarator_alloc();
    if (pcVar32 == (c1_declarator *)0x0) {
      pcVar32 = (c1_declarator *)0x0;
    }
    else {
      pcVar32 = decl_declarator_init(pcVar32,g_name_new_target,4,(c1_overload_set *)0x0);
    }
    g_declarator_paren_base = g_declarator_paren_base + 1;
    if (g_yy_lookahead != (byte *)0x0) {
      cVar10 = lex_token_code((c1xx_token *)g_yy_lookahead);
      if (cVar10 == 'v') {
        g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] | 3;
      }
    }
    value_base[1].declarator = pcVar32;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1e5:
    pcVar32 = decl_declarator_alloc();
    if (pcVar32 == (c1_declarator *)0x0) {
      pcVar32 = (c1_declarator *)0x0;
    }
    else {
      pcVar32 = decl_declarator_init(pcVar32,g_name_new_target,4,(c1_overload_set *)0x0);
    }
    pcVar14 = decl_declarator_record(pcVar32);
    type_check_based_form(pcVar14,&pcVar39->mods);
    g_declarator_paren_base = g_declarator_paren_base + 1;
LAB_10467c7c:
    value_base[1].declarator = pcVar32;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1e7:
    if ((pcVar13->node != (c1_node *)0x0) && (pcVar13->node->op == '7')) {
      diag_warning(4,0x2c5);
    }
    pcVar23 = pcVar13->node;
    pvVar22 = decl_declarator_record(value_base[1].declarator);
    type_check_array_bound_constant_2(pvVar22,pcVar23);
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1eb:
    pcVar23 = expr_build_delete((pcVar13->spec).spec[0],pcVar39->node,(c1_node *)0x0,'\0');
    value_base[1].node = pcVar23;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1ec:
    if ((pcVar13[-1].node != (c1_node *)0x0) && ((pcVar13[-1].node)->op == '7')) {
      diag_warning(4,0x2c5);
    }
    pcVar23 = expr_build_delete(pcVar13[-3].spec.spec[0],pcVar39->node,pcVar13[-1].node,'\x01');
    value_base[1].node = pcVar23;
    lVar45 = g_enum_value;
    goto switchD_10421905_caseD_1;
  }
  g_enum_value = lVar45;
  value_base[1].words[0] = 0;
  lVar45 = g_enum_value;
  goto switchD_10421905_caseD_1;
switchD_10421905_caseD_dd:
  if (pcVar13->node == (c1_node *)0x0) {
    bound = 0;
  }
  else {
    bound = expr_eval_constant_expression(pcVar13->node);
    if (((g_class_depth < 0) || (g_ms_extensions == '\0')) && (bound == 0)) {
      iVar34 = yyparse_cpp_zero_array_bound_error
                         (value_base,parser,state_sp,0,saved_lookahead,saved_rule);
      return iVar34;
    }
  }
  goto LAB_10421952;
}

