void __fastcall reader_free_stack_cell(c2_reader_cell *cell)

{
  if ((cell->u10).bitfield != (c2_operand *)0x0) {
    node_list_free((c2_node *)(cell->u10).bitfield);
  }
  cell->tail = cell->head;
  cell->head->next = (c2_tuple *)0x0;
  cell->next = g_reader_stack_cell_free;
  g_reader_stack_cell_free = cell;
  return;
}

