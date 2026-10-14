void __cdecl pch_relocate_warning_state(void)

{
  uint uVar1;
  fe_warning_record *slot;
  char cVar2;
  
  pch_relocate_warning_state_chain((int)g_warning_state);
  slot = g_warning_record_free_list;
  if (g_warning_record_free_list != (fe_warning_record *)0x0) {
    uVar1 = g_warning_record_free_list->next;
    g_warning_record_free_list->next = g_warning_record_free_list->next & 0xfffffffe;
    cVar2 = pch_relocate_slot_once(&g_pch_image,(uint)slot);
    if (cVar2 != '\0') {
      pch_relocate_tagged_list((uint *)slot->next);
    }
    if ((uVar1 & 1) != 0) {
      slot->next = slot->next | 1;
    }
    return;
  }
  return;
}

