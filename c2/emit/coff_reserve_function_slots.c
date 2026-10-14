void __fastcall coff_reserve_function_slots(uint32_t key)

{
  uint32_t uVar1;
  
  uVar1 = coff_hash64_find(key,1);
  if (uVar1 == 0) {
    coff_alloc_symbol_slots(3,0,0);
    return;
  }
  g_coff_reserved_slots_left = 2;
  g_coff_reserved_slot_cursor = uVar1 - 2;
  return;
}

