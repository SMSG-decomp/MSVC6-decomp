void decl_check_export_linkage(int eax,c1_declarator *d)

{
  char cVar1;
  byte bVar2;
  c1_u32 cVar3;
  c1_type *pcVar4;
  c1_symbol *pcVar5;
  c1_type *pcVar6;
  byte *unaff_EBP;
  undefined4 uStack0000000c;
  char in_stack_00000013;
  
  if (eax != 1) {
    pcVar5 = d->sym;
    if (pcVar5 == (c1_symbol *)0x0) {
      pcVar5 = sym_new_from_declarator(d,5);
    }
    diag_error(0xc9,pcVar5);
    bVar2 = unaff_EBP[2];
    unaff_EBP[2] = bVar2 & 0xfb;
    unaff_EBP[2] = bVar2 & 0xf3;
    *unaff_EBP = *unaff_EBP | 8;
  }
  if (((d->spec[2] & 0xc) != 0) && ((g_compile_flags_c4 & 0x20000) != 0)) {
    typesym_check_declaration(g_compile_flags_c4,d);
    return;
  }
  if ((((in_stack_00000013 == '\0') &&
       (((cVar3 = d->kind, cVar3 != 7 && (cVar3 != 8)) || (d->special_kind == '\0')))) &&
      (d->flags54 = (*(byte *)(g_linkage_stack + g_linkage_depth) ^ d->flags54) & 3 ^ d->flags54,
      g_opt_EHc != '\0')) &&
     (((cVar3 == 7 || (cVar3 == 8)) &&
      ((g_linkage_stack[g_linkage_depth] == 2 && ((d->spec[3] & 0x20) == 0)))))) {
    d->spec[3] = d->spec[3] | 0x10;
  }
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
    if (((d->kind == 2) || (d->kind == 1)) && ((*unaff_EBP & 7) == 0)) {
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
  uStack0000000c = 0x5a3;
  diag_fatal(1);
}

