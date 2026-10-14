void __cdecl pch_relocate_hash_142c_record(int record)

{
  char cVar1;
  
  pch_relocate_slot_once(&g_pch_image,(uint *)record);
  pch_relocate_slot_once(&g_pch_image,(uint *)(record + 0xc));
  cVar1 = pch_relocate_slot_once(&g_pch_image,(uint *)(record + 8));
  if (cVar1 != '\0') {
    pch_relocate_tree(*(c1_node **)(record + 8));
  }
  return;
}

