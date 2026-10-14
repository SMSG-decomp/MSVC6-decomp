char * __cdecl decorate_number(char *out,uint n)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  byte bVar4;
  char *pcVar5;
  uint uVar6;
  
  if (n == 0) {
    *out = 'A';
    out[1] = '@';
    return out + 2;
  }
  bVar4 = (byte)n;
  if ((n != 0) && (n < 0xb)) {
    *out = bVar4 + 0x2f;
    return out + 1;
  }
  uVar6 = 0xf0000000;
  iVar3 = 0x1c;
  do {
    if ((n & uVar6) != 0) {
      if (iVar3 != 0) {
        do {
          pcVar5 = out;
          uVar1 = uVar6 & n;
          bVar2 = (byte)iVar3;
          iVar3 = iVar3 + -4;
          uVar6 = uVar6 >> 4;
          *pcVar5 = (char)(uVar1 >> (bVar2 & 0x1f)) + 'A';
          out = pcVar5 + 1;
        } while (iVar3 != 0);
        pcVar5[1] = (bVar4 & 0xf) + 0x41;
        pcVar5[2] = '@';
        return pcVar5 + 3;
      }
      break;
    }
    iVar3 = iVar3 + -4;
    uVar6 = uVar6 >> 4;
  } while (iVar3 != 0);
  *out = (bVar4 & 0xf) + 0x41;
  out[1] = '@';
  return out + 2;
}

