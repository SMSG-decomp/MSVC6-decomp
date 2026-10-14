void __fastcall
decl_check_storage_class
          (char keyword,c1_declarator *d,byte *spec_flags,int slot_c,char is_member,
          c1_u8 keyword_code)

{
  byte bVar1;
  c1_u32 cVar2;
  c1_type *pcVar3;
  byte bVar4;
  char cVar5;
  c1_symbol *pcVar6;
  c1_type *pcVar7;
  int iVar8;
  byte *pbVar9;
  
  pcVar6 = d->sym;
  if (pcVar6 == (c1_symbol *)0x0) {
    pcVar6 = sym_new_from_declarator(d,5);
  }
  diag_error(0x47,pcVar6);
  bVar4 = *spec_flags;
  *spec_flags = bVar4 & 0xf8;
  bVar1 = d->flags54;
  *spec_flags = bVar4 & 0xf8 | 8;
  d->flags54 = bVar1 | 0x40;
  if ((d->spec[1] & 2) != 0) {
    keyword = '\x0f';
    keyword_code = '\x0f';
    d->spec[1] = d->spec[1] & 0xfd;
  }
  if ((d->spec[1] & 4) != 0) {
    bVar4 = *spec_flags;
    d->spec[1] = d->spec[1] & 0xfb;
    bVar1 = d->flags54;
    keyword = '\r';
    keyword_code = '\r';
    is_member = '\x01';
    d->kind = 2;
    *spec_flags = bVar4 | 8;
    d->flags54 = bVar1 | 0x40;
  }
  bVar4 = d->spec[1];
  if ((bVar4 & 8) == 0) {
    if ((bVar4 & 1) != 0) {
      keyword_code = '\x0e';
      d->spec[1] = bVar4 & 0xfe;
      goto LAB_1047743d;
    }
    if (keyword != '\x01') goto LAB_1047743d;
  }
  else {
    keyword_code = 0xec;
    d->spec[1] = bVar4 & 0xf6;
LAB_1047743d:
    if (d->kind == 6) {
      diag_error(0x2df,keyword_code);
    }
    else if (d->kind == 4) {
      diag_error(0x2e0,keyword_code);
    }
    else {
      pcVar6 = d->sym;
      if (pcVar6 == (c1_symbol *)0x0) {
        pcVar6 = sym_new_from_declarator(d,5);
      }
      diag_error(0x1b1,pcVar6,keyword_code);
    }
  }
  if (d->kind == 4) {
    switch(*spec_flags & 7) {
    case 1:
      cVar5 = '\n';
      break;
    default:
      cVar5 = '\x01';
      break;
    case 3:
      cVar5 = '\t';
      break;
    case 4:
      cVar5 = '\b';
      break;
    case 5:
      cVar5 = '\v';
      break;
    case 7:
      cVar5 = '\f';
    }
    *spec_flags = *spec_flags & 0xf8;
    if (cVar5 != '\x01') {
      decl_check_parameter_storage_class(d);
      return;
    }
  }
  cVar2 = d->kind;
  if (((cVar2 == 5) || (cVar2 == 6)) || (cVar2 == 0xb)) {
    bVar4 = *spec_flags & 7;
    if ((bVar4 != 5) && (bVar4 != 4)) {
      if (bVar4 != 0) {
        pcVar6 = d->sym;
        if (pcVar6 == (c1_symbol *)0x0) {
          pcVar6 = sym_new_from_declarator(d,5);
        }
        diag_warning(1,0x2a,pcVar6);
      }
      *spec_flags = *spec_flags & 0xfc | 4;
    }
    if (((((d->spec[1] & 7) != 0) || (bVar4 = d->spec[2], (bVar4 & 3) != 0)) ||
        (((bVar4 & 0xc) != 0 ||
         ((((d->spec[3] & 1) != 0 || ((d->spec[3] & 0x9c) != 0)) || ((bVar4 & 0x40) != 0)))))) ||
       (((d->spec[0x14] & 3) != 0 || ((d->spec[1] & 0x40) != 0)))) {
      pcVar6 = d->sym;
      if (pcVar6 == (c1_symbol *)0x0) {
        pcVar6 = sym_new_from_declarator(d,5);
      }
      diag_warning(1,0x2a,pcVar6);
      bVar4 = *spec_flags;
      pbVar9 = spec_flags;
      for (iVar8 = 6; iVar8 != 0; iVar8 = iVar8 + -1) {
        pbVar9[0] = 0;
        pbVar9[1] = 0;
        pbVar9[2] = 0;
        pbVar9[3] = 0;
        pbVar9 = pbVar9 + 4;
      }
      bVar4 = (bVar4 & 7 ^ *spec_flags) & 7 ^ *spec_flags;
LAB_1047755b:
      *spec_flags = bVar4;
    }
  }
  else if (cVar2 == 3) {
    if ((g_compile_flags_c4 & 0x20000) == 0) {
      if (((g_compile_flags_c4 & 0x100) != 0) && ((g_compile_flags_c8 & 0x100) != 0)) {
        decl_process_declaration_storage_fragment(g_compile_flags_c4,d);
        return;
      }
      bVar4 = *spec_flags & 7;
      if ((bVar4 < 4) || (6 < bVar4)) {
        if (bVar4 == 0) {
          pcVar7 = d->type;
          while ((bVar4 = (byte)pcVar7->code, (bVar4 & 0x8f) == 0x83 || ((bVar4 & 0x83) == 0x81))) {
            pcVar7 = pcVar7->base;
          }
          if (((byte)pcVar7->flags >> 5 & 1) == 0) {
            if (((((d->flags54 & 0x80) != 0) && ((d->flags55 & 1) != 0)) && ((d->flags54 & 4) == 0))
               || ((d->spec[2] & 8) != 0)) {
              bVar4 = *spec_flags & 0xf9 | 1;
              goto LAB_1047755b;
            }
            *spec_flags = *spec_flags & 0xfa | 2;
          }
          else {
            *spec_flags = *spec_flags & 0xfb | 3;
          }
        }
      }
      else {
        pcVar6 = d->sym;
        if (pcVar6 == (c1_symbol *)0x0) {
          pcVar6 = sym_new_from_declarator(d,5);
        }
        diag_error(0x186,pcVar6,(-(uint)(bVar4 < 5) & 0xfffffffd) + 0xb);
        *spec_flags = *spec_flags & 0xfa | 2;
      }
    }
    else if ((*spec_flags & 7) == 0) {
      if ((g_compile_flags_c4 & 0x20) == 0) {
        if ((d->spec[2] & 8) != 0) {
          bVar4 = *spec_flags & 0xf9 | 1;
          goto LAB_1047755b;
        }
        *spec_flags = *spec_flags & 0xfc | 4;
      }
      else {
        *spec_flags = *spec_flags & 0xfa | 2;
      }
    }
  }
  if ((*spec_flags & 7) == 3) {
    if ((d->spec[2] & 0xc) != 0) {
      if (d->kind != 2) {
        decl_check_export_linkage(d->kind,d);
        return;
      }
      goto LAB_10402ac5;
    }
  }
  else {
LAB_10402ac5:
    if (((d->spec[2] & 0xc) != 0) && ((g_compile_flags_c4 & 0x20000) != 0)) {
      typesym_check_declaration(g_compile_flags_c4,d);
      return;
    }
  }
  if (((is_member == '\0') &&
      (((cVar2 = d->kind, cVar2 != 7 && (cVar2 != 8)) || (d->special_kind == '\0')))) &&
     (((d->flags54 = (*(byte *)(g_linkage_stack + g_linkage_depth) ^ d->flags54) & 3 ^ d->flags54,
       g_opt_EHc != '\0' &&
       (((cVar2 == 7 || (cVar2 == 8)) && (g_linkage_stack[g_linkage_depth] == 2)))) &&
      ((d->spec[3] & 0x20) == 0)))) {
    d->spec[3] = d->spec[3] | 0x10;
  }
  if (d->kind != 10) {
    pcVar7 = d->type;
    cVar5 = (char)pcVar7->code;
    pcVar3 = pcVar7;
    while (cVar5 < '\0') {
      pcVar3 = pcVar3->base;
      cVar5 = (char)pcVar3->code;
    }
    if ((pcVar3->code & 0xfff) == 0x802) {
      cVar5 = (char)pcVar7->code;
      while (cVar5 < '\0') {
        pcVar7 = pcVar7->base;
        cVar5 = (char)pcVar7->code;
      }
      if (((*(short *)&pcVar7->extra == 0) && ((g_compile_flags_c8 & 0x10000000) == 0)) &&
         ((g_compile_flags_cc & 0x100000) == 0)) {
        pcVar6 = d->sym;
        if (pcVar6 == (c1_symbol *)0x0) {
          pcVar6 = sym_new_from_declarator(d,5);
        }
        diag_error(0x3bb,pcVar6);
      }
    }
  }
  if ((d->spec[3] & 4) != 0) {
    if (((d->kind == 2) || (d->kind == 1)) && ((*spec_flags & 7) == 0)) {
      pcVar7 = d->type;
      if ((pcVar7->code & 0x8f) == 0x83) {
        pcVar7 = type_skip_arrays(pcVar7->base);
      }
      if (((byte)pcVar7->flags >> 5 & 1) == 0) goto LAB_10402b60;
    }
    pcVar6 = d->sym;
    if (pcVar6 == (c1_symbol *)0x0) {
      pcVar6 = sym_new_from_declarator(d,5);
    }
    diag_error(0x47,pcVar6);
    d->spec[3] = d->spec[3] & 0xfb;
  }
LAB_10402b60:
  if (((d->spec[3] & 8) != 0) &&
     ((((d->kind != 7 && (d->kind != 8)) || ((d->flags55 & 0x40) == 0)) || (g_class_depth < 0)))) {
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

