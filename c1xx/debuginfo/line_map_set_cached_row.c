void __thiscall line_map_set_cached_row(c1_line_map_state *map,void *file)

{
  int iVar1;
  c1_u32 cVar2;
  c1_line_map_row *pcVar3;
  
  iVar1 = map->position;
  (map->cached).position = iVar1;
  (map->cached).file = file;
  cVar2 = (map->map).count;
  pcVar3 = (map->map).rows;
  (map->cached).line = (pcVar3[cVar2 - 1].line - pcVar3[cVar2 - 1].position) + iVar1;
  return;
}

