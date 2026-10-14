void __fastcall pch_relocate_list_1b6c(int node)

{
  char cVar1;
  
  while( true ) {
    pch_relocate_slot_once(&g_pch_image,(uint *)node);
    pch_relocate_slot_once(&g_pch_image,(uint *)(node + 0xc));
    cVar1 = pch_relocate_slot_once(&g_pch_image,(uint *)(node + 4));
    if (cVar1 != '\0') {
      pch_relocate_pair(*(void **)(node + 4));
    }
    cVar1 = pch_relocate_slot_once(&g_pch_image,(uint *)(node + 8));
    if (cVar1 == '\0') break;
    node = *(uint *)(node + 8);
  }
  return;
}

