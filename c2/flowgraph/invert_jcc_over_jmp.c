uint32_t __fastcall invert_jcc_over_jmp(c2_block *from,c2_function *fn)

{
  c2_block *pcVar1;
  c2_tuple *pcVar2;
  c2_symbol *pcVar3;
  c2_tuple *pcVar4;
  
  pcVar1 = from->next;
  if (((((pcVar1 != (c2_block *)0x0) && (pcVar2 = from->end->prev, pcVar2->kind == '\x11')) &&
       (((pcVar2->u20).cond_cells != (c2_cond_cell *)0x0 || (pcVar2->op == 0x18b)))) &&
      ((((((pcVar2->src->kind == '\x04' && (*(int *)((int)&pcVar2->src->sym->u30 + 2) != 0)) &&
          (pcVar4 = tuple_next_real_in_block(pcVar1->head), pcVar4 != (c2_tuple *)0x0)) &&
         ((pcVar4->kind == '\x11' && ((pcVar4->u20).cond_cells == (c2_cond_cell *)0x0)))) &&
        (pcVar4->op != 0x18b)) &&
       ((pcVar4->src->kind == '\x04' &&
        (pcVar3 = pcVar4->src->sym, *(int *)((int)&pcVar3->u30 + 2) != 0)))))) &&
     ((pcVar4->flags & 8) == 0)) {
    if ((((pcVar1->loop == (c2_loop *)0x0) || (pcVar1 != pcVar1->loop->last)) &&
        ((from->succs->to == pcVar1->next || (from->succs->next_succ->to == pcVar1->next)))) &&
       (((pcVar2->flags & 8) == 0 && (pcVar3 != pcVar2->src->sym)))) {
      invert_branch_over_jump_swap(from,fn);
      return 1;
    }
  }
  return 0;
}

