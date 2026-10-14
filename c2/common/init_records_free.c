void __fastcall init_records_free(c2_init *list)

{
  c2_init *pcVar1;
  
  while (pcVar1 = list, pcVar1 != (c2_init *)0x0) {
    list = pcVar1->next;
    (pcVar1->u08).header.list_next = g_init_record_free;
    g_init_record_free = pcVar1;
  }
  return;
}

