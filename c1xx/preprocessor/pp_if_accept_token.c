int __cdecl pp_if_accept_token(byte token)

{
  byte bVar1;
  byte *pbVar2;
  
  if (g_pp_if_lookahead != 0x2d) {
    if (g_pp_if_lookahead == 0x88) {
      pbVar2 = token_next((c1_token_reader *)&g_token_position);
      bVar1 = *pbVar2;
      if (g_token_class[bVar1] == '\x06') {
        g_pp_if_constant.value.lo = pp_if_parse_defined(*(int *)(pbVar2 + 8));
        g_pp_if_constant.value.hi = (int)g_pp_if_constant.value.lo >> 0x1f;
        g_pp_if_constant.type = 0x13;
        if (token == 0x65) {
          return 1;
        }
      }
      else {
        if (g_token_class[bVar1] != 'e') {
          if (token == bVar1) {
            return 1;
          }
          g_pp_if_lookahead = bVar1;
          return 0;
        }
        g_pp_if_constant.type = **(ushort **)(pbVar2 + 8);
        if ((g_pp_if_constant.type & 0x10) == 0) {
          diag_fatal_simple(0x11);
        }
        g_pp_if_constant.value.lo = *(c1_u32 *)(pbVar2 + 0x10);
        g_pp_if_constant.value.hi = *(int *)(pbVar2 + 0x14);
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

