void __thiscall
diag_message_collect_args_dollar_fragment(c1_message *msg,int **ap,char *fmt,int index)

{
  c1_u32 *pcVar1;
  int *piVar2;
  char cVar3;
  char *pcVar4;
  int iVar5;
  c1_message_arg *pcVar6;
  
code_r0x1048998c:
  cVar3 = *fmt;
  fmt = fmt + 1;
  pcVar6 = msg->args + index;
  do {
    switch(cVar3) {
    case '*':
      piVar2 = *ap;
      index = index + 1;
      *ap = piVar2 + 1;
      cVar3 = (char)*piVar2;
      pcVar6->ch = cVar3;
      pcVar6 = pcVar6 + 1;
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
      index = index + -1;
      goto switchD_1043c97f_caseD_25;
    case 'p':
      goto code_r0x1048998c;
    }
  } while( true );
  do {
    fmt = pcVar4 + 2;
    switch(pcVar4[1]) {
    case '$':
      goto code_r0x1048998c;
    case 'D':
    case 'U':
    case 'X':
      pcVar1 = (c1_u32 *)*ap;
      *ap = (int *)(pcVar1 + 2);
      msg->args[iVar5 + 1].half[0] = *pcVar1;
      *(c1_u32 *)((int)msg->args + iVar5 * 8 + 0xc) = pcVar1[1];
    default:
switchD_1043c97f_caseD_25:
      iVar5 = index;
      index = iVar5 + 1;
      do {
        pcVar4 = fmt;
        if (*pcVar4 == '\0') {
          return;
        }
        fmt = pcVar4 + 1;
      } while (*pcVar4 != '%');
      break;
    case 'c':
switchD_1043c97f_caseD_63:
      piVar2 = *ap;
      *ap = piVar2 + 1;
      msg->args[index].ch = (char)*piVar2;
      break;
    case 'd':
    case 's':
    case 'u':
    case 'x':
switchD_1043c97f_caseD_64:
      pcVar1 = (c1_u32 *)*ap;
      *ap = (int *)(pcVar1 + 1);
      msg->args[index].half[0] = *pcVar1;
      break;
    }
  } while( true );
}

