void __fastcall reader_push_pending_list(c2_reader_cell *cell)

{
  c2_tuple *pcVar1;
  c2_tuple *pcVar2;
  c2_reader_cell *pcVar3;
  c2_reader_cell *pcVar4;
  c2_reader_cell *pcVar5;
  
  pcVar5 = cell->before;
  pcVar4 = (c2_reader_cell *)&cell->before;
  while (pcVar3 = pcVar5, pcVar3 != (c2_reader_cell *)0x0) {
    pcVar4 = pcVar3;
    pcVar5 = pcVar3->next;
  }
  pcVar5 = reader_new_stack_cell();
  pcVar4->next = pcVar5;
  pcVar1 = cell->head;
  tuple_splice_after(pcVar5->head,pcVar1->next);
  pcVar2 = cell->tail;
  pcVar1->next = (c2_tuple *)0x0;
  pcVar5->tail = pcVar2;
  cell->tail = pcVar1;
  return;
}

