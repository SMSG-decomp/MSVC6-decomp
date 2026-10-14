int __cdecl conv_promote_operand(c1_type *type,c1_node *node)

{
  c1_type *type_00;
  c1_node *pcVar1;
  
  if (node == (c1_node *)0x0) {
    return 0;
  }
  if ((-1 < (char)node->type->code) &&
     (type_00 = conv_arithmetic_result_type(type,&node), type_00 != (c1_type *)0x0)) {
    pcVar1 = conv_convert_to_type('d',type_00,node);
    return (int)pcVar1;
  }
  return (int)node;
}

