uint32_t __fastcall alias_assign_reserved_class(c2_symbol *sym)

{
  c2_bitvec **ppcVar1;
  c2_bitvec **ppcVar2;
  int iVar3;
  c2_symbol_cell *pcVar4;
  c2_bitvec *pcVar5;
  uint32_t n;
  uint32_t uVar6;
  
  uVar6 = g_alias_reserved_class_base;
  if (g_alias_reserved_class_base < g_alias_class_count) {
    do {
      iVar3 = symbol_in_alias_class(sym,uVar6);
      if (iVar3 != 0) {
        return uVar6;
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < g_alias_class_count);
  }
  uVar6 = g_alias_reserved_class_next;
  n = g_alias_reserved_number_next;
  if (g_alias_class_count <= g_alias_reserved_class_next) {
    uVar6 = g_alias_reserved_class_base;
    n = g_alias_reserved_number_base;
  }
  g_alias_reserved_class_next = uVar6 + 1;
  g_alias_reserved_number_next = n + 1;
  pcVar4 = symbol_list_add_unique(g_alias_primary_table[uVar6],sym,1);
  g_alias_primary_table[uVar6] = pcVar4;
  ppcVar2 = g_alias_class_symbol_sets;
  if (g_alias_class_symbol_sets[uVar6] == (c2_bitvec *)0x0) {
    ppcVar1 = g_alias_class_symbol_sets + uVar6;
    pcVar5 = bitvec_new(8,g_alias_symbol_number_count);
    *ppcVar1 = pcVar5;
  }
  bitvec_set(ppcVar2[uVar6],n);
  return uVar6;
}

