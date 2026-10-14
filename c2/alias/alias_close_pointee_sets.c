void __fastcall alias_close_pointee_sets(c2_symbol_cell *pointees,c2_bitvec *out,uint32_t nsyms)

{
  c2_symbol *pointees_00;
  uint32_t uVar1;
  c2_alias_ref *pcVar2;
  c2_bitvec *member_closure;
  c2_bitvec *ref_closure;
  int iVar3;
  c2_symbol *pointee;
  c2_symbol *member;
  
  for (; pointees != (c2_symbol_cell *)0x0; pointees = pointees->next) {
    pointee = pointees->sym;
    if (pointee->cls != '\f') {
      if (pointee->cls == '\x0e') {
        for (member = pointee->storage; member != (c2_symbol *)0x0; member = member->part_next) {
          uVar1 = (member->u34).refs;
          iVar3 = bitvec_test(out,uVar1);
          if (iVar3 == 0) {
            bitvec_set(out,uVar1);
            pointees_00 = member->order_next;
            if (pointees_00 != (c2_symbol *)0x0) {
              if (member->def == (c2_tuple *)0x0) {
                member_closure = bitvec_new(6,nsyms);
                member->def = (c2_tuple *)member_closure;
                alias_close_pointee_sets((c2_symbol_cell *)pointees_00,member_closure,nsyms);
              }
              bitvec_or(out,(c2_bitvec *)member->def);
            }
          }
          if ((member->u30).order_prev != (c2_symbol *)0x0) {
            iVar3 = uVar1 + g_alias_exposed_ref_count;
            if (g_alias_ref_table[iVar3].pointee_nodes == (c2_bitset *)0x0) {
              ref_closure = bitvec_new(6,nsyms);
              pcVar2 = g_alias_ref_table;
              g_alias_ref_table[iVar3].pointee_nodes = (c2_bitset *)ref_closure;
              alias_close_pointee_sets(pcVar2[iVar3].pointees,ref_closure,nsyms);
            }
            bitvec_or(out,(c2_bitvec *)g_alias_ref_table[iVar3].pointee_nodes);
          }
        }
      }
      else {
        uVar1 = (pointee->u34).refs;
        bitvec_set(out,uVar1);
        iVar3 = uVar1 + g_alias_exposed_ref_count;
        if (g_alias_ref_table[iVar3].pointee_nodes == (c2_bitset *)0x0) {
          ref_closure = bitvec_new(6,nsyms);
          pcVar2 = g_alias_ref_table;
          g_alias_ref_table[iVar3].pointee_nodes = (c2_bitset *)ref_closure;
          alias_close_pointee_sets(pcVar2[iVar3].pointees,ref_closure,nsyms);
        }
        bitvec_or(out,(c2_bitvec *)g_alias_ref_table[iVar3].pointee_nodes);
      }
    }
  }
  return;
}

