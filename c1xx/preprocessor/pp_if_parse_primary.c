c1_pp_value * __cdecl pp_if_parse_primary(void)

{
  int iVar1;
  c1_pp_value *pcVar2;
  c1_pp_value *pcVar3;
  c1_u8 *value;
  
  iVar1 = pp_if_accept_token(0x3c);
  if (iVar1 != 0) {
    pcVar3 = (c1_pp_value *)0x0;
    pcVar2 = pp_if_parse_primary();
    pcVar2 = pp_if_fold_operator(0x3c,pcVar2,pcVar3);
    return pcVar2;
  }
  iVar1 = pp_if_accept_token(0x59);
  if (iVar1 != 0) {
    pcVar3 = (c1_pp_value *)0x0;
    pcVar2 = pp_if_parse_primary();
    pcVar2 = pp_if_fold_operator(0x59,pcVar2,pcVar3);
    return pcVar2;
  }
  iVar1 = pp_if_accept_token(0x51);
  if (iVar1 != 0) {
    pcVar3 = (c1_pp_value *)0x0;
    pcVar2 = pp_if_parse_primary();
    pcVar2 = pp_if_fold_operator(0x86,pcVar2,pcVar3);
    return pcVar2;
  }
  iVar1 = pp_if_accept_token(0x46);
  if (iVar1 == 0) {
    iVar1 = pp_if_accept_token(0x76);
    if (iVar1 != 0) {
      g_pp_if_paren_depth = g_pp_if_paren_depth + 1;
      pcVar2 = pp_if_parse_conditional();
      iVar1 = pp_if_accept_token(0x7e);
      if (iVar1 != 0) {
        g_pp_if_paren_depth = g_pp_if_paren_depth + -1;
        return pcVar2;
      }
      diag_fatal(0xc,0x29);
    }
    iVar1 = pp_if_accept_token(0x65);
    value = g_arenas[7].cur;
    if (iVar1 != 0) {
      g_arenas[7].cur = g_arenas[7].cur + 0x10;
      if (g_arenas[7].end < g_arenas[7].cur) {
        arena_grow(g_arenas + 7);
      }
      *(undefined4 *)value = g_pp_if_constant._0_4_;
      *(c1_u32 *)(value + 4) = g_pp_if_constant.unk04;
      *(c1_u32 *)(value + 8) = g_pp_if_constant.value.lo;
      *(int *)(value + 0xc) = g_pp_if_constant.value.hi;
      return (c1_pp_value *)value;
    }
    diag_fatal_simple(0x11);
  }
  pcVar3 = (c1_pp_value *)0x0;
  pcVar2 = pp_if_parse_primary();
  pcVar2 = pp_if_fold_operator(0x5a,pcVar2,pcVar3);
  return pcVar2;
}

