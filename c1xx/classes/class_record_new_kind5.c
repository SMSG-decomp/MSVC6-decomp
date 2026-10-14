c1_u8 * __cdecl class_record_new_kind5(void)

{
  c1_u8 *list;
  
  list = g_arenas[5].cur;
  g_arenas[5].cur = g_arenas[5].cur + 0x1c;
  if (g_arenas[5].end < g_arenas[5].cur) {
    arena_grow(g_arenas + 5);
  }
  if (list == (c1_u8 *)0x0) {
    list = (c1_u8 *)0x0;
  }
  else {
    list[0x10] = '\x05';
    list[0x11] = '\0';
    list[0x12] = '\0';
    list[0x13] = '\0';
    list[0x14] = '\0';
    list[0] = '\0';
    list[1] = '\0';
    list[2] = '\0';
    list[3] = '\0';
  }
  if (g_empty_list_sentinel == (c1_symbol *)0x0) {
    g_empty_list_sentinel = sym_new_kind12();
  }
  sym_list_append_2(list,g_empty_list_sentinel);
  return list;
}

