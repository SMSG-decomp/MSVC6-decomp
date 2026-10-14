void __fastcall cxx_eh_drop_object_state(c2_tuple *t,c2_eh_state *object,c2_eh_object_cell *cell)

{
  c2_eh_state *pcVar1;
  c2_eh_tuple_cell *pcVar2;
  c2_eh_tuple_cell *pcVar3;
  c2_eh_object_cell *next_cell;
  c2_eh_op_region *region;
  c2_eh_object_cell *prev_cell;
  
  if (object->origin != (c2_eh_state *)0x0) {
    object = object->origin;
  }
  if (t->op == 0x1a2) {
    if ((object->flags & 0x400) == 0) {
      return;
    }
    pcVar2 = ((t->u20).eh_region)->state_stores;
    pcVar1 = (c2_eh_state *)((pcVar2->tuple->u20).cond_cells)->op;
    pcVar3 = (c2_eh_tuple_cell *)0x0;
    while (object != pcVar1) {
      pcVar1 = (c2_eh_state *)((pcVar2->next->tuple->u20).cond_cells)->op;
      pcVar3 = pcVar2;
      pcVar2 = pcVar2->next;
    }
    tuple_unlink_free(pcVar2->tuple);
    if (pcVar3 == (c2_eh_tuple_cell *)0x0) {
      ((t->u20).cond_cells)->cc = (uint32_t)pcVar2->next;
    }
    else {
      pcVar3->next = pcVar2->next;
    }
    if (((t->u20).cond_cells)->cc != 0) {
      tuple_unlink(t);
      tuple_insert_before(((t->u20).eh_region)->state_stores->tuple,t);
    }
  }
  if ((object->flags & 0x400) != 0) {
    region = (t->u20).eh_region;
    region->count = region->count + -1;
    if (cell != (c2_eh_object_cell *)0x0) {
      prev_cell = cell->prev;
      next_cell = cell->next;
      if (prev_cell == (c2_eh_object_cell *)0x0) {
        region->objects = next_cell;
        if (next_cell != (c2_eh_object_cell *)0x0) {
          next_cell->prev = (c2_eh_object_cell *)0x0;
        }
      }
      else {
        prev_cell->next = next_cell;
        if (next_cell != (c2_eh_object_cell *)0x0) {
          next_cell->prev = prev_cell;
          return;
        }
      }
    }
  }
  return;
}

