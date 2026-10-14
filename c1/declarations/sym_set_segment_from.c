void __cdecl sym_set_segment_from(c1_symbol *sym,int value)

{
  if (value == 0) {
    if ((sym->flags23 & 2) != 0) {
      sym->flags23 = sym->flags23 & 0xfe;
    }
  }
  else if (((sym->flags23 & 1) == 0) || ((sym->flags23 & 2) != 0)) {
    sym_set_segment(sym,(void *)value);
    sym->flags23 = sym->flags23 | 2;
    return;
  }
  return;
}

