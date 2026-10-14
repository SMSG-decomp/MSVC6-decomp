int yyparse_asm_fragment(short state,short *ssp,c1_yystype *vsp)

{
  ushort *puVar1;
  byte bVar2;
  ushort uVar3;
  c1_type *pcVar4;
  char cVar5;
  short sVar6;
  c1_yystype *pcVar7;
  c1_symbol *pcVar8;
  c1_u8 *pcVar9;
  int iVar10;
  short *left;
  c1_yy_token_insertion *pcVar11;
  short sVar12;
  c1_yystype *pcVar13;
  int state_00;
  c1_yystype *pcVar14;
  c1_yystype *pcVar15;
  c1_u8 token;
  short *psVar16;
  
  pcVar13 = vsp;
code_r0x10622e08:
  vsp = pcVar13;
  asm_check_operand_count();
  pcVar13 = vsp;
switchD_10622da2_caseD_2:
  vsp = pcVar13;
  ssp = ssp + 1;
  if (&g_asm_yy_states_last < ssp) {
    asm_check_parser_stack("yacc stack overflow");
    return 1;
  }
  pcVar15 = vsp + 1;
  *ssp = state;
  pcVar13 = &g_yyval;
  pcVar7 = pcVar15;
  for (iVar10 = 6; iVar10 != 0; iVar10 = iVar10 + -1) {
    pcVar7->words[0] = (c1_u32)pcVar13->ptr;
    pcVar13 = (c1_yystype *)(&pcVar13->ptr + 1);
    pcVar7 = (c1_yystype *)&(pcVar7->string).length;
  }
  iVar10 = (int)state;
LAB_10622c9c:
  sVar12 = g_asm_yy_pact[iVar10];
  pcVar13 = pcVar15;
  if (-1000 < sVar12) {
    if (g_asm_lookahead == &g_asm_no_lookahead) {
      g_asm_lookahead = &asm_yylex()->code;
    }
    sVar6 = g_asm_yy_errflag;
    sVar12 = sVar12 + (ushort)*g_asm_lookahead;
    if (((-1 < sVar12) && (sVar12 < 0x104)) &&
       (sVar12 = g_asm_yy_action[sVar12], g_asm_yy_chk[sVar12] == (ushort)*g_asm_lookahead)) {
      pcVar9 = g_asm_lookahead + 8;
      pcVar7 = &g_yyval;
      for (iVar10 = 6; iVar10 != 0; iVar10 = iVar10 + -1) {
        pcVar7->ptr = *(void **)pcVar9;
        pcVar9 = pcVar9 + 4;
        pcVar7 = (c1_yystype *)(&pcVar7->ptr + 1);
      }
      g_asm_lookahead = &g_asm_no_lookahead;
      state = sVar12;
      if (0 < sVar6) {
        g_asm_yy_errflag = g_asm_yy_errflag + -1;
      }
      goto switchD_10622da2_caseD_2;
    }
  }
  sVar12 = (&g_asm_yy_def)[iVar10];
  if (sVar12 == -2) {
    if (g_asm_lookahead == &g_asm_no_lookahead) {
      g_asm_lookahead = &asm_yylex()->code;
    }
    psVar16 = g_asm_yy_exca + g_asm_yy_exidx[iVar10];
    uVar3 = g_asm_yy_exca[g_asm_yy_exidx[iVar10]];
    while ((uVar3 != *g_asm_lookahead && (-1 < (short)uVar3))) {
      puVar1 = (ushort *)(psVar16 + 2);
      psVar16 = psVar16 + 2;
      uVar3 = *puVar1;
    }
    sVar12 = psVar16[1];
    if (sVar12 < 0) {
      iVar10 = yyparse_asm_fragment_2();
      return iVar10;
    }
  }
  if (sVar12 == 0) {
    switch(g_asm_yy_errflag) {
    case 0:
      sVar12 = 3;
      iVar10 = 0;
      pcVar11 = g_asm_yy_token_insertions;
      break;
    case 1:
    case 2:
      goto switchD_1064e3f2_caseD_1;
    case 3:
      goto switchD_1064e3f2_caseD_3;
    default:
      goto switchD_1064e3f2_default;
    }
    do {
      if (state <= sVar12) break;
      sVar12 = pcVar11[1].state;
      pcVar11 = pcVar11 + 1;
      iVar10 = iVar10 + 3;
    } while (sVar12 != -1000);
    if (state == (&g_asm_yy_token_insertions[0].state)[iVar10]) {
      state_00 = (int)(&g_asm_yy_token_insertions[0].token)[iVar10];
      if (state_00 < 0) {
        g_asm_yy_errflag = g_asm_yy_errflag + 1;
        state_00 = -state_00;
      }
      if (g_asm_yy_errflag < 2) {
        asm_report_syntax_error((char *)g_asm_lookahead,state_00);
      }
      pcVar7 = asm_parser_value_for_token((c1_yystype *)&stack0x0000001c,state_00);
      state = (&g_asm_yy_token_insertions[0].next_state)[iVar10];
      pcVar15 = &g_yyval;
      for (iVar10 = 6; iVar10 != 0; iVar10 = iVar10 + -1) {
        pcVar15->words[0] = (c1_u32)pcVar7->ptr;
        pcVar7 = (c1_yystype *)&(pcVar7->string).length;
        pcVar15 = (c1_yystype *)(&pcVar15->ptr + 1);
      }
    }
    else {
      asm_check_parser_stack("syntax error");
      g_asm_yy_nerrs = g_asm_yy_nerrs + 1;
switchD_1064e3f2_caseD_1:
      g_asm_yy_errflag = 3;
      vsp = pcVar15;
      while( true ) {
        if (ssp < &g_asm_yy_states) {
          g_asm_yy_errflag = 3;
          return 1;
        }
        sVar12 = g_asm_yy_pact[*ssp] + 0x100;
        if (((-1 < sVar12) && (sVar12 < 0x104)) && (g_asm_yy_chk[g_asm_yy_action[sVar12]] == 0x100))
        break;
        ssp = ssp + -1;
        vsp = vsp + -1;
      }
      state = g_asm_yy_action[sVar12];
      pcVar13 = vsp;
    }
    goto switchD_10622da2_caseD_2;
  }
switchD_1064e3f2_default:
  ssp = ssp + -(uint)g_asm_yy_r2[sVar12];
  pcVar13 = pcVar15 + -(uint)g_asm_yy_r2[sVar12];
  bVar2 = g_asm_yy_r1[sVar12];
  pcVar7 = pcVar13 + 1;
  pcVar14 = &g_yyval;
  for (iVar10 = 6; iVar10 != 0; iVar10 = iVar10 + -1) {
    pcVar14->words[0] = (c1_u32)pcVar7->ptr;
    pcVar7 = (c1_yystype *)&(pcVar7->string).length;
    pcVar14 = (c1_yystype *)(&pcVar14->ptr + 1);
  }
  sVar6 = *ssp + g_asm_yy_pgo[(short)(ushort)bVar2] + 1;
  if ((0x103 < sVar6) ||
     (state = g_asm_yy_action[sVar6], (int)g_asm_yy_chk[state] != -(int)(short)(ushort)bVar2)) {
    state = g_asm_yy_action[g_asm_yy_pgo[(short)(ushort)bVar2]];
  }
  switch(sVar12) {
  case 3:
    if ((pcVar15->spec).words.storage == 0xf2) {
      il_emit_pragma_or_segment_record(0x24);
    }
    arena_reset_ptr(g_arenas + 3);
    token = (pcVar15->spec).words.storage;
    break;
  case 4:
    g_asm_yy_errflag = 0;
    if ((pcVar15->spec).words.storage == 0xf2) {
      il_emit_pragma_or_segment_record(0x24);
    }
    arena_reset_ptr(g_arenas + 3);
    token = (pcVar15->spec).words.storage;
    break;
  default:
    goto switchD_10622da2_caseD_2;
  case 7:
    g_asm_brace_depth = g_asm_brace_depth + 1;
    goto switchD_10622da2_caseD_2;
  case 9:
    asm_check_label_redefinition(vsp->words[0]);
    goto switchD_10622da2_caseD_2;
  case 0xb:
    asm_warn_directive(vsp->half,*(uint *)((int)vsp + 0x20));
    goto switchD_10622da2_caseD_2;
  case 0xc:
    g_asm_operands_begun = 1;
    asm_instruction_begin(pcVar15->half);
    goto switchD_10622da2_caseD_2;
  case 0xd:
    goto code_r0x10622e08;
  case 0xe:
    goto switchD_10622da2_caseD_b;
  case 0xf:
  case 0x31:
    g_asm_after_period = 1;
    goto switchD_10622da2_caseD_2;
  case 0x10:
    g_asm_operand_index = 0;
    g_yyval.words[2] = 0;
    g_yyval.spec.type = (c1_type *)0x0;
    goto switchD_10622da2_caseD_2;
  case 0x11:
    g_asm_operand_index = 1;
    g_yyval.ptr = pcVar15->ptr;
    g_yyval.spec.words.segment = (void *)*(undefined4 *)((int)vsp + 0x1c);
    g_yyval.words[2] = *(c1_u32 *)((int)vsp + 0x20);
    g_yyval.spec.type = (c1_type *)*(undefined4 *)((int)vsp + 0x24);
    goto switchD_10622da2_caseD_2;
  case 0x14:
    asm_instruction_begin(pcVar15->half);
    asm_check_operand_count();
    goto switchD_10622da2_caseD_2;
  case 0x15:
    asm_instruction_begin(pcVar15->half);
    goto code_r0x10622e08;
  case 0x17:
    g_asm_operand_index = g_asm_operand_index + 1;
    goto switchD_10622da2_caseD_2;
  case 0x19:
    if (g_asm_operand_index < 2) {
      g_asm_operand_index = g_asm_operand_index + 1;
      g_asm_operand = asm_operand_reset(g_asm_operand_index);
    }
    goto switchD_10622da2_caseD_2;
  case 0x1b:
    if (((pcVar15->constant).type)->code != 3) {
      asm_operand_add_displacement((int)((pcVar15->constant).type)->base);
    }
    goto switchD_10622da2_caseD_2;
  case 0x1c:
    psVar16 = (short *)(pcVar15->string).text;
    if (*psVar16 == 0) {
      g_yyval.string.text =
           (char *)asm_check_index_register
                             ((ushort)(vsp->spec).words.storage,(short *)vsp[-1].string.text,psVar16
                             );
    }
    else {
      g_yyval.string.text =
           (char *)asm_check_index_register
                             ((ushort)(vsp->spec).words.storage,psVar16,(short *)vsp[-1].string.text
                             );
    }
    goto switchD_10622da2_caseD_2;
  case 0x1d:
  case 0x1e:
  case 0x1f:
  case 0x20:
  case 0x21:
  case 0x22:
  case 0x23:
  case 0x24:
  case 0x25:
  case 0x26:
  case 0x27:
  case 0x28:
  case 0x29:
    g_yyval.string.text =
         (char *)asm_check_constant_operand
                           ((ushort)(vsp->spec).words.storage,(short *)vsp[-1].string.text,
                            (short *)(pcVar15->string).text);
    goto switchD_10622da2_caseD_2;
  case 0x2a:
  case 0x2b:
    psVar16 = (short *)(pcVar15->string).text;
    left = (short *)vsp[-1].string.text;
    bVar2 = (vsp->spec).words.storage;
    goto LAB_10622e70;
  case 0x2c:
    g_asm_ptr_form = 1;
    g_asm_size_without_ptr = 1;
    if ((vsp[-1].constant.type)->code == 0) {
      pcVar4 = (vsp[-1].constant.type)->base;
      if (pcVar4 == (c1_type *)0xffff) {
        asm_warn_ptr_operator(0x3d);
        g_yyval.ptr = pcVar15->ptr;
        goto switchD_10622da2_caseD_2;
      }
      if (pcVar4 == (c1_type *)0xfffe) {
        asm_warn_ptr_operator(0x3e);
        g_yyval.ptr = pcVar15->ptr;
        goto switchD_10622da2_caseD_2;
      }
    }
    iVar10 = asm_operand_description_id();
    diag_error(0x198,iVar10);
    g_yyval.ptr = pcVar15->ptr;
    goto switchD_10622da2_caseD_2;
  case 0x2d:
    g_asm_after_period = 1;
    pcVar8 = asm_lookup_name(vsp->words[0],0);
    pcVar4 = pcVar8->type;
    cVar5 = (char)pcVar4->code;
    while (cVar5 < '\0') {
      pcVar4 = pcVar4->base;
      cVar5 = (char)pcVar4->code;
    }
    if ((pcVar4->code & 0x300) == 0) goto LAB_1064e741;
    g_asm_member_struct = (pcVar4->extra).sym;
    goto switchD_10622da2_caseD_2;
  case 0x2e:
  case 0x30:
    g_asm_after_period = 0;
    psVar16 = (short *)(pcVar15->string).text;
    left = (short *)vsp[-3].string.text;
    goto LAB_1064e761;
  case 0x2f:
    g_asm_after_period = 1;
    pcVar4 = (vsp->spec).type;
    cVar5 = (char)pcVar4->code;
    while (cVar5 < '\0') {
      pcVar4 = pcVar4->base;
      cVar5 = (char)pcVar4->code;
    }
    if ((pcVar4->code & 0x300) == 0) {
LAB_1064e741:
      g_asm_member_struct = (void *)0x0;
    }
    else {
      g_asm_member_struct = (pcVar4->extra).sym;
    }
    goto switchD_10622da2_caseD_2;
  case 0x32:
    g_asm_after_period = 0;
  case 0x52:
    psVar16 = (short *)(pcVar15->string).text;
    left = (short *)vsp[-2].string.text;
LAB_1064e761:
    bVar2 = vsp[-1].spec.words.storage;
LAB_10622e70:
    g_yyval.string.text = (char *)asm_check_constant_expression((ushort)bVar2,left,psVar16);
    goto switchD_10622da2_caseD_2;
  case 0x34:
    goto switchD_10622da2_caseD_31;
  case 0x35:
  case 0x38:
    g_yyval.string.text =
         (char *)asm_check_constant_operand_2
                           ((ushort)(vsp->spec).words.storage,(short *)(pcVar15->string).text);
    goto switchD_10622da2_caseD_2;
  case 0x36:
  case 0x39:
    g_yyval.string.text =
         (char *)asm_check_constant_operand_2
                           ((ushort)(vsp->spec).words.storage,(short *)(pcVar15->string).text);
    goto switchD_10622da2_caseD_2;
  case 0x37:
    g_yyval.string.text =
         (char *)asm_check_constant_operand_2
                           ((ushort)(vsp->spec).words.storage,(short *)(pcVar15->string).text);
    goto switchD_10622da2_caseD_2;
  case 0x3a:
    g_yyval.string.text =
         (char *)asm_check_segment_override(vsp[-1].half,(short *)(pcVar15->string).text);
    goto switchD_10622da2_caseD_2;
  case 0x3b:
    iVar10 = type_size(*(c1_type **)((int)vsp + 0x24));
    g_yyval.string.text = (char *)asm_operand_node_new(iVar10);
    goto switchD_10622da2_caseD_2;
  case 0x3c:
    g_yyval.string.text =
         (char *)asm_operand_node_new
                           ((int)(char)(&g_type_rank_table)
                                       [(byte)g_tree_op_to_il_op[(pcVar15->spec).words.storage] &
                                        0xf]);
    goto switchD_10622da2_caseD_2;
  case 0x3d:
    g_yyval.string.text =
         (char *)asm_operand_node_new
                           ((uint)(byte)(&g_asm_size_class_by_keyword)[(short)pcVar15->half]);
    goto switchD_10622da2_caseD_2;
  case 0x3e:
    pcVar8 = asm_lookup_name(pcVar15->words[0],1);
    iVar10 = asm_symbol_operand_size(pcVar8);
    g_yyval.string.text = (char *)asm_operand_node_new(iVar10);
    goto switchD_10622da2_caseD_2;
  case 0x3f:
    pcVar8 = asm_lookup_name(pcVar15->words[0],0);
    iVar10 = type_size(pcVar8->type);
    g_yyval.string.text = (char *)asm_operand_node_new(iVar10);
    goto switchD_10622da2_caseD_2;
  case 0x40:
    pcVar8 = asm_lookup_name(pcVar15->words[0],0);
    iVar10 = asm_symbol_length(pcVar8);
    g_yyval.string.text = (char *)asm_operand_node_new(iVar10);
    goto switchD_10622da2_caseD_2;
  case 0x41:
    g_yyval.string.text = (char *)asm_operand_node_new(*(int *)((int)vsp + 0x20));
    goto switchD_10622da2_caseD_2;
  case 0x42:
    g_yyval.string.text = (char *)asm_operand_node_new(*(int *)((int)vsp + 0x20));
    goto switchD_10622da2_caseD_2;
  case 0x43:
    if (g_asm_after_period == 0) goto LAB_10622ea9;
    iVar10 = asm_check_member_operand(pcVar15->ptr);
    g_yyval.string.text = (char *)asm_operand_node_new(iVar10);
switchD_10622da2_caseD_b:
    g_asm_after_period = 0;
    goto switchD_10622da2_caseD_2;
  case 0x44:
    pcVar9 = asm_check_symbol(pcVar15->words[0]);
    g_yyval.string.text = (char *)asm_check_operand_type(pcVar9);
    goto switchD_10622da2_caseD_2;
  case 0x45:
    g_yyval.string.text = (char *)asm_check_register_3((short *)(pcVar15->string).text);
    goto switchD_10622da2_caseD_2;
  case 0x46:
    g_yyval.string.text = (char *)asm_check_register_1(pcVar15->half);
    goto switchD_10622da2_caseD_2;
  case 0x47:
    g_yyval.string.text = (char *)asm_check_float_register(vsp[-2].half,vsp->words[2]);
    goto switchD_10622da2_caseD_2;
  case 0x48:
    g_asm_ptr_form = 1;
    g_asm_size_without_ptr = 0;
    asm_check_ptr_type((&g_asm_size_class_by_keyword)[(short)vsp[-1].half]);
    g_yyval.ptr = pcVar15->ptr;
    goto switchD_10622da2_caseD_2;
  case 0x49:
    g_asm_ptr_form = 1;
    g_asm_size_without_ptr = 0;
    iVar10 = type_size(*(c1_type **)((int)vsp + -0xc));
    cVar5 = asm_size_class_of_bytes(iVar10);
    asm_check_ptr_type(cVar5);
    g_yyval.ptr = pcVar15->ptr;
    goto switchD_10622da2_caseD_2;
  case 0x4a:
    g_asm_ptr_form = 1;
    g_asm_size_without_ptr = 0;
    cVar5 = asm_size_class_of_bytes
                      ((int)(char)(&g_type_rank_table)
                                  [(byte)g_tree_op_to_il_op[vsp[-1].spec.words.storage] & 0xf]);
    asm_check_ptr_type(cVar5);
    g_yyval.ptr = pcVar15->ptr;
    goto switchD_10622da2_caseD_2;
  case 0x4b:
    g_asm_ptr_form = 1;
    g_asm_size_without_ptr = 1;
    asm_warn_ptr_operator(vsp[-1].half);
    g_yyval.ptr = pcVar15->ptr;
    goto switchD_10622da2_caseD_2;
  case 0x4c:
    g_asm_ptr_form = 0;
    g_asm_size_without_ptr = 1;
    if ((g_tree_op_to_il_op[(vsp->spec).words.storage] & 0x1f) == 0x12) {
      asm_warn_ptr_operator(0x3c);
      g_yyval.string.text = (char *)asm_check_symbol(pcVar15->words[0]);
    }
    else {
      iVar10 = asm_operand_description_id();
      diag_error(0x199,iVar10);
LAB_10622ea9:
      g_yyval.string.text = (char *)asm_check_symbol(pcVar15->words[0]);
    }
    goto switchD_10622da2_caseD_2;
  case 0x4d:
    g_asm_ptr_form = 0;
    g_asm_size_without_ptr = 1;
    asm_warn_ptr_operator(vsp->half);
    g_yyval.string.text = (char *)asm_check_symbol(pcVar15->words[0]);
    goto switchD_10622da2_caseD_2;
  case 0x4e:
  case 0x50:
    g_asm_in_brackets = 0;
switchD_10622da2_caseD_31:
    g_yyval.ptr = vsp->ptr;
    goto switchD_10622da2_caseD_2;
  case 0x4f:
  case 0x51:
    if (g_asm_in_brackets != 0) {
      iVar10 = asm_operand_description_id();
      diag_error(0x1aa,(&PTR_s_no_token_1065b868)[(pcVar15->spec).words.storage],iVar10);
    }
    g_asm_in_brackets = 1;
    goto switchD_10622da2_caseD_2;
  }
  iVar10 = asm_is_statement_end(token);
  if (iVar10 != 0) {
    return 1;
  }
  asm_instruction_reset();
  goto switchD_10622da2_caseD_2;
switchD_1064e3f2_caseD_3:
  if (*g_asm_lookahead == '\0') {
    return 1;
  }
  g_asm_lookahead = &g_asm_no_lookahead;
  goto LAB_10622c9c;
}

