void __thiscall il_buffer_put_compact_u16_unchecked(c1_il_buffer *buf,ushort value)

{
  ushort *puVar1;
  
  if ((value & 0xff80) != 0) {
    *(buf->bytes).cur = 0x80;
    puVar1 = (ushort *)((buf->bytes).cur + 1);
    (buf->bytes).cur = (c1_u8 *)puVar1;
    *puVar1 = value;
    (buf->bytes).cur = (buf->bytes).cur + 2;
    return;
  }
  *(buf->bytes).cur = (c1_u8)value;
  (buf->bytes).cur = (buf->bytes).cur + 1;
  return;
}

