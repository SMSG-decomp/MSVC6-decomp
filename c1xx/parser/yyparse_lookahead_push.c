uint __fastcall yyparse_lookahead_push(c1_yy_lookahead_parser *parser)

{
  ushort *puVar1;
  byte *pbVar2;
  byte bVar3;
  byte bVar4;
  short sVar5;
  c1xx_token *pcVar6;
  uint uVar7;
  ushort *puVar8;
  int iVar9;
  ushort uVar10;
  c1_yy_value *pcVar11;
  short *psVar12;
  void **ppvVar13;
  c1_yy_value *pcVar14;
  c1_yy_value *pcVar15;
  
code_r0x1042f80c:
  psVar12 = parser->ps + 1;
  parser->ps = psVar12;
  if (parser->states + 0x96 < psVar12) {
    parse_table_yyerror_nop("yacc stack overflow");
    uVar7 = yyparse_lookahead_return_1();
    return uVar7;
  }
  *psVar12 = parser->state;
  pcVar15 = parser->pv;
  parser->pv = pcVar15 + 1;
  pcVar11 = &g_yyval;
  pcVar15 = pcVar15 + 1;
  for (iVar9 = 10; iVar9 != 0; iVar9 = iVar9 + -1) {
    pcVar15->words[0] = pcVar11->words[0];
    pcVar11 = (c1_yy_value *)(pcVar11->words + 1);
    pcVar15 = (c1_yy_value *)(pcVar15->words + 1);
  }
LAB_1042f848:
  sVar5 = g_lookahead_yy_pact[parser->state];
  if (-1000 < sVar5) {
    if (parser->lookahead == (c1xx_token *)0x0) {
      pcVar6 = (c1xx_token *)yylex_cpp();
      parser->lookahead = pcVar6;
    }
    sVar5 = sVar5 + (ushort)g_token_class[parser->lookahead->code];
    if (((-1 < sVar5) && (sVar5 < 0x666)) &&
       (sVar5 = g_lookahead_yy_action[sVar5],
       g_lookahead_yy_chk[sVar5] == (ushort)g_token_class[parser->lookahead->code])) {
      ppvVar13 = &parser->lookahead->value;
      pcVar15 = &g_yyval;
      for (iVar9 = 10; iVar9 != 0; iVar9 = iVar9 + -1) {
        pcVar15->words[0] = (c1_u32)*ppvVar13;
        ppvVar13 = ppvVar13 + 1;
        pcVar15 = (c1_yy_value *)(pcVar15->words + 1);
      }
      parser->state = sVar5;
      parser->lookahead = (c1xx_token *)0x0;
      if (0 < parser->errflag) {
        uVar7 = parse_action_tail_e1(parser->errflag,(int *)parser);
        return uVar7;
      }
      goto code_r0x1042f80c;
    }
  }
  uVar10 = g_lookahead_yy_def[parser->state];
  if (uVar10 == 0xfffe) {
    if (parser->lookahead == (c1xx_token *)0x0) {
      pcVar6 = (c1xx_token *)yylex_cpp();
      parser->lookahead = pcVar6;
    }
    puVar8 = (ushort *)(g_lookahead_yy_exca + g_lookahead_yy_exca_index[parser->state]);
    uVar10 = *puVar8;
    while ((uVar10 != g_token_class[parser->lookahead->code] && (-1 < (short)uVar10))) {
      puVar1 = puVar8 + 2;
      puVar8 = puVar8 + 2;
      uVar10 = *puVar1;
    }
    uVar10 = puVar8[1];
    if ((short)uVar10 < 0) {
      uVar7 = yyparse_lookahead_return_0();
      return uVar7;
    }
  }
  if (uVar10 != 0) goto switchD_104a5826_default;
  switch(parser->errflag) {
  case 0:
    parse_table_yyerror_nop("syntax error");
    parser->error_count = parser->error_count + 1;
  case 1:
  case 2:
    parser->errflag = 3;
    while( true ) {
      psVar12 = parser->ps;
      if (psVar12 < parser->states) {
        return 1;
      }
      sVar5 = g_lookahead_yy_pact[*psVar12] + 0x100;
      if (((-1 < sVar5) && (sVar5 < 0x666)) &&
         (g_lookahead_yy_chk[g_lookahead_yy_action[sVar5]] == 0x100)) break;
      parser->ps = psVar12 + -1;
      parser->pv = parser->pv + -1;
    }
    parser->state = g_lookahead_yy_action[sVar5];
    uVar7 = yyparse_lookahead_push(parser);
    return uVar7;
  case 3:
    if (g_token_class[parser->lookahead->code] == '\0') {
      return 1;
    }
    parser->lookahead = (c1xx_token *)0x0;
    break;
  default:
    goto switchD_104a5826_default;
  }
  goto LAB_1042f848;
switchD_104a5826_default:
  pcVar15 = parser->pv;
  parser->ps = parser->ps + -(uint)g_lookahead_yy_r2[(short)uVar10];
  bVar3 = g_lookahead_yy_r2[(short)uVar10];
  parser->pv = pcVar15 + -(uint)bVar3;
  bVar4 = g_lookahead_yy_r1[(short)uVar10];
  pcVar11 = pcVar15 + -(uint)bVar3 + 1;
  pcVar14 = &g_yyval;
  for (iVar9 = 10; iVar9 != 0; iVar9 = iVar9 + -1) {
    pcVar14->words[0] = pcVar11->words[0];
    pcVar11 = (c1_yy_value *)(pcVar11->words + 1);
    pcVar14 = (c1_yy_value *)(pcVar14->words + 1);
  }
  iVar9 = (int)(short)(ushort)bVar4;
  sVar5 = *parser->ps + g_lookahead_yy_pgo[iVar9] + 1;
  if ((0x665 < sVar5) ||
     (sVar5 = g_lookahead_yy_action[sVar5], parser->state = sVar5,
     (int)g_lookahead_yy_chk[sVar5] != -iVar9)) {
    parser->state = g_lookahead_yy_action[g_lookahead_yy_pgo[iVar9]];
  }
  switch(uVar10) {
  case 1:
    goto yyparse_lookahead_case_1;
  case 2:
    return pcVar15->words[0];
  case 3:
    return 0;
  case 4:
    g_yyval.words[0] = pcVar15->words[0] | 8;
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfd;
    uVar7 = yyparse_lookahead_push(parser);
    return uVar7;
  case 5:
    g_yyval.words[0] = (pcVar15->words[0] | g_yyval.words[0]) & 0xfffffff7;
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfd;
    uVar7 = yyparse_lookahead_push(parser);
    return uVar7;
  case 6:
    g_yyval.words[0] = (pcVar15->words[0] | g_yyval.words[0]) & 0xfffffff7;
  case 0x2d:
  case 0x2e:
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfd;
    uVar7 = yyparse_lookahead_push(parser);
    return uVar7;
  case 7:
  case 8:
    uVar7 = pcVar15[-2].words[0];
    g_yyval.words[0] = uVar7 | 2;
    if ((uVar7 & 8) != 0) {
      g_yyval.words[0] = uVar7 & 0xfffffffe | 2;
      uVar7 = yyparse_lookahead_push(parser);
      return uVar7;
    }
    goto code_r0x1042f80c;
  case 9:
    g_yyval.words[0] = 1;
    if (pcVar15->words[0] == 5) {
      uVar7 = parse_action_tail_e3((int *)parser);
      return uVar7;
    }
    goto code_r0x1042f80c;
  case 10:
  case 0xb:
    g_yyval.words[0] = 1;
    uVar7 = yyparse_lookahead_push(parser);
    return uVar7;
  case 0xc:
    goto code_r0x1042f905;
  case 0xd:
  case 0x2f:
  case 0x30:
  case 0x36:
  case 0x41:
  case 0x44:
  case 0x45:
  case 0x88:
  case 0x89:
  case 0x8a:
  case 0x8b:
  case 0x8c:
  case 0x8d:
  case 0x95:
  case 0x9d:
  case 0x9e:
  case 0x9f:
  case 0xac:
    break;
  default:
    goto code_r0x1042f80c;
  case 0x10:
  case 0x11:
  case 0x16:
    g_yyval.words[0] = 0;
    uVar7 = yyparse_lookahead_push(parser);
    return uVar7;
  case 0x12:
    if (pcVar15[-1].words[0] == 0) {
      uVar7 = parse_action_tail_e2(pcVar15->words,(int *)parser);
      return uVar7;
    }
    goto code_r0x1042f80c;
  case 0x13:
  case 0x14:
    g_yyval.words[0] = 6;
    uVar7 = yyparse_lookahead_push(parser);
    return uVar7;
  case 0x15:
    if (0 < g_paren_depth) {
      g_paren_depth = g_paren_depth + -1;
    }
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] | 4;
    g_yyval.words[0] = pcVar15[-1].words[0];
    uVar7 = yyparse_lookahead_push(parser);
    return uVar7;
  case 0x19:
  case 0x1b:
  case 0x99:
  case 0x9b:
    g_compile_flags_c4 = g_compile_flags_c4 & 0xfffffffb;
    uVar7 = yyparse_lookahead_push(parser);
    return uVar7;
  case 0x22:
    if (0 < g_paren_depth) {
      g_paren_depth = g_paren_depth + -1;
    }
    g_yyval.words[0] = 5;
    uVar7 = yyparse_lookahead_push(parser);
    return uVar7;
  case 0x23:
  case 0x24:
    if (0 < g_paren_depth) {
      g_paren_depth = g_paren_depth + -1;
    }
    g_yyval.words[0] = 3;
    uVar7 = yyparse_lookahead_push(parser);
    return uVar7;
  case 0x27:
  case 0x28:
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfc;
    goto code_r0x1042f80c;
  case 0x47:
  case 0x48:
  case 0x49:
    g_yyval.words[0] = 2;
    goto code_r0x1042f80c;
  case 0x4b:
    g_yyval.words[0] = pcVar15->words[0];
    uVar7 = yyparse_lookahead_push(parser);
    return uVar7;
  case 0x50:
    if (0 < g_paren_depth) {
      g_paren_depth = g_paren_depth + -1;
    }
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] | 4;
    goto code_r0x1042f80c;
  case 0x7a:
    g_compile_flags_c4 = g_compile_flags_c4 & 0xfffffffe;
    uVar7 = yyparse_lookahead_push(parser);
    return uVar7;
  case 0x7c:
  case 0x7d:
    g_sizeof_depth = g_sizeof_depth + -1;
    uVar7 = yyparse_lookahead_push(parser);
    return uVar7;
  case 0x87:
    iVar9 = g_paren_depth + 1;
    if (0x3b < iVar9) {
      g_paren_depth = iVar9;
      diag_fatal_simple(0xd);
    }
    pbVar2 = g_paren_level_flags + g_paren_depth + 1;
    g_paren_depth = iVar9;
    *pbVar2 = 0;
    *pbVar2 = *pbVar2 | 0x10;
    uVar7 = yyparse_lookahead_push(parser);
    return uVar7;
  case 0xa4:
    if (0 < g_paren_depth) {
      g_paren_depth = g_paren_depth + -1;
    }
    g_compile_flags_c8 = g_compile_flags_c8 & 0xffffffef;
    g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] | 2;
  case 0x7e:
    g_compile_flags_c4 = g_compile_flags_c4 & 0x7fffffff;
    uVar7 = yyparse_lookahead_push(parser);
    return uVar7;
  case 0xa9:
    g_compile_flags_c8 = g_compile_flags_c8 | 0x10;
    g_compile_flags_c4 = g_compile_flags_c4 | 0x80000000;
    uVar7 = yyparse_lookahead_push(parser);
    return uVar7;
  case 0xaa:
    g_compile_flags_c8 = g_compile_flags_c8 | 0x10;
    g_compile_flags_c4 = g_compile_flags_c4 | 0x80000000;
    iVar9 = g_paren_depth + 1;
    if (0x3b < iVar9) {
      g_paren_depth = iVar9;
      diag_fatal_simple(0xd);
    }
    pbVar2 = g_paren_level_flags + g_paren_depth + 1;
    g_paren_depth = iVar9;
    *pbVar2 = 0;
    *pbVar2 = *pbVar2 | 0x40;
    uVar7 = yyparse_lookahead_push(parser);
    return uVar7;
  case 0xb3:
  }
  if (0 < g_paren_depth) {
    g_paren_depth = g_paren_depth + -1;
    uVar7 = yyparse_lookahead_push(parser);
    return uVar7;
  }
  goto code_r0x1042f80c;
code_r0x1042f905:
  return 1;
yyparse_lookahead_case_1:
  if (g_paren_depth == 0) {
    if (((pcVar15->spec).spec[0] & 2) == 0) {
      if (parser->lookahead == (c1xx_token *)0x0) {
        pcVar6 = (c1xx_token *)yylex_cpp();
        parser->lookahead = pcVar6;
      }
      switch(parser->lookahead->code) {
      case 'u':
      case '{':
      case '\x7f':
      case 0xa6:
        goto code_r0x1042f905;
      default:
        return 0;
      }
    }
    return 0;
  }
  uVar7 = pcVar15->words[0];
  if (((uVar7 & 1) != 0) && ((uVar7 & 8) == 0)) {
    return 0;
  }
  if ((uVar7 & 4) == 0) {
    if (parser->lookahead == (c1xx_token *)0x0) {
      pcVar6 = (c1xx_token *)yylex_cpp();
      parser->lookahead = pcVar6;
    }
    return (uint)(g_token_class[parser->lookahead->code] == '~');
  }
  return 0;
}

