void __fastcall cxx_eh_lower_scope_exit(c2_tuple *t)

{
  c2_eh_op_region *pcVar1;
  uint uVar2;
  c2_eh_state *object;
  c2_eh_object_cell *list;
  int local_c;
  int local_8;
  
  pcVar1 = (t->u20).eh_region;
  list = (c2_eh_object_cell *)0x0;
  local_c = 0;
  local_8 = pcVar1->count;
  if ((pcVar1->flags & 7) != 2) {
    do {
      object = eh_pop_state();
      uVar2 = object->flags;
      if ((char)uVar2 != '\a') {
        node_list_free((c2_node *)(object->u1c).unwind_body);
        (object->u1c).unwind_body = (c2_tuple *)0x0;
        if ((uVar2 & 0x200) == 0) {
          list = list_append_new(list,object);
          local_c = local_c + 1;
          object->refs = object->refs + 1;
        }
      }
      local_8 = local_8 + -1;
    } while (0 < local_8);
    if (local_c == 0) {
      tuple_unlink_free(t);
      return;
    }
    pcVar1->count = local_c;
    pcVar1->objects = list;
  }
  return;
}

