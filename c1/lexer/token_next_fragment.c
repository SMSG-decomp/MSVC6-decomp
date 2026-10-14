c1_token * __cdecl token_next_fragment(c1_token *token)

{
  bool bVar1;
  
  if ((token->code == '\x02') && (g_pch_directive_mode != 0)) {
    bVar1 = pp_include_top_is_pseudo_file();
    if (bVar1) {
      pp_include_pop_file();
    }
  }
  return token;
}

