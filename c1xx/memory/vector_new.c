c1_vector * __cdecl vector_new(c1_u16 capacity,int arena)

{
  c1_arena *a;
  c1_vector *pcVar1;
  c1_vector *pcVar2;
  void **ppvVar3;
  void **ppvVar4;
  void **ppvVar5;
  
  pcVar1 = (c1_vector *)g_arenas[arena].cur;
  pcVar2 = (c1_vector *)g_arenas[arena].end;
  a = g_arenas + arena;
  a->cur = (c1_u8 *)(pcVar1 + 1);
  if (pcVar2 < pcVar1 + 1) {
    arena_grow(a);
  }
  pcVar1->count = 0;
  pcVar1->capacity = capacity;
  pcVar1->arena = arena;
  if (capacity != 0) {
    ppvVar3 = (void **)a->cur;
    ppvVar4 = (void **)g_arenas[arena].end;
    ppvVar5 = ppvVar3 + capacity;
    a->cur = (c1_u8 *)ppvVar5;
    if (ppvVar4 < ppvVar5) {
      arena_grow(a);
    }
    pcVar1->data = ppvVar3;
  }
  return pcVar1;
}

