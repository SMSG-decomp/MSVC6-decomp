void __cdecl pch_relocate_current_scope(void)

{
  uint slot;
  int iVar1;
  fe_file_record *slot_00;
  c1_scope_stack *pcVar2;
  char cVar3;
  void *cell;
  void **link_slot;
  
  pcVar2 = g_current_scope;
  pch_relocate_slot_once(&g_pch_image,(uint)g_current_scope);
  pch_relocate_slot_once(&g_pch_image,(uint)&pcVar2->current);
  pch_relocate_slot_once(&g_pch_image,(uint)pcVar2->objects);
  pch_relocate_slot_once(&g_pch_image,(uint)&pcVar2->unk20c);
  (*pcVar2->file_scope->vtbl->pch_fixup)(pcVar2->file_scope);
  pch_relocate_pointer_array((uint)pcVar2->objects,pcVar2->depth + 1);
  pch_relocate_slot_once(&g_pch_image,(uint)&pcVar2->unk210);
  pch_relocate_slot_once(&g_pch_image,(uint)&pcVar2->file_records);
  slot = pcVar2->unk210;
  if (slot != 0) {
    pch_relocate_slot_once(&g_pch_image,slot);
    pch_relocate_symbol((byte *)(slot - 8));
    cVar3 = pch_relocate_slot_once(&g_pch_image,slot + 4);
    if (cVar3 != '\0') {
      cell = *(void **)(slot + 4);
      if ((*(byte *)((int)cell + -8) & 0x1f) == 4) {
        pch_relocate_symbol_list(cell);
        cVar3 = pch_relocate_slot_once(&g_pch_image,(uint)((int)cell + 0x2c));
        if (cVar3 == '\0') goto LAB_106438f8;
        iVar1 = *(int *)((int)cell + 0x2c);
        pch_relocate_slot_once(&g_pch_image,iVar1 + 8);
        link_slot = (void **)(iVar1 + 4);
        cVar3 = pch_relocate_slot_once(&g_pch_image,(uint)link_slot);
        if (cVar3 == '\0') goto LAB_106438f8;
        cell = *link_slot;
        if ((*(byte *)((int)cell + -8) & 0x1f) == 4) {
          pch_relocate_tag_symbol_list(cell);
          goto LAB_106438f8;
        }
      }
      pch_relocate_symbol_list(cell);
    }
  }
LAB_106438f8:
  slot_00 = pcVar2->file_records;
  if (slot_00 != (fe_file_record *)0x0) {
    pch_relocate_slot_once(&g_pch_image,(uint)slot_00);
    pch_relocate_slot_once(&g_pch_image,(uint)&slot_00->canonical_name);
    cVar3 = pch_relocate_slot_once(&g_pch_image,(uint)&slot_00->next);
    if (cVar3 != '\0') {
      pch_relocate_record_chain(slot_00->next);
    }
  }
  return;
}

