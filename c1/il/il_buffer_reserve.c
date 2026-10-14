int __thiscall il_buffer_reserve(Buffer *buf,int n)

{
  int iVar1;
  
  if (n < 0) {
    return 0;
  }
  if ((buf->pbStart + buf->cbAlloc < buf->pbEnd + n) && (iVar1 = il_buffer_grow(buf,n), iVar1 == 0))
  {
    return 0;
  }
  return 1;
}

