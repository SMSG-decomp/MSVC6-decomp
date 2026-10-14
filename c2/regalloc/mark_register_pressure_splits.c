c2_bitset * __fastcall
mark_register_pressure_splits(c2_function *fn,int reg_class,c2_bitset *candidates,int reg_count)

{
  uint8_t *puVar1;
  uint8_t uVar2;
  ushort uVar3;
  c2_block *pcVar4;
  c2_symbol *pcVar5;
  uint uVar6;
  bool bVar7;
  byte bVar8;
  c2_bitset *dst;
  c2_bitset *dst_00;
  c2_operand *pcVar9;
  c2_tuple *pcVar10;
  uint32_t uVar11;
  c2_operand *pcVar12;
  int iVar13;
  c2_operand *pcVar14;
  c2_list_cell *pcVar15;
  uint32_t uVar16;
  c2_tuple *pcVar17;
  uint32_t uVar18;
  c2_live_range *pcVar19;
  c2_tuple *pcVar20;
  int local_48;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_28;
  c2_list_cell *local_20;
  c2_bitset *local_1c;
  int local_10;
  int local_c;
  c2_operand *local_8;
  int local_4;
  
  local_20 = (c2_list_cell *)0x0;
  local_10 = 0;
  if ((g_ebp_allocatable == 0) || ((g_opt_favor_speed != 0 && (g_aligned_frame_score == 0)))) {
    bVar7 = false;
  }
  else {
    bVar7 = true;
  }
  local_c = 0;
  local_3c = 0;
  g_ra_offset_byte_ranges = bitset_new(6);
  dst = bitset_new(6);
  local_40 = 0;
  local_38 = 0;
  if (bVar7) {
    local_1c = bitset_new(6);
  }
  dst_00 = bitset_new(6);
  pcVar4 = fn->cfg->last;
  do {
    if (pcVar4 == (c2_block *)0x0) {
      bitset_free(dst_00);
      if (bVar7) {
        bitset_free(local_1c);
        if (g_opt_favor_speed == 0) {
          if (local_c + 1 < local_3c) {
            g_ebp_allocatable = 0;
            g_class_register_count[0] = g_class_register_count[0] + -1;
          }
        }
        else {
          if (local_10 * 2 <= g_aligned_frame_score) {
            g_class_register_count[0] = g_class_register_count[0] + -1;
            g_ebp_allocatable = 0;
            enable_aligned_double_frame(fn);
          }
        }
      }
      if (local_20 != (c2_list_cell *)0x0) {
        ra_eliminate_register_copy(local_20);
        free_split_cell_list(local_20);
      }
      bitset_free(g_ra_offset_byte_ranges);
      if (dst->chunks == (c2_bitset_chunk *)0x0) {
        bitset_free(dst);
        return (c2_bitset *)0x0;
      }
      uVar18 = bitset_iter_next(dst);
      while (uVar18 != 0xffffffff) {
        pcVar19 = live_range_from_id(uVar18);
        pcVar19->flags5 = pcVar19->flags5 | 2;
        uVar18 = bitset_iter_next((c2_bitset *)0x0);
      }
      return dst;
    }
    bitset_copy(dst_00,pcVar4->live_out);
    if (bVar7) {
      bitset_and(local_1c,dst_00);
      local_28 = bitset_popcount(local_1c);
    }
    pcVar17 = pcVar4->end;
    if (pcVar17 != pcVar4->head) {
      do {
        pcVar20 = pcVar17;
        if ((pcVar17->flags & 1) != 0) {
          uVar3 = pcVar17->line;
          if (uVar3 != 0) {
            g_current_line_abs = fn->line_base + (uint)uVar3;
            g_cur_line = uVar3;
          }
          pcVar17->flags12 = '\0';
          local_48 = 0;
          local_34 = 0;
          pcVar9 = pcVar17->dst;
          pcVar15 = local_20;
          while (pcVar14 = pcVar9, local_20 = pcVar15, pcVar14 != (c2_operand *)0x0) {
            local_8 = pcVar14->next;
            pcVar9 = local_8;
            if (pcVar14->kind == '\x01') {
              uVar3 = pcVar14->type;
              if (g_type_class[uVar3 >> 0xc] == reg_class) {
                pcVar5 = (pcVar14->u18).reg;
                uVar2 = pcVar5->cls;
                if (uVar2 == '\x01') {
                  uVar18 = pcVar5->storage->id;
                  uVar11 = bitset_test(g_class_allowed_sets[reg_class],uVar18);
                  pcVar9 = local_8;
                  if (uVar11 != 0) {
                    bitset_set(pcVar4->set4c,uVar18);
                    if (pcVar14->sym->cls == '\x01') {
                      local_48 = local_48 + 1;
                      pcVar9 = local_8;
                    }
                    else {
                      pcVar12 = find_src_reg_operand(pcVar5,pcVar17);
                      pcVar9 = local_8;
                      if (pcVar12 == (c2_operand *)0x0) {
                        local_38 = local_38 + -1;
                        local_48 = local_48 + 1;
                        pcVar14->flags11 = pcVar14->flags11 | 0x10;
                      }
                      else {
                        pcVar14->flags11 = pcVar14->flags11 & 0xef;
                      }
                    }
                  }
                }
                else if (uVar2 == '\x02') {
                  uVar18 = pcVar5->id;
                  uVar11 = bitset_test(dst_00,uVar18);
                  if (uVar11 == 0) {
                    pcVar10 = tuple_new_pseudo(0x19e,uVar3);
                    tuple_append_src(pcVar10,pcVar14);
                    pcVar9 = pcVar10->src;
                    pcVar9->flags = pcVar9->flags & 0xf0;
                    pcVar9->flags11 = pcVar9->flags11 | 0x10;
                    pcVar10->flags = pcVar10->flags & 0xf | 0x10;
                    tuple_insert_after(pcVar17,pcVar10);
                    pcVar14->rank = 0;
                  }
                  uVar11 = pcVar17->op;
                  if (((uVar11 == 0x163) && (pcVar14->sym->cls == '\r')) &&
                     (uVar16 = bitset_test(pcVar4->live_in,uVar18), uVar16 != 0)) {
                    pcVar20 = pcVar17->next;
                    tuple_unlink_free(pcVar17);
                    goto LAB_10721ae2;
                  }
                  bitset_clear(dst_00,uVar18);
                  if ((bVar7) && (uVar16 = bitset_test(local_1c,uVar18), uVar16 != 0)) {
                    local_28 = local_28 + -1;
                    bitset_clear(local_1c,uVar18);
                  }
                  if (uVar11 != 0x163) {
                    local_48 = local_48 + 1;
                    pcVar14->flags11 = pcVar14->flags11 & 0x7f;
                    if (((uVar11 == 1) && (pcVar9 = pcVar17->src, pcVar9->kind == '\x01')) &&
                       ((((pcVar9->u18).reg)->cls == '\x03' &&
                        (((pcVar9->next == (c2_operand *)0x0 &&
                          (pcVar17->dst->next == (c2_operand *)0x0)) &&
                         (uVar11 = bitset_test(pcVar4->live_in,uVar18), uVar11 == 0)))))) {
                      local_20 = alloc_split_cell();
                      (local_20->u04).tuple = pcVar17;
                      local_20->next = pcVar15;
                    }
                  }
                  bitset_set(pcVar4->live,uVar18);
                  pcVar9 = local_8;
                  pcVar15 = local_20;
                  if ((pcVar14->type & 0xfff) == 1) {
                    puVar1 = &((pcVar14->u18).reg)->flags5;
                    *puVar1 = *puVar1 | 0x80;
                  }
                }
                else {
                  if (uVar2 != '\x03') {
                    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\color.c",0x348);
                  }
                  pcVar14->flags11 = pcVar14->flags11 & 0x7f;
                  pcVar9 = find_src_reg_operand(pcVar5,pcVar17);
                  if (pcVar9 == (c2_operand *)0x0) {
                    local_40 = local_40 + -1;
                    local_48 = local_48 + 1;
                    bVar8 = pcVar14->flags11 | 0x10;
                  }
                  else {
                    bVar8 = pcVar14->flags11 & 0xef;
                  }
                  pcVar14->flags11 = bVar8;
                  pcVar9 = local_8;
                  if ((pcVar14->type & 0xfff) == 1) {
                    pcVar5 = (pcVar14->u18).reg;
                    iVar13 = pcVar14->sym->offset;
                    pcVar5->flags5 = pcVar5->flags5 | 0x80;
                    if (iVar13 != 0) {
                      bitset_set(g_ra_offset_byte_ranges,pcVar5->id);
                      pcVar9 = local_8;
                    }
                  }
                }
              }
            }
            else if (pcVar14->kind == '\n') {
              uVar18 = bitset_iter_next((c2_bitset *)pcVar14->sym);
              while (uVar18 != 0xffffffff) {
                uVar18 = bitset_test(g_class_allowed_sets[reg_class],uVar18);
                if (uVar18 != 0) {
                  local_48 = local_48 + 1;
                }
                uVar18 = bitset_iter_next((c2_bitset *)0x0);
              }
              bitset_or(pcVar4->set4c,(c2_bitset *)pcVar14->sym);
              pcVar9 = local_8;
            }
            else if ((pcVar14->op == 0x14a) || (pcVar14->op == 0x14e)) {
              local_3c = local_3c + 1;
            }
          }
          local_4 = local_38 + local_40;
          for (pcVar9 = pcVar17->src; pcVar9 != (c2_operand *)0x0; pcVar9 = pcVar9->next) {
            if (pcVar9->kind == '\x01') {
              pcVar9->rank = 0;
              pcVar9->flags = pcVar9->flags & 0x7f;
              if (g_type_class[pcVar9->type >> 0xc] == reg_class) {
                pcVar5 = (pcVar9->u18).reg;
                uVar2 = pcVar5->cls;
                if (uVar2 == '\x01') {
                  uVar18 = pcVar5->storage->id;
                  uVar11 = bitset_test(g_class_allowed_sets[reg_class],uVar18);
                  if (uVar11 != 0) {
                    if (pcVar9->sym->cls == '\x01') {
                      bitset_set(pcVar4->set4c,uVar18);
                    }
                    else {
                      pcVar14 = find_dst_reg_operand(pcVar5,pcVar17);
                      if ((pcVar14 == (c2_operand *)0x0) || (pcVar14->sym->cls != '\x03')) {
                        local_38 = local_38 + 1;
                        local_34 = local_34 + 1;
                        pcVar9->flags11 = pcVar9->flags11 | 0x10;
                      }
                      else {
                        pcVar9->flags11 = pcVar9->flags11 & 0xef;
                      }
                    }
                  }
                }
                else if (uVar2 == '\x02') {
                  pcVar9->flags11 = pcVar9->flags11 & 0x7f;
                  if ((pcVar9->type & 0xfff) == 1) {
                    pcVar5->flags5 = pcVar5->flags5 | 0x80;
                  }
                  iVar13 = operand_list_has_same_reg(pcVar9);
                  if (iVar13 == 0) {
                    pcVar5 = (pcVar9->u18).reg;
                    pcVar14 = (c2_operand *)pcVar5->id;
                    if ((pcVar17->op != 0x164) && (pcVar9->sym->cls != '\r')) {
                      local_34 = local_34 + 1;
                    }
                    local_8 = pcVar14;
                    if ((bVar7) && (uVar18 = bitset_test(local_1c,(uint32_t)pcVar14), uVar18 == 0))
                    {
                      bitset_set(local_1c,(uint32_t)pcVar14);
                      local_28 = local_28 + 1;
                    }
                    uVar18 = bitset_test(dst_00,(uint32_t)pcVar14);
                    if (uVar18 == 0) {
                      pcVar9->flags11 = pcVar9->flags11 | 0x10;
                      bitset_set(dst_00,(uint32_t)pcVar14);
                      if ((pcVar9->flags & 0x20) != 0) {
                        fold_increment_into_address(pcVar17,pcVar5);
                      }
                    }
                    else {
                      pcVar9->flags11 = pcVar9->flags11 & 0xef;
                    }
                    if ((((pcVar17->op == 1) && (uVar2 = pcVar9->sym->cls, uVar2 != '\r')) &&
                        (pcVar14 = pcVar17->dst, pcVar14->kind == '\x01')) &&
                       (((pcVar5 = (pcVar14->u18).reg, pcVar5->cls == '\x03' &&
                         (pcVar14->next == (c2_operand *)0x0)) &&
                        (pcVar17->src->next == (c2_operand *)0x0)))) {
                      pcVar10 = (c2_tuple *)pcVar5->defs;
                      if (((pcVar10->op != 0x166) &&
                          (((pcVar10->op != 0x18d ||
                            (iVar13 = switch_use_byte_index_table((c2_node *)pcVar10), iVar13 == 0))
                           || (g_opt_favor_speed != 0)))) &&
                         (((((uVar6 = pcVar10->op, uVar6 == 0 || (0x143 < uVar6)) ||
                            ((g_x86_op_flags[uVar6] & 0x40) == 0)) ||
                           ((pcVar10->src != (c2_operand *)pcVar5->uses ||
                            (pcVar14 = find_dst_reg_operand(pcVar5,pcVar10),
                            pcVar14 != (c2_operand *)0x0)))) &&
                          ((((((*(ushort *)((int)&pcVar5->uses[1].next + 2) & 0xfff) <=
                               (pcVar9->type & 0xfff) || ((uVar2 == '\x03' || (uVar2 == '\x04'))))
                             || (uVar2 == '\x05')) || (uVar2 == '\x06')) &&
                           ((((uint)pcVar5->uses[2].next & 0x1000) != 0 ||
                            (((pcVar9->flags11 & 0x10) != 0 &&
                             (uVar18 = bitset_test(pcVar4->live_out,(uint32_t)local_8), uVar18 == 0)
                             ))))))))) {
                        pcVar15 = alloc_split_cell();
                        (pcVar15->u04).tuple = pcVar17;
                        pcVar15->next = local_20;
                        local_20 = pcVar15;
                      }
                    }
                  }
                  else {
                    pcVar9->flags11 = pcVar9->flags11 & 0xef;
                  }
                }
                else {
                  if (uVar2 != '\x03') {
                    ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\color.c",0x40a);
                  }
                  pcVar9->flags11 = pcVar9->flags11 & 0x7f;
                  pcVar14 = find_dst_reg_operand(pcVar5,pcVar17);
                  if (pcVar14 == (c2_operand *)0x0) {
                    local_34 = local_34 + 1;
                    local_40 = local_40 + 1;
                    bVar8 = pcVar9->flags11 | 0x10;
                  }
                  else {
                    bVar8 = pcVar9->flags11 & 0xef;
                  }
                  pcVar9->flags11 = bVar8;
                  if ((((pcVar17->op == 1) && (pcVar17->dst->kind == '\x01')) &&
                      (pcVar5 = (pcVar17->dst->u18).reg, pcVar5->cls == '\x01')) &&
                     ((pcVar9 == pcVar17->src &&
                      (iVar13 = retarget_value_chain_register
                                          (pcVar17,(pcVar9->u18).reg,pcVar5->storage), iVar13 != 0))
                     )) {
                    local_40 = local_40 + -1;
                    local_38 = local_38 + 1;
                  }
                  else {
                    if ((pcVar9->type & 0xfff) == 1) {
                      pcVar5 = (pcVar9->u18).reg;
                      pcVar5->flags5 = pcVar5->flags5 | 0x80;
                      if (pcVar9->sym->offset != 0) {
                        bitset_set(g_ra_offset_byte_ranges,pcVar5->id);
                      }
                    }
                    pcVar5 = (pcVar9->u18).reg;
                    pcVar5->defs = (c2_list_cell *)pcVar17;
                    pcVar5->uses = (c2_list_cell *)pcVar9;
                  }
                }
              }
            }
            else if (pcVar9->kind == '\x02') {
              pcVar9->rank = 0;
              if (pcVar9->op == 0x14a) goto LAB_10721dc2;
            }
            else if ((pcVar9->op == 0x14a) || (pcVar9->op == 0x14e)) {
LAB_10721dc2:
              local_3c = local_3c + 1;
            }
          }
          if (local_34 < local_48) {
            local_34 = local_48;
          }
          local_34 = local_4 + local_34;
          if (reg_count < local_34) {
            iVar13 = local_34 - reg_count;
            local_40 = local_40 - iVar13;
            local_34 = local_34 - iVar13;
            do {
              split_local_temp_at_pressure_point(fn,reg_class,pcVar17);
              iVar13 = iVar13 + -1;
            } while (iVar13 != 0);
          }
          if ((local_34 == reg_count) &&
             (pcVar17 = insert_pressure_split_marker
                                  (pcVar17,dst_00,(c2_bitset *)0x0,(c2_bitset *)0x0),
             pcVar17 != (c2_tuple *)0x0)) {
            bitset_or(dst,(pcVar17->u14).regs);
            pcVar4->flags = pcVar4->flags | 0x40000;
          }
          if ((bVar7) && (7 < local_28 + local_34)) {
            if ((g_aligned_frame_score != 0) && (6 < local_28 + local_34)) {
              iVar13 = int_power(5,(int)pcVar4->loop_depth);
              local_10 = local_10 + iVar13;
            }
            iVar13 = average_frame_range_savings(local_1c,&local_c);
            local_28 = 0;
            local_3c = local_3c + iVar13;
            bitset_clear_all(local_1c);
          }
        }
LAB_10721ae2:
        pcVar17 = pcVar20->prev;
      } while (pcVar17 != pcVar4->head);
    }
    pcVar4 = pcVar4->prev;
  } while( true );
}

