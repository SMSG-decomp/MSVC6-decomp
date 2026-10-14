void __fastcall cxx_eh_lower_object_marker(c2_tuple *t)

{
  c2_eh_state *rec;
  c2_cxx_try_block *try_block;
  
  try_block = ((t->u20).eh_try)->try_block;
  if (t->op == 0x1a4) {
    rec = cxx_eh_new_object_record(6,0,0);
    push_eh_state(rec);
    (rec->u1c).try_block = try_block;
    try_block->state_rec = rec;
    (try_block->u24).catch_tail = (c2_cxx_catch *)0x0;
  }
  else if ((t->op == 0x1a5) && ((try_block->u24).catch_tail == (c2_cxx_catch *)0x0)) {
    eh_pop_state();
    (try_block->u24).state_popped = -1;
    return;
  }
  return;
}

