void __fastcall pch_fixup_scope_record_chain(int rec)

{
  do {
    pch_relocate_slot_once(&g_pch_image,(uint *)rec);
    pch_relocate_slot_once(&g_pch_image,(uint *)(rec + 4));
    pch_relocate_slot_once(&g_pch_image,(uint *)(rec + 8));
    pch_relocate_slot_once(&g_pch_image,(uint *)(rec + 0x10));
    rec = *(uint *)(rec + 0x10);
  } while ((uint *)rec != (uint *)0x0);
  return;
}

