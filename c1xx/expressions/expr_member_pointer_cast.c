c1_node * __cdecl expr_member_pointer_cast(c1_type *type,c1_node *node,c1_node *right2)

{
  int iVar1;
  c1_node *pcVar2;
  
  iVar1 = class_complete_type_of(type);
  if (iVar1 == 1) {
    pcVar2 = tree_new_cast(type,node);
    return pcVar2;
  }
  if (iVar1 != 2) {
    return (c1_node *)0x0;
  }
  pcVar2 = pm_spill_mi_function_pointer(type,node,right2);
  return pcVar2;
}

