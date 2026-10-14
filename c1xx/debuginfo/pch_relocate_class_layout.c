void __cdecl pch_relocate_class_layout(int sym)

{
  char cVar1;
  char *pcVar2;
  
  pch_relocate_slot_once(&g_pch_image,(uint *)(*(int *)(sym + 0x24) + 8));
  pch_relocate_slot_once(&g_pch_image,(uint *)(*(int *)(sym + 0x24) + 0xc));
  pch_relocate_slot_once(&g_pch_image,(uint *)(*(int *)(sym + 0x24) + 0x10));
  pch_relocate_slot_once(&g_pch_image,(uint *)(*(int *)(sym + 0x24) + 0x14));
  pch_relocate_slot_once(&g_pch_image,(uint *)(*(int *)(sym + 0x24) + 0x18));
  pch_relocate_slot_once(&g_pch_image,(uint *)(*(int *)(sym + 0x24) + 0x1c));
  pch_mark_vector_slots(*(c1_vector **)(*(int *)(sym + 0x24) + 8),pch_mark_vtable_record);
  pch_mark_vector_slots(*(c1_vector **)(*(int *)(sym + 0x24) + 0xc),pch_mark_vtable_record);
  pch_mark_vector_slots(*(c1_vector **)(*(int *)(sym + 0x24) + 0x10),pch_relocate_vbase_record);
  pch_fixup_counted_pointer_array(*(short **)(*(int *)(sym + 0x24) + 0x18),(void *)0x0);
  pch_fixup_counted_pointer_array(*(short **)(*(int *)(sym + 0x24) + 0x1c),(void *)0x0);
  pcVar2 = *(char **)(sym + 0x14);
  cVar1 = *pcVar2;
  while (cVar1 < '\0') {
    pcVar2 = *(char **)(pcVar2 + 4);
    cVar1 = *pcVar2;
  }
  if ((pcVar2[1] & 1U) != 0) {
    pch_relocate_slot_once(&g_pch_image,(uint *)(sym + 0x28));
    pch_relocate_symtab_entries(*(c1_symtab **)(sym + 0x28),(void *)0x0,(void *)0x0);
    return;
  }
  pch_relocate_counted_pointer_array((uint *)(*(int *)(sym + 0x24) + 0x20));
  return;
}

