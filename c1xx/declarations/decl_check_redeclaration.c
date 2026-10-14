char __thiscall decl_check_redeclaration(c1_declarator *d,c1_symbol *sym)

{
  char cVar1;
  byte bVar2;
  int iVar3;
  c1_symbol *pcVar4;
  c1_symbol *pcVar5;
  char *pcVar6;
  char *pcVar7;
  
  if ((d->flags54 & 0x40) != 0) {
    sym->flags3 = sym->flags3 | 4;
    return '\x01';
  }
  pcVar7 = "";
  pcVar6 = "";
  if ((d->kind == 0xd) && ((d->flags56 & 0x40) != 0)) {
    if ((sym->kind & 0x1f) != 4) {
      if ((sym->flags2 & 0x10) != 0) {
        pcVar7 = "typedef";
        pcVar6 = " ";
      }
LAB_1047a05b:
      pcVar4 = d->sym;
      if (pcVar4 == (c1_symbol *)0x0) {
        pcVar4 = sym_new_from_declarator(d,5);
      }
      diag_error(0x398,pcVar4,pcVar7,pcVar6,sym);
      return '\x01';
    }
    if ((((sym->detail).cls)->flags3e & 2) == 0) goto LAB_1047a05b;
  }
  else if (((sym->kind & 0x1f) == 4) && ((((sym->detail).cls)->flags3e & 2) != 0)) {
    if ((d->kind != 0xd) && ((d->flags55 & 4) != 0)) {
      pcVar7 = "typedef";
      pcVar6 = " ";
    }
    pcVar4 = d->sym;
    if (pcVar4 == (c1_symbol *)0x0) {
      pcVar4 = sym_new_from_declarator(d,5);
    }
    diag_error(0x399,sym,pcVar7,pcVar6,pcVar4);
    return '\x01';
  }
  iVar3 = decl_compare_redeclared_type(d,sym);
  if (iVar3 == 0) {
    cVar1 = decl_check_storage_compatible(d,sym);
    if (cVar1 == '\0') {
      bVar2 = sym->kind & 0x1f;
      if ((bVar2 == 7) || (bVar2 == 8)) {
        iVar3 = 0x177;
        goto LAB_1047a11b;
      }
    }
    else {
      if (((sym->flags4 & 4) != 0) && ((d->flags54 & 4) != 0)) {
        iVar3 = 0x176;
        goto LAB_1047a11b;
      }
      if ((d->spec[3] & 1) != 0) {
        if ((sym->flags23 & 1) == 0) {
          if (*(void **)(d->spec + 4) == (void *)0x0) {
            sym->flags23 = sym->flags23 & 0xfe;
            return '\0';
          }
          sym_set_segment(sym,*(void **)(d->spec + 4));
        }
        else {
          pcVar4 = *(c1_symbol **)(d->spec + 4);
          pcVar5 = sym_segment_record(sym);
          if (pcVar5 != pcVar4) {
            iVar3 = 0x170;
            goto LAB_1047a11b;
          }
        }
        return '\0';
      }
      if (((d->kind == 7) || (d->kind == 8)) && ((d->spec[0x14] & 1) != 0)) {
        if ((*(byte *)((int)&sym->tail + 10) & 0x80) != 0) {
          sym_list_1b58_value(sym);
          return '\0';
        }
        if (*(int *)(d->spec + 0x10) != 0) {
          sym_list_1b58_insert(sym,*(int *)(d->spec + 0x10));
          return '\0';
        }
        *(byte *)((int)&sym->tail + 10) = *(byte *)((int)&sym->tail + 10) & 0x7f;
        return '\0';
      }
      if ((d->spec[2] & 2) == 0) {
        return '\0';
      }
      if ((sym->flags22 & 2) != 0) {
        return '\0';
      }
    }
    iVar3 = 0x172;
  }
  else if (iVar3 == 0x28) {
    d->flags54 = d->flags54 | 0x40;
    sym->flags3 = sym->flags3 | 4;
    diag_error(0x28,0x53,sym,d->type,sym->type);
    return '\x01';
  }
LAB_1047a11b:
  d->flags54 = d->flags54 | 0x40;
  sym->flags3 = sym->flags3 | 4;
  diag_error((short)iVar3,sym);
  return '\x01';
}

