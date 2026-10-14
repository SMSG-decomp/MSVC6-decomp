int __cdecl vector_iterator_next(uint *iter)

{
  short sVar1;
  ushort *puVar2;
  uint uVar3;
  uint3 uVar4;
  
  puVar2 = (ushort *)*iter;
  uVar4 = (uint3)((uint)iter >> 8);
  if (puVar2 != (ushort *)0x0) {
    sVar1 = (short)iter[1];
    if ((int)sVar1 < (int)(uint)*puVar2) {
      uVar3 = *(uint *)(*(int *)(puVar2 + 4) + sVar1 * 4);
      *(short *)(iter + 1) = sVar1 + 1;
      iter[2] = uVar3;
      return CONCAT31(uVar4,1);
    }
  }
  return (uint)uVar4 << 8;
}

