int __cdecl expr_apply_implicit_conversion(c1_node *node)

{
  c1_type *type;
  c1_node *pcVar1;
  
  if (node == (c1_node *)0x0) {
    return 0;
  }
  type = type_promoted_integral(node->type);
  if (type == (c1_type *)0x0) {
    return (int)node;
  }
  pcVar1 = conv_convert_to_type('d',type,node);
  return (int)pcVar1;
}

