c1_node * __cdecl pm_compare_vi_function(c1_node *node,int op,int join,int join2)

{
  c1_node *pcVar1;
  c1_node *pcVar2;
  c1_node *pcVar3;
  c1_node *pcVar4;
  c1_node *right;
  c1_node *pcVar5;
  c1_node *left;
  c1_node *pcVar6;
  c1_node *pcVar7;
  c1_node *pcVar8;
  c1_u8 cVar9;
  
  pcVar7 = node;
  pcVar8 = node->left;
  pcVar6 = pcVar8;
  pcVar1 = pm_spill_member_pointer_operand(pcVar8,0,&node);
  pcVar1 = pm_code_part(pcVar1,pcVar6);
  pcVar6 = pcVar8;
  pcVar2 = pm_spill_member_pointer_operand(pcVar8,1,&node);
  pcVar2 = pm_code_part(pcVar2,pcVar6);
  pcVar6 = pcVar8;
  pcVar3 = pm_spill_member_pointer_operand(pcVar8,1,&node);
  pcVar3 = pm_this_adjustment_part(pcVar3,pcVar6);
  pcVar6 = pcVar8;
  pcVar4 = pm_spill_member_pointer_operand(pcVar8,1,&node);
  pcVar4 = member_pointer_function_part_1(pcVar4,(int)pcVar6);
  right = tree_new_null_member_pointer(pcVar8->type);
  pcVar7 = pcVar7->right;
  pcVar6 = pcVar7;
  pcVar5 = pm_spill_member_pointer_operand(pcVar7,0,&node);
  pcVar5 = pm_code_part(pcVar5,pcVar6);
  pcVar6 = pcVar7;
  left = pm_spill_member_pointer_operand(pcVar7,1,&node);
  pcVar6 = pm_this_adjustment_part(left,pcVar6);
  pcVar7 = pm_spill_member_pointer_operand(pcVar7,1,&node);
  pcVar8 = member_pointer_function_part_1(pcVar7,(int)pcVar8);
  cVar9 = (c1_u8)op;
  pcVar7 = tree_new_node(cVar9,pcVar1,pcVar5,g_type_int);
  pcVar1 = tree_new_node(cVar9,pcVar2,right,g_type_int);
  op = (int)tree_new_node(cVar9,pcVar3,pcVar6,g_type_int);
  pcVar8 = tree_new_node(cVar9,pcVar4,pcVar8,g_type_int);
  cVar9 = (c1_u8)join;
  pcVar8 = tree_new_node(cVar9,(c1_node *)op,pcVar8,g_type_int);
  pcVar8 = tree_new_binary((c1_u8)join2,pcVar1,pcVar8);
  pcVar8 = tree_new_binary(cVar9,pcVar7,pcVar8);
  pcVar7 = tree_new_int_constant(0);
  pcVar8 = tree_new_binary_typed_right('7',pcVar7,pcVar8);
  return pcVar8;
}

