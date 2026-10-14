c1_node * __cdecl eh_state_marker(c1_node *expr,int unused,c1_flow_state *rec)

{
  c1_node *right;
  
  if (g_error_count == g_flow_error_count_at_start) {
    right = tree_new_node_with_fields(0xc3,1,(void *)rec->word1c,0x20);
    if ((g_eh_current_state == -1) || (g_eh_state_table[g_eh_current_state].cls == (c1_symbol *)0x0)
       ) {
      g_eh_current_state = rec->word18;
    }
    else {
      g_eh_previous_state = rec->word18;
    }
    if (expr != (c1_node *)0x0) {
      right = tree_new_binary_typed_right('7',expr,right);
    }
    return right;
  }
  return expr;
}

