void __cdecl
conv_bind_reference_to_rvalue
          (c1_conversion *conv,c1_type *ref_type,c1_symbol *source_class,char related,
          int ref_category,c1_symbol *ref_class)

{
  c1_u8 cVar1;
  c1_u8 cVar2;
  c1_node *pcVar3;
  char cVar4;
  c1_type *pcVar5;
  c1_conversion *conv_00;
  c1_u16 cStack0000001c;
  c1_u16 cStack0000001e;
  c1_type *pcStack00000020;
  c1_type_extra cStack00000024;
  c1_u32 cStack00000028;
  
  if (related == '\0') {
    if (conv->source_class != ref_category) goto LAB_10415942;
    cVar4 = type_compare(conv->source,ref_type,2);
    if (cVar4 == '\0') goto LAB_10415942;
  }
  conv_compare_level_qualifiers(conv,ref_type,conv->source,'\x01');
  if ((conv->flags4e & 4) != 0) {
    conv_bind_reference_loses_qualifiers(conv);
    return;
  }
LAB_10415942:
  conv_00 = (c1_conversion *)g_arenas[5].cur;
  if (((conv->flags4e & 0x10) == 0) && (related != '\0')) {
    if (source_class == ref_class) {
      conv->rank = 0;
      conv->build = conv_build_bind_class_rvalue;
      conv->note = 0x17e7;
      return;
    }
    conv->rank = 0x20;
    conv->build = conv_build_bind_class_rvalue;
    conv->note = 0x17e7;
    return;
  }
  if ((conv->flags & 0x40) == 0) {
    g_arenas[5].cur = g_arenas[5].cur + 0x50;
    if (g_arenas[5].end < g_arenas[5].cur) {
      arena_grow(g_arenas + 5);
    }
    if (conv_00 == (c1_conversion *)0x0) {
      conv_00 = (c1_conversion *)0x0;
    }
    else {
      cVar1 = conv->mode;
      pcVar3 = conv->expr;
      cVar2 = conv->flags;
      conv_00->op = conv->op;
      *(c1_u8 *)((int)conv_00 + 2) = cVar2;
      *(c1_u8 *)((int)conv_00 + 1) = (cVar1 == '\x03') + '\x02';
      *(c1_node **)((int)conv_00 + 4) = pcVar3;
      if (pcVar3 == (c1_node *)0x0) {
        pcStack00000020 = (c1_type *)0x0;
        cStack00000028 = 0;
        cStack0000001c = 0x80f;
        cStack0000001e = 0;
        cStack00000024.cls = (c1_symbol *)0x0;
        pcVar5 = type_intern((c1_type *)&stack0x0000001c);
        *(c1_type **)((int)conv_00 + 8) = pcVar5;
        *(c1_type **)((int)conv_00 + 0xc) = ref_type;
        conv_compute_conversion(conv_00);
      }
      else {
        *(c1_type **)((int)conv_00 + 8) = pcVar3->type;
        *(c1_type **)((int)conv_00 + 0xc) = ref_type;
        conv_compute_conversion(conv_00);
      }
    }
    conv->first = conv_00;
    if ((conv_00->flags4e & 1) != 0) {
      conv->rank = conv_00->rank;
      conv->build = conv_build_reference_temporary;
      conv->note_fn = diag_note_followed_by_2;
      conv->note = 0x17e7;
      conv->flags4e = conv->flags4e | 0x40;
      return;
    }
    conv->rank = 0x70;
    conv->note_fn = diag_note_conversion_reason;
  }
  else {
    conv->rank = 0x70;
    if (conv->note == 0) {
      conv->note = 0x179b;
      return;
    }
  }
  return;
}

