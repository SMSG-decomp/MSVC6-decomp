void __fastcall lower_int64_compare_operands(c2_tuple *anchor)

{
  c2_operand *pcVar1;
  c2_tuple *t;
  c2_operand *src;
  c2_tuple *pcVar2;
  uint uVar3;
  c2_tuple *pcVar4;
  c2_tuple *pcVar5;
  
  pcVar2 = find_next_use_of_symbol((c2_node *)anchor,anchor->dst->sym,(c2_operand **)0x0);
  pcVar1 = anchor->src;
  while (src = pcVar1, src != (c2_operand *)0x0) {
    pcVar1 = src->next;
    uVar3 = 1 << (src->kind & 0x1f);
    if (((uVar3 & 0x60) != 0) ||
       (((uVar3 & 0x1e) != 0 &&
        ((((uVar3 & 6) == 0 || (src->sym->def == (c2_tuple *)0x0)) && ((src->flags & 0x20) == 0)))))
       ) {
      pcVar4 = tuple_new_unary_temp(0x15b,src->type,src,tuple_insert_before,anchor);
      tuple_replace_src(anchor,src,pcVar4->dst);
      lower_tuple(pcVar4);
    }
  }
  pcVar4 = pcVar2->prev->next;
  pcVar5 = anchor->next;
  while (t = pcVar5, t != pcVar4) {
    pcVar5 = t->next;
    if (((t->flags & 1) != 0) &&
       (((t->type & 0xf000) == 0x4000 || ((t->op != 0x15a && (t->op != 0x16a)))))) {
      pcVar5 = lower_tuple(t);
    }
  }
  pcVar2 = pcVar2->prev->next;
  pcVar4 = anchor->next;
  while (pcVar5 = pcVar4, pcVar5 != pcVar2) {
    pcVar4 = pcVar5->next;
    if ((pcVar5->flags & 1) != 0) {
      tuple_move_before(anchor,pcVar5);
    }
  }
  return;
}

