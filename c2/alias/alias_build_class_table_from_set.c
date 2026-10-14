void __fastcall alias_build_class_table_from_set(c2_symbol *s,int nfixed,uint32_t nsyms,int based)

{
  ushort uVar1;
  c2_alias_sym_info *pcVar2;
  uint32_t uVar3;
  c2_symbol *pcVar4;
  c2_alias_class_cache *pcVar5;
  c2_bitvec *pcVar6;
  int iVar7;
  c2_symbol *member_sym;
  c2_symbol_cell *scope_member;
  c2_symbol_cell *class_members;
  int own_fields_only;
  uint32_t access_size;
  int access_offset;
  c2_symbol_cell *pointee;
  
  pcVar2 = (s->u30).alias_info;
  bitset_free(pcVar2->ref_nodes);
  pcVar2->ref_nodes = (c2_bitset *)0x0;
  pcVar5 = pcVar2->classes;
  own_fields_only = based;
  do {
    if (pcVar5 == (c2_alias_class_cache *)0x0) {
      if (own_fields_only != 0) {
        for (member_sym = pcVar2->fields; member_sym != (c2_symbol *)0x0;
            member_sym = member_sym->part_next) {
          bitvec_set(g_alias_based_member_numbers,(member_sym->u34).refs);
        }
      }
      return;
    }
    uVar3 = pcVar5->cls;
    if (g_alias_primary_table[uVar3] == (c2_symbol_cell *)0x0) {
      if (based != 0) {
        access_size = pcVar5->size;
        access_offset = *(int *)((int)pcVar5->key + 0x24);
      }
      pcVar6 = bitvec_new(8,nsyms);
      class_members = (c2_symbol_cell *)0x0;
      g_alias_class_symbol_sets[uVar3] = pcVar6;
      iVar7 = bitset_iter_next(pcVar5->pointees);
      while (iVar7 != -1) {
        if ((iVar7 < nfixed) && (based == 0)) {
          class_members = symbol_list_add_unique(class_members,g_alias_special_symbol,1);
        }
        else {
          for (pointee = g_alias_ref_table[iVar7].pointees; pointee != (c2_symbol_cell *)0x0;
              pointee = pointee->next) {
            member_sym = pointee->sym;
            if (((member_sym->cls == '\f') && (member_sym != g_alias_special_symbol)) &&
               ((member_sym->u30).order_prev == (c2_symbol *)0x0)) {
              own_fields_only = 0;
            }
            else if (member_sym->cls == '\x0e') {
              if (access_offset < 1) {
                pcVar6 = g_alias_class_symbol_sets[uVar3];
              }
              else {
                member_sym = alias_find_member_by_offset
                                       (member_sym,member_sym->offset + access_offset);
                pcVar6 = g_alias_class_symbol_sets[uVar3];
              }
              alias_mark_offset_members(member_sym,pcVar6,access_offset,access_size);
              if (member_sym != pcVar5->key) {
                own_fields_only = 0;
              }
            }
            else {
              class_members = symbol_list_add_unique(class_members,member_sym,1);
            }
          }
        }
        if ((iVar7 < nfixed) || (g_alias_ref_table[iVar7].addr_taken != 0)) {
          own_fields_only = 0;
        }
        iVar7 = bitset_iter_next((c2_bitset *)0x0);
      }
      g_alias_primary_table[uVar3] = class_members;
      for (; class_members != (c2_symbol_cell *)0x0; class_members = class_members->next) {
        member_sym = class_members->sym;
        if (member_sym->cls == '\f') {
          if (based == 0) {
            bitvec_or(g_alias_class_symbol_sets[uVar3],(member_sym->u34).class_syms);
          }
          else {
            scope_member = (member_sym->u30).members;
            if (scope_member != (c2_symbol_cell *)0x0) {
              member_sym = pcVar2->fields;
              do {
                uVar1 = (scope_member->sym->fe->u3e).alias_class;
                pcVar4 = member_sym;
                if (g_alias_class_symbol_sets[uVar1] == (c2_bitvec *)0x0) {
                  pcVar6 = bitvec_new(8,nsyms);
                  g_alias_class_symbol_sets[uVar1] = pcVar6;
                }
                for (; pcVar4 != (c2_symbol *)0x0; pcVar4 = pcVar4->part_next) {
                  bitvec_set(g_alias_class_symbol_sets[uVar1],(pcVar4->u34).refs);
                }
                scope_member = scope_member->next;
              } while (scope_member != (c2_symbol_cell *)0x0);
            }
          }
LAB_1072bdb9:
          own_fields_only = 0;
        }
        else {
          bitvec_set(g_alias_class_symbol_sets[uVar3],(member_sym->u34).refs);
          if ((member_sym->flags5 & 4) != 0) goto LAB_1072bdb9;
        }
      }
    }
    bitset_free(pcVar5->pointees);
    pcVar5->pointees = (c2_bitset *)0x0;
    pcVar5 = pcVar5->next;
  } while( true );
}

