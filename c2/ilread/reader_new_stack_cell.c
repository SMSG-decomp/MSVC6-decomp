c2_reader_cell * reader_new_stack_cell(void)

{
  c2_reader_cell *pcVar1;
  c2_tuple *pcVar2;
  int iVar3;
  c2_reader_cell *pcVar4;
  
  pcVar1 = g_reader_stack_cell_free;
  if (g_reader_stack_cell_free != (c2_reader_cell *)0x0) {
    pcVar2 = g_reader_stack_cell_free->head;
    pcVar4 = g_reader_stack_cell_free;
    g_reader_stack_cell_free = g_reader_stack_cell_free->next;
    for (iVar3 = 7; iVar3 != 0; iVar3 = iVar3 + -1) {
      pcVar4->next = (c2_reader_cell *)0x0;
      pcVar4 = (c2_reader_cell *)&pcVar4->head;
    }
    pcVar1->tail = pcVar2;
    pcVar1->head = pcVar2;
    return pcVar1;
  }
  pcVar1 = arena_alloc(4,0x1c);
  pcVar2 = tuple_new_block_boundary();
  pcVar1->tail = pcVar2;
  pcVar1->head = pcVar2;
  return pcVar1;
}

