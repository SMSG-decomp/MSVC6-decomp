void __fastcall reader_flush_all_cells(c2_reader_cell *cell)

{
  c2_reader_cell *pcVar1;
  c2_tuple *at;
  c2_reader_cell *cell_00;
  
  cell_00 = cell->after;
  at = cell->tail;
  if (cell_00 == (c2_reader_cell *)0x0) {
    cell->tail = at;
    cell->after = (c2_reader_cell *)0x0;
    return;
  }
  do {
    pcVar1 = cell_00->next;
    at = reader_flush_cell_tuples(cell_00,at);
    reader_free_stack_cell(cell_00);
    cell_00 = pcVar1;
  } while (pcVar1 != (c2_reader_cell *)0x0);
  cell->after = (c2_reader_cell *)0x0;
  cell->tail = at;
  return;
}

