c1_u8 * __cdecl record4_copy(int *src,int arena)

{
  int *piVar1;
  int *piVar2;
  c1_arena *a;
  
  a = g_arenas + arena;
  piVar1 = (int *)a->cur;
  piVar2 = (int *)g_arenas[arena].end;
  a->cur = (c1_u8 *)(piVar1 + 4);
  if (piVar2 < piVar1 + 4) {
    arena_grow(a);
  }
  *piVar1 = *src;
  piVar1[1] = src[1];
  piVar1[2] = src[2];
  piVar1[3] = src[3];
  return (c1_u8 *)piVar1;
}

