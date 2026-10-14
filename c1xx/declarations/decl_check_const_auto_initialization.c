void __fastcall
decl_check_const_auto_initialization(c1_declarator *d,c1_type *t,uint storage,c1_symbol *cls)

{
  byte bVar1;
  c1_symbol *pcVar2;
  c1_symbol *type_cls;
  int iVar3;
  int n;
  
  if ((((cls->detail).cls)->layout_flags3c & 0x40) != 0) {
    if ((t->code & 0x200) == 0) {
      if (((char)t->code < '\0') && ((t->base->code & 0x200) != 0)) {
        pcVar2 = (t->base->extra).cls;
      }
      else {
        pcVar2 = (c1_symbol *)0x0;
      }
    }
    else {
      pcVar2 = (t->extra).cls;
    }
    if ((((pcVar2->detail).cls)->implicit_state41 & 2) != 0) {
      bVar1 = (byte)storage & 7;
      if ((bVar1 == 2) || (bVar1 == 3)) {
        pcVar2 = d->sym;
        if (pcVar2 == (c1_symbol *)0x0) {
          pcVar2 = sym_new_from_declarator(d,5);
        }
        n = 0x10c;
        iVar3 = 4;
      }
      else {
        pcVar2 = d->sym;
        if (pcVar2 == (c1_symbol *)0x0) {
          pcVar2 = sym_new_from_declarator(d,5);
        }
        n = 0x10d;
        iVar3 = 1;
      }
      diag_warning(iVar3,n,pcVar2);
    }
  }
  iVar3 = type_size(t);
  if (iVar3 != 0) {
    type_check_based_allocation_return_case();
    return;
  }
  if (((byte)storage & 7) == 1) {
    return;
  }
  if ((t->code & 0x200) != 0) {
    pcVar2 = (t->extra).cls;
    if ((pcVar2->kind & 0x1f) != 4) {
      pcVar2 = (pcVar2->type->extra).cls;
    }
    if ((pcVar2->flags2 & 4) == 0) {
      type_cls = d->sym;
      if (type_cls == (c1_symbol *)0x0) {
        type_cls = sym_new_from_declarator(d,5);
      }
      diag_error(0x4f,type_cls,pcVar2->type,pcVar2);
      d->sym->flags3 = d->sym->flags3 | 4;
      return;
    }
  }
  pcVar2 = d->sym;
  if (pcVar2 == (c1_symbol *)0x0) {
    pcVar2 = sym_new_from_declarator(d,5);
  }
  diag_error(0x85,pcVar2);
  type_check_based_allocation_return_case();
  return;
}

