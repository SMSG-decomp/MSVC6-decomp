void __fastcall conv_rule_array_source(c1_conversion *conv)

{
  c1_u8 cVar1;
  c1_u8 cVar2;
  c1_type *pcVar3;
  int iVar4;
  c1_type *pcVar5;
  c1_conversion *conv_00;
  
  conv_00 = (c1_conversion *)g_arenas[5].cur;
  g_arenas[5].cur = g_arenas[5].cur + 0x50;
  if (g_arenas[5].end < g_arenas[5].cur) {
    arena_grow(g_arenas + 5);
  }
  if (conv_00 == (c1_conversion *)0x0) {
    conv_00 = (c1_conversion *)0x0;
  }
  else {
    pcVar3 = conv->target;
    pcVar5 = type_reference_to(conv->source,'\0');
    cVar1 = conv->mode;
    cVar2 = conv->flags;
    conv_00->op = conv->op;
    *(c1_u8 *)((int)conv_00 + 2) = cVar2;
    *(c1_u8 *)((int)conv_00 + 1) = cVar1;
    *(c1_u8 *)((int)conv_00 + 4) = '\0';
    *(c1_u8 *)((int)conv_00 + 5) = '\0';
    *(c1_u8 *)((int)conv_00 + 6) = '\0';
    *(c1_u8 *)((int)conv_00 + 7) = '\0';
    *(c1_type **)((int)conv_00 + 8) = pcVar5;
    *(c1_type **)((int)conv_00 + 0xc) = pcVar3;
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
    iVar4 = conv_00->rank;
    conv->rank = iVar4;
    conv->build = conv_build_decayed_conversion;
    conv->note = 0x17e3;
    conv->flags4e = conv->flags4e | 0x80;
    if (iVar4 != 0) {
      conv->note_fn = diag_note_followed_by_1;
    }
    if (iVar4 < 2) {
      conv->rank = 2;
      return;
    }
  }
  return;
}

