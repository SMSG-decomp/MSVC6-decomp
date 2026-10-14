void __fastcall split_live_range_regions(c2_live_range *lr)

{
  uint8_t uVar1;
  short sVar2;
  short sVar3;
  c2_tuple *t;
  c2_block *pcVar4;
  c2_block *pcVar5;
  c2_edge *pcVar6;
  c2_operand *pcVar7;
  c2_bitset *bs;
  c2_symbol *pcVar8;
  bool bVar9;
  bool bVar10;
  c2_block *block;
  uint uVar11;
  c2_bitset *dst;
  c2_list_cell *cell;
  c2_tuple *t_00;
  uint32_t uVar12;
  c2_operand *pcVar13;
  c2_block *pcVar14;
  c2_tuple *pcVar15;
  int iVar16;
  c2_list_cell *site;
  c2_bitset *src_ranges;
  c2_list_cell *use_sites;
  uint local_20;
  uint32_t local_1c;
  c2_block *local_14;
  c2_operand *mem_src;
  c2_operand *opnd;
  c2_live_range *src_range;
  
  t = (lr->u38).def;
  block = tuple_get_block_nonnull(t);
  sVar2 = block->loop_depth;
  pcVar13 = t->src;
  iVar16 = 0;
  src_ranges = (c2_bitset *)0x0;
  mem_src = (c2_operand *)0x0;
  bVar10 = false;
  if (pcVar13 != (c2_operand *)0x0) {
    do {
      uVar1 = pcVar13->kind;
      if (uVar1 == '\x01') {
        if (pcVar13->sym->cls != '\r') {
          if (src_ranges == (c2_bitset *)0x0) {
            src_ranges = bitset_new(6);
          }
          src_range = (pcVar13->u18).range;
          bitset_set(src_ranges,src_range->id);
          if (src_range->colour == (c2_register_descriptor *)0x0) {
            if ((src_range->flags5 & 0x80) != 0) goto LAB_1074ca3d;
            iVar16 = iVar16 + 1;
          }
        }
      }
      else if (((uVar1 == '\x02') || (uVar1 == '\x06')) && (mem_src = pcVar13, uVar1 == '\x06')) {
        if (((pcVar13->base != (c2_operand *)0x0) &&
            (src_range = (pcVar13->base->u18).range, src_range->kind == '\x02')) &&
           (src_range->colour == (c2_register_descriptor *)0x0)) {
          bVar10 = true;
        }
        if (((pcVar13->index != (c2_operand *)0x0) &&
            (src_range = (pcVar13->index->u18).range, src_range->kind == '\x02')) &&
           (src_range->colour == (c2_register_descriptor *)0x0)) {
          bVar10 = true;
        }
      }
      pcVar13 = pcVar13->next;
    } while (pcVar13 != (c2_operand *)0x0);
    if (1 < iVar16) {
LAB_1074ca3d:
      bitset_free(src_ranges);
      return;
    }
  }
  block = lr->first_block;
  if (block != lr->last_block) {
    do {
      pcVar15 = block->head;
      block->flags = block->flags & 0xff2fffff;
      if (pcVar15 != block->end) {
        do {
          if ((pcVar15->flags & 1) == 0) {
            if ((pcVar15->kind == '\x1b') &&
               (uVar12 = bitset_test((pcVar15->u14).regs,lr->id), uVar12 != 0)) {
              uVar11 = block->flags & 0xffbfffff | 0x800000;
              goto LAB_1074cab4;
            }
          }
          else if ((block->flags & 0x400000) == 0) {
            pcVar13 = find_dst_reg_operand((c2_symbol *)lr,pcVar15);
            uVar11 = block->flags;
            if (pcVar13 == (c2_operand *)0x0) {
              if (((uVar11 & 0x400000) != 0) ||
                 (pcVar13 = find_src_reg_operand((c2_symbol *)lr,pcVar15),
                 pcVar13 == (c2_operand *)0x0)) goto LAB_1074ca54;
              uVar11 = block->flags;
            }
            uVar11 = uVar11 | 0x400000;
LAB_1074cab4:
            block->flags = uVar11;
          }
LAB_1074ca54:
          pcVar15 = pcVar15->next;
        } while (pcVar15 != block->end);
      }
      uVar11 = block->flags;
      if ((uVar11 & 0x400000) == 0) {
        uVar11 = uVar11 & 0xffdfffff;
      }
      else {
        uVar11 = uVar11 | 0x200000;
      }
      block->flags = uVar11;
      if (block == lr->last_block) goto LAB_1074caf4;
      block = block->next;
    } while( true );
  }
  block->flags = block->flags & 0xffefffff;
LAB_1074cb57:
  use_sites = (c2_list_cell *)0x0;
  local_14 = (c2_block *)0x0;
  do {
    uVar11 = block->flags & 0x100000;
    local_1c = bitset_test(block->live_in,lr->id);
    pcVar15 = block->head;
    sVar3 = block->loop_depth;
    local_20 = uVar11;
    if (pcVar15 != block->end) {
      do {
        if ((pcVar15->flags & 1) == 0) {
          if ((pcVar15->kind == '\x1b') &&
             (uVar12 = bitset_test((pcVar15->u14).regs,lr->id), uVar12 != 0)) {
            uVar11 = 0;
            local_20 = uVar11;
          }
        }
        else {
          if (uVar11 == 0) {
            pcVar13 = find_dst_reg_operand((c2_symbol *)lr,pcVar15);
            if (pcVar13 != (c2_operand *)0x0) {
              uVar11 = 1;
              local_20 = 1;
              local_1c = 1;
              goto LAB_1074cd9a;
            }
            for (pcVar13 = pcVar15->src; pcVar13 != (c2_operand *)0x0; pcVar13 = pcVar13->next) {
              if ((pcVar13->kind == '\x01') && ((pcVar13->u18).reg == (c2_symbol *)lr)) {
                if ((bVar10) && ((g_opt_favor_speed != 0 && (sVar2 < sVar3))))
                goto joined_r0x1074cc12;
                if (src_ranges != (c2_bitset *)0x0) {
                  bs = block->live_in;
                  uVar12 = bitset_test(bs,lr->id);
                  if (uVar12 != 0) {
                    dst = bitset_clone(src_ranges);
                    bitset_andnot(dst,bs);
                    if ((dst->chunks != (c2_bitset_chunk *)0x0) &&
                       ((((((local_14 != (c2_block *)0x0 || (pcVar15 != block->head->next)) ||
                           (block->preds->next_pred != (c2_edge *)0x0)) ||
                          ((iVar16 = bitset_intersects(block->preds->from->live_out,src_ranges),
                           iVar16 == 0 || (iVar16 = bitset_popcount(src_ranges), iVar16 != 1)))) ||
                         (pcVar7 = pcVar15->dst, pcVar7 == (c2_operand *)0x0)) ||
                        (((pcVar7->kind != '\x01' || (((pcVar7->u18).reg)->cls != '\x02')) ||
                         (uVar12 = bitset_test(src_ranges,((pcVar7->u18).reg)->id), local_14 = block
                         , uVar12 == 0)))))) {
                      bitset_free(dst);
                      goto LAB_1074ce0f;
                    }
                    bitset_free(dst);
                    uVar11 = local_20;
                  }
                }
                cell = alloc_split_cell();
                (cell->u04).tuple = pcVar15;
                cell->next = use_sites;
                use_sites = cell;
                if ((pcVar13->flags11 & 0x10) == 0) {
                  uVar11 = 1;
                  local_20 = 1;
                }
                else {
                  local_1c = 0;
                }
              }
            }
          }
          if (local_1c != 0) {
            if (src_ranges != (c2_bitset *)0x0) {
              for (pcVar13 = pcVar15->dst; pcVar13 != (c2_operand *)0x0; pcVar13 = pcVar13->next) {
                if (((pcVar13->kind == '\x01') && (((pcVar13->u18).reg)->cls == '\x02')) &&
                   (uVar12 = bitset_test(src_ranges,((pcVar13->u18).reg)->id), uVar12 != 0))
                goto LAB_1074ce0f;
              }
            }
            if (mem_src != (c2_operand *)0x0) {
              for (pcVar13 = pcVar15->dst; pcVar13 != (c2_operand *)0x0; pcVar13 = pcVar13->next) {
                iVar16 = operands_may_alias(pcVar13,mem_src);
                if (iVar16 != 0) {
joined_r0x1074cc12:
                  if (src_ranges != (c2_bitset *)0x0) {
LAB_1074ce0f:
                    bitset_free(src_ranges);
                  }
                  if (use_sites == (c2_list_cell *)0x0) {
                    return;
                  }
                  free_split_cell_list(use_sites);
                  return;
                }
              }
            }
            for (pcVar13 = pcVar15->src; pcVar13 != (c2_operand *)0x0; pcVar13 = pcVar13->next) {
              if (((pcVar13->kind == '\x01') && ((pcVar13->u18).reg == (c2_symbol *)lr)) &&
                 ((pcVar13->flags11 & 0x10) != 0)) {
                uVar11 = 0;
                local_1c = 0;
              }
              local_20 = uVar11;
            }
          }
        }
LAB_1074cd9a:
        pcVar15 = pcVar15->next;
      } while (pcVar15 != block->end);
    }
    if (block == lr->last_block) {
      if (use_sites == (c2_list_cell *)0x0) {
        if (src_ranges != (c2_bitset *)0x0) {
          bitset_free(src_ranges);
          return;
        }
      }
      else {
        cell = use_sites;
        site = use_sites;
        if (src_ranges != (c2_bitset *)0x0) {
          do {
            pcVar15 = ((cell->u04).tuple)->prev;
            uVar1 = pcVar15->kind;
            while (uVar1 != '\x19') {
              if ((pcVar15->flags & 1) != 0) {
                for (opnd = pcVar15->src; opnd != (c2_operand *)0x0; opnd = opnd->next) {
                  if (((opnd->kind == '\x01') && (((opnd->u18).reg)->cls == '\x02')) &&
                     (((opnd->flags11 & 0x10) != 0 &&
                      (uVar12 = bitset_test(src_ranges,((opnd->u18).reg)->id), uVar12 != 0)))) {
                    bitset_free(src_ranges);
                    free_split_cell_list(use_sites);
                    return;
                  }
                }
              }
              pcVar15 = pcVar15->prev;
              uVar1 = pcVar15->kind;
            }
            cell = cell->next;
          } while (cell != (c2_list_cell *)0x0);
          bitset_free(src_ranges);
        }
        do {
          t_00 = (c2_tuple *)node_clone((c2_node *)t);
          pcVar15 = (site->u04).tuple;
          pcVar13 = t_00->src;
          t_00->line = pcVar15->line;
          for (; pcVar13 != (c2_operand *)0x0; pcVar13 = pcVar13->next) {
            if ((pcVar13->kind == '\x01') && (pcVar13->sym->cls == '\r')) {
              pcVar13 = tuple_replace_src_with_base_copy(t_00,pcVar13,pcVar13->sym);
            }
          }
          tuple_insert_before(pcVar15,t_00);
          block = tuple_get_block_nonnull((site->u04).tuple);
          site = site->next;
          block->flags = block->flags | 0x40000;
        } while (site != (c2_list_cell *)0x0);
        free_split_cell_list(use_sites);
        lr->flags5 = lr->flags5 | 0x10;
        if (local_14 != (c2_block *)0x0) {
          pcVar13 = t->src;
          while ((pcVar13 != (c2_operand *)0x0 &&
                 (((pcVar13->kind != '\x01' || (((pcVar13->u18).reg)->cls != '\x02')) ||
                  (pcVar13->sym->cls == '\r'))))) {
            pcVar13 = pcVar13->next;
          }
          pcVar8 = (c2_symbol *)(pcVar13->u18).range;
          bitset_set(local_14->live_in,pcVar8->id);
          if (*(c2_register_descriptor **)&pcVar8->type != (c2_register_descriptor *)0x0) {
            bitset_set(local_14->set24,(*(c2_register_descriptor **)&pcVar8->type)->id);
          }
          pcVar13 = local_14->head->next->src;
          if (pcVar13 != (c2_operand *)0x0) {
            while ((pcVar13->kind != '\x01' || ((pcVar13->u18).reg != pcVar8))) {
              pcVar13 = pcVar13->next;
              if (pcVar13 == (c2_operand *)0x0) {
                return;
              }
            }
            pcVar13->flags11 = pcVar13->flags11 | 0x10;
          }
        }
      }
      return;
    }
    block = block->next;
  } while( true );
LAB_1074caf4:
  block = lr->first_block;
  pcVar4 = lr->last_block;
  pcVar5 = block->next;
LAB_1074cb00:
  bVar9 = false;
  pcVar14 = pcVar5;
  do {
    uVar11 = pcVar14->flags;
    if ((uVar11 & 0x100000) == 0) {
      for (pcVar6 = pcVar14->preds; pcVar6 != (c2_edge *)0x0; pcVar6 = pcVar6->next_pred) {
        if ((pcVar6->from->flags & 0x200000) == 0) {
          if (pcVar6 != (c2_edge *)0x0) goto LAB_1074cb0f;
          break;
        }
      }
      pcVar14->flags = uVar11 | 0x100000;
      if ((uVar11 & 0x800000) == 0) {
        bVar9 = true;
        pcVar14->flags = uVar11 | 0x300000;
      }
    }
LAB_1074cb0f:
    if (pcVar14 == pcVar4) break;
    pcVar14 = pcVar14->next;
  } while( true );
  if (!bVar9) goto LAB_1074cb57;
  goto LAB_1074cb00;
}

