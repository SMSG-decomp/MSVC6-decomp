void __fastcall decl_check_missing_type_specifier(c1_declarator *d)

{
  c1_type *pcVar1;
  c1_symbol *pcVar2;
  
  if (((((d->spec[0] & 0x10) != 0) && ((d->spec[0] & 0x20) != 0)) && ((d->flags55 & 0xc0) == 0)) &&
     (((d->kind != 7 && (d->kind != 8)) ||
      (((d->flags56 & 1) == 0 &&
       (pcVar1 = type_function_return(d->decl->type), (char)pcVar1->code < '\0')))))) {
    pcVar2 = d->sym;
    if (pcVar2 == (c1_symbol *)0x0) {
      pcVar2 = sym_new_from_declarator(d,5);
    }
    diag_error(0x1f5,0x53,pcVar2);
  }
  return;
}

