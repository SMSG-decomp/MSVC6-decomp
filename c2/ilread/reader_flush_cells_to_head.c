void __fastcall reader_flush_cells_to_head(c2_reader_cell *cell)

{
  c2_reader_cell *pcVar1;
  c2_tuple *pcVar2;
  c2_tuple *first;
  c2_reader_cell *cell_00;
  c2_tuple *node;
  c2_tuple *pcVar3;
  
  node = tuple_new_block_boundary();
  cell_00 = cell->before;
  pcVar3 = node;
  while (cell_00 != (c2_reader_cell *)0x0) {
    pcVar1 = cell_00->next;
    pcVar3 = reader_flush_cell_tuples(cell_00,pcVar3);
    reader_free_stack_cell(cell_00);
    cell_00 = pcVar1;
  }
  if (node->next != (c2_tuple *)0x0) {
    pcVar2 = cell->head;
    first = pcVar2->next;
    if (first == (c2_tuple *)0x0) {
      cell->tail = pcVar3;
    }
    else {
      tuple_splice_after(pcVar3,first);
    }
    pcVar3 = node->next;
    pcVar2->next = pcVar3;
    pcVar3->prev = (c2_tuple *)0x0;
  }
  cell->before = (c2_reader_cell *)0x0;
  node_free((c2_node *)node);
  return;
}

