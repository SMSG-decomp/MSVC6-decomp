void __fastcall conv_based_pointer_conversion(c1_conversion *conv)

{
  c1_u8 cVar1;
  c1_u8 cVar2;
  byte bVar3;
  c1_node *pcVar4;
  c1_type *pcVar5;
  c1_type *pcVar6;
  c1_symbol *pcVar7;
  c1_symbol *pcVar8;
  c1_conversion *conv_00;
  
  pcVar4 = conv->expr;
  if ((pcVar4 != (c1_node *)0x0) && (pcVar4->op == ']')) {
    conv->source = *(c1_type **)((int)pcVar4->left + 4);
  }
  conv_00 = (c1_conversion *)g_arenas[5].cur;
  g_arenas[5].cur = g_arenas[5].cur + 0x50;
  if (g_arenas[5].end < g_arenas[5].cur) {
    arena_grow(g_arenas + 5);
  }
  if (conv_00 == (c1_conversion *)0x0) {
    conv_00 = (c1_conversion *)0x0;
  }
  else {
    pcVar5 = type_strip_based(conv->target);
    pcVar6 = type_strip_based(conv->source);
    cVar1 = conv->mode;
    cVar2 = conv->flags;
    conv_00->op = conv->op;
    *(c1_u8 *)((int)conv_00 + 2) = cVar2;
    *(c1_u8 *)((int)conv_00 + 1) = cVar1;
    *(c1_u8 *)((int)conv_00 + 4) = '\0';
    *(c1_u8 *)((int)conv_00 + 5) = '\0';
    *(c1_u8 *)((int)conv_00 + 6) = '\0';
    *(c1_u8 *)((int)conv_00 + 7) = '\0';
    *(c1_type **)((int)conv_00 + 8) = pcVar6;
    *(c1_type **)((int)conv_00 + 0xc) = pcVar5;
    conv_compute_conversion(conv_00);
  }
  conv->first = conv_00;
  if ((conv_00->flags4e & 1) == 0) {
    conv->rank = 0x70;
    if (conv_00->note_fn != (void *)0x0) {
      conv->note_fn = diag_note_conversion_reason;
    }
    conv->note = conv_00->note;
  }
  else {
    if ((conv->source->flags & 0x18) == 0x18) {
      pcVar8 = (conv->source->extra).cls;
    }
    else {
      pcVar8 = (c1_symbol *)0x0;
    }
    if ((conv->target->flags & 0x18) == 0x18) {
      pcVar7 = (conv->target->extra).cls;
    }
    else {
      pcVar7 = (c1_symbol *)0x0;
    }
    conv->rank = conv_00->rank;
    bVar3 = conv->mode;
    if (bVar3 == 7) {
      conv->build = conv_apply_standard_conversion;
    }
    else {
      conv->build = conv_build_based_pointer;
    }
    if ((bVar3 == 8) && (pcVar8 != pcVar7)) {
      conv->rank = 0x70;
      conv->note = 0x1784;
      return;
    }
    if (pcVar8 == (c1_symbol *)0x0) {
      if ((3 < bVar3) && (bVar3 < 10)) {
        conv->rank = 0x50;
        conv->note_fn = conv_note_none;
        return;
      }
      conv->rank = 0x70;
      conv->note = 0x1783;
      return;
    }
    if ((pcVar7 == (c1_symbol *)0x0) && (conv->rank < 0x20)) {
      conv->rank = 0x20;
      return;
    }
  }
  return;
}

