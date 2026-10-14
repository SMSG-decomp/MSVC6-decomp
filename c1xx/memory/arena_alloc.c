void * __thiscall arena_alloc(arena *a,int n)

{
  c1_u8 *pcVar1;
  c1_u8 *pcVar2;
  
  pcVar1 = a->cur;
  pcVar2 = pcVar1 + n;
  a->cur = pcVar2;
  if (a->end < pcVar2) {
    arena_grow(a);
  }
  return pcVar1;
}

