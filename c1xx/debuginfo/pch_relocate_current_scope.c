void __cdecl pch_relocate_current_scope(void)

{
  uint *slot;
  fe_file_record *slot_00;
  c1_using_cell *pcVar1;
  c1_symbol *sym;
  c1_scope_stack *pcVar2;
  char cVar3;
  byte bVar4;
  uint entry;
  c1_using_cell **ppcVar5;
  
  pcVar2 = g_current_scope;
  pch_relocate_slot_once(&g_pch_image,(uint *)g_current_scope);
  pch_relocate_slot_once(&g_pch_image,(uint *)&pcVar2->current);
  pch_relocate_slot_once(&g_pch_image,(uint *)pcVar2->contexts);
  pch_relocate_slot_once(&g_pch_image,(uint *)&pcVar2->closed_blocks);
  (*((c1xx_hash_scope *)pcVar2->global_scope)->vtbl->pch_fixup)
            ((c1xx_hash_scope *)pcVar2->global_scope);
  pch_relocate_pointer_array((uint)pcVar2->contexts,pcVar2->depth + 1);
  pch_relocate_slot_once(&g_pch_image,(uint *)&pcVar2->segments);
  pch_relocate_slot_once(&g_pch_image,(uint *)&pcVar2->file_records);
  pch_relocate_slot_once(&g_pch_image,(uint *)&pcVar2->using_namespaces);
  pch_relocate_slot_once(&g_pch_image,(uint *)&pcVar2->global_ns);
  slot = pcVar2->segments;
  if (slot != (uint *)0x0) {
    pch_relocate_slot_once(&g_pch_image,slot);
    pch_relocate_symbol((byte *)(slot + -2));
    cVar3 = pch_relocate_slot_once(&g_pch_image,slot + 1);
    if (cVar3 != '\0') {
      entry = slot[1];
      if ((*(byte *)(entry - 8) & 0x1f) == 4) {
        pch_relocate_symbol_list(entry);
        cVar3 = pch_relocate_slot_once(&g_pch_image,(uint *)(entry + 0x20));
        if (cVar3 != '\0') {
          pch_relocate_class_scope_list(*(uint *)(entry + 0x20));
        }
      }
      else {
        bVar4 = *(byte *)(entry - 8) & 0x1f;
        if ((bVar4 == 0x10) || (bVar4 == 0x11)) {
          pch_relocate_symbol_list(entry);
          cVar3 = pch_relocate_slot_once(&g_pch_image,(uint *)(entry + 0xc));
          if (cVar3 == '\0') goto LAB_1048a3f6;
          entry = *(uint *)(entry + 0xc);
        }
        pch_relocate_symbol_list(entry);
      }
    }
  }
LAB_1048a3f6:
  slot_00 = pcVar2->file_records;
  if (slot_00 != (fe_file_record *)0x0) {
    pch_relocate_slot_once(&g_pch_image,(uint *)slot_00);
    pch_relocate_slot_once(&g_pch_image,(uint *)&slot_00->canonical_name);
    cVar3 = pch_relocate_slot_once(&g_pch_image,(uint *)&slot_00->next);
    if (cVar3 != '\0') {
      pch_relocate_record_chain((int)slot_00->next);
    }
  }
  ppcVar5 = pcVar2->using_namespaces;
  if (ppcVar5 != (c1_using_cell **)0x0) {
    pch_relocate_slot_once(&g_pch_image,(uint *)ppcVar5);
    pcVar1 = *ppcVar5;
    pch_relocate_slot_once(&g_pch_image,(uint *)pcVar1);
    ppcVar5 = &pcVar1->next;
    pch_relocate_slot_once(&g_pch_image,(uint *)ppcVar5);
    pcVar1 = *ppcVar5;
    if (pcVar1 != (c1_using_cell *)0x0) {
      pch_fixup_pair_list((uint)pcVar1);
    }
  }
  sym = pcVar2->global_ns;
  if (sym != (c1_symbol *)0x0) {
    pch_relocate_symbol_chain(&sym->kind);
  }
  return;
}

