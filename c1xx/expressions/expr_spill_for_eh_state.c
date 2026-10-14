c1_node * __cdecl expr_spill_for_eh_state(c1_node *value)

{
  c1_type *type;
  c1_flow_state *rec;
  c1_node *pcVar1;
  c1_node *right;
  c1_type *type_00;
  
  rec = func_flow_state_find(g_flow_state_top,0x43,'\0');
  pcVar1 = value;
  if (rec->subject != (void *)0xffffffff) {
    type = value->type;
    pcVar1 = expr_spill_to_temporary(&value);
    pcVar1->kind = pcVar1->kind | 0x20;
    type_00 = type;
    right = tree_new_node_with_fields(0xc2,1,rec->subject,0x20);
    value = tree_new_node('7',value,right,type_00);
    pcVar1 = tree_new_node('7',value,pcVar1,type);
    func_flow_state_release(rec);
    return pcVar1;
  }
  func_flow_state_release(rec);
  return pcVar1;
}

