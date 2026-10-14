c1_node * __cdecl expr_reference_identifier(c1_symbol *sym)

{
  c1_node *pcVar1;
  
  if ((g_browse_file != (char *)0x0) && ((g_symbol_scope_level == '\0' || (g_opt_FR_browse != 0))))
  {
    (*g_il_emitter->vtbl->reference_symbol)(sym);
  }
  pcVar1 = expr_reference_named_entity(sym);
  return pcVar1;
}

