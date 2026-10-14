void __fastcall rehash_block_tuples(c2_block *b,int enter_single_def_temps)

{
  c2_tuple *pcVar1;
  c2_tuple *pcVar2;
  c2_tuple *t;
  
  pcVar1 = b->end;
  pcVar2 = b->head->next;
  while (t = pcVar2, t != pcVar1) {
    pcVar2 = t->next;
    if ((t->flags & 1) != 0) {
      enter_tuple_in_expression_table(t,enter_single_def_temps);
    }
  }
  return;
}

