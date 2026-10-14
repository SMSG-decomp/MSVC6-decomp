c2_tuple * __fastcall tuple_next_real(c2_tuple *t)

{
  c2_tuple *pcVar1;
  
  pcVar1 = t->next;
  while( true ) {
    if (pcVar1 == (c2_tuple *)0x0) {
      return (c2_tuple *)0x0;
    }
    if ((pcVar1->flags & 1) != 0) break;
    pcVar1 = pcVar1->next;
  }
  return pcVar1;
}

