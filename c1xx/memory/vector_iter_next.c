char __cdecl vector_iter_next(int *it)

{
  short sVar1;
  short *psVar2;
  int iVar3;
  
  psVar2 = (short *)*it;
  if (psVar2 == (short *)0x0) {
    return '\0';
  }
  sVar1 = (short)it[1];
  if (sVar1 < *psVar2) {
    iVar3 = *(int *)(psVar2 + sVar1 * 2 + 2);
    *(short *)(it + 1) = sVar1 + 1;
    it[2] = iVar3;
    return '\x01';
  }
  return '\0';
}

