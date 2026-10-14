void __fastcall conv_rule_integral_to_floating(c1_conversion *conv)

{
  if ((6 < conv->mode) && (conv->mode < 10)) {
    conv->rank = 0x70;
    conv->note = 0x1773;
    return;
  }
  conv->build = conv_build_integral_to_floating;
  conv->build_constant = conv_build_integral_constant_to_floating;
  conv->rank = 0x20;
  conv->note = 0x17d9;
  return;
}

