void __fastcall pch_fixup_pair_list(uint node)

{
  do {
    pch_relocate_slot_once(&g_pch_image,(uint *)node);
    pch_relocate_slot_once(&g_pch_image,(uint *)(node + 4));
    node = *(uint *)(node + 4);
  } while ((uint *)node != (uint *)0x0);
  return;
}

