c2_tuple * __fastcall follow_trivial_branch_chain(c2_block **b)

{
  uint8_t uVar1;
  c2_block *pcVar2;
  c2_tuple *t;
  c2_tuple *pcVar3;
  uint uVar4;
  
  uVar4 = 0;
  t = (*b)->head;
  do {
    while( true ) {
      while (pcVar3 = tuple_next_real_before_boundary(t), pcVar3 == (c2_tuple *)0x0) {
        pcVar2 = (*b)->next;
        *b = pcVar2;
        if (pcVar2 == (c2_block *)0x0) {
          return (c2_tuple *)0x0;
        }
        t = pcVar2->head;
      }
      if (((((pcVar3->kind != '\x11') || ((pcVar3->u20).cond_cells != (c2_cond_cell *)0x0)) ||
           (pcVar3->op == 0x18b)) ||
          ((pcVar3->src->kind != '\x04' ||
           (t = *(c2_tuple **)&(pcVar3->src->sym->u30).globopt.marks, t == (c2_tuple *)0x0)))) ||
         ((pcVar3->flags & 8) != 0)) break;
      uVar4 = uVar4 + 1;
      *b = (c2_block *)t->u14;
      if (10 < uVar4) {
        return t;
      }
    }
    uVar1 = pcVar3->flags13;
    t = pcVar3;
  } while (((uVar1 == '\x01') || (uVar1 == '\x02')) || (uVar1 == '\x11'));
  return pcVar3;
}

