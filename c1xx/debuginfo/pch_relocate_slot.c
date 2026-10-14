void __fastcall pch_relocate_slot(uint slot)

{
  pch_relocate_slot_once(&g_pch_image,(uint *)slot);
  return;
}

