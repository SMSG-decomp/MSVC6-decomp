void __cdecl format_buffer_prepend_string(int buf,char *s)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  uint n;
  char *pcVar4;
  
  uVar3 = 0xffffffff;
  pcVar4 = s;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar4;
    pcVar4 = pcVar4 + 1;
  } while (cVar1 != '\0');
  n = ~uVar3 - 1;
  if (n != 0) {
    pcVar2 = format_buffer_reserve(buf,0,n);
    pcVar4 = s + (~uVar3 - 2);
    for (; n != 0; n = n - 1) {
      *pcVar2 = *pcVar4;
      pcVar2 = pcVar2 + -1;
      pcVar4 = pcVar4 + -1;
    }
  }
  return;
}

