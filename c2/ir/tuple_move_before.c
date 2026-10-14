c2_tuple * __fastcall tuple_move_before(c2_tuple *pos,c2_tuple *t)

{
  c2_tuple *pcVar1;
  
  tuple_unlink(t);
  pcVar1 = pos->prev;
  pos->prev = t;
  t->next = pos;
  t->prev = pcVar1;
  pcVar1->next = t;
  return pcVar1;
}

