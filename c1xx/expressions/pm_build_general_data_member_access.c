c1_node * __cdecl pm_build_general_data_member_access(c1_node *node)

{
  c1_node *node_00;
  c1_u32 cVar1;
  c1_node *pcVar2;
  c1_node *pcVar3;
  c1_node *pcVar4;
  c1_node *left;
  c1_node *local_10;
  c1_node *local_c;
  c1_node *local_8;
  c1_node *local_4;
  
  pcVar3 = node;
  node_00 = node->right;
  cVar1 = type_member_pointer_class(node_00->type);
  if (((*(byte *)(cVar1 + 2) & 4) == 0) || ((*(byte *)(*(int *)(cVar1 + 0x24) + 0x3b) & 0x10) != 0))
  {
    pm_spill_object_for_data_member(pcVar3->left,&local_c,&local_10);
    pcVar3 = pm_spill_member_pointer_operand(node_00,0,&node);
    pcVar3 = member_pointer_data_part_2(pcVar3);
    pcVar2 = pm_spill_member_pointer_operand(node_00,1,&node);
    local_8 = member_pointer_data_part_1b(pcVar2);
    pcVar2 = pm_spill_member_pointer_operand(node_00,1,&node);
    pcVar2 = member_pointer_data_part_0b(pcVar2);
    pcVar4 = tree_copy_to_arena(pcVar2,0);
    left = tree_copy_to_arena(local_10,0);
    local_4 = tree_new_binary('Q',left,pcVar4);
    if ((*(byte *)(cVar1 + 2) & 4) == 0) {
      pcVar2 = pm_build_vbase_adjusted_pointer_dynamic(local_c,(int)local_10,pcVar2,local_8,pcVar3);
    }
    else {
      pcVar2 = pm_build_vbase_adjusted_pointer(local_c,local_10,pcVar2,pcVar3,node_00->type);
    }
    pcVar2 = tree_new_binary('6',local_4,pcVar2);
    pcVar4 = tree_new_int_constant(0);
    pcVar3 = tree_copy_to_arena(pcVar3,0);
    pcVar3 = tree_new_binary_typed_right(';',pcVar3,pcVar4);
    pcVar3 = tree_new_binary_typed_right('V',pcVar3,pcVar2);
  }
  else {
    pcVar2 = pm_spill_member_pointer_operand(node_00,0,&node);
    pcVar2 = member_pointer_data_part_0b(pcVar2);
    pcVar3 = tree_new_binary('Q',pcVar3->left,pcVar2);
  }
  pcVar3 = tree_new_rvalue(pcVar3);
  pcVar3->type = node_00->type->base;
  return pcVar3;
}

