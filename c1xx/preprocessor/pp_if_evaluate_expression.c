longlong __cdecl pp_if_evaluate_expression(void)

{
  longlong lVar1;
  void *pvVar2;
  int iVar3;
  bool bVar4;
  
  g_pp_if_paren_depth = 0;
  g_pp_if_lookahead = 0x88;
  pvVar2 = pp_if_parse_conditional();
  if (g_pp_if_lookahead == 0x7e) {
    iVar3 = g_pp_if_paren_depth + -1;
    bVar4 = g_pp_if_paren_depth == 0;
    g_pp_if_paren_depth = iVar3;
    if (bVar4) {
      diag_fatal(0xc,0x28);
    }
  }
  else if (g_pp_if_lookahead != 0x2d) {
    diag_warning(1,0x43,"#if/#elif");
  }
  if (g_pp_if_paren_depth < 1) {
    lVar1 = *(longlong *)((int)pvVar2 + 8);
    arena_reset_ptr(g_arenas + 7);
    return lVar1;
  }
  diag_fatal(0xc,0x29);
}

