void coff_close_pending_type6_slots(void)

{
  uint32_t uVar1;
  c2_coff_slot **ppcVar2;
  int iVar3;
  
  uVar1 = g_coff_symbol_slot_count;
  if (g_coff_first_free_slot < g_coff_symbol_slot_count) {
    iVar3 = g_coff_symbol_slot_count - g_coff_first_free_slot;
    ppcVar2 = g_coff_symbol_slots + g_coff_first_free_slot;
    do {
      if ((*ppcVar2)->kind == 6) {
        *ppcVar2 = &g_coff_reserved_slot_record;
      }
      ppcVar2 = ppcVar2 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
    g_coff_first_free_slot = uVar1;
    return;
  }
  g_coff_first_free_slot = g_coff_symbol_slot_count;
  return;
}

