void cxx_eh_create_funcinfo(void)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  
  cxx_eh_create_record_and_sections();
  reset_eh_state_numbering();
  if (g_eh_return_object_record != (c2_eh_state *)0x0) {
    push_eh_state(g_eh_return_object_record);
  }
  g_ehfuncinfo_symbol = fe_symbol_new_local_cur(6,0x1c,7,1,'\x04',0x80);
  if (g_opt_edit_and_continue != 0) {
    uVar3 = 0xffffffff;
    pcVar2 = g_cur_function->fsym->name;
    do {
      if (uVar3 == 0) break;
      uVar3 = uVar3 - 1;
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    pcVar2 = arena_alloc(0,~uVar3 + 0xd);
    sprintf(pcVar2,"__ehfuncinfo$%s",g_cur_function->fsym->name);
    g_ehfuncinfo_symbol->name = pcVar2;
  }
  return;
}

