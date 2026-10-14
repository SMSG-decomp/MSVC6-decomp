void __fastcall reader_swap_top(c2_reader_cell **stack)

{
  c2_reader_cell *pcVar1;
  c2_reader_cell *pcVar2;
  c2_reader_cell *pcVar3;
  
  pcVar1 = *stack;
  pcVar2 = pcVar1->next;
  *stack = pcVar2;
  pcVar3 = *stack;
  pcVar1->next = pcVar2->next;
  pcVar3->next = pcVar1;
  return;
}

