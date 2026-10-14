c2_tuple * __fastcall reader_flush_cell_tuples(c2_reader_cell *cell,c2_tuple *at)

{
  c2_tuple *pcVar1;
  c2_tuple *pcVar2;
  
  if ((cell->flags & 0x20) == 0) {
    pcVar2 = (c2_tuple *)tuple_delete_if_dead((c2_node *)cell->tail,0);
  }
  else {
    reader_unlink_value_tree(cell->tail);
    pcVar2 = (c2_tuple *)list_last((c2_link *)cell->head);
  }
  pcVar1 = cell->head;
  cell->tail = pcVar2;
  if (pcVar1->next != (c2_tuple *)0x0) {
    tuple_splice_after(at,pcVar1->next);
    pcVar2 = cell->tail;
    pcVar1->next = (c2_tuple *)0x0;
    cell->tail = pcVar1;
    return pcVar2;
  }
  return at;
}

