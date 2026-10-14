void __fastcall collect_iv_excluded_symbols(c2_loop *loop)

{
  c2_symbol **ppcVar1;
  byte bVar2;
  c2_loop *pcVar3;
  c2_operand *pcVar4;
  c2_symbol *pcVar5;
  bool bVar6;
  c2_symbol_cell **ppcVar7;
  c2_block *pcVar8;
  uint32_t uVar9;
  c2_symbol_cell *pcVar10;
  c2_symbol *pcVar11;
  c2_symbol **ppcVar12;
  c2_symbol *pcVar13;
  int iVar14;
  c2_tuple *pcVar15;
  c2_symbol_cell *pcVar16;
  c2_symbol_cell *pcVar17;
  c2_symbol *pcVar18;
  c2_symbol *local_c [3];
  
  pcVar8 = loop->first;
  if (pcVar8 != loop->last->next) {
    do {
      pcVar3 = pcVar8->loop;
      pcVar15 = pcVar8->head->next;
      if (pcVar15 != pcVar8->end) {
        do {
          if (((pcVar15->flags & 1) != 0) && (pcVar15->flags13 != '\x11')) {
            for (pcVar4 = pcVar15->src; pcVar4 != (c2_operand *)0x0; pcVar4 = pcVar4->next) {
              bVar2 = pcVar4->kind;
              if (bVar2 == 6) {
                pcVar11 = (c2_symbol *)pcVar4->tag;
LAB_107451f0:
                pcVar10 = alias_class_members((uint32_t)pcVar11);
                pcVar16 = (c2_symbol_cell *)0x0;
joined_r0x107451fb:
                if (pcVar10 != (c2_symbol_cell *)0x0) {
                  do {
                    pcVar11 = pcVar10->sym;
                    pcVar17 = pcVar10;
                    if (pcVar11->cls == '\f') {
                      pcVar17 = (pcVar11->u30).members;
                      pcVar16 = pcVar10;
                      if (pcVar17 == (c2_symbol_cell *)0x0) {
                        pcVar10 = pcVar10->next;
                        goto joined_r0x107451fb;
                      }
                      pcVar11 = pcVar17->sym;
                    }
                    for (pcVar11 = pcVar11->storage; pcVar11 != (c2_symbol *)0x0;
                        pcVar11 = pcVar11->part_next) {
                      bitset_set(g_iv_excluded_syms,pcVar11->id);
                    }
                    pcVar10 = pcVar17->next;
                  } while (pcVar10 != (c2_symbol_cell *)0x0);
                  if (pcVar16 == (c2_symbol_cell *)0x0) goto LAB_10745382;
                  ppcVar7 = &pcVar16->next;
                  pcVar16 = (c2_symbol_cell *)0x0;
                  pcVar10 = *ppcVar7;
                  goto joined_r0x107451fb;
                }
              }
              else {
                if (bVar2 == 0xb) {
                  pcVar11 = pcVar4->sym;
                  goto LAB_107451f0;
                }
                if (((1 << (bVar2 & 0x1f) & 6U) != 0) &&
                   (pcVar4->sym->storage->fe != (c2_fe_symbol *)0x0)) {
                  uVar9 = pcVar4->sym->id;
                  bitset_set(g_aggregate_member_syms,uVar9);
                  iVar14 = node_has_side_effects((c2_node *)pcVar4);
                  if (iVar14 != 0) {
                    bitset_set(g_iv_excluded_syms,uVar9);
                  }
                }
              }
LAB_10745382:
            }
            for (pcVar4 = pcVar15->dst; pcVar4 != (c2_operand *)0x0; pcVar4 = pcVar4->next) {
              bVar2 = pcVar4->kind;
              if ((1 << (bVar2 & 0x1f) & 6U) == 0) {
                if (bVar2 == 6) {
                  pcVar11 = (c2_symbol *)pcVar4->tag;
                }
                else {
                  if (bVar2 != 0xb) goto LAB_107452d9;
                  pcVar11 = pcVar4->sym;
                }
                pcVar10 = alias_class_members((uint32_t)pcVar11);
                pcVar16 = (c2_symbol_cell *)0x0;
joined_r0x1074529b:
                if (pcVar10 != (c2_symbol_cell *)0x0) {
                  do {
                    pcVar11 = pcVar10->sym;
                    pcVar17 = pcVar10;
                    if (pcVar11->cls == '\f') {
                      pcVar17 = (pcVar11->u30).members;
                      pcVar16 = pcVar10;
                      if (pcVar17 == (c2_symbol_cell *)0x0) {
                        pcVar10 = pcVar10->next;
                        goto joined_r0x1074529b;
                      }
                      pcVar11 = pcVar17->sym;
                    }
                    for (pcVar11 = pcVar11->storage; pcVar11 != (c2_symbol *)0x0;
                        pcVar11 = pcVar11->part_next) {
                      bitset_set(g_iv_excluded_syms,pcVar11->id);
                    }
                    pcVar10 = pcVar17->next;
                  } while (pcVar10 != (c2_symbol_cell *)0x0);
                  if (pcVar16 == (c2_symbol_cell *)0x0) goto LAB_107452d9;
                  ppcVar7 = &pcVar16->next;
                  pcVar16 = (c2_symbol_cell *)0x0;
                  pcVar10 = *ppcVar7;
                  goto joined_r0x1074529b;
                }
              }
              else if (pcVar4->sym->def == (c2_tuple *)0x0) {
                uVar9 = pcVar4->sym->id;
                iVar14 = node_has_side_effects((c2_node *)pcVar4);
                if (iVar14 != 0) {
                  bitset_set(g_iv_excluded_syms,uVar9);
                }
                if (pcVar3 != loop) {
                  bitset_set(g_iv_excluded_syms,uVar9);
                }
              }
LAB_107452d9:
            }
            ppcVar12 = local_c;
            if ((pcVar15->op == 0x15b) && ((pcVar15->type & 0xf000) == 0x5000)) {
              if (pcVar15->src->kind == '\x02') {
                local_c[0] = pcVar15->src->sym;
                ppcVar12 = local_c + 1;
              }
              if (pcVar15->dst->kind == '\x02') {
                *ppcVar12 = pcVar15->dst->sym;
                ppcVar12 = ppcVar12 + 1;
              }
            }
            else if ((pcVar15->op == 0x16a) && (pcVar15->src->kind == '\x02')) {
              local_c[0] = pcVar15->src->sym;
              ppcVar12 = local_c + 1;
            }
            *ppcVar12 = (c2_symbol *)0x0;
            ppcVar12 = local_c;
            pcVar11 = local_c[0];
            while (pcVar11 != (c2_symbol *)0x0) {
              for (pcVar5 = pcVar11->storage; pcVar5 != (c2_symbol *)0x0; pcVar5 = pcVar5->part_next
                  ) {
                if (pcVar5 == pcVar11) {
LAB_10745463:
                  uVar9 = pcVar5->id;
                  bitset_set(g_iv_excluded_syms,uVar9);
                  bitset_set(g_iv_partial_alias_syms,uVar9);
                }
                else if ((pcVar5->offset < pcVar11->size + pcVar11->offset) &&
                        (pcVar11->offset < pcVar5->size + pcVar5->offset)) goto LAB_10745463;
              }
              ppcVar1 = ppcVar12 + 1;
              ppcVar12 = ppcVar12 + 1;
              pcVar11 = *ppcVar1;
            }
          }
          pcVar15 = pcVar15->next;
        } while (pcVar15 != pcVar8->end);
      }
      pcVar8 = pcVar8->next;
    } while (pcVar8 != loop->last->next);
  }
  uVar9 = bitset_iter_next(g_aggregate_member_syms);
  do {
    if (uVar9 == 0xffffffff) {
      return;
    }
    pcVar13 = symbol_by_id(uVar9);
    pcVar11 = pcVar13->storage;
    pcVar5 = pcVar11;
    if ((pcVar11->type == 0x1008) || (bVar6 = false, pcVar11->type == 0x2008)) {
      bVar6 = true;
    }
    for (; pcVar5 != (c2_symbol *)0x0; pcVar5 = pcVar5->part_next) {
      if (bVar6) {
        bitset_set(g_iv_excluded_syms,uVar9);
        bitset_set(g_iv_excluded_syms,pcVar5->id);
      }
      else {
        if (pcVar13 != pcVar5) {
          if ((pcVar5->size + pcVar5->offset <= pcVar13->offset) ||
             (pcVar13->size + pcVar13->offset <= pcVar5->offset)) goto LAB_107454e3;
        }
        if (pcVar13->offset != pcVar5->offset) {
          bitset_set(g_iv_excluded_syms,uVar9);
          bitset_set(g_iv_partial_alias_syms,uVar9);
          iVar14 = type_is_register_candidate(pcVar5->type);
          if (iVar14 != 0) {
            bitset_set(g_iv_excluded_syms,pcVar5->id);
            bitset_set(g_iv_partial_alias_syms,pcVar5->id);
            pcVar18 = pcVar11;
            do {
              if (pcVar5 == pcVar18) {
LAB_107455b5:
                iVar14 = type_is_register_candidate(pcVar18->type);
                if (iVar14 != 0) {
                  bitset_set(g_iv_excluded_syms,pcVar18->id);
                  bitset_set(g_iv_partial_alias_syms,pcVar18->id);
                }
              }
              else if ((pcVar5->offset < pcVar18->size + pcVar18->offset) &&
                      (pcVar18->offset < pcVar5->size + pcVar5->offset)) goto LAB_107455b5;
              pcVar18 = pcVar18->part_next;
            } while (pcVar18 != (c2_symbol *)0x0);
          }
        }
      }
LAB_107454e3:
    }
    uVar9 = bitset_iter_next((c2_bitset *)0x0);
  } while( true );
}

