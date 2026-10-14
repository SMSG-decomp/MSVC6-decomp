void __fastcall alias_add_pointee(c2_tuple *t,int oa,c2_symbol *pointee)

{
  c2_operand *pcVar1;
  uint32_t uVar2;
  c2_alias_ref *pcVar3;
  c2_symbol_cell *pcVar4;
  
  pcVar3 = g_alias_ref_table;
  for (pcVar1 = t->dst; pcVar1 != (c2_operand *)0x0; pcVar1 = pcVar1->next) {
    uVar2 = pcVar1->rank;
    g_alias_ref_table = pcVar3;
    if (uVar2 != 0) {
      if (oa == 0) {
        pcVar4 = symbol_list_add_unique(pcVar3[uVar2].pointees,g_alias_special_symbol,4);
        pcVar3[uVar2].pointees = pcVar4;
      }
      pcVar4 = symbol_list_add_unique(pcVar3[uVar2].pointees,pointee,4);
      pcVar3[uVar2].pointees = pcVar4;
    }
    pcVar3 = g_alias_ref_table;
  }
  g_alias_ref_table = pcVar3;
  return;
}

