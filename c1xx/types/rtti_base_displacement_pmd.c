c1_u8 * __cdecl rtti_base_displacement_pmd(int *path)

{
  uint uVar1;
  int *piVar2;
  int *piVar3;
  c1_u8 *pcVar4;
  int *piVar5;
  
  pcVar4 = g_arenas[4].cur;
  if (path == (int *)0x0) {
    return (c1_u8 *)0x0;
  }
  if (((path[1] & 0x1000U) == 0) && (path[8] == 0)) {
    return (c1_u8 *)0x0;
  }
  g_arenas[4].cur = g_arenas[4].cur + 0xc;
  if (g_arenas[4].end < g_arenas[4].cur) {
    arena_grow(g_arenas + 4);
  }
  *(int *)pcVar4 = path[8];
  uVar1 = path[1];
  if ((uVar1 & 0x1000) == 0) {
    pcVar4[4] = 0xff;
    pcVar4[5] = 0xff;
    pcVar4[6] = 0xff;
    pcVar4[7] = 0xff;
    pcVar4[8] = '\0';
    pcVar4[9] = '\0';
    pcVar4[10] = '\0';
    pcVar4[0xb] = '\0';
    return pcVar4;
  }
  while ((uVar1 & 0x2000) == 0) {
    path = (int *)*path;
    uVar1 = path[1];
  }
  piVar5 = (int *)*path;
  piVar3 = path;
  while (piVar2 = piVar5, piVar2 != (int *)0x0) {
    piVar3 = piVar2;
    piVar5 = (int *)*piVar2;
  }
  class_virtual_base_info
            ((c1_symbol *)path[6],(c1_symbol *)piVar3[6],(int *)(pcVar4 + 4),(int *)(pcVar4 + 8),
             (c1_type **)0x0);
  return pcVar4;
}

