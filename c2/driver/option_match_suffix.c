int __fastcall option_match_suffix(char *pattern,char *arg,int kind)

{
  char *pcVar1;
  char *pcVar2;
  char cVar3;
  char *pcVar4;
  char *pcVar5;
  
  pcVar4 = pattern + 1;
  if (pattern[1] == '\0') {
    return 1;
  }
  do {
    pcVar5 = pcVar4;
    pcVar4 = pcVar5 + 1;
  } while (pcVar5[1] != '\0');
  cVar3 = arg[1];
  pcVar4 = arg;
  while (cVar3 != '\0') {
    cVar3 = pcVar4[2];
    pcVar4 = pcVar4 + 1;
  }
  if (*pcVar4 == *pcVar5) {
    do {
      pcVar1 = pcVar4 + -1;
      pcVar2 = pcVar5 + -1;
      pcVar4 = pcVar4 + -1;
      pcVar5 = pcVar5 + -1;
    } while (*pcVar1 == *pcVar2);
  }
  if ((pcVar5 == pattern) && (arg <= pcVar4)) {
    return 1;
  }
  return 0;
}

