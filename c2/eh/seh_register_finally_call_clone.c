c2_eh_tuple_cell * __fastcall seh_register_finally_call_clone(c2_tuple *original,c2_tuple *clone)

{
  c2_eh_tuple_cell *pcVar1;
  c2_eh_tuple_cell *pcVar2;
  c2_seh_try_scope *pcVar3;
  c2_eh_tuple_cell *pcVar4;
  
  pcVar3 = g_seh_try_records;
  do {
    if (pcVar3->kind == 2) {
      for (pcVar1 = pcVar3->finally_calls; pcVar1 != (c2_eh_tuple_cell *)0x0; pcVar1 = pcVar1->next)
      {
        if (pcVar1->tuple == original) {
          pcVar4 = arena_alloc(1,8);
          pcVar2 = pcVar1->next;
          pcVar4->tuple = clone;
          pcVar1->next = pcVar4;
          pcVar4->next = pcVar2;
          return pcVar4;
        }
      }
    }
    pcVar3 = pcVar3->next;
  } while( true );
}

