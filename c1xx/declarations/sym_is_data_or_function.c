c1_node * __cdecl sym_is_data_or_function(c1_symbol *sym)

{
  byte bVar1;
  c1_node *pcVar2;
  
  bVar1 = sym->kind & 0x1f;
  if ((((((bVar1 != 0x10) && (bVar1 != 7)) && (bVar1 != 6)) &&
       (((bVar1 != 0x11 && (bVar1 != 8)) && (bVar1 != 0x1b)))) &&
      ((bVar1 != 0x1a ||
       (((bVar1 = **(byte **)sym->type & 0x1f, bVar1 != 0x10 && (bVar1 != 7)) &&
        ((bVar1 != 6 && (((bVar1 != 0x11 && (bVar1 != 8)) && (bVar1 != 0x1b)))))))))) &&
     ((g_browse_file != (char *)0x0 && ((g_symbol_scope_level == '\0' || (g_opt_FR_browse != 0))))))
  {
    (*g_il_emitter->vtbl->reference_symbol)((int)sym);
  }
  pcVar2 = expr_reference_named_entity(sym,0);
  return pcVar2;
}

