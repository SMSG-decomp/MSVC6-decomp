void __fastcall string_end(char *s)

{
  char *pcVar1;
  char cVar2;
  
  if (s != (char *)0x0) {
    cVar2 = *s;
    while (cVar2 != '\0') {
      pcVar1 = s + 1;
      s = s + 1;
      cVar2 = *pcVar1;
    }
  }
  return;
}

