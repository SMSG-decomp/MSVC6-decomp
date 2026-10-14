uint __fastcall parse_action_tail_e3(int *parser)

{
  uint uVar1;
  
  g_yyval.words[0] = 5;
  uVar1 = yyparse_lookahead_push((c1_yy_lookahead_parser *)parser);
  return uVar1;
}

