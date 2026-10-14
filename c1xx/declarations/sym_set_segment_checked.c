void __cdecl sym_set_segment_checked(c1_symbol *sym,void *segment)

{
  byte bVar1;
  c1_symbol *pcVar2;
  
  if ((sym->flags23 & 1) == 0) {
    if (segment == (void *)0x0) {
      bVar1 = sym->flags23 & 0xfe;
      sym->flags23 = bVar1;
      sym->flags23 = bVar1 | 2;
      return;
    }
    sym_set_segment(sym,segment);
    sym->flags23 = sym->flags23 | 2;
  }
  else {
    pcVar2 = sym_segment_record(sym);
    if (segment != pcVar2) {
      diag_error(0xc1,sym);
      return;
    }
  }
  return;
}

