void __cdecl format_buffer_append_string(int buf,char *s)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  uint uVar4;
  
  uVar3 = 0xffffffff;
  pcVar2 = s;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  uVar4 = ~uVar3 - 1;
  pcVar2 = format_buffer_reserve(buf,1,uVar4);
  for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)pcVar2 = *(undefined4 *)s;
    s = s + 4;
    pcVar2 = pcVar2 + 4;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *pcVar2 = *s;
    s = s + 1;
    pcVar2 = pcVar2 + 1;
  }
  return;
}

