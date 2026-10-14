byte __cdecl diag_warning(int level,int n,...)

{
  int iVar1;
  int iVar2;
  
  if ((g_compile_flags_c8 & 0x20000) == 0) {
    iVar2 = (int)g_warning_state->state[n];
    switch(iVar2) {
    case 0:
    case 5:
      iVar1 = level;
      break;
    case 1:
    case 2:
    case 3:
    case 4:
      iVar1 = iVar2;
      break;
    default:
      goto switchD_10604d83_caseD_6;
    case 0xe:
      level = (int)&stack0x0000000c;
      diag_begin(&g_diag_message_list,g_token_position);
      diag_message_list_add(&g_diag_message_list,2000,(short)n + 4000,(char *)&level);
      diag_end(&g_diag_message_list);
      if ((g_idb != (c1_idb_state *)0x0) &&
         (iVar2 = (*g_idb->vtbl->idb_note_error)(g_idb), iVar2 == 0)) {
        diag_fatal(0x49,".\\error.c",0x38a);
      }
      if (g_error_count == 0) {
        g_error_count = 1;
      }
      return 1;
    }
    if (iVar1 <= g_warning_state->level) {
      if (((g_warnings_as_errors != 0) && (g_error_count == 0)) && (g_warnings_as_errors == 1)) {
        g_warnings_as_errors = 2;
        diag_error(0xdc);
        g_error_count = g_error_count + -1;
      }
      level = (int)&stack0x0000000c;
      diag_begin(&g_diag_message_list,g_token_position);
      diag_message_list_set_state_3(&g_diag_message_list);
      diag_message_list_add(&g_diag_message_list,4000,(short)n + 4000,(char *)&level);
      diag_end(&g_diag_message_list);
      level = 0;
      if ((g_idb != (c1_idb_state *)0x0) &&
         (iVar1 = (*g_idb->vtbl->idb_note_warning)(g_idb), iVar1 == 0)) {
        diag_fatal(0x49,".\\error.c",0x36e);
      }
      if (iVar2 == 5) {
        pragma_warning_check_number(n,0xd);
      }
      return 1;
    }
  }
switchD_10604d83_caseD_6:
  return 0;
}

