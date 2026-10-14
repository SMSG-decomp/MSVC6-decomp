void __fastcall conv_rule_pointer4086_to_reference84(c1_conversion *conv)

{
  c1_u16 cVar1;
  c1_type *pcVar2;
  
  cVar1 = conv->source->code;
  if ((((byte)cVar1 & 0x8f) == 0x86) && (cVar1 == 0x4086)) {
    pcVar2 = type_base(conv->source);
    conv->source = pcVar2;
    conv->flags4e = conv->flags4e | 0x10;
    conv->source_class = 0xb;
    conv_rule_reference_target(conv);
    return;
  }
  conv_rule_impossible(conv);
  return;
}

