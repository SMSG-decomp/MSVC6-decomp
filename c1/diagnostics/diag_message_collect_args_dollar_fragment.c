void __thiscall
diag_message_collect_args_dollar_fragment(fe_message *m,int **ap,char *fmt,int index)

{
  uint *puVar1;
  int *piVar2;
  char cVar3;
  char *pcVar4;
  int iVar5;
  fe_message_arg *pfVar6;
  
code_r0x10642f7b:
  cVar3 = *fmt;
  fmt = fmt + 1;
  pfVar6 = m->args + index;
  do {
    switch(cVar3) {
    case '*':
      piVar2 = *ap;
      index = index + 1;
      *ap = piVar2 + 1;
      cVar3 = (char)*piVar2;
      pfVar6->ch = cVar3;
      pfVar6 = pfVar6 + 1;
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
      index = index + -1;
      goto switchD_1061e2c4_caseD_25;
    case 'p':
      goto code_r0x10642f7b;
    }
  } while( true );
  do {
    fmt = pcVar4 + 2;
    switch(pcVar4[1]) {
    case '$':
      goto code_r0x10642f7b;
    case 'D':
    case 'U':
    case 'X':
      puVar1 = (uint *)*ap;
      *ap = (int *)(puVar1 + 2);
      m->args[iVar5 + 1].half[0] = *puVar1;
      *(uint *)((int)m->args + iVar5 * 8 + 0xc) = puVar1[1];
    default:
switchD_1061e2c4_caseD_25:
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
switchD_1061e2c4_caseD_63:
      piVar2 = *ap;
      *ap = piVar2 + 1;
      m->args[index].ch = (char)*piVar2;
      break;
    case 'd':
    case 's':
    case 'u':
    case 'x':
switchD_1061e2c4_caseD_64:
      puVar1 = (uint *)*ap;
      *ap = (int *)(puVar1 + 1);
      m->args[index].half[0] = *puVar1;
      break;
    }
  } while( true );
}

