int __cdecl list_push_in_arena(int *head,int arena)

{
  int *piVar1;
  int *piVar2;
  c1_arena *a;
  
  a = g_arenas + arena;
  piVar1 = (int *)a->cur;
  piVar2 = (int *)g_arenas[arena].end;
  a->cur = (c1_u8 *)(piVar1 + 2);
  if (piVar2 < piVar1 + 2) {
    arena_grow(a);
  }
  *piVar1 = *head;
  *head = (int)piVar1;
  return (int)piVar1;
}

