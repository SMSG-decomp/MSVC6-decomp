void __cdecl pch_relocate_list_1444(void)

{
  c1_include_alias *slot;
  c1_include_alias **ppcVar1;
  
  ppcVar1 = g_include_alias_table;
  pch_relocate_slot_once(&g_pch_image,(uint)g_include_alias_table);
  for (slot = *ppcVar1; slot != (c1_include_alias *)0x0; slot = slot->next) {
    pch_relocate_slot_once(&g_pch_image,(uint)slot);
    pch_relocate_slot_once(&g_pch_image,(uint)&slot->from);
    pch_relocate_slot_once(&g_pch_image,(uint)&slot->to);
  }
  return;
}

