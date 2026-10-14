void __fastcall map_destroy(c1xx_pdb_map *map)

{
  c1_u32 *pcVar1;
  
  pcVar1 = (map->deleted).data;
  if (pcVar1 != (c1_u32 *)0x0) {
    __3_YAXPAX_Z(pcVar1);
  }
  pcVar1 = (map->present).data;
  if (pcVar1 != (c1_u32 *)0x0) {
    __3_YAXPAX_Z(pcVar1);
  }
  pcVar1 = (map->range).data;
  if (pcVar1 != (c1_u32 *)0x0) {
    __3_YAXPAX_Z(pcVar1);
  }
  pcVar1 = (map->domain).data;
  if (pcVar1 != (c1_u32 *)0x0) {
    __3_YAXPAX_Z(pcVar1);
  }
  return;
}

