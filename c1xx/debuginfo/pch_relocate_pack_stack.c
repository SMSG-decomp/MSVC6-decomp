void __cdecl pch_relocate_pack_stack(void)

{
  c1_pack_cell **slot;
  c1_pack_cell *pcVar1;
  c1_pack_stack *pcVar2;
  
  pcVar2 = g_pack_stack;
  pch_relocate_slot_once(&g_pch_image,(uint *)g_pack_stack);
  for (pcVar1 = pcVar2->top; pcVar1 != (c1_pack_cell *)0x0; pcVar1 = pcVar1->next) {
    pch_relocate_slot_once(&g_pch_image,(uint *)pcVar1);
    if (pcVar1->ident != (void *)0x0) {
      pch_relocate_slot_once(&g_pch_image,(uint *)&pcVar1->ident);
    }
  }
  slot = &pcVar2->free_cells;
  pch_relocate_slot_once(&g_pch_image,(uint *)slot);
  for (pcVar1 = *slot; pcVar1 != (c1_pack_cell *)0x0; pcVar1 = pcVar1->next) {
    pch_relocate_slot_once(&g_pch_image,(uint *)pcVar1);
  }
  return;
}

