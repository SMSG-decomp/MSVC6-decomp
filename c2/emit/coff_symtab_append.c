uint32_t __fastcall coff_symtab_append(c2_coff_slot *slot)

{
  uint32_t uVar1;
  
  g_coff_symbol_slots[g_coff_reserved_slot_cursor] = slot;
  g_coff_reserved_slots_left = g_coff_reserved_slots_left + -1;
  uVar1 = g_coff_reserved_slot_cursor;
  g_coff_reserved_slot_cursor = g_coff_reserved_slot_cursor + 1;
  return uVar1;
}

