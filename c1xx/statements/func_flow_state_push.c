void __cdecl func_flow_state_push(c1_symbol *fn,void *param_scope)

{
  c1_flow_state *pcVar1;
  int iVar2;
  int kind;
  int word1;
  int word2;
  int word3;
  c1_symbol *local_8;
  int word5;
  
  word1 = 0;
  word2 = 0;
  word3 = 0;
  kind = 1;
  local_8 = fn;
  word5 = 0;
  g_flow_state_function_record = g_flow_state_top;
  if ((g_flow_state_abandoned != '\0') || (g_flow_error_count_at_start != g_error_count)) {
    func_flow_state_reset();
  }
  g_flow_state_abandoned = '\0';
  func_check_flow_state_complexity((c1_u8 *)&kind,0x18);
  g_flow_error_count_at_start = g_error_count;
  func_flow_state_note();
  if ((fn->flags3 & 4) == 0) {
    if (param_scope == (void *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)((int)param_scope + 8);
    }
    for (; (iVar2 != 0 && (eh_register_destructible_object((c1_symbol *)(iVar2 + -8),0), iVar2 != 0)
           ); iVar2 = *(int *)(iVar2 + 0x1c)) {
    }
  }
  func_flow_state_note_3();
  if (g_flow_state_function_record != (c1_flow_state *)0x0) {
    pcVar1 = g_flow_state_function_record->next;
    g_flow_state_bottom->prev = g_flow_state_top;
    g_flow_state_top->next = g_flow_state_bottom;
    pcVar1->prev = (c1_flow_state *)0x0;
    g_flow_state_function_record->next = (c1_flow_state *)0x0;
    g_flow_state_top = g_flow_state_function_record;
    g_flow_state_function_record = g_flow_state_bottom->prev;
    g_flow_state_bottom = pcVar1;
  }
  return;
}

