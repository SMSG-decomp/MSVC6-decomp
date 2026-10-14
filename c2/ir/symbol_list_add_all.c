c2_symbol_cell * __fastcall symbol_list_add_all(c2_symbol_cell *list,c2_symbol_cell *from,int arena)

{
  for (; from != (c2_symbol_cell *)0x0; from = from->next) {
    list = symbol_list_add_unique(list,from->sym,arena);
  }
  return list;
}

