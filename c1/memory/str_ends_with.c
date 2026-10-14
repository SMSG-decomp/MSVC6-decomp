int __cdecl str_ends_with(char *s,char *suffix)

{
  char cVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  byte *pbVar5;
  char *pcVar6;
  bool bVar7;
  
  uVar3 = 0xffffffff;
  pcVar6 = s;
  do {
    if (uVar3 == 0) break;
    uVar3 = uVar3 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  uVar4 = 0xffffffff;
  pcVar6 = suffix;
  do {
    if (uVar4 == 0) break;
    uVar4 = uVar4 - 1;
    cVar1 = *pcVar6;
    pcVar6 = pcVar6 + 1;
  } while (cVar1 != '\0');
  if ((int)(~uVar3 - 1) <= (int)(~uVar4 - 1)) {
    return 0;
  }
  pbVar5 = (byte *)(s + ((~uVar3 - 1) - (~uVar4 - 1)));
  while( true ) {
    bVar2 = *pbVar5;
    bVar7 = bVar2 < (byte)*suffix;
    if (bVar2 != *suffix) break;
    if (bVar2 == 0) {
      return 1;
    }
    bVar2 = pbVar5[1];
    bVar7 = bVar2 < (byte)suffix[1];
    if (bVar2 != suffix[1]) break;
    pbVar5 = pbVar5 + 2;
    suffix = suffix + 2;
    if (bVar2 == 0) {
      return 1;
    }
  }
  return (uint)(1 - bVar7 == (uint)(bVar7 != 0));
}

