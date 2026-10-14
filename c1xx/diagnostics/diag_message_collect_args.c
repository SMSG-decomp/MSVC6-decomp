void __thiscall diag_message_collect_args(void *this,int *id)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  int iVar4;
  char *pcVar5;
  uint *arg_dword_pair;
  char *arg_byte;
  uint *arg_dword_pair_2;
  
  iVar4 = 0;
  cVar2 = **(char **)((int)this + 4);
  pcVar5 = *(char **)((int)this + 4);
  do {
    if (cVar2 == '\0') {
      return;
    }
    pcVar3 = pcVar5 + 1;
    if (cVar2 == '%') {
      cVar2 = *pcVar3;
      pcVar3 = pcVar5 + 2;
      switch(cVar2) {
      case '$':
diag_message_collect_args_dollar_fragment:
        cVar2 = *pcVar3;
        pcVar3 = pcVar3 + 1;
        pcVar5 = (char *)((int)this + iVar4 * 8 + 8);
        do {
          switch(cVar2) {
          case '*':
            pcVar1 = (char *)*id;
            iVar4 = iVar4 + 1;
            *id = (int)(pcVar1 + 4);
            cVar2 = *pcVar1;
            *pcVar5 = cVar2;
            pcVar5 = pcVar5 + 8;
            break;
          default:
            goto switchD_1043c97f_caseD_25;
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
            goto switchD_1043c97f_caseD_64;
          case 'L':
            goto switchD_1043c97f_caseD_63;
          case 'N':
            iVar4 = iVar4 + -1;
            goto switchD_1043c97f_caseD_25;
          case 'p':
            goto diag_message_collect_args_dollar_fragment;
          }
        } while( true );
      case 'D':
      case 'U':
      case 'X':
        arg_dword_pair = (uint *)*id;
        *id = (int)(arg_dword_pair + 2);
        *(uint *)((int)this + iVar4 * 8 + 8) = *arg_dword_pair;
        *(uint *)((int)this + iVar4 * 8 + 0xc) = arg_dword_pair[1];
        break;
      case 'c':
switchD_1043c97f_caseD_63:
        arg_byte = (char *)*id;
        *id = (int)(arg_byte + 4);
        *(char *)((int)this + iVar4 * 8 + 8) = *arg_byte;
        break;
      case 'd':
      case 's':
      case 'u':
      case 'x':
switchD_1043c97f_caseD_64:
        arg_dword_pair_2 = (uint *)*id;
        *id = (int)(arg_dword_pair_2 + 1);
        *(uint *)((int)this + iVar4 * 8 + 8) = *arg_dword_pair_2;
      }
switchD_1043c97f_caseD_25:
      iVar4 = iVar4 + 1;
    }
    cVar2 = *pcVar3;
    pcVar5 = pcVar3;
  } while( true );
}

