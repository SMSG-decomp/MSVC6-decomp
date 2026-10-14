void __cdecl tu_emit_function_records(void)

{
  c1_function_record_block *pcVar1;
  int iVar2;
  c1xx_function_record *rec;
  
  for (pcVar1 = g_function_record_first_block; pcVar1 != (c1_function_record_block *)0x0;
      pcVar1 = pcVar1->next) {
    iVar2 = g_function_record_index;
    if (pcVar1 != g_function_record_block) {
      iVar2 = 0x13;
    }
    rec = pcVar1->records;
    iVar2 = iVar2 + 1;
    do {
      func_emit_definition_record(rec);
      rec = rec + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return;
}

