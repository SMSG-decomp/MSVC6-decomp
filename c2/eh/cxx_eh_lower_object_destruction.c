void __fastcall cxx_eh_lower_object_destruction(c2_tuple *t)

{
  c2_eh_op_region *pcVar1;
  uint uVar2;
  int32_t old_state;
  c2_eh_object_cell *pcVar3;
  c2_eh_state *object;
  
  pcVar1 = (t->u20).eh_region;
  t->op = 0x145;
  uVar2 = pcVar1->flags;
  if (((byte)uVar2 & 7) == 2) {
    cxx_eh_unwind_to_state(t);
    tuple_unlink_free(t);
    return;
  }
  pcVar3 = cxx_eh_order_objects_by_state(pcVar1->objects,pcVar1->count);
  if (pcVar3 != (c2_eh_object_cell *)0x0) {
    old_state = g_eh_current_state->state;
    do {
      object = eh_pop_state();
      pcVar3 = pcVar3->next;
    } while (pcVar3 != (c2_eh_object_cell *)0x0);
    if ((uVar2 & 0x80) == 0) {
      insert_eh_state_store(object->to_state,old_state,object,t);
    }
    tuple_unlink_free(t);
    return;
  }
  tuple_unlink_free(t);
  return;
}

