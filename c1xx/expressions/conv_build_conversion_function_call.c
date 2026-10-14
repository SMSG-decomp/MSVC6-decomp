c1_node * __thiscall conv_build_conversion_function_call(c1_conversion *conv,c1_node *dest)

{
  c1_conversion *pcVar1;
  int iVar2;
  char cVar3;
  c1_node *pcVar4;
  
  if (dest == (c1_node *)0x0) {
    cVar3 = conv_constructor_ice_check(conv,conv->second);
    if (cVar3 != '\0') {
      pcVar4 = conv_build_class_argument_in_slot(conv);
      return pcVar4;
    }
  }
  pcVar4 = expr_build_address_of(conv->expr,2);
  pcVar1 = conv->first;
  pcVar1->expr = pcVar4;
  pcVar4 = conv_apply_conversion(pcVar1,(c1_node *)0x0);
  if (pcVar4 != (c1_node *)0x0) {
    class_redeclare_member_with_access((int)conv->via,(int)conv->source);
    pcVar4 = expr_build_call_node((conv->via).function,pcVar4,0,0,0,0);
    if (pcVar4 != (c1_node *)0x0) {
      pcVar1 = conv->second;
      iVar2 = conv->target_kind;
      pcVar1->target_symbol = conv->target_symbol;
      pcVar1->target_kind = iVar2;
      pcVar1 = conv->second;
      pcVar1->expr = pcVar4;
      pcVar4 = conv_apply_conversion(pcVar1,dest);
      return pcVar4;
    }
    return (c1_node *)0x0;
  }
  return (c1_node *)0x0;
}

