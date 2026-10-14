c1_u8 * __cdecl list_copy_nodes(int *node,int arena)

{
  c1_u8 *pcVar1;
  c1_u8 *pcVar2;
  c1_arena *a;
  
  if (node != (int *)0x0) {
    a = g_arenas + arena;
    pcVar1 = a->cur;
    pcVar2 = g_arenas[arena].end;
    a->cur = pcVar1 + 0xc;
    if (pcVar2 < pcVar1 + 0xc) {
      arena_grow(a);
    }
    *(int *)(pcVar1 + 8) = node[2];
    pcVar2 = list_copy_nodes((int *)*node,arena);
    *(c1_u8 **)pcVar1 = pcVar2;
    return pcVar1;
  }
  return (c1_u8 *)0x0;
}

