int __cdecl pm_lower_general_member_call(c1_node *node,c1_node *node2,c1_type *type,c1_node *left)

{
  c1_u32 cVar1;
  int iVar2;
  c1_node *pcVar3;
  c1_node *pcVar4;
  c1_node *pcVar5;
  c1_node *pcVar6;
  c1_node *pcVar7;
  c1_node *pcVar8;
  bool bVar9;
  
  pcVar6 = node2;
  cVar1 = type_member_pointer_class(node2->type);
  iVar2 = expr_is_reusable_lvalue(pcVar6);
  pcVar7 = left;
  bVar9 = (char)iVar2 == '\0';
  if (bVar9) {
    pcVar5 = pm_spill_member_pointer_operand(pcVar6,0,&node2);
    *(c1_node **)pcVar7 = pcVar5;
  }
  pcVar5 = pcVar6;
  pcVar3 = pm_spill_member_pointer_operand(pcVar6,(uint)bVar9,&node2);
  pcVar3 = pm_code_part(pcVar3,pcVar5);
  pcVar5 = pcVar6;
  pcVar4 = pm_spill_member_pointer_operand(pcVar6,1,&node2);
  pcVar5 = pm_this_adjustment_part(pcVar4,pcVar5);
  if (((*(byte *)(cVar1 + 2) & 4) == 0) || ((*(byte *)(*(int *)(cVar1 + 0x24) + 0x3b) & 0x10) != 0))
  {
    pm_spill_object_for_member_call(node,&left,&node,(c1_node **)pcVar7);
    pcVar7 = tree_copy_to_arena(pcVar5,0);
    pcVar4 = tree_copy_to_arena(node,0);
    pcVar4 = tree_new_binary('Q',pcVar4,pcVar7);
    pcVar7 = pcVar6;
    pcVar8 = pm_spill_member_pointer_operand(pcVar6,1,&node2);
    pcVar7 = member_pointer_function_part_2(pcVar8,(int)pcVar7);
    if ((*(byte *)(cVar1 + 2) & 4) == 0) {
      pcVar8 = pm_spill_member_pointer_operand(pcVar6,1,&node2);
      pcVar6 = member_pointer_function_part_1b(pcVar8,(int)pcVar6);
      pcVar6 = pm_build_vbase_adjusted_pointer_dynamic(left,(int)node,pcVar5,pcVar6,pcVar7);
    }
    else {
      pcVar6 = pm_build_vbase_adjusted_pointer(left,node,pcVar5,pcVar7,pcVar6->type);
    }
    pcVar6 = tree_new_binary('6',pcVar4,pcVar6);
    pcVar5 = tree_new_int_constant(0);
    pcVar7 = tree_copy_to_arena(pcVar7,0);
    pcVar7 = tree_new_binary_typed_right(';',pcVar7,pcVar5);
    pcVar6 = tree_new_binary_typed_right('V',pcVar7,pcVar6);
  }
  else {
    pcVar6 = tree_new_binary('Q',node,pcVar5);
  }
  pcVar6 = tree_new_member_offset_load(pcVar3,pcVar6,type);
  return (int)pcVar6;
}

