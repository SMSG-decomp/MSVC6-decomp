c1_node * __thiscall conv_build_member_pointer_to_bool(c1_conversion *conv,c1_node *dest)

{
  c1_node *right;
  c1_node *node;
  c1_node *value;
  
  right = expr_member_pointer_null_constant(conv->source);
  node = tree_new_node('L',conv->expr,right,conv->target);
  value = expr_expand_member_pointer_compare(node);
  if (value == node) {
    value = fold_binary_constants(node,conv->expr,right);
  }
  if (dest != (c1_node *)0x0) {
    value = conv_store_converted_value(conv,dest,value);
  }
  return value;
}

