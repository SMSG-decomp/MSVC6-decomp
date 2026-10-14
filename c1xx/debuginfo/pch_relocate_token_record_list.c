void __fastcall pch_relocate_token_record_list(int node)

{
  do {
    pch_relocate_slot_once(&g_pch_image,(uint *)node);
    pch_relocate_slot_once(&g_pch_image,(uint *)(node + 4));
    pch_relocate_slot_once(&g_pch_image,(uint *)(node + 8));
    token_io_release_record(*(uint *)(node + 4));
    node = *(uint *)(node + 8);
  } while ((uint *)node != (uint *)0x0);
  return;
}

