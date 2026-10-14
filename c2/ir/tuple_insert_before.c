c2_tuple * __fastcall tuple_insert_before(c2_tuple *pos,c2_tuple *t)

{
  c2_tuple *pcVar1;
  
  pcVar1 = pos->prev;
  pos->prev = t;
  t->next = pos;
  t->prev = pcVar1;
  pcVar1->next = t;
  return pcVar1;
}

