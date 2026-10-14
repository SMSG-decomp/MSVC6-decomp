void __thiscall sym_attrs_set_declspec_record(c1_symbol_attrs *attrs,void *declspec)

{
  if (declspec == (void *)0x0) {
    attrs->declspec = (void *)0x0;
    attrs->flags21 = attrs->flags21 & 0xbf;
    return;
  }
  attrs->declspec = declspec;
  attrs->flags21 = attrs->flags21 | 0x40;
  return;
}

