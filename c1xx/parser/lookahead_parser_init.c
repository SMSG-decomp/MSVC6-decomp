void __fastcall lookahead_parser_init(c1_yy_lookahead_parser *parser)

{
  parser->lookahead = (c1xx_token *)0x0;
  parser->state = 0;
  parser->errflag = 0;
  parser->error_count = 0;
  parser->pv = (c1_yy_value *)(parser[-1].states + 0x90);
  parser->ps = (short *)((int)parser->values + 0x176e);
  return;
}

