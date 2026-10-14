int __thiscall il_buffer_append(c1_byte_buffer *buf,void *src,uint n,c1_u8 **pos)

{
  int iVar1;
  uint uVar2;
  c1_u8 *pcVar3;
  
  if (((src != (void *)0x0) && (-1 < (int)n)) &&
     ((buf->cur + n <= buf->start + buf->size || (iVar1 = il_buffer_grow(buf,n), iVar1 != 0)))) {
    pcVar3 = src;
    if (&stack0x00000000 != (undefined1 *)0xfffffffc) {
      pcVar3 = buf->cur;
    }
    if (buf->start != (c1_u8 *)0x0) {
      buf->cur = buf->cur + n;
    }
    if (pos != (c1_u8 **)0x0) {
      *pos = pcVar3;
    }
    for (uVar2 = n >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *(undefined4 *)pcVar3 = *(undefined4 *)src;
      src = (c1_u8 *)((int)src + 4);
      pcVar3 = pcVar3 + 4;
    }
    for (uVar2 = n & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *pcVar3 = *(c1_u8 *)src;
      src = (c1_u8 *)((int)src + 1);
      pcVar3 = pcVar3 + 1;
    }
    return 1;
  }
  return 0;
}

