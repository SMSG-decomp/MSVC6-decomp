void __fastcall propagate_alias_sets(uint32_t nfixed,uint32_t nrefs,int oa)

{
  byte bVar1;
  c2_symbol *pcVar2;
  c2_bitset *pcVar3;
  c2_symbol_cell *pcVar4;
  c2_symbol_cell *pcVar5;
  c2_symbol_cell *pcVar6;
  c2_symbol_cell *extra_pointees;
  int iVar7;
  int iVar8;
  c2_alias_ref *refs;
  int pass;
  int local_8;
  c2_symbol_cell *pointee;
  bool changed;
  c2_symbol *own_fields;
  
  pass = 0;
  refs = g_alias_ref_table;
  do {
    changed = false;
    if (nfixed < nrefs) {
      iVar8 = nfixed * 0x14;
      local_8 = nrefs - nfixed;
      do {
        pcVar3 = *(c2_bitset **)((int)&refs->pointee_nodes + iVar8);
        if (pcVar3 != (c2_bitset *)0x0) {
          own_fields = *(c2_symbol **)(*(int *)(*(int *)((int)&refs->sym + iVar8) + 0x30) + 0xc);
          iVar7 = bitset_iter_next(pcVar3);
          refs = g_alias_ref_table;
          while (g_alias_ref_table = refs, iVar7 != -1) {
            if ((iVar7 < (int)nfixed) && (oa == 0)) {
              if (pass == 0) {
                pcVar4 = *(c2_symbol_cell **)((int)&refs->pointees + iVar8);
                pcVar5 = symbol_list_add_unique(pcVar4,g_alias_special_symbol,4);
                *(c2_symbol_cell **)((int)&g_alias_ref_table->pointees + iVar8) = pcVar5;
                if (pcVar5 != pcVar4) {
                  changed = true;
                }
              }
            }
            else {
              for (pcVar4 = refs[iVar7].pointees; pcVar4 != (c2_symbol_cell *)0x0;
                  pcVar4 = pcVar4->next) {
                pcVar5 = *(c2_symbol_cell **)((int)&g_alias_ref_table->pointees + iVar8);
                pcVar6 = symbol_list_add_unique(pcVar5,pcVar4->sym,4);
                *(c2_symbol_cell **)((int)&g_alias_ref_table->pointees + iVar8) = pcVar6;
                if (pcVar6 != pcVar5) {
                  changed = true;
                  if (((pcVar4->sym->cls == '\x0e') && (own_fields != (c2_symbol *)0x0)) &&
                     (pcVar2 = pcVar4->sym->storage, own_fields != pcVar2)) {
                    extra_pointees =
                         symbol_list_add_unique((c2_symbol_cell *)pcVar2->order_next,own_fields,4);
                    pcVar2->order_next = (c2_symbol *)extra_pointees;
                  }
                }
              }
            }
            iVar7 = bitset_iter_next((c2_bitset *)0x0);
            refs = g_alias_ref_table;
          }
        }
        iVar8 = iVar8 + 0x14;
        local_8 = local_8 + -1;
      } while (local_8 != 0);
    }
    pass = pass + 1;
  } while (changed);
  if (nfixed < nrefs) {
    iVar7 = nfixed * 0x14;
    iVar8 = nrefs - nfixed;
    do {
      pcVar3 = *(c2_bitset **)((int)&refs->pointee_nodes + iVar7);
      if (pcVar3 != (c2_bitset *)0x0) {
        bitset_free(pcVar3);
        refs = g_alias_ref_table;
        *(undefined4 *)((int)&g_alias_ref_table->pointee_nodes + iVar7) = 0;
      }
      if (*(int *)((int)&refs->addr_taken + iVar7) != 0) {
        for (pointee = *(c2_symbol_cell **)((int)&refs->pointees + iVar7);
            pointee != (c2_symbol_cell *)0x0; pointee = pointee->next) {
          bVar1 = pointee->sym->flags5;
          if ((bVar1 & 2) != 0) {
            pointee->sym->flags5 = bVar1 | 4;
          }
        }
      }
      iVar7 = iVar7 + 0x14;
      iVar8 = iVar8 + -1;
    } while (iVar8 != 0);
  }
  return;
}

