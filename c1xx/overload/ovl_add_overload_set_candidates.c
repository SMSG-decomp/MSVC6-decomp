void __thiscall
ovl_add_overload_set_candidates(c1_ovl_resolution *ctx,c1_symbol *sym,c1_symbol *overload_set)

{
  fe_name **ppfVar1;
  c1_symbol_type_word *pcVar2;
  c1_sym_link *pcVar3;
  byte bVar4;
  c1_symbol *pcVar5;
  c1_sym_link *link;
  c1_sym_link *next_link;
  
  ppfVar1 = &sym->name;
  link = (c1_sym_link *)0x0;
  if ((((ppfVar1 != (fe_name **)0x0) &&
       (bVar4 = sym->kind & 0x1f, link = (c1_sym_link *)ppfVar1, bVar4 != 7)) && (bVar4 != 8)) &&
     ((bVar4 != 6 && ((sym->kind & 0x1f) != 0x1a)))) {
    link = (c1_sym_link *)sym->type;
  }
LAB_10413a18:
  if ((ppfVar1 == (fe_name **)0x0) || (link == (c1_sym_link *)0x0)) {
    return;
  }
  bVar4 = sym->kind & 0x1f;
  if ((((bVar4 == 7) || (bVar4 == 8)) || (bVar4 == 6)) || ((sym->kind & 0x1f) == 0x1a)) {
    next_link = (c1_sym_link *)0x0;
  }
  else {
    next_link = link->next;
  }
  pcVar3 = link + -1;
  pcVar5 = (c1_symbol *)&pcVar3->position;
  if ((link[-1].position & 0x1f) == 0x1a) goto LAB_104a64d0;
  goto LAB_10413a65;
LAB_104a64d0:
  pcVar2 = &link->type;
  link = next_link;
  if (pcVar2->alias->hidden == '\0') {
    pcVar5 = pcVar2->alias->target;
LAB_10413a65:
    link = next_link;
    if ((*(byte *)((int)&pcVar5->tail + 9) & 0xe0) == 0) {
      ovl_add_candidate_entry(ctx,(c1_symbol *)&pcVar3->position,overload_set);
      link = next_link;
    }
  }
  goto LAB_10413a18;
}

