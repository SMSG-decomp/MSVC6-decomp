void __fastcall propagate_temp_copies_in_loop(c2_loop *loop)

{
  c2_operand *a;
  c2_tuple *t;
  int iVar1;
  c2_block *pcVar2;
  c2_tuple *pcVar3;
  
  pcVar2 = loop->first;
  if (pcVar2 != loop->last->next) {
    do {
      pcVar3 = pcVar2->head->next;
      if (pcVar3 != pcVar2->end) {
        do {
          if ((((((pcVar3->op == 0x15b) && (a = pcVar3->dst, (1 << (a->kind & 0x1f) & 6U) != 0)) &&
                (a->sym->cls == '\x03')) &&
               (((1 << (pcVar3->src->kind & 0x1f) & 6U) != 0 &&
                (pcVar3->src->sym->def == (c2_tuple *)0x0)))) &&
              ((t = pcVar3->next, t->op == 0x15b &&
               ((iVar1 = operand_compare(a,t->src), iVar1 == 0 &&
                (iVar1 = node_has_side_effects((c2_node *)pcVar3->src), iVar1 == 0)))))) &&
             (iVar1 = node_has_side_effects((c2_node *)t->src), iVar1 == 0)) {
            tuple_replace_src(t,t->src,pcVar3->src);
            number_assignment(t,1);
          }
          pcVar3 = pcVar3->next;
        } while (pcVar3 != pcVar2->end);
      }
      pcVar2 = pcVar2->next;
    } while (pcVar2 != loop->last->next);
  }
  return;
}

