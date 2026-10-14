void __fastcall pch_relocate_member_list_head(int *head_slot)

{
  int iVar1;
  char cVar2;
  uint *puVar3;
  
  cVar2 = pch_relocate_slot_once(&g_pch_image,(uint *)head_slot);
  if (cVar2 != '\0') {
    iVar1 = *head_slot;
    pch_relocate_slot_once(&g_pch_image,(uint *)(iVar1 + 8));
    puVar3 = (uint *)(iVar1 + 4);
    cVar2 = pch_relocate_slot_once(&g_pch_image,puVar3);
    if (cVar2 != '\0') {
      puVar3 = (uint *)*puVar3;
      pch_relocate_slot_once(&g_pch_image,puVar3);
      pch_relocate_symbol((byte *)(puVar3 + -2));
      pch_relocate_slot_once(&g_pch_image,puVar3 + 7);
      cVar2 = pch_relocate_slot_once(&g_pch_image,puVar3 + 1);
      if (cVar2 != '\0') {
        pch_relocate_symbol_list_simple(puVar3[1]);
      }
    }
  }
  return;
}

