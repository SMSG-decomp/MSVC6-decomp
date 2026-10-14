void __thiscall decl_set_has_initializer(c1_declarator *d,c1_u8 value)

{
  d->flags54 = (value & 1) << 2 | d->flags54 & 0xfb;
  return;
}

