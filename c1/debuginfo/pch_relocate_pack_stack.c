void __cdecl pch_relocate_pack_stack(void)

{
  fe_pack_cell **slot;
  fe_pack_stack *pfVar1;
  uint *record;
  uint *record_2;
  
  pfVar1 = g_pack_stack;
  pch_relocate_slot_once(&g_pch_image,(uint)g_pack_stack);
  for (record = (uint *)pfVar1->top; record != (uint *)0x0; record = (uint *)*record) {
    pch_relocate_slot_once(&g_pch_image,(uint)record);
    if (record[2] != 0) {
      pch_relocate_slot_once(&g_pch_image,(uint)(record + 2));
    }
  }
  slot = &pfVar1->free_cells;
  pch_relocate_slot_once(&g_pch_image,(uint)slot);
  for (record_2 = (uint *)*slot; record_2 != (uint *)0x0; record_2 = (uint *)*record_2) {
    pch_relocate_slot_once(&g_pch_image,(uint)record_2);
  }
  return;
}

