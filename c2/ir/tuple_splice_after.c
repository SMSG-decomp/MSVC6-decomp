void __fastcall tuple_splice_after(c2_tuple *pos,c2_tuple *first)

{
  c2_tuple *pcVar1;
  c2_tuple *pcVar2;
  c2_tuple *pcVar3;
  
  pcVar1 = pos->next;
  pos->next = first;
  first->prev = pos;
  if (pcVar1 != (c2_tuple *)0x0) {
    pcVar3 = first->next;
    while (pcVar2 = pcVar3, pcVar2 != (c2_tuple *)0x0) {
      first = pcVar2;
      pcVar3 = pcVar2->next;
    }
    first->next = pcVar1;
    pcVar1->prev = first;
  }
  return;
}

