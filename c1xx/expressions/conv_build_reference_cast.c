c1_node * __thiscall conv_build_reference_cast(c1_conversion *conv,c1_node *dest)

{
  c1_conversion *conv_00;
  c1_node *pcVar1;
  c1_type *type;
  
  pcVar1 = expr_build_address_of(conv->expr,8);
  if (pcVar1 == (c1_node *)0x0) {
    return (c1_node *)0x0;
  }
  conv_00 = conv->first;
  if (conv_00 != (c1_conversion *)0x0) {
    conv_00->expr = pcVar1;
    pcVar1 = conv_apply_conversion(conv_00,(c1_node *)0x0);
    if (pcVar1 == (c1_node *)0x0) {
      return (c1_node *)0x0;
    }
  }
  if (dest != (c1_node *)0x0) {
    pcVar1 = tree_new_init_assign(dest,pcVar1);
  }
  type = type_base(conv->target);
  pcVar1 = tree_new_unary('=',type,pcVar1);
  return pcVar1;
}

