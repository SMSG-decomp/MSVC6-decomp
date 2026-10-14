void __cdecl pch_relocate_name_hash(void)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    pch_relocate_slot_once(&g_pch_image,iVar1 + (int)g_name_hash);
    pch_relocate_name_chain(*(uint **)(iVar1 + (int)g_name_hash));
    iVar1 = iVar1 + 4;
  } while (iVar1 < 0x2000);
  return;
}

