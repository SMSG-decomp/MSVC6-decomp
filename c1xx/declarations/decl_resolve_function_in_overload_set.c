byte * __fastcall decl_resolve_function_in_overload_set(c1_declarator *d)

{
  byte bVar1;
  c1_symbol *pcVar2;
  c1_symbol *sym;
  
  if (d->qualifier == (c1_overload_set *)0x0) {
    return (byte *)0x0;
  }
  sym = d->qualifier->list->head->sym;
  pcVar2 = sym;
  if ((sym->flags2 & 0x20) != 0) {
    if ((sym->flags2 & 0x10) == 0) {
      pcVar2 = (c1_symbol *)((int)&sym->next[-1].tail + 4);
    }
    else {
      sym = (c1_symbol *)((int)&sym->next[-1].tail + 4);
    }
  }
  if (((byte)g_compile_flags_c4 & 0x10) == 0) {
    if ((d->kind == 7) || (d->kind == 8)) {
      bVar1 = sym->kind & 0x1f;
      if (((bVar1 == 0x10) || (((bVar1 == 7 || (bVar1 == 6)) || (bVar1 == 0x11)))) ||
         (((bVar1 == 8 || (bVar1 == 0x1b)) ||
          ((bVar1 == 0x1a &&
           (((bVar1 = **(byte **)sym->type & 0x1f, bVar1 == 0x10 || (bVar1 == 7)) ||
            ((bVar1 == 6 || (((bVar1 == 0x11 || (bVar1 == 8)) || (bVar1 == 0x1b)))))))))))) {
        pcVar2 = d->sym;
        if (pcVar2 == (c1_symbol *)0x0) {
          pcVar2 = sym_new_from_declarator(d,5);
        }
        pcVar2 = (c1_symbol *)ovl_find_function_with_type(sym,d->type,1,0,pcVar2,d,1);
        if (pcVar2 == (c1_symbol *)0x0) {
          return (byte *)0x0;
        }
        goto LAB_1041be26;
      }
      diag_error(0x3f,sym);
    }
    else if ((d->flags55 & 4) != 0) goto LAB_1041be26;
    pcVar2 = sym;
  }
LAB_1041be26:
  if (d->qualifier != (c1_overload_set *)0x0) {
    d->qualifier->list->head->sym = pcVar2;
    pcVar2 = (c1_symbol *)d->qualifier;
  }
  return &pcVar2->kind;
}

