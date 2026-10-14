void globopt_canonicalize_tuples_part
               (c2_operand *opnd,c2_tuple *t,c2_tuple *next,c2_function *fn,c2_tuple *end)

{
  c2_list_cell_u04 *pcVar1;
  byte bVar2;
  uint16_t uVar3;
  c2_symbol *pcVar4;
  c2_operand *pcVar5;
  c2_list_cell *pcVar6;
  c2_operand *pcVar7;
  c2_list_cell *pcVar8;
  uint uVar9;
  c2_operand *pcVar10;
  c2_operand *pcVar11;
  c2_tuple *pcVar12;
  int iVar13;
  c2_const_operand *pcVar14;
  ushort uVar15;
  c2_symbol *pcVar16;
  c2_symbol *pcVar17;
  c2_node *in_stack_00000014;
  c2_operand *in_stack_00000020;
  
code_r0x1072a089:
  do {
    pcVar12 = tuple_new_unary_temp(0x15d,opnd->type,opnd,tuple_insert_before,t);
    if (opnd->kind == '\x06') {
      pcVar16 = opnd->base->sym->storage;
    }
    else {
      pcVar16 = opnd->sym->storage;
    }
    if ((pcVar16->cls == '\x03') && (pcVar16->def == (c2_tuple *)0x0)) {
      if (pcVar16->order_next == (c2_symbol *)0x0) {
        pcVar16->order_next = g_touched_temp_list;
        g_touched_temp_list = pcVar16;
      }
      in_stack_00000020 = (c2_operand *)pcVar16->uses;
      if (g_list_node_free == (c2_list_cell *)0x0) {
        refill_list_node_pool();
      }
      pcVar6 = g_list_node_free;
      pcVar1 = &g_list_node_free->u04;
      g_list_node_free = g_list_node_free->next;
      pcVar1->tuple = pcVar12;
      pcVar6->next = (c2_list_cell *)in_stack_00000020;
      pcVar16->uses = pcVar6;
    }
    if (t->flags13 == '\x11') {
      pcVar12->flags13 = '\x11';
    }
    opnd = tuple_replace_src(t,opnd,pcVar12->dst);
    mark_tuple_materialize(pcVar12);
LAB_10729cc3:
    do {
      do {
        opnd = opnd->next;
joined_r0x10729cc7:
        if (opnd == (c2_operand *)0x0) {
          do {
            mark_tuple_materialize(t);
            pcVar11 = (c2_operand *)next;
            do {
              next = (c2_tuple *)pcVar11;
              pcVar11 = (c2_operand *)next;
              if (t->kind == '\x12') {
                uVar15 = (t->u20).intrinsic.id;
                if ((0xab < uVar15) && (uVar15 < 0xae)) {
                  tuple_append_int_const(t,0x2001,'\x01');
                }
              }
              else if (t->kind == '\x14') {
                if (t->op == 0x19e) {
                  pcVar5 = t->src;
                  if ((((pcVar5 != (c2_operand *)0x0) && ((1 << (pcVar5->kind & 0x1f) & 6U) != 0))
                      && (pcVar12 = pcVar5->sym->def, pcVar12 != (c2_tuple *)0x0)) &&
                     (pcVar12->op == 0x17d)) {
                    pcVar12->op = 0x16e;
                  }
                }
                else if ((t->op == 0x1ab) && ((t->u20).tuples != (c2_tuple *)0x0)) {
                  for (in_stack_00000014 = (c2_node *)list_last((c2_link *)(t->u20).tuples);
                      (in_stack_00000014 != (c2_node *)0x0 && (in_stack_00000014->op != 0x1ac));
                      in_stack_00000014 = (c2_node *)in_stack_00000014->rank_or_prev) {
                  }
                  pcVar5 = *(c2_operand **)&in_stack_00000014[1].kind;
                  if (((((1 << (pcVar5->kind & 0x1f) & 6U) == 0) || (pcVar5->sym->cls != '\x03')) ||
                      (pcVar5->sym->def != (c2_tuple *)0x0)) &&
                     (iVar13 = node_has_side_effects((c2_node *)pcVar5), iVar13 == 0)) {
                    if (((1 << (pcVar5->kind & 0x1f) & 6U) == 0) ||
                       (pcVar12 = pcVar5->sym->def, pcVar12 == (c2_tuple *)0x0)) {
                      if ((((pcVar5->kind != 6) ||
                           ((pcVar10 = pcVar5->base, pcVar10 != (c2_operand *)0x0 &&
                            (((1 << (pcVar10->kind & 0x1f) & 6U) == 0 ||
                             (pcVar10->sym->def == (c2_tuple *)0x0)))))) ||
                          ((pcVar7 = pcVar5->index, pcVar7 != (c2_operand *)0x0 &&
                           (((1 << (pcVar7->kind & 0x1f) & 6U) == 0 ||
                            (pcVar7->sym->def == (c2_tuple *)0x0)))))) ||
                         (pcVar12 = tree_find_def_matching
                                              (pcVar10->sym->def,globopt_tree_stop_predicate),
                         pcVar12 != (c2_tuple *)0x0)) goto LAB_1072a195;
                      tuple_unlink_free(t);
                    }
                    else {
                      pcVar12 = tree_find_def_matching(pcVar12,globopt_tree_stop_predicate);
                      if (pcVar12 == (c2_tuple *)0x0) {
                        tuple_unlink_free(t);
                      }
                      else {
LAB_1072a195:
                        in_stack_00000020 = (c2_operand *)t->prev;
                        t->flags13 = '\x11';
                        if (((1 << (pcVar5->kind & 0x1f) & 6U) == 0) ||
                           (pcVar12 = pcVar5->sym->def, pcVar12 == (c2_tuple *)0x0)) {
                          if (((pcVar5->kind == 6) &&
                              ((pcVar11 = pcVar5->base, pcVar11 == (c2_operand *)0x0 ||
                               (((1 << (pcVar11->kind & 0x1f) & 6U) != 0 &&
                                (pcVar11->sym->def != (c2_tuple *)0x0)))))) &&
                             ((pcVar10 = pcVar5->index, pcVar10 == (c2_operand *)0x0 ||
                              (((1 << (pcVar10->kind & 0x1f) & 6U) != 0 &&
                               (pcVar10->sym->def != (c2_tuple *)0x0)))))) {
                            tree_find_def_matching
                                      (pcVar11->sym->def,canonicalize_mark_materialize_pred);
                            pcVar16 = pcVar11->sym;
                            goto LAB_1072a1d0;
                          }
                        }
                        else {
                          tree_find_def_matching(pcVar12,canonicalize_mark_materialize_pred);
                          pcVar16 = pcVar5->sym;
LAB_1072a1d0:
                          move_expression_tree_before(t,pcVar16->def);
                        }
                        tuple_detach_src(in_stack_00000014,pcVar5);
                        tuple_append_src(t,pcVar5);
                        node_list_free((c2_node *)(t->u20).tuples);
                        (t->u20).tuples = (c2_tuple *)0x0;
                        pcVar11 = in_stack_00000020->next;
                      }
                    }
                  }
                  else {
                    tuple_unlink_free(t);
                  }
                }
              }
              do {
                next = (c2_tuple *)pcVar11;
                t = next;
                if (next == end) {
                  return;
                }
                pcVar11 = (c2_operand *)next->next;
              } while (((next->flags & 1) == 0) || (next->op == 0x15d));
              if (((g_opt_dlp != 0) &&
                  (((next->op == 0x15b && ((1 << (next->dst->kind & 0x1f) & 6U) != 0)) &&
                   (next->dst->sym->def != (c2_tuple *)0x0)))) && (next->src->kind == '\x03')) {
                next->op = 0x169;
              }
              if (next->line != 0) {
                g_current_line_abs = fn->line_base + (uint)next->line;
                g_cur_line = next->line;
              }
              for (pcVar5 = next->src; pcVar5 != (c2_operand *)0x0; pcVar5 = pcVar5->next) {
                if (((1 << (pcVar5->kind & 0x1f) & 0x60U) != 0) && (pcVar5->op != 0x14c)) {
                  pcVar14 = operand_new_intconst(0x2004,pcVar5->disp,pcVar5->disp >> 0x1f);
                  pcVar12 = tuple_new_unary_temp(0x15d,0x2004,pcVar14,tuple_insert_before,next);
                  pcVar5->op = 0x14c;
                  if (next->flags13 == '\x11') {
                    pcVar12->flags13 = '\x11';
                  }
                  pcVar5->disp = 0;
                  pcVar10 = (c2_operand *)node_clone((c2_node *)pcVar12->dst);
                  pcVar5->base = pcVar10;
                  pcVar10->flags = pcVar10->flags | 0x20;
                  pcVar5->base->flags = pcVar5->base->flags | 0x10;
                  tuple_append_base_index(next,pcVar5);
                }
              }
              for (pcVar5 = next->dst; pcVar5 != (c2_operand *)0x0; pcVar5 = pcVar5->next) {
                if (((1 << (pcVar5->kind & 0x1f) & 0x60U) != 0) && (pcVar5->op != 0x14c)) {
                  pcVar14 = operand_new_intconst(0x2004,pcVar5->disp,pcVar5->disp >> 0x1f);
                  pcVar12 = tuple_new_unary_temp(0x15d,0x2004,pcVar14,tuple_insert_before,next);
                  if (next->flags13 == '\x11') {
                    pcVar12->flags13 = '\x11';
                  }
                  pcVar5->op = 0x14c;
                  pcVar5->disp = 0;
                  pcVar10 = (c2_operand *)node_clone((c2_node *)pcVar12->dst);
                  pcVar5->base = pcVar10;
                  pcVar10->flags = pcVar10->flags | 0x20;
                  pcVar5->base->flags = pcVar5->base->flags | 0x10;
                  tuple_append_base_index(next,pcVar5);
                }
              }
              if (((next->op == 0x15b) && (next->dst->kind == '\x02')) &&
                 (pcVar16 = next->dst->sym->storage, pcVar16->storage->fe != (c2_fe_symbol *)0x0)) {
                bitset_set(g_fwdprop_candidate_syms,pcVar16->id);
              }
              if (next->op == 0x16b) {
                next->kind = '\f';
                uVar15 = next->type & 0xfff;
                next->op = 0x15b;
                if (((next->type & 0xfff) != 0) && ((uVar15 < 3 || (uVar15 == 4)))) {
                  uVar15 = next->type & 0xfff | 0x2000;
                  operand_set_type(next->dst,uVar15);
                  pcVar5 = next->dst;
                  if (((1 << (pcVar5->kind & 0x1f) & 6U) != 0) &&
                     (pcVar5->sym->def != (c2_tuple *)0x0)) {
                    set_operand_home(pcVar5,pcVar5->sym);
                  }
                  operand_set_type(next->src,uVar15);
                  pcVar5 = next->src;
                  if (((1 << (pcVar5->kind & 0x1f) & 6U) != 0) &&
                     (pcVar5->sym->def != (c2_tuple *)0x0)) {
                    set_operand_home(pcVar5,pcVar5->sym);
                  }
                  next->type = uVar15;
                }
              }
            } while ((next->type & 0xf000) == 0x5000);
            if (next->op == 0x15b) {
              if (((((1 << (next->dst->kind & 0x1f) & 6U) != 0) &&
                   (pcVar16 = next->dst->sym, pcVar16->cls == '\x03')) &&
                  ((1 << (next->src->kind & 0x1f) & 6U) != 0)) &&
                 (pcVar17 = next->src->sym, pcVar17->cls == '\x03')) {
                pcVar16->flags7 = pcVar16->flags7 | pcVar17->flags7 & 2;
              }
              bVar2 = next->dst->kind;
              if ((bVar2 == 2) || (next->src->kind == '\x02')) {
                pcVar16 = (c2_symbol *)0x0;
                if (((1 << (bVar2 & 0x1f) & 6U) != 0) &&
                   ((pcVar17 = next->dst->sym, pcVar17->cls == '\x03' &&
                    (pcVar17->def == (c2_tuple *)0x0)))) {
                  pcVar16 = pcVar17->storage;
                  if (pcVar16->order_next == (c2_symbol *)0x0) {
                    pcVar16->order_next = g_touched_temp_list;
                    g_touched_temp_list = pcVar16;
                  }
                  pcVar6 = pcVar16->defs;
                  if (g_list_node_free == (c2_list_cell *)0x0) {
                    refill_list_node_pool();
                  }
                  pcVar8 = g_list_node_free;
                  pcVar1 = &g_list_node_free->u04;
                  g_list_node_free = g_list_node_free->next;
                  pcVar1->tuple = next;
                  pcVar8->next = pcVar6;
                  pcVar16->defs = pcVar8;
                }
                pcVar17 = (c2_symbol *)0x0;
                if ((((1 << (next->src->kind & 0x1f) & 6U) != 0) &&
                    (pcVar4 = next->src->sym, pcVar4->cls == '\x03')) &&
                   (pcVar4->def == (c2_tuple *)0x0)) {
                  pcVar17 = pcVar4->storage;
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
                  pcVar1->tuple = next;
                  pcVar8->next = pcVar6;
                  pcVar17->uses = pcVar8;
                }
                if ((pcVar16 != (c2_symbol *)0x0) && (pcVar17 != (c2_symbol *)0x0)) {
                  pcVar6 = (c2_list_cell *)pcVar17->visit_stamp;
                  if (g_list_node_free == (c2_list_cell *)0x0) {
                    refill_list_node_pool();
                  }
                  pcVar8 = g_list_node_free;
                  pcVar1 = &g_list_node_free->u04;
                  g_list_node_free = g_list_node_free->next;
                  pcVar1->sym = pcVar16;
                  pcVar8->next = pcVar6;
                  pcVar17->visit_stamp = (uint32_t)pcVar8;
                }
              }
            }
            else {
              pcVar5 = next->dst;
              if ((((pcVar5 != (c2_operand *)0x0) &&
                   ((uVar9 = 1 << (pcVar5->kind & 0x1f) & 6, uVar9 == 0 ||
                    (pcVar5->sym->def == (c2_tuple *)0x0)))) && (uVar9 != 0)) &&
                 ((pcVar5->sym->cls == '\x03' && (uVar3 = pcVar5->type, (uVar3 & 0xf000) != 0x5000))
                 )) {
                pcVar10 = operand_new_temp(uVar3);
                pcVar11 = (c2_operand *)
                          tuple_new(0x15b,uVar3,pcVar5,pcVar10,tuple_insert_after,next);
                if (next->flags13 == '\x11') {
                  ((c2_tuple *)pcVar11)->flags13 = '\x11';
                }
                tuple_replace_dst(next,pcVar5,pcVar10);
                pcVar10->sym->def = next;
                ((c2_tuple *)pcVar11)->flags = ((c2_tuple *)pcVar11)->flags | 0x40;
              }
            }
            next = (c2_tuple *)pcVar11;
            pcVar11 = t->src;
            in_stack_00000014 = (c2_node *)0x1;
            for (; pcVar11 != (c2_operand *)0x0; pcVar11 = pcVar11->next) {
              if ((((pcVar11->flags & 0x20) != 0) && ((pcVar11->flags & 0x40) != 0)) &&
                 (((1 << (pcVar11->kind & 0x1f) & 6U) == 0 || (pcVar11->sym->def == (c2_tuple *)0x0)
                  ))) {
                pcVar12 = tuple_new_unary_temp(0x15d,pcVar11->type,pcVar11,tuple_insert_before,t);
                if (t->flags13 == '\x11') {
                  pcVar12->flags13 = '\x11';
                }
                pcVar11 = tuple_replace_src(t,pcVar11,pcVar12->dst);
              }
              if (((t->op != 0x15b) &&
                  (((uVar9 = 1 << (pcVar11->kind & 0x1f) & 6, uVar9 == 0 ||
                    (pcVar11->sym->def == (c2_tuple *)0x0)) && (uVar9 != 0)))) &&
                 ((pcVar11->sym->cls == '\x03' &&
                  (uVar3 = pcVar11->type, (uVar3 & 0xf000) != 0x5000)))) {
                in_stack_00000020 = operand_new_temp(uVar3);
                pcVar12 = tuple_new(0x15b,uVar3,in_stack_00000020,pcVar11,tuple_insert_before,t);
                pcVar16 = pcVar11->sym->storage;
                if (pcVar16->order_next == (c2_symbol *)0x0) {
                  pcVar16->order_next = g_touched_temp_list;
                  g_touched_temp_list = pcVar16;
                }
                pcVar6 = pcVar16->uses;
                if (g_list_node_free == (c2_list_cell *)0x0) {
                  refill_list_node_pool();
                }
                pcVar5 = in_stack_00000020;
                pcVar8 = g_list_node_free;
                pcVar1 = &g_list_node_free->u04;
                g_list_node_free = g_list_node_free->next;
                pcVar1->tuple = pcVar12;
                pcVar8->next = pcVar6;
                pcVar16->uses = pcVar8;
                if (t->flags13 == '\x11') {
                  pcVar12->flags13 = '\x11';
                }
                pcVar11 = tuple_replace_src(t,pcVar11,in_stack_00000020);
                pcVar5->sym->def = pcVar12;
                if (in_stack_00000014 != (c2_node *)0x0) {
                  in_stack_00000014 = (c2_node *)0x0;
                  next = pcVar12;
                }
                pcVar12->flags = pcVar12->flags | 0x40;
              }
            }
            if (((t->op != 0x15b) || ((1 << (t->dst->kind & 0x1f) & 6U) == 0)) ||
               ((t->dst->sym->def == (c2_tuple *)0x0 || (t->src->kind != '\x06'))))
            goto LAB_10729c9b;
            t->op = 0x15d;
          } while( true );
        }
        uVar9 = 1 << (opnd->kind & 0x1f);
      } while ((uVar9 & 0x7e) == 0);
      if (opnd->kind == 6) goto code_r0x1072a089;
    } while ((opnd->flags & 0x40) == 0);
  } while ((uVar9 & 6) == 0);
  if (opnd->sym->def == (c2_tuple *)0x0) {
    globopt_canonicalize_tuples_part(opnd,t,next,fn,end);
    return;
  }
  goto LAB_10729cc3;
LAB_10729c9b:
  opnd = t->src;
  goto joined_r0x10729cc7;
}

