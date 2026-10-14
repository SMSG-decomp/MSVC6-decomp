void __thiscall decl_set_local_key_flag(c1_declarator *d,c1_u8 value)

{
  d->flags57 = (value & 1) << 5 | d->flags57 & 0xdf;
  return;
}

