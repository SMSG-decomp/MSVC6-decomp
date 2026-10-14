fe_vector * __cdecl vector_new(c1_u16 capacity,int arena)

{
  fe_arena *a;
  fe_vector *pfVar1;
  fe_vector *pfVar2;
  void **ppvVar3;
  void **ppvVar4;
  void **ppvVar5;
  
  pfVar1 = (fe_vector *)g_arenas[arena].cur;
  pfVar2 = (fe_vector *)g_arenas[arena].end;
  a = g_arenas + arena;
  a->cur = (uchar *)(pfVar1 + 1);
  if (pfVar2 < pfVar1 + 1) {
    arena_grow(a);
  }
  pfVar1->count = 0;
  pfVar1->capacity = capacity;
  pfVar1->arena = arena;
  if (capacity != 0) {
    ppvVar3 = (void **)a->cur;
    ppvVar4 = (void **)g_arenas[arena].end;
    ppvVar5 = ppvVar3 + capacity;
    a->cur = (uchar *)ppvVar5;
    if (ppvVar4 < ppvVar5) {
      arena_grow(a);
    }
    pfVar1->data = ppvVar3;
  }
  return pfVar1;
}

