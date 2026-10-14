void __cdecl pch_fixup_pair_element(int elem)

{
  pch_relocate_slot_once(&g_pch_image,(uint *)elem);
  pch_relocate_slot_once(&g_pch_image,(uint *)(elem + 4));
  return;
}

