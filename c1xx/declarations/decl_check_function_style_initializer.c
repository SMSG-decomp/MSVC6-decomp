char __cdecl decl_check_function_style_initializer(c1_symbol *sym)

{
  c1_u8 cVar1;
  c1xx_token *pcVar2;
  byte *token;
  
  pcVar2 = parse_lookahead_token();
  if (pcVar2 == (c1xx_token *)0x0) {
    token = yylex_cpp();
    yyparse_set_lookahead(token);
  }
  pcVar2 = parse_lookahead_token();
  cVar1 = g_token_class[pcVar2->code];
  if (cVar1 != '$') {
    if (cVar1 == '6') goto LAB_1046890f;
    if (cVar1 != 'u') {
      return '\0';
    }
  }
  pcVar2 = parse_lookahead_token();
  (*g_token_source->stream->vtbl->unget)(g_token_source->stream,(char *)pcVar2);
  yyparse_set_lookahead(g_token_semicolon);
  g_compile_flags_c8 = g_compile_flags_c8 | 0x40;
LAB_1046890f:
  diag_error(0x1c0,sym);
  return '\x01';
}

