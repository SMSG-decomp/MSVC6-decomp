void fputs_stderr(char *s)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  
  uVar2 = 0xffffffff;
  pcVar3 = s;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  fwrite(s,~uVar2 - 1,1,(FILE *)(_iob_exref + 0x40));
  return;
}

