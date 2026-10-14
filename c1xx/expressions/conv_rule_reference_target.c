void __fastcall conv_rule_reference_target(c1_conversion *conv)

{
  byte bVar1;
  c1_u8 cVar2;
  c1_u8 cVar3;
  char cVar4;
  c1_type *pcVar5;
  int iVar6;
  c1_node *pcVar7;
  c1_type *pcVar8;
  c1_symbol *source_class;
  c1_conversion *pcVar9;
  bool bVar10;
  char related;
  int ref_category;
  c1_symbol *target_class;
  
  if ((3 < conv->mode) && (conv->mode < 10)) {
    if ((3 < conv->mode) && (conv->mode < 7)) {
      conv_bind_reference(conv);
      if (conv->rank != 0x70) {
        return;
      }
      if (conv->mode == '\x06') {
        conv->rank = 0x70;
        conv->note = 0x1793;
        return;
      }
    }
    pcVar5 = type_base(conv->target);
    pcVar5 = type_pointer_with_qualifiers(pcVar5,0);
    pcVar8 = type_pointer_with_qualifiers(conv->source,0);
    pcVar9 = (c1_conversion *)g_arenas[5].cur;
    g_arenas[5].cur = g_arenas[5].cur + 0x50;
    if (g_arenas[5].end < g_arenas[5].cur) {
      arena_grow(g_arenas + 5);
    }
    if (pcVar9 == (c1_conversion *)0x0) {
      pcVar9 = (c1_conversion *)0x0;
    }
    else {
      cVar2 = conv->flags;
      cVar3 = conv->op;
      *(c1_u8 *)((int)pcVar9 + 1) = conv->mode;
      pcVar9->op = cVar3;
      *(c1_u8 *)((int)pcVar9 + 2) = cVar2;
      *(c1_u8 *)((int)pcVar9 + 4) = '\0';
      *(c1_u8 *)((int)pcVar9 + 5) = '\0';
      *(c1_u8 *)((int)pcVar9 + 6) = '\0';
      *(c1_u8 *)((int)pcVar9 + 7) = '\0';
      *(c1_type **)((int)pcVar9 + 8) = pcVar8;
      *(c1_type **)((int)pcVar9 + 0xc) = pcVar5;
      conv_compute_conversion(pcVar9);
    }
    conv->first = pcVar9;
    if ((pcVar9->flags4e & 1) == 0) {
      conv->rank = 0x70;
      conv->note_fn = diag_note_conversion_reason;
      conv_rule_reference_target_return();
      return;
    }
    conv->rank = 0x50;
    conv->build = conv_build_reference_cast;
    conv->note_fn = conv_note_none;
    return;
  }
  bVar10 = false;
  pcVar5 = type_base(conv->target);
  iVar6 = type_category(pcVar5);
  ref_category = iVar6;
  if ((conv->expr != (c1_node *)0x0) && ((conv->flags4e & 0x10) == 0)) {
    if (conv->source_class == 9) {
      conv->flags4e = conv->flags4e | 0x10;
    }
    else {
      pcVar7 = expr_lvalue_address(conv->expr,0);
      if ((pcVar7 != (c1_node *)0x0) && (pcVar7->op != '5')) {
        conv->flags4e = conv->flags4e | 0x10;
      }
    }
  }
  source_class = (c1_symbol *)0x0;
  related = '\0';
  target_class = (c1_symbol *)0x0;
  if ((conv->source_class == 6) && (iVar6 == 6)) {
    source_class = (conv->source->extra).cls;
    target_class = (pcVar5->extra).cls;
    if ((source_class == target_class) ||
       (cVar4 = conv_find_base_class_path(conv,source_class,target_class,'\0'), cVar4 != '\0')) {
      related = '\x01';
    }
  }
  if ((conv->flags4e & 0x10) != 0) {
    iVar6 = conv->source_class;
    if (iVar6 == 6) {
      if (related != '\0') {
        if (source_class != target_class) {
          conv->rank = 0x20;
          conv->build = conv_build_base_reference;
          conv->note = 0x17e7;
        }
        goto LAB_104156a6;
      }
      bVar1 = conv->flags;
      if ((bVar1 & 0x20) == 0) {
        conv->flags = bVar1 | 0x40;
        conv_rule_conversion_function(conv);
        if (conv->rank != 0x70) {
          return;
        }
        bVar10 = conv->note == 0x179a;
        conv->note = 0;
        conv->note_fn = (void *)0x0;
        conv->first = (c1_conversion *)0x0;
        conv->second = (c1_conversion *)0x0;
        if ((bVar1 >> 6 & 1) == 0) {
          conv->flags = conv->flags & 0xbf;
        }
      }
    }
    else if ((iVar6 == 8) || (iVar6 == 0xc)) {
      if ((iVar6 == ref_category) &&
         (cVar4 = conv_pointer_levels_dissimilar(conv,pcVar5,conv->source,'\x01'), cVar4 == '\0'))
      goto LAB_104156a6;
    }
    else if ((iVar6 == ref_category) && (cVar4 = type_compare(conv->source,pcVar5,2), cVar4 != '\0')
            ) {
LAB_104156a6:
      if (((conv->mode != '\x04') && (conv->mode != '\x05')) &&
         (conv_compare_level_qualifiers(conv,pcVar5,conv->source,'\x01'), (conv->flags4e & 4) != 0))
      {
        conv->rank = 0x70;
        conv->build = (void *)0x0;
        conv->note_fn = (void *)0x0;
        conv->note = 0x177f;
        return;
      }
      if (conv->build != (void *)0x0) {
        return;
      }
      if ((conv->flags4e & 2) != 0) {
        conv->rank = 1;
        conv->note = 0x17e8;
        conv->build = conv_build_reference_binding;
        return;
      }
      conv->rank = 0;
      conv->note = 0x17e7;
      conv->build = conv_build_reference_binding;
      return;
    }
  }
  pcVar8 = pcVar5;
  if ((pcVar5->code & 0x8f) == 0x83) {
    pcVar8 = type_skip_arrays(pcVar5->base);
  }
  if (((pcVar8->flags & 0x60) == 0x20) || ((conv->flags & 0xa0) == 0xa0)) {
    if (((related != '\0') ||
        ((conv->source_class == ref_category &&
         (cVar4 = type_compare(conv->source,pcVar5,2), cVar4 != '\0')))) &&
       (conv_compare_level_qualifiers(conv,pcVar5,conv->source,'\x01'), (conv->flags4e & 4) != 0)) {
      conv_bind_reference_loses_qualifiers(conv);
      return;
    }
    pcVar9 = (c1_conversion *)g_arenas[5].cur;
    if (((conv->flags4e & 0x10) == 0) && (related != '\0')) {
      if (source_class != target_class) {
        conv->rank = 0x20;
        conv->build = conv_build_bind_class_rvalue;
        conv->note = 0x17e7;
        return;
      }
      conv->rank = 0;
      conv->build = conv_build_bind_class_rvalue;
      conv->note = 0x17e7;
      return;
    }
    if ((conv->flags & 0x40) == 0) {
      g_arenas[5].cur = g_arenas[5].cur + 0x50;
      if (g_arenas[5].end < g_arenas[5].cur) {
        arena_grow(g_arenas + 5);
      }
      if (pcVar9 == (c1_conversion *)0x0) {
        pcVar9 = (c1_conversion *)0x0;
      }
      else {
        cVar2 = conv->mode;
        pcVar7 = conv->expr;
        cVar3 = conv->flags;
        pcVar9->op = conv->op;
        *(c1_u8 *)((int)pcVar9 + 2) = cVar3;
        *(c1_u8 *)((int)pcVar9 + 1) = (cVar2 == '\x03') + '\x02';
        *(c1_node **)((int)pcVar9 + 4) = pcVar7;
        if (pcVar7 == (c1_node *)0x0) {
          pcVar8 = type_intern((c1_type *)&stack0xfffffff0);
          *(c1_type **)((int)pcVar9 + 8) = pcVar8;
          *(c1_type **)((int)pcVar9 + 0xc) = pcVar5;
          conv_compute_conversion(pcVar9);
        }
        else {
          *(c1_type **)((int)pcVar9 + 8) = pcVar7->type;
          *(c1_type **)((int)pcVar9 + 0xc) = pcVar5;
          conv_compute_conversion(pcVar9);
        }
      }
      conv->first = pcVar9;
      if ((pcVar9->flags4e & 1) != 0) {
        conv->rank = pcVar9->rank;
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
  }
  else {
    if (g_ms_extensions != '\0') {
      if (related != '\0') {
LAB_10496fa0:
        conv->extension_note = 0x1794;
        conv_bind_reference_to_rvalue(conv,pcVar5,source_class,related,ref_category,target_class);
        return;
      }
      pcVar8 = pcVar5;
      if ((pcVar5->code & 0x8f) == 0x83) {
        pcVar8 = type_skip_arrays(pcVar5->base);
      }
      if (((byte)pcVar8->flags >> 5 & 1) != 0) goto LAB_10496fa0;
    }
    conv->rank = 0x70;
    conv->note = 0x1794;
    if (bVar10) {
      conv->note = 0x179a;
      return;
    }
  }
  return;
}

