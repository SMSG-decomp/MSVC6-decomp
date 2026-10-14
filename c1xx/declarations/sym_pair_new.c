c1_u8 * __cdecl sym_pair_new(void *first,void *second,int arena)

{
  c1_u8 *pcVar1;
  c1_u8 *pcVar2;
  c1_arena *a;
  
  a = g_arenas + arena;
  pcVar1 = a->cur;
  pcVar2 = g_arenas[arena].end;
  a->cur = pcVar1 + 8;
  if (pcVar2 < pcVar1 + 8) {
    arena_grow(a);
  }
  *(void **)pcVar1 = first;
  *(void **)(pcVar1 + 4) = second;
  return pcVar1;
}

