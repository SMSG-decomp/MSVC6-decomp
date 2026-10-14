int __fastcall label_try_remove(c2_tuple *t)

{
  c2_operand *pcVar1;
  c2_tuple *t_00;
  c2_tuple *pcVar2;
  
  pcVar1 = t->dst;
  if ((((pcVar1 != (c2_operand *)0x0) &&
       (pcVar2 = (c2_tuple *)pcVar1->rank, pcVar2 != (c2_tuple *)0x0)) &&
      (pcVar1->next == (c2_operand *)0x0)) && ((pcVar2 == t->prev && (pcVar2->op == 0x186)))) {
    tuple_unlink(pcVar2);
    node_free((c2_node *)pcVar2);
  }
  if ((t->dst == (c2_operand *)0x0) && ((t->src[1].rank & 0x10000) == 0)) {
    if (*(char *)&t->src[1].next == '\0') {
      g_cur_line = 0;
      t_00 = tuple_new_marker(0x1bc);
      t_00->u14 = (c2_tuple_u14)t->src;
      pcVar2 = tuple_next_real(t);
      if (pcVar2 == (c2_tuple *)0x0) {
        pcVar2 = t;
      }
      tuple_insert_before(pcVar2,t_00);
    }
    label_delete(t);
    return 1;
  }
  return 0;
}

