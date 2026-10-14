void init_pop_brace_level(void)

{
  int iVar1;
  int iVar2;
  
  if (-1 < g_init_brace_depth) {
    if ((g_init_level->flags & 0x20) != 0) {
      g_init_brace_depth = g_init_brace_depth + -1;
      g_init_level = g_init_levels + g_init_brace_depth;
      return;
    }
    iVar1 = init_count_remaining_elements();
    if ((g_init_level->flags & 6) == 0) {
      iVar2 = init_partial_array_remainder();
      iVar1 = iVar1 + iVar2;
    }
    g_init_level->flags = '\0';
    init_advance_member();
    if (iVar1 != 0) {
      g_constant_value_high = 0;
      g_constant_value = iVar1;
      init_emit_data(0);
    }
  }
  return;
}

