void function_cleanup_drop_unknown_inits(void)

{
  c2_init *pcVar1;
  c2_init *pcVar2;
  c2_init *list;
  void *pvVar3;
  int iVar4;
  
  pcVar2 = (c2_init *)0x0;
  list = g_init_record_list;
  do {
    while( true ) {
      while( true ) {
        if (list == (c2_init *)0x0) {
          return;
        }
        iVar4 = coff_is_known_global_id((list->u08).header.sym_id);
        pvVar3 = g_init_records_tail;
        if (iVar4 == 0) break;
        pcVar2 = list;
        list = (list->u08).header.list_next;
      }
      pcVar1 = (list->u08).header.list_next;
      if (pcVar2 != (c2_init *)0x0) break;
      g_init_record_list = pcVar1;
      if (g_init_records_tail == list) {
        g_init_records_tail = (void *)0x0;
      }
LAB_10783ff9:
      init_records_free(list);
      list = pcVar1;
    }
    (pcVar2->u08).header.list_next = pcVar1;
    if (pvVar3 != list) goto LAB_10783ff9;
    g_init_records_tail = pcVar2;
    init_records_free(list);
    list = pcVar1;
  } while( true );
}

