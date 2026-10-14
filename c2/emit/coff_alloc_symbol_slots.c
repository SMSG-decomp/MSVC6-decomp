uint32_t __fastcall coff_alloc_symbol_slots(uint32_t n,uint16_t after_section,int fixed)

{
  int iVar1;
  c2_coff_slot **ppcVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint32_t uVar6;
  
  uVar6 = 0;
  if (((after_section != 0) && (after_section != g_coff_abs_section_id)) ||
     ((uVar5 = g_coff_first_free_slot, fixed != 0 && (g_coff_function_slot_mark != 0)))) {
    uVar5 = g_coff_function_slot_mark;
    if (fixed == 0) {
      iVar1 = coff_symbol_value(after_section);
      uVar5 = iVar1 + 1;
    }
    if (uVar5 < g_coff_first_free_slot) {
      uVar5 = g_coff_first_free_slot;
    }
  }
  if (uVar5 < g_coff_symbol_slot_count) {
    ppcVar2 = g_coff_symbol_slots + uVar5;
    do {
      if ((*ppcVar2)->kind == 6) {
        uVar6 = uVar6 + 1;
      }
      else {
        uVar6 = 0;
      }
      uVar5 = uVar5 + 1;
      ppcVar2 = ppcVar2 + 1;
    } while ((uVar6 != n) && (uVar5 < g_coff_symbol_slot_count));
  }
  uVar5 = uVar5 - uVar6;
  if (uVar6 < n) {
    if (g_coff_symbol_slot_capacity < (uVar5 - 1) + n) {
      coff_grow_symbol_slots();
    }
    g_coff_symbol_slot_count = g_coff_symbol_slot_count + (n - uVar6);
  }
  uVar6 = g_coff_symbol_slot_count;
  uVar3 = uVar5;
  if (uVar5 < uVar5 + n) {
    iVar4 = (uVar5 + n) - uVar5;
    ppcVar2 = g_coff_symbol_slots + uVar5;
    for (iVar1 = iVar4; iVar1 != 0; iVar1 = iVar1 + -1) {
      *ppcVar2 = &g_coff_reserved_slot_record;
      ppcVar2 = ppcVar2 + 1;
    }
    uVar3 = iVar4 + uVar5;
  }
  if ((uVar5 == g_coff_first_free_slot) && (g_coff_first_free_slot = uVar3, uVar3 < uVar6)) {
    ppcVar2 = g_coff_symbol_slots + uVar3;
    do {
      if ((*ppcVar2)->kind == 6) {
        g_coff_first_free_slot = uVar3;
        g_coff_reserved_slots_left = n;
        g_coff_reserved_slot_cursor = uVar5;
        return uVar5;
      }
      uVar3 = uVar3 + 1;
      ppcVar2 = ppcVar2 + 1;
      g_coff_first_free_slot = uVar3;
    } while (uVar3 < uVar6);
  }
  g_coff_reserved_slot_cursor = uVar5;
  g_coff_reserved_slots_left = n;
  return uVar5;
}

