void __cdecl pch_relocate_symbol_chain(c1_symbol *sym)

{
  c1_sym_link *cell;
  int *cell_00;
  char cVar1;
  c1_sym_link *link;
  c1_scope_symbol_list *link_members;
  c1_scope_symbol_list *members;
  
  if (sym == (c1_symbol *)0x0) {
    return;
  }
  if ((sym->kind & 0x1f) == 4) {
    pch_relocate_slot_once(&g_pch_image,(uint)&sym->name);
    pch_relocate_symbol(&sym->kind);
    cVar1 = pch_relocate_slot_once(&g_pch_image,(uint)&sym->next);
    if (cVar1 != '\0') {
      cell = sym->next;
      if ((cell[-1].position & 0x1f) == 4) {
        pch_relocate_tag_symbol_list(cell);
      }
      else {
        pch_relocate_symbol_list(cell);
      }
    }
    cVar1 = pch_relocate_slot_once(&g_pch_image,(uint)&sym->tag_members);
    if (cVar1 == '\0') {
      return;
    }
    members = sym->tag_members;
    pch_relocate_slot_once(&g_pch_image,(uint)&members->last);
    cVar1 = pch_relocate_slot_once(&g_pch_image,(uint)&members->first);
    if (cVar1 == '\0') {
      return;
    }
    cell_00 = members->first;
    if ((*(byte *)(cell_00 + -2) & 0x1f) == 4) {
      pch_relocate_tag_symbol_list(cell_00);
      return;
    }
    pch_relocate_slot_once(&g_pch_image,(uint)cell_00);
    pch_relocate_symbol((byte *)(cell_00 + -2));
    cVar1 = pch_relocate_slot_once(&g_pch_image,(uint)(cell_00 + 1));
    if (cVar1 == '\0') {
      return;
    }
    link = (c1_sym_link *)cell_00[1];
    if ((link[-1].position & 0x1f) == 4) {
      pch_relocate_tag_symbol_list(link);
      return;
    }
  }
  else {
    pch_relocate_slot_once(&g_pch_image,(uint)&sym->name);
    pch_relocate_symbol(&sym->kind);
    cVar1 = pch_relocate_slot_once(&g_pch_image,(uint)&sym->next);
    if (cVar1 == '\0') {
      return;
    }
    link = sym->next;
    if ((link[-1].position & 0x1f) == 4) {
      pch_relocate_symbol_list(link);
      cVar1 = pch_relocate_slot_once(&g_pch_image,(uint)&link[2].type);
      if (cVar1 == '\0') {
        return;
      }
      link_members = (c1_scope_symbol_list *)link[2].type;
      pch_relocate_slot_once(&g_pch_image,(uint)&link_members->last);
      cVar1 = pch_relocate_slot_once(&g_pch_image,(uint)&link_members->first);
      if (cVar1 == '\0') {
        return;
      }
      link = (c1_sym_link *)link_members->first;
      if ((link[-1].position & 0x1f) == 4) {
        pch_relocate_tag_symbol_list(link);
        return;
      }
    }
  }
  pch_relocate_symbol_list(link);
  return;
}

