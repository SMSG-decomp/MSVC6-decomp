int __cdecl
pm_convert_by_complete_kind(c1_node *node,c1_type *type,int path,int keep_sign,int value)

{
  c1_type *mptype;
  c1_type *type_00;
  int iVar1;
  int iVar2;
  c1_node *pcVar3;
  c1_node *pcVar4;
  int iVar5;
  c1_node *pcVar6;
  
  type_00 = type;
  pcVar4 = node;
  mptype = node->type;
  iVar1 = class_complete_type_of(type);
  iVar2 = class_complete_type_of(mptype);
  iVar5 = value;
  if ((value == 0) && (iVar1 == iVar2)) {
    pcVar4->type = type_00;
    return (int)pcVar4;
  }
  if (iVar2 == 1) {
    pcVar3 = tree_new_int_constant(value);
    pcVar4 = expr_member_pointer_cast(type_00,pcVar4,pcVar3);
    return (int)pcVar4;
  }
  if (iVar1 == 1) {
    iVar5 = pm_match_address_of_member_tree((char *)pcVar4,(char **)&node);
    if ((char)iVar5 == '\0') {
      pcVar3 = expr_build_address_of(pcVar4,4);
      node = pm_code_part(pcVar3,pcVar4);
    }
    pcVar4 = expr_member_pointer_cast(type_00,node,(c1_node *)0x0);
    return (int)pcVar4;
  }
  pcVar3 = pcVar4;
  pcVar6 = pm_spill_member_pointer_operand(pcVar4,0,&node);
  pcVar3 = pm_code_part(pcVar6,pcVar3);
  pcVar6 = pm_spill_member_pointer_operand(pcVar4,1,&node);
  pcVar4 = pm_this_adjustment_part(pcVar6,pcVar4);
  pcVar4 = tree_add_offset_if_nonzero(pcVar4,iVar5);
  pcVar4 = expr_member_pointer_cast(type_00,pcVar3,pcVar4);
  return (int)pcVar4;
}

