int __thiscall il_buffer_put_byte7(fe_il_buffer *buf,uint value)

{
  PB puVar1;
  
  if ((value & 0xffffff80) == 0) {
    *(buf->bytes).pbEnd = (uchar)value;
    puVar1 = (buf->bytes).pbEnd + 1;
    (buf->bytes).pbEnd = puVar1;
    return CONCAT31((int3)((uint)puVar1 >> 8),1);
  }
  return value & 0xffffff00;
}

