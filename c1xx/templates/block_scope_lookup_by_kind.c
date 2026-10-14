c1_u8 * __thiscall
block_scope_lookup_by_kind(c1xx_block_scope *scope,int name,uint kind_mask,byte *found)

{
  c1_sym_link *entry;
  c1_u8 *pcVar1;
  c1_u8 *pcVar2;
  uint uVar3;
  
  entry = scope->symbols->head;
  *found = 1;
  while( true ) {
    if (entry == (c1_sym_link *)0x0) {
      return (c1_u8 *)0x0;
    }
    if ((entry->name == (fe_name *)name) &&
       (uVar3 = sym_kind_in_lookup_mask((c1_u8 *)entry,kind_mask), pcVar2 = g_arenas[5].cur,
       (char)uVar3 != '\0')) break;
    entry = entry->next;
  }
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
  if (pcVar1 == (c1_u8 *)0x0) {
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
  *(c1xx_block_scope **)(pcVar1 + 4) = scope;
  *(c1_u32 **)pcVar1 = &entry[-1].position;
  pcVar1[8] = '\0';
  pcVar1[9] = '\0';
  pcVar1[10] = '\0';
  pcVar1[0xb] = '\0';
  *(c1_u8 **)pcVar2 = pcVar1;
  *(c1_u8 **)(pcVar2 + 4) = pcVar1;
  return pcVar2;
}

