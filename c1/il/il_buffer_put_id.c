void __thiscall il_buffer_put_id(fe_il_buffer *buf,uint id)

{
  int iVar1;
  byte bVar2;
  
  if ((buf->bytes).pbStart + (buf->bytes).cbAlloc < (buf->bytes).pbEnd + 5) {
    iVar1 = il_buffer_grow(&buf->bytes,5);
    if (iVar1 == 0) {
      bVar2 = 0;
      goto LAB_10602761;
    }
  }
  bVar2 = 1;
LAB_10602761:
  bVar2 = buf->open & bVar2;
  buf->open = bVar2;
  if (bVar2 != 0) {
    if ((int)id < 0x8000) {
      *(short *)(buf->bytes).pbEnd = (short)id;
      (buf->bytes).pbEnd = (buf->bytes).pbEnd + 2;
      return;
    }
    *(uint *)(buf->bytes).pbEnd = (uint)((uint3)(id >> 8) & 0xffffc0 | 0x40) << 9 | id & 0x7fff;
    (buf->bytes).pbEnd = (buf->bytes).pbEnd + 4;
  }
  return;
}

