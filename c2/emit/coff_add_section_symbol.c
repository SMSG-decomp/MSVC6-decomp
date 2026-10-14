uint32_t __fastcall coff_add_section_symbol(c2_coff_section_out *sec)

{
  byte bVar1;
  c2_coff_section *pcVar2;
  c2_coff_slot *slot;
  uint32_t uVar3;
  bool bVar4;
  
  if ((g_opt_incremental != 0) && (g_coff_reserved_slots_left == 0)) {
    pcVar2 = sec->desc;
    if ((g_opt_edit_and_continue == 0) && (g_opt_ZX == 0)) {
      bVar1 = (byte)pcVar2->flags;
      uVar3 = 2;
    }
    else {
      bVar1 = (byte)pcVar2->flags;
      uVar3 = 3;
    }
    coff_alloc_symbol_slots
              (uVar3,-(ushort)(pcVar2->comdat_assoc != 0) & pcVar2->comdat_assoc,bVar1 & 0x10);
  }
  slot = (*g_coff_alloc_fn)(0xc);
  bVar4 = g_opt_incremental == 0;
  slot->kind = 2;
  slot->payload = sec;
  if (bVar4) {
    uVar3 = coff_push_record(slot);
  }
  else {
    uVar3 = coff_symtab_append(slot);
  }
  sec->symbol_index = uVar3;
  slot = (*g_coff_alloc_fn)(0xc);
  bVar4 = g_opt_incremental == 0;
  slot->kind = 5;
  if (bVar4) {
    coff_push_record(slot);
  }
  else {
    coff_symtab_append(slot);
  }
  if ((g_opt_edit_and_continue == 0) && (g_opt_ZX == 0)) {
    return 0;
  }
  slot = (*g_coff_alloc_fn)(0xc);
  bVar4 = g_opt_incremental != 0;
  slot->kind = 5;
  if (bVar4) {
    g_coff_symbol_slots[g_coff_reserved_slot_cursor] = slot;
    g_coff_reserved_slots_left = g_coff_reserved_slots_left + -1;
    uVar3 = g_coff_reserved_slot_cursor;
    g_coff_reserved_slot_cursor = g_coff_reserved_slot_cursor + 1;
    return uVar3;
  }
  if (g_coff_symbol_slot_capacity < g_coff_symbol_append_index) {
    coff_grow_symbol_slots();
  }
  g_coff_symbol_slot_count = g_coff_symbol_slot_count + 1;
  g_coff_symbol_slots[g_coff_symbol_append_index] = slot;
  uVar3 = g_coff_symbol_append_index;
  g_coff_symbol_append_index = g_coff_symbol_append_index + 1;
  return uVar3;
}

