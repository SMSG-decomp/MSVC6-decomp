c1_node * __thiscall conv_build_based_pointer(c1_conversion *conv,c1_node *dest)

{
  c1_conversion *conv_00;
  c1_node *value;
  ushort uVar1;
  
  conv_00 = conv->first;
  conv_00->expr = conv->expr;
  value = conv_apply_conversion(conv_00,(c1_node *)0x0);
  uVar1 = conv->target->flags & 0x18;
  if ((uVar1 == 0x18) || (uVar1 == 8)) {
    value = type_based_pointer_from_node(conv->target,value);
  }
  if (dest != (c1_node *)0x0) {
    value = conv_store_converted_value(conv,dest,value);
  }
  uVar1 = conv->target->flags & 0x18;
  if (((uVar1 == 0x18) || (uVar1 == 8)) && ((conv->flags & 4) == 0)) {
    value = expr_based_pointer_fixup(value);
  }
  return value;
}

