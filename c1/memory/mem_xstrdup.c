char * __cdecl mem_xstrdup(char *s)

{
  char cVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  char *pcVar6;
  uint *dst;
  
  uVar3 = 0xffffffff;
  pcVar6 = s;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  puVar2 = mem_xmalloc(~uVar3);
  uVar3 = 0xffffffff;
  do {
    pcVar6 = s;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar6 = s + 1;
    cVar1 = *s;
    s = pcVar6;
  } while (cVar1 != '\0');
  uVar3 = ~uVar3;
  puVar5 = (uint *)(pcVar6 + -uVar3);
  dst = puVar2;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *dst = *puVar5;
    puVar5 = puVar5 + 1;
    dst = dst + 1;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(char *)dst = (char)*puVar5;
    puVar5 = (uint *)((int)puVar5 + 1);
    dst = (uint *)((int)dst + 1);
  }
  return (char *)puVar2;
}

