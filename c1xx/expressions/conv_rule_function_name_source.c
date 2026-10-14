void __fastcall conv_rule_function_name_source(c1_conversion *conv)

{
  c1_u16 cVar1;
  c1_node *pcVar2;
  uint how;
  
  how = (uint)conv;
  pcVar2 = expr_strip_to_function_ref(conv->expr,&how);
  conv->expr = pcVar2;
  pcVar2 = expr_build_address_of(pcVar2,4);
  if (((pcVar2 != (c1_node *)0x0) && (cVar1 = pcVar2->type->code, cVar1 != 0x80c)) &&
     (cVar1 != 0x80e)) {
    conv->expr = pcVar2;
    conv->source = pcVar2->type;
    conv_compute_conversion(conv);
    return;
  }
  conv->rank = 0x70;
  conv->note = 0x1774;
  return;
}

