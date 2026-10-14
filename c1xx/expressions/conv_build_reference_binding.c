c1_node * __thiscall conv_build_reference_binding(c1_conversion *conv,c1_node *dest)

{
  c1_type *pcVar1;
  c1_node *pcVar2;
  c1_type *pcVar3;
  
  pcVar1 = type_base(conv->target);
  pcVar2 = expr_build_address_of(conv->expr,8);
  if (dest != (c1_node *)0x0) {
    pcVar2 = tree_new_init_assign(dest,pcVar2);
    return pcVar2;
  }
  if ((pcVar1->code & 0x83) == 0x81) {
    pcVar1 = type_member_pointer_to_2(pcVar1,'\x01');
    pcVar2->type = pcVar1;
  }
  else {
    pcVar3 = type_pointer_with_qualifiers(pcVar1,0);
    pcVar2->type = pcVar3;
    if ((conv->flags & 4) == 0) {
      pcVar2 = tree_new_unary('=',pcVar1,pcVar2);
      return pcVar2;
    }
  }
  return pcVar2;
}

