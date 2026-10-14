void __fastcall build_live_ranges(c2_function *fn)

{
  byte *pbVar1;
  ushort uVar2;
  c2_loop *loop;
  c2_cfg *pcVar3;
  c2_bitset *pcVar4;
  c2_bitset *pcVar5;
  c2_bitset *bs;
  c2_live_range *pcVar6;
  c2_symbol *pcVar7;
  c2_symbol *pcVar8;
  c2_operand *pcVar9;
  c2_ra_candidate *pcVar10;
  c2_symbol_cell **ppcVar11;
  uint32_t uVar12;
  uint32_t candidate_count;
  c2_live_range **web_ranges;
  c2_symbol_cell *pcVar13;
  c2_symbol *member;
  int iVar14;
  c2_symbol **hash_cursor;
  c2_symbol_cell *pcVar15;
  c2_tuple *t;
  uint32_t tuple_ordinal;
  c2_symbol_cell *member_cell;
  c2_live_range *web;
  c2_block *block;
  
  arena_reset(4);
  arena_reset(6);
  g_class_candidates[0] = bitset_new(6);
  g_class_candidates[1] = bitset_new(6);
  g_live_range_free_list = (c2_live_range *)0x0;
  g_next_live_range_id = 1;
  if (g_class_sets_initialized == 0) {
    g_class_sets_initialized = 1;
    init_register_class_sets();
  }
  empty_hook();
  clear_live_range_hash();
  hash_cursor = g_constant_symbol_hash;
  for (iVar14 = 0x40; iVar14 != 0; iVar14 = iVar14 + -1) {
    *hash_cursor = (c2_symbol *)0x0;
    hash_cursor = hash_cursor + 1;
  }
  block = fn->cfg->first;
  uVar12 = promote_immediates_to_candidates(block->head);
  g_candidate_count = uVar12 - 1;
  candidate_count = number_register_candidate_symbols(uVar12);
  g_candidate_symbols = arena_alloc(4,candidate_count * 4);
  compute_block_local_sets(block,candidate_count);
  solve_block_liveness(fn->cfg->last);
  solve_availability(block,1);
  intersect_live_with_avail(block);
  if (((fn->flags & 0x10000) == 0) && ((fn->fsym->attrs & 0x1000) == 0)) {
    hoist_candidate_reloads(fn);
  }
  insert_upward_exposed_reloads(fn);
  loop = fn->loops;
  g_fp_loop_list = (c2_loop *)0x0;
  find_loop_fp_candidates(loop,candidate_count);
  pcVar3 = fn->cfg;
  uVar12 = compute_reaching_def_webs(pcVar3->last,uVar12);
  propagate_loop_live_sets(loop);
  web_ranges = arena_alloc(4,uVar12 * 4);
  create_web_live_ranges(web_ranges);
  solve_block_liveness(pcVar3->last);
  block = fn->cfg->first;
  tuple_ordinal = 0;
  do {
    if (block == (c2_block *)0x0) {
      return;
    }
    bitset_free(block->ue);
    block->ue = (c2_bitset *)0x0;
    bitset_free(block->kill);
    block->kill = (c2_bitset *)0x0;
    bitset_free(block->live_in);
    pcVar4 = block->live_out;
    pcVar5 = block->set28;
    bs = (block->avail_out).set;
    (block->avail_out).set = (c2_bitset *)0x0;
    block->live_out = bs;
    block->set28 = (c2_bitset *)0x0;
    iVar14 = bitset_iter_next(pcVar5);
    while (iVar14 != -1) {
      pcVar6 = web_ranges[iVar14];
      pcVar6->last_block = block;
      bitset_set(bs,pcVar6->id);
      iVar14 = bitset_iter_next((c2_bitset *)0x0);
    }
    bitset_free(pcVar5);
    t = block->end;
    if (t != block->head) {
      do {
        if ((t->flags & 1) != 0) {
          uVar2 = t->line;
          if (uVar2 != 0) {
            g_current_line_abs = fn->line_base + (uint)uVar2;
            g_cur_line = uVar2;
          }
          tuple_ordinal = tuple_ordinal + 1;
          for (pcVar9 = t->dst; pcVar9 != (c2_operand *)0x0; pcVar9 = pcVar9->next) {
            if (pcVar9->kind == '\x01') {
              if ((pcVar9->u18).reg == &g_register_candidate_home) {
                pcVar7 = (pcVar9->sym->u34).parent;
                member = pcVar9->sym;
                if (pcVar7 != (c2_symbol *)0x0) {
                  member = pcVar7;
                }
                web = web_ranges[pcVar9->rank];
                (pcVar9->u18).range = web;
                web->tie = tuple_ordinal;
                if (t->op == 0x163) {
                  pcVar9->rank = 0;
                }
                else {
                  uVar12 = bitset_test(pcVar4,((member->u30).ra)->id);
                  if (((uVar12 != 0) || ((pcVar9->flags11 & 8) != 0)) ||
                     ((member->storage->flags6 & 1) != 0)) {
                    pcVar9->rank = 0;
                    iVar14 = insert_live_range_spill_store(member,(c2_symbol *)web,t);
                    if (((pcVar9->flags11 & 8) != 0) || ((member->storage->flags6 & 1) != 0)) {
                      pbVar1 = (byte *)(*(int *)(iVar14 + 0x1c) + 0x11);
                      *pbVar1 = *pbVar1 | 8;
                    }
                  }
                }
                bitset_clear(pcVar4,((member->u30).ra)->id);
                pcVar7 = member->storage;
                pcVar8 = pcVar7->part_next;
joined_r0x107201cf:
                if (pcVar8 != (c2_symbol *)0x0) {
                  for (pcVar7 = pcVar7->storage; pcVar7 != (c2_symbol *)0x0;
                      pcVar7 = pcVar7->part_next) {
                    if (member != pcVar7) {
                      if (((member->offset <= pcVar7->offset) &&
                          (pcVar7->size + pcVar7->offset <= member->size + member->offset)) &&
                         (((pcVar7->u30).ra != (c2_ra_candidate *)0x0 &&
                          (uVar12 = ((pcVar7->u30).ra)->id, uVar12 != 0)))) {
                        bitset_clear(pcVar4,uVar12);
                      }
                    }
                  }
                }
              }
            }
            else if (pcVar9->kind == '\x02') {
              member = pcVar9->sym;
              if (((member->u30).ra != (c2_ra_candidate *)0x0) &&
                 (uVar12 = ((member->u30).ra)->id, uVar12 != 0)) {
                bitset_clear(pcVar4,uVar12);
              }
              pcVar7 = member->storage;
              pcVar8 = pcVar7->part_next;
              goto joined_r0x107201cf;
            }
          }
          for (pcVar9 = t->src; pcVar9 != (c2_operand *)0x0; pcVar9 = pcVar9->next) {
            switch(pcVar9->kind) {
            case '\x01':
              if ((pcVar9->u18).reg == &g_register_candidate_home) {
                uVar12 = pcVar9->rank;
                pcVar9->rank = 0;
                pcVar6 = web_ranges[uVar12];
                (pcVar9->u18).range = pcVar6;
                pcVar6->last_block = block;
              }
              break;
            case '\x02':
              member = pcVar9->sym;
              for (pcVar7 = member->storage; pcVar7 != (c2_symbol *)0x0; pcVar7 = pcVar7->part_next)
              {
                if (member == pcVar7) {
LAB_10720322:
                  pcVar10 = (pcVar7->u30).ra;
                  if ((pcVar10 != (c2_ra_candidate *)0x0) &&
                     ((pcVar10->id != 0 && (0 < pcVar10->defs)))) {
                    bitset_set(pcVar4,pcVar10->id);
                  }
                }
                else if ((member->offset < pcVar7->size + pcVar7->offset) &&
                        (pcVar7->offset < member->size + member->offset)) goto LAB_10720322;
              }
              break;
            case '\x06':
              member = (c2_symbol *)pcVar9->tag;
              goto LAB_10720342;
            case '\v':
              member = pcVar9->sym;
LAB_10720342:
              pcVar13 = alias_class_members((uint32_t)member);
              pcVar15 = (c2_symbol_cell *)0x0;
joined_r0x1072034d:
              if (pcVar13 != (c2_symbol_cell *)0x0) {
                do {
                  member = pcVar13->sym;
                  member_cell = pcVar13;
                  if (member->cls == '\f') {
                    member_cell = (member->u30).members;
                    pcVar15 = pcVar13;
                    if (member_cell == (c2_symbol_cell *)0x0) {
                      pcVar13 = pcVar13->next;
                      goto joined_r0x1072034d;
                    }
                    member = member_cell->sym;
                  }
                  if (((member->u30).ra != (c2_ra_candidate *)0x0) &&
                     (pcVar5 = ((member->u30).ra)->part_ids, pcVar5 != (c2_bitset *)0x0)) {
                    bitset_or(pcVar4,pcVar5);
                  }
                  pcVar13 = member_cell->next;
                } while (pcVar13 != (c2_symbol_cell *)0x0);
                if (pcVar15 == (c2_symbol_cell *)0x0) break;
                ppcVar11 = &pcVar15->next;
                pcVar15 = (c2_symbol_cell *)0x0;
                pcVar13 = *ppcVar11;
                goto joined_r0x1072034d;
              }
            }
          }
        }
        t = t->prev;
      } while (t != block->head);
    }
    bitset_free(pcVar4);
    pcVar4 = block->set24;
    pcVar5 = (block->avail_in).set;
    (block->avail_in).set = (c2_bitset *)0x0;
    block->live_in = pcVar5;
    block->set24 = (c2_bitset *)0x0;
    iVar14 = bitset_iter_next(pcVar4);
    while (iVar14 != -1) {
      pcVar6 = web_ranges[iVar14];
      pcVar6->last_block = block;
      bitset_set(pcVar5,pcVar6->id);
      iVar14 = bitset_iter_next((c2_bitset *)0x0);
    }
    bitset_free(pcVar4);
    block->flags = block->flags & 0xfffffffe;
    block = block->next;
  } while( true );
}

