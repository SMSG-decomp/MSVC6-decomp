void pragma_warning_pop(void)

{
  fe_warning_record *pfVar1;
  fe_warning_state *pfVar2;
  
  pfVar2 = g_warning_state;
  if (g_warning_state->saved == (fe_warning_record *)0x0) {
    diag_warning(3,0xc1);
    return;
  }
  while( true ) {
    pfVar1 = pfVar2->saved;
    pfVar2->saved = (fe_warning_record *)(pfVar1->next & 0xfffffffe);
    if ((~pfVar1->next & 1) != 0) break;
    pfVar2->state[pfVar1->value & 0xfffffff] = (byte)(pfVar1->value >> 0x1c);
    pfVar1->next = (uint)g_warning_record_free_list;
    g_warning_record_free_list = pfVar1;
  }
  pfVar2->level = pfVar1->value;
  pfVar1->next = (uint)g_warning_record_free_list;
  g_warning_record_free_list = pfVar1;
  return;
}

