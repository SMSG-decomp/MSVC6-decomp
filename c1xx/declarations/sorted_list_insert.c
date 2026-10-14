void __thiscall sorted_list_insert(void *this,uint value)

{
  c1_u8 *pcVar1;
  int *piVar2;
  uint *prev_node;
  uint *prev_node_2;
  uint *prev_node_3;
  
  pcVar1 = g_arenas[1].cur;
  piVar2 = *(int **)this;
  if (piVar2 == (int *)0x0) {
    g_arenas[1].cur = g_arenas[1].cur + 0xc;
    if (g_arenas[1].end < g_arenas[1].cur) {
      arena_grow(g_arenas + 1);
    }
    if (pcVar1 == (c1_u8 *)0x0) {
      pcVar1 = (c1_u8 *)0x0;
    }
    else {
      prev_node = *(uint **)((int)this + 4);
      pcVar1[0] = '\0';
      pcVar1[1] = '\0';
      pcVar1[2] = '\0';
      pcVar1[3] = '\0';
      *(uint **)(pcVar1 + 4) = prev_node;
      *(uint *)(pcVar1 + 8) = value;
      if (prev_node != (uint *)0x0) {
        *prev_node = (uint)pcVar1;
      }
      if (*(int *)pcVar1 != 0) {
        *(c1_u8 **)(*(int *)pcVar1 + 4) = pcVar1;
        *(c1_u8 **)this = pcVar1;
        *(c1_u8 **)((int)this + 4) = pcVar1;
        return;
      }
    }
    *(c1_u8 **)this = pcVar1;
    *(c1_u8 **)((int)this + 4) = pcVar1;
    return;
  }
  while ((uint)piVar2[2] <= value) {
    piVar2 = (int *)*piVar2;
    if (piVar2 == (int *)0x0) {
      g_arenas[1].cur = g_arenas[1].cur + 0xc;
      if (g_arenas[1].end < g_arenas[1].cur) {
        arena_grow(g_arenas + 1);
      }
      if (pcVar1 == (c1_u8 *)0x0) {
        pcVar1 = (c1_u8 *)0x0;
      }
      else {
        prev_node_2 = *(uint **)((int)this + 4);
        pcVar1[0] = '\0';
        pcVar1[1] = '\0';
        pcVar1[2] = '\0';
        pcVar1[3] = '\0';
        *(uint **)(pcVar1 + 4) = prev_node_2;
        *(uint *)(pcVar1 + 8) = value;
        if (prev_node_2 != (uint *)0x0) {
          *prev_node_2 = (uint)pcVar1;
        }
        if (*(int *)pcVar1 != 0) {
          *(c1_u8 **)(*(int *)pcVar1 + 4) = pcVar1;
          *(c1_u8 **)((int)this + 4) = pcVar1;
          return;
        }
      }
      *(c1_u8 **)((int)this + 4) = pcVar1;
      return;
    }
  }
  g_arenas[1].cur = g_arenas[1].cur + 0xc;
  if (g_arenas[1].end < g_arenas[1].cur) {
    arena_grow(g_arenas + 1);
  }
  if (pcVar1 == (c1_u8 *)0x0) {
    pcVar1 = (c1_u8 *)0x0;
  }
  else {
    prev_node_3 = (uint *)piVar2[1];
    *(int **)pcVar1 = piVar2;
    *(uint **)(pcVar1 + 4) = prev_node_3;
    *(uint *)(pcVar1 + 8) = value;
    if (prev_node_3 != (uint *)0x0) {
      *prev_node_3 = (uint)pcVar1;
    }
    if (*(int *)pcVar1 != 0) {
      *(c1_u8 **)(*(int *)pcVar1 + 4) = pcVar1;
    }
  }
  if (piVar2 != *(int **)this) {
    return;
  }
  *(c1_u8 **)this = pcVar1;
  return;
}

