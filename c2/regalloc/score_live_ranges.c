void __fastcall score_live_ranges(c2_function *fn,int reg_class,c2_bitset *candidates)

{
  uint8_t uVar1;
  byte bVar2;
  byte bVar3;
  c2_block *block;
  c2_symbol *pcVar4;
  int iVar5;
  c2_ra_candidate *pcVar6;
  c2_node *pcVar7;
  c2_register_descriptor *pcVar8;
  c2_operand *pcVar9;
  c2_register_descriptor *pcVar10;
  c2_cse_expr *pcVar11;
  c2_live_range *pcVar12;
  c2_bitset *dst;
  c2_bitset *dst_00;
  int iVar13;
  c2_bitset *bs;
  c2_register_descriptor *pcVar14;
  c2_operand *pcVar15;
  c2_tuple *t;
  uint uVar16;
  uint32_t uVar17;
  uint32_t uVar18;
  c2_register_descriptor *local_2c;
  c2_symbol *local_20;
  int local_18;
  c2_block *local_8;
  
  local_8 = (c2_block *)0x0;
  dst = bitset_new(6);
  dst_00 = bitset_new(6);
  block = fn->cfg->first;
  do {
    if (block == (c2_block *)0x0) {
      bitset_free(dst);
      bitset_free(dst_00);
      return;
    }
    iVar13 = bitset_intersects(block->live,candidates);
    if (iVar13 != 0) {
      if (((local_8 == (c2_block *)0x0) ||
          (iVar13 = block_has_predecessor(block,local_8), iVar13 == 0)) ||
         (iVar13 = bitset_equal(block->live_in,local_8->live_out), iVar13 == 0)) {
        bitset_copy(dst,block->live_in);
        bitset_and(dst,candidates);
        uVar17 = bitset_iter_next(dst);
        local_2c = (c2_register_descriptor *)0x0;
        while (uVar17 != 0xffffffff) {
          pcVar14 = (c2_register_descriptor *)live_range_from_id(uVar17);
          pcVar14->def = (c2_tuple *)local_2c;
          uVar17 = bitset_iter_next((c2_bitset *)0x0);
          local_2c = pcVar14;
        }
      }
      bitset_copy(dst_00,block->set24);
      for (pcVar14 = local_2c; pcVar14 != (c2_register_descriptor *)0x0;
          pcVar14 = (c2_register_descriptor *)((c2_live_range_u14 *)&pcVar14->def)->queue_next) {
        if ((c2_block *)(pcVar14->u28).free_next == (c2_block *)0x0) {
          (pcVar14->u28).free_next = (c2_symbol *)block;
        }
        (pcVar14->u30).order_prev = (c2_symbol *)block;
      }
      local_20 = (c2_symbol *)0x0;
      bs = bitset_new(6);
      if (g_opt_favor_speed == 0) {
        local_18 = 1;
      }
      else {
        local_18 = 1 << ((byte)block->loop_depth & 0x1f);
      }
      t = block->head;
      if (t != block->end) {
        do {
          if ((t->flags & 1) != 0) {
            for (pcVar9 = t->src; pcVar9 != (c2_operand *)0x0; pcVar9 = pcVar9->next) {
              if ((pcVar9->kind == '\x01') && (g_type_class[pcVar9->type >> 0xc] == reg_class)) {
                pcVar4 = (c2_symbol *)((pcVar9->u18).range)->self;
                if (pcVar4->cls == '\x02') {
                  pcVar14 = *(c2_register_descriptor **)&pcVar4->type;
                  if (pcVar14 == (c2_register_descriptor *)0x0) {
                    bVar3 = pcVar4->flags5;
                    if ((bVar3 & 1) == 0) {
                      bitset_set(bs,pcVar4->id);
                    }
                    else {
                      if (t->op == 0x164) {
                        if (((g_opt_favor_speed == 0) || (block->loop == (c2_loop *)0x0)) ||
                           ((pcVar6 = (pcVar9->sym->u30).ra, pcVar6 == (c2_ra_candidate *)0x0 ||
                            (uVar17 = bitset_test(block->loop->candidates,pcVar6->id), uVar17 != 0))
                           )) {
                          iVar13 = spill_reload_cost(pcVar9->sym);
                          pcVar4->copy_equivs =
                               (c2_symbol_cell *)((int)pcVar4->copy_equivs - iVar13 * local_18);
                          pcVar4->flags5 = bVar3 | 4;
                        }
                        pcVar4->flags7 = pcVar4->flags7 + '\x01';
                      }
                      else {
                        uVar16 = can_use_memory_operand(t,pcVar9);
                        if (uVar16 == 0) {
                          uVar17 = load_saving(pcVar9->sym);
                          if (((pcVar9->flags & 0x20) != 0) &&
                             (iVar13 = operand_list_has_same_reg(pcVar9), iVar13 != 0)) {
                            pcVar4->flags7 = pcVar4->flags7 + '\x01';
                          }
                        }
                        else {
                          uVar17 = memory_operand_saving(t,pcVar9->sym);
                        }
                        bVar3 = pcVar9->flags;
                        pcVar4->copy_equivs =
                             (c2_symbol_cell *)((int)&pcVar4->copy_equivs->next + uVar17 * local_18)
                        ;
                        (pcVar4->u18).expr =
                             (c2_cse_expr *)((int)&((pcVar4->u18).expr)->next + uVar17);
                        pcVar4->offset = pcVar4->offset + 1;
                        if ((bVar3 & 0x20) == 0) {
                          pcVar4->flags5 = pcVar4->flags5 | 4;
                        }
                      }
                      bVar3 = pcVar9->flags11;
                      pcVar4->flags6 = pcVar4->flags6 | 0x10;
                      if ((((bVar3 & 0x10) != 0) && ((pcVar9->flags & 0xf) == 0)) &&
                         ((pcVar15 = find_dst_reg_operand(pcVar4,t), pcVar15 == (c2_operand *)0x0 ||
                          ((pcVar15->flags & 0xf) == 0)))) {
                        local_2c = (c2_register_descriptor *)
                                   unlink_scoring_list((c2_live_range *)local_2c,
                                                       (c2_live_range *)pcVar4);
                        pcVar4->def = (c2_tuple *)local_20;
                        pcVar4->flags6 = pcVar4->flags6 | 8;
                        local_20 = pcVar4;
                      }
                    }
                  }
                  else {
                    if ((pcVar4->flags6 & 8) == 0) {
                      pcVar4->flags6 = pcVar4->flags6 | 8;
                      pcVar4->def = (c2_tuple *)local_20;
                      local_20 = pcVar4;
                    }
                    if (((pcVar9->flags11 & 0x10) != 0) && ((pcVar9->flags & 0x80) == 0)) {
                      bitset_clear(dst_00,pcVar14->id);
                    }
                    uVar17 = t->op;
                    if (((uVar17 == 1) && (t->dst->kind == '\x01')) &&
                       (pcVar12 = (t->dst->u18).range, pcVar12->kind == '\x02')) {
                      add_register_preference(pcVar12,pcVar14);
                    }
                    if ((uVar17 == 0x12) && (t->dst->kind == '\x01')) {
                      pcVar12 = (t->dst->u18).range;
                      uVar1 = pcVar12->kind;
joined_r0x107146b1:
                      if (uVar1 == '\x02') {
                        add_register_preference(pcVar12,pcVar14);
                      }
                    }
                  }
                }
                else if (pcVar4->cls == '\x01') {
                  uVar17 = pcVar4->id;
                  uVar18 = bitset_test(g_class_allowed_sets[reg_class],uVar17);
                  if (uVar18 != 0) {
                    pcVar14 = local_2c;
                    if (pcVar9->sym->cls == '\x03') {
                      if (((pcVar9->flags11 & 0x10) != 0) && ((pcVar9->flags & 0x80) == 0)) {
                        bitset_clear(dst_00,uVar17);
                      }
                    }
                    else {
                      for (; pcVar14 != (c2_register_descriptor *)0x0;
                          pcVar14 = (c2_register_descriptor *)pcVar14->def) {
                        bitset_clear((c2_bitset *)pcVar14->size,uVar17);
                      }
                    }
                    if ((t->op == 1) && (t->dst->kind == '\x01')) {
                      pcVar12 = (t->dst->u18).range;
                      uVar1 = pcVar12->kind;
                      pcVar14 = pcVar4;
                      goto joined_r0x107146b1;
                    }
                  }
                }
              }
            }
            pcVar14 = local_2c;
            if ((t->flags12 & 2) != 0) {
              for (; pcVar14 != (c2_register_descriptor *)0x0;
                  pcVar14 = (c2_register_descriptor *)pcVar14->def) {
                pcVar14->flags6 = pcVar14->flags6 | 2;
              }
            }
            for (pcVar9 = t->dst; pcVar9 != (c2_operand *)0x0; pcVar9 = pcVar9->next) {
              if (pcVar9->kind == '\x01') {
                if (g_type_class[pcVar9->type >> 0xc] == reg_class) {
                  pcVar14 = (c2_register_descriptor *)((pcVar9->u18).range)->self;
                  if (pcVar14->cls == '\x02') {
                    pcVar8 = *(c2_register_descriptor **)&pcVar14->type;
                    if (pcVar8 == (c2_register_descriptor *)0x0) {
                      bVar3 = pcVar14->flags5;
                      if ((bVar3 & 1) == 0) {
                        bitset_set(bs,pcVar14->id);
                      }
                      else {
                        if (t->op == 0x163) {
                          iVar13 = load_saving(pcVar9->sym);
                          bVar2 = pcVar9->flags11;
                          pcVar14->copy_equivs =
                               (c2_symbol_cell *)((int)pcVar14->copy_equivs - iVar13 * local_18);
                          pcVar14->flags5 = bVar3 | 4;
                          if ((bVar2 & 0x80) != 0) {
                            pcVar14->flags6 = pcVar14->flags6 | 1;
                          }
                        }
                        else {
                          uVar16 = can_use_memory_operand(t,pcVar9);
                          if (uVar16 == 0) {
                            uVar17 = spill_reload_cost(pcVar9->sym);
                          }
                          else if ((pcVar9->flags & 0xf) == 0) {
                            uVar17 = memory_operand_saving(t,pcVar9->sym);
                          }
                          else {
                            uVar17 = 0;
                          }
                          pcVar14->copy_equivs =
                               (c2_symbol_cell *)
                               ((int)&pcVar14->copy_equivs->next + uVar17 * local_18);
                          pcVar14->offset = pcVar14->offset + 1;
                          pcVar7 = (c2_node *)(pcVar14->u38).copy_links;
                          (pcVar14->u18).expr =
                               (c2_cse_expr *)((int)&((pcVar14->u18).expr)->next + uVar17);
                          if (pcVar7 == (c2_node *)0x0) {
                            iVar13 = is_lea_of_live_ranges(t);
                            if (iVar13 == 0) {
LAB_1071489e:
                              pcVar14->flags5 = pcVar14->flags5 | 4;
                            }
                          }
                          else if (((pcVar14->flags5 & 4) == 0) &&
                                  ((pcVar7->op != t->op ||
                                   (iVar13 = compare_trees(pcVar7,(c2_node *)t), iVar13 != 0))))
                          goto LAB_1071489e;
                        }
                        if (((pcVar14->flags5 & 8) == 0) &&
                           (((pcVar9->rank == 0 ||
                             (iVar13 = tuple_has_nonweb_reg_src(t), iVar13 != 0)) ||
                            ((pcVar7 = (c2_node *)(pcVar14->u38).copy_links,
                             pcVar7 != (c2_node *)0x0 &&
                             (((pcVar7->op != t->op ||
                               (iVar13 = compare_trees(pcVar7,(c2_node *)t), iVar13 != 0)) ||
                              (t->flags12 != *(uint8_t *)((pcVar14->u38).index + 0x12))))))))) {
                          pcVar14->flags5 = pcVar14->flags5 | 8;
                        }
                        (pcVar14->u38).copy_links = (c2_copy_link *)t;
                        bitset_andnot((c2_bitset *)pcVar14->size,dst_00);
                        if ((pcVar14->u28).free_next == (c2_symbol *)0x0) {
                          (pcVar14->u28).free_next = (c2_symbol *)block;
                        }
                        bVar3 = pcVar14->flags6;
                        bVar2 = pcVar9->flags;
                        (pcVar14->u30).order_prev = (c2_symbol *)block;
                        pcVar14->flags6 = bVar3 | 0x10;
                        if ((bVar2 & 0xf) == 0) {
                          if ((bVar3 & 8) != 0) {
                            pcVar14->flags6 = bVar3 & 0xf7 | 0x10;
                            local_20 = (c2_symbol *)
                                       unlink_scoring_list((c2_live_range *)local_20,
                                                           (c2_live_range *)pcVar14);
                          }
                          pcVar14->def = (c2_tuple *)local_2c;
                          local_2c = pcVar14;
                        }
                      }
                    }
                    else {
                      if ((pcVar14->flags6 & 8) == 0) {
                        pcVar14->flags6 = pcVar14->flags6 | 8;
                        pcVar14->def = (c2_tuple *)local_20;
                        local_20 = pcVar14;
                      }
                      uVar17 = pcVar8->id;
                      bitset_set(dst_00,uVar17);
                      uVar18 = t->op;
                      if ((((uVar18 == 0x12) && (t->src->kind == '\x05')) &&
                          (pcVar15 = t->src->base, pcVar15 != (c2_operand *)0x0)) &&
                         (pcVar12 = (pcVar15->u18).range, pcVar12->kind == '\x02')) {
                        add_register_preference(pcVar12,pcVar8);
                      }
                      pcVar14 = local_2c;
                      if ((((uVar18 == 1) && (pcVar15 = t->src, pcVar15->kind == '\x01')) &&
                          ((pcVar10 = (c2_register_descriptor *)(pcVar15->u18).range,
                           pcVar10->cls == '\x02' && ((pcVar10->flags5 & 1) != 0)))) &&
                         (((t->type & 0xfff) != 1 ||
                          (((pcVar15->sym->offset & 1) == 0 && ((pcVar9->sym->offset & 1) == 0))))))
                      {
                        add_register_preference((c2_live_range *)pcVar10,pcVar8);
                        for (; pcVar14 != (c2_register_descriptor *)0x0;
                            pcVar14 = (c2_register_descriptor *)
                                      ((c2_live_range_u14 *)&pcVar14->def)->queue_next) {
                          if (pcVar14 != pcVar10) {
                            bitset_clear((c2_bitset *)pcVar14->size,uVar17);
                          }
                        }
                      }
                      else {
                        for (; pcVar14 != (c2_register_descriptor *)0x0;
                            pcVar14 = (c2_register_descriptor *)
                                      ((c2_live_range_u14 *)&pcVar14->def)->queue_next) {
                          bitset_clear((c2_bitset *)pcVar14->size,uVar17);
                        }
                      }
                    }
                  }
                  else if (pcVar14->cls == '\x01') {
                    uVar17 = pcVar14->id;
                    uVar18 = bitset_test(g_class_allowed_sets[reg_class],uVar17);
                    if (uVar18 != 0) {
                      pcVar8 = local_2c;
                      if (((t->op == 1) && (pcVar15 = t->src, pcVar15->kind == '\x01')) &&
                         (((pcVar10 = (c2_register_descriptor *)(pcVar15->u18).range,
                           pcVar10->cls == '\x02' && ((pcVar10->flags5 & 1) != 0)) &&
                          ((((pcVar15->flags11 & 0x10) != 0 ||
                            (pcVar4 = pcVar15->sym, pcVar4->storage == pcVar4)) ||
                           (iVar13 = symbol_has_no_register_overlap(pcVar4), iVar13 != 0)))))) {
                        add_register_preference((c2_live_range *)pcVar10,pcVar14);
                        for (; pcVar8 != (c2_register_descriptor *)0x0;
                            pcVar8 = (c2_register_descriptor *)
                                     ((c2_live_range_u14 *)&pcVar8->def)->queue_next) {
                          if (pcVar8 != pcVar10) {
                            bitset_clear((c2_bitset *)pcVar8->size,pcVar14->id);
                          }
                        }
                      }
                      else {
                        for (; pcVar8 != (c2_register_descriptor *)0x0;
                            pcVar8 = (c2_register_descriptor *)
                                     ((c2_live_range_u14 *)&pcVar8->def)->queue_next) {
                          bitset_clear((c2_bitset *)pcVar8->size,uVar17);
                        }
                      }
                      if ((pcVar9->sym->cls == '\x03') && ((pcVar9->flags11 & 0x10) != 0)) {
                        bitset_set(dst_00,pcVar14->id);
                      }
                    }
                  }
                }
              }
              else if ((pcVar9->kind == '\n') && (local_2c != (c2_register_descriptor *)0x0)) {
                pcVar4 = pcVar9->sym;
                pcVar14 = local_2c;
                do {
                  bitset_andnot((c2_bitset *)pcVar14->size,(c2_bitset *)pcVar4);
                  pcVar14 = (c2_register_descriptor *)
                            ((c2_live_range_u14 *)&pcVar14->def)->queue_next;
                } while (pcVar14 != (c2_register_descriptor *)0x0);
              }
            }
          }
          t = t->next;
        } while (t != block->end);
      }
      iVar13 = bitset_popcount(bs);
      bitset_free(bs);
      for (pcVar4 = local_20; pcVar14 = local_2c, pcVar4 != (c2_symbol *)0x0;
          pcVar4 = (c2_symbol *)pcVar4->def) {
        iVar13 = iVar13 + 1;
      }
      for (; pcVar14 != (c2_register_descriptor *)0x0;
          pcVar14 = (c2_register_descriptor *)((c2_live_range_u14 *)&pcVar14->def)->queue_next) {
        if ((pcVar14->flags6 & 0x10) != 0) {
          iVar13 = iVar13 + 1;
        }
      }
      iVar13 = iVar13 * local_18;
      for (; pcVar14 = local_2c, local_20 != (c2_symbol *)0x0; local_20 = (c2_symbol *)local_20->def
          ) {
        iVar5._0_2_ = local_20->type;
        iVar5._2_2_ = local_20->x12;
        if (iVar5 == 0) {
          pcVar11 = (local_20->u18).expr;
          (local_20->u18).expr = (c2_cse_expr *)0x0;
          local_20->part_next = (c2_symbol *)((int)&local_20->part_next->fe + iVar13 * (int)pcVar11)
          ;
          local_20->flags6 = local_20->flags6 & 0xef;
        }
        local_20->flags6 = local_20->flags6 & 0xf7;
      }
      for (; local_8 = block, pcVar14 != (c2_register_descriptor *)0x0;
          pcVar14 = (c2_register_descriptor *)((c2_live_range_u14 *)&pcVar14->def)->queue_next) {
        if ((pcVar14->flags6 & 0x10) == 0) {
          pcVar14->part_next = (c2_symbol *)((int)pcVar14->part_next - iVar13);
        }
        else {
          pcVar14->flags6 = pcVar14->flags6 & 0xef;
          pcVar12 = (c2_live_range *)(pcVar14->u18).expr;
          (pcVar14->u18).expr = (c2_cse_expr *)0x0;
          pcVar14->part_next = (c2_symbol *)((int)&pcVar14->part_next->fe + iVar13 * (int)pcVar12);
        }
      }
    }
    block = block->next;
  } while( true );
}

