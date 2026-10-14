void __fastcall conv_rule_integral_to_member_pointer(c1_conversion *conv)

{
  c1_node *pcVar1;
  
  if (conv->expr != (c1_node *)0x0) {
    pcVar1 = fold_static_const_member(conv->expr);
    if ((pcVar1->kind & 0x80) != 0) {
      if (conv->mode < 8) {
        conv->rank = 0x20;
        conv->build = conv_build_null_member_pointer;
        conv->note = 0x17df;
        return;
      }
      conv->rank = 0x70;
      conv->note = 0x177c;
      return;
    }
  }
  conv->rank = 0x70;
  conv->note = 0x177d;
  return;
}

