c1_node * __cdecl pm_lower_member_function_call(c1_node *left,c1_node **spilled)

{
  c1_node *node2;
  c1_type *mptype;
  int iVar1;
  c1_node *pcVar2;
  
  pcVar2 = left->left;
  node2 = left->right;
  mptype = node2->type;
  *spilled = (c1_node *)0x0;
  iVar1 = class_complete_type_of(mptype);
  switch(iVar1) {
  case 1:
    pcVar2 = tree_new_unary('=',(c1_type *)
                                **(undefined4 **)
                                  (*(int *)((-(uint)((mptype->code & 0x80) != 0) & (uint)mptype) + 4
                                           ) + 8),pcVar2);
    pcVar2 = tree_new_binary(0x99,node2,pcVar2);
    return pcVar2;
  case 2:
    pcVar2 = pm_lower_mi_member_call(pcVar2,node2,mptype,spilled);
    return pcVar2;
  case 3:
    pcVar2 = pm_lower_vi_member_call(pcVar2,node2,mptype,spilled);
    return pcVar2;
  case 4:
    pcVar2 = (c1_node *)pm_lower_general_member_call(pcVar2,node2,mptype,(c1_node *)spilled);
    return pcVar2;
  default:
    return (c1_node *)0x0;
  }
}

