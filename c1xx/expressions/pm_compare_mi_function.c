c1_node * __cdecl pm_compare_mi_function(c1_node *node,int op,int join,int join2)

{
  c1_node *pcVar1;
  c1_node *pcVar2;
  c1_node *pcVar3;
  c1_node *pcVar4;
  c1_node *pcVar5;
  c1_node *pcVar6;
  c1_node *pcVar7;
  c1_u8 op_00;
  c1_type *type;
  
  pcVar6 = node;
  pcVar7 = node->left;
  pcVar4 = pcVar7;
  pcVar1 = pm_spill_member_pointer_operand(pcVar7,0,&node);
  pcVar1 = pm_code_part(pcVar1,pcVar4);
  pcVar4 = pcVar7;
  pcVar2 = pm_spill_member_pointer_operand(pcVar7,1,&node);
  pcVar2 = pm_code_part(pcVar2,pcVar4);
  pcVar4 = pcVar7;
  pcVar3 = pm_spill_member_pointer_operand(pcVar7,1,&node);
  pcVar4 = pm_this_adjustment_part(pcVar3,pcVar4);
  pcVar3 = tree_new_null_member_pointer(pcVar7->type);
  pcVar7 = pcVar6->right;
  pcVar6 = pcVar7;
  pcVar5 = pm_spill_member_pointer_operand(pcVar7,0,&node);
  pcVar6 = pm_code_part(pcVar5,pcVar6);
  pcVar5 = pm_spill_member_pointer_operand(pcVar7,1,&node);
  pcVar7 = pm_this_adjustment_part(pcVar5,pcVar7);
  op_00 = (c1_u8)op;
  pcVar6 = tree_new_node(op_00,pcVar1,pcVar6,g_type_int);
  pcVar1 = tree_new_node(op_00,pcVar2,pcVar3,g_type_int);
  pcVar7 = tree_new_node(op_00,pcVar4,pcVar7,g_type_int);
  pcVar7 = tree_new_binary((c1_u8)join2,pcVar1,pcVar7);
  pcVar7 = tree_new_binary((c1_u8)join,pcVar6,pcVar7);
  type = pcVar7->type;
  pcVar6 = tree_new_int_constant(0);
  pcVar7 = tree_new_node('7',pcVar6,pcVar7,type);
  return pcVar7;
}

