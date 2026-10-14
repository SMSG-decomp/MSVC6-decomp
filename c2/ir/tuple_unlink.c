c2_tuple * __fastcall tuple_unlink(c2_tuple *t)

{
  c2_tuple *pcVar1;
  
  pcVar1 = t->prev;
  if (pcVar1 != (c2_tuple *)0x0) {
    pcVar1->next = t->next;
  }
  if (t->next != (c2_tuple *)0x0) {
    t->next->prev = pcVar1;
  }
  t->prev = (c2_tuple *)0x0;
  t->next = (c2_tuple *)0x0;
  return pcVar1;
}

