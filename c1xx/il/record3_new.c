c1_u8 * __cdecl record3_new(int a,int b,int c,int arena)

{
  int *piVar1;
  int *piVar2;
  c1_arena *a_00;
  
  a_00 = g_arenas + arena;
  piVar1 = (int *)a_00->cur;
  piVar2 = (int *)g_arenas[arena].end;
  a_00->cur = (c1_u8 *)(piVar1 + 3);
  if (piVar2 < piVar1 + 3) {
    arena_grow(a_00);
  }
  *piVar1 = a;
  piVar1[1] = b;
  piVar1[2] = c;
  return (c1_u8 *)piVar1;
}

