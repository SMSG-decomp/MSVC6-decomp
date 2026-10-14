int __fastcall tuple_reaches_in_straight_line(c2_tuple *t,c2_tuple *t2)

{
  c2_edge *pcVar1;
  c2_block *pcVar2;
  c2_block *pcVar3;
  
  pcVar2 = tuple_get_block(t);
  pcVar3 = tuple_get_block(t2);
  if (pcVar2 == pcVar3) {
    for (; (t2 != (c2_tuple *)0x0 && (t2->kind != '\x19')); t2 = t2->next) {
      if (t2 == t) {
        return 1;
      }
    }
  }
  else {
    while (((pcVar3->rpo <= pcVar2->rpo && (pcVar1 = pcVar3->succs, pcVar1 != (c2_edge *)0x0)) &&
           (pcVar1->next_succ == (c2_edge *)0x0))) {
      pcVar3 = pcVar1->to;
      if (pcVar2 == pcVar3) {
        return 1;
      }
    }
    if (pcVar2 == pcVar3) {
      return 1;
    }
  }
  return 0;
}

