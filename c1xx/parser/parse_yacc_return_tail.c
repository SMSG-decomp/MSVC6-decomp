int __cdecl parse_yacc_return_tail(byte *saved_lookahead,int saved_rule)

{
  g_yy_rule = saved_rule;
  g_yy_lookahead = saved_lookahead;
  return g_yy_result;
}

