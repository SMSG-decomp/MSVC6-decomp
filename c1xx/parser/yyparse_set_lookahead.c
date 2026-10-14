void __cdecl yyparse_set_lookahead(byte *token)

{
  parser_set_lookahead(g_yy_parser,token);
  return;
}

