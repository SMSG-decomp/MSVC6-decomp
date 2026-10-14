int __cdecl eh_check_state_count(c1_symbol *cls)

{
  c1_u8 cVar1;
  c1_u8 cVar2;
  c1_u8 cVar3;
  c1_eh_state *pcVar4;
  int iVar5;
  c1_u8 *pcVar6;
  
  pcVar6 = g_arenas[4].cur;
  if (g_eh_state_table == (c1_eh_state *)0x0) {
    g_arenas[4].cur = g_arenas[4].cur + g_eh_state_capacity * 0x10;
    if (g_arenas[4].end < g_arenas[4].cur) {
      arena_grow(g_arenas + 4);
    }
    g_eh_state_table = (c1_eh_state *)pcVar6;
  }
  else if (g_eh_last_state + 1 == g_eh_state_capacity) {
    if (0x7ff < g_eh_state_capacity + 0x80) {
      diag_fatal(0x1fd,g_current_function);
    }
    pcVar4 = (c1_eh_state *)g_arenas[4].cur;
    g_arenas[4].cur = g_arenas[4].cur + g_eh_state_capacity * 0x10 + 0x800;
    if (g_arenas[4].end < g_arenas[4].cur) {
      arena_grow(g_arenas + 4);
    }
    for (iVar5 = (g_eh_state_capacity & 0xfffffffU) << 2; iVar5 != 0; iVar5 = iVar5 + -1) {
      cVar1 = g_eh_state_table->pad01[0];
      cVar2 = g_eh_state_table->pad01[1];
      cVar3 = g_eh_state_table->pad01[2];
      pcVar6[0] = g_eh_state_table->unwound;
      pcVar6[1] = cVar1;
      pcVar6[2] = cVar2;
      pcVar6[3] = cVar3;
      g_eh_state_table = (c1_eh_state *)&g_eh_state_table->kind;
      pcVar6 = pcVar6 + 4;
    }
    for (iVar5 = 0; iVar5 != 0; iVar5 = iVar5 + -1) {
      *pcVar6 = g_eh_state_table->unwound;
      g_eh_state_table = (c1_eh_state *)g_eh_state_table->pad01;
      pcVar6 = pcVar6 + 1;
    }
    g_eh_state_capacity = g_eh_state_capacity + 0x80;
    g_eh_state_table = pcVar4;
  }
  g_eh_last_state = g_eh_last_state + 1;
  g_eh_previous_state = g_eh_current_state;
  g_eh_current_state = g_eh_last_state;
  g_eh_state_table[g_eh_last_state].cls = cls;
  g_eh_state_table[g_eh_current_state].kind = g_eh_context_kind;
  g_eh_state_table[g_eh_current_state].unwound = '\0';
  return g_eh_current_state;
}

