c1_node * __thiscall conv_build_identity(c1_conversion *conv,c1_node *dest)

{
  c1_node *pcVar1;
  
  pcVar1 = conv->expr;
  if ((pcVar1->type != conv->target) && (conv->target->code != 0x80d)) {
    pcVar1 = conv_apply_standard_conversion(conv,dest);
    return pcVar1;
  }
  if (dest != (c1_node *)0x0) {
    pcVar1 = conv_store_converted_value(conv,dest,pcVar1);
  }
  return pcVar1;
}

