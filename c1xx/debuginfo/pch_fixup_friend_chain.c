void __cdecl pch_fixup_friend_chain(int node)

{
  for (; node != 0; node = *(uint *)(node + 8U)) {
    pch_relocate_slot_once(&g_pch_image,(uint *)(node + 4));
    pch_relocate_slot_once(&g_pch_image,(uint *)(node + 8U));
  }
  return;
}

