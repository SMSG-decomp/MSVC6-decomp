void __fastcall reader_push_tuple_list(c2_reader_cell *cell,c2_tuple *list)

{
  c2_reader_cell *pcVar1;
  c2_reader_cell *pcVar2;
  c2_tuple *pcVar3;
  
  pcVar2 = reader_new_stack_cell();
  pcVar1 = cell->before;
  cell->before = pcVar2;
  pcVar2->next = pcVar1;
  tuple_splice_after(pcVar2->head,list);
  pcVar3 = (c2_tuple *)list_last((c2_link *)list);
  pcVar2->tail = pcVar3;
  return;
}

