void __fastcall reader_push(c2_reader_cell **stack,c2_node *first)

{
  c2_reader_cell *pcVar1;
  c2_tuple *pcVar2;
  c2_tuple *pcVar3;
  c2_reader_cell *pcVar4;
  
  pcVar4 = reader_new_stack_cell();
  tuple_splice_after(pcVar4->tail,(c2_tuple *)first);
  pcVar3 = (c2_tuple *)first->next;
  while (pcVar2 = pcVar3, pcVar2 != (c2_tuple *)0x0) {
    first = (c2_node *)pcVar2;
    pcVar3 = pcVar2->next;
  }
  pcVar1 = *stack;
  pcVar4->tail = (c2_tuple *)first;
  pcVar4->next = pcVar1;
  *stack = pcVar4;
  return;
}

