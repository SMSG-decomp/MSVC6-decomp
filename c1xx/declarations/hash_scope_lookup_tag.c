c1_u8 * __thiscall hash_scope_lookup_tag(void *scope,void *name)

{
  int *piVar1;
  c1_u8 *pcVar2;
  
  pcVar2 = g_arenas[5].cur;
  if (*(int *)((int)scope + 0x14) != 0) {
    for (piVar1 = *(int **)(*(int *)((int)scope + 0x14) +
                           (*(uint *)((int)name + 8) & *(uint *)((int)scope + 0x18) & 0xffff) * 4);
        piVar1 != (int *)0x0; piVar1 = (int *)piVar1[1]) {
      if (((void *)*piVar1 == name) &&
         (((*(byte *)(piVar1 + -2) & 0x1f) == 4 || ((*(byte *)(piVar1 + -2) & 0x1f) == 0x19)))) {
        if (piVar1 + -2 != (int *)0x0) {
          g_arenas[5].cur = g_arenas[5].cur + 0xc;
          if (g_arenas[5].end < g_arenas[5].cur) {
            arena_grow(g_arenas + 5);
          }
          if (pcVar2 != (c1_u8 *)0x0) {
            *(int **)pcVar2 = piVar1 + -2;
            *(void **)(pcVar2 + 4) = scope;
            pcVar2[8] = '\0';
            pcVar2[9] = '\0';
            pcVar2[10] = '\0';
            pcVar2[0xb] = '\0';
            return pcVar2;
          }
          return (c1_u8 *)0x0;
        }
        break;
      }
    }
  }
  if (*(char *)((int)scope + 8) != '\x02') {
    return (c1_u8 *)0x0;
  }
  pcVar2 = (c1_u8 *)(**(code **)(**(int **)((int)scope + 4) + 0x10))(name);
  return pcVar2;
}

