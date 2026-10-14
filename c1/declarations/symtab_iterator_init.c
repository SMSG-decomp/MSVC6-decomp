void __cdecl symtab_iterator_init(fe_symtab_iter *it,fe_symtab *tab)

{
  it->tab = tab;
  it->next_bucket = 0;
  it->entry = (fe_symtab_entry *)0x0;
  return;
}

