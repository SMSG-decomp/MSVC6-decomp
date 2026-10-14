void __thiscall il_buffer_put_id(c1_il_buffer *buf,uint id)

{
  int iVar1;
  byte bVar2;
  
  if ((buf->bytes).start + (buf->bytes).size < (buf->bytes).cur + 5) {
    iVar1 = il_buffer_grow(&buf->bytes,5);
    if (iVar1 == 0) {
      bVar2 = 0;
      goto LAB_1040d0ff;
    }
  }
  bVar2 = 1;
LAB_1040d0ff:
  bVar2 = buf->open & bVar2;
  buf->open = bVar2;
  if (bVar2 != 0) {
    if ((int)id < 0x8000) {
      *(short *)(buf->bytes).cur = (short)id;
      (buf->bytes).cur = (buf->bytes).cur + 2;
      return;
    }
    *(uint *)(buf->bytes).cur = (uint)((uint3)(id >> 8) & 0xffffc0 | 0x40) << 9 | id & 0x7fff;
    (buf->bytes).cur = (buf->bytes).cur + 4;
  }
  return;
}

