c1_line_map_row * __fastcall vector_push_12(c1_line_map *map)

{
  uint uVar1;
  c1_u32 cVar2;
  c1_line_map_row *pcVar3;
  
  uVar1 = map->capacity;
  if (uVar1 <= map->count) {
    pcVar3 = arena_alloc_copy_bytes(g_arenas,map->rows,uVar1 * 0xc,uVar1 * 0x18);
    map->rows = pcVar3;
    map->capacity = map->capacity << 1;
  }
  cVar2 = map->count;
  map->count = cVar2 + 1;
  return map->rows + cVar2;
}

