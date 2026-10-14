void __fastcall alias_replace_symbol(c2_symbol *old,c2_symbol *new_sym)

{
  c2_symbol *pcVar1;
  uint32_t uVar2;
  c2_symbol_cell **ppcVar3;
  int iVar4;
  c2_symbol_cell *member_cell;
  
  if (g_alias_tables_valid != 0) {
    if (1 < g_alias_class_count) {
      iVar4 = g_alias_class_count - 1;
      ppcVar3 = g_alias_primary_table;
      do {
        ppcVar3 = ppcVar3 + 1;
        for (member_cell = *ppcVar3; member_cell != (c2_symbol_cell *)0x0;
            member_cell = member_cell->next) {
          if (member_cell->sym == old) {
            member_cell->sym = new_sym;
          }
        }
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
    }
    for (member_cell = (g_alias_special_symbol->u30).members; pcVar1 = g_alias_scope_symbols,
        member_cell != (c2_symbol_cell *)0x0; member_cell = member_cell->next) {
      if (member_cell->sym == old) {
        member_cell->sym = new_sym;
      }
    }
    for (; pcVar1 != (c2_symbol *)0x0; pcVar1 = pcVar1->order_next) {
      for (member_cell = (pcVar1->u30).members; member_cell != (c2_symbol_cell *)0x0;
          member_cell = member_cell->next) {
        if (member_cell->sym == old) {
          member_cell->sym = new_sym;
        }
      }
    }
    uVar2 = sparse_set_test_and_remove(g_aliased_syms,old->id);
    if (uVar2 != 0) {
      bitset_set(g_aliased_syms,new_sym->id);
    }
  }
  return;
}

