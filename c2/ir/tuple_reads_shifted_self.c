int __fastcall tuple_reads_shifted_self(c2_tuple *t,c2_operand *op)

{
  c2_symbol *pcVar1;
  uint32_t uVar2;
  c2_operand *pcVar3;
  c2_symbol *pcVar4;
  bool bVar5;
  c2_operand *local_4;
  
  if ((op->flags & 0x20) == 0) {
    pcVar1 = op->sym;
    uVar2 = t->op;
    if (((uVar2 == 0x172) || (uVar2 == 0x173)) || (uVar2 == 0x174)) {
      bVar5 = true;
    }
    else {
      bVar5 = false;
    }
    pcVar3 = t->dst;
    local_4 = (c2_operand *)t;
    while (((pcVar3 != (c2_operand *)0x0 && ((1 << (t->dst->kind & 0x1f) & 6U) != 0)) &&
           (t->dst->sym->def != (c2_tuple *)0x0))) {
      t = find_next_use_of_dst(t,&local_4);
      uVar2 = t->op;
      if (((uVar2 == 0x172) || (uVar2 == 0x173)) || (uVar2 == 0x174)) {
        bVar5 = true;
      }
      pcVar3 = t->dst;
    }
    if ((((bVar5) && (pcVar3 = t->dst, pcVar3 != (c2_operand *)0x0)) && (pcVar3->kind == '\x02')) &&
       (pcVar4 = pcVar3->sym, pcVar4->storage == pcVar1->storage)) {
      if (pcVar4 != pcVar1) {
        if (pcVar1->size + pcVar1->offset <= pcVar4->offset) {
          return 0;
        }
        if (pcVar4->size + pcVar4->offset <= pcVar1->offset) {
          return 0;
        }
      }
      return 1;
    }
  }
  return 0;
}

