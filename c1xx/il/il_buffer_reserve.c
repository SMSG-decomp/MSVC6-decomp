int __thiscall il_buffer_reserve(c1_byte_buffer *buf,int n)

{
  int iVar1;
  
  if (n < 0) {
    return 0;
  }
  if ((buf->start + buf->size < buf->cur + n) && (iVar1 = il_buffer_grow(buf,n), iVar1 == 0)) {
    return 0;
  }
  return 1;
}

