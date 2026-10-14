void __cdecl
pm_convert_two_part_offset(c1_node *node,c1_type *type,int unused3,int unused4,int value)

{
  int value_00;
  byte bVar1;
  c1_node *pcVar2;
  c1_node *pcVar3;
  
  value_00 = value;
  if (value == 0) {
    bVar1 = type_member_pointers_same_null(type,node->type);
    if (bVar1 != 0) {
      tree_new_cast(type,node);
      return;
    }
  }
  pcVar2 = pm_spill_member_pointer_operand(node,0,(c1_node **)&value);
  pcVar2 = tree_new_rvalue(pcVar2);
  pcVar3 = pm_spill_member_pointer_operand(node,1,(c1_node **)&value);
  pcVar3 = tree_new_rvalue(pcVar3);
  pcVar3 = tree_new_offset(pcVar3,value_00,type);
  expr_build_null_checked_member_pointer(pcVar3,pcVar2,node->type);
  return;
}

