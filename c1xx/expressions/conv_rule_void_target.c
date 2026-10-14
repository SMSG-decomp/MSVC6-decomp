void __fastcall conv_rule_void_target(c1_conversion *conv)

{
  if ((6 < conv->mode) && (conv->mode < 10)) {
    conv->rank = 0x70;
    conv->note = 0x1771;
    return;
  }
  conv->rank = 0x50;
  conv->build = conv_apply_standard_conversion;
  conv->note_fn = conv_note_none;
  return;
}

