void __fastcall
decl_process_declaration_case0_fragment(c1_declarator *d,byte *spec_flags,int slot_c,char is_member)

{
  char cVar1;
  byte bVar2;
  c1_u32 cVar3;
  c1_type *pcVar4;
  c1_type *pcVar5;
  c1_symbol *pcVar6;
  
  bVar2 = *spec_flags;
  *spec_flags = bVar2 & 0xf9 | 1;
  *spec_flags = bVar2 & 0xf9 | 0x21;
  if ((((is_member == '\0') &&
       (((cVar3 = d->kind, cVar3 != 7 && (cVar3 != 8)) || (d->special_kind == '\0')))) &&
      (d->flags54 = (*(byte *)(g_linkage_stack + g_linkage_depth) ^ d->flags54) & 3 ^ d->flags54,
      g_opt_EHc != '\0')) &&
     (((cVar3 == 7 || (cVar3 == 8)) &&
      ((g_linkage_stack[g_linkage_depth] == 2 && ((d->spec[3] & 0x20) == 0)))))) {
    d->spec[3] = d->spec[3] | 0x10;
  }
  if (d->kind != 10) {
    pcVar5 = d->type;
    cVar1 = (char)pcVar5->code;
    pcVar4 = pcVar5;
    while (cVar1 < '\0') {
      pcVar4 = pcVar4->base;
      cVar1 = (char)pcVar4->code;
    }
    if ((pcVar4->code & 0xfff) == 0x802) {
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
    if (((d->kind == 2) || (d->kind == 1)) && ((*spec_flags & 7) == 0)) {
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

