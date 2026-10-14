int __cdecl str_compare_nocase(char *a,char *b)

{
  char cVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  
  if (a != b) {
    if ((a == (char *)0x0) || (b == (char *)0x0)) {
      return -1;
    }
    do {
      while( true ) {
        cVar1 = *a;
        cVar2 = *b;
        a = a + 1;
        b = b + 1;
        if (cVar1 == cVar2) break;
        iVar3 = toupper((int)cVar2);
        iVar4 = toupper((int)cVar1);
        if (iVar4 != iVar3) {
          return (int)cVar1 - (int)cVar2;
        }
      }
    } while (cVar1 != '\0');
  }
  return 0;
}

