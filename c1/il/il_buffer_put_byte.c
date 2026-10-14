void __thiscall il_buffer_put_byte(fe_il_buffer *buf,c1_u8 b)

{
  int iVar1;
  byte bVar2;
  
  if ((buf->bytes).pbStart + (buf->bytes).cbAlloc < (buf->bytes).pbEnd + 2) {
    iVar1 = il_buffer_grow(&buf->bytes,2);
    if (iVar1 == 0) {
      bVar2 = 0;
      goto LAB_10624e03;
    }
  }
  bVar2 = 1;
LAB_10624e03:
  bVar2 = buf->open & bVar2;
  buf->open = bVar2;
  if (bVar2 != 0) {
    *(buf->bytes).pbEnd = b;
    (buf->bytes).pbEnd = (buf->bytes).pbEnd + 1;
  }
  return;
}

