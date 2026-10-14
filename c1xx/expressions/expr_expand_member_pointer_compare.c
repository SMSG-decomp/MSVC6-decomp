c1_node * __cdecl expr_expand_member_pointer_compare(c1_node *node)

{
  c1_type *mptype;
  int iVar1;
  code *builder_00;
  void *builder;
  c1_node *pcVar2;
  bool bVar3;
  
  mptype = *(c1_type **)((int)node->left + 4);
  bVar3 = (mptype->code & 0x8f) != 0x8a;
  iVar1 = class_complete_type_of(mptype);
  switch(iVar1) {
  case 1:
    goto switchD_104b0983_caseD_1;
  case 2:
    if (bVar3) {
      pcVar2 = expr_member_pointer_compare_dispatch(node,pm_compare_mi_function);
      return pcVar2;
    }
switchD_104b0983_caseD_1:
    return node;
  case 3:
    builder_00 = pm_compare_two_part;
    if (bVar3) {
      builder_00 = pm_compare_vi_function;
    }
    pcVar2 = expr_member_pointer_compare_dispatch(node,builder_00);
    return pcVar2;
  case 4:
    builder = pm_compare_general_data;
    if (bVar3) {
      builder = pm_compare_general_function;
    }
    pcVar2 = expr_member_pointer_compare_dispatch(node,builder);
    return pcVar2;
  default:
    return (c1_node *)0x0;
  }
}

