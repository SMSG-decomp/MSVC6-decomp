c1_node * __thiscall conv_build_null_member_pointer(c1_conversion *conv,c1_node *dest)

{
  c1_node *value;
  
  value = expr_member_pointer_null_constant(conv->target);
  if (dest != (c1_node *)0x0) {
    value = conv_store_converted_value(conv,dest,value);
  }
  return value;
}

