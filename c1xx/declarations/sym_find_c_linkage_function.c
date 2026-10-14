c1_symbol * __cdecl sym_find_c_linkage_function(c1_symbol *sym)

{
  fe_name **ppfVar1;
  c1_type *pcVar2;
  byte bVar3;
  c1_symbol *entry_sym;
  c1_sym_link *link;
  c1_sym_link *next_link;
  
  ppfVar1 = &sym->name;
  pcVar2 = (c1_type *)(c1_sym_link *)0x0;
  if ((((ppfVar1 != (fe_name **)0x0) &&
       (bVar3 = sym->kind & 0x1f, pcVar2 = (c1_type *)ppfVar1, bVar3 != 7)) && (bVar3 != 8)) &&
     ((bVar3 != 6 && ((sym->kind & 0x1f) != 0x1a)))) {
    pcVar2 = sym->type;
  }
  do {
    link = (c1_sym_link *)pcVar2;
    if ((ppfVar1 == (fe_name **)0x0) || (link == (c1_sym_link *)0x0)) {
      return (c1_symbol *)0x0;
    }
    bVar3 = sym->kind & 0x1f;
    if ((((bVar3 == 7) || (bVar3 == 8)) || (bVar3 == 6)) || ((sym->kind & 0x1f) == 0x1a)) {
      next_link = (c1_sym_link *)0x0;
    }
    else {
      next_link = link->next;
    }
    entry_sym = (c1_symbol *)&link[-1].position;
    if ((link[-1].position & 0x1f) == 0x1a) {
      entry_sym = ((link->type).alias)->target;
    }
    pcVar2 = (c1_type *)next_link;
  } while ((entry_sym->flags1 & 2) == 0);
  if ((link[-1].position & 0x1f) != 0x1a) {
    return (c1_symbol *)&link[-1].position;
  }
  return ((link->type).alias)->target;
}

