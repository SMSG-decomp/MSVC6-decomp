void incr_function_prepare_data(void)

{
  c2_incr_id_cell *pcVar1;
  c2_list_cell *pcVar2;
  uint32_t uVar3;
  c2_fe_symbol *pcVar4;
  c2_incr_id_cell *pcVar5;
  c2_list_cell *list;
  
  uVar3 = coff_resolve_function_hash(g_cur_func_sym->id);
  pcVar4 = g_cur_func_sym;
  g_cur_func_sym->coff_symbol = uVar3;
  pcVar4->last_referrer = pcVar4;
  if ((pcVar4->storage & 0x800) != 0) {
    note_symbol_referenced(pcVar4);
    pcVar4 = g_cur_func_sym;
  }
  pcVar4->flags31 = pcVar4->flags31 | 4;
  pcVar1 = pcVar4->incr->symbol_deps;
  do {
    if (pcVar1 == (c2_incr_id_cell *)0x0) {
      list = move_zero_initialized_data_to_bss();
      for (pcVar2 = list; pcVar2 != (c2_list_cell *)0x0; pcVar2 = pcVar2->next) {
        fe_symbol_assign_frame((pcVar2->u04).fe);
      }
      writer_flush_pending();
      emit_symbol_list_records(list);
      pcVar1 = g_cur_func_sym->incr->callees;
      while (pcVar1 != (c2_incr_id_cell *)0x0) {
        pcVar4 = fe_scope_lookup_id(&g_global_scope,pcVar1->sym_id);
        pcVar1 = pcVar1->next;
        pcVar4->fn_flags = pcVar4->fn_flags | 0x1000;
      }
      return;
    }
    uVar3 = pcVar1->sym_id;
    pcVar4 = fe_scope_lookup_id(&g_global_scope,uVar3);
    pcVar5 = g_incr_unknown_symbol_ids;
    if (pcVar4 == (c2_fe_symbol *)0x0) {
      for (; pcVar5 != (c2_incr_id_cell *)0x0; pcVar5 = pcVar5->next) {
        if (pcVar5->sym_id == uVar3) {
          if (pcVar5 != (c2_incr_id_cell *)0x0) goto LAB_107846e4;
          break;
        }
      }
      pcVar5 = arena_alloc(0,8);
      pcVar5->sym_id = uVar3;
      pcVar5->next = g_incr_unknown_symbol_ids;
      g_incr_unknown_symbol_ids = pcVar5;
    }
    else {
      pcVar4->last_referrer = g_cur_func_sym;
      note_symbol_referenced(pcVar4);
      if (((pcVar4->cls == '\x04') && ((pcVar4->storage & 0x4000) != 0)) &&
         ((pcVar4->storage & 0x1000) == 0)) {
        pcVar4->fn_flags = pcVar4->fn_flags | 0x20;
      }
    }
LAB_107846e4:
    pcVar1 = pcVar1->next;
  } while( true );
}

