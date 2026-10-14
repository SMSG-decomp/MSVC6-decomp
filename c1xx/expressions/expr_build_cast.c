c1_node * __cdecl expr_build_cast(c1_u8 op,c1_symbol *type_id,c1_node *node)

{
  c1_node *pcVar1;
  
  if (type_id == (c1_symbol *)0x0) {
    return (c1_node *)0x0;
  }
  if (node == (c1_node *)0x0) {
    return (c1_node *)0x0;
  }
  if (node->op == 0x98) {
    diag_error(0x113,node->left);
    return (c1_node *)0x0;
  }
  if (node->op == 0xe8) {
    node = property_build_access('\x01',node,(c1_node *)0x0);
    if (node == (c1_node *)0x0) {
      return (c1_node *)0x0;
    }
  }
  if (op != 0xde) {
    pcVar1 = conv_convert_cast(op,type_id->type,node);
    return pcVar1;
  }
  pcVar1 = conv_check_named_cast(type_id->type,node);
  return pcVar1;
}

