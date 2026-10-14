c1_symbol * __cdecl sym_chain_find_name(c1_symbol *sym,void *name)

{
  while( true ) {
    if (sym == (c1_symbol *)0x0) {
      return (c1_symbol *)0x0;
    }
    if ((sym->name != g_name_alignment_member) && (name == sym->name)) break;
    if (sym->next == (c1_symbol *)0x0) {
      return (c1_symbol *)0x0;
    }
    sym = (c1_symbol *)((int)&sym->next[-1].tail + 4);
  }
  return sym;
}

