void __fastcall pch_relocate_template_header(int rec)

{
  char cVar1;
  
  pch_relocate_member_list_head((int *)rec);
  pch_relocate_slot_once(&g_pch_image,(uint *)(rec + 8));
  pch_relocate_slot_once(&g_pch_image,(uint *)(rec + 0xc));
  pch_relocate_slot_once(&g_pch_image,(uint *)(rec + 0x18));
  pch_relocate_slot_once(&g_pch_image,(uint *)(rec + 0x10));
  cVar1 = pch_relocate_slot_once(&g_pch_image,(uint *)(rec + 0x14));
  if (cVar1 != '\0') {
    (**(code **)(**(int **)(rec + 0x14) + 0x20))();
  }
  return;
}

