void __cdecl pch_relocate_redeclaration_value(uint *slot)

{
  pch_relocate_slot_once(&g_pch_image,slot);
  return;
}

