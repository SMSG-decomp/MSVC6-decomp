c2_tuple * __fastcall block_first_assignment(c2_tuple *t)

{
  c2_tuple *pcVar1;
  
  pcVar1 = t->next;
  while( true ) {
    if (pcVar1 == (c2_tuple *)0x0) {
      return (c2_tuple *)0x0;
    }
    if (pcVar1->kind == '\f') break;
    if (pcVar1->kind == '\x19') {
      return (c2_tuple *)0x0;
    }
    pcVar1 = pcVar1->next;
  }
  return pcVar1;
}

