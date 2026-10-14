void parse_skip_to_closing_brace(void)

{
  c1_token *token;
  int iVar1;
  
  iVar1 = 0;
switchD_10631524_caseD_1:
  token = token_next(&g_token_position);
  switch(token->code) {
  case '\0':
    goto switchD_10631524_caseD_0;
  default:
    goto switchD_10631524_caseD_1;
  case 'm':
    diag_fatal_simple(4);
  case 'u':
    iVar1 = iVar1 + 1;
    goto switchD_10631524_caseD_1;
  case '{':
    goto switchD_10631524_caseD_7b;
  case '\x7f':
    arena_reset_ptr(g_arenas + 3);
  }
  g_string_literal_cur = &g_string_literal_buffer;
  goto switchD_10631524_caseD_1;
switchD_10631524_caseD_7b:
  if (iVar1 == 0) {
    (*g_token_source->stream->vtbl->unget)(g_token_source->stream,token);
    return;
  }
  iVar1 = iVar1 + -1;
  goto switchD_10631524_caseD_1;
switchD_10631524_caseD_0:
  return;
}

