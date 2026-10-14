int __fastcall yyparse_cpp_error_recovery(c1_yy_parser *parser)

{
  short sVar1;
  uint *src;
  short *row;
  int iVar2;
  int iVar3;
  uint *dst;
  uint token_value [10];
  
  switch(parser->errflag) {
  case 0:
    sVar1 = 1;
    iVar2 = 0;
    row = &g_yy_corrections[0].state;
    do {
      if (g_yy_state <= sVar1) break;
      sVar1 = row[3];
      row = row + 3;
      iVar2 = iVar2 + 3;
    } while (sVar1 != -1000);
    if (g_yy_state == (&g_yy_corrections[0].state)[iVar2]) {
      iVar3 = (int)(&g_yy_corrections[0].terminal)[iVar2];
      if (iVar3 < 0) {
        parser->errflag = 1;
        iVar3 = -iVar3;
      }
      if (parser->errflag < 2) {
        parse_report_inserted_token(g_yy_lookahead,iVar3);
      }
      src = parse_make_inserted_token_value(token_value,iVar3);
      dst = (uint *)(g_yy_pv + 1);
      for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
        *dst = *src;
        src = src + 1;
        dst = dst + 1;
      }
      g_yy_state = (int)(&g_yy_corrections[0].new_state)[iVar2];
      return 0;
    }
    yyerror_cpp("syntax error");
    parser->error_count = parser->error_count + 1;
  case 1:
  case 2:
    parser->errflag = 3;
    for (; parser->states <= g_yy_ps; g_yy_ps = g_yy_ps + -1) {
      g_yy_n = g_yy_pact[*g_yy_ps] + 0x100;
      if (((-1 < g_yy_n) && (g_yy_n < 0xfdc)) && (g_yy_chk[g_yy_action[g_yy_n]] == 0x100)) {
        g_yy_state = (int)g_yy_action[g_yy_n];
        return 0;
      }
      g_yy_pv = g_yy_pv + -1;
      g_yy_n = (int)g_yy_pact[*g_yy_ps];
    }
    break;
  case 3:
    parse_error_resync_token();
    if ((g_yy_lookahead == (byte *)0x0) || (g_token_class[*g_yy_lookahead] != '\0')) {
      g_yy_lookahead = (byte *)0x0;
      return 2;
    }
  }
  return 1;
}

