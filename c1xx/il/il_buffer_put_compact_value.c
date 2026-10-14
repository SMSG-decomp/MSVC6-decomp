void __thiscall il_buffer_put_compact_value(c1_il_buffer *buf,uint value)

{
  int iVar1;
  byte bVar2;
  uint *puVar3;
  
  if ((buf->bytes).start + (buf->bytes).size < (buf->bytes).cur + 6) {
    iVar1 = il_buffer_grow(&buf->bytes,6);
    if (iVar1 == 0) {
      bVar2 = 0;
      goto LAB_1041bc3c;
    }
  }
  bVar2 = 1;
LAB_1041bc3c:
  bVar2 = buf->open & bVar2;
  buf->open = bVar2;
  if (bVar2 != 0) {
    if ((value & 0xffffff80) == 0) {
      *(buf->bytes).cur = (c1_u8)value;
      (buf->bytes).cur = (buf->bytes).cur + 1;
      return;
    }
    *(buf->bytes).cur = 0x80;
    puVar3 = (uint *)((buf->bytes).cur + 1);
    (buf->bytes).cur = (c1_u8 *)puVar3;
    *puVar3 = value;
    (buf->bytes).cur = (buf->bytes).cur + 4;
  }
  return;
}

