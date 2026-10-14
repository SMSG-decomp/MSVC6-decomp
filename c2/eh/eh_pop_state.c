c2_eh_state * eh_pop_state(void)

{
  c2_eh_state *pcVar1;
  
  pcVar1 = g_eh_current_state;
  g_eh_current_state = g_eh_current_state->parent;
  return pcVar1;
}

