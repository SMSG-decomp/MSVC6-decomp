void __fastcall conv_rule_compound_to_ellipsis(c1_conversion *conv)

{
  conv->rank = 0x40;
  conv->build = conv_build_identity;
  conv->note = 0x17dc;
  return;
}

