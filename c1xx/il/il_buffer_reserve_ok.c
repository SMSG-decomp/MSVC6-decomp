c1_u8 __thiscall il_buffer_reserve_ok(c1_il_buffer *buf,int n)

{
  int iVar1;
  byte bVar2;
  
  iVar1 = n + 1;
  if (iVar1 < 0) {
    buf->open = '\0';
    return '\0';
  }
  if (((buf->bytes).start + (buf->bytes).size < (buf->bytes).cur + iVar1) &&
     (iVar1 = il_buffer_grow(&buf->bytes,iVar1), iVar1 == 0)) {
    buf->open = '\0';
    return '\0';
  }
  bVar2 = buf->open & 1;
  buf->open = bVar2;
  return bVar2;
}

