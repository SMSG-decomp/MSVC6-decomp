c2_bitset * __fastcall
build_interference_and_pressure_splits_part
          (c2_operand *opnd,c2_bitset *neighbour_set,c2_tuple *prev,uint8_t operand_field,int defs,
          int held,int byte_held,c2_bitset *live,int byte_ops,int uses,c2_tuple *tuple,
          c2_live_range *w,int byte_defs,int byte_temps_live,c2_bitset *hregs,
          c2_list_cell *split_cells,int class_ops,c2_block *block,c2_bitset *cut_set,uint32_t w_live
          ,int i28,int byte_pressure,uint32_t home_width,int live_read_webs,int pressure,
          c2_list_cell *remat_cells,uint32_t w_id,c2_function *fn,uint32_t tuple_width,
          c2_tuple *cursor,int reg_class,c2_bitset *interference,c2_bitset *exclude,int k)

{
  uint8_t uVar1;
  ushort uVar2;
  c2_live_range *pcVar3;
  c2_operand *pcVar4;
  c2_bitset *pcVar5;
  int iVar6;
  c2_operand *pcVar7;
  uint32_t uVar8;
  c2_list_cell *pending_copy;
  int iVar9;
  int iVar10;
  uint uVar11;
  int iVar12;
  uint32_t uVar13;
  uint32_t uVar14;
  c2_bitset *pcVar15;
  c2_tuple *pcVar16;
  c2_symbol *pcVar17;
  c2_tuple *pcVar18;
  c2_list_cell *pcVar19;
  int iVar20;
  c2_live_range *reg_rec;
  c2_live_range *src_web;
  c2_symbol *dst_hreg;
  c2_register_descriptor *colour;
  
code_r0x10715c09:
  do {
    bitset_or(interference,neighbour_set);
LAB_10715d35:
    opnd = opnd->next;
    while (opnd == (c2_operand *)0x0) {
      iVar20 = held + class_ops;
      live_read_webs = 0;
      iVar9 = byte_held + byte_temps_live;
      pending_copy = remat_cells;
      for (pcVar7 = tuple->src; remat_cells = pending_copy, pcVar7 != (c2_operand *)0x0;
          pcVar7 = pcVar7->next) {
        iVar12 = held;
        iVar6 = uses;
        if ((pcVar7->kind == '\x01') && (g_type_class[pcVar7->type >> 0xc] == reg_class)) {
          pcVar3 = (pcVar7->u18).range;
          uVar1 = pcVar3->kind;
          if (uVar1 == '\x01') {
            uVar14 = pcVar3->self->id;
            uVar13 = bitset_test(g_class_allowed_sets[reg_class],uVar14);
            if ((((uVar13 != 0) && (pcVar7->sym->cls != '\x01')) && ((pcVar7->flags11 & 0x10) != 0))
               && (uVar13 = bitset_test(hregs,uVar14), uVar13 == 0)) {
              bitset_set(hregs,uVar14);
              uVar14 = bitset_test(g_byte_register_set,uVar14);
joined_r0x1071613c:
              iVar12 = held + 1;
              iVar6 = uses + 1;
              if (uVar14 != 0) {
                held = held + 1;
                byte_held = byte_held + 1;
LAB_10716142:
                uses = uses + 1;
                byte_defs = byte_defs + 1;
                iVar12 = held;
                iVar6 = uses;
              }
            }
          }
          else if (uVar1 == '\x02') {
            colour = pcVar3->colour;
            if (colour == (c2_register_descriptor *)0x0) {
              if (pcVar3 == w) {
                uVar14 = pcVar3->id;
                uVar13 = bitset_test(live,uVar14);
                if (uVar13 == 0) {
                  bitset_set(live,uVar14);
                  held = held + 1;
                  uses = uses + 1;
                  w_live = 1;
                  if (((tuple->op == 1) && (tuple->dst->kind == '\x01')) &&
                     (pcVar17 = (tuple->dst->u18).reg, pcVar17->cls == '\x02')) {
                    bitset_set(g_copy_related_ranges,pcVar17->id);
                  }
                }
                pcVar4 = tuple->dst;
                operand_field = pcVar7->flags11 & 7;
                if (((pcVar4 != (c2_operand *)0x0) && (pcVar4->kind == '\x01')) &&
                   (((pcVar3 = (pcVar4->u18).range, pcVar3->kind == '\x02' &&
                     ((((pcVar3->flags5 & 4) == 0 &&
                       (pcVar3->colour == (c2_register_descriptor *)0x0)) &&
                      ((pcVar3->u38).def == tuple)))) &&
                    (iVar12 = operand_list_has_same_reg(pcVar7), iVar12 == 0)))) {
                  remat_cells = alloc_split_cell();
                  (remat_cells->u04).tuple = tuple;
                  remat_cells->next = pending_copy;
                }
                if (((tuple->op == 1) && ((pcVar7->flags11 & 0x10) == 0)) &&
                   ((pcVar7 == tuple->src && (pcVar4->kind == '\x01')))) {
                  uVar1 = ((pcVar4->u18).range)->kind;
                  if (((uVar1 == '\x01') && (pcVar4->sym->cls == '\x03')) ||
                     ((uVar1 == '\x02' &&
                      (((pcVar4->u18).range)->colour != (c2_register_descriptor *)0x0)))) {
                    pending_copy = alloc_split_cell();
                    (pending_copy->u04).tuple = tuple;
                    pending_copy->next = g_pending_copy_list;
                    g_pending_copy_list = pending_copy;
                  }
                }
                uVar11 = pcVar7->type & 0xfff;
                if ((int)home_width < (int)uVar11) {
                  home_width = uVar11;
                }
                pcVar4 = (pcVar7->sym->u34).lcse_values;
                iVar12 = held;
                iVar6 = uses;
                if (((pcVar4 != (c2_operand *)0x0) && (pcVar4->disp < pcVar7->sym->offset)) &&
                   (home_width == 1)) {
                  home_width = 2;
                }
              }
              else {
                iVar10 = operand_list_has_same_reg(pcVar7);
                if (iVar10 == 0) {
                  if (((tuple->op != 0x164) && (pcVar7->sym->cls != '\r')) &&
                     (uses = uses + 1, (pcVar3->flags5 & 0x80) != 0)) {
                    i28 = 1;
                    byte_defs = byte_defs + 1;
                  }
                  iVar6 = uses;
                  if ((pcVar7->flags11 & 0x10) == 0) {
                    live_read_webs = live_read_webs + 1;
                  }
                  else {
                    bitset_set(live,pcVar3->id);
                  }
                }
              }
            }
            else {
              uVar14 = pcVar3->id;
              uVar13 = bitset_test(live,uVar14);
              if (uVar13 == 0) {
                bitset_set(live,uVar14);
                uVar14 = colour->id;
                uVar13 = bitset_test(hregs,uVar14);
                if (uVar13 == 0) {
                  bitset_set(hregs,uVar14);
                  uVar14 = bitset_test(g_byte_register_set,uVar14);
                  goto joined_r0x1071613c;
                }
              }
            }
          }
          else {
            if (uVar1 != '\x03') {
              ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\color.c",0xf2e);
            }
            if ((pcVar7->flags11 & 0x10) != 0) {
              class_ops = class_ops + 1;
              iVar6 = uses + 1;
              if ((pcVar3->flags5 & 0x80) != 0) {
                byte_temps_live = byte_temps_live + 1;
                goto LAB_10716142;
              }
            }
          }
        }
        uses = iVar6;
        held = iVar12;
        pending_copy = remat_cells;
      }
      iVar12 = uses;
      if (uses < defs) {
        iVar12 = defs;
      }
      iVar20 = iVar20 + iVar12;
      if (byte_ops <= byte_defs) {
        byte_ops = byte_defs;
      }
      byte_pressure = iVar9 + byte_ops;
      iVar9 = iVar20 - k;
      if (k < iVar20) {
        iVar9 = iVar20 - k;
        class_ops = class_ops - iVar9;
        iVar20 = iVar20 - iVar9;
        do {
          pcVar17 = split_local_temp_at_pressure_point(fn,reg_class,tuple);
          if ((pcVar17->flags5 & 0x80) != 0) {
            byte_temps_live = byte_temps_live + -1;
            byte_pressure = byte_pressure + -1;
          }
          iVar9 = iVar9 + -1;
        } while (iVar9 != 0);
        iVar9 = iVar20 - k;
      }
      if ((SBORROW4(iVar20,k) == iVar9 < 0) && ((tuple->flags12 & 1) == 0)) {
        pcVar15 = bitset_new(6);
        for (pcVar7 = tuple->src; pcVar7 != (c2_operand *)0x0; pcVar7 = pcVar7->next) {
          if ((((pcVar7->kind == '\x01') && (pcVar17 = pcVar7->sym, pcVar17->cls == '\r')) &&
              (g_type_class[pcVar7->type >> 0xc] == reg_class)) &&
             ((pcVar3 = (pcVar7->u18).range, pcVar3 != w &&
              (pcVar3->colour == (c2_register_descriptor *)0x0)))) {
            if ((pcVar7->flags11 & 0x10) == 0) {
              live_read_webs = live_read_webs + -1;
            }
            bitset_set(pcVar15,pcVar3->id);
            pcVar7 = tuple_replace_src_with_base_copy(tuple,pcVar7,pcVar17);
          }
        }
        if ((0 < live_read_webs) && (uses - defs < live_read_webs)) {
          pcVar7 = tuple->src;
          live_read_webs = live_read_webs - (uses - defs);
          do {
            reg_rec = (c2_live_range *)0x0;
            for (pcVar4 = pcVar7; pcVar4 != (c2_operand *)0x0; pcVar4 = pcVar4->next) {
              if ((((pcVar4->kind == '\x01') &&
                   (pcVar3 = (pcVar4->u18).range, pcVar3->kind == '\x02')) && (pcVar3 != w)) &&
                 (((g_type_class[pcVar4->type >> 0xc] == reg_class &&
                   (pcVar3->colour == (c2_register_descriptor *)0x0)) &&
                  (((pcVar4->flags11 & 0x10) == 0 &&
                   ((reg_rec == (c2_live_range *)0x0 || (pcVar3->priority < reg_rec->priority)))))))
                 ) {
                reg_rec = pcVar3;
              }
            }
            bitset_set(pcVar15,reg_rec->id);
            live_read_webs = live_read_webs + -1;
          } while (live_read_webs != 0);
        }
        pcVar16 = insert_pressure_split_marker(tuple,live,exclude,pcVar15);
        bitset_free(pcVar15);
        if (pcVar16 != (c2_tuple *)0x0) {
          bitset_or(cut_set,(pcVar16->u14).regs);
          block->flags = block->flags | 0x40000;
          pcVar19 = alloc_split_cell();
          (pcVar19->u04).tuple = tuple;
          pcVar19->next = split_cells;
          split_cells = pcVar19;
        }
        tuple->flags12 = tuple->flags12 | 1;
      }
      pcVar16 = cursor;
      if ((w_live != 0) && (i28 + byte_temps_live != 0)) {
        if ((tuple->flags12 & 2) == 0) {
          if (byte_pressure == 3) {
            pcVar15 = w->allowed;
            iVar20 = bitset_intersects(pcVar15,g_nonbyte_register_set);
            if (iVar20 != 0) goto LAB_107164ce;
            pcVar18 = ra_mark_byte_register_conflicts(tuple,live,w);
            if (pcVar18 != (c2_tuple *)0x0) {
              bitset_or(cut_set,(pcVar18->u14).regs);
              block->flags = block->flags | 0x40000;
              pcVar19 = alloc_split_cell();
              (pcVar19->u04).tuple = tuple;
              pcVar19->next = split_cells;
              split_cells = pcVar19;
            }
            pcVar5 = g_byte_register_set;
            pcVar15 = block->set4c;
            tuple->flags12 = tuple->flags12 | 2;
            bitset_or(pcVar15,pcVar5);
          }
          else if (3 < byte_pressure) {
            pcVar18 = ra_mark_byte_register_conflicts(tuple,live,w);
            if (pcVar18 != (c2_tuple *)0x0) {
              bitset_or(cut_set,(pcVar18->u14).regs);
              block->flags = block->flags | 0x40000;
              pcVar19 = alloc_split_cell();
              (pcVar19->u04).tuple = tuple;
              pcVar19->next = split_cells;
              split_cells = pcVar19;
            }
            pcVar5 = g_byte_register_set;
            pcVar15 = block->set4c;
            tuple->flags12 = tuple->flags12 | 2;
            bitset_or(pcVar15,pcVar5);
          }
        }
        else {
          pcVar15 = w->allowed;
          iVar20 = bitset_intersects(pcVar15,g_nonbyte_register_set);
          if (iVar20 != 0) {
LAB_107164ce:
            bitset_and(pcVar15,g_nonbyte_register_set);
          }
        }
      }
      do {
        cursor = pcVar16;
        if (cursor == block->head) {
          do {
            if (block == w->last_block) {
              bitset_free(live);
              bitset_free(hregs);
              if (pending_copy != (c2_list_cell *)0x0) {
                g_pressure_split_points = split_cells;
                pcVar15 = rematerialize_candidate_definitions(pending_copy,w);
                if (pcVar15 != (c2_bitset *)0x0) {
                  bitset_andnot(interference,pcVar15);
                  bitset_andnot(cut_set,pcVar15);
                  bitset_free(pcVar15);
                }
                free_split_cell_list(pending_copy);
                g_pressure_split_points = (void *)0x0;
              }
              bitset_andnot(interference,exclude);
              if (((int)home_width < (int)tuple_width) && (home_width != 2)) {
                ra_retype_range_homes(w,home_width);
              }
              if (operand_field != '\0') {
                ra_set_range_operand_field(w,operand_field);
              }
              if (cut_set->chunks == (c2_bitset_chunk *)0x0) {
                bitset_free(cut_set);
                return (c2_bitset *)0x0;
              }
              if (split_cells != (c2_list_cell *)0x0) {
                ra_pressure_split_candidates(split_cells,cut_set,w);
                free_split_cell_list(split_cells);
              }
              return cut_set;
            }
            do {
              block = block->next;
              uVar14 = bitset_test(block->live,w_id);
            } while (uVar14 == 0);
            bitset_copy(live,block->live_out);
            bitset_copy(hregs,block->set28);
            held = bitset_popcount(hregs);
            uVar14 = bitset_test(hregs,7);
            byte_held = held;
            if (uVar14 != 0) {
              byte_held = held + -1;
            }
            uVar14 = bitset_test(hregs,8);
            if (uVar14 != 0) {
              byte_held = byte_held + -1;
            }
            uVar14 = bitset_test(hregs,6);
            if (uVar14 != 0) {
              byte_held = byte_held + -1;
            }
            uVar14 = bitset_test(live,w_id);
            if (uVar14 != 0) {
              held = held + 1;
            }
            w_live = (uint32_t)(uVar14 != 0);
            cursor = block->end;
          } while (cursor == block->head);
        }
        pcVar16 = cursor->prev;
      } while ((cursor->flags & 1) == 0);
      uVar2 = cursor->line;
      if (uVar2 != 0) {
        g_current_line_abs = fn->line_base + (uint)uVar2;
        g_cur_line = uVar2;
      }
      opnd = cursor->dst;
      defs = 0;
      uses = 0;
      byte_ops = 0;
      byte_defs = 0;
      prev = cursor;
      tuple = cursor;
      i28 = byte_temps_live;
      cursor = cursor->prev;
    }
    if (opnd->kind != '\x01') {
      if (opnd->kind == '\n') {
        uVar14 = bitset_iter_next((c2_bitset *)opnd->sym);
        while (uVar14 != 0xffffffff) {
          uVar13 = bitset_test(g_class_allowed_sets[reg_class],uVar14);
          if (uVar13 != 0) {
            defs = defs + 1;
            uVar14 = bitset_test(g_byte_register_set,uVar14);
            if (uVar14 != 0) {
              byte_ops = byte_ops + 1;
            }
          }
          uVar14 = bitset_iter_next((c2_bitset *)0x0);
        }
      }
      goto LAB_10715d35;
    }
    if (g_type_class[opnd->type >> 0xc] != reg_class) goto LAB_10715d35;
    pcVar17 = (c2_symbol *)(opnd->u18).range;
    uVar1 = pcVar17->cls;
    if (uVar1 == '\x01') {
      dst_hreg = pcVar17->storage;
      uVar14 = dst_hreg->id;
      uVar13 = bitset_test(g_class_allowed_sets[reg_class],uVar14);
      if (uVar13 == 0) goto LAB_10715d35;
      if (opnd->sym->cls == '\x01') {
        defs = defs + 1;
        uVar14 = bitset_test(g_byte_register_set,uVar14);
        if (uVar14 != 0) {
          byte_ops = byte_ops + 1;
        }
        goto LAB_10715d35;
      }
      if (((opnd->flags11 & 0x10) == 0) ||
         ((((prev->op == 1 && (prev->src->kind == '\x01')) &&
           (src_web = (prev->src->u18).range, src_web->kind == '\x02')) &&
          (src_web->colour == dst_hreg)))) goto LAB_10715d35;
      bitset_clear(hregs,uVar14);
LAB_107162da:
      held = held + -1;
      defs = defs + 1;
      uVar14 = bitset_test(g_byte_register_set,uVar14);
      if (uVar14 != 0) {
        byte_held = byte_held + -1;
        byte_ops = byte_ops + 1;
      }
      goto LAB_10715d35;
    }
    if (uVar1 != '\x02') {
      if (uVar1 != '\x03') {
        ice_fatal("E:\\8168\\vc98\\p2\\src\\P2\\color.c",0xe5b);
      }
      if ((opnd->flags11 & 0x10) != 0) {
        class_ops = class_ops + -1;
        defs = defs + 1;
        if ((pcVar17->flags5 & 0x80) != 0) {
          byte_temps_live = byte_temps_live + -1;
          byte_ops = byte_ops + 1;
        }
      }
      goto LAB_10715d35;
    }
    iVar20._0_2_ = pcVar17->type;
    iVar20._2_2_ = pcVar17->x12;
    if (iVar20 != 0) {
      pcVar7 = find_src_reg_operand(pcVar17,prev);
      if ((pcVar7 != (c2_operand *)0x0) ||
         (((bitset_clear(live,pcVar17->id), prev->op == 1 && (prev->src->kind == '\x01')) &&
          ((pcVar3 = (prev->src->u18).range, pcVar3->kind == '\x02' &&
           (pcVar3->colour == *(c2_register_descriptor **)&pcVar17->type)))))) goto LAB_10715d35;
      uVar14 = *(uint32_t *)(*(int *)&pcVar17->type + 0x1c);
      bitset_clear(hregs,uVar14);
      goto LAB_107162da;
    }
    if (pcVar17 != (c2_symbol *)w) {
      uVar14 = pcVar17->id;
      bitset_clear(live,uVar14);
      if ((prev->op != 0x163) && (defs = defs + 1, (pcVar17->flags5 & 0x80) != 0)) {
        i28 = 1;
        byte_ops = byte_ops + 1;
      }
      if ((w_live != 0) &&
         ((((prev->op != 1 || (pcVar7 = prev->src, pcVar7->kind != '\x01')) ||
           ((pcVar7->u18).range != w)) ||
          (((prev->type & 0xfff) == 1 &&
           (((pcVar7->sym->offset & 1) != 0 || ((opnd->sym->offset & 1) != 0)))))))) {
        bitset_set(interference,uVar14);
      }
      goto LAB_10715d35;
    }
    pcVar7 = find_src_reg_operand(pcVar17,prev);
    neighbour_set = live;
    if (pcVar7 != (c2_operand *)0x0) goto code_r0x10715c09;
    uVar14 = pcVar17->id;
    uVar13 = bitset_test(live,uVar14);
    if (uVar13 != 0) {
      bitset_clear(live,uVar14);
      held = held + -1;
      defs = defs + 1;
      w_live = 0;
      if (prev->op == 0x163) {
        tuple_width = prev->type & 0xfff;
      }
      uVar14 = 0;
      if ((((prev->op == 1) && (pcVar7 = prev->src, pcVar7->kind == '\x01')) &&
          (pcVar3 = (pcVar7->u18).range, pcVar3->kind == '\x02')) &&
         (((prev->type & 0xfff) != 1 ||
          (((pcVar7->sym->offset & 1) == 0 && ((opnd->sym->offset & 1) == 0)))))) {
        if (pcVar3->colour == (c2_register_descriptor *)0x0) {
          uVar13 = pcVar3->id;
          uVar8 = bitset_test(interference,uVar13);
          uVar14 = uVar13;
          if (uVar8 != 0) {
            uVar14 = 0;
          }
          prev = tuple;
          if (((pcVar7->flags11 & 0x10) != 0) || (uVar14 != 0)) {
            bitset_set(g_copy_related_ranges,uVar13);
          }
        }
        else {
          pending_copy = alloc_split_cell();
          (pending_copy->u04).tuple = prev;
          pending_copy->next = g_pending_copy_list;
          g_pending_copy_list = pending_copy;
        }
      }
      bitset_or(interference,live);
      if (uVar14 != 0) {
        bitset_clear(interference,uVar14);
      }
      goto LAB_10715d35;
    }
    pcVar16 = tuple_new_pseudo(0x19e,opnd->type);
    tuple_append_src(pcVar16,opnd);
    pcVar7 = pcVar16->src;
    pcVar7->flags = pcVar7->flags & 0xf0;
    pcVar7->flags11 = pcVar7->flags11 | 0x10;
    pcVar16->flags = pcVar16->flags & 0xf | 0x10;
    tuple_insert_after(prev,pcVar16);
    opnd->rank = 0;
  } while( true );
}

