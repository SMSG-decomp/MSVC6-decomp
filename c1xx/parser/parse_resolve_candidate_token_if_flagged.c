char * __cdecl parse_resolve_candidate_token_if_flagged(char *token)

{
  if (*token == -0x5c) {
    if ((g_compile_flags_c4 & 0x40000000) != 0) {
      parse_resolve_candidate_token(token);
      return token;
    }
    token_set_kind_24(token);
  }
  return (char *)0x0;
}

