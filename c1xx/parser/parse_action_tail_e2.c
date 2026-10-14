uint __fastcall parse_action_tail_e2(uint *value_top,int *parser)

{
  uint uVar1;
  
  g_yyval.words[0] = *value_top;
  uVar1 = yyparse_lookahead_push((c1_yy_lookahead_parser *)parser);
  return uVar1;
}

