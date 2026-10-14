int __thiscall decl_compare_redeclared_type(c1_declarator *d,c1_symbol *sym)

{
  c1_u16 cVar1;
  c1_type *pcVar2;
  byte bVar3;
  int iVar4;
  c1_type *pcVar5;
  c1_symbol *pcVar6;
  c1_symbol *pcVar7;
  byte bVar8;
  c1_type local_10;
  
  bVar3 = sym->flags23 & 1;
  pcVar5 = d->type;
  pcVar2 = sym->type;
  if (pcVar5 == (c1_type *)0x0) {
    if (d->kind == 0xd) {
      cVar1 = d->unk50;
      type_descriptor_clear(&local_10);
      local_10.flags = 0;
      local_10.extra.cls = (c1_symbol *)0x0;
      local_10.code = cVar1;
      pcVar5 = type_intern(&local_10);
    }
    if (pcVar5 == (c1_type *)0x0) {
      return 0;
    }
  }
  if ((d->spec[3] & 1) == 0) {
    if (bVar3 != 0) {
      pcVar7 = sym_segment_record(sym);
      if (pcVar7 == (c1_symbol *)0x0) {
        d->spec[4] = '\0';
        d->spec[5] = '\0';
        d->spec[6] = '\0';
        d->spec[7] = '\0';
        d->spec[3] = d->spec[3] & 0xfe;
      }
      else {
        *(c1_symbol **)(d->spec + 4) = pcVar7;
        d->spec[3] = d->spec[3] | 1;
      }
    }
  }
  else if (bVar3 == 0) {
    if (*(void **)(d->spec + 4) == (void *)0x0) {
      sym->flags23 = sym->flags23 & 0xfe;
    }
    else {
      sym_set_segment(sym,*(void **)(d->spec + 4));
    }
  }
  else {
    pcVar7 = *(c1_symbol **)(d->spec + 4);
    pcVar6 = sym_segment_record(sym);
    if (((pcVar6 != pcVar7) && (pcVar7 = sym_segment_record(sym), (pcVar7->entity & 0xffffff) != 5))
       && ((*(uint *)(*(int *)(d->spec + 4) + 0x1c) & 0xffffff) != 2)) {
      return 0x178;
    }
  }
  if (pcVar2 == pcVar5) {
    return 0;
  }
  iVar4 = decl_type_modifiers_compatible(d,pcVar2->flags,pcVar5->flags,sym);
  if (iVar4 != 0) {
    bVar3 = (byte)pcVar2->code;
    if ((char)bVar3 < '\0') {
      bVar8 = (byte)pcVar5->code;
      if ((char)bVar8 < '\0') {
        if (((bVar8 ^ bVar3) & 0x8f) != 0) {
          return 0x174;
        }
        if ((bVar3 & 0x8f) == 0x83) {
          if ((((pcVar2->extra).cls != (pcVar5->extra).cls) &&
              ((pcVar2->extra).cls != (c1_symbol *)0x0)) &&
             ((pcVar5->extra).cls != (c1_symbol *)0x0)) {
            return 0x171;
          }
        }
        else if ((bVar3 & 0x83) == 0x81) {
          if ((pcVar2->extra).count != (pcVar5->extra).count) {
            decl_compare_parameter_lists((pcVar2->extra).count,(pcVar5->extra).count);
          }
        }
        if (pcVar2->base == pcVar5->base) {
          return 0;
        }
        iVar4 = decl_resolve_declarator_type_fragment(1,pcVar2->base,pcVar5->base,d,sym);
        return iVar4;
      }
    }
    else if (-1 < (char)pcVar5->code) {
      iVar4 = type_codes_equal(pcVar2->code,pcVar5->code);
      if (iVar4 == 0) {
        return 0x173;
      }
      if ((((g_compile_flags_cc & 0x200000) == 0) &&
          (((pcVar2->code & 0x800) == 0 || ((pcVar5->code & 0x800) == 0)))) &&
         ((pcVar2->extra).cls != (pcVar5->extra).cls)) {
        return 0x173;
      }
      return 0;
    }
    return 0x28;
  }
  return 0x175;
}

