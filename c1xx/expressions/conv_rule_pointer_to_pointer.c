void __fastcall conv_rule_pointer_to_pointer(c1_conversion *conv)

{
  c1_u8 cVar1;
  byte bVar2;
  char cVar3;
  ushort uVar4;
  c1_type *pcVar5;
  c1_type *from;
  code *pcVar6;
  int iVar7;
  int iVar8;
  bool bVar9;
  c1_symbol *pcStack_8;
  c1_symbol *pcStack_4;
  
  cVar1 = conv->mode;
  bVar9 = conv->source_class == 8;
  pcStack_4 = (c1_symbol *)0x0;
  pcStack_8 = (c1_symbol *)0x0;
  conv->rank = 0;
  if (bVar9) {
    uVar4 = conv->source->flags & 0x18;
    if ((uVar4 == 0x18) || (uVar4 == 8)) {
LAB_104971b7:
      conv_based_pointer_conversion(conv);
      return;
    }
    pcVar5 = conv->target;
    uVar4 = pcVar5->flags & 0x18;
    if (((uVar4 == 0x18) || (uVar4 == 8)) ||
       ((conv->expr != (c1_node *)0x0 && (conv->expr->op == ']')))) goto LAB_104971b7;
  }
  else {
    pcVar5 = conv->target;
    uVar4 = pcVar5->code & 0x8f;
    if ((uVar4 == 0x8a) || (uVar4 == 0x8e)) {
      pcStack_4 = (pcVar5->extra).cls;
    }
    else {
      pcStack_4 = (c1_symbol *)0x0;
    }
    uVar4 = conv->source->code & 0x8f;
    if ((uVar4 == 0x8a) || (uVar4 == 0x8e)) {
      pcStack_8 = (conv->source->extra).cls;
    }
    else {
      pcStack_8 = (c1_symbol *)0x0;
    }
  }
  pcVar5 = type_base(pcVar5);
  from = type_base(conv->source);
  if (pcVar5 == from) goto LAB_1042b5ae;
  conv_compare_level_qualifiers(conv,pcVar5,from,'\x01');
  iVar7 = type_category(pcVar5);
  iVar8 = type_category(from);
  if (iVar7 != iVar8) {
    if (bVar9) {
      if (iVar7 == 3) {
        conv->rank = 0x20;
        conv->build = conv_apply_standard_conversion;
        conv->note = 0x17e1;
        if (iVar8 == 6) {
          conv->flags4e = conv->flags4e | 0x20;
        }
      }
      else {
        if (iVar8 != 3) goto LAB_1042b751;
        if ((conv->mode < 4) || (9 < conv->mode)) {
          conv->rank = 0x70;
          conv->note = 0x1781;
        }
        else {
          conv->rank = 0x50;
          conv->build = conv_apply_standard_conversion;
          conv->note_fn = conv_note_none;
        }
      }
      goto LAB_1042b5ae;
    }
    goto LAB_1042b751;
  }
  switch(iVar7) {
  case 2:
  case 3:
  case 4:
    uVar4 = pcVar5->code;
    if ((uVar4 & 0x300) == 0) {
      if ((uVar4 & 0x800) == 0) {
        if (uVar4 == from->code) break;
      }
      else if (((from->code & 0x800) != 0) && (*(short *)&pcVar5->extra == *(short *)&from->extra))
      break;
      goto LAB_1042b751;
    }
    if (((from->code & 0x300) == 0) || ((pcVar5->extra).cls != (from->extra).cls))
    goto LAB_1042b751;
    break;
  case 5:
LAB_104971d3:
    if ((pcVar5->extra).cls != (from->extra).cls) goto LAB_1042b751;
    break;
  case 6:
    if (!bVar9) goto LAB_104971d3;
    pcStack_4 = (from->extra).cls;
    pcStack_8 = (pcVar5->extra).cls;
    break;
  case 8:
  case 10:
  case 0xc:
  case 0xd:
    cVar3 = conv_pointer_levels_dissimilar(conv,pcVar5,from,'\0');
    if (cVar3 != '\0') goto LAB_1042b751;
    break;
  case 9:
    cVar3 = type_compare_member_pointer(pcVar5,from,2);
    goto joined_r0x1042b78b;
  case 0xb:
    cVar3 = type_compare_function(pcVar5,from,0);
joined_r0x1042b78b:
    if (cVar3 != '\0') break;
    goto LAB_1042b751;
  }
LAB_1042b5ae:
  if (cVar1 != '\a') {
    if ((pcStack_4 == (c1_symbol *)0x0) || (pcStack_4 == pcStack_8)) goto LAB_1042b5c6;
    cVar3 = conv_find_base_class_path(conv,pcStack_4,pcStack_8,!bVar9);
    if (cVar3 != '\0') {
      pcVar6 = conv_build_base_pointer;
      if (!bVar9) {
        pcVar6 = conv_build_member_pointer_along_base_path;
      }
      conv->build = pcVar6;
      bVar2 = conv->mode;
      if (((byte)~conv->flags4e & 8) >> 3 == (uint)!bVar9) {
        if ((bVar2 < 4) || (6 < bVar2)) {
          conv->rank = 0x70;
          iVar7 = (-(uint)bVar9 & 0xfffffffa) + 0x1788;
          goto LAB_1042b7f7;
        }
        conv->rank = 0x50;
        conv->note_fn = conv_note_none;
      }
      else if (bVar2 == 8) {
        conv->rank = 0x70;
        conv->note = 0x1784;
      }
      else {
        conv->rank = 0x20;
        iVar7 = (-(uint)bVar9 & 0xfffffffd) + 0x17e5;
LAB_1042b7f7:
        conv->note = iVar7;
      }
LAB_1042b5c6:
      if (conv->mode != '\a') goto LAB_1042b5d0;
    }
  }
LAB_1042b751:
  cVar1 = conv->mode;
  if (((cVar1 == '\a') || (cVar1 == '\x04')) || (cVar1 == '\x05')) {
    if (!bVar9) {
      iVar7 = class_complete_for_use(pcStack_8);
      iVar8 = class_complete_for_use(pcStack_4);
      if (iVar8 != iVar7) {
        conv->rank = 0x70;
        conv->note = 0x1789;
        goto LAB_1042b5d0;
      }
    }
    conv->rank = 0x50;
    conv->build = conv_apply_standard_conversion;
    conv->note_fn = conv_note_none;
    if ((conv->source_class == 0xd) &&
       (cVar3 = conv_function_cast_is_unsafe(conv,from,pcVar5,'\0'), cVar3 != '\0')) {
      diag_warning(3,0xbf,(uint)conv->op,conv->source,conv->target);
    }
  }
  else {
    conv->rank = 0x70;
    conv->note = 0x1780;
  }
LAB_1042b5d0:
  if (((conv->flags4e & 4) == 0) || (conv->rank == 0x70)) {
    if (conv->rank == 0) {
      if ((conv->flags4e & 2) != 0) {
        conv->rank = 1;
        conv->build = conv_apply_standard_conversion;
        conv->note = 0x17e0;
        return;
      }
      conv->build = conv_build_identity;
      conv->note = 0x17d4;
    }
    return;
  }
  if ((conv->rank == 0) &&
     (((cVar1 = conv->mode, cVar1 == '\b' || (cVar1 == '\x04')) || (cVar1 == '\x05')))) {
    conv->rank = 0x50;
    conv->build = conv_apply_standard_conversion;
    conv->note_fn = conv_note_none;
    return;
  }
  if ((conv->mode != '\x04') && (conv->mode != '\x05')) {
    conv->rank = 0x70;
    conv->note = 0x177f;
    return;
  }
  conv->rank = 0x50;
  conv->note_fn = conv_note_none;
  return;
}

