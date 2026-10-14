void __fastcall
build_alias_class_tables
          (uint32_t scope_cls_end,uint32_t nscopes,uint32_t nfixed,uint32_t nsyms,int oa)

{
  c2_bitvec **ppcVar1;
  c2_symbol_cell **ppcVar2;
  uint8_t uVar3;
  ushort uVar4;
  c2_symbol *pcVar5;
  uint32_t n;
  c2_bitvec **ppcVar6;
  c2_alias_call_record *pcVar7;
  c2_alias_ref *pcVar8;
  c2_alias_class_subst *pcVar9;
  void *pvVar10;
  c2_bitvec *pcVar11;
  c2_symbol_cell *cell;
  int iVar12;
  c2_bitvec *closure;
  c2_symbol_cell *pcVar13;
  c2_symbol_cell *pcVar14;
  uint32_t uVar15;
  c2_bitvec *pcVar16;
  c2_alias_memeffect *effect;
  uint uVar17;
  uint uVar18;
  c2_symbol *pcVar19;
  int local_8;
  c2_symbol_cell *member_cell;
  c2_symbol_chunk *chunk;
  
  g_alias_primary_table = arena_alloc(1,g_alias_class_count * 4);
  g_alias_class_symbol_sets = arena_alloc(1,g_alias_class_count * 4);
  pcVar11 = bitvec_new(8,nsyms);
  g_alias_class_symbol_sets[2] = pcVar11;
  if (g_alias_loadv_class != 0) {
    pcVar11 = bitvec_new(8,nsyms);
    g_alias_class_symbol_sets[g_alias_loadv_class] = pcVar11;
  }
  pcVar11 = bitvec_new(8,nsyms);
  for (member_cell = (g_alias_special_symbol->u30).members; member_cell != (c2_symbol_cell *)0x0;
      member_cell = member_cell->next) {
    bitvec_set(pcVar11,(member_cell->sym->u34).refs);
  }
  bitvec_set(pcVar11,0);
  (g_alias_special_symbol->u34).class_syms = pcVar11;
  if (oa != 0) {
    g_alias_based_member_numbers = bitvec_new(8,nsyms);
  }
  local_8 = 1;
  uVar17 = scope_cls_end - 1;
  pcVar19 = g_alias_scope_symbols;
  for (uVar18 = uVar17; chunk = g_symbol_chunks, 2 < uVar18; uVar18 = uVar18 - 1) {
    pcVar11 = bitvec_new(8,nsyms);
    g_alias_class_symbol_sets[uVar18] = pcVar11;
    if ((pcVar19->u30).order_prev != (c2_symbol *)0x0) {
      pcVar14 = symbol_list_add_unique((c2_symbol_cell *)0x0,pcVar19,1);
      g_alias_primary_table[uVar18] = pcVar14;
      pcVar11 = bitvec_new(8,nsyms);
      ppcVar6 = g_alias_class_symbol_sets;
      for (pcVar14 = (pcVar19->u30).members; g_alias_class_symbol_sets = ppcVar6,
          pcVar14 != (c2_symbol_cell *)0x0; pcVar14 = pcVar14->next) {
        bitvec_set(pcVar11,(pcVar14->sym->u34).refs);
        ppcVar6 = g_alias_class_symbol_sets;
      }
      (pcVar19->u34).class_syms = pcVar11;
      bitvec_or(ppcVar6[uVar18],pcVar11);
      pcVar19->offset = local_8;
      local_8 = local_8 + 1;
    }
    if (oa == 0) {
      cell = symbol_list_add_unique(g_alias_primary_table[uVar18],g_alias_special_symbol,1);
      pcVar11 = (g_alias_special_symbol->u34).class_syms;
      g_alias_primary_table[uVar18] = cell;
      bitvec_or(g_alias_class_symbol_sets[uVar18],pcVar11);
    }
    pcVar19 = pcVar19->order_next;
  }
  for (; pcVar19 = g_alias_synth_class_symbols, chunk != (c2_symbol_chunk *)0x0; chunk = chunk->next
      ) {
    pcVar19 = chunk->syms;
    if (pcVar19 < chunk->cursor) {
      do {
        uVar3 = pcVar19->cls;
        if (uVar3 != '\x10') {
          if ((pcVar19->storage == pcVar19) &&
             ((((uVar3 == '\x04' || (uVar3 == '\x05')) || (uVar3 == '\a')) || (uVar3 == '\b')))) {
            uVar4 = (pcVar19->fe->u3e).alias_class;
            pcVar14 = symbol_list_add_unique((c2_symbol_cell *)0x0,pcVar19,1);
            g_alias_primary_table[uVar4] = pcVar14;
            ppcVar6 = g_alias_class_symbol_sets;
            if (g_alias_class_symbol_sets[uVar4] == (c2_bitvec *)0x0) {
              ppcVar1 = g_alias_class_symbol_sets + uVar4;
              pcVar11 = bitvec_new(8,nsyms);
              *ppcVar1 = pcVar11;
            }
            bitvec_set(ppcVar6[uVar4],(pcVar19->u34).refs);
          }
          if ((pcVar19->flags5 & 8) == 0) {
            if (((pcVar19->storage == pcVar19) && (oa != 0)) && ((pcVar19->u34).refs != 0)) {
              alias_build_class_table_for_base(pcVar19,nsyms);
            }
          }
          else {
            alias_build_class_table_from_set(pcVar19,nfixed,nsyms,oa);
            for (pcVar5 = ((pcVar19->u30).order_prev)->part_next; pcVar5 != (c2_symbol *)0x0;
                pcVar5 = pcVar5->part_next) {
              if ((pcVar5->u30).order_prev != (c2_symbol *)0x0) {
                alias_build_class_table_for_base(pcVar5,nsyms);
              }
            }
          }
        }
        pcVar19 = pcVar19 + 1;
      } while (pcVar19 < chunk->cursor);
    }
  }
  for (; pcVar19 != (c2_symbol *)0x0; pcVar19 = pcVar19->order_next) {
    alias_build_class_table_from_set(pcVar19,nfixed,nsyms,oa);
    if ((pcVar19->u34).refs != 0) {
      uVar15 = ((pcVar19->u30).alias_info)->classes->cls;
      pcVar14 = g_alias_primary_table[(pcVar19->u34).refs];
      while (pcVar14 != (c2_symbol_cell *)0x0) {
        ppcVar2 = g_alias_primary_table + uVar15;
        pcVar13 = symbol_list_add_unique(g_alias_primary_table[uVar15],pcVar14->sym,1);
        pcVar14 = pcVar14->next;
        *ppcVar2 = pcVar13;
      }
      bitvec_or(g_alias_class_symbol_sets[uVar15],g_alias_class_symbol_sets[(pcVar19->u34).refs]);
    }
  }
  if (oa == 0) {
    oa = 0;
    pcVar7 = g_alias_call_records;
    effect = g_alias_eh_effect_records;
  }
  else {
    oa = (int)bitvec_new(8,nsyms);
    bitvec_set((c2_bitvec *)oa,0);
    for (uVar18 = g_alias_symbol_number_end; uVar18 < nsyms; uVar18 = uVar18 + 1) {
      bitvec_set((c2_bitvec *)oa,uVar18);
    }
    bitvec_and_not((c2_bitvec *)oa,g_alias_based_member_numbers);
    bitset_header_free(g_alias_based_member_numbers);
    for (; 2 < uVar17; uVar17 = uVar17 - 1) {
      bitvec_or(g_alias_class_symbol_sets[uVar17],(c2_bitvec *)oa);
    }
    pcVar14 = symbol_list_add_unique(g_alias_primary_table[3],g_alias_special_symbol,1);
    pcVar11 = g_alias_class_symbol_sets[3];
    g_alias_primary_table[3] = pcVar14;
    bitvec_or(pcVar11,(g_alias_special_symbol->u34).class_syms);
    pcVar7 = g_alias_call_records;
    effect = g_alias_eh_effect_records;
  }
  for (; g_alias_eh_effect_records = effect, pcVar7 != (c2_alias_call_record *)0x0;
      pcVar7 = pcVar7->next) {
    uVar15 = pcVar7->cls;
    pcVar14 = symbol_list_add_unique((c2_symbol_cell *)0x0,g_alias_special_symbol,1);
    g_alias_primary_table[uVar15] = pcVar14;
    pcVar11 = bitvec_new(8,nsyms);
    pcVar19 = pcVar7->scope;
    g_alias_class_symbol_sets[uVar15] = pcVar11;
    if ((pcVar19->u30).order_prev != (c2_symbol *)0x0) {
      pcVar14 = symbol_list_add_unique(g_alias_primary_table[uVar15],pcVar19,1);
      g_alias_primary_table[uVar15] = pcVar14;
      bitvec_or(pcVar11,(pcVar19->u34).class_syms);
    }
    bitvec_set(pcVar11,0);
    for (pcVar14 = pcVar7->pointees; pcVar14 != (c2_symbol_cell *)0x0; pcVar14 = pcVar14->next) {
      bitvec_set(pcVar11,(pcVar14->sym->u34).refs);
    }
    iVar12 = bitset_iter_next(pcVar7->pointee_nodes);
    while (iVar12 != -1) {
      if (g_alias_ref_table[iVar12].pointee_nodes == (c2_bitset *)0x0) {
        closure = bitvec_new(6,nsyms);
        pcVar8 = g_alias_ref_table;
        g_alias_ref_table[iVar12].pointee_nodes = (c2_bitset *)closure;
        alias_close_pointee_sets(pcVar8[iVar12].pointees,closure,nsyms);
      }
      bitvec_or(pcVar11,(c2_bitvec *)g_alias_ref_table[iVar12].pointee_nodes);
      iVar12 = bitset_iter_next((c2_bitset *)0x0);
    }
    bitvec_or(pcVar11,(g_alias_special_symbol->u34).class_syms);
    bitset_free(pcVar7->pointee_nodes);
    effect = g_alias_eh_effect_records;
  }
  pvVar10 = (void *)0x0;
  if (effect != (c2_alias_memeffect *)0x0) {
    do {
      uVar15 = effect->dst_cls;
      if (uVar15 != 0) {
        pcVar11 = bitvec_new(8,nsyms);
        pcVar14 = effect->written;
        g_alias_class_symbol_sets[uVar15] = pcVar11;
        for (; pcVar14 != (c2_symbol_cell *)0x0; pcVar14 = pcVar14->next) {
          pcVar19 = pcVar14->sym;
          bitvec_set(pcVar11,(pcVar19->u34).refs);
          pcVar19 = (pcVar19->u30).order_prev;
          if ((pcVar19 != (c2_symbol *)0x0) &&
             (pcVar19 = pcVar19->part_next, pcVar19 != (c2_symbol *)0x0)) {
            alias_build_class_symbol_sets_tail(pcVar19,pcVar11,pcVar14,effect,nsyms,(c2_bitvec *)oa)
            ;
            return;
          }
        }
        pcVar19 = effect->scope;
        if ((pcVar19->u30).order_prev != (c2_symbol *)0x0) {
          pcVar14 = symbol_list_add_unique(effect->written,pcVar19,1);
          pcVar16 = (pcVar19->u34).class_syms;
          effect->written = pcVar14;
          if (pcVar16 != (c2_bitvec *)0x0) {
            bitvec_or(pcVar11,pcVar16);
          }
        }
        pcVar14 = symbol_list_add_unique(effect->written,g_alias_special_symbol,1);
        pcVar19 = g_alias_special_symbol;
        effect->written = pcVar14;
        pcVar16 = (pcVar19->u34).class_syms;
        if (pcVar16 == (c2_bitvec *)0x0) {
          pcVar16 = g_alias_class_symbol_sets[3];
        }
        bitvec_or(pcVar11,pcVar16);
        if (oa != 0) {
          bitvec_or(pcVar11,(c2_bitvec *)oa);
        }
        g_alias_primary_table[effect->dst_cls] = pcVar14;
      }
      uVar15 = effect->src_cls;
      if (uVar15 != 0) {
        pcVar11 = bitvec_new(8,nsyms);
        pcVar14 = effect->read;
        g_alias_class_symbol_sets[uVar15] = pcVar11;
        for (; pcVar14 != (c2_symbol_cell *)0x0; pcVar14 = pcVar14->next) {
          pcVar19 = pcVar14->sym;
          if ((pcVar19->flags5 & 2) == 0) {
            for (pcVar5 = pcVar19->storage; pcVar5 != (c2_symbol *)0x0; pcVar5 = pcVar5->part_next)
            {
              pcVar5->flags5 = pcVar5->flags5 | 2;
            }
          }
          bitvec_set(pcVar11,(pcVar19->u34).refs);
          if ((pcVar19->u30).order_prev != (c2_symbol *)0x0) {
            for (pcVar19 = ((pcVar19->u30).order_prev)->part_next; pcVar19 != (c2_symbol *)0x0;
                pcVar19 = pcVar19->part_next) {
              bitvec_set(pcVar11,(pcVar19->u34).refs);
            }
          }
        }
        pcVar19 = effect->scope;
        if ((pcVar19->u30).order_prev != (c2_symbol *)0x0) {
          pcVar14 = symbol_list_add_unique(effect->read,pcVar19,1);
          pcVar16 = (pcVar19->u34).class_syms;
          effect->read = pcVar14;
          if (pcVar16 != (c2_bitvec *)0x0) {
            bitvec_or(pcVar11,pcVar16);
          }
        }
        pcVar14 = symbol_list_add_unique(effect->read,g_alias_special_symbol,1);
        pcVar19 = g_alias_special_symbol;
        effect->read = pcVar14;
        pcVar16 = (pcVar19->u34).class_syms;
        if (pcVar16 == (c2_bitvec *)0x0) {
          pcVar16 = g_alias_class_symbol_sets[3];
        }
        bitvec_or(pcVar11,pcVar16);
        if (oa != 0) {
          bitvec_or(pcVar11,(c2_bitvec *)oa);
        }
        g_alias_primary_table[effect->src_cls] = pcVar14;
      }
      effect = effect->next;
    } while (effect != (c2_alias_memeffect *)0x0);
    pvVar10 = (void *)0x0;
  }
  for (; g_alias_eh_effect_records = pvVar10,
      g_alias_loadv_class_substitutions != (c2_alias_class_subst *)0x0;
      g_alias_loadv_class_substitutions = g_alias_loadv_class_substitutions->next) {
    uVar15 = g_alias_loadv_class_substitutions->to_cls;
    pcVar11 = bitvec_new(8,nsyms);
    pcVar9 = g_alias_loadv_class_substitutions;
    g_alias_class_symbol_sets[uVar15] = pcVar11;
    for (pcVar14 = g_alias_primary_table[pcVar9->from_cls]; pcVar14 != (c2_symbol_cell *)0x0;
        pcVar14 = pcVar14->next) {
      uVar3 = pcVar14->sym->cls;
      if ((uVar3 != '\x0e') && (uVar3 != '\f')) {
        pcVar13 = symbol_list_add_unique(g_alias_primary_table[uVar15],pcVar14->sym,1);
        n = (pcVar14->sym->u34).refs;
        g_alias_primary_table[uVar15] = pcVar13;
        bitvec_set(g_alias_class_symbol_sets[uVar15],n);
      }
    }
    pvVar10 = g_alias_eh_effect_records;
  }
  if (g_alias_seh_edge_class != 0) {
    pcVar11 = bitvec_new(8,nsyms);
    uVar15 = g_alias_seh_edge_class;
    chunk = g_symbol_chunks;
    g_alias_class_symbol_sets[g_alias_seh_edge_class] = pcVar11;
    for (; chunk != (c2_symbol_chunk *)0x0; chunk = chunk->next) {
      pcVar19 = chunk->syms;
      if (pcVar19 < chunk->cursor) {
        do {
          uVar3 = pcVar19->cls;
          if (((uVar3 != '\x10') && (pcVar19->storage == pcVar19)) &&
             ((uVar3 == '\x04' || (uVar3 == '\x05')))) {
            pcVar14 = symbol_list_add_unique(g_alias_primary_table[uVar15],pcVar19,1);
            g_alias_primary_table[g_alias_seh_edge_class] = pcVar14;
            bitvec_set(pcVar11,(pcVar19->u34).refs);
            uVar15 = g_alias_seh_edge_class;
            pcVar5 = pcVar19;
            if ((pcVar19->flags5 & 2) == 0) {
              for (; g_alias_seh_edge_class = uVar15, pcVar5 != (c2_symbol *)0x0;
                  pcVar5 = pcVar5->part_next) {
                pcVar5->flags5 = pcVar5->flags5 | 2;
                uVar15 = g_alias_seh_edge_class;
              }
            }
          }
          pcVar19 = pcVar19 + 1;
        } while (pcVar19 < chunk->cursor);
      }
    }
    pcVar14 = symbol_list_add_unique(g_alias_primary_table[uVar15],g_alias_special_symbol,1);
    g_alias_primary_table[g_alias_seh_edge_class] = pcVar14;
    bitvec_or(pcVar11,(g_alias_special_symbol->u34).class_syms);
    g_alias_seh_edge_class = 0;
  }
  if (oa != 0) {
    bitset_header_free((c2_bitvec *)oa);
  }
  return;
}

