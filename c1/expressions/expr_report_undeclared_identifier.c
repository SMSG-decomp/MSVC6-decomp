c1_symbol * __cdecl expr_report_undeclared_identifier(int name)

{
  c1_symbol *sym;
  c1_u8 level;
  
  if (g_current_scope->unk209 == '\0') {
    diag_error(0x41,name);
    level = g_block_depth;
    if (g_ms_extensions != '\0') {
      level = '\0';
    }
    sym = sym_new_object((void *)name,level);
    if ((g_browse_file != (char *)0x0) && ((g_symbol_scope_level == '\0' || (g_opt_FR_browse != 0)))
       ) {
      (*g_il_emitter->vtbl->define_symbol)(g_il_emitter,sym);
    }
    sym->flags2 = sym->flags2 | 1;
    return sym;
  }
  return (c1_symbol *)0x0;
}

