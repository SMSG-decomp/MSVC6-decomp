uint __fastcall parse_action_tail_e1(int errflag,int *parser)

{
  uint uVar1;
  
  parser[2] = errflag + -1;
  uVar1 = yyparse_lookahead_push((c1_yy_lookahead_parser *)parser);
  return uVar1;
}

