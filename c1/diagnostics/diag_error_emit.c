void __cdecl diag_error_emit(short n)

{
  int iVar1;
  
  diag_begin(&g_diag_message_list,g_token_position);
  diag_message_list_add(&g_diag_message_list,2000,n + 2000,&stack0x00000008);
  diag_end(&g_diag_message_list);
  g_error_count = g_error_count + 1;
  if (100 < g_error_count) {
    diag_fatal(3,100);
  }
  if (g_idb != (c1_idb_state *)0x0) {
    iVar1 = (*g_idb->vtbl->idb_note_error)(g_idb);
    if (iVar1 == 0) {
      diag_fatal(0x49,".\\error.c",0x1c8);
    }
  }
  return;
}

