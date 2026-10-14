void __cdecl sym_set_segment_checked(c1_symbol *sym,void *value)

{
  byte bVar1;
  void *pvVar2;
  
  if ((sym->flags23 & 1) == 0) {
    if (value == (void *)0x0) {
      bVar1 = sym->flags23 & 0xfe;
      sym->flags23 = bVar1;
      sym->flags23 = bVar1 | 2;
      return;
    }
    sym_set_segment(sym,value);
    sym->flags23 = sym->flags23 | 2;
  }
  else {
    pvVar2 = sym_segment_record(sym);
    if (value != pvVar2) {
      diag_error(0xc1,sym);
      return;
    }
  }
  return;
}

