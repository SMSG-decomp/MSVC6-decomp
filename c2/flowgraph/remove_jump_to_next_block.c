int __fastcall remove_jump_to_next_block(c2_block *b)

{
  c2_edge *pcVar1;
  c2_tuple *t;
  
  if (b->next != (c2_block *)0x0) {
    for (pcVar1 = b->succs; pcVar1 != (c2_edge *)0x0; pcVar1 = pcVar1->next_succ) {
      if (pcVar1->to != b->next) {
        return 0;
      }
    }
    t = b->end->prev;
    if ((t->kind == '\x11') && ((t->flags & 8) == 0)) {
      branch_delete(t);
      return 1;
    }
    if ((t->kind == '\x13') && (t->op != 0x18e)) {
      branch_delete_and_free_switch(t);
      return 1;
    }
  }
  return 0;
}

