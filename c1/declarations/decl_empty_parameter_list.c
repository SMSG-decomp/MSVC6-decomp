c1_param_list * __cdecl decl_empty_parameter_list(void)

{
  uchar *puVar1;
  
  puVar1 = g_arenas[0].cur;
  if (g_param_list_empty == (c1_param_list *)0x0) {
    g_arenas[0].cur = g_arenas[0].cur + 0xc;
    if (g_arenas[0].end < g_arenas[0].cur) {
      arena_grow(g_arenas);
    }
    g_param_list_empty = (c1_param_list *)puVar1;
    puVar1[0] = '\0';
    puVar1[1] = '\0';
    puVar1[2] = '\0';
    puVar1[3] = '\0';
    g_param_list_empty->debug_index = 0;
  }
  return g_param_list_empty;
}

