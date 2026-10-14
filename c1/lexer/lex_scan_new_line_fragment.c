c1_token * __cdecl lex_scan_new_line_fragment(c1_token *token)

{
  int iVar1;
  uint *puVar2;
  c1_yystype *pcVar3;
  
  if (token != (c1_token *)0x0) {
    token->code = 0xf2;
    puVar2 = &g_yylval;
    pcVar3 = &token->value;
    for (iVar1 = 6; iVar1 != 0; iVar1 = iVar1 + -1) {
      pcVar3->words[0] = *puVar2;
      puVar2 = puVar2 + 1;
      pcVar3 = (c1_yystype *)((int)pcVar3 + 4);
    }
    return token;
  }
  return (c1_token *)0x0;
}

