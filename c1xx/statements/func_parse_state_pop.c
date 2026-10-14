void __fastcall func_parse_state_pop(c1_u8 **saved)

{
  func_parse_state_restore((c1_parse_state *)*saved);
  g_parse_context_depth = g_parse_context_depth + -1;
  if ((g_parse_context_depth == 0) && (g_current_scope->saved == (c1_decl_state *)0x0)) {
    arena_reset_ptr(g_arenas + 8);
    return;
  }
  return;
}

