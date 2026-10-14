void __fastcall cxx_eh_emit_funclets(c2_function *fn)

{
  c2_tuple *t;
  c2_function **funclet_slot;
  c2_function *funclet_fn;
  c2_function *funclet;
  c2_tuple *end;
  c2_tuple *exit_tuple;
  c2_tuple *next_t;
  c2_eh_state *object;
  
  end = fn->cfg->last->end;
  for (exit_tuple = end; (exit_tuple != (c2_tuple *)0x0 && (exit_tuple->kind != '\x18'));
      exit_tuple = exit_tuple->prev) {
  }
  next_t = fn->cfg->first->head->next;
  while (t = next_t, t != end) {
    next_t = t->next;
    if (t->op == 0x18b) {
      tuple_unlink_free(t);
    }
    else if (t->op == 0x1a0) {
      object = ((t->u20).eh_construct)->object;
      funclet_fn = object->funclet;
      funclet_slot = &object->funclet;
      if ((funclet_fn != (c2_function *)0x0) && ((funclet_fn->flags & 0x4000) == 0)) {
        emit_size_frame_operands(funclet_fn,fn);
        object = ((t->u20).eh_construct)->object;
        funclet = object->funclet;
        funclet_slot = &object->funclet;
        tuple_splice_after(exit_tuple->prev,funclet->cfg->first->head);
        funclet->flags = funclet->flags | 0x4000;
      }
      *funclet_slot = (c2_function *)0x0;
      tuple_unlink_free(t);
    }
  }
  cxx_eh_emit_unwind_and_tryblock_tables(fn);
  g_eh_return_object_record = (c2_eh_state *)0x0;
  return;
}

