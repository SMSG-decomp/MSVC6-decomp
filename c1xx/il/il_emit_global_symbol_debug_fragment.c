void __cdecl il_emit_global_symbol_debug_fragment(c1_symbol *sym,int *symref,char mode)

{
  c1_symbol *sym_00;
  
  if (g_opt_Zi != '\0') {
    il_emit_symbol_if_needed(symref);
    sym_00 = sym_lookup_pair_local_then_global(sym,(uint *)&stack0x00000058);
    sym_mark_referenced(sym_00);
    il_emit_global_symbol((int *)&sym_00->name);
    il_emit_symbol_with_mode(7,(int)symref,mode);
    sym->flags2 = sym->flags2 | 8;
  }
  return;
}

