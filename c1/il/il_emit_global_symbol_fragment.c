void __cdecl il_emit_global_symbol_fragment(c1_symbol *sym,char from_pch)

{
  if (from_pch == '\0') {
    il_emit_symbol(0xb,sym);
    sym->flags1 = sym->flags1 | 2;
    return;
  }
  sym->flags1 = sym->flags1 | 2;
  return;
}

