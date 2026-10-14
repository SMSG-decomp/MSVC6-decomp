c1_u8 * __cdecl arena_alloc_n_aligned(uint n,int arena)

{
  c1_u8 *pcVar1;
  c1_u8 *pcVar2;
  c1_u8 *pcVar3;
  c1_arena *a;
  
  a = g_arenas + arena;
  pcVar1 = a->cur;
  pcVar2 = g_arenas[arena].end;
  pcVar3 = pcVar1 + (n + 3 & 0xfffffffc);
  a->cur = pcVar3;
  if (pcVar2 < pcVar3) {
    arena_grow(a);
  }
  return pcVar1;
}

