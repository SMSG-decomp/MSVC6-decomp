void __thiscall class_vtable_declarator_set_decorated_name(c1_declarator *d,c1_symbol *cls)

{
  c1_symbol *sym;
  char *s;
  fe_name *pfVar1;
  
  d->flags54 = d->flags54 & 0xfc;
  d->spec[0] = d->spec[0] & 0xfa | 2;
  d->kind = 3;
  sym = sym_new_from_declarator(d,5);
  s = decorate_name(sym,cls);
  pfVar1 = name_intern(s);
  d->name = pfVar1;
  d->kind = 0;
  d->flags54 = d->flags54 & 0xfe | 2;
  return;
}

