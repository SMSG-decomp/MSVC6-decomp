int __thiscall il_buffer_grow(Buffer *buf,int n)

{
  int iVar1;
  uchar *pNew;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  PB puVar5;
  uchar *puVar6;
  
  iVar1 = buf->cbAlloc / 2;
  if (iVar1 < n + 0x1000) {
    iVar1 = n + 0x1000;
  }
  uVar4 = buf->cbAlloc + 0xfff + iVar1 & 0xfffff000;
  pNew = __2_YAPAXI_Z(uVar4);
  if (pNew != (uchar *)0x0) {
    buf->cbAlloc = uVar4;
    uVar4 = (int)buf->pbEnd - (int)buf->pbStart;
    puVar5 = buf->pbStart;
    puVar6 = pNew;
    for (uVar2 = uVar4 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *(undefined4 *)puVar6 = *(undefined4 *)puVar5;
      puVar5 = puVar5 + 4;
      puVar6 = puVar6 + 4;
    }
    for (uVar2 = uVar4 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar6 = *puVar5;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
    uVar3 = buf->cbAlloc - uVar4;
    puVar6 = pNew + uVar4;
    for (uVar2 = uVar3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      puVar6[0] = '\0';
      puVar6[1] = '\0';
      puVar6[2] = '\0';
      puVar6[3] = '\0';
      puVar6 = puVar6 + 4;
    }
    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
      *puVar6 = '\0';
      puVar6 = puVar6 + 1;
    }
    __3_YAXPAX_Z(buf->pbStart);
    puVar6 = buf->pbStart;
    buf->pbStart = pNew;
    buf->pbEnd = pNew + uVar4;
    if ((puVar6 != pNew) && (buf->pfnMove != (_func_44 *)0x0)) {
      (*buf->pfnMove)(buf->pfnMoveArg,puVar6,pNew);
    }
    return 1;
  }
  return 0;
}

