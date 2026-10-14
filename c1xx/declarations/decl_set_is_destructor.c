void __thiscall decl_set_is_destructor(c1_declarator *d,c1_u8 value)

{
  d->flags55 = d->flags55 & 0x7f | value << 7;
  return;
}

