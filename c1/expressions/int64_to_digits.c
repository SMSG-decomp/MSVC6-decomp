void __cdecl int64_to_digits(int *value,char *buf,uint32_t radix,int negative)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  uint32_t hi;
  char *pcVar4;
  char *pcVar5;
  int iVar6;
  bool bVar7;
  uint64_t uVar8;
  uint64_t uVar9;
  
  iVar3 = value[1];
  iVar6 = *value;
  if (negative != 0) {
    *buf = '-';
    buf = buf + 1;
    bVar7 = iVar6 != 0;
    iVar6 = -iVar6;
    iVar3 = -(iVar3 + (uint)bVar7);
  }
  uVar9 = CONCAT44(iVar3,iVar6);
  pcVar2 = buf;
  do {
    pcVar4 = pcVar2;
    hi = (uint32_t)(uVar9 >> 0x20);
    uVar8 = _aullrem((uint32_t)uVar9,hi,radix,0);
    *pcVar4 = "0123456789abcdefghijklmnopqrstuvwxyz"[(int)uVar8];
    uVar9 = _aulldiv((uint32_t)uVar9,hi,radix,0);
    pcVar2 = pcVar4 + 1;
  } while (uVar9 != 0);
  pcVar4[1] = '\0';
  do {
    cVar1 = *pcVar4;
    pcVar5 = pcVar4 + -1;
    pcVar2 = buf + 1;
    *pcVar4 = *buf;
    *buf = cVar1;
    pcVar4 = pcVar5;
    buf = pcVar2;
  } while (pcVar2 < pcVar5);
  return;
}

