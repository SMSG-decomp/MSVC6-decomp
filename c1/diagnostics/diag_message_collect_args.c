void __thiscall diag_message_collect_args(fe_message *m,va_list *args)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  int iVar4;
  fe_message_arg *pfVar5;
  uint *arg;
  uint *arg_2;
  
  iVar4 = 0;
  cVar2 = *m->text;
  pcVar1 = m->text;
  do {
    if (cVar2 == '\0') {
      return;
    }
    pcVar3 = pcVar1 + 1;
    if (cVar2 == '%') {
      cVar2 = *pcVar3;
      pcVar3 = pcVar1 + 2;
      switch(cVar2) {
      case '$':
diag_message_collect_args_dollar_fragment:
        cVar2 = *pcVar3;
        pcVar3 = pcVar3 + 1;
        pfVar5 = m->args + iVar4;
        do {
          switch(cVar2) {
          case '*':
            pcVar1 = *args;
            iVar4 = iVar4 + 1;
            *args = pcVar1 + 4;
            cVar2 = *pcVar1;
            pfVar5->ch = cVar2;
            pfVar5 = pfVar5 + 1;
            break;
          default:
            goto switchD_1061e2c4_caseD_25;
          case 'B':
          case 'C':
          case 'D':
          case 'E':
          case 'I':
          case 'M':
          case 'O':
          case 'P':
          case 'S':
          case 'T':
          case 'e':
          case 's':
            goto switchD_1061e2c4_caseD_64;
          case 'L':
            goto switchD_1061e2c4_caseD_63;
          case 'N':
            iVar4 = iVar4 + -1;
            goto switchD_1061e2c4_caseD_25;
          case 'p':
            goto diag_message_collect_args_dollar_fragment;
          }
        } while( true );
      case 'D':
      case 'U':
      case 'X':
        arg = (uint *)*args;
        *args = (va_list)(arg + 2);
        m->args[iVar4].value = *arg;
        *(uint *)((int)m->args + iVar4 * 8 + 4) = arg[1];
        break;
      case 'c':
switchD_1061e2c4_caseD_63:
        pcVar1 = *args;
        *args = pcVar1 + 4;
        m->args[iVar4].ch = *pcVar1;
        break;
      case 'd':
      case 's':
      case 'u':
      case 'x':
switchD_1061e2c4_caseD_64:
        arg_2 = (uint *)*args;
        *args = (va_list)(arg_2 + 1);
        m->args[iVar4].value = *arg_2;
      }
switchD_1061e2c4_caseD_25:
      iVar4 = iVar4 + 1;
    }
    cVar2 = *pcVar3;
    pcVar1 = pcVar3;
  } while( true );
}

