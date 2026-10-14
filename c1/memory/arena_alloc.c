void * __thiscall arena_alloc(fe_arena *a,int n)

{
  uchar *puVar1;
  uchar *puVar2;
  
  puVar1 = a->cur;
  puVar2 = puVar1 + n;
  a->cur = puVar2;
  if (a->end < puVar2) {
    arena_grow(a);
  }
  return puVar1;
}

