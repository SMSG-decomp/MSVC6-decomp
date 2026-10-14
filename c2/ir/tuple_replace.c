void __fastcall tuple_replace(c2_tuple *t,c2_node *t2)

{
  c2_tuple *pcVar1;
  c2_tuple *pcVar2;
  
  tuple_insert_before(t,(c2_tuple *)t2);
  pcVar1 = t->prev;
  pcVar2 = t->next;
  pcVar1->next = pcVar2;
  pcVar2->prev = pcVar1;
  node_free((c2_node *)t);
  return;
}

