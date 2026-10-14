byte __thiscall arena_reserve(fe_arena *a,void *descriptor,void *address)

{
  uint dwSize;
  uchar *puVar1;
  
  a->desc = descriptor;
  dwSize = arena_scaled_reserve_size(descriptor);
  a->limit = dwSize;
  puVar1 = VirtualAlloc(address,dwSize,(*(byte *)((int)descriptor + 0xc) & 1) << 0x14 | 0x2000,4);
  a->base = puVar1;
  if (puVar1 != (uchar *)0x0) {
    a->mapped = '\0';
    arena_reset_to_base(a);
    return 1;
  }
  return 0;
}

