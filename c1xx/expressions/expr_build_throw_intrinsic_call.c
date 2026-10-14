c1_node * __cdecl expr_build_throw_intrinsic_call(c1_node *object,c1_node *throw_info)

{
  c1_node *pcVar1;
  c1_node *left;
  int flag;
  c1_type *type;
  
  flag = 2;
  type = g_type_void;
  pcVar1 = tree_append_list_item((c1_node *)0x0,object,2);
  pcVar1 = tree_append_list_item(pcVar1,throw_info,flag);
  left = tree_new_int_constant(0x151);
  pcVar1 = tree_new_node('w',left,pcVar1,type);
  return pcVar1;
}

