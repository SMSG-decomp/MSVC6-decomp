void __thiscall func_in_write_key(c1_il_buffer *buf,uint key)

{
  c1_u32 cVar1;
  int iVar2;
  byte bVar3;
  c1_u8 *pcVar4;
  
  cVar1 = (buf->bytes).size;
  pcVar4 = (buf->bytes).start;
  if (g_c9il_mode != '\0') {
    if ((pcVar4 + cVar1 < (buf->bytes).cur + 5) &&
       (iVar2 = il_buffer_grow(&buf->bytes,5), iVar2 == 0)) {
      bVar3 = 0;
    }
    else {
      bVar3 = 1;
    }
    bVar3 = buf->open & bVar3;
    buf->open = bVar3;
    if (bVar3 != 0) {
      if ((int)key < 0x8000) {
        *(short *)(buf->bytes).cur = (short)key;
        (buf->bytes).cur = (buf->bytes).cur + 2;
        return;
      }
      *(uint *)(buf->bytes).cur = (uint)((uint3)(key >> 8) & 0xffffc0 | 0x40) << 9 | key & 0x7fff;
      (buf->bytes).cur = (buf->bytes).cur + 4;
    }
    return;
  }
  if (pcVar4 + cVar1 < (buf->bytes).cur + 4) {
    iVar2 = il_buffer_grow(&buf->bytes,4);
    bVar3 = 0;
    if (iVar2 == 0) goto LAB_1047e7dd;
  }
  bVar3 = 1;
LAB_1047e7dd:
  bVar3 = buf->open & bVar3;
  buf->open = bVar3;
  if (bVar3 == 0) {
    return;
  }
  bVar3 = (byte)key;
  if (key < 0x3fff80) {
    if (0x3fff < key) {
      *(buf->bytes).cur = bVar3 | 0xc0;
      pcVar4 = (buf->bytes).cur + 1;
      (buf->bytes).cur = pcVar4;
      *pcVar4 = (c1_u8)(key >> 6);
      pcVar4 = (buf->bytes).cur + 1;
      (buf->bytes).cur = pcVar4;
      *pcVar4 = (c1_u8)(key >> 0xe);
      (buf->bytes).cur = (buf->bytes).cur + 1;
      return;
    }
    *(buf->bytes).cur = bVar3 & 0x3f | 0x80;
    pcVar4 = (buf->bytes).cur + 1;
    (buf->bytes).cur = pcVar4;
    *pcVar4 = (c1_u8)(key >> 6);
    (buf->bytes).cur = (buf->bytes).cur + 1;
    return;
  }
  *(buf->bytes).cur = bVar3 + 0x80;
  (buf->bytes).cur = (buf->bytes).cur + 1;
  return;
}

