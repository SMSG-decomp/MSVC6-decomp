void __fastcall conv_rule_integral_to_ellipsis(c1_conversion *conv)

{
  c1_type *pcVar1;
  
  conv->rank = 0x40;
  pcVar1 = type_promoted_integral(conv->source);
  if (pcVar1 != g_type_int) {
    conv->build = conv_build_identity;
    conv->note = 0x17dc;
    return;
  }
  conv->target = g_type_int;
  conv->build = conv_apply_standard_conversion;
  conv->build_constant = conv_build_integral_constant;
  conv->note = 0x17db;
  return;
}

