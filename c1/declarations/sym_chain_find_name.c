c1_symbol * __cdecl sym_chain_find_name(c1_symbol *chain,void *name)

{
  while( true ) {
    if (chain == (c1_symbol *)0x0) {
      return (c1_symbol *)0x0;
    }
    if ((chain->name != g_name_alignment_member) && (name == chain->name)) break;
    if (chain->next == (c1_sym_link *)0x0) {
      return (c1_symbol *)0x0;
    }
    chain = (c1_symbol *)&chain->next[-1].position;
  }
  return chain;
}

