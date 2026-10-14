c1_node * __cdecl expr_build_member_pointer_dereference(c1_node *node)

{
  c1_u8 cVar1;
  c1_node *pcVar2;
  int iVar3;
  c1_node *pcVar4;
  c1_type *pcVar5;
  c1_type local_10;
  c1_node *member_pointer;
  
  cVar1 = node->op;
  pcVar4 = node->left;
  member_pointer = node->right;
  if (cVar1 == 0x92) {
    node->op = 0x93;
    pcVar2 = expr_build_address_of(pcVar4,6);
    node->left = pcVar2;
  }
  iVar3 = pm_convert_object_to_member_class(node);
  if ((char)iVar3 == '\0') {
    diag_error(0x287,cVar1,member_pointer->type,pcVar4->type);
  }
  else {
    if ((member_pointer->type->code & 0x8f) != 0x8a) {
      local_10.base = (c1_type *)0x0;
      local_10.debug_index = 0;
      local_10.code = 0x80c;
      local_10.flags = 0;
      local_10.extra.cls = (c1_symbol *)0x0;
      pcVar5 = type_intern(&local_10);
      node->type = pcVar5;
      return node;
    }
    iVar3 = class_complete_type_of(member_pointer->type);
    switch(iVar3) {
    case 1:
    case 2:
      pcVar4 = pm_build_simple_data_member_access(node);
      return pcVar4;
    case 3:
      pcVar4 = pm_build_vi_data_member_access(node);
      return pcVar4;
    case 4:
      pcVar4 = pm_build_general_data_member_access(node);
      return pcVar4;
    }
  }
  return (c1_node *)0x0;
}

