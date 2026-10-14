void __fastcall cxx_eh_enter_object_state(c2_tuple *pos)

{
  c2_cxx_try_block *pcVar1;
  c2_eh_state *rec;
  int32_t new_state;
  int32_t old_state;
  
  pcVar1 = ((pos->u20).eh_try)->try_block;
  rec = pcVar1->state_rec;
  push_eh_state(rec);
  new_state = rec->state;
  old_state = rec->to_state;
  pcVar1->try_low = new_state;
  insert_eh_state_store(new_state,old_state,(c2_eh_state *)0x0,pos);
  return;
}

