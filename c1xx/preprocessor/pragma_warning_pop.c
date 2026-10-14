void __cdecl pragma_warning_pop(void)

{
  c1_warning_record *pcVar1;
  c1xx_warning_state *pcVar2;
  
  pcVar2 = g_warning_state;
  if (g_warning_state->saved == (c1_warning_record *)0x0) {
    diag_warning(3,0xc1);
    return;
  }
  while( true ) {
    pcVar1 = pcVar2->saved;
    pcVar2->saved = (c1_warning_record *)(pcVar1->next & 0xfffffffe);
    if ((~pcVar1->next & 1) != 0) break;
    pcVar2->state[pcVar1->value & 0xfffffff] = (byte)(pcVar1->value >> 0x1c);
    pcVar1->next = (c1_u32)g_warning_record_free_list;
    g_warning_record_free_list = pcVar1;
  }
  pcVar2->level = pcVar1->value;
  pcVar1->next = (c1_u32)g_warning_record_free_list;
  g_warning_record_free_list = pcVar1;
  return;
}

