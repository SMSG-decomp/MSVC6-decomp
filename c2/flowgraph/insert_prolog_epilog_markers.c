void __fastcall insert_prolog_epilog_markers(c2_function *fn)

{
  c2_block *pcVar1;
  c2_tuple *pcVar2;
  c2_tuple *pcVar3;
  
  pcVar1 = fn->cfg->first;
  pcVar3 = pcVar1->head->next;
  do {
    if (pcVar3 == pcVar1->end) {
LAB_107051a5:
      pcVar1 = fn->cfg->last;
      pcVar3 = pcVar1->end;
      pcVar2 = pcVar1->head->next;
      if (pcVar2 != pcVar3) {
        while (pcVar2->kind != '\x18') {
          pcVar2 = pcVar2->next;
          if (pcVar2 == pcVar3) {
            return;
          }
        }
        pcVar3 = tuple_new_marker(0x1b5);
        tuple_insert_before(pcVar2,pcVar3);
        if (g_opt_debug_info != 0) {
          pcVar3 = tuple_new_marker(0x1b7);
          tuple_insert_before(pcVar2,pcVar3);
        }
      }
      return;
    }
    if (pcVar3->kind == '\x17') {
      pcVar2 = tuple_new_marker(0x1b4);
      tuple_insert_after(pcVar3,pcVar2);
      if (g_opt_debug_info != 0) {
        pcVar2 = tuple_new_marker(0x1b6);
        tuple_insert_after(pcVar3,pcVar2);
      }
      goto LAB_107051a5;
    }
    pcVar3 = pcVar3->next;
  } while( true );
}

