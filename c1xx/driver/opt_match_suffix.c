int __cdecl opt_match_suffix(char *pattern,char *word)

{
  char *pcVar1;
  char *pcVar2;
  char cVar3;
  char *pcVar4;
  char *pcVar5;
  
  pcVar5 = pattern;
  if (pattern[1] == '\0') {
    return 1;
  }
  do {
    pcVar4 = pcVar5 + 1;
    pcVar1 = pcVar5 + 2;
    pcVar5 = pcVar4;
  } while (*pcVar1 != '\0');
  cVar3 = word[1];
  pcVar5 = word;
  while (cVar3 != '\0') {
    cVar3 = pcVar5[2];
    pcVar5 = pcVar5 + 1;
  }
  if (*pcVar5 == *pcVar4) {
    do {
      pcVar1 = pcVar5 + -1;
      pcVar2 = pcVar4 + -1;
      pcVar5 = pcVar5 + -1;
      pcVar4 = pcVar4 + -1;
    } while (*pcVar1 == *pcVar2);
  }
  if ((pcVar4 == pattern) && (word <= pcVar5)) {
    return 1;
  }
  return 0;
}

