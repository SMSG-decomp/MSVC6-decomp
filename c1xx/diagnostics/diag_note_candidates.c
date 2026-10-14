void __cdecl diag_note_candidates(c1_symbol *sym,char *context)

{
  fe_name **ppfVar1;
  char cVar2;
  c1_type *pcVar3;
  byte bVar4;
  c1_symbol *candidate;
  c1_sym_link *link;
  c1_sym_link *next_link;
  c1_lookup_entry *cell;
  
  bVar4 = sym->kind & 0x1f;
  if (((bVar4 != 7) && (bVar4 != 8)) && (bVar4 != 6)) {
    if (bVar4 != 0x1a) {
      if (bVar4 == 0x1b) {
        cell = *(c1_lookup_entry **)sym->type;
        do {
          diag_note_candidates(cell->sym,context);
          cell = cell->next;
        } while (cell != (c1_lookup_entry *)0x0);
        return;
      }
      ppfVar1 = &sym->name;
      pcVar3 = (c1_type *)(c1_sym_link *)0x0;
      if (((ppfVar1 != (fe_name **)0x0) &&
          (bVar4 = sym->kind & 0x1f, pcVar3 = (c1_type *)ppfVar1, bVar4 != 7)) &&
         ((bVar4 != 8 && ((bVar4 != 6 && ((sym->kind & 0x1f) != 0x1a)))))) {
        pcVar3 = sym->type;
      }
LAB_1048912f:
      link = (c1_sym_link *)pcVar3;
      if (ppfVar1 == (fe_name **)0x0) {
        return;
      }
      if (link == (c1_sym_link *)0x0) {
        return;
      }
      bVar4 = sym->kind & 0x1f;
      if ((((bVar4 == 7) || (bVar4 == 8)) || (bVar4 == 6)) || ((sym->kind & 0x1f) == 0x1a)) {
        next_link = (c1_sym_link *)0x0;
      }
      else {
        next_link = link->next;
      }
      candidate = (c1_symbol *)&link[-1].position;
      bVar4 = (byte)link[-1].position & 0x1f;
      if (((bVar4 != 7) && (bVar4 != 8)) && (bVar4 != 6)) goto code_r0x10489172;
      cVar2 = *context;
      goto joined_r0x104891a5;
    }
    if (*(char *)((int)&sym->type->extra + 2) != '\0') {
      return;
    }
    sym = *(c1_symbol **)sym->type;
  }
  if (*context == '\0') {
    diag_note(0x189d,sym);
    return;
  }
  diag_note(0x189c,sym);
  *context = '\0';
  return;
code_r0x10489172:
  pcVar3 = (c1_type *)next_link;
  if ((bVar4 == 0x1a) && (pcVar3 = (c1_type *)next_link, ((link->type).alias)->hidden == '\0')) {
    candidate = ((link->type).alias)->target;
    cVar2 = *context;
joined_r0x104891a5:
    if (cVar2 == '\0') {
      diag_note(0x189d,candidate);
      pcVar3 = (c1_type *)next_link;
    }
    else {
      diag_note(0x189c,candidate);
      *context = '\0';
      pcVar3 = (c1_type *)next_link;
    }
  }
  goto LAB_1048912f;
}

