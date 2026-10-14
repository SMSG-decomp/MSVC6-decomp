c1_symbol * __thiscall decl_redeclare_or_new(c1_declarator *d,c1_symbol *sym)

{
  byte bVar1;
  c1_u32 cVar2;
  byte bVar3;
  char cVar4;
  ushort uVar5;
  c1_symbol *pcVar6;
  c1_symbol *pcVar7;
  uint uVar8;
  c1_type *pcVar9;
  
  pcVar7 = sym;
  if ((g_compile_flags_c8 & 0x10000000) != 0) {
    return (c1_symbol *)0x0;
  }
  cVar2 = d->kind;
  if (((((cVar2 != 5) && (cVar2 != 6)) && (cVar2 != 10)) && ((cVar2 != 7 && (cVar2 != 8)))) &&
     ((d->spec[0] & 0x20) != 0)) {
    pcVar9 = d->type;
    while ((bVar3 = (byte)pcVar9->code, (bVar3 & 0x8f) == 0x83 || ((bVar3 & 0x83) == 0x81))) {
      pcVar9 = pcVar9->base;
    }
    if (((byte)pcVar9->flags >> 5 & 1) != 0) {
      if ((d->flags54 & 4) == 0) {
        uVar8 = type_classify_class_form(d->type,(int *)&sym);
        pcVar6 = sym;
        if ((uVar8 & 3) != 0) {
          if ((sym->flags2 & 4) == 0) {
            tmpl_instantiate_if_needed(sym);
          }
          if (((((pcVar6->detail).cls)->implicit_state41 & 2) != 0) ||
             ((((pcVar6->detail).cls)->implicit_state43 & 2) != 0)) goto LAB_1040495f;
        }
        pcVar6 = d->sym;
        if (pcVar6 == (c1_symbol *)0x0) {
          pcVar6 = sym_new_from_declarator(d,5);
        }
        diag_error(0x2de,pcVar6);
      }
      else {
LAB_1040495f:
        if (g_block_depth == '\0') {
          if (pcVar7 == (c1_symbol *)0x0) {
            bVar3 = d->spec[0];
            d->spec[0] = bVar3 & 0xfb | 3;
            bVar1 = d->spec[2];
            d->spec[0] = bVar3 & 0x9b | 3;
            if ((bVar1 & 0x40) == 0) {
              return (c1_symbol *)0x0;
            }
            pcVar7 = d->sym;
            if (pcVar7 == (c1_symbol *)0x0) {
              pcVar7 = sym_new_from_declarator(d,5);
            }
            diag_error(0x1f0,pcVar7);
            d->spec[2] = d->spec[2] & 0xbf;
            d->spec[1] = d->spec[1] & 0x7f;
            return (c1_symbol *)0x0;
          }
          bVar3 = pcVar7->kind & 0x1f;
          if ((((((bVar3 == 0x10) || (bVar3 == 7)) || (bVar3 == 6)) ||
               (((bVar3 == 0x11 || (bVar3 == 8)) || (bVar3 == 0x1b)))) ||
              ((bVar3 == 0x1a &&
               (((bVar3 = **(byte **)pcVar7->type & 0x1f, bVar3 == 0x10 || (bVar3 == 7)) ||
                ((bVar3 == 6 || (((bVar3 == 0x11 || (bVar3 == 8)) || (bVar3 == 0x1b)))))))))) ||
             (((pcVar7->storage & 0x20) != 0 || ((pcVar7->storage & 7) != 1)))) goto LAB_104049c3;
          d->spec[0] = d->spec[0] & 0xfa | 2;
          d->spec[1] = d->spec[1] | 0x10;
        }
      }
    }
  }
  if (pcVar7 == (c1_symbol *)0x0) {
    return (c1_symbol *)0x0;
  }
LAB_104049c3:
  pcVar6 = expr_resolve_overload_set_member(pcVar7,(c1_symbol *)0x0);
  bVar3 = pcVar6->kind & 0x1f;
  if (((((bVar3 == 0x10) || (bVar3 == 7)) ||
       ((bVar3 == 6 || (((bVar3 == 0x11 || (bVar3 == 8)) || (bVar3 == 0x1b)))))) ||
      ((bVar3 == 0x1a &&
       (((bVar3 = **(byte **)pcVar6->type & 0x1f, bVar3 == 0x10 || (bVar3 == 7)) ||
        (((bVar3 == 6 || ((bVar3 == 0x11 || (bVar3 == 8)))) || (bVar3 == 0x1b)))))))) &&
     ((d->kind == 7 || (d->kind == 8)))) {
    pcVar7 = decl_check_overload_linkage(d,pcVar6);
    return pcVar7;
  }
  if ((pcVar7 != pcVar6) ||
     (pcVar7 = (c1_symbol *)decl_redeclare_beside_class_name(d,&pcVar6->kind),
     pcVar7 == (c1_symbol *)0x0)) {
    if ((g_block_depth == '\0') &&
       ((((pcVar6->storage & 7) == 1 || ((d->spec[0] & 7) == 1)) || ((pcVar6->flags22 & 8) != 0))))
    {
      cVar4 = decl_check_redeclaration(d,pcVar6);
      if (cVar4 == '\0') {
        decl_merge_attributes(d,pcVar6);
        return pcVar6;
      }
    }
    else if (((pcVar6->storage & 7) == 1) && ((d->spec[0] & 7) == 1)) {
      cVar4 = decl_check_redeclaration(d,pcVar6);
      if (cVar4 == '\0') {
        uVar5 = d->type->code;
        if (((char)uVar5 < '\0') &&
           (((uVar5 = uVar5 & 0x8f, uVar5 == 0x84 || (uVar5 == 0x86)) || (uVar5 == 0x8e)))) {
          decl_check_default_argument_redefinition
                    ((d->type->base->extra).params,(pcVar6->type->base->extra).params,d->sym,1);
        }
        return pcVar6;
      }
    }
    else {
      cVar4 = decl_check_redeclaration(d,pcVar6);
      if (cVar4 == '\0') {
        pcVar7 = d->sym;
        if (pcVar7 == (c1_symbol *)0x0) {
          pcVar7 = sym_new_from_declarator(d,5);
        }
        diag_error(0x56,pcVar7);
      }
    }
    d->flags54 = d->flags54 | 0x40;
    pcVar7 = sym_new_from_declarator(d,0xffffffff);
  }
  return pcVar7;
}

