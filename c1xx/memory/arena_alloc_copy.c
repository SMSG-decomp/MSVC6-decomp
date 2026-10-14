c1_u8 * __cdecl arena_alloc_copy(c1_u8 *src,int arena,uint n)

{
  c1_u8 *pcVar1;
  c1_arena *a;
  uint uVar2;
  c1_u8 *pcVar3;
  
  a = g_arenas + arena;
  pcVar1 = a->cur;
  pcVar3 = g_arenas[arena].end;
  a->cur = pcVar1 + (n + 3 & 0xfffffffc);
  if (pcVar3 < pcVar1 + (n + 3 & 0xfffffffc)) {
    arena_grow(a);
  }
  pcVar3 = pcVar1;
  for (uVar2 = n >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
    *(undefined4 *)pcVar3 = *(undefined4 *)src;
    src = src + 4;
    pcVar3 = pcVar3 + 4;
  }
  for (uVar2 = n & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *pcVar3 = *src;
    src = src + 1;
    pcVar3 = pcVar3 + 1;
  }
  return pcVar1;
}

