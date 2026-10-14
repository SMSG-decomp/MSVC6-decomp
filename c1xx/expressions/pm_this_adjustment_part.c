c1_node * __cdecl pm_this_adjustment_part(c1_node *left,c1_node *node)

{
  int iVar1;
  c1_node *pcVar2;
  
  iVar1 = class_complete_type_of(node->type);
  if (iVar1 == 1) {
    pcVar2 = tree_new_int_constant(0);
    return pcVar2;
  }
  if ((1 < iVar1) && (iVar1 < 5)) {
    pcVar2 = member_pointer_function_part(left,(int)node,0);
    return pcVar2;
  }
  return (c1_node *)0x0;
}

