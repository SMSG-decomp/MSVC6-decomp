byte __thiscall arena_reserve(c1_arena *a,c1_arena_desc *descriptor,void *address)

{
  uint dwSize;
  c1_u8 *pcVar1;
  
  a->desc = descriptor;
  dwSize = arena_scaled_reserve_size(descriptor);
  a->limit = dwSize;
  pcVar1 = VirtualAlloc(address,dwSize,(descriptor->flags & 1) << 0x14 | 0x2000,4);
  a->base = pcVar1;
  if (pcVar1 != (c1_u8 *)0x0) {
    a->mapped = '\0';
    arena_reset_to_base(a);
    return 1;
  }
  return 0;
}

