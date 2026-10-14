void __fastcall mark_label_refs_for_18c(c2_tuple *t)

{
  c2_operand *pcVar1;
  c2_switch_case *c;
  
  if (t->prev->kind == '\x1a') {
    pcVar1 = t->prev->dst;
    while (pcVar1 != (c2_operand *)0x0) {
      c = (c2_switch_case *)pcVar1->rank;
      pcVar1 = pcVar1->next;
      if (c->kind == '\x13') {
        c[1].lo = c[1].lo | 2;
      }
      else {
        switch_case_unlink(c);
      }
    }
  }
  return;
}

