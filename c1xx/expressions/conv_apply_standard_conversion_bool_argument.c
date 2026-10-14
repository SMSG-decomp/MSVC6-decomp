c1_node * __cdecl
conv_apply_standard_conversion_bool_argument
          (c1_node *operand,c1_type *target,c1_conversion *conv,c1_node *dest)

{
  c1_node *value;
  byte bVar1;
  
  value = tree_new_unary('d',target,operand);
  bVar1 = (value->flags ^ *(byte *)((int)value->left + 2)) & 1 ^ value->flags;
  value->flags = bVar1;
  value->flags = (bVar1 ^ *(byte *)((int)value->left + 2)) & 4 ^ bVar1;
  if (dest != (c1_node *)0x0) {
    value = conv_store_converted_value(conv,dest,value);
  }
  return value;
}

