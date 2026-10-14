c2_tuple * __fastcall reader_pop(c2_reader_cell **stack)

{
  c2_reader_cell *cell;
  c2_tuple *pcVar1;
  
  cell = *stack;
  pcVar1 = cell->head->next;
  if (pcVar1 != (c2_tuple *)0x0) {
    pcVar1->prev = (c2_tuple *)0x0;
  }
  *stack = cell->next;
  reader_free_stack_cell(cell);
  return pcVar1;
}

