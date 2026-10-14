void __fastcall
alias_build_class_symbol_sets
          (c2_alias_call_effect *intrin_effects,c2_alias_call_effect *call_effects,uint32_t nsyms)

{
  uint32_t uVar1;
  c2_symbol *pcVar2;
  c2_symbol_cell **ppcVar3;
  c2_bitvec *pcVar4;
  c2_symbol_cell *pcVar5;
  
  while (intrin_effects != (c2_alias_call_effect *)0x0) {
    pcVar4 = bitvec_new(8,nsyms);
    uVar1 = intrin_effects->cls;
    pcVar5 = intrin_effects->members;
    g_alias_class_symbol_sets[uVar1] = pcVar4;
    for (; pcVar5 != (c2_symbol_cell *)0x0; pcVar5 = pcVar5->next) {
      pcVar2 = pcVar5->sym;
      bitvec_set(pcVar4,(pcVar2->u34).refs);
      if ((pcVar2->flags5 & 2) == 0) {
        for (pcVar2 = pcVar2->storage; pcVar2 != (c2_symbol *)0x0; pcVar2 = pcVar2->part_next) {
          pcVar2->flags5 = pcVar2->flags5 | 2;
        }
      }
    }
    if ((g_alias_special_symbol->u34).class_syms == (c2_bitvec *)0x0) {
      bitvec_set(pcVar4,0);
    }
    else {
      bitvec_or(pcVar4,(g_alias_special_symbol->u34).class_syms);
    }
    pcVar5 = symbol_list_add_unique(intrin_effects->members,g_alias_special_symbol,1);
    ppcVar3 = g_alias_primary_table;
    intrin_effects->members = pcVar5;
    intrin_effects = intrin_effects->next;
    ppcVar3[uVar1] = pcVar5;
  }
  for (; call_effects != (c2_alias_call_effect *)0x0; call_effects = call_effects->next) {
    uVar1 = call_effects->cls;
    pcVar5 = call_effects->members;
    g_alias_primary_table[uVar1] = pcVar5;
    pcVar4 = bitvec_new(8,nsyms);
    g_alias_class_symbol_sets[uVar1] = pcVar4;
    for (; pcVar5 != (c2_symbol_cell *)0x0; pcVar5 = pcVar5->next) {
      bitvec_set(pcVar4,(pcVar5->sym->u34).refs);
    }
  }
  return;
}

