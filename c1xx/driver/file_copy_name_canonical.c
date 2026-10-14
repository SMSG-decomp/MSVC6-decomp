char * __cdecl file_copy_name_canonical(char terminator,char *file,char *out)

{
  char cVar1;
  byte *pbVar2;
  uint uVar3;
  uint uVar4;
  c1_u32 *pcVar5;
  c1_u32 *dst;
  char *pcVar6;
  
  uVar3 = 0xffffffff;
  do {
    pcVar6 = file;
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    pcVar6 = file + 1;
    cVar1 = *file;
    file = pcVar6;
  } while (terminator != cVar1);
  uVar3 = ~uVar3;
  pcVar5 = (c1_u32 *)(pcVar6 + -uVar3);
  dst = (c1_u32 *)out;
  for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
    *dst = *pcVar5;
    pcVar5 = pcVar5 + 1;
    dst = dst + 1;
  }
  for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(char *)dst = (char)*pcVar5;
    pcVar5 = (c1_u32 *)((int)pcVar5 + 1);
    dst = (c1_u32 *)((int)dst + 1);
  }
  pbVar2 = file_name_canonicalize((byte *)out);
  return (char *)pbVar2;
}

