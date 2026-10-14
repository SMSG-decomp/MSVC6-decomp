int __thiscall il_buffer_put_bytes(fe_il_buffer *buf,uint *src,uint n)

{
  uint uVar1;
  uint *puVar2;
  
  puVar2 = (uint *)(buf->bytes).pbEnd;
  for (uVar1 = n >> 2; uVar1 != 0; uVar1 = uVar1 - 1) {
    *puVar2 = *src;
    src = src + 1;
    puVar2 = puVar2 + 1;
  }
  for (uVar1 = n & 3; uVar1 != 0; uVar1 = uVar1 - 1) {
    *(uchar *)puVar2 = (uchar)*src;
    src = (uint *)((int)src + 1);
    puVar2 = (uint *)((int)puVar2 + 1);
  }
  (buf->bytes).pbEnd = (buf->bytes).pbEnd + n;
  return 1;
}

