void __cdecl pch_fixup_pair_record(int rec)

{
  pch_relocate_slot_once(&g_pch_image,(uint *)(rec + 4));
  pch_relocate_slot_once(&g_pch_image,(uint *)rec);
  return;
}

