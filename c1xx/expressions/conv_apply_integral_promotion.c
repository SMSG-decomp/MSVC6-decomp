int __cdecl conv_apply_integral_promotion(c1_type *type,c1_node *node)

{
  c1_type *target;
  c1_node *pcVar1;
  
  if (node == (c1_node *)0x0) {
    return 0;
  }
  if ((-1 < (char)node->type->code) &&
     (target = conv_integral_promotion_target(type,&node), target != (c1_type *)0x0)) {
    pcVar1 = conv_convert_expression('d',target,node,'\x02','\0');
    return (int)pcVar1;
  }
  return (int)node;
}

