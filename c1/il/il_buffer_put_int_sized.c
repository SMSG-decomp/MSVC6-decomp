void __cdecl il_buffer_put_int_sized(uint *value,int size,fe_il_buffer *buf)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  byte bVar4;
  ushort *puVar5;
  uint *puVar6;
  int iVar7;
  
  if (size == 2) {
    uVar1 = (ushort)*value;
    if (((buf->bytes).pbStart + (buf->bytes).cbAlloc < (buf->bytes).pbEnd + 4) &&
       (iVar3 = il_buffer_grow(&buf->bytes,4), iVar3 == 0)) {
      bVar4 = 0;
    }
    else {
      bVar4 = 1;
    }
    bVar4 = buf->open & bVar4;
    buf->open = bVar4;
    if (bVar4 == 0) {
      return;
    }
    if ((uVar1 & 0xff80) != 0) {
      *(buf->bytes).pbEnd = 0x80;
      puVar5 = (ushort *)((buf->bytes).pbEnd + 1);
      (buf->bytes).pbEnd = (PB)puVar5;
      *puVar5 = uVar1;
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 2;
      return;
    }
    *(buf->bytes).pbEnd = (uchar)uVar1;
    (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
    return;
  }
  if (size == 4) {
    uVar2 = *value;
    iVar3 = il_buffer_reserve(&buf->bytes,6);
    bVar4 = buf->open & (byte)iVar3 & 1;
    buf->open = bVar4;
    if (bVar4 == 0) {
      return;
    }
    if ((uVar2 & 0xffffff80) != 0) {
      *(buf->bytes).pbEnd = 0x80;
      puVar6 = (uint *)((buf->bytes).pbEnd + 1);
      (buf->bytes).pbEnd = (PB)puVar6;
      *puVar6 = uVar2;
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
      return;
    }
    *(buf->bytes).pbEnd = (uchar)uVar2;
    (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
    return;
  }
  iVar3 = il_buffer_reserve(&buf->bytes,size + 2);
  bVar4 = buf->open & (byte)iVar3 & 1;
  buf->open = bVar4;
  if (bVar4 == 0) {
    return;
  }
  uVar2 = value[1];
  if (((int)uVar2 < 1) &&
     (((((int)uVar2 < 0 || (*value < 0x80)) && (-2 < (int)uVar2)) &&
      ((uVar2 < 0x80000000 || (0xffffff80 < *value)))))) {
    *(buf->bytes).pbEnd = (uchar)*value;
    (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
    return;
  }
  iVar3 = 0;
  *(buf->bytes).pbEnd = 0x80;
  (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
  if (size < 1) {
    return;
  }
  do {
    iVar7 = iVar3 >> 2;
    iVar3 = iVar3 + 4;
    *(uint *)(buf->bytes).pbEnd = value[iVar7];
    (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
  } while (iVar3 < size);
  return;
}

