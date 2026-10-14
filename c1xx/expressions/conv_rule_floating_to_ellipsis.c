void __fastcall conv_rule_floating_to_ellipsis(c1_conversion *conv)

{
  c1_type *pcVar1;
  
  conv->rank = 0x40;
  pcVar1 = g_type_double;
  if (7 < (byte)(&g_type_rank_table)[(byte)conv->source->code & 0xf]) {
    conv->build = conv_build_identity;
    conv->note = 0x17dc;
    return;
  }
  conv->build = conv_apply_standard_conversion;
  conv->target = pcVar1;
  conv->note = 0x17dd;
  return;
}

