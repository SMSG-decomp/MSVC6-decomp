int __thiscall il_buffer_append(Buffer *buf,void *src,uint n,c1_u8 **pos)

{
  int iVar1;
  uint uVar2;
  PB puVar3;
  
  if (((src != (void *)0x0) && (-1 < (int)n)) &&
     ((buf->pbEnd + n <= buf->pbStart + buf->cbAlloc || (iVar1 = il_buffer_grow(buf,n), iVar1 != 0))
     )) {
    puVar3 = src;
    if (&stack0x00000000 != (undefined1 *)0xfffffffc) {
      puVar3 = buf->pbEnd;
    }
    if (buf->pbStart != (PB)0x0) {
      buf->pbEnd = buf->pbEnd + n;
    }
    if (pos != (c1_u8 **)0x0) {
      *pos = puVar3;
    }
    for (uVar2 = n >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *(undefined4 *)puVar3 = *(undefined4 *)src;
      src = (uchar *)((int)src + 4);
      puVar3 = puVar3 + 4;
    }
    for (uVar2 = n & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar3 = *(uchar *)src;
      src = (uchar *)((int)src + 1);
      puVar3 = puVar3 + 1;
    }
    return 1;
  }
  return 0;
}

