c1_node * __cdecl pm_compare_general_data(c1_node *node,int op,int join)

{
  c1_node *pcVar1;
  c1_node *pcVar2;
  c1_node *pcVar3;
  c1_node *left;
  c1_node *pcVar4;
  c1_node *pcVar5;
  c1_u8 cVar6;
  
  pcVar4 = node;
  pcVar3 = node->left;
  pcVar1 = pm_spill_member_pointer_operand(pcVar3,0,&node);
  pcVar1 = member_pointer_data_part_0b(pcVar1);
  pcVar2 = pm_spill_member_pointer_operand(pcVar3,1,&node);
  pcVar2 = member_pointer_data_part_1b(pcVar2);
  pcVar3 = pm_spill_member_pointer_operand(pcVar3,1,&node);
  left = member_pointer_data_part_2(pcVar3);
  pcVar3 = pcVar4->right;
  pcVar4 = pm_spill_member_pointer_operand(pcVar3,0,&node);
  pcVar4 = member_pointer_data_part_0b(pcVar4);
  pcVar5 = pm_spill_member_pointer_operand(pcVar3,1,&node);
  pcVar5 = member_pointer_data_part_1b(pcVar5);
  pcVar3 = pm_spill_member_pointer_operand(pcVar3,1,&node);
  pcVar3 = member_pointer_data_part_2(pcVar3);
  cVar6 = (c1_u8)op;
  pcVar4 = tree_new_node(cVar6,pcVar1,pcVar4,g_type_int);
  pcVar1 = tree_new_node(cVar6,pcVar2,pcVar5,g_type_int);
  pcVar3 = tree_new_node(cVar6,left,pcVar3,g_type_int);
  cVar6 = (c1_u8)join;
  pcVar4 = tree_new_binary(cVar6,pcVar4,pcVar1);
  pcVar3 = tree_new_binary(cVar6,pcVar4,pcVar3);
  pcVar4 = tree_new_int_constant(0);
  pcVar3 = tree_new_binary_typed_right('7',pcVar4,pcVar3);
  return pcVar3;
}

