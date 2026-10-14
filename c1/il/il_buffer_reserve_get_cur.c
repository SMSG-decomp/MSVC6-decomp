int __thiscall il_buffer_reserve_get_cur(Buffer *buf,int n,c1_u8 **cur)

{
  int iVar1;
  
  if (n < 0) {
    return 0;
  }
  if ((buf->pbStart + buf->cbAlloc < buf->pbEnd + n) && (iVar1 = il_buffer_grow(buf,n), iVar1 == 0))
  {
    return 0;
  }
  if (cur != (c1_u8 **)0x0) {
    *cur = buf->pbEnd;
  }
  return 1;
}

