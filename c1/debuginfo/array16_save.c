int __thiscall array16_save(fe_idb_region_array *array,Buffer *buf)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  Buffer *pBVar5;
  fe_idb_region *pfVar6;
  
  puVar1 = &array->count;
  if ((puVar1 == (uint *)0x0) ||
     ((buf->pbStart + buf->cbAlloc < buf->pbEnd + 4 && (iVar3 = il_buffer_grow(buf,4), iVar3 == 0)))
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
  uVar2 = *puVar1;
  if (uVar2 != 0) {
    pfVar6 = array->data;
    iVar3 = uVar2 * 0x10;
    if (pfVar6 == (fe_idb_region *)0x0) {
      return 0;
    }
    if (iVar3 < 0) {
      return 0;
    }
    if ((buf->pbStart + buf->cbAlloc < buf->pbEnd + iVar3) &&
       (iVar4 = il_buffer_grow(buf,iVar3), iVar4 == 0)) {
      return 0;
    }
    pBVar5 = buf;
    if (&stack0x00000000 != (undefined1 *)0xfffffffc) {
      pBVar5 = (Buffer *)buf->pbEnd;
    }
    if (buf->pbStart != (PB)0x0) {
      buf->pbEnd = buf->pbEnd + iVar3;
    }
    for (iVar3 = (uVar2 & 0xfffffff) << 2; iVar3 != 0; iVar3 = iVar3 + -1) {
      pBVar5->pbStart = (PB)pfVar6->signature;
      pfVar6 = (fe_idb_region *)&pfVar6->length;
      pBVar5 = (Buffer *)&pBVar5->pbEnd;
    }
    for (iVar3 = 0; iVar3 != 0; iVar3 = iVar3 + -1) {
      *(char *)&pBVar5->pbStart = (char)pfVar6->signature;
      pfVar6 = (fe_idb_region *)((int)&pfVar6->signature + 1);
      pBVar5 = (Buffer *)((int)&pBVar5->pbStart + 1);
    }
  }
  return 1;
}

