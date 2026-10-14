c2_tuple * __fastcall tuple_next_real_in_block(c2_tuple *t)

{
  c2_tuple *pcVar1;
  
  pcVar1 = t->next;
  while( true ) {
    if (pcVar1 == (c2_tuple *)0x0) {
      return (c2_tuple *)0x0;
    }
    if ((pcVar1->flags & 1) != 0) {
      return pcVar1;
    }
    if (pcVar1->kind == '\x1a') {
      return pcVar1;
    }
    if (pcVar1->kind == '\x19') break;
    pcVar1 = pcVar1->next;
  }
  return (c2_tuple *)0x0;
}

