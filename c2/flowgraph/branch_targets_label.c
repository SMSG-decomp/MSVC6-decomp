c2_tuple * __fastcall branch_targets_label(c2_tuple *t,c2_tuple *t2)

{
  if (t->kind == '\x11') {
    if (t->src->kind == '\x04') {
      return (c2_tuple *)((uint)t & (t->src->sym != (c2_symbol *)t2->src) - 1);
    }
    t = (c2_tuple *)((uint)t & (t2->src != (c2_operand *)0x0) - 1);
  }
  else {
    if (t->kind != '\x13') {
      return (c2_tuple *)0x0;
    }
    if (t2 != (c2_tuple *)(t->u20).cond_cells) {
      t = (c2_tuple *)(t->u24).cases;
      while( true ) {
        if (t == (c2_tuple *)0x0) {
          return (c2_tuple *)0x0;
        }
        if (t2 == (t->u14).arg) break;
        t = t->next;
      }
    }
  }
  return t;
}

