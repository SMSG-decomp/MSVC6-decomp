c2_tuple * __fastcall seh_move_finally_block(c2_tuple *t,c2_tuple **cursor)

{
  c2_tuple *pcVar1;
  c2_tuple *t_00;
  c2_tuple *pcVar2;
  
  pcVar1 = t;
  if (*cursor == (c2_tuple *)0x0) {
    while ((pcVar1 != (c2_tuple *)0x0 &&
           ((pcVar1->kind != '\x1a' || (*(char *)&pcVar1->src[1].next != 'G'))))) {
      pcVar1 = pcVar1->next;
    }
    *cursor = pcVar1;
  }
  pcVar1 = *cursor;
  do {
    if (pcVar1 == (c2_tuple *)0x0) {
LAB_107877d5:
      return t->next;
    }
    if ((pcVar1->kind == '\x1a') && ((c2_symbol *)pcVar1->src == t->src->sym)) {
      if (pcVar1 != (c2_tuple *)0x0) {
        for (t_00 = pcVar1->next;
            (t_00 != (c2_tuple *)0x0 && (((t_00->flags & 1) == 0 || (t_00->op != 0x186))));
            t_00 = t_00->next) {
        }
        pcVar2 = t_00->prev;
        tuple_unlink_free(t_00);
        pcVar1->prev->next = pcVar2->next;
        pcVar2->next->prev = pcVar1->prev;
        pcVar1->prev = (c2_tuple *)0x0;
        pcVar2->next = (c2_tuple *)0x0;
        tuple_splice_after(t,pcVar1);
        return t->next;
      }
      goto LAB_107877d5;
    }
    pcVar1 = pcVar1->next;
  } while( true );
}

