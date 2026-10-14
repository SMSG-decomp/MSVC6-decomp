void __fastcall
decl_check_virtual_function(c1_declarator *d,byte *spec_flags,int slot_c,char is_member)

{
  char cVar1;
  byte bVar2;
  c1_u32 cVar3;
  c1_type *pcVar4;
  c1_symbol *pcVar5;
  c1_type *pcVar6;
  
  pcVar5 = d->sym;
  if (pcVar5 == (c1_symbol *)0x0) {
    pcVar5 = sym_new_from_declarator(d,5);
  }
  diag_error(0x28a,pcVar5);
  d->spec[1] = d->spec[1] & 0xfd;
  if ((d->spec[1] & 4) == 0) {
    if (((*spec_flags & 7) == 1) && (is_member != '\0')) {
      decl_check_member_storage_class(*spec_flags,'\x01',d,spec_flags,slot_c,is_member);
      return;
    }
  }
  else if (g_class_depth < 0) {
    decl_check_friend_context(d,spec_flags,slot_c,is_member);
    return;
  }
  if ((*spec_flags & 7) == 3) {
    if ((d->flags55 & 0x80) == 0) {
      if (is_member == '\0') {
        if (((g_compile_flags_cc & 0x40) == 0) && (g_block_depth != '\0')) {
          decl_check_function_storage_class('\x01',d,spec_flags,slot_c,'\0');
          return;
        }
      }
      else {
        d->flags56 = d->flags56 & 0xef;
      }
    }
    else {
      pcVar5 = d->sym;
      if (pcVar5 == (c1_symbol *)0x0) {
        pcVar5 = sym_new_from_declarator(d,5);
      }
      diag_error(0x23e,pcVar5);
    }
  }
  bVar2 = d->flags55;
  if ((*spec_flags & 0x10) == 0) {
    if ((bVar2 & 0x80) == 0) {
      if ((bVar2 & 0x40) != 0) {
        pcVar5 = d->sym;
        if (pcVar5 == (c1_symbol *)0x0) {
          pcVar5 = sym_new_from_declarator(d,5);
        }
        diag_error(0x215,pcVar5);
      }
    }
    else {
      pcVar5 = d->sym;
      if (pcVar5 == (c1_symbol *)0x0) {
        pcVar5 = sym_new_from_declarator(d,5);
      }
      diag_error(0x277,pcVar5);
    }
LAB_10402eea:
    pcVar6 = type_with_base(d->type,g_type_void);
    d->type = pcVar6;
  }
  else if ((bVar2 & 0xc0) != 0) goto LAB_10402eea;
  bVar2 = *spec_flags;
  *spec_flags = bVar2 | 8;
  *spec_flags = bVar2 & 0xf8 | 8;
  d->flags54 = d->flags54 | 0x40;
  switch(*spec_flags & 7) {
  case 0:
  case 2:
    bVar2 = *spec_flags;
    *spec_flags = bVar2 & 0xf9 | 1;
    *spec_flags = bVar2 & 0xf9 | 0x21;
    break;
  case 3:
    if ((d->spec[1] & 2) != 0) {
      pcVar5 = d->sym;
      if (pcVar5 == (c1_symbol *)0x0) {
        pcVar5 = sym_new_from_declarator(d,5);
      }
      diag_error(0x240,pcVar5);
      d->spec[1] = d->spec[1] & 0xfd;
    }
    if ((d->spec[2] & 0xc) == 0) break;
    if (is_member == '\0') {
      pcVar5 = d->sym;
      if (pcVar5 == (c1_symbol *)0x0) {
        pcVar5 = sym_new_from_declarator(d,5);
      }
      diag_error(0xc9,pcVar5);
      bVar2 = *spec_flags;
      *spec_flags = bVar2 & 0xf9 | 1;
      *spec_flags = bVar2 & 0xf9 | 0x21;
      goto LAB_10402ad7;
    }
    goto LAB_10402b21;
  case 4:
  case 5:
  case 6:
    pcVar5 = d->sym;
    if (pcVar5 == (c1_symbol *)0x0) {
      pcVar5 = sym_new_from_declarator(d,5);
    }
    diag_warning(1,0x2a,pcVar5);
    decl_process_declaration_case0_fragment(d,spec_flags,slot_c,is_member);
    return;
  case 7:
    if ((d->flags54 & 8) != 0) {
      pcVar5 = d->sym;
      if (pcVar5 == (c1_symbol *)0x0) {
        pcVar5 = sym_new_from_declarator(d,5);
      }
      diag_error(0x47,pcVar5);
      *spec_flags = *spec_flags & 0xf9 | 1;
    }
    d->kind = (d->kind != 8) + 2;
  }
  if (is_member == '\0') {
LAB_10402ad7:
    cVar3 = d->kind;
    if ((((cVar3 != 7) && (cVar3 != 8)) || (d->special_kind == '\0')) &&
       ((((d->flags54 = (*(byte *)(g_linkage_stack + g_linkage_depth) ^ d->flags54) & 3 ^ d->flags54
          , g_opt_EHc != '\0' && ((cVar3 == 7 || (cVar3 == 8)))) &&
         (g_linkage_stack[g_linkage_depth] == 2)) && ((d->spec[3] & 0x20) == 0)))) {
      d->spec[3] = d->spec[3] | 0x10;
    }
  }
LAB_10402b21:
  if (d->kind != 10) {
    pcVar6 = d->type;
    cVar1 = (char)pcVar6->code;
    pcVar4 = pcVar6;
    while (cVar1 < '\0') {
      pcVar4 = pcVar4->base;
      cVar1 = (char)pcVar4->code;
    }
    if ((pcVar4->code & 0xfff) == 0x802) {
      cVar1 = (char)pcVar6->code;
      while (cVar1 < '\0') {
        pcVar6 = pcVar6->base;
        cVar1 = (char)pcVar6->code;
      }
      if (((*(short *)&pcVar6->extra == 0) && ((g_compile_flags_c8 & 0x10000000) == 0)) &&
         ((g_compile_flags_cc & 0x100000) == 0)) {
        pcVar5 = d->sym;
        if (pcVar5 == (c1_symbol *)0x0) {
          pcVar5 = sym_new_from_declarator(d,5);
        }
        diag_error(0x3bb,pcVar5);
      }
    }
  }
  if ((d->spec[3] & 4) != 0) {
    if (((d->kind == 2) || (d->kind == 1)) && ((*spec_flags & 7) == 0)) {
      pcVar6 = d->type;
      if ((pcVar6->code & 0x8f) == 0x83) {
        pcVar6 = type_skip_arrays(pcVar6->base);
      }
      if (((byte)pcVar6->flags >> 5 & 1) == 0) goto LAB_10402b60;
    }
    pcVar5 = d->sym;
    if (pcVar5 == (c1_symbol *)0x0) {
      pcVar5 = sym_new_from_declarator(d,5);
    }
    diag_error(0x47,pcVar5);
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
  if (d->type != (c1_type *)0x0) {
    return;
  }
  diag_fatal(1);
}

