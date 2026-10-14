void __fastcall record_iv_update_clones(c2_loop *loop)

{
  c2_block *pcVar1;
  c2_operand *opnd;
  c2_list_cell *pcVar2;
  c2_tuple *t;
  uint32_t uVar3;
  c2_list_cell *cell;
  c2_tuple *clone;
  c2_operand *step_source;
  c2_tuple *pcVar4;
  c2_operand *step;
  
  if (loop->trip_count != (c2_operand *)0x0) {
    pcVar1 = loop->preheader;
    pcVar4 = pcVar1->head->next;
    if (pcVar4 != pcVar1->end) {
      do {
        if (pcVar4->op == 0x15b) {
          opnd = pcVar4->dst;
          uVar3 = is_induction_variable_operand(opnd);
          if ((((uVar3 != 0) && (pcVar2 = opnd->sym->defs, pcVar2 != (c2_list_cell *)0x0)) &&
              (pcVar2->next == (c2_list_cell *)0x0)) &&
             ((((((pcVar2->u04).tuple)->flags13 == '\x04' &&
                (t = ((pcVar2->u04).tuple)->prev, t->flags13 == '\x04')) &&
               ((t->op == 0x16d || (t->op == 0x16e)))) &&
              (uVar3 = block_range_dominated(t,loop->exit_compare), uVar3 != 0)))) {
            cell = arena_alloc(0xd,8);
            clone = (c2_tuple *)node_clone((c2_node *)t);
            step_source = iv_find_copy_source(clone->src->next,loop);
            step = clone->src->next;
            if (step_source != step) {
              tuple_replace_src(clone,step,step_source);
            }
            (cell->u04).tuple = clone;
            cell->next = (c2_list_cell *)loop->u30;
            (loop->u30).iv_update_clones = cell;
          }
        }
        pcVar4 = pcVar4->next;
      } while (pcVar4 != pcVar1->end);
    }
  }
  return;
}

