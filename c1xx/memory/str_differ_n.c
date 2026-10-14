int __cdecl str_differ_n(char *a,char *b,int n)

{
  bool bVar1;
  
  if (b == (char *)0x0) {
    if (a == (char *)0x0) {
      return 0;
    }
  }
  else if (a != (char *)0x0) {
    bVar1 = true;
    do {
      if (n == 0) break;
      n = n + -1;
      bVar1 = *a == *b;
      a = a + 1;
      b = b + 1;
    } while (bVar1);
    return (uint)!bVar1;
  }
  return 1;
}

