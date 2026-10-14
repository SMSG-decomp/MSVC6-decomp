int __fastcall arena_grow(fe_arena *a)

{
  LPVOID pvVar1;
  uint uVar2;
  uint uVar3;
  
  if ((int)a->limit < (int)a->cur - (int)a->base) {
    diag_fatal_simple(0x4c);
  }
  uVar3 = a->desc->granule;
  uVar3 = (uint)(a->cur + uVar3 + (-1 - (int)a->end)) & ~(uVar3 - 1);
  pvVar1 = VirtualAlloc(a->end,uVar3,0x1000,4);
  if (pvVar1 != (LPVOID)0x0) {
    uVar2 = a->committed + uVar3;
    a->end = a->end + uVar3;
    a->committed = uVar2;
    return CONCAT31((int3)(uVar2 >> 8),1);
  }
  diag_fatal_simple(0x3c);
}

