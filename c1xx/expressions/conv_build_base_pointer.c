c1_node * __thiscall conv_build_base_pointer(c1_conversion *conv,c1_node *dest)

{
  c1_node *value;
  
  value = conv_convert_along_base_path(conv,conv->expr);
  if (dest != (c1_node *)0x0) {
    value = conv_store_converted_value(conv,dest,value);
  }
  return value;
}

