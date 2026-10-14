void __cdecl pch_relocate_list_1444(void)

{
  void *pvVar1;
  int *cell;
  
  pvVar1 = g_include_alias_table;
  pch_relocate_slot_once(&g_pch_image,g_include_alias_table);
  for (cell = *(int **)pvVar1; (uint *)cell != (uint *)0x0; cell = (int *)*cell) {
    pch_relocate_slot_once(&g_pch_image,(uint *)cell);
    pch_relocate_slot_once(&g_pch_image,(uint *)(cell + 1));
    pch_relocate_slot_once(&g_pch_image,(uint *)(cell + 2));
  }
  return;
}

