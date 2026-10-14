c2_tuple * __fastcall tuple_move_range(c2_tuple *pos,c2_tuple *first,c2_tuple *last)

{
  c2_tuple *pcVar1;
  
  pcVar1 = first->prev;
  if (pcVar1 != (c2_tuple *)0x0) {
    pcVar1->next = last->next;
  }
  if (last->next != (c2_tuple *)0x0) {
    last->next->prev = pcVar1;
  }
  pcVar1 = pos->prev;
  pos->prev = last;
  last->next = pos;
  first->prev = pcVar1;
  pcVar1->next = first;
  return pcVar1;
}

