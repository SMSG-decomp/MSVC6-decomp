uint __fastcall yyparse_lookahead_case_1(c1_yy_value *value_top,c1_yy_lookahead_parser *parser)

{
  uint uVar1;
  c1xx_token *pcVar2;
  
  if (g_paren_depth == 0) {
    if (((value_top->spec).spec[0] & 2) == 0) {
      if (parser->lookahead == (c1xx_token *)0x0) {
        pcVar2 = (c1xx_token *)yylex_cpp();
        parser->lookahead = pcVar2;
      }
      switch(parser->lookahead->code) {
      case 'u':
      case '{':
      case '\x7f':
      case 0xa6:
        return 1;
      default:
        return 0;
      }
    }
    return 0;
  }
  uVar1 = value_top->words[0];
  if (((uVar1 & 1) != 0) && ((uVar1 & 8) == 0)) {
    return 0;
  }
  if ((uVar1 & 4) == 0) {
    if (parser->lookahead == (c1xx_token *)0x0) {
      pcVar2 = (c1xx_token *)yylex_cpp();
      parser->lookahead = pcVar2;
    }
    return (uint)(g_token_class[parser->lookahead->code] == '~');
  }
  return 0;
}

