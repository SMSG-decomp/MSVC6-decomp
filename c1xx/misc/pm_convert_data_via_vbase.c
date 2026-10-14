void __cdecl
pm_convert_data_via_vbase(c1_node *node,c1_node *type,int unused3,int unused4,int value,int value2)

{
  c1_symbol *cls;
  int iVar1;
  c1_type *pcVar2;
  c1_node *pcVar3;
  c1_node *pcVar4;
  c1_node *pcVar5;
  int node_00;
  int value2_00;
  int *offset_out;
  int *index_out;
  c1_node *local_4;
  
  pcVar5 = type;
  index_out = &value;
  offset_out = &value2;
  node_00 = 0;
  iVar1 = value;
  value2_00 = value2;
  cls = (c1_symbol *)type_member_pointer_class((c1_type *)type);
  pm_vi_member_offset_adjust(cls,node_00,iVar1,value2_00,offset_out,index_out);
  iVar1 = pm_value_may_be_null((char *)node);
  if ((char)iVar1 != '\0') {
    pm_spill_object_for_data_member(node,&local_4,&type);
    pcVar2 = type_int();
    pcVar3 = tree_new_offset(type,value2,pcVar2);
    pcVar4 = tree_new_int_constant(value);
    pcVar5 = pm_spill_vi_data_pointer((c1_type *)pcVar5,pcVar3,pcVar4);
    expr_build_null_checked_member_pointer(pcVar5,local_4,node->type);
    return;
  }
  pcVar2 = type_int();
  pcVar3 = tree_new_offset(node,value2,pcVar2);
  pcVar4 = tree_new_int_constant(value);
  pm_spill_vi_data_pointer((c1_type *)pcVar5,pcVar3,pcVar4);
  return;
}

