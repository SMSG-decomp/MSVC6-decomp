void __fastcall conv_rule_function_source(c1_conversion *conv)

{
  c1_u8 cVar1;
  c1_u8 cVar2;
  int iVar3;
  c1_type *pcVar4;
  c1_type *pcVar5;
  c1_conversion *conv_00;
  c1_type cStack_10;
  
  conv_00 = (c1_conversion *)g_arenas[5].cur;
  if (((conv->source->code & 0x8f) == 0x85) && ((((conv->source->extra).cls)->flags5 & 1) == 0)) {
    cStack_10.code = 0x80c;
    cStack_10.base = (c1_type *)0x0;
    cStack_10.debug_index = 0;
    cStack_10.flags = 0;
    cStack_10.extra.cls = (c1_symbol *)0x0;
    pcVar4 = type_intern(&cStack_10);
    conv->expr->type = pcVar4;
    conv->source = conv->expr->type;
    conv_rule_function_name_to_pointer(conv);
    return;
  }
  g_arenas[5].cur = g_arenas[5].cur + 0x50;
  if (g_arenas[5].end < g_arenas[5].cur) {
    arena_grow(g_arenas + 5);
  }
  if (conv_00 == (c1_conversion *)0x0) {
    conv_00 = (c1_conversion *)0x0;
  }
  else {
    pcVar4 = conv->target;
    pcVar5 = type_member_pointer_to_2(conv->source,'\x01');
    cVar1 = conv->mode;
    cVar2 = conv->op;
    *(c1_u8 *)((int)conv_00 + 2) = conv->flags;
    conv_00->op = cVar2;
    *(c1_u8 *)((int)conv_00 + 1) = cVar1;
    *(c1_u8 *)((int)conv_00 + 4) = '\0';
    *(c1_u8 *)((int)conv_00 + 5) = '\0';
    *(c1_u8 *)((int)conv_00 + 6) = '\0';
    *(c1_u8 *)((int)conv_00 + 7) = '\0';
    *(c1_type **)((int)conv_00 + 8) = pcVar5;
    *(c1_type **)((int)conv_00 + 0xc) = pcVar4;
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
    iVar3 = conv_00->rank;
    conv->rank = iVar3;
    conv->build = conv_build_decayed_conversion;
    conv->note = 0x17e4;
    conv->flags4e = conv->flags4e | 0x80;
    if (iVar3 != 0) {
      conv->note_fn = diag_note_followed_by_1;
    }
    if (iVar3 < 2) {
      conv->rank = 2;
      return;
    }
  }
  return;
}

