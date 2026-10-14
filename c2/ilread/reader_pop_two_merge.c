void __fastcall reader_pop_two_merge(c2_reader_cell **stack,c2_operand **a,c2_operand **b,int keep)

{
  c2_reader_cell *pcVar1;
  c2_tuple *pcVar2;
  c2_reader_cell *pcVar3;
  c2_reader_cell *pcVar4;
  c2_reader_cell *pcVar5;
  c2_reader_cell *pcVar6;
  c2_operand *pcVar7;
  c2_tuple *first;
  
  if (keep == 0) {
    pcVar7 = reader_pop_operand(*stack);
    *b = pcVar7;
  }
  pcVar1 = *stack;
  pcVar2 = pcVar1->tail;
  pcVar3 = pcVar1->before;
  pcVar1->before = (c2_reader_cell *)0x0;
  pcVar4 = pcVar1->after;
  pcVar1->after = (c2_reader_cell *)0x0;
  first = reader_pop(stack);
  if (keep == 0) {
    pcVar7 = reader_pop_operand(*stack);
    *a = pcVar7;
  }
  pcVar1 = *stack;
  pcVar5 = pcVar1->before;
  if (pcVar5 == (c2_reader_cell *)0x0) {
    pcVar1->before = pcVar3;
  }
  else if (pcVar3 != (c2_reader_cell *)0x0) {
    for (pcVar6 = pcVar5->next; pcVar6 != (c2_reader_cell *)0x0; pcVar6 = pcVar6->next) {
      pcVar5 = pcVar6;
    }
    pcVar5->next = pcVar3;
  }
  if (pcVar4 != (c2_reader_cell *)0x0) {
    pcVar3 = pcVar1->after;
    pcVar1->after = pcVar4;
    if (pcVar3 != (c2_reader_cell *)0x0) {
      for (pcVar5 = pcVar4->next; pcVar5 != (c2_reader_cell *)0x0; pcVar5 = pcVar5->next) {
        pcVar4 = pcVar5;
      }
      pcVar4->next = pcVar3;
    }
  }
  if (first != (c2_tuple *)0x0) {
    tuple_splice_after(pcVar1->tail,first);
    pcVar1->tail = pcVar2;
  }
  return;
}

