int __cdecl asm_is_statement_end(c1_u8 token)

{
  c1_token *pcVar1;
  int iVar2;
  
  switch(token) {
  case '\0':
    diag_fatal_simple(4);
  default:
    pcVar1 = token_next(&g_token_position);
    iVar2 = asm_is_statement_end(pcVar1->code);
    return iVar2;
  case '*':
    goto switchD_10623049_caseD_2a;
  case '{':
    g_asm_brace_depth = g_asm_brace_depth + -1;
    if (g_asm_brace_depth == 0) {
      return 1;
    }
    if (g_asm_brace_depth < 0) {
      (*g_token_source->stream->vtbl->unget)(g_token_source->stream,g_token_rbrace);
      g_asm_brace_depth = 0;
      return 1;
    }
switchD_10623049_caseD_2a:
    return 0;
  case 0xf2:
    return (uint)(g_asm_brace_depth == 0);
  }
}

