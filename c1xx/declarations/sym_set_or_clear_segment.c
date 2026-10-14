void __cdecl sym_set_or_clear_segment(c1_symbol *sym,int value)

{
  if (value == 0) {
    sym->flags23 = sym->flags23 & 0xfe;
    return;
  }
  sym_set_segment(sym,(void *)value);
  return;
}

