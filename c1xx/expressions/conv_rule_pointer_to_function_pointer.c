void __fastcall conv_rule_pointer_to_function_pointer(c1_conversion *conv)

{
  c1_u8 cVar1;
  ushort uVar2;
  c1_type *pcVar3;
  
  if (g_ms_extensions != '\0') {
    uVar2 = conv->source->flags & 0x18;
    if ((uVar2 == 0x18) || (uVar2 == 8)) {
      conv_based_pointer_conversion(conv);
      return;
    }
    cVar1 = conv->mode;
    if (((cVar1 != '\a') && (cVar1 != '\x04')) && (cVar1 != '\x05')) {
      pcVar3 = type_base(conv->source);
      if (((byte)pcVar3->code >> 6 & 1) == 0) goto LAB_10427088;
      if ((conv->mode < 4) || (6 < conv->mode)) {
        conv->rank = 0x70;
        conv->note = 0x1781;
        return;
      }
    }
    conv->rank = 0x50;
    conv->build = conv_apply_standard_conversion;
    conv->note_fn = conv_note_none;
    return;
  }
LAB_10427088:
  conv->rank = 0x70;
  conv->note = 0x1777;
  return;
}

