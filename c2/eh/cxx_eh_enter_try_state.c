void __fastcall cxx_eh_enter_try_state(c2_tuple *t)

{
  c2_fe_symbol *fs;
  c2_eh_state *rec;
  c2_symbol *pcVar1;
  c2_cxx_try_block *try_block;
  c2_eh_op_try *try_op;
  
  try_op = (t->u20).eh_try;
  try_block = try_op->try_block;
  if (try_op->catch_rec == try_block->catches) {
    eh_pop_state();
    try_block->try_high = g_eh_state_counter + -1;
    rec = cxx_eh_new_object_record(6,0,0);
    push_eh_state(rec);
  }
  try_op->state = g_eh_current_state;
  fs = try_op->catch_rec->object;
  if (fs != (c2_fe_symbol *)0x0) {
    pcVar1 = fe_symbol_get_storage(fs);
    for (pcVar1 = pcVar1->storage; pcVar1 != (c2_symbol *)0x0; pcVar1 = pcVar1->part_next) {
      pcVar1->flags5 = pcVar1->flags5 | 2;
    }
  }
  return;
}

