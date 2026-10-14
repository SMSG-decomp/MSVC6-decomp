int parse_translation_unit(void)

{
  c1_yyparse_state *pcVar1;
  c1_yyparse_state *pcVar2;
  int iVar3;
  int iVar4;
  c1_yystype *pcVar5;
  c1_yystype *pcVar6;
  c1_yystype saved_yyval;
  
  pcVar1 = g_parser_state;
  pcVar5 = &g_yyval;
  pcVar6 = &saved_yyval;
  for (iVar3 = 6; iVar3 != 0; iVar3 = iVar3 + -1) {
    pcVar6->words[0] = (c1_u32)pcVar5->ptr;
    pcVar5 = (c1_yystype *)(&pcVar5->ptr + 1);
    pcVar6 = (c1_yystype *)&(pcVar6->string).length;
  }
  pcVar2 = __2_YAPAXI_Z(0x6818);
  if (pcVar2 == (c1_yyparse_state *)0x0) {
    g_parser_state = (c1_yyparse_state *)0x0;
  }
  else {
    g_parser_state = yyparse_state_new(pcVar2);
  }
  iVar3 = yyparse_c(g_parser_state);
  pcVar2 = g_parser_state;
  if (g_parser_state != (c1_yyparse_state *)0x0) {
    parse_end_nop();
    __3_YAXPAX_Z(pcVar2);
  }
  pcVar5 = &saved_yyval;
  pcVar6 = &g_yyval;
  g_parser_state = pcVar1;
  for (iVar4 = 6; iVar4 != 0; iVar4 = iVar4 + -1) {
    pcVar6->words[0] = (c1_u32)pcVar5->ptr;
    pcVar5 = (c1_yystype *)&(pcVar5->string).length;
    pcVar6 = (c1_yystype *)(&pcVar6->ptr + 1);
  }
  return iVar3;
}

