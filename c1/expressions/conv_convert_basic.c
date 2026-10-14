c1_node * __cdecl conv_convert_basic(c1_u8 op,c1_type *type,c1_node *node)

{
  ushort uVar1;
  c1_node *pcVar2;
  
  if (node == (c1_node *)0x0) {
    return (c1_node *)0x0;
  }
  uVar1 = type->flags & 0x18;
  if ((uVar1 == 0x18) || (uVar1 == 8)) {
    pcVar2 = type_based_pointer_from_node(type,node);
    pcVar2 = expr_based_pointer_fixup(pcVar2);
    return pcVar2;
  }
  if ((node->kind & 7) == 3) {
    conv_warn_arithmetic_conversion(op,node,type);
    pcVar2 = fold_float_constant_conversion(op,type,node);
    return pcVar2;
  }
  if ((op != 'd') && (op != '\x01')) {
    pcVar2 = conv_convert_basic_fragment(op,node,type);
    return pcVar2;
  }
  pcVar2 = tree_new_cast(type,node);
  return pcVar2;
}

