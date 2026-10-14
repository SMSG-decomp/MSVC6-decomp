void __fastcall conv_rule_integral_to_enum(c1_conversion *conv)

{
  byte bVar1;
  
  if (((conv->source->code & 0x100) != 0) &&
     ((conv->source->extra).cls == (conv->target->extra).cls)) {
    conv->rank = 0;
    conv->build = conv_build_identity;
    conv->note = 0x17d4;
    return;
  }
  bVar1 = conv->mode;
  if ((3 < bVar1) && (bVar1 < 7)) {
    conv->rank = 0x50;
    conv->note_fn = conv_note_none;
    conv->build = conv_apply_standard_conversion;
    conv->build_constant = conv_build_integral_constant;
    return;
  }
  if ((((g_ms_extensions == '\0') || (bVar1 != 2)) || ((conv->flags & 0x10) == 0)) &&
     (g_opt_int2enum == '\0')) {
    conv->rank = 0x70;
    conv->note = 0x1779;
    conv->build = conv_apply_standard_conversion;
    conv->build_constant = conv_build_integral_constant;
    return;
  }
  conv->rank = 0x20;
  conv->extension_note = 0x17a0;
  conv->build = conv_apply_standard_conversion;
  conv->build_constant = conv_build_integral_constant;
  return;
}

