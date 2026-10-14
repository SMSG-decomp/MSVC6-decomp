void __fastcall conv_rule_floating_to_integral(c1_conversion *conv)

{
  if ((6 < conv->mode) && (conv->mode < 10)) {
    conv->rank = 0x70;
    conv->note = 0x1773;
    return;
  }
  if ((conv->target->code & 0xfff) != 0x10) {
    conv->build = conv_warn_possible_loss_of_data_3;
    conv->build_constant = conv_build_floating_constant_to_integral;
    conv->rank = 0x20;
    conv->note = 0x17d9;
    return;
  }
  conv->build = conv_build_to_bool;
  conv->rank = 0x20;
  conv->note = 0x17d9;
  return;
}

