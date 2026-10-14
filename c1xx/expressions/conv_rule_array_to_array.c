void __fastcall conv_rule_array_to_array(c1_conversion *conv)

{
  char cVar1;
  
  cVar1 = type_compare(conv->source,conv->target,0);
  if (cVar1 != '\0') {
    conv->rank = 0;
    conv->build = conv_build_identity;
    conv->note = 0x17d4;
    return;
  }
  conv->rank = 0x70;
  conv->note = 0x1777;
  return;
}

