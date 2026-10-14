void __fastcall coff_fill_slots_default(uint32_t first,int n)

{
  c2_coff_slot **ppcVar1;
  
  if (first < g_coff_first_free_slot) {
    g_coff_first_free_slot = first;
  }
  if (0 < n) {
    ppcVar1 = g_coff_symbol_slots + first;
    for (; n != 0; n = n + -1) {
      *ppcVar1 = &g_coff_free_slot_record;
      ppcVar1 = ppcVar1 + 1;
    }
  }
  return;
}

