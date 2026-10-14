void __cdecl pch_fixup_vtable_slot_word0(uint slot)

{
  pch_relocate_slot_once(&g_pch_image,(uint *)slot);
  return;
}

