char * __fastcall arena_strdup(char *s,int arena)

{
  char cVar1;
  char *copy;
  uint uVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  
  uVar2 = 0xffffffff;
  copy = s;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *copy;
    copy = copy + 1;
  } while (cVar1 != '\0');
  copy = arena_alloc(arena,~uVar2);
  uVar2 = 0xffffffff;
  do {
    pcVar4 = s;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar4 = s + 1;
    cVar1 = *s;
    s = pcVar4;
  } while (cVar1 != '\0');
  uVar2 = ~uVar2;
  pcVar4 = pcVar4 + -uVar2;
  pcVar5 = copy;
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)pcVar5 = *(undefined4 *)pcVar4;
    pcVar4 = pcVar4 + 4;
    pcVar5 = pcVar5 + 4;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *pcVar5 = *pcVar4;
    pcVar4 = pcVar4 + 1;
    pcVar5 = pcVar5 + 1;
  }
  return copy;
}

