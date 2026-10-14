void __cdecl pch_mark_vtable_record(int *rec)

{
  uint slot;
  int iVar1;
  
  pch_relocate_slot_once(&g_pch_image,(uint *)(rec + 1));
  pch_relocate_slot_once(&g_pch_image,(uint *)(rec + 6));
  pch_relocate_slot_once(&g_pch_image,(uint *)(rec + 2));
  pch_relocate_slot_once(&g_pch_image,(uint *)(rec + 10));
  pch_relocate_slot_once(&g_pch_image,(uint *)(rec + 0xb));
  pch_relocate_slot_once(&g_pch_image,(uint *)(rec + 0xc));
  pch_relocate_slot_once(&g_pch_image,(uint *)(rec + 0xd));
  pch_relocate_slot_once(&g_pch_image,(uint *)(rec + 0xf));
  iVar1 = 0;
  while (iVar1 < rec[4]) {
    slot = iVar1 * 0x10 + rec[6];
    iVar1 = iVar1 + 1;
    if (slot == 0) break;
    if ((*rec == 0) || (*rec == 2)) {
      pch_fixup_vtable_slot_word0(slot);
    }
    else {
      pch_fixup_vtable_slot_word1(slot);
    }
  }
  pch_mark_vector_slots((c1_vector *)rec[0xd],(void *)0x0);
  return;
}

