int __thiscall il_buffer_put_byte7(c1_il_buffer *buf,uint value)

{
  c1_u8 *pcVar1;
  
  if ((value & 0xffffff80) == 0) {
    *(buf->bytes).cur = (c1_u8)value;
    pcVar1 = (buf->bytes).cur + 1;
    (buf->bytes).cur = pcVar1;
    return CONCAT31((int3)((uint)pcVar1 >> 8),1);
  }
  return value & 0xffffff00;
}

