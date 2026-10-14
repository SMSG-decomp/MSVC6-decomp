char __cdecl type_set_equal(short *a,short *b)

{
  short sVar1;
  short sVar2;
  int iVar3;
  short *psVar4;
  short *psVar5;
  
  if (a == (short *)0x0) {
    return b == (short *)0x0;
  }
  if (b == (short *)0x0) {
    return '\0';
  }
  if (a == b) {
    return '\x01';
  }
  if (*a == *b) {
    iVar3 = (int)*a << 2;
    psVar4 = a + 2;
    psVar5 = b + 2;
    do {
      if (iVar3 == 0) {
        return '\x01';
      }
      iVar3 = iVar3 + -1;
      sVar1 = *psVar5;
      sVar2 = *psVar4;
      psVar4 = (short *)((int)psVar4 + 1);
      psVar5 = (short *)((int)psVar5 + 1);
    } while ((char)sVar2 == (char)sVar1);
    return '\0';
  }
  return '\0';
}

