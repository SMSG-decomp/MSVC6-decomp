longlong __cdecl pp_if_evaluate_expression(void)

{
  fe_pp_value *pfVar1;
  int iVar2;
  bool bVar3;
  longlong lVar4;
  
  g_pp_if_paren_depth = 0;
  g_pp_if_lookahead = 0x88;
  pfVar1 = pp_if_parse_conditional();
  if (g_pp_if_lookahead == 0x7e) {
    iVar2 = g_pp_if_paren_depth + -1;
    bVar3 = g_pp_if_paren_depth == 0;
    g_pp_if_paren_depth = iVar2;
    if (bVar3) {
      diag_fatal(0xc,0x28);
    }
  }
  else if (g_pp_if_lookahead != 0x2d) {
    diag_warning(1,0x43,"#if/#elif");
  }
  if (g_pp_if_paren_depth < 1) {
    arena_reset_ptr(g_arenas + 5);
    lVar4._0_4_ = (pfVar1->value).lo;
    lVar4._4_4_ = (pfVar1->value).hi;
    return lVar4;
  }
  diag_fatal(0xc,0x29);
}

