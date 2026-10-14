int __fastcall arena_grow(c1_arena *a)

{
  LPVOID pvVar1;
  c1_u32 cVar2;
  uint dwSize;
  
  if ((int)a->limit < (int)a->cur - (int)a->base) {
    diag_fatal_simple(0x4c);
  }
  cVar2 = a->desc->granule;
  dwSize = (uint)(a->cur + cVar2 + (-1 - (int)a->end)) & ~(cVar2 - 1);
  pvVar1 = VirtualAlloc(a->end,dwSize,0x1000,4);
  if (pvVar1 != (LPVOID)0x0) {
    cVar2 = a->committed + dwSize;
    a->end = a->end + dwSize;
    a->committed = cVar2;
    return CONCAT31((int3)(cVar2 >> 8),1);
  }
  diag_fatal_simple(0x3c);
}

