void __cdecl pch_relocate_function_records(void)

{
  void *slot;
  fe_function_record_block *slot_00;
  char cVar1;
  int iVar2;
  void **slot_01;
  
  for (slot_00 = g_function_record_first_block; slot_00 != (fe_function_record_block *)0x0;
      slot_00 = slot_00->next) {
    pch_relocate_slot_once(&g_pch_image,(uint)slot_00);
    iVar2 = g_function_record_index;
    if (slot_00 != g_function_record_block) {
      iVar2 = 0x13;
    }
    slot_01 = &slot_00->records[0].references;
    iVar2 = iVar2 + 1;
    do {
      pch_relocate_slot_once(&g_pch_image,(uint)(slot_01 + -5));
      cVar1 = pch_relocate_slot_once(&g_pch_image,(uint)slot_01);
      if (cVar1 != '\0') {
        for (slot = *slot_01; slot != (void *)0x0; slot = *(void **)((int)slot + 4U)) {
          pch_relocate_slot_once(&g_pch_image,(uint)slot);
          pch_relocate_slot_once(&g_pch_image,(int)slot + 4U);
        }
      }
      slot_01 = slot_01 + 9;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return;
}

