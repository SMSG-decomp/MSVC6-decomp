c1_u8 * __cdecl list_copy_with_header(int *list,int arena)

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
  pcVar2 = list_copy_nodes((int *)*list,arena);
  *(c1_u8 **)(pcVar1 + 4) = pcVar2;
  *(c1_u8 **)pcVar1 = pcVar2;
  return pcVar1;
}

