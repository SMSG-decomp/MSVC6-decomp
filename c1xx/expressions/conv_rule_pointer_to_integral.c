void __fastcall conv_rule_pointer_to_integral(c1_conversion *conv)

{
  c1_u8 cVar1;
  uint uVar2;
  
  uVar2 = (uint)conv->target->code;
  if (((uVar2 & 0xfff) == 0x10) && ((conv->mode < 7 || (9 < conv->mode)))) {
    conv->rank = 0x20;
    conv->build = conv_build_to_bool;
    conv->note = 0x17eb;
    conv->flags4f = conv->flags4f | 4;
    return;
  }
  cVar1 = conv->mode;
  if (((cVar1 != '\a') && (cVar1 != '\x04')) && (cVar1 != '\x05')) {
    conv->rank = 0x70;
    conv->note = 0x1787;
    return;
  }
  if (((byte)(&g_type_rank_table)[uVar2 & 0xf] < 4) && (g_ms_extensions == '\0')) {
    conv->rank = 0x70;
    conv->note = 0x1786;
    return;
  }
  conv->rank = 0x50;
  conv->build = conv_apply_standard_conversion;
  conv->note_fn = conv_note_none;
  return;
}

