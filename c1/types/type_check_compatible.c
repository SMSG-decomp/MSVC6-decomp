int __cdecl type_check_compatible(c1_u8 op,c1_type *to,c1_type *from)

{
  ushort uVar1;
  c1_type *pcVar2;
  c1_param_list *pcVar3;
  c1_param_list *pcVar4;
  c1_type *type2;
  bool bVar5;
  bool bVar6;
  byte bVar7;
  byte bVar8;
  char cVar9;
  c1_u8 cVar10;
  int iVar11;
  c1_symbol *pcVar12;
  int iVar13;
  byte bVar14;
  c1_u16 cVar15;
  c1_type *to_layer;
  char cVar16;
  c1_type *from_layer;
  c1_type *pcVar17;
  c1_type **ppcVar18;
  ushort uVar19;
  c1_u16 quals_to;
  c1_symbol *pcVar20;
  c1_u16 quals_from;
  c1_type **ppcVar21;
  int iVar22;
  c1_type *pcVar23;
  int local_1c;
  c1_u16 mods_from;
  c1_u16 mods_to;
  
  if (to == from) {
    return 1;
  }
  bVar8 = (byte)to->code;
  if (((to->code & 0x30) != 0) && ((from->code & 0x130) != 0)) {
    return 1;
  }
  bVar6 = false;
  local_1c = 1;
  pcVar23 = to;
  bVar7 = bVar8;
  while ((char)bVar7 < '\0') {
    pcVar23 = pcVar23->base;
    bVar7 = (byte)pcVar23->code;
  }
  bVar14 = (byte)from->code;
  pcVar2 = from;
  bVar7 = bVar14;
  while ((char)bVar7 < '\0') {
    pcVar2 = pcVar2->base;
    bVar7 = (byte)pcVar2->code;
  }
  if (((bVar8 & 0x8f) == 0x82) && (((byte)to->base->code >> 6 & 1) != 0)) {
    cVar16 = '\x01';
  }
  else {
    cVar16 = '\0';
  }
  if (((bVar14 & 0x8f) == 0x82) && (((byte)from->base->code >> 6 & 1) != 0)) {
    cVar9 = '\x01';
  }
  else {
    cVar9 = '\0';
  }
  if (cVar9 != cVar16) {
    pcVar17 = from;
    if (cVar16 == '\0') {
      pcVar17 = to;
    }
    uVar19 = pcVar17->code & 0x8f;
    if (((uVar19 == 0x83) || (uVar19 == 0x82)) || (uVar19 == 0x86)) {
      switch((uint)op) {
      case 0x34:
      case 0x70:
      case 0x74:
      case 0x7d:
        if (uVar19 == 0x86) {
          conv_warn_function_data_pointer();
        }
        if (((pcVar23->code & 0xfff) == 0x11) || (((byte)pcVar23->code >> 6 & 1) != 0)) {
          iVar11 = 1;
        }
        else {
          iVar11 = 0;
        }
        iVar11 = conv_warn_different_qualifiers(op,pcVar23->flags,pcVar2->flags,1,iVar11);
        if (iVar11 == 0) {
          return 0;
        }
switchD_1061acb2_caseD_3b:
        uVar19 = to->flags & 0x18;
        if (((uVar19 != 0x18) && (uVar19 != 8)) &&
           ((uVar19 = from->flags & 0x18, uVar19 != 0x18 && (uVar19 != 8)))) {
          return 1;
        }
        conv_warn_different_bases(op,to,from);
        return 1;
      default:
        return 1;
      case 0x3b:
      case 0x4c:
        goto switchD_1061acb2_caseD_3b;
      case 0x3e:
      case 0x3f:
      case 0x44:
      case 0x45:
      case 0x46:
        diag_warning(3,0x85,(uint)op,from,to);
        return 1;
      }
    }
  }
  cVar10 = type_derivations_equal(to,from);
  if (cVar10 == '\0') {
    to_layer = (c1_type *)(-(uint)((to->code & 0x80) != 0) & (uint)to);
    from_layer = (c1_type *)(-(uint)((from->code & 0x80) != 0) & (uint)from);
    do {
      pcVar17 = from_layer;
      if ((to_layer == (c1_type *)0x0) || (pcVar17 = (c1_type *)0x0, from_layer == (c1_type *)0x0))
      goto LAB_1061abb7;
      bVar8 = (byte)from_layer->code;
      mods_to = to_layer->flags;
      mods_from = from_layer->flags;
      pcVar17 = to_layer->base;
      cVar15 = to_layer->code;
      if (-1 < (char)pcVar17->code) {
        cVar16 = (char)to->code;
        pcVar17 = to;
        while (cVar16 < '\0') {
          pcVar17 = pcVar17->base;
          cVar16 = (char)pcVar17->code;
        }
      }
      quals_to = pcVar17->flags;
      pcVar17 = from_layer->base;
      if (-1 < (char)pcVar17->code) {
        cVar16 = (char)from->code;
        pcVar17 = from;
        while (cVar16 < '\0') {
          pcVar17 = pcVar17->base;
          cVar16 = (char)pcVar17->code;
        }
      }
      quals_from = pcVar17->flags;
      if ((((byte)cVar15 & 0x8f) == 0x83) && (quals_to = quals_to | mods_to & 0x3e0, local_1c != 0))
      {
        cVar15 = 0x82;
      }
      if (((bVar8 & 0x8f) == 0x83) && (quals_from = quals_from | mods_from & 0x3e0, local_1c != 0))
      {
        bVar8 = 0x82;
      }
      if (((bVar8 ^ (byte)cVar15) & 0x8f) != 0) {
        iVar11 = conv_warn_indirection_levels(op,to,from);
        return iVar11;
      }
      uVar19 = cVar15 & 0x8f;
      if ((uVar19 == 0x86) && (iVar11 = type_modifier_bits_match(mods_to,mods_from), iVar11 == 0)) {
        iVar11 = conv_report_function_pointer_attributes(op);
        return iVar11;
      }
      if (((to_layer->flags & 8) != 0) || ((from_layer->flags & 8) != 0)) {
        conv_warn_different_bases(op,to_layer,from_layer);
      }
      cVar16 = (char)to->code;
      pcVar17 = to;
      while (cVar16 < '\0') {
        pcVar17 = pcVar17->base;
        cVar16 = (char)pcVar17->code;
      }
      iVar11 = conv_warn_different_qualifiers
                         (op,quals_to,quals_from,local_1c,(uint)((pcVar17->code & 0xfff) == 0x11));
      if (iVar11 == 0) {
        return 0;
      }
      if ((((iVar11 == 2) && (uVar19 != 0x86)) && ((uVar19 != 0x83 || ((bVar8 & 0x8f) != 0x83)))) &&
         (iVar11 = type_modifier_bits_match(mods_to,mods_from), iVar11 == 0)) {
        iVar11 = conv_warn_indirection_levels_2(op);
        return iVar11;
      }
      if (uVar19 == 0x83) {
        if ((to_layer->extra).sym != (from_layer->extra).sym) {
          diag_warning(1,0x30,to,from);
          return 0;
        }
      }
      else if ((to_layer->code & 0x83) == 0x81) {
        pcVar3 = (to_layer->extra).params;
        if ((pcVar3 == (c1_param_list *)0x0) ||
           (pcVar4 = (from_layer->extra).params, pcVar4 == (c1_param_list *)0x0)) {
          if (((to_layer->flags & 0x4000) == 0) && ((from_layer->flags & 0x4000) == 0))
          goto LAB_1061ab7b;
        }
        else {
          iVar11 = pcVar3->count;
          iVar22 = pcVar4->count;
          if (iVar11 != iVar22) {
            if (((from_layer->flags & 0x8000) == 0) && ((to_layer->flags & 0x8000) == 0)) {
              if ((iVar11 != 0) || (g_ms_extensions == '\0')) {
                diag_warning(1,0x71,from,to);
              }
              goto LAB_1061ab7b;
            }
            if (iVar22 < iVar11) {
              iVar11 = iVar22;
            }
          }
          ppcVar21 = pcVar3->types;
          ppcVar18 = pcVar4->types;
          if (0 < iVar11) {
            iVar22 = 1;
            do {
              pcVar17 = *ppcVar21;
              type2 = *ppcVar18;
              if (pcVar17 != type2) {
                if ((pcVar17->code == 0x80d) || (type2->code == 0x80d)) break;
                if (local_1c == 0) {
                  iVar13 = type_check_pointer_compatible(pcVar17,type2);
                  if ((iVar13 == 1) || ((iVar13 == 2 && (g_ms_extensions == '\0')))) {
                    diag_warning(1,0x1c,iVar22);
                    goto LAB_1063beac;
                  }
                }
                else {
                  iVar13 = type_check_compatible('p',pcVar17,type2);
                  if (iVar13 == 0) {
LAB_1063beac:
                    bVar6 = true;
                  }
                }
              }
              ppcVar21 = ppcVar21 + 1;
              ppcVar18 = ppcVar18 + 1;
              bVar5 = iVar22 < iVar11;
              iVar22 = iVar22 + 1;
            } while (bVar5);
          }
        }
        if (((!bVar6) && (g_ms_extensions != '\0')) &&
           ((char)((byte)(to_layer->flags >> 8) ^ (byte)(from_layer->flags >> 8)) < '\0')) {
          diag_warning(4,0xdc);
        }
      }
LAB_1061ab7b:
      local_1c = 0;
      to_layer = (c1_type *)(-(uint)((to_layer->base->code & 0x80) != 0) & (uint)to_layer->base);
      from_layer = (c1_type *)
                   ((uint)from_layer->base & -(uint)((from_layer->base->code & 0x80) != 0));
    } while (to_layer != from_layer);
    to_layer = (c1_type *)0x0;
    pcVar17 = (c1_type *)0x0;
LAB_1061abb7:
    if (to_layer != pcVar17) {
      if ((local_1c != 0) &&
         ((((pcVar2->code & 0x40) != 0 && (pcVar17 == (c1_type *)0x0)) ||
          (((pcVar23->code & 0x40) != 0 && (to_layer == (c1_type *)0x0)))))) {
        diag_error(0x78);
        return 0;
      }
      if ((((char)to->code < '\0') || ((pcVar23->code & 0x10) != 0)) &&
         (((char)from->code < '\0' || ((pcVar2->code & 0x10) != 0)))) {
        iVar11 = conv_warn_indirection_levels(op,to,from);
        return iVar11;
      }
      goto LAB_1063bdf5;
    }
  }
  else {
    uVar19 = to->code;
    if (-1 < (char)uVar19) {
      if ((uVar19 & 0x300) == 0) {
        pcVar20 = (c1_symbol *)0x0;
      }
      else {
        pcVar20 = (to->extra).sym;
      }
      if ((from->code & 0x300) == 0) {
        pcVar12 = (c1_symbol *)0x0;
      }
      else {
        pcVar12 = (from->extra).sym;
      }
      if (pcVar20 == pcVar12) {
        return 1;
      }
      if (((op == '6') && ((uVar19 & 0x100) != 0)) && ((from->code & 0x100) != 0)) {
        return 1;
      }
LAB_1063bdf5:
      diag_error(0x73,op);
      return 0;
    }
    iVar11 = conv_warn_different_qualifiers
                       (op,pcVar23->flags,pcVar2->flags,1,(uint)((pcVar23->code & 0xfff) == 0x11));
    if (iVar11 == 0) {
      iVar11 = type_check_compatible_fragment(0);
      return iVar11;
    }
  }
  uVar19 = pcVar23->code;
  uVar1 = pcVar2->code;
  if (uVar19 == uVar1) {
    cVar16 = (char)to->code;
    pcVar23 = to;
    while (cVar16 < '\0') {
      pcVar23 = pcVar23->base;
      cVar16 = (char)pcVar23->code;
    }
    if ((pcVar23->code & 0x300) == 0) {
      pcVar20 = (c1_symbol *)0x0;
    }
    else {
      pcVar20 = (pcVar23->extra).sym;
    }
    cVar16 = (char)from->code;
    pcVar23 = from;
    while (cVar16 < '\0') {
      pcVar23 = pcVar23->base;
      cVar16 = (char)pcVar23->code;
    }
    if ((pcVar23->code & 0x300) == 0) {
      pcVar12 = (c1_symbol *)0x0;
    }
    else {
      pcVar12 = (pcVar23->extra).sym;
    }
    if (pcVar20 == pcVar12) {
      return (uint)!bVar6;
    }
  }
  if (((g_ms_extensions != '\0') &&
      ((&g_type_rank_table)[uVar19 & 0xf] == (&g_type_rank_table)[uVar1 & 0xf])) &&
     (((uVar19 ^ uVar1) & 0xff0) == 0)) {
    cVar16 = (char)to->code;
    pcVar23 = to;
    while (cVar16 < '\0') {
      pcVar23 = pcVar23->base;
      cVar16 = (char)pcVar23->code;
    }
    if ((pcVar23->code & 0x300) == 0) {
      pcVar20 = (c1_symbol *)0x0;
    }
    else {
      pcVar20 = (pcVar23->extra).sym;
    }
    cVar16 = (char)from->code;
    pcVar23 = from;
    while (cVar16 < '\0') {
      pcVar23 = pcVar23->base;
      cVar16 = (char)pcVar23->code;
    }
    if ((pcVar23->code & 0x300) == 0) {
      pcVar12 = (c1_symbol *)0x0;
    }
    else {
      pcVar12 = (pcVar23->extra).sym;
    }
    if (pcVar20 == pcVar12) {
      iVar22 = 0x39;
      iVar11 = 4;
      pcVar23 = to;
      goto LAB_1061af93;
    }
  }
  if ((uVar19 & 0xfff) == 0x40) {
    return 1;
  }
  iVar22 = 0x85;
  iVar11 = 1;
  pcVar23 = from;
  from = to;
LAB_1061af93:
  diag_warning(iVar11,iVar22,op,pcVar23,from);
  return (uint)!bVar6;
}

