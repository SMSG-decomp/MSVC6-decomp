void function_cleanup_free_inits(void)

{
  char cVar1;
  c2_init *pcVar2;
  c2_fe_symbol *pcVar3;
  c2_init *pcVar4;
  c2_init *list;
  c2_init *pcVar5;
  int iVar6;
  char *pcVar7;
  
  pcVar4 = (c2_init *)0x0;
  list = g_init_record_list;
  pcVar5 = g_init_records_tail;
  do {
    while( true ) {
      if (list == (c2_init *)0x0) {
        g_init_records_tail = pcVar5;
        return;
      }
      g_init_records_tail = pcVar5;
      if ((list->u08).header.placed != 0) break;
      (list->u18).sym = (c2_fe_symbol *)0x0;
      pcVar4 = list;
      list = (list->u08).header.list_next;
      pcVar5 = g_init_records_tail;
    }
    pcVar2 = (list->u08).header.list_next;
    if (pcVar4 == (c2_init *)0x0) {
      g_init_record_list = pcVar2;
      if (pcVar5 == list) {
        g_init_records_tail = (void *)0x0;
      }
    }
    else {
      (pcVar4->u08).header.list_next = pcVar2;
      if (pcVar5 == list) {
        g_init_records_tail = pcVar4;
      }
    }
    pcVar3 = (list->u18).sym;
    if ((pcVar3->cls == '\x01') && (pcVar3->role == '%')) {
      iVar6 = -1;
      pcVar7 = (char *)(((pcVar3->u32).inits)->next->u08).header.offset;
      do {
        if (iVar6 == 0) break;
        iVar6 = iVar6 + -1;
        cVar1 = *pcVar7;
        pcVar7 = pcVar7 + 1;
      } while (cVar1 != '\0');
      (pcVar3->u44).length = ~(ushort)iVar6;
    }
    init_records_free(list);
    list = pcVar2;
    pcVar5 = g_init_records_tail;
  } while( true );
}

