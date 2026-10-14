c2_bitset * __fastcall
build_interference_and_pressure_splits
          (c2_function *fn,c2_live_range *lr,int reg_class,c2_bitset *candidates,
          c2_bitset *neighbours,c2_bitset *picked,int reg_count)

{
  uint8_t uVar1;
  ushort uVar2;
  uint32_t n;
  c2_register_descriptor *pcVar3;
  c2_live_range *pcVar4;
  c2_bitset *pcVar5;
  int iVar6;
  c2_bitset *cut_regs;
  c2_bitset *live_now;
  c2_bitset *held_regs;
  c2_operand *pcVar7;
  uint32_t uVar8;
  int iVar9;
  uint uVar10;
  uint32_t uVar11;
  c2_bitset *pcVar12;
  c2_operand *opnd;
  uint32_t uVar13;
  c2_symbol *pcVar14;
  c2_tuple *pcVar15;
  c2_list_cell *split_cell;
  int iVar16;
  c2_live_range *src_range;
  c2_tuple *t;
  c2_block *block;
  int iVar17;
  bool bVar18;
  byte local_69;
  int iStack_68;
  int iStack_64;
  int iStack_60;
  int iStack_58;
  int iStack_54;
  int iStack_48;
  int local_44;
  c2_list_cell *cut_points;
  int local_38;
  int iStack_28;
  int iStack_24;
  uint local_20;
  int iStack_1c;
  c2_list_cell *remat_defs;
  uint local_8;
  c2_symbol *dst_hreg;
  c2_tuple *prev_t;
  
  remat_defs = (c2_list_cell *)0x0;
  local_69 = 0;
  local_44 = 0;
  cut_points = (c2_list_cell *)0x0;
  local_8 = 0;
  local_20 = 0;
  if ((lr->flags6 & 4) != 0) {
    ra_trim_live_range_span(lr);
  }
  n = lr->id;
  cut_regs = bitset_new(6);
  live_now = bitset_new(6);
  held_regs = bitset_new(6);
  block = lr->first_block;
  local_38 = 0;
  do {
    uVar13 = bitset_test(block->live,n);
    if (uVar13 != 0) {
      bitset_copy(live_now,block->live_out);
      bitset_copy(held_regs,block->set28);
      iStack_64 = bitset_popcount(held_regs);
      uVar13 = bitset_test(held_regs,7);
      iStack_60 = iStack_64;
      if (uVar13 != 0) {
        iStack_60 = iStack_64 + -1;
      }
      uVar13 = bitset_test(held_regs,8);
      if (uVar13 != 0) {
        iStack_60 = iStack_60 + -1;
      }
      uVar13 = bitset_test(held_regs,6);
      if (uVar13 != 0) {
        iStack_60 = iStack_60 + -1;
      }
      uVar13 = bitset_test(live_now,n);
      bVar18 = uVar13 != 0;
      if (bVar18) {
        iStack_64 = iStack_64 + 1;
      }
      t = block->end;
      if (block->end != block->head) {
        do {
          prev_t = t->prev;
          if ((t->flags & 1) != 0) {
            uVar2 = t->line;
            if (uVar2 != 0) {
              g_current_line_abs = fn->line_base + (uint)uVar2;
              g_cur_line = uVar2;
            }
            opnd = t->dst;
            iStack_68 = 0;
            iStack_54 = 0;
            iStack_58 = 0;
            iStack_48 = 0;
            iStack_28 = local_44;
            for (; opnd != (c2_operand *)0x0; opnd = opnd->next) {
              if (opnd->kind == '\x01') {
                if (g_type_class[opnd->type >> 0xc] == reg_class) {
                  pcVar14 = (c2_symbol *)(opnd->u18).range;
                  uVar1 = pcVar14->cls;
                  if (uVar1 == '\x01') {
                    dst_hreg = pcVar14->storage;
                    uVar13 = dst_hreg->id;
                    uVar11 = bitset_test(g_class_allowed_sets[reg_class],uVar13);
                    if (uVar11 != 0) {
                      if (opnd->sym->cls == '\x01') {
                        iStack_68 = iStack_68 + 1;
                        uVar13 = bitset_test(g_byte_register_set,uVar13);
                        if (uVar13 != 0) {
                          iStack_58 = iStack_58 + 1;
                        }
                      }
                      else if (((opnd->flags11 & 0x10) != 0) &&
                              (((t->op != 1 || (t->src->kind != '\x01')) ||
                               ((src_range = (t->src->u18).range, src_range->kind != '\x02' ||
                                (src_range->colour != dst_hreg)))))) {
                        bitset_clear(held_regs,uVar13);
LAB_107162da:
                        iStack_64 = iStack_64 + -1;
                        iStack_68 = iStack_68 + 1;
                        uVar13 = bitset_test(g_byte_register_set,uVar13);
                        if (uVar13 != 0) {
                          iStack_60 = iStack_60 + -1;
                          iStack_58 = iStack_58 + 1;
                        }
                      }
                    }
                  }
                  else if (uVar1 == '\x02') {
                    iVar16._0_2_ = pcVar14->type;
                    iVar16._2_2_ = pcVar14->x12;
                    if (iVar16 == 0) {
                      if (pcVar14 == (c2_symbol *)lr) {
                        pcVar7 = find_src_reg_operand(pcVar14,t);
                        if (pcVar7 == (c2_operand *)0x0) {
                          uVar13 = pcVar14->id;
                          uVar11 = bitset_test(live_now,uVar13);
                          if (uVar11 != 0) {
                            bitset_clear(live_now,uVar13);
                            iStack_64 = iStack_64 + -1;
                            iStack_68 = iStack_68 + 1;
                            bVar18 = false;
                            if (t->op == 0x163) {
                              local_8 = t->type & 0xfff;
                            }
                            uVar13 = 0;
                            if ((((t->op == 1) && (pcVar7 = t->src, pcVar7->kind == '\x01')) &&
                                (src_range = (pcVar7->u18).range, src_range->kind == '\x02')) &&
                               (((t->type & 0xfff) != 1 ||
                                (((pcVar7->sym->offset & 1) == 0 && ((opnd->sym->offset & 1) == 0)))
                                ))) {
                              if (src_range->colour == (c2_register_descriptor *)0x0) {
                                uVar11 = src_range->id;
                                uVar8 = bitset_test(neighbours,uVar11);
                                uVar13 = uVar11;
                                if (uVar8 != 0) {
                                  uVar13 = 0;
                                }
                                if (((pcVar7->flags11 & 0x10) != 0) || (uVar13 != 0)) {
                                  bitset_set(g_copy_related_ranges,uVar11);
                                }
                              }
                              else {
                                split_cell = alloc_split_cell();
                                (split_cell->u04).tuple = t;
                                split_cell->next = g_pending_copy_list;
                                g_pending_copy_list = split_cell;
                              }
                            }
                            bitset_or(neighbours,live_now);
                            if (uVar13 != 0) {
                              bitset_clear(neighbours,uVar13);
                            }
                            goto LAB_10715d35;
                          }
                          pcVar15 = tuple_new_pseudo(0x19e,opnd->type);
                          tuple_append_src(pcVar15,opnd);
                          pcVar7 = pcVar15->src;
                          pcVar7->flags = pcVar7->flags & 0xf0;
                          pcVar7->flags11 = pcVar7->flags11 | 0x10;
                          pcVar15->flags = pcVar15->flags & 0xf | 0x10;
                          tuple_insert_after(t,pcVar15);
                          opnd->rank = 0;
                        }
                        bitset_or(neighbours,live_now);
                      }
                      else {
                        uVar13 = pcVar14->id;
                        bitset_clear(live_now,uVar13);
                        if ((t->op != 0x163) &&
                           (iStack_68 = iStack_68 + 1, (pcVar14->flags5 & 0x80) != 0)) {
                          iStack_28 = 1;
                          iStack_58 = iStack_58 + 1;
                        }
                        if ((bVar18) &&
                           ((((t->op != 1 || (pcVar7 = t->src, pcVar7->kind != '\x01')) ||
                             ((pcVar7->u18).range != lr)) ||
                            (((t->type & 0xfff) == 1 &&
                             (((pcVar7->sym->offset & 1) != 0 || ((opnd->sym->offset & 1) != 0))))))
                           )) {
                          bitset_set(neighbours,uVar13);
                        }
                      }
                    }
                    else {
                      pcVar7 = find_src_reg_operand(pcVar14,t);
                      if ((pcVar7 == (c2_operand *)0x0) &&
                         ((((bitset_clear(live_now,pcVar14->id), t->op != 1 ||
                            (t->src->kind != '\x01')) ||
                           (src_range = (t->src->u18).range, src_range->kind != '\x02')) ||
                          (src_range->colour != *(c2_register_descriptor **)&pcVar14->type)))) {
                        uVar13 = *(uint32_t *)(*(int *)&pcVar14->type + 0x1c);
                        bitset_clear(held_regs,uVar13);
                        goto LAB_107162da;
                      }
                    }
                  }
                  else {
                    if (uVar1 != '\x03') {
                      ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\color.c",0xe5b);
                    }
                    if ((opnd->flags11 & 0x10) != 0) {
                      local_38 = local_38 + -1;
                      iStack_68 = iStack_68 + 1;
                      if ((pcVar14->flags5 & 0x80) != 0) {
                        local_44 = local_44 + -1;
                        iStack_58 = iStack_58 + 1;
                      }
                    }
                  }
                }
              }
              else if (opnd->kind == '\n') {
                uVar13 = bitset_iter_next((c2_bitset *)opnd->sym);
                while (uVar13 != 0xffffffff) {
                  uVar11 = bitset_test(g_class_allowed_sets[reg_class],uVar13);
                  if (uVar11 != 0) {
                    iStack_68 = iStack_68 + 1;
                    uVar13 = bitset_test(g_byte_register_set,uVar13);
                    if (uVar13 != 0) {
                      iStack_58 = iStack_58 + 1;
                    }
                  }
                  uVar13 = bitset_iter_next((c2_bitset *)0x0);
                }
              }
LAB_10715d35:
            }
            iVar16 = iStack_64 + local_38;
            iStack_1c = 0;
            iStack_24 = iStack_60 + local_44;
            split_cell = remat_defs;
            for (opnd = t->src; remat_defs = split_cell, opnd != (c2_operand *)0x0;
                opnd = opnd->next) {
              iVar17 = iStack_64;
              iVar6 = iStack_54;
              if ((opnd->kind == '\x01') && (g_type_class[opnd->type >> 0xc] == reg_class)) {
                src_range = (opnd->u18).range;
                uVar1 = src_range->kind;
                if (uVar1 == '\x01') {
                  uVar13 = src_range->self->id;
                  uVar11 = bitset_test(g_class_allowed_sets[reg_class],uVar13);
                  if ((((uVar11 != 0) && (opnd->sym->cls != '\x01')) &&
                      ((opnd->flags11 & 0x10) != 0)) &&
                     (uVar11 = bitset_test(held_regs,uVar13), uVar11 == 0)) {
                    bitset_set(held_regs,uVar13);
                    uVar13 = bitset_test(g_byte_register_set,uVar13);
joined_r0x1071613c:
                    iVar17 = iStack_64 + 1;
                    iVar6 = iStack_54 + 1;
                    if (uVar13 != 0) {
                      iStack_64 = iStack_64 + 1;
                      iStack_60 = iStack_60 + 1;
LAB_10716142:
                      iStack_54 = iStack_54 + 1;
                      iStack_48 = iStack_48 + 1;
                      iVar17 = iStack_64;
                      iVar6 = iStack_54;
                    }
                  }
                }
                else if (uVar1 == '\x02') {
                  pcVar3 = src_range->colour;
                  if (pcVar3 == (c2_register_descriptor *)0x0) {
                    if (src_range == lr) {
                      uVar13 = src_range->id;
                      uVar11 = bitset_test(live_now,uVar13);
                      if (uVar11 == 0) {
                        bitset_set(live_now,uVar13);
                        iStack_64 = iStack_64 + 1;
                        iStack_54 = iStack_54 + 1;
                        bVar18 = true;
                        if (((t->op == 1) && (t->dst->kind == '\x01')) &&
                           (pcVar14 = (t->dst->u18).reg, pcVar14->cls == '\x02')) {
                          bitset_set(g_copy_related_ranges,pcVar14->id);
                        }
                      }
                      pcVar7 = t->dst;
                      local_69 = opnd->flags11 & 7;
                      if (((pcVar7 != (c2_operand *)0x0) && (pcVar7->kind == '\x01')) &&
                         ((src_range = (pcVar7->u18).range, src_range->kind == '\x02' &&
                          (((((src_range->flags5 & 4) == 0 &&
                             (src_range->colour == (c2_register_descriptor *)0x0)) &&
                            ((src_range->u38).def == t)) &&
                           (iVar17 = operand_list_has_same_reg(opnd), iVar17 == 0)))))) {
                        remat_defs = alloc_split_cell();
                        (remat_defs->u04).tuple = t;
                        remat_defs->next = split_cell;
                      }
                      if (((t->op == 1) && ((opnd->flags11 & 0x10) == 0)) &&
                         ((opnd == t->src && (pcVar7->kind == '\x01')))) {
                        uVar1 = ((pcVar7->u18).range)->kind;
                        if (((uVar1 == '\x01') && (pcVar7->sym->cls == '\x03')) ||
                           ((uVar1 == '\x02' &&
                            (((pcVar7->u18).range)->colour != (c2_register_descriptor *)0x0)))) {
                          split_cell = alloc_split_cell();
                          (split_cell->u04).tuple = t;
                          split_cell->next = g_pending_copy_list;
                          g_pending_copy_list = split_cell;
                        }
                      }
                      uVar10 = opnd->type & 0xfff;
                      if (local_20 < uVar10) {
                        local_20 = uVar10;
                      }
                      pcVar7 = (opnd->sym->u34).lcse_values;
                      iVar17 = iStack_64;
                      iVar6 = iStack_54;
                      if (((pcVar7 != (c2_operand *)0x0) && (pcVar7->disp < opnd->sym->offset)) &&
                         (local_20 == 1)) {
                        local_20 = 2;
                      }
                    }
                    else {
                      iVar9 = operand_list_has_same_reg(opnd);
                      if (iVar9 == 0) {
                        if (((t->op != 0x164) && (opnd->sym->cls != '\r')) &&
                           (iStack_54 = iStack_54 + 1, (src_range->flags5 & 0x80) != 0)) {
                          iStack_28 = 1;
                          iStack_48 = iStack_48 + 1;
                        }
                        iVar6 = iStack_54;
                        if ((opnd->flags11 & 0x10) == 0) {
                          iStack_1c = iStack_1c + 1;
                        }
                        else {
                          bitset_set(live_now,src_range->id);
                        }
                      }
                    }
                  }
                  else {
                    uVar13 = src_range->id;
                    uVar11 = bitset_test(live_now,uVar13);
                    if (uVar11 == 0) {
                      bitset_set(live_now,uVar13);
                      uVar13 = pcVar3->id;
                      uVar11 = bitset_test(held_regs,uVar13);
                      if (uVar11 == 0) {
                        bitset_set(held_regs,uVar13);
                        uVar13 = bitset_test(g_byte_register_set,uVar13);
                        goto joined_r0x1071613c;
                      }
                    }
                  }
                }
                else {
                  if (uVar1 != '\x03') {
                    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\color.c",0xf2e);
                  }
                  if ((opnd->flags11 & 0x10) != 0) {
                    local_38 = local_38 + 1;
                    iVar6 = iStack_54 + 1;
                    if ((src_range->flags5 & 0x80) != 0) {
                      local_44 = local_44 + 1;
                      goto LAB_10716142;
                    }
                  }
                }
              }
              iStack_54 = iVar6;
              iStack_64 = iVar17;
              split_cell = remat_defs;
            }
            iVar17 = iStack_54;
            if (iStack_54 < iStack_68) {
              iVar17 = iStack_68;
            }
            iVar16 = iVar16 + iVar17;
            if (iStack_58 <= iStack_48) {
              iStack_58 = iStack_48;
            }
            iStack_24 = iStack_24 + iStack_58;
            iVar17 = iVar16 - reg_count;
            if (reg_count < iVar16) {
              iVar17 = iVar16 - reg_count;
              local_38 = local_38 - iVar17;
              iVar16 = iVar16 - iVar17;
              do {
                pcVar14 = split_local_temp_at_pressure_point(fn,reg_class,t);
                if ((pcVar14->flags5 & 0x80) != 0) {
                  local_44 = local_44 + -1;
                  iStack_24 = iStack_24 + -1;
                }
                iVar17 = iVar17 + -1;
              } while (iVar17 != 0);
              iVar17 = iVar16 - reg_count;
            }
            if ((SBORROW4(iVar16,reg_count) == iVar17 < 0) && ((t->flags12 & 1) == 0)) {
              pcVar12 = bitset_new(6);
              for (opnd = t->src; opnd != (c2_operand *)0x0; opnd = opnd->next) {
                if ((((opnd->kind == '\x01') && (pcVar14 = opnd->sym, pcVar14->cls == '\r')) &&
                    (g_type_class[opnd->type >> 0xc] == reg_class)) &&
                   ((src_range = (opnd->u18).range, src_range != lr &&
                    (src_range->colour == (c2_register_descriptor *)0x0)))) {
                  if ((opnd->flags11 & 0x10) == 0) {
                    iStack_1c = iStack_1c + -1;
                  }
                  bitset_set(pcVar12,src_range->id);
                  opnd = tuple_replace_src_with_base_copy(t,opnd,pcVar14);
                }
              }
              if ((0 < iStack_1c) && (iStack_54 - iStack_68 < iStack_1c)) {
                opnd = t->src;
                iStack_1c = iStack_1c - (iStack_54 - iStack_68);
                do {
                  src_range = (c2_live_range *)0x0;
                  for (pcVar7 = opnd; pcVar7 != (c2_operand *)0x0; pcVar7 = pcVar7->next) {
                    if ((((((pcVar7->kind == '\x01') &&
                           (pcVar4 = (pcVar7->u18).range, pcVar4->kind == '\x02')) && (pcVar4 != lr)
                          ) && ((g_type_class[pcVar7->type >> 0xc] == reg_class &&
                                (pcVar4->colour == (c2_register_descriptor *)0x0)))) &&
                        ((pcVar7->flags11 & 0x10) == 0)) &&
                       ((src_range == (c2_live_range *)0x0 ||
                        (pcVar4->priority < src_range->priority)))) {
                      src_range = pcVar4;
                    }
                  }
                  bitset_set(pcVar12,src_range->id);
                  iStack_1c = iStack_1c + -1;
                } while (iStack_1c != 0);
              }
              pcVar15 = insert_pressure_split_marker(t,live_now,picked,pcVar12);
              bitset_free(pcVar12);
              if (pcVar15 != (c2_tuple *)0x0) {
                bitset_or(cut_regs,(pcVar15->u14).regs);
                block->flags = block->flags | 0x40000;
                split_cell = alloc_split_cell();
                (split_cell->u04).tuple = t;
                split_cell->next = cut_points;
                cut_points = split_cell;
              }
              t->flags12 = t->flags12 | 1;
            }
            if ((bVar18) && (iStack_28 + local_44 != 0)) {
              if ((t->flags12 & 2) == 0) {
                if (iStack_24 == 3) {
                  pcVar12 = lr->allowed;
                  iVar16 = bitset_intersects(pcVar12,g_nonbyte_register_set);
                  if (iVar16 != 0) goto LAB_107164ce;
                  pcVar15 = ra_mark_byte_register_conflicts(t,live_now,lr);
                  if (pcVar15 != (c2_tuple *)0x0) {
                    bitset_or(cut_regs,(pcVar15->u14).regs);
                    block->flags = block->flags | 0x40000;
                    split_cell = alloc_split_cell();
                    (split_cell->u04).tuple = t;
                    split_cell->next = cut_points;
                    cut_points = split_cell;
                  }
                  pcVar5 = g_byte_register_set;
                  pcVar12 = block->set4c;
                  t->flags12 = t->flags12 | 2;
                  bitset_or(pcVar12,pcVar5);
                }
                else if (3 < iStack_24) {
                  pcVar15 = ra_mark_byte_register_conflicts(t,live_now,lr);
                  if (pcVar15 != (c2_tuple *)0x0) {
                    bitset_or(cut_regs,(pcVar15->u14).regs);
                    block->flags = block->flags | 0x40000;
                    split_cell = alloc_split_cell();
                    (split_cell->u04).tuple = t;
                    split_cell->next = cut_points;
                    cut_points = split_cell;
                  }
                  pcVar5 = g_byte_register_set;
                  pcVar12 = block->set4c;
                  t->flags12 = t->flags12 | 2;
                  bitset_or(pcVar12,pcVar5);
                }
              }
              else {
                pcVar12 = lr->allowed;
                iVar16 = bitset_intersects(pcVar12,g_nonbyte_register_set);
                if (iVar16 != 0) {
LAB_107164ce:
                  bitset_and(pcVar12,g_nonbyte_register_set);
                }
              }
            }
          }
          t = prev_t;
        } while (prev_t != block->head);
      }
      if (block == lr->last_block) {
        bitset_free(live_now);
        bitset_free(held_regs);
        if (remat_defs != (c2_list_cell *)0x0) {
          g_pressure_split_points = cut_points;
          live_now = rematerialize_candidate_definitions(remat_defs,lr);
          if (live_now != (c2_bitset *)0x0) {
            bitset_andnot(neighbours,live_now);
            bitset_andnot(cut_regs,live_now);
            bitset_free(live_now);
          }
          free_split_cell_list(remat_defs);
          g_pressure_split_points = (void *)0x0;
        }
        bitset_andnot(neighbours,picked);
        if ((local_20 < local_8) && (local_20 != 2)) {
          ra_retype_range_homes(lr,local_20);
        }
        if (local_69 != 0) {
          ra_set_range_operand_field(lr,local_69);
        }
        if (cut_regs->chunks == (c2_bitset_chunk *)0x0) {
          bitset_free(cut_regs);
          return (c2_bitset *)0x0;
        }
        if (cut_points != (c2_list_cell *)0x0) {
          ra_pressure_split_candidates(cut_points,cut_regs,lr);
          free_split_cell_list(cut_points);
        }
        return cut_regs;
      }
    }
    block = block->next;
  } while( true );
}

