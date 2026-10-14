void __fastcall conv_rule_floating_to_floating(c1_conversion *conv)

{
  ushort uVar1;
  c1_type *pcVar2;
  c1_type *pcVar3;
  bool bVar4;
  
  if ((6 < conv->mode) && (conv->mode < 10)) {
    conv->rank = 0x70;
    conv->note = 0x1773;
    return;
  }
  pcVar2 = conv->target;
  pcVar3 = conv->source;
  conv->build = conv_warn_possible_loss_of_data_2;
  conv->build_constant = conv_build_floating_constant;
  if (pcVar3 != pcVar2) {
    uVar1 = pcVar3->code;
    if ((uVar1 & 0x300) == 0) {
      if ((uVar1 & 0x800) == 0) {
        if (uVar1 == pcVar2->code) goto LAB_1044dbae;
        goto LAB_1044dbe6;
      }
      if ((pcVar2->code & 0x800) == 0) goto LAB_1044dbe6;
      bVar4 = *(short *)&pcVar3->extra == *(short *)&pcVar2->extra;
    }
    else {
      if ((pcVar2->code & 0x300) == 0) goto LAB_1044dbe6;
      bVar4 = (pcVar3->extra).cls == (pcVar2->extra).cls;
    }
    if (!bVar4) {
LAB_1044dbe6:
      if (((byte)(&g_type_rank_table)[(byte)pcVar3->code & 0xf] < 8) &&
         ((pcVar2->code & 0xfff) == 0x27)) {
        conv->rank = 0x10;
        conv->note = 0x17d6;
        return;
      }
      conv->rank = 0x20;
      conv->note = 0x17d8;
      return;
    }
  }
LAB_1044dbae:
  conv->rank = 0;
  conv->note = 0x17d4;
  return;
}

