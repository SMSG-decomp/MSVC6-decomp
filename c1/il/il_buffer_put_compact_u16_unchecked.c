void __thiscall il_buffer_put_compact_u16_unchecked(fe_il_buffer *buf,ushort value)

{
  ushort *puVar1;
  
  if ((value & 0xff80) != 0) {
    *(buf->bytes).pbEnd = 0x80;
    puVar1 = (ushort *)((buf->bytes).pbEnd + 1);
    (buf->bytes).pbEnd = (PB)puVar1;
    *puVar1 = value;
    (buf->bytes).pbEnd = (buf->bytes).pbEnd + 2;
    return;
  }
  *(buf->bytes).pbEnd = (uchar)value;
  (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
  return;
}

