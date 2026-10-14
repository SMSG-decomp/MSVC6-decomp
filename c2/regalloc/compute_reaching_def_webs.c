uint32_t __fastcall compute_reaching_def_webs(c2_block *last_block,uint32_t nsyms)

{
  c2_symbol_u30 *pcVar1;
  c2_block *pcVar2;
  c2_symbol *pcVar3;
  c2_operand *pcVar4;
  uint32_t uVar5;
  c2_ra_web_cell *pcVar6;
  c2_ra_web_cell *pcVar7;
  c2_block_slot cVar8;
  c2_ra_candidate *pcVar9;
  c2_symbol_cell **ppcVar10;
  c2_ra_web_cell *pcVar11;
  c2_bitset *pcVar12;
  c2_bitset *pcVar13;
  int iVar14;
  c2_ra_web_cell *new_web;
  c2_ra_web_cell *src_new_web;
  c2_symbol_cell *pcVar15;
  uint32_t uVar16;
  c2_block *block;
  c2_symbol *pcVar17;
  c2_bitset *pcVar18;
  c2_symbol *chunk_sym;
  c2_symbol *pcVar19;
  c2_symbol_cell *pcVar20;
  c2_symbol_cell *member_cell;
  c2_ra_web_cell *web;
  c2_edge *pcVar21;
  c2_symbol *open_webs;
  uint32_t next_web;
  c2_block *local_20;
  c2_bitset *local_1c;
  c2_tuple *local_18;
  c2_edge *local_14;
  c2_symbol_chunk *local_10;
  c2_bitset *scratch_set;
  c2_block *local_8;
  c2_block *local_4;
  c2_ra_web_cell *old_webs;
  c2_ra_candidate *part_cand;
  c2_ra_candidate *sym_cand;
  c2_ra_candidate *root_cand;
  c2_symbol *member;
  c2_ra_web_cell *src_old_webs;
  c2_ra_candidate *src_cand;
  c2_ra_candidate *merge_cand;
  c2_ra_candidate *const_cand;
  c2_ra_candidate *dst_const_cand;
  
  local_8 = last_block;
  pcVar12 = bitset_new(6);
  bitset_set_range(pcVar12,nsyms);
  for (; last_block != (c2_block *)0x0; last_block = last_block->prev) {
    if ((last_block->avail_in).set == (c2_bitset *)0x0) {
      pcVar13 = bitset_new(6);
      (last_block->avail_in).set = pcVar13;
      pcVar13 = bitset_new(6);
      (last_block->avail_out).set = pcVar13;
      pcVar13 = bitset_new(6);
      last_block->ue = pcVar13;
      pcVar13 = bitset_new(6);
      last_block->kill = pcVar13;
    }
    else {
      bitset_free(last_block->de);
      last_block->de = (c2_bitset *)0x0;
      bitset_clear_all(last_block->ue);
      bitset_clear_all(last_block->kill);
    }
    pcVar13 = last_block->live_in;
    pcVar18 = (last_block->avail_in).set;
    bitset_copy(pcVar18,pcVar13);
    bitset_andnot(pcVar18,pcVar12);
    bitset_and(pcVar13,pcVar12);
    pcVar13 = last_block->live_out;
    pcVar18 = (last_block->avail_out).set;
    bitset_copy(pcVar18,pcVar13);
    bitset_andnot(pcVar18,pcVar12);
    bitset_and(pcVar13,pcVar12);
  }
  bitset_free(pcVar12);
  for (local_10 = g_symbol_chunks; local_10 != (c2_symbol_chunk *)0x0; local_10 = local_10->next) {
    scratch_set = (c2_bitset *)local_10->cursor;
    chunk_sym = local_10->syms;
    if (chunk_sym < scratch_set) {
      do {
        if (((chunk_sym->cls != '\x10') &&
            (root_cand = (chunk_sym->u30).ra, root_cand != (c2_ra_candidate *)0x0)) &&
           (pcVar12 = root_cand->part_ids, pcVar12 != (c2_bitset *)0x0)) {
          for (pcVar17 = chunk_sym->storage; pcVar17 != (c2_symbol *)0x0;
              pcVar17 = pcVar17->part_next) {
            part_cand = (pcVar17->u30).ra;
            if (((part_cand != (c2_ra_candidate *)0x0) && (part_cand->id != 0)) &&
               (part_cand->defs == 0)) {
              bitset_clear(pcVar12,part_cand->id);
            }
          }
          if (pcVar12->chunks == (c2_bitset_chunk *)0x0) {
            bitset_free(pcVar12);
            root_cand->part_ids = (c2_bitset *)0x0;
          }
        }
        chunk_sym = chunk_sym + 1;
      } while (chunk_sym < scratch_set);
    }
  }
  scratch_set = bitset_new(6);
  open_webs = (c2_symbol *)0x0;
  next_web = 1;
  pcVar12 = bitset_new(6);
  local_8->set28 = pcVar12;
  block = local_8;
LAB_107182e4:
  local_1c = block->ue;
  local_10 = (c2_symbol_chunk *)block->kill;
  if (block->loop == (c2_loop *)0x0) {
    local_14 = (c2_edge *)0x0;
  }
  else {
    local_14 = (c2_edge *)block->loop->candidates;
  }
  local_18 = block->end;
  local_20 = block;
  if (local_18 != block->head) {
    do {
      if ((local_18->flags & 1) != 0) {
        for (pcVar4 = local_18->dst; pcVar4 != (c2_operand *)0x0; pcVar4 = pcVar4->next) {
          if (pcVar4->kind == '\x01') {
            if ((pcVar4->u18).reg == &g_register_candidate_home) {
              pcVar19 = (pcVar4->sym->u34).parent;
              pcVar17 = pcVar4->sym;
              if (pcVar19 != (c2_symbol *)0x0) {
                pcVar17 = pcVar19;
              }
              if (pcVar17->cls != '\r') {
                sym_cand = (pcVar17->u30).ra;
                if (sym_cand->web == 0) {
                  new_web = arena_alloc(4,8);
                  pcVar12 = bitset_new(6);
                  new_web->defs = pcVar12;
                  bitset_set(pcVar12,next_web);
                  old_webs = (sym_cand->u0c).webs;
                  (sym_cand->u0c).webs = new_web;
                  new_web->next = old_webs;
                  sym_cand->web = next_web;
                  next_web = next_web + 1;
                  pcVar17->order_next = open_webs;
                  if (open_webs != (c2_symbol *)0x0) {
                    (((open_webs->u30).ra)->u10).prev_open = pcVar17;
                  }
                  sym_cand = (pcVar17->u30).ra;
                  (sym_cand->u10).prev_open = (c2_symbol *)0x0;
                  open_webs = pcVar17;
                }
                pcVar4->rank = sym_cand->web;
                if ((pcVar4->flags & 0xf) == 0) {
                  sym_cand->web = 0;
                  if (pcVar17 == open_webs) {
                    open_webs = pcVar17->order_next;
                    if (open_webs != (c2_symbol *)0x0) {
                      (((open_webs->u30).ra)->u10).last_def = (c2_tuple *)0x0;
                    }
                  }
                  else {
                    pcVar19 = (sym_cand->u10).prev_open;
                    pcVar3 = pcVar17->order_next;
                    pcVar19->order_next = pcVar3;
                    if (pcVar3 != (c2_symbol *)0x0) {
                      (((pcVar3->u30).ra)->u10).prev_open = pcVar19;
                    }
                  }
                }
                uVar5 = sym_cand->id;
                bitset_clear(local_1c,uVar5);
                bitset_set((c2_bitset *)local_10,uVar5);
                pcVar19 = pcVar17->storage;
                pcVar3 = pcVar19->part_next;
                goto joined_r0x10718454;
              }
              dst_const_cand = (pcVar17->u30).ra;
              pcVar4->rank = 0;
              (pcVar4->u18).range = (c2_live_range *)dst_const_cand->u0c;
            }
          }
          else if (pcVar4->kind == '\x02') {
            pcVar17 = pcVar4->sym;
            if (((pcVar17->u30).ra != (c2_ra_candidate *)0x0) &&
               (uVar5 = ((pcVar17->u30).ra)->id, uVar5 != 0)) {
              bitset_clear(local_1c,uVar5);
              bitset_set((c2_bitset *)local_10,uVar5);
            }
            pcVar19 = pcVar17->storage;
            pcVar3 = pcVar19->part_next;
joined_r0x10718454:
            if (pcVar3 != (c2_symbol *)0x0) {
              for (pcVar19 = pcVar19->storage; pcVar19 != (c2_symbol *)0x0;
                  pcVar19 = pcVar19->part_next) {
                if (pcVar17 != pcVar19) {
                  if ((((pcVar17->offset <= pcVar19->offset) &&
                       (pcVar19->size + pcVar19->offset <= pcVar17->size + pcVar17->offset)) &&
                      ((pcVar19->u30).ra != (c2_ra_candidate *)0x0)) &&
                     (uVar5 = ((pcVar19->u30).ra)->id, uVar5 != 0)) {
                    bitset_clear(local_1c,uVar5);
                    bitset_set((c2_bitset *)local_10,uVar5);
                  }
                }
              }
            }
          }
        }
        pcVar21 = local_14;
        for (pcVar4 = local_18->src; local_14 = pcVar21, pcVar4 != (c2_operand *)0x0;
            pcVar4 = pcVar4->next) {
          switch(pcVar4->kind) {
          case '\x01':
            if ((pcVar4->u18).reg == &g_register_candidate_home) {
              pcVar17 = (pcVar4->sym->u34).parent;
              pcVar19 = pcVar4->sym;
              if (pcVar17 != (c2_symbol *)0x0) {
                pcVar19 = pcVar17;
              }
              if (pcVar19->cls == '\r') {
                const_cand = (pcVar19->u30).ra;
                pcVar4->rank = 0;
                const_cand->web = const_cand->web + 1;
                (pcVar4->u18).range = (c2_live_range *)const_cand->u0c;
              }
              else {
                src_cand = (pcVar19->u30).ra;
                if (src_cand->web == 0) {
                  src_new_web = arena_alloc(4,8);
                  pcVar12 = bitset_new(6);
                  src_new_web->defs = pcVar12;
                  bitset_set(pcVar12,next_web);
                  src_old_webs = (src_cand->u0c).webs;
                  (src_cand->u0c).webs = src_new_web;
                  src_new_web->next = src_old_webs;
                  src_cand->web = next_web;
                  next_web = next_web + 1;
                  pcVar19->order_next = open_webs;
                  if (open_webs != (c2_symbol *)0x0) {
                    (((open_webs->u30).ra)->u10).prev_open = pcVar19;
                  }
                  src_cand = (pcVar19->u30).ra;
                  (src_cand->u10).last_def = (c2_tuple *)0x0;
                  open_webs = pcVar19;
                }
                pcVar4->rank = src_cand->web;
              }
            }
            break;
          case '\x02':
            pcVar17 = pcVar4->sym;
            for (pcVar19 = pcVar17->storage; pcVar19 != (c2_symbol *)0x0;
                pcVar19 = pcVar19->part_next) {
              if (pcVar17 == pcVar19) {
LAB_1071860f:
                pcVar9 = (pcVar19->u30).ra;
                if ((pcVar9 != (c2_ra_candidate *)0x0) &&
                   (((uVar5 = pcVar9->id, uVar5 != 0 && (0 < pcVar9->defs)) &&
                    (bitset_set(local_1c,uVar5), pcVar21 != (c2_edge *)0x0)))) {
                  bitset_set((c2_bitset *)pcVar21,uVar5);
                }
              }
              else if ((pcVar17->offset < pcVar19->size + pcVar19->offset) &&
                      (pcVar19->offset < pcVar17->size + pcVar17->offset)) goto LAB_1071860f;
            }
            break;
          case '\x06':
            pcVar17 = (c2_symbol *)pcVar4->tag;
            goto LAB_1071866a;
          case '\v':
            pcVar17 = pcVar4->sym;
LAB_1071866a:
            pcVar15 = alias_class_members((uint32_t)pcVar17);
            pcVar20 = (c2_symbol_cell *)0x0;
            pcVar21 = local_14;
joined_r0x10718675:
            local_14 = pcVar21;
            if (pcVar15 != (c2_symbol_cell *)0x0) {
              do {
                member = pcVar15->sym;
                member_cell = pcVar15;
                if (member->cls == '\f') {
                  member_cell = (member->u30).members;
                  pcVar20 = pcVar15;
                  if (member_cell == (c2_symbol_cell *)0x0) {
                    pcVar15 = pcVar15->next;
                    pcVar21 = local_14;
                    goto joined_r0x10718675;
                  }
                  member = member_cell->sym;
                }
                if ((((member->u30).ra != (c2_ra_candidate *)0x0) &&
                    (pcVar12 = ((member->u30).ra)->part_ids, pcVar12 != (c2_bitset *)0x0)) &&
                   (bitset_or(local_1c,pcVar12), pcVar21 != (c2_edge *)0x0)) {
                  bitset_or((c2_bitset *)pcVar21,pcVar12);
                }
                pcVar15 = member_cell->next;
              } while (pcVar15 != (c2_symbol_cell *)0x0);
              if (pcVar20 == (c2_symbol_cell *)0x0) break;
              ppcVar10 = &pcVar20->next;
              pcVar20 = (c2_symbol_cell *)0x0;
              pcVar15 = *ppcVar10;
              pcVar21 = local_14;
              goto joined_r0x10718675;
            }
          }
          pcVar21 = local_14;
        }
      }
      local_18 = local_18->prev;
    } while (local_18 != local_20->head);
  }
  pcVar12 = bitset_new(6);
  local_20->set24 = pcVar12;
  local_1c = pcVar12;
  for (pcVar17 = open_webs; pcVar17 != (c2_symbol *)0x0; pcVar17 = pcVar17->order_next) {
    bitset_set(pcVar12,((pcVar17->u30).ra)->web);
  }
  local_18 = (c2_tuple *)0x0;
  block = local_20->prev;
  local_4 = block;
  for (pcVar21 = local_20->preds; local_14 = pcVar21, pcVar21 != (c2_edge *)0x0;
      pcVar21 = pcVar21->next_pred) {
    pcVar2 = pcVar21->from;
    if (pcVar2 == block) {
      local_18 = (c2_tuple *)0x1;
    }
    pcVar12 = pcVar2->set28;
    if (pcVar12 == (c2_bitset *)0x0) {
      pcVar12 = bitset_clone(local_1c);
      pcVar2->set28 = pcVar12;
    }
    else {
      local_10 = (c2_symbol_chunk *)open_webs;
      if (open_webs != (c2_symbol *)0x0) {
        do {
          merge_cand = ((c2_symbol_u30 *)((int)local_10 + 0x30))->ra;
          web = (merge_cand->u0c).webs;
          if (web == (c2_ra_web_cell *)0x0) {
LAB_1078e15e:
            bitset_set(pcVar12,merge_cand->web);
          }
          else {
            do {
              iVar14 = bitset_intersects(web->defs,pcVar12);
              if (iVar14 != 0) {
                if (web == (c2_ra_web_cell *)0x0) goto LAB_1078e15e;
                uVar5 = merge_cand->web;
                uVar16 = bitset_test(web->defs,uVar5);
                if (uVar16 == 0) {
                  pcVar6 = (merge_cand->u0c).webs;
                  uVar16 = bitset_test(pcVar6->defs,uVar5);
                  pcVar11 = (c2_ra_web_cell *)&merge_cand->u0c;
                  while (uVar16 == 0) {
                    pcVar7 = ((c2_ra_candidate_u0c *)&pcVar6->next)->webs;
                    uVar16 = bitset_test(pcVar7->defs,uVar5);
                    pcVar11 = pcVar6;
                    pcVar6 = pcVar7;
                  }
                  pcVar6 = ((c2_ra_candidate_u0c *)&pcVar11->next)->webs;
                  bitset_or(web->defs,pcVar6->defs);
                  *(c2_ra_web_cell **)&pcVar11->next = pcVar6->next;
                }
                goto LAB_10718710;
              }
              web = web->next;
            } while (web != (c2_ra_web_cell *)0x0);
            bitset_set(pcVar12,merge_cand->web);
          }
LAB_10718710:
          local_10 = *(c2_symbol_chunk **)((int)local_10 + 0x2c);
        } while (local_10 != (c2_symbol_chunk *)0x0);
        local_10 = (c2_symbol_chunk *)0x0;
        block = local_4;
        pcVar21 = local_14;
      }
    }
  }
  if (block == (c2_block *)0x0) {
    bitset_free(scratch_set);
    block = local_8;
    pcVar12 = local_8->ue;
    for (pcVar15 = (g_alias_special_symbol->u30).members; pcVar15 != (c2_symbol_cell *)0x0;
        pcVar15 = pcVar15->next) {
      pcVar9 = (pcVar15->sym->u30).ra;
      if ((pcVar9 != (c2_ra_candidate *)0x0) &&
         (pcVar13 = pcVar9->part_ids, pcVar13 != (c2_bitset *)0x0)) {
        bitset_or(pcVar12,pcVar13);
      }
    }
    for (; block != (c2_block *)0x0; block = block->prev) {
      bitset_free((block->avail_in).set);
      block->avail_in = (c2_block_slot)block->live_in;
      block->live_in = (c2_bitset *)0x0;
      bitset_free((block->avail_out).set);
      cVar8 = (c2_block_slot)block->live_out;
      block->live_out = (c2_bitset *)0x0;
      block->avail_out = cVar8;
    }
    return next_web;
  }
  if (local_18 != (c2_tuple *)0x0) goto code_r0x107182c3;
  while (open_webs != (c2_symbol *)0x0) {
    pcVar1 = &open_webs->u30;
    open_webs = open_webs->order_next;
    pcVar1->ra->web = 0;
  }
  if (block->set28 == (c2_bitset *)0x0) {
    pcVar12 = bitset_new(6);
    block->set28 = pcVar12;
  }
  pcVar12 = block->set28;
  pcVar18 = (block->avail_out).set;
  open_webs = (c2_symbol *)0x0;
  goto LAB_107187f2;
code_r0x107182c3:
  pcVar12 = (block->avail_out).set;
  pcVar13 = (local_20->avail_in).set;
  iVar14 = bitset_equal(pcVar13,pcVar12);
  pcVar18 = scratch_set;
  if (iVar14 == 0) {
    bitset_copy(scratch_set,pcVar12);
    bitset_andnot(pcVar18,pcVar13);
    pcVar12 = block->set28;
LAB_107187f2:
    open_webs = merge_defs_into_web(open_webs,pcVar18,pcVar12,&next_web);
  }
  goto LAB_107182e4;
}

