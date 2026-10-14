void __fastcall
decl_check_void_variable(c1_declarator *d,int slot_c,char is_member,c1_u8 keyword_code)

{
  c1_u8 *pcVar1;
  c1_u32 cVar2;
  c1_type *pcVar3;
  fe_name *pfVar4;
  byte bVar5;
  ushort uVar6;
  c1_symbol *pcVar7;
  c1_symbol *pcVar8;
  c1_type *pcVar9;
  uint uVar10;
  int iVar11;
  char cVar12;
  c1_u8 *pcVar13;
  
  pcVar7 = d->sym;
  if (pcVar7 == (c1_symbol *)0x0) {
    pcVar7 = sym_new_from_declarator(d,5);
  }
  diag_error(0xb6,pcVar7);
  d->type = g_type_int;
  if (d->type == (c1_type *)0x0) {
    d->type = d->sym->type;
  }
  if ((d->flags54 & 0x40) != 0) {
    d->spec[0] = d->spec[0] | 8;
  }
  cVar2 = d->kind;
  if ((cVar2 != 7) && (cVar2 != 8)) {
    pcVar1 = d->spec;
    bVar5 = d->spec[0] & 7;
    cVar12 = '\x01';
    _keyword_code = 1;
    if (((bVar5 < 4) || (6 < bVar5)) && ((bVar5 != 1 && (bVar5 != 2)))) {
      if ((d->spec[2] & 0xc) == 0) goto LAB_104029f4;
      if (bVar5 != 3) goto LAB_10402f67;
LAB_10402f82:
      if (cVar2 == 1) {
        decl_check_storage_class('\x01',d,pcVar1,slot_c,is_member,'\x01');
        return;
      }
    }
    else {
LAB_10402f67:
      if (cVar2 == 2) {
        pcVar7 = d->sym;
        if (pcVar7 == (c1_symbol *)0x0) {
          pcVar7 = sym_new_from_declarator(d,5);
        }
        diag_error(0x47,pcVar7);
        bVar5 = *pcVar1;
        *pcVar1 = bVar5 & 0xf8;
        *pcVar1 = bVar5 & 0xf8 | 8;
        d->flags54 = d->flags54 | 0x40;
      }
      else {
        if (cVar2 == 1) {
          decl_check_storage_class('\x01',d,pcVar1,slot_c,is_member,'\x01');
          return;
        }
LAB_104029f4:
        if (bVar5 == 3) goto LAB_10402f82;
      }
    }
    if ((d->spec[1] & 2) != 0) {
      cVar12 = '\x0f';
      _keyword_code = 0xf;
      d->spec[1] = d->spec[1] & 0xfd;
    }
    if ((d->spec[1] & 4) != 0) {
      bVar5 = *pcVar1;
      d->spec[1] = d->spec[1] & 0xfb;
      cVar12 = '\r';
      _keyword_code = 0xd;
      is_member = '\x01';
      d->kind = 2;
      *pcVar1 = bVar5 | 8;
      d->flags54 = d->flags54 | 0x40;
    }
    bVar5 = d->spec[1];
    if ((bVar5 & 8) == 0) {
      if ((bVar5 & 1) != 0) {
        _keyword_code = 0xe;
        d->spec[1] = bVar5 & 0xfe;
        goto LAB_1047743d;
      }
      if (cVar12 != '\x01') goto LAB_1047743d;
    }
    else {
      _keyword_code = 0xec;
      d->spec[1] = bVar5 & 0xf6;
LAB_1047743d:
      if (d->kind == 6) {
        diag_error(0x2df,_keyword_code);
      }
      else if (d->kind == 4) {
        diag_error(0x2e0,_keyword_code);
      }
      else {
        pcVar7 = d->sym;
        if (pcVar7 == (c1_symbol *)0x0) {
          pcVar7 = sym_new_from_declarator(d,5);
        }
        diag_error(0x1b1,pcVar7,_keyword_code);
      }
    }
    if (d->kind == 4) {
      switch(*pcVar1 & 7) {
      case 1:
        cVar12 = '\n';
        break;
      default:
        cVar12 = '\x01';
        break;
      case 3:
        cVar12 = '\t';
        break;
      case 4:
        cVar12 = '\b';
        break;
      case 5:
        cVar12 = '\v';
        break;
      case 7:
        cVar12 = '\f';
      }
      *pcVar1 = *pcVar1 & 0xf8;
      if (cVar12 != '\x01') {
        decl_check_parameter_storage_class(d);
        return;
      }
    }
    cVar2 = d->kind;
    if (((cVar2 == 5) || (cVar2 == 6)) || (cVar2 == 0xb)) {
      bVar5 = *pcVar1 & 7;
      if ((bVar5 != 5) && (bVar5 != 4)) {
        if (bVar5 != 0) {
          pcVar7 = d->sym;
          if (pcVar7 == (c1_symbol *)0x0) {
            pcVar7 = sym_new_from_declarator(d,5);
          }
          diag_warning(1,0x2a,pcVar7);
        }
        *pcVar1 = *pcVar1 & 0xfc | 4;
      }
      if ((((d->spec[1] & 7) != 0) || (bVar5 = d->spec[2], (bVar5 & 3) != 0)) ||
         (((bVar5 & 0xc) != 0 ||
          (((((d->spec[3] & 1) != 0 || ((d->spec[3] & 0x9c) != 0)) || ((bVar5 & 0x40) != 0)) ||
           (((d->spec[0x14] & 3) != 0 || ((d->spec[1] & 0x40) != 0)))))))) {
        pcVar7 = d->sym;
        if (pcVar7 == (c1_symbol *)0x0) {
          pcVar7 = sym_new_from_declarator(d,5);
        }
        diag_warning(1,0x2a,pcVar7);
        bVar5 = *pcVar1;
        pcVar13 = pcVar1;
        for (iVar11 = 6; iVar11 != 0; iVar11 = iVar11 + -1) {
          pcVar13[0] = '\0';
          pcVar13[1] = '\0';
          pcVar13[2] = '\0';
          pcVar13[3] = '\0';
          pcVar13 = pcVar13 + 4;
        }
        bVar5 = (bVar5 & 7 ^ *pcVar1) & 7 ^ *pcVar1;
LAB_1047755b:
        *pcVar1 = bVar5;
      }
    }
    else if (cVar2 == 3) {
      if ((g_compile_flags_c4 & 0x20000) == 0) {
        if (((g_compile_flags_c4 & 0x100) != 0) && ((g_compile_flags_c8 & 0x100) != 0)) {
          decl_process_declaration_storage_fragment(g_compile_flags_c4,d);
          return;
        }
        bVar5 = *pcVar1 & 7;
        if ((bVar5 < 4) || (6 < bVar5)) {
          if (bVar5 == 0) {
            pcVar9 = d->type;
            while ((bVar5 = (byte)pcVar9->code, (bVar5 & 0x8f) == 0x83 || ((bVar5 & 0x83) == 0x81)))
            {
              pcVar9 = pcVar9->base;
            }
            if (((byte)pcVar9->flags >> 5 & 1) == 0) {
              if (((((d->flags54 & 0x80) != 0) && ((d->flags55 & 1) != 0)) &&
                  ((d->flags54 & 4) == 0)) || ((d->spec[2] & 8) != 0)) {
                bVar5 = *pcVar1 & 0xf9 | 1;
                goto LAB_1047755b;
              }
              *pcVar1 = *pcVar1 & 0xfa | 2;
            }
            else {
              *pcVar1 = *pcVar1 & 0xfb | 3;
            }
          }
        }
        else {
          pcVar7 = d->sym;
          if (pcVar7 == (c1_symbol *)0x0) {
            pcVar7 = sym_new_from_declarator(d,5);
          }
          diag_error(0x186,pcVar7,(-(uint)(bVar5 < 5) & 0xfffffffd) + 0xb);
          *pcVar1 = *pcVar1 & 0xfa | 2;
        }
      }
      else if ((*pcVar1 & 7) == 0) {
        if ((g_compile_flags_c4 & 0x20) == 0) {
          if ((d->spec[2] & 8) != 0) {
            bVar5 = *pcVar1 & 0xf9 | 1;
            goto LAB_1047755b;
          }
          *pcVar1 = *pcVar1 & 0xfc | 4;
        }
        else {
          *pcVar1 = *pcVar1 & 0xfa | 2;
        }
      }
    }
    if ((*pcVar1 & 7) == 3) {
      if ((d->spec[2] & 0xc) == 0) goto switchD_10402dd2_caseD_1;
      if (d->kind != 2) {
        decl_check_export_linkage(d->kind,d);
        return;
      }
    }
    if (((d->spec[2] & 0xc) != 0) && ((g_compile_flags_c4 & 0x20000) != 0)) {
      typesym_check_declaration(g_compile_flags_c4,d);
      return;
    }
    goto switchD_10402dd2_caseD_1;
  }
  if ((d->decl->flags & 2) == 0) {
    pfVar4 = d->name;
    uVar10 = pfVar4->flags & 0x40000000;
    if ((uVar10 == 0) ||
       (((pfVar4 != g_name_main && (pfVar4 != g_name_wmain)) || (d->owner != (c1_symbol *)0x0)))) {
      if ((uVar10 != 0) &&
         ((((pfVar4 == g_name_WinMain || (pfVar4 == g_name_DllMain)) || (pfVar4 == g_name_wWinMain))
          && ((d->owner == (c1_symbol *)0x0 && (g_default_stdcall == 0)))))) {
        pcVar9 = type_with_qualifier_bits(d->type,5);
        d->type = pcVar9;
        pcVar7 = d->sym;
        if (pcVar7 == (c1_symbol *)0x0) {
          pcVar7 = sym_new_from_declarator(d,5);
        }
        diag_warning(3,7,pcVar7,0x82);
      }
    }
    else if (((g_opt_Gr != '\0') || (g_opt_Gc != '\0')) || (g_default_stdcall != 0)) {
      pcVar9 = type_with_qualifier_bits(d->type,1);
      d->type = pcVar9;
      pcVar7 = d->sym;
      if (pcVar7 == (c1_symbol *)0x0) {
        pcVar7 = sym_new_from_declarator(d,5);
      }
      diag_warning(3,7,pcVar7,0x25);
    }
  }
  else if (((d->flags55 >> 1 & 0x40) != 0 || (d->flags55 & 0x40) != 0) &&
          ((g_compile_flags_c4 & 0x200) == 0)) {
    uVar6 = d->type->flags & 7;
    if ((uVar6 != 6) && (uVar6 != 5)) {
      diag_warning(1,0xa6);
    }
    if ((d->type->flags & 0x8000) == 0) {
      uVar6 = 6;
    }
    else {
      uVar6 = 1;
    }
    pcVar9 = type_with_qualifier_bits(d->type,uVar6);
    d->type = pcVar9;
  }
  pcVar1 = d->spec;
  if ((d->spec[0] & 8) == 0) {
    cVar12 = '\0';
    uVar6 = d->type->code;
    if ((uVar6 & 0x8000) == 0) {
      if ((uVar6 & 0x4000) != 0) {
        pcVar9 = type_function_return(d->type);
        pcVar7 = (pcVar9->extra).cls;
        if ((g_linkage_stack[g_linkage_depth] == 2) && ((pcVar7->flags1 & 2) == 0)) {
          if ((pcVar7->flags2 & 4) == 0) {
            pcVar8 = d->sym;
            if (pcVar8 == (c1_symbol *)0x0) {
              pcVar8 = sym_new_from_declarator(d,5);
            }
            diag_error(0x20e,pcVar8,pcVar7);
            cVar12 = '\x01';
          }
          else if ((((pcVar7->detail).cls)->layout_flags3c & 1) == 0) {
            decl_check_linkage_and_virtual(pcVar7,d,pcVar1,slot_c,is_member);
            return;
          }
        }
      }
    }
    else {
      d->flags56 = d->flags56 | 8;
    }
    if ((d->spec[1] & 2) != 0) {
      if (is_member == '\0') {
        pcVar7 = d->sym;
        if (pcVar7 == (c1_symbol *)0x0) {
          pcVar7 = sym_new_from_declarator(d,5);
        }
        diag_error(0x23f,pcVar7);
        d->spec[1] = d->spec[1] & 0xfd;
      }
      else {
        pfVar4 = d->name;
        if (((pfVar4 == g_name_new) || (pfVar4 == g_name_delete)) || (pfVar4 == g_name_array_new)) {
          pcVar7 = d->sym;
          if (pcVar7 == (c1_symbol *)0x0) {
            pcVar7 = sym_new_from_declarator(d,5);
          }
          diag_error(0x28a,pcVar7);
          cVar12 = '\x01';
          d->spec[1] = d->spec[1] & 0xfd;
        }
        else if (pfVar4 == g_name_array_delete) {
          decl_check_virtual_function(d,pcVar1,slot_c,is_member);
          return;
        }
      }
    }
    if ((d->spec[1] & 4) == 0) {
      if (((*pcVar1 & 7) == 1) && (is_member != '\0')) {
        decl_check_member_storage_class(*pcVar1,cVar12,d,pcVar1,slot_c,is_member);
        return;
      }
    }
    else if (g_class_depth < 0) {
      decl_check_friend_context(d,pcVar1,slot_c,is_member);
      return;
    }
    if ((*pcVar1 & 7) == 3) {
      if ((d->flags55 & 0x80) == 0) {
        if (is_member == '\0') {
          if (((g_compile_flags_cc & 0x40) == 0) && (g_block_depth != '\0')) {
            decl_check_function_storage_class(cVar12,d,pcVar1,slot_c,'\0');
            return;
          }
        }
        else {
          d->flags56 = d->flags56 & 0xef;
        }
      }
      else {
        pcVar7 = d->sym;
        if (pcVar7 == (c1_symbol *)0x0) {
          pcVar7 = sym_new_from_declarator(d,5);
        }
        diag_error(0x23e,pcVar7);
        cVar12 = '\x01';
      }
    }
    bVar5 = d->flags55;
    if ((*pcVar1 & 0x10) == 0) {
      if ((bVar5 & 0x80) == 0) {
        if ((bVar5 & 0x40) == 0) {
          if (cVar12 == '\0') goto LAB_10402dc3;
        }
        else {
          pcVar7 = d->sym;
          if (pcVar7 == (c1_symbol *)0x0) {
            pcVar7 = sym_new_from_declarator(d,5);
          }
          diag_error(0x215,pcVar7);
          cVar12 = '\x01';
        }
      }
      else {
        pcVar7 = d->sym;
        if (pcVar7 == (c1_symbol *)0x0) {
          pcVar7 = sym_new_from_declarator(d,5);
        }
        diag_error(0x277,pcVar7);
        cVar12 = '\x01';
      }
LAB_10402eea:
      pcVar9 = type_with_base(d->type,g_type_void);
      d->type = pcVar9;
    }
    else if ((bVar5 & 0xc0) != 0) goto LAB_10402eea;
    if (cVar12 != '\0') {
      bVar5 = *pcVar1;
      *pcVar1 = bVar5 | 8;
      *pcVar1 = bVar5 & 0xf8 | 8;
      d->flags54 = d->flags54 | 0x40;
    }
  }
LAB_10402dc3:
  switch(*pcVar1 & 7) {
  case 0:
  case 2:
    bVar5 = *pcVar1;
    *pcVar1 = bVar5 & 0xf9 | 1;
    *pcVar1 = bVar5 & 0xf9 | 0x21;
    break;
  case 3:
    if ((d->spec[1] & 2) != 0) {
      pcVar7 = d->sym;
      if (pcVar7 == (c1_symbol *)0x0) {
        pcVar7 = sym_new_from_declarator(d,5);
      }
      diag_error(0x240,pcVar7);
      d->spec[1] = d->spec[1] & 0xfd;
    }
    if ((d->spec[2] & 0xc) == 0) break;
    if (is_member == '\0') {
      pcVar7 = d->sym;
      if (pcVar7 == (c1_symbol *)0x0) {
        pcVar7 = sym_new_from_declarator(d,5);
      }
      diag_error(0xc9,pcVar7);
      bVar5 = *pcVar1;
      *pcVar1 = bVar5 & 0xf9 | 1;
      *pcVar1 = bVar5 & 0xf9 | 0x21;
      goto LAB_10402ad7;
    }
    goto LAB_10402b21;
  case 4:
  case 5:
  case 6:
    pcVar7 = d->sym;
    if (pcVar7 == (c1_symbol *)0x0) {
      pcVar7 = sym_new_from_declarator(d,5);
    }
    diag_warning(1,0x2a,pcVar7);
    decl_process_declaration_case0_fragment(d,pcVar1,slot_c,is_member);
    return;
  case 7:
    if ((d->flags54 & 8) != 0) {
      pcVar7 = d->sym;
      if (pcVar7 == (c1_symbol *)0x0) {
        pcVar7 = sym_new_from_declarator(d,5);
      }
      diag_error(0x47,pcVar7);
      *pcVar1 = *pcVar1 & 0xf9 | 1;
    }
    d->kind = (d->kind != 8) + 2;
  }
switchD_10402dd2_caseD_1:
  if (is_member == '\0') {
LAB_10402ad7:
    cVar2 = d->kind;
    if ((((((cVar2 != 7) && (cVar2 != 8)) || (d->special_kind == '\0')) &&
         (d->flags54 = (*(byte *)(g_linkage_stack + g_linkage_depth) ^ d->flags54) & 3 ^ d->flags54,
         g_opt_EHc != '\0')) && ((cVar2 == 7 || (cVar2 == 8)))) &&
       ((g_linkage_stack[g_linkage_depth] == 2 && ((d->spec[3] & 0x20) == 0)))) {
      d->spec[3] = d->spec[3] | 0x10;
    }
  }
LAB_10402b21:
  if (d->kind != 10) {
    pcVar9 = d->type;
    cVar12 = (char)pcVar9->code;
    pcVar3 = pcVar9;
    while (cVar12 < '\0') {
      pcVar3 = pcVar3->base;
      cVar12 = (char)pcVar3->code;
    }
    if ((pcVar3->code & 0xfff) == 0x802) {
      cVar12 = (char)pcVar9->code;
      while (cVar12 < '\0') {
        pcVar9 = pcVar9->base;
        cVar12 = (char)pcVar9->code;
      }
      if (((*(short *)&pcVar9->extra == 0) && ((g_compile_flags_c8 & 0x10000000) == 0)) &&
         ((g_compile_flags_cc & 0x100000) == 0)) {
        pcVar7 = d->sym;
        if (pcVar7 == (c1_symbol *)0x0) {
          pcVar7 = sym_new_from_declarator(d,5);
        }
        diag_error(0x3bb,pcVar7);
      }
    }
  }
  if ((d->spec[3] & 4) != 0) {
    if (((d->kind == 2) || (d->kind == 1)) && ((d->spec[0] & 7) == 0)) {
      pcVar9 = d->type;
      if ((pcVar9->code & 0x8f) == 0x83) {
        pcVar9 = type_skip_arrays(pcVar9->base);
      }
      if (((byte)pcVar9->flags >> 5 & 1) == 0) goto LAB_10402b60;
    }
    pcVar7 = d->sym;
    if (pcVar7 == (c1_symbol *)0x0) {
      pcVar7 = sym_new_from_declarator(d,5);
    }
    diag_error(0x47,pcVar7);
    d->spec[3] = d->spec[3] & 0xfb;
  }
LAB_10402b60:
  if (((d->spec[3] & 8) != 0) &&
     (((d->kind != 7 && (d->kind != 8)) || (((d->flags55 & 0x40) == 0 || (g_class_depth < 0)))))) {
    if (d->sym == (c1_symbol *)0x0) {
      sym_new_from_declarator(d,5);
    }
    diag_error(0x47);
    d->spec[3] = d->spec[3] & 0xf7;
  }
  if (d->type == (c1_type *)0x0) {
    diag_fatal(1);
  }
  return;
}

