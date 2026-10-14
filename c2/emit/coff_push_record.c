uint32_t __fastcall coff_push_record(c2_coff_slot *slot)

{
  uint32_t uVar1;
  
  if (g_coff_symbol_slot_capacity < g_coff_symbol_append_index) {
    coff_grow_symbol_slots();
  }
  g_coff_symbol_slot_count = g_coff_symbol_slot_count + 1;
  g_coff_symbol_slots[g_coff_symbol_append_index] = slot;
  uVar1 = g_coff_symbol_append_index;
  g_coff_symbol_append_index = g_coff_symbol_append_index + 1;
  return uVar1;
}

