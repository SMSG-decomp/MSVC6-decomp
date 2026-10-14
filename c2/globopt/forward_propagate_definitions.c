void __fastcall forward_propagate_definitions(c2_function *fn)

{
  uint8_t *puVar1;
  c2_list_cell_u04 *pcVar2;
  uint8_t uVar3;
  ushort uVar4;
  ushort uVar5;
  c2_list_cell *pcVar6;
  c2_list_cell_u04 cVar7;
  void *value;
  c2_bitset *bs;
  c2_symbol *pcVar8;
  c2_list_cell *pcVar9;
  bool bVar10;
  c2_list_cell **ppcVar11;
  c2_symbol_cell **ppcVar12;
  c2_block *block;
  uint32_t uVar13;
  c2_symbol *pcVar14;
  c2_list_cell *pcVar15;
  c2_symbol_cell *pcVar16;
  c2_symbol_cell *member_cell;
  c2_block *pcVar17;
  c2_edge *pcVar18;
  c2_operand *pcVar19;
  c2_list_cell *pcVar20;
  c2_tuple *pcVar21;
  c2_tuple *pcVar22;
  int iVar23;
  c2_operand *pcVar24;
  c2_const_operand *size;
  c2_block *pcVar25;
  c2_tuple *pcVar26;
  c2_symbol *pcVar27;
  c2_list_cell *pcVar28;
  c2_symbol_cell *pcVar29;
  c2_symbol *touched_syms;
  c2_list_cell *committed;
  c2_list_cell *boundary_copies;
  int back_succs;
  c2_list_cell *next_reg_cell;
  c2_list_cell *saved_entry;
  c2_list_cell *saved_cell;
  c2_tuple *use_tuple;
  c2_list_cell *reg_cell;
  
  uVar13 = bitset_iter_next(g_fwdprop_candidate_syms);
  pcVar27 = (c2_symbol *)0x0;
  while (uVar13 != 0xffffffff) {
    pcVar14 = symbol_by_id(uVar13);
    puVar1 = &(pcVar14->u30).sizeopt.width_facts;
    *puVar1 = *puVar1 | 8;
    (pcVar14->u28).free_next = pcVar27;
    uVar13 = bitset_test(g_aliased_syms,uVar13);
    (pcVar14->u30).globopt.marks =
         (ushort)(uVar13 != 0) << 4 | (pcVar14->u30).globopt.marks & 0xffef;
    uVar13 = bitset_iter_next((c2_bitset *)0x0);
    pcVar27 = pcVar14;
  }
  bitset_free(g_fwdprop_candidate_syms);
  if (pcVar27 != (c2_symbol *)0x0) {
    init_list_node_pool();
    set_tuple_block_links(fn);
    boundary_copies = (c2_list_cell *)0x0;
    pcVar25 = fn->cfg->first;
    while (block = pcVar25, block != (c2_block *)0x0) {
      pcVar25 = block->next;
      pcVar18 = block->preds;
      touched_syms = (c2_symbol *)0xffffffff;
      for (; pcVar18 != (c2_edge *)0x0; pcVar18 = pcVar18->next_pred) {
        pcVar17 = pcVar18->from;
        if (pcVar17->rpo < block->rpo) {
          reg_cell = (c2_list_cell *)&pcVar17->x74;
          for (pcVar20 = reg_cell->next; pcVar20 != (c2_list_cell *)0x0; pcVar20 = pcVar20->next) {
            pcVar14 = (pcVar20->u04).sym;
            if (pcVar14->order_next == (c2_symbol *)0x0) {
              pcVar14->order_next = touched_syms;
              touched_syms = pcVar14;
            }
            for (saved_cell = pcVar20[1].next; saved_cell != (c2_list_cell *)0x0;
                saved_cell = saved_cell->next) {
              pcVar15 = saved_cell[1].next;
              pcVar26 = (saved_cell->u04).tuple;
              pcVar9 = pcVar14->defs;
              for (pcVar6 = pcVar9; pcVar6 != (c2_list_cell *)0x0; pcVar6 = pcVar6->next) {
                pcVar28 = pcVar9;
                if ((pcVar6->u04).tuple == pcVar26) goto LAB_107282e0;
              }
              if (g_list_node_free == (c2_list_cell *)0x0) {
                refill_list_node_pool();
              }
              pcVar28 = g_list_node_free;
              ppcVar11 = &g_list_node_free->next;
              g_list_node_free = g_list_node_free->next;
              *ppcVar11 = pcVar9;
              (pcVar28->u04).tuple = pcVar26;
LAB_107282e0:
              pcVar14->defs = pcVar28;
              pcVar28[1].next = pcVar15;
            }
            for (pcVar26 = pcVar20[1].u04.tuple; pcVar26 != (c2_tuple *)0x0; pcVar26 = pcVar26->next
                ) {
              cVar7 = (c2_list_cell_u04)pcVar26->prev;
              value = (void *)pcVar26->op;
              pcVar15 = pcVar14->uses;
              iVar23 = list_contains_value(pcVar15,(int)value);
              if (iVar23 == 0) {
                pcVar15 = list_node_push(pcVar15,value);
              }
              pcVar14->uses = pcVar15;
              pcVar15[1].u04 = cVar7;
            }
          }
          uVar13 = pcVar17->x78 - 1;
          pcVar17->x78 = uVar13;
          if (uVar13 == 0) {
            for (saved_entry = reg_cell->next; saved_entry != (c2_list_cell *)0x0;
                saved_entry = saved_entry->next) {
              list_node_release_all(&saved_entry[1].next);
              list_node_release_all((c2_list_cell **)&saved_entry[1].u04.tuple);
            }
            list_node_release_all((c2_list_cell **)reg_cell);
          }
        }
      }
      pcVar14 = touched_syms;
      if ((block->preds == (c2_edge *)0x0) || (block->preds->next_pred != (c2_edge *)0x0)) {
        for (; pcVar14 != (c2_symbol *)0xffffffff; pcVar14 = pcVar14->order_next) {
          if ((((pcVar14->uses == (c2_list_cell *)0x0) ||
               (pcVar14->uses->next != (c2_list_cell *)0x0)) ||
              (pcVar14->defs == (c2_list_cell *)0x0)) ||
             (pcVar14->defs->next != (c2_list_cell *)0x0)) {
            for (pcVar20 = pcVar14->defs; pcVar20 != (c2_list_cell *)0x0; pcVar20 = pcVar20->next) {
              if (((pcVar20->u04).tuple)->flags13 != '\n') {
                ((pcVar20->u04).tuple)->flags13 = '\v';
              }
            }
          }
        }
      }
      pcVar26 = block->head->next;
      if (pcVar26 != block->end) {
        do {
          if ((pcVar26->flags & 1) == 0) {
            if (pcVar26->kind == '\x17') {
              pcVar17 = tuple_get_block(pcVar26);
              pcVar14 = pcVar27;
              do {
                pcVar20 = boundary_copies;
                if (pcVar14->cls == '\x05') {
                  uVar4 = pcVar14->type;
                  pcVar14->order_next = touched_syms;
                  pcVar19 = operand_new_sym(0x14a,uVar4,pcVar14);
                  if ((uVar4 & 0xf000) == 0x5000) {
                    size = operand_new_intconst(0x1004,uVar4 & 0xfff,0);
                    pcVar21 = tuple_new_blockop(0x16b,uVar4,pcVar19,pcVar19,size,tuple_insert_after,
                                                pcVar26);
                    pcVar21->kind = '\f';
                    pcVar21->op = 0x15b;
                  }
                  else {
                    pcVar21 = tuple_new(0x15b,uVar4,pcVar19,pcVar19,tuple_insert_after,pcVar26);
                  }
                  pcVar19 = pcVar21->dst;
                  if (g_list_node_free == (c2_list_cell *)0x0) {
                    refill_list_node_pool();
                  }
                  pcVar15 = g_list_node_free;
                  ppcVar11 = &pcVar14->defs;
                  boundary_copies = g_list_node_free;
                  pcVar2 = &g_list_node_free->u04;
                  g_list_node_free = g_list_node_free->next;
                  pcVar2->tuple = pcVar21;
                  pcVar15->next = pcVar20;
                  for (pcVar20 = *ppcVar11; pcVar20 != (c2_list_cell *)0x0; pcVar20 = pcVar20->next)
                  {
                    pcVar22 = (pcVar20->u04).tuple;
                    iVar23 = operands_same_location(pcVar19,pcVar22->dst);
                    if (iVar23 == 0) {
                      pcVar22->flags13 = '\v';
                    }
                  }
                  list_node_release_all(ppcVar11);
                  list_node_release_all(&pcVar14->uses);
                  if (pcVar21->op != 0x15b) {
                    pcVar21->flags13 = '\v';
                  }
                  pcVar20 = *ppcVar11;
                  if (g_list_node_free == (c2_list_cell *)0x0) {
                    refill_list_node_pool();
                  }
                  pcVar15 = g_list_node_free;
                  pcVar2 = &g_list_node_free->u04;
                  g_list_node_free = g_list_node_free->next;
                  pcVar2->tuple = pcVar21;
                  pcVar15->next = pcVar20;
                  *ppcVar11 = pcVar15;
                  pcVar15[1].next = (c2_list_cell *)pcVar19;
                  pcVar21->flags13 = '\v';
                  (pcVar21->u14).block = pcVar17;
                  touched_syms = pcVar14;
                }
                pcVar14 = (pcVar14->u28).free_next;
              } while (pcVar14 != (c2_symbol *)0x0);
            }
          }
          else {
            for (pcVar19 = pcVar26->src; pcVar19 != (c2_operand *)0x0; pcVar19 = pcVar19->next) {
              uVar3 = pcVar19->kind;
              if (uVar3 == '\x02') {
                pcVar14 = pcVar19->sym->storage;
                if (((pcVar14->u30).sizeopt.width_facts & 8) != 0) {
                  if (pcVar14->order_next == (c2_symbol *)0x0) {
                    pcVar14->order_next = touched_syms;
                    touched_syms = pcVar14;
                  }
                  pcVar20 = pcVar14->uses;
                  if (g_list_node_free == (c2_list_cell *)0x0) {
                    refill_list_node_pool();
                  }
                  pcVar15 = g_list_node_free;
                  pcVar2 = &g_list_node_free->u04;
                  g_list_node_free = g_list_node_free->next;
                  pcVar2->tuple = pcVar26;
                  pcVar15->next = pcVar20;
                  pcVar14->uses = pcVar15;
                  pcVar15[1].u04.tuple = (c2_tuple *)pcVar19;
                  pcVar20 = pcVar14->defs;
                  if (((pcVar20 == (c2_list_cell *)0x0) || (pcVar20->next != (c2_list_cell *)0x0))
                     || ((pcVar14->uses == (c2_list_cell *)0x0 ||
                         (pcVar14->uses->next != (c2_list_cell *)0x0)))) {
LAB_107284e4:
                    for (pcVar20 = pcVar14->defs; pcVar20 != (c2_list_cell *)0x0;
                        pcVar20 = pcVar20->next) {
                      ((pcVar20->u04).tuple)->flags13 = '\v';
                    }
                  }
                  else {
                    pcVar21 = (pcVar20->u04).tuple;
                    pcVar24 = (c2_operand *)pcVar20[1].next;
                    if (((pcVar21->flags13 == '\v') ||
                        (iVar23 = operands_same_location(pcVar24,pcVar19), iVar23 == 0)) ||
                       (pcVar24->sym->offset != pcVar19->sym->offset)) goto LAB_107284e4;
                    uVar4 = pcVar24->type;
                    if ((uVar4 & 0xf000) == 0x5000) goto LAB_107284e4;
                    uVar5 = pcVar19->type;
                    if (((uVar5 & 0xf000) == 0x5000) ||
                       (((g_opt_float_consistency != 0 || (g_opt_basic != 0)) &&
                        (((uVar4 & 0xf000) == 0x4000 || ((uVar5 & 0xf000) == 0x4000))))))
                    goto LAB_107284e4;
                    if (uVar4 != uVar5) {
                      if ((1 << (byte)(uVar4 >> 0xc) & 0xeU) == 0) {
                        if (((uVar4 & 0xf000) == 0x5000) && ((uVar5 & 0xfff) <= (uVar4 & 0xfff)))
                        goto LAB_107285c5;
                      }
                      else {
                        if ((((1 << (byte)(uVar5 >> 0xc) & 0xeU) != 0) ||
                            ((uVar5 & 0xf000) == 0x5000)) && ((uVar5 & 0xfff) <= (uVar4 & 0xfff)))
                        goto LAB_107285c5;
                      }
                      goto LAB_107284e4;
                    }
LAB_107285c5:
                    iVar23 = node_has_side_effects((c2_node *)pcVar24);
                    if (((iVar23 != 0) ||
                        (iVar23 = node_has_side_effects((c2_node *)pcVar19), iVar23 != 0)) ||
                       (iVar23 = propagation_def_use_eligible(pcVar21,pcVar26), iVar23 == 0))
                    goto LAB_107284e4;
                    pcVar20 = list_node_push((c2_list_cell *)pcVar14->visit_stamp,pcVar14);
                    pcVar14->visit_stamp = (uint32_t)pcVar20;
                    pcVar20[1].next = (c2_list_cell *)pcVar21;
                    pcVar20[1].u04.tuple = pcVar26;
                    pcVar21->flags13 = (pcVar21->flags13 != '\0') + '\n';
                  }
                  pcVar20 = pcVar14->uses;
                  if ((pcVar20 == (c2_list_cell *)0x0) || (pcVar20->next != (c2_list_cell *)0x0)) {
                    for (; pcVar20 != (c2_list_cell *)0x0; pcVar20 = pcVar20->next) {
                      *(byte *)((int)&(pcVar20[1].u04.tuple)->line + 1) =
                           *(byte *)((int)&(pcVar20[1].u04.tuple)->line + 1) & 0xef;
                    }
                  }
                }
              }
              else {
                if (uVar3 == '\x06') {
                  pcVar14 = (c2_symbol *)pcVar19->tag;
                }
                else {
                  if (uVar3 != '\v') goto LAB_10728718;
                  pcVar14 = pcVar19->sym;
                }
                pcVar16 = alias_class_members((uint32_t)pcVar14);
                pcVar29 = (c2_symbol_cell *)0x0;
joined_r0x10728430:
                if (pcVar16 != (c2_symbol_cell *)0x0) {
                  do {
                    pcVar14 = pcVar16->sym;
                    member_cell = pcVar16;
                    if (pcVar14->cls == '\f') {
                      member_cell = (pcVar14->u30).members;
                      pcVar29 = pcVar16;
                      if (member_cell == (c2_symbol_cell *)0x0) {
                        pcVar16 = pcVar16->next;
                        goto joined_r0x10728430;
                      }
                      pcVar14 = member_cell->sym;
                    }
                    if (((pcVar14->u30).sizeopt.width_facts & 8) != 0) {
                      for (pcVar20 = pcVar14->defs; pcVar20 != (c2_list_cell *)0x0;
                          pcVar20 = pcVar20->next) {
                        ((pcVar20->u04).tuple)->flags13 = '\v';
                      }
                    }
                    pcVar16 = member_cell->next;
                  } while (pcVar16 != (c2_symbol_cell *)0x0);
                  if (pcVar29 == (c2_symbol_cell *)0x0) goto LAB_10728718;
                  ppcVar12 = &pcVar29->next;
                  pcVar29 = (c2_symbol_cell *)0x0;
                  pcVar16 = *ppcVar12;
                  goto joined_r0x10728430;
                }
              }
LAB_10728718:
            }
            for (pcVar19 = pcVar26->dst; pcVar19 != (c2_operand *)0x0; pcVar19 = pcVar19->next) {
              uVar3 = pcVar19->kind;
              if (uVar3 == '\x02') {
                pcVar14 = pcVar19->sym->storage;
                if (((pcVar14->u30).sizeopt.width_facts & 8) != 0) {
                  if (pcVar14->order_next == (c2_symbol *)0x0) {
                    pcVar14->order_next = touched_syms;
                    touched_syms = pcVar14;
                  }
                  ppcVar11 = &pcVar14->defs;
                  for (pcVar20 = pcVar14->defs; pcVar20 != (c2_list_cell *)0x0;
                      pcVar20 = pcVar20->next) {
                    pcVar21 = (pcVar20->u04).tuple;
                    iVar23 = operands_same_location(pcVar19,pcVar21->dst);
                    if (iVar23 == 0) {
                      pcVar21->flags13 = '\v';
                    }
                  }
                  list_node_release_all(ppcVar11);
                  list_node_release_all(&pcVar14->uses);
                  if (pcVar26->op != 0x15b) {
                    pcVar26->flags13 = '\v';
                  }
                  pcVar20 = *ppcVar11;
                  if (g_list_node_free == (c2_list_cell *)0x0) {
                    refill_list_node_pool();
                  }
                  pcVar15 = g_list_node_free;
                  pcVar2 = &g_list_node_free->u04;
                  g_list_node_free = g_list_node_free->next;
                  pcVar2->tuple = pcVar26;
                  pcVar15->next = pcVar20;
                  *ppcVar11 = pcVar15;
                  pcVar15[1].next = (c2_list_cell *)pcVar19;
                }
              }
              else {
                if (uVar3 == '\x06') {
                  pcVar14 = (c2_symbol *)pcVar19->tag;
                }
                else {
                  if (uVar3 != '\v') goto LAB_107286a7;
                  pcVar14 = pcVar19->sym;
                }
                pcVar16 = alias_class_members((uint32_t)pcVar14);
                pcVar29 = (c2_symbol_cell *)0x0;
joined_r0x1072867c:
                if (pcVar16 != (c2_symbol_cell *)0x0) {
                  do {
                    pcVar14 = pcVar16->sym;
                    member_cell = pcVar16;
                    if (pcVar14->cls == '\f') {
                      member_cell = (pcVar14->u30).members;
                      pcVar29 = pcVar16;
                      if (member_cell == (c2_symbol_cell *)0x0) {
                        pcVar16 = pcVar16->next;
                        goto joined_r0x1072867c;
                      }
                      pcVar14 = member_cell->sym;
                    }
                    if (((pcVar14->u30).sizeopt.width_facts & 8) != 0) {
                      for (pcVar20 = pcVar14->defs; pcVar20 != (c2_list_cell *)0x0;
                          pcVar20 = pcVar20->next) {
                        ((pcVar20->u04).tuple)->flags13 = '\v';
                      }
                    }
                    pcVar16 = member_cell->next;
                  } while (pcVar16 != (c2_symbol_cell *)0x0);
                  if (pcVar29 == (c2_symbol_cell *)0x0) goto LAB_107286a7;
                  ppcVar12 = &pcVar29->next;
                  pcVar29 = (c2_symbol_cell *)0x0;
                  pcVar16 = *ppcVar12;
                  goto joined_r0x1072867c;
                }
              }
LAB_107286a7:
            }
            pcVar14 = touched_syms;
            if ((pcVar26->kind == '\x14') || (pcVar26->op == 0x187)) {
              for (; pcVar14 != (c2_symbol *)0xffffffff; pcVar14 = pcVar14->order_next) {
                for (pcVar20 = pcVar14->defs; pcVar20 != (c2_list_cell *)0x0;
                    pcVar20 = pcVar20->next) {
                  pcVar21 = (pcVar20->u04).tuple;
                  if ((pcVar21->flags13 != '\n') ||
                     (((1 << (pcVar21->src->kind & 0x1f) & 6U) != 0 &&
                      (pcVar21->src->sym->def != (c2_tuple *)0x0)))) {
                    pcVar21->flags13 = '\v';
                  }
                }
              }
            }
          }
          pcVar26 = pcVar26->next;
        } while (pcVar26 != block->end);
      }
      pcVar18 = block->succs;
      bVar10 = false;
      iVar23 = 0;
      committed = (c2_list_cell *)0x0;
      back_succs = 0;
      if (pcVar18 != (c2_edge *)0x0) {
        do {
          if ((pcVar18->to->rpo <= block->rpo) && (iVar23 = iVar23 + 1, !bVar10)) {
            committed = (c2_list_cell *)pcVar18->to->de;
            bVar10 = true;
          }
          pcVar18 = pcVar18->next_succ;
          back_succs = iVar23;
        } while (pcVar18 != (c2_edge *)0x0);
      }
      bs = block->ue;
      for (pcVar14 = touched_syms; pcVar14 != (c2_symbol *)0xffffffff; pcVar14 = pcVar14->order_next
          ) {
        uVar13 = bitset_test(bs,pcVar14->id);
        if (uVar13 != 0) {
          for (pcVar20 = pcVar14->defs; pcVar20 != (c2_list_cell *)0x0; pcVar20 = pcVar20->next) {
            if (((pcVar20->u04).tuple)->flags13 == '\n') {
              ((pcVar20->u04).tuple)->flags13 = '\v';
            }
          }
        }
        if (((pcVar14->u30).sizeopt.width_facts & 0x10) == 0) {
          if (committed != (c2_list_cell *)0x0) {
            for (pcVar8 = pcVar14->storage; pcVar8 != (c2_symbol *)0x0; pcVar8 = pcVar8->part_next)
            {
              if (pcVar8 == pcVar14) {
LAB_10728abb:
                uVar13 = bitset_test((c2_bitset *)committed,pcVar8->id);
                if (uVar13 == 0) goto LAB_10728acb;
                for (pcVar20 = pcVar14->defs; pcVar20 != (c2_list_cell *)0x0;
                    pcVar20 = pcVar20->next) {
                  ((pcVar20->u04).tuple)->flags13 = '\v';
                }
                break;
              }
              if ((pcVar8->offset < pcVar14->size + pcVar14->offset) &&
                 (pcVar14->offset < pcVar8->size + pcVar8->offset)) goto LAB_10728abb;
LAB_10728acb:
            }
          }
        }
        else {
          for (pcVar20 = pcVar14->defs; pcVar20 != (c2_list_cell *)0x0; pcVar20 = pcVar20->next) {
            ((pcVar20->u04).tuple)->flags13 = '\v';
          }
          list_node_release_all(&pcVar14->defs);
          list_node_release_all(&pcVar14->uses);
        }
      }
      iVar23 = count_successors(block);
      block->x78 = iVar23 - back_succs;
      if (iVar23 - back_succs < 1) {
        while (touched_syms != (c2_symbol *)0xffffffff) {
          pcVar14 = touched_syms->order_next;
          touched_syms->order_next = (c2_symbol *)0x0;
          list_node_release_all(&touched_syms->defs);
          list_node_release_all(&touched_syms->uses);
          touched_syms = pcVar14;
        }
      }
      else {
        while (pcVar14 = touched_syms, pcVar14 != (c2_symbol *)0xffffffff) {
          touched_syms = pcVar14->order_next;
          pcVar14->order_next = (c2_symbol *)0x0;
          if ((pcVar14->uses != (c2_list_cell *)0x0) || (pcVar14->defs != (c2_list_cell *)0x0)) {
            pcVar20 = (c2_list_cell *)block->x74;
            if (g_list_node_free == (c2_list_cell *)0x0) {
              refill_list_node_pool();
            }
            pcVar15 = g_list_node_free;
            pcVar2 = &g_list_node_free->u04;
            g_list_node_free = g_list_node_free->next;
            pcVar2->sym = pcVar14;
            pcVar15->next = pcVar20;
            block->x74 = (uint32_t)pcVar15;
            pcVar15[1].next = pcVar14->defs;
            pcVar15[1].u04 = (c2_list_cell_u04)pcVar14->uses;
            pcVar14->defs = (c2_list_cell *)0x0;
            pcVar14->uses = (c2_list_cell *)0x0;
          }
        }
      }
    }
    committed = (c2_list_cell *)0x0;
    do {
      pcVar14 = (pcVar27->u28).free_next;
      pcVar20 = (c2_list_cell *)pcVar27->visit_stamp;
      while (pcVar20 != (c2_list_cell *)0x0) {
        pcVar27->visit_stamp = (uint32_t)pcVar20->next;
        pcVar15 = pcVar20[1].next;
        pcVar26 = pcVar20[1].u04.tuple;
        pcVar19 = find_src_symbol_ref(pcVar26,pcVar27);
        if ((*(char *)((int)&pcVar15[2].next + 3) == '\n') && ((pcVar19->flags11 & 0x10) != 0)) {
          pcVar20->next = committed;
          pcVar26->flags12 = pcVar26->flags12 + '\x01';
          committed = pcVar20;
        }
        pcVar20 = (c2_list_cell *)pcVar27->visit_stamp;
      }
      pcVar27->visit_stamp = 0;
      (pcVar27->u28).free_next = (c2_symbol *)0x0;
      pcVar27 = pcVar14;
    } while (pcVar14 != (c2_symbol *)0x0);
    g_resimplify_list = (c2_list_cell *)0x0;
    while (committed != (c2_list_cell *)0x0) {
      pcVar20 = (c2_list_cell *)0x0;
      pcVar15 = committed;
joined_r0x10728c95:
      committed = pcVar20;
      if (pcVar15 != (c2_list_cell *)0x0) {
        pcVar26 = (c2_tuple *)pcVar15[1].next;
        next_reg_cell = pcVar15->next;
        if (pcVar26->flags12 == '\0') {
          use_tuple = pcVar15[1].u04.tuple;
          pcVar27 = pcVar26->dst->sym;
          use_tuple->flags12 = use_tuple->flags12 + 0xff;
          pcVar21 = clone_tuple_for_propagation
                              (pcVar26,0,(uint)((pcVar26->u14).arg == (use_tuple->u14).arg));
          pcVar15 = next_reg_cell;
          if (pcVar21 != (c2_tuple *)0x0) {
            pcVar22 = find_root_def_tuple(use_tuple);
            pcVar22 = clone_tuple_for_propagation(pcVar22,1,1);
            if (pcVar22 == (c2_tuple *)0x0) {
              node_free((c2_node *)pcVar21);
            }
            else {
              pcVar19 = find_src_symbol_ref(pcVar22,pcVar27);
              tuple_remove_src(pcVar22,pcVar19);
              bVar10 = false;
              iVar23 = range_free_of_conflicts(pcVar22,pcVar22,pcVar21);
              if ((iVar23 != 0) &&
                 ((pcVar26->next == use_tuple ||
                  (iVar23 = range_free_of_conflicts(pcVar26->next,use_tuple->prev,pcVar21),
                  iVar23 != 0)))) {
                bVar10 = true;
              }
              node_free((c2_node *)pcVar22);
              node_free((c2_node *)pcVar21);
              if (bVar10) {
                move_expression_tree_before(use_tuple,pcVar26);
                pcVar19 = (c2_operand *)node_clone((c2_node *)pcVar26->src);
                pcVar24 = find_src_symbol_ref(use_tuple,pcVar27);
                if (pcVar19->type != pcVar24->type) {
                  pcVar21 = tuple_new_unary_temp
                                      (0x15f,pcVar24->type,pcVar19,tuple_insert_before,use_tuple);
                  pcVar19 = pcVar21->dst;
                  mark_tuple_materialize(pcVar21);
                }
                if (((pcVar24->flags & 0x20) != 0) && ((1 << (pcVar19->kind & 0x1f) & 6U) == 0)) {
                  pcVar21 = tuple_new_unary_temp
                                      (0x15b,pcVar19->type,pcVar19,tuple_insert_before,use_tuple);
                  pcVar19 = pcVar21->dst;
                }
                if ((pcVar19->type & 0xf000) == 0x4000) {
                  pcVar21 = tuple_new_unary_temp
                                      (0x162,pcVar19->type,pcVar19,tuple_insert_before,use_tuple);
                  pcVar19 = pcVar21->dst;
                  pcVar21->line = use_tuple->line;
                  mark_tuple_materialize(pcVar21);
                }
                tuple_replace_src(use_tuple,pcVar24,pcVar19);
                tuple_unlink_free(pcVar26);
                pcVar15 = (c2_list_cell *)0x0;
                for (pcVar9 = g_resimplify_list; pcVar9 != (c2_list_cell *)0x0;
                    pcVar9 = pcVar9->next) {
                  if ((pcVar9->u04).tuple == pcVar26) {
                    if (pcVar15 == (c2_list_cell *)0x0) {
                      g_resimplify_list = pcVar9->next;
                    }
                    else {
                      pcVar15->next = pcVar9->next;
                    }
                    break;
                  }
                  pcVar15 = pcVar9;
                }
                pcVar26 = find_root_def_tuple(use_tuple);
                pcVar6 = g_resimplify_list;
                for (pcVar9 = g_resimplify_list; pcVar9 != (c2_list_cell *)0x0;
                    pcVar9 = pcVar9->next) {
                  pcVar15 = next_reg_cell;
                  if ((pcVar9->u04).tuple == pcVar26) goto joined_r0x10728c95;
                }
                if (g_list_node_free == (c2_list_cell *)0x0) {
                  refill_list_node_pool();
                }
                g_resimplify_list = g_list_node_free;
                ppcVar11 = &g_list_node_free->next;
                g_list_node_free = g_list_node_free->next;
                *ppcVar11 = pcVar6;
                (g_resimplify_list->u04).tuple = pcVar26;
                pcVar15 = next_reg_cell;
              }
            }
          }
        }
        else {
          pcVar15->next = pcVar20;
          pcVar20 = pcVar15;
          pcVar15 = next_reg_cell;
        }
        goto joined_r0x10728c95;
      }
    }
    while( true ) {
      if (g_resimplify_list == (c2_list_cell *)0x0) {
        pcVar26 = (c2_tuple *)0x0;
        pcVar20 = (c2_list_cell *)0x0;
      }
      else {
        pcVar20 = g_resimplify_list->next;
        pcVar26 = (g_resimplify_list->u04).tuple;
        g_resimplify_list->next = g_list_node_free;
        g_list_node_free = g_resimplify_list;
      }
      g_resimplify_list = pcVar20;
      if (pcVar26 == (c2_tuple *)0x0) break;
      pcVar26 = resimplify_tuple(pcVar26);
      mark_tree_materialize(pcVar26);
      if (pcVar26->kind == '\x11') {
        pcVar26 = pcVar26->src->next->sym->def;
        pcVar25 = tuple_get_block(pcVar26);
        simplify_tuple(pcVar26,pcVar25,fn);
      }
    }
    while (boundary_copies != (c2_list_cell *)0x0) {
      pcVar20 = boundary_copies->next;
      boundary_copies->next = g_list_node_free;
      g_list_node_free = boundary_copies;
      if ((boundary_copies->u04).tuple == (c2_tuple *)0x0) break;
      tuple_delete((boundary_copies->u04).tuple);
      boundary_copies = pcVar20;
    }
    for (pcVar26 = fn->cfg->first->head; pcVar26 != (c2_tuple *)0x0; pcVar26 = pcVar26->next) {
      if ((pcVar26->flags & 1) != 0) {
        (pcVar26->u14).arg = (void *)0x0;
      }
      if ((9 < pcVar26->flags13) && (pcVar26->flags13 < 0xc)) {
        pcVar26->flags13 = '\0';
      }
    }
    reset_list_node_pool();
  }
  return;
}

