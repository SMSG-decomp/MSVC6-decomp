void decl_check_parameter_storage_class(c1_declarator *d)

{
  char cVar1;
  c1_u32 cVar2;
  c1_type *pcVar3;
  byte bVar4;
  c1_type *pcVar5;
  c1_symbol *pcVar6;
  int iVar7;
  byte *unaff_EBP;
  byte *pbVar8;
  undefined4 uStack0000000c;
  char in_stack_00000013;
  uint in_stack_00000014;
  
  diag_error(0x2e0,in_stack_00000014 & 0xff);
  cVar2 = d->kind;
  if (((cVar2 == 5) || (cVar2 == 6)) || (cVar2 == 0xb)) {
    bVar4 = *unaff_EBP & 7;
    if ((bVar4 != 5) && (bVar4 != 4)) {
      if (bVar4 != 0) {
        pcVar6 = d->sym;
        if (pcVar6 == (c1_symbol *)0x0) {
          pcVar6 = sym_new_from_declarator(d,5);
        }
        diag_warning(1,0x2a,pcVar6);
      }
      *unaff_EBP = *unaff_EBP & 0xfc | 4;
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
      bVar4 = *unaff_EBP;
      pbVar8 = unaff_EBP;
      for (iVar7 = 6; iVar7 != 0; iVar7 = iVar7 + -1) {
        pbVar8[0] = 0;
        pbVar8[1] = 0;
        pbVar8[2] = 0;
        pbVar8[3] = 0;
        pbVar8 = pbVar8 + 4;
      }
      bVar4 = (bVar4 & 7 ^ *unaff_EBP) & 7 ^ *unaff_EBP;
LAB_1047755b:
      *unaff_EBP = bVar4;
    }
  }
  else if (cVar2 == 3) {
    if ((g_compile_flags_c4 & 0x20000) == 0) {
      if (((g_compile_flags_c4 & 0x100) != 0) && ((g_compile_flags_c8 & 0x100) != 0)) {
        decl_process_declaration_storage_fragment(g_compile_flags_c4,d);
        return;
      }
      bVar4 = *unaff_EBP & 7;
      if ((bVar4 < 4) || (6 < bVar4)) {
        if (bVar4 == 0) {
          pcVar5 = d->type;
          while ((bVar4 = (byte)pcVar5->code, (bVar4 & 0x8f) == 0x83 || ((bVar4 & 0x83) == 0x81))) {
            pcVar5 = pcVar5->base;
          }
          if (((byte)pcVar5->flags >> 5 & 1) == 0) {
            if (((((d->flags54 & 0x80) != 0) && ((d->flags55 & 1) != 0)) && ((d->flags54 & 4) == 0))
               || ((d->spec[2] & 8) != 0)) {
              bVar4 = *unaff_EBP & 0xf9 | 1;
              goto LAB_1047755b;
            }
            *unaff_EBP = *unaff_EBP & 0xfa | 2;
          }
          else {
            *unaff_EBP = *unaff_EBP & 0xfb | 3;
          }
        }
      }
      else {
        pcVar6 = d->sym;
        if (pcVar6 == (c1_symbol *)0x0) {
          pcVar6 = sym_new_from_declarator(d,5);
        }
        diag_error(0x186,pcVar6,(-(uint)(bVar4 < 5) & 0xfffffffd) + 0xb);
        *unaff_EBP = *unaff_EBP & 0xfa | 2;
      }
    }
    else if ((*unaff_EBP & 7) == 0) {
      if ((g_compile_flags_c4 & 0x20) == 0) {
        if ((d->spec[2] & 8) != 0) {
          bVar4 = *unaff_EBP & 0xf9 | 1;
          goto LAB_1047755b;
        }
        *unaff_EBP = *unaff_EBP & 0xfc | 4;
      }
      else {
        *unaff_EBP = *unaff_EBP & 0xfa | 2;
      }
    }
  }
  if ((*unaff_EBP & 7) == 3) {
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
  if (((in_stack_00000013 == '\0') &&
      (((cVar2 = d->kind, cVar2 != 7 && (cVar2 != 8)) || (d->special_kind == '\0')))) &&
     (((d->flags54 = (*(byte *)(g_linkage_stack + g_linkage_depth) ^ d->flags54) & 3 ^ d->flags54,
       g_opt_EHc != '\0' &&
       (((cVar2 == 7 || (cVar2 == 8)) && (g_linkage_stack[g_linkage_depth] == 2)))) &&
      ((d->spec[3] & 0x20) == 0)))) {
    d->spec[3] = d->spec[3] | 0x10;
  }
  if (d->kind != 10) {
    pcVar5 = d->type;
    cVar1 = (char)pcVar5->code;
    pcVar3 = pcVar5;
    while (cVar1 < '\0') {
      pcVar3 = pcVar3->base;
      cVar1 = (char)pcVar3->code;
    }
    if ((pcVar3->code & 0xfff) == 0x802) {
      cVar1 = (char)pcVar5->code;
      while (cVar1 < '\0') {
        pcVar5 = pcVar5->base;
        cVar1 = (char)pcVar5->code;
      }
      if (((*(short *)&pcVar5->extra == 0) && ((g_compile_flags_c8 & 0x10000000) == 0)) &&
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
    if (((d->kind == 2) || (d->kind == 1)) && ((*unaff_EBP & 7) == 0)) {
      pcVar5 = d->type;
      if ((pcVar5->code & 0x8f) == 0x83) {
        pcVar5 = type_skip_arrays(pcVar5->base);
      }
      if (((byte)pcVar5->flags >> 5 & 1) == 0) goto LAB_10402b60;
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
  if (d->type != (c1_type *)0x0) {
    return;
  }
  uStack0000000c = 0x5a3;
  diag_fatal(1);
}

