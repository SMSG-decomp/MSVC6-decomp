void __thiscall declarator_set_flags56_bit0(c1_declarator *d,c1_u8 bit)

{
  d->flags56 = (d->flags56 ^ bit) & 1 ^ d->flags56;
  return;
}

