void __fastcall place_split_points_for_ranges(c2_function *fn,c2_bitset *set,c2_bitset *regs)

{
  c2_bitset *dst;
  c2_edge *pcVar1;
  c2_tuple *pcVar2;
  c2_block *pcVar3;
  uint uVar4;
  uint32_t uVar5;
  c2_live_range *pcVar6;
  c2_bitset *free_regs;
  c2_bitset *spare_regs;
  c2_bitset *pcVar7;
  c2_edge *pcVar8;
  int iVar9;
  int iVar10;
  c2_block *block;
  c2_ra_region *region;
  c2_ra_region *regions;
  int region_count;
  c2_block *live_blocks;
  
  regions = (c2_ra_region *)0x0;
  uVar4 = bitset_popcount(set);
  if ((uVar4 < 3) || (g_ra_block_count < 100)) {
    uVar5 = bitset_iter_next(set);
    while (uVar5 != 0xffffffff) {
      pcVar6 = live_range_from_id(uVar5);
      place_split_points_for_range(pcVar6,regs);
      uVar5 = bitset_iter_next((c2_bitset *)0x0);
    }
  }
  else {
    free_regs = bitset_new(6);
    spare_regs = bitset_new(6);
    region_count = 0;
    block = fn->cfg->first;
    live_blocks = (c2_block *)0x0;
    pcVar3 = live_blocks;
    if (block != (c2_block *)0x0) {
LAB_1072533b:
      iVar9 = bitset_intersects(block->live,set);
      if (iVar9 != 0) {
        (block->avail_out).block = live_blocks;
        bitset_copy(free_regs,regs);
        bitset_andnot(free_regs,block->set4c);
        live_blocks = block;
        if (free_regs->chunks == (c2_bitset_chunk *)0x0) {
          uVar5 = bitset_iter_next(set);
          while (uVar5 != 0xffffffff) {
            pcVar7 = regs;
            pcVar6 = live_range_from_id(uVar5);
            place_split_points_in_block(block,pcVar6,pcVar7);
            uVar5 = bitset_iter_next((c2_bitset *)0x0);
          }
        }
        else {
          for (pcVar8 = block->preds; region = regions, pcVar8 != (c2_edge *)0x0;
              pcVar8 = pcVar8->next_pred) {
            pcVar7 = (pcVar8->from->avail_in).set;
            if (pcVar7 != (c2_bitset *)0x0) {
              if ((c2_bitset *)region_count != pcVar7) {
                iVar9 = region_count - (int)pcVar7;
                do {
                  region = region->next;
                  iVar9 = iVar9 + -1;
                } while (iVar9 != 0);
              }
              bitset_copy(spare_regs,free_regs);
              bitset_andnot(spare_regs,region->used);
              if (spare_regs->chunks != (c2_bitset_chunk *)0x0) goto LAB_1072531b;
            }
          }
          for (pcVar8 = block->succs; pcVar8 != (c2_edge *)0x0; pcVar8 = pcVar8->next_succ) {
            pcVar7 = (pcVar8->to->avail_in).set;
            if (pcVar7 != (c2_bitset *)0x0) {
              region = regions;
              if ((c2_bitset *)region_count != pcVar7) {
                iVar9 = region_count - (int)pcVar7;
                do {
                  region = region->next;
                  iVar9 = iVar9 + -1;
                } while (iVar9 != 0);
              }
              bitset_copy(spare_regs,free_regs);
              bitset_andnot(spare_regs,region->used);
              if (spare_regs->chunks != (c2_bitset_chunk *)0x0) goto LAB_1072531b;
            }
          }
          region = alloc_split_cell();
          pcVar7 = bitset_clone(block->set4c);
          region->used = pcVar7;
          region->next = regions;
          region_count = region_count + 1;
          (block->avail_in).set = (c2_bitset *)region_count;
          regions = region;
        }
      }
      goto LAB_10725331;
    }
joined_r0x1072527d:
    for (; pcVar3 != (c2_block *)0x0; pcVar3 = (pcVar3->avail_out).block) {
      pcVar7 = (pcVar3->avail_in).set;
      if (pcVar7 == (c2_bitset *)0x0) {
        pcVar2 = pcVar3->head->next;
        if (pcVar2->kind == '\x1b') {
          bitset_or((pcVar2->u14).regs,set);
        }
        else {
          insert_pressure_split_marker(pcVar3->head,(c2_bitset *)0x0,(c2_bitset *)0x0,set);
        }
        pcVar2 = pcVar3->end->prev;
        if (pcVar2->kind == '\x1b') {
          bitset_or((pcVar2->u14).regs,set);
          pcVar3->flags = pcVar3->flags | 0x40000;
        }
        else {
          insert_pressure_split_marker(pcVar2,(c2_bitset *)0x0,(c2_bitset *)0x0,set);
          pcVar3->flags = pcVar3->flags | 0x40000;
        }
      }
      else {
        pcVar1 = pcVar3->preds;
        iVar10 = 0;
        iVar9 = 0;
        pcVar8 = pcVar1;
        if (pcVar1 != (c2_edge *)0x0) {
          do {
            iVar9 = iVar9 + 1;
            if ((pcVar8->from->avail_in).set == pcVar7) {
              iVar10 = iVar10 + 1;
            }
            pcVar8 = pcVar8->next_pred;
          } while (pcVar8 != (c2_edge *)0x0);
          if (iVar10 < iVar9) {
            if (iVar10 == 0) {
              pcVar2 = pcVar3->head->next;
              if (pcVar2->kind == '\x1b') {
                bitset_or((pcVar2->u14).regs,set);
                pcVar3->flags = pcVar3->flags | 0x40000;
              }
              else {
                insert_pressure_split_marker(pcVar3->head,(c2_bitset *)0x0,(c2_bitset *)0x0,set);
                pcVar3->flags = pcVar3->flags | 0x40000;
              }
            }
            else {
              for (; pcVar1 != (c2_edge *)0x0; pcVar1 = pcVar1->next_pred) {
                block = pcVar1->from;
                if ((block->avail_in).set != pcVar7) {
                  pcVar2 = block->end->prev;
                  if (pcVar2->kind == '\x1b') {
                    bitset_or((pcVar2->u14).regs,set);
                  }
                  else {
                    insert_pressure_split_marker(pcVar2,(c2_bitset *)0x0,(c2_bitset *)0x0,set);
                  }
                  block->flags = block->flags | 0x40000;
                }
              }
            }
          }
        }
        pcVar1 = pcVar3->succs;
        iVar10 = 0;
        iVar9 = 0;
        pcVar8 = pcVar1;
        if (pcVar1 != (c2_edge *)0x0) {
          do {
            iVar9 = iVar9 + 1;
            if ((pcVar8->to->avail_in).set == pcVar7) {
              iVar10 = iVar10 + 1;
            }
            pcVar8 = pcVar8->next_succ;
          } while (pcVar8 != (c2_edge *)0x0);
          if (iVar10 < iVar9) {
            if (iVar10 == 0) {
              pcVar2 = pcVar3->end->prev;
              if (pcVar2->kind == '\x1b') {
                bitset_or((pcVar2->u14).regs,set);
                pcVar3->flags = pcVar3->flags | 0x40000;
              }
              else {
                insert_pressure_split_marker(pcVar2,(c2_bitset *)0x0,(c2_bitset *)0x0,set);
                pcVar3->flags = pcVar3->flags | 0x40000;
              }
            }
            else {
              for (; pcVar1 != (c2_edge *)0x0; pcVar1 = pcVar1->next_succ) {
                block = pcVar1->to;
                if ((block->avail_in).set != pcVar7) {
                  pcVar2 = block->head->next;
                  if (pcVar2->kind == '\x1b') {
                    bitset_or((pcVar2->u14).regs,set);
                  }
                  else {
                    insert_pressure_split_marker(block->head,(c2_bitset *)0x0,(c2_bitset *)0x0,set);
                  }
                  block->flags = block->flags | 0x40000;
                }
              }
            }
          }
        }
      }
    }
    while (live_blocks != (c2_block *)0x0) {
      block = (live_blocks->avail_out).block;
      (live_blocks->avail_in).set = (c2_bitset *)0x0;
      (live_blocks->avail_out).set = (c2_bitset *)0x0;
      live_blocks = block;
    }
    bitset_free(free_regs);
    bitset_free(spare_regs);
    if (regions != (c2_ra_region *)0x0) {
      free_split_cell_list(regions);
      return;
    }
  }
  return;
LAB_1072531b:
  dst = region->used;
  (block->avail_in).set = pcVar7;
  bitset_or(dst,block->set4c);
LAB_10725331:
  block = block->next;
  pcVar3 = live_blocks;
  if (block == (c2_block *)0x0) goto joined_r0x1072527d;
  goto LAB_1072533b;
}

