int __cdecl
yyparse_cpp_ellipsis_parameter_arena0
          (c1_yy_value *value_base,c1_yy_parser *parser,int *state_sp,byte *saved_lookahead,
          int saved_rule)

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
  c1_symbol *pcVar21;
  c1_type *pcVar22;
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
  c1_declarator *d_00;
  c1_declarator *pcVar31;
  c1_decl_record *pcVar32;
  int iVar33;
  c1_arena *a;
  uint uVar34;
  undefined4 extraout_ECX;
  short *psVar35;
  undefined2 uVar39;
  c1xx_idb_vtbl *pcVar36;
  c1_yy_value *pcVar37;
  c1_yy_value *pcVar38;
  c1_u32 *pcVar40;
  void **ppvVar41;
  undefined4 *puVar42;
  bool bVar43;
  longlong lVar44;
  c1_decl_modifier cVar45;
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
  undefined1 uVar46;
  undefined1 uVar47;
  undefined1 uVar48;
  undefined1 uVar49;
  undefined2 uVar50;
  c1_symbol **ppcVar51;
  c1xx_decl_specifiers *pcVar52;
  c1_symbol *qualifier;
  int iVar53;
  c1_overload_set *pcVar54;
  uint uVar55;
  
  lVar44 = g_enum_value;
code_r0x104225db:
  iVar53 = 0;
  uVar47 = SUB41(g_name_ellipsis,0);
  uVar49 = (undefined1)((uint)g_name_ellipsis >> 8);
  uVar50 = (undefined2)((uint)g_name_ellipsis >> 0x10);
LAB_104225ad:
  g_enum_value = lVar44;
  pcVar21 = sym_new_of_kind('\v',(fe_name *)CONCAT22(uVar50,CONCAT11(uVar49,uVar47)),iVar53);
  value_base[1].sym = pcVar21;
  pcVar22 = type_intern_basic_parts(0x80d,0,0);
  (value_base[1].sym)->type = pcVar22;
  sym_mark_ellipsis_parameter(value_base[1].sym);
  lVar44 = g_enum_value;
switchD_10421905_caseD_1:
  iVar53 = g_yy_pgo[g_yy_r1[g_yy_rule]] + 1 + *state_sp;
  pcVar13 = value_base;
  g_enum_value = lVar44;
  if ((0xfdb < iVar53) ||
     (iVar33 = (int)g_yy_action[iVar53],
     (int)g_yy_chk[g_yy_action[iVar53]] != -(uint)g_yy_r1[g_yy_rule])) {
    iVar33 = (int)g_yy_action[g_yy_pgo[g_yy_r1[g_yy_rule]]];
  }
  while( true ) {
    state_sp = state_sp + 1;
    pcVar38 = pcVar13 + 1;
    *state_sp = iVar33;
    sVar3 = g_yy_pact[iVar33];
    if (sVar3 < -999) break;
    if (g_yy_lookahead == (byte *)0x0) {
      g_yy_lookahead = yylex_cpp();
    }
    iVar53 = (int)sVar3 + (uint)g_token_class[*g_yy_lookahead];
    if (((iVar53 < 0) || (0xfdb < iVar53)) ||
       (iVar53 = (int)g_yy_action[iVar53],
       g_yy_chk[iVar53] != (ushort)g_token_class[*g_yy_lookahead])) break;
    if (parser->states + 0x3fb < state_sp) {
      yyerror_cpp("yacc stack overflow");
      g_yy_result = 1;
      iVar53 = parse_yacc_return_tail(saved_lookahead,saved_rule);
      return iVar53;
    }
    yy_copy_token_value(pcVar13 + 2,g_yy_lookahead);
    g_yy_lookahead = (byte *)0x0;
    pcVar13 = pcVar38;
    iVar33 = iVar53;
    if (0 < parser->errflag) {
      parser->errflag = parser->errflag + -1;
    }
  }
  iVar53 = (int)g_yy_def[iVar33];
  lVar44 = g_enum_value;
  if (iVar53 < 1) {
    if (iVar53 == -2) {
      if (g_yy_lookahead == (byte *)0x0) {
        g_yy_lookahead = yylex_cpp();
        lVar44 = g_enum_value;
      }
      psVar35 = g_yy_exca + g_yy_exca_index[iVar33];
      uVar2 = g_yy_exca[g_yy_exca_index[iVar33]];
      while ((uVar2 != g_token_class[*g_yy_lookahead] && (-1 < (short)uVar2))) {
        puVar1 = (ushort *)(psVar35 + 2);
        psVar35 = psVar35 + 2;
        uVar2 = *puVar1;
      }
      iVar53 = (int)psVar35[1];
      if (iVar53 < 0) {
        g_yy_result = 0;
        g_enum_value = lVar44;
        iVar53 = parse_yacc_return_tail(saved_lookahead,saved_rule);
        return iVar53;
      }
    }
    if (iVar53 == 0) {
      g_enum_value = lVar44;
      iVar53 = yyparse_cpp_error_entry
                         (0,pcVar38,state_sp,iVar33,parser,in_stack_00000018,saved_lookahead,
                          saved_rule);
      return iVar53;
    }
  }
  iVar33 = g_paren_depth;
  pcVar26 = (c1xx_token *)g_yy_lookahead;
  g_enum_value._4_4_ = (undefined4)((ulonglong)lVar44 >> 0x20);
  g_enum_value._0_4_ = (undefined4)lVar44;
  uVar55 = (uint)g_yy_r2[iVar53];
  state_sp = state_sp + -uVar55;
  value_base = pcVar38 + -uVar55;
  uVar39 = (undefined2)(uVar55 * -5 >> 0x10);
  uVar50 = (undefined2)((uint)g_name_ellipsis >> 0x10);
  uVar47 = SUB41(g_name_ellipsis,0);
  uVar49 = (undefined1)((uint)g_name_ellipsis >> 8);
  g_yy_rule = iVar53;
  g_enum_value = lVar44;
  switch(iVar53) {
  case 3:
    iVar53 = parser->error_count;
    goto LAB_104235dc;
  default:
    goto switchD_10421905_caseD_1;
  case 5:
    paren_depth_leave(pcVar13->words[0]);
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 6:
    paren_depth_leave(0);
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 8:
    if ((g_yy_lookahead == (byte *)0x0) || (*g_yy_lookahead != 0x76)) {
      pcVar52 = g_paren_level_declspecs + g_paren_depth;
      for (iVar53 = 9; iVar53 != 0; iVar53 = iVar53 + -1) {
        *(c1_u32 *)pcVar52->spec = pcVar13->words[0];
        pcVar52 = (c1xx_decl_specifiers *)(pcVar52->spec + 4);
        pcVar13 = (c1_yy_value *)(pcVar13->words + 1);
      }
      g_paren_level_flags[iVar33] = g_paren_level_flags[iVar33] | 1;
      lVar44 = g_enum_value;
    }
    else {
      pcVar40 = (c1_u32 *)(&g_paren_level_declspecs_prev_base + g_paren_depth * 0x24);
      iVar33 = 9;
      iVar53 = g_paren_depth;
LAB_10420c2b:
      for (; g_enum_value = lVar44, iVar33 != 0; iVar33 = iVar33 + -1) {
        *pcVar40 = pcVar13->words[0];
        pcVar13 = (c1_yy_value *)(pcVar13->words + 1);
        pcVar40 = pcVar40 + 1;
        lVar44 = g_enum_value;
      }
      pbVar15 = (byte *)((int)&g_function_tuple_count + iVar53 + 3);
      *pbVar15 = *pbVar15 | 1;
      lVar44 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 9:
    pcVar38 = pcVar13 + -1;
    g_declarator_paren_base = g_declarator_paren_base + -1;
    decl_check_conversion_return_type(pcVar13->declarator->decl,&pcVar38->spec);
    decl_finish_declarator(pcVar13->declarator->decl);
    pcVar37 = pcVar38;
    ppvVar41 = (void **)&pcVar13->node->unk0c;
    for (iVar53 = 6; iVar53 != 0; iVar53 = iVar53 + -1) {
      *ppvVar41 = (void *)pcVar37->words[0];
      pcVar37 = (c1_yy_value *)(pcVar37->words + 1);
      ppvVar41 = ppvVar41 + 1;
    }
    pcVar13->declarator->flags56 = pcVar13->declarator->flags56 | 0x20;
    if (g_class_depth < 0) {
      if ((g_compile_flags_c8 & 0x40) == 0) {
        g_last_declared_symbol =
             decl_declare_from_declarator(pcVar13->declarator,(byte *)pcVar38->words);
      }
      else {
        g_last_declared_symbol = pcVar13->declarator->sym;
      }
      bVar11 = g_current_scope->current->kind;
      if ((0xfa < bVar11) && (bVar11 != 0xfd)) {
        scope_pop_to_kind(g_current_scope,'\x01');
      }
      class_check_unnamed_class_member(&pcVar38->spec);
      lVar44 = g_enum_value;
    }
    else {
      pcVar13->declarator->kind = 2;
      in_stack_00000018.sym = (c1_symbol *)0x0;
      cVar9 = class_begin_member_list
                        (pcVar13->declarator,&pcVar38->spec,(c1_symbol **)&stack0x00000018);
      lVar44 = g_enum_value;
      if (((cVar9 == '\0') && (bVar11 = g_current_scope->current->kind, 0xfa < bVar11)) &&
         (bVar11 != 0xfd)) {
        scope_pop_to_kind(g_current_scope,'\x01');
        lVar44 = g_enum_value;
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
      pcVar52 = decl_specifiers_default((void *)0x0);
    }
    else {
      pcVar52 = g_paren_level_declspecs + g_paren_depth;
    }
    decl_check_conversion_return_type(pcVar13->declarator->decl,pcVar52);
    decl_finish_declarator(pcVar13->declarator->decl);
    if ((g_paren_level_flags[g_paren_depth] & 1) == 0) {
      pcVar52 = decl_specifiers_default((void *)0x0);
    }
    else {
      pcVar52 = g_paren_level_declspecs + g_paren_depth;
    }
    ppvVar41 = (void **)&pcVar13->node->unk0c;
    for (iVar53 = 6; iVar53 != 0; iVar53 = iVar53 + -1) {
      *ppvVar41 = *(void **)pcVar52->spec;
      pcVar52 = (c1xx_decl_specifiers *)(pcVar52->spec + 4);
      ppvVar41 = ppvVar41 + 1;
    }
    pcVar13->declarator->flags56 = pcVar13->declarator->flags56 | 0x20;
    if (g_class_depth < 0) {
      if ((g_compile_flags_c8 & 0x40) == 0) {
        if ((g_paren_level_flags[g_paren_depth] & 1) == 0) {
          pcVar52 = decl_specifiers_default((void *)0x0);
          g_last_declared_symbol = decl_declare_from_declarator(pcVar13->declarator,pcVar52->spec);
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
      lVar44 = g_enum_value;
      if ((0xfa < bVar11) && (bVar11 != 0xfd)) {
        scope_pop_to_kind(g_current_scope,'\x01');
        lVar44 = g_enum_value;
      }
    }
    else {
      pcVar13->declarator->kind = 2;
      in_stack_00000018.sym = (c1_symbol *)0x0;
      if ((g_paren_level_flags[g_paren_depth] & 1) == 0) {
        pcVar52 = decl_specifiers_default((void *)0x0);
      }
      else {
        pcVar52 = g_paren_level_declspecs + g_paren_depth;
      }
      cVar9 = class_begin_member_list(pcVar13->declarator,pcVar52,(c1_symbol **)&stack0x00000018);
      lVar44 = g_enum_value;
      if (((cVar9 == '\0') && (bVar11 = g_current_scope->current->kind, 0xfa < bVar11)) &&
         (bVar11 != 0xfd)) {
        scope_pop_to_kind(g_current_scope,'\x01');
        lVar44 = g_enum_value;
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
      pcVar52 = decl_specifiers_default((void *)0x0);
    }
    else {
      pcVar52 = g_paren_level_declspecs + g_paren_depth;
    }
    decl_check_conversion_return_type(pcVar13->declarator->decl,pcVar52);
    decl_finish_declarator(pcVar13->declarator->decl);
    if ((g_paren_level_flags[g_paren_depth] & 1) == 0) {
      pcVar52 = decl_specifiers_default((void *)0x0);
    }
    else {
      pcVar52 = g_paren_level_declspecs + g_paren_depth;
    }
    ppvVar41 = (void **)&pcVar13->node->unk0c;
    for (iVar53 = 6; iVar53 != 0; iVar53 = iVar53 + -1) {
      *ppvVar41 = *(void **)pcVar52->spec;
      pcVar52 = (c1xx_decl_specifiers *)(pcVar52->spec + 4);
      ppvVar41 = ppvVar41 + 1;
    }
    if ((g_paren_level_flags[g_paren_depth] & 1) == 0) {
      pcVar52 = decl_specifiers_default((void *)0x0);
    }
    else {
      pcVar52 = g_paren_level_declspecs + g_paren_depth;
    }
    g_last_declared_symbol = func_begin_member_definition(pcVar13->declarator,pcVar52->spec);
    g_declarator_paren_base = g_declarator_paren_base + -1;
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfc;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xc:
    g_compile_flags_c4 = g_compile_flags_c4 & 0xfeffffff;
    g_compile_flags_c8 = g_compile_flags_c8 & 0xfffffffd;
    bVar11 = g_current_scope->current->kind;
    if ((0xfa < bVar11) && (bVar11 != 0xfd)) {
      scope_pop_to_kind(g_current_scope,'\x01');
    }
    pcVar38 = pcVar13 + -1;
    decl_check_conversion_return_type(pcVar13->declarator->decl,&pcVar38->spec);
    decl_finish_declarator(pcVar13->declarator->decl);
    pcVar37 = pcVar38;
    ppvVar41 = (void **)&pcVar13->node->unk0c;
    for (iVar53 = 6; iVar53 != 0; iVar53 = iVar53 + -1) {
      *ppvVar41 = (void *)pcVar37->words[0];
      pcVar37 = (c1_yy_value *)(pcVar37->words + 1);
      ppvVar41 = ppvVar41 + 1;
    }
    g_last_declared_symbol =
         func_begin_member_definition(pcVar13->declarator,(byte *)pcVar38->words);
    goto LAB_10420683;
  case 0xd:
  case 0x83:
    default_argument_store_and_advance_top(pcVar13->node);
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xe:
    g_class_depth = g_class_depth + -1;
    class_begin_deferred_member_bodies();
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xf:
    class_reset_member_function_class();
    g_yy_lookahead = (byte *)lex_unget_token((c1xx_token *)g_yy_lookahead);
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x10:
    parse_external_declaration_end();
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x11:
    pch_creation_point();
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x12:
    pp_line_after_pch_options();
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x13:
    iVar53 = g_error_count;
    if (g_error_count != 0) {
LAB_104235dc:
      g_yy_result = iVar53;
      iVar53 = parse_yacc_return_tail(saved_lookahead,saved_rule);
      return iVar53;
    }
    goto switchD_10421905_caseD_1;
  case 0x14:
    pch_hdrstop();
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x15:
    if ((g_compile_flags_c8 & 0x40) == 0) {
      diag_error(0x1bf);
      lex_skip_to_closing_brace('\0');
      parse_yyerrok(parser);
      lVar44 = g_enum_value;
    }
    else {
      g_compile_flags_c8 = g_compile_flags_c8 & 0xffffffbf;
      lex_skip_to_closing_brace('\0');
      parse_yyerrok(parser);
      lVar44 = g_enum_value;
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
      pcVar52 = decl_specifiers_default((void *)0x0);
      lVar44 = g_enum_value;
    }
    else {
      pcVar52 = g_paren_level_declspecs + g_paren_depth;
    }
    g_enum_value = lVar44;
    decl_check_conversion_return_type(pcVar38->declarator->decl,pcVar52);
    decl_finish_declarator(pcVar38->declarator->decl);
    if ((g_paren_level_flags[g_paren_depth] & 1) == 0) {
      pcVar52 = decl_specifiers_default((void *)0x0);
    }
    else {
      pcVar52 = g_paren_level_declspecs + g_paren_depth;
    }
    ppvVar41 = (void **)&pcVar38->node->unk0c;
    for (iVar53 = 6; iVar53 != 0; iVar53 = iVar53 + -1) {
      *ppvVar41 = *(void **)pcVar52->spec;
      pcVar52 = (c1xx_decl_specifiers *)(pcVar52->spec + 4);
      ppvVar41 = ppvVar41 + 1;
    }
    if ((g_paren_level_flags[g_paren_depth] & 1) == 0) {
      pcVar52 = decl_specifiers_default((void *)0x0);
    }
    else {
      pcVar52 = g_paren_level_declspecs + g_paren_depth;
    }
    func_begin_member_definition(pcVar38->declarator,pcVar52->spec);
    g_declarator_paren_base = g_declarator_paren_base + -1;
    bVar11 = g_current_scope->current->kind;
    if ((0xfa < bVar11) && (bVar11 != 0xfd)) {
      scope_pop_to_kind(g_current_scope,'\x01');
    }
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfc;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1f:
    g_ctor_mem_initializers = pcVar38->node;
    func_begin_definition_frame();
    g_compile_flags_c8 = g_compile_flags_c8 & 0xffffffbf;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x20:
    funcs_check_incremental();
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x21:
    tmpl_parse_queued_definition(pcVar38->header);
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x22:
    g_compile_flags_c4 = g_compile_flags_c4 & 0xfeffffff;
    g_compile_flags_c8 = g_compile_flags_c8 & 0xfffffffd;
    bVar11 = g_current_scope->current->kind;
    if ((0xfa < bVar11) && (bVar11 != 0xfd)) {
      scope_pop_to_kind(g_current_scope,'\x01');
    }
    decl_check_conversion_return_type(pcVar38->declarator->decl,&pcVar13->spec);
    decl_finish_declarator(pcVar38->declarator->decl);
    pcVar37 = pcVar13;
    ppvVar41 = (void **)&pcVar38->node->unk0c;
    for (iVar53 = 6; iVar53 != 0; iVar53 = iVar53 + -1) {
      *ppvVar41 = (void *)pcVar37->words[0];
      pcVar37 = (c1_yy_value *)(pcVar37->words + 1);
      ppvVar41 = ppvVar41 + 1;
    }
    if (g_block_depth == '\0') {
      pcVar21 = func_begin_member_definition(pcVar38->declarator,(byte *)pcVar13->words);
      value_base[1].sym = pcVar21;
    }
    else {
      cVar9 = '\0';
      pcVar21 = decl_declare_in_current_scope(pcVar38->declarator,&pcVar13->spec);
      func_parse_definition_or_skip(pcVar21,cVar9);
      g_yy_lookahead = g_token_end_parse;
    }
LAB_10420683:
    g_declarator_paren_base = g_declarator_paren_base + -1;
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfc;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x24:
    g_compile_flags_cc = g_compile_flags_cc | 2;
    func_begin_definition_state((int *)(pcVar38->str).text);
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x25:
    pcVar21 = type_require_complete(pcVar38->sym);
    value_base[1].sym = pcVar21;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x26:
    pcVar21 = type_require_complete(pcVar38->sym);
    value_base[1].sym = pcVar21;
    lVar44 = g_enum_value;
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
    value_base[1].ptr = (void *)pcVar38->words[0];
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x2a:
    pcVar24 = tree_append_expression_list_item((c1_node *)0x0,pcVar38->node);
    value_base[1].node = pcVar24;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x2b:
    pcVar24 = tree_append_expression_list_item(pcVar13[-1].node,pcVar38->node);
    value_base[1].node = pcVar24;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x2c:
    diag_error(0x276);
    pcVar24 = tree_append_expression_list_item(pcVar13[-1].node,pcVar38->node);
    value_base[1].node = pcVar24;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x2d:
  case 0x2f:
  case 0x31:
  case 0x33:
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] | 1;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x2e:
    cVar29 = pcVar13->words[0];
    pfVar30 = pcVar13[-3].name;
    uVar47 = (undefined1)cVar29;
    uVar49 = (undefined1)(cVar29 >> 8);
    uVar50 = (undefined2)(cVar29 >> 0x10);
    goto LAB_1042079c;
  case 0x30:
    cVar29 = pcVar13->words[0];
    uVar47 = (undefined1)cVar29;
    uVar49 = (undefined1)(cVar29 >> 8);
    uVar50 = (undefined2)(cVar29 >> 0x10);
    pfVar30 = (pcVar13[-3].declarator)->name;
LAB_1042079c:
    cVar9 = '\0';
    pcVar22 = (c1_type *)0x0;
    pcVar21 = sym_new_kind1_placeholder(pfVar30);
    pcVar24 = tree_new_symbol_ref(pcVar21,cVar9);
    pcVar24 = tree_new_node('v',pcVar24,(c1_node *)CONCAT22(uVar50,CONCAT11(uVar49,uVar47)),pcVar22)
    ;
    value_base[1].node = pcVar24;
    g_compile_flags_c4 = g_compile_flags_c4 | 1;
    goto LAB_104207ca;
  case 0x32:
  case 0x34:
    cVar29 = pcVar13->words[0];
    pcVar22 = (c1_type *)0x0;
    uVar47 = (undefined1)cVar29;
    uVar49 = (undefined1)(cVar29 >> 8);
    uVar50 = (undefined2)(cVar29 >> 0x10);
    pcVar24 = tree_new_symbol_ref(*pcVar13[-3].cell,'\0');
    pcVar24 = tree_new_node('v',pcVar24,(c1_node *)CONCAT22(uVar50,CONCAT11(uVar49,uVar47)),pcVar22)
    ;
    value_base[1].node = pcVar24;
    g_compile_flags_c4 = g_compile_flags_c4 | 1;
    goto LAB_104207ca;
  case 0x35:
    value_base[1].words[0] = 0;
    diag_error(0x15f);
    g_compile_flags_c4 = g_compile_flags_c4 | 1;
    lVar44 = g_enum_value;
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
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x38:
    value_base[1].words[0] = pcVar13->words[0];
LAB_104207ca:
    lVar44 = g_enum_value;
    if (0 < g_paren_depth) {
      g_paren_depth = g_paren_depth + -1;
    }
    goto switchD_10421905_caseD_1;
  case 0x3b:
    pcVar24 = tree_append_list_item((c1_node *)0x0,pcVar38->node,2);
    value_base[1].node = pcVar24;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x3c:
    pcVar24 = tree_append_list_item(pcVar13[-1].node,pcVar38->node,2);
    value_base[1].node = pcVar24;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x3e:
    decl_pop_linkage_specification();
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x46:
    if (pcVar13->words[0] == 0) {
      g_compile_flags_c4 = g_compile_flags_c4 | 0x800000;
      g_compile_flags_c8 = g_compile_flags_c8 & 0xffffffbf;
    }
    else {
      g_ctor_mem_initializers = pcVar38->node;
      func_begin_definition_frame();
      g_compile_flags_c8 = g_compile_flags_c8 & 0xffffffbf;
      lVar44 = g_enum_value;
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
      lVar44 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0x49:
    parse_yyerrok(parser);
    g_compile_flags_c4 = g_compile_flags_c4 & 0xff7fffff;
    g_compile_flags_c8 = g_compile_flags_c8 & 0xffffffbf;
    g_compile_flags_cc = g_compile_flags_cc & 0xfffffffd;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x4a:
    pcVar40 = (c1_u32 *)&stack0x00000100;
    for (iVar53 = 9; iVar53 != 0; iVar53 = iVar53 + -1) {
      *pcVar40 = pcVar13->words[0];
      pcVar40 = pcVar40 + 1;
      pcVar13 = (c1_yy_value *)(pcVar13->words + 1);
    }
    class_check_unnamed_class_member((c1xx_decl_specifiers *)&stack0x00000100);
    value_base[1].ptr = (void *)pcVar38->words[0];
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x4b:
    pcVar40 = (c1_u32 *)&stack0x000000b8;
    for (iVar53 = 9; iVar53 != 0; iVar53 = iVar53 + -1) {
      *pcVar40 = pcVar38->words[0];
      pcVar38 = (c1_yy_value *)(pcVar38->words + 1);
      pcVar40 = pcVar40 + 1;
    }
    class_check_unnamed_class_member((c1xx_decl_specifiers *)&stack0x000000b8);
    decl_check_empty_declaration(&stack0x000000b8);
    value_base[1].words[0] = 0;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x4c:
    tmpl_finish_class_template_declaration(pcVar13 + -1,&pcVar13->spec);
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x4d:
    tmpl_finish_nonclass_template_declaration(pcVar13 + -1,pcVar13->sym);
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x4e:
    tmpl_finish_class_template_declaration(pcVar13,(c1xx_decl_specifiers *)0x0);
    lVar44 = g_enum_value;
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
    pcVar38 = pcVar13;
    pcVar28 = pcVar31->spec;
    for (iVar53 = 6; iVar53 != 0; iVar53 = iVar53 + -1) {
      *(c1_u32 *)pcVar28 = pcVar38->words[0];
      pcVar38 = (c1_yy_value *)(pcVar38->words + 1);
      pcVar28 = pcVar28 + 4;
    }
    tmpl_explicit_instantiation(pcVar31,'\x01',&pcVar13->spec);
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x50:
    g_compile_flags_cc = g_compile_flags_cc & 0xefffffff;
    pcVar38 = pcVar13 + -1;
    decl_check_conversion_return_type(pcVar13->declarator->decl,&pcVar38->spec);
    decl_finish_declarator(pcVar13->declarator->decl);
    pcVar37 = pcVar38;
    ppvVar41 = (void **)&pcVar13->node->unk0c;
    for (iVar53 = 6; iVar53 != 0; iVar53 = iVar53 + -1) {
      *ppvVar41 = (void *)pcVar37->words[0];
      pcVar37 = (c1_yy_value *)(pcVar37->words + 1);
      ppvVar41 = ppvVar41 + 1;
    }
    tmpl_explicit_instantiation(pcVar13->declarator,'\x01',&pcVar38->spec);
    g_declarator_paren_base = g_declarator_paren_base + -1;
    lVar44 = g_enum_value;
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
    pcVar38 = pcVar13;
    pcVar28 = pcVar31->spec;
    for (iVar53 = 6; iVar53 != 0; iVar53 = iVar53 + -1) {
      *(c1_u32 *)pcVar28 = pcVar38->words[0];
      pcVar38 = (c1_yy_value *)(pcVar38->words + 1);
      pcVar28 = pcVar28 + 4;
    }
    tmpl_explicit_instantiation(pcVar31,pcVar13[-2].spec.spec[0],&pcVar13->spec);
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x53:
    pcVar38 = pcVar13 + -1;
    g_compile_flags_cc = g_compile_flags_cc & 0xefffffff;
    decl_check_conversion_return_type(pcVar13->declarator->decl,&pcVar38->spec);
    decl_finish_declarator(pcVar13->declarator->decl);
    pcVar37 = pcVar38;
    ppvVar41 = (void **)&pcVar13->node->unk0c;
    for (iVar53 = 6; iVar53 != 0; iVar53 = iVar53 + -1) {
      *ppvVar41 = (void *)pcVar37->words[0];
      pcVar37 = (c1_yy_value *)(pcVar37->words + 1);
      ppvVar41 = ppvVar41 + 1;
    }
    tmpl_explicit_instantiation(pcVar13->declarator,pcVar13[-3].spec.spec[0],&pcVar38->spec);
    bVar11 = g_current_scope->current->kind;
    if ((0xfa < bVar11) && (bVar11 != 0xfd)) {
      scope_pop_to_kind(g_current_scope,'\x01');
    }
    g_declarator_paren_base = g_declarator_paren_base + -1;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x54:
    g_compile_flags_cc = g_compile_flags_cc & 0xefffffff;
    in_stack_00000060 = in_stack_00000060 & 0xf8;
    in_stack_00000028 = CONCAT31(in_stack_00000028._1_3_,pcVar13[-2].spec.spec[0]);
    puVar42 = (undefined4 *)&stack0x00000060;
    for (iVar53 = 6; iVar53 != 0; iVar53 = iVar53 + -1) {
      *puVar42 = 0;
      puVar42 = puVar42 + 1;
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
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x55:
    g_compile_flags_cc = g_compile_flags_cc & 0xefffffff;
    parse_yyerrok(parser);
    tmpl_finish_class_template_declaration((c1_yy_value *)0x0,(c1xx_decl_specifiers *)0x0);
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x56:
    tmpl_check_nested_definition();
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x57:
    decl_pop_declarator_state(pcVar13->params);
    pvVar23 = tmpl_header_end(pcVar13->header->parameter_scope);
    value_base[1].ptr = pvVar23;
    pcVar18 = tmpl_header_take_parameter_list();
    *(c1_arg_list **)((int)value_base + 0x2c) = pcVar18;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x5d:
    g_declarator_paren_base = g_declarator_paren_base + -1;
    decl_check_conversion_return_type(pcVar38->declarator->decl,&pcVar13->spec);
    decl_finish_declarator(pcVar38->declarator->decl);
    pcVar37 = pcVar13;
    ppvVar41 = (void **)&pcVar38->node->unk0c;
    for (iVar53 = 6; iVar53 != 0; iVar53 = iVar53 + -1) {
      *ppvVar41 = (void *)pcVar37->words[0];
      pcVar37 = (c1_yy_value *)(pcVar37->words + 1);
      ppvVar41 = ppvVar41 + 1;
    }
    if (g_class_depth < 0) {
      if ((g_compile_flags_c8 & 0x40) == 0) {
        pcVar21 = decl_declare_from_declarator(pcVar38->declarator,(byte *)pcVar13->words);
      }
      else {
        pcVar21 = pcVar38->declarator->sym;
      }
      bVar11 = g_current_scope->current->kind;
      if ((0xfa < bVar11) && (bVar11 != 0xfd)) {
        scope_pop_to_kind(g_current_scope,'\x01');
      }
      class_check_unnamed_class_member(&pcVar13->spec);
      value_base[1].sym = pcVar21;
      lVar44 = g_enum_value;
    }
    else {
      pcVar38->declarator->kind = 2;
      cVar9 = class_begin_member_list(pcVar38->declarator,&pcVar13->spec,(c1_symbol **)0x0);
      if (((cVar9 == '\0') && (bVar11 = g_current_scope->current->kind, 0xfa < bVar11)) &&
         (bVar11 != 0xfd)) {
        scope_pop_to_kind(g_current_scope,'\x01');
      }
      value_base[1].words[0] = (c1_u32)pcVar38->declarator->sym;
      lVar44 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0x5e:
    g_compile_flags_c4 = g_compile_flags_c4 | 0x1000000;
    g_compile_flags_c8 = g_compile_flags_c8 & 0xfffffffd;
    g_declarator_paren_base = g_declarator_paren_base + -1;
    if ((g_paren_level_flags[g_paren_depth] & 1) == 0) {
      pcVar52 = decl_specifiers_default((void *)0x0);
      lVar44 = g_enum_value;
    }
    else {
      pcVar52 = g_paren_level_declspecs + g_paren_depth;
    }
    g_enum_value = lVar44;
    decl_check_conversion_return_type(pcVar38->declarator->decl,pcVar52);
    decl_finish_declarator(pcVar38->declarator->decl);
    if ((g_paren_level_flags[g_paren_depth] & 1) == 0) {
      pcVar52 = decl_specifiers_default((void *)0x0);
    }
    else {
      pcVar52 = g_paren_level_declspecs + g_paren_depth;
    }
    ppvVar41 = (void **)&pcVar38->node->unk0c;
    for (iVar53 = 6; iVar53 != 0; iVar53 = iVar53 + -1) {
      *ppvVar41 = *(void **)pcVar52->spec;
      pcVar52 = (c1xx_decl_specifiers *)(pcVar52->spec + 4);
      ppvVar41 = ppvVar41 + 1;
    }
    if (g_class_depth < 0) {
      if ((g_compile_flags_c8 & 0x40) == 0) {
        if ((g_paren_level_flags[g_paren_depth] & 1) == 0) {
          pcVar52 = decl_specifiers_default((void *)0x0);
          pcVar31 = (c1_declarator *)decl_declare_from_declarator(pcVar38->declarator,pcVar52->spec)
          ;
        }
        else {
          pcVar31 = (c1_declarator *)
                    decl_declare_from_declarator
                              (pcVar38->declarator,g_paren_level_declspecs[g_paren_depth].spec);
        }
      }
      else {
        pcVar31 = (c1_declarator *)pcVar38->declarator->sym;
      }
      bVar11 = g_current_scope->current->kind;
      if (0xfa < bVar11) {
        iVar53 = yyparse_cpp_template_member_declaration_tail
                           (g_current_scope,bVar11,(c1_symbol *)pcVar31,value_base,parser,state_sp,
                            saved_lookahead,saved_rule);
        return iVar53;
      }
      goto LAB_10421939;
    }
    pcVar38->declarator->kind = 2;
    if ((g_paren_level_flags[g_paren_depth] & 1) == 0) {
      pcVar52 = decl_specifiers_default((void *)0x0);
    }
    else {
      pcVar52 = g_paren_level_declspecs + g_paren_depth;
    }
    cVar9 = class_begin_member_list(pcVar38->declarator,pcVar52,(c1_symbol **)0x0);
    if (((cVar9 == '\0') && (bVar11 = g_current_scope->current->kind, 0xfa < bVar11)) &&
       (bVar11 != 0xfd)) {
      scope_pop_to_kind(g_current_scope,'\x01');
    }
    value_base[1].words[0] = (c1_u32)pcVar38->declarator->sym;
    lVar44 = g_enum_value;
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
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 100:
    if ((g_token_source->stream->flags & 1) != 0) {
      pcVar25 = include_line_map_find((c1_line_map_state *)&g_lex_position,g_token_position);
      (*g_idb->vtbl->idb_scope_kind4_end)
                (g_idb,CONCAT22(uVar39,(short)pcVar25->line - (short)pcVar25->position) +
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
      cVar6 = (c1_arg_value)pcVar38->node->right;
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
    uVar34 = g_compile_flags_cc & 0xffffffef;
    lVar44 = g_enum_value;
    if (((g_compile_flags_c8 & 0x32000000) == 0) &&
       (((((g_compile_flags_c8 & 0x40000000) == 0 || ((g_compile_flags_cc & 8) != 0)) ||
         ((g_compile_flags_c4 & 0x200) != 0)) &&
        ((uVar8 = g_compile_flags_c8 & 0x4000000, g_compile_flags_c8 = uVar55,
         g_compile_flags_cc = uVar34, uVar8 == 0 || ((g_compile_flags_c4 & 0x8000) != 0))))))
    goto LAB_1046607d;
LAB_1046625d:
    g_compile_flags_cc = uVar34;
    g_compile_flags_c8 = uVar55;
    g_context_arena_index = 0;
    g_expr_arena_index = 0;
    goto switchD_10421905_caseD_5c;
  case 0x65:
    if ((g_token_source->stream->flags & 1) != 0) {
      pcVar25 = include_line_map_find((c1_line_map_state *)&g_lex_position,g_token_position);
      (*g_idb->vtbl->idb_scope_kind4_end)
                (g_idb,CONCAT22(uVar39,(short)pcVar25->line - (short)pcVar25->position) +
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
    pcVar24->left = (void *)pcVar38->words[0];
    in_stack_00000054 = (c1_type *)0x0;
    in_stack_0000005c = 0;
    in_stack_00000050 = 0x80e;
    in_stack_00000052 = 0;
    in_stack_00000058.cls = (c1_symbol *)0x0;
    pcVar22 = type_intern((c1_type *)&stack0x00000050);
    pcVar24->type = pcVar22;
    pcVar24 = tree_append_list_item((c1_node *)0x0,pcVar24,2);
    pcVar17 = arena_alloc(g_arenas,0x14);
    if (pcVar17 == (c1_arg_item *)0x0) {
      pcVar17 = (c1_arg_item *)0x0;
    }
    else {
      tmpl_list_item_construct(pcVar17,1,0);
      pcVar17->vtbl = &PTR_pch_fixup_tree_list_object_104bcbcc;
      (pcVar17->value).expr = pcVar24;
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
    uVar34 = g_compile_flags_cc & 0xffffffef;
    lVar44 = g_enum_value;
    if ((((g_compile_flags_c8 & 0x32000000) != 0) ||
        ((((g_compile_flags_c8 & 0x40000000) != 0 && ((g_compile_flags_cc & 8) == 0)) &&
         ((g_compile_flags_c4 & 0x200) == 0)))) ||
       ((uVar8 = g_compile_flags_c8 & 0x4000000, g_compile_flags_c8 = uVar55,
        g_compile_flags_cc = uVar34, uVar8 != 0 && ((g_compile_flags_c4 & 0x8000) == 0))))
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
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x69:
    stream = token_reader_current_stream((c1_token_reader *)&g_token_position);
    cVar9 = token_stream_is_source_text(stream);
    lVar44 = g_enum_value;
    if (cVar9 != '\0') {
      pcVar36 = g_idb->vtbl;
      goto LAB_10422231;
    }
    goto switchD_10421905_caseD_1;
  case 0x6b:
  case 0x6d:
    pcVar28 = arena_alloc_n_aligned(0xc,0);
    if (pcVar28 == (c1_u8 *)0x0) goto LAB_10465f34;
    pvVar23 = tmpl_argument_list_init(pcVar28,pcVar38->ptr);
    value_base[1].ptr = pvVar23;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x6c:
    list_append_tail(pcVar13[-1].args,pcVar38->arg);
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x6e:
    pcVar17 = tmpl_argument_from_expression(pcVar38->node);
    value_base[1].arg = pcVar17;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x6f:
    pcVar40 = acStack_24;
    for (iVar53 = 9; iVar53 != 0; iVar53 = iVar53 + -1) {
      *pcVar40 = pcVar13->words[0];
      pcVar40 = pcVar40 + 1;
      pcVar13 = (c1_yy_value *)(pcVar13->words + 1);
    }
    pcVar17 = decl_finish_declarator_record(pcVar38->declarator);
    value_base[1].arg = pcVar17;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x71:
    g_compile_flags_c8 = g_compile_flags_c8 & 0xffffffdf;
    goto switchD_10421905_caseD_1;
  case 0x72:
  case 0x15d:
  case 0x15e:
    goto switchD_10421905_caseD_6f;
  case 0x73:
    pcVar24 = pcVar38->node;
    pcVar13 = pcVar13 + -1;
    pcVar40 = (c1_u32 *)&stack0x00000124;
    for (iVar53 = 9; iVar53 != 0; iVar53 = iVar53 + -1) {
      *pcVar40 = pcVar13->words[0];
      pcVar13 = (c1_yy_value *)(pcVar13->words + 1);
      pcVar40 = pcVar40 + 1;
    }
    iVar53 = decl_parse_linkage_specification((c1xx_decl_specifiers *)&stack0x00000124,pcVar24);
    decl_push_linkage_specification(iVar53);
    if (g_yy_lookahead == (byte *)0x0) {
      iVar53 = parse_error_recovery_count();
      if (iVar53 == 0) {
        arena_reset(5);
      }
    }
    g_string_literal_cur = &g_string_literal_buffer;
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfc;
    lVar44 = g_enum_value;
    if (g_yy_lookahead != (byte *)0x0) {
      cVar10 = lex_token_code((c1xx_token *)g_yy_lookahead);
      lVar44 = g_enum_value;
      if (cVar10 != 'u') {
        g_compile_flags_c8 = g_compile_flags_c8 | 0x20;
      }
    }
    goto switchD_10421905_caseD_1;
  case 0x76:
    ns_end_definition(pcVar13[-1].words[0]);
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x77:
    pbVar15 = ns_define_namespace((void *)0x0);
    value_base[1].str.text = pbVar15;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x78:
    pbVar15 = ns_define_namespace(pcVar13->ptr);
    value_base[1].str.text = pbVar15;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x79:
    scope_pop_to_kind_if_needed(g_current_scope,'\0');
    pvVar23 = qualname_resolved_symbol(pcVar13->declarator);
    cVar10 = '\0';
    uVar47 = 0;
    uVar49 = 0;
    uVar50 = 0;
    if (pvVar23 == (void *)0x0) {
      pcVar21 = value_word0(pcVar13->cell);
      ns_using_directive((c1_symbol *)0x0,(fe_name *)pcVar21,
                         CONCAT22(uVar50,CONCAT11(uVar49,uVar47)),cVar10);
      lVar44 = g_enum_value;
    }
    else {
      uVar46 = 0;
      uVar48 = 0;
      uVar39 = 0;
      pcVar21 = qualname_resolved_symbol(pcVar13->declarator);
      ns_using_directive(pcVar21,(fe_name *)CONCAT22(uVar39,CONCAT11(uVar48,uVar46)),
                         CONCAT22(uVar50,CONCAT11(uVar49,uVar47)),cVar10);
      lVar44 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0x7a:
    scope_pop_to_kind_if_needed(g_current_scope,'\0');
    pvVar23 = qualname_resolved_symbol(pcVar13->declarator);
    pcVar31 = (c1_declarator *)pcVar13->cell;
    if (pvVar23 == (void *)0x0) goto LAB_104668f9;
    pcVar21 = qualname_resolved_symbol(pcVar31);
    ns_using_declaration(pcVar21);
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x7b:
    ns_using_declaration((pcVar13->spec).type_sym);
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x7c:
    scope_pop_to_kind_if_needed(g_current_scope,'\0');
    ns_define_alias(pcVar13->declarator,pcVar13[-2].name);
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x7d:
    diag_error(0x122);
    parse_paren_depth_pop();
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x7e:
    if (g_yy_lookahead != (byte *)0x0) {
      cVar10 = lex_token_code((c1xx_token *)g_yy_lookahead);
      if (cVar10 == 'v') {
        iVar33 = 9;
        iVar53 = g_paren_depth;
        pcVar13 = pcVar38;
        pcVar40 = (c1_u32 *)(&g_paren_level_declspecs_prev_base + g_paren_depth * 0x24);
        lVar44 = g_enum_value;
        goto LAB_10420c2b;
      }
    }
    iVar53 = g_paren_depth;
    pcVar52 = g_paren_level_declspecs + g_paren_depth;
    for (iVar33 = 9; iVar33 != 0; iVar33 = iVar33 + -1) {
      *(c1_u32 *)pcVar52->spec = pcVar38->words[0];
      pcVar38 = (c1_yy_value *)(pcVar38->words + 1);
      pcVar52 = (c1xx_decl_specifiers *)(pcVar52->spec + 4);
    }
    g_paren_level_flags[iVar53] = g_paren_level_flags[iVar53] | 1;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x7f:
    if ((*(code **)((int)pcVar13 + 0x48) != (code *)0x0) && (*(int *)((int)pcVar13 + 0x44) != 0)) {
      (**(code **)((int)pcVar13 + 0x48))();
      lVar44 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0x80:
    bVar43 = g_yy_lookahead != (byte *)0x0;
    puVar27 = &g_yylval;
    for (iVar53 = 9; iVar53 != 0; iVar53 = iVar53 + -1) {
      *puVar27 = pcVar38->words[0];
      pcVar38 = (c1_yy_value *)(pcVar38->words + 1);
      puVar27 = puVar27 + 1;
    }
    if (bVar43) {
      cVar10 = lex_token_code(pcVar26);
      pcVar26 = (c1xx_token *)g_yy_lookahead;
      lVar44 = g_enum_value;
      if (cVar10 == '\x7f') goto switchD_10421905_caseD_1;
    }
    g_yy_lookahead = (byte *)lex_unget_token(pcVar26);
    g_compile_flags_c4 = g_compile_flags_c4 | 0x80000000;
    pcVar21 = value_word0((c1_symbol **)&g_token_arena_index);
    pcVar28 = arena_or_pool_alloc(0x30,(int)pcVar21);
    if (pcVar28 == (c1_u8 *)0x0) {
      token = (char *)0x0;
    }
    else {
      token = token_init(pcVar28,'\"',&g_yylval);
    }
    pcVar26 = (c1xx_token *)lex_lookahead_decl_specifiers(token);
    g_compile_flags_c4 = g_compile_flags_c4 & 0x7fffffff;
    pcVar13 = token_value_address(pcVar26);
    pcVar38 = value_base + 1;
    lVar44 = g_enum_value;
    for (iVar53 = 9; iVar53 != 0; iVar53 = iVar53 + -1) {
      g_enum_value = lVar44;
      pcVar38->words[0] = pcVar13->words[0];
      pcVar13 = (c1_yy_value *)(pcVar13->words + 1);
      pcVar38 = (c1_yy_value *)(pcVar38->words + 1);
      lVar44 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0x85:
    iVar53 = browse_end_global_block();
    *(int *)((int)value_base + 0x40) = iVar53;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x86:
    pcVar22 = class_end_definition();
    *(c1_type **)((int)value_base + 0x40) = pcVar22;
    class_begin_deferred_member_bodies();
    lVar44 = g_enum_value;
    if (g_yy_lookahead == (byte *)0x0) {
      g_yy_lookahead = token_next((c1_token_reader *)&g_token_position);
      lVar44 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0x87:
    class_reset_member_function_class();
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x88:
    if ((code *)pcVar13->words[8] != (code *)0x0) {
      (*(code *)pcVar13->words[8])();
    }
    class_begin_definition((pcVar13->spec).type_sym,(pcVar13->spec).type);
    class_end_member_list();
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x8a:
    if (*(code **)((int)pcVar13 + 0x48) != (code *)0x0) {
      (**(code **)((int)pcVar13 + 0x48))();
    }
    class_begin_definition(*(c1_symbol **)((int)pcVar13 + 0x44),*(c1_type **)((int)pcVar13 + 0x40));
    g_compile_flags_c4 = g_compile_flags_c4 | 3;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
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
    lVar44 = g_enum_value;
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
    pcVar21 = (c1_symbol *)sym_name((c1_symbol *)(pcVar13->spec).type);
    lVar44 = g_enum_value;
    if (g_pragma_mintypeinfo != '\0') {
      sym_detail_set_flag3f_bit3(pcVar21);
      lVar44 = g_enum_value;
    }
    if ((g_browse_file != (char *)0x0) && ((g_block_depth == '\0' || (g_opt_FR_browse != 0)))) {
      g_enum_value = lVar44;
      cVar10 = sym_flags3_bit0(pcVar21);
      lVar44 = g_enum_value;
      if (cVar10 == '\0') {
        (*g_il_emitter->vtbl->begin_block)();
        pcVar5 = g_il_emitter->vtbl;
        iVar53 = sym_name(pcVar21);
        iVar53 = (*pcVar5->mark_definition)(0,iVar53);
        if (iVar53 == 0) {
          (*g_il_emitter->vtbl->define_symbol)(g_il_emitter,pcVar21);
        }
        (*g_il_emitter->vtbl->set_owner)((int)pcVar21);
        lVar44 = g_enum_value;
      }
    }
    goto switchD_10421905_caseD_1;
  case 0x96:
    if (g_yy_lookahead == (byte *)0x0) {
      g_yy_lookahead = token_next((c1_token_reader *)&g_token_position);
    }
    cVar10 = lex_token_code((c1xx_token *)g_yy_lookahead);
    lVar44 = g_enum_value;
    if (cVar10 != '7') {
      cVar10 = lex_token_code((c1xx_token *)g_yy_lookahead);
      lVar44 = g_enum_value;
      if (cVar10 != 'u') {
        parse_report_inserted_token(g_yy_lookahead,0x37);
        lex_unget_token((c1xx_token *)g_yy_lookahead);
        g_yy_lookahead = &token_static_for_code(0x37)->code;
        lVar44 = g_enum_value;
      }
    }
    goto switchD_10421905_caseD_1;
  case 0x97:
  case 0x9e:
    class_check_base_defined
              ((pcVar13->spec).spec[0] & 3,(pcVar13->spec).spec[0] >> 2 & 0xffffff01,pcVar38->name,0
              );
    g_compile_flags_c4 = g_compile_flags_c4 | 1;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x98:
    bVar11 = (pcVar13->spec).spec[0];
    pcVar21 = (c1_symbol *)sym_name(pcVar38->sym);
    class_check_base_class(bVar11 & 3,bVar11 >> 2 & 1,pcVar21);
    goto LAB_10420ed7;
  case 0x99:
    pcVar21 = value_word0(pcVar38->cell);
    access_check_member(pcVar21);
    bVar11 = (pcVar13->spec).spec[0];
    iVar53 = 0;
    pcVar21 = value_word0(pcVar38->cell);
    uVar46 = SUB41(pcVar21,0);
    uVar48 = (undefined1)((uint)pcVar21 >> 8);
    uVar39 = (undefined2)((uint)pcVar21 >> 0x10);
    uVar55 = CONCAT31((int3)((uint)extraout_ECX >> 8),bVar11 >> 2) & 0xffffff01;
    uVar47 = (undefined1)uVar55;
    uVar49 = (undefined1)(uVar55 >> 8);
    uVar50 = (undefined2)(uVar55 >> 0x10);
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
    lVar44 = g_enum_value;
    if (cVar10 != '7') {
      cVar10 = lex_token_code((c1xx_token *)g_yy_lookahead);
      lVar44 = g_enum_value;
      if (cVar10 != 'u') {
        cVar10 = lex_token_code((c1xx_token *)g_yy_lookahead);
        lVar44 = g_enum_value;
        if (cVar10 != '6') {
          parse_report_inserted_token(g_yy_lookahead,0x37);
          lex_unget_token((c1xx_token *)g_yy_lookahead);
          g_yy_lookahead = &token_static_for_code(0x37)->code;
          lVar44 = g_enum_value;
        }
      }
    }
    goto switchD_10421905_caseD_1;
  case 0x9f:
    pcVar21 = value_word0(pcVar38->cell);
    access_check_member(pcVar21);
    bVar11 = (pcVar13->spec).spec[0];
    iVar53 = 1;
    pcVar21 = value_word0(pcVar38->cell);
    uVar46 = SUB41(pcVar21,0);
    uVar48 = (undefined1)((uint)pcVar21 >> 8);
    uVar39 = (undefined2)((uint)pcVar21 >> 0x10);
    uVar55 = CONCAT31((int3)((uint)pcVar21 >> 8),bVar11 >> 2) & 0xffffff01;
    uVar47 = (undefined1)uVar55;
    uVar49 = (undefined1)(uVar55 >> 8);
    uVar50 = (undefined2)(uVar55 >> 0x10);
LAB_10466526:
    class_check_base_of_symbol
              (bVar11 & 3,CONCAT22(uVar50,CONCAT11(uVar49,uVar47)),
               (c1_symbol *)CONCAT22(uVar39,CONCAT11(uVar48,uVar46)),iVar53);
LAB_10420ed7:
    g_compile_flags_c4 = g_compile_flags_c4 | 1;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xa0:
    diag_error(0x348);
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xa2:
    value_base[1].spec.spec[0] = value_base[1].spec.spec[0] & 0xe0;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xa3:
    bVar11 = value_base[1].spec.spec[0];
    if ((bVar11 & 3) == 0) {
      value_base[1].spec.spec[0] =
           ((byte)g_tree_op_to_il_op[(pcVar38->spec).spec[0]] ^ bVar11) & 3 ^ bVar11;
      lVar44 = g_enum_value;
    }
    else if ((bVar11 & 8) == 0) {
      diag_error(0x1f6);
      value_base[1].spec.spec[0] = value_base[1].spec.spec[0] | 8;
      lVar44 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0xa4:
    bVar11 = value_base[1].spec.spec[0];
    if ((bVar11 & 4) == 0) {
      value_base[1].spec.spec[0] = bVar11 | 4;
      lVar44 = g_enum_value;
    }
    else if ((bVar11 & 0x10) == 0) {
      diag_error(0x1fb);
      value_base[1].spec.spec[0] = value_base[1].spec.spec[0] | 0x10;
      lVar44 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0xa7:
  case 0xa8:
    diag_error(0x2f8);
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xa9:
    lVar44 = enum_warn_value_wrapped(lVar44,pcVar38->ptr);
    acStack_24[1] = 0x10420f95;
    g_enum_value = lVar44;
    enum_declare(pcVar38->name,g_current_enum_type,(c1_u32)lVar44,(int)((ulonglong)lVar44 >> 0x20));
    g_compile_flags_c4 = g_compile_flags_c4 | 1;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xaa:
    if ((g_compile_flags_cc & 0x100000) != 0) {
      pcVar26 = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
      pcVar26 = parse_skip_tokens_to_one_of(pcVar26);
      token_source_unget((c1_token_reader *)&g_token_position,pcVar26);
      g_yylval = (uint)g_type_int;
      _g_yylval_word2 = 1;
      _g_yylval_word3 = 0;
      pcVar21 = value_word0((c1_symbol **)&g_token_arena_index);
      pcVar28 = arena_or_pool_alloc(0x30,(int)pcVar21);
      if (pcVar28 == (c1_u8 *)0x0) goto LAB_10466f79;
      g_yy_lookahead = token_init(pcVar28,'e',&g_yylval);
      lVar44 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0xab:
    enum_declare(pcVar13[-2].name,g_current_enum_type,pcVar38->words[0],
                 *(int *)((int)pcVar13 + 0x2c));
    if (((g_prototype_scope_depth == 0) && ((g_compile_flags_c4 & 0x8000000) == 0)) &&
       ((g_paren_depth == 0 &&
        (((g_compile_flags_c8 & 0x40000000) == 0 && ((g_compile_flags_cc & 8) == 0)))))) {
      arena_reset(5);
    }
    g_compile_flags_c4 = g_compile_flags_c4 | 1;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xac:
  case 0xad:
    if ((((g_prototype_scope_depth == 0) && ((g_compile_flags_c4 & 0x8000000) == 0)) &&
        (g_paren_depth == 0)) &&
       (((g_compile_flags_c8 & 0x40000000) == 0 && ((g_compile_flags_cc & 8) == 0)))) {
      arena_reset(5);
      lVar44 = g_enum_value;
    }
    g_string_literal_cur = &g_string_literal_buffer;
  case 0x16c:
    g_compile_flags_c4 = g_compile_flags_c4 & 0xfffffffe;
    g_enum_value = lVar44;
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfc;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xaf:
    pcVar40 = (c1_u32 *)&stack0x000000dc;
    for (iVar53 = 9; iVar53 != 0; iVar53 = iVar53 + -1) {
      *pcVar40 = pcVar13->words[0];
      pcVar40 = pcVar40 + 1;
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
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xb1:
    pcVar13 = pcVar13 + -1;
    pcVar40 = (c1_u32 *)&stack0x00000148;
    for (iVar53 = 9; iVar53 != 0; iVar53 = iVar53 + -1) {
      *pcVar40 = pcVar13->words[0];
      pcVar13 = (c1_yy_value *)(pcVar13->words + 1);
      pcVar40 = pcVar40 + 1;
    }
    class_check_unnamed_class_member((c1xx_decl_specifiers *)&stack0x00000148);
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xb3:
    if ((((c1_symbol_tail *)pcVar13->declarator->unk2c)->fn).op_token == '\x01') {
      cVar9 = value_byte1_bit4((c1_symbol *)pcVar13->declarator);
      lVar44 = g_enum_value;
      if (cVar9 == '\0') {
        cVar9 = value_byte1_bit5(pcVar13->sym);
        lVar44 = g_enum_value;
        if ((cVar9 == '\0') &&
           ((((c1_symbol_tail *)pcVar13->declarator->unk2c)->fn).special_kind == '\0')) {
          sym_name((c1_symbol *)pcVar13->declarator);
          diag_warning(1);
          lVar44 = g_enum_value;
        }
      }
    }
    goto switchD_10421905_caseD_1;
  case 0xb4:
    class_set_current_access((c1_u8)g_tree_op_to_il_op[(pcVar13->spec).spec[0]]);
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xb5:
    lex_token_code((c1xx_token *)g_yy_lookahead);
    diag_error(0x140);
    class_set_current_access((c1_u8)g_tree_op_to_il_op[(pcVar38->spec).spec[0]]);
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
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
        iVar53 = token_reader_top_kind((c1_token_reader *)&g_token_position);
joined_r0x1046681a:
        if (iVar53 == 0) {
          diag_fatal_simple(0xc9);
        }
      }
    }
LAB_1046681c:
    parse_yyerrok(parser);
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xba:
    diag_error(0x14e);
    lex_skip_to_closing_brace('\0');
    if ((g_compile_flags_c8 & 0x40000000) != 0) {
      pcVar26 = (c1xx_token *)lex_peek_token((uint *)&g_token_position);
      cVar10 = lex_token_code(pcVar26);
      if (cVar10 != 0xf7) goto LAB_1046681c;
      iVar53 = token_reader_top_kind((c1_token_reader *)&g_token_position);
      goto joined_r0x1046681a;
    }
    goto LAB_1046681c;
  case 0xbe:
  case 0xcd:
    diag_warning(1,0xe4);
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xbf:
    g_yy_lookahead = &parse_skip_tokens_to_one_of((c1xx_token *)g_yy_lookahead)->code;
    cVar10 = lex_token_code((c1xx_token *)g_yy_lookahead);
    if (cVar10 != '\x7f') {
      lex_unget_token((c1xx_token *)g_yy_lookahead);
      g_yy_lookahead = &token_static_for_code(0x7f)->code;
    }
    parse_yyerrok(parser);
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xc0:
    g_yy_lookahead = &parse_skip_tokens_to_one_of((c1xx_token *)g_yy_lookahead)->code;
    cVar10 = lex_token_code((c1xx_token *)g_yy_lookahead);
    lVar44 = g_enum_value;
    if (cVar10 != '\x7f') {
      lex_unget_token((c1xx_token *)g_yy_lookahead);
      g_yy_lookahead = &token_static_for_code(0x7f)->code;
      lVar44 = g_enum_value;
    }
switchD_10421905_caseD_18:
    g_enum_value = lVar44;
    parse_yyerrok(parser);
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xc1:
    pcVar21 = decl_declarator_symbol(pcVar38->declarator);
    if (pcVar21 == (c1_symbol *)0x0) {
      declarator_set_kind(pcVar38->declarator,2);
      g_declarator_paren_base = g_declarator_paren_base + -1;
      pcVar52 = decl_specifiers_current();
      pcVar32 = decl_declarator_record(pcVar38->declarator);
      decl_check_conversion_return_type(pcVar32,pcVar52);
      pcVar32 = decl_declarator_record(pcVar38->declarator);
      decl_finish_declarator(pcVar32);
      pcVar52 = decl_specifiers_current();
      decl_declarator_set_specifiers(pcVar38->declarator,pcVar52);
      ppcVar51 = (c1_symbol **)0x0;
      pcVar52 = decl_specifiers_current();
      cVar9 = class_begin_member_list(pcVar38->declarator,pcVar52,ppcVar51);
      if (cVar9 == '\0') {
        scope_pop_to_kind_if_needed(g_current_scope,'\x01');
      }
      pcVar21 = decl_declarator_symbol(pcVar38->declarator);
      value_base[1].sym = pcVar21;
      lVar44 = g_enum_value;
    }
    else {
      pcVar21 = decl_declarator_symbol(pcVar38->declarator);
      value_base[1].sym = pcVar21;
      lVar44 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0xc2:
    pcVar24 = expr_resolve_address_of_overload(pcVar38->node);
    bVar11 = expr_is_zero_constant(pcVar24);
    if (bVar11 == 0) {
      diag_error(0x102);
    }
    declarator_set_flags56_bit1(pcVar13->declarator,'\x01');
    declarator_set_kind(pcVar13->declarator,2);
    g_declarator_paren_base = g_declarator_paren_base + -1;
    pcVar52 = decl_specifiers_current();
    pcVar32 = decl_declarator_record(pcVar13->declarator);
    decl_check_conversion_return_type(pcVar32,pcVar52);
    pcVar32 = decl_declarator_record(pcVar13->declarator);
    decl_finish_declarator(pcVar32);
    pcVar52 = decl_specifiers_current();
    decl_declarator_set_specifiers(pcVar13->declarator,pcVar52);
    ppcVar51 = (c1_symbol **)0x0;
    pcVar52 = decl_specifiers_current();
    cVar9 = class_begin_member_list(pcVar13->declarator,pcVar52,ppcVar51);
    if (cVar9 == '\0') {
      scope_pop_to_kind_if_needed(g_current_scope,'\x01');
    }
    pcVar21 = decl_declarator_symbol(pcVar13->declarator);
    value_base[1].sym = pcVar21;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xc4:
    declarator_set_kind(pcVar13[-1].declarator,1);
    iVar53 = *(int *)((int)pcVar13 + 0x2c);
    cVar29 = pcVar38->words[0];
    uVar47 = (undefined1)cVar29;
    uVar49 = (undefined1)(cVar29 >> 8);
    uVar50 = (undefined2)(cVar29 >> 0x10);
    pcVar21 = decl_declarator_symbol(pcVar13[-1].declarator);
    cVar10 = type_check_bitfield_width(pcVar21,CONCAT22(uVar50,CONCAT11(uVar49,uVar47)),iVar53);
    decl_set_bitfield_width(pcVar13[-1].declarator,cVar10);
    g_declarator_paren_base = g_declarator_paren_base + -1;
    pcVar52 = decl_specifiers_current();
    pcVar32 = decl_declarator_record(pcVar13[-1].declarator);
    decl_check_conversion_return_type(pcVar32,pcVar52);
    pcVar32 = decl_declarator_record(pcVar13[-1].declarator);
    decl_finish_declarator(pcVar32);
    pcVar52 = decl_specifiers_current();
    decl_declarator_set_specifiers(pcVar13[-1].declarator,pcVar52);
    ppcVar51 = (c1_symbol **)0x0;
    pcVar52 = decl_specifiers_current();
    cVar9 = class_begin_member_list(pcVar13[-1].declarator,pcVar52,ppcVar51);
    if (cVar9 == '\0') {
      scope_pop_to_kind_if_needed(g_current_scope,'\x01');
    }
    pcVar21 = decl_declarator_symbol(pcVar13[-1].declarator);
    value_base[1].sym = pcVar21;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xc5:
    pcVar31 = decl_declarator_alloc();
    if (pcVar31 == (c1_declarator *)0x0) {
      pcVar31 = (c1_declarator *)0x0;
    }
    else {
      pcVar31 = decl_declarator_init(pcVar31,g_name_alignment_member,1,(c1_overload_set *)0x0);
    }
    iVar53 = *(int *)((int)pcVar13 + 0x2c);
    cVar29 = pcVar38->words[0];
    uVar47 = (undefined1)cVar29;
    uVar49 = (undefined1)(cVar29 >> 8);
    uVar50 = (undefined2)(cVar29 >> 0x10);
    pcVar21 = decl_declarator_symbol(pcVar31);
    cVar10 = type_check_bitfield_width(pcVar21,CONCAT22(uVar50,CONCAT11(uVar49,uVar47)),iVar53);
    decl_set_bitfield_width(pcVar31,cVar10);
    declarator_set_flags54_bit5(pcVar31,'\x01');
    pcVar52 = decl_specifiers_current();
    pcVar32 = decl_declarator_record(pcVar31);
    decl_check_conversion_return_type(pcVar32,pcVar52);
    pcVar32 = decl_declarator_record(pcVar31);
    decl_finish_declarator(pcVar32);
    pcVar52 = decl_specifiers_current();
    decl_declarator_set_specifiers(pcVar31,pcVar52);
    ppcVar51 = (c1_symbol **)0x0;
    pcVar52 = decl_specifiers_current();
    class_begin_member_list(pcVar31,pcVar52,ppcVar51);
    pcVar21 = decl_declarator_symbol(pcVar31);
    value_base[1].sym = pcVar21;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xc6:
    scope_pop_to_kind_if_needed(g_current_scope,'\x01');
    pcVar21 = decl_declarator_symbol(pcVar38->declarator);
    value_base[1].sym = pcVar21;
    pvVar23 = qualname_resolved_symbol(pcVar38->declarator);
    pcVar31 = (c1_declarator *)pcVar38->cell;
    if (pvVar23 == (void *)0x0) {
LAB_104668f9:
      value_word0((c1_symbol **)pcVar31);
      diag_error(0x369);
      lVar44 = g_enum_value;
    }
    else {
      pbVar15 = qualname_resolved_symbol(pcVar31);
      ns_member_using_declaration(pbVar15);
      lVar44 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 199:
    ns_member_using_declaration(*(byte **)((int)pcVar13 + 0x44));
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xca:
    cVar10 = lex_token_code((c1xx_token *)g_yy_lookahead);
    lVar44 = g_enum_value;
    if (cVar10 == '6') {
      pcVar21 = value_word0(pcVar38->cell);
      iVar53 = class_is_innermost_being_defined((int)pcVar21);
      lVar44 = g_enum_value;
      if ((char)iVar53 != '\0') {
        declarator_set_kind(pcVar38->declarator,2);
        g_declarator_paren_base = g_declarator_paren_base + -1;
        pcVar52 = decl_specifiers_current();
        pcVar32 = decl_declarator_record(pcVar38->declarator);
        decl_check_conversion_return_type(pcVar32,pcVar52);
        pcVar32 = decl_declarator_record(pcVar38->declarator);
        decl_finish_declarator(pcVar32);
        pcVar52 = decl_specifiers_current();
        decl_declarator_set_specifiers(pcVar38->declarator,pcVar52);
        g_yy_lookahead = (byte *)lex_unget_token((c1xx_token *)g_yy_lookahead);
        ppcVar51 = (c1_symbol **)0x0;
        pcVar52 = decl_specifiers_current();
        cVar9 = class_begin_member_list(pcVar38->declarator,pcVar52,ppcVar51);
        lVar44 = g_enum_value;
        if (cVar9 == '\0') {
          scope_pop_to_kind_if_needed(g_current_scope,'\x01');
          lVar44 = g_enum_value;
        }
      }
    }
    goto switchD_10421905_caseD_1;
  case 0xce:
    g_declarator_paren_base = g_declarator_paren_base + -1;
    pcVar52 = decl_specifiers_current();
    pcVar32 = decl_declarator_record(pcVar38->declarator);
    decl_check_conversion_return_type(pcVar32,pcVar52);
    pcVar32 = decl_declarator_record(pcVar38->declarator);
    decl_finish_declarator(pcVar32);
    pcVar52 = decl_specifiers_current();
    decl_declarator_set_specifiers(pcVar38->declarator,pcVar52);
    if (((g_compile_flags_c8 & 0x40) == 0) && ((g_compile_flags_cc & 0x200000) == 0)) {
      pcVar52 = decl_specifiers_current();
      decl_declare_from_declarator(pcVar38->declarator,pcVar52->spec);
    }
    scope_pop_to_kind_if_needed(g_current_scope,'\x01');
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xcf:
    if (g_opt_Zg == '\0') {
      pcVar21 = decl_declarator_symbol(pcVar13->declarator);
      cVar9 = decl_check_function_style_initializer(pcVar21);
      if (cVar9 == '\0') {
        g_declarator_paren_base = g_declarator_paren_base + -1;
        decl_set_has_initializer(pcVar13->declarator,'\x01');
        pcVar52 = decl_specifiers_current();
        pcVar32 = decl_declarator_record(pcVar13->declarator);
        decl_check_conversion_return_type(pcVar32,pcVar52);
        pcVar32 = decl_declarator_record(pcVar13->declarator);
        decl_finish_declarator(pcVar32);
        pcVar52 = decl_specifiers_current();
        decl_declarator_set_specifiers(pcVar13->declarator,pcVar52);
        pcVar52 = decl_specifiers_current();
        pcVar21 = decl_declare_and_check(pcVar13->declarator,pcVar52->spec);
        decl_record_set_symbol(pcVar13->ptr,pcVar21);
        pcVar21 = decl_declarator_symbol(pcVar13->declarator);
        pcVar21 = (c1_symbol *)decl_begin_initialized_definition(pcVar21);
        decl_record_set_symbol(pcVar13->ptr,pcVar21);
        pcVar21 = decl_declarator_symbol(pcVar13->declarator);
        if (pcVar21 != (c1_symbol *)0x0) {
          pcVar21 = decl_declarator_symbol(pcVar13->declarator);
          init_set_target_symbol(pcVar21);
          pcVar24 = pcVar38->node;
          pcVar21 = decl_declarator_symbol(pcVar13->declarator);
          decl_finish_initialization(pcVar21,pcVar24);
          scope_pop_to_kind_if_needed(g_current_scope,'\x01');
          pcVar31 = pcVar13->declarator;
          goto LAB_10421651;
        }
      }
    }
    goto LAB_10422a54;
  case 0xd1:
    if ((g_opt_Zg != '\0') || (pcVar13[-1].words[0] == 0)) goto LAB_10422a54;
    pcVar24 = pcVar38->node;
    if ((pcVar24 != (c1_node *)0x0) && (pcVar24->op == 0xe8)) {
      pcVar24 = property_build_access('\x01',pcVar24,(c1_node *)0x0);
      pcVar38->node = pcVar24;
    }
    pcVar21 = decl_declarator_symbol(pcVar13[-1].declarator);
    init_set_target_symbol(pcVar21);
    g_compile_flags_c8 = g_compile_flags_c8 | 0x80000;
    g_compile_flags_cc = g_compile_flags_cc | 0x80000;
    pcVar24 = expr_resolve_address_of_overload(pcVar38->node);
    pcVar21 = decl_declarator_symbol(pcVar13[-1].declarator);
    decl_finish_initialization(pcVar21,pcVar24);
    g_compile_flags_cc = g_compile_flags_cc & 0xfff7ffff;
    g_compile_flags_c8 = g_compile_flags_c8 & 0xfff7ffff;
    scope_pop_to_kind_if_needed(g_current_scope,'\x01');
    pcVar31 = pcVar13[-1].declarator;
LAB_10421651:
    pcVar21 = decl_declarator_symbol(pcVar31);
    type_check_destructible_2(pcVar21);
    g_string_literal_cur = &g_string_literal_buffer;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xd2:
    if (g_opt_Zg == '\0') {
      cVar9 = '\0';
      pcVar21 = decl_declarator_symbol(pcVar38->declarator);
      init_begin(pcVar21,cVar9);
      g_compile_flags_cc = g_compile_flags_cc | 0x80000;
      g_brace_init_active = 1;
      lVar44 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0xd3:
    pcVar21 = decl_declarator_symbol(pcVar13[-4].declarator);
    init_finish(pcVar21);
    g_compile_flags_cc = g_compile_flags_cc & 0xfff7ffff;
    if (g_opt_Zg == '\0') {
      pcVar21 = decl_declarator_symbol(pcVar13[-4].declarator);
      type_check_destructible_2(pcVar21);
    }
    scope_pop_to_kind_if_needed(g_current_scope,'\x01');
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xd4:
    pcVar52 = decl_specifiers_current();
    pcVar32 = decl_declarator_record(pcVar13->declarator);
    decl_check_conversion_return_type(pcVar32,pcVar52);
    pcVar32 = decl_declarator_record(pcVar13->declarator);
    decl_finish_declarator(pcVar32);
    pcVar52 = decl_specifiers_current();
    decl_declarator_set_specifiers(pcVar13->declarator,pcVar52);
    g_declarator_paren_base = g_declarator_paren_base + -1;
    lVar44 = g_enum_value;
    if (g_opt_Zg == '\0') {
      decl_set_has_initializer(pcVar13->declarator,'\x01');
      pcVar52 = decl_specifiers_current();
      decl_declarator_set_specifiers(pcVar13->declarator,pcVar52);
      pcVar52 = decl_specifiers_current();
      pcVar21 = decl_declare_and_check(pcVar13->declarator,pcVar52->spec);
      decl_record_set_symbol(pcVar13->ptr,pcVar21);
      pcVar21 = decl_declarator_symbol(pcVar13->declarator);
      decl_begin_initialized_definition(pcVar21);
      g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] | 2;
      lVar44 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0xd5:
    decl_specifiers_current();
    diag_error(0x201);
    value_base[1].words[0] = 0;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xd8:
    if (g_opt_Zg == '\0') {
      iVar53 = 0;
      pcVar24 = expr_resolve_address_of_overload(pcVar38->node);
      init_process_initializer(pcVar24,iVar53);
    }
    g_string_literal_cur = &g_string_literal_buffer;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xd9:
    if (g_opt_Zg == '\0') {
      init_check_too_many_2();
      lVar44 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0xda:
    if (g_opt_Zg == '\0') {
      init_pop_brace_level();
      lVar44 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0xdb:
    if (g_yy_lookahead == (byte *)0x0) {
      g_yy_lookahead = token_next((c1_token_reader *)&g_token_position);
    }
    cVar10 = lex_token_code((c1xx_token *)g_yy_lookahead);
    lVar44 = g_enum_value;
    switch(cVar10) {
    case '4':
    case '7':
    case '>':
    case 0xbf:
      goto switchD_10421905_caseD_1;
    case '6':
    case 'u':
    case 0xa6:
      bVar43 = g_paren_depth == 0;
      goto LAB_10421837;
    case 'j':
    case '~':
      bVar43 = g_paren_depth != 0;
LAB_10421837:
      if (bVar43) goto switchD_10421905_caseD_1;
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
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xdc:
  case 0x11a:
    g_declarator_paren_base = g_declarator_paren_base + 1;
    goto switchD_10421905_caseD_1;
  case 0xdd:
    pvVar23 = pcVar38->ptr;
    piVar19 = decl_declarator_record(value_base[1].declarator);
    decl_append_function_layer(piVar19,pvVar23);
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xde:
    pcVar31 = pcVar38->declarator;
    goto LAB_1042192a;
  case 0xe0:
    if (pcVar13->node == (c1_node *)0x0) {
      in_stack_00000020 = 0;
    }
    else {
      in_stack_00000020 = expr_eval_constant_expression(pcVar13->node);
      if (((g_class_depth < 0) || (g_ms_extensions == '\0')) && (in_stack_00000020 == 0)) {
        iVar53 = yyparse_cpp_zero_array_bound_error
                           (value_base,parser,state_sp,0,saved_lookahead,saved_rule);
        return iVar53;
      }
    }
    piVar19 = (int *)&stack0x00000020;
    pcVar32 = decl_declarator_record(value_base[1].declarator);
    decl_append_array_layer(pcVar32,piVar19);
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xe1:
  case 0x125:
  case 0x175:
    value_base[1].words[0] = pcVar13->words[0];
    lVar44 = g_enum_value;
  case 0x17f:
    g_enum_value = lVar44;
    parse_paren_depth_pop();
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xe2:
    pcVar31 = pcVar38->declarator;
    pcVar32 = decl_declarator_record(pcVar31);
    type_check_based_form(pcVar32,&pcVar13->mods);
    value_base[1].declarator = pcVar31;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xe4:
    pcVar31 = pcVar38->declarator;
    cVar9 = declarator_flags56_bit0(pcVar31);
    if (cVar9 != '\0') {
      pcVar52 = &g_conversion_type_specifiers;
      pcVar32 = decl_declarator_record(pcVar31);
      decl_record_set_conversion_type(pcVar32,pcVar52);
    }
    value_base[1].declarator = pcVar31;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xe5:
    pcVar31 = decl_declarator_alloc();
    if (pcVar31 == (c1_declarator *)0x0) {
LAB_10466a12:
      pcVar31 = (c1_declarator *)0x0;
    }
    else {
      pcVar31 = decl_declarator_init(pcVar31,pcVar38->name,0,(c1_overload_set *)0x0);
    }
    goto LAB_10421a04;
  case 0xe6:
    pcVar31 = decl_declarator_alloc();
    if (pcVar31 == (c1_declarator *)0x0) {
      pcVar31 = (c1_declarator *)0x0;
    }
    else {
      pcVar54 = (c1_overload_set *)0x0;
      uVar47 = 0;
      uVar49 = 0;
      uVar50 = 0;
      pcVar21 = value_word0(pcVar38->cell);
      pcVar31 = decl_declarator_init
                          (pcVar31,(fe_name *)pcVar21,CONCAT22(uVar50,CONCAT11(uVar49,uVar47)),
                           pcVar54);
    }
    pvVar23 = decl_declarator_record(pcVar38->declarator);
    if (pvVar23 == (void *)0x0) {
      pcVar21 = (c1_symbol *)sym_name(pcVar38->sym);
    }
    else {
      pcVar21 = (c1_symbol *)sym_name(pcVar38->sym);
    }
    iVar53 = sym_scope_index(pcVar21);
    if (iVar53 != 0) {
      pcVar21 = sym_scope_by_index(pcVar21,0x1c);
      decl_record_set_qualifying_class(pcVar31,pcVar21);
    }
    goto LAB_10421a04;
  case 0xe7:
    pcVar31 = decl_declarator_alloc();
    if (pcVar31 == (c1_declarator *)0x0) goto LAB_10466a12;
    pcVar54 = (c1_overload_set *)0x0;
    uVar47 = 0;
    uVar49 = 0;
    uVar50 = 0;
    pfVar30 = sym_name_of_ref(pcVar38->cell);
    pcVar31 = decl_declarator_init(pcVar31,pfVar30,CONCAT22(uVar50,CONCAT11(uVar49,uVar47)),pcVar54)
    ;
LAB_10421a04:
    cVar9 = class_name_is_current_class(pcVar31);
    if (cVar9 == '\0') {
LAB_10421a0f:
      value_base[1].declarator = pcVar31;
      lVar44 = g_enum_value;
    }
    else {
      decl_set_is_constructor(pcVar31,'\x01');
      value_base[1].declarator = pcVar31;
      lVar44 = g_enum_value;
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
      pcVar31 = decl_declarator_init(pcVar31,pcVar38->name,0,(c1_overload_set *)0x0);
    }
    cVar9 = class_name_is_current_class(pcVar31);
    if (cVar9 == '\0') {
      if (-1 < g_class_depth) goto LAB_10466aa7;
LAB_10466b25:
      value_word0((c1_symbol **)pcVar31);
LAB_10466b2d:
      diag_error(0x24c);
      value_base[1].declarator = pcVar31;
      lVar44 = g_enum_value;
    }
    else {
      decl_set_is_destructor(pcVar31,'\x01');
      value_base[1].declarator = pcVar31;
      lVar44 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0xea:
    pcVar21 = value_word0(pcVar38->cell);
    pcVar31 = decl_declarator_alloc();
    if (pcVar31 == (c1_declarator *)0x0) {
      pcVar31 = (c1_declarator *)0x0;
    }
    else {
      pcVar31 = decl_declarator_init(pcVar31,(fe_name *)pcVar21,0,(c1_overload_set *)0x0);
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
      uVar47 = 0;
      uVar49 = 0;
      uVar50 = 0;
      pfVar30 = sym_name_of_ref(pcVar38->cell);
      pcVar31 = decl_declarator_init
                          (pcVar31,pfVar30,CONCAT22(uVar50,CONCAT11(uVar49,uVar47)),pcVar54);
    }
    cVar9 = class_name_is_current_class(pcVar31);
    if (cVar9 != '\0') goto LAB_10421ad0;
    if (g_class_depth < 0) goto LAB_10466b25;
LAB_10466aa7:
    diag_error(0x20b);
    pvVar23 = class_current_definition_name();
    decl_set_name(pcVar31,pvVar23);
LAB_10421ad0:
    decl_set_is_destructor(pcVar31,'\x01');
    value_base[1].declarator = pcVar31;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xec:
    pcVar31 = decl_declarator_alloc();
    if (pcVar31 == (c1_declarator *)0x0) {
      value_set_byte30((c1_declarator *)0x0,(pcVar38->spec).spec[0]);
      value_base[1].words[0] = 0;
      lVar44 = g_enum_value;
    }
    else {
      pcVar31 = decl_declarator_init
                          (pcVar31,*(fe_name **)((int)pcVar13 + 0x2c),0,(c1_overload_set *)0x0);
      value_set_byte30(pcVar31,(pcVar38->spec).spec[0]);
      value_base[1].declarator = pcVar31;
      lVar44 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0xed:
    pcVar52 = &g_conversion_type_specifiers;
    for (iVar53 = 9; iVar53 != 0; iVar53 = iVar53 + -1) {
      *(c1_u32 *)pcVar52->spec = pcVar38->words[0];
      pcVar38 = (c1_yy_value *)(pcVar38->words + 1);
      pcVar52 = (c1xx_decl_specifiers *)(pcVar52->spec + 4);
    }
    pcVar31 = decl_declarator_alloc();
    if (pcVar31 == (c1_declarator *)0x0) {
      pcVar31 = (c1_declarator *)0x0;
    }
    else {
      pcVar54 = (c1_overload_set *)0x0;
      uVar47 = 0;
      uVar49 = 0;
      uVar50 = 0;
      pfVar30 = decl_conversion_function_name(g_conversion_type_specifiers.type);
      pcVar31 = decl_declarator_init
                          (pcVar31,pfVar30,CONCAT22(uVar50,CONCAT11(uVar49,uVar47)),pcVar54);
    }
    value_set_byte30(pcVar31,0x8f);
    declarator_set_flags56_bit0(pcVar31,'\x01');
    g_compile_flags_c4 = g_compile_flags_c4 & 0xfffffffb;
    value_base[1].declarator = pcVar31;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xee:
    if (pcVar38->cell == (c1_symbol **)0x0) {
      d.sym = (c1_symbol *)0x0;
      in_stack_00000018.sym = d.sym;
    }
    else {
      pcVar14 = value_word0(pcVar38->cell);
      pcVar21 = *(c1_symbol **)(*(int *)pcVar14->type + 8);
      pcVar31 = decl_declarator_alloc();
      if (pcVar31 == (c1_declarator *)0x0) {
        d.sym = (c1_symbol *)0x0;
      }
      else {
        uVar47 = 0;
        uVar49 = 0;
        uVar50 = 0;
        qualifier = pcVar14;
        pfVar30 = (fe_name *)sym_name(pcVar14);
        d.sym = (c1_symbol *)
                decl_declarator_init
                          (pcVar31,pfVar30,CONCAT22(uVar50,CONCAT11(uVar49,uVar47)),qualifier);
      }
      in_stack_00000018 = d;
      lookup_check_symbol_kinds_reversed(*(int **)pcVar14->type);
      bVar11 = pcVar14->flags1;
      if ((bVar11 & 0x40) == 0) {
        if ((bVar11 & 0x10) == 0) {
          lVar44 = g_enum_value;
          if ((bVar11 & 0x20) != 0) {
            decl_set_is_destructor(d.declarator,'\x01');
            lVar44 = g_enum_value;
          }
        }
        else {
          decl_set_is_constructor(d.declarator,'\x01');
          lVar44 = g_enum_value;
        }
      }
      else {
        d = in_stack_00000018;
        if ((pcVar21->kind & 0x1f) == 0x11) {
          pcVar21 = (c1_symbol *)ovl_first_function_of_set(pcVar21);
          d = in_stack_00000018;
        }
        g_conversion_type_specifiers.type = decl_declarator_record((c1_declarator *)pcVar21->type);
        puVar27 = decl_specifiers_of_symbol((uint *)&stack0x0000016c,pcVar21);
        pcVar52 = &g_conversion_type_specifiers;
        for (iVar53 = 6; iVar53 != 0; iVar53 = iVar53 + -1) {
          *(uint *)pcVar52->spec = *puVar27;
          puVar27 = puVar27 + 1;
          pcVar52 = (c1xx_decl_specifiers *)(pcVar52->spec + 4);
        }
        declarator_set_flags56_bit0(d.declarator,'\x01');
        in_stack_00000018 = d;
        lVar44 = g_enum_value;
      }
      bVar11 = pcVar21->kind & 0x1f;
      if ((((bVar11 == 0x10) || (bVar11 == 7)) ||
          ((bVar11 == 6 || (((bVar11 == 0x11 || (bVar11 == 8)) || (bVar11 == 0x1b)))))) ||
         ((bVar11 == 0x1a &&
          (((bVar11 = **(byte **)pcVar21->type & 0x1f, bVar11 == 0x10 || (bVar11 == 7)) ||
           (((bVar11 == 6 || ((bVar11 == 0x11 || (bVar11 == 8)))) || (bVar11 == 0x1b)))))))) {
        g_enum_value = lVar44;
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
        bVar11 = pcVar21->kind & 0x1f;
        if (((bVar11 == 0x10) || (bVar11 == 0x11)) || (bVar11 == 0x1b)) {
          pbVar15 = ovl_first_function_of_set(pcVar21);
          value_set_byte30(d.declarator,pbVar15[0x2f]);
          value_base[1].declarator = (c1_declarator *)d;
          lVar44 = g_enum_value;
        }
        else {
          value_set_byte30(d.declarator,(pcVar21->tail).fn.op_token);
          value_base[1].declarator = (c1_declarator *)d;
          lVar44 = g_enum_value;
        }
        goto switchD_10421905_caseD_1;
      }
    }
    g_enum_value = lVar44;
    value_base[1].declarator = (c1_declarator *)d;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xef:
    if (pcVar13->cell == (c1_symbol **)0x0) {
LAB_10466c6d:
      pcVar31 = (c1_declarator *)0x0;
    }
    else {
      pcVar21 = value_word0(pcVar13->cell);
      pcVar52 = &g_conversion_type_specifiers;
      for (iVar53 = 9; iVar53 != 0; iVar53 = iVar53 + -1) {
        *(c1_u32 *)pcVar52->spec = pcVar38->words[0];
        pcVar38 = (c1_yy_value *)(pcVar38->words + 1);
        pcVar52 = (c1xx_decl_specifiers *)(pcVar52->spec + 4);
      }
      decl_qualified_conversion_function_name(pcVar21,g_conversion_type_specifiers.type);
      if (pcVar21->type == (c1_type *)0x0) {
        pcVar31 = decl_declarator_alloc();
        if (pcVar31 == (c1_declarator *)0x0) goto LAB_10466c6d;
        pcVar54 = (c1_overload_set *)0x0;
        uVar47 = 0;
        uVar49 = 0;
        uVar50 = 0;
        pfVar30 = name_new_S();
        pcVar31 = decl_declarator_init
                            (pcVar31,pfVar30,CONCAT22(uVar50,CONCAT11(uVar49,uVar47)),pcVar54);
      }
      else {
        pcVar31 = decl_declarator_alloc();
        if (pcVar31 == (c1_declarator *)0x0) {
          pcVar31 = (c1_declarator *)0x0;
        }
        else {
          uVar47 = 0;
          uVar49 = 0;
          uVar50 = 0;
          pcVar14 = pcVar21;
          pfVar30 = (fe_name *)sym_name(pcVar21);
          pcVar31 = decl_declarator_init
                              (pcVar31,pfVar30,CONCAT22(uVar50,CONCAT11(uVar49,uVar47)),
                               (c1_overload_set *)pcVar14);
        }
        lookup_check_symbol_kinds_reversed(*(int **)pcVar21->type);
        if (**(int **)pcVar21->type != 0) {
          pcVar21 = *(c1_symbol **)(**(int **)pcVar21->type + 8);
          if ((pcVar21->kind & 0x1f) == 0xf) {
            pcVar21 = scope_vector_get((short)pcVar21->key_ref);
          }
          decl_record_set_qualifying_class(pcVar31,pcVar21);
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
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xf0:
    pcVar13 = value_base + 1;
    decl_conversion_function_declarator(&pcVar13->spec,(c1_decl_record *)0x0);
    (pcVar13->spec).spec[0] = (pcVar13->spec).spec[0] & 0x7f;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xf1:
    pcVar13 = value_base + 1;
    pcVar32 = decl_declarator_record(pcVar38->declarator);
    decl_conversion_function_declarator(&pcVar13->spec,pcVar32);
    (pcVar13->spec).spec[0] = (pcVar13->spec).spec[0] & 0x7f;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xf2:
    param_clause_set_cv_qualifiers(pcVar13[-1].params,&pcVar13->mods);
    param_clause_set_exception_spec(pcVar13[-1].params,pcVar38->words[0]);
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xf3:
    pcVar28 = class_record_new_kind5();
    value_base[1].str.text = pcVar28;
    parse_paren_depth_pop();
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xf4:
    g_prototype_scope_depth = g_prototype_scope_depth + 1;
    g_block_depth = g_block_depth + '\x01';
    scope_new_block_record(g_current_scope,(c1_sym_list *)0x0);
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xf5:
    pvVar23 = pcVar13[-1].ptr;
    value_base[1].ptr = pvVar23;
    if (pcVar13->sym != (c1_symbol *)0x0) {
      sym_list_append(pvVar23,pcVar13->sym);
    }
    g_prototype_scope_depth = g_prototype_scope_depth + -1;
    g_block_depth = g_block_depth + 0xff;
    parse_paren_depth_pop();
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xf6:
    if (((((g_block_depth == '\0') || (-1 < g_class_depth)) ||
         ((g_compile_flags_c8 & 0x10000000) != 0)) ||
        ((((g_compile_flags_c8 & 0x40000000) != 0 && ((g_compile_flags_cc & 8) == 0)) &&
         ((g_compile_flags_c4 & 0x200) == 0)))) || ((g_compile_flags_cc & 0x50) != 0)) {
      iVar53 = 0;
    }
    else {
      iVar53 = 4;
    }
    pcVar21 = sym_new_of_kind('\v',g_name_ellipsis,iVar53);
    sym_mark_ellipsis_parameter(pcVar21);
    pcVar22 = type_intern_basic_parts(0x80d,0,0);
    pcVar21->type = pcVar22;
    pcVar16 = (c1_param_clause *)arena5_alloc_1c();
    if (pcVar16 == (c1_param_clause *)0x0) {
      value_base[1].words[0] = 0;
      sym_list_append((void *)0x0,pcVar21);
      parse_paren_depth_pop();
      lVar44 = g_enum_value;
    }
    else {
      pcVar16 = optional_value_init(pcVar16,3,(c1_sym_list *)0x0,'\0');
      value_base[1].params = pcVar16;
      sym_list_append(pcVar16,pcVar21);
      parse_paren_depth_pop();
      lVar44 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0xf8:
    if (pcVar38->words[0] != 2) goto LAB_10467c9b;
    diag_warning(3,0x122);
    value_base[1].ptr = (void *)pcVar38->words[0];
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xf9:
    pcVar16 = (c1_param_clause *)arena5_alloc_1c();
    if (pcVar16 == (c1_param_clause *)0x0) goto LAB_10465f34;
    cVar9 = '\x01';
    scope = decl_declarator_record((c1_declarator *)g_current_scope);
    params = scope_symbol_list(scope);
    pcVar16 = optional_value_init(pcVar16,3,params,cVar9);
    value_base[1].params = pcVar16;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xfb:
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] | 8;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xfc:
    if ((pcVar38->words[0] != 0) && (g_paren_level_arg_lists[g_paren_depth] != (c1_arg_list *)0x0))
    {
      arena_set_expression_index(0);
      g_compile_flags_cc = g_compile_flags_cc | 0x10;
      pcVar24 = tree_append_list_item((c1_node *)0x0,(c1_node *)0x0,2);
      pcVar17 = (c1_arg_item *)arena_alloc_n_aligned(0x14,0);
      if (pcVar17 == (c1_arg_item *)0x0) {
        pcVar17 = (c1_arg_item *)0x0;
      }
      else {
        pcVar17 = arg_expression_item_init(pcVar17,pcVar24,'\0','\x01');
      }
      tmpl_argument_list_prepend(g_paren_level_arg_lists[g_paren_depth],pcVar17);
      goto LAB_10466d4e;
    }
    goto switchD_10421905_caseD_5c;
  case 0xfd:
    cVar10 = token_source_reads_source_file((c1_token_reader *)&g_token_position);
    if (cVar10 != '\0') {
      iVar53 = 0;
      pcVar36 = g_idb->vtbl;
      uVar55 = lex_line_number_of_position(&g_token_position);
      (*pcVar36->idb_scope_kind4_end)(g_idb,uVar55,iVar53);
    }
    if ((pcVar13->words[0] != 0) && (pcVar38->node != (c1_node *)0x0)) {
      pcVar24 = expr_resolve_address_of_overload(pcVar38->node);
      if ((g_compile_flags_c8 & 0x40000000) != 0) {
        pcVar24 = tree_copy_to_arena(pcVar24,0);
      }
      tree_attach_typed_link(pcVar24,pcVar13->sym->type);
      acStack_24[1] = 0x10421fe2;
      pcVar24 = conv_convert_expression(0xc6,pcVar13->sym->type,pcVar24,'\x02','\x04');
      pcVar38->node = pcVar24;
      iVar53 = 2;
      pcVar24 = (c1_node *)expr_finish_full_expression((int)pcVar24);
      pcVar24 = tree_append_list_item((c1_node *)0x0,pcVar24,iVar53);
      pcVar17 = (c1_arg_item *)arena_alloc_n_aligned(0x14,0);
      if (pcVar17 == (c1_arg_item *)0x0) {
        pcVar17 = (c1_arg_item *)0x0;
      }
      else {
        pcVar17 = arg_expression_item_init(pcVar17,pcVar24,'\0','\x01');
      }
      if (g_paren_level_arg_lists[g_paren_depth] == (c1_arg_list *)0x0) {
        pcVar28 = arena_alloc_n_aligned(0xc,0);
        if (pcVar28 == (c1_u8 *)0x0) {
          g_paren_level_arg_lists[g_paren_depth] = (c1_arg_list *)0x0;
        }
        else {
          pcVar18 = tmpl_argument_list_init(pcVar28,pcVar17);
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
      iVar53 = 0;
      pcVar36 = g_idb->vtbl;
      uVar55 = lex_line_number_of_position(&g_token_position);
      (*pcVar36->idb_scope_kind4_end)(g_idb,uVar55,iVar53);
    }
    if ((g_compile_flags_c8 & 0x10000000) == 0) {
      diag_error(0x3e);
    }
    pcVar17 = (c1_arg_item *)arena_alloc_n_aligned(0x14,0);
    if (pcVar17 == (c1_arg_item *)0x0) {
      pcVar17 = (c1_arg_item *)0x0;
    }
    else {
      pcVar17 = pch_fixup_list_object_ctor(pcVar17,pcVar38->sym->type,'\0');
    }
    if (g_paren_level_arg_lists[g_paren_depth] == (c1_arg_list *)0x0) {
      pcVar28 = arena_alloc_n_aligned(0xc,0);
      if (pcVar28 == (c1_u8 *)0x0) {
        g_paren_level_arg_lists[g_paren_depth] = (c1_arg_list *)0x0;
      }
      else {
        pcVar18 = tmpl_argument_list_init(pcVar28,pcVar17);
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
    lVar44 = g_enum_value;
switchD_10421905_caseD_5c:
    g_enum_value = lVar44;
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfd;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0xff:
    cVar10 = token_source_reads_source_file((c1_token_reader *)&g_token_position);
    if (cVar10 != '\0') {
      iVar53 = 0;
      pcVar36 = g_idb->vtbl;
      uVar55 = lex_line_number_of_position(&g_token_position);
      (*pcVar36->idb_scope_kind4_end)(g_idb,uVar55,iVar53);
    }
    if ((g_compile_flags_cc & 0x100000) == 0) {
      pcVar24 = arena_alloc(g_arenas + g_expr_arena_index,0x18);
      pcVar24->kind = '\0';
      pcVar24->op = 0xc6;
      pcVar24->left = (void *)pcVar38->words[0];
      pcVar22 = type_intern_basic_parts(0x80e,0,0);
      value_set_field4(pcVar24,pcVar22);
      pcVar24 = tree_append_list_item((c1_node *)0x0,pcVar24,2);
      pcVar17 = (c1_arg_item *)arena_alloc_n_aligned(0x14,0);
      if (pcVar17 == (c1_arg_item *)0x0) {
        pcVar17 = (c1_arg_item *)0x0;
      }
      else {
        pcVar17 = arg_expression_item_init(pcVar17,pcVar24,'\0','\x01');
      }
      if (g_paren_level_arg_lists[g_paren_depth] == (c1_arg_list *)0x0) {
        pcVar28 = arena_alloc_n_aligned(0xc,0);
        if (pcVar28 == (c1_u8 *)0x0) {
          g_paren_level_arg_lists[g_paren_depth] = (c1_arg_list *)0x0;
        }
        else {
          pcVar18 = tmpl_argument_list_init(pcVar28,pcVar17);
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
      iVar53 = 0;
      pcVar36 = g_idb->vtbl;
      uVar55 = lex_line_number_of_position(&g_token_position);
      (*pcVar36->idb_scope_kind4_end)(g_idb,uVar55,iVar53);
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
      lVar44 = g_enum_value;
    }
    else {
      g_compile_flags_c8 = g_compile_flags_c8 | 0x8000000;
      parse_default_argument_begin(pcVar38->sym->type);
      func_flow_state_note_3e();
      lVar44 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0x102:
    cVar10 = token_source_reads_source_file((c1_token_reader *)&g_token_position);
    lVar44 = g_enum_value;
    if (cVar10 != '\0') {
      pcVar36 = g_idb->vtbl;
LAB_10422231:
      iVar53 = 0;
      uVar55 = lex_line_number_of_position(&g_token_position);
      (*pcVar36->idb_scope_kind3_to_4)(g_idb,uVar55,iVar53);
      lVar44 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0x104:
    scope_insert_through_object(g_current_scope,pcVar38->sym);
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
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
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x106:
    pcVar40 = (c1_u32 *)&stack0x00000094;
    for (iVar53 = 9; iVar53 != 0; iVar53 = iVar53 + -1) {
      *pcVar40 = pcVar13->words[0];
      pcVar40 = pcVar40 + 1;
      pcVar13 = (c1_yy_value *)(pcVar13->words + 1);
    }
    decl_set_local_key_flag(pcVar38->declarator,'\x01');
    if (((g_compile_flags_c8 & 0x10000000) == 0) || (g_paren_depth != 1)) {
      cVar29 = 5;
    }
    else {
      cVar29 = 0xb;
    }
    declarator_set_kind(pcVar38->declarator,cVar29);
    pcVar52 = (c1xx_decl_specifiers *)&stack0x00000094;
    pcVar32 = decl_declarator_record(pcVar38->declarator);
    decl_check_conversion_return_type(pcVar32,pcVar52);
    pcVar32 = decl_declarator_record(pcVar38->declarator);
    decl_finish_declarator(pcVar32);
    decl_declarator_set_specifiers(pcVar38->declarator,(c1xx_decl_specifiers *)&stack0x00000094);
    decl_declare_in_current_scope(pcVar38->declarator,(c1xx_decl_specifiers *)&stack0x00000094);
    pcVar21 = decl_declarator_symbol(pcVar38->declarator);
    if ((g_compile_flags_c8 & 0x10000000) != 0) {
      pcVar22 = pcVar21->type;
      cVar9 = type_code_is_201(pcVar22);
      if (cVar9 == '\0') {
        cVar9 = type_code_is_202(pcVar22);
        if (cVar9 != '\0') {
          iVar53 = yyparse_cpp_class_template_parameter_error
                             (pcVar21,value_base,parser,state_sp,saved_lookahead,saved_rule);
          return iVar53;
        }
      }
      else if ((pcVar21->storage & 0x80) == 0) {
        diag_error(0x3e1);
        pcVar21->flags3 = pcVar21->flags3 | 4;
      }
    }
    g_declarator_paren_base = g_declarator_paren_base + -1;
    scope_pop_to_kind_if_needed(g_current_scope,'\x01');
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfc;
    value_base[1].sym = pcVar21;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x107:
    bVar43 = false;
    decl_set_local_key_flag(pcVar38->declarator,'\x01');
    if (((g_compile_flags_c8 & 0x10000000) == 0) || (g_paren_depth != 1)) {
      cVar29 = 6;
    }
    else {
      cVar29 = 0xb;
    }
    declarator_set_kind(pcVar38->declarator,cVar29);
    decl_set_name(pcVar38->declarator,g_name_formal);
    if ((((g_compile_flags_c8 & 0x10000000) != 0) && ((pcVar13->spec).type_sym != (c1_symbol *)0x0))
       && ((((pcVar13->spec).type_sym)->kind & 0x1f) == 4)) {
      pcVar22 = type_innermost_base((pcVar13->spec).type);
      if (((pcVar22->code & 0x20f) == 0x201) && (((pcVar13->spec).spec[0] & 0x80) == 0)) {
        iVar53 = sym_scope_index((pcVar13->spec).type_sym);
        if (iVar53 == 0) {
          bVar43 = true;
          pvVar23 = (void *)sym_name((pcVar13->spec).type_sym);
          if ((*(uint *)((int)pvVar23 + 8) & 0x2000000) != 0) {
            cell = lookup_name_in_context(g_current_scope,pvVar23,0x20);
            if (cell != (c1_lookup_entry *)0x0) {
              value_word0(&cell->sym);
            }
            diag_error(0x3af);
          }
          decl_set_name(pcVar38->declarator,pvVar23);
        }
      }
    }
    (pcVar13->spec).spec[0] = (pcVar13->spec).spec[0] & 0x7f;
    pcVar37 = pcVar13;
    pcVar32 = decl_declarator_record(pcVar38->declarator);
    decl_check_conversion_return_type(pcVar32,&pcVar37->spec);
    pcVar32 = decl_declarator_record(pcVar38->declarator);
    decl_finish_declarator(pcVar32);
    decl_declarator_set_specifiers(pcVar38->declarator,&pcVar13->spec);
    decl_process_declaration(pcVar38->declarator);
    pcVar21 = sym_new_from_declarator(pcVar38->declarator,0xffffffff);
    if (bVar43) {
      bVar11 = type_code_high_bit(pcVar21->type);
      if (bVar11 != 0) {
        sym_name(pcVar21);
        diag_error(0x395);
        pcVar21->flags3 = pcVar21->flags3 | 4;
      }
    }
    g_declarator_paren_base = g_declarator_paren_base + -1;
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfc;
    value_base[1].sym = pcVar21;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x108:
  case 0x10f:
    goto switchD_10421905_caseD_105;
  case 0x10b:
  case 0x112:
    qualified_type_merge(&value_base[1].mods,&pcVar38->mods,(c1_u32)g_yy_lookahead);
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x10c:
    diag_warning(1,0xe6);
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x10d:
    operator_id_set(&value_base[1].mods,(short)g_tree_op_to_il_op[(pcVar38->spec).spec[0]],
                    (void *)0x0);
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x10e:
    value_base[1].words[0] = pcVar13->words[0];
    *(c1_u32 *)((int)value_base + 0x2c) = pcVar13->words[1];
    parse_paren_depth_pop();
    g_compile_flags_c4 = g_compile_flags_c4 & 0x7fffffff;
    lVar44 = g_enum_value;
    if ((g_compile_flags_c8 & 0x10) != 0) {
      g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfc;
      lVar44 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0x113:
    operator_id_set(&value_base[1].mods,(short)g_tree_op_to_il_op[(pcVar38->spec).spec[0]],
                    (void *)0x0);
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x114:
    operator_id_set(&value_base[1].mods,(pcVar38->ptr_op).kind,(void *)0x0);
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x115:
    bits = value_u16_at2(*(c1_type **)((int)pcVar13 + 0x40));
    pcVar22 = type_without_flags(*(c1_type **)((int)pcVar13 + 0x40),0x3e0);
    *(c1_type **)((int)pcVar13 + 0x40) = pcVar22;
    decl_warn_unexpected_specifiers_1(&pcVar38->spec);
    operator_id_set(&value_base[1].mods,bits,(void *)0x0);
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x116:
    pcVar21 = type_parse_based_specifier(pcVar38->ptr);
    operator_id_set(&value_base[1].mods,0x18,pcVar21);
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x117:
    pcVar24 = expr_check_this_usage();
    lVar44 = g_enum_value;
    if (pcVar24 == (c1_node *)0x0) {
switchD_10421905_caseD_105:
      g_enum_value = lVar44;
      pair_clear(&value_base[1].mods);
      lVar44 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0x118:
    operator_id_set(&value_base[1].mods,8,(void *)0x0);
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x119:
    pair_clear(&value_base[1].mods);
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_14f;
  case 0x11c:
    pcVar31 = decl_declarator_alloc();
    if (pcVar31 == (c1_declarator *)0x0) {
LAB_10465f34:
      value_base[1].words[0] = 0;
      lVar44 = g_enum_value;
    }
    else {
      pcVar31 = decl_declarator_init(pcVar31,g_name_abstract_declarator,4,(c1_overload_set *)0x0);
      value_base[1].declarator = pcVar31;
      lVar44 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0x11d:
    pcVar31 = decl_declarator_alloc();
    if (pcVar31 == (c1_declarator *)0x0) {
      pcVar32 = decl_declarator_record((c1_declarator *)0x0);
      type_check_based_form(pcVar32,&pcVar38->mods);
      value_base[1].words[0] = 0;
      lVar44 = g_enum_value;
    }
    else {
      pcVar31 = decl_declarator_init(pcVar31,g_name_abstract_declarator,4,(c1_overload_set *)0x0);
      pcVar32 = decl_declarator_record(pcVar31);
      type_check_based_form(pcVar32,&pcVar38->mods);
      value_base[1].declarator = pcVar31;
      lVar44 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0x11e:
    pcVar31 = decl_declarator_alloc();
    if (pcVar31 == (c1_declarator *)0x0) {
      pvVar23 = pcVar38->ptr;
      pcVar31 = (c1_declarator *)0x0;
    }
    else {
      pcVar31 = decl_declarator_init(pcVar31,g_name_abstract_declarator,4,(c1_overload_set *)0x0);
      pvVar23 = pcVar38->ptr;
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
    pvVar23 = pcVar38->ptr;
LAB_10467272:
    piVar19 = decl_declarator_record(pcVar31);
    decl_append_function_layer(piVar19,pvVar23);
    goto LAB_10421a0f;
  case 0x120:
    pcVar32 = decl_declarator_record(pcVar38->declarator);
    decl_declarator_append_pointer_op(pcVar32,&pcVar13->ptr_op);
    lVar44 = g_enum_value;
switchD_10421905_caseD_e5:
    g_enum_value = lVar44;
    value_base[1].ptr = (void *)pcVar38->words[0];
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x122:
    pcVar24 = pcVar13->node;
    pvVar23 = decl_declarator_record(value_base[1].declarator);
    type_check_array_bound_constant_2(pvVar23,pcVar24);
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x123:
    pvVar23 = pcVar38->ptr;
    piVar19 = decl_declarator_record(value_base[1].declarator);
    decl_append_function_layer(piVar19,pvVar23);
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x126:
    pcVar31 = decl_declarator_alloc();
    if (pcVar31 == (c1_declarator *)0x0) {
      pcVar31 = (c1_declarator *)0x0;
      pcVar13 = pcVar38;
      lVar44 = g_enum_value;
    }
    else {
      pcVar31 = decl_declarator_init(pcVar31,(fe_name *)0x0,0,(c1_overload_set *)0x0);
      pcVar13 = pcVar38;
      lVar44 = g_enum_value;
    }
LAB_1042192a:
    g_enum_value = lVar44;
    pcVar32 = decl_declarator_record(pcVar31);
    decl_declarator_append_pointer_op(pcVar32,&pcVar13->ptr_op);
LAB_10421939:
    value_base[1].declarator = pcVar31;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x127:
  case 0x1e6:
    pcVar32 = decl_declarator_record(pcVar38->declarator);
    decl_declarator_append_pointer_op(pcVar32,&pcVar13->ptr_op);
    lVar44 = g_enum_value;
LAB_10467c9b:
    g_enum_value = lVar44;
    value_base[1].ptr = (void *)pcVar38->words[0];
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x128:
    in_stack_00000040 = pcVar13[-1].words[0];
    in_stack_00000044 = *(void **)((int)pcVar13 + -0x24);
    type_pair_record_init(&value_base[1].ptr_op,(c1_decl_modifier *)&stack0x00000040,&pcVar38->mods)
    ;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x129:
    pcVar20 = u16_value_init((c1_decl_modifier *)&stack0x0000008c,0);
    type_pair_record_init(&value_base[1].ptr_op,pcVar20,&pcVar38->mods);
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x12a:
    in_stack_00000048 = pcVar13[-1].words[0];
    in_stack_0000004c = *(void **)((int)pcVar13 + -0x24);
    type_warn_qualifiers_on_reference
              (&value_base[1].ptr_op,(c1_decl_modifier *)&stack0x00000048,&pcVar38->mods);
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 299:
    pcVar20 = u16_value_init((c1_decl_modifier *)&stack0x00000084,0);
    type_warn_qualifiers_on_reference(&value_base[1].ptr_op,pcVar20,&pcVar38->mods);
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 300:
    in_stack_00000038 = pcVar13[-1].words[0];
    in_stack_0000003c = *(void **)((int)pcVar13 + -0x24);
    qualified_name_record_init
              (&value_base[1].ptr_op,pcVar13->qualified,(c1_decl_modifier *)&stack0x00000038,
               &pcVar38->mods);
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x12e:
    goto switchD_10421905_caseD_12b;
  case 0x12f:
    goto switchD_10421905_caseD_12c;
  case 0x130:
    if ((g_opt_Zg == '\0') && ((g_compile_flags_c4 & 0x800000) == 0)) {
      if ((pcVar38->spec).spec[0] != 0xaa) {
        func_begin_compound_statement();
      }
      g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfc;
      il_emit_line_record_24();
      lVar44 = g_enum_value;
    }
    else {
      lex_skip_to_closing_brace('\0');
      lVar44 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0x131:
    if ((g_opt_Zg == '\0') && ((g_compile_flags_c4 & 0x800000) == 0)) {
      if (pcVar13[-1].spec.spec[0] != 0xaa) {
        scope_end_block();
        lVar44 = g_enum_value;
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
      lVar44 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0x136:
  case 0x165:
    value_base[1].spec.spec[0] = '\0';
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x137:
  case 0x176:
  case 0x1ed:
    value_base[1].spec.spec[0] = '\x01';
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x138:
    pcVar24 = pcVar13->node;
    if (pcVar24 != (c1_node *)0x0) {
      if (pcVar24->op == 0xe8) {
        pcVar24 = property_build_access('t',pcVar24,(c1_node *)0x0);
        pcVar13->node = pcVar24;
      }
      cVar9 = '\x01';
      pcVar24 = expr_resolve_address_of_overload(pcVar13->node);
      pcVar24 = expr_warn_no_effect(pcVar24,cVar9);
      pcVar13->node = pcVar24;
      pcVar24 = expr_full_expression_guarded(pcVar24,2);
      stmt_emit_expression(pcVar24);
    }
    iVar53 = parse_error_recovery_count();
    if (iVar53 != 0) goto LAB_10422a54;
    arena_reset(5);
    g_string_literal_cur = &g_string_literal_buffer;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x13b:
    func_end_compound_statement(pcVar13->node,'\0');
    label_emit_definition(pcVar13->node);
    stmt_if_then_end_flow_state(1);
    func_end_compound_statement((c1_node *)0x0,'\x01');
    lVar44 = g_enum_value;
    if ((pcVar38->spec).spec[0] != '\0') {
      diag_warning(3,0x186);
      lVar44 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0x13c:
    func_end_compound_statement(pcVar13->node,'\0');
    label_emit_definition(pcVar13->node);
    stmt_else_end_flow_state();
    func_end_compound_statement((c1_node *)0x0,'\x01');
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x13d:
    stmt_while_end_flow_state();
    stmt_loop_end();
    func_end_compound_statement((c1_node *)0x0,(pcVar13->spec).spec[0]);
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x13e:
    if (g_ms_extensions != '\0') {
      func_end_compound_statement((c1_node *)0x0,(pcVar13->spec).spec[0]);
      stmt_for_end_flow_state();
    }
    stmt_loop_end();
    lVar44 = g_enum_value;
    if (g_ms_extensions == '\0') {
      stmt_for_end_flow_state();
      func_end_compound_statement((c1_node *)0x0,(pcVar13->spec).spec[0]);
      lVar44 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0x13f:
    func_flow_state_note_1f();
    stmt_do_head();
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfc;
    cVar10 = parse_begin_compound_value((c1_node *)0x0);
    (pcVar38->spec).spec[0] = cVar10;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x140:
    func_end_compound_statement((c1_node *)0x0,pcVar13[-3].spec.spec[0]);
    func_flow_state_note_22();
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] | 3;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x141:
    label_emit_definition(g_continue_label_stack->label);
    if (pcVar13[-1].node != (c1_node *)0x0) {
      pcVar24 = expr_resolve_address_of_overload(pcVar13[-1].node);
      pcVar13[-1].node = pcVar24;
      pcVar24 = stmt_check_controlling_expression(pcVar24,0);
      pcVar13[-1].node = pcVar24;
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
    iVar53 = parse_error_recovery_count();
    if (iVar53 == 0) {
      arena_reset(5);
    }
    g_string_literal_cur = &g_string_literal_buffer;
    stmt_do_end_flow_state();
    parse_paren_depth_pop();
    lVar44 = g_enum_value;
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
    lVar44 = g_enum_value;
    if (g_loop_label_count == 0) {
      arena_reset(6);
      lVar44 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0x143:
    eh_check_leave();
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x144:
    if (g_break_label_stack == (void *)0x0) {
      diag_error(0x2b);
      lVar44 = g_enum_value;
    }
    else {
      stmt_jump_flow_state();
      il_emit_tuple(0x3a,*(node **)((int)g_break_label_stack + 4));
      lVar44 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0x145:
    if (g_continue_label_stack == (c1xx_label_cell *)0x0) {
      diag_error(0x2c);
      lVar44 = g_enum_value;
    }
    else {
      stmt_jump_flow_state_2();
      il_emit_tuple(0x3a,g_continue_label_stack->label);
      lVar44 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0x146:
    func_flow_state_note_8();
    stmt_emit_return_value((c1_node *)0x0,1);
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x147:
    func_flow_state_note_8();
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x148:
    pcVar24 = pcVar13->node;
    if ((pcVar24 != (c1_node *)0x0) && (pcVar24->op == 0xe8)) {
      pcVar24 = property_build_access('\x01',pcVar24,(c1_node *)0x0);
      pcVar13->node = pcVar24;
    }
    pcVar24 = expr_resolve_address_of_overload(pcVar13->node);
    pcVar13->node = pcVar24;
    stmt_emit_return_value(pcVar24,2);
    iVar53 = parse_error_recovery_count();
    if (iVar53 != 0) goto LAB_10422a54;
    arena_reset(5);
    g_string_literal_cur = &g_string_literal_buffer;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x149:
    pcVar21 = (c1_symbol *)label_find_in_function(pcVar13->words[0]);
    if (pcVar21 == (c1_symbol *)0x0) {
      pcVar21 = (c1_symbol *)label_new_user(pcVar13->words[0]);
      label_register(pcVar21);
      stmt_goto_flow_state(pcVar21,0);
    }
    else {
      stmt_goto_flow_state(pcVar21,1);
    }
    pcVar24 = tree_new_symbol_ref(pcVar21,'\0');
    il_emit_tuple(0x3a,pcVar24);
    iVar53 = parse_error_recovery_count();
    if (iVar53 == 0) {
      arena_reset(5);
    }
LAB_10422a54:
    g_string_literal_cur = &g_string_literal_buffer;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x14a:
    il_emit_line_record_24();
    asm_block_emit();
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x14b:
    eh_except_end();
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x14c:
    eh_finally_begin();
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x14d:
    eh_finally_end();
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x14f:
    diag_error(0xb5);
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x152:
    goto switchD_10421905_caseD_14f;
  case 0x153:
    parse_yyerrok(parser);
    g_yy_lookahead = (byte *)0x0;
    uVar55 = 0x7b;
LAB_1046653f:
    pcVar26 = token_static_for_code(uVar55);
    token_source_unget((c1_token_reader *)&g_token_position,pcVar26);
    lVar44 = g_enum_value;
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
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x155:
    pending_top_mark();
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x156:
    eh_check_try_has_catch();
    lVar44 = g_enum_value;
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
      lVar44 = g_enum_value;
      if ((pcVar38->spec).spec[0] != '\0') {
        g_yylval = CONCAT31(g_yylval._1_3_,0xaa);
        pcVar28 = arena_or_pool_alloc(0x30,4);
        if (pcVar28 == (c1_u8 *)0x0) goto LAB_104671eb;
        g_yy_lookahead = token_init(pcVar28,'u',&g_yylval);
        lVar44 = g_enum_value;
      }
    }
    else {
      diag_error(0x13f);
      lVar44 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0x15a:
    scope_end_and_flush_pending_top(pcVar13[-1].spec.spec[0]);
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x15b:
    decl_pop_declarator_state(pcVar38->params);
    cVar10 = eh_check_catch_type_count(pcVar38->params);
    value_base[1].spec.spec[0] = cVar10;
    vtable_nop();
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x15c:
    diag_error(0x135);
    lVar44 = g_enum_value;
switchD_10421905_caseD_14f:
    g_enum_value = lVar44;
    parse_yyerrok(parser);
LAB_104671eb:
    g_yy_lookahead = (byte *)0x0;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x15f:
    parse_paren_depth_pop();
    value_base[1].words[0] = 1;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x160:
    parse_paren_depth_pop();
    value_base[1].words[0] = 2;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x161:
    eh_try_begin();
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x162:
    eh_try_block_end();
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x163:
    eh_except_filter_begin();
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x164:
    eh_except_emit_filter(pcVar13->node);
    eh_except_filter_end();
    parse_paren_depth_pop();
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x169:
    expr_warn_no_effect(pcVar38->node,'\0');
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x16a:
    pcVar31 = (c1_declarator *)0x0;
    g_pending_access_check[g_paren_depth] = (c1_symbol *)0x0;
    if (pcVar38->declarator != (c1_declarator *)0x0) {
      pcVar21 = decl_declarator_symbol(pcVar38->declarator);
      if (pcVar21 == (c1_symbol *)0x0) goto LAB_10467c7c;
      pcVar21 = decl_declarator_symbol(pcVar38->declarator);
      pvVar23 = (void *)sym_name(pcVar21);
      pcVar24 = expr_lookup_name_expression(pvVar23);
      value_base[1].node = pcVar24;
      lVar44 = g_enum_value;
      goto switchD_10421905_caseD_1;
    }
    goto LAB_10467c7c;
  case 0x16b:
    g_case_label = (c1_node *)0x0;
    goto switchD_10421905_caseD_1;
  case 0x16d:
    stmt_define_label(pcVar13->words[0]);
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x16e:
    if ((pcVar13[-1].node == (c1_node *)0x0) || (g_switch_case_stack == (c1_switch_cases_cell *)0x0)
       ) {
      diag_error(0x2e);
      lVar44 = g_enum_value;
    }
    else {
      pcVar24 = expr_resolve_address_of_overload(pcVar13[-1].node);
      stmt_case_label(pcVar24);
      lVar44 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0x16f:
    if (g_default_label_stack == (c1xx_label_cell *)0x0) {
      diag_error(0x2f);
      lVar44 = g_enum_value;
    }
    else if (g_default_label_stack->label == (c1_node *)0x0) {
      if (g_case_label == (c1_node *)0x0) {
        pcVar24 = label_new(0x14);
        g_default_label_stack->label = pcVar24;
        g_case_label = g_default_label_stack->label;
        label_emit_definition(g_default_label_stack->label);
        stmt_default_label_flow_state();
        lVar44 = g_enum_value;
      }
      else {
        g_default_label_stack->label = g_case_label;
        stmt_default_label_flow_state();
        lVar44 = g_enum_value;
      }
    }
    else {
      diag_error(0x30);
      lVar44 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0x170:
    parse_begin_compound_value(pcVar13->node);
    value_base[1].words[0] = pcVar13->words[0];
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x171:
    parse_begin_compound_value((c1_node *)0x0);
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] | 0x80;
    func_flow_state_note_11();
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x172:
    pcVar24 = label_new(0x1e);
    value_base[1].node = pcVar24;
    if (pcVar13->node != (c1_node *)0x0) {
      pcVar24 = expr_resolve_address_of_overload(pcVar13->node);
      pcVar13->node = pcVar24;
      pcVar24 = stmt_check_controlling_expression(pcVar24,0);
      pcVar13->node = pcVar24;
      stmt_emit_condition(pcVar24,value_base[1].node,0);
    }
    stmt_if_then_begin_flow_state();
    parse_paren_depth_pop();
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfe;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x173:
    func_end_compound_statement(pcVar13[-1].node,'\0');
    stmt_else_begin_flow_state();
    pcVar24 = label_new(0x1e);
    il_emit_tuple(0x3a,pcVar24);
    label_emit_definition(pcVar13[-1].node);
    il_emit_line_record_24();
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfe;
    acStack_24[1] = 0x10422c59;
    parse_begin_compound_value(pcVar24);
    value_base[1].node = pcVar24;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x177:
    value_base[1].spec.spec[0] = (pcVar38->spec).spec[0];
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x178:
    if (g_ms_extensions == '\0') {
      cVar10 = parse_begin_compound_value((c1_node *)0x0);
      (pcVar38->spec).spec[0] = cVar10;
    }
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] | 0x80;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x179:
    if (pcVar13->node != (c1_node *)0x0) {
      cVar9 = '\x01';
      pcVar24 = expr_resolve_address_of_overload(pcVar13->node);
      pcVar24 = expr_warn_no_effect(pcVar24,cVar9);
      pcVar13->node = pcVar24;
      pcVar24 = expr_full_expression_guarded(pcVar24,2);
      stmt_emit_expression(pcVar24);
    }
    iVar53 = parse_error_recovery_count();
    if (iVar53 == 0) {
      arena_reset(5);
    }
    g_string_literal_cur = &g_string_literal_buffer;
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] | 2;
    func_flow_state_note_25();
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x17a:
    pcVar24 = stmt_check_controlling_expression(pcVar13->node,0);
    pcVar13->node = pcVar24;
    func_flow_state_note_27();
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x17b:
    cVar9 = '\x01';
    pcVar24 = expr_resolve_address_of_overload(pcVar13[-1].node);
    pcVar24 = expr_warn_no_effect(pcVar24,cVar9);
    pcVar13[-1].node = pcVar24;
    stmt_for_head((c1_node *)0x0,pcVar13[-4].node,pcVar24);
    if ((pcVar13->spec).spec[0] != '\0') {
      diag_error(0x3b);
    }
    parse_paren_depth_pop();
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfc;
    func_flow_state_note_2a();
    lVar44 = g_enum_value;
    if (g_ms_extensions != '\0') {
      cVar10 = parse_begin_compound_value((c1_node *)0x0);
      pcVar13[-9].spec.spec[0] = cVar10;
      lVar44 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0x17c:
    cVar10 = parse_begin_compound_value((c1_node *)0x0);
    (pcVar38->spec).spec[0] = cVar10;
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] | 0x80;
    func_flow_state_note_19();
    stmt_while_head();
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x17d:
    cVar9 = '\0';
    pcVar24 = expr_resolve_address_of_overload(pcVar13->node);
    pcVar24 = expr_warn_no_effect(pcVar24,cVar9);
    pcVar13->node = pcVar24;
    pcVar24 = stmt_check_controlling_expression(pcVar24,0);
    pcVar13->node = pcVar24;
    stmt_emit_loop_test(pcVar24);
    parse_paren_depth_pop();
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfe;
    func_flow_state_note_1c();
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x17e:
    cVar10 = parse_begin_compound_value((c1_node *)0x0);
    (pcVar38->spec).spec[0] = cVar10;
    func_flow_state_note_31();
    lVar44 = g_enum_value;
  case 0x1b0:
    g_enum_value = lVar44;
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] | 3;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x180:
    pcVar24 = expr_resolve_address_of_overload(pcVar13[-2].node);
    stmt_switch_head((int)pcVar24);
    lVar44 = g_enum_value;
switchD_10421905_caseD_6f:
    g_enum_value = lVar44;
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfc;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x181:
    cVar9 = '\0';
    pcVar24 = expr_resolve_address_of_overload(pcVar38->node);
    pcVar24 = expr_warn_no_effect(pcVar24,cVar9);
    cVar45 = (c1_decl_modifier)expr_eval_constant_expression(pcVar24);
    value_base[1].mods = cVar45;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x183:
    cVar9 = '\0';
    pcVar24 = expr_resolve_address_of_overload(pcVar38->node);
    pcVar24 = expr_warn_no_effect(pcVar24,cVar9);
    value_base[1].node = pcVar24;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x184:
  case 0x19a:
    pcVar24 = expr_build_binary((pcVar13->spec).spec[0],pcVar13[-1].node,pcVar38->node);
    value_base[1].node = pcVar24;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x185:
    pcVar24 = expr_build_zero_pair();
    value_base[1].node = pcVar24;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x186:
    pcVar24 = expr_build_throw(pcVar38->node);
    value_base[1].node = pcVar24;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x187:
    if ((pcVar13[-1].declarator != (c1_declarator *)0x0) &&
       (pcVar24 = pcVar38->node, pcVar24 != (c1_node *)0x0)) {
      pcVar22 = decl_declarator_record(pcVar13[-1].declarator);
      pcVar24 = expr_resolve_function_address(pcVar22,pcVar24);
joined_r0x104676a9:
      if (pcVar24 == (c1_node *)0x0) {
        expr_report_function_operand('4',pcVar38->node);
      }
      goto LAB_10422ec5;
    }
    break;
  case 0x188:
    if ((pcVar13[-1].declarator != (c1_declarator *)0x0) &&
       (pcVar24 = pcVar38->node, pcVar24 != (c1_node *)0x0)) {
      pcVar22 = decl_declarator_record(pcVar13[-1].declarator);
      pcVar24 = expr_resolve_function_address(pcVar22,pcVar24);
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
    pcVar24 = pcVar38->node;
LAB_10422ec5:
    pcVar24 = expr_build_binary((pcVar13->spec).spec[0],pcVar13[-1].node,pcVar24);
    value_base[1].node = pcVar24;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x18a:
    pcVar24 = expr_build_conditional(pcVar13[-3].node,pcVar13[-1].node,pcVar38->node);
    value_base[1].node = pcVar24;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x18b:
  case 0x18d:
    if (pcVar13->words[0] != 0) {
      func_flow_state_note_3e();
      lVar44 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0x18c:
  case 0x18e:
    pcVar24 = expr_build_binary(pcVar13[-1].spec.spec[0],pcVar13[-2].node,pcVar38->node);
    value_base[1].node = pcVar24;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x199:
    pcVar24 = expr_check_based_operator(pcVar13[-1].node,pcVar38->node);
    value_base[1].node = pcVar24;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x19d:
    g_compile_flags_c8 = g_compile_flags_c8 | 1;
    pcVar24 = pcVar38->node;
    cVar29 = pcVar13->words[0];
    uVar47 = (undefined1)cVar29;
    uVar49 = (undefined1)(cVar29 >> 8);
    uVar50 = (undefined2)(cVar29 >> 0x10);
    cVar10 = 'd';
LAB_10422f46:
    g_enum_value = lVar44;
    pcVar24 = expr_build_cast(cVar10,(c1_symbol *)CONCAT22(uVar50,CONCAT11(uVar49,uVar47)),pcVar24);
    value_base[1].node = pcVar24;
    g_compile_flags_c8 = g_compile_flags_c8 & 0xfffffffe;
    tree_clear_value_link(value_base[1].node);
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x19e:
    goto switchD_10421905_caseD_19b;
  case 0x19f:
    (pcVar13->spec).spec[0] = ((pcVar13->spec).spec[0] == '@') + 'T';
    pcVar24 = tree_new_int_constant(1);
    pcVar24 = expr_build_binary((pcVar13->spec).spec[0],pcVar38->node,pcVar24);
    value_base[1].node = pcVar24;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1a0:
    cVar29 = expr_build_unary(0x3d,pcVar38->node);
    value_base[1].words[0] = cVar29;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1a1:
    pcVar21 = pcVar38->sym;
    if (pcVar21 == (c1_symbol *)0x0) {
      value_base[1].words[0] = 0;
      lVar44 = g_enum_value;
    }
    else if ((pcVar21->kind == '=') && ((c1_symbol *)pcVar21->type != (c1_symbol *)0x0)) {
      pcVar24 = expr_address_of_member((c1_symbol *)pcVar21->type);
      value_base[1].node = pcVar24;
      lVar44 = g_enum_value;
    }
    else {
      if ((pcVar21->kind == 'S') && ((((c1_node *)pcVar21->type)->kind & 7) == 4)) {
        iVar53 = yyparse_cpp_address_of_member_leaf
                           ((c1_node *)pcVar21->type,value_base,pcVar38,parser,state_sp,
                            saved_lookahead,saved_rule);
        return iVar53;
      }
      g_compile_flags_c8 = g_compile_flags_c8 | 4;
      cVar29 = expr_build_unary(0x31,pcVar38->node);
      value_base[1].words[0] = cVar29;
      g_compile_flags_c8 = g_compile_flags_c8 & 0xfffffffb;
      lVar44 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0x1a2:
    pcVar24 = (c1_node *)expr_build_unary(0x86,pcVar38->node);
    value_base[1].node = pcVar24;
    tree_clear_value_link(pcVar24);
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1a3:
    cVar29 = expr_build_unary(0x5a,pcVar38->node);
    value_base[1].words[0] = cVar29;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1a4:
    cVar29 = expr_build_unary(0x3c,pcVar38->node);
    value_base[1].words[0] = cVar29;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1a6:
    cVar29 = expr_build_unary(0x59,pcVar38->node);
    value_base[1].words[0] = cVar29;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1a7:
    (*g_idb->vtbl->idb_note_sizeof)(g_idb);
    if (pcVar38->node == (c1_node *)0x0) {
      value_base[1].words[0] = 0;
      g_sizeof_depth = g_sizeof_depth + -1;
      lVar44 = g_enum_value;
    }
    else {
      pcVar24 = expr_build_sizeof(pcVar38->node);
      value_base[1].node = pcVar24;
      g_sizeof_depth = g_sizeof_depth + -1;
      lVar44 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0x1a8:
    (*g_idb->vtbl->idb_note_sizeof)(g_idb);
    pcVar24 = expr_sizeof_type(pcVar38->sym->type);
    value_base[1].node = pcVar24;
    g_sizeof_depth = g_sizeof_depth + -1;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1ad:
    cVar29 = expr_build_unary(0xf0,pcVar13->node);
    value_base[1].words[0] = cVar29;
    parse_paren_depth_pop();
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1af:
    g_member_access_op = '\x01';
    if ((pcVar13->node != (c1_node *)0x0) && (pcVar13->node->op == '7')) {
      diag_warning(4,0x2c5);
    }
    pcVar24 = expr_build_binary(pcVar13[-1].spec.spec[0],pcVar13[-2].node,pcVar13->node);
    value_base[1].node = pcVar24;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1b1:
    pcVar24 = pcVar13[-1].node;
    if ((pcVar24 != (c1_node *)0x0) && ((pcVar24->kind & 0x88) == 0)) {
      if ((g_compile_flags_c8 & 0x800000) != 0) {
        if (pcVar38->node != (c1_node *)0x0) {
          diag_error(0x209);
          pcVar24 = tree_new_zero_flagged();
        }
        value_base[1].node = pcVar24;
        g_compile_flags_c8 = g_compile_flags_c8 & 0xff7fffff;
        g_member_access_op = '\x01';
        lVar44 = g_enum_value;
        goto switchD_10421905_caseD_1;
      }
      pcVar24 = (c1_node *)expr_build_call(pcVar24,pcVar38->node);
    }
    value_base[1].node = pcVar24;
    lVar44 = g_enum_value;
switchD_10421905_caseD_19b:
    g_member_access_op = '\x01';
    goto switchD_10421905_caseD_1;
  case 0x1b4:
    g_member_access_op = '\x01';
    pcVar24 = tree_new_int_constant(1);
    pcVar24 = expr_build_binary((pcVar38->spec).spec[0],pcVar13->node,pcVar24);
    value_base[1].node = pcVar24;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1b5:
    g_member_access_op = '\x01';
    pcVar24 = class_check_operator_global_form
                        (CONCAT22((short)((uint)g_yy_lookahead >> 0x10),
                                  CONCAT11((char)((uint)g_yy_lookahead >> 8),(pcVar13->spec).spec[0]
                                          )),pcVar38->node);
    value_base[1].node = pcVar24;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1b6:
    if ((pcVar38->spec).spec[0] != 'D') {
      diag_error(0x2f8);
    }
    parse_paren_depth_push(1);
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1b7:
    if ((pcVar38->spec).spec[0] != 0xbf) {
      iVar53 = yyparse_cpp_named_cast_expected_gt
                         ((pcVar38->spec).spec[0],value_base,parser,state_sp,saved_lookahead,
                          saved_rule);
      return iVar53;
    }
    goto LAB_104232f5;
  case 0x1b8:
    if (pcVar38->words[0] != 0) {
      g_compile_flags_c8 = g_compile_flags_c8 | 1;
      pcVar24 = pcVar38->node;
      pcVar21 = parse_type_id_declarator(pcVar13[-2].declarator,&pcVar13[-3].spec);
      uVar47 = SUB41(pcVar21,0);
      uVar49 = (undefined1)((uint)pcVar21 >> 8);
      uVar50 = (undefined2)((uint)pcVar21 >> 0x10);
      cVar10 = pcVar13[-6].spec.spec[0];
      lVar44 = g_enum_value;
      goto LAB_10422f46;
    }
    break;
  case 0x1b9:
    pcVar24 = expr_build_typeid_expression(pcVar13->node);
    value_base[1].node = pcVar24;
    parse_paren_depth_pop();
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1ba:
    pcVar21 = (c1_symbol *)decl_finish_declarator_then_type(pcVar13->ptr,(byte *)pcVar13[-1].words);
    goto LAB_104232f2;
  case 0x1bb:
    pcVar24 = expr_build_uuidof_expression(pcVar13->node);
    value_base[1].node = pcVar24;
    parse_paren_depth_pop();
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1bc:
    pcVar21 = decl_finish_declarator_uuidof(pcVar13->ptr,(byte *)pcVar13[-1].words);
    goto LAB_104232f2;
  case 0x1bd:
    parse_paren_depth_pop();
    value_base[1].words[0] = pcVar13->words[0];
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1be:
    value_base[1].words[0] = 0;
    parse_report_inserted_token(g_yy_lookahead,0x76);
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1bf:
    pcVar24 = tree_new_constant(pcVar38->type,(void *)((int)pcVar13 + 0x30),g_expr_arena_index);
    value_base[1].node = pcVar24;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1c1:
    type_string_literal_array(pcVar38->node);
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1c2:
    pcVar24 = expr_check_this_usage();
    value_base[1].node = pcVar24;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1c3:
    pcVar24 = expr_build_builtin_unary(0x76,pcVar13->node);
    value_base[1].node = pcVar24;
    tree_clear_value_link(pcVar24);
    parse_paren_depth_pop();
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1c5:
    PTR_104d2158 = expr_prepare_member_access_object
                             (g_current_scope,(pcVar38->spec).spec[0],pcVar13->node,'\0');
    g_member_access_op = (pcVar38->spec).spec[0];
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1c6:
    pcVar24 = expr_build_member_access(g_member_access_op,PTR_104d2158,pcVar38->node);
    value_base[1].node = pcVar24;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1c7:
    pcVar24 = expr_build_pseudo_destructor_call(g_member_access_op,PTR_104d2158,pcVar38->words[0]);
    value_base[1].node = pcVar24;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1c8:
    pcVar21 = value_word0(pcVar38->cell);
    pcVar24 = expr_build_pseudo_destructor_call(g_member_access_op,PTR_104d2158,(int)pcVar21);
    value_base[1].node = pcVar24;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1c9:
    pfVar30 = sym_name_of_ref(pcVar38->cell);
    pcVar24 = expr_build_pseudo_destructor_call(g_member_access_op,PTR_104d2158,(int)pfVar30);
    value_base[1].node = pcVar24;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1ca:
    pcVar24 = expr_check_qualified_pseudo_destructor
                        (g_member_access_op,PTR_104d2158,&pcVar13[-2].spec,&pcVar38->spec);
    value_base[1].node = pcVar24;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1cb:
    pcVar24 = expr_lookup_name_expression(pcVar38->ptr);
    value_base[1].node = pcVar24;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1cc:
    pvVar23 = decl_declarator_record(pcVar38->declarator);
    if (pvVar23 == (void *)0x0) {
      pcVar21 = (c1_symbol *)sym_name(pcVar38->sym);
      pcVar24 = sym_is_data_or_function(pcVar21);
      value_base[1].node = pcVar24;
      lVar44 = g_enum_value;
    }
    else {
      pcVar21 = (c1_symbol *)sym_name(pcVar38->sym);
      pcVar24 = sym_is_data_or_function(pcVar21);
      if (pcVar24->right != (void *)0x0) {
        diag_fatal(1);
      }
      pvVar23 = value_fieldc(pcVar38->ptr);
      pcVar24->right = pvVar23;
      value_base[1].node = pcVar24;
      lVar44 = g_enum_value;
    }
    goto switchD_10421905_caseD_1;
  case 0x1cd:
    pcVar21 = value_word0(pcVar38->cell);
    pcVar24 = sym_is_data_or_function(pcVar21);
    value_base[1].node = pcVar24;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1ce:
    pcVar24 = expr_lookup_name_expression(*(void **)((int)pcVar13 + 0x2c));
    value_base[1].node = pcVar24;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1cf:
    pfVar30 = decl_conversion_function_name(*(c1_type **)((int)pcVar13 + 0x40));
    pcVar24 = expr_lookup_name_expression(pfVar30);
    value_base[1].node = pcVar24;
    g_compile_flags_c4 = g_compile_flags_c4 & 0xfffffffb;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1d0:
    pcVar21 = value_word0(pcVar38->cell);
    lVar44 = g_enum_value;
    if ((pcVar21->flags3 & 4) == 0) {
      pcVar21 = value_word0(pcVar38->cell);
      pcVar24 = sym_is_data_or_function(pcVar21);
      pvVar23 = decl_declarator_record(pcVar38->declarator);
      if (pvVar23 != (void *)0x0) {
        if (pcVar24->right != (void *)0x0) {
          diag_fatal(1);
        }
        pvVar23 = decl_declarator_record(pcVar38->declarator);
        pcVar24->right = pvVar23;
      }
      value_base[1].node = pcVar24;
      lVar44 = g_enum_value;
      goto switchD_10421905_caseD_1;
    }
    break;
  case 0x1d1:
    if (pcVar13->cell != (c1_symbol **)0x0) {
      pcVar22 = *(c1_type **)((int)pcVar13 + 0x40);
      pcVar21 = value_word0(pcVar13->cell);
      decl_qualified_conversion_function_name(pcVar21,pcVar22);
      pcVar21 = value_word0(pcVar13->cell);
      pcVar24 = sym_is_data_or_function(pcVar21);
      pvVar23 = decl_declarator_record(pcVar13->declarator);
      if (pvVar23 != (void *)0x0) {
        if (pcVar24->right != (void *)0x0) {
          diag_fatal(1);
        }
        pvVar23 = decl_declarator_record(pcVar13->declarator);
        pcVar24->right = pvVar23;
      }
      value_base[1].node = pcVar24;
    }
    g_compile_flags_c4 = g_compile_flags_c4 & 0xfffffffb;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1d3:
    pcVar21 = parse_type_id_declarator(pcVar13->declarator,&pcVar13[-1].spec);
LAB_104232f2:
    value_base[1].sym = pcVar21;
    lVar44 = g_enum_value;
LAB_104232f5:
    g_enum_value = lVar44;
    parse_paren_depth_pop();
LAB_104232fa:
    g_declarator_paren_base = g_declarator_paren_base + -1;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1d4:
    value_base[1].words[0] = pcVar13->words[0];
    parse_paren_depth_pop();
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1d5:
  case 0x1ea:
    value_base[1].words[0] = 0;
    parse_paren_depth_pop();
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1d6:
    pcVar24 = tree_append_list_item((c1_node *)0x0,pcVar38->node,0);
    value_base[1].node = pcVar24;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1d7:
    pcVar24 = tree_append_list_item(pcVar13[-1].node,pcVar38->node,0);
    value_base[1].node = pcVar24;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1d8:
    pcVar24 = arena_alloc(g_arenas + g_expr_arena_index,0x18);
    pcVar24->kind = '\x05';
    pcVar24->op = '\a';
    pcVar24->left = (void *)pcVar38->words[0];
    pcVar24->right = *(void **)((int)pcVar13 + 0x2c);
    value_base[1].node = pcVar24;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1d9:
    lex_concatenate_strings((c1_string_value *)(pcVar13->declarator->spec + 4),&pcVar38->str);
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1da:
    parse_paren_depth_pop();
    g_compile_flags_c8 = g_compile_flags_c8 & 0xffffffef;
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] | 2;
    g_compile_flags_c4 = g_compile_flags_c4 & 0x7fffffff;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1db:
    pcVar32 = decl_declarator_record(pcVar13->declarator);
    pcVar24 = decl_record_new_array_bound(pcVar32);
    cVar29 = pcVar38->words[0];
    uVar47 = (undefined1)cVar29;
    uVar49 = (undefined1)(cVar29 >> 8);
    uVar50 = (undefined2)(cVar29 >> 0x10);
    pcVar21 = sym_new_from_declarator(pcVar13->declarator,0xffffffff);
    pcVar24 = expr_build_new_or_placeholder
                        (pcVar13[-1].spec.spec[0],0,pcVar21,CONCAT22(uVar50,CONCAT11(uVar49,uVar47))
                         ,(int)pcVar24);
    value_base[1].node = pcVar24;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1dc:
    pcVar32 = decl_declarator_record(pcVar13->declarator);
    pcVar24 = decl_record_new_array_bound(pcVar32);
    cVar29 = pcVar38->words[0];
    uVar47 = (undefined1)cVar29;
    uVar49 = (undefined1)(cVar29 >> 8);
    uVar50 = (undefined2)(cVar29 >> 0x10);
    pcVar21 = sym_new_from_declarator(pcVar13->declarator,0xffffffff);
    pcVar24 = expr_build_new_or_placeholder
                        (pcVar13[-1].spec.spec[0],0,pcVar21,CONCAT22(uVar50,CONCAT11(uVar49,uVar47))
                         ,(int)pcVar24);
    value_base[1].node = pcVar24;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1dd:
  case 0x1de:
    pcVar32 = decl_declarator_record(pcVar13->declarator);
    pcVar24 = decl_record_new_array_bound(pcVar32);
    cVar29 = pcVar38->words[0];
    uVar47 = (undefined1)cVar29;
    uVar49 = (undefined1)(cVar29 >> 8);
    uVar50 = (undefined2)(cVar29 >> 0x10);
    pcVar21 = sym_new_from_declarator(pcVar13->declarator,0xffffffff);
    pcVar24 = expr_build_new_or_placeholder
                        (pcVar13[-2].spec.spec[0],pcVar13[-1].words[0],pcVar21,
                         CONCAT22(uVar50,CONCAT11(uVar49,uVar47)),(int)pcVar24);
    value_base[1].node = pcVar24;
    lVar44 = g_enum_value;
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
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1e1:
    decl_set_local_key_flag(pcVar38->declarator,'\x01');
    (pcVar13->spec).spec[0] = (pcVar13->spec).spec[0] & 0x7f;
    pcVar37 = pcVar13;
    pcVar32 = decl_declarator_record(pcVar38->declarator);
    decl_check_conversion_return_type(pcVar32,&pcVar37->spec);
    pcVar32 = decl_declarator_record(pcVar38->declarator);
    decl_allow_variable_array_bound(pcVar32);
    pcVar32 = decl_declarator_record(pcVar38->declarator);
    decl_finish_declarator(pcVar32);
    decl_declarator_set_specifiers(pcVar38->declarator,&pcVar13->spec);
    decl_process_declaration(pcVar38->declarator);
    pcVar22 = (c1_type *)sym_name(pcVar38->sym);
    iVar53 = type_chain_is_cv_qualified(pcVar22);
    if ((char)iVar53 == '\0') {
      pcVar22 = (c1_type *)sym_name(pcVar38->sym);
      cVar10 = type_is_void(pcVar22);
      if (cVar10 != '\0') {
        diag_error(0x1d5);
      }
    }
    else {
      sym_name(pcVar38->sym);
      diag_error(0x1d4);
    }
    g_declarator_paren_base = g_declarator_paren_base + -1;
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfe;
    value_base[1].ptr = (void *)pcVar38->words[0];
    lVar44 = g_enum_value;
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
    pvVar23 = decl_declarator_record(pcVar38->declarator);
    d_00 = decl_declarator_record(pcVar31);
    decl_set_name(d_00,pvVar23);
    pcVar32 = decl_declarator_record(pcVar31);
    decl_finish_declarator(pcVar32);
    decl_process_declaration(pcVar31);
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfe;
    value_base[1].declarator = pcVar31;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1e3:
    pcVar31 = pcVar13->declarator;
    decl_set_local_key_flag(pcVar31,'\x01');
    declarator_set_kind(pcVar31,4);
    decl_set_name(pcVar31,g_name_new_target);
    pcVar38 = pcVar13 + -1;
    (pcVar38->spec).spec[0] = pcVar13[-1].spec.spec[0] & 0x7f;
    decl_declarator_set_specifiers(pcVar31,&pcVar38->spec);
    pcVar32 = decl_declarator_record(pcVar31);
    decl_check_conversion_return_type(pcVar32,&pcVar38->spec);
    pcVar32 = decl_declarator_record(pcVar31);
    decl_allow_variable_array_bound(pcVar32);
    pcVar32 = decl_declarator_record(pcVar31);
    decl_finish_declarator(pcVar32);
    decl_process_declaration(pcVar31);
    cVar10 = type_is_cv_qualified_stripped(pcVar31);
    if (cVar10 == '\0') {
      pcVar22 = (c1_type *)sym_name((c1_symbol *)pcVar31);
      cVar10 = type_is_void(pcVar22);
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
    lVar44 = g_enum_value;
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
    lVar44 = g_enum_value;
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
    type_check_based_form(pcVar32,&pcVar38->mods);
    g_declarator_paren_base = g_declarator_paren_base + 1;
LAB_10467c7c:
    value_base[1].declarator = pcVar31;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1e7:
    if ((pcVar13->node != (c1_node *)0x0) && (pcVar13->node->op == '7')) {
      diag_warning(4,0x2c5);
    }
    pcVar24 = pcVar13->node;
    pvVar23 = decl_declarator_record(value_base[1].declarator);
    type_check_array_bound_constant_2(pvVar23,pcVar24);
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1eb:
    pcVar24 = expr_build_delete((pcVar13->spec).spec[0],pcVar38->node,(c1_node *)0x0,'\0');
    value_base[1].node = pcVar24;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  case 0x1ec:
    if ((pcVar13[-1].node != (c1_node *)0x0) && ((pcVar13[-1].node)->op == '7')) {
      diag_warning(4,0x2c5);
    }
    pcVar24 = expr_build_delete(pcVar13[-3].spec.spec[0],pcVar38->node,pcVar13[-1].node,'\x01');
    value_base[1].node = pcVar24;
    lVar44 = g_enum_value;
    goto switchD_10421905_caseD_1;
  }
  g_enum_value = lVar44;
  value_base[1].words[0] = 0;
  lVar44 = g_enum_value;
  goto switchD_10421905_caseD_1;
switchD_10421905_caseD_12c:
  if (((((g_block_depth == '\0') || (-1 < g_class_depth)) ||
       ((g_compile_flags_c8 & 0x10000000) != 0)) ||
      ((((g_compile_flags_c8 & 0x40000000) != 0 && ((g_compile_flags_cc & 8) == 0)) &&
       ((g_compile_flags_c4 & 0x200) == 0)))) || ((g_compile_flags_cc & 0x50) != 0)) {
    iVar53 = 0;
  }
  else {
    iVar53 = 4;
  }
  goto LAB_104225ad;
switchD_10421905_caseD_12b:
  if (((g_block_depth == '\0') || (-1 < g_class_depth)) || ((g_compile_flags_c8 & 0x10000000) != 0))
  goto code_r0x104225db;
  if ((((g_compile_flags_c8 & 0x40000000) != 0) && ((g_compile_flags_cc & 8) == 0)) &&
     ((g_compile_flags_c4 & 0x200) == 0)) {
    iVar53 = yyparse_cpp_ellipsis_parameter_arena0
                       (value_base,parser,state_sp,saved_lookahead,saved_rule);
    return iVar53;
  }
  if ((g_compile_flags_cc & 0x50) != 0) goto code_r0x104225db;
  iVar53 = 4;
  goto LAB_104225ad;
}

