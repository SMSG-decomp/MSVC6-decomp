void __fastcall conv_rule_member_pointer_to_integral(c1_conversion *conv)

{
  if ((conv->target->code & 0xfff) == 0x10) {
    conv->rank = 0x20;
    conv->build = conv_build_member_pointer_to_bool;
    conv->note = 0x17eb;
    conv->flags4f = conv->flags4f | 4;
    return;
  }
  conv->rank = 0x70;
  conv->note = 0x1773;
  return;
}

