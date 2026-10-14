c1_node * __cdecl
pm_lower_mi_member_call(c1_node *left,c1_node *node,c1_type *type,c1_node **spilled)

{
  int iVar1;
  c1_node *pcVar2;
  c1_node *pcVar3;
  c1_node *pcVar4;
  
  pcVar4 = node;
  iVar1 = expr_is_reusable_lvalue(node);
  if ((char)iVar1 == '\0') {
    pcVar3 = pm_spill_member_pointer_operand(pcVar4,0,&node);
    *spilled = pcVar3;
    pcVar3 = pcVar4;
    pcVar2 = pm_spill_member_pointer_operand(pcVar4,1,&node);
    pcVar3 = pm_code_part(pcVar2,pcVar3);
  }
  else {
    pcVar3 = pcVar4;
    pcVar2 = pm_spill_member_pointer_operand(pcVar4,0,&node);
    pcVar3 = pm_code_part(pcVar2,pcVar3);
  }
  pcVar2 = pm_spill_member_pointer_operand(pcVar4,1,&node);
  pcVar4 = pm_this_adjustment_part(pcVar2,pcVar4);
  pcVar4 = tree_new_binary('Q',left,pcVar4);
  pcVar4 = tree_new_member_offset_load(pcVar3,pcVar4,type);
  return pcVar4;
}

