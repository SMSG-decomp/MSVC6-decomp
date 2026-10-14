void __fastcall incremental_note_callee(uint32_t callee_id)

{
  c2_incr_id_cell *pcVar1;
  c2_fe_symbol *pcVar2;
  c2_incr_id_cell *pcVar3;
  
  pcVar1 = g_cur_func_sym->incr->callees;
  do {
    if (pcVar1 == (c2_incr_id_cell *)0x0) {
LAB_10784244:
      pcVar3 = arena_alloc(0,8);
      pcVar2 = g_cur_func_sym;
      pcVar3->sym_id = callee_id;
      pcVar1 = pcVar2->incr->callees;
      pcVar2->incr->callees = pcVar3;
      pcVar3->next = pcVar1;
      return;
    }
    if (pcVar1->sym_id == callee_id) {
      if (pcVar1 != (c2_incr_id_cell *)0x0) {
        return;
      }
      goto LAB_10784244;
    }
    pcVar1 = pcVar1->next;
  } while( true );
}

