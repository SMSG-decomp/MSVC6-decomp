void __cdecl pch_fixup_vtable_slot_word1(int slot)

{
  pch_relocate_slot_once(&g_pch_image,(uint *)(slot + 4));
  return;
}

