c2_fe_symbol * get_ehhandler_symbol(void)

{
  char cVar1;
  int iVar2;
  c2_fe_symbol *pcVar3;
  char *pcVar4;
  uint uVar5;
  
  pcVar3 = g_ehhandler_symbol;
  if (g_ehhandler_symbol == (c2_fe_symbol *)0x0) {
    pcVar3 = label_symbol_new();
    iVar2 = g_opt_edit_and_continue;
    pcVar3->role = 'U';
    g_ehhandler_symbol = pcVar3;
    (pcVar3->u3e).label_flags = (pcVar3->u3e).label_flags | 1;
    if (iVar2 != 0) {
      uVar5 = 0xffffffff;
      pcVar4 = g_cur_function->fsym->name;
      do {
        if (uVar5 == 0) break;
        uVar5 = uVar5 - 1;
        cVar1 = *pcVar4;
        pcVar4 = pcVar4 + 1;
      } while (cVar1 != '\0');
      pcVar4 = arena_alloc(0,~uVar5 + 0xc);
      sprintf(pcVar4,"__ehhandler$%s",g_cur_function->fsym->name);
      pcVar3 = g_ehhandler_symbol;
      g_ehhandler_symbol->name = pcVar4;
    }
  }
  return pcVar3;
}

