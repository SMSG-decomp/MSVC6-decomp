c1_node * __cdecl pm_build_vi_data_member_access(c1_node *node)

{
  c1_node *pcVar1;
  c1_node *pcVar2;
  c1_node *pcVar3;
  c1_node *local_8;
  c1_node *local_4;
  
  pcVar1 = node;
  pm_spill_object_for_data_member(node->left,&local_4,&local_8);
  pcVar1 = pcVar1->right;
  pcVar2 = pm_spill_member_pointer_operand(pcVar1,0,&node);
  pcVar2 = member_pointer_data_part_1(pcVar2);
  pcVar3 = pm_spill_member_pointer_operand(pcVar1,1,&node);
  pcVar3 = member_pointer_data_part_0(pcVar3);
  pcVar2 = pm_build_vbase_adjusted_pointer(local_4,local_8,pcVar3,pcVar2,pcVar1->type);
  pcVar2 = tree_new_rvalue(pcVar2);
  pcVar2->type = pcVar1->type->base;
  return pcVar2;
}

