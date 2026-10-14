c1xx_token * __cdecl parse_skip_tokens_to_one_of(c1xx_token *token,...)

{
  c1_u8 cVar1;
  c1xx_token *pcVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int local_f0 [60];
  char *code_arg;
  
  iVar4 = 0;
  iVar6 = 0;
LAB_104682eb:
  yyparse_set_lookahead(&token->code);
  if ((iVar4 == 0) && (code_arg = (char *)register0x00000010, iVar6 == 0)) {
    do {
      cVar1 = code_arg[8];
      pcVar2 = parse_lookahead_token();
      if (cVar1 == pcVar2->code) {
        pcVar2 = parse_lookahead_token();
        return pcVar2;
      }
      code_arg = code_arg + 4;
    } while (cVar1 != '\x01');
  }
  pcVar2 = parse_lookahead_token();
  switch(pcVar2->code) {
  case '\0':
    return g_token_newline;
  case '\x06':
    pcVar2 = parse_lookahead_token();
    if ((*(uint *)((int)pcVar2->value + 8) & 0x4000000) != 0) {
      pbVar3 = token_next((c1_token_reader *)&g_token_position);
      yyparse_set_lookahead(pbVar3);
      pcVar2 = parse_lookahead_token();
      if (pcVar2->code == 'D') {
        iVar5 = 0;
        local_f0[0] = iVar6;
        do {
          pbVar3 = token_next((c1_token_reader *)&g_token_position);
          yyparse_set_lookahead(pbVar3);
          pcVar2 = parse_lookahead_token();
          switch(pcVar2->code) {
          case '\0':
          case 'm':
            goto switchD_104683a6_caseD_0;
          case '\x06':
            pcVar2 = parse_lookahead_token();
            if ((*(uint *)((int)pcVar2->value + 8) & 0x4000000) != 0) {
              pbVar3 = token_next((c1_token_reader *)&g_token_position);
              yyparse_set_lookahead(pbVar3);
              pcVar2 = parse_lookahead_token();
              if (pcVar2->code == 'D') {
                iVar5 = iVar5 + 1;
                if (iVar5 == 0x3c) {
                  diag_fatal_simple(0x23);
                }
                local_f0[iVar5] = iVar6;
              }
              else {
                pcVar2 = parse_lookahead_token();
                lex_unget_token(pcVar2);
              }
            }
            break;
          case '>':
            if (iVar6 == local_f0[iVar5]) {
              iVar5 = iVar5 + -1;
            }
            if (iVar5 < 0) goto switchD_10468337_caseD_1;
            break;
          case 'v':
            iVar6 = iVar6 + 1;
            break;
          case '~':
            iVar6 = iVar6 + -1;
          }
        } while( true );
      }
switchD_104683a6_caseD_0:
      pcVar2 = parse_lookahead_token();
      lex_unget_token(pcVar2);
      token = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
      goto LAB_104682eb;
    }
    break;
  case '\a':
    goto switchD_10468337_caseD_7;
  case 'm':
    diag_fatal_simple(4);
  case 'u':
    iVar4 = iVar4 + 1;
    token = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
    goto LAB_104682eb;
  case 'v':
    iVar6 = iVar6 + 1;
    token = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
    goto LAB_104682eb;
  case '{':
    iVar4 = iVar4 + -1;
    token = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
    goto LAB_104682eb;
  case '~':
    goto switchD_10468337_caseD_7e;
  case '\x7f':
    arena_reset_ptr(g_arenas + 5);
switchD_10468337_caseD_7:
    g_string_literal_cur = &g_string_literal_buffer;
  }
switchD_10468337_caseD_1:
  token = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
  goto LAB_104682eb;
switchD_10468337_caseD_7e:
  iVar6 = iVar6 + -1;
  token = (c1xx_token *)token_next((c1_token_reader *)&g_token_position);
  goto LAB_104682eb;
}

