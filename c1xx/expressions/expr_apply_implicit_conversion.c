int __cdecl expr_apply_implicit_conversion(c1_node *node)

{
  c1_type *target;
  c1_node *pcVar1;
  
  if (node == (c1_node *)0x0) {
    return 0;
  }
  target = type_promoted_integral(node->type);
  if (target == (c1_type *)0x0) {
    return (int)node;
  }
  pcVar1 = conv_convert_expression('d',target,node,'\x02','\0');
  return (int)pcVar1;
}

