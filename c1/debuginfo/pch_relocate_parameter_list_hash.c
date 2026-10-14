void __cdecl pch_relocate_parameter_list_hash(void)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    pch_relocate_slot_once(&g_pch_image,iVar1 + (int)g_param_list_hash);
    pch_relocate_parameter_list_chain(*(uint **)(iVar1 + (int)g_param_list_hash));
    iVar1 = iVar1 + 4;
  } while (iVar1 < 0x1000);
  if (g_param_list_void != (c1_param_list *)0x0) {
    pch_relocate_counted_slot_array(&g_param_list_void->count);
  }
  if (g_param_list_empty != (c1_param_list *)0x0) {
    pch_relocate_counted_slot_array(&g_param_list_empty->count);
  }
  return;
}

