c1_u8 * __cdecl str_dup_arena(char *s,int arena)

{
  char cVar1;
  uint *puVar2;
  uchar *puVar3;
  uint uVar4;
  uint uVar5;
  fe_arena *a;
  uint *puVar6;
  uchar *puVar7;
  char *pcVar8;
  uint *dst;
  
  uVar4 = 0xffffffff;
  a = g_arenas + arena;
  pcVar8 = s;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar1 != '\0');
  puVar2 = (uint *)a->cur;
  puVar7 = (uchar *)((int)puVar2 + (~uVar4 + 3 & 0xfffffffc));
  puVar3 = g_arenas[arena].end;
  a->cur = puVar7;
  if (puVar3 < puVar7) {
    arena_grow(a);
  }
  uVar4 = 0xffffffff;
  do {
    pcVar8 = s;
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    pcVar8 = s + 1;
    cVar1 = *s;
    s = pcVar8;
  } while (cVar1 != '\0');
  uVar4 = ~uVar4;
  puVar6 = (uint *)(pcVar8 + -uVar4);
  dst = puVar2;
  for (uVar5 = uVar4 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {
    *dst = *puVar6;
    puVar6 = puVar6 + 1;
    dst = dst + 1;
  }
  for (uVar4 = uVar4 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(char *)dst = (char)*puVar6;
    puVar6 = (uint *)((int)puVar6 + 1);
    dst = (uint *)((int)dst + 1);
  }
  return (c1_u8 *)puVar2;
}

