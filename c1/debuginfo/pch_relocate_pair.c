void __cdecl pch_relocate_pair(uint slots)

{
  pch_relocate_slot_once(&g_pch_image,slots);
  pch_relocate_slot_once(&g_pch_image,slots + 4);
  return;
}

