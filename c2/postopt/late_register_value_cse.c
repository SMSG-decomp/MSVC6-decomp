void __fastcall late_register_value_cse(c2_function *fn)

{
  uint8_t uVar1;
  ushort uVar2;
  ushort uVar3;
  c2_tuple *pcVar4;
  c2_tuple *pcVar5;
  c2_symbol_u34 cVar6;
  c2_tuple *t;
  c2_symbol *pcVar7;
  uint uVar8;
  c2_symbol *pcVar9;
  bool bVar10;
  c2_symbol *pcVar11;
  c2_symbol *pcVar12;
  c2_symbol *pcVar13;
  c2_symbol *reg;
  c2_symbol *pcVar14;
  c2_operand *pcVar15;
  int iVar16;
  uint32_t uVar17;
  c2_operand *pcVar18;
  c2_operand *pcVar19;
  c2_symbol *pcVar20;
  c2_symbol *vclass;
  c2_symbol *local_40;
  c2_operand *local_34;
  c2_symbol *src_reg;
  c2_symbol *dst_reg;
  c2_symbol *local_24;
  int local_1c;
  c2_symbol *local_18;
  uint local_14;
  c2_symbol *local_c;
  c2_symbol *local_4;
  c2_operand *class_val;
  c2_symbol *def_reg;
  
  local_40 = (c2_symbol *)0x0;
  bVar10 = false;
  make_int_zero_constant();
  pcVar4 = fn->cfg->first->head;
  pcVar14 = dst_reg;
joined_r0x107390b3:
  do {
    while( true ) {
      pcVar5 = pcVar4;
      if (pcVar5 == (c2_tuple *)0x0) {
        free_late_cse_constants();
        return;
      }
      uVar3 = pcVar5->line;
      if (uVar3 != 0) {
        g_current_line_abs = fn->line_base + (uint)uVar3;
        g_cur_line = uVar3;
      }
      t = pcVar5->next;
      pcVar4 = t;
      if ((pcVar5->flags & 1) != 0) break;
      if (pcVar5->kind == '\x1a') {
        local_40 = (c2_symbol *)0x0;
      }
    }
    if (((pcVar5->op != 1) || (pcVar5->dst->kind != '\x01')) || (pcVar5->src->kind != '\x01')) {
LAB_1073968e:
      if (local_40 != (c2_symbol *)0x0) {
        for (pcVar18 = pcVar5->src; pcVar18 != (c2_operand *)0x0; pcVar18 = pcVar18->next) {
          pcVar4 = pcVar5;
          switch(pcVar18->kind) {
          case '\x02':
          case '\x06':
            vclass = local_40;
            do {
              for (pcVar19 = (vclass->u34).lcse_values; pcVar19 != (c2_operand *)0x0;
                  pcVar19 = (c2_operand *)pcVar19->rank) {
                if (pcVar18->kind == '\x02') {
                  if (pcVar19->kind == '\x02') {
                    if ((pcVar18->sym->storage == pcVar19->sym->storage) &&
                       (pcVar18->sym->offset == pcVar19->sym->offset)) goto LAB_10739200;
                  }
                }
                else if ((pcVar19->kind == '\x06') &&
                        ((((pcVar18->disp == pcVar19->disp &&
                           (iVar16 = symbol_compare(pcVar18->base_sym,pcVar19->base_sym),
                           iVar16 == 0)) &&
                          (iVar16 = operand_compare(pcVar18->base,pcVar19->base), iVar16 == 0)) &&
                         (iVar16 = operand_compare(pcVar18->index,pcVar19->index), iVar16 == 0)))) {
LAB_10739200:
                  uVar3 = pcVar19->type;
                  uVar2 = pcVar18->type;
                  if (((uVar2 & 0xfff) <= (uVar3 & 0xfff)) &&
                     ((((uVar2 ^ uVar3) & 0xfff) == 0 ||
                      ((((1 << (byte)(uVar2 >> 0xc) & 0xeU) != 0 &&
                        ((1 << (byte)(uVar3 >> 0xc) & 0xeU) != 0)) &&
                       (((uVar2 & 0xfff) != 1 || (vclass->storage->id < 5)))))))) {
                    if (pcVar19 != (c2_operand *)0x0) {
                      if (((pcVar18->flags & 0x40) != 0) ||
                         (iVar16 = late_cse_tuple_is_candidate(pcVar5,pcVar18), iVar16 == 0))
                      goto switchD_10739175_caseD_4;
                      pcVar14 = reg_find_subreg(vclass,(pcVar18->type & 0xfff) << 3,0);
                      pcVar15 = operand_new_reg(0x149,pcVar18->type,pcVar14,pcVar14);
                      tuple_replace_src(pcVar5,pcVar18,pcVar15);
                      pcVar4 = pcVar5->prev;
                      late_cse_finish_compare(pcVar5,pcVar19);
                      pcVar4 = pcVar4->next;
                      pcVar14 = dst_reg;
                      goto joined_r0x107390b3;
                    }
                    break;
                  }
                }
              }
              vclass = (vclass->u30).order_prev;
            } while (vclass != (c2_symbol *)0x0);
            break;
          case '\x03':
            pcVar14 = local_40;
            do {
              for (pcVar19 = (pcVar14->u34).lcse_values; pcVar19 != (c2_operand *)0x0;
                  pcVar19 = (c2_operand *)pcVar19->rank) {
                if ((pcVar19->kind == '\x03') && (pcVar19->sym == pcVar18->sym)) {
                  if (pcVar19 != (c2_operand *)0x0) {
                    pcVar19 = operand_new_reg(0x149,pcVar18->type,pcVar14,pcVar14);
                    tuple_replace_src(pcVar5,pcVar18,pcVar19);
                    pcVar14 = dst_reg;
                    goto joined_r0x107390b3;
                  }
                  break;
                }
              }
              pcVar14 = (pcVar14->u30).order_prev;
            } while (pcVar14 != (c2_symbol *)0x0);
            break;
          case '\a':
            pcVar14 = local_40;
            do {
              for (pcVar19 = (pcVar14->u34).lcse_values; pcVar19 != (c2_operand *)0x0;
                  pcVar19 = (c2_operand *)pcVar19->rank) {
                if ((pcVar19->kind == '\a') && ((pcVar19->u18).reg == (pcVar18->u18).reg)) {
                  if (pcVar19 != (c2_operand *)0x0) {
                    iVar16 = late_cse_use_register(pcVar5,pcVar18,pcVar14);
                    pcVar14 = dst_reg;
                    if (iVar16 != 0) goto joined_r0x107390b3;
                    goto switchD_10739175_caseD_4;
                  }
                  break;
                }
              }
              pcVar14 = (pcVar14->u30).order_prev;
            } while (pcVar14 != (c2_symbol *)0x0);
          }
switchD_10739175_caseD_4:
          pcVar14 = dst_reg;
        }
      }
      local_24 = (c2_symbol *)0x0;
      pcVar20 = pcVar14;
      pcVar14 = local_40;
joined_r0x107396d2:
      pcVar9 = local_24;
      if (pcVar14 != (c2_symbol *)0x0) {
        local_34 = (c2_operand *)0x0;
        pcVar18 = (pcVar14->u34).lcse_values;
joined_r0x107396e9:
        pcVar19 = local_34;
        local_34 = pcVar18;
        if (local_34 != (c2_operand *)0x0) {
          pcVar18 = (c2_operand *)local_34->rank;
          if ((local_34->kind != '\x03') && (local_34->kind != '\a')) {
            for (pcVar15 = pcVar5->dst; pcVar15 != (c2_operand *)0x0; pcVar15 = pcVar15->next) {
              uVar17 = operands_overlap(local_34,pcVar15);
              if (uVar17 != 0) {
                pcVar20 = pcVar14;
                if (pcVar19 == (c2_operand *)0x0) {
                  for (; local_34 = pcVar19, pcVar20 != (c2_symbol *)0x0;
                      pcVar20 = pcVar20->order_next) {
                    (pcVar20->u34).lcse_values = pcVar18;
                  }
                }
                else {
                  pcVar19->rank = (uint32_t)pcVar18;
                  local_34 = pcVar19;
                }
                break;
              }
            }
          }
          goto joined_r0x107396e9;
        }
        pcVar7 = (pcVar14->u30).order_prev;
        local_c = (c2_symbol *)0x0;
        pcVar12 = local_40;
        pcVar13 = pcVar14;
joined_r0x10739738:
        reg = pcVar14;
        pcVar11 = local_c;
        local_40 = pcVar12;
        pcVar20 = dst_reg;
        local_24 = pcVar9;
        pcVar14 = pcVar7;
        if (reg != (c2_symbol *)0x0) {
          pcVar14 = reg->order_next;
          uVar8 = pcVar5->op;
          if ((uVar8 == 0) || (0x143 < uVar8)) {
            local_14 = 100;
          }
          else {
            local_14 = (uint)g_x86_op_result_dst_count[uVar8];
          }
          pcVar18 = pcVar5->dst;
          local_1c = 0;
          while( true ) {
            local_c = reg;
            if ((pcVar18 == (c2_operand *)0x0) || ((int)local_14 <= local_1c))
            goto joined_r0x10739738;
            if ((pcVar18->kind == '\x01') &&
               (def_reg = (pcVar18->u18).reg, def_reg->storage == reg->storage)) break;
LAB_107393d2:
            if ((pcVar18->kind == '\n') &&
               (uVar17 = bitset_test((c2_bitset *)pcVar18->sym,reg->storage->id), uVar17 != 0))
            goto LAB_10739443;
            pcVar18 = pcVar18->next;
            local_1c = local_1c + 1;
          }
          if (def_reg != reg) {
            if ((reg->size + reg->offset <= def_reg->offset) ||
               (def_reg->size + def_reg->offset <= reg->offset)) goto LAB_107393d2;
          }
LAB_10739443:
          if ((pcVar18 == pcVar5->dst) &&
             (iVar16 = late_cse_simplify_constant_op(pcVar5,reg), iVar16 != 0)) {
            pcVar4 = t;
            pcVar14 = dst_reg;
            if (((t->kind == '\x11') &&
                (((((t->u20).cond_cells == (c2_cond_cell *)0x0 && (t->op != 0x18b)) &&
                  (t->src->kind == '\x04')) &&
                 (((*(int *)((int)&t->src->sym->u30 + 2) != 0 &&
                   (pcVar5 = t->prev, pcVar5->kind == '\x11')) &&
                  (((pcVar5->u20).cond_cells != (c2_cond_cell *)0x0 || (pcVar5->op == 0x18b))))))))
               && ((t->next->kind == '\x1a' &&
                   (*(c2_tuple **)((int)&pcVar5->src->sym->u30 + 2) == t->next)))) {
              branch_invert_condition(pcVar5);
              tuple_retarget(pcVar5,*(c2_node **)((int)&t->src->sym->u30 + 2),0);
              branch_free(t);
              pcVar4 = pcVar5->next;
            }
            goto joined_r0x107390b3;
          }
          local_c = pcVar11;
          if (pcVar11 == (c2_symbol *)0x0) {
            if (pcVar14 == (c2_symbol *)0x0) {
              pcVar14 = pcVar7;
              local_40 = pcVar7;
              if (pcVar9 != (c2_symbol *)0x0) {
                (pcVar9->u30).order_prev = pcVar7;
                local_40 = pcVar12;
              }
              goto joined_r0x107396d2;
            }
            pcVar13 = pcVar14;
            if (pcVar9 == (c2_symbol *)0x0) {
              (pcVar14->u30).order_prev = pcVar7;
              pcVar12 = pcVar14;
            }
            else {
              (pcVar9->u30).order_prev = pcVar14;
              (pcVar14->u30).order_prev = pcVar7;
            }
          }
          else {
            pcVar11->order_next = pcVar14;
          }
          goto joined_r0x10739738;
        }
        local_24 = pcVar13;
        if (((pcVar13->u34).refs == 0) && (pcVar13->order_next == (c2_symbol *)0x0)) {
          local_40 = pcVar7;
          if (pcVar9 != (c2_symbol *)0x0) {
            (pcVar9->u30).order_prev = pcVar7;
            local_40 = pcVar12;
          }
          local_24 = pcVar9;
          if ((bVar10) && (local_18 == pcVar13)) {
            local_18 = (c2_symbol *)0x0;
          }
        }
        goto joined_r0x107396d2;
      }
      if (!bVar10) {
        pcVar14 = pcVar20;
        if ((pcVar5->op == 1) && (pcVar5->dst->kind == '\x01')) {
          uVar1 = pcVar5->src->kind;
          if ((uVar1 == '\x02') || (uVar1 == '\x06')) {
            uVar17 = operands_overlap(pcVar5->src,pcVar5->dst);
            pcVar4 = t;
            if ((uVar17 == 0) && (pcVar18 = pcVar5->src, (pcVar18->flags & 0x40) == 0)) {
              dst_reg = (pcVar5->dst->u18).reg;
              (dst_reg->u30).order_prev = local_40;
              dst_reg->order_next = (c2_symbol *)0x0;
              pcVar18->rank = 0;
              (dst_reg->u34).lcse_values = pcVar18;
              local_40 = dst_reg;
              pcVar14 = dst_reg;
            }
            goto joined_r0x107390b3;
          }
        }
        pcVar18 = late_cse_value_of(pcVar5,&local_4);
        if (pcVar18 == (c2_operand *)0x0) {
          pcVar4 = t;
          pcVar14 = dst_reg;
          if ((pcVar5->op != 1) || (pcVar5->src->kind != '\x01')) goto joined_r0x107390b3;
          pcVar19 = pcVar5->dst;
          if (((pcVar19->kind != '\x02') && (pcVar19->kind != '\x06')) ||
             (pcVar14 = pcVar20, (pcVar19->flags & 0x40) != 0)) goto joined_r0x107390b3;
          pcVar20 = (pcVar5->src->u18).reg;
        }
        else {
          pcVar20 = local_4;
          pcVar19 = pcVar18;
          pcVar14 = local_40;
          if ((pcVar18->flags & 0x10) == 0) {
            for (; pcVar14 != (c2_symbol *)0x0; pcVar14 = (pcVar14->u30).order_prev) {
              for (class_val = (pcVar14->u34).lcse_values; class_val != (c2_operand *)0x0;
                  class_val = (c2_operand *)class_val->rank) {
                if (class_val == pcVar18) {
                  if (class_val != (c2_operand *)0x0) {
                    if (pcVar14 != (c2_symbol *)0x0) {
                      pcVar19 = (c2_operand *)node_clone((c2_node *)pcVar18);
                      pcVar15 = pcVar18->next;
                      pcVar18->next = pcVar19;
                      pcVar19->next = pcVar15;
                      pcVar20 = local_4;
                    }
                    goto LAB_1073982c;
                  }
                  break;
                }
              }
            }
          }
        }
LAB_1073982c:
        local_40 = late_cse_merge_value_classes(local_40,pcVar20,pcVar19);
        pcVar4 = t;
        pcVar14 = dst_reg;
        goto joined_r0x107390b3;
      }
      bVar10 = false;
      if (local_18 == (c2_symbol *)0x0) {
        (src_reg->u30).order_prev = local_40;
        src_reg->order_next = pcVar20;
        pcVar20->order_next = (c2_symbol *)0x0;
        (src_reg->u34).refs = 0;
        (pcVar20->u34).refs = 0;
        pcVar4 = t;
        local_40 = src_reg;
        pcVar14 = dst_reg;
      }
      else {
        pcVar14 = src_reg->order_next;
        src_reg->order_next = pcVar20;
        cVar6 = src_reg->u34;
        pcVar20->order_next = pcVar14;
        pcVar20->u34 = cVar6;
        pcVar4 = t;
        pcVar14 = dst_reg;
      }
      goto joined_r0x107390b3;
    }
    src_reg = (pcVar5->src->u18).reg;
    for (local_18 = local_40; pcVar14 = local_18, local_18 != (c2_symbol *)0x0;
        local_18 = (local_18->u30).order_prev) {
      for (; pcVar14 != (c2_symbol *)0x0; pcVar14 = pcVar14->order_next) {
        if (pcVar14 == src_reg) {
          if (pcVar14 != (c2_symbol *)0x0) goto LAB_10739119;
          break;
        }
      }
    }
LAB_10739119:
    pcVar14 = (pcVar5->dst->u18).reg;
    for (pcVar20 = local_40; pcVar9 = pcVar20, pcVar20 != (c2_symbol *)0x0;
        pcVar20 = (pcVar20->u30).order_prev) {
      for (; pcVar9 != (c2_symbol *)0x0; pcVar9 = pcVar9->order_next) {
        if (pcVar9 == pcVar14) {
          if (pcVar9 != (c2_symbol *)0x0) goto LAB_10739144;
          break;
        }
      }
    }
LAB_10739144:
    dst_reg = pcVar14;
    if ((local_18 != pcVar20) || (local_18 == (c2_symbol *)0x0)) {
      bVar10 = true;
      goto LAB_1073968e;
    }
    tuple_unlink_free(pcVar5);
  } while( true );
}

