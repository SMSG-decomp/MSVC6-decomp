void __cdecl pch_relocate_warning_state(void)

{
  c1_u32 cVar1;
  c1_warning_record *slot;
  char cVar2;
  
  pch_relocate_warning_state_chain((int)g_warning_state);
  if (g_tmpl_warning_state_snapshot != (int *)0x0) {
    pch_relocate_hook_empty();
  }
  slot = g_warning_record_free_list;
  if (g_warning_record_free_list != (c1_warning_record *)0x0) {
    cVar1 = g_warning_record_free_list->next;
    g_warning_record_free_list->next = g_warning_record_free_list->next & 0xfffffffe;
    cVar2 = pch_relocate_slot_once(&g_pch_image,&slot->next);
    if (cVar2 != '\0') {
      pch_relocate_tagged_list((uint *)slot->next);
    }
    if ((cVar1 & 1) != 0) {
      slot->next = slot->next | 1;
    }
    return;
  }
  return;
}

