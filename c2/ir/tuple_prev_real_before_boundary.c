c2_tuple * __fastcall tuple_prev_real_before_boundary(c2_tuple *t)

{
  c2_tuple *pcVar1;
  
  pcVar1 = t->prev;
  while( true ) {
    if (pcVar1 == (c2_tuple *)0x0) {
      return (c2_tuple *)0x0;
    }
    if ((pcVar1->flags & 1) != 0) break;
    if (pcVar1->kind == '\x19') {
      return (c2_tuple *)0x0;
    }
    pcVar1 = pcVar1->prev;
  }
  return pcVar1;
}

