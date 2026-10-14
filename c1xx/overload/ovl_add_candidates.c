void __thiscall ovl_add_candidates(c1_ovl_resolution *res,c1_symbol *sym,c1_symbol *overload_set)

{
  byte bVar1;
  c1_symbol *pcVar2;
  int iVar3;
  c1_lookup_entry *link;
  
  if (res->set == (c1_symbol *)0x0) {
    res->set = sym;
  }
  bVar1 = sym->kind & 0x1f;
  if ((bVar1 != 7) && (bVar1 != 6)) {
    if ((bVar1 == 0x1a) &&
       (iVar3 = sym_is_kind_6_7_through_alias(*(c1_symbol **)sym->type), (char)iVar3 != '\0')) {
      ovl_add_candidate_entry_fragment(res,&sym->kind,(int)overload_set);
      return;
    }
    bVar1 = sym->kind & 0x1f;
    if ((bVar1 != 8) &&
       ((bVar1 != 0x1a ||
        (iVar3 = sym_is_member_function_via_alias(*(c1_symbol **)sym->type), (char)iVar3 == '\0'))))
    {
      if ((sym->kind & 0x1f) == 0x1b) {
        link = *(c1_lookup_entry **)sym->type;
        do {
          pcVar2 = link->sym;
          bVar1 = pcVar2->kind & 0x1f;
          if ((((bVar1 == 7) || (bVar1 == 6)) ||
              ((bVar1 == 0x1a &&
               (iVar3 = sym_is_kind_6_7_through_alias(*(c1_symbol **)pcVar2->type),
               (char)iVar3 != '\0')))) ||
             ((bVar1 = pcVar2->kind & 0x1f, bVar1 == 8 ||
              ((bVar1 == 0x1a &&
               (iVar3 = sym_is_member_function_via_alias(*(c1_symbol **)pcVar2->type),
               (char)iVar3 != '\0')))))) {
            if ((((pcVar2->kind & 0x1f) != 0x1a) ||
                (*(char *)((int)&pcVar2->type->extra + 2) == '\0')) &&
               ((*(byte *)((int)&pcVar2->tail + 9) & 0xe0) == 0)) {
              ovl_add_candidate_entry(res,pcVar2,overload_set);
            }
          }
          else {
            ovl_add_overload_set_candidates(res,pcVar2,overload_set);
          }
          link = link->next;
        } while (link != (c1_lookup_entry *)0x0);
        return;
      }
      ovl_add_overload_set_candidates(res,sym,overload_set);
      return;
    }
  }
  pcVar2 = sym;
  if ((sym->kind & 0x1f) == 0x1a) {
    pcVar2 = *(c1_symbol **)sym->type;
  }
  if ((*(byte *)((int)&pcVar2->tail + 9) & 0xe0) == 0) {
    ovl_add_candidate_entry(res,sym,overload_set);
  }
  return;
}

