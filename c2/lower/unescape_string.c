char * __fastcall unescape_string(char *s)

{
  char *pcVar1;
  char cVar2;
  char *pcVar3;
  char *pcVar4;
  
  pcVar3 = s;
  cVar2 = *s;
  pcVar4 = s;
  while (cVar2 != '\0') {
    if (cVar2 == '\\') {
      pcVar1 = pcVar4 + 1;
      pcVar4 = pcVar4 + 1;
      if (*pcVar1 == 'n') {
        *pcVar4 = '\n';
      }
      else if (*pcVar1 == 't') {
        *pcVar4 = '\t';
      }
      else {
        *s = '\\';
        s = s + 1;
      }
    }
    *s = *pcVar4;
    pcVar1 = pcVar4 + 1;
    s = s + 1;
    pcVar4 = pcVar4 + 1;
    cVar2 = *pcVar1;
  }
  *s = '\0';
  return pcVar3;
}

