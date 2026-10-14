void coff_find_first_type6_slot(void)

{
  c2_coff_slot **ppcVar1;
  
  g_coff_first_free_slot = 0;
  ppcVar1 = g_coff_symbol_slots;
  if (g_coff_symbol_slot_count != 0) {
    do {
      if ((*ppcVar1)->kind == 6) {
        return;
      }
      g_coff_first_free_slot = g_coff_first_free_slot + 1;
      ppcVar1 = ppcVar1 + 1;
    } while (g_coff_first_free_slot < g_coff_symbol_slot_count);
  }
  return;
}

