char * __cdecl debug_put_length_prefixed_name(char *out,char *name)

{
  char cVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  char *pcVar5;
  
  uVar2 = 0xffffffff;
  pcVar5 = name;
  do {
    if (uVar2 == 0) break;
    uVar2 = uVar2 - 1;
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  uVar3 = ~uVar2 - 1;
  if (uVar3 < 0x100) {
    *out = (char)uVar3;
    pcVar5 = out + 1;
    for (uVar4 = uVar3 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)pcVar5 = *(undefined4 *)name;
      name = name + 4;
      pcVar5 = pcVar5 + 4;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *pcVar5 = *name;
      name = name + 1;
      pcVar5 = pcVar5 + 1;
    }
    return out + ~uVar2;
  }
  TruncStFromSz(out,name,uVar3);
  diag_warning(3,0x312,name,0xff,0x164);
  return out + 0x100;
}

