int __cdecl yyparse_asm(void)

{
  ushort uVar1;
  c1_type *pcVar2;
  ushort *puVar3;
  char cVar4;
  short sVar5;
  c1_yy_value *pcVar6;
  c1_symbol *pcVar7;
  c1_u8 *operand;
  int iVar8;
  short *left;
  short *psVar9;
  short sVar10;
  void **ppvVar11;
  c1_u32 *pcVar12;
  int state;
  c1_u32 *pcVar13;
  c1_u32 *pcVar14;
  c1_yy_value *pcVar15;
  byte bVar16;
  short local_34;
  short *local_30;
  c1_u32 *local_2c;
  c1_yy_value local_28;
  
  local_34 = 0;
  local_2c = (c1_u32 *)(g_asm_yy_states + 0x84);
  local_30 = g_asm_yy_states;
LAB_10455685:
  pcVar13 = local_2c + 10;
  *local_30 = local_34;
  pcVar6 = &g_yyval;
  pcVar14 = pcVar13;
  for (iVar8 = 10; iVar8 != 0; iVar8 = iVar8 + -1) {
    *pcVar14 = pcVar6->words[0];
    pcVar6 = (c1_yy_value *)(pcVar6->words + 1);
    pcVar14 = pcVar14 + 1;
  }
  iVar8 = (int)local_34;
LAB_104556ab:
  sVar10 = g_asm_yy_pact[iVar8];
  pcVar14 = pcVar13;
  if (-1000 < sVar10) {
    if (g_asm_yy_lookahead == &g_asm_empty_token) {
      g_asm_yy_lookahead = (c1xx_token *)asm_yylex();
    }
    sVar5 = g_asm_yy_errflag;
    sVar10 = sVar10 + (ushort)g_asm_yy_lookahead->code;
    if (((sVar10 < 0) || (0x103 < sVar10)) ||
       (sVar10 = g_asm_yy_action[sVar10], g_asm_yy_chk[sVar10] != (ushort)g_asm_yy_lookahead->code))
    goto LAB_104556f3;
    ppvVar11 = &g_asm_yy_lookahead->value;
    pcVar6 = &g_yyval;
    for (iVar8 = 10; iVar8 != 0; iVar8 = iVar8 + -1) {
      pcVar6->words[0] = (c1_u32)*ppvVar11;
      ppvVar11 = ppvVar11 + 1;
      pcVar6 = (c1_yy_value *)(pcVar6->words + 1);
    }
    g_asm_yy_lookahead = &g_asm_empty_token;
    local_34 = sVar10;
    if (0 < sVar5) {
      g_asm_yy_errflag = g_asm_yy_errflag + -1;
    }
    goto switchD_104557af_caseD_2;
  }
LAB_104556f3:
  sVar10 = g_asm_yy_def[iVar8];
  if (sVar10 == -2) {
    if (g_asm_yy_lookahead == &g_asm_empty_token) {
      g_asm_yy_lookahead = (c1xx_token *)asm_yylex();
    }
    psVar9 = g_asm_yy_exca + g_asm_yy_exca_index[iVar8];
    uVar1 = g_asm_yy_exca[g_asm_yy_exca_index[iVar8]];
    while ((uVar1 != g_asm_yy_lookahead->code && (-1 < (short)uVar1))) {
      puVar3 = (ushort *)(psVar9 + 2);
      psVar9 = psVar9 + 2;
      uVar1 = *puVar3;
    }
    sVar10 = psVar9[1];
    if (sVar10 < 0) {
      return 0;
    }
  }
  if (sVar10 != 0) {
switchD_104b8a21_default:
    local_30 = local_30 + -(uint)g_asm_yy_r2[sVar10];
    pcVar14 = pcVar13 + (uint)g_asm_yy_r2[sVar10] * -10;
    bVar16 = g_asm_yy_r1[sVar10];
    pcVar12 = pcVar14 + 10;
    pcVar6 = &g_yyval;
    for (iVar8 = 10; iVar8 != 0; iVar8 = iVar8 + -1) {
      pcVar6->words[0] = *pcVar12;
      pcVar12 = pcVar12 + 1;
      pcVar6 = (c1_yy_value *)(pcVar6->words + 1);
    }
    sVar5 = *local_30 + g_asm_yy_pgo[(short)(ushort)bVar16] + 1;
    if ((0x103 < sVar5) ||
       (local_34 = g_asm_yy_action[sVar5],
       (int)g_asm_yy_chk[local_34] != -(int)(short)(ushort)bVar16)) {
      local_34 = g_asm_yy_action[g_asm_yy_pgo[(short)(ushort)bVar16]];
    }
    switch(sVar10) {
    case 3:
      if ((byte)*pcVar13 == 0xf2) {
        il_emit_pragma_or_segment_record(0x24);
      }
      arena_reset_ptr(g_arenas + 5);
      bVar16 = (byte)*pcVar13;
      goto LAB_104557d4;
    case 4:
      g_asm_yy_errflag = 0;
      if ((byte)*pcVar13 == 0xf2) {
        il_emit_pragma_or_segment_record(0x24);
      }
      arena_reset_ptr(g_arenas + 5);
      bVar16 = (byte)*pcVar13;
LAB_104557d4:
      iVar8 = asm_is_statement_end(bVar16);
      if (iVar8 != 0) {
        return 1;
      }
      asm_instruction_reset();
      break;
    case 7:
      g_asm_brace_depth = g_asm_brace_depth + 1;
      break;
    case 9:
      asm_check_label_redefinition(*local_2c);
      break;
    case 0xb:
      asm_warn_directive((short)*local_2c,local_2c[0xc]);
      break;
    case 0xc:
      g_asm_operands_begun = 1;
      asm_instruction_begin((short)*pcVar13);
      break;
    case 0xd:
      goto switchD_104557af_caseD_a;
    case 0xe:
switchD_104557af_caseD_b:
      g_asm_period_seen = 0;
      break;
    case 0xf:
    case 0x31:
      g_asm_period_seen = 1;
      break;
    case 0x10:
      g_asm_operand_index = 0;
      g_yyval.words[2] = 0;
      g_yyval.words[3] = 0;
      break;
    case 0x11:
      g_asm_operand_index = 1;
      g_yyval.words[0] = *pcVar13;
      g_yyval.words[1] = local_2c[0xb];
      g_yyval.words[2] = local_2c[0xc];
      g_yyval.words[3] = local_2c[0xd];
      break;
    case 0x14:
      asm_instruction_begin((short)*pcVar13);
      asm_check_operand_count();
      break;
    case 0x15:
      asm_instruction_begin((short)*pcVar13);
      goto switchD_104557af_caseD_a;
    case 0x17:
      g_asm_operand_index = g_asm_operand_index + 1;
      break;
    case 0x19:
      if (g_asm_operand_index < 2) {
        g_asm_operand_index = g_asm_operand_index + 1;
        g_asm_current_operand = (c1_asm_operand_slot *)asm_operand_reset(g_asm_operand_index);
      }
      break;
    case 0x1b:
      if (*(short *)*pcVar13 != 3) {
        asm_operand_add_displacement(*(int *)((short *)*pcVar13 + 2));
      }
      break;
    case 0x1c:
      psVar9 = (short *)*pcVar13;
      if (*psVar9 == 0) {
        g_yyval.ptr = asm_check_index_register
                                ((ushort)(byte)*local_2c,(short *)local_2c[-10],psVar9);
      }
      else {
        g_yyval.ptr = asm_check_index_register
                                ((ushort)(byte)*local_2c,psVar9,(short *)local_2c[-10]);
      }
      break;
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
      g_yyval.ptr = asm_check_constant_operand
                              ((ushort)(byte)*local_2c,(short *)local_2c[-10],(short *)*pcVar13);
      break;
    case 0x2a:
    case 0x2b:
      psVar9 = (short *)*pcVar13;
      left = (short *)local_2c[-10];
      bVar16 = (byte)*local_2c;
      goto LAB_1045587d;
    case 0x2c:
      g_asm_ptr_written = '\x01';
      g_asm_distance_operator = 1;
      if (*(short *)local_2c[-10] == 0) {
        iVar8 = *(int *)((short *)local_2c[-10] + 2);
        if (iVar8 == 0xffff) {
          asm_warn_ptr_operator(0x3d);
          g_yyval.words[0] = *pcVar13;
        }
        else {
          if (iVar8 != 0xfffe) goto LAB_104b8cd1;
          asm_warn_ptr_operator(0x3e);
          g_yyval.words[0] = *pcVar13;
        }
      }
      else {
LAB_104b8cd1:
        iVar8 = asm_operand_description_id();
        diag_error(0x198,iVar8);
        g_yyval.words[0] = *pcVar13;
      }
      break;
    case 0x2d:
      g_asm_period_seen = 1;
      pcVar7 = asm_lookup_name((fe_name *)*local_2c,0);
      pcVar2 = pcVar7->type;
      cVar4 = (char)pcVar2->code;
      while (cVar4 < '\0') {
        pcVar2 = pcVar2->base;
        cVar4 = (char)pcVar2->code;
      }
      if ((pcVar2->code & 0x300) == 0) {
LAB_104b8d70:
        g_asm_member_class = (c1_symbol *)0x0;
      }
      else {
        g_asm_member_class = (pcVar2->extra).cls;
      }
      break;
    case 0x2e:
    case 0x30:
      g_asm_period_seen = 0;
      psVar9 = (short *)*pcVar13;
      left = (short *)local_2c[-0x1e];
      goto LAB_104b8d93;
    case 0x2f:
      g_asm_period_seen = 1;
      puVar3 = (ushort *)local_2c[6];
      cVar4 = (char)*puVar3;
      while (cVar4 < '\0') {
        puVar3 = *(ushort **)(puVar3 + 2);
        cVar4 = (char)*puVar3;
      }
      if ((*puVar3 & 0x300) == 0) goto LAB_104b8d70;
      g_asm_member_class = *(c1_symbol **)(puVar3 + 4);
      break;
    case 0x32:
      g_asm_period_seen = 0;
    case 0x52:
      psVar9 = (short *)*pcVar13;
      left = (short *)local_2c[-0x14];
LAB_104b8d93:
      bVar16 = (byte)local_2c[-10];
LAB_1045587d:
      g_yyval.ptr = asm_check_constant_expression((ushort)bVar16,left,psVar9);
      break;
    case 0x34:
      goto switchD_104557af_caseD_31;
    case 0x35:
    case 0x38:
      g_yyval.ptr = asm_check_constant_operand_2((ushort)(byte)*local_2c,(short *)*pcVar13);
      break;
    case 0x36:
    case 0x39:
      g_yyval.ptr = asm_check_constant_operand_2((ushort)(byte)*local_2c,(short *)*pcVar13);
      break;
    case 0x37:
      g_yyval.ptr = asm_check_constant_operand_2((ushort)(byte)*local_2c,(short *)*pcVar13);
      break;
    case 0x3a:
      g_yyval.ptr = asm_check_segment_override((short)local_2c[-10],(short *)*pcVar13);
      break;
    case 0x3b:
      iVar8 = type_size((c1_type *)local_2c[0x10]);
      g_yyval.ptr = asm_operand_node_new(iVar8);
      break;
    case 0x3c:
      g_yyval.ptr = asm_operand_node_new
                              ((int)(char)(&g_type_rank_table)
                                          [(byte)g_tree_op_to_il_op[(byte)*pcVar13] & 0xf]);
      break;
    case 0x3d:
      g_yyval.ptr = asm_operand_node_new
                              ((uint)*(byte *)((int)g_asm_yy_def + (short)*pcVar13 + 0xde));
      break;
    case 0x3e:
      pcVar7 = asm_lookup_name((fe_name *)*pcVar13,1);
      iVar8 = asm_symbol_operand_size(pcVar7);
      g_yyval.ptr = asm_operand_node_new(iVar8);
      break;
    case 0x3f:
      pcVar7 = asm_lookup_name((fe_name *)*pcVar13,0);
      iVar8 = type_size(pcVar7->type);
      g_yyval.ptr = asm_operand_node_new(iVar8);
      break;
    case 0x40:
      pcVar7 = asm_lookup_name((fe_name *)*pcVar13,0);
      iVar8 = asm_symbol_length(pcVar7);
      g_yyval.ptr = asm_operand_node_new(iVar8);
      break;
    case 0x41:
      g_yyval.ptr = asm_operand_node_new(local_2c[0xc]);
      break;
    case 0x42:
      g_yyval.ptr = asm_operand_node_new(local_2c[0xc]);
      break;
    case 0x43:
      if (g_asm_period_seen != 0) {
        iVar8 = asm_check_member_operand((fe_name *)*pcVar13);
        g_yyval.ptr = asm_operand_node_new(iVar8);
        goto switchD_104557af_caseD_b;
      }
LAB_104558b6:
      g_yyval.ptr = asm_check_symbol(*pcVar13);
      break;
    case 0x44:
      operand = asm_check_symbol(*pcVar13);
      g_yyval.ptr = asm_check_operand_type(operand);
      break;
    case 0x45:
      g_yyval.ptr = asm_check_register_3((short *)*pcVar13);
      break;
    case 0x46:
      g_yyval.ptr = asm_check_register_1((short)*pcVar13);
      break;
    case 0x47:
      g_yyval.ptr = asm_check_float_register((short)local_2c[-0x14],local_2c[2]);
      break;
    case 0x48:
      g_asm_ptr_written = '\x01';
      g_asm_distance_operator = 0;
      asm_check_ptr_type(*(char *)((int)g_asm_yy_def + (short)local_2c[-10] + 0xde));
      g_yyval.words[0] = *pcVar13;
      break;
    case 0x49:
      g_asm_ptr_written = '\x01';
      g_asm_distance_operator = 0;
      iVar8 = type_size((c1_type *)local_2c[-4]);
      cVar4 = asm_size_class_of_bytes(iVar8);
      asm_check_ptr_type(cVar4);
      g_yyval.words[0] = *pcVar13;
      break;
    case 0x4a:
      g_asm_ptr_written = '\x01';
      g_asm_distance_operator = 0;
      cVar4 = asm_size_class_of_bytes
                        ((int)(char)(&g_type_rank_table)
                                    [(byte)g_tree_op_to_il_op[(byte)local_2c[-10]] & 0xf]);
      asm_check_ptr_type(cVar4);
      g_yyval.words[0] = *pcVar13;
      break;
    case 0x4b:
      g_asm_ptr_written = '\x01';
      g_asm_distance_operator = 1;
      asm_warn_ptr_operator((short)local_2c[-10]);
      g_yyval.words[0] = *pcVar13;
      break;
    case 0x4c:
      g_asm_ptr_written = '\0';
      g_asm_distance_operator = 1;
      if ((g_tree_op_to_il_op[(byte)*local_2c] & 0x1f) != 0x12) {
        iVar8 = asm_operand_description_id();
        diag_error(0x199,iVar8);
        goto LAB_104558b6;
      }
      asm_warn_ptr_operator(0x3c);
      g_yyval.ptr = asm_check_symbol(*pcVar13);
      break;
    case 0x4d:
      g_asm_ptr_written = '\0';
      g_asm_distance_operator = 1;
      asm_warn_ptr_operator((short)*local_2c);
      g_yyval.ptr = asm_check_symbol(*pcVar13);
      break;
    case 0x4e:
    case 0x50:
      g_asm_in_brackets = 0;
      goto switchD_104557af_caseD_31;
    case 0x4f:
    case 0x51:
      if (g_asm_in_brackets != 0) {
        iVar8 = asm_operand_description_id();
        diag_error(0x1aa,g_asm_token_spelling[(byte)*pcVar13],iVar8);
      }
      g_asm_in_brackets = 1;
    }
    goto switchD_104557af_caseD_2;
  }
  switch(g_asm_yy_errflag) {
  case 0:
    sVar10 = 3;
    iVar8 = 0;
    psVar9 = g_asm_yy_corrections;
    break;
  case 1:
  case 2:
    goto switchD_104b8a21_caseD_1;
  case 3:
    goto switchD_104b8a21_caseD_3;
  default:
    goto switchD_104b8a21_default;
  }
  do {
    if (local_34 <= sVar10) break;
    sVar10 = psVar9[3];
    psVar9 = psVar9 + 3;
    iVar8 = iVar8 + 3;
  } while (sVar10 != -1000);
  if (local_34 == g_asm_yy_corrections[iVar8]) {
    state = (int)g_asm_yy_corrections[iVar8 + 1];
    if (state < 0) {
      g_asm_yy_errflag = g_asm_yy_errflag + 1;
      state = -state;
    }
    if (g_asm_yy_errflag < 2) {
      asm_report_syntax_error((char *)g_asm_yy_lookahead,state);
    }
    pcVar6 = asm_parser_value_for_token(&local_28,state);
    local_34 = g_asm_yy_corrections[iVar8 + 2];
    pcVar15 = &g_yyval;
    for (iVar8 = 10; iVar8 != 0; iVar8 = iVar8 + -1) {
      pcVar15->words[0] = pcVar6->words[0];
      pcVar6 = (c1_yy_value *)(pcVar6->words + 1);
      pcVar15 = (c1_yy_value *)(pcVar15->words + 1);
    }
  }
  else {
    asm_check_parser_stack("syntax error");
    g_asm_yy_nerrs = g_asm_yy_nerrs + 1;
switchD_104b8a21_caseD_1:
    g_asm_yy_errflag = 3;
    local_2c = pcVar13;
    while( true ) {
      if (local_30 < g_asm_yy_states) {
        g_asm_yy_errflag = 3;
        return 1;
      }
      sVar10 = g_asm_yy_pact[*local_30] + 0x100;
      if (((-1 < sVar10) && (sVar10 < 0x104)) && (g_asm_yy_chk[g_asm_yy_action[sVar10]] == 0x100))
      break;
      local_30 = local_30 + -1;
      local_2c = local_2c + -10;
    }
    local_34 = g_asm_yy_action[sVar10];
    pcVar14 = local_2c;
  }
  goto switchD_104557af_caseD_2;
switchD_104557af_caseD_31:
  g_yyval.words[0] = *local_2c;
  goto switchD_104557af_caseD_2;
switchD_104557af_caseD_a:
  asm_check_operand_count();
switchD_104557af_caseD_2:
  local_2c = pcVar14;
  local_30 = local_30 + 1;
  if (&g_asm_yy_states_end < local_30) {
    asm_check_parser_stack("yacc stack overflow");
    return 1;
  }
  goto LAB_10455685;
switchD_104b8a21_caseD_3:
  if (g_asm_yy_lookahead->code == '\0') {
    return 1;
  }
  g_asm_yy_lookahead = &g_asm_empty_token;
  goto LAB_104556ab;
}

