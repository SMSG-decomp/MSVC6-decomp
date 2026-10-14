c1_node * __cdecl
pm_build_vbase_adjusted_pointer
          (c1_node *left,c1_node *left2,c1_node *right,c1_node *right2,c1_type *type)

{
  c1_u32 cls;
  c1_node *pcVar1;
  c1_node *pcVar2;
  int *vbptr_offset;
  c1_type **first;
  c1_type *pcVar3;
  int local_4;
  
  vbptr_offset = &local_4;
  first = &type;
  cls = type_member_pointer_class(type);
  class_vbptr_layout(cls,vbptr_offset,(int *)first);
  pcVar3 = type;
  pcVar1 = tree_new_int_constant(local_4);
  pcVar1 = tree_new_node('Q',left,pcVar1,pcVar3);
  pcVar3 = type;
  pcVar2 = tree_new_int_constant(local_4);
  pcVar2 = tree_new_node('Q',left2,pcVar2,pcVar3);
  pcVar2 = tree_new_rvalue(pcVar2);
  pcVar2 = tree_new_binary_typed_right('Q',pcVar2,right2);
  pcVar2 = tree_new_rvalue(pcVar2);
  pcVar1 = tree_new_binary('Q',pcVar1,pcVar2);
  pcVar1 = tree_new_binary('Q',pcVar1,right);
  return pcVar1;
}

