void __fastcall pch_relocate_warning_state_chain(int state)

{
  char cVar1;
  
  cVar1 = pch_relocate_slot_once(&g_pch_image,state + 0x3f0U);
  if (cVar1 != '\0') {
    pch_relocate_warning_state_chain(*(int *)(state + 0x3f0U));
  }
  cVar1 = pch_relocate_slot_once(&g_pch_image,(uint)(state + 0x3ec));
  if (cVar1 != '\0') {
    pch_relocate_tagged_list(*(uint **)(state + 0x3ec));
  }
  return;
}

