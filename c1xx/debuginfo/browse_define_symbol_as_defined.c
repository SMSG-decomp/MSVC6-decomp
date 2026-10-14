void __cdecl browse_define_symbol_as_defined(c1_symbol *sym)

{
  byte bVar1;
  
  if ((g_browse_file != (char *)0x0) &&
     (((g_block_depth == '\0' || (g_opt_FR_browse != 0)) &&
      (((g_class_def_stack[g_class_depth].cls)->flags3 & 1) == 0)))) {
    bVar1 = sym->flags2;
    sym->flags2 = bVar1 | 4;
    (*g_il_emitter->vtbl->define_symbol)(g_il_emitter,sym);
    if ((bVar1 >> 2 & 1) == 0) {
      sym->flags2 = sym->flags2 & 0xfb;
    }
  }
  return;
}

