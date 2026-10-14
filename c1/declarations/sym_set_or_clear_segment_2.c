void __thiscall sym_set_or_clear_segment_2(c1_symbol *sym,void *value)

{
  if (value == (void *)0x0) {
    sym->flags23 = sym->flags23 & 0xfe;
    return;
  }
  sym_set_segment(sym,value);
  return;
}

