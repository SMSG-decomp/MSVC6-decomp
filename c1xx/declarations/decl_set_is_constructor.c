void __thiscall decl_set_is_constructor(c1_declarator *d,c1_u8 value)

{
  d->flags55 = (value & 1) << 6 | d->flags55 & 0xbf;
  return;
}

