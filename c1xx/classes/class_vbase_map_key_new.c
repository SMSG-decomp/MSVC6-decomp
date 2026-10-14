c1_vbase_map_key * __cdecl
class_vbase_map_key_new(c1_symbol *cls_a,c1_symbol *cls_b,c1_u8 reverse,int arena)

{
  c1_vbase_map_key *pcVar1;
  c1_vbase_map_key *pcVar2;
  c1_arena *a;
  
  a = g_arenas + arena;
  pcVar1 = (c1_vbase_map_key *)a->cur;
  pcVar2 = (c1_vbase_map_key *)g_arenas[arena].end;
  a->cur = (c1_u8 *)(pcVar1 + 1);
  if (pcVar2 < pcVar1 + 1) {
    arena_grow(a);
  }
  pcVar1->cls_a = cls_a;
  pcVar1->cls_b = cls_b;
  pcVar1->reverse = reverse;
  return pcVar1;
}

