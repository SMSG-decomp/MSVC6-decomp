void __cdecl expr_new_mark_eh_state(void)

{
  c1_flow_state *pcVar1;
  
  pcVar1 = func_flow_state_find(g_flow_state_top,0x43,'\0');
  pcVar1->subject = (void *)g_eh_current_state;
  g_eh_state_table[g_eh_current_state].kind = 9;
  return;
}

