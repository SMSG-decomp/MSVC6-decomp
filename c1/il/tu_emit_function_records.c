void tu_emit_function_records(void)

{
  fe_function_record_block *pfVar1;
  int iVar2;
  fe_function_record *rec;
  
  for (pfVar1 = g_function_record_first_block; pfVar1 != (fe_function_record_block *)0x0;
      pfVar1 = pfVar1->next) {
    iVar2 = g_function_record_index;
    if (pfVar1 != g_function_record_block) {
      iVar2 = 0x13;
    }
    rec = pfVar1->records;
    iVar2 = iVar2 + 1;
    do {
      func_emit_definition_record(rec);
      rec = rec + 1;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return;
}

