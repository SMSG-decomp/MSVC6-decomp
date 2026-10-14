void __cdecl pch_relocate_declarator_record_value(uint *slot)

{
  pch_relocate_slot_once(&g_pch_image,slot);
  pch_relocate_slot_once(&g_pch_image,slot + 1);
  return;
}

