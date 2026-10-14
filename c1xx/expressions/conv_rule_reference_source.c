void __fastcall conv_rule_reference_source(c1_conversion *conv)

{
  c1_type *pcVar1;
  
  conv->flags4e = conv->flags4e | 0x10;
  pcVar1 = type_base(conv->source);
  conv->source = pcVar1;
  conv_compute_conversion(conv);
  return;
}

