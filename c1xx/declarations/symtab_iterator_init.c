void __cdecl symtab_iterator_init(c1_symtab_iter *it,c1_symtab *tab)

{
  it->tab = tab;
  it->next_bucket = 0;
  it->entry = (c1_symtab_entry *)0x0;
  return;
}

