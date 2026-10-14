void __cdecl pch_relocate_type_hash(void)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    pch_relocate_slot_once(&g_pch_image,(uint *)(iVar1 + g_type_hash));
    pch_relocate_type_chain(*(void **)(iVar1 + g_type_hash));
    iVar1 = iVar1 + 4;
  } while (iVar1 < 0x2000);
  return;
}

