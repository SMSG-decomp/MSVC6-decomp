void __fastcall decl_process_declaration(c1_declarator *d)

{
  c1_u8 *pcVar1;
  c1_decl_record *pcVar2;
  c1_u32 cVar3;
  c1_type *pcVar4;
  fe_name *pfVar5;
  byte bVar6;
  ushort uVar7;
  c1_symbol *pcVar8;
  c1_type *pcVar9;
  c1_symbol *pcVar10;
  uint uVar11;
  int iVar12;
  char cVar13;
  int unaff_ESI;
  c1_u8 *pcVar14;
  char cVar15;
  c1_u8 keyword_code;
  
  if (g_pending_access_check[g_paren_depth] != (c1_symbol *)0x0) {
    access_check_member(g_pending_access_check[g_paren_depth]);
  }
  if (((d->flags55 & 0x20) == 0) &&
     (((-1 < g_class_depth && ((d->spec[1] & 4) == 0)) ||
      ((d->qualifier != (c1_overload_set *)0x0 &&
       ((d->qualifier->list->head->key->sym->kind & 0x1f) != 0x19)))))) {
    cVar15 = '\x01';
  }
  else {
    cVar15 = '\0';
  }
  if (d->type == (c1_type *)0x0) {
    pcVar2 = d->decl;
    d->type = pcVar2->type;
    if ((pcVar2->flags & 1) != 0) {
      d->flags54 = d->flags54 | 0x40;
    }
    if (cVar15 != '\0') {
      bVar6 = (byte)d->type->code;
      if (((bVar6 & 0x83) == 0x81) && ((pcVar2->flags & 4) != 0)) {
        decl_process_declaration_member_type_block(d->type,bVar6,d,unaff_ESI,cVar15,keyword_code);
        return;
      }
    }
    type_check_declarator_kind(d);
    pcVar9 = d->type;
    bVar6 = (byte)pcVar9->code;
    if (((-1 < (char)bVar6) && ((d->spec[0] & 7) != 7)) && ((g_compile_flags_c8 & 0x20000000) == 0))
    {
      if ((bVar6 >> 6 & 1) == 0) {
        if (((pcVar9->code & 0x300) != 0) && ((d->spec[3] & 0x80) == 0)) {
          pcVar10 = (pcVar9->extra).cls;
          if ((((pcVar10->detail).cls)->flags3e & 2) == 0) {
            if ((pcVar10->flags2 & 4) == 0) {
              tmpl_instantiate_if_needed(pcVar10);
              goto LAB_10402d16;
            }
          }
          else {
            if ((g_compile_flags_cc & 0x300000) == 0) {
              diag_error(0x3bb,pcVar10);
              d->flags54 = d->flags54 | 0x40;
            }
LAB_10402d16:
            if ((pcVar10->flags2 & 4) == 0) goto LAB_10402c12;
          }
          if ((((pcVar10->detail).cls)->layout_flags3b & 0x80) != 0) {
            decl_check_abstract_class_object_block(pcVar10,d,unaff_ESI,cVar15,keyword_code);
            return;
          }
        }
LAB_10402c12:
        if ((((d->spec[0] & 7) != 1) && ((d->type->code & 0x200) != 0)) &&
           ((d->spec[3] & 0x80) == 0)) {
          pcVar10 = (d->type->extra).cls;
          if ((pcVar10->kind & 0x1f) == 4) {
            if ((pcVar10->flags2 & 4) != 0) goto LAB_1040299a;
            tmpl_instantiate_if_needed(pcVar10);
          }
          if (((((((pcVar10->flags2 & 4) == 0) && (cVar3 = d->kind, cVar3 != 4)) &&
                ((cVar3 != 6 && (((d->spec[3] & 0x80) == 0 && (cVar3 != 5)))))) && (cVar3 != 10)) &&
              (((g_compile_flags_cc & 0x200000) == 0 || (cVar3 != 3)))) &&
             ((((g_compile_flags_cc & 0x100000) == 0 || (cVar3 != 2)) && ((d->spec[0] & 7) != 3))))
          {
            decl_check_variable_type(pcVar10,d,unaff_ESI,cVar15,keyword_code);
            return;
          }
        }
      }
      else if ((d->kind != 4) && (d->kind != 6)) {
        decl_check_void_variable(d,unaff_ESI,cVar15,keyword_code);
        return;
      }
    }
LAB_1040299a:
    if (d->type == (c1_type *)0x0) {
      d->type = d->sym->type;
    }
  }
  if ((d->flags54 & 0x40) != 0) {
    d->spec[0] = d->spec[0] | 8;
  }
  cVar3 = d->kind;
  if ((cVar3 != 7) && (cVar3 != 8)) {
    pcVar1 = d->spec;
    bVar6 = d->spec[0] & 7;
    cVar13 = '\x01';
    _keyword_code = 1;
    if (((bVar6 < 4) || (6 < bVar6)) && ((bVar6 != 1 && (bVar6 != 2)))) {
      if ((d->spec[2] & 0xc) == 0) goto LAB_104029f4;
      if (bVar6 != 3) goto LAB_10402f67;
LAB_10402f82:
      if (cVar3 == 1) {
        decl_check_storage_class('\x01',d,pcVar1,unaff_ESI,cVar15,'\x01');
        return;
      }
    }
    else {
LAB_10402f67:
      if (cVar3 == 2) {
        pcVar10 = d->sym;
        if (pcVar10 == (c1_symbol *)0x0) {
          pcVar10 = sym_new_from_declarator(d,5);
        }
        diag_error(0x47,pcVar10);
        bVar6 = *pcVar1;
        *pcVar1 = bVar6 & 0xf8;
        *pcVar1 = bVar6 & 0xf8 | 8;
        d->flags54 = d->flags54 | 0x40;
      }
      else {
        if (cVar3 == 1) {
          decl_check_storage_class('\x01',d,pcVar1,unaff_ESI,cVar15,'\x01');
          return;
        }
LAB_104029f4:
        if (bVar6 == 3) goto LAB_10402f82;
      }
    }
    if ((d->spec[1] & 2) != 0) {
      cVar13 = '\x0f';
      _keyword_code = 0xf;
      d->spec[1] = d->spec[1] & 0xfd;
    }
    if ((d->spec[1] & 4) != 0) {
      bVar6 = *pcVar1;
      d->spec[1] = d->spec[1] & 0xfb;
      cVar13 = '\r';
      _keyword_code = 0xd;
      cVar15 = '\x01';
      d->kind = 2;
      *pcVar1 = bVar6 | 8;
      d->flags54 = d->flags54 | 0x40;
    }
    bVar6 = d->spec[1];
    if ((bVar6 & 8) == 0) {
      if ((bVar6 & 1) != 0) {
        _keyword_code = 0xe;
        d->spec[1] = bVar6 & 0xfe;
        goto LAB_1047743d;
      }
      if (cVar13 != '\x01') goto LAB_1047743d;
    }
    else {
      _keyword_code = 0xec;
      d->spec[1] = bVar6 & 0xf6;
LAB_1047743d:
      if (d->kind == 6) {
        diag_error(0x2df,_keyword_code);
      }
      else if (d->kind == 4) {
        diag_error(0x2e0,_keyword_code);
      }
      else {
        pcVar10 = d->sym;
        if (pcVar10 == (c1_symbol *)0x0) {
          pcVar10 = sym_new_from_declarator(d,5);
        }
        diag_error(0x1b1,pcVar10,_keyword_code);
      }
    }
    if (d->kind == 4) {
      switch(*pcVar1 & 7) {
      case 1:
        cVar13 = '\n';
        break;
      default:
        cVar13 = '\x01';
        break;
      case 3:
        cVar13 = '\t';
        break;
      case 4:
        cVar13 = '\b';
        break;
      case 5:
        cVar13 = '\v';
        break;
      case 7:
        cVar13 = '\f';
      }
      *pcVar1 = *pcVar1 & 0xf8;
      if (cVar13 != '\x01') {
        decl_check_parameter_storage_class(d);
        return;
      }
    }
    cVar3 = d->kind;
    if (((cVar3 == 5) || (cVar3 == 6)) || (cVar3 == 0xb)) {
      bVar6 = *pcVar1 & 7;
      if ((bVar6 != 5) && (bVar6 != 4)) {
        if (bVar6 != 0) {
          pcVar10 = d->sym;
          if (pcVar10 == (c1_symbol *)0x0) {
            pcVar10 = sym_new_from_declarator(d,5);
          }
          diag_warning(1,0x2a,pcVar10);
        }
        *pcVar1 = *pcVar1 & 0xfc | 4;
      }
      if ((((d->spec[1] & 7) != 0) || (bVar6 = d->spec[2], (bVar6 & 3) != 0)) ||
         (((bVar6 & 0xc) != 0 ||
          (((((d->spec[3] & 1) != 0 || ((d->spec[3] & 0x9c) != 0)) || ((bVar6 & 0x40) != 0)) ||
           (((d->spec[0x14] & 3) != 0 || ((d->spec[1] & 0x40) != 0)))))))) {
        pcVar10 = d->sym;
        if (pcVar10 == (c1_symbol *)0x0) {
          pcVar10 = sym_new_from_declarator(d,5);
        }
        diag_warning(1,0x2a,pcVar10);
        bVar6 = *pcVar1;
        pcVar14 = pcVar1;
        for (iVar12 = 6; iVar12 != 0; iVar12 = iVar12 + -1) {
          pcVar14[0] = '\0';
          pcVar14[1] = '\0';
          pcVar14[2] = '\0';
          pcVar14[3] = '\0';
          pcVar14 = pcVar14 + 4;
        }
        bVar6 = (bVar6 & 7 ^ *pcVar1) & 7 ^ *pcVar1;
LAB_1047755b:
        *pcVar1 = bVar6;
      }
    }
    else if (cVar3 == 3) {
      if ((g_compile_flags_c4 & 0x20000) == 0) {
        if (((g_compile_flags_c4 & 0x100) != 0) && ((g_compile_flags_c8 & 0x100) != 0)) {
          decl_process_declaration_storage_fragment(g_compile_flags_c4,d);
          return;
        }
        bVar6 = *pcVar1 & 7;
        if ((bVar6 < 4) || (6 < bVar6)) {
          if (bVar6 == 0) {
            pcVar9 = d->type;
            while ((bVar6 = (byte)pcVar9->code, (bVar6 & 0x8f) == 0x83 || ((bVar6 & 0x83) == 0x81)))
            {
              pcVar9 = pcVar9->base;
            }
            if (((byte)pcVar9->flags >> 5 & 1) == 0) {
              if (((((d->flags54 & 0x80) != 0) && ((d->flags55 & 1) != 0)) &&
                  ((d->flags54 & 4) == 0)) || ((d->spec[2] & 8) != 0)) {
                bVar6 = *pcVar1 & 0xf9 | 1;
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
          pcVar10 = d->sym;
          if (pcVar10 == (c1_symbol *)0x0) {
            pcVar10 = sym_new_from_declarator(d,5);
          }
          diag_error(0x186,pcVar10,(-(uint)(bVar6 < 5) & 0xfffffffd) + 0xb);
          *pcVar1 = *pcVar1 & 0xfa | 2;
        }
      }
      else if ((*pcVar1 & 7) == 0) {
        if ((g_compile_flags_c4 & 0x20) == 0) {
          if ((d->spec[2] & 8) != 0) {
            bVar6 = *pcVar1 & 0xf9 | 1;
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
    pfVar5 = d->name;
    uVar11 = pfVar5->flags & 0x40000000;
    if ((uVar11 == 0) ||
       (((pfVar5 != g_name_main && (pfVar5 != g_name_wmain)) || (d->owner != (c1_symbol *)0x0)))) {
      if (((uVar11 != 0) &&
          (((pfVar5 == g_name_WinMain || (pfVar5 == g_name_DllMain)) || (pfVar5 == g_name_wWinMain))
          )) && ((d->owner == (c1_symbol *)0x0 && (g_default_stdcall == 0)))) {
        pcVar9 = type_with_qualifier_bits(d->type,5);
        d->type = pcVar9;
        pcVar10 = d->sym;
        if (pcVar10 == (c1_symbol *)0x0) {
          pcVar10 = sym_new_from_declarator(d,5);
        }
        diag_warning(3,7,pcVar10,0x82);
      }
    }
    else if (((g_opt_Gr != '\0') || (g_opt_Gc != '\0')) || (g_default_stdcall != 0)) {
      pcVar9 = type_with_qualifier_bits(d->type,1);
      d->type = pcVar9;
      pcVar10 = d->sym;
      if (pcVar10 == (c1_symbol *)0x0) {
        pcVar10 = sym_new_from_declarator(d,5);
      }
      diag_warning(3,7,pcVar10,0x25);
    }
  }
  else if (((d->flags55 >> 1 & 0x40) != 0 || (d->flags55 & 0x40) != 0) &&
          ((g_compile_flags_c4 & 0x200) == 0)) {
    uVar7 = d->type->flags & 7;
    if ((uVar7 != 6) && (uVar7 != 5)) {
      diag_warning(1,0xa6);
    }
    if ((d->type->flags & 0x8000) == 0) {
      uVar7 = 6;
    }
    else {
      uVar7 = 1;
    }
    pcVar9 = type_with_qualifier_bits(d->type,uVar7);
    d->type = pcVar9;
  }
  pcVar1 = d->spec;
  if ((d->spec[0] & 8) == 0) {
    cVar13 = '\0';
    uVar7 = d->type->code;
    if ((uVar7 & 0x8000) == 0) {
      if ((uVar7 & 0x4000) != 0) {
        pcVar9 = type_function_return(d->type);
        pcVar10 = (pcVar9->extra).cls;
        if ((g_linkage_stack[g_linkage_depth] == 2) && ((pcVar10->flags1 & 2) == 0)) {
          if ((pcVar10->flags2 & 4) == 0) {
            pcVar8 = d->sym;
            if (pcVar8 == (c1_symbol *)0x0) {
              pcVar8 = sym_new_from_declarator(d,5);
            }
            diag_error(0x20e,pcVar8,pcVar10);
            cVar13 = '\x01';
          }
          else if ((((pcVar10->detail).cls)->layout_flags3c & 1) == 0) {
            decl_check_linkage_and_virtual(pcVar10,d,pcVar1,unaff_ESI,cVar15);
            return;
          }
        }
      }
    }
    else {
      d->flags56 = d->flags56 | 8;
    }
    if ((d->spec[1] & 2) != 0) {
      if (cVar15 == '\0') {
        pcVar10 = d->sym;
        if (pcVar10 == (c1_symbol *)0x0) {
          pcVar10 = sym_new_from_declarator(d,5);
        }
        diag_error(0x23f,pcVar10);
        d->spec[1] = d->spec[1] & 0xfd;
      }
      else {
        pfVar5 = d->name;
        if (((pfVar5 == g_name_new) || (pfVar5 == g_name_delete)) || (pfVar5 == g_name_array_new)) {
          pcVar10 = d->sym;
          if (pcVar10 == (c1_symbol *)0x0) {
            pcVar10 = sym_new_from_declarator(d,5);
          }
          diag_error(0x28a,pcVar10);
          cVar13 = '\x01';
          d->spec[1] = d->spec[1] & 0xfd;
        }
        else if (pfVar5 == g_name_array_delete) {
          decl_check_virtual_function(d,pcVar1,unaff_ESI,cVar15);
          return;
        }
      }
    }
    if ((d->spec[1] & 4) == 0) {
      if (((*pcVar1 & 7) == 1) && (cVar15 != '\0')) {
        decl_check_member_storage_class(*pcVar1,cVar13,d,pcVar1,unaff_ESI,cVar15);
        return;
      }
    }
    else if (g_class_depth < 0) {
      decl_check_friend_context(d,pcVar1,unaff_ESI,cVar15);
      return;
    }
    if ((*pcVar1 & 7) == 3) {
      if ((d->flags55 & 0x80) == 0) {
        if (cVar15 == '\0') {
          if (((g_compile_flags_cc & 0x40) == 0) && (g_block_depth != '\0')) {
            decl_check_function_storage_class(cVar13,d,pcVar1,unaff_ESI,'\0');
            return;
          }
        }
        else {
          d->flags56 = d->flags56 & 0xef;
        }
      }
      else {
        pcVar10 = d->sym;
        if (pcVar10 == (c1_symbol *)0x0) {
          pcVar10 = sym_new_from_declarator(d,5);
        }
        diag_error(0x23e,pcVar10);
        cVar13 = '\x01';
      }
    }
    bVar6 = d->flags55;
    if ((*pcVar1 & 0x10) == 0) {
      if ((bVar6 & 0x80) == 0) {
        if ((bVar6 & 0x40) == 0) {
          if (cVar13 == '\0') goto LAB_10402dc3;
        }
        else {
          pcVar10 = d->sym;
          if (pcVar10 == (c1_symbol *)0x0) {
            pcVar10 = sym_new_from_declarator(d,5);
          }
          diag_error(0x215,pcVar10);
          cVar13 = '\x01';
        }
      }
      else {
        pcVar10 = d->sym;
        if (pcVar10 == (c1_symbol *)0x0) {
          pcVar10 = sym_new_from_declarator(d,5);
        }
        diag_error(0x277,pcVar10);
        cVar13 = '\x01';
      }
LAB_10402eea:
      pcVar9 = type_with_base(d->type,g_type_void);
      d->type = pcVar9;
    }
    else if ((bVar6 & 0xc0) != 0) goto LAB_10402eea;
    if (cVar13 != '\0') {
      bVar6 = *pcVar1;
      *pcVar1 = bVar6 | 8;
      *pcVar1 = bVar6 & 0xf8 | 8;
      d->flags54 = d->flags54 | 0x40;
    }
  }
LAB_10402dc3:
  switch(*pcVar1 & 7) {
  case 0:
  case 2:
    bVar6 = *pcVar1;
    *pcVar1 = bVar6 & 0xf9 | 1;
    *pcVar1 = bVar6 & 0xf9 | 0x21;
    break;
  case 3:
    if ((d->spec[1] & 2) != 0) {
      pcVar10 = d->sym;
      if (pcVar10 == (c1_symbol *)0x0) {
        pcVar10 = sym_new_from_declarator(d,5);
      }
      diag_error(0x240,pcVar10);
      d->spec[1] = d->spec[1] & 0xfd;
    }
    if ((d->spec[2] & 0xc) == 0) break;
    if (cVar15 == '\0') {
      pcVar10 = d->sym;
      if (pcVar10 == (c1_symbol *)0x0) {
        pcVar10 = sym_new_from_declarator(d,5);
      }
      diag_error(0xc9,pcVar10);
      bVar6 = *pcVar1;
      *pcVar1 = bVar6 & 0xf9 | 1;
      *pcVar1 = bVar6 & 0xf9 | 0x21;
      goto LAB_10402ad7;
    }
    goto LAB_10402b21;
  case 4:
  case 5:
  case 6:
    pcVar10 = d->sym;
    if (pcVar10 == (c1_symbol *)0x0) {
      pcVar10 = sym_new_from_declarator(d,5);
    }
    diag_warning(1,0x2a,pcVar10);
    decl_process_declaration_case0_fragment(d,pcVar1,unaff_ESI,cVar15);
    return;
  case 7:
    if ((d->flags54 & 8) != 0) {
      pcVar10 = d->sym;
      if (pcVar10 == (c1_symbol *)0x0) {
        pcVar10 = sym_new_from_declarator(d,5);
      }
      diag_error(0x47,pcVar10);
      *pcVar1 = *pcVar1 & 0xf9 | 1;
    }
    d->kind = (d->kind != 8) + 2;
  }
switchD_10402dd2_caseD_1:
  if (cVar15 == '\0') {
LAB_10402ad7:
    cVar3 = d->kind;
    if ((((((cVar3 != 7) && (cVar3 != 8)) || (d->special_kind == '\0')) &&
         (d->flags54 = (*(byte *)(g_linkage_stack + g_linkage_depth) ^ d->flags54) & 3 ^ d->flags54,
         g_opt_EHc != '\0')) && ((cVar3 == 7 || (cVar3 == 8)))) &&
       ((g_linkage_stack[g_linkage_depth] == 2 && ((d->spec[3] & 0x20) == 0)))) {
      d->spec[3] = d->spec[3] | 0x10;
    }
  }
LAB_10402b21:
  if (d->kind != 10) {
    pcVar9 = d->type;
    cVar15 = (char)pcVar9->code;
    pcVar4 = pcVar9;
    while (cVar15 < '\0') {
      pcVar4 = pcVar4->base;
      cVar15 = (char)pcVar4->code;
    }
    if ((pcVar4->code & 0xfff) == 0x802) {
      cVar15 = (char)pcVar9->code;
      while (cVar15 < '\0') {
        pcVar9 = pcVar9->base;
        cVar15 = (char)pcVar9->code;
      }
      if (((*(short *)&pcVar9->extra == 0) && ((g_compile_flags_c8 & 0x10000000) == 0)) &&
         ((g_compile_flags_cc & 0x100000) == 0)) {
        pcVar10 = d->sym;
        if (pcVar10 == (c1_symbol *)0x0) {
          pcVar10 = sym_new_from_declarator(d,5);
        }
        diag_error(0x3bb,pcVar10);
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
    pcVar10 = d->sym;
    if (pcVar10 == (c1_symbol *)0x0) {
      pcVar10 = sym_new_from_declarator(d,5);
    }
    diag_error(0x47,pcVar10);
    d->spec[3] = d->spec[3] & 0xfb;
  }
LAB_10402b60:
  if (((d->spec[3] & 8) != 0) &&
     (((d->kind != 7 && (d->kind != 8)) || (((d->flags55 & 0x40) == 0 || (g_class_depth < 0)))))) {
    pcVar10 = d->sym;
    if (pcVar10 == (c1_symbol *)0x0) {
      pcVar10 = sym_new_from_declarator(d,5);
    }
    diag_error(0x47,pcVar10);
    d->spec[3] = d->spec[3] & 0xf7;
  }
  if (d->type == (c1_type *)0x0) {
    diag_fatal(1,".\\typesym.c",0x5a3);
  }
  return;
}

