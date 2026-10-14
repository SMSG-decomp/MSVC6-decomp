uint parse_run_lookahead_classifier(void)

{
  int *piVar1;
  void *parser;
  uint uVar2;
  int iVar3;
  uint *dst;
  uint *src;
  uint *src_2;
  uint *dst_2;
  uint saved_yyval [10];
  int *saved;
  
  saved = g_lookahead_parser;
  dst = (uint *)&g_yyval;
  src_2 = saved_yyval;
  for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *src_2 = *dst;
    dst = dst + 1;
    src_2 = src_2 + 1;
  }
  parser = __2_YAPAXI_Z(0x18b8);
  if (parser == (void *)0x0) {
    g_lookahead_parser = (int *)0x0;
  }
  else {
    g_lookahead_parser = lookahead_parser_construct(parser);
  }
  uVar2 = yyparse_lookahead((c1_yy_lookahead_parser *)g_lookahead_parser);
  piVar1 = g_lookahead_parser;
  if (g_lookahead_parser != (int *)0x0) {
    lookahead_parser_destruct();
    __3_YAXPAX_Z(piVar1);
  }
  src = saved_yyval;
  dst_2 = (uint *)&g_yyval;
  g_lookahead_parser = saved;
  for (iVar3 = 10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *dst_2 = *src;
    src = src + 1;
    dst_2 = dst_2 + 1;
  }
  return uVar2;
}

