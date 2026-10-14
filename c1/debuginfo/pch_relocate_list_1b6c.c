void __fastcall pch_relocate_list_1b6c(int node)

{
  char cVar1;
  
  while( true ) {
    pch_relocate_slot_once(&g_pch_image,node);
    pch_relocate_slot_once(&g_pch_image,node + 0xc);
    cVar1 = pch_relocate_slot_once(&g_pch_image,node + 4U);
    if (cVar1 != '\0') {
      pch_relocate_pair(*(uint *)(node + 4U));
    }
    cVar1 = pch_relocate_slot_once(&g_pch_image,node + 8U);
    if (cVar1 == '\0') break;
    node = *(uint *)(node + 8U);
  }
  return;
}

