void __cdecl format_message_args(char *out,char *fmt,char *args)

{
  uint32_t *puVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  char *pcVar6;
  char *pcVar7;
  char *str_arg;
  char *pcVar8;
  
  cVar2 = *fmt;
  if (cVar2 == '\0') {
    *out = '\0';
    return;
  }
  pcVar8 = args + -4;
LAB_10796db9:
  if (cVar2 == '%') {
    uVar3 = (int)fmt[1] - 0x46;
    if (uVar3 < 0x33) {
LAB_10796dcd:
      switch((&switchD_10796dd5::switchdataD_10796eb0)[uVar3]) {
      case 0x46:
        goto switchD_10796dd5_caseD_46;
      default:
        break;
      case 99:
        str_arg = pcVar8 + 4;
        pcVar8 = pcVar8 + 4;
        *out = (char)*(undefined4 *)str_arg;
        out = out + 1;
        fmt = fmt + 2;
        goto LAB_10796e3e;
      case 100:
      case 0x78:
        puVar1 = (uint32_t *)(pcVar8 + 4);
        pcVar8 = pcVar8 + 4;
        iVar4 = format_integer(*puVar1,out,(-(uint)(fmt[1] != 'd') & 6) + 10);
        out = out + iVar4;
        fmt = fmt + 2;
        goto LAB_10796e3e;
      case 0x6c:
        goto switchD_10796dd5_caseD_6c;
      case 0x73:
        str_arg = *(char **)(pcVar8 + 4);
        pcVar8 = pcVar8 + 4;
        if ((str_arg == (char *)0x0) || (*str_arg == '\0')) goto LAB_10796e3b;
        uVar3 = 0xffffffff;
        pcVar6 = str_arg;
        goto code_r0x10796e11;
      }
    }
switchD_10796dd5_caseD_47:
    *out = *fmt;
  }
  else {
    *out = cVar2;
  }
  out = out + 1;
  fmt = fmt + 1;
  goto LAB_10796e3e;
  while( true ) {
    uVar3 = uVar3 - 1;
    pcVar7 = pcVar6 + 1;
    cVar2 = *pcVar6;
    pcVar6 = pcVar7;
    if (cVar2 == '\0') break;
code_r0x10796e11:
    pcVar7 = pcVar6;
    if (uVar3 == 0) break;
  }
  uVar3 = ~uVar3;
  pcVar6 = pcVar7 + -uVar3;
  pcVar7 = out;
  for (uVar5 = uVar3 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar6;
    pcVar6 = pcVar6 + 4;
    pcVar7 = pcVar7 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar7 = *pcVar6;
    pcVar6 = pcVar6 + 1;
    pcVar7 = pcVar7 + 1;
  }
  uVar3 = 0xffffffff;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar2 = *str_arg;
    str_arg = str_arg + 1;
  } while (cVar2 != '\0');
  out = out + (~uVar3 - 1);
LAB_10796e3b:
  fmt = fmt + 2;
LAB_10796e3e:
  cVar2 = *fmt;
  if (cVar2 == '\0') {
    *out = '\0';
    return;
  }
  goto LAB_10796db9;
switchD_10796dd5_caseD_6c:
switchD_10796dd5_caseD_46:
  str_arg = fmt + 2;
  fmt = fmt + 1;
  uVar3 = (int)*str_arg - 0x46;
  if (0x32 < uVar3) goto switchD_10796dd5_caseD_47;
  goto LAB_10796dcd;
}

