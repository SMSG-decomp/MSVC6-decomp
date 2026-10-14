c1_symbol * __cdecl sym_hiding_partner_link(c1_symbol *sym)

{
  return (c1_symbol *)((int)&sym->next[-1].tail + 4);
}

