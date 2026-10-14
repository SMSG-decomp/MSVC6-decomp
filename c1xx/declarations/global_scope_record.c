c1_type_list * __cdecl global_scope_record(void)

{
  c1_u8 *pcVar1;
  
  pcVar1 = g_arenas[0].cur;
  if (g_void_parameter_list_record == (c1_type_list *)0x0) {
    g_arenas[0].cur = g_arenas[0].cur + 0xc;
    if (g_arenas[0].end < g_arenas[0].cur) {
      arena_grow(g_arenas);
    }
    g_void_parameter_list_record = (c1_type_list *)pcVar1;
    pcVar1[0] = '\x01';
    pcVar1[1] = '\0';
    pcVar1[2] = '\0';
    pcVar1[3] = '\0';
    g_void_parameter_list_record->unk04 = 0;
    g_void_parameter_list_record->types[0] = g_type_void;
  }
  return g_void_parameter_list_record;
}

