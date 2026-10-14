fe_pp_value * __cdecl pp_if_parse_primary(void)

{
  int iVar1;
  fe_pp_value *pfVar2;
  fe_pp_value *pfVar3;
  uchar *value;
  
  iVar1 = pp_if_accept_token(0x3c);
  if (iVar1 != 0) {
    pfVar3 = (fe_pp_value *)0x0;
    pfVar2 = pp_if_parse_primary();
    pfVar2 = pp_if_fold_operator(0x3c,pfVar2,pfVar3);
    return pfVar2;
  }
  iVar1 = pp_if_accept_token(0x59);
  if (iVar1 != 0) {
    pfVar3 = (fe_pp_value *)0x0;
    pfVar2 = pp_if_parse_primary();
    pfVar2 = pp_if_fold_operator(0x59,pfVar2,pfVar3);
    return pfVar2;
  }
  iVar1 = pp_if_accept_token(0x51);
  if (iVar1 != 0) {
    pfVar3 = (fe_pp_value *)0x0;
    pfVar2 = pp_if_parse_primary();
    pfVar2 = pp_if_fold_operator(0x86,pfVar2,pfVar3);
    return pfVar2;
  }
  iVar1 = pp_if_accept_token(0x46);
  if (iVar1 == 0) {
    iVar1 = pp_if_accept_token(0x76);
    if (iVar1 != 0) {
      g_pp_if_paren_depth = g_pp_if_paren_depth + 1;
      pfVar2 = pp_if_parse_conditional();
      iVar1 = pp_if_accept_token(0x7e);
      if (iVar1 != 0) {
        g_pp_if_paren_depth = g_pp_if_paren_depth + -1;
        return pfVar2;
      }
      diag_fatal(0xc,0x29);
    }
    iVar1 = pp_if_accept_token(0x65);
    value = g_arenas[5].cur;
    if (iVar1 != 0) {
      g_arenas[5].cur = g_arenas[5].cur + 0x10;
      if (g_arenas[5].end < g_arenas[5].cur) {
        arena_grow(g_arenas + 5);
      }
      *(undefined4 *)value = g_pp_if_constant._0_4_;
      *(uint *)(value + 4) = g_pp_if_constant.unk04;
      *(uint *)(value + 8) = g_pp_if_constant.value.lo;
      *(int *)(value + 0xc) = g_pp_if_constant.value.hi;
      return (fe_pp_value *)value;
    }
    diag_fatal_simple(0x11);
  }
  pfVar3 = (fe_pp_value *)0x0;
  pfVar2 = pp_if_parse_primary();
  pfVar2 = pp_if_fold_operator(0x5a,pfVar2,pfVar3);
  return pfVar2;
}

