c2_tuple * __fastcall tuple_insert_after(c2_tuple *pos,c2_tuple *t)

{
  c2_tuple *pcVar1;
  
  pcVar1 = pos->next;
  pos->next = t;
  t->prev = pos;
  t->next = pcVar1;
  pcVar1->prev = t;
  return pcVar1;
}

