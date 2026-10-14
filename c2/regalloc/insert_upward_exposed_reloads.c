void __fastcall insert_upward_exposed_reloads(c2_function *fn)

{
  byte bVar1;
  ushort uVar2;
  c2_operand *pcVar3;
  c2_bitset *src;
  c2_symbol *pcVar4;
  c2_symbol_cell **ppcVar5;
  c2_block *b;
  c2_bitset *bs;
  c2_bitset *dst;
  c2_tuple *pcVar6;
  uint32_t uVar7;
  c2_symbol_cell *pcVar8;
  c2_symbol *pcVar9;
  int iVar10;
  c2_tuple *pcVar11;
  c2_symbol *pcVar12;
  c2_symbol_cell *member_cell;
  uint32_t uVar13;
  c2_symbol_cell *pcVar14;
  c2_ra_candidate *def_cand;
  
  bs = bitset_new(6);
  dst = bitset_new(6);
  b = fn->cfg->first;
  do {
    if (b == (c2_block *)0x0) {
      bitset_free(bs);
      bitset_free(dst);
      return;
    }
    insert_entry_copies_on_pred_edges(fn,b,0);
    bitset_copy(dst,b->live_in);
    pcVar11 = b->head;
    if (pcVar11 != b->end) {
      do {
        if ((pcVar11->flags & 1) != 0) {
          if ((pcVar11->kind == '\x14') || (pcVar11->op == 0x187)) {
            switch(pcVar11->op) {
            case 0x187:
            case 0x194:
            case 0x196:
            case 0x198:
            case 0x19a:
            case 0x19c:
            case 0x1a5:
switchD_10717bdc_caseD_187:
              bitset_clear_all(dst);
              break;
            case 0x19d:
              if (((pcVar11->u20).cc & 1) != 0) goto switchD_10717bdc_caseD_187;
              if ((((pcVar11->u20).cc & 2) != 0) && (uVar13 = 1, g_candidate_count != 0)) {
                do {
                  bitset_clear(dst,uVar13);
                  uVar13 = uVar13 + 1;
                } while (uVar13 <= g_candidate_count);
              }
            }
          }
          uVar2 = pcVar11->line;
          if (uVar2 != 0) {
            g_current_line_abs = fn->line_base + (uint)uVar2;
            g_cur_line = uVar2;
          }
          for (pcVar3 = pcVar11->src; pcVar3 != (c2_operand *)0x0; pcVar3 = pcVar3->next) {
            if ((pcVar3->kind == '\x01') && ((pcVar3->u18).reg == &g_register_candidate_home)) {
              pcVar9 = (pcVar3->sym->u34).parent;
              pcVar12 = pcVar3->sym;
              if (pcVar9 != (c2_symbol *)0x0) {
                pcVar12 = pcVar9;
              }
              uVar13 = ((pcVar12->u30).ra)->id;
              uVar7 = bitset_test(dst,uVar13);
              if (uVar7 == 0) {
                uVar7 = bitset_test(bs,uVar13);
                if (uVar7 == 0) {
                  bitset_set(bs,uVar13);
                }
                else {
                  demote_unused_candidate_def(fn,pcVar12,pcVar11);
                  uVar2 = pcVar11->line;
                  if (uVar2 != 0) {
                    g_current_line_abs = fn->line_base + (uint)uVar2;
                    g_cur_line = uVar2;
                  }
                }
                iVar10 = is_lea_base_operand(pcVar11,pcVar3);
                if (iVar10 != 0) {
                  bitset_clear(bs,((pcVar12->u30).ra)->id);
                }
                bitset_set(dst,((pcVar12->u30).ra)->id);
                pcVar6 = insert_live_range_reload(pcVar12,&g_register_candidate_home,pcVar11);
                (((pcVar12->u30).ra)->u10).last_def = pcVar6;
              }
              else {
                bitset_clear(bs,uVar13);
              }
            }
          }
          for (pcVar3 = pcVar11->dst; pcVar3 != (c2_operand *)0x0; pcVar3 = pcVar3->next) {
            switch(pcVar3->kind) {
            case '\x01':
              if ((pcVar3->u18).reg == &g_register_candidate_home) {
                pcVar12 = (pcVar3->sym->u34).parent;
                pcVar9 = pcVar3->sym;
                if (pcVar12 != (c2_symbol *)0x0) {
                  pcVar9 = pcVar12;
                }
                uVar13 = ((pcVar9->u30).ra)->id;
                uVar7 = bitset_test(bs,uVar13);
                if (uVar7 == 0) {
                  bitset_set(bs,uVar13);
                }
                else {
                  demote_unused_candidate_def(fn,pcVar9,pcVar11);
                  uVar2 = pcVar11->line;
                  if (uVar2 != 0) {
                    g_current_line_abs = fn->line_base + (uint)uVar2;
                    g_cur_line = uVar2;
                  }
                }
                def_cand = (pcVar9->u30).ra;
                bitset_set(dst,def_cand->id);
                uVar13 = pcVar11->op;
                (def_cand->u10).last_def = pcVar11;
                if (uVar13 != 0x163) {
                  def_cand->defs = def_cand->defs + 1;
                }
                pcVar12 = pcVar9->storage;
                pcVar4 = pcVar12->part_next;
                goto joined_r0x1078e0ef;
              }
              break;
            case '\x02':
              pcVar9 = pcVar3->sym;
              if (((pcVar9->u30).ra != (c2_ra_candidate *)0x0) &&
                 (uVar13 = ((pcVar9->u30).ra)->id, uVar13 != 0)) {
                bitset_clear(dst,uVar13);
              }
              pcVar12 = pcVar9->storage;
              pcVar4 = pcVar12->part_next;
joined_r0x1078e0ef:
              if (pcVar4 != (c2_symbol *)0x0) {
                for (pcVar12 = pcVar12->storage; pcVar12 != (c2_symbol *)0x0;
                    pcVar12 = pcVar12->part_next) {
                  if (pcVar9 != pcVar12) {
                    if ((((pcVar9->offset < pcVar12->size + pcVar12->offset) &&
                         (pcVar12->offset < pcVar9->size + pcVar9->offset)) &&
                        ((pcVar12->u30).ra != (c2_ra_candidate *)0x0)) &&
                       (uVar13 = ((pcVar12->u30).ra)->id, uVar13 != 0)) {
                      bitset_clear(dst,uVar13);
                    }
                  }
                }
              }
              break;
            case '\x06':
              pcVar9 = (c2_symbol *)pcVar3->tag;
              goto LAB_10717e4f;
            case '\v':
              pcVar9 = pcVar3->sym;
LAB_10717e4f:
              pcVar8 = alias_class_members((uint32_t)pcVar9);
              pcVar14 = (c2_symbol_cell *)0x0;
joined_r0x10717e5a:
              if (pcVar8 != (c2_symbol_cell *)0x0) {
                do {
                  pcVar9 = pcVar8->sym;
                  member_cell = pcVar8;
                  if (pcVar9->cls == '\f') {
                    member_cell = (pcVar9->u30).members;
                    pcVar14 = pcVar8;
                    if (member_cell == (c2_symbol_cell *)0x0) {
                      pcVar8 = pcVar8->next;
                      goto joined_r0x10717e5a;
                    }
                    pcVar9 = member_cell->sym;
                  }
                  if (((pcVar9->u30).ra != (c2_ra_candidate *)0x0) &&
                     (src = ((pcVar9->u30).ra)->part_ids, src != (c2_bitset *)0x0)) {
                    bitset_andnot(dst,src);
                  }
                  pcVar8 = member_cell->next;
                } while (pcVar8 != (c2_symbol_cell *)0x0);
                if (pcVar14 == (c2_symbol_cell *)0x0) break;
                ppcVar5 = &pcVar14->next;
                pcVar14 = (c2_symbol_cell *)0x0;
                pcVar8 = *ppcVar5;
                goto joined_r0x10717e5a;
              }
            }
          }
        }
        pcVar11 = pcVar11->next;
      } while (pcVar11 != b->end);
    }
    bitset_andnot(bs,b->live_out);
    if (bs->chunks != (c2_bitset_chunk *)0x0) {
      iVar10 = bitset_iter_next(bs);
      while (iVar10 != -1) {
        demote_unused_candidate_def(fn,g_candidate_symbols[iVar10],(c2_tuple *)0x0);
        iVar10 = bitset_iter_next((c2_bitset *)0x0);
      }
      bitset_clear_all(bs);
      pcVar11 = pcVar11->prev;
      bVar1 = pcVar11->flags;
      while (((bVar1 & 1) == 0 && (pcVar11->kind != '\x19'))) {
        pcVar11 = pcVar11->prev;
        bVar1 = pcVar11->flags;
      }
      uVar2 = pcVar11->line;
      if (uVar2 != 0) {
        g_current_line_abs = fn->line_base + (uint)uVar2;
        g_cur_line = uVar2;
      }
    }
    b->set24 = (c2_bitset *)0x0;
    b->set28 = (c2_bitset *)0x0;
    b = b->next;
  } while( true );
}

