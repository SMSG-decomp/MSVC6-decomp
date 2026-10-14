void __cdecl eh_pop_state(void)

{
  int iVar1;
  c1_eh_state *pcVar2;
  int iVar3;
  
  iVar3 = g_eh_current_state;
  if ((g_eh_current_state != g_eh_region_base_state) &&
     (g_eh_pending_unwind_count = 0, iVar3 = g_eh_region_base_state,
     g_eh_region_base_state < g_eh_current_state)) {
    iVar1 = g_eh_current_state << 4;
    pcVar2 = g_eh_state_table;
    iVar3 = g_eh_region_base_state;
    do {
      if ((*(int *)(pcVar2->pad01 + iVar1 + 3) == 3) && (pcVar2->pad01[iVar1 + -1] == '\0')) {
        pcVar2->pad01[iVar1 + -1] = '\x01';
        g_eh_pending_unwind_count = g_eh_pending_unwind_count + 1;
        pcVar2 = g_eh_state_table;
        iVar3 = g_eh_region_base_state;
        g_eh_pending_unwind_state = g_eh_current_state;
      }
      g_eh_current_state = g_eh_current_state + -1;
      iVar1 = iVar1 + -0x10;
    } while (iVar3 < g_eh_current_state);
  }
  g_eh_current_state = iVar3;
  g_eh_context_kind = g_eh_state_stack->value;
  list_pop_head((int *)&g_eh_state_stack);
  return;
}

