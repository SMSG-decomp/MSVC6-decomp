c1_symbol * __cdecl expr_report_undeclared_identifier(void *name)

{
  c1_symbol *sym;
  c1_u8 local;
  
  if (g_current_scope->qualified != '\0') {
    return (c1_symbol *)0x0;
  }
  if (g_current_scope->reported == '\0') {
    diag_error(0x41,name);
    local = g_block_depth;
    if (g_ms_extensions != '\0') {
      local = '\0';
    }
    sym = sym_new_object(name,local);
    if ((g_browse_file != (char *)0x0) && ((g_symbol_scope_level == '\0' || (g_opt_FR_browse != 0)))
       ) {
      (*g_il_emitter->vtbl->define_symbol)(g_il_emitter,sym);
    }
    sym->flags3 = sym->flags3 | 4;
    return sym;
  }
  g_current_scope->reported = '\0';
  return (c1_symbol *)0x0;
}

