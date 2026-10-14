c1_type_list * __cdecl param_type_list_intern(int count,c1_sym_list *params)

{
  c1_u8 *list;
  c1_type_list *pcVar1;
  c1_sym_link *pcVar2;
  c1_symbol_type_word *pcVar3;
  uint hash;
  
  list = g_arenas[5].cur;
  hash = 0;
  g_arenas[5].cur = g_arenas[5].cur + count * 4 + 8;
  if (g_arenas[5].end < g_arenas[5].cur) {
    arena_grow(g_arenas + 5);
  }
  pcVar3 = (c1_symbol_type_word *)(list + 8);
  *(int *)list = count;
  if (params == (c1_sym_list *)0x0) {
    pcVar2 = (c1_sym_link *)0x0;
  }
  else {
    pcVar2 = params->head;
  }
  for (; pcVar2 != (c1_sym_link *)0x0; pcVar2 = pcVar2->next) {
    *pcVar3 = pcVar2->type;
    pcVar3 = pcVar3 + 1;
    hash = hash + ((*(ushort *)&pcVar2->type & 0x3ffc) >> 2);
    if (pcVar2 == (c1_sym_link *)0x0) break;
  }
  pcVar1 = type_list_intern((int *)list,hash);
  return pcVar1;
}

