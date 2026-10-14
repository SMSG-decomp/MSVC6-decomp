void incr_write_function_records(void)

{
  c2_incr_function_record *pcVar1;
  c2_incr_id_cell *pcVar2;
  c2_coff_fn_section *pcVar3;
  c2_fe_symbol *pcVar4;
  
  for (pcVar4 = g_incr_compiled_functions; pcVar4 != (c2_fe_symbol *)0x0;
      pcVar4 = pcVar4->next_function) {
    incr_stream_put_dword(pcVar4->id);
    pcVar1 = pcVar4->incr;
    incr_stream_put_word(pcVar1->il_version);
    for (pcVar2 = pcVar1->symbol_deps; pcVar2 != (c2_incr_id_cell *)0x0; pcVar2 = pcVar2->next) {
      incr_stream_put_dword(pcVar2->sym_id);
    }
    incr_stream_put_dword(0);
    for (pcVar2 = pcVar1->callees; pcVar2 != (c2_incr_id_cell *)0x0; pcVar2 = pcVar2->next) {
      incr_stream_put_dword(pcVar2->sym_id);
    }
    incr_stream_put_dword(0);
    for (pcVar3 = pcVar1->sections; pcVar3 != (c2_coff_fn_section *)0x0; pcVar3 = pcVar3->next) {
      incr_stream_put_dword(pcVar3->number);
    }
    incr_stream_put_dword(0);
  }
  incr_stream_put_dword(0);
  for (pcVar4 = g_function_list; pcVar4 != (c2_fe_symbol *)0x0; pcVar4 = pcVar4->next_function) {
    if ((pcVar4->fn_flags & 0x1000) != 0) {
      incr_stream_put_dword(pcVar4->id);
      incr_stream_put_word(pcVar4->incr->il_version);
    }
  }
  incr_stream_put_dword(0);
  return;
}

