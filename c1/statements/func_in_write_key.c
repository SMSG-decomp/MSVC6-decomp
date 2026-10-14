void __thiscall func_in_write_key(fe_il_buffer *buf,uint key)

{
  int iVar1;
  byte bVar2;
  PB puVar3;
  
  iVar1 = (buf->bytes).cbAlloc;
  puVar3 = (buf->bytes).pbStart;
  if (g_c9il_mode != '\0') {
    if ((puVar3 + iVar1 < (buf->bytes).pbEnd + 5) &&
       (iVar1 = il_buffer_grow(&buf->bytes,5), iVar1 == 0)) {
      bVar2 = 0;
    }
    else {
      bVar2 = 1;
    }
    bVar2 = buf->open & bVar2;
    buf->open = bVar2;
    if (bVar2 != 0) {
      if ((int)key < 0x8000) {
        *(short *)(buf->bytes).pbEnd = (short)key;
        (buf->bytes).pbEnd = (buf->bytes).pbEnd + 2;
        return;
      }
      *(uint *)(buf->bytes).pbEnd = (uint)((uint3)(key >> 8) & 0xffffc0 | 0x40) << 9 | key & 0x7fff;
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
    }
    return;
  }
  if (puVar3 + iVar1 < (buf->bytes).pbEnd + 4) {
    iVar1 = il_buffer_grow(&buf->bytes,4);
    bVar2 = 0;
    if (iVar1 == 0) goto LAB_1063a96f;
  }
  bVar2 = 1;
LAB_1063a96f:
  bVar2 = buf->open & bVar2;
  buf->open = bVar2;
  if (bVar2 == 0) {
    return;
  }
  bVar2 = (byte)key;
  if (key < 0x3fff80) {
    if (0x3fff < key) {
      *(buf->bytes).pbEnd = bVar2 | 0xc0;
      puVar3 = (buf->bytes).pbEnd + 1;
      (buf->bytes).pbEnd = puVar3;
      *puVar3 = (uchar)(key >> 6);
      puVar3 = (buf->bytes).pbEnd + 1;
      (buf->bytes).pbEnd = puVar3;
      *puVar3 = (uchar)(key >> 0xe);
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
      return;
    }
    *(buf->bytes).pbEnd = bVar2 & 0x3f | 0x80;
    puVar3 = (buf->bytes).pbEnd + 1;
    (buf->bytes).pbEnd = puVar3;
    *puVar3 = (uchar)(key >> 6);
    (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
    return;
  }
  *(buf->bytes).pbEnd = bVar2 + 0x80;
  (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
  return;
}

