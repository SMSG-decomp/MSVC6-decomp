c1_node * __cdecl expr_member_pointer_null_constant(c1_type *type)

{
  int iVar1;
  c1_node *pcVar2;
  bool bVar3;
  
  bVar3 = (type->code & 0x8f) == 0x8a;
  iVar1 = class_complete_type_of(type);
  switch(iVar1) {
  case 1:
  case 2:
    break;
  case 3:
    if (!bVar3) {
      pcVar2 = pm_null_vi_function_pointer(type);
      return pcVar2;
    }
    pcVar2 = pm_null_vi_data_pointer(type);
    return pcVar2;
  case 4:
    if (!bVar3) {
      pcVar2 = pm_null_general_function_pointer(type);
      return pcVar2;
    }
    pcVar2 = pm_null_general_data_pointer(type);
    return pcVar2;
  default:
    return (c1_node *)0x0;
  }
  if (bVar3) {
    pcVar2 = tree_new_null_data_member_pointer(type);
    return pcVar2;
  }
  pcVar2 = expr_null_member_pointer_value(type);
  return pcVar2;
}

