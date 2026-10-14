c1_u8 __cdecl access_least_member_through_path(c1_symbol *entity,c1_keyed_cell *cell,c1_u8 *least)

{
  fe_name **ppfVar1;
  c1_symbol *pcVar2;
  bool bVar3;
  byte bVar4;
  c1_symbol *pcVar5;
  c1_sym_link *link;
  c1_sym_link *next_link_2;
  c1_sym_link *next_link;
  
  pcVar2 = cell->sym;
  ppfVar1 = &entity->name;
  link = (c1_sym_link *)0x0;
  bVar3 = true;
  next_link = (c1_sym_link *)0x0;
  if (ppfVar1 != (fe_name **)0x0) {
    bVar4 = entity->kind & 0x1f;
    next_link_2 = (c1_sym_link *)ppfVar1;
    if ((((bVar4 != 7) && (bVar4 != 8)) && (bVar4 != 6)) && ((entity->kind & 0x1f) != 0x1a)) {
      next_link_2 = (c1_sym_link *)entity->type;
    }
    next_link = next_link_2;
    if (next_link_2 != (c1_sym_link *)0x0) {
      bVar4 = entity->kind & 0x1f;
      link = next_link_2;
      if (((bVar4 == 7) || (bVar4 == 8)) || ((bVar4 == 6 || ((entity->kind & 0x1f) == 0x1a)))) {
        next_link = (c1_sym_link *)0x0;
      }
      else {
        next_link = next_link_2->next;
      }
    }
  }
  while( true ) {
    pcVar5 = (c1_symbol *)&link[-1].position;
    if ((link[-1].position & 0x1f) == 0x1a) {
      pcVar5 = ((link->type).alias)->target;
    }
    cell->sym = pcVar5;
    bVar4 = access_member_through_path(cell);
    if (bVar4 == 1) break;
    if (bVar3) {
      *least = bVar4;
      bVar3 = false;
    }
    else if (bVar4 < *least) {
      *least = bVar4;
    }
    if ((ppfVar1 == (fe_name **)0x0) || (next_link == (c1_sym_link *)0x0)) {
      cell->sym = pcVar2;
      return '\x01';
    }
    bVar4 = entity->kind & 0x1f;
    link = next_link;
    if ((((bVar4 == 7) || (bVar4 == 8)) || (bVar4 == 6)) || ((entity->kind & 0x1f) == 0x1a)) {
      next_link = (c1_sym_link *)0x0;
    }
    else {
      next_link = next_link->next;
    }
  }
  cell->sym = pcVar2;
  return '\0';
}

