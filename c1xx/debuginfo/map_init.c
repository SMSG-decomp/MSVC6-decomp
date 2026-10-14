c1xx_pdb_map * __thiscall map_init(c1xx_pdb_map *map,uint size)

{
  c1_u32 *pcVar1;
  uint uVar2;
  
  uVar2 = size;
  if (size == 0) {
    uVar2 = 1;
  }
  pcVar1 = __2_YAPAXI_Z(uVar2 * 4);
  (map->domain).data = pcVar1;
  uVar2 = -(uint)(pcVar1 != (c1_u32 *)0x0) & uVar2;
  (map->domain).capacity = uVar2;
  (map->domain).count = uVar2;
  if (size == 0) {
    size = 1;
  }
  pcVar1 = __2_YAPAXI_Z(size * 4);
  (map->range).data = pcVar1;
  uVar2 = -(uint)(pcVar1 != (c1_u32 *)0x0) & size;
  (map->range).capacity = uVar2;
  (map->range).count = uVar2;
  (map->present).data = (c1_u32 *)0x0;
  (map->present).capacity = 0;
  (map->present).count = 0;
  (map->deleted).data = (c1_u32 *)0x0;
  (map->deleted).capacity = 0;
  (map->deleted).count = 0;
  map->count = 0;
  return map;
}

