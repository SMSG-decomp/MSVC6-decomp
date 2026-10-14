c2_eh_tuple_cell * __fastcall seh_forget_finally_call(c2_tuple *t)

{
  c2_eh_tuple_cell *pcVar1;
  c2_seh_try_scope *pcVar2;
  
  pcVar2 = g_seh_try_records;
  do {
    if (pcVar2->kind == 2) {
      for (pcVar1 = pcVar2->finally_calls; pcVar1 != (c2_eh_tuple_cell *)0x0; pcVar1 = pcVar1->next)
      {
        if (pcVar1->tuple == t) {
          pcVar1->tuple = (c2_tuple *)0x0;
          return pcVar1;
        }
      }
    }
    pcVar2 = pcVar2->next;
  } while( true );
}

