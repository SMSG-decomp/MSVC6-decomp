void __thiscall il_buffer_put_byte(c1_il_buffer *buf,c1_u8 b)

{
  int iVar1;
  byte bVar2;
  
  if ((buf->bytes).start + (buf->bytes).size < (buf->bytes).cur + 2) {
    iVar1 = il_buffer_grow(&buf->bytes,2);
    if (iVar1 == 0) {
      bVar2 = 0;
      goto LAB_1044805f;
    }
  }
  bVar2 = 1;
LAB_1044805f:
  bVar2 = buf->open & bVar2;
  buf->open = bVar2;
  if (bVar2 != 0) {
    *(buf->bytes).cur = b;
    (buf->bytes).cur = (buf->bytes).cur + 1;
  }
  return;
}

