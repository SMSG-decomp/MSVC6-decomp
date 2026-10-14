int __thiscall il_buffer_reserve_advance(Buffer *buf,int n,c1_u8 **pos)

{
  int iVar1;
  
  if ((-1 < n) &&
     ((buf->pbEnd + n <= buf->pbStart + buf->cbAlloc || (iVar1 = il_buffer_grow(buf,n), iVar1 != 0))
     )) {
    if (pos != (c1_u8 **)0x0) {
      *pos = buf->pbEnd;
    }
    if (buf->pbStart != (PB)0x0) {
      buf->pbEnd = buf->pbEnd + n;
    }
    return 1;
  }
  return 0;
}

