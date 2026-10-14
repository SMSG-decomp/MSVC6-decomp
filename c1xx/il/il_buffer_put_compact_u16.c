void __thiscall il_buffer_put_compact_u16(c1_il_buffer *buf,ushort value)

{
  int iVar1;
  byte bVar2;
  ushort *puVar3;
  
  if ((buf->bytes).start + (buf->bytes).size < (buf->bytes).cur + 4) {
    iVar1 = il_buffer_grow(&buf->bytes,4);
    bVar2 = 0;
    if (iVar1 == 0) goto LAB_1047ddc9;
  }
  bVar2 = 1;
LAB_1047ddc9:
  bVar2 = buf->open & bVar2;
  buf->open = bVar2;
  if (bVar2 != 0) {
    if ((value & 0xff80) == 0) {
      *(buf->bytes).cur = (c1_u8)value;
      (buf->bytes).cur = (buf->bytes).cur + 1;
      return;
    }
    *(buf->bytes).cur = 0x80;
    puVar3 = (ushort *)((buf->bytes).cur + 1);
    (buf->bytes).cur = (c1_u8 *)puVar3;
    *puVar3 = value;
    (buf->bytes).cur = (buf->bytes).cur + 2;
  }
  return;
}

