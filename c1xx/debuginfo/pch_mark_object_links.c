void __fastcall pch_mark_object_links(int obj)

{
  pch_relocate_slot_once(&g_pch_image,(uint *)(obj + 4));
  pch_relocate_slot_once(&g_pch_image,(uint *)(obj + 8));
  return;
}

