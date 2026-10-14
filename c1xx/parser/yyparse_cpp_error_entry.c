int __cdecl
yyparse_cpp_error_entry
          (int action,c1_yy_value *value_sp,int *state_sp,int state,c1_yy_parser *parser,
          c1_yy_action_slot action_slot,byte *saved_lookahead,int saved_rule)

{
  ushort *puVar1;
  ushort uVar2;
  short sVar3;
  c1_scope_body cVar4;
  c1xx_il_emitter_vtbl *pcVar5;
  c1_u32 cVar6;
  c1_arg_value cVar7;
  c1_node *pcVar8;
  uint uVar9;
  char cVar10;
  c1_u8 cVar11;
  byte bVar12;
  c1_u16 bits;
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
  void *pvVar22;
  c1_node *pcVar23;
  int iVar24;
  int iVar25;
  c1_line_map_row *pcVar26;
  c1xx_token_stream *stream;
  c1xx_token *pcVar27;
  uint *puVar28;
  c1_lookup_entry *cell;
  c1_u8 *pcVar29;
  c1_u32 cVar30;
  fe_name *pfVar31;
  c1_symbol *pcVar32;
  c1_declarator *d_00;
  c1_type *pcVar33;
  c1_declarator *pcVar34;
  c1_decl_record *pcVar35;
  c1_arena *a;
  uint uVar36;
  undefined4 extraout_ECX;
  short *psVar37;
  c1_yy_value *pcVar38;
  undefined2 uVar41;
  c1xx_idb_vtbl *pcVar39;
  c1_yy_value *pcVar40;
  c1_u32 *pcVar42;
  int state_00;
  void **ppvVar43;
  undefined4 *puVar44;
  bool bVar45;
  longlong lVar46;
  c1_decl_modifier cVar47;
  c1_yy_value *in_stack_00000014;
  int *state_sp_00;
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
  undefined1 uVar48;
  undefined1 uVar49;
  undefined1 uVar50;
  undefined1 uVar51;
  undefined2 uVar52;
  c1_symbol **ppcVar53;
  c1xx_decl_specifiers *pcVar54;
  c1_symbol *qualifier;
  c1_yy_value *spec;
  c1_overload_set *pcVar55;
  uint uVar56;
  
  g_yy_n = action;
  g_yy_state = state;
  g_yy_ps = state_sp;
  g_yy_pv = value_sp;
  iVar24 = yyparse_cpp_error_recovery(parser);
  pcVar14 = g_yy_pv;
  iVar25 = g_yy_state;
  state_sp_00 = g_yy_ps;
  if (iVar24 == 0) goto LAB_1042188d;
  if (iVar24 != 1) {
    piVar20 = g_yy_ps;
    state_00 = g_yy_state;
    if (iVar24 != 2) {
      iVar25 = parse_yacc_return_tail(saved_lookahead,saved_rule);
      return iVar25;
    }
    while (sVar3 = g_yy_pact[state_00], state_sp_00 = piVar20, sVar3 < -999) {
LAB_104218b7:
      iVar25 = (int)g_yy_def[state_00];
      lVar46 = g_enum_value;
      if (iVar25 < 1) {
        if (iVar25 == -2) {
          piVar20 = state_sp_00;
          if (g_yy_lookahead == (byte *)0x0) {
            g_yy_lookahead = yylex_cpp();
            piVar20 = state_sp_00;
            lVar46 = g_enum_value;
          }
          psVar37 = g_yy_exca + g_yy_exca_index[state_00];
          uVar2 = g_yy_exca[g_yy_exca_index[state_00]];
          while ((uVar2 != g_token_class[*g_yy_lookahead] && (-1 < (short)uVar2))) {
            puVar1 = (ushort *)(psVar37 + 2);
            psVar37 = psVar37 + 2;
            uVar2 = *puVar1;
          }
          iVar25 = (int)psVar37[1];
          state_sp_00 = piVar20;
          if (iVar25 < 0) {
            g_yy_result = 0;
            g_enum_value = lVar46;
            iVar25 = parse_yacc_return_tail(saved_lookahead,saved_rule);
            return iVar25;
          }
        }
        if (iVar25 == 0) {
          g_enum_value = lVar46;
          iVar25 = yyparse_cpp_error_entry
                             (0,pcVar14,piVar20,state_00,parser,action_slot,saved_lookahead,
                              saved_rule);
          return iVar25;
        }
      }
      iVar24 = g_paren_depth;
      pcVar27 = (c1xx_token *)g_yy_lookahead;
      g_enum_value._4_4_ = (undefined4)((ulonglong)lVar46 >> 0x20);
      g_enum_value._0_4_ = (undefined4)lVar46;
      uVar56 = (uint)g_yy_r2[iVar25];
      state_sp_00 = state_sp_00 + -uVar56;
      pcVar38 = pcVar14 + -uVar56;
      uVar41 = (undefined2)(uVar56 * -5 >> 0x10);
      g_yy_rule = iVar25;
      in_stack_00000014 = pcVar38;
      g_enum_value = lVar46;
      switch(iVar25) {
      case 3:
        iVar25 = parser->error_count;
LAB_104235dc:
        g_yy_result = iVar25;
        iVar25 = parse_yacc_return_tail(saved_lookahead,saved_rule);
        return iVar25;
      case 5:
        paren_depth_leave(pcVar14[-1].words[0]);
        lVar46 = g_enum_value;
        break;
      case 6:
        paren_depth_leave(0);
        lVar46 = g_enum_value;
        break;
      case 8:
        if ((g_yy_lookahead == (byte *)0x0) || (*g_yy_lookahead != 0x76)) {
          pcVar14 = pcVar14 + -1;
          pcVar54 = g_paren_level_declspecs + g_paren_depth;
          for (iVar25 = 9; iVar25 != 0; iVar25 = iVar25 + -1) {
            *(c1_u32 *)pcVar54->spec = pcVar14->words[0];
            pcVar14 = (c1_yy_value *)(pcVar14->words + 1);
            pcVar54 = (c1xx_decl_specifiers *)(pcVar54->spec + 4);
          }
          g_paren_level_flags[iVar24] = g_paren_level_flags[iVar24] | 1;
          lVar46 = g_enum_value;
        }
        else {
          pcVar14 = pcVar14 + -1;
          pcVar42 = (c1_u32 *)(&g_paren_level_declspecs_prev_base + g_paren_depth * 0x24);
          iVar24 = 9;
          iVar25 = g_paren_depth;
LAB_10420c2b:
          for (; g_enum_value = lVar46, iVar24 != 0; iVar24 = iVar24 + -1) {
            *pcVar42 = pcVar14->words[0];
            pcVar14 = (c1_yy_value *)(pcVar14->words + 1);
            pcVar42 = pcVar42 + 1;
            lVar46 = g_enum_value;
          }
          pbVar16 = (byte *)((int)&g_function_tuple_count + iVar25 + 3);
          *pbVar16 = *pbVar16 | 1;
          lVar46 = g_enum_value;
        }
        break;
      case 9:
        pcVar38 = pcVar14 + -2;
        g_declarator_paren_base = g_declarator_paren_base + -1;
        decl_check_conversion_return_type((pcVar14[-1].declarator)->decl,&pcVar38->spec);
        decl_finish_declarator((pcVar14[-1].declarator)->decl);
        pcVar40 = pcVar38;
        ppvVar43 = (void **)&(pcVar14[-1].node)->unk0c;
        for (iVar25 = 6; iVar25 != 0; iVar25 = iVar25 + -1) {
          *ppvVar43 = (void *)pcVar40->words[0];
          pcVar40 = (c1_yy_value *)(pcVar40->words + 1);
          ppvVar43 = ppvVar43 + 1;
        }
        (pcVar14[-1].declarator)->flags56 = (pcVar14[-1].declarator)->flags56 | 0x20;
        if (g_class_depth < 0) {
          if ((g_compile_flags_c8 & 0x40) == 0) {
            g_last_declared_symbol =
                 decl_declare_from_declarator(pcVar14[-1].declarator,(byte *)pcVar38->words);
          }
          else {
            g_last_declared_symbol = (pcVar14[-1].declarator)->sym;
          }
          bVar12 = g_current_scope->current->kind;
          if ((0xfa < bVar12) && (bVar12 != 0xfd)) {
            scope_pop_to_kind(g_current_scope,'\x01');
          }
          class_check_unnamed_class_member(&pcVar38->spec);
          pcVar38 = in_stack_00000014;
          lVar46 = g_enum_value;
        }
        else {
          (pcVar14[-1].declarator)->kind = 2;
          action_slot.sym = (c1_symbol *)0x0;
          cVar10 = class_begin_member_list(pcVar14[-1].declarator,&pcVar38->spec,&action_slot.sym);
          if (((cVar10 == '\0') && (bVar12 = g_current_scope->current->kind, 0xfa < bVar12)) &&
             (bVar12 != 0xfd)) {
            scope_pop_to_kind(g_current_scope,'\x01');
          }
          pcVar38 = in_stack_00000014;
          lVar46 = g_enum_value;
          if (action_slot.sym == (c1_symbol *)0x0) {
            g_last_declared_symbol = (pcVar14[-1].declarator)->sym;
          }
          else {
            g_last_declared_symbol = action_slot.sym;
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
        decl_check_conversion_return_type((pcVar14[-1].declarator)->decl,pcVar54);
        decl_finish_declarator((pcVar14[-1].declarator)->decl);
        if ((g_paren_level_flags[g_paren_depth] & 1) == 0) {
          pcVar54 = decl_specifiers_default((void *)0x0);
        }
        else {
          pcVar54 = g_paren_level_declspecs + g_paren_depth;
        }
        ppvVar43 = (void **)&(pcVar14[-1].node)->unk0c;
        for (iVar25 = 6; iVar25 != 0; iVar25 = iVar25 + -1) {
          *ppvVar43 = *(void **)pcVar54->spec;
          pcVar54 = (c1xx_decl_specifiers *)(pcVar54->spec + 4);
          ppvVar43 = ppvVar43 + 1;
        }
        (pcVar14[-1].declarator)->flags56 = (pcVar14[-1].declarator)->flags56 | 0x20;
        if (g_class_depth < 0) {
          if ((g_compile_flags_c8 & 0x40) == 0) {
            if ((g_paren_level_flags[g_paren_depth] & 1) == 0) {
              pcVar54 = decl_specifiers_default((void *)0x0);
              g_last_declared_symbol =
                   decl_declare_from_declarator(pcVar14[-1].declarator,pcVar54->spec);
            }
            else {
              g_last_declared_symbol =
                   decl_declare_from_declarator
                             (pcVar14[-1].declarator,g_paren_level_declspecs[g_paren_depth].spec);
            }
          }
          else {
            g_last_declared_symbol = (pcVar14[-1].declarator)->sym;
          }
          bVar12 = g_current_scope->current->kind;
          lVar46 = g_enum_value;
          if ((0xfa < bVar12) && (bVar12 != 0xfd)) {
            scope_pop_to_kind(g_current_scope,'\x01');
            lVar46 = g_enum_value;
          }
        }
        else {
          (pcVar14[-1].declarator)->kind = 2;
          action_slot.sym = (c1_symbol *)0x0;
          if ((g_paren_level_flags[g_paren_depth] & 1) == 0) {
            pcVar54 = decl_specifiers_default((void *)0x0);
          }
          else {
            pcVar54 = g_paren_level_declspecs + g_paren_depth;
          }
          cVar10 = class_begin_member_list(pcVar14[-1].declarator,pcVar54,&action_slot.sym);
          lVar46 = g_enum_value;
          if (((cVar10 == '\0') && (bVar12 = g_current_scope->current->kind, 0xfa < bVar12)) &&
             (bVar12 != 0xfd)) {
            scope_pop_to_kind(g_current_scope,'\x01');
            lVar46 = g_enum_value;
          }
          g_last_declared_symbol = action_slot.sym;
          if (action_slot.sym == (c1_symbol *)0x0) {
            g_last_declared_symbol = (pcVar14[-1].declarator)->sym;
          }
        }
        break;
      case 0xb:
        g_compile_flags_c4 = g_compile_flags_c4 | 0x1000000;
        g_compile_flags_c8 = g_compile_flags_c8 & 0xfffffffd;
        bVar12 = g_current_scope->current->kind;
        if ((0xfa < bVar12) && (bVar12 != 0xfd)) {
          scope_pop_to_kind(g_current_scope,'\x01');
        }
        if ((g_paren_level_flags[g_paren_depth] & 1) == 0) {
          pcVar54 = decl_specifiers_default((void *)0x0);
        }
        else {
          pcVar54 = g_paren_level_declspecs + g_paren_depth;
        }
        decl_check_conversion_return_type((pcVar14[-1].declarator)->decl,pcVar54);
        decl_finish_declarator((pcVar14[-1].declarator)->decl);
        if ((g_paren_level_flags[g_paren_depth] & 1) == 0) {
          pcVar54 = decl_specifiers_default((void *)0x0);
        }
        else {
          pcVar54 = g_paren_level_declspecs + g_paren_depth;
        }
        ppvVar43 = (void **)&(pcVar14[-1].node)->unk0c;
        for (iVar25 = 6; iVar25 != 0; iVar25 = iVar25 + -1) {
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
        g_last_declared_symbol = func_begin_member_definition(pcVar14[-1].declarator,pcVar54->spec);
        g_declarator_paren_base = g_declarator_paren_base + -1;
        g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfc;
        lVar46 = g_enum_value;
        break;
      case 0xc:
        g_compile_flags_c4 = g_compile_flags_c4 & 0xfeffffff;
        g_compile_flags_c8 = g_compile_flags_c8 & 0xfffffffd;
        bVar12 = g_current_scope->current->kind;
        if ((0xfa < bVar12) && (bVar12 != 0xfd)) {
          scope_pop_to_kind(g_current_scope,'\x01');
        }
        pcVar38 = pcVar14 + -2;
        decl_check_conversion_return_type((pcVar14[-1].declarator)->decl,&pcVar38->spec);
        decl_finish_declarator((pcVar14[-1].declarator)->decl);
        pcVar40 = pcVar38;
        ppvVar43 = (void **)&(pcVar14[-1].node)->unk0c;
        for (iVar25 = 6; iVar25 != 0; iVar25 = iVar25 + -1) {
          *ppvVar43 = (void *)pcVar40->words[0];
          pcVar40 = (c1_yy_value *)(pcVar40->words + 1);
          ppvVar43 = ppvVar43 + 1;
        }
        g_last_declared_symbol =
             func_begin_member_definition(pcVar14[-1].declarator,(byte *)pcVar38->words);
        goto LAB_10420683;
      case 0xd:
      case 0x83:
        default_argument_store_and_advance_top(pcVar14[-1].node);
        lVar46 = g_enum_value;
        break;
      case 0xe:
        g_class_depth = g_class_depth + -1;
        class_begin_deferred_member_bodies();
        lVar46 = g_enum_value;
        break;
      case 0xf:
        class_reset_member_function_class();
        g_yy_lookahead = (byte *)lex_unget_token((c1xx_token *)g_yy_lookahead);
        lVar46 = g_enum_value;
        break;
      case 0x10:
        parse_external_declaration_end();
        lVar46 = g_enum_value;
        break;
      case 0x11:
        pch_creation_point();
        lVar46 = g_enum_value;
        break;
      case 0x12:
        pp_line_after_pch_options();
        lVar46 = g_enum_value;
        break;
      case 0x13:
        iVar25 = g_error_count;
        if (g_error_count != 0) goto LAB_104235dc;
        break;
      case 0x14:
        pch_hdrstop();
        lVar46 = g_enum_value;
        break;
      case 0x15:
        if ((g_compile_flags_c8 & 0x40) == 0) {
          diag_error(0x1bf);
          lex_skip_to_closing_brace('\0');
          parse_yyerrok(parser);
          lVar46 = g_enum_value;
        }
        else {
          g_compile_flags_c8 = g_compile_flags_c8 & 0xffffffbf;
          lex_skip_to_closing_brace('\0');
          parse_yyerrok(parser);
          lVar46 = g_enum_value;
        }
        break;
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
          pcVar54 = decl_specifiers_default((void *)0x0);
          lVar46 = g_enum_value;
        }
        else {
          pcVar54 = g_paren_level_declspecs + g_paren_depth;
        }
        g_enum_value = lVar46;
        decl_check_conversion_return_type(pcVar14->declarator->decl,pcVar54);
        decl_finish_declarator(pcVar14->declarator->decl);
        if ((g_paren_level_flags[g_paren_depth] & 1) == 0) {
          pcVar54 = decl_specifiers_default((void *)0x0);
        }
        else {
          pcVar54 = g_paren_level_declspecs + g_paren_depth;
        }
        ppvVar43 = (void **)&pcVar14->node->unk0c;
        for (iVar25 = 6; iVar25 != 0; iVar25 = iVar25 + -1) {
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
        func_begin_member_definition(pcVar14->declarator,pcVar54->spec);
        g_declarator_paren_base = g_declarator_paren_base + -1;
        bVar12 = g_current_scope->current->kind;
        if ((0xfa < bVar12) && (bVar12 != 0xfd)) {
          scope_pop_to_kind(g_current_scope,'\x01');
        }
        g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfc;
        lVar46 = g_enum_value;
        break;
      case 0x1f:
        g_ctor_mem_initializers = pcVar14->node;
        func_begin_definition_frame();
        g_compile_flags_c8 = g_compile_flags_c8 & 0xffffffbf;
        lVar46 = g_enum_value;
        break;
      case 0x20:
        funcs_check_incremental();
        lVar46 = g_enum_value;
        break;
      case 0x21:
        tmpl_parse_queued_definition(pcVar14->header);
        lVar46 = g_enum_value;
        break;
      case 0x22:
        g_compile_flags_c4 = g_compile_flags_c4 & 0xfeffffff;
        g_compile_flags_c8 = g_compile_flags_c8 & 0xfffffffd;
        bVar12 = g_current_scope->current->kind;
        if ((0xfa < bVar12) && (bVar12 != 0xfd)) {
          scope_pop_to_kind(g_current_scope,'\x01');
        }
        pcVar38 = pcVar14 + -1;
        decl_check_conversion_return_type(pcVar14->declarator->decl,&pcVar38->spec);
        decl_finish_declarator(pcVar14->declarator->decl);
        pcVar40 = pcVar38;
        ppvVar43 = (void **)&pcVar14->node->unk0c;
        for (iVar25 = 6; iVar25 != 0; iVar25 = iVar25 + -1) {
          *ppvVar43 = (void *)pcVar40->words[0];
          pcVar40 = (c1_yy_value *)(pcVar40->words + 1);
          ppvVar43 = ppvVar43 + 1;
        }
        if (g_block_depth == '\0') {
          pcVar32 = func_begin_member_definition(pcVar14->declarator,(byte *)pcVar38->words);
          in_stack_00000014[1].sym = pcVar32;
        }
        else {
          cVar10 = '\0';
          pcVar32 = decl_declare_in_current_scope(pcVar14->declarator,&pcVar38->spec);
          func_parse_definition_or_skip(pcVar32,cVar10);
          g_yy_lookahead = g_token_end_parse;
        }
LAB_10420683:
        g_declarator_paren_base = g_declarator_paren_base + -1;
        g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfc;
        pcVar38 = in_stack_00000014;
        lVar46 = g_enum_value;
        break;
      case 0x24:
        g_compile_flags_cc = g_compile_flags_cc | 2;
        func_begin_definition_state((int *)(pcVar14->str).text);
        lVar46 = g_enum_value;
        break;
      case 0x25:
        pcVar32 = type_require_complete(pcVar14->sym);
        pcVar38[1].sym = pcVar32;
        lVar46 = g_enum_value;
        break;
      case 0x26:
        pcVar32 = type_require_complete(pcVar14->sym);
        pcVar38[1].sym = pcVar32;
        lVar46 = g_enum_value;
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
        pcVar38[1].words[0] = pcVar14->words[0];
        lVar46 = g_enum_value;
        break;
      case 0x2a:
        pcVar23 = tree_append_expression_list_item((c1_node *)0x0,pcVar14->node);
        pcVar38[1].node = pcVar23;
        lVar46 = g_enum_value;
        break;
      case 0x2b:
        pcVar23 = tree_append_expression_list_item(pcVar14[-2].node,pcVar14->node);
        pcVar38[1].node = pcVar23;
        lVar46 = g_enum_value;
        break;
      case 0x2c:
        diag_error(0x276);
        pcVar23 = tree_append_expression_list_item(pcVar14[-2].node,pcVar14->node);
        pcVar38[1].node = pcVar23;
        lVar46 = g_enum_value;
        break;
      case 0x2d:
      case 0x2f:
      case 0x31:
      case 0x33:
        g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] | 1;
        lVar46 = g_enum_value;
        break;
      case 0x2e:
        cVar30 = pcVar14[-1].words[0];
        pfVar31 = pcVar14[-4].name;
        uVar49 = (undefined1)cVar30;
        uVar51 = (undefined1)(cVar30 >> 8);
        uVar41 = (undefined2)(cVar30 >> 0x10);
        goto LAB_1042079c;
      case 0x30:
        cVar30 = pcVar14[-1].words[0];
        uVar49 = (undefined1)cVar30;
        uVar51 = (undefined1)(cVar30 >> 8);
        uVar41 = (undefined2)(cVar30 >> 0x10);
        pfVar31 = (pcVar14[-4].declarator)->name;
LAB_1042079c:
        cVar10 = '\0';
        pcVar33 = (c1_type *)0x0;
        pcVar32 = sym_new_kind1_placeholder(pfVar31);
        pcVar23 = tree_new_symbol_ref(pcVar32,cVar10);
        pcVar23 = tree_new_node('v',pcVar23,(c1_node *)CONCAT22(uVar41,CONCAT11(uVar51,uVar49)),
                                pcVar33);
        pcVar38[1].node = pcVar23;
        g_compile_flags_c4 = g_compile_flags_c4 | 1;
        goto LAB_104207ca;
      case 0x32:
      case 0x34:
        cVar30 = pcVar14[-1].words[0];
        pcVar33 = (c1_type *)0x0;
        uVar49 = (undefined1)cVar30;
        uVar51 = (undefined1)(cVar30 >> 8);
        uVar41 = (undefined2)(cVar30 >> 0x10);
        pcVar23 = tree_new_symbol_ref(*pcVar14[-4].cell,'\0');
        pcVar23 = tree_new_node('v',pcVar23,(c1_node *)CONCAT22(uVar41,CONCAT11(uVar51,uVar49)),
                                pcVar33);
        pcVar38[1].node = pcVar23;
        g_compile_flags_c4 = g_compile_flags_c4 | 1;
        goto LAB_104207ca;
      case 0x35:
        pcVar38[1].words[0] = 0;
        diag_error(0x15f);
        g_compile_flags_c4 = g_compile_flags_c4 | 1;
        lVar46 = g_enum_value;
        break;
      case 0x36:
        pcVar38[1].words[0] = 0;
        diag_error(0x15f);
        g_compile_flags_c4 = g_compile_flags_c4 | 1;
        goto LAB_104207ca;
      case 0x37:
        pcVar38[1].words[0] = 0;
        parse_yyerrok(parser);
        parse_skip_tokens_to_one_of((c1xx_token *)g_yy_lookahead);
        lVar46 = g_enum_value;
        break;
      case 0x38:
        pcVar38[1].words[0] = pcVar14[-1].words[0];
LAB_104207ca:
        lVar46 = g_enum_value;
        if (0 < g_paren_depth) {
          g_paren_depth = g_paren_depth + -1;
        }
        break;
      case 0x3b:
        pcVar23 = tree_append_list_item((c1_node *)0x0,pcVar14->node,2);
        pcVar38[1].node = pcVar23;
        lVar46 = g_enum_value;
        break;
      case 0x3c:
        pcVar23 = tree_append_list_item(pcVar14[-2].node,pcVar14->node,2);
        pcVar38[1].node = pcVar23;
        lVar46 = g_enum_value;
        break;
      case 0x3e:
        decl_pop_linkage_specification();
        lVar46 = g_enum_value;
        break;
      case 0x46:
        if (pcVar14[-1].words[0] == 0) {
          g_compile_flags_c4 = g_compile_flags_c4 | 0x800000;
          g_compile_flags_c8 = g_compile_flags_c8 & 0xffffffbf;
        }
        else {
          g_ctor_mem_initializers = pcVar14->node;
          func_begin_definition_frame();
          g_compile_flags_c8 = g_compile_flags_c8 & 0xffffffbf;
          lVar46 = g_enum_value;
        }
        break;
      case 0x47:
        if (pcVar14[-3].words[0] == 0) {
          g_compile_flags_c4 = g_compile_flags_c4 & 0xff7fffff;
          g_compile_flags_cc = g_compile_flags_cc & 0xfffffffd;
        }
        else {
          funcs_check_incremental();
          g_compile_flags_cc = g_compile_flags_cc & 0xfffffffd;
          lVar46 = g_enum_value;
        }
        break;
      case 0x49:
        parse_yyerrok(parser);
        g_compile_flags_c4 = g_compile_flags_c4 & 0xff7fffff;
        g_compile_flags_c8 = g_compile_flags_c8 & 0xffffffbf;
        g_compile_flags_cc = g_compile_flags_cc & 0xfffffffd;
        lVar46 = g_enum_value;
        break;
      case 0x4a:
        pcVar40 = pcVar14 + -1;
        pcVar42 = (c1_u32 *)&stack0x00000100;
        for (iVar25 = 9; iVar25 != 0; iVar25 = iVar25 + -1) {
          *pcVar42 = pcVar40->words[0];
          pcVar40 = (c1_yy_value *)(pcVar40->words + 1);
          pcVar42 = pcVar42 + 1;
        }
        class_check_unnamed_class_member((c1xx_decl_specifiers *)&stack0x00000100);
        pcVar38[1].words[0] = pcVar14->words[0];
        lVar46 = g_enum_value;
        break;
      case 0x4b:
        pcVar42 = (c1_u32 *)&stack0x000000b8;
        for (iVar25 = 9; iVar25 != 0; iVar25 = iVar25 + -1) {
          *pcVar42 = pcVar14->words[0];
          pcVar14 = (c1_yy_value *)(pcVar14->words + 1);
          pcVar42 = pcVar42 + 1;
        }
        class_check_unnamed_class_member((c1xx_decl_specifiers *)&stack0x000000b8);
        decl_check_empty_declaration(&stack0x000000b8);
        pcVar38[1].words[0] = 0;
        lVar46 = g_enum_value;
        break;
      case 0x4c:
        tmpl_finish_class_template_declaration(pcVar14 + -2,&pcVar14[-1].spec);
        lVar46 = g_enum_value;
        break;
      case 0x4d:
        tmpl_finish_nonclass_template_declaration(pcVar14 + -2,pcVar14[-1].sym);
        lVar46 = g_enum_value;
        break;
      case 0x4e:
        tmpl_finish_class_template_declaration(pcVar14 + -1,(c1xx_decl_specifiers *)0x0);
        lVar46 = g_enum_value;
        break;
      case 0x4f:
        g_compile_flags_cc = g_compile_flags_cc & 0xefffffff;
        pcVar34 = arena_alloc(g_arenas + 5,0x58);
        if (pcVar34 == (c1_declarator *)0x0) {
          pcVar34 = (c1_declarator *)0x0;
        }
        else {
          pcVar34->position = g_token_position;
        }
        pcVar40 = pcVar14 + -1;
        pcVar29 = pcVar34->spec;
        for (iVar25 = 6; iVar25 != 0; iVar25 = iVar25 + -1) {
          *(c1_u32 *)pcVar29 = pcVar40->words[0];
          pcVar40 = (c1_yy_value *)(pcVar40->words + 1);
          pcVar29 = pcVar29 + 4;
        }
        tmpl_explicit_instantiation(pcVar34,'\x01',&pcVar14[-1].spec);
        lVar46 = g_enum_value;
        break;
      case 0x50:
        g_compile_flags_cc = g_compile_flags_cc & 0xefffffff;
        pcVar38 = pcVar14 + -2;
        decl_check_conversion_return_type((pcVar14[-1].declarator)->decl,&pcVar38->spec);
        decl_finish_declarator((pcVar14[-1].declarator)->decl);
        pcVar40 = pcVar38;
        ppvVar43 = (void **)&(pcVar14[-1].node)->unk0c;
        for (iVar25 = 6; iVar25 != 0; iVar25 = iVar25 + -1) {
          *ppvVar43 = (void *)pcVar40->words[0];
          pcVar40 = (c1_yy_value *)(pcVar40->words + 1);
          ppvVar43 = ppvVar43 + 1;
        }
        tmpl_explicit_instantiation(pcVar14[-1].declarator,'\x01',&pcVar38->spec);
        g_declarator_paren_base = g_declarator_paren_base + -1;
        pcVar38 = in_stack_00000014;
        lVar46 = g_enum_value;
        break;
      case 0x51:
        g_compile_flags_cc = g_compile_flags_cc & 0xefffffff;
        diag_error(0x38d);
        tmpl_explicit_instantiation_without_specifiers(pcVar14[-1].declarator,1);
        bVar12 = g_current_scope->current->kind;
        goto LAB_10465c69;
      case 0x52:
        g_compile_flags_cc = g_compile_flags_cc & 0xefffffff;
        pcVar34 = arena_alloc(g_arenas + 5,0x58);
        if (pcVar34 == (c1_declarator *)0x0) {
          pcVar34 = (c1_declarator *)0x0;
        }
        else {
          pcVar34->position = g_token_position;
        }
        pcVar40 = pcVar14 + -1;
        pcVar29 = pcVar34->spec;
        for (iVar25 = 6; iVar25 != 0; iVar25 = iVar25 + -1) {
          *(c1_u32 *)pcVar29 = pcVar40->words[0];
          pcVar40 = (c1_yy_value *)(pcVar40->words + 1);
          pcVar29 = pcVar29 + 4;
        }
        tmpl_explicit_instantiation(pcVar34,pcVar14[-3].spec.spec[0],&pcVar14[-1].spec);
        lVar46 = g_enum_value;
        break;
      case 0x53:
        pcVar38 = pcVar14 + -2;
        g_compile_flags_cc = g_compile_flags_cc & 0xefffffff;
        decl_check_conversion_return_type((pcVar14[-1].declarator)->decl,&pcVar38->spec);
        decl_finish_declarator((pcVar14[-1].declarator)->decl);
        pcVar40 = pcVar38;
        ppvVar43 = (void **)&(pcVar14[-1].node)->unk0c;
        for (iVar25 = 6; iVar25 != 0; iVar25 = iVar25 + -1) {
          *ppvVar43 = (void *)pcVar40->words[0];
          pcVar40 = (c1_yy_value *)(pcVar40->words + 1);
          ppvVar43 = ppvVar43 + 1;
        }
        tmpl_explicit_instantiation(pcVar14[-1].declarator,pcVar14[-4].spec.spec[0],&pcVar38->spec);
        bVar12 = g_current_scope->current->kind;
        if ((0xfa < bVar12) && (bVar12 != 0xfd)) {
          scope_pop_to_kind(g_current_scope,'\x01');
        }
        g_declarator_paren_base = g_declarator_paren_base + -1;
        pcVar38 = in_stack_00000014;
        lVar46 = g_enum_value;
        break;
      case 0x54:
        g_compile_flags_cc = g_compile_flags_cc & 0xefffffff;
        in_stack_00000060 = in_stack_00000060 & 0xf8;
        in_stack_00000028 = CONCAT31(in_stack_00000028._1_3_,pcVar14[-3].spec.spec[0]);
        puVar44 = (undefined4 *)&stack0x00000060;
        for (iVar25 = 6; iVar25 != 0; iVar25 = iVar25 + -1) {
          *puVar44 = 0;
          puVar44 = puVar44 + 1;
        }
        pcVar34 = pcVar14[-1].declarator;
        in_stack_0000007c = (c1_symbol *)0x0;
        in_stack_00000060 = in_stack_00000060 & 7 ^ in_stack_00000060 | 0x30;
        in_stack_00000078 = g_type_none;
        decl_check_conversion_return_type(pcVar34->decl,(c1xx_decl_specifiers *)&stack0x00000060);
        decl_finish_declarator(pcVar34->decl);
        tmpl_explicit_instantiation
                  (pcVar34,(c1_u8)in_stack_00000028,(c1xx_decl_specifiers *)&stack0x00000060);
        bVar12 = g_current_scope->current->kind;
LAB_10465c69:
        if ((0xfa < bVar12) && (bVar12 != 0xfd)) {
          scope_pop_to_kind(g_current_scope,'\x01');
          g_declarator_paren_base = g_declarator_paren_base + -1;
          lVar46 = g_enum_value;
          break;
        }
        goto LAB_104232fa;
      case 0x55:
        g_compile_flags_cc = g_compile_flags_cc & 0xefffffff;
        parse_yyerrok(parser);
        tmpl_finish_class_template_declaration((c1_yy_value *)0x0,(c1xx_decl_specifiers *)0x0);
        lVar46 = g_enum_value;
        break;
      case 0x56:
        tmpl_check_nested_definition();
        lVar46 = g_enum_value;
        break;
      case 0x57:
        decl_pop_declarator_state(pcVar14[-1].params);
        pvVar22 = tmpl_header_end((pcVar14[-1].header)->parameter_scope);
        pcVar38[1].ptr = pvVar22;
        pcVar19 = tmpl_header_take_parameter_list();
        *(c1_arg_list **)((int)pcVar38 + 0x2c) = pcVar19;
        lVar46 = g_enum_value;
        break;
      case 0x5d:
        pcVar38 = pcVar14 + -1;
        g_declarator_paren_base = g_declarator_paren_base + -1;
        decl_check_conversion_return_type(pcVar14->declarator->decl,&pcVar38->spec);
        decl_finish_declarator(pcVar14->declarator->decl);
        pcVar40 = pcVar38;
        ppvVar43 = (void **)&pcVar14->node->unk0c;
        for (iVar25 = 6; iVar25 != 0; iVar25 = iVar25 + -1) {
          *ppvVar43 = (void *)pcVar40->words[0];
          pcVar40 = (c1_yy_value *)(pcVar40->words + 1);
          ppvVar43 = ppvVar43 + 1;
        }
        if (g_class_depth < 0) {
          if ((g_compile_flags_c8 & 0x40) == 0) {
            pcVar32 = decl_declare_from_declarator(pcVar14->declarator,(byte *)pcVar38->words);
          }
          else {
            pcVar32 = pcVar14->declarator->sym;
          }
          bVar12 = g_current_scope->current->kind;
          if ((0xfa < bVar12) && (bVar12 != 0xfd)) {
            scope_pop_to_kind(g_current_scope,'\x01');
          }
          class_check_unnamed_class_member(&pcVar38->spec);
          in_stack_00000014[1].sym = pcVar32;
          pcVar38 = in_stack_00000014;
          lVar46 = g_enum_value;
        }
        else {
          pcVar14->declarator->kind = 2;
          cVar10 = class_begin_member_list(pcVar14->declarator,&pcVar38->spec,(c1_symbol **)0x0);
          if (((cVar10 == '\0') && (bVar12 = g_current_scope->current->kind, 0xfa < bVar12)) &&
             (bVar12 != 0xfd)) {
            scope_pop_to_kind(g_current_scope,'\x01');
          }
          in_stack_00000014[1].words[0] = (c1_u32)pcVar14->declarator->sym;
          pcVar38 = in_stack_00000014;
          lVar46 = g_enum_value;
        }
        break;
      case 0x5e:
        g_compile_flags_c4 = g_compile_flags_c4 | 0x1000000;
        g_compile_flags_c8 = g_compile_flags_c8 & 0xfffffffd;
        g_declarator_paren_base = g_declarator_paren_base + -1;
        if ((g_paren_level_flags[g_paren_depth] & 1) == 0) {
          pcVar54 = decl_specifiers_default((void *)0x0);
          lVar46 = g_enum_value;
        }
        else {
          pcVar54 = g_paren_level_declspecs + g_paren_depth;
        }
        g_enum_value = lVar46;
        decl_check_conversion_return_type(pcVar14->declarator->decl,pcVar54);
        decl_finish_declarator(pcVar14->declarator->decl);
        if ((g_paren_level_flags[g_paren_depth] & 1) == 0) {
          pcVar54 = decl_specifiers_default((void *)0x0);
        }
        else {
          pcVar54 = g_paren_level_declspecs + g_paren_depth;
        }
        ppvVar43 = (void **)&pcVar14->node->unk0c;
        for (iVar25 = 6; iVar25 != 0; iVar25 = iVar25 + -1) {
          *ppvVar43 = *(void **)pcVar54->spec;
          pcVar54 = (c1xx_decl_specifiers *)(pcVar54->spec + 4);
          ppvVar43 = ppvVar43 + 1;
        }
        if (-1 < g_class_depth) {
          pcVar14->declarator->kind = 2;
          if ((g_paren_level_flags[g_paren_depth] & 1) == 0) {
            pcVar54 = decl_specifiers_default((void *)0x0);
          }
          else {
            pcVar54 = g_paren_level_declspecs + g_paren_depth;
          }
          cVar10 = class_begin_member_list(pcVar14->declarator,pcVar54,(c1_symbol **)0x0);
          if (((cVar10 == '\0') && (bVar12 = g_current_scope->current->kind, 0xfa < bVar12)) &&
             (bVar12 != 0xfd)) {
            scope_pop_to_kind(g_current_scope,'\x01');
          }
          pcVar38[1].words[0] = (c1_u32)pcVar14->declarator->sym;
          lVar46 = g_enum_value;
          break;
        }
        if ((g_compile_flags_c8 & 0x40) == 0) {
          if ((g_paren_level_flags[g_paren_depth] & 1) == 0) {
            pcVar54 = decl_specifiers_default((void *)0x0);
            pcVar34 = (c1_declarator *)
                      decl_declare_from_declarator(pcVar14->declarator,pcVar54->spec);
          }
          else {
            pcVar34 = (c1_declarator *)
                      decl_declare_from_declarator
                                (pcVar14->declarator,g_paren_level_declspecs[g_paren_depth].spec);
          }
        }
        else {
          pcVar34 = (c1_declarator *)pcVar14->declarator->sym;
        }
        bVar12 = g_current_scope->current->kind;
        if (0xfa < bVar12) {
          iVar25 = yyparse_cpp_template_member_declaration_tail
                             (g_current_scope,bVar12,(c1_symbol *)pcVar34,pcVar38,parser,state_sp_00
                              ,saved_lookahead,saved_rule);
          return iVar25;
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
          pcVar38[1].words[0] = 0;
          lVar46 = g_enum_value;
        }
        else {
          cVar4 = g_current_scope->current->body;
          pcVar13[4] = (c1_scope_body)0x3;
          *(c1_u8 *)(pcVar13 + 5) = '\x01';
          *pcVar13 = cVar4;
          pcVar38[1].params = (c1_param_clause *)pcVar13;
          lVar46 = g_enum_value;
        }
        break;
      case 100:
        if ((g_token_source->stream->flags & 1) != 0) {
          pcVar26 = include_line_map_find((c1_line_map_state *)&g_lex_position,g_token_position);
          (*g_idb->vtbl->idb_scope_kind4_end)
                    (g_idb,CONCAT22(uVar41,(short)pcVar26->line - (short)pcVar26->position) +
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
          cVar7 = (c1_arg_value)pcVar14->node->right;
          tmpl_list_item_construct(pcVar18,0,0);
          pcVar18->value = cVar7;
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
        lVar46 = g_enum_value;
        if (((g_compile_flags_c8 & 0x32000000) != 0) ||
           (((((g_compile_flags_c8 & 0x40000000) != 0 && ((g_compile_flags_cc & 8) == 0)) &&
             ((g_compile_flags_c4 & 0x200) == 0)) ||
            ((uVar9 = g_compile_flags_c8 & 0x4000000, g_compile_flags_c8 = uVar56,
             g_compile_flags_cc = uVar36, uVar9 != 0 && ((g_compile_flags_c4 & 0x8000) == 0))))))
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
          pcVar26 = include_line_map_find((c1_line_map_state *)&g_lex_position,g_token_position);
          (*g_idb->vtbl->idb_scope_kind4_end)
                    (g_idb,CONCAT22(uVar41,(short)pcVar26->line - (short)pcVar26->position) +
                           g_token_position,0);
        }
        a = g_arenas + g_expr_arena_index;
        pcVar23 = (c1_node *)a->cur;
        pcVar8 = (c1_node *)g_arenas[g_expr_arena_index].end;
        a->cur = &pcVar23[1].op;
        if (pcVar8 < pcVar23 + 1) {
          arena_grow(a);
        }
        pcVar23->kind = '\0';
        pcVar23->op = 0xc6;
        pcVar23->left = (void *)pcVar14->words[0];
        in_stack_00000054 = (c1_type *)0x0;
        in_stack_0000005c = 0;
        in_stack_00000050 = 0x80e;
        in_stack_00000052 = 0;
        in_stack_00000058.cls = (c1_symbol *)0x0;
        pcVar33 = type_intern((c1_type *)&stack0x00000050);
        pcVar23->type = pcVar33;
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
        uVar56 = g_compile_flags_c8 & 0xfeffffff;
        uVar36 = g_compile_flags_cc & 0xffffffef;
        lVar46 = g_enum_value;
        if ((((g_compile_flags_c8 & 0x32000000) == 0) &&
            ((((g_compile_flags_c8 & 0x40000000) == 0 || ((g_compile_flags_cc & 8) != 0)) ||
             ((g_compile_flags_c4 & 0x200) != 0)))) &&
           ((uVar9 = g_compile_flags_c8 & 0x4000000, g_compile_flags_c8 = uVar56,
            g_compile_flags_cc = uVar36, uVar9 == 0 || ((g_compile_flags_c4 & 0x8000) != 0))))
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
        lVar46 = g_enum_value;
        break;
      case 0x69:
        stream = token_reader_current_stream((c1_token_reader *)&g_token_position);
        cVar10 = token_stream_is_source_text(stream);
        lVar46 = g_enum_value;
        if (cVar10 != '\0') {
          pcVar39 = g_idb->vtbl;
LAB_10422231:
          iVar25 = 0;
          uVar56 = lex_line_number_of_position(&g_token_position);
          (*pcVar39->idb_scope_kind3_to_4)(g_idb,uVar56,iVar25);
          lVar46 = g_enum_value;
        }
        break;
      case 0x6b:
      case 0x6d:
        pcVar29 = arena_alloc_n_aligned(0xc,0);
        if (pcVar29 == (c1_u8 *)0x0) goto LAB_10465f34;
        pvVar22 = tmpl_argument_list_init(pcVar29,pcVar14->ptr);
        pcVar38[1].ptr = pvVar22;
        lVar46 = g_enum_value;
        break;
      case 0x6c:
        list_append_tail(pcVar14[-2].args,pcVar14->arg);
        lVar46 = g_enum_value;
        break;
      case 0x6e:
        pcVar18 = tmpl_argument_from_expression(pcVar14->node);
        pcVar38[1].arg = pcVar18;
        lVar46 = g_enum_value;
        break;
      case 0x6f:
        pcVar40 = pcVar14 + -1;
        pcVar42 = acStack_24;
        for (iVar25 = 9; iVar25 != 0; iVar25 = iVar25 + -1) {
          *pcVar42 = pcVar40->words[0];
          pcVar40 = (c1_yy_value *)(pcVar40->words + 1);
          pcVar42 = pcVar42 + 1;
        }
        pcVar18 = decl_finish_declarator_record(pcVar14->declarator);
        pcVar38[1].arg = pcVar18;
        lVar46 = g_enum_value;
        break;
      case 0x71:
        g_compile_flags_c8 = g_compile_flags_c8 & 0xffffffdf;
        break;
      case 0x72:
      case 0x15d:
      case 0x15e:
        goto switchD_10421905_caseD_6f;
      case 0x73:
        pcVar23 = pcVar14->node;
        pcVar14 = pcVar14 + -2;
        pcVar42 = (c1_u32 *)&stack0x00000124;
        for (iVar25 = 9; iVar25 != 0; iVar25 = iVar25 + -1) {
          *pcVar42 = pcVar14->words[0];
          pcVar14 = (c1_yy_value *)(pcVar14->words + 1);
          pcVar42 = pcVar42 + 1;
        }
        iVar25 = decl_parse_linkage_specification((c1xx_decl_specifiers *)&stack0x00000124,pcVar23);
        decl_push_linkage_specification(iVar25);
        if (g_yy_lookahead == (byte *)0x0) {
          iVar25 = parse_error_recovery_count();
          if (iVar25 == 0) {
            arena_reset(5);
          }
        }
        g_string_literal_cur = &g_string_literal_buffer;
        g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfc;
        lVar46 = g_enum_value;
        if (g_yy_lookahead != (byte *)0x0) {
          cVar11 = lex_token_code((c1xx_token *)g_yy_lookahead);
          lVar46 = g_enum_value;
          if (cVar11 != 'u') {
            g_compile_flags_c8 = g_compile_flags_c8 | 0x20;
          }
        }
        break;
      case 0x76:
        ns_end_definition(pcVar14[-2].words[0]);
        lVar46 = g_enum_value;
        break;
      case 0x77:
        pbVar16 = ns_define_namespace((void *)0x0);
        pcVar38[1].str.text = pbVar16;
        lVar46 = g_enum_value;
        break;
      case 0x78:
        pbVar16 = ns_define_namespace(pcVar14[-1].ptr);
        pcVar38[1].str.text = pbVar16;
        lVar46 = g_enum_value;
        break;
      case 0x79:
        scope_pop_to_kind_if_needed(g_current_scope,'\0');
        pvVar22 = qualname_resolved_symbol(pcVar14[-1].declarator);
        cVar11 = '\0';
        uVar49 = 0;
        uVar51 = 0;
        uVar41 = 0;
        if (pvVar22 == (void *)0x0) {
          pcVar32 = value_word0(pcVar14[-1].cell);
          ns_using_directive((c1_symbol *)0x0,(fe_name *)pcVar32,
                             CONCAT22(uVar41,CONCAT11(uVar51,uVar49)),cVar11);
          lVar46 = g_enum_value;
        }
        else {
          uVar48 = 0;
          uVar50 = 0;
          uVar52 = 0;
          pcVar32 = qualname_resolved_symbol(pcVar14[-1].declarator);
          ns_using_directive(pcVar32,(fe_name *)CONCAT22(uVar52,CONCAT11(uVar50,uVar48)),
                             CONCAT22(uVar41,CONCAT11(uVar51,uVar49)),cVar11);
          lVar46 = g_enum_value;
        }
        break;
      case 0x7a:
        scope_pop_to_kind_if_needed(g_current_scope,'\0');
        pvVar22 = qualname_resolved_symbol(pcVar14[-1].declarator);
        pcVar34 = (c1_declarator *)pcVar14[-1].cell;
        if (pvVar22 == (void *)0x0) {
LAB_104668f9:
          value_word0((c1_symbol **)pcVar34);
          diag_error(0x369);
          lVar46 = g_enum_value;
        }
        else {
          pcVar32 = qualname_resolved_symbol(pcVar34);
          ns_using_declaration(pcVar32);
          lVar46 = g_enum_value;
        }
        break;
      case 0x7b:
        ns_using_declaration(*(c1_symbol **)((int)pcVar14 + -0xc));
        lVar46 = g_enum_value;
        break;
      case 0x7c:
        scope_pop_to_kind_if_needed(g_current_scope,'\0');
        ns_define_alias(pcVar14[-1].declarator,pcVar14[-3].name);
        lVar46 = g_enum_value;
        break;
      case 0x7d:
        diag_error(0x122);
        parse_paren_depth_pop();
        lVar46 = g_enum_value;
        break;
      case 0x7e:
        if (g_yy_lookahead != (byte *)0x0) {
          cVar11 = lex_token_code((c1xx_token *)g_yy_lookahead);
          if (cVar11 == 'v') {
            iVar24 = 9;
            iVar25 = g_paren_depth;
            pcVar42 = (c1_u32 *)(&g_paren_level_declspecs_prev_base + g_paren_depth * 0x24);
            lVar46 = g_enum_value;
            goto LAB_10420c2b;
          }
        }
        iVar25 = g_paren_depth;
        pcVar54 = g_paren_level_declspecs + g_paren_depth;
        for (iVar24 = 9; iVar24 != 0; iVar24 = iVar24 + -1) {
          *(c1_u32 *)pcVar54->spec = pcVar14->words[0];
          pcVar14 = (c1_yy_value *)(pcVar14->words + 1);
          pcVar54 = (c1xx_decl_specifiers *)(pcVar54->spec + 4);
        }
        g_paren_level_flags[iVar25] = g_paren_level_flags[iVar25] | 1;
        lVar46 = g_enum_value;
        break;
      case 0x7f:
        if (((code *)pcVar14->words[8] != (code *)0x0) && (pcVar14->words[7] != 0)) {
          (*(code *)pcVar14->words[8])();
          lVar46 = g_enum_value;
        }
        break;
      case 0x80:
        bVar45 = g_yy_lookahead != (byte *)0x0;
        puVar28 = &g_yylval;
        for (iVar25 = 9; iVar25 != 0; iVar25 = iVar25 + -1) {
          *puVar28 = pcVar14->words[0];
          pcVar14 = (c1_yy_value *)(pcVar14->words + 1);
          puVar28 = puVar28 + 1;
        }
        if (bVar45) {
          cVar11 = lex_token_code(pcVar27);
          pcVar27 = (c1xx_token *)g_yy_lookahead;
          lVar46 = g_enum_value;
          if (cVar11 == '\x7f') break;
        }
        g_yy_lookahead = (byte *)lex_unget_token(pcVar27);
        g_compile_flags_c4 = g_compile_flags_c4 | 0x80000000;
        pcVar32 = value_word0((c1_symbol **)&g_token_arena_index);
        pcVar29 = arena_or_pool_alloc(0x30,(int)pcVar32);
        if (pcVar29 == (c1_u8 *)0x0) {
          token = (char *)0x0;
        }
        else {
          token = token_init(pcVar29,'\"',&g_yylval);
        }
        pcVar27 = (c1xx_token *)lex_lookahead_decl_specifiers(token);
        g_compile_flags_c4 = g_compile_flags_c4 & 0x7fffffff;
        pcVar14 = token_value_address(pcVar27);
        pcVar40 = pcVar38 + 1;
        lVar46 = g_enum_value;
        for (iVar25 = 9; iVar25 != 0; iVar25 = iVar25 + -1) {
          g_enum_value = lVar46;
          pcVar40->words[0] = pcVar14->words[0];
          pcVar14 = (c1_yy_value *)(pcVar14->words + 1);
          pcVar40 = (c1_yy_value *)(pcVar40->words + 1);
          lVar46 = g_enum_value;
        }
        break;
      case 0x85:
        iVar25 = browse_end_global_block();
        *(int *)((int)pcVar38 + 0x40) = iVar25;
        lVar46 = g_enum_value;
        break;
      case 0x86:
        pcVar33 = class_end_definition();
        *(c1_type **)((int)pcVar38 + 0x40) = pcVar33;
        class_begin_deferred_member_bodies();
        lVar46 = g_enum_value;
        if (g_yy_lookahead == (byte *)0x0) {
          g_yy_lookahead = token_next((c1_token_reader *)&g_token_position);
          lVar46 = g_enum_value;
        }
        break;
      case 0x87:
        class_reset_member_function_class();
        lVar46 = g_enum_value;
        break;
      case 0x88:
        if (*(code **)((int)pcVar14 + -8) != (code *)0x0) {
          (**(code **)((int)pcVar14 + -8))();
        }
        class_begin_definition
                  (*(c1_symbol **)((int)pcVar14 + -0xc),*(c1_type **)((int)pcVar14 + -0x10));
        class_end_member_list();
        lVar46 = g_enum_value;
        break;
      case 0x8a:
        if ((code *)pcVar14->words[8] != (code *)0x0) {
          (*(code *)pcVar14->words[8])();
        }
        class_begin_definition((pcVar14->spec).type_sym,(pcVar14->spec).type);
        g_compile_flags_c4 = g_compile_flags_c4 | 3;
        lVar46 = g_enum_value;
        break;
      case 0x8b:
        if (g_yy_lookahead == (byte *)0x0) {
          g_yy_lookahead = token_next((c1_token_reader *)&g_token_position);
        }
        cVar11 = lex_token_code((c1xx_token *)g_yy_lookahead);
        if (cVar11 != 'u') {
          lex_token_code((c1xx_token *)g_yy_lookahead);
          diag_error(0x265);
          pcVar27 = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
          g_yy_lookahead = &parse_skip_tokens_to_one_of(pcVar27)->code;
          cVar11 = lex_token_code((c1xx_token *)g_yy_lookahead);
          if (cVar11 == '\x7f') {
            lex_unget_token((c1xx_token *)g_yy_lookahead);
            pcVar27 = token_static_for_code(0x7b);
            token_source_unget((c1_token_reader *)&g_token_position,pcVar27);
            g_yy_lookahead = &token_static_for_code(0x75)->code;
          }
        }
        g_compile_flags_c4 = g_compile_flags_c4 & 0xfffffffc;
        class_end_member_list();
        lVar46 = g_enum_value;
        break;
      case 0x8d:
      case 0x8e:
      case 0x1a5:
        g_compile_flags_c4 = g_compile_flags_c4 & 0xfffffffe;
        break;
      case 0x8f:
        if (*(code **)((int)pcVar14 + -8) != (code *)0x0) {
          (**(code **)((int)pcVar14 + -8))();
        }
        pcVar32 = (c1_symbol *)sym_name(*(c1_symbol **)((int)pcVar14 + -0x10));
        lVar46 = g_enum_value;
        if (g_pragma_mintypeinfo != '\0') {
          sym_detail_set_flag3f_bit3(pcVar32);
          lVar46 = g_enum_value;
        }
        if ((g_browse_file != (char *)0x0) && ((g_block_depth == '\0' || (g_opt_FR_browse != 0)))) {
          g_enum_value = lVar46;
          cVar11 = sym_flags3_bit0(pcVar32);
          lVar46 = g_enum_value;
          if (cVar11 == '\0') {
            (*g_il_emitter->vtbl->begin_block)();
            pcVar5 = g_il_emitter->vtbl;
            iVar25 = sym_name(pcVar32);
            iVar25 = (*pcVar5->mark_definition)(0,iVar25);
            if (iVar25 == 0) {
              (*g_il_emitter->vtbl->define_symbol)(g_il_emitter,pcVar32);
            }
            (*g_il_emitter->vtbl->set_owner)((int)pcVar32);
            lVar46 = g_enum_value;
          }
        }
        break;
      case 0x96:
        if (g_yy_lookahead == (byte *)0x0) {
          g_yy_lookahead = token_next((c1_token_reader *)&g_token_position);
        }
        cVar11 = lex_token_code((c1xx_token *)g_yy_lookahead);
        lVar46 = g_enum_value;
        if (cVar11 != '7') {
          cVar11 = lex_token_code((c1xx_token *)g_yy_lookahead);
          lVar46 = g_enum_value;
          if (cVar11 != 'u') {
            parse_report_inserted_token(g_yy_lookahead,0x37);
            lex_unget_token((c1xx_token *)g_yy_lookahead);
            g_yy_lookahead = &token_static_for_code(0x37)->code;
            lVar46 = g_enum_value;
          }
        }
        break;
      case 0x97:
      case 0x9e:
        class_check_base_defined
                  (pcVar14[-1].spec.spec[0] & 3,pcVar14[-1].spec.spec[0] >> 2 & 0xffffff01,
                   pcVar14->name,0);
        g_compile_flags_c4 = g_compile_flags_c4 | 1;
        lVar46 = g_enum_value;
        break;
      case 0x98:
        bVar12 = pcVar14[-1].spec.spec[0];
        pcVar32 = (c1_symbol *)sym_name(pcVar14->sym);
        class_check_base_class(bVar12 & 3,bVar12 >> 2 & 1,pcVar32);
        goto LAB_10420ed7;
      case 0x99:
        pcVar32 = value_word0(pcVar14->cell);
        access_check_member(pcVar32);
        bVar12 = pcVar14[-1].spec.spec[0];
        iVar25 = 0;
        pcVar32 = value_word0(pcVar14->cell);
        uVar48 = SUB41(pcVar32,0);
        uVar50 = (undefined1)((uint)pcVar32 >> 8);
        uVar52 = (undefined2)((uint)pcVar32 >> 0x10);
        uVar56 = CONCAT31((int3)((uint)extraout_ECX >> 8),bVar12 >> 2) & 0xffffff01;
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
        cVar11 = lex_token_code((c1xx_token *)g_yy_lookahead);
        lVar46 = g_enum_value;
        if (cVar11 != '7') {
          cVar11 = lex_token_code((c1xx_token *)g_yy_lookahead);
          lVar46 = g_enum_value;
          if (cVar11 != 'u') {
            cVar11 = lex_token_code((c1xx_token *)g_yy_lookahead);
            lVar46 = g_enum_value;
            if (cVar11 != '6') {
              parse_report_inserted_token(g_yy_lookahead,0x37);
              lex_unget_token((c1xx_token *)g_yy_lookahead);
              g_yy_lookahead = &token_static_for_code(0x37)->code;
              lVar46 = g_enum_value;
            }
          }
        }
        break;
      case 0x9f:
        pcVar32 = value_word0(pcVar14->cell);
        access_check_member(pcVar32);
        bVar12 = pcVar14[-1].spec.spec[0];
        iVar25 = 1;
        pcVar32 = value_word0(pcVar14->cell);
        uVar48 = SUB41(pcVar32,0);
        uVar50 = (undefined1)((uint)pcVar32 >> 8);
        uVar52 = (undefined2)((uint)pcVar32 >> 0x10);
        uVar56 = CONCAT31((int3)((uint)pcVar32 >> 8),bVar12 >> 2) & 0xffffff01;
        uVar49 = (undefined1)uVar56;
        uVar51 = (undefined1)(uVar56 >> 8);
        uVar41 = (undefined2)(uVar56 >> 0x10);
LAB_10466526:
        class_check_base_of_symbol
                  (bVar12 & 3,CONCAT22(uVar41,CONCAT11(uVar51,uVar49)),
                   (c1_symbol *)CONCAT22(uVar52,CONCAT11(uVar50,uVar48)),iVar25);
LAB_10420ed7:
        g_compile_flags_c4 = g_compile_flags_c4 | 1;
        pcVar38 = in_stack_00000014;
        lVar46 = g_enum_value;
        break;
      case 0xa0:
        diag_error(0x348);
        lVar46 = g_enum_value;
        break;
      case 0xa2:
        pcVar38[1].spec.spec[0] = pcVar38[1].spec.spec[0] & 0xe0;
        lVar46 = g_enum_value;
        break;
      case 0xa3:
        bVar12 = pcVar38[1].spec.spec[0];
        if ((bVar12 & 3) == 0) {
          pcVar38[1].spec.spec[0] =
               ((byte)g_tree_op_to_il_op[(pcVar14->spec).spec[0]] ^ bVar12) & 3 ^ bVar12;
          lVar46 = g_enum_value;
        }
        else if ((bVar12 & 8) == 0) {
          diag_error(0x1f6);
          pcVar38[1].spec.spec[0] = pcVar38[1].spec.spec[0] | 8;
          lVar46 = g_enum_value;
        }
        break;
      case 0xa4:
        bVar12 = pcVar38[1].spec.spec[0];
        if ((bVar12 & 4) == 0) {
          pcVar38[1].spec.spec[0] = bVar12 | 4;
          lVar46 = g_enum_value;
        }
        else if ((bVar12 & 0x10) == 0) {
          diag_error(0x1fb);
          pcVar38[1].spec.spec[0] = pcVar38[1].spec.spec[0] | 0x10;
          lVar46 = g_enum_value;
        }
        break;
      case 0xa7:
      case 0xa8:
        diag_error(0x2f8);
        lVar46 = g_enum_value;
        break;
      case 0xa9:
        lVar46 = enum_warn_value_wrapped(lVar46,pcVar14->ptr);
        acStack_24[1] = 0x10420f95;
        g_enum_value = lVar46;
        enum_declare(pcVar14->name,g_current_enum_type,(c1_u32)lVar46,
                     (int)((ulonglong)lVar46 >> 0x20));
        g_compile_flags_c4 = g_compile_flags_c4 | 1;
        lVar46 = g_enum_value;
        break;
      case 0xaa:
        if ((g_compile_flags_cc & 0x100000) != 0) {
          pcVar27 = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
          pcVar27 = parse_skip_tokens_to_one_of(pcVar27);
          token_source_unget((c1_token_reader *)&g_token_position,pcVar27);
          g_yylval = (uint)g_type_int;
          _g_yylval_word2 = 1;
          _g_yylval_word3 = 0;
          pcVar32 = value_word0((c1_symbol **)&g_token_arena_index);
          pcVar29 = arena_or_pool_alloc(0x30,(int)pcVar32);
          if (pcVar29 == (c1_u8 *)0x0) goto LAB_10466f79;
          g_yy_lookahead = token_init(pcVar29,'e',&g_yylval);
          lVar46 = g_enum_value;
        }
        break;
      case 0xab:
        enum_declare(pcVar14[-3].name,g_current_enum_type,pcVar14->words[0],pcVar14->words[1]);
        if (((g_prototype_scope_depth == 0) && ((g_compile_flags_c4 & 0x8000000) == 0)) &&
           ((g_paren_depth == 0 &&
            (((g_compile_flags_c8 & 0x40000000) == 0 && ((g_compile_flags_cc & 8) == 0)))))) {
          arena_reset(5);
        }
        g_compile_flags_c4 = g_compile_flags_c4 | 1;
        lVar46 = g_enum_value;
        break;
      case 0xac:
      case 0xad:
        if ((((g_prototype_scope_depth == 0) && ((g_compile_flags_c4 & 0x8000000) == 0)) &&
            (g_paren_depth == 0)) &&
           (((g_compile_flags_c8 & 0x40000000) == 0 && ((g_compile_flags_cc & 8) == 0)))) {
          arena_reset(5);
          lVar46 = g_enum_value;
        }
        g_string_literal_cur = &g_string_literal_buffer;
      case 0x16c:
        g_compile_flags_c4 = g_compile_flags_c4 & 0xfffffffe;
        g_enum_value = lVar46;
        g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfc;
        lVar46 = g_enum_value;
        break;
      case 0xaf:
        pcVar14 = pcVar14 + -1;
        pcVar42 = (c1_u32 *)&stack0x000000dc;
        for (iVar25 = 9; iVar25 != 0; iVar25 = iVar25 + -1) {
          *pcVar42 = pcVar14->words[0];
          pcVar14 = (c1_yy_value *)(pcVar14->words + 1);
          pcVar42 = pcVar42 + 1;
        }
        pcVar34 = decl_declarator_alloc();
        if (pcVar34 == (c1_declarator *)0x0) {
          pcVar34 = (c1_declarator *)0x0;
        }
        else {
          pcVar34 = declarator_set_position(pcVar34);
        }
        decl_declarator_set_specifiers(pcVar34,(c1xx_decl_specifiers *)&stack0x000000dc);
        class_begin_member_list(pcVar34,(c1xx_decl_specifiers *)&stack0x000000dc,(c1_symbol **)0x0);
        lVar46 = g_enum_value;
        break;
      case 0xb1:
        pcVar14 = pcVar14 + -2;
        pcVar42 = (c1_u32 *)&stack0x00000148;
        for (iVar25 = 9; iVar25 != 0; iVar25 = iVar25 + -1) {
          *pcVar42 = pcVar14->words[0];
          pcVar14 = (c1_yy_value *)(pcVar14->words + 1);
          pcVar42 = pcVar42 + 1;
        }
        class_check_unnamed_class_member((c1xx_decl_specifiers *)&stack0x00000148);
        lVar46 = g_enum_value;
        break;
      case 0xb3:
        if ((((c1_symbol_tail *)(pcVar14[-1].declarator)->unk2c)->fn).op_token == '\x01') {
          cVar10 = value_byte1_bit4((c1_symbol *)pcVar14[-1].declarator);
          lVar46 = g_enum_value;
          if (cVar10 == '\0') {
            cVar10 = value_byte1_bit5(pcVar14[-1].sym);
            lVar46 = g_enum_value;
            if ((cVar10 == '\0') &&
               ((((c1_symbol_tail *)(pcVar14[-1].declarator)->unk2c)->fn).special_kind == '\0')) {
              sym_name((c1_symbol *)pcVar14[-1].declarator);
              diag_warning(1);
              lVar46 = g_enum_value;
            }
          }
        }
        break;
      case 0xb4:
        class_set_current_access((c1_u8)g_tree_op_to_il_op[pcVar14[-1].spec.spec[0]]);
        lVar46 = g_enum_value;
        break;
      case 0xb5:
        lex_token_code((c1xx_token *)g_yy_lookahead);
        diag_error(0x140);
        class_set_current_access((c1_u8)g_tree_op_to_il_op[(pcVar14->spec).spec[0]]);
        lVar46 = g_enum_value;
        break;
      case 0xb7:
        diag_error(0x14e);
        lex_skip_to_closing_brace('\x01');
        goto LAB_10466782;
      case 0xb9:
        diag_error(0xee);
LAB_10466782:
        if ((g_compile_flags_c8 & 0x40000000) != 0) {
          pcVar27 = (c1xx_token *)lex_peek_token((uint *)&g_token_position);
          cVar11 = lex_token_code(pcVar27);
          if (cVar11 == 0xf7) {
            iVar25 = token_reader_top_kind((c1_token_reader *)&g_token_position);
joined_r0x1046681a:
            if (iVar25 == 0) {
              diag_fatal_simple(0xc9);
            }
          }
        }
LAB_1046681c:
        parse_yyerrok(parser);
        lVar46 = g_enum_value;
        break;
      case 0xba:
        diag_error(0x14e);
        lex_skip_to_closing_brace('\0');
        if ((g_compile_flags_c8 & 0x40000000) != 0) {
          pcVar27 = (c1xx_token *)lex_peek_token((uint *)&g_token_position);
          cVar11 = lex_token_code(pcVar27);
          if (cVar11 != 0xf7) goto LAB_1046681c;
          iVar25 = token_reader_top_kind((c1_token_reader *)&g_token_position);
          goto joined_r0x1046681a;
        }
        goto LAB_1046681c;
      case 0xbe:
      case 0xcd:
        diag_warning(1,0xe4);
        lVar46 = g_enum_value;
        break;
      case 0xbf:
        g_yy_lookahead = &parse_skip_tokens_to_one_of((c1xx_token *)g_yy_lookahead)->code;
        cVar11 = lex_token_code((c1xx_token *)g_yy_lookahead);
        if (cVar11 != '\x7f') {
          lex_unget_token((c1xx_token *)g_yy_lookahead);
          g_yy_lookahead = &token_static_for_code(0x7f)->code;
        }
        parse_yyerrok(parser);
        lVar46 = g_enum_value;
        break;
      case 0xc0:
        g_yy_lookahead = &parse_skip_tokens_to_one_of((c1xx_token *)g_yy_lookahead)->code;
        cVar11 = lex_token_code((c1xx_token *)g_yy_lookahead);
        lVar46 = g_enum_value;
        if (cVar11 != '\x7f') {
          lex_unget_token((c1xx_token *)g_yy_lookahead);
          g_yy_lookahead = &token_static_for_code(0x7f)->code;
          lVar46 = g_enum_value;
        }
switchD_10421905_caseD_18:
        g_enum_value = lVar46;
        parse_yyerrok(parser);
        lVar46 = g_enum_value;
        break;
      case 0xc1:
        pcVar32 = decl_declarator_symbol(pcVar14->declarator);
        if (pcVar32 == (c1_symbol *)0x0) {
          declarator_set_kind(pcVar14->declarator,2);
          g_declarator_paren_base = g_declarator_paren_base + -1;
          pcVar54 = decl_specifiers_current();
          pcVar35 = decl_declarator_record(pcVar14->declarator);
          decl_check_conversion_return_type(pcVar35,pcVar54);
          pcVar35 = decl_declarator_record(pcVar14->declarator);
          decl_finish_declarator(pcVar35);
          pcVar54 = decl_specifiers_current();
          decl_declarator_set_specifiers(pcVar14->declarator,pcVar54);
          ppcVar53 = (c1_symbol **)0x0;
          pcVar54 = decl_specifiers_current();
          cVar10 = class_begin_member_list(pcVar14->declarator,pcVar54,ppcVar53);
          if (cVar10 == '\0') {
            scope_pop_to_kind_if_needed(g_current_scope,'\x01');
          }
          pcVar32 = decl_declarator_symbol(pcVar14->declarator);
          pcVar38[1].sym = pcVar32;
          lVar46 = g_enum_value;
        }
        else {
          pcVar32 = decl_declarator_symbol(pcVar14->declarator);
          pcVar38[1].sym = pcVar32;
          lVar46 = g_enum_value;
        }
        break;
      case 0xc2:
        pcVar23 = expr_resolve_address_of_overload(pcVar14->node);
        bVar12 = expr_is_zero_constant(pcVar23);
        if (bVar12 == 0) {
          diag_error(0x102);
        }
        declarator_set_flags56_bit1(pcVar14[-1].declarator,'\x01');
        declarator_set_kind(pcVar14[-1].declarator,2);
        g_declarator_paren_base = g_declarator_paren_base + -1;
        pcVar54 = decl_specifiers_current();
        pcVar35 = decl_declarator_record(pcVar14[-1].declarator);
        decl_check_conversion_return_type(pcVar35,pcVar54);
        pcVar35 = decl_declarator_record(pcVar14[-1].declarator);
        decl_finish_declarator(pcVar35);
        pcVar54 = decl_specifiers_current();
        decl_declarator_set_specifiers(pcVar14[-1].declarator,pcVar54);
        ppcVar53 = (c1_symbol **)0x0;
        pcVar54 = decl_specifiers_current();
        cVar10 = class_begin_member_list(pcVar14[-1].declarator,pcVar54,ppcVar53);
        if (cVar10 == '\0') {
          scope_pop_to_kind_if_needed(g_current_scope,'\x01');
        }
        pcVar32 = decl_declarator_symbol(pcVar14[-1].declarator);
        pcVar38[1].sym = pcVar32;
        lVar46 = g_enum_value;
        break;
      case 0xc4:
        declarator_set_kind(pcVar14[-2].declarator,1);
        cVar30 = pcVar14->words[1];
        cVar6 = pcVar14->words[0];
        uVar49 = (undefined1)cVar6;
        uVar51 = (undefined1)(cVar6 >> 8);
        uVar41 = (undefined2)(cVar6 >> 0x10);
        pcVar32 = decl_declarator_symbol(pcVar14[-2].declarator);
        cVar11 = type_check_bitfield_width(pcVar32,CONCAT22(uVar41,CONCAT11(uVar51,uVar49)),cVar30);
        decl_set_bitfield_width(pcVar14[-2].declarator,cVar11);
        g_declarator_paren_base = g_declarator_paren_base + -1;
        pcVar54 = decl_specifiers_current();
        pcVar35 = decl_declarator_record(pcVar14[-2].declarator);
        decl_check_conversion_return_type(pcVar35,pcVar54);
        pcVar35 = decl_declarator_record(pcVar14[-2].declarator);
        decl_finish_declarator(pcVar35);
        pcVar54 = decl_specifiers_current();
        decl_declarator_set_specifiers(pcVar14[-2].declarator,pcVar54);
        ppcVar53 = (c1_symbol **)0x0;
        pcVar54 = decl_specifiers_current();
        cVar10 = class_begin_member_list(pcVar14[-2].declarator,pcVar54,ppcVar53);
        if (cVar10 == '\0') {
          scope_pop_to_kind_if_needed(g_current_scope,'\x01');
        }
        pcVar32 = decl_declarator_symbol(pcVar14[-2].declarator);
        pcVar38[1].sym = pcVar32;
        lVar46 = g_enum_value;
        break;
      case 0xc5:
        pcVar34 = decl_declarator_alloc();
        if (pcVar34 == (c1_declarator *)0x0) {
          pcVar34 = (c1_declarator *)0x0;
        }
        else {
          pcVar34 = decl_declarator_init(pcVar34,g_name_alignment_member,1,(c1_overload_set *)0x0);
        }
        cVar30 = pcVar14->words[1];
        cVar6 = pcVar14->words[0];
        uVar49 = (undefined1)cVar6;
        uVar51 = (undefined1)(cVar6 >> 8);
        uVar41 = (undefined2)(cVar6 >> 0x10);
        pcVar32 = decl_declarator_symbol(pcVar34);
        cVar11 = type_check_bitfield_width(pcVar32,CONCAT22(uVar41,CONCAT11(uVar51,uVar49)),cVar30);
        decl_set_bitfield_width(pcVar34,cVar11);
        declarator_set_flags54_bit5(pcVar34,'\x01');
        pcVar54 = decl_specifiers_current();
        pcVar35 = decl_declarator_record(pcVar34);
        decl_check_conversion_return_type(pcVar35,pcVar54);
        pcVar35 = decl_declarator_record(pcVar34);
        decl_finish_declarator(pcVar35);
        pcVar54 = decl_specifiers_current();
        decl_declarator_set_specifiers(pcVar34,pcVar54);
        ppcVar53 = (c1_symbol **)0x0;
        pcVar54 = decl_specifiers_current();
        class_begin_member_list(pcVar34,pcVar54,ppcVar53);
        pcVar32 = decl_declarator_symbol(pcVar34);
        pcVar38[1].sym = pcVar32;
        lVar46 = g_enum_value;
        break;
      case 0xc6:
        scope_pop_to_kind_if_needed(g_current_scope,'\x01');
        pcVar32 = decl_declarator_symbol(pcVar14->declarator);
        pcVar38[1].sym = pcVar32;
        pvVar22 = qualname_resolved_symbol(pcVar14->declarator);
        pcVar34 = (c1_declarator *)pcVar14->cell;
        if (pvVar22 == (void *)0x0) goto LAB_104668f9;
        pbVar16 = qualname_resolved_symbol(pcVar34);
        ns_member_using_declaration(pbVar16);
        lVar46 = g_enum_value;
        break;
      case 199:
        ns_member_using_declaration(&((pcVar14->spec).type_sym)->kind);
        lVar46 = g_enum_value;
        break;
      case 0xca:
        cVar11 = lex_token_code((c1xx_token *)g_yy_lookahead);
        lVar46 = g_enum_value;
        if (cVar11 == '6') {
          pcVar32 = value_word0(pcVar14->cell);
          iVar25 = class_is_innermost_being_defined((int)pcVar32);
          lVar46 = g_enum_value;
          if ((char)iVar25 != '\0') {
            declarator_set_kind(pcVar14->declarator,2);
            g_declarator_paren_base = g_declarator_paren_base + -1;
            pcVar54 = decl_specifiers_current();
            pcVar35 = decl_declarator_record(pcVar14->declarator);
            decl_check_conversion_return_type(pcVar35,pcVar54);
            pcVar35 = decl_declarator_record(pcVar14->declarator);
            decl_finish_declarator(pcVar35);
            pcVar54 = decl_specifiers_current();
            decl_declarator_set_specifiers(pcVar14->declarator,pcVar54);
            g_yy_lookahead = (byte *)lex_unget_token((c1xx_token *)g_yy_lookahead);
            ppcVar53 = (c1_symbol **)0x0;
            pcVar54 = decl_specifiers_current();
            cVar10 = class_begin_member_list(pcVar14->declarator,pcVar54,ppcVar53);
            lVar46 = g_enum_value;
            if (cVar10 == '\0') {
              scope_pop_to_kind_if_needed(g_current_scope,'\x01');
              lVar46 = g_enum_value;
            }
          }
        }
        break;
      case 0xce:
        g_declarator_paren_base = g_declarator_paren_base + -1;
        pcVar54 = decl_specifiers_current();
        pcVar35 = decl_declarator_record(pcVar14->declarator);
        decl_check_conversion_return_type(pcVar35,pcVar54);
        pcVar35 = decl_declarator_record(pcVar14->declarator);
        decl_finish_declarator(pcVar35);
        pcVar54 = decl_specifiers_current();
        decl_declarator_set_specifiers(pcVar14->declarator,pcVar54);
        if (((g_compile_flags_c8 & 0x40) == 0) && ((g_compile_flags_cc & 0x200000) == 0)) {
          pcVar54 = decl_specifiers_current();
          decl_declare_from_declarator(pcVar14->declarator,pcVar54->spec);
        }
        scope_pop_to_kind_if_needed(g_current_scope,'\x01');
        lVar46 = g_enum_value;
        break;
      case 0xcf:
        if (g_opt_Zg == '\0') {
          pcVar32 = decl_declarator_symbol(pcVar14[-1].declarator);
          cVar10 = decl_check_function_style_initializer(pcVar32);
          if (cVar10 == '\0') {
            g_declarator_paren_base = g_declarator_paren_base + -1;
            decl_set_has_initializer(pcVar14[-1].declarator,'\x01');
            pcVar54 = decl_specifiers_current();
            pcVar35 = decl_declarator_record(pcVar14[-1].declarator);
            decl_check_conversion_return_type(pcVar35,pcVar54);
            pcVar35 = decl_declarator_record(pcVar14[-1].declarator);
            decl_finish_declarator(pcVar35);
            pcVar54 = decl_specifiers_current();
            decl_declarator_set_specifiers(pcVar14[-1].declarator,pcVar54);
            pcVar54 = decl_specifiers_current();
            pcVar32 = decl_declare_and_check(pcVar14[-1].declarator,pcVar54->spec);
            decl_record_set_symbol(pcVar14[-1].ptr,pcVar32);
            pcVar32 = decl_declarator_symbol(pcVar14[-1].declarator);
            pcVar32 = (c1_symbol *)decl_begin_initialized_definition(pcVar32);
            decl_record_set_symbol(pcVar14[-1].ptr,pcVar32);
            pcVar32 = decl_declarator_symbol(pcVar14[-1].declarator);
            if (pcVar32 != (c1_symbol *)0x0) {
              pcVar32 = decl_declarator_symbol(pcVar14[-1].declarator);
              init_set_target_symbol(pcVar32);
              pcVar23 = pcVar14->node;
              pcVar32 = decl_declarator_symbol(pcVar14[-1].declarator);
              decl_finish_initialization(pcVar32,pcVar23);
              scope_pop_to_kind_if_needed(g_current_scope,'\x01');
              pcVar34 = pcVar14[-1].declarator;
              goto LAB_10421651;
            }
          }
        }
        goto LAB_10422a54;
      case 0xd1:
        if ((g_opt_Zg != '\0') || (pcVar14[-2].words[0] == 0)) goto LAB_10422a54;
        pcVar23 = pcVar14->node;
        if ((pcVar23 != (c1_node *)0x0) && (pcVar23->op == 0xe8)) {
          pcVar23 = property_build_access('\x01',pcVar23,(c1_node *)0x0);
          pcVar14->node = pcVar23;
        }
        pcVar32 = decl_declarator_symbol(pcVar14[-2].declarator);
        init_set_target_symbol(pcVar32);
        g_compile_flags_c8 = g_compile_flags_c8 | 0x80000;
        g_compile_flags_cc = g_compile_flags_cc | 0x80000;
        pcVar23 = expr_resolve_address_of_overload(pcVar14->node);
        pcVar32 = decl_declarator_symbol(pcVar14[-2].declarator);
        decl_finish_initialization(pcVar32,pcVar23);
        g_compile_flags_cc = g_compile_flags_cc & 0xfff7ffff;
        g_compile_flags_c8 = g_compile_flags_c8 & 0xfff7ffff;
        scope_pop_to_kind_if_needed(g_current_scope,'\x01');
        pcVar34 = pcVar14[-2].declarator;
LAB_10421651:
        pcVar32 = decl_declarator_symbol(pcVar34);
        type_check_destructible_2(pcVar32);
        g_string_literal_cur = &g_string_literal_buffer;
        lVar46 = g_enum_value;
        break;
      case 0xd2:
        if (g_opt_Zg == '\0') {
          cVar10 = '\0';
          pcVar32 = decl_declarator_symbol(pcVar14->declarator);
          init_begin(pcVar32,cVar10);
          g_compile_flags_cc = g_compile_flags_cc | 0x80000;
          g_brace_init_active = 1;
          lVar46 = g_enum_value;
        }
        break;
      case 0xd3:
        pcVar32 = decl_declarator_symbol(pcVar14[-5].declarator);
        init_finish(pcVar32);
        g_compile_flags_cc = g_compile_flags_cc & 0xfff7ffff;
        if (g_opt_Zg == '\0') {
          pcVar32 = decl_declarator_symbol(pcVar14[-5].declarator);
          type_check_destructible_2(pcVar32);
        }
        scope_pop_to_kind_if_needed(g_current_scope,'\x01');
        lVar46 = g_enum_value;
        break;
      case 0xd4:
        pcVar54 = decl_specifiers_current();
        pcVar35 = decl_declarator_record(pcVar14[-1].declarator);
        decl_check_conversion_return_type(pcVar35,pcVar54);
        pcVar35 = decl_declarator_record(pcVar14[-1].declarator);
        decl_finish_declarator(pcVar35);
        pcVar54 = decl_specifiers_current();
        decl_declarator_set_specifiers(pcVar14[-1].declarator,pcVar54);
        g_declarator_paren_base = g_declarator_paren_base + -1;
        lVar46 = g_enum_value;
        if (g_opt_Zg == '\0') {
          decl_set_has_initializer(pcVar14[-1].declarator,'\x01');
          pcVar54 = decl_specifiers_current();
          decl_declarator_set_specifiers(pcVar14[-1].declarator,pcVar54);
          pcVar54 = decl_specifiers_current();
          pcVar32 = decl_declare_and_check(pcVar14[-1].declarator,pcVar54->spec);
          decl_record_set_symbol(pcVar14[-1].ptr,pcVar32);
          pcVar32 = decl_declarator_symbol(pcVar14[-1].declarator);
          decl_begin_initialized_definition(pcVar32);
          g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] | 2;
          lVar46 = g_enum_value;
        }
        break;
      case 0xd5:
        decl_specifiers_current();
        diag_error(0x201);
        pcVar38[1].words[0] = 0;
        lVar46 = g_enum_value;
        break;
      case 0xd8:
        if (g_opt_Zg == '\0') {
          iVar25 = 0;
          pcVar23 = expr_resolve_address_of_overload(pcVar14->node);
          init_process_initializer(pcVar23,iVar25);
        }
        g_string_literal_cur = &g_string_literal_buffer;
        lVar46 = g_enum_value;
        break;
      case 0xd9:
        if (g_opt_Zg == '\0') {
          init_check_too_many_2();
          lVar46 = g_enum_value;
        }
        break;
      case 0xda:
        if (g_opt_Zg == '\0') {
          init_pop_brace_level();
          lVar46 = g_enum_value;
        }
        break;
      case 0xdb:
        if (g_yy_lookahead == (byte *)0x0) {
          g_yy_lookahead = token_next((c1_token_reader *)&g_token_position);
        }
        cVar11 = lex_token_code((c1xx_token *)g_yy_lookahead);
        lVar46 = g_enum_value;
        switch(cVar11) {
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
          bVar45 = g_paren_depth == 0;
          goto LAB_10421837;
        case 'j':
        case '~':
          bVar45 = g_paren_depth != 0;
LAB_10421837:
          if (!bVar45) {
switchD_1042181a_caseD_35:
            bVar12 = (-(g_paren_depth != 0) & 0xb8U) + 0x7f;
            in_stack_00000034 = CONCAT31(in_stack_00000034._1_3_,bVar12);
            parse_report_inserted_token(g_yy_lookahead,(uint)bVar12);
            lex_unget_token((c1xx_token *)g_yy_lookahead);
            g_yy_lookahead = &token_static_for_code(in_stack_00000034)->code;
            lVar46 = g_enum_value;
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
        pvVar22 = pcVar14->ptr;
        piVar20 = decl_declarator_record(pcVar38[1].declarator);
        decl_append_function_layer(piVar20,pvVar22);
        lVar46 = g_enum_value;
        break;
      case 0xde:
        pcVar34 = pcVar14->declarator;
        pcVar14 = pcVar14 + -1;
        goto LAB_1042192a;
      case 0xe0:
        if (pcVar14[-1].node == (c1_node *)0x0) {
          in_stack_00000020 = 0;
        }
        else {
          in_stack_00000020 = expr_eval_constant_expression(pcVar14[-1].node);
          if (((g_class_depth < 0) || (g_ms_extensions == '\0')) && (in_stack_00000020 == 0)) {
            iVar25 = yyparse_cpp_zero_array_bound_error
                               (pcVar38,parser,state_sp_00,0,saved_lookahead,saved_rule);
            return iVar25;
          }
        }
        piVar20 = (int *)&stack0x00000020;
        pcVar35 = decl_declarator_record(pcVar38[1].declarator);
        decl_append_array_layer(pcVar35,piVar20);
        lVar46 = g_enum_value;
        break;
      case 0xe1:
      case 0x125:
      case 0x175:
        pcVar38[1].words[0] = pcVar14[-1].words[0];
        lVar46 = g_enum_value;
      case 0x17f:
        g_enum_value = lVar46;
        parse_paren_depth_pop();
        lVar46 = g_enum_value;
        break;
      case 0xe2:
        pcVar34 = pcVar14->declarator;
        pcVar14 = pcVar14 + -1;
        pcVar35 = decl_declarator_record(pcVar34);
        type_check_based_form(pcVar35,&pcVar14->mods);
        pcVar38[1].words[0] = (c1_u32)pcVar34;
        lVar46 = g_enum_value;
        break;
      case 0xe4:
        pcVar34 = pcVar14->declarator;
        cVar10 = declarator_flags56_bit0(pcVar34);
        if (cVar10 != '\0') {
          pcVar54 = &g_conversion_type_specifiers;
          pcVar35 = decl_declarator_record(pcVar34);
          decl_record_set_conversion_type(pcVar35,pcVar54);
        }
        pcVar38[1].words[0] = (c1_u32)pcVar34;
        lVar46 = g_enum_value;
        break;
      case 0xe5:
        pcVar34 = decl_declarator_alloc();
        if (pcVar34 == (c1_declarator *)0x0) {
LAB_10466a12:
          pcVar34 = (c1_declarator *)0x0;
        }
        else {
          pcVar34 = decl_declarator_init(pcVar34,pcVar14->name,0,(c1_overload_set *)0x0);
        }
        goto LAB_10421a04;
      case 0xe6:
        pcVar34 = decl_declarator_alloc();
        if (pcVar34 == (c1_declarator *)0x0) {
          pcVar34 = (c1_declarator *)0x0;
        }
        else {
          pcVar55 = (c1_overload_set *)0x0;
          uVar49 = 0;
          uVar51 = 0;
          uVar41 = 0;
          pcVar32 = value_word0(pcVar14->cell);
          pcVar34 = decl_declarator_init
                              (pcVar34,(fe_name *)pcVar32,CONCAT22(uVar41,CONCAT11(uVar51,uVar49)),
                               pcVar55);
        }
        pvVar22 = decl_declarator_record(pcVar14->declarator);
        if (pvVar22 == (void *)0x0) {
          pcVar32 = (c1_symbol *)sym_name(pcVar14->sym);
        }
        else {
          pcVar32 = (c1_symbol *)sym_name(pcVar14->sym);
        }
        iVar25 = sym_scope_index(pcVar32);
        if (iVar25 != 0) {
          pcVar32 = sym_scope_by_index(pcVar32,0x1c);
          decl_record_set_qualifying_class(pcVar34,pcVar32);
        }
        goto LAB_10421a04;
      case 0xe7:
        pcVar34 = decl_declarator_alloc();
        if (pcVar34 == (c1_declarator *)0x0) goto LAB_10466a12;
        pcVar55 = (c1_overload_set *)0x0;
        uVar49 = 0;
        uVar51 = 0;
        uVar41 = 0;
        pfVar31 = sym_name_of_ref(pcVar14->cell);
        pcVar34 = decl_declarator_init
                            (pcVar34,pfVar31,CONCAT22(uVar41,CONCAT11(uVar51,uVar49)),pcVar55);
LAB_10421a04:
        cVar10 = class_name_is_current_class(pcVar34);
        if (cVar10 == '\0') {
LAB_10421a0f:
          pcVar38[1].declarator = pcVar34;
          lVar46 = g_enum_value;
        }
        else {
          decl_set_is_constructor(pcVar34,'\x01');
          pcVar38[1].declarator = pcVar34;
          lVar46 = g_enum_value;
        }
        break;
      case 0xe8:
      case 0x1b2:
        goto switchD_10421905_caseD_e5;
      case 0xe9:
        pcVar34 = decl_declarator_alloc();
        if (pcVar34 == (c1_declarator *)0x0) {
          pcVar34 = (c1_declarator *)0x0;
        }
        else {
          pcVar34 = decl_declarator_init(pcVar34,pcVar14->name,0,(c1_overload_set *)0x0);
        }
        cVar10 = class_name_is_current_class(pcVar34);
        if (cVar10 == '\0') {
joined_r0x10466b1f:
          if (g_class_depth < 0) {
            value_word0((c1_symbol **)pcVar34);
            goto LAB_10466b2d;
          }
LAB_10466aa7:
          diag_error(0x20b);
          pvVar22 = class_current_definition_name();
          decl_set_name(pcVar34,pvVar22);
          goto LAB_10421ad0;
        }
        decl_set_is_destructor(pcVar34,'\x01');
        pcVar38[1].declarator = pcVar34;
        lVar46 = g_enum_value;
        break;
      case 0xea:
        pcVar32 = value_word0(pcVar14->cell);
        pcVar34 = decl_declarator_alloc();
        if (pcVar34 == (c1_declarator *)0x0) {
          pcVar34 = (c1_declarator *)0x0;
        }
        else {
          pcVar34 = decl_declarator_init(pcVar34,(fe_name *)pcVar32,0,(c1_overload_set *)0x0);
        }
        cVar10 = class_name_is_current_class(pcVar34);
        if (cVar10 != '\0') goto LAB_10421ad0;
        if (-1 < g_class_depth) goto LAB_10466aa7;
LAB_10466b2d:
        diag_error(0x24c);
        pcVar38[1].declarator = pcVar34;
        lVar46 = g_enum_value;
        break;
      case 0xeb:
        pcVar34 = decl_declarator_alloc();
        if (pcVar34 == (c1_declarator *)0x0) {
          pcVar34 = (c1_declarator *)0x0;
        }
        else {
          pcVar55 = (c1_overload_set *)0x0;
          uVar49 = 0;
          uVar51 = 0;
          uVar41 = 0;
          pfVar31 = sym_name_of_ref(pcVar14->cell);
          pcVar34 = decl_declarator_init
                              (pcVar34,pfVar31,CONCAT22(uVar41,CONCAT11(uVar51,uVar49)),pcVar55);
        }
        cVar10 = class_name_is_current_class(pcVar34);
        if (cVar10 == '\0') goto joined_r0x10466b1f;
LAB_10421ad0:
        decl_set_is_destructor(pcVar34,'\x01');
        pcVar38[1].declarator = pcVar34;
        lVar46 = g_enum_value;
        break;
      case 0xec:
        pcVar34 = decl_declarator_alloc();
        if (pcVar34 == (c1_declarator *)0x0) {
          value_set_byte30((c1_declarator *)0x0,(pcVar14->spec).spec[0]);
          pcVar38[1].words[0] = 0;
          lVar46 = g_enum_value;
        }
        else {
          pcVar34 = decl_declarator_init(pcVar34,(pcVar14->mods).based,0,(c1_overload_set *)0x0);
          value_set_byte30(pcVar34,(pcVar14->spec).spec[0]);
          pcVar38[1].declarator = pcVar34;
          lVar46 = g_enum_value;
        }
        break;
      case 0xed:
        pcVar54 = &g_conversion_type_specifiers;
        for (iVar25 = 9; iVar25 != 0; iVar25 = iVar25 + -1) {
          *(c1_u32 *)pcVar54->spec = pcVar14->words[0];
          pcVar14 = (c1_yy_value *)(pcVar14->words + 1);
          pcVar54 = (c1xx_decl_specifiers *)(pcVar54->spec + 4);
        }
        pcVar34 = decl_declarator_alloc();
        if (pcVar34 == (c1_declarator *)0x0) {
          pcVar34 = (c1_declarator *)0x0;
        }
        else {
          pcVar55 = (c1_overload_set *)0x0;
          uVar49 = 0;
          uVar51 = 0;
          uVar41 = 0;
          pfVar31 = decl_conversion_function_name(g_conversion_type_specifiers.type);
          pcVar34 = decl_declarator_init
                              (pcVar34,pfVar31,CONCAT22(uVar41,CONCAT11(uVar51,uVar49)),pcVar55);
        }
        value_set_byte30(pcVar34,0x8f);
        declarator_set_flags56_bit0(pcVar34,'\x01');
        g_compile_flags_c4 = g_compile_flags_c4 & 0xfffffffb;
        pcVar38[1].declarator = pcVar34;
        lVar46 = g_enum_value;
        break;
      case 0xee:
        if (pcVar14->cell == (c1_symbol **)0x0) {
          action_slot.sym = (c1_symbol *)0x0;
          d.sym = action_slot.sym;
        }
        else {
          pcVar15 = value_word0(pcVar14->cell);
          pcVar32 = *(c1_symbol **)(*(int *)pcVar15->type + 8);
          pcVar34 = decl_declarator_alloc();
          if (pcVar34 == (c1_declarator *)0x0) {
            d.sym = (c1_symbol *)0x0;
          }
          else {
            uVar49 = 0;
            uVar51 = 0;
            uVar41 = 0;
            qualifier = pcVar15;
            pfVar31 = (fe_name *)sym_name(pcVar15);
            d.sym = (c1_symbol *)
                    decl_declarator_init
                              (pcVar34,pfVar31,CONCAT22(uVar41,CONCAT11(uVar51,uVar49)),qualifier);
          }
          action_slot = d;
          lookup_check_symbol_kinds_reversed(*(int **)pcVar15->type);
          bVar12 = pcVar15->flags1;
          if ((bVar12 & 0x40) == 0) {
            if ((bVar12 & 0x10) == 0) {
              lVar46 = g_enum_value;
              if ((bVar12 & 0x20) != 0) {
                decl_set_is_destructor(d.declarator,'\x01');
                lVar46 = g_enum_value;
              }
            }
            else {
              decl_set_is_constructor(d.declarator,'\x01');
              lVar46 = g_enum_value;
            }
          }
          else {
            if ((pcVar32->kind & 0x1f) == 0x11) {
              pcVar32 = (c1_symbol *)ovl_first_function_of_set(pcVar32);
            }
            g_conversion_type_specifiers.type =
                 decl_declarator_record((c1_declarator *)pcVar32->type);
            puVar28 = decl_specifiers_of_symbol((uint *)&stack0x0000016c,pcVar32);
            pcVar54 = &g_conversion_type_specifiers;
            for (iVar25 = 6; iVar25 != 0; iVar25 = iVar25 + -1) {
              *(uint *)pcVar54->spec = *puVar28;
              puVar28 = puVar28 + 1;
              pcVar54 = (c1xx_decl_specifiers *)(pcVar54->spec + 4);
            }
            declarator_set_flags56_bit0(action_slot.declarator,'\x01');
            d = action_slot;
            lVar46 = g_enum_value;
          }
          bVar12 = pcVar32->kind & 0x1f;
          if ((((bVar12 == 0x10) || (bVar12 == 7)) ||
              ((bVar12 == 6 || (((bVar12 == 0x11 || (bVar12 == 8)) || (bVar12 == 0x1b)))))) ||
             ((bVar12 == 0x1a &&
              (((bVar12 = **(byte **)pcVar32->type & 0x1f, bVar12 == 0x10 || (bVar12 == 7)) ||
               (((bVar12 == 6 || ((bVar12 == 0x11 || (bVar12 == 8)))) || (bVar12 == 0x1b)))))))) {
            g_enum_value = lVar46;
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
            bVar12 = pcVar32->kind & 0x1f;
            if (((bVar12 == 0x10) || (bVar12 == 0x11)) || (bVar12 == 0x1b)) {
              pbVar16 = ovl_first_function_of_set(pcVar32);
              value_set_byte30(d.declarator,pbVar16[0x2f]);
              in_stack_00000014[1].declarator = (c1_declarator *)d;
              pcVar38 = in_stack_00000014;
              lVar46 = g_enum_value;
            }
            else {
              value_set_byte30(d.declarator,(pcVar32->tail).fn.op_token);
              in_stack_00000014[1].declarator = (c1_declarator *)d;
              pcVar38 = in_stack_00000014;
              lVar46 = g_enum_value;
            }
            break;
          }
        }
        g_enum_value = lVar46;
        in_stack_00000014[1].declarator = (c1_declarator *)d;
        pcVar38 = in_stack_00000014;
        lVar46 = g_enum_value;
        break;
      case 0xef:
        if (pcVar14[-1].cell == (c1_symbol **)0x0) {
LAB_10466c6d:
          pcVar34 = (c1_declarator *)0x0;
        }
        else {
          pcVar32 = value_word0(pcVar14[-1].cell);
          pcVar54 = &g_conversion_type_specifiers;
          for (iVar25 = 9; iVar25 != 0; iVar25 = iVar25 + -1) {
            *(c1_u32 *)pcVar54->spec = pcVar14->words[0];
            pcVar14 = (c1_yy_value *)(pcVar14->words + 1);
            pcVar54 = (c1xx_decl_specifiers *)(pcVar54->spec + 4);
          }
          decl_qualified_conversion_function_name(pcVar32,g_conversion_type_specifiers.type);
          if (pcVar32->type == (c1_type *)0x0) {
            pcVar34 = decl_declarator_alloc();
            if (pcVar34 == (c1_declarator *)0x0) goto LAB_10466c6d;
            pcVar55 = (c1_overload_set *)0x0;
            uVar49 = 0;
            uVar51 = 0;
            uVar41 = 0;
            pfVar31 = name_new_S();
            pcVar34 = decl_declarator_init
                                (pcVar34,pfVar31,CONCAT22(uVar41,CONCAT11(uVar51,uVar49)),pcVar55);
          }
          else {
            pcVar34 = decl_declarator_alloc();
            if (pcVar34 == (c1_declarator *)0x0) {
              pcVar34 = (c1_declarator *)0x0;
            }
            else {
              uVar49 = 0;
              uVar51 = 0;
              uVar41 = 0;
              pcVar15 = pcVar32;
              pfVar31 = (fe_name *)sym_name(pcVar32);
              pcVar34 = decl_declarator_init
                                  (pcVar34,pfVar31,CONCAT22(uVar41,CONCAT11(uVar51,uVar49)),
                                   (c1_overload_set *)pcVar15);
            }
            lookup_check_symbol_kinds_reversed(*(int **)pcVar32->type);
            if (**(int **)pcVar32->type != 0) {
              pcVar32 = *(c1_symbol **)(**(int **)pcVar32->type + 8);
              if ((pcVar32->kind & 0x1f) == 0xf) {
                pcVar32 = scope_vector_get((short)pcVar32->key_ref);
              }
              decl_record_set_qualifying_class(pcVar34,pcVar32);
            }
            value_set_byte30(pcVar34,0x8f);
            declarator_set_flags56_bit0(pcVar34,'\x01');
            if ((g_compile_flags_cc & 0x200000) != 0) {
              declarator_set_kind(pcVar34,2);
            }
          }
        }
        g_compile_flags_c4 = g_compile_flags_c4 & 0xfffffffb;
        in_stack_00000014[1].declarator = pcVar34;
        pcVar38 = in_stack_00000014;
        lVar46 = g_enum_value;
        break;
      case 0xf0:
        pcVar14 = pcVar38 + 1;
        decl_conversion_function_declarator(&pcVar14->spec,(c1_decl_record *)0x0);
        (pcVar14->spec).spec[0] = (pcVar14->spec).spec[0] & 0x7f;
        lVar46 = g_enum_value;
        break;
      case 0xf1:
        pcVar40 = pcVar38 + 1;
        pcVar35 = decl_declarator_record(pcVar14->declarator);
        decl_conversion_function_declarator(&pcVar40->spec,pcVar35);
        (pcVar40->spec).spec[0] = (pcVar40->spec).spec[0] & 0x7f;
        lVar46 = g_enum_value;
        break;
      case 0xf2:
        param_clause_set_cv_qualifiers(pcVar14[-2].params,&pcVar14[-1].mods);
        param_clause_set_exception_spec(pcVar14[-2].params,pcVar14->words[0]);
        lVar46 = g_enum_value;
        break;
      case 0xf3:
        pcVar29 = class_record_new_kind5();
        pcVar38[1].str.text = pcVar29;
        parse_paren_depth_pop();
        lVar46 = g_enum_value;
        break;
      case 0xf4:
        g_prototype_scope_depth = g_prototype_scope_depth + 1;
        g_block_depth = g_block_depth + '\x01';
        scope_new_block_record(g_current_scope,(c1_sym_list *)0x0);
        lVar46 = g_enum_value;
        break;
      case 0xf5:
        pvVar22 = pcVar14[-2].ptr;
        pcVar38[1].ptr = pvVar22;
        if (pcVar14[-1].sym != (c1_symbol *)0x0) {
          sym_list_append(pvVar22,pcVar14[-1].sym);
        }
        g_prototype_scope_depth = g_prototype_scope_depth + -1;
        g_block_depth = g_block_depth + 0xff;
        parse_paren_depth_pop();
        lVar46 = g_enum_value;
        break;
      case 0xf6:
        if (((((g_block_depth == '\0') || (-1 < g_class_depth)) ||
             ((g_compile_flags_c8 & 0x10000000) != 0)) ||
            ((((g_compile_flags_c8 & 0x40000000) != 0 && ((g_compile_flags_cc & 8) == 0)) &&
             ((g_compile_flags_c4 & 0x200) == 0)))) || ((g_compile_flags_cc & 0x50) != 0)) {
          iVar25 = 0;
        }
        else {
          iVar25 = 4;
        }
        pcVar32 = sym_new_of_kind('\v',g_name_ellipsis,iVar25);
        sym_mark_ellipsis_parameter(pcVar32);
        pcVar33 = type_intern_basic_parts(0x80d,0,0);
        pcVar32->type = pcVar33;
        pcVar17 = (c1_param_clause *)arena5_alloc_1c();
        if (pcVar17 == (c1_param_clause *)0x0) {
          pcVar38[1].words[0] = 0;
          sym_list_append((void *)0x0,pcVar32);
          parse_paren_depth_pop();
          lVar46 = g_enum_value;
        }
        else {
          pcVar17 = optional_value_init(pcVar17,3,(c1_sym_list *)0x0,'\0');
          pcVar38[1].params = pcVar17;
          sym_list_append(pcVar17,pcVar32);
          parse_paren_depth_pop();
          lVar46 = g_enum_value;
        }
        break;
      case 0xf8:
        if (pcVar14->words[0] != 2) goto LAB_10467c9b;
        diag_warning(3,0x122);
        pcVar38[1].words[0] = pcVar14->words[0];
        lVar46 = g_enum_value;
        break;
      case 0xf9:
        pcVar17 = (c1_param_clause *)arena5_alloc_1c();
        if (pcVar17 == (c1_param_clause *)0x0) goto LAB_10465f34;
        cVar10 = '\x01';
        scope = decl_declarator_record((c1_declarator *)g_current_scope);
        params = scope_symbol_list(scope);
        pcVar17 = optional_value_init(pcVar17,3,params,cVar10);
        pcVar38[1].params = pcVar17;
        lVar46 = g_enum_value;
        break;
      case 0xfb:
        g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] | 8;
        lVar46 = g_enum_value;
        break;
      case 0xfc:
        if ((pcVar14->words[0] != 0) &&
           (g_paren_level_arg_lists[g_paren_depth] != (c1_arg_list *)0x0)) {
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
        cVar11 = token_source_reads_source_file((c1_token_reader *)&g_token_position);
        if (cVar11 != '\0') {
          iVar25 = 0;
          pcVar39 = g_idb->vtbl;
          uVar56 = lex_line_number_of_position(&g_token_position);
          (*pcVar39->idb_scope_kind4_end)(g_idb,uVar56,iVar25);
        }
        if ((pcVar14[-1].words[0] != 0) && (pcVar14->node != (c1_node *)0x0)) {
          pcVar23 = expr_resolve_address_of_overload(pcVar14->node);
          if ((g_compile_flags_c8 & 0x40000000) != 0) {
            pcVar23 = tree_copy_to_arena(pcVar23,0);
          }
          tree_attach_typed_link(pcVar23,(pcVar14[-1].sym)->type);
          acStack_24[1] = 0x10421fe2;
          pcVar23 = conv_convert_expression(0xc6,(pcVar14[-1].sym)->type,pcVar23,'\x02','\x04');
          pcVar14->node = pcVar23;
          iVar25 = 2;
          pcVar23 = (c1_node *)expr_finish_full_expression((int)pcVar23);
          pcVar23 = tree_append_list_item((c1_node *)0x0,pcVar23,iVar25);
          pcVar18 = (c1_arg_item *)arena_alloc_n_aligned(0x14,0);
          if (pcVar18 == (c1_arg_item *)0x0) {
            pcVar18 = (c1_arg_item *)0x0;
          }
          else {
            pcVar18 = arg_expression_item_init(pcVar18,pcVar23,'\0','\x01');
          }
          if (g_paren_level_arg_lists[g_paren_depth] == (c1_arg_list *)0x0) {
            pcVar29 = arena_alloc_n_aligned(0xc,0);
            if (pcVar29 == (c1_u8 *)0x0) {
              g_paren_level_arg_lists[g_paren_depth] = (c1_arg_list *)0x0;
            }
            else {
              pcVar19 = tmpl_argument_list_init(pcVar29,pcVar18);
              g_paren_level_arg_lists[g_paren_depth] = pcVar19;
            }
          }
          else {
            tmpl_argument_list_prepend(g_paren_level_arg_lists[g_paren_depth],pcVar18);
          }
        }
        goto joined_r0x10466e52;
      case 0xfe:
        cVar11 = token_source_reads_source_file((c1_token_reader *)&g_token_position);
        if (cVar11 != '\0') {
          iVar25 = 0;
          pcVar39 = g_idb->vtbl;
          uVar56 = lex_line_number_of_position(&g_token_position);
          (*pcVar39->idb_scope_kind4_end)(g_idb,uVar56,iVar25);
        }
        if ((g_compile_flags_c8 & 0x10000000) == 0) {
          diag_error(0x3e);
        }
        pcVar18 = (c1_arg_item *)arena_alloc_n_aligned(0x14,0);
        if (pcVar18 == (c1_arg_item *)0x0) {
          pcVar18 = (c1_arg_item *)0x0;
        }
        else {
          pcVar18 = pch_fixup_list_object_ctor(pcVar18,pcVar14->sym->type,'\0');
        }
        if (g_paren_level_arg_lists[g_paren_depth] == (c1_arg_list *)0x0) {
          pcVar29 = arena_alloc_n_aligned(0xc,0);
          if (pcVar29 == (c1_u8 *)0x0) {
            g_paren_level_arg_lists[g_paren_depth] = (c1_arg_list *)0x0;
          }
          else {
            pcVar19 = tmpl_argument_list_init(pcVar29,pcVar18);
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
        lVar46 = g_enum_value;
switchD_10421905_caseD_5c:
        g_enum_value = lVar46;
        g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfd;
        lVar46 = g_enum_value;
        break;
      case 0xff:
        cVar11 = token_source_reads_source_file((c1_token_reader *)&g_token_position);
        if (cVar11 != '\0') {
          iVar25 = 0;
          pcVar39 = g_idb->vtbl;
          uVar56 = lex_line_number_of_position(&g_token_position);
          (*pcVar39->idb_scope_kind4_end)(g_idb,uVar56,iVar25);
        }
        if ((g_compile_flags_cc & 0x100000) == 0) {
          pcVar23 = arena_alloc(g_arenas + g_expr_arena_index,0x18);
          pcVar23->kind = '\0';
          pcVar23->op = 0xc6;
          pcVar23->left = (void *)pcVar14->words[0];
          pcVar33 = type_intern_basic_parts(0x80e,0,0);
          value_set_field4(pcVar23,pcVar33);
          pcVar23 = tree_append_list_item((c1_node *)0x0,pcVar23,2);
          pcVar18 = (c1_arg_item *)arena_alloc_n_aligned(0x14,0);
          if (pcVar18 == (c1_arg_item *)0x0) {
            pcVar18 = (c1_arg_item *)0x0;
          }
          else {
            pcVar18 = arg_expression_item_init(pcVar18,pcVar23,'\0','\x01');
          }
          if (g_paren_level_arg_lists[g_paren_depth] == (c1_arg_list *)0x0) {
            pcVar29 = arena_alloc_n_aligned(0xc,0);
            if (pcVar29 == (c1_u8 *)0x0) {
              g_paren_level_arg_lists[g_paren_depth] = (c1_arg_list *)0x0;
            }
            else {
              pcVar19 = tmpl_argument_list_init(pcVar29,pcVar18);
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
        cVar11 = token_source_reads_source_file((c1_token_reader *)&g_token_position);
        if (cVar11 != '\0') {
          iVar25 = 0;
          pcVar39 = g_idb->vtbl;
          uVar56 = lex_line_number_of_position(&g_token_position);
          (*pcVar39->idb_scope_kind4_end)(g_idb,uVar56,iVar25);
        }
        cVar11 = lex_token_code((c1xx_token *)g_yy_lookahead);
        if (cVar11 == 'u') {
          diag_error(0x117);
          pcVar27 = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
          parse_skip_tokens_to_one_of(pcVar27);
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
          lVar46 = g_enum_value;
        }
        else {
          g_compile_flags_c8 = g_compile_flags_c8 | 0x8000000;
          parse_default_argument_begin(pcVar14->sym->type);
          func_flow_state_note_3e();
          lVar46 = g_enum_value;
        }
        break;
      case 0x102:
        cVar11 = token_source_reads_source_file((c1_token_reader *)&g_token_position);
        lVar46 = g_enum_value;
        if (cVar11 != '\0') {
          pcVar39 = g_idb->vtbl;
          goto LAB_10422231;
        }
        break;
      case 0x104:
        scope_insert_through_object(g_current_scope,pcVar14->sym);
        lVar46 = g_enum_value;
        break;
      case 0x105:
        pcVar38[1].words[0] = 0;
        if ((g_compile_flags_c8 & 0x30000000) == 0) {
          pcVar27 = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
          pcVar27 = parse_skip_tokens_to_one_of(pcVar27);
          g_yy_lookahead = &pcVar27->code;
LAB_10466f65:
          token_source_unget((c1_token_reader *)&g_token_position,pcVar27);
        }
        else {
          if (g_yy_lookahead == (byte *)0x0) {
LAB_10466f97:
            g_yy_lookahead = token_next((c1_token_reader *)&g_token_position);
          }
          else {
            cVar11 = lex_token_code((c1xx_token *)g_yy_lookahead);
            if (cVar11 != '>') goto LAB_10466f97;
          }
          g_yy_lookahead = &parse_skip_tokens_to_one_of((c1xx_token *)g_yy_lookahead)->code;
          token_source_unget((c1_token_reader *)&g_token_position,(c1xx_token *)g_yy_lookahead);
          cVar11 = lex_token_code((c1xx_token *)g_yy_lookahead);
          if (cVar11 == '\x7f') {
            pcVar27 = token_static_for_code(0x3e);
            goto LAB_10466f65;
          }
        }
        parse_yyerrok(parser);
LAB_10466f79:
        g_yy_lookahead = (byte *)0x0;
        lVar46 = g_enum_value;
        break;
      case 0x106:
        pcVar40 = pcVar14 + -1;
        pcVar42 = (c1_u32 *)&stack0x00000094;
        for (iVar25 = 9; iVar25 != 0; iVar25 = iVar25 + -1) {
          *pcVar42 = pcVar40->words[0];
          pcVar40 = (c1_yy_value *)(pcVar40->words + 1);
          pcVar42 = pcVar42 + 1;
        }
        decl_set_local_key_flag(pcVar14->declarator,'\x01');
        if (((g_compile_flags_c8 & 0x10000000) == 0) || (g_paren_depth != 1)) {
          cVar30 = 5;
        }
        else {
          cVar30 = 0xb;
        }
        declarator_set_kind(pcVar14->declarator,cVar30);
        pcVar54 = (c1xx_decl_specifiers *)&stack0x00000094;
        pcVar35 = decl_declarator_record(pcVar14->declarator);
        decl_check_conversion_return_type(pcVar35,pcVar54);
        pcVar35 = decl_declarator_record(pcVar14->declarator);
        decl_finish_declarator(pcVar35);
        decl_declarator_set_specifiers(pcVar14->declarator,(c1xx_decl_specifiers *)&stack0x00000094)
        ;
        decl_declare_in_current_scope(pcVar14->declarator,(c1xx_decl_specifiers *)&stack0x00000094);
        pcVar32 = decl_declarator_symbol(pcVar14->declarator);
        if ((g_compile_flags_c8 & 0x10000000) != 0) {
          pcVar33 = pcVar32->type;
          cVar10 = type_code_is_201(pcVar33);
          if (cVar10 == '\0') {
            cVar10 = type_code_is_202(pcVar33);
            if (cVar10 != '\0') {
              iVar25 = yyparse_cpp_class_template_parameter_error
                                 (pcVar32,pcVar38,parser,state_sp_00,saved_lookahead,saved_rule);
              return iVar25;
            }
          }
          else if ((pcVar32->storage & 0x80) == 0) {
            diag_error(0x3e1);
            pcVar32->flags3 = pcVar32->flags3 | 4;
          }
        }
        g_declarator_paren_base = g_declarator_paren_base + -1;
        scope_pop_to_kind_if_needed(g_current_scope,'\x01');
        g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfc;
        pcVar38[1].sym = pcVar32;
        lVar46 = g_enum_value;
        break;
      case 0x107:
        bVar45 = false;
        decl_set_local_key_flag(pcVar14->declarator,'\x01');
        if (((g_compile_flags_c8 & 0x10000000) == 0) || (g_paren_depth != 1)) {
          cVar30 = 6;
        }
        else {
          cVar30 = 0xb;
        }
        declarator_set_kind(pcVar14->declarator,cVar30);
        decl_set_name(pcVar14->declarator,g_name_formal);
        if ((((g_compile_flags_c8 & 0x10000000) != 0) &&
            (*(byte **)((int)pcVar14 + -0xc) != (byte *)0x0)) &&
           ((**(byte **)((int)pcVar14 + -0xc) & 0x1f) == 4)) {
          pcVar33 = type_innermost_base(*(c1_type **)((int)pcVar14 + -0x10));
          if (((pcVar33->code & 0x20f) == 0x201) && ((pcVar14[-1].spec.spec[0] & 0x80) == 0)) {
            iVar25 = sym_scope_index(*(c1_symbol **)((int)pcVar14 + -0xc));
            if (iVar25 == 0) {
              bVar45 = true;
              pvVar22 = (void *)sym_name(*(c1_symbol **)((int)pcVar14 + -0xc));
              if ((*(uint *)((int)pvVar22 + 8) & 0x2000000) != 0) {
                cell = lookup_name_in_context(g_current_scope,pvVar22,0x20);
                if (cell != (c1_lookup_entry *)0x0) {
                  value_word0(&cell->sym);
                }
                diag_error(0x3af);
              }
              decl_set_name(pcVar14->declarator,pvVar22);
            }
          }
        }
        pcVar34 = pcVar14->declarator;
        pcVar38 = pcVar14 + -1;
        (pcVar38->spec).spec[0] = pcVar14[-1].spec.spec[0] & 0x7f;
        pcVar40 = pcVar38;
        pcVar35 = decl_declarator_record(pcVar34);
        decl_check_conversion_return_type(pcVar35,&pcVar40->spec);
        pcVar35 = decl_declarator_record(pcVar14->declarator);
        decl_finish_declarator(pcVar35);
        decl_declarator_set_specifiers(pcVar14->declarator,&pcVar38->spec);
        decl_process_declaration(pcVar14->declarator);
        pcVar32 = sym_new_from_declarator(pcVar14->declarator,0xffffffff);
        if (bVar45) {
          bVar12 = type_code_high_bit(pcVar32->type);
          if (bVar12 != 0) {
            sym_name(pcVar32);
            diag_error(0x395);
            pcVar32->flags3 = pcVar32->flags3 | 4;
          }
        }
        g_declarator_paren_base = g_declarator_paren_base + -1;
        g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfc;
        in_stack_00000014[1].sym = pcVar32;
        pcVar38 = in_stack_00000014;
        lVar46 = g_enum_value;
        break;
      case 0x108:
      case 0x10f:
switchD_10421905_caseD_105:
        g_enum_value = lVar46;
        pair_clear(&pcVar38[1].mods);
        lVar46 = g_enum_value;
        break;
      case 0x10b:
      case 0x112:
        qualified_type_merge(&pcVar38[1].mods,&pcVar14->mods,(c1_u32)g_yy_lookahead);
        lVar46 = g_enum_value;
        break;
      case 0x10c:
        diag_warning(1,0xe6);
        lVar46 = g_enum_value;
        break;
      case 0x10d:
        operator_id_set(&pcVar38[1].mods,(short)g_tree_op_to_il_op[(pcVar14->spec).spec[0]],
                        (void *)0x0);
        lVar46 = g_enum_value;
        break;
      case 0x10e:
        pcVar38[1].words[0] = pcVar14[-1].words[0];
        *(undefined4 *)((int)pcVar38 + 0x2c) = *(undefined4 *)((int)pcVar14 + -0x24);
        parse_paren_depth_pop();
        g_compile_flags_c4 = g_compile_flags_c4 & 0x7fffffff;
        lVar46 = g_enum_value;
        if ((g_compile_flags_c8 & 0x10) != 0) {
          g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfc;
          lVar46 = g_enum_value;
        }
        break;
      case 0x113:
        operator_id_set(&pcVar38[1].mods,(short)g_tree_op_to_il_op[(pcVar14->spec).spec[0]],
                        (void *)0x0);
        lVar46 = g_enum_value;
        break;
      case 0x114:
        operator_id_set(&pcVar38[1].mods,(pcVar14->ptr_op).kind,(void *)0x0);
        lVar46 = g_enum_value;
        break;
      case 0x115:
        bits = value_u16_at2((pcVar14->spec).type);
        pcVar33 = type_without_flags((pcVar14->spec).type,0x3e0);
        (pcVar14->spec).type = pcVar33;
        decl_warn_unexpected_specifiers_1(&pcVar14->spec);
        operator_id_set(&pcVar38[1].mods,bits,(void *)0x0);
        lVar46 = g_enum_value;
        break;
      case 0x116:
        pcVar32 = type_parse_based_specifier(pcVar14->ptr);
        operator_id_set(&pcVar38[1].mods,0x18,pcVar32);
        lVar46 = g_enum_value;
        break;
      case 0x117:
        pcVar23 = expr_check_this_usage();
        lVar46 = g_enum_value;
        if (pcVar23 == (c1_node *)0x0) goto switchD_10421905_caseD_105;
        break;
      case 0x118:
        operator_id_set(&pcVar38[1].mods,8,(void *)0x0);
        lVar46 = g_enum_value;
        break;
      case 0x119:
        pair_clear(&pcVar38[1].mods);
        lVar46 = g_enum_value;
        goto switchD_10421905_caseD_14f;
      case 0x11c:
        pcVar34 = decl_declarator_alloc();
        if (pcVar34 == (c1_declarator *)0x0) goto LAB_10465f34;
        pcVar34 = decl_declarator_init(pcVar34,g_name_abstract_declarator,4,(c1_overload_set *)0x0);
        pcVar38[1].declarator = pcVar34;
        lVar46 = g_enum_value;
        break;
      case 0x11d:
        pcVar34 = decl_declarator_alloc();
        if (pcVar34 == (c1_declarator *)0x0) {
          pcVar35 = decl_declarator_record((c1_declarator *)0x0);
          type_check_based_form(pcVar35,&pcVar14->mods);
          pcVar38[1].words[0] = 0;
          lVar46 = g_enum_value;
        }
        else {
          pcVar34 = decl_declarator_init
                              (pcVar34,g_name_abstract_declarator,4,(c1_overload_set *)0x0);
          pcVar35 = decl_declarator_record(pcVar34);
          type_check_based_form(pcVar35,&pcVar14->mods);
          pcVar38[1].declarator = pcVar34;
          lVar46 = g_enum_value;
        }
        break;
      case 0x11e:
        pcVar34 = decl_declarator_alloc();
        if (pcVar34 == (c1_declarator *)0x0) {
          pvVar22 = pcVar14->ptr;
          pcVar34 = (c1_declarator *)0x0;
        }
        else {
          pcVar34 = decl_declarator_init
                              (pcVar34,g_name_abstract_declarator,4,(c1_overload_set *)0x0);
          pvVar22 = pcVar14->ptr;
        }
        goto LAB_10467272;
      case 0x11f:
        pcVar34 = decl_declarator_alloc();
        if (pcVar34 == (c1_declarator *)0x0) {
          pcVar34 = (c1_declarator *)0x0;
        }
        else {
          pcVar34 = decl_declarator_init
                              (pcVar34,g_name_abstract_declarator,4,(c1_overload_set *)0x0);
        }
        pcVar40 = pcVar14 + -1;
        pcVar35 = decl_declarator_record(pcVar34);
        type_check_based_form(pcVar35,&pcVar40->mods);
        pvVar22 = pcVar14->ptr;
LAB_10467272:
        piVar20 = decl_declarator_record(pcVar34);
        decl_append_function_layer(piVar20,pvVar22);
        goto LAB_10421a0f;
      case 0x120:
        pcVar40 = pcVar14 + -1;
        pcVar35 = decl_declarator_record(pcVar14->declarator);
        decl_declarator_append_pointer_op(pcVar35,&pcVar40->ptr_op);
        lVar46 = g_enum_value;
switchD_10421905_caseD_e5:
        g_enum_value = lVar46;
        pcVar38[1].words[0] = pcVar14->words[0];
        lVar46 = g_enum_value;
        break;
      case 0x122:
        pcVar23 = pcVar14[-1].node;
        pvVar22 = decl_declarator_record(pcVar38[1].declarator);
        type_check_array_bound_constant_2(pvVar22,pcVar23);
        lVar46 = g_enum_value;
        break;
      case 0x123:
        pvVar22 = pcVar14->ptr;
        piVar20 = decl_declarator_record(pcVar38[1].declarator);
        decl_append_function_layer(piVar20,pvVar22);
        lVar46 = g_enum_value;
        break;
      case 0x126:
        pcVar34 = decl_declarator_alloc();
        if (pcVar34 == (c1_declarator *)0x0) {
          pcVar34 = (c1_declarator *)0x0;
          lVar46 = g_enum_value;
        }
        else {
          pcVar34 = decl_declarator_init(pcVar34,(fe_name *)0x0,0,(c1_overload_set *)0x0);
          lVar46 = g_enum_value;
        }
LAB_1042192a:
        g_enum_value = lVar46;
        pcVar35 = decl_declarator_record(pcVar34);
        decl_declarator_append_pointer_op(pcVar35,&pcVar14->ptr_op);
LAB_10421939:
        pcVar38[1].declarator = pcVar34;
        lVar46 = g_enum_value;
        break;
      case 0x127:
      case 0x1e6:
        pcVar40 = pcVar14 + -1;
        pcVar35 = decl_declarator_record(pcVar14->declarator);
        decl_declarator_append_pointer_op(pcVar35,&pcVar40->ptr_op);
        lVar46 = g_enum_value;
LAB_10467c9b:
        g_enum_value = lVar46;
        pcVar38[1].words[0] = pcVar14->words[0];
        lVar46 = g_enum_value;
        break;
      case 0x128:
        in_stack_00000040 = pcVar14[-2].words[0];
        in_stack_00000044 = *(void **)((int)pcVar14 + -0x4c);
        type_pair_record_init
                  (&pcVar38[1].ptr_op,(c1_decl_modifier *)&stack0x00000040,&pcVar14->mods);
        lVar46 = g_enum_value;
        break;
      case 0x129:
        pcVar21 = u16_value_init((c1_decl_modifier *)&stack0x0000008c,0);
        type_pair_record_init(&pcVar38[1].ptr_op,pcVar21,&pcVar14->mods);
        lVar46 = g_enum_value;
        break;
      case 0x12a:
        in_stack_00000048 = pcVar14[-2].words[0];
        in_stack_0000004c = *(void **)((int)pcVar14 + -0x4c);
        type_warn_qualifiers_on_reference
                  (&pcVar38[1].ptr_op,(c1_decl_modifier *)&stack0x00000048,&pcVar14->mods);
        lVar46 = g_enum_value;
        break;
      case 299:
        pcVar21 = u16_value_init((c1_decl_modifier *)&stack0x00000084,0);
        type_warn_qualifiers_on_reference(&pcVar38[1].ptr_op,pcVar21,&pcVar14->mods);
        lVar46 = g_enum_value;
        break;
      case 300:
        in_stack_00000038 = pcVar14[-2].words[0];
        in_stack_0000003c = *(void **)((int)pcVar14 + -0x4c);
        qualified_name_record_init
                  (&pcVar38[1].ptr_op,pcVar14[-1].qualified,(c1_decl_modifier *)&stack0x00000038,
                   &pcVar14->mods);
        lVar46 = g_enum_value;
        break;
      case 0x12e:
        if (((g_block_depth != '\0') && (g_class_depth < 0)) &&
           ((g_compile_flags_c8 & 0x10000000) == 0)) {
          if ((((g_compile_flags_c8 & 0x40000000) != 0) && ((g_compile_flags_cc & 8) == 0)) &&
             ((g_compile_flags_c4 & 0x200) == 0)) {
            iVar25 = yyparse_cpp_ellipsis_parameter_arena0
                               (pcVar38,parser,state_sp_00,saved_lookahead,saved_rule);
            return iVar25;
          }
          if ((g_compile_flags_cc & 0x50) == 0) {
            iVar25 = 4;
            goto LAB_104225ad;
          }
        }
        iVar25 = 0;
        goto LAB_104225ad;
      case 0x12f:
        if (((((g_block_depth == '\0') || (-1 < g_class_depth)) ||
             ((g_compile_flags_c8 & 0x10000000) != 0)) ||
            ((((g_compile_flags_c8 & 0x40000000) != 0 && ((g_compile_flags_cc & 8) == 0)) &&
             ((g_compile_flags_c4 & 0x200) == 0)))) || ((g_compile_flags_cc & 0x50) != 0)) {
          iVar25 = 0;
        }
        else {
          iVar25 = 4;
        }
LAB_104225ad:
        pcVar32 = sym_new_of_kind('\v',g_name_ellipsis,iVar25);
        pcVar38[1].sym = pcVar32;
        pcVar33 = type_intern_basic_parts(0x80d,0,0);
        (pcVar38[1].sym)->type = pcVar33;
        sym_mark_ellipsis_parameter(pcVar38[1].sym);
        lVar46 = g_enum_value;
        break;
      case 0x130:
        if ((g_opt_Zg == '\0') && ((g_compile_flags_c4 & 0x800000) == 0)) {
          if ((pcVar14->spec).spec[0] != 0xaa) {
            func_begin_compound_statement();
          }
          g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfc;
          il_emit_line_record_24();
          lVar46 = g_enum_value;
        }
        else {
          lex_skip_to_closing_brace('\0');
          lVar46 = g_enum_value;
        }
        break;
      case 0x131:
        if ((g_opt_Zg == '\0') && ((g_compile_flags_c4 & 0x800000) == 0)) {
          if (pcVar14[-2].spec.spec[0] != 0xaa) {
            scope_end_block();
            lVar46 = g_enum_value;
          }
        }
        else {
          g_compile_flags_c4 = g_compile_flags_c4 & 0xff7fffff;
        }
        break;
      case 0x135:
        g_compile_flags_c4 = g_compile_flags_c4 & 0xfffffffe;
        if (g_yy_lookahead == (byte *)0x0) {
          bVar12 = g_paren_level_flags[g_paren_depth];
          g_pending_access_check[g_paren_depth] = (c1_symbol *)0x0;
          g_paren_level_flags[iVar24] = bVar12 & 0xfc;
          lVar46 = g_enum_value;
        }
        break;
      case 0x136:
      case 0x165:
        pcVar38[1].spec.spec[0] = '\0';
        lVar46 = g_enum_value;
        break;
      case 0x137:
      case 0x176:
      case 0x1ed:
        pcVar38[1].spec.spec[0] = '\x01';
        lVar46 = g_enum_value;
        break;
      case 0x138:
        pcVar23 = pcVar14[-1].node;
        if (pcVar23 != (c1_node *)0x0) {
          if (pcVar23->op == 0xe8) {
            pcVar23 = property_build_access('t',pcVar23,(c1_node *)0x0);
            pcVar14[-1].node = pcVar23;
          }
          cVar10 = '\x01';
          pcVar23 = expr_resolve_address_of_overload(pcVar14[-1].node);
          pcVar23 = expr_warn_no_effect(pcVar23,cVar10);
          pcVar14[-1].node = pcVar23;
          pcVar23 = expr_full_expression_guarded(pcVar23,2);
          stmt_emit_expression(pcVar23);
        }
        iVar25 = parse_error_recovery_count();
        if (iVar25 != 0) goto LAB_10422a54;
        arena_reset(5);
        g_string_literal_cur = &g_string_literal_buffer;
        lVar46 = g_enum_value;
        break;
      case 0x13b:
        func_end_compound_statement(pcVar14[-1].node,'\0');
        label_emit_definition(pcVar14[-1].node);
        stmt_if_then_end_flow_state(1);
        func_end_compound_statement((c1_node *)0x0,'\x01');
        lVar46 = g_enum_value;
        if ((pcVar14->spec).spec[0] != '\0') {
          diag_warning(3,0x186);
          lVar46 = g_enum_value;
        }
        break;
      case 0x13c:
        func_end_compound_statement(pcVar14[-1].node,'\0');
        label_emit_definition(pcVar14[-1].node);
        stmt_else_end_flow_state();
        func_end_compound_statement((c1_node *)0x0,'\x01');
        lVar46 = g_enum_value;
        break;
      case 0x13d:
        stmt_while_end_flow_state();
        stmt_loop_end();
        func_end_compound_statement((c1_node *)0x0,pcVar14[-1].spec.spec[0]);
        lVar46 = g_enum_value;
        break;
      case 0x13e:
        if (g_ms_extensions != '\0') {
          func_end_compound_statement((c1_node *)0x0,pcVar14[-1].spec.spec[0]);
          stmt_for_end_flow_state();
        }
        stmt_loop_end();
        lVar46 = g_enum_value;
        if (g_ms_extensions == '\0') {
          stmt_for_end_flow_state();
          func_end_compound_statement((c1_node *)0x0,pcVar14[-1].spec.spec[0]);
          lVar46 = g_enum_value;
        }
        break;
      case 0x13f:
        func_flow_state_note_1f();
        stmt_do_head();
        g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfc;
        cVar11 = parse_begin_compound_value((c1_node *)0x0);
        (pcVar14->spec).spec[0] = cVar11;
        lVar46 = g_enum_value;
        break;
      case 0x140:
        func_end_compound_statement((c1_node *)0x0,pcVar14[-4].spec.spec[0]);
        func_flow_state_note_22();
        g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] | 3;
        lVar46 = g_enum_value;
        break;
      case 0x141:
        label_emit_definition(g_continue_label_stack->label);
        if (pcVar14[-2].node != (c1_node *)0x0) {
          pcVar23 = expr_resolve_address_of_overload(pcVar14[-2].node);
          pcVar14[-2].node = pcVar23;
          pcVar23 = stmt_check_controlling_expression(pcVar23,0);
          pcVar14[-2].node = pcVar23;
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
        iVar25 = parse_error_recovery_count();
        if (iVar25 == 0) {
          arena_reset(5);
        }
        g_string_literal_cur = &g_string_literal_buffer;
        stmt_do_end_flow_state();
        parse_paren_depth_pop();
        lVar46 = g_enum_value;
        break;
      case 0x142:
        il_emit_line_record_24();
        il_emit_tuple(0x3a,*(node **)((int)g_break_label_stack + 4));
        stmt_switch_end();
        stmt_warn_switch_without_cases();
        func_end_compound_statement((c1_node *)0x0,pcVar14[-1].spec.spec[0]);
        g_loop_top_label_stack = g_loop_top_label_stack->next;
        g_break_label_stack = *(void **)g_break_label_stack;
        g_switch_case_stack = g_switch_case_stack->next;
        g_default_label_stack = g_default_label_stack->next;
        g_loop_label_count = g_loop_label_count + -4;
        lVar46 = g_enum_value;
        if (g_loop_label_count == 0) {
          arena_reset(6);
          lVar46 = g_enum_value;
        }
        break;
      case 0x143:
        eh_check_leave();
        lVar46 = g_enum_value;
        break;
      case 0x144:
        if (g_break_label_stack == (void *)0x0) {
          diag_error(0x2b);
          lVar46 = g_enum_value;
        }
        else {
          stmt_jump_flow_state();
          il_emit_tuple(0x3a,*(node **)((int)g_break_label_stack + 4));
          lVar46 = g_enum_value;
        }
        break;
      case 0x145:
        if (g_continue_label_stack == (c1xx_label_cell *)0x0) {
          diag_error(0x2c);
          lVar46 = g_enum_value;
        }
        else {
          stmt_jump_flow_state_2();
          il_emit_tuple(0x3a,g_continue_label_stack->label);
          lVar46 = g_enum_value;
        }
        break;
      case 0x146:
        func_flow_state_note_8();
        stmt_emit_return_value((c1_node *)0x0,1);
        lVar46 = g_enum_value;
        break;
      case 0x147:
        func_flow_state_note_8();
        lVar46 = g_enum_value;
        break;
      case 0x148:
        pcVar23 = pcVar14[-1].node;
        if ((pcVar23 != (c1_node *)0x0) && (pcVar23->op == 0xe8)) {
          pcVar23 = property_build_access('\x01',pcVar23,(c1_node *)0x0);
          pcVar14[-1].node = pcVar23;
        }
        pcVar23 = expr_resolve_address_of_overload(pcVar14[-1].node);
        pcVar14[-1].node = pcVar23;
        stmt_emit_return_value(pcVar23,2);
        iVar25 = parse_error_recovery_count();
        if (iVar25 != 0) goto LAB_10422a54;
        arena_reset(5);
        g_string_literal_cur = &g_string_literal_buffer;
        lVar46 = g_enum_value;
        break;
      case 0x149:
        pcVar32 = (c1_symbol *)label_find_in_function(pcVar14[-1].words[0]);
        if (pcVar32 == (c1_symbol *)0x0) {
          pcVar32 = (c1_symbol *)label_new_user(pcVar14[-1].words[0]);
          label_register(pcVar32);
          stmt_goto_flow_state(pcVar32,0);
        }
        else {
          stmt_goto_flow_state(pcVar32,1);
        }
        pcVar23 = tree_new_symbol_ref(pcVar32,'\0');
        il_emit_tuple(0x3a,pcVar23);
        iVar25 = parse_error_recovery_count();
        if (iVar25 == 0) {
          arena_reset(5);
        }
LAB_10422a54:
        g_string_literal_cur = &g_string_literal_buffer;
        lVar46 = g_enum_value;
        break;
      case 0x14a:
        il_emit_line_record_24();
        asm_block_emit();
        lVar46 = g_enum_value;
        break;
      case 0x14b:
        eh_except_end();
        lVar46 = g_enum_value;
        break;
      case 0x14c:
        eh_finally_begin();
        lVar46 = g_enum_value;
        break;
      case 0x14d:
        eh_finally_end();
        lVar46 = g_enum_value;
        break;
      case 0x14f:
        diag_error(0xb5);
        lVar46 = g_enum_value;
        break;
      case 0x152:
        goto switchD_10421905_caseD_14f;
      case 0x153:
        parse_yyerrok(parser);
        g_yy_lookahead = (byte *)0x0;
        uVar56 = 0x7b;
LAB_1046653f:
        pcVar27 = token_static_for_code(uVar56);
        token_source_unget((c1_token_reader *)&g_token_position,pcVar27);
        lVar46 = g_enum_value;
        break;
      case 0x154:
        if (g_yy_lookahead == (byte *)0x0) {
          g_yy_lookahead = yylex_cpp();
          if (g_yy_lookahead == (byte *)0x0) {
            diag_fatal(1);
          }
        }
        cVar11 = lex_token_code((c1xx_token *)g_yy_lookahead);
        if (cVar11 != 'u') {
          diag_error(0x13f);
        }
        eh_check_handling_enabled();
        lVar46 = g_enum_value;
        break;
      case 0x155:
        pending_top_mark();
        lVar46 = g_enum_value;
        break;
      case 0x156:
        eh_check_try_has_catch();
        lVar46 = g_enum_value;
        break;
      case 0x159:
        if (g_yy_lookahead == (byte *)0x0) {
          g_yy_lookahead = yylex_cpp();
          if (g_yy_lookahead == (byte *)0x0) {
            diag_fatal(1);
          }
        }
        cVar11 = lex_token_code((c1xx_token *)g_yy_lookahead);
        if (cVar11 != 'u') {
          diag_error(0x13f);
          lVar46 = g_enum_value;
          break;
        }
        lVar46 = g_enum_value;
        if ((pcVar14->spec).spec[0] == '\0') break;
        g_yylval = CONCAT31(g_yylval._1_3_,0xaa);
        pcVar29 = arena_or_pool_alloc(0x30,4);
        if (pcVar29 != (c1_u8 *)0x0) {
          g_yy_lookahead = token_init(pcVar29,'u',&g_yylval);
          lVar46 = g_enum_value;
          break;
        }
        goto LAB_104671eb;
      case 0x15a:
        scope_end_and_flush_pending_top(pcVar14[-2].spec.spec[0]);
        lVar46 = g_enum_value;
        break;
      case 0x15b:
        decl_pop_declarator_state(pcVar14->params);
        cVar11 = eh_check_catch_type_count(pcVar14->params);
        pcVar38[1].spec.spec[0] = cVar11;
        vtable_nop();
        lVar46 = g_enum_value;
        break;
      case 0x15c:
        diag_error(0x135);
        lVar46 = g_enum_value;
switchD_10421905_caseD_14f:
        g_enum_value = lVar46;
        parse_yyerrok(parser);
LAB_104671eb:
        g_yy_lookahead = (byte *)0x0;
        lVar46 = g_enum_value;
        break;
      case 0x15f:
        parse_paren_depth_pop();
        pcVar38[1].words[0] = 1;
        lVar46 = g_enum_value;
        break;
      case 0x160:
        parse_paren_depth_pop();
        pcVar38[1].words[0] = 2;
        lVar46 = g_enum_value;
        break;
      case 0x161:
        eh_try_begin();
        lVar46 = g_enum_value;
        break;
      case 0x162:
        eh_try_block_end();
        lVar46 = g_enum_value;
        break;
      case 0x163:
        eh_except_filter_begin();
        lVar46 = g_enum_value;
        break;
      case 0x164:
        eh_except_emit_filter(pcVar14[-1].node);
        eh_except_filter_end();
        parse_paren_depth_pop();
        lVar46 = g_enum_value;
        break;
      case 0x169:
        expr_warn_no_effect(pcVar14->node,'\0');
        lVar46 = g_enum_value;
        break;
      case 0x16a:
        pcVar34 = (c1_declarator *)0x0;
        g_pending_access_check[g_paren_depth] = (c1_symbol *)0x0;
        if (pcVar14->declarator != (c1_declarator *)0x0) {
          pcVar32 = decl_declarator_symbol(pcVar14->declarator);
          if (pcVar32 != (c1_symbol *)0x0) {
            pcVar32 = decl_declarator_symbol(pcVar14->declarator);
            pvVar22 = (void *)sym_name(pcVar32);
            pcVar23 = expr_lookup_name_expression(pvVar22);
            pcVar38[1].node = pcVar23;
            lVar46 = g_enum_value;
            break;
          }
        }
        goto LAB_10467c7c;
      case 0x16b:
        g_case_label = (c1_node *)0x0;
        break;
      case 0x16d:
        stmt_define_label(pcVar14[-1].words[0]);
        lVar46 = g_enum_value;
        break;
      case 0x16e:
        if ((pcVar14[-2].node == (c1_node *)0x0) ||
           (g_switch_case_stack == (c1_switch_cases_cell *)0x0)) {
          diag_error(0x2e);
          lVar46 = g_enum_value;
        }
        else {
          pcVar23 = expr_resolve_address_of_overload(pcVar14[-2].node);
          stmt_case_label(pcVar23);
          lVar46 = g_enum_value;
        }
        break;
      case 0x16f:
        if (g_default_label_stack == (c1xx_label_cell *)0x0) {
          diag_error(0x2f);
          lVar46 = g_enum_value;
        }
        else if (g_default_label_stack->label == (c1_node *)0x0) {
          if (g_case_label == (c1_node *)0x0) {
            pcVar23 = label_new(0x14);
            g_default_label_stack->label = pcVar23;
            g_case_label = g_default_label_stack->label;
            label_emit_definition(g_default_label_stack->label);
            stmt_default_label_flow_state();
            lVar46 = g_enum_value;
          }
          else {
            g_default_label_stack->label = g_case_label;
            stmt_default_label_flow_state();
            lVar46 = g_enum_value;
          }
        }
        else {
          diag_error(0x30);
          lVar46 = g_enum_value;
        }
        break;
      case 0x170:
        parse_begin_compound_value(pcVar14[-1].node);
        pcVar38[1].words[0] = pcVar14[-1].words[0];
        lVar46 = g_enum_value;
        break;
      case 0x171:
        parse_begin_compound_value((c1_node *)0x0);
        g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] | 0x80;
        func_flow_state_note_11();
        lVar46 = g_enum_value;
        break;
      case 0x172:
        pcVar23 = label_new(0x1e);
        pcVar38[1].node = pcVar23;
        if (pcVar14[-1].node != (c1_node *)0x0) {
          pcVar23 = expr_resolve_address_of_overload(pcVar14[-1].node);
          pcVar14[-1].node = pcVar23;
          pcVar23 = stmt_check_controlling_expression(pcVar23,0);
          pcVar14[-1].node = pcVar23;
          stmt_emit_condition(pcVar23,pcVar38[1].node,0);
        }
        stmt_if_then_begin_flow_state();
        parse_paren_depth_pop();
        g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfe;
        lVar46 = g_enum_value;
        break;
      case 0x173:
        func_end_compound_statement(pcVar14[-2].node,'\0');
        stmt_else_begin_flow_state();
        pcVar23 = label_new(0x1e);
        il_emit_tuple(0x3a,pcVar23);
        label_emit_definition(pcVar14[-2].node);
        il_emit_line_record_24();
        g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfe;
        acStack_24[1] = 0x10422c59;
        parse_begin_compound_value(pcVar23);
        pcVar38[1].node = pcVar23;
        lVar46 = g_enum_value;
        break;
      case 0x177:
        pcVar38[1].spec.spec[0] = (pcVar14->spec).spec[0];
        lVar46 = g_enum_value;
        break;
      case 0x178:
        if (g_ms_extensions == '\0') {
          cVar11 = parse_begin_compound_value((c1_node *)0x0);
          (pcVar14->spec).spec[0] = cVar11;
        }
        g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] | 0x80;
        lVar46 = g_enum_value;
        break;
      case 0x179:
        if (pcVar14[-1].node != (c1_node *)0x0) {
          cVar10 = '\x01';
          pcVar23 = expr_resolve_address_of_overload(pcVar14[-1].node);
          pcVar23 = expr_warn_no_effect(pcVar23,cVar10);
          pcVar14[-1].node = pcVar23;
          pcVar23 = expr_full_expression_guarded(pcVar23,2);
          stmt_emit_expression(pcVar23);
        }
        iVar25 = parse_error_recovery_count();
        if (iVar25 == 0) {
          arena_reset(5);
        }
        g_string_literal_cur = &g_string_literal_buffer;
        g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] | 2;
        func_flow_state_note_25();
        lVar46 = g_enum_value;
        break;
      case 0x17a:
        pcVar23 = stmt_check_controlling_expression(pcVar14[-1].node,0);
        pcVar14[-1].node = pcVar23;
        func_flow_state_note_27();
        lVar46 = g_enum_value;
        break;
      case 0x17b:
        cVar10 = '\x01';
        pcVar23 = expr_resolve_address_of_overload(pcVar14[-2].node);
        pcVar23 = expr_warn_no_effect(pcVar23,cVar10);
        pcVar14[-2].node = pcVar23;
        stmt_for_head((c1_node *)0x0,pcVar14[-5].node,pcVar23);
        if (pcVar14[-1].spec.spec[0] != '\0') {
          diag_error(0x3b);
        }
        parse_paren_depth_pop();
        g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfc;
        func_flow_state_note_2a();
        lVar46 = g_enum_value;
        if (g_ms_extensions != '\0') {
          cVar11 = parse_begin_compound_value((c1_node *)0x0);
          pcVar14[-10].spec.spec[0] = cVar11;
          lVar46 = g_enum_value;
        }
        break;
      case 0x17c:
        cVar11 = parse_begin_compound_value((c1_node *)0x0);
        (pcVar14->spec).spec[0] = cVar11;
        g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] | 0x80;
        func_flow_state_note_19();
        stmt_while_head();
        lVar46 = g_enum_value;
        break;
      case 0x17d:
        cVar10 = '\0';
        pcVar23 = expr_resolve_address_of_overload(pcVar14[-1].node);
        pcVar23 = expr_warn_no_effect(pcVar23,cVar10);
        pcVar14[-1].node = pcVar23;
        pcVar23 = stmt_check_controlling_expression(pcVar23,0);
        pcVar14[-1].node = pcVar23;
        stmt_emit_loop_test(pcVar23);
        parse_paren_depth_pop();
        g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfe;
        func_flow_state_note_1c();
        lVar46 = g_enum_value;
        break;
      case 0x17e:
        cVar11 = parse_begin_compound_value((c1_node *)0x0);
        (pcVar14->spec).spec[0] = cVar11;
        func_flow_state_note_31();
        lVar46 = g_enum_value;
      case 0x1b0:
        g_enum_value = lVar46;
        g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] | 3;
        lVar46 = g_enum_value;
        break;
      case 0x180:
        pcVar23 = expr_resolve_address_of_overload(pcVar14[-3].node);
        stmt_switch_head((int)pcVar23);
        lVar46 = g_enum_value;
switchD_10421905_caseD_6f:
        g_enum_value = lVar46;
        g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfc;
        lVar46 = g_enum_value;
        break;
      case 0x181:
        cVar10 = '\0';
        pcVar23 = expr_resolve_address_of_overload(pcVar14->node);
        pcVar23 = expr_warn_no_effect(pcVar23,cVar10);
        cVar47 = (c1_decl_modifier)expr_eval_constant_expression(pcVar23);
        pcVar38[1].mods = cVar47;
        lVar46 = g_enum_value;
        break;
      case 0x183:
        cVar10 = '\0';
        pcVar23 = expr_resolve_address_of_overload(pcVar14->node);
        pcVar23 = expr_warn_no_effect(pcVar23,cVar10);
        pcVar38[1].node = pcVar23;
        lVar46 = g_enum_value;
        break;
      case 0x184:
      case 0x19a:
        pcVar23 = expr_build_binary(pcVar14[-1].spec.spec[0],pcVar14[-2].node,pcVar14->node);
        pcVar38[1].node = pcVar23;
        lVar46 = g_enum_value;
        break;
      case 0x185:
        pcVar23 = expr_build_zero_pair();
        pcVar38[1].node = pcVar23;
        lVar46 = g_enum_value;
        break;
      case 0x186:
        pcVar23 = expr_build_throw(pcVar14->node);
        pcVar38[1].node = pcVar23;
        lVar46 = g_enum_value;
        break;
      case 0x187:
        if ((pcVar14[-2].declarator != (c1_declarator *)0x0) &&
           (pcVar23 = pcVar14->node, pcVar23 != (c1_node *)0x0)) {
          pcVar33 = decl_declarator_record(pcVar14[-2].declarator);
          pcVar23 = expr_resolve_function_address(pcVar33,pcVar23);
joined_r0x104676a9:
          if (pcVar23 == (c1_node *)0x0) {
            expr_report_function_operand('4',pcVar14->node);
          }
          goto LAB_10422ec5;
        }
        goto switchD_10421905_caseD_24;
      case 0x188:
        if ((pcVar14[-2].declarator != (c1_declarator *)0x0) &&
           (pcVar23 = pcVar14->node, pcVar23 != (c1_node *)0x0)) {
          pcVar33 = decl_declarator_record(pcVar14[-2].declarator);
          pcVar23 = expr_resolve_function_address(pcVar33,pcVar23);
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
        pcVar23 = pcVar14->node;
LAB_10422ec5:
        pcVar23 = expr_build_binary(pcVar14[-1].spec.spec[0],pcVar14[-2].node,pcVar23);
        pcVar38[1].node = pcVar23;
        lVar46 = g_enum_value;
        break;
      case 0x18a:
        pcVar23 = expr_build_conditional(pcVar14[-4].node,pcVar14[-2].node,pcVar14->node);
        pcVar38[1].node = pcVar23;
        lVar46 = g_enum_value;
        break;
      case 0x18b:
      case 0x18d:
        if (pcVar14[-1].words[0] != 0) {
          func_flow_state_note_3e();
          lVar46 = g_enum_value;
        }
        break;
      case 0x18c:
      case 0x18e:
        pcVar23 = expr_build_binary(pcVar14[-2].spec.spec[0],pcVar14[-3].node,pcVar14->node);
        pcVar38[1].node = pcVar23;
        lVar46 = g_enum_value;
        break;
      case 0x199:
        pcVar23 = expr_check_based_operator(pcVar14[-2].node,pcVar14->node);
        pcVar38[1].node = pcVar23;
        lVar46 = g_enum_value;
        break;
      case 0x19d:
        g_compile_flags_c8 = g_compile_flags_c8 | 1;
        pcVar23 = pcVar14->node;
        cVar30 = pcVar14[-1].words[0];
        uVar49 = (undefined1)cVar30;
        uVar51 = (undefined1)(cVar30 >> 8);
        uVar41 = (undefined2)(cVar30 >> 0x10);
        cVar11 = 'd';
LAB_10422f46:
        g_enum_value = lVar46;
        pcVar23 = expr_build_cast(cVar11,(c1_symbol *)CONCAT22(uVar41,CONCAT11(uVar51,uVar49)),
                                  pcVar23);
        pcVar38[1].node = pcVar23;
        g_compile_flags_c8 = g_compile_flags_c8 & 0xfffffffe;
        tree_clear_value_link(pcVar38[1].node);
        lVar46 = g_enum_value;
        break;
      case 0x19e:
        goto switchD_10421905_caseD_19b;
      case 0x19f:
        pcVar14[-1].spec.spec[0] = (pcVar14[-1].spec.spec[0] == '@') + 'T';
        pcVar23 = tree_new_int_constant(1);
        pcVar23 = expr_build_binary(pcVar14[-1].spec.spec[0],pcVar14->node,pcVar23);
        pcVar38[1].node = pcVar23;
        lVar46 = g_enum_value;
        break;
      case 0x1a0:
        cVar30 = expr_build_unary(0x3d,pcVar14->node);
        pcVar38[1].words[0] = cVar30;
        lVar46 = g_enum_value;
        break;
      case 0x1a1:
        pcVar32 = pcVar14->sym;
        if (pcVar32 == (c1_symbol *)0x0) {
          pcVar38[1].words[0] = 0;
          lVar46 = g_enum_value;
        }
        else if ((pcVar32->kind == '=') && ((c1_symbol *)pcVar32->type != (c1_symbol *)0x0)) {
          pcVar23 = expr_address_of_member((c1_symbol *)pcVar32->type);
          pcVar38[1].node = pcVar23;
          lVar46 = g_enum_value;
        }
        else {
          if ((pcVar32->kind == 'S') && ((((c1_node *)pcVar32->type)->kind & 7) == 4)) {
            iVar25 = yyparse_cpp_address_of_member_leaf
                               ((c1_node *)pcVar32->type,pcVar38,pcVar14,parser,state_sp_00,
                                saved_lookahead,saved_rule);
            return iVar25;
          }
          g_compile_flags_c8 = g_compile_flags_c8 | 4;
          cVar30 = expr_build_unary(0x31,pcVar14->node);
          pcVar38[1].words[0] = cVar30;
          g_compile_flags_c8 = g_compile_flags_c8 & 0xfffffffb;
          lVar46 = g_enum_value;
        }
        break;
      case 0x1a2:
        pcVar23 = (c1_node *)expr_build_unary(0x86,pcVar14->node);
        pcVar38[1].node = pcVar23;
        tree_clear_value_link(pcVar23);
        lVar46 = g_enum_value;
        break;
      case 0x1a3:
        cVar30 = expr_build_unary(0x5a,pcVar14->node);
        pcVar38[1].words[0] = cVar30;
        lVar46 = g_enum_value;
        break;
      case 0x1a4:
        cVar30 = expr_build_unary(0x3c,pcVar14->node);
        pcVar38[1].words[0] = cVar30;
        lVar46 = g_enum_value;
        break;
      case 0x1a6:
        cVar30 = expr_build_unary(0x59,pcVar14->node);
        pcVar38[1].words[0] = cVar30;
        lVar46 = g_enum_value;
        break;
      case 0x1a7:
        (*g_idb->vtbl->idb_note_sizeof)(g_idb);
        if (pcVar14->node == (c1_node *)0x0) {
          pcVar38[1].words[0] = 0;
          g_sizeof_depth = g_sizeof_depth + -1;
          lVar46 = g_enum_value;
        }
        else {
          pcVar23 = expr_build_sizeof(pcVar14->node);
          pcVar38[1].node = pcVar23;
          g_sizeof_depth = g_sizeof_depth + -1;
          lVar46 = g_enum_value;
        }
        break;
      case 0x1a8:
        (*g_idb->vtbl->idb_note_sizeof)(g_idb);
        pcVar23 = expr_sizeof_type(pcVar14->sym->type);
        pcVar38[1].node = pcVar23;
        g_sizeof_depth = g_sizeof_depth + -1;
        lVar46 = g_enum_value;
        break;
      case 0x1ad:
        cVar30 = expr_build_unary(0xf0,pcVar14[-1].node);
        pcVar38[1].words[0] = cVar30;
        parse_paren_depth_pop();
        lVar46 = g_enum_value;
        break;
      case 0x1af:
        g_member_access_op = '\x01';
        if ((pcVar14[-1].node != (c1_node *)0x0) && ((pcVar14[-1].node)->op == '7')) {
          diag_warning(4,0x2c5);
        }
        pcVar23 = expr_build_binary(pcVar14[-2].spec.spec[0],pcVar14[-3].node,pcVar14[-1].node);
        pcVar38[1].node = pcVar23;
        lVar46 = g_enum_value;
        break;
      case 0x1b1:
        pcVar23 = pcVar14[-2].node;
        if ((pcVar23 != (c1_node *)0x0) && ((pcVar23->kind & 0x88) == 0)) {
          if ((g_compile_flags_c8 & 0x800000) != 0) {
            if (pcVar14->node != (c1_node *)0x0) {
              diag_error(0x209);
              pcVar23 = tree_new_zero_flagged();
            }
            pcVar38[1].node = pcVar23;
            g_compile_flags_c8 = g_compile_flags_c8 & 0xff7fffff;
            g_member_access_op = '\x01';
            lVar46 = g_enum_value;
            break;
          }
          pcVar23 = (c1_node *)expr_build_call(pcVar23,pcVar14->node);
        }
        pcVar38[1].node = pcVar23;
        lVar46 = g_enum_value;
switchD_10421905_caseD_19b:
        g_member_access_op = '\x01';
        break;
      case 0x1b4:
        g_member_access_op = '\x01';
        pcVar23 = tree_new_int_constant(1);
        pcVar23 = expr_build_binary((pcVar14->spec).spec[0],pcVar14[-1].node,pcVar23);
        pcVar38[1].node = pcVar23;
        lVar46 = g_enum_value;
        break;
      case 0x1b5:
        g_member_access_op = '\x01';
        pcVar23 = class_check_operator_global_form
                            (CONCAT22((short)((uint)g_yy_lookahead >> 0x10),
                                      CONCAT11((char)((uint)g_yy_lookahead >> 8),
                                               pcVar14[-1].spec.spec[0])),pcVar14->node);
        pcVar38[1].node = pcVar23;
        lVar46 = g_enum_value;
        break;
      case 0x1b6:
        if ((pcVar14->spec).spec[0] != 'D') {
          diag_error(0x2f8);
        }
        parse_paren_depth_push(1);
        lVar46 = g_enum_value;
        break;
      case 0x1b7:
        if ((pcVar14->spec).spec[0] != 0xbf) {
          iVar25 = yyparse_cpp_named_cast_expected_gt
                             ((pcVar14->spec).spec[0],pcVar38,parser,state_sp_00,saved_lookahead,
                              saved_rule);
          return iVar25;
        }
        goto LAB_104232f5;
      case 0x1b8:
        if (pcVar14->words[0] != 0) {
          g_compile_flags_c8 = g_compile_flags_c8 | 1;
          pcVar23 = pcVar14->node;
          pcVar32 = parse_type_id_declarator(pcVar14[-3].declarator,&pcVar14[-4].spec);
          uVar49 = SUB41(pcVar32,0);
          uVar51 = (undefined1)((uint)pcVar32 >> 8);
          uVar41 = (undefined2)((uint)pcVar32 >> 0x10);
          cVar11 = pcVar14[-7].spec.spec[0];
          lVar46 = g_enum_value;
          goto LAB_10422f46;
        }
switchD_10421905_caseD_24:
        g_enum_value = lVar46;
        pcVar38[1].words[0] = 0;
        lVar46 = g_enum_value;
        break;
      case 0x1b9:
        pcVar23 = expr_build_typeid_expression(pcVar14[-1].node);
        pcVar38[1].node = pcVar23;
        parse_paren_depth_pop();
        lVar46 = g_enum_value;
        break;
      case 0x1ba:
        pcVar32 = (c1_symbol *)
                  decl_finish_declarator_then_type(pcVar14[-1].ptr,(byte *)pcVar14[-2].words);
        goto LAB_104232f2;
      case 0x1bb:
        pcVar23 = expr_build_uuidof_expression(pcVar14[-1].node);
        pcVar38[1].node = pcVar23;
        parse_paren_depth_pop();
        lVar46 = g_enum_value;
        break;
      case 0x1bc:
        pcVar32 = decl_finish_declarator_uuidof(pcVar14[-1].ptr,(byte *)pcVar14[-2].words);
        goto LAB_104232f2;
      case 0x1bd:
        parse_paren_depth_pop();
        pcVar38[1].words[0] = pcVar14[-1].words[0];
        lVar46 = g_enum_value;
        break;
      case 0x1be:
        pcVar38[1].words[0] = 0;
        parse_report_inserted_token(g_yy_lookahead,0x76);
        lVar46 = g_enum_value;
        break;
      case 0x1bf:
        pcVar23 = tree_new_constant(pcVar14->type,pcVar14->words + 2,g_expr_arena_index);
        pcVar38[1].node = pcVar23;
        lVar46 = g_enum_value;
        break;
      case 0x1c1:
        type_string_literal_array(pcVar14->node);
        lVar46 = g_enum_value;
        break;
      case 0x1c2:
        pcVar23 = expr_check_this_usage();
        pcVar38[1].node = pcVar23;
        lVar46 = g_enum_value;
        break;
      case 0x1c3:
        pcVar23 = expr_build_builtin_unary(0x76,pcVar14[-1].node);
        pcVar38[1].node = pcVar23;
        tree_clear_value_link(pcVar23);
        parse_paren_depth_pop();
        lVar46 = g_enum_value;
        break;
      case 0x1c5:
        PTR_104d2158 = expr_prepare_member_access_object
                                 (g_current_scope,(pcVar14->spec).spec[0],pcVar14[-1].node,'\0');
        g_member_access_op = (pcVar14->spec).spec[0];
        lVar46 = g_enum_value;
        break;
      case 0x1c6:
        pcVar23 = expr_build_member_access(g_member_access_op,PTR_104d2158,pcVar14->node);
        pcVar38[1].node = pcVar23;
        lVar46 = g_enum_value;
        break;
      case 0x1c7:
        pcVar23 = expr_build_pseudo_destructor_call
                            (g_member_access_op,PTR_104d2158,pcVar14->words[0]);
        pcVar38[1].node = pcVar23;
        lVar46 = g_enum_value;
        break;
      case 0x1c8:
        pcVar32 = value_word0(pcVar14->cell);
        pcVar23 = expr_build_pseudo_destructor_call(g_member_access_op,PTR_104d2158,(int)pcVar32);
        pcVar38[1].node = pcVar23;
        lVar46 = g_enum_value;
        break;
      case 0x1c9:
        pfVar31 = sym_name_of_ref(pcVar14->cell);
        pcVar23 = expr_build_pseudo_destructor_call(g_member_access_op,PTR_104d2158,(int)pfVar31);
        pcVar38[1].node = pcVar23;
        lVar46 = g_enum_value;
        break;
      case 0x1ca:
        pcVar23 = expr_check_qualified_pseudo_destructor
                            (g_member_access_op,PTR_104d2158,&pcVar14[-3].spec,&pcVar14->spec);
        pcVar38[1].node = pcVar23;
        lVar46 = g_enum_value;
        break;
      case 0x1cb:
        pcVar23 = expr_lookup_name_expression(pcVar14->ptr);
        pcVar38[1].node = pcVar23;
        lVar46 = g_enum_value;
        break;
      case 0x1cc:
        pvVar22 = decl_declarator_record(pcVar14->declarator);
        if (pvVar22 == (void *)0x0) {
          pcVar32 = (c1_symbol *)sym_name(pcVar14->sym);
          pcVar23 = sym_is_data_or_function(pcVar32);
          pcVar38[1].node = pcVar23;
          lVar46 = g_enum_value;
        }
        else {
          pcVar32 = (c1_symbol *)sym_name(pcVar14->sym);
          pcVar23 = sym_is_data_or_function(pcVar32);
          if (pcVar23->right != (void *)0x0) {
            diag_fatal(1);
          }
          pvVar22 = value_fieldc(pcVar14->ptr);
          pcVar23->right = pvVar22;
          pcVar38[1].node = pcVar23;
          lVar46 = g_enum_value;
        }
        break;
      case 0x1cd:
        pcVar32 = value_word0(pcVar14->cell);
        pcVar23 = sym_is_data_or_function(pcVar32);
        pcVar38[1].node = pcVar23;
        lVar46 = g_enum_value;
        break;
      case 0x1ce:
        pcVar23 = expr_lookup_name_expression((pcVar14->mods).based);
        pcVar38[1].node = pcVar23;
        lVar46 = g_enum_value;
        break;
      case 0x1cf:
        pfVar31 = decl_conversion_function_name((pcVar14->spec).type);
        pcVar23 = expr_lookup_name_expression(pfVar31);
        pcVar38[1].node = pcVar23;
        g_compile_flags_c4 = g_compile_flags_c4 & 0xfffffffb;
        lVar46 = g_enum_value;
        break;
      case 0x1d0:
        pcVar32 = value_word0(pcVar14->cell);
        lVar46 = g_enum_value;
        if ((pcVar32->flags3 & 4) != 0) goto switchD_10421905_caseD_24;
        pcVar32 = value_word0(pcVar14->cell);
        pcVar23 = sym_is_data_or_function(pcVar32);
        pvVar22 = decl_declarator_record(pcVar14->declarator);
        if (pvVar22 != (void *)0x0) {
          if (pcVar23->right != (void *)0x0) {
            diag_fatal(1);
          }
          pvVar22 = decl_declarator_record(pcVar14->declarator);
          pcVar23->right = pvVar22;
        }
        pcVar38[1].node = pcVar23;
        lVar46 = g_enum_value;
        break;
      case 0x1d1:
        if (pcVar14[-1].cell != (c1_symbol **)0x0) {
          pcVar33 = (pcVar14->spec).type;
          pcVar32 = value_word0(pcVar14[-1].cell);
          decl_qualified_conversion_function_name(pcVar32,pcVar33);
          pcVar32 = value_word0(pcVar14[-1].cell);
          pcVar23 = sym_is_data_or_function(pcVar32);
          pvVar22 = decl_declarator_record(pcVar14[-1].declarator);
          if (pvVar22 != (void *)0x0) {
            if (pcVar23->right != (void *)0x0) {
              diag_fatal(1);
            }
            pvVar22 = decl_declarator_record(pcVar14[-1].declarator);
            pcVar23->right = pvVar22;
          }
          pcVar38[1].node = pcVar23;
        }
        g_compile_flags_c4 = g_compile_flags_c4 & 0xfffffffb;
        lVar46 = g_enum_value;
        break;
      case 0x1d3:
        pcVar32 = parse_type_id_declarator(pcVar14[-1].declarator,&pcVar14[-2].spec);
LAB_104232f2:
        pcVar38[1].sym = pcVar32;
        lVar46 = g_enum_value;
LAB_104232f5:
        g_enum_value = lVar46;
        parse_paren_depth_pop();
LAB_104232fa:
        g_declarator_paren_base = g_declarator_paren_base + -1;
        lVar46 = g_enum_value;
        break;
      case 0x1d4:
        pcVar38[1].words[0] = pcVar14[-1].words[0];
        parse_paren_depth_pop();
        lVar46 = g_enum_value;
        break;
      case 0x1d5:
      case 0x1ea:
        pcVar38[1].words[0] = 0;
        parse_paren_depth_pop();
        lVar46 = g_enum_value;
        break;
      case 0x1d6:
        pcVar23 = tree_append_list_item((c1_node *)0x0,pcVar14->node,0);
        pcVar38[1].node = pcVar23;
        lVar46 = g_enum_value;
        break;
      case 0x1d7:
        pcVar23 = tree_append_list_item(pcVar14[-2].node,pcVar14->node,0);
        pcVar38[1].node = pcVar23;
        lVar46 = g_enum_value;
        break;
      case 0x1d8:
        pcVar23 = arena_alloc(g_arenas + g_expr_arena_index,0x18);
        pcVar23->kind = '\x05';
        pcVar23->op = '\a';
        pcVar23->left = (void *)pcVar14->words[0];
        pcVar23->right = (void *)pcVar14->words[1];
        pcVar38[1].node = pcVar23;
        lVar46 = g_enum_value;
        break;
      case 0x1d9:
        lex_concatenate_strings
                  ((c1_string_value *)((pcVar14[-1].declarator)->spec + 4),&pcVar14->str);
        lVar46 = g_enum_value;
        break;
      case 0x1da:
        parse_paren_depth_pop();
        g_compile_flags_c8 = g_compile_flags_c8 & 0xffffffef;
        g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] | 2;
        g_compile_flags_c4 = g_compile_flags_c4 & 0x7fffffff;
        lVar46 = g_enum_value;
        break;
      case 0x1db:
        pcVar35 = decl_declarator_record(pcVar14[-1].declarator);
        pcVar23 = decl_record_new_array_bound(pcVar35);
        cVar30 = pcVar14->words[0];
        uVar49 = (undefined1)cVar30;
        uVar51 = (undefined1)(cVar30 >> 8);
        uVar41 = (undefined2)(cVar30 >> 0x10);
        pcVar32 = sym_new_from_declarator(pcVar14[-1].declarator,0xffffffff);
        pcVar23 = expr_build_new_or_placeholder
                            (pcVar14[-2].spec.spec[0],0,pcVar32,
                             CONCAT22(uVar41,CONCAT11(uVar51,uVar49)),(int)pcVar23);
        pcVar38[1].node = pcVar23;
        lVar46 = g_enum_value;
        break;
      case 0x1dc:
        pcVar35 = decl_declarator_record(pcVar14[-1].declarator);
        pcVar23 = decl_record_new_array_bound(pcVar35);
        cVar30 = pcVar14->words[0];
        uVar49 = (undefined1)cVar30;
        uVar51 = (undefined1)(cVar30 >> 8);
        uVar41 = (undefined2)(cVar30 >> 0x10);
        pcVar32 = sym_new_from_declarator(pcVar14[-1].declarator,0xffffffff);
        pcVar23 = expr_build_new_or_placeholder
                            (pcVar14[-2].spec.spec[0],0,pcVar32,
                             CONCAT22(uVar41,CONCAT11(uVar51,uVar49)),(int)pcVar23);
        pcVar38[1].node = pcVar23;
        lVar46 = g_enum_value;
        break;
      case 0x1dd:
      case 0x1de:
        pcVar35 = decl_declarator_record(pcVar14[-1].declarator);
        pcVar23 = decl_record_new_array_bound(pcVar35);
        cVar30 = pcVar14->words[0];
        uVar49 = (undefined1)cVar30;
        uVar51 = (undefined1)(cVar30 >> 8);
        uVar41 = (undefined2)(cVar30 >> 0x10);
        pcVar32 = sym_new_from_declarator(pcVar14[-1].declarator,0xffffffff);
        pcVar23 = expr_build_new_or_placeholder
                            (pcVar14[-3].spec.spec[0],pcVar14[-2].words[0],pcVar32,
                             CONCAT22(uVar41,CONCAT11(uVar51,uVar49)),(int)pcVar23);
        pcVar38[1].node = pcVar23;
        lVar46 = g_enum_value;
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
        lVar46 = g_enum_value;
        break;
      case 0x1e1:
        decl_set_local_key_flag(pcVar14->declarator,'\x01');
        pcVar40 = pcVar14 + -1;
        (pcVar40->spec).spec[0] = pcVar14[-1].spec.spec[0] & 0x7f;
        spec = pcVar40;
        pcVar35 = decl_declarator_record(pcVar14->declarator);
        decl_check_conversion_return_type(pcVar35,&spec->spec);
        pcVar35 = decl_declarator_record(pcVar14->declarator);
        decl_allow_variable_array_bound(pcVar35);
        pcVar35 = decl_declarator_record(pcVar14->declarator);
        decl_finish_declarator(pcVar35);
        decl_declarator_set_specifiers(pcVar14->declarator,&pcVar40->spec);
        decl_process_declaration(pcVar14->declarator);
        pcVar33 = (c1_type *)sym_name(pcVar14->sym);
        iVar25 = type_chain_is_cv_qualified(pcVar33);
        if ((char)iVar25 == '\0') {
          pcVar33 = (c1_type *)sym_name(pcVar14->sym);
          cVar11 = type_is_void(pcVar33);
          if (cVar11 != '\0') {
            diag_error(0x1d5);
          }
        }
        else {
          sym_name(pcVar14->sym);
          diag_error(0x1d4);
        }
        g_declarator_paren_base = g_declarator_paren_base + -1;
        g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfe;
        pcVar38[1].words[0] = pcVar14->words[0];
        lVar46 = g_enum_value;
        break;
      case 0x1e2:
        pcVar34 = decl_declarator_alloc();
        if (pcVar34 == (c1_declarator *)0x0) {
          pcVar34 = (c1_declarator *)0x0;
        }
        else {
          pcVar34 = decl_declarator_init(pcVar34,g_name_new_target,4,(c1_overload_set *)0x0);
        }
        decl_set_local_key_flag(pcVar34,'\x01');
        pvVar22 = decl_declarator_record(pcVar14->declarator);
        d_00 = decl_declarator_record(pcVar34);
        decl_set_name(d_00,pvVar22);
        pcVar35 = decl_declarator_record(pcVar34);
        decl_finish_declarator(pcVar35);
        decl_process_declaration(pcVar34);
        g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfe;
        pcVar38[1].declarator = pcVar34;
        lVar46 = g_enum_value;
        break;
      case 0x1e3:
        pcVar34 = pcVar14[-1].declarator;
        decl_set_local_key_flag(pcVar34,'\x01');
        declarator_set_kind(pcVar34,4);
        decl_set_name(pcVar34,g_name_new_target);
        pcVar40 = pcVar14 + -2;
        (pcVar40->spec).spec[0] = pcVar14[-2].spec.spec[0] & 0x7f;
        decl_declarator_set_specifiers(pcVar34,&pcVar40->spec);
        pcVar35 = decl_declarator_record(pcVar34);
        decl_check_conversion_return_type(pcVar35,&pcVar40->spec);
        pcVar35 = decl_declarator_record(pcVar34);
        decl_allow_variable_array_bound(pcVar35);
        pcVar35 = decl_declarator_record(pcVar34);
        decl_finish_declarator(pcVar35);
        decl_process_declaration(pcVar34);
        cVar11 = type_is_cv_qualified_stripped(pcVar34);
        if (cVar11 == '\0') {
          pcVar33 = (c1_type *)sym_name((c1_symbol *)pcVar34);
          cVar11 = type_is_void(pcVar33);
          if (cVar11 != '\0') {
            diag_error(0x1d5);
          }
        }
        else {
          sym_name((c1_symbol *)pcVar34);
          diag_error(0x1d4);
        }
        g_declarator_paren_base = g_declarator_paren_base + -1;
        parse_paren_depth_pop();
        g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfe;
        pcVar38[1].declarator = pcVar34;
        lVar46 = g_enum_value;
        break;
      case 0x1e4:
        pcVar34 = decl_declarator_alloc();
        if (pcVar34 == (c1_declarator *)0x0) {
          pcVar34 = (c1_declarator *)0x0;
        }
        else {
          pcVar34 = decl_declarator_init(pcVar34,g_name_new_target,4,(c1_overload_set *)0x0);
        }
        g_declarator_paren_base = g_declarator_paren_base + 1;
        if (g_yy_lookahead != (byte *)0x0) {
          cVar11 = lex_token_code((c1xx_token *)g_yy_lookahead);
          if (cVar11 == 'v') {
            g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] | 3;
          }
        }
        pcVar38[1].declarator = pcVar34;
        lVar46 = g_enum_value;
        break;
      case 0x1e5:
        pcVar34 = decl_declarator_alloc();
        if (pcVar34 == (c1_declarator *)0x0) {
          pcVar34 = (c1_declarator *)0x0;
        }
        else {
          pcVar34 = decl_declarator_init(pcVar34,g_name_new_target,4,(c1_overload_set *)0x0);
        }
        pcVar35 = decl_declarator_record(pcVar34);
        type_check_based_form(pcVar35,&pcVar14->mods);
        g_declarator_paren_base = g_declarator_paren_base + 1;
LAB_10467c7c:
        pcVar38[1].declarator = pcVar34;
        lVar46 = g_enum_value;
        break;
      case 0x1e7:
        if ((pcVar14[-1].node != (c1_node *)0x0) && ((pcVar14[-1].node)->op == '7')) {
          diag_warning(4,0x2c5);
        }
        pcVar23 = pcVar14[-1].node;
        pvVar22 = decl_declarator_record(pcVar38[1].declarator);
        type_check_array_bound_constant_2(pvVar22,pcVar23);
        lVar46 = g_enum_value;
        break;
      case 0x1eb:
        pcVar23 = expr_build_delete(pcVar14[-1].spec.spec[0],pcVar14->node,(c1_node *)0x0,'\0');
        pcVar38[1].node = pcVar23;
        lVar46 = g_enum_value;
        break;
      case 0x1ec:
        if ((pcVar14[-2].node != (c1_node *)0x0) && ((pcVar14[-2].node)->op == '7')) {
          diag_warning(4,0x2c5);
        }
        pcVar23 = expr_build_delete(pcVar14[-4].spec.spec[0],pcVar14->node,pcVar14[-2].node,'\x01');
        pcVar38[1].node = pcVar23;
        lVar46 = g_enum_value;
      }
      iVar25 = g_yy_pgo[g_yy_r1[g_yy_rule]] + 1 + *state_sp_00;
      pcVar14 = pcVar38;
      g_enum_value = lVar46;
      if ((0xfdb < iVar25) ||
         (iVar25 = (int)g_yy_action[iVar25], (int)g_yy_chk[iVar25] != -(uint)g_yy_r1[g_yy_rule])) {
        iVar25 = (int)g_yy_action[g_yy_pgo[g_yy_r1[g_yy_rule]]];
      }
LAB_1042188d:
      piVar20 = state_sp_00 + 1;
      pcVar14 = pcVar14 + 1;
      *piVar20 = iVar25;
      state_00 = iVar25;
    }
    if (g_yy_lookahead == (byte *)0x0) {
      g_yy_lookahead = yylex_cpp();
    }
    iVar25 = (int)sVar3 + (uint)g_token_class[*g_yy_lookahead];
    if (((iVar25 < 0) || (0xfdb < iVar25)) ||
       (iVar25 = (int)g_yy_action[iVar25],
       g_yy_chk[iVar25] != (ushort)g_token_class[*g_yy_lookahead])) goto LAB_104218b7;
    if (piVar20 <= parser->states + 0x3fb) {
      yy_copy_token_value(pcVar14 + 1,g_yy_lookahead);
      g_yy_lookahead = (byte *)0x0;
      if (0 < parser->errflag) {
        parser->errflag = parser->errflag + -1;
      }
      goto LAB_1042188d;
    }
    yyerror_cpp("yacc stack overflow");
  }
  g_yy_result = 1;
  iVar25 = parse_yacc_return_tail(saved_lookahead,saved_rule);
  return iVar25;
}

