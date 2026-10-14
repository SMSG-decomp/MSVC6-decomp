int __thiscall il_buffer_reserve_advance(c1_byte_buffer *buf,int n,c1_u8 **pos)

{
  int iVar1;
  
  if ((-1 < n) &&
     ((buf->cur + n <= buf->start + buf->size || (iVar1 = il_buffer_grow(buf,n), iVar1 != 0)))) {
    if (pos != (c1_u8 **)0x0) {
      *pos = buf->cur;
    }
    if (buf->start != (c1_u8 *)0x0) {
      buf->cur = buf->cur + n;
    }
    return 1;
  }
  return 0;
}

