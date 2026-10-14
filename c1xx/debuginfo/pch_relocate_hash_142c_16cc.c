void __cdecl pch_relocate_hash_142c_16cc(void)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    pch_relocate_slot_once(&g_pch_image,(uint *)(iVar1 + (int)g_function_params_hash));
    pch_relocate_hash_142c_chain(*(void **)(iVar1 + (int)g_function_params_hash));
    iVar1 = iVar1 + 4;
  } while (iVar1 < 0x1000);
  iVar1 = 0;
  do {
    pch_relocate_slot_once(&g_pch_image,(uint *)(iVar1 + (int)g_type_list_hash));
    pch_relocate_hash_16cc_chain(*(void **)(iVar1 + (int)g_type_list_hash));
    iVar1 = iVar1 + 4;
  } while (iVar1 < 0x800);
  return;
}

