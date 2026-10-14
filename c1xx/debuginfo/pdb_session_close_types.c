void __fastcall pdb_session_close_types(int *session)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  char *message2;
  char text [260];
  char *message;
  
  if (*session == 0) {
    return;
  }
  if (g_last_in_batch != '\0') {
    iVar3 = (**(code **)(*(int *)session[2] + 0x20))();
    if (iVar3 == 0) {
      message2 = (char *)(**(code **)(*(int *)*session + 0xc))(text);
      diag_error(0x1d7,message2);
    }
    session[2] = 0;
    if (session[1] != 0) {
      return;
    }
    if (session[3] != 0) {
      return;
    }
    (**(code **)(*(int *)*session + 0xc))(text);
    bVar2 = 1;
    if ((void *)session[5] != (void *)0x0) {
      bVar2 = pdb_stream_table_close((void *)session[5]);
      session[5] = 0;
      bVar2 = bVar2 & 1;
    }
    if (((((uint)(1 < g_warnings_as_errors) + g_error_count == 0) && ((char)session[6] == '\0')) &&
        (iVar3 = (**(code **)(*(int *)*session + 0x24))(), iVar3 == 0)) ||
       (iVar3 = (**(code **)(*(int *)*session + 0x28))(), iVar3 == 0)) {
      bVar1 = 0;
    }
    else {
      bVar1 = 1;
    }
    *session = 0;
    if ((bVar2 & bVar1) != 0) {
      return;
    }
    message = &stack0xfffffef8;
    goto LAB_10499e4f;
  }
  if ((char)session[6] != '\0') {
    return;
  }
  iVar3 = (**(code **)(*(int *)session[2] + 0x24))();
  if (iVar3 != 0) {
    bVar2 = 1;
    if ((void *)session[5] != (void *)0x0) {
      bVar2 = pdb_stream_table_close((void *)session[5]);
      session[5] = 0;
      bVar2 = bVar2 & 1;
    }
    if (((uint)(1 < g_warnings_as_errors) + g_error_count == 0) && ((char)session[6] == '\0')) {
      iVar3 = (**(code **)(*(int *)*session + 0x24))();
      bVar1 = 0;
      if (iVar3 != 0) goto LAB_10443e87;
    }
    else {
LAB_10443e87:
      bVar1 = 1;
    }
    if ((bVar2 & bVar1) != 0) {
      return;
    }
  }
  message = (char *)(**(code **)(*(int *)*session + 0xc))(text);
LAB_10499e4f:
  diag_error(0x1d7,message);
  return;
}

