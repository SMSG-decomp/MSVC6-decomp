void __fastcall conv_bind_reference(c1_conversion *conv)

{
  byte bVar1;
  c1_u8 cVar2;
  c1_u8 cVar3;
  char cVar4;
  c1_type *type;
  int iVar5;
  c1_node *pcVar6;
  c1_type *pcVar7;
  c1_symbol *source_class;
  c1_conversion *conv_00;
  bool bVar8;
  char related;
  int ref_category;
  c1_symbol *target_class;
  c1_type error_type;
  
  bVar8 = false;
  type = type_base(conv->target);
  iVar5 = type_category(type);
  ref_category = iVar5;
  if ((conv->expr != (c1_node *)0x0) && ((conv->flags4e & 0x10) == 0)) {
    if (conv->source_class == 9) {
      conv->flags4e = conv->flags4e | 0x10;
    }
    else {
      pcVar6 = expr_lvalue_address(conv->expr,0);
      if ((pcVar6 != (c1_node *)0x0) && (pcVar6->op != '5')) {
        conv->flags4e = conv->flags4e | 0x10;
      }
    }
  }
  source_class = (c1_symbol *)0x0;
  related = '\0';
  target_class = (c1_symbol *)0x0;
  if ((conv->source_class == 6) && (iVar5 == 6)) {
    source_class = (conv->source->extra).cls;
    target_class = (type->extra).cls;
    if ((source_class == target_class) ||
       (cVar4 = conv_find_base_class_path(conv,source_class,target_class,'\0'), cVar4 != '\0')) {
      related = '\x01';
    }
  }
  if ((conv->flags4e & 0x10) != 0) {
    iVar5 = conv->source_class;
    if (iVar5 == 6) {
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
        bVar8 = conv->note == 0x179a;
        conv->note = 0;
        conv->note_fn = (void *)0x0;
        conv->first = (c1_conversion *)0x0;
        conv->second = (c1_conversion *)0x0;
        if ((bVar1 >> 6 & 1) == 0) {
          conv->flags = conv->flags & 0xbf;
        }
      }
    }
    else if ((iVar5 == 8) || (iVar5 == 0xc)) {
      if ((iVar5 == ref_category) &&
         (cVar4 = conv_pointer_levels_dissimilar(conv,type,conv->source,'\x01'), cVar4 == '\0'))
      goto LAB_104156a6;
    }
    else if ((iVar5 == ref_category) && (cVar4 = type_compare(conv->source,type,2), cVar4 != '\0'))
    {
LAB_104156a6:
      if (((conv->mode != '\x04') && (conv->mode != '\x05')) &&
         (conv_compare_level_qualifiers(conv,type,conv->source,'\x01'), (conv->flags4e & 4) != 0)) {
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
  pcVar7 = type;
  if ((type->code & 0x8f) == 0x83) {
    pcVar7 = type_skip_arrays(type->base);
  }
  if (((pcVar7->flags & 0x60) == 0x20) || ((conv->flags & 0xa0) == 0xa0)) {
    if (((related != '\0') ||
        ((conv->source_class == ref_category &&
         (cVar4 = type_compare(conv->source,type,2), cVar4 != '\0')))) &&
       (conv_compare_level_qualifiers(conv,type,conv->source,'\x01'), (conv->flags4e & 4) != 0)) {
      conv_bind_reference_loses_qualifiers(conv);
      return;
    }
    conv_00 = (c1_conversion *)g_arenas[5].cur;
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
      if (conv_00 == (c1_conversion *)0x0) {
        conv_00 = (c1_conversion *)0x0;
      }
      else {
        cVar2 = conv->mode;
        pcVar6 = conv->expr;
        cVar3 = conv->flags;
        conv_00->op = conv->op;
        *(c1_u8 *)((int)conv_00 + 2) = cVar3;
        *(c1_u8 *)((int)conv_00 + 1) = (cVar2 == '\x03') + '\x02';
        *(c1_node **)((int)conv_00 + 4) = pcVar6;
        if (pcVar6 == (c1_node *)0x0) {
          error_type.base = (c1_type *)0x0;
          error_type.debug_index = 0;
          error_type.code = 0x80f;
          error_type.flags = 0;
          error_type.extra.cls = (c1_symbol *)0x0;
          pcVar7 = type_intern(&error_type);
          *(c1_type **)((int)conv_00 + 8) = pcVar7;
          *(c1_type **)((int)conv_00 + 0xc) = type;
          conv_compute_conversion(conv_00);
        }
        else {
          *(c1_type **)((int)conv_00 + 8) = pcVar6->type;
          *(c1_type **)((int)conv_00 + 0xc) = type;
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
  }
  else {
    if (g_ms_extensions != '\0') {
      if (related != '\0') {
LAB_10496fa0:
        conv->extension_note = 0x1794;
        conv_bind_reference_to_rvalue(conv,type,source_class,related,ref_category,target_class);
        return;
      }
      pcVar7 = type;
      if ((type->code & 0x8f) == 0x83) {
        pcVar7 = type_skip_arrays(type->base);
      }
      if (((byte)pcVar7->flags >> 5 & 1) != 0) goto LAB_10496fa0;
    }
    conv->rank = 0x70;
    conv->note = 0x1794;
    if (bVar8) {
      conv->note = 0x179a;
      return;
    }
  }
  return;
}

