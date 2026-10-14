void __thiscall il_buffer_put_counted_bytes(fe_il_buffer *buf,ushort length,void *bytes)

{
  PB puVar1;
  int iVar2;
  byte bVar3;
  uint uVar4;
  ushort *puVar5;
  
  iVar2 = length + 4;
  if (((buf->bytes).pbStart + (buf->bytes).cbAlloc < (buf->bytes).pbEnd + iVar2) &&
     (iVar2 = il_buffer_grow(&buf->bytes,iVar2), iVar2 == 0)) {
    bVar3 = 0;
  }
  else {
    bVar3 = 1;
  }
  bVar3 = buf->open & bVar3;
  buf->open = bVar3;
  if (bVar3 != 0) {
    if ((length & 0xff80) == 0) {
      *(buf->bytes).pbEnd = (uchar)length;
      puVar1 = (buf->bytes).pbEnd + 1;
    }
    else {
      *(buf->bytes).pbEnd = 0x80;
      puVar5 = (ushort *)((buf->bytes).pbEnd + 1);
      (buf->bytes).pbEnd = (PB)puVar5;
      *puVar5 = length;
      puVar1 = (buf->bytes).pbEnd + 2;
    }
    (buf->bytes).pbEnd = puVar1;
    for (uVar4 = (uint)(length >> 2); uVar4 != 0; uVar4 = uVar4 - 1) {
      *(undefined4 *)puVar1 = *(undefined4 *)bytes;
      bytes = (uchar *)((int)bytes + 4);
      puVar1 = puVar1 + 4;
    }
    for (uVar4 = length & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
      *puVar1 = *(uchar *)bytes;
      bytes = (uchar *)((int)bytes + 1);
      puVar1 = puVar1 + 1;
    }
    (buf->bytes).pbEnd = (buf->bytes).pbEnd + length;
  }
  return;
}

