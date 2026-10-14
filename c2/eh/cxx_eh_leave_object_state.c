void __fastcall cxx_eh_leave_object_state(c2_tuple *t)

{
  c2_cxx_try_block *pcVar1;
  
  eh_pop_state();
  pcVar1 = ((t->u20).eh_try)->try_block;
  pcVar1->catch_high = g_eh_state_counter + -1;
  insert_eh_state_store(pcVar1->state_rec->to_state,-2,(c2_eh_state *)0x0,t);
  tuple_unlink_free(t);
  return;
}

