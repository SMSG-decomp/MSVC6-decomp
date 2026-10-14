void __fastcall conv_rule_segment_thunk(c1_conversion *conv)

{
  conv->rank = 0x70;
  conv->note = g_conversion_rules[conv->source_class * 0x10 + conv->target_class].note;
  return;
}

