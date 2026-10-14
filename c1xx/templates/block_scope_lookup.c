c1_u8 * __thiscall block_scope_lookup(void *this,int name,int kind)

{
  c1_u8 *pcVar1;
  c1_u8 *pcVar2;
  c1_symbol *pcVar3;
  
  if (*(c1_sym_list **)((int)this + 0x14) != (c1_sym_list *)0x0) {
    pcVar3 = block_scope_find_name(*(c1_sym_list **)((int)this + 0x14),name);
    pcVar2 = g_arenas[5].cur;
    if (pcVar3 != (c1_symbol *)0x0) {
      g_arenas[5].cur = g_arenas[5].cur + 8;
      if (g_arenas[5].end < g_arenas[5].cur) {
        arena_grow(g_arenas + 5);
      }
      pcVar1 = g_arenas[5].cur;
      if (pcVar2 == (c1_u8 *)0x0) {
        return (c1_u8 *)0x0;
      }
      g_arenas[5].cur = g_arenas[5].cur + 0xc;
      if (g_arenas[5].end < g_arenas[5].cur) {
        arena_grow(g_arenas + 5);
      }
      if (pcVar1 != (c1_u8 *)0x0) {
        *(c1_symbol **)pcVar1 = pcVar3;
        *(void **)(pcVar1 + 4) = this;
        pcVar1[8] = '\0';
        pcVar1[9] = '\0';
        pcVar1[10] = '\0';
        pcVar1[0xb] = '\0';
        *(c1_u8 **)pcVar2 = pcVar1;
        *(c1_u8 **)(pcVar2 + 4) = pcVar1;
        return pcVar2;
      }
      pcVar2[0] = '\0';
      pcVar2[1] = '\0';
      pcVar2[2] = '\0';
      pcVar2[3] = '\0';
      pcVar2[4] = '\0';
      pcVar2[5] = '\0';
      pcVar2[6] = '\0';
      pcVar2[7] = '\0';
      return pcVar2;
    }
  }
  return (c1_u8 *)0x0;
}

