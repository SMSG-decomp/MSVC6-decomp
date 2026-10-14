c2_symbol_cell * __fastcall symbol_list_add_unique(c2_symbol_cell *list,c2_symbol *s,int arena)

{
  c2_symbol_cell *pcVar1;
  
  if ((s->cls != '\n') && (pcVar1 = list, s->cls != '\v')) {
    while( true ) {
      if (pcVar1 == (c2_symbol_cell *)0x0) {
        pcVar1 = arena_alloc(arena,8);
        pcVar1->sym = s;
        pcVar1->next = list;
        return pcVar1;
      }
      if (pcVar1->sym == s) break;
      pcVar1 = pcVar1->next;
    }
  }
  return list;
}

