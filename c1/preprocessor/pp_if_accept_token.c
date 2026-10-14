int __cdecl pp_if_accept_token(byte token)

{
  byte bVar1;
  c1_token *pcVar2;
  
  if (g_pp_if_lookahead != 0x2d) {
    if (g_pp_if_lookahead == 0x88) {
      pcVar2 = token_next(&g_token_position);
      bVar1 = pcVar2->code;
      if ((&g_token_class)[bVar1] == '\x06') {
        g_pp_if_constant.value.lo = pp_if_parse_defined((pcVar2->value).words[0]);
        g_pp_if_constant.value.hi = (int)g_pp_if_constant.value.lo >> 0x1f;
        g_pp_if_constant.type = 0x13;
        if (token == 0x65) {
          return 1;
        }
      }
      else {
        if ((&g_token_class)[bVar1] != 'e') {
          if (token == bVar1) {
            return 1;
          }
          g_pp_if_lookahead = bVar1;
          return 0;
        }
        g_pp_if_constant.type = ((pcVar2->value).constant.type)->code;
        if ((g_pp_if_constant.type & 0x10) == 0) {
          diag_fatal_simple(0x11);
        }
        g_pp_if_constant.value.lo = (pcVar2->value).words[2];
        g_pp_if_constant.value.hi = (pcVar2->value).constant.hi;
        if (token == 0x65) {
          return 1;
        }
      }
      g_pp_if_lookahead = 0x65;
    }
    else if (token == g_pp_if_lookahead) {
      g_pp_if_lookahead = 0x88;
      return 1;
    }
  }
  return 0;
}

