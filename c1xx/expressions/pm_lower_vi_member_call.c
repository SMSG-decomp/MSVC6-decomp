c1_node * __cdecl
pm_lower_vi_member_call(c1_node *node,c1_node *node2,c1_type *type,c1_node **spilled)

{
  int iVar1;
  c1_node *pcVar2;
  c1_node *pcVar3;
  c1_node *mp;
  c1_node *pcVar4;
  c1_node *pcVar5;
  bool bVar6;
  c1_node *local_8;
  c1_node *local_4;
  
  pcVar5 = node2;
  iVar1 = expr_is_reusable_lvalue(node2);
  bVar6 = (char)iVar1 == '\0';
  if (bVar6) {
    pcVar4 = pm_spill_member_pointer_operand(pcVar5,0,&node2);
    *spilled = pcVar4;
  }
  pcVar4 = pcVar5;
  pcVar2 = pm_spill_member_pointer_operand(pcVar5,(uint)bVar6,&node2);
  pcVar2 = pm_code_part(pcVar2,pcVar4);
  pcVar4 = pcVar5;
  pcVar3 = pm_spill_member_pointer_operand(pcVar5,1,&node2);
  pcVar3 = pm_this_adjustment_part(pcVar3,pcVar4);
  pcVar4 = pcVar5;
  mp = pm_spill_member_pointer_operand(pcVar5,1,&node2);
  pcVar4 = member_pointer_function_part_1(mp,(int)pcVar4);
  pm_spill_object_for_member_call(node,&local_4,&local_8,spilled);
  pcVar5 = pm_build_vbase_adjusted_pointer(local_4,local_8,pcVar3,pcVar4,pcVar5->type);
  pcVar5 = tree_new_member_offset_load(pcVar2,pcVar5,type);
  return pcVar5;
}

