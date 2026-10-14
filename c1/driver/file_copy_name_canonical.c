char * __cdecl file_copy_name_canonical(char terminator,char *file,char *out)

{
  char cVar1;
  char *extraout_EAX;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  uint *dst;
  char *pcVar5;
  
  uVar2 = 0xffffffff;
  do {
    pcVar5 = file;
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    pcVar5 = file + 1;
    cVar1 = *file;
    file = pcVar5;
  } while (terminator != cVar1);
  uVar2 = ~uVar2;
  puVar4 = (uint *)(pcVar5 + -uVar2);
  dst = (uint *)out;
  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *dst = *puVar4;
    puVar4 = puVar4 + 1;
    dst = dst + 1;
  }
  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *(char *)dst = (char)*puVar4;
    puVar4 = (uint *)((int)puVar4 + 1);
    dst = (uint *)((int)dst + 1);
  }
  file_name_canonicalize((byte *)out);
  return extraout_EAX;
}

