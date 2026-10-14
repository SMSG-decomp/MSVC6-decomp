c1_node * __thiscall conv_build_base_reference(c1_conversion *conv,c1_node *dest)

{
  c1_node *pcVar1;
  c1_type *type;
  
  pcVar1 = expr_build_address_of(conv->expr,8);
  if (pcVar1 == (c1_node *)0x0) {
    return (c1_node *)0x0;
  }
  pcVar1 = conv_convert_along_base_path(conv,pcVar1);
  if (pcVar1 == (c1_node *)0x0) {
    return (c1_node *)0x0;
  }
  if (dest != (c1_node *)0x0) {
    pcVar1 = tree_new_init_assign(dest,pcVar1);
  }
  if ((conv->flags & 4) == 0) {
    type = conv->target;
    if ((char)type->code < '\0') {
      type = type_base(type);
    }
    pcVar1 = tree_new_unary('=',type,pcVar1);
  }
  return pcVar1;
}

