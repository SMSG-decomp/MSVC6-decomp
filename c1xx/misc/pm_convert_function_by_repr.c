int __cdecl
pm_convert_function_by_repr
          (c1_node *node,c1_type *type,int unused3,int unused4,int value,int value2)

{
  c1_type *type_00;
  int iVar1;
  c1_symbol *cls;
  c1_node *pcVar2;
  c1_node *pcVar3;
  c1_node *pcVar4;
  int value2_00;
  c1_node **offset_out;
  int *index_out;
  uint passthrough;
  
  type_00 = type;
  iVar1 = class_complete_type_of(type);
  pcVar4 = node;
  if (iVar1 == 1) {
    pcVar3 = expr_lvalue_address(node,0);
    pcVar4 = pm_code_part(pcVar3,pcVar4);
    pcVar4 = expr_member_pointer_cast(type_00,pcVar4,(c1_node *)0x0);
    return (int)pcVar4;
  }
  if (iVar1 == 2) {
    offset_out = &node;
    index_out = (int *)0x0;
    passthrough = 0;
    iVar1 = value;
    value2_00 = value2;
    cls = (c1_symbol *)type_member_pointer_class(node->type);
    pm_vi_member_offset_adjust(cls,passthrough,iVar1,value2_00,(int *)offset_out,index_out);
    pcVar3 = pcVar4;
    pcVar2 = pm_spill_member_pointer_operand(pcVar4,0,(c1_node **)&type);
    pcVar3 = pm_code_part(pcVar2,pcVar3);
    pcVar2 = pm_spill_member_pointer_operand(pcVar4,1,(c1_node **)&type);
    pcVar4 = pm_this_adjustment_part(pcVar2,pcVar4);
    if (node != (c1_node *)0x0) {
      pcVar2 = tree_new_int_constant((int)node);
      pcVar4 = tree_new_binary('F',pcVar4,pcVar2);
    }
    pcVar4 = expr_member_pointer_cast(type_00,pcVar3,pcVar4);
    return (int)pcVar4;
  }
  return (int)node;
}

