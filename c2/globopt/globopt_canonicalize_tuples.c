void __fastcall globopt_canonicalize_tuples(c2_function *fn)

{
  c2_list_cell_u04 *pcVar1;
  byte bVar2;
  uint16_t uVar3;
  c2_symbol *pcVar4;
  c2_operand *pcVar5;
  c2_list_cell *pcVar6;
  bool bVar7;
  c2_list_cell *pcVar8;
  uint uVar9;
  c2_operand *pcVar10;
  c2_tuple *pcVar11;
  c2_operand *pcVar12;
  c2_node *node;
  int iVar13;
  c2_tuple *pcVar14;
  c2_const_operand *pcVar15;
  ushort uVar16;
  c2_symbol *pcVar17;
  c2_tuple *pcVar18;
  c2_symbol *pcVar19;
  c2_function *fn_00;
  c2_tuple *end;
  
  fn_00 = fn;
  g_fwdprop_candidate_syms = bitset_new(4);
  init_list_node_pool();
  end = fn->cfg->last->end;
  pcVar18 = fn->cfg->first->head->next;
  if (pcVar18 != end) {
    do {
      pcVar11 = pcVar18->next;
      if (((pcVar18->flags & 1) != 0) && (pcVar18->op != 0x15d)) {
        if ((g_opt_dlp != 0) &&
           ((((pcVar18->op == 0x15b && ((1 << (pcVar18->dst->kind & 0x1f) & 6U) != 0)) &&
             (pcVar18->dst->sym->def != (c2_tuple *)0x0)) && (pcVar18->src->kind == '\x03')))) {
          pcVar18->op = 0x169;
        }
        if (pcVar18->line != 0) {
          g_current_line_abs = fn_00->line_base + (uint)pcVar18->line;
          g_cur_line = pcVar18->line;
        }
        for (pcVar12 = pcVar18->src; pcVar12 != (c2_operand *)0x0; pcVar12 = pcVar12->next) {
          if (((1 << (pcVar12->kind & 0x1f) & 0x60U) != 0) && (pcVar12->op != 0x14c)) {
            pcVar15 = operand_new_intconst(0x2004,pcVar12->disp,pcVar12->disp >> 0x1f);
            pcVar14 = tuple_new_unary_temp(0x15d,0x2004,pcVar15,tuple_insert_before,pcVar18);
            pcVar12->op = 0x14c;
            if (pcVar18->flags13 == '\x11') {
              pcVar14->flags13 = '\x11';
            }
            pcVar12->disp = 0;
            pcVar10 = (c2_operand *)node_clone((c2_node *)pcVar14->dst);
            pcVar12->base = pcVar10;
            pcVar10->flags = pcVar10->flags | 0x20;
            pcVar12->base->flags = pcVar12->base->flags | 0x10;
            tuple_append_base_index(pcVar18,pcVar12);
          }
        }
        for (pcVar12 = pcVar18->dst; pcVar12 != (c2_operand *)0x0; pcVar12 = pcVar12->next) {
          if (((1 << (pcVar12->kind & 0x1f) & 0x60U) != 0) && (pcVar12->op != 0x14c)) {
            pcVar15 = operand_new_intconst(0x2004,pcVar12->disp,pcVar12->disp >> 0x1f);
            pcVar14 = tuple_new_unary_temp(0x15d,0x2004,pcVar15,tuple_insert_before,pcVar18);
            if (pcVar18->flags13 == '\x11') {
              pcVar14->flags13 = '\x11';
            }
            pcVar12->op = 0x14c;
            pcVar12->disp = 0;
            pcVar10 = (c2_operand *)node_clone((c2_node *)pcVar14->dst);
            pcVar12->base = pcVar10;
            pcVar10->flags = pcVar10->flags | 0x20;
            pcVar12->base->flags = pcVar12->base->flags | 0x10;
            tuple_append_base_index(pcVar18,pcVar12);
          }
        }
        if (((pcVar18->op == 0x15b) && (pcVar18->dst->kind == '\x02')) &&
           (pcVar17 = pcVar18->dst->sym->storage, pcVar17->storage->fe != (c2_fe_symbol *)0x0)) {
          bitset_set(g_fwdprop_candidate_syms,pcVar17->id);
        }
        if (pcVar18->op == 0x16b) {
          pcVar18->kind = '\f';
          uVar16 = pcVar18->type & 0xfff;
          pcVar18->op = 0x15b;
          if (((pcVar18->type & 0xfff) != 0) && ((uVar16 < 3 || (uVar16 == 4)))) {
            uVar16 = pcVar18->type & 0xfff | 0x2000;
            operand_set_type(pcVar18->dst,uVar16);
            pcVar12 = pcVar18->dst;
            if (((1 << (pcVar12->kind & 0x1f) & 6U) != 0) && (pcVar12->sym->def != (c2_tuple *)0x0))
            {
              set_operand_home(pcVar12,pcVar12->sym);
            }
            operand_set_type(pcVar18->src,uVar16);
            pcVar12 = pcVar18->src;
            if (((1 << (pcVar12->kind & 0x1f) & 6U) != 0) && (pcVar12->sym->def != (c2_tuple *)0x0))
            {
              set_operand_home(pcVar12,pcVar12->sym);
            }
            pcVar18->type = uVar16;
          }
        }
        if ((pcVar18->type & 0xf000) != 0x5000) {
          if (pcVar18->op == 0x15b) {
            if (((((1 << (pcVar18->dst->kind & 0x1f) & 6U) != 0) &&
                 (pcVar17 = pcVar18->dst->sym, pcVar17->cls == '\x03')) &&
                ((1 << (pcVar18->src->kind & 0x1f) & 6U) != 0)) &&
               (pcVar19 = pcVar18->src->sym, pcVar19->cls == '\x03')) {
              pcVar17->flags7 = pcVar17->flags7 | pcVar19->flags7 & 2;
            }
            bVar2 = pcVar18->dst->kind;
            if ((bVar2 == 2) || (pcVar18->src->kind == '\x02')) {
              pcVar17 = (c2_symbol *)0x0;
              if (((1 << (bVar2 & 0x1f) & 6U) != 0) &&
                 ((pcVar19 = pcVar18->dst->sym, pcVar19->cls == '\x03' &&
                  (pcVar19->def == (c2_tuple *)0x0)))) {
                pcVar17 = pcVar19->storage;
                if (pcVar17->order_next == (c2_symbol *)0x0) {
                  pcVar17->order_next = g_touched_temp_list;
                  g_touched_temp_list = pcVar17;
                }
                pcVar6 = pcVar17->defs;
                if (g_list_node_free == (c2_list_cell *)0x0) {
                  refill_list_node_pool();
                }
                pcVar8 = g_list_node_free;
                pcVar1 = &g_list_node_free->u04;
                g_list_node_free = g_list_node_free->next;
                pcVar1->tuple = pcVar18;
                pcVar8->next = pcVar6;
                pcVar17->defs = pcVar8;
              }
              pcVar19 = (c2_symbol *)0x0;
              if ((((1 << (pcVar18->src->kind & 0x1f) & 6U) != 0) &&
                  (pcVar4 = pcVar18->src->sym, pcVar4->cls == '\x03')) &&
                 (pcVar4->def == (c2_tuple *)0x0)) {
                pcVar19 = pcVar4->storage;
                if (pcVar19->order_next == (c2_symbol *)0x0) {
                  pcVar19->order_next = g_touched_temp_list;
                  g_touched_temp_list = pcVar19;
                }
                pcVar6 = pcVar19->uses;
                if (g_list_node_free == (c2_list_cell *)0x0) {
                  refill_list_node_pool();
                }
                pcVar8 = g_list_node_free;
                pcVar1 = &g_list_node_free->u04;
                g_list_node_free = g_list_node_free->next;
                pcVar1->tuple = pcVar18;
                pcVar8->next = pcVar6;
                pcVar19->uses = pcVar8;
              }
              if ((pcVar17 != (c2_symbol *)0x0) && (pcVar19 != (c2_symbol *)0x0)) {
                pcVar6 = (c2_list_cell *)pcVar19->visit_stamp;
                if (g_list_node_free == (c2_list_cell *)0x0) {
                  refill_list_node_pool();
                }
                pcVar8 = g_list_node_free;
                pcVar1 = &g_list_node_free->u04;
                g_list_node_free = g_list_node_free->next;
                pcVar1->tuple = (c2_tuple *)pcVar17;
                pcVar8->next = pcVar6;
                pcVar19->visit_stamp = (uint32_t)pcVar8;
              }
            }
          }
          else {
            pcVar12 = pcVar18->dst;
            if ((((pcVar12 != (c2_operand *)0x0) &&
                 ((uVar9 = 1 << (pcVar12->kind & 0x1f) & 6, uVar9 == 0 ||
                  (pcVar12->sym->def == (c2_tuple *)0x0)))) && (uVar9 != 0)) &&
               ((pcVar12->sym->cls == '\x03' && (uVar3 = pcVar12->type, (uVar3 & 0xf000) != 0x5000))
               )) {
              pcVar10 = operand_new_temp(uVar3);
              pcVar11 = tuple_new(0x15b,uVar3,pcVar12,pcVar10,tuple_insert_after,pcVar18);
              if (pcVar18->flags13 == '\x11') {
                pcVar11->flags13 = '\x11';
              }
              tuple_replace_dst(pcVar18,pcVar12,pcVar10);
              pcVar10->sym->def = pcVar18;
              pcVar11->flags = pcVar11->flags | 0x40;
            }
          }
          bVar7 = true;
          for (pcVar12 = pcVar18->src; pcVar12 != (c2_operand *)0x0; pcVar12 = pcVar12->next) {
            if ((((pcVar12->flags & 0x20) != 0) && ((pcVar12->flags & 0x40) != 0)) &&
               (((1 << (pcVar12->kind & 0x1f) & 6U) == 0 || (pcVar12->sym->def == (c2_tuple *)0x0)))
               ) {
              pcVar14 = tuple_new_unary_temp
                                  (0x15d,pcVar12->type,pcVar12,tuple_insert_before,pcVar18);
              if (pcVar18->flags13 == '\x11') {
                pcVar14->flags13 = '\x11';
              }
              pcVar12 = tuple_replace_src(pcVar18,pcVar12,pcVar14->dst);
            }
            if ((pcVar18->op != 0x15b) &&
               ((((uVar9 = 1 << (pcVar12->kind & 0x1f) & 6, uVar9 == 0 ||
                  (pcVar12->sym->def == (c2_tuple *)0x0)) && (uVar9 != 0)) &&
                ((pcVar12->sym->cls == '\x03' && (uVar3 = pcVar12->type, (uVar3 & 0xf000) != 0x5000)
                 ))))) {
              pcVar10 = operand_new_temp(uVar3);
              pcVar14 = tuple_new(0x15b,uVar3,pcVar10,pcVar12,tuple_insert_before,pcVar18);
              pcVar17 = pcVar12->sym->storage;
              if (pcVar17->order_next == (c2_symbol *)0x0) {
                pcVar17->order_next = g_touched_temp_list;
                g_touched_temp_list = pcVar17;
              }
              pcVar6 = pcVar17->uses;
              if (g_list_node_free == (c2_list_cell *)0x0) {
                refill_list_node_pool();
              }
              pcVar8 = g_list_node_free;
              pcVar1 = &g_list_node_free->u04;
              g_list_node_free = g_list_node_free->next;
              pcVar1->tuple = pcVar14;
              pcVar8->next = pcVar6;
              pcVar17->uses = pcVar8;
              if (pcVar18->flags13 == '\x11') {
                pcVar14->flags13 = '\x11';
              }
              pcVar12 = tuple_replace_src(pcVar18,pcVar12,pcVar10);
              pcVar10->sym->def = pcVar14;
              if (bVar7) {
                bVar7 = false;
                pcVar11 = pcVar14;
              }
              pcVar14->flags = pcVar14->flags | 0x40;
            }
          }
          if (((pcVar18->op == 0x15b) && ((1 << (pcVar18->dst->kind & 0x1f) & 6U) != 0)) &&
             ((pcVar18->dst->sym->def != (c2_tuple *)0x0 && (pcVar18->src->kind == '\x06')))) {
            pcVar18->op = 0x15d;
          }
          else {
            for (pcVar12 = pcVar18->src; pcVar12 != (c2_operand *)0x0; pcVar12 = pcVar12->next) {
              uVar9 = 1 << (pcVar12->kind & 0x1f);
              if ((uVar9 & 0x7e) != 0) {
                if (pcVar12->kind == 6) {
code_r0x1072a089:
                  pcVar14 = tuple_new_unary_temp
                                      (0x15d,pcVar12->type,pcVar12,tuple_insert_before,pcVar18);
                  if (pcVar12->kind == '\x06') {
                    pcVar17 = pcVar12->base->sym->storage;
                  }
                  else {
                    pcVar17 = pcVar12->sym->storage;
                  }
                  if ((pcVar17->cls == '\x03') && (pcVar17->def == (c2_tuple *)0x0)) {
                    if (pcVar17->order_next == (c2_symbol *)0x0) {
                      pcVar17->order_next = g_touched_temp_list;
                      g_touched_temp_list = pcVar17;
                    }
                    pcVar6 = pcVar17->uses;
                    if (g_list_node_free == (c2_list_cell *)0x0) {
                      refill_list_node_pool();
                    }
                    pcVar8 = g_list_node_free;
                    pcVar1 = &g_list_node_free->u04;
                    g_list_node_free = g_list_node_free->next;
                    pcVar1->tuple = pcVar14;
                    pcVar8->next = pcVar6;
                    pcVar17->uses = pcVar8;
                  }
                  if (pcVar18->flags13 == '\x11') {
                    pcVar14->flags13 = '\x11';
                  }
                  pcVar12 = tuple_replace_src(pcVar18,pcVar12,pcVar14->dst);
                  mark_tuple_materialize(pcVar14);
                }
                else if ((pcVar12->flags & 0x40) != 0) {
                  if ((uVar9 & 6) == 0) goto code_r0x1072a089;
                  if (pcVar12->sym->def == (c2_tuple *)0x0) {
                    globopt_canonicalize_tuples_part(pcVar12,pcVar18,pcVar11,fn_00,end);
                    return;
                  }
                }
              }
            }
          }
          mark_tuple_materialize(pcVar18);
        }
        if (pcVar18->kind == '\x12') {
          uVar16 = (pcVar18->u20).intrinsic.id;
          if ((0xab < uVar16) && (uVar16 < 0xae)) {
            tuple_append_int_const(pcVar18,0x2001,'\x01');
          }
        }
        else if (pcVar18->kind == '\x14') {
          if (pcVar18->op == 0x19e) {
            pcVar12 = pcVar18->src;
            if ((((pcVar12 != (c2_operand *)0x0) && ((1 << (pcVar12->kind & 0x1f) & 6U) != 0)) &&
                (pcVar18 = pcVar12->sym->def, pcVar18 != (c2_tuple *)0x0)) && (pcVar18->op == 0x17d)
               ) {
              pcVar18->op = 0x16e;
            }
          }
          else if ((pcVar18->op == 0x1ab) && ((pcVar18->u20).cond_cells != (c2_cond_cell *)0x0)) {
            for (node = (c2_node *)list_last((c2_link *)(pcVar18->u20).cond_cells);
                (node != (c2_node *)0x0 && (node->op != 0x1ac));
                node = (c2_node *)node->rank_or_prev) {
            }
            pcVar12 = *(c2_operand **)&node[1].kind;
            if (((((1 << (pcVar12->kind & 0x1f) & 6U) == 0) || (pcVar12->sym->cls != '\x03')) ||
                (pcVar12->sym->def != (c2_tuple *)0x0)) &&
               (iVar13 = node_has_side_effects((c2_node *)pcVar12), iVar13 == 0)) {
              if (((1 << (pcVar12->kind & 0x1f) & 6U) == 0) ||
                 (pcVar14 = pcVar12->sym->def, pcVar14 == (c2_tuple *)0x0)) {
                if ((((pcVar12->kind != 6) ||
                     ((pcVar10 = pcVar12->base, pcVar10 != (c2_operand *)0x0 &&
                      (((1 << (pcVar10->kind & 0x1f) & 6U) == 0 ||
                       (pcVar10->sym->def == (c2_tuple *)0x0)))))) ||
                    ((pcVar5 = pcVar12->index, pcVar5 != (c2_operand *)0x0 &&
                     (((1 << (pcVar5->kind & 0x1f) & 6U) == 0 ||
                      (pcVar5->sym->def == (c2_tuple *)0x0)))))) ||
                   (pcVar14 = tree_find_def_matching(pcVar10->sym->def,globopt_tree_stop_predicate),
                   pcVar14 != (c2_tuple *)0x0)) goto LAB_1072a195;
                tuple_unlink_free(pcVar18);
              }
              else {
                pcVar14 = tree_find_def_matching(pcVar14,globopt_tree_stop_predicate);
                if (pcVar14 == (c2_tuple *)0x0) {
                  tuple_unlink_free(pcVar18);
                }
                else {
LAB_1072a195:
                  pcVar11 = pcVar18->prev;
                  pcVar18->flags13 = '\x11';
                  if (((1 << (pcVar12->kind & 0x1f) & 6U) == 0) ||
                     (pcVar14 = pcVar12->sym->def, pcVar14 == (c2_tuple *)0x0)) {
                    if (((pcVar12->kind == 6) &&
                        ((pcVar10 = pcVar12->base, pcVar10 == (c2_operand *)0x0 ||
                         (((1 << (pcVar10->kind & 0x1f) & 6U) != 0 &&
                          (pcVar10->sym->def != (c2_tuple *)0x0)))))) &&
                       ((pcVar5 = pcVar12->index, pcVar5 == (c2_operand *)0x0 ||
                        (((1 << (pcVar5->kind & 0x1f) & 6U) != 0 &&
                         (pcVar5->sym->def != (c2_tuple *)0x0)))))) {
                      tree_find_def_matching(pcVar10->sym->def,canonicalize_mark_materialize_pred);
                      pcVar17 = pcVar10->sym;
                      goto LAB_1072a1d0;
                    }
                  }
                  else {
                    tree_find_def_matching(pcVar14,canonicalize_mark_materialize_pred);
                    pcVar17 = pcVar12->sym;
LAB_1072a1d0:
                    move_expression_tree_before(pcVar18,pcVar17->def);
                  }
                  tuple_detach_src(node,pcVar12);
                  tuple_append_src(pcVar18,pcVar12);
                  node_list_free((c2_node *)(pcVar18->u20).cond_cells);
                  (pcVar18->u20).cond_cells = (c2_cond_cell *)0x0;
                  pcVar11 = pcVar11->next;
                }
              }
            }
            else {
              tuple_unlink_free(pcVar18);
            }
          }
        }
      }
      pcVar18 = pcVar11;
    } while (pcVar18 != end);
  }
  return;
}

