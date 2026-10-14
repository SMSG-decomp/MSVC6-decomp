c1_u8 * __cdecl arena_alloc_copy(c1_u8 *s,int arena,uint n)

{
  c1_u8 *pcVar1;
  uchar *puVar2;
  fe_arena *a;
  uint uVar3;
  c1_u8 *pcVar4;
  
  a = g_arenas + arena;
  pcVar1 = a->cur;
  puVar2 = g_arenas[arena].end;
  a->cur = pcVar1 + (n + 3 & 0xfffffffc);
  if (puVar2 < pcVar1 + (n + 3 & 0xfffffffc)) {
    arena_grow(a);
  }
  pcVar4 = pcVar1;
  for (uVar3 = n >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
    *(undefined4 *)pcVar4 = *(undefined4 *)s;
    s = s + 4;
    pcVar4 = pcVar4 + 4;
  }
  for (uVar3 = n & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
    *pcVar4 = *s;
    s = s + 1;
    pcVar4 = pcVar4 + 1;
  }
  return pcVar1;
}

