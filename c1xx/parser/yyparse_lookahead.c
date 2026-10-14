uint __fastcall yyparse_lookahead(c1_yy_lookahead_parser *parser)

{
  ushort *puVar1;
  byte *pbVar2;
  byte bVar3;
  byte bVar4;
  short sVar5;
  uint uVar6;
  short *psVar7;
  c1xx_token *pcVar8;
  ushort *puVar9;
  int iVar10;
  ushort uVar11;
  uint *src;
  uint *src_2;
  uint *dst;
  c1_yy_value *pcVar12;
  c1_yy_value *pcVar13;
  
  psVar7 = parser->ps + 1;
  parser->ps = psVar7;
  if (parser->states + 0x96 < psVar7) {
    uVar6 = yyparse_lookahead_stack_overflow();
    return uVar6;
  }
  do {
    *psVar7 = parser->state;
    pcVar13 = parser->pv;
    parser->pv = pcVar13 + 1;
    src_2 = (uint *)&g_yyval;
    pcVar13 = pcVar13 + 1;
    for (iVar10 = 10; iVar10 != 0; iVar10 = iVar10 + -1) {
      pcVar13->words[0] = *src_2;
      src_2 = src_2 + 1;
      pcVar13 = (c1_yy_value *)(pcVar13->words + 1);
    }
LAB_1042f848:
    sVar5 = g_lookahead_yy_pact[parser->state];
    if (-1000 < sVar5) {
      if (parser->lookahead == (c1xx_token *)0x0) {
        pcVar8 = (c1xx_token *)yylex_cpp();
        parser->lookahead = pcVar8;
      }
      sVar5 = sVar5 + (ushort)g_token_class[parser->lookahead->code];
      if (((sVar5 < 0) || (0x665 < sVar5)) ||
         (sVar5 = g_lookahead_yy_action[sVar5],
         g_lookahead_yy_chk[sVar5] != (ushort)g_token_class[parser->lookahead->code]))
      goto LAB_1042f60c;
      dst = (uint *)&parser->lookahead->value;
      pcVar13 = &g_yyval;
      for (iVar10 = 10; iVar10 != 0; iVar10 = iVar10 + -1) {
        pcVar13->words[0] = *dst;
        dst = dst + 1;
        pcVar13 = (c1_yy_value *)(pcVar13->words + 1);
      }
      parser->state = sVar5;
      parser->lookahead = (c1xx_token *)0x0;
      if (0 < parser->errflag) {
        uVar6 = parse_action_tail_e1(parser->errflag,(int *)parser);
        return uVar6;
      }
      goto code_r0x1042f80c;
    }
LAB_1042f60c:
    uVar11 = g_lookahead_yy_def[parser->state];
    if (uVar11 == 0xfffe) {
      if (parser->lookahead == (c1xx_token *)0x0) {
        pcVar8 = (c1xx_token *)yylex_cpp();
        parser->lookahead = pcVar8;
      }
      puVar9 = (ushort *)(g_lookahead_yy_exca + g_lookahead_yy_exca_index[parser->state]);
      uVar11 = *puVar9;
      while ((uVar11 != g_token_class[parser->lookahead->code] && (-1 < (short)uVar11))) {
        puVar1 = puVar9 + 2;
        puVar9 = puVar9 + 2;
        uVar11 = *puVar1;
      }
      uVar11 = puVar9[1];
      if ((short)uVar11 < 0) {
        uVar6 = yyparse_lookahead_return_0();
        return uVar6;
      }
    }
    if (uVar11 == 0) {
      switch(parser->errflag) {
      case 0:
        parse_table_yyerror_nop("syntax error");
        parser->error_count = parser->error_count + 1;
      case 1:
      case 2:
        parser->errflag = 3;
        while( true ) {
          psVar7 = parser->ps;
          if (psVar7 < parser->states) {
            return 1;
          }
          sVar5 = g_lookahead_yy_pact[*psVar7] + 0x100;
          if (((-1 < sVar5) && (sVar5 < 0x666)) &&
             (g_lookahead_yy_chk[g_lookahead_yy_action[sVar5]] == 0x100)) break;
          parser->ps = psVar7 + -1;
          parser->pv = parser->pv + -1;
        }
        parser->state = g_lookahead_yy_action[sVar5];
        uVar6 = yyparse_lookahead_push(parser);
        return uVar6;
      case 3:
        goto switchD_104a5826_caseD_3;
      }
    }
    pcVar13 = parser->pv;
    parser->ps = parser->ps + -(uint)g_lookahead_yy_r2[(short)uVar11];
    bVar3 = g_lookahead_yy_r2[(short)uVar11];
    parser->pv = pcVar13 + -(uint)bVar3;
    bVar4 = g_lookahead_yy_r1[(short)uVar11];
    src = (uint *)(pcVar13 + -(uint)bVar3 + 1);
    pcVar12 = &g_yyval;
    for (iVar10 = 10; iVar10 != 0; iVar10 = iVar10 + -1) {
      pcVar12->words[0] = *src;
      src = src + 1;
      pcVar12 = (c1_yy_value *)(pcVar12->words + 1);
    }
    iVar10 = (int)(short)(ushort)bVar4;
    sVar5 = *parser->ps + g_lookahead_yy_pgo[iVar10] + 1;
    if ((0x665 < sVar5) ||
       (sVar5 = g_lookahead_yy_action[sVar5], parser->state = sVar5,
       (int)g_lookahead_yy_chk[sVar5] != -iVar10)) {
      parser->state = g_lookahead_yy_action[g_lookahead_yy_pgo[iVar10]];
    }
    switch(uVar11) {
    case 1:
      if (g_paren_depth != 0) {
        uVar6 = pcVar13->words[0];
        if (((uVar6 & 1) != 0) && ((uVar6 & 8) == 0)) {
          return 0;
        }
        if ((uVar6 & 4) == 0) {
          if (parser->lookahead == (c1xx_token *)0x0) {
            pcVar8 = (c1xx_token *)yylex_cpp();
            parser->lookahead = pcVar8;
          }
          return (uint)(g_token_class[parser->lookahead->code] == '~');
        }
        return 0;
      }
      if (((pcVar13->spec).spec[0] & 2) != 0) {
        return 0;
      }
      if (parser->lookahead == (c1xx_token *)0x0) {
        pcVar8 = (c1xx_token *)yylex_cpp();
        parser->lookahead = pcVar8;
      }
      switch(parser->lookahead->code) {
      case 'u':
      case '{':
      case '\x7f':
      case 0xa6:
        goto code_r0x1042f905;
      default:
        goto code_r0x104a5af9;
      }
    case 2:
      return pcVar13->words[0];
    case 3:
code_r0x104a5af9:
      return 0;
    case 4:
      g_yyval.words[0] = pcVar13->words[0] | 8;
      g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfd;
      uVar6 = yyparse_lookahead_push(parser);
      return uVar6;
    case 5:
      g_yyval.words[0] = (pcVar13->words[0] | g_yyval.words[0]) & 0xfffffff7;
      g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfd;
      uVar6 = yyparse_lookahead_push(parser);
      return uVar6;
    case 6:
      g_yyval.words[0] = (pcVar13->words[0] | g_yyval.words[0]) & 0xfffffff7;
    case 0x2d:
    case 0x2e:
      g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfd;
      uVar6 = yyparse_lookahead_push(parser);
      return uVar6;
    case 7:
    case 8:
      uVar6 = pcVar13[-2].words[0];
      g_yyval.words[0] = uVar6 | 2;
      if ((uVar6 & 8) != 0) {
        g_yyval.words[0] = uVar6 & 0xfffffffe | 2;
        uVar6 = yyparse_lookahead_push(parser);
        return uVar6;
      }
      break;
    case 9:
      g_yyval.words[0] = 1;
      if (pcVar13->words[0] == 5) {
        uVar6 = parse_action_tail_e3((int *)parser);
        return uVar6;
      }
      break;
    case 10:
    case 0xb:
      g_yyval.words[0] = 1;
      uVar6 = yyparse_lookahead_push(parser);
      return uVar6;
    case 0xc:
code_r0x1042f905:
      return 1;
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
      goto joined_r0x104a5ab0;
    case 0x10:
    case 0x11:
    case 0x16:
      g_yyval.words[0] = 0;
      uVar6 = yyparse_lookahead_push(parser);
      return uVar6;
    case 0x12:
      if (pcVar13[-1].words[0] == 0) {
        uVar6 = parse_action_tail_e2(pcVar13->words,(int *)parser);
        return uVar6;
      }
      break;
    case 0x13:
    case 0x14:
      g_yyval.words[0] = 6;
      uVar6 = yyparse_lookahead_push(parser);
      return uVar6;
    case 0x15:
      if (0 < g_paren_depth) {
        g_paren_depth = g_paren_depth + -1;
      }
      g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] | 4;
      g_yyval.words[0] = pcVar13[-1].words[0];
      uVar6 = yyparse_lookahead_push(parser);
      return uVar6;
    case 0x19:
    case 0x1b:
    case 0x99:
    case 0x9b:
      g_compile_flags_c4 = g_compile_flags_c4 & 0xfffffffb;
      uVar6 = yyparse_lookahead_push(parser);
      return uVar6;
    case 0x22:
      if (0 < g_paren_depth) {
        g_paren_depth = g_paren_depth + -1;
      }
      g_yyval.words[0] = 5;
      uVar6 = yyparse_lookahead_push(parser);
      return uVar6;
    case 0x23:
    case 0x24:
      if (0 < g_paren_depth) {
        g_paren_depth = g_paren_depth + -1;
      }
      g_yyval.words[0] = 3;
      uVar6 = yyparse_lookahead_push(parser);
      return uVar6;
    case 0x27:
    case 0x28:
      g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] & 0xfc;
      break;
    case 0x47:
    case 0x48:
    case 0x49:
      g_yyval.words[0] = 2;
      break;
    case 0x4b:
      g_yyval.words[0] = pcVar13->words[0];
      uVar6 = yyparse_lookahead_push(parser);
      return uVar6;
    case 0x50:
      if (0 < g_paren_depth) {
        g_paren_depth = g_paren_depth + -1;
      }
      g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] | 4;
      break;
    case 0x7a:
      g_compile_flags_c4 = g_compile_flags_c4 & 0xfffffffe;
      uVar6 = yyparse_lookahead_push(parser);
      return uVar6;
    case 0x7c:
    case 0x7d:
      g_sizeof_depth = g_sizeof_depth + -1;
      uVar6 = yyparse_lookahead_push(parser);
      return uVar6;
    case 0x87:
      iVar10 = g_paren_depth + 1;
      if (0x3b < iVar10) {
        g_paren_depth = iVar10;
        diag_fatal_simple(0xd);
      }
      pbVar2 = g_paren_level_flags + g_paren_depth + 1;
      g_paren_depth = iVar10;
      *pbVar2 = 0;
      *pbVar2 = *pbVar2 | 0x10;
      uVar6 = yyparse_lookahead_push(parser);
      return uVar6;
    case 0xa4:
      if (0 < g_paren_depth) {
        g_paren_depth = g_paren_depth + -1;
      }
      g_compile_flags_c8 = g_compile_flags_c8 & 0xffffffef;
      g_paren_level_flags[g_paren_depth] = g_paren_level_flags[g_paren_depth] | 2;
    case 0x7e:
      g_compile_flags_c4 = g_compile_flags_c4 & 0x7fffffff;
      uVar6 = yyparse_lookahead_push(parser);
      return uVar6;
    case 0xa9:
      g_compile_flags_c8 = g_compile_flags_c8 | 0x10;
      g_compile_flags_c4 = g_compile_flags_c4 | 0x80000000;
      uVar6 = yyparse_lookahead_push(parser);
      return uVar6;
    case 0xaa:
      g_compile_flags_c8 = g_compile_flags_c8 | 0x10;
      g_compile_flags_c4 = g_compile_flags_c4 | 0x80000000;
      iVar10 = g_paren_depth + 1;
      if (0x3b < iVar10) {
        g_paren_depth = iVar10;
        diag_fatal_simple(0xd);
      }
      pbVar2 = g_paren_level_flags + g_paren_depth + 1;
      g_paren_depth = iVar10;
      *pbVar2 = 0;
      *pbVar2 = *pbVar2 | 0x40;
      uVar6 = yyparse_lookahead_push(parser);
      return uVar6;
    case 0xb3:
joined_r0x104a5ab0:
      if (0 < g_paren_depth) {
        g_paren_depth = g_paren_depth + -1;
        uVar6 = yyparse_lookahead_push(parser);
        return uVar6;
      }
    }
code_r0x1042f80c:
    psVar7 = parser->ps + 1;
    parser->ps = psVar7;
    if (parser->states + 0x96 < psVar7) {
      parse_table_yyerror_nop("yacc stack overflow");
      uVar6 = yyparse_lookahead_return_1();
      return uVar6;
    }
  } while( true );
switchD_104a5826_caseD_3:
  if (g_token_class[parser->lookahead->code] == '\0') {
    return 1;
  }
  parser->lookahead = (c1xx_token *)0x0;
  goto LAB_1042f848;
}

