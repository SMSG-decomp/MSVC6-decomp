c1_line_map_row * __thiscall pp_line_map_find_entry(void *line_map,uint position)

{
  int iVar1;
  c1_line_map_row *pcVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar6 = *(uint *)((int)line_map + 4);
  iVar1 = *(int *)line_map;
  pcVar2 = (c1_line_map_row *)(iVar1 + -0xc + uVar6 * 0xc);
  if (position < *(uint *)(iVar1 + -0xc + uVar6 * 0xc)) {
    uVar4 = 0;
    uVar3 = uVar6 >> 1;
    if (uVar3 != 0) {
      do {
        uVar5 = uVar3;
        if ((*(uint *)(iVar1 + uVar3 * 0xc) <= position) &&
           (uVar4 = uVar3, uVar5 = uVar6, position < *(uint *)(iVar1 + (uVar3 * 3 + 3) * 4))) break;
        uVar3 = (uVar5 - uVar4 >> 1) + uVar4;
        uVar6 = uVar5;
      } while (uVar3 != uVar4);
    }
    pcVar2 = (c1_line_map_row *)(iVar1 + uVar3 * 0xc);
  }
  return pcVar2;
}

