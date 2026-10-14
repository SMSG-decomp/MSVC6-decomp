void __fastcall conv_rule_integral_to_pointer(c1_conversion *conv)

{
  c1_u8 cVar1;
  ushort uVar2;
  c1_node *pcVar3;
  
  if (conv->expr != (c1_node *)0x0) {
    pcVar3 = fold_static_const_member(conv->expr);
    if ((pcVar3->kind & 0x80) != 0) {
      if (conv->mode < 8) {
        conv->rank = 0x20;
        conv->build = conv_build_null_pointer;
        conv->note = 0x17de;
        return;
      }
      conv->rank = 0x70;
      conv->note = 0x177a;
      return;
    }
  }
  cVar1 = conv->mode;
  if (((cVar1 != '\a') && (cVar1 != '\x04')) && (cVar1 != '\x05')) {
    conv->rank = 0x70;
    conv->note = 0x177b;
    return;
  }
  conv->rank = 0x50;
  uVar2 = conv->target->flags & 0x18;
  if ((uVar2 != 0x18) && (uVar2 != 8)) {
    conv->build = conv_apply_standard_conversion;
    conv->note_fn = conv_note_none;
    return;
  }
  conv->build = conv_build_integral_to_based_pointer;
  conv->note_fn = conv_note_none;
  return;
}

