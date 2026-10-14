c2_edge * __fastcall
thread_jump_to_successor(c2_function *fn,c2_edge *e,c2_tuple *t,int taken,c2_block *succ)

{
  byte bVar1;
  c2_block *block;
  c2_block *to;
  c2_tuple *t_00;
  c2_edge *pcVar2;
  c2_fe_symbol *label_sym;
  c2_tuple *pcVar3;
  c2_tuple *pcVar4;
  
  block = e->from;
  to = e->to;
  pcVar4 = to->head->next;
  if (taken == 0) {
    pcVar3 = t->next;
    if (((pcVar3->kind == '\x11') && ((pcVar3->u20).cond_cells == (c2_cond_cell *)0x0)) &&
       (pcVar3->op != 0x18b)) {
      pcVar3 = *(c2_tuple **)&(pcVar3->src->sym->u30).globopt.marks;
    }
    else {
      pcVar3 = pcVar3->next;
      if (pcVar3->kind != '\x1a') {
        if (t->line != 0) {
          g_current_line_abs = fn->line_base + (uint)t->line;
          g_cur_line = t->line;
        }
        label_sym = label_symbol_new();
        pcVar3 = tuple_new_label(label_sym);
        tuple_insert_after(t->next,pcVar3);
        pcVar3->u14 = (c2_tuple_u14)succ->next;
      }
    }
  }
  else {
    pcVar3 = *(c2_tuple **)&(t->src->sym->u30).globopt.marks;
  }
  t_00 = tuple_prev_real_in_block(block->end);
  if (t_00 == (c2_tuple *)0x0) {
LAB_1074c6fb:
    pcVar4 = tuple_next_real(block->end);
    if (pcVar4->line != 0) {
      g_current_line_abs = fn->line_base + (uint)pcVar4->line;
      g_cur_line = pcVar4->line;
    }
    tuple_new_jmp_before(pcVar3,block->end);
  }
  else {
    bVar1 = t_00->kind;
    if (((bVar1 == 0x11) && ((t_00->u20).cond_cells == (c2_cond_cell *)0x0)) &&
       ((t_00->op != 0x18b && (*(c2_tuple **)((int)&t_00->src->sym->u30 + 2) != pcVar4)))) {
      t_00 = tuple_prev_real_before_boundary(t_00);
    }
    else {
      if (((1 << (bVar1 & 0x1f) & 0xa0000U) == 0) ||
         (((bVar1 == 0x11 &&
           (((t_00->u20).cond_cells != (c2_cond_cell *)0x0 || (t_00->op == 0x18b)))) &&
          (*(c2_tuple **)((int)&t_00->src->sym->u30 + 2) != pcVar4)))) goto LAB_1074c6fb;
      if ((bVar1 == 0x13) && ((c2_tuple *)(t_00->u20).cond_cells != pcVar4)) {
        for (t_00 = (c2_tuple *)(t_00->u24).cases;
            (t_00 != (c2_tuple *)0x0 && ((t_00->u14).arg != pcVar4)); t_00 = t_00->next) {
        }
      }
    }
    tuple_retarget(t_00,(c2_node *)pcVar3,1);
  }
  if (to == (pcVar3->u14).arg) {
    return e->next_succ;
  }
  pcVar2 = flow_edge_find(block,to);
  while (pcVar2 != (c2_edge *)0x0) {
    e = cfg_add_edge(fn,block,(pcVar3->u14).block);
    compute_dominators(fn);
    remove_loop_back_edge(block,to,fn);
    pcVar2 = flow_edge_find(block,to);
  }
  return e;
}

