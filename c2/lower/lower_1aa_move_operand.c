void __fastcall lower_1aa_move_operand(c2_tuple *marker,c2_tuple *t)

{
  c2_tuple *pcVar1;
  c2_tuple *pcVar2;
  c2_operand *op;
  
  op = marker->src;
  tuple_detach_src((c2_node *)marker,op);
  tuple_replace_src(t,t->src,op);
  tuple_unlink(t);
  tuple_insert_after(marker,t);
  pcVar1 = marker->prev;
  pcVar2 = marker->next;
  pcVar1->next = pcVar2;
  pcVar2->prev = pcVar1;
  node_free((c2_node *)marker);
  return;
}

