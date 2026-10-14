c1_node * __cdecl conv_convert_basic_fragment(c1_u8 op,c1_node *node,c1_type *type)

{
  c1_node *pcVar1;
  
  conv_check_conversion_to_type(op,type,node);
  pcVar1 = tree_new_cast(type,node);
  return pcVar1;
}

