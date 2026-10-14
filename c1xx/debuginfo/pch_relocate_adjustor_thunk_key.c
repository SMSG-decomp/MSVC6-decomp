void __cdecl pch_relocate_adjustor_thunk_key(int key)

{
  pch_relocate_slot_once(&g_pch_image,(uint *)(key + 4));
  return;
}

