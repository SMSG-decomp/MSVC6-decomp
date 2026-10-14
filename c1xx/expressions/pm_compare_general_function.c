c1_node * __cdecl pm_compare_general_function(c1_node *node,int op,int join,int join2)

{
  c1_node *pcVar1;
  c1_node *pcVar2;
  c1_node *pcVar3;
  c1_node *pcVar4;
  c1_node *pcVar5;
  c1_node *right;
  c1_node *pcVar6;
  c1_node *pcVar7;
  c1_node *mp;
  c1_node *pcVar8;
  c1_node *pcVar9;
  c1_node *pcVar10;
  c1_u8 cVar11;
  
  pcVar9 = node;
  pcVar10 = node->left;
  pcVar8 = pcVar10;
  pcVar1 = pm_spill_member_pointer_operand(pcVar10,0,&node);
  pcVar1 = pm_code_part(pcVar1,pcVar8);
  pcVar8 = pcVar10;
  pcVar2 = pm_spill_member_pointer_operand(pcVar10,1,&node);
  pcVar2 = pm_code_part(pcVar2,pcVar8);
  pcVar8 = pcVar10;
  pcVar3 = pm_spill_member_pointer_operand(pcVar10,1,&node);
  pcVar3 = pm_this_adjustment_part(pcVar3,pcVar8);
  pcVar8 = pcVar10;
  pcVar4 = pm_spill_member_pointer_operand(pcVar10,1,&node);
  pcVar4 = member_pointer_function_part_1b(pcVar4,(int)pcVar8);
  pcVar8 = pcVar10;
  pcVar5 = pm_spill_member_pointer_operand(pcVar10,1,&node);
  pcVar5 = member_pointer_function_part_2(pcVar5,(int)pcVar8);
  right = tree_new_null_member_pointer(pcVar10->type);
  pcVar9 = pcVar9->right;
  pcVar8 = pcVar9;
  pcVar6 = pm_spill_member_pointer_operand(pcVar9,0,&node);
  pcVar6 = pm_code_part(pcVar6,pcVar8);
  pcVar8 = pcVar9;
  pcVar7 = pm_spill_member_pointer_operand(pcVar9,1,&node);
  pcVar7 = pm_this_adjustment_part(pcVar7,pcVar8);
  pcVar8 = pcVar10;
  mp = pm_spill_member_pointer_operand(pcVar9,1,&node);
  pcVar8 = member_pointer_function_part_1b(mp,(int)pcVar8);
  pcVar9 = pm_spill_member_pointer_operand(pcVar9,1,&node);
  pcVar10 = member_pointer_function_part_2(pcVar9,(int)pcVar10);
  cVar11 = (c1_u8)op;
  pcVar9 = tree_new_node(cVar11,pcVar1,pcVar6,g_type_int);
  pcVar1 = tree_new_node(cVar11,pcVar2,right,g_type_int);
  pcVar2 = tree_new_node(cVar11,pcVar3,pcVar7,g_type_int);
  op = (int)tree_new_node(cVar11,pcVar4,pcVar8,g_type_int);
  pcVar10 = tree_new_node(cVar11,pcVar5,pcVar10,g_type_int);
  cVar11 = (c1_u8)join;
  pcVar8 = tree_new_node(cVar11,pcVar2,(c1_node *)op,g_type_int);
  pcVar10 = tree_new_node(cVar11,pcVar8,pcVar10,g_type_int);
  pcVar10 = tree_new_binary((c1_u8)join2,pcVar1,pcVar10);
  pcVar10 = tree_new_binary(cVar11,pcVar9,pcVar10);
  pcVar9 = tree_new_int_constant(0);
  pcVar10 = tree_new_binary_typed_right('7',pcVar9,pcVar10);
  return pcVar10;
}

