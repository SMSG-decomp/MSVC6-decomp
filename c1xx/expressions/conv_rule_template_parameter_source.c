void __fastcall conv_rule_template_parameter_source(c1_conversion *conv)

{
  ushort uVar1;
  
  uVar1 = conv->source->code;
  if ((uVar1 != 0x800) && ((uVar1 < 0x801 || (0x802 < uVar1)))) {
    conv->rank = 0x70;
    conv->note = g_conversion_rules[conv->source_class * 0x10 + conv->target_class].note;
    return;
  }
  conv->rank = 0;
  conv->build = conv_build_template_parameter_operand;
  conv->note = 0x17d4;
  return;
}

