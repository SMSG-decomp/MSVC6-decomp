int __thiscall array_save(Array_DWORD *array,Buffer *buf)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  Buffer *pBVar5;
  ulong *puVar6;
  
  puVar1 = &array->itMac;
  if ((puVar1 == (uint *)0x0) ||
     ((buf->pbStart + buf->cbAlloc < buf->pbEnd + 4 && (iVar2 = il_buffer_grow(buf,4), iVar2 == 0)))
     ) {
    return 0;
  }
  pBVar5 = buf;
  if (&stack0x00000000 != (undefined1 *)0xfffffffc) {
    pBVar5 = (Buffer *)buf->pbEnd;
  }
  if (buf->pbStart != (PB)0x0) {
    buf->pbEnd = buf->pbEnd + 4;
  }
  pBVar5->pbStart = (PB)*puVar1;
  uVar4 = *puVar1;
  if (uVar4 != 0) {
    puVar6 = array->rgt;
    iVar2 = uVar4 * 4;
    if (puVar6 == (ulong *)0x0) {
      return 0;
    }
    if (iVar2 < 0) {
      return 0;
    }
    if ((buf->pbStart + buf->cbAlloc < buf->pbEnd + iVar2) &&
       (iVar3 = il_buffer_grow(buf,iVar2), iVar3 == 0)) {
      return 0;
    }
    pBVar5 = buf;
    if (&stack0x00000000 != (undefined1 *)0xfffffffc) {
      pBVar5 = (Buffer *)buf->pbEnd;
    }
    if (buf->pbStart != (PB)0x0) {
      buf->pbEnd = buf->pbEnd + iVar2;
    }
    for (uVar4 = uVar4 & 0x3fffffff; uVar4 != 0; uVar4 = uVar4 - 1) {
      pBVar5->pbStart = (PB)*puVar6;
      puVar6 = puVar6 + 1;
      pBVar5 = (Buffer *)&pBVar5->pbEnd;
    }
    for (iVar2 = 0; iVar2 != 0; iVar2 = iVar2 + -1) {
      *(char *)&pBVar5->pbStart = (char)*puVar6;
      puVar6 = (ulong *)((int)puVar6 + 1);
      pBVar5 = (Buffer *)((int)&pBVar5->pbStart + 1);
    }
  }
  return 1;
}

