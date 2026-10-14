c1_u8 * __cdecl str_dup_arena(char *s,int arena)

{
  char cVar1;
  c1_u8 *pcVar2;
  uint uVar3;
  uint uVar4;
  c1_arena *a;
  c1_u8 *pcVar5;
  char *pcVar6;
  c1_u8 *pcVar7;
  
  uVar3 = 0xffffffff;
  a = g_arenas + arena;
  pcVar6 = s;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  pcVar2 = a->cur;
  pcVar5 = g_arenas[arena].end;
  a->cur = pcVar2 + (~uVar3 + 3 & 0xfffffffc);
  if (pcVar5 < pcVar2 + (~uVar3 + 3 & 0xfffffffc)) {
    arena_grow(a);
  }
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
  pcVar5 = (c1_u8 *)(pcVar6 + -uVar3);
  pcVar7 = pcVar2;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *(undefined4 *)pcVar7 = *(undefined4 *)pcVar5;
    pcVar5 = pcVar5 + 4;
    pcVar7 = pcVar7 + 4;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar7 = *pcVar5;
    pcVar5 = pcVar5 + 1;
    pcVar7 = pcVar7 + 1;
  }
  return pcVar2;
}

