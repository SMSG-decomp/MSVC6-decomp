fe_line_map_row * __thiscall pp_line_map_find_entry(fe_line_map *line_map,uint position)

{
  fe_line_map_row *pfVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = line_map->count;
  pfVar1 = line_map->rows;
  uVar2 = uVar5 - 1;
  if (position < (uint)pfVar1[uVar5 - 1].position) {
    uVar3 = 0;
    uVar2 = uVar5 >> 1;
    if (uVar2 != 0) {
      do {
        uVar4 = uVar2;
        if (((uint)pfVar1[uVar2].position <= position) &&
           (uVar3 = uVar2, uVar4 = uVar5, position < (uint)pfVar1[uVar2 + 1].position)) break;
        uVar2 = (uVar4 - uVar3 >> 1) + uVar3;
        uVar5 = uVar4;
      } while (uVar2 != uVar3);
    }
  }
  return pfVar1 + uVar2;
}

