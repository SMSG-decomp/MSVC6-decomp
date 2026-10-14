c1_u8 * __thiscall block_scope_lookup_tag(c1xx_block_scope *scope,int name)

{
  c1_u8 *pcVar1;
  c1_symbol *pcVar2;
  
  if (scope->symbols != (c1_sym_list *)0x0) {
    pcVar2 = block_scope_find_tag(scope->symbols,name);
    pcVar1 = g_arenas[5].cur;
    if (pcVar2 != (c1_symbol *)0x0) {
      g_arenas[5].cur = g_arenas[5].cur + 0xc;
      if (g_arenas[5].end < g_arenas[5].cur) {
        arena_grow(g_arenas + 5);
      }
      if (pcVar1 != (c1_u8 *)0x0) {
        *(c1_symbol **)pcVar1 = pcVar2;
        *(c1xx_block_scope **)(pcVar1 + 4) = scope;
        pcVar1[8] = '\0';
        pcVar1[9] = '\0';
        pcVar1[10] = '\0';
        pcVar1[0xb] = '\0';
        return pcVar1;
      }
      return (c1_u8 *)0x0;
    }
  }
  return (c1_u8 *)0x0;
}

