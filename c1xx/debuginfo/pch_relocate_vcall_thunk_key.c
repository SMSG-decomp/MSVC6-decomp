void __cdecl pch_relocate_vcall_thunk_key(uint *slot)

{
  pch_relocate_slot_once(&g_pch_image,slot);
  return;
}

