void alias_build_class_symbol_sets_tail
               (c2_symbol *field_class,c2_bitvec *class_syms,c2_symbol_cell *member,
               c2_alias_memeffect *effect,uint32_t nsyms,c2_bitvec *rest_syms)

{
  uint8_t uVar1;
  c2_symbol *pcVar2;
  uint32_t n;
  c2_alias_class_subst *pcVar3;
  c2_symbol_cell *pcVar4;
  c2_bitvec *pcVar5;
  c2_symbol_cell *pcVar6;
  uint32_t uVar7;
  c2_bitvec *pcVar8;
  c2_symbol *pcVar9;
  undefined4 uStack0000000c;
  c2_symbol_chunk *chunk;
  
  do {
    bitvec_set(class_syms,(field_class->u34).refs);
    field_class = field_class->part_next;
  } while (field_class != (c2_symbol *)0x0);
  do {
    member = member->next;
    while (member == (c2_symbol_cell *)0x0) {
      pcVar9 = effect->scope;
      if ((pcVar9->u30).order_prev != (c2_symbol *)0x0) {
        pcVar4 = symbol_list_add_unique(effect->written,pcVar9,1);
        pcVar5 = (pcVar9->u34).class_syms;
        effect->written = pcVar4;
        if (pcVar5 != (c2_bitvec *)0x0) {
          bitvec_or(class_syms,pcVar5);
        }
      }
      pcVar4 = symbol_list_add_unique(effect->written,g_alias_special_symbol,1);
      pcVar9 = g_alias_special_symbol;
      effect->written = pcVar4;
      pcVar5 = (pcVar9->u34).class_syms;
      if (pcVar5 == (c2_bitvec *)0x0) {
        pcVar5 = g_alias_class_symbol_sets[3];
      }
      bitvec_or(class_syms,pcVar5);
      if (rest_syms != (c2_bitvec *)0x0) {
        bitvec_or(class_syms,rest_syms);
      }
      g_alias_primary_table[effect->dst_cls] = pcVar4;
      do {
        uVar7 = effect->src_cls;
        if (uVar7 != 0) {
          pcVar5 = bitvec_new(8,nsyms);
          pcVar4 = effect->read;
          g_alias_class_symbol_sets[uVar7] = pcVar5;
          for (; pcVar4 != (c2_symbol_cell *)0x0; pcVar4 = pcVar4->next) {
            pcVar9 = pcVar4->sym;
            if ((pcVar9->flags5 & 2) == 0) {
              for (pcVar2 = pcVar9->storage; pcVar2 != (c2_symbol *)0x0; pcVar2 = pcVar2->part_next)
              {
                pcVar2->flags5 = pcVar2->flags5 | 2;
              }
            }
            bitvec_set(pcVar5,(pcVar9->u34).refs);
            if ((pcVar9->u30).order_prev != (c2_symbol *)0x0) {
              for (pcVar9 = ((pcVar9->u30).order_prev)->part_next; pcVar9 != (c2_symbol *)0x0;
                  pcVar9 = pcVar9->part_next) {
                bitvec_set(pcVar5,(pcVar9->u34).refs);
              }
            }
          }
          pcVar9 = effect->scope;
          if ((pcVar9->u30).order_prev != (c2_symbol *)0x0) {
            pcVar4 = symbol_list_add_unique(effect->read,pcVar9,1);
            pcVar8 = (pcVar9->u34).class_syms;
            effect->read = pcVar4;
            if (pcVar8 != (c2_bitvec *)0x0) {
              bitvec_or(pcVar5,pcVar8);
            }
          }
          pcVar4 = symbol_list_add_unique(effect->read,g_alias_special_symbol,1);
          pcVar9 = g_alias_special_symbol;
          effect->read = pcVar4;
          pcVar8 = (pcVar9->u34).class_syms;
          if (pcVar8 == (c2_bitvec *)0x0) {
            pcVar8 = g_alias_class_symbol_sets[3];
          }
          bitvec_or(pcVar5,pcVar8);
          if (rest_syms != (c2_bitvec *)0x0) {
            bitvec_or(pcVar5,rest_syms);
          }
          g_alias_primary_table[effect->src_cls] = pcVar4;
        }
        effect = effect->next;
        if (effect == (c2_alias_memeffect *)0x0) {
          g_alias_eh_effect_records = (void *)0x0;
          for (; g_alias_loadv_class_substitutions != (c2_alias_class_subst *)0x0;
              g_alias_loadv_class_substitutions = g_alias_loadv_class_substitutions->next) {
            uVar7 = g_alias_loadv_class_substitutions->to_cls;
            pcVar5 = bitvec_new(8,nsyms);
            pcVar3 = g_alias_loadv_class_substitutions;
            g_alias_class_symbol_sets[uVar7] = pcVar5;
            for (pcVar4 = g_alias_primary_table[pcVar3->from_cls]; pcVar4 != (c2_symbol_cell *)0x0;
                pcVar4 = pcVar4->next) {
              uVar1 = pcVar4->sym->cls;
              if ((uVar1 != '\x0e') && (uVar1 != '\f')) {
                pcVar6 = symbol_list_add_unique(g_alias_primary_table[uVar7],pcVar4->sym,1);
                n = (pcVar4->sym->u34).refs;
                g_alias_primary_table[uVar7] = pcVar6;
                bitvec_set(g_alias_class_symbol_sets[uVar7],n);
              }
            }
          }
          if (g_alias_seh_edge_class != 0) {
            pcVar5 = bitvec_new(8,nsyms);
            uVar7 = g_alias_seh_edge_class;
            chunk = g_symbol_chunks;
            g_alias_class_symbol_sets[g_alias_seh_edge_class] = pcVar5;
            for (; chunk != (c2_symbol_chunk *)0x0; chunk = chunk->next) {
              pcVar9 = chunk->syms;
              if (pcVar9 < chunk->cursor) {
                do {
                  uVar1 = pcVar9->cls;
                  if (((uVar1 != '\x10') && (pcVar9->storage == pcVar9)) &&
                     ((uVar1 == '\x04' || (uVar1 == '\x05')))) {
                    pcVar4 = symbol_list_add_unique(g_alias_primary_table[uVar7],pcVar9,1);
                    g_alias_primary_table[g_alias_seh_edge_class] = pcVar4;
                    bitvec_set(pcVar5,(pcVar9->u34).refs);
                    uVar7 = g_alias_seh_edge_class;
                    pcVar2 = pcVar9;
                    if ((pcVar9->flags5 & 2) == 0) {
                      for (; g_alias_seh_edge_class = uVar7, pcVar2 != (c2_symbol *)0x0;
                          pcVar2 = pcVar2->part_next) {
                        pcVar2->flags5 = pcVar2->flags5 | 2;
                        uVar7 = g_alias_seh_edge_class;
                      }
                    }
                  }
                  pcVar9 = pcVar9 + 1;
                } while (pcVar9 < chunk->cursor);
              }
            }
            pcVar4 = symbol_list_add_unique(g_alias_primary_table[uVar7],g_alias_special_symbol,1);
            g_alias_primary_table[g_alias_seh_edge_class] = pcVar4;
            bitvec_or(pcVar5,(g_alias_special_symbol->u34).class_syms);
            g_alias_seh_edge_class = 0;
          }
          if (rest_syms != (c2_bitvec *)0x0) {
            uStack0000000c = 0x1072b4f7;
            bitset_header_free(rest_syms);
          }
          return;
        }
        uVar7 = effect->dst_cls;
      } while (uVar7 == 0);
      class_syms = bitvec_new(8,nsyms);
      member = effect->written;
      g_alias_class_symbol_sets[uVar7] = class_syms;
    }
    pcVar9 = member->sym;
    bitvec_set(class_syms,(pcVar9->u34).refs);
    pcVar9 = (pcVar9->u30).order_prev;
    if ((pcVar9 != (c2_symbol *)0x0) && (pcVar9 = pcVar9->part_next, pcVar9 != (c2_symbol *)0x0)) {
      alias_build_class_symbol_sets_tail(pcVar9,class_syms,member,effect,nsyms,rest_syms);
      return;
    }
  } while( true );
}

