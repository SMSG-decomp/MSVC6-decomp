c2_block * __fastcall
split_edge_with_new_block(c2_function *fn,void *edge,c2_block *pred,c2_block *succ)

{
  uint8_t uVar1;
  uint16_t uVar2;
  c2_tuple *pcVar3;
  c2_tuple *pcVar4;
  c2_block *to;
  c2_block *referrer;
  c2_fe_symbol *label_sym;
  c2_tuple *pcVar5;
  
  cfg_remove_edge(fn,edge);
  pcVar4 = tuple_new_block_boundary();
  tuple_insert_before(succ->head,pcVar4);
  to = block_new(fn,succ,pcVar4,succ->head);
  to->loop_depth = succ->loop_depth;
  to->eh_state = succ->eh_state;
  cfg_add_edge(fn,pred,to);
  cfg_add_edge(fn,to,succ);
  for (pcVar4 = succ->head; (pcVar4 != (c2_tuple *)0x0 && (pcVar4->kind != '\x1a'));
      pcVar4 = pcVar4->next) {
  }
  pcVar5 = pred->end;
  while ((pcVar5 != (c2_tuple *)0x0 && ((1 << (pcVar5->kind & 0x1f) & 0xa0000U) == 0))) {
    pcVar5 = pcVar5->prev;
  }
  if ((1 << (pcVar5->kind & 0x1f) & 0xa0000U) == 0) {
    referrer = pred;
    if (pred != (c2_block *)0x0) {
LAB_10713d8b:
      label_sym = label_symbol_new();
      pcVar5 = label_insert_in_block(label_sym,to);
      tuple_retarget((c2_tuple *)referrer,(c2_node *)pcVar5,1);
      uVar2 = to->end->prev->line;
      if (uVar2 != 0) {
        g_current_line_abs = (uint)to->end->prev->line + fn->line_base;
        g_cur_line = uVar2;
      }
      tuple_new_jmp_before(pcVar4,to->end);
    }
  }
  else {
    do {
      referrer = (c2_block *)branch_targets_label(pcVar5,pcVar4);
      if (referrer != (c2_block *)0x0) goto LAB_10713d8b;
      pcVar5 = pcVar5->prev;
      uVar1 = pcVar5->kind;
      while (uVar1 == '\x1b') {
        pcVar5 = pcVar5->prev;
        uVar1 = pcVar5->kind;
      }
    } while ((1 << (pcVar5->kind & 0x1f) & 0xa0000U) != 0);
  }
  pcVar5 = to->head;
  pcVar3 = pcVar5;
  if (pcVar5 != pred->end) {
    for (; pcVar3 != (c2_tuple *)0x0; pcVar3 = pcVar3->prev) {
      if (((pcVar3->flags & 1) != 0) || (pcVar3->kind == '\x1a')) {
        if ((pcVar3 != (c2_tuple *)0x0) &&
           (((pcVar3->kind == '\x11' && ((pcVar3->u20).cond_cells == (c2_cond_cell *)0x0)) &&
            (pcVar3->op != 0x18b)))) {
          return to;
        }
        break;
      }
    }
    uVar2 = pcVar5->prev->line;
    if (uVar2 != 0) {
      g_current_line_abs = (uint)to->head->prev->line + fn->line_base;
      g_cur_line = uVar2;
    }
    tuple_new_jmp_before(pcVar4,to->head);
  }
  return to;
}

