void __cdecl pm_compare_two_part(c1_node *node,int op,int op2)

{
  c1_node *pcVar1;
  c1_node *pcVar2;
  c1_node *left;
  c1_node *pcVar3;
  c1_u8 op_00;
  
  pcVar3 = node;
  pcVar2 = node->left;
  pcVar1 = pm_spill_member_pointer_operand(pcVar2,0,&node);
  pcVar1 = member_pointer_data_part_0(pcVar1);
  pcVar2 = pm_spill_member_pointer_operand(pcVar2,1,&node);
  left = member_pointer_data_part_1(pcVar2);
  pcVar2 = pcVar3->right;
  pcVar3 = pm_spill_member_pointer_operand(pcVar2,0,&node);
  pcVar3 = member_pointer_data_part_0(pcVar3);
  pcVar2 = pm_spill_member_pointer_operand(pcVar2,1,&node);
  pcVar2 = member_pointer_data_part_1(pcVar2);
  op_00 = (c1_u8)op;
  pcVar3 = tree_new_node(op_00,pcVar1,pcVar3,g_type_int);
  pcVar2 = tree_new_node(op_00,left,pcVar2,g_type_int);
  pcVar2 = tree_new_binary((c1_u8)op2,pcVar3,pcVar2);
  pcVar3 = tree_new_int_constant(0);
  tree_new_binary_typed_right('7',pcVar3,pcVar2);
  return;
}

