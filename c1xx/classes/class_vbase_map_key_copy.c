c1_vbase_map_key * __cdecl class_vbase_map_key_copy(c1_vbase_map_key *key,int arena)

{
  c1_vbase_map_key *pcVar1;
  c1_vbase_map_key *pcVar2;
  c1_u8 cVar3;
  c1_u8 cVar4;
  c1_u8 cVar5;
  c1_arena *a;
  
  a = g_arenas + arena;
  pcVar1 = (c1_vbase_map_key *)a->cur;
  pcVar2 = (c1_vbase_map_key *)g_arenas[arena].end;
  a->cur = (c1_u8 *)(pcVar1 + 1);
  if (pcVar2 < pcVar1 + 1) {
    arena_grow(a);
  }
  pcVar1->cls_a = key->cls_a;
  pcVar1->cls_b = key->cls_b;
  cVar3 = key->emitted;
  cVar4 = key->pad0a[0];
  cVar5 = key->pad0a[1];
  pcVar1->reverse = key->reverse;
  pcVar1->emitted = cVar3;
  pcVar1->pad0a[0] = cVar4;
  pcVar1->pad0a[1] = cVar5;
  pcVar1->emitted = '\0';
  return pcVar1;
}

