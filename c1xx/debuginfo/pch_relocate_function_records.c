void __cdecl pch_relocate_function_records(void)

{
  uint *slot;
  c1_function_record_block *slot_00;
  char cVar1;
  int iVar2;
  c1_u32 *slot_01;
  
  for (slot_00 = g_function_record_first_block; slot_00 != (c1_function_record_block *)0x0;
      slot_00 = slot_00->next) {
    pch_relocate_slot_once(&g_pch_image,(uint *)slot_00);
    iVar2 = g_function_record_index;
    if (slot_00 != g_function_record_block) {
      iVar2 = 0x13;
    }
    slot_01 = &slot_00->records[0].unk14;
    iVar2 = iVar2 + 1;
    do {
      pch_relocate_slot_once(&g_pch_image,(uint *)(slot_01 + -5));
      cVar1 = pch_relocate_slot_once(&g_pch_image,slot_01);
      if (cVar1 != '\0') {
        for (slot = (uint *)*slot_01; slot != (uint *)0x0; slot = (uint *)slot[1]) {
          pch_relocate_slot_once(&g_pch_image,slot);
          pch_relocate_slot_once(&g_pch_image,slot + 1);
        }
      }
      slot_01 = slot_01 + 9;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return;
}

