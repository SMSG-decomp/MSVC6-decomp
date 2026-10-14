c1_node * __cdecl tree_new_argument_slot_intrinsic(c1_type *type,int size,c1_node *slot)

{
  c1_node *pcVar1;
  c1_node *left;
  int flag;
  
  flag = 2;
  pcVar1 = tree_new_int_constant(size);
  pcVar1 = tree_append_list_item((c1_node *)0x0,pcVar1,flag);
  pcVar1 = tree_append_list_item(pcVar1,slot,2);
  left = tree_new_int_constant(0xde);
  pcVar1 = tree_new_binary('w',left,pcVar1);
  pcVar1->type = type;
  return pcVar1;
}

