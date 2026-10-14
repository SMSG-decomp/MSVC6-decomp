void __fastcall cxx_eh_unwind_to_state(c2_tuple *pos)

{
  char cVar1;
  int32_t old_state;
  c2_eh_state *object;
  c2_eh_state *rec;
  c2_tuple *t;
  c2_eh_op_construct *pcVar2;
  c2_eh_object_cell *list;
  int32_t iVar3;
  
  list = (c2_eh_object_cell *)0x0;
  old_state = g_eh_current_state->state;
  iVar3 = ((pos->u20).eh_region)->count;
  do {
    object = eh_pop_state();
    cVar1 = (char)object->flags;
    while (cVar1 == '\x03') {
      list = list_append_new(list,object);
      object = eh_pop_state();
      cVar1 = (char)object->flags;
    }
    iVar3 = iVar3 + -1;
  } while (0 < iVar3);
  if (list == (c2_eh_object_cell *)0x0) {
    iVar3 = object->to_state;
  }
  else {
    do {
      rec = cxx_eh_clone_object_record(list->object);
      t = tuple_new_pseudo(0x1a0,0x1004);
      pcVar2 = arena_alloc(1,0x10);
      (t->u20).eh_construct = pcVar2;
      pcVar2->object = rec;
      tuple_insert_before(pos,t);
      push_eh_state(rec);
      list = list->next;
    } while (list != (c2_eh_object_cell *)0x0);
    iVar3 = rec->state;
  }
  insert_eh_state_store(iVar3,old_state,object,pos);
  return;
}

