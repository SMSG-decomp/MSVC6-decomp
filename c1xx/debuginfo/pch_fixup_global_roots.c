void __cdecl pch_fixup_global_roots(void)

{
  uint *puVar1;
  c1_symbol_vector **slot;
  c1_type **slot_00;
  c1_type **ppcVar2;
  
  slot = &g_pending_special_members;
  do {
    pch_relocate_pointer(&g_pch_image,(uint *)slot);
    slot = slot + 1;
  } while (slot < (c1_symbol_vector **)((int)&g_type_hash + 1U));
  pch_fixup_line_map();
  if ((char)g_builtin_operator_candidates[0].op != '\0') {
    ppcVar2 = &g_builtin_operator_candidates[0].left;
    do {
      pch_relocate_pointer(&g_pch_image,(uint *)(ppcVar2 + 3));
      for (slot_00 = ppcVar2; slot_00 < ppcVar2 + 2; slot_00 = slot_00 + 1) {
        pch_relocate_pointer(&g_pch_image,(uint *)slot_00);
      }
      puVar1 = (uint *)(ppcVar2 + 4);
      ppcVar2 = ppcVar2 + 5;
    } while ((char)*puVar1 != '\0');
  }
  return;
}

