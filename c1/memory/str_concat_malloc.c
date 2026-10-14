char * __cdecl str_concat_malloc(char *a,char *b)

{
  char cVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  uint *dst_2;
  char *pcVar8;
  uint *dst;
  
  uVar3 = 0xffffffff;
  pcVar8 = a;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  iVar4 = ~uVar3 - 1;
  uVar5 = 0xffffffff;
  pcVar8 = b;
  do {
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  puVar2 = mem_xmalloc(~uVar5 + 1 + iVar4);
  uVar5 = 0xffffffff;
  do {
    pcVar8 = a;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar8 = a + 1;
    cVar1 = *a;
    a = pcVar8;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  puVar7 = (uint *)(pcVar8 + -uVar5);
  dst_2 = puVar2;
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *dst_2 = *puVar7;
    puVar7 = puVar7 + 1;
    dst_2 = dst_2 + 1;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(char *)dst_2 = (char)*puVar7;
    puVar7 = (uint *)((int)puVar7 + 1);
    dst_2 = (uint *)((int)dst_2 + 1);
  }
  uVar5 = 0xffffffff;
  *(char *)((int)puVar2 + iVar4) = '/';
  do {
    pcVar8 = b;
    if (uVar5 == 0) break;
    uVar5 = uVar5 - 1;
    pcVar8 = b + 1;
    cVar1 = *b;
    b = pcVar8;
  } while (cVar1 != '\0');
  uVar5 = ~uVar5;
  puVar7 = (uint *)(pcVar8 + -uVar5);
  dst = (uint *)((int)puVar2 + ~uVar3);
  for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {
    *dst = *puVar7;
    puVar7 = puVar7 + 1;
    dst = dst + 1;
  }
  for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
    *(char *)dst = (char)*puVar7;
    puVar7 = (uint *)((int)puVar7 + 1);
    dst = (uint *)((int)dst + 1);
  }
  return (char *)puVar2;
}

