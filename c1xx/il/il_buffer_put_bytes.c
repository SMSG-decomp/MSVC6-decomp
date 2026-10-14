int __thiscall il_buffer_put_bytes(c1_il_buffer *buf,uint *src,uint n)

{
  uint uVar1;
  uint *puVar2;
  
  puVar2 = (uint *)(buf->bytes).cur;
  for (uVar1 = n >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
    *puVar2 = *src;
    src = src + 1;
    puVar2 = puVar2 + 1;
  }
  for (uVar1 = n & 3; uVar1 != 0; uVar1 = uVar1 - 1) {
    *(c1_u8 *)puVar2 = (c1_u8)*src;
    src = (uint *)((int)src + 1);
    puVar2 = (uint *)((int)puVar2 + 1);
  }
  (buf->bytes).cur = (buf->bytes).cur + n;
  return 1;
}

