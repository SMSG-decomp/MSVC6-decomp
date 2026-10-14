c1_flow_state * __cdecl stmt_find_label_flow_state(c1_symbol *label)

{
  c1_flow_state *pcVar1;
  
  for (pcVar1 = g_defined_label_flow_states;
      (pcVar1 != (c1_flow_state *)0x0 && (pcVar1->subject != label));
      pcVar1 = (c1_flow_state *)pcVar1->word14) {
  }
  return pcVar1;
}

